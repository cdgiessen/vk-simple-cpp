# Copyright 2021 Charles Giessen (cdgiessen@gmail.com)

# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files
# (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
# FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

import xml.etree.ElementTree
import re
from codegen_text import *

#globals that are initialized near beginning of xml parsing
vendor_abbreviations = []
base_type_implicit_conversions = {}
api_constants = {}

base_type_default_values = {
    'void*': 'nullptr',
    'char': '0',
    'uint8_t': '0',
    'uint16_t': '0',
    'uint32_t': '0',
    'uint64_t': '0',
    'int32_t': '0',
    'int64_t': '0',
    'int': '0',
    'float': '0.f',
    'double': '0.0',
    'size_t': '0'
}

def MorphVkEnumName(name, enum_name_len):
    n_part = name.title().split('_')[enum_name_len:]
    if n_part[-1] == "Bit":
        n_part = n_part[:-1]
    if n_part[-1].upper() in vendor_abbreviations:
        n_part[-1] = n_part[-1].upper()
    out = ''.join(n_part)
    if out[0].isnumeric():
        out = 'e' + out
    return out

def PrintConsecutivePlatforms(file, in_list, function_name, *args, **kwargs):
    prev_platform = None
    for item in in_list:
        if getattr(item, 'platform', None) is not None:
            if prev_platform != item.platform:
                if prev_platform is not None:
                    file.write(f'#endif // defined({prev_platform})\n')
                if item.platform is not None:
                    file.write(f'#if defined({item.platform})\n')
            prev_platform = item.platform
        else:
            if prev_platform is not None:
                file.write(f'#endif // defined({prev_platform})\n')
            prev_platform = None
        getattr(item, function_name)(file, *args, **kwargs)
    if prev_platform is not None:
        file.write(f'#endif // defined({prev_platform})\n')

def TrimVkFromType(in_string):
    return in_string[2:] if in_string[:2] == 'Vk' or in_string[:2] == 'vk' else in_string

def TrimVkFromPFN(in_string):
    return f'PFN_{in_string[6:]}' if in_string[:6] == 'PFN_vk' else in_string

def TrimVkFromAll(in_string):
    return TrimVkFromType(TrimVkFromPFN(in_string))

class PlatformRequires:
    def __init__(self, node):
        self.name = node.get('name')
        self.requires = node.get('requires')

class ApiConstant:
    def __init__(self, node):
        self.name = node.get('name')
        self.value = node.get('value')
        self.alias = node.get('alias')
        self.type = node.get('type') if node.get('type') is not None else 'auto'

    def print_basic(self, file):
        if self.alias is not None:
            file.write(f'constexpr {self.type} {self.name} = {self.alias};\n')
        elif self.value is not None:
            file.write(f'constexpr {self.type} {self.name} = {self.value};\n')

class BaseType:
    def __init__(self, node):
        self.name = node.find('name').text
        self.type = None

        raw_xml_text = ' '.join(node.itertext())
        type_list = raw_xml_text.split()
        if type_list[0] is not None:
            if type_list[0] == 'typedef':
                self.type = node.find('type').text
                if self.type == 'void':
                    self.type = 'void*'
                    self.default_value = 'nullptr'
                else:
                    self.default_value = base_type_default_values[self.type]
            if type_list[0] == 'struct':
                pass

    def print_basic(self, file):
        if self.type is not None:
            file.write(f'using {self.name} = {self.type};\n')

class MacroDefine:
    def __init__(self, node):
        self.should_print = True
        self.name = node.find("name")
        self.text = ''.join(node.itertext())

    def print_base(self, file):
        text = ''
        should_print = True
        for t in self.text.itertext():
            if t in ['VK_API_VERSION', 'VK_API_VERSION_1_0', 'VK_API_VERSION_1_1', \
                'VK_API_VERSION_1_2', 'VK_HEADER_VERSION', 'VK_HEADER_VERSION_COMPLETE']:
                should_print = False
            text += t
        text += '\n'
        if should_print:
            file.write(text)

    def get_text(self):
        return self.text

