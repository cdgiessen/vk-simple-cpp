# Copyright 2024 Charles Giessen (cdgiessen@gmail.com)

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

 # eg. VK_ENUM_NAME_FLAG_BITS -> VK_ENUM_NAME
def GetUnderlyingEnumName(enum_name):
    enum_name = enum_name.replace('FlagBits','')
    for abbreviation in vendor_abbreviations:
        enum_name = enum_name.replace(abbreviation,'')
    return '_'.join(re.sub( r"([A-Z])", r" \1", enum_name.replace('FlagBits','')).split()).upper() # eg. VK_ENUM_NAME

def MorphVkEnumName(modified_enum_name, value_name):
    n_part = value_name.replace(modified_enum_name.upper(), '').title().split('_')
    if n_part[-1].upper() in vendor_abbreviations:
        n_part[-1] = n_part[-1].upper()
    out = ''.join(n_part).replace('Vk','').replace('Bit','')
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


def platform_check(type_to_check, platform, extension_type_list):
    if type(type_to_check) in [Bitmask, EmptyBitmask]:
        if type_to_check.name in extension_type_list or type_to_check.flags_name in extension_type_list:
            type_to_check.platform = platform

    if type_to_check.name in extension_type_list:
        type_to_check.platform = platform

class ApiConstant:
    def __init__(self, node):
        self.name = node.get('name')
        self.value = node.get('value')
        self.alias = node.get('alias')
        self.type = node.get('type') if node.get('type') is not None else 'auto'

    def print(self, file):
        file.write(f'{self.name} = {self.value};\n')

def RepresentsInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False
class Enum:
    def __init__(self, node):
        self.name = node.get('name')
        self.name_in_value = GetUnderlyingEnumName(self.name)
        self.underlying_type = 'uint32_t'  # for ABI
        self.values = {}
        self.platform = None
        self.alias = node.get('alias')
        if self.alias is not None:
            return

        for elem in node:
            if elem.get('api') is not None and elem.get('api') != 'vulkan':
                continue
            if elem.get('name') is not None and elem.get('value') is not None:
                self.values[elem.get('name')] = elem.get('value')

                if RepresentsInt(elem.get('value')):
                    if int(elem.get('value')) < 0:
                        self.underlying_type = 'int32_t'

    def fill(self, enum_ext_list):
        for ext_enum in enum_ext_list:
            self.values[ext_enum.name] = ext_enum.value

    def print(self, file):
        if self.alias is not None:
            file.write(f'using {self.name[2:]} = {self.alias[2:]};\n')
        else:
            file.write(f"enum class {self.name[2:]} : {self.underlying_type} {{\n")
            for value_name, value in self.values.items():
                file.write(f'    {MorphVkEnumName(self.name_in_value, value_name)} = {str(value)},\n')
            file.write('};\n')

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
        self.name_in_value = GetUnderlyingEnumName(self.name)
        self.alias = node.get('alias')
        self.platform = None

        for elem in node.findall('enum'):
            if elem.get('api') is not None and elem.get('api') != 'vulkan':
                continue
            # skip misspelled bits
            if elem.get('name') in ['VK_SURFACE_COUNTER_VBLANK_EXT', 'VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR', 'VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR']:
                continue

            value = elem.get('value')
            if value is None and elem.get('bitpos') is not None:
                value = str(1 << int(elem.get('bitpos')))
            elif elem.get('alias') is not None:
                if elem.get('name') == "VK_STENCIL_FRONT_AND_BACK":
                    continue #ugly special case
                value = elem.get("alias")
            self.values[elem.get('name')] = value

    def fill(self, bitmask_ext_dict):
        for ext_bit in bitmask_ext_dict:
            self.values[ext_bit.name] = str(ext_bit.bitpos)


    def print(self, file):
        if self.alias is not None:
            file.write(f'using {self.name} = {self.alias};\n')
        else:
            file.write(f'enum class {self.name[2:]}: {self.underlying_type} {{\n')
            for bitflag_name, bitpos in self.values.items():
                file.write(f'    {MorphVkEnumName(self.name_in_value, bitflag_name)} = ')
                if all(c.isnumeric() for c in bitpos) or '0x' in bitpos :
                    file.write(f'{bitpos},\n')
                else:
                    file.write(f'{MorphVkEnumName(self.name_in_value, bitpos)},\n')
            file.write('};\n')

