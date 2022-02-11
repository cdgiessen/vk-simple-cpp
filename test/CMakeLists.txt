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

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG        v2.13.1
)
FetchContent_Declare(
    vma_repo
    GIT_REPOSITORY https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator
    GIT_TAG        59ec0809a7176ce6b9fa3d6341b477102ac3d3aa
)
FetchContent_Declare(
    vk_bootstrap
    GIT_REPOSITORY https://github.com/charles-lunarg/vk-bootstrap
    GIT_TAG        7aef0dc1c191dbe3392e8abc1b71fd40529295c7
)
FetchContent_MakeAvailable(catch2 vk_bootstrap)

FetchContent_GetProperties(vma_repo)
if(NOT vma_repoPOPULATED)
    FetchContent_Populate(vma_repo)
    add_library(VulkanMemoryAllocator INTERFACE)
    target_include_directories(VulkanMemoryAllocator INTERFACE ${vma_repo_SOURCE_DIR}/include)
endif()

cmake_policy(SET CMP0079 NEW)
target_link_libraries(vk-bootstrap PUBLIC vulkan-simple-cpp)