class Enum:
    def __init__(self, node):
        self.name = node.get('name')
        self.underlying_type = 'uint32_t'  # for ABI
        self.values = {}
        self.platform = None
        self.alias = node.get('alias')
        if self.alias is not None:
            return

        self.enum_name_len = len(re.findall('[A-Z][^A-Z]+', self.name))
        if self.name == 'VkResult':
            self.enum_name_len = 1
            self.underlying_type = 'int32_t'

        for elem in node:
            if elem.get('name') is not None and elem.get('value') is not None:
                self.values[elem.get('name')] = elem.get('value')

    def fill_ext_enums(self, enum_ext_list):
        for ext_enum in enum_ext_list:
            self.values[ext_enum.name] = ext_enum.value

    def check_platform(self, platform, ext_types):
        if self.name in ext_types:
            self.platform = platform

    def print_basic(self, file):
        if self.alias is not None:
            file.write(f'using {self.name} = {self.alias};\n')
        else:
            file.write(f"enum class {self.name} : {self.underlying_type} {{\n")
            for name, value in self.values.items():
                file.write(f'    {MorphVkEnumName(name, self.enum_name_len)} = {str(value)},\n')
            file.write('};\n')
            for name, value in self.values.items():
                file.write(f'const {self.name} {name} = {self.name}::{MorphVkEnumName(name, self.enum_name_len)};\n')

    def print_string(self, file):
        if self.alias is not None:
            return
        if len(self.values) == 0:
            file.write(f'inline const char * to_string([[maybe_unused]] {self.name[2:]} val) {{ return "UNKNOWN"; }}\n')
            return
        file.write(f'inline const char * to_string({self.name[2:]} val) {{\n')
        file.write(f'    switch(val) {{\n')
        for name in self.values.keys():
            modified_name = MorphVkEnumName(name, self.enum_name_len)
            file.write(f'        case({self.name[2:]}::{modified_name}): return \"{modified_name}\";\n')
        file.write('        default: return "UNKNOWN";\n    }\n}\n')

    def print_basic_string_forward_def(self, file):
        if self.alias is None:
            file.write(f'const char * to_string({self.name} val);\n')

    def print_basic_string_impl(self, file):
        if self.alias is None:
            if len(self.values) == 0:
                file.write(f'const char * to_string({self.name} val) {{ UNUSED_VARIABLE(val); return "UNKNOWN"; }}\n')
                return
            file.write(f'const char * to_string({self.name} val) {{\n')
            file.write(f'    switch(val) {{\n')
            for name in self.values.keys():
                modified_name = MorphVkEnumName(name, self.enum_name_len)
                file.write(f'        case({self.name}::{modified_name}): return \"{modified_name}\";\n')
            file.write('        default: return "UNKNOWN";\n    }\n}\n')

def RepresentsIntOrHex(s):
    try:
        int(s)
        int(s, 16)
        return True
    except ValueError:
        return False

class Bitmask:
    def __init__(self, node):
        self.node = node
        self.name = node.get('name')
        self.flags_name = self.name.replace('Bits', 's')
        self.underlying_type = 'uint64_t' if node.get('bitwidth') is not None else 'uint32_t'
        self.values = {}
        self.bitmask_name_len = len(re.findall('[A-Z]+[^A-Z]*', self.name)) - 2
        if self.name[-4:] != "Bits": #ie an extension bitmask
            self.bitmask_name_len = self.bitmask_name_len - 1

        self.alias = node.get('alias')
        self.platform = None

        for elem in node:
            value = elem.get('value')
            if value is None and elem.get('bitpos') is not None:
                value = str(1 << int(elem.get('bitpos')))
            elif elem.get('alias') is not None:
                if elem.get('name') == "VK_STENCIL_FRONT_AND_BACK":
                    continue #ugly special case
                value = elem.get("alias")
            self.values[elem.get('name')] = value

    def fill_ext_bitmasks(self, bitmask_ext_dict):
        for ext_bit in bitmask_ext_dict:
            self.values[ext_bit.name] = str(ext_bit.bitpos)

    def check_platform(self, platform, ext_types):
        if self.name in ext_types:
            self.platform = platform

    def print_basic(self, file):
        if self.alias is not None:
            file.write(f'using {self.name} = {self.alias};\n')
        else:
            file.write(f'enum class {self.name}: {self.underlying_type} {{\n')
            for name, bitpos in self.values.items():
                file.write(f'    {MorphVkEnumName(name, self.bitmask_name_len)} = ')
                if all(c.isnumeric() for c in bitpos) or '0x' in bitpos :
                    file.write(f'{bitpos},\n')
                else:
                    file.write(f'{MorphVkEnumName(bitpos, self.bitmask_name_len)},\n')
            file.write('};\n')
            for name in self.values.keys():
                file.write(f'const {self.name} {name} = {self.name}::{MorphVkEnumName(name, self.bitmask_name_len)};\n')

    def print_string(self, file):
        if self.alias is None:
            if len(self.values) == 0:
                file.write(f'inline const char * to_string([[maybe_unused]] {self.name[2:]} val) {{ return "UNKNOWN"; }}\n')
                file.write(f'inline std::string to_string([[maybe_unused]] {self.flags_name[2:]} flag){{ return "UNKNOWN"; }}\n')
                return
            file.write(f'inline const char * to_string({self.name[2:]} val) {{\n')
            file.write('    switch(val) {\n')
            already_printed_bits = set()
            for name, bitpos in self.values.items():
                if bitpos in already_printed_bits:
                    continue
                if not RepresentsIntOrHex(bitpos):
                    continue
                modified_name = MorphVkEnumName(name, self.bitmask_name_len)
                file.write(f'        case({self.name[2:]}::{modified_name}): return \"{modified_name}\";\n')
                already_printed_bits.add(bitpos)

            file.write('        default: return "UNKNOWN";\n    }\n}\n')
            file.write(f'inline std::string to_string({self.flags_name[2:]} flag){{\n')
            file.write(f'    if (flag.flags == 0) return \"None\";\n')
            file.write(f'    std::string out;\n')
            for name, bitpos in self.values.items():
                if not RepresentsIntOrHex(bitpos):
                    continue
                modified_name = MorphVkEnumName(name, self.bitmask_name_len)
                file.write(f'    if (flag & {self.name[2:]}::{modified_name}) out += \"{modified_name} | \";\n')

            file.write(f'    return out.substr(0, out.size() - 3);\n}}\n')

    def print_basic_string_forward_def(self, file):
        if self.alias is None:
            file.write(f'const char * to_string({self.name} val);\n')
            file.write(f'std::string to_string({self.flags_name} flag);\n')


    def print_basic_string_impl(self, file):
        if self.alias is None:
            if len(self.values) == 0:
                file.write(f'const char * to_string({self.name} val) {{ UNUSED_VARIABLE(val); return "UNKNOWN"; }}\n')
                file.write(f'inline std::string to_string({self.flags_name} flag){{ UNUSED_VARIABLE(flag); return "UNKNOWN"; }}\n')
                return
            file.write(f'const char * to_string({self.name} val) {{\n')
            file.write('    switch(val) {\n')
            already_printed_bits = set()
            for name, bitpos in self.values.items():
                if bitpos in already_printed_bits:
                    continue
                if not RepresentsIntOrHex(bitpos):
                    continue
                modified_name = MorphVkEnumName(name, self.bitmask_name_len)
                file.write(f'        case({self.name}::{modified_name}): return \"{modified_name}\";\n')
                already_printed_bits.add(bitpos)

            file.write('        default: return "UNKNOWN";\n    }\n}\n')
            file.write(f'std::string to_string({self.flags_name} flag){{\n')
            file.write(f'    if (flag.flags == 0) return \"None\";\n')
            file.write(f'    std::string out;\n')
            for name, bitpos in self.values.items():
                if not RepresentsIntOrHex(bitpos):
                    continue
                modified_name = MorphVkEnumName(name, self.bitmask_name_len)
                file.write(f'    if (flag & {self.name}::{modified_name}) out += \"{modified_name} | \";\n')
            file.write(f'    return out.substr(0, out.size() - 3);\n}}\n')

    def print_c_interop(self, file):
        if self.alias is None:
            file.write(f'constexpr {self.name} to_c({self.name[2:]} value) {{ return static_cast<{self.name}>(value);}}\n')
            file.write(f'constexpr {self.name[2:]} from_c({self.name} value) {{ return static_cast<{self.name[2:]}>(value);}}\n')