class EmptyBitmask:
    def __init__(self, name):
        self.name = name
        self.flags_name = name.replace('Bits', 's')
        self.underlying_type = 'uint32_t'
        self.platform = None

    def fill(self, bitmask_ext_dict):
        pass


    def print(self, file):
        file.write(f'enum class {self.name[2:]}: {self.underlying_type} {{ }};\n')

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

        self.flag_bits_name = self.name.replace('Flags', 'FlagBits')
        self.requires = node.get('requires')
        self.need_empty = False
        if self.alias is None and self.requires is None:
            self.need_empty = True
        self.platform = None

    def print(self, file):
        if self.alias is None:
            file.write(f'DECLARE_ENUM_FLAG_OPERATORS({self.name[2:]}, {self.flag_bits_name[2:]}, {self.underlying_type})\n')
        else:
            file.write(f'using {self.name[2:]} = {self.alias[2:]};\n')

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

    def print(self, file):
        if self.alias is None:
            file.write(f'using {self.name[2:]} = {self.name};\n')
        else:
            file.write(f'using {self.name[2:]} = {self.alias};\n')

class Variable:
    def __init__(self, node, handles):
        self.name = node.find('name').text
        self.sType_value = node.get('values')

        # attributes
        self.optional = node.get('optional')
        self.len_attrib = node.get('len')

        self.alt_len = node.get('altlen')
        self.length_ref = None

        # type characteristics
        self.bitfield = None

        self.base_type = node.find('type').text
        self.base_type_modified = TrimVkFromAll(self.base_type)
        # special case cause of bitfields
        if self.base_type == 'VkGeometryInstanceFlagsKHR':
            self.base_type = 'uint32_t'
            self.base_type_modified = 'uint32_t'

        if node.find('comment') is not None:
            node.remove(node.find('comment'))

        raw_text_list = []
        for l in node.itertext():
            if not str(l).isspace():
                raw_text_list.append(str(l.strip()))
        self.raw_xml_text = ' '.join(raw_text_list)

        type_list = self.raw_xml_text.split()

        for t in type_list:
            if len(t) > 0 and t[0] == ':':
                self.bitfield = t[1:]
        if self.name == 'sType' and self.sType_value is not None:
            self.sType_value = f'StructureType::{MorphVkEnumName("VK_STRUCTURE_TYPE", self.sType_value)}'

        self.is_handle = self.base_type in handles

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
    def __init__(self, node, handles):
        self.name = node.get('name')
        self.alias = node.get('alias')
        self.category = node.get('category') # struct or union
        self.members = []
        self.platform = None
        self.returnedonly = node.get('returnedonly') is not None
        self.structextends = node.get('structextends')

        for member in node.findall('member'):
            if member.get('api') is not None and member.get('api') != 'vulkan':
                continue
            self.members.append(Variable(member, handles))


    def print(self, file):
        if self.alias is not None:
            file.write(f'using {self.name[2:]} = {self.alias[2:]};\n')
        else:
            should_init = self.category == 'struct'
            file.write(f'{self.category} {self.name[2:]} {{\n')
            for member in self.members:
                if self.name in['VkAccelerationStructureInstanceKHR', 'VkAccelerationStructureMatrixMotionInstanceNV','VkAccelerationStructureSRTMotionInstanceNV']:
                    file.write(f'    {member.get_raw_xml().replace("VkGeometryInstanceFlagsKHR", "uint32_t")}')
                else:
                    file.write(f'    {member.get_raw_xml().replace("Vk", "")}')
                if member.name == 'sType' and member.sType_value is not None:
                    file.write(f' = {member.sType_value};\n')
                elif should_init and member.bitfield is None:
                    file.write('{};\n')
                else:
                    file.write(';\n')
            file.write('};\n')

