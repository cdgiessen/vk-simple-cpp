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

license_header = '''/*
 * Copyright 2021 Charles Giessen (cdgiessen@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
'''

vk_module_file_header = '''
// clang-format off
#pragma once
#include <stdint.h>
#include <cstddef>
#include <array>
#include <new>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "vk_platform.h"

#if defined(VK_USE_PLATFORM_FUCHSIA)
#include <zircon/types.h>
#endif

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include <wayland-client.h>
#endif

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb.h>
#endif

#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include <X11/Xlib.h>
#endif

#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#include <directfb.h>
#endif

#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#endif

#if defined(VK_USE_PLATFORM_GGP)
#include <ggp_c/vulkan_types.h>
#endif

// Compatability with compilers that don't support __has_feature
#if !defined(__has_feature)
#define __has_feature(x) 0
#endif

#if !defined(VK_MODULE_DISABLE_LEAK_SANITIZER_SUPPRESSION) && (__has_feature(address_sanitizer) || defined(__SANITIZE_ADDRESS__) )
#include <sanitizer/lsan_interface.h>
#define VK_MODULE_LEAK_SANITIZER_SUPPRESSION_CODE __lsan::ScopedDisabler lsan_scope{};
#else
#define VK_MODULE_LEAK_SANITIZER_SUPPRESSION_CODE
#endif

#if !defined(__has_feature)
#undef __has_feature
#endif

#if !defined(VULKAN_CUSTOM_ASSERT)
#include <cassert>
#define VULKAN_CUSTOM_ASSERT assert
#endif

namespace vk {
constexpr uint32_t make_vk_version(uint32_t major, uint32_t minor, uint32_t patch) {
    return major << 22 | minor << 12 | patch;
}

#if !defined(VK_DEFINE_HANDLE)
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
#endif

#if !defined(VK_DEFINE_NON_DISPATCHABLE_HANDLE)
#if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__) ) || defined(_M_X64) || defined(__ia64) || defined (_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
        #define VK_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef struct object##_T *object;
#else
        #define VK_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef uint64_t object;
#endif
#endif
'''

bitmask_flags_macro = '''
#define DECLARE_ENUM_FLAG_OPERATORS(FLAG_TYPE, FLAG_BITS, BASE_TYPE)                       \\
                                                                                           \\
struct FLAG_TYPE {                                                                         \\
    BASE_TYPE flags = static_cast<BASE_TYPE>(0);                                           \\
                                                                                           \\
    constexpr FLAG_TYPE() noexcept = default;                                              \\
    constexpr FLAG_TYPE(BASE_TYPE in) noexcept: flags(in){ }                      \\
    constexpr FLAG_TYPE(FLAG_BITS in) noexcept: flags(static_cast<BASE_TYPE>(in)){ }       \\
    constexpr bool operator==(FLAG_TYPE const& right) const { return flags == right.flags;}\\
    constexpr bool operator!=(FLAG_TYPE const& right) const { return flags != right.flags;}\\
    constexpr explicit operator BASE_TYPE() const { return flags;}                         \\
    constexpr explicit operator bool() const noexcept {                                    \\
      return flags != 0;                                                                   \\
    }                                                                                      \\
};                                                                                         \\
constexpr FLAG_TYPE operator|(FLAG_TYPE a, FLAG_TYPE b) noexcept {                         \\
    return static_cast<FLAG_TYPE>(a.flags | b.flags);                                      \\
}                                                                                          \\
constexpr FLAG_TYPE operator&(FLAG_TYPE a, FLAG_TYPE b) noexcept {                         \\
    return static_cast<FLAG_TYPE>(a.flags & b.flags);                                      \\
}                                                                                          \\
constexpr FLAG_TYPE operator^(FLAG_TYPE a, FLAG_TYPE b) noexcept {                         \\
    return static_cast<FLAG_TYPE>(a.flags ^ b.flags);                                      \\
}                                                                                          \\
constexpr FLAG_TYPE operator~(FLAG_TYPE a) noexcept {                                      \\
    return static_cast<FLAG_TYPE>(~a.flags);                                               \\
}                                                                                          \\
constexpr FLAG_TYPE& operator|=(FLAG_TYPE& a, FLAG_TYPE b) noexcept {                      \\
    a.flags = (a.flags | b.flags); return a;                                               \\
}                                                                                          \\
constexpr FLAG_TYPE& operator&=(FLAG_TYPE& a, FLAG_TYPE b) noexcept {                      \\
    a.flags = (a.flags & b.flags); return a;                                               \\
}                                                                                          \\
constexpr FLAG_TYPE operator^=(FLAG_TYPE& a, FLAG_TYPE b) noexcept {                       \\
    a.flags = (a.flags ^ b.flags); return a;                                               \\
}                                                                                          \\
constexpr FLAG_TYPE operator|(FLAG_BITS a, FLAG_BITS b) noexcept {                         \\
    return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) | static_cast<BASE_TYPE>(b));  \\
}                                                                                          \\
constexpr FLAG_TYPE operator&(FLAG_BITS a, FLAG_BITS b) noexcept {                         \\
    return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) & static_cast<BASE_TYPE>(b));  \\
}                                                                                          \\
constexpr FLAG_TYPE operator~(FLAG_BITS key) noexcept {                                    \\
    return static_cast<FLAG_TYPE>(~static_cast<BASE_TYPE>(key));                           \\
}                                                                                          \\
constexpr FLAG_TYPE operator^(FLAG_BITS a, FLAG_BITS b) noexcept {                         \\
    return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) ^ static_cast<BASE_TYPE>(b));  \\
}                                                                                          \\
'''