class EmptyBitmask:
    def __init__(self, name):
        self.name = name
        self.flags_name = self.name.replace('Bits', 's')
        self.underlying_type = 'uint32_t'
        self.platform = None

    def fill_ext_bitmasks(self, bitmask_ext_dict):
        pass

    def check_platform(self, platform, ext_types):
        if self.name in ext_types or self.flags_name in ext_types:
            self.platform = platform

    def print_basic(self, file):
        file.write(f'enum class {self.name}: {self.underlying_type} {{ }};\n')

    def print_string(self, file):
        file.write(f'inline const char * to_string([[maybe_unused]] {self.name[2:]} val) {{ return "Unknown"; }} \n')
        file.write(f'inline std::string to_string({self.flags_name[2:]} flag){{\n')
        file.write(f'    if (flag.flags == 0) return \"None\";\n')
        file.write(f'    return "Unknown";\n}}\n')

    def print_basic_string_forward_def(self, file):
        pass

    def print_basic_string_impl(self, file):
        pass

    def print_c_interop(self, file):
        pass

class Flags:
    def __init__(self, node):
        if node.find('name') is not None:
            self.name = node.find('name').text
            self.alias = None
            self.underlying_type = 'uint64_t' if node.find('type').text == 'VkFlags64' else 'uint32_t'
        else:
            self.name = node.get('name')
            self.alias = node.get('alias')
            self.underlying_type = None

        self.flags_name = self.name.replace('Flags', 'FlagBits')
        self.requires = node.get('requires')
        self.need_empty = False
        if self.alias is None and self.requires is None:
            self.need_empty = True
        self.platform = None

    def check_platform(self, platform, ext_types):
        if (self.alias is not None and self.alias in ext_types) or self.name in ext_types:
            self.platform = platform

    def print_basic(self, file):
        if self.alias is None:
            file.write(f'DECLARE_ENUM_FLAG_OPERATORS({self.name}, {self.flags_name}, {self.underlying_type})\n')
        else:
            file.write(f'using {self.name} = {self.alias};\n')

    def print_c_interop(self, file):
        if self.alias is None:
            file.write(f'constexpr {self.name} to_c({self.name[2:]} value) {{ return static_cast<{self.name}>(value.flags);}}\n')

class Handle:
    def __init__(self, node):
        self.name = None
        if node.find('name') is not None:
            self.name = node.find('name').text
            self.dispatchable = node.find('type').text == 'VK_DEFINE_HANDLE' #else is a nondispatchable handle
            self.dispatchable_text = node.find('type').text
            self.parent = node.get('parent')
        self.alias = node.get('alias')
        if self.alias is not None:
            self.name = node.get('name')
        self.platform = None

    def check_platform(self, platform, ext_types):
        if self.name in ext_types:
            self.platform = platform

    def print_vk_handle(self, file):
        if self.alias is None:
            file.write(f'{self.dispatchable_text}({self.name})\n')
        else:
            file.write(f'using {self.name} = {self.alias};\n')