class Function:
    def __init__(self, node, handles, dispatchable_handles):
        self.success_codes = node.get('successcodes', default='').split(',')
        self.error_codes = node.get('errorcodes', default='').split(',')

        self.platform = None
        proto = node.find('proto')
        self.name = proto.find('name').text if proto is not None else node.get('name')
        self.alias = node.get('alias') if proto is None else None
        self.return_type = proto.find('type').text if proto is not None else None
        if self.return_type == 'VkResult':
            self.return_type = 'Result'
        self.pfn_name = f'pfn_{self.name[2:]}'
        self.pfn_type = f'PFN_{self.name[2:]}'

        self.parameters = []
        for param in node.findall('param'):
            if param.get('api') is not None and param.get('api') != 'vulkan':
                continue
            self.parameters.append( Variable(param, handles))
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

    # def print_pfn_variable_decl(self, file):
    #     file.write(f'    detail::{self.pfn_type} {self.pfn_name} = nullptr;\n')

    # def print_get_pfn_statement(self, file, gpa_name, gpa_val):
    #     file.write(f'    pfn_{self.name[2:]} = ')
    #     file.write(f'reinterpret_cast<detail::{self.pfn_type}>({gpa_name}({gpa_val},\"{self.name}\"));\n')

    def print_extern_decl(self, file, parent_dispatch_type):
        if parent_dispatch_type == 'instance' and self.name == 'vkGetInstanceProcAddr':
            return #halt duplicate vkGetInstanceProcAddr's being defined
        file.write(f'extern PFN_{self.name[2:]} {self.name};\n')

    def print_function_def(self, file, parent_dispatch_type):
        if parent_dispatch_type == 'instance' and self.name == 'vkGetInstanceProcAddr':
            return #halt duplicate vkGetInstanceProcAddr's being defined
        file.write(f'PFN_{self.name[2:]} {self.name};\n')

    def print_init_global_functions(self, file, dispatch_name):
        file.write(f'    {self.name} = reinterpret_cast<PFN_{self.name[2:]}>(vkGet{dispatch_name}ProcAddr({dispatch_name}, \"{self.name}\"));\n')

    def print_init_dispatch_table(self, file, dispatch_name):
        file.write(f'    table.{self.name} = reinterpret_cast<PFN_{self.name[2:]}>(vkGet{dispatch_name}ProcAddr({dispatch_name}, \"{self.name}\"));\n')

    def print_pfn_func_decl(self, file):
        if self.alias is not None:
            file.write(f'using PFN_{self.name[2:]} = PFN_{self.alias[2:]};\n')
            return
        file.write(f'using PFN_{self.name[2:]} = {self.return_type} (*) (')
        for param in self.parameters:
            if param != self.parameters[0]:
                file.write(', ')
            file.write(f'{param.get_raw_xml().replace("Vk","")}')
        file.write(");\n")

class FuncPointer:
    def __init__(self, node):
        self.name = node.find('name').text
        self.raw_text = ' '.join(node.itertext())
        self.text = ''
        for t in node.itertext():
            t.replace('VkBool32', 'Bool32')
            self.text += TrimVkFromAll(t.replace('VkBool32', 'Bool32'))

    def print(self, file):
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

    def fill(self, enum_dict, bitmask_dict, functions):
        for key in self.enum_dict.keys():
            enum_dict[key].fill(self.enum_dict[key])
        [bitmask_dict[key].fill(self.bitmask_dict[key]) for key in self.bitmask_dict.keys()]
        self.functions.extend([function for function in functions if function.name in self.commands])

    def check_platform(self, platform, enum_dict, flags_dict, bitmask_dict, handles, structures, functions):
        [platform_check(enum, platform, self.types) for enum in enum_dict.values()]
        [platform_check(flag, platform, self.types) for flag in flags_dict.values()]
        [platform_check(bitmask, platform, self.types) for bitmask in bitmask_dict.values()]
        [platform_check(struct, platform, self.types) for struct in structures]
        [platform_check(handle, platform, self.types) for handle in handles.values()]
        [platform_check(function, platform, self.commands) for function in functions]

class Extension:
    def __init__(self, node, platforms):
        self.name = node.get('name')
        self.ext_num = int(node.get('number'))
        self.ext_type = node.get('type')
        self.platform = None
        if node.get('platform') is not None:
            self.platform = platforms[node.get('platform')]
        self.requires = []
        for require in node.findall('require'):
            if require.get('api') is not None and require.get('api') == 'vulkansc':
                continue
            self.requires.append(Requires(require, self.ext_num))
        self.str_name = node.findall('require')[0].findall('enum')[1].get('name')


