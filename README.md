# vk-simple-cpp

Takes the current C headers and adds a few quality of life improvements while staying faithful to the original C API.

Improvements:

* Enums and Bitfields use enum classes, makes it impossible to use the wrong enum.
* sType parameters are initialized to their correct value.
* Structs always initialize all values to zero (except sType). Prevents uninitialized memory bugs.
* Add an API to automatically load function pointers with the following benefits:
  * Function pointers are known to be faster than using the exported Vulkan functions.
  * No compile time dependency on the Vulkan-Loader. It is loaded at runtime instead.
  * Automatically querying function pointers from extensions
  * Removes the need to use an external library such as [volk](https://github.com/zeux/volk) to accomplish this task

Notes:

* This aims to be a production ready solution - though currently lacks in test coverage
* The goal of these bindings is to bridge the gap between the simplicity of the C API and the type safety of `vulkan.hpp`.
* I am not planning on adding additional features, but am open to simple QoL suggestions.


## Getting started

Since vk-simple-cpp loads function pointers, some special functions must be called in order to load the functions.

```c++
// Call this before calling any vulkan functions
VkResult res = vkSimpleCppInitializeLoaderLibrary();
assert(res == VK_SUCCESS);

// Create your instance
vkSimplCppInitializeInstanceFunctions(instance);
// Create your device
vkSimpleCppInitializeDeviceFunctions(device);

... // rest of the renderer/application mainloop

// shutdown
vkSimpleCppCloseLoaderLibrary();
```


To use vk-simple-cpp as a header-only library, define the following macro in one source file before including the vulkan headers.
```c++
#define VULKAN_CPP_IMPLEMENTATION
#include "vulkan/vulkan.h"
```