class Variable:
    def __init__(self, node, handles, default_values):
        self.name = node.find('name').text
        self.sType_value = node.get('values')

        # attributes
        self.optional = node.get('optional')
        self.len_attrib = node.get('len')

        self.alt_len = node.get('altlen')
        self.length_ref = None

        # type characteristics
        self.is_const = False
        self.const = ''
        self.pointer_type = 'none'
        self.array_lengths = []
        self.default_value = None
        self.is_equatable = True
        self.bitfield = None

        self.base_type = node.find('type').text
        self.base_type_modified = TrimVkFromAll(self.base_type)
        # special case cause of bitfields
        if self.base_type == 'VkGeometryInstanceFlagsKHR':
            self.base_type = 'uint32_t'
            self.base_type_modified = 'uint32_t'

        if node.find('comment') is not None:
            node.remove(node.find('comment'))

        self.raw_xml_text = ' '.join(node.itertext())
        type_list = self.raw_xml_text.split()

        # type parsing
        cur = 0
        if type_list[cur] == 'const':
            self.is_const = True
            self.const = 'const'
            cur += 1
        if type_list[cur] == 'struct':
            cur += 1
        if type_list[cur] == self.base_type:
            cur += 1
        if type_list[cur] == '*':
            self.pointer_type = 'single'
            cur += 1
        if type_list[cur] == '**':
            self.pointer_type = 'double'
            cur += 1
        if type_list[cur] == 'const*':
            self.pointer_type = 'const double'
            cur += 1
        if type_list[cur] == self.name:
            cur += 1

        while len(type_list) > cur:
            if type_list[cur] == '[':
                cur += 1
                arr_len = type_list[cur]
                cur += 2
            elif len(type_list[cur]) > 0 and type_list[cur][0] == '[':
                next_bracket = 1
                for t in type_list[cur][1:]:
                    if t == ']':
                        break
                    next_bracket += 1
                arr_len = type_list[cur][1:next_bracket]
                type_list[cur] = type_list[cur][next_bracket + 1:]
            else:
                break
            if arr_len in api_constants:
                arr_len = arr_len[3:]
            self.array_lengths.append(arr_len)
        for t in type_list:
            if len(t) > 0 and t[0] == ':':
                self.bitfield = t[1:]
        if self.base_type in default_values:
            self.default_value = default_values[self.base_type]
        if self.name == 'sType' and self.sType_value is not None:
            self.default_value = f'StructureType::{MorphVkEnumName(self.sType_value, 3)}'
        if self.name == 'sType' and self.sType_value is not None:
            self.base_default_value = f'VkStructureType::{MorphVkEnumName(self.sType_value, 3)}'

        self.is_handle = self.base_type in handles

    def is_ptr(self):
        return self.pointer_type != 'none'

    def get_raw_xml(self):
        return self.raw_xml_text


def MakeBuilderName(in_str):
    return in_str[0:1].capitalize() + in_str[1:]

def MakeBuilderFunctionNames(in_str):
    if in_str.find('ppEnabled') != -1:
        return in_str[2:]
    if in_str[0] == 'p' and in_str[1].isupper():
        return in_str[1:]
    else:
        return in_str[0:1].capitalize() + in_str[1:]

# Contains both structs and unions
class Structure:
    def __init__(self, node, handles, default_values):
        self.name = node.get('name')
        self.alias = node.get('alias')
        self.category = node.get('category') # struct or union
        self.members = []
        self.platform = None
        self.returnedonly = node.get('returnedonly') is not None
        self.structextends = node.get('structextends')

        for member in node.findall('member'):
            self.members.append(Variable(member, handles, default_values))


    def check_platform(self, platform, ext_types):
        if self.name in ext_types or (self.alias is not None and self.alias in ext_types):
            self.platform = platform

    def print_basic(self, file):
        if self.alias is not None:
            file.write(f'using {self.name} = {self.alias};\n')
        else:
            should_init = self.category == 'struct'
            file.write(f'{self.category} {self.name} {{\n')
            for member in self.members:
                if self.name in['VkAccelerationStructureInstanceKHR', 'VkAccelerationStructureMatrixMotionInstanceNV','VkAccelerationStructureSRTMotionInstanceNV']:
                    file.write(f'    {member.get_raw_xml().replace("VkGeometryInstanceFlagsKHR", "uint32_t")}')
                else:
                    file.write(f'    {member.get_raw_xml()}')
                if member.name == 'sType' and member.sType_value is not None:
                    file.write(f' = {member.base_default_value};\n')
                elif should_init and member.bitfield is None:
                    file.write('{};\n')
                else:
                    file.write(';\n')
            file.write('};\n')