class VulkanFeatureLevel:
    def __init__(self,node):
        self.api = node.get('api')
        self.name = node.get('name')
        self.number = node.get('number')
        self.requires = []
        for require in node.findall('require'):
            if require.get('api') is not None and require.get('api') == 'vulkansc':
                continue
            self.requires.append(Requires(require))

class DispatchTable:
    def __init__(self, name, dispatch_type, requires):
        self.name = name
        self.dispatch_type = dispatch_type
        self.functions = {}
        for require in requires:
            for function in require.functions:
                if function.dispatch_type == dispatch_type or dispatch_type == 'instance' and function.name == 'vkGetInstanceProcAddr':
                    self.functions[function.name] = function

        self.gpa_type = 'PFN_GetDeviceProcAddr' if self.dispatch_type  == 'device' else 'PFN_GetInstanceProcAddr'
        self.gpa_name = 'get_device_proc_addr'  if self.dispatch_type == 'device' else 'get_instance_proc_addr'
        self.dispatch_handle = f'{self.dispatch_type.title()}' if self.dispatch_type != 'global' else None
        self.gpa_val = f'{self.dispatch_type}' if self.dispatch_type != 'global' else 'nullptr'

    def print_extern_decl(self, file):
        PrintConsecutivePlatforms(file, self.functions.values(), 'print_extern_decl', self.dispatch_type)

    def print_function_def(self, file):
        PrintConsecutivePlatforms(file, self.functions.values(), 'print_function_def', self.dispatch_type)

    def print_init_global_functions(self, file):
        file.write(f'void SimpleCppInitialize{self.name}Functions ({self.name} {self.name}) {{\n')
        PrintConsecutivePlatforms(file, self.functions.values(), 'print_init_global_functions', self.name)
        file.write('};\n')

    def print_dispatch_table(self, file):
        file.write(f'struct {self.name}DispatchTable {{\n')
        for function in self.functions.values():
            if function.platform is not None:
                file.write(f'#if defined({function.platform})\n')
            file.write(f'    PFN_{function.name[2:]} {function.name[2:]} = nullptr;\n')
            if function.platform is not None:
                file.write(f'#else\n')
                file.write(f'    void* z_padding_{function.name[2:]} = nullptr;\n')
                file.write(f'#endif // defined({function.platform})\n')
        file.write('};\n')

    def print_init_dispatch_table(self, file):
        file.write(f'void SimpleCppInitialize{self.name}DispatchTable ({self.name} {self.name}, {self.name}DispatchTable & table) {{\n')
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
        self.platform_requires = []
        self.base_types = []
        self.func_pointers = []
        self.flags_dict = {}
        self.enum_dict = {}
        self.handles = {}
        self.dispatchable_handles = []
        self.structures = []
        self.bitmask_dict = {}
        self.functions = []
        self.requires = []
        self.vk_feature_levels = []
        self.ext_list = []
        self.dispatch_tables = []
        self.dispatchable_handle_tables = []

        for platform in root.find('platforms'):
            self.platforms[platform.get('name')] = platform.get('protect')

        for ext in root.find('extensions'):
            if ext.tag == 'extension' and ext.get('supported') is not None and 'vulkan' in ext.get('supported').split(','):
                self.ext_list.append(Extension(ext, self.platforms))

        for feature in root.findall('feature'):
            if 'vulkan' in feature.get('api').split(','):
                self.vk_feature_levels.append(VulkanFeatureLevel(feature))

        for feature in self.vk_feature_levels:
            self.requires.extend(feature.requires)

        for ext in self.ext_list:
            self.requires.extend(ext.requires)

        for enum in root.findall("enums"):
            if enum.attrib.get('name') == "API Constants":
                for constant in enum.iter():
                    api_constant = ApiConstant(constant)
                    api_constants[api_constant.name] = api_constant
                break

        for xml_type in root.find('types'):
            category = xml_type.get('category')
            if category is None and xml_type.get('requires') is not None:
                self.platform_requires.append(PlatformRequires(xml_type))
            elif category == 'funcpointer':
                self.func_pointers.append(FuncPointer(xml_type))
            elif category == 'bitmask':
                flag = Flags(xml_type)
                self.flags_dict[flag.name] = flag
            elif category == 'enum':
                enum = Enum(xml_type)
                if enum.name.find('Flag') == -1 or enum.name.find('FlagBits') == -1:
                    self.enum_dict[enum.name] = Enum(xml_type)
            elif category == 'handle':
                handle = Handle(xml_type)
                self.handles[handle.name] = handle
                if handle.alias is None and handle.dispatchable:
                    self.dispatchable_handles.append(handle.name)
            elif category == 'union' or category == 'struct':
                self.structures.append(Structure(xml_type, self.handles))

        for enum in root.findall("enums"):
            if enum.get('type') == 'enum':
                self.enum_dict[enum.get('name')] = Enum(enum)
            elif enum.get('type') == 'bitmask':
                self.bitmask_dict[enum.get('name')] = Bitmask(enum)

        for commands in root.findall('commands'):
            for command in commands.findall('command'):
                new_function = Function(command, self.handles, self.dispatchable_handles)
                if new_function.name not in ['vkEnumerateDeviceLayerProperties']:
                    self.functions.append(new_function)

        types_set = set()
        commands_set = set()
        for require in self.requires:
            types_set.update(require.types)
            commands_set.update(require.commands)

        self.handles = { handle:v for handle,v in self.handles.items() if handle in types_set }
        self.enum_dict = { enum:v for enum,v in self.enum_dict.items() if enum in types_set }
        self.bitmask_dict = { bitmask:v for bitmask,v in self.bitmask_dict.items() if bitmask in types_set }
        self.flags_dict = { flag:v for flag,v in self.flags_dict.items() if flag in types_set }
        self.structures = [ structure for structure in self.structures if structure.name in types_set ]
        self.functions = [ function for function in self.functions if function.name in commands_set ]

        # add in flags which have no bitmask
        for name, flag in self.flags_dict.items():
            if flag.need_empty and flag.flag_bits_name not in self.bitmask_dict:
                if name in types_set:
                    self.bitmask_dict[flag.flag_bits_name] = EmptyBitmask(flag.flag_bits_name)


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

        for ext in self.ext_list:
            for require in ext.requires:
                require.check_platform(ext.platform, self.enum_dict, self.flags_dict, self.bitmask_dict, self.handles,
                    self.structures, self.functions)

        for require in self.requires:
            require.fill(self.enum_dict, self.bitmask_dict, self.functions)

        self.dispatch_tables.append(DispatchTable("Global", "global", self.requires))
        self.dispatch_tables.append(DispatchTable("Instance", "instance", self.requires))
        self.dispatch_tables.append(DispatchTable("Device", "device", self.requires))

        regular_structures = []
        alias_structures = []
        for struct in self.structures:
            if struct.alias is not None:
                alias_structures.append(struct)
            else:
                regular_structures.append(struct)
        self.structures.clear()
        self.structures.extend(regular_structures)
        self.structures.extend(alias_structures)