cpp_header_guard = '''
// clang-format off
#ifndef SIMPLE_VULKAN_H_
#ifdef VULKAN_H_
#error "Must include these bindings first, not official C vulkan headers (vulkan.h)"
#endif
#endif
#ifndef VULKAN_H_
#define VULKAN_H_ 1
#define SIMPLE_VULKAN_H_ 1

#define VK_VERSION_1_0 1
#define VK_VERSION_1_1 1
#define VK_VERSION_1_2 1
#include <stdint.h>
#include "vk_platform.h"
'''

cpp_platform_headers = '''
#if defined(VK_USE_PLATFORM_FUCHSIA)
#include <zircon/types.h>
#endif

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include <wayland-client.h>
#endif

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb.h>
#endif

#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include <X11/Xlib.h>
#endif

#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#include <directfb.h>
#endif

#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#endif

#if defined(VK_USE_PLATFORM_GGP)
#include <ggp_c/vulkan_types.h>
#endif
'''

cpp_footer  = '''
// This function finds the Vulkan-Loader (vulkan-1.dll, libvulkan.so, libvulkan.dylib, etc) on a system, loads it,
// and loads the follwing functions:
//  * vkGetInstanceProcAddr
//  * vkCreateInstance
//  * vkEnumerateInstanceExtensionProperties
//  * vkEnumerateInstanceLayerProperties
//  * vkEnumerateInstanceVersion
//
// Note:
// This function must be called before all other vulkan calls!
//
// Return Codes:
// VkResult::Success -- Successful initialization & loading of functions
// VkResult::ErrorInitializationFailed -- failure [unable to find Vulkan-Loader]
//
// Optional Parameter:
// PFN_vkGetInstanceProcAddr pfn_vkGetInstanceProcAddr = VK_NULL_HANDLE
VkResult vkInitializeLoaderLibrary(PFN_vkGetInstanceProcAddr pfn_vkGetInstanceProcAddr = VK_NULL_HANDLE);

// Close the Vulkan-Loader and assigns VK_NULL_HANDLE to vkGetInstanceProcAddr
//
// Note:
// After this function is called, no further vulkan calls can be made, except for `vkInitializeLoaderLibrary()`
void vkCloseLoaderLibrary();

// Initialize the instance and physical device functions into the global function pointers
// (all functions which take a VkInstance or VkPhysicalDevice as the first parameter)
//
// Note: This must only be called after the application has created a valid VkInstance with vkCreateInstance
//
// Parameter:
// VkInstance instance
// The VkInstance handle which the application has created. Must not be VK_NULL_HANDLE
void vkInitializeInstanceFunctions(VkInstance instance);

// Loads device functions into the global function pointers
//
// Notes:
//  * This function must not be used for any application which creates multiple VkDevices.
//    Instead, the application should use a VkDeviceDispatchTable per device created.
//  * This must only be called after the application has created a valid VkDevice with vkCreateDevice
//
// Parameter:
// VkDevice device
// The VkDevice handle which the application has created. Must not be VK_NULL_HANDLE
void vkInitializeDeviceFunctions(VkDevice device);

// Loads device functions into the provided VkDeviceDispatchTable
//
// Notes:
//  *
//  * This must only be called after the application has created a valid VkDevice with vkCreateDevice
//
// Parameters:
//  * VkDevice device
// The VkDevice handle which the application has created. Must not be VK_NULL_HANDLE
//  * VkDeviceDispatchTable& table
// The table in which holds all loaded device function pointers.
void vkInitializeDeviceDispatchTable(VkDevice device, VkDeviceDispatchTable& table);

#ifdef __cplusplus
} // extern "C"
#endif

#if defined(VULKAN_CPP_IMPLEMENTATION)
#include "vulkan.cpp"
#endif //defined(VULKAN_CPP_IMPLEMENTATION)

#endif // VULKAN_H_
// clang-format on
'''