class Function:
    def __init__(self, node, handles, dispatchable_handles, default_values):
        self.success_codes = node.get('successcodes', default='').split(',')
        self.error_codes = node.get('errorcodes', default='').split(',')

        self.platform = None
        proto = node.find('proto')
        self.name = proto.find('name').text if proto is not None else node.get('name')
        self.alias = node.get('alias') if proto is None else None
        self.return_type = proto.find('type').text if proto is not None else None

        self.pfn_name = f'pfn_{self.name[2:]}'
        self.pfn_type = f'PFN_{self.name[2:]}'

        self.parameters = []
        for param in node.findall('param'):
            self.parameters.append( Variable(param, handles, default_values))
        self.dispatch_type = None
        if len(self.parameters) > 0:
            self.free_function = self.parameters[0].base_type not in dispatchable_handles

            if self.name == 'vkGetInstanceProcAddr' or self.free_function:
                self.dispatch_type = 'global'
            elif self.name == 'vkGetDeviceProcAddr' or self.parameters[0].base_type in ['VkInstance', 'VkPhysicalDevice']:
                self.dispatch_type = 'instance'
            else:
                self.dispatch_type = 'device'

        self.dispatch_handle = None
        if len(self.parameters) > 0 and self.parameters[0].base_type in dispatchable_handles:
            self.dispatch_handle = self.parameters[0].base_type

    def check_platform(self, platform, ext_functions):
        if self.name in ext_functions:
            self.platform = platform

    def print_pfn_variable_decl(self, file):
        file.write(f'    detail::{self.pfn_type} {self.pfn_name} = nullptr;\n')

    def print_get_pfn_statement(self, file, gpa_name, gpa_val):
        file.write(f'    pfn_{self.name[2:]} = ')
        file.write(f'reinterpret_cast<detail::{self.pfn_type}>({gpa_name}({gpa_val},\"{self.name}\"));\n')

    def print_extern_decl(self, file, parent_dispatch_type):
        if parent_dispatch_type == 'instance' and self.name == 'vkGetInstanceProcAddr':
            return #halt duplicate vkGetInstanceProcAddr's being defined
        file.write(f'extern PFN_{self.name} {self.name};\n')

    def print_function_def(self, file, parent_dispatch_type):
        if parent_dispatch_type == 'instance' and self.name == 'vkGetInstanceProcAddr':
            return #halt duplicate vkGetInstanceProcAddr's being defined
        file.write(f'PFN_{self.name} {self.name};\n')

    def print_init_global_functions(self, file, dispatch_name):
        file.write(f'    {self.name} = reinterpret_cast<PFN_{self.name}>(vkGet{dispatch_name}ProcAddr({dispatch_name}, \"{self.name}\"));\n')

    def print_init_dispatch_table(self, file, dispatch_name):
        file.write(f'    table.{self.name} = reinterpret_cast<PFN_{self.name}>(vkGet{dispatch_name}ProcAddr({dispatch_name}, \"{self.name}\"));\n')

    def print_basic_pfn_func_decl(self, file):
        if self.alias is not None:
            file.write(f'using PFN_{self.name} = PFN_{self.alias};\n')
            return
        file.write(f'using PFN_{self.name} = {self.return_type} (*) (')
        for param in self.parameters:
            if param != self.parameters[0]:
                file.write(', ')
            file.write(f'{param.get_raw_xml()}')
        file.write(");\n")

    def print_function(self, file, dispatch_handle = None, dispatch_handle_name = None, pfn_source=None):
        if self.alias is not None:
            file.write(f'const auto {self.name[2:]} = {self.alias[2:]};\n')
            return
        self.inner_print_function(file, dispatch_handle, dispatch_handle_name, pfn_source)

class FuncPointer:
    def __init__(self, node):
        self.name = node.find('name').text
        self.raw_text = ' '.join(node.itertext())
        self.text = ''
        for t in node.itertext():
            t.replace('VkBool32', 'Bool32')
            self.text += TrimVkFromAll(t.replace('VkBool32', 'Bool32'))

    def print_basic(self, file):
        file.write(self.raw_text + '\n')

class ExtEnum:
    def __init__(self, name, value):
        self.name = name
        self.value = value

class ExtBitmask:
    def __init__(self, name, bitpos):
        self.name = name
        self.bitpos = bitpos

def EnumExtValue(ext_num, offset, direction):
    enum_value = 1000000000 + 1000 * (ext_num - 1) + offset
    enum_value = -enum_value if direction == '-' else enum_value
    return enum_value

def AppendToDictOfLists(dict, key, val):
    if key not in dict:
        dict[key] = []
    dict[key].append(val)