def print_bindings(bindings):

    with open(f'include/vk-simple/vk-simple.h', 'w') as vulkan_core:
        vulkan_core.write(license_header)
        vulkan_core.write(cpp_header_guard + '\n')
        PrintConsecutivePlatforms(vulkan_core, bindings.handles.values(), 'print')
        PrintConsecutivePlatforms(vulkan_core, bindings.enum_dict.values(), 'print')
        PrintConsecutivePlatforms(vulkan_core, bindings.bitmask_dict.values(), 'print')
        vulkan_core.write(bitmask_flags_macro + '\n')
        PrintConsecutivePlatforms(vulkan_core, bindings.flags_dict.values(), 'print')
        PrintConsecutivePlatforms(vulkan_core, bindings.structures, 'print')
        PrintConsecutivePlatforms(vulkan_core, bindings.functions, 'print_pfn_func_decl')
        # [ table.print_extern_decl(vulkan_core) for table in bindings.dispatch_tables ]
        for dispatch_table in bindings.dispatch_tables:
            dispatch_table.print_dispatch_table(vulkan_core)
        vulkan_core.write(cpp_footer)


def main():
    tree = xml.etree.ElementTree.parse('registry/vk.xml')
    root = tree.getroot()

    for tag in root.find('tags'):
        vendor_abbreviations.append(tag.get('name'))

    bindings = BindingGenerator(root)

    print_bindings(bindings)

if __name__ == "__main__":
    main()