cpp_definition = '''

#if defined(_WIN32)
    using HINSTANCE = struct HINSTANCE__ *;
    #if defined( _WIN64 )
    using FARPROC = int64_t( __stdcall * )();
    #else
    using FARPROC = typedef int( __stdcall * )();
    #endif
    extern "C" __declspec( dllimport ) HINSTANCE __stdcall LoadLibraryA( char const * lpLibFileName );
    extern "C" __declspec( dllimport ) int __stdcall FreeLibrary( HINSTANCE hLibModule );
    extern "C" __declspec( dllimport ) FARPROC __stdcall GetProcAddress( HINSTANCE hModule, const char * lpProcName );
#elif defined(__linux__) || defined(__APPLE__)
    #include <dlfcn.h>
#endif

#if defined(__linux__) || defined(__APPLE__)
void *library = nullptr;
#elif defined(_WIN32)
::HINSTANCE library = nullptr;
#endif

void* LibraryLoadFunction(const char* name) {
#if defined(__linux__) || defined(__APPLE__)
    return dlsym(library, name);
#elif defined(_WIN32)
    return ::GetProcAddress(library, name);
#endif
}
void LoadGetInstanceProcAddr(){
    vkGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(LibraryLoadFunction("vkGetInstanceProcAddr"));
}
void LoadGlobalFunctions() {
    if (vkGetInstanceProcAddr == VK_NULL_HANDLE) return;
    vkCreateInstance = reinterpret_cast<PFN_vkCreateInstance>(vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkCreateInstance"));
    vkEnumerateInstanceExtensionProperties = reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceExtensionProperties"));
    vkEnumerateInstanceLayerProperties = reinterpret_cast<PFN_vkEnumerateInstanceLayerProperties>(vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceLayerProperties"));
    vkEnumerateInstanceVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(vkGetInstanceProcAddr(VK_NULL_HANDLE, "vkEnumerateInstanceVersion"));
}

VkResult vkInitializeLoaderLibrary(PFN_vkGetInstanceProcAddr pfn_vkGetInstanceProcAddr){
    if(pfn_vkGetInstanceProcAddr != VK_NULL_HANDLE){
        vkGetInstanceProcAddr = pfn_vkGetInstanceProcAddr;
        LoadGlobalFunctions();
        return VkResult::Success;
    }

#if defined(__linux__)
    library = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
    if (!library) library = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
#elif defined(__APPLE__)
    library = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
#elif defined(_WIN32)
    library = ::LoadLibraryA("vulkan-1.dll");
#endif
    if (library == 0) return VkResult::ErrorInitializationFailed;
    LoadGetInstanceProcAddr();
    LoadGlobalFunctions();
    if (vkGetInstanceProcAddr == nullptr) return VkResult::ErrorInitializationFailed;
    return VkResult::Success;
}

void vkCloseLoaderLibrary(){
    if (library != nullptr) {
#if defined(__linux__) || defined(__APPLE__)
        dlclose(library);
#elif defined(_WIN32)
        ::FreeLibrary(library);
#endif
        library = 0;
        vkGetInstanceProcAddr = VK_NULL_HANDLE;
    }
}
'''

begin_extern_c = '''
#ifdef __cplusplus
extern "C" {
#endif
'''

end_extern_c = '''
#ifdef __cplusplus
} // extern "C"
#endif
'''