class Requires:
    def __init__(self, node, ext_num = None):
        self.feature = node.get('feature')
        self.extension = node.get('extension')
        self.enum_dict = {}
        self.bitmask_dict = {}
        self.types = set()
        self.commands = set()
        self.functions = []

        for e_type in node.findall('type'):
            self.types.add(e_type.get('name'))
        for command in node.findall('command'):
            self.commands.add(command.get('name'))

        for enum in node.findall('enum'):
            extends = enum.get('extends')
            if extends is None:
                continue
            name = enum.get('name')
            value = enum.get('value')
            bitpos = enum.get('bitpos')
            offset = enum.get('offset')
            extnumber = enum.get('extnumber')

            if offset is not None:
                offset = int(offset)

            if value is not None:  # core enums
                if value == '0':
                    AppendToDictOfLists(self.bitmask_dict, extends, ExtBitmask(name, 0))
                else:
                    AppendToDictOfLists(self.enum_dict, extends, ExtEnum(name, value))
            elif offset is not None:
                if extnumber is None and ext_num is not None:
                    extnumber = ext_num
                enum_value = EnumExtValue(int(extnumber), offset, enum.get('dir'))
                AppendToDictOfLists(self.enum_dict, extends, ExtEnum(name, enum_value))
            elif bitpos is not None:
                AppendToDictOfLists(self.bitmask_dict, extends, ExtBitmask(name, 1 << int(bitpos)))

    def fill_functions(self, functions):
        self.functions.extend([function for function in functions if function.name in self.commands])

    def fill_enums(self, enum_dict):
        for key in self.enum_dict.keys():
            enum_dict[key].fill_ext_enums(self.enum_dict[key])

    def fill_bitmasks(self, bitmask_dict):
        [bitmask_dict[key].fill_ext_bitmasks(self.bitmask_dict[key]) for key in self.bitmask_dict.keys()]

    def check_platform(self, platform, enum_dict, flags_dict, bitmask_dict, structures, functions):
        [enum.check_platform(platform, self.types) for enum in enum_dict.values()]
        [flag.check_platform(platform, self.types) for flag in flags_dict.values()]
        [bitmask.check_platform(platform, self.types) for bitmask in bitmask_dict.values()]
        [struct.check_platform(platform, self.types) for struct in structures]
        [function.check_platform(platform, self.commands) for function in functions]

class Extension:
    def __init__(self, node, platforms):
        self.name = node.get('name')
        self.ext_num = int(node.get('number'))
        self.ext_type = node.get('type')
        self.supported = node.get('supported')
        self.platform = None
        if node.get('platform') is not None:
            self.platform = platforms[node.get('platform')]
        self.requires = []
        for requires in node.findall('require'):
            self.requires.append(Requires(requires, self.ext_num))
        if self.supported != "disabled":
            self.str_name = node.findall('require')[0].findall('enum')[1].get('name')


class VulkanFeatureLevel:
    def __init__(self,node):
        self.api = node.get('api')
        self.name = node.get('name')
        self.number = node.get('number')
        self.requires = []
        for require in node.findall('require'):
            self.requires.append(Requires(require))

class DispatchTable:
    def __init__(self, name, dispatch_type, ext_or_feature_list):
        self.name = name
        self.dispatch_type = dispatch_type
        self.functions = {}
        for ext_or_feature in ext_or_feature_list:
            for require in ext_or_feature.requires:
                for function in require.functions:
                    if function.dispatch_type == dispatch_type or dispatch_type == 'instance' and function.name == 'vkGetInstanceProcAddr':
                        self.functions[function.name] = function

        self.gpa_type = 'PFN_GetDeviceProcAddr' if self.dispatch_type  == 'device' else 'PFN_GetInstanceProcAddr'
        self.gpa_name = 'get_device_proc_addr'  if self.dispatch_type == 'device' else 'get_instance_proc_addr'
        self.dispatch_handle = f'Vk{self.dispatch_type.title()}' if self.dispatch_type != 'global' else None
        self.gpa_val = f'{self.dispatch_type}' if self.dispatch_type != 'global' else 'nullptr'

    def print_extern_decl(self, file):
        PrintConsecutivePlatforms(file, self.functions.values(), 'print_extern_decl', self.dispatch_type)

    def print_function_def(self, file):
        PrintConsecutivePlatforms(file, self.functions.values(), 'print_function_def', self.dispatch_type)

    def print_init_global_functions(self, file):
        file.write(f'void vkInitialize{self.name}Functions (Vk{self.name} {self.name}) {{\n')
        PrintConsecutivePlatforms(file, self.functions.values(), 'print_init_global_functions', self.name)
        file.write('};\n')

    def print_dispatch_table(self, file):
        file.write(f'struct Vk{self.name}DispatchTable {{\n')
        for function in self.functions.values():
            if function.platform is not None:
                file.write(f'#if defined({function.platform})\n')
            file.write(f'    PFN_{function.name} {function.name} = nullptr;\n')
            if function.platform is not None:
                file.write(f'#else\n')
                file.write(f'    void* z_padding_{function.name} = nullptr;\n')
                file.write(f'#endif // defined({function.platform})\n')
        file.write('};\n')

    def print_init_dispatch_table(self, file):
        file.write(f'void vkInitialize{self.name}DispatchTable (Vk{self.name} {self.name}, Vk{self.name}DispatchTable & table) {{\n')
        for function in self.functions.values():
            if function.platform is not None:
                file.write(f'#if defined({function.platform})\n')
            file.write(f'    table.{function.name} = reinterpret_cast<PFN_{function.name}>(vkGet{self.name}ProcAddr({self.name}, \"{function.name}\"));\n')
            if function.platform is not None:
                 file.write(f'#endif // defined({function.platform})\n')
        file.write('};\n')

class BindingGenerator:
    def __init__(self, root):

        self.platforms = {}
        self.default_values = {}
        self.requires = []
        self.macro_defines = []
        self.base_types = []
        self.func_pointers = []
        self.flags_dict = {}
        self.enum_dict = {}
        self.handles = {}
        self.dispatchable_handles = []
        self.structures = []
        self.bitmask_dict = {}
        self.functions = []
        self.vk_feature_levels = []
        self.ext_list = []
        self.dispatch_tables = []
        self.dispatchable_handle_tables = []

        for platform in root.find('platforms'):
            self.platforms[platform.get('name')] = platform.get('protect')

        for key, value in base_type_default_values.items():
            self.default_values[key] = value

        for enum in root.findall("enums"):
            if enum.attrib.get('name') == "API Constants":
                for constant in enum.iter():
                    api_constant = ApiConstant(constant)
                    api_constants[api_constant.name] = api_constant
                break

        for xml_type in root.find('types'):
            category = xml_type.get('category')
            if category is None and xml_type.get('requires') is not None:
                self.requires.append(PlatformRequires(xml_type))
            elif category == 'define':
                self.macro_defines.append(MacroDefine(xml_type))
            elif category == 'basetype':
                base_type = BaseType(xml_type)
                self.base_types.append(base_type)
                if base_type.type is not None:
                    self.default_values[base_type.name] = base_type.default_value
                if base_type.name not in base_type_implicit_conversions:
                    base_type_implicit_conversions[base_type.name] = base_type.type
            elif category == 'funcpointer':
                self.func_pointers.append(FuncPointer(xml_type))
            elif category == 'bitmask':
                flag = Flags(xml_type)
                self.flags_dict[flag.name] = flag
            elif category == 'enum':
                enum = Enum(xml_type)
                if enum.name.find('Flag') == -1 or enum.name.find('FlagBits') == -1:
                    self.enum_dict[enum.name] = Enum(xml_type)
                self.default_values[enum.name] = f'static_cast<{enum.name[2:]}>(0)'
            elif category == 'handle':
                handle = Handle(xml_type)
                self.handles[handle.name] = handle
                if handle.alias is None and handle.dispatchable:
                    self.dispatchable_handles.append(handle.name)
            elif category == 'union' or category == 'struct':
                self.structures.append(Structure(xml_type, self.handles, self.default_values))

        #fixup the list so that members using a type appear after that type is defined
        outer_counter = 0
        inner_counter = 0
        while outer_counter < len(self.structures):
            moved = False
            for m in self.structures[outer_counter].members:
                inner_counter = outer_counter
                for t2 in self.structures[outer_counter:]:
                    if m.base_type == t2.name and inner_counter > outer_counter:
                        self.structures.insert(outer_counter, self.structures.pop(inner_counter))
                        moved = True
                    inner_counter = inner_counter + 1
            if not moved:
                outer_counter = outer_counter + 1

        for enum in root.findall("enums"):
            if enum.get('type') == 'enum':
                self.enum_dict[enum.get('name')] = Enum(enum)
            elif enum.get('type') == 'bitmask':
                self.bitmask_dict[enum.get('name')] = Bitmask(enum)

        # add in flags which have no bitmask
        for f in self.flags_dict.values():
            if f.need_empty and f.flags_name not in self.bitmask_dict:
                self.bitmask_dict[f.flags_name] = EmptyBitmask(f.flags_name)

        for commands in root.findall('commands'):
            for command in commands.findall('command'):
                new_function = Function(command, self.handles, self.dispatchable_handles, self.default_values)
                if new_function.name not in ['vkEnumerateDeviceLayerProperties']:
                    self.functions.append(new_function)

        for ext in root.find('extensions'):
            if ext.tag == 'extension':
                new_ext = Extension(ext, self.platforms)
                if new_ext.supported == 'vulkan':
                    for require in new_ext.requires:
                        require.check_platform(new_ext.platform, self.enum_dict, self.flags_dict, self.bitmask_dict,
                            self.structures, self.functions)
                        require.fill_enums(self.enum_dict)
                        require.fill_bitmasks(self.bitmask_dict)
                        require.fill_functions(self.functions)
                    self.ext_list.append(new_ext)
                elif new_ext.supported == 'disabled':
                    for require in new_ext.requires:
                        for req_type in require.types:
                            if req_type in self.enum_dict:
                                self.enum_dict.pop(req_type)
                            if req_type in self.bitmask_dict:
                                self.bitmask_dict.pop(req_type)
                            if req_type in self.flags_dict:
                                self.flags_dict.pop(req_type)
                            for structure in self.structures:
                                if structure.name == req_type:
                                    self.structures.remove(structure)
                        for command in require.commands:
                            for function in self.functions:
                                if function.name == command:
                                    self.functions.remove(function)
        for feature in root.findall('feature'):
            feat_level = VulkanFeatureLevel(feature)
            for require in feat_level.requires:
                require.fill_enums(self.enum_dict)
                require.fill_bitmasks(self.bitmask_dict)
                require.fill_functions(self.functions)
            self.vk_feature_levels.append(feat_level)

        features_and_extensions = self.vk_feature_levels
        features_and_extensions.extend(self.ext_list)

        self.dispatch_tables.append(DispatchTable("Global", "global", features_and_extensions))
        self.dispatch_tables.append(DispatchTable("Instance", "instance", features_and_extensions))
        self.dispatch_tables.append(DispatchTable("Device", "device", features_and_extensions))

def print_bindings(bindings):
    with open(f'include/vulkan/vulkan.h', 'w') as vulkan_core:
        vulkan_core.write(license_header)
        vulkan_core.write(cpp_header_guard + '\n')
        vulkan_core.write(cpp_platform_headers + '\n')
        for macro in bindings.macro_defines:
            vulkan_core.write(f'{macro.get_text()}\n\n')
        PrintConsecutivePlatforms(vulkan_core, api_constants.values(), 'print_basic')
        PrintConsecutivePlatforms(vulkan_core, bindings.base_types, 'print_basic')
        for ext in bindings.ext_list:
            if ext.supported != "disabled":
                vulkan_core.write(f'#define {ext.str_name} "{ext.name}"\n')
        PrintConsecutivePlatforms(vulkan_core, bindings.enum_dict.values(), 'print_basic')
        PrintConsecutivePlatforms(vulkan_core, bindings.bitmask_dict.values(), 'print_basic')
        vulkan_core.write(bitmask_flags_macro + '\n')
        PrintConsecutivePlatforms(vulkan_core, bindings.flags_dict.values(), 'print_basic')
        [ handle.print_vk_handle(vulkan_core) for handle in bindings.handles.values() ]
        vulkan_core.write('struct VkDebugUtilsMessengerCallbackDataEXT;\n')
        vulkan_core.write('struct VkDeviceMemoryReportCallbackDataEXT;\n')
        vulkan_core.write(begin_extern_c)
        PrintConsecutivePlatforms(vulkan_core, bindings.func_pointers, 'print_basic')
        PrintConsecutivePlatforms(vulkan_core, bindings.structures, 'print_basic')
        PrintConsecutivePlatforms(vulkan_core, bindings.functions, 'print_basic_pfn_func_decl')
        [ table.print_extern_decl(vulkan_core) for table in bindings.dispatch_tables ]
        for dispatch_table in bindings.dispatch_tables:
            if dispatch_table.name in ['Device']:
                dispatch_table.print_dispatch_table(vulkan_core)
        vulkan_core.write(cpp_footer)

    with open(f'include/vulkan/vulkan.cpp', 'w') as vulkan_impl:
        vulkan_impl.write(license_header)
        vulkan_impl.write('// clang-format off\n#include "vulkan.h"\n')
        vulkan_impl.write(cpp_definition)
        vulkan_impl.write(begin_extern_c)
        vulkan_impl.write('#if defined(__GNUC__)\n#if defined(VK_SIMPLE_USE_DEFAULT_VISIBILITY)\n')
        vulkan_impl.write('#	pragma GCC visibility push(default)\n#else\n')
        vulkan_impl.write('#	pragma GCC visibility push(hidden)\n#endif\n#endif\n')
        for dispatch_table in bindings.dispatch_tables:
            if dispatch_table.name == 'Global':
                dispatch_table.print_function_def(vulkan_impl)
            elif dispatch_table.name == 'Instance':
                dispatch_table.print_function_def(vulkan_impl)
                dispatch_table.print_init_global_functions(vulkan_impl)
            elif dispatch_table.name == 'Device':
                dispatch_table.print_function_def(vulkan_impl)
                dispatch_table.print_init_global_functions(vulkan_impl)
                dispatch_table.print_init_dispatch_table(vulkan_impl)
        vulkan_impl.write('#if defined(__GNUC__)\n#	pragma GCC visibility pop\n#endif\n')
        vulkan_impl.write(end_extern_c)
        vulkan_impl.write('\n// clang-format on\n')

    with open(f'include/vulkan/vulkan_string.h', 'w') as vulkan_string:
        vulkan_string.write(license_header)
        vulkan_string.write('// clang-format off\n#pragma once\n#include "vulkan.h"\n#include <string>\n')
        PrintConsecutivePlatforms(vulkan_string, bindings.enum_dict.values(), 'print_basic_string_forward_def')
        PrintConsecutivePlatforms(vulkan_string, bindings.bitmask_dict.values(), 'print_basic_string_forward_def')
        vulkan_string.write('\n// clang-format on\n')

    with open(f'include/vulkan/vulkan_string.cpp', 'w') as vulkan_string_impl:
        vulkan_string_impl.write(license_header)
        vulkan_string_impl.write('// clang-format off\n#include "vulkan_string.h"\n')
        vulkan_string_impl.write('''#define UNUSED_VARIABLE(x) (void)(x)\n''')
        PrintConsecutivePlatforms(vulkan_string_impl, bindings.enum_dict.values(), 'print_basic_string_impl')
        PrintConsecutivePlatforms(vulkan_string_impl, bindings.bitmask_dict.values(), 'print_basic_string_impl')
        vulkan_string_impl.write('\n// clang-format on\n')

def main():
    tree = xml.etree.ElementTree.parse('registry/vk.xml')
    root = tree.getroot()

    for tag in root.find('tags'):
        vendor_abbreviations.append(tag.get('name'))

    bindings = BindingGenerator(root)

    print_bindings(bindings)

if __name__ == "__main__":
    main()
