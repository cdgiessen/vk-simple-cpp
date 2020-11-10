#include "vkm_function.h"
namespace vk {
[[nodiscard]] expected<Instance> GlobalFunctions::CreateInstance(const InstanceCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Instance pInstance;
    vk::Result result = static_cast<Result>(pfn_CreateInstance(reinterpret_cast<const VkInstanceCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkInstance*>(&pInstance)));
    return expected<Instance>(pInstance, result);
}
[[nodiscard]] PFN_vkVoidFunction GlobalFunctions::GetInstanceProcAddr(Instance instance, 
    const char* pName) const {
    return pfn_GetInstanceProcAddr(instance.get(),
        pName);
}
[[nodiscard]] expected<detail::fixed_vector<ExtensionProperties>> GlobalFunctions::EnumerateInstanceExtensionProperties(const char* pLayerName) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_EnumerateInstanceExtensionProperties(pLayerName,
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<ExtensionProperties>{}, result);
    detail::fixed_vector<ExtensionProperties> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_EnumerateInstanceExtensionProperties(pLayerName,
        &pPropertyCount,
        reinterpret_cast<VkExtensionProperties*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<LayerProperties>> GlobalFunctions::EnumerateInstanceLayerProperties() const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_EnumerateInstanceLayerProperties(&pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<LayerProperties>{}, result);
    detail::fixed_vector<LayerProperties> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_EnumerateInstanceLayerProperties(&pPropertyCount,
        reinterpret_cast<VkLayerProperties*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<uint32_t> GlobalFunctions::EnumerateInstanceVersion() const {
    if (pfn_EnumerateInstanceVersion == 0) return expected<uint32_t>(VK_MAKE_VERSION(1,0,0), Result::Success);
    uint32_t pApiVersion;
    vk::Result result = static_cast<Result>(pfn_EnumerateInstanceVersion(&pApiVersion));
    return expected<uint32_t>(pApiVersion, result);
}
GlobalFunctions::GlobalFunctions() noexcept {}
GlobalFunctions::GlobalFunctions(DynamicLibrary const& library) noexcept {
    detail::PFN_vkGetInstanceProcAddr get_instance_proc_addr = library.get();
    pfn_CreateInstance = reinterpret_cast<detail::PFN_vkCreateInstance>(get_instance_proc_addr(nullptr,"vkCreateInstance"));
    pfn_GetInstanceProcAddr = get_instance_proc_addr;
    pfn_EnumerateInstanceExtensionProperties = reinterpret_cast<detail::PFN_vkEnumerateInstanceExtensionProperties>(get_instance_proc_addr(nullptr,"vkEnumerateInstanceExtensionProperties"));
    pfn_EnumerateInstanceLayerProperties = reinterpret_cast<detail::PFN_vkEnumerateInstanceLayerProperties>(get_instance_proc_addr(nullptr,"vkEnumerateInstanceLayerProperties"));
    pfn_EnumerateInstanceVersion = reinterpret_cast<detail::PFN_vkEnumerateInstanceVersion>(get_instance_proc_addr(nullptr,"vkEnumerateInstanceVersion"));
}
void InstanceFunctions::DestroyInstance(const AllocationCallbacks* pAllocator) const {
    pfn_DestroyInstance(instance.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<detail::fixed_vector<PhysicalDevice>> InstanceFunctions::EnumeratePhysicalDevices() const {
    uint32_t pPhysicalDeviceCount = 0;
    vk::Result result = static_cast<Result>(pfn_EnumeratePhysicalDevices(instance.get(),
        &pPhysicalDeviceCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PhysicalDevice>{}, result);
    detail::fixed_vector<PhysicalDevice> pPhysicalDevices{pPhysicalDeviceCount};
    result = static_cast<Result>(pfn_EnumeratePhysicalDevices(instance.get(),
        &pPhysicalDeviceCount,
        reinterpret_cast<VkPhysicalDevice*>(pPhysicalDevices.data())));
    if (pPhysicalDeviceCount < pPhysicalDevices.size()) pPhysicalDevices.shrink(pPhysicalDeviceCount);
    return expected(std::move(pPhysicalDevices), result);
}
[[nodiscard]] PFN_vkVoidFunction InstanceFunctions::GetDeviceProcAddr(Device device, 
    const char* pName) const {
    return pfn_GetDeviceProcAddr(device.get(),
        pName);
}
[[nodiscard]] PFN_vkVoidFunction InstanceFunctions::GetInstanceProcAddr(const char* pName) const {
    return pfn_GetInstanceProcAddr(instance.get(),
        pName);
}
[[nodiscard]] PhysicalDeviceProperties InstanceFunctions::GetPhysicalDeviceProperties(PhysicalDevice physicalDevice) const {
    PhysicalDeviceProperties pProperties;
    pfn_GetPhysicalDeviceProperties(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceProperties*>(&pProperties));
    return pProperties;
}
[[nodiscard]] detail::fixed_vector<QueueFamilyProperties> InstanceFunctions::GetPhysicalDeviceQueueFamilyProperties(PhysicalDevice physicalDevice) const {
    uint32_t pQueueFamilyPropertyCount = 0;
    pfn_GetPhysicalDeviceQueueFamilyProperties(physicalDevice.get(),
        &pQueueFamilyPropertyCount,
        nullptr);
    detail::fixed_vector<QueueFamilyProperties> pQueueFamilyProperties{pQueueFamilyPropertyCount};
    pfn_GetPhysicalDeviceQueueFamilyProperties(physicalDevice.get(),
        &pQueueFamilyPropertyCount,
        reinterpret_cast<VkQueueFamilyProperties*>(pQueueFamilyProperties.data()));
    if (pQueueFamilyPropertyCount < pQueueFamilyProperties.size()) pQueueFamilyProperties.shrink(pQueueFamilyPropertyCount);
    return pQueueFamilyProperties;
}
[[nodiscard]] PhysicalDeviceMemoryProperties InstanceFunctions::GetPhysicalDeviceMemoryProperties(PhysicalDevice physicalDevice) const {
    PhysicalDeviceMemoryProperties pMemoryProperties;
    pfn_GetPhysicalDeviceMemoryProperties(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceMemoryProperties*>(&pMemoryProperties));
    return pMemoryProperties;
}
[[nodiscard]] PhysicalDeviceFeatures InstanceFunctions::GetPhysicalDeviceFeatures(PhysicalDevice physicalDevice) const {
    PhysicalDeviceFeatures pFeatures;
    pfn_GetPhysicalDeviceFeatures(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceFeatures*>(&pFeatures));
    return pFeatures;
}
[[nodiscard]] FormatProperties InstanceFunctions::GetPhysicalDeviceFormatProperties(PhysicalDevice physicalDevice, 
    Format format) const {
    FormatProperties pFormatProperties;
    pfn_GetPhysicalDeviceFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        reinterpret_cast<VkFormatProperties*>(&pFormatProperties));
    return pFormatProperties;
}
[[nodiscard]] expected<ImageFormatProperties> InstanceFunctions::GetPhysicalDeviceImageFormatProperties(PhysicalDevice physicalDevice, 
    Format format, 
    ImageType type, 
    ImageTiling tiling, 
    ImageUsageFlags usage, 
    ImageCreateFlags flags) const {
    ImageFormatProperties pImageFormatProperties;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceImageFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkImageTiling>(tiling),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageCreateFlags>(flags),
        reinterpret_cast<VkImageFormatProperties*>(&pImageFormatProperties)));
    return expected<ImageFormatProperties>(pImageFormatProperties, result);
}
[[nodiscard]] expected<Device> InstanceFunctions::CreateDevice(PhysicalDevice physicalDevice, 
    const DeviceCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Device pDevice;
    vk::Result result = static_cast<Result>(pfn_CreateDevice(physicalDevice.get(),
        reinterpret_cast<const VkDeviceCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDevice*>(&pDevice)));
    return expected<Device>(pDevice, result);
}
[[nodiscard]] expected<detail::fixed_vector<ExtensionProperties>> InstanceFunctions::EnumerateDeviceExtensionProperties(PhysicalDevice physicalDevice, 
    const char* pLayerName) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_EnumerateDeviceExtensionProperties(physicalDevice.get(),
        pLayerName,
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<ExtensionProperties>{}, result);
    detail::fixed_vector<ExtensionProperties> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_EnumerateDeviceExtensionProperties(physicalDevice.get(),
        pLayerName,
        &pPropertyCount,
        reinterpret_cast<VkExtensionProperties*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] detail::fixed_vector<SparseImageFormatProperties> InstanceFunctions::GetPhysicalDeviceSparseImageFormatProperties(PhysicalDevice physicalDevice, 
    Format format, 
    ImageType type, 
    SampleCountFlagBits samples, 
    ImageUsageFlags usage, 
    ImageTiling tiling) const {
    uint32_t pPropertyCount = 0;
    pfn_GetPhysicalDeviceSparseImageFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkSampleCountFlagBits>(samples),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageTiling>(tiling),
        &pPropertyCount,
        nullptr);
    detail::fixed_vector<SparseImageFormatProperties> pProperties{pPropertyCount};
    pfn_GetPhysicalDeviceSparseImageFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkSampleCountFlagBits>(samples),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageTiling>(tiling),
        &pPropertyCount,
        reinterpret_cast<VkSparseImageFormatProperties*>(pProperties.data()));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return pProperties;
}
[[nodiscard]] expected<detail::fixed_vector<PhysicalDeviceGroupProperties>> InstanceFunctions::EnumeratePhysicalDeviceGroups() const {
    uint32_t pPhysicalDeviceGroupCount = 0;
    vk::Result result = static_cast<Result>(pfn_EnumeratePhysicalDeviceGroups(instance.get(),
        &pPhysicalDeviceGroupCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PhysicalDeviceGroupProperties>{}, result);
    detail::fixed_vector<PhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties{pPhysicalDeviceGroupCount};
    result = static_cast<Result>(pfn_EnumeratePhysicalDeviceGroups(instance.get(),
        &pPhysicalDeviceGroupCount,
        reinterpret_cast<VkPhysicalDeviceGroupProperties*>(pPhysicalDeviceGroupProperties.data())));
    if (pPhysicalDeviceGroupCount < pPhysicalDeviceGroupProperties.size()) pPhysicalDeviceGroupProperties.shrink(pPhysicalDeviceGroupCount);
    return expected(std::move(pPhysicalDeviceGroupProperties), result);
}
[[nodiscard]] PhysicalDeviceFeatures2 InstanceFunctions::GetPhysicalDeviceFeatures2(PhysicalDevice physicalDevice) const {
    PhysicalDeviceFeatures2 pFeatures;
    pfn_GetPhysicalDeviceFeatures2(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceFeatures2*>(&pFeatures));
    return pFeatures;
}
[[nodiscard]] PhysicalDeviceProperties2 InstanceFunctions::GetPhysicalDeviceProperties2(PhysicalDevice physicalDevice) const {
    PhysicalDeviceProperties2 pProperties;
    pfn_GetPhysicalDeviceProperties2(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceProperties2*>(&pProperties));
    return pProperties;
}
[[nodiscard]] FormatProperties2 InstanceFunctions::GetPhysicalDeviceFormatProperties2(PhysicalDevice physicalDevice, 
    Format format) const {
    FormatProperties2 pFormatProperties;
    pfn_GetPhysicalDeviceFormatProperties2(physicalDevice.get(),
        static_cast<VkFormat>(format),
        reinterpret_cast<VkFormatProperties2*>(&pFormatProperties));
    return pFormatProperties;
}
[[nodiscard]] expected<ImageFormatProperties2> InstanceFunctions::GetPhysicalDeviceImageFormatProperties2(PhysicalDevice physicalDevice, 
    const PhysicalDeviceImageFormatInfo2&  pImageFormatInfo) const {
    ImageFormatProperties2 pImageFormatProperties;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceImageFormatProperties2(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(&pImageFormatInfo),
        reinterpret_cast<VkImageFormatProperties2*>(&pImageFormatProperties)));
    return expected<ImageFormatProperties2>(pImageFormatProperties, result);
}
[[nodiscard]] detail::fixed_vector<QueueFamilyProperties2> InstanceFunctions::GetPhysicalDeviceQueueFamilyProperties2(PhysicalDevice physicalDevice) const {
    uint32_t pQueueFamilyPropertyCount = 0;
    pfn_GetPhysicalDeviceQueueFamilyProperties2(physicalDevice.get(),
        &pQueueFamilyPropertyCount,
        nullptr);
    detail::fixed_vector<QueueFamilyProperties2> pQueueFamilyProperties{pQueueFamilyPropertyCount};
    pfn_GetPhysicalDeviceQueueFamilyProperties2(physicalDevice.get(),
        &pQueueFamilyPropertyCount,
        reinterpret_cast<VkQueueFamilyProperties2*>(pQueueFamilyProperties.data()));
    if (pQueueFamilyPropertyCount < pQueueFamilyProperties.size()) pQueueFamilyProperties.shrink(pQueueFamilyPropertyCount);
    return pQueueFamilyProperties;
}
[[nodiscard]] PhysicalDeviceMemoryProperties2 InstanceFunctions::GetPhysicalDeviceMemoryProperties2(PhysicalDevice physicalDevice) const {
    PhysicalDeviceMemoryProperties2 pMemoryProperties;
    pfn_GetPhysicalDeviceMemoryProperties2(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceMemoryProperties2*>(&pMemoryProperties));
    return pMemoryProperties;
}
[[nodiscard]] detail::fixed_vector<SparseImageFormatProperties2> InstanceFunctions::GetPhysicalDeviceSparseImageFormatProperties2(PhysicalDevice physicalDevice, 
    const PhysicalDeviceSparseImageFormatInfo2&  pFormatInfo) const {
    uint32_t pPropertyCount = 0;
    pfn_GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(&pFormatInfo),
        &pPropertyCount,
        nullptr);
    detail::fixed_vector<SparseImageFormatProperties2> pProperties{pPropertyCount};
    pfn_GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(&pFormatInfo),
        &pPropertyCount,
        reinterpret_cast<VkSparseImageFormatProperties2*>(pProperties.data()));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return pProperties;
}
[[nodiscard]] ExternalBufferProperties InstanceFunctions::GetPhysicalDeviceExternalBufferProperties(PhysicalDevice physicalDevice, 
    const PhysicalDeviceExternalBufferInfo&  pExternalBufferInfo) const {
    ExternalBufferProperties pExternalBufferProperties;
    pfn_GetPhysicalDeviceExternalBufferProperties(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(&pExternalBufferInfo),
        reinterpret_cast<VkExternalBufferProperties*>(&pExternalBufferProperties));
    return pExternalBufferProperties;
}
[[nodiscard]] ExternalFenceProperties InstanceFunctions::GetPhysicalDeviceExternalFenceProperties(PhysicalDevice physicalDevice, 
    const PhysicalDeviceExternalFenceInfo&  pExternalFenceInfo) const {
    ExternalFenceProperties pExternalFenceProperties;
    pfn_GetPhysicalDeviceExternalFenceProperties(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(&pExternalFenceInfo),
        reinterpret_cast<VkExternalFenceProperties*>(&pExternalFenceProperties));
    return pExternalFenceProperties;
}
[[nodiscard]] ExternalSemaphoreProperties InstanceFunctions::GetPhysicalDeviceExternalSemaphoreProperties(PhysicalDevice physicalDevice, 
    const PhysicalDeviceExternalSemaphoreInfo&  pExternalSemaphoreInfo) const {
    ExternalSemaphoreProperties pExternalSemaphoreProperties;
    pfn_GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(&pExternalSemaphoreInfo),
        reinterpret_cast<VkExternalSemaphoreProperties*>(&pExternalSemaphoreProperties));
    return pExternalSemaphoreProperties;
}
void InstanceFunctions::DestroySurfaceKHR(SurfaceKHR surface, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroySurfaceKHR(instance.get(),
        surface.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<Bool32> InstanceFunctions::GetPhysicalDeviceSurfaceSupportKHR(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex, 
    SurfaceKHR surface) const {
    Bool32 pSupported;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceSupportKHR(physicalDevice.get(),
        queueFamilyIndex,
        surface.get(),
        &pSupported));
    return expected<Bool32>(pSupported, result);
}
[[nodiscard]] expected<SurfaceCapabilitiesKHR> InstanceFunctions::GetPhysicalDeviceSurfaceCapabilitiesKHR(PhysicalDevice physicalDevice, 
    SurfaceKHR surface) const {
    SurfaceCapabilitiesKHR pSurfaceCapabilities;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice.get(),
        surface.get(),
        reinterpret_cast<VkSurfaceCapabilitiesKHR*>(&pSurfaceCapabilities)));
    return expected<SurfaceCapabilitiesKHR>(pSurfaceCapabilities, result);
}
[[nodiscard]] expected<detail::fixed_vector<SurfaceFormatKHR>> InstanceFunctions::GetPhysicalDeviceSurfaceFormatsKHR(PhysicalDevice physicalDevice, 
    SurfaceKHR surface) const {
    uint32_t pSurfaceFormatCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice.get(),
        surface.get(),
        &pSurfaceFormatCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<SurfaceFormatKHR>{}, result);
    detail::fixed_vector<SurfaceFormatKHR> pSurfaceFormats{pSurfaceFormatCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice.get(),
        surface.get(),
        &pSurfaceFormatCount,
        reinterpret_cast<VkSurfaceFormatKHR*>(pSurfaceFormats.data())));
    if (pSurfaceFormatCount < pSurfaceFormats.size()) pSurfaceFormats.shrink(pSurfaceFormatCount);
    return expected(std::move(pSurfaceFormats), result);
}
[[nodiscard]] expected<detail::fixed_vector<PresentModeKHR>> InstanceFunctions::GetPhysicalDeviceSurfacePresentModesKHR(PhysicalDevice physicalDevice, 
    SurfaceKHR surface) const {
    uint32_t pPresentModeCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice.get(),
        surface.get(),
        &pPresentModeCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PresentModeKHR>{}, result);
    detail::fixed_vector<PresentModeKHR> pPresentModes{pPresentModeCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice.get(),
        surface.get(),
        &pPresentModeCount,
        reinterpret_cast<VkPresentModeKHR*>(pPresentModes.data())));
    if (pPresentModeCount < pPresentModes.size()) pPresentModes.shrink(pPresentModeCount);
    return expected(std::move(pPresentModes), result);
}
[[nodiscard]] expected<detail::fixed_vector<Rect2D>> InstanceFunctions::GetPhysicalDevicePresentRectanglesKHR(PhysicalDevice physicalDevice, 
    SurfaceKHR surface) const {
    uint32_t pRectCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDevicePresentRectanglesKHR(physicalDevice.get(),
        surface.get(),
        &pRectCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<Rect2D>{}, result);
    detail::fixed_vector<Rect2D> pRects{pRectCount};
    result = static_cast<Result>(pfn_GetPhysicalDevicePresentRectanglesKHR(physicalDevice.get(),
        surface.get(),
        &pRectCount,
        reinterpret_cast<VkRect2D*>(pRects.data())));
    if (pRectCount < pRects.size()) pRects.shrink(pRectCount);
    return expected(std::move(pRects), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayPropertiesKHR>> InstanceFunctions::GetPhysicalDeviceDisplayPropertiesKHR(PhysicalDevice physicalDevice) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayPropertiesKHR>{}, result);
    detail::fixed_vector<DisplayPropertiesKHR> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice.get(),
        &pPropertyCount,
        reinterpret_cast<VkDisplayPropertiesKHR*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayPlanePropertiesKHR>> InstanceFunctions::GetPhysicalDeviceDisplayPlanePropertiesKHR(PhysicalDevice physicalDevice) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayPlanePropertiesKHR>{}, result);
    detail::fixed_vector<DisplayPlanePropertiesKHR> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice.get(),
        &pPropertyCount,
        reinterpret_cast<VkDisplayPlanePropertiesKHR*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayKHR>> InstanceFunctions::GetDisplayPlaneSupportedDisplaysKHR(PhysicalDevice physicalDevice, 
    uint32_t planeIndex) const {
    uint32_t pDisplayCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetDisplayPlaneSupportedDisplaysKHR(physicalDevice.get(),
        planeIndex,
        &pDisplayCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayKHR>{}, result);
    detail::fixed_vector<DisplayKHR> pDisplays{pDisplayCount};
    result = static_cast<Result>(pfn_GetDisplayPlaneSupportedDisplaysKHR(physicalDevice.get(),
        planeIndex,
        &pDisplayCount,
        reinterpret_cast<VkDisplayKHR*>(pDisplays.data())));
    if (pDisplayCount < pDisplays.size()) pDisplays.shrink(pDisplayCount);
    return expected(std::move(pDisplays), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayModePropertiesKHR>> InstanceFunctions::GetDisplayModePropertiesKHR(PhysicalDevice physicalDevice, 
    DisplayKHR display) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetDisplayModePropertiesKHR(physicalDevice.get(),
        display.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayModePropertiesKHR>{}, result);
    detail::fixed_vector<DisplayModePropertiesKHR> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetDisplayModePropertiesKHR(physicalDevice.get(),
        display.get(),
        &pPropertyCount,
        reinterpret_cast<VkDisplayModePropertiesKHR*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<DisplayModeKHR> InstanceFunctions::CreateDisplayModeKHR(PhysicalDevice physicalDevice, 
    DisplayKHR display, 
    const DisplayModeCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DisplayModeKHR pMode;
    vk::Result result = static_cast<Result>(pfn_CreateDisplayModeKHR(physicalDevice.get(),
        display.get(),
        reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDisplayModeKHR*>(&pMode)));
    return expected<DisplayModeKHR>(pMode, result);
}
[[nodiscard]] expected<DisplayPlaneCapabilitiesKHR> InstanceFunctions::GetDisplayPlaneCapabilitiesKHR(PhysicalDevice physicalDevice, 
    DisplayModeKHR mode, 
    uint32_t planeIndex) const {
    DisplayPlaneCapabilitiesKHR pCapabilities;
    vk::Result result = static_cast<Result>(pfn_GetDisplayPlaneCapabilitiesKHR(physicalDevice.get(),
        mode.get(),
        planeIndex,
        reinterpret_cast<VkDisplayPlaneCapabilitiesKHR*>(&pCapabilities)));
    return expected<DisplayPlaneCapabilitiesKHR>(pCapabilities, result);
}
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateDisplayPlaneSurfaceKHR(const DisplaySurfaceCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateDisplayPlaneSurfaceKHR(instance.get(),
        reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#if defined(VK_USE_PLATFORM_XLIB_KHR)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateXlibSurfaceKHR(const XlibSurfaceCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateXlibSurfaceKHR(instance.get(),
        reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XLIB_KHR)
[[nodiscard]] VkBool32 InstanceFunctions::GetPhysicalDeviceXlibPresentationSupportKHR(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex, 
    Display&  dpy, 
    VisualID visualID) const {
    return pfn_GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice.get(),
        queueFamilyIndex,
        reinterpret_cast<Display*>(&dpy),
        static_cast<VisualID>(visualID));
}
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateXcbSurfaceKHR(const XcbSurfaceCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateXcbSurfaceKHR(instance.get(),
        reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
[[nodiscard]] VkBool32 InstanceFunctions::GetPhysicalDeviceXcbPresentationSupportKHR(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex, 
    xcb_connection_t&  connection, 
    xcb_visualid_t visual_id) const {
    return pfn_GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice.get(),
        queueFamilyIndex,
        reinterpret_cast<xcb_connection_t*>(&connection),
        static_cast<xcb_visualid_t>(visual_id));
}
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateWaylandSurfaceKHR(const WaylandSurfaceCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateWaylandSurfaceKHR(instance.get(),
        reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
[[nodiscard]] wl_display InstanceFunctions::GetPhysicalDeviceWaylandPresentationSupportKHR(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex) const {
    wl_display display;
    vk::Result result = pfn_GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice.get(),
        queueFamilyIndex,
        reinterpret_cast<wl_display*>(&display));
    return display;
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateAndroidSurfaceKHR(const AndroidSurfaceCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateAndroidSurfaceKHR(instance.get(),
        reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateWin32SurfaceKHR(const Win32SurfaceCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateWin32SurfaceKHR(instance.get(),
        reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] VkBool32 InstanceFunctions::GetPhysicalDeviceWin32PresentationSupportKHR(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex) const {
    return pfn_GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice.get(),
        queueFamilyIndex);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
[[nodiscard]] expected<DebugReportCallbackEXT> InstanceFunctions::CreateDebugReportCallbackEXT(const DebugReportCallbackCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DebugReportCallbackEXT pCallback;
    vk::Result result = static_cast<Result>(pfn_CreateDebugReportCallbackEXT(instance.get(),
        reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDebugReportCallbackEXT*>(&pCallback)));
    return expected<DebugReportCallbackEXT>(pCallback, result);
}
void InstanceFunctions::DestroyDebugReportCallbackEXT(DebugReportCallbackEXT callback, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDebugReportCallbackEXT(instance.get(),
        callback.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
void InstanceFunctions::DebugReportMessageEXT(DebugReportFlagsEXT flags, 
    DebugReportObjectTypeEXT objectType, 
    uint64_t object, 
    size_t location, 
    int32_t messageCode, 
    const char* pLayerPrefix, 
    const char* pMessage) const {
    pfn_DebugReportMessageEXT(instance.get(),
        static_cast<VkDebugReportFlagsEXT>(flags),
        static_cast<VkDebugReportObjectTypeEXT>(objectType),
        object,
        location,
        messageCode,
        pLayerPrefix,
        pMessage);
}
#if defined(VK_USE_PLATFORM_GGP)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateStreamDescriptorSurfaceGGP(const StreamDescriptorSurfaceCreateInfoGGP&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateStreamDescriptorSurfaceGGP(instance.get(),
        reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_GGP
[[nodiscard]] expected<ExternalImageFormatPropertiesNV> InstanceFunctions::GetPhysicalDeviceExternalImageFormatPropertiesNV(PhysicalDevice physicalDevice, 
    Format format, 
    ImageType type, 
    ImageTiling tiling, 
    ImageUsageFlags usage, 
    ImageCreateFlags flags, 
    ExternalMemoryHandleTypeFlagsNV externalHandleType) const {
    ExternalImageFormatPropertiesNV pExternalImageFormatProperties;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice.get(),
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkImageTiling>(tiling),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageCreateFlags>(flags),
        static_cast<VkExternalMemoryHandleTypeFlagsNV>(externalHandleType),
        reinterpret_cast<VkExternalImageFormatPropertiesNV*>(&pExternalImageFormatProperties)));
    return expected<ExternalImageFormatPropertiesNV>(pExternalImageFormatProperties, result);
}
#if defined(VK_USE_PLATFORM_VI_NN)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateViSurfaceNN(const ViSurfaceCreateInfoNN&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateViSurfaceNN(instance.get(),
        reinterpret_cast<const VkViSurfaceCreateInfoNN*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_VI_NN
[[nodiscard]] Result InstanceFunctions::ReleaseDisplayEXT(PhysicalDevice physicalDevice, 
    DisplayKHR display) const {
    return static_cast<Result>(pfn_ReleaseDisplayEXT(physicalDevice.get(),
        display.get()));
}
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
[[nodiscard]] Result InstanceFunctions::AcquireXlibDisplayEXT(PhysicalDevice physicalDevice, 
    Display&  dpy, 
    DisplayKHR display) const {
    return static_cast<Result>(pfn_AcquireXlibDisplayEXT(physicalDevice.get(),
        reinterpret_cast<Display*>(&dpy),
        display.get()));
}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
[[nodiscard]] expected<DisplayKHR> InstanceFunctions::GetRandROutputDisplayEXT(PhysicalDevice physicalDevice, 
    Display&  dpy, 
    RROutput rrOutput) const {
    DisplayKHR pDisplay;
    vk::Result result = static_cast<Result>(pfn_GetRandROutputDisplayEXT(physicalDevice.get(),
        reinterpret_cast<Display*>(&dpy),
        static_cast<RROutput>(rrOutput),
        reinterpret_cast<VkDisplayKHR*>(&pDisplay)));
    return expected<DisplayKHR>(pDisplay, result);
}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
[[nodiscard]] expected<SurfaceCapabilities2EXT> InstanceFunctions::GetPhysicalDeviceSurfaceCapabilities2EXT(PhysicalDevice physicalDevice, 
    SurfaceKHR surface) const {
    SurfaceCapabilities2EXT pSurfaceCapabilities;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice.get(),
        surface.get(),
        reinterpret_cast<VkSurfaceCapabilities2EXT*>(&pSurfaceCapabilities)));
    return expected<SurfaceCapabilities2EXT>(pSurfaceCapabilities, result);
}
[[nodiscard]] Result InstanceFunctions::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex, 
    uint32_t&  pCounterCount, 
    PerformanceCounterKHR* pCounters, 
    PerformanceCounterDescriptionKHR* pCounterDescriptions) const {
    return static_cast<Result>(pfn_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice.get(),
        queueFamilyIndex,
        &pCounterCount,
        reinterpret_cast<VkPerformanceCounterKHR*>(pCounters),
        reinterpret_cast<VkPerformanceCounterDescriptionKHR*>(pCounterDescriptions)));
}
[[nodiscard]] uint32_t InstanceFunctions::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(PhysicalDevice physicalDevice, 
    const QueryPoolPerformanceCreateInfoKHR&  pPerformanceQueryCreateInfo) const {
    uint32_t pNumPasses;
    pfn_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice.get(),
        reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(&pPerformanceQueryCreateInfo),
        &pNumPasses);
    return pNumPasses;
}
[[nodiscard]] expected<SurfaceCapabilities2KHR> InstanceFunctions::GetPhysicalDeviceSurfaceCapabilities2KHR(PhysicalDevice physicalDevice, 
    const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    SurfaceCapabilities2KHR pSurfaceCapabilities;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(&pSurfaceInfo),
        reinterpret_cast<VkSurfaceCapabilities2KHR*>(&pSurfaceCapabilities)));
    return expected<SurfaceCapabilities2KHR>(pSurfaceCapabilities, result);
}
[[nodiscard]] expected<detail::fixed_vector<SurfaceFormat2KHR>> InstanceFunctions::GetPhysicalDeviceSurfaceFormats2KHR(PhysicalDevice physicalDevice, 
    const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    uint32_t pSurfaceFormatCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(&pSurfaceInfo),
        &pSurfaceFormatCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<SurfaceFormat2KHR>{}, result);
    detail::fixed_vector<SurfaceFormat2KHR> pSurfaceFormats{pSurfaceFormatCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(&pSurfaceInfo),
        &pSurfaceFormatCount,
        reinterpret_cast<VkSurfaceFormat2KHR*>(pSurfaceFormats.data())));
    if (pSurfaceFormatCount < pSurfaceFormats.size()) pSurfaceFormats.shrink(pSurfaceFormatCount);
    return expected(std::move(pSurfaceFormats), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayProperties2KHR>> InstanceFunctions::GetPhysicalDeviceDisplayProperties2KHR(PhysicalDevice physicalDevice) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayProperties2KHR(physicalDevice.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayProperties2KHR>{}, result);
    detail::fixed_vector<DisplayProperties2KHR> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayProperties2KHR(physicalDevice.get(),
        &pPropertyCount,
        reinterpret_cast<VkDisplayProperties2KHR*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayPlaneProperties2KHR>> InstanceFunctions::GetPhysicalDeviceDisplayPlaneProperties2KHR(PhysicalDevice physicalDevice) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayPlaneProperties2KHR>{}, result);
    detail::fixed_vector<DisplayPlaneProperties2KHR> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice.get(),
        &pPropertyCount,
        reinterpret_cast<VkDisplayPlaneProperties2KHR*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<DisplayModeProperties2KHR>> InstanceFunctions::GetDisplayModeProperties2KHR(PhysicalDevice physicalDevice, 
    DisplayKHR display) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetDisplayModeProperties2KHR(physicalDevice.get(),
        display.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<DisplayModeProperties2KHR>{}, result);
    detail::fixed_vector<DisplayModeProperties2KHR> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetDisplayModeProperties2KHR(physicalDevice.get(),
        display.get(),
        &pPropertyCount,
        reinterpret_cast<VkDisplayModeProperties2KHR*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<DisplayPlaneCapabilities2KHR> InstanceFunctions::GetDisplayPlaneCapabilities2KHR(PhysicalDevice physicalDevice, 
    const DisplayPlaneInfo2KHR&  pDisplayPlaneInfo) const {
    DisplayPlaneCapabilities2KHR pCapabilities;
    vk::Result result = static_cast<Result>(pfn_GetDisplayPlaneCapabilities2KHR(physicalDevice.get(),
        reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(&pDisplayPlaneInfo),
        reinterpret_cast<VkDisplayPlaneCapabilities2KHR*>(&pCapabilities)));
    return expected<DisplayPlaneCapabilities2KHR>(pCapabilities, result);
}
#if defined(VK_USE_PLATFORM_IOS_MVK)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateIOSSurfaceMVK(const IOSSurfaceCreateInfoMVK&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateIOSSurfaceMVK(instance.get(),
        reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateMacOSSurfaceMVK(const MacOSSurfaceCreateInfoMVK&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateMacOSSurfaceMVK(instance.get(),
        reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_MACOS_MVK
[[nodiscard]] expected<DebugUtilsMessengerEXT> InstanceFunctions::CreateDebugUtilsMessengerEXT(const DebugUtilsMessengerCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DebugUtilsMessengerEXT pMessenger;
    vk::Result result = static_cast<Result>(pfn_CreateDebugUtilsMessengerEXT(instance.get(),
        reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDebugUtilsMessengerEXT*>(&pMessenger)));
    return expected<DebugUtilsMessengerEXT>(pMessenger, result);
}
void InstanceFunctions::DestroyDebugUtilsMessengerEXT(DebugUtilsMessengerEXT messenger, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDebugUtilsMessengerEXT(instance.get(),
        messenger.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
void InstanceFunctions::SubmitDebugUtilsMessageEXT(DebugUtilsMessageSeverityFlagBitsEXT messageSeverity, 
    DebugUtilsMessageTypeFlagsEXT messageTypes, 
    const DebugUtilsMessengerCallbackDataEXT&  pCallbackData) const {
    pfn_SubmitDebugUtilsMessageEXT(instance.get(),
        static_cast<VkDebugUtilsMessageSeverityFlagBitsEXT>(messageSeverity),
        static_cast<VkDebugUtilsMessageTypeFlagsEXT>(messageTypes),
        reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(&pCallbackData));
}
[[nodiscard]] MultisamplePropertiesEXT InstanceFunctions::GetPhysicalDeviceMultisamplePropertiesEXT(PhysicalDevice physicalDevice, 
    SampleCountFlagBits samples) const {
    MultisamplePropertiesEXT pMultisampleProperties;
    pfn_GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice.get(),
        static_cast<VkSampleCountFlagBits>(samples),
        reinterpret_cast<VkMultisamplePropertiesEXT*>(&pMultisampleProperties));
    return pMultisampleProperties;
}
[[nodiscard]] expected<detail::fixed_vector<TimeDomainEXT>> InstanceFunctions::GetPhysicalDeviceCalibrateableTimeDomainsEXT(PhysicalDevice physicalDevice) const {
    uint32_t pTimeDomainCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice.get(),
        &pTimeDomainCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<TimeDomainEXT>{}, result);
    detail::fixed_vector<TimeDomainEXT> pTimeDomains{pTimeDomainCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice.get(),
        &pTimeDomainCount,
        reinterpret_cast<VkTimeDomainEXT*>(pTimeDomains.data())));
    if (pTimeDomainCount < pTimeDomains.size()) pTimeDomains.shrink(pTimeDomainCount);
    return expected(std::move(pTimeDomains), result);
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateImagePipeSurfaceFUCHSIA(const ImagePipeSurfaceCreateInfoFUCHSIA&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateImagePipeSurfaceFUCHSIA(instance.get(),
        reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateMetalSurfaceEXT(const MetalSurfaceCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateMetalSurfaceEXT(instance.get(),
        reinterpret_cast<const VkMetalSurfaceCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_METAL_EXT
[[nodiscard]] expected<detail::fixed_vector<PhysicalDeviceToolPropertiesEXT>> InstanceFunctions::GetPhysicalDeviceToolPropertiesEXT(PhysicalDevice physicalDevice) const {
    uint32_t pToolCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceToolPropertiesEXT(physicalDevice.get(),
        &pToolCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PhysicalDeviceToolPropertiesEXT>{}, result);
    detail::fixed_vector<PhysicalDeviceToolPropertiesEXT> pToolProperties{pToolCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceToolPropertiesEXT(physicalDevice.get(),
        &pToolCount,
        reinterpret_cast<VkPhysicalDeviceToolPropertiesEXT*>(pToolProperties.data())));
    if (pToolCount < pToolProperties.size()) pToolProperties.shrink(pToolCount);
    return expected(std::move(pToolProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<CooperativeMatrixPropertiesNV>> InstanceFunctions::GetPhysicalDeviceCooperativeMatrixPropertiesNV(PhysicalDevice physicalDevice) const {
    uint32_t pPropertyCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice.get(),
        &pPropertyCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<CooperativeMatrixPropertiesNV>{}, result);
    detail::fixed_vector<CooperativeMatrixPropertiesNV> pProperties{pPropertyCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice.get(),
        &pPropertyCount,
        reinterpret_cast<VkCooperativeMatrixPropertiesNV*>(pProperties.data())));
    if (pPropertyCount < pProperties.size()) pProperties.shrink(pPropertyCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<FramebufferMixedSamplesCombinationNV>> InstanceFunctions::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(PhysicalDevice physicalDevice) const {
    uint32_t pCombinationCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice.get(),
        &pCombinationCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<FramebufferMixedSamplesCombinationNV>{}, result);
    detail::fixed_vector<FramebufferMixedSamplesCombinationNV> pCombinations{pCombinationCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice.get(),
        &pCombinationCount,
        reinterpret_cast<VkFramebufferMixedSamplesCombinationNV*>(pCombinations.data())));
    if (pCombinationCount < pCombinations.size()) pCombinations.shrink(pCombinationCount);
    return expected(std::move(pCombinations), result);
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<detail::fixed_vector<PresentModeKHR>> InstanceFunctions::GetPhysicalDeviceSurfacePresentModes2EXT(PhysicalDevice physicalDevice, 
    const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    uint32_t pPresentModeCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(&pSurfaceInfo),
        &pPresentModeCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PresentModeKHR>{}, result);
    detail::fixed_vector<PresentModeKHR> pPresentModes{pPresentModeCount};
    result = static_cast<Result>(pfn_GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice.get(),
        reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(&pSurfaceInfo),
        &pPresentModeCount,
        reinterpret_cast<VkPresentModeKHR*>(pPresentModes.data())));
    if (pPresentModeCount < pPresentModes.size()) pPresentModes.shrink(pPresentModeCount);
    return expected(std::move(pPresentModes), result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateHeadlessSurfaceEXT(const HeadlessSurfaceCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateHeadlessSurfaceEXT(instance.get(),
        reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
[[nodiscard]] expected<SurfaceKHR> InstanceFunctions::CreateDirectFBSurfaceEXT(const DirectFBSurfaceCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SurfaceKHR pSurface;
    vk::Result result = static_cast<Result>(pfn_CreateDirectFBSurfaceEXT(instance.get(),
        reinterpret_cast<const VkDirectFBSurfaceCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSurfaceKHR*>(&pSurface)));
    return expected<SurfaceKHR>(pSurface, result);
}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
[[nodiscard]] IDirectFB InstanceFunctions::GetPhysicalDeviceDirectFBPresentationSupportEXT(PhysicalDevice physicalDevice, 
    uint32_t queueFamilyIndex) const {
    IDirectFB dfb;
    vk::Result result = pfn_GetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice.get(),
        queueFamilyIndex,
        reinterpret_cast<IDirectFB*>(&dfb));
    return dfb;
}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
InstanceFunctions::InstanceFunctions() noexcept {}
InstanceFunctions::InstanceFunctions(GlobalFunctions const& global_functions, Instance instance) noexcept 
    :instance(instance) { 
    detail::PFN_vkGetInstanceProcAddr get_instance_proc_addr = global_functions.pfn_GetInstanceProcAddr;
    pfn_DestroyInstance = reinterpret_cast<detail::PFN_vkDestroyInstance>(get_instance_proc_addr(instance.get(),"vkDestroyInstance"));
    pfn_EnumeratePhysicalDevices = reinterpret_cast<detail::PFN_vkEnumeratePhysicalDevices>(get_instance_proc_addr(instance.get(),"vkEnumeratePhysicalDevices"));
    pfn_GetDeviceProcAddr = reinterpret_cast<detail::PFN_vkGetDeviceProcAddr>(get_instance_proc_addr(instance.get(),"vkGetDeviceProcAddr"));
    pfn_GetInstanceProcAddr = get_instance_proc_addr;
    pfn_GetPhysicalDeviceProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceProperties"));
    pfn_GetPhysicalDeviceQueueFamilyProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceQueueFamilyProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceQueueFamilyProperties"));
    pfn_GetPhysicalDeviceMemoryProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceMemoryProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceMemoryProperties"));
    pfn_GetPhysicalDeviceFeatures = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceFeatures>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceFeatures"));
    pfn_GetPhysicalDeviceFormatProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceFormatProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceFormatProperties"));
    pfn_GetPhysicalDeviceImageFormatProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceImageFormatProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceImageFormatProperties"));
    pfn_CreateDevice = reinterpret_cast<detail::PFN_vkCreateDevice>(get_instance_proc_addr(instance.get(),"vkCreateDevice"));
    pfn_EnumerateDeviceExtensionProperties = reinterpret_cast<detail::PFN_vkEnumerateDeviceExtensionProperties>(get_instance_proc_addr(instance.get(),"vkEnumerateDeviceExtensionProperties"));
    pfn_GetPhysicalDeviceSparseImageFormatProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSparseImageFormatProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSparseImageFormatProperties"));
    pfn_EnumeratePhysicalDeviceGroups = reinterpret_cast<detail::PFN_vkEnumeratePhysicalDeviceGroups>(get_instance_proc_addr(instance.get(),"vkEnumeratePhysicalDeviceGroups"));
    pfn_GetPhysicalDeviceFeatures2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceFeatures2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceFeatures2"));
    pfn_GetPhysicalDeviceProperties2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceProperties2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceProperties2"));
    pfn_GetPhysicalDeviceFormatProperties2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceFormatProperties2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceFormatProperties2"));
    pfn_GetPhysicalDeviceImageFormatProperties2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceImageFormatProperties2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceImageFormatProperties2"));
    pfn_GetPhysicalDeviceQueueFamilyProperties2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceQueueFamilyProperties2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceQueueFamilyProperties2"));
    pfn_GetPhysicalDeviceMemoryProperties2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceMemoryProperties2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceMemoryProperties2"));
    pfn_GetPhysicalDeviceSparseImageFormatProperties2 = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSparseImageFormatProperties2>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSparseImageFormatProperties2"));
    pfn_GetPhysicalDeviceExternalBufferProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceExternalBufferProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceExternalBufferProperties"));
    pfn_GetPhysicalDeviceExternalFenceProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceExternalFenceProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceExternalFenceProperties"));
    pfn_GetPhysicalDeviceExternalSemaphoreProperties = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceExternalSemaphoreProperties>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceExternalSemaphoreProperties"));
    pfn_DestroySurfaceKHR = reinterpret_cast<detail::PFN_vkDestroySurfaceKHR>(get_instance_proc_addr(instance.get(),"vkDestroySurfaceKHR"));
    pfn_GetPhysicalDeviceSurfaceSupportKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfaceSupportKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfaceSupportKHR"));
    pfn_GetPhysicalDeviceSurfaceCapabilitiesKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    pfn_GetPhysicalDeviceSurfaceFormatsKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfaceFormatsKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfaceFormatsKHR"));
    pfn_GetPhysicalDeviceSurfacePresentModesKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfacePresentModesKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfacePresentModesKHR"));
    pfn_GetPhysicalDevicePresentRectanglesKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDevicePresentRectanglesKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDevicePresentRectanglesKHR"));
    pfn_GetPhysicalDeviceDisplayPropertiesKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceDisplayPropertiesKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceDisplayPropertiesKHR"));
    pfn_GetPhysicalDeviceDisplayPlanePropertiesKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceDisplayPlanePropertiesKHR"));
    pfn_GetDisplayPlaneSupportedDisplaysKHR = reinterpret_cast<detail::PFN_vkGetDisplayPlaneSupportedDisplaysKHR>(get_instance_proc_addr(instance.get(),"vkGetDisplayPlaneSupportedDisplaysKHR"));
    pfn_GetDisplayModePropertiesKHR = reinterpret_cast<detail::PFN_vkGetDisplayModePropertiesKHR>(get_instance_proc_addr(instance.get(),"vkGetDisplayModePropertiesKHR"));
    pfn_CreateDisplayModeKHR = reinterpret_cast<detail::PFN_vkCreateDisplayModeKHR>(get_instance_proc_addr(instance.get(),"vkCreateDisplayModeKHR"));
    pfn_GetDisplayPlaneCapabilitiesKHR = reinterpret_cast<detail::PFN_vkGetDisplayPlaneCapabilitiesKHR>(get_instance_proc_addr(instance.get(),"vkGetDisplayPlaneCapabilitiesKHR"));
    pfn_CreateDisplayPlaneSurfaceKHR = reinterpret_cast<detail::PFN_vkCreateDisplayPlaneSurfaceKHR>(get_instance_proc_addr(instance.get(),"vkCreateDisplayPlaneSurfaceKHR"));
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    pfn_CreateXlibSurfaceKHR = reinterpret_cast<detail::PFN_vkCreateXlibSurfaceKHR>(get_instance_proc_addr(instance.get(),"vkCreateXlibSurfaceKHR"));
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    pfn_GetPhysicalDeviceXlibPresentationSupportKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceXlibPresentationSupportKHR"));
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
    pfn_CreateXcbSurfaceKHR = reinterpret_cast<detail::PFN_vkCreateXcbSurfaceKHR>(get_instance_proc_addr(instance.get(),"vkCreateXcbSurfaceKHR"));
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
    pfn_GetPhysicalDeviceXcbPresentationSupportKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceXcbPresentationSupportKHR"));
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    pfn_CreateWaylandSurfaceKHR = reinterpret_cast<detail::PFN_vkCreateWaylandSurfaceKHR>(get_instance_proc_addr(instance.get(),"vkCreateWaylandSurfaceKHR"));
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    pfn_GetPhysicalDeviceWaylandPresentationSupportKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceWaylandPresentationSupportKHR"));
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    pfn_CreateAndroidSurfaceKHR = reinterpret_cast<detail::PFN_vkCreateAndroidSurfaceKHR>(get_instance_proc_addr(instance.get(),"vkCreateAndroidSurfaceKHR"));
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_CreateWin32SurfaceKHR = reinterpret_cast<detail::PFN_vkCreateWin32SurfaceKHR>(get_instance_proc_addr(instance.get(),"vkCreateWin32SurfaceKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetPhysicalDeviceWin32PresentationSupportKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceWin32PresentationSupportKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
    pfn_CreateDebugReportCallbackEXT = reinterpret_cast<detail::PFN_vkCreateDebugReportCallbackEXT>(get_instance_proc_addr(instance.get(),"vkCreateDebugReportCallbackEXT"));
    pfn_DestroyDebugReportCallbackEXT = reinterpret_cast<detail::PFN_vkDestroyDebugReportCallbackEXT>(get_instance_proc_addr(instance.get(),"vkDestroyDebugReportCallbackEXT"));
    pfn_DebugReportMessageEXT = reinterpret_cast<detail::PFN_vkDebugReportMessageEXT>(get_instance_proc_addr(instance.get(),"vkDebugReportMessageEXT"));
#if defined(VK_USE_PLATFORM_GGP)
    pfn_CreateStreamDescriptorSurfaceGGP = reinterpret_cast<detail::PFN_vkCreateStreamDescriptorSurfaceGGP>(get_instance_proc_addr(instance.get(),"vkCreateStreamDescriptorSurfaceGGP"));
#endif // VK_USE_PLATFORM_GGP
    pfn_GetPhysicalDeviceExternalImageFormatPropertiesNV = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceExternalImageFormatPropertiesNV"));
#if defined(VK_USE_PLATFORM_VI_NN)
    pfn_CreateViSurfaceNN = reinterpret_cast<detail::PFN_vkCreateViSurfaceNN>(get_instance_proc_addr(instance.get(),"vkCreateViSurfaceNN"));
#endif // VK_USE_PLATFORM_VI_NN
    pfn_ReleaseDisplayEXT = reinterpret_cast<detail::PFN_vkReleaseDisplayEXT>(get_instance_proc_addr(instance.get(),"vkReleaseDisplayEXT"));
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    pfn_AcquireXlibDisplayEXT = reinterpret_cast<detail::PFN_vkAcquireXlibDisplayEXT>(get_instance_proc_addr(instance.get(),"vkAcquireXlibDisplayEXT"));
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    pfn_GetRandROutputDisplayEXT = reinterpret_cast<detail::PFN_vkGetRandROutputDisplayEXT>(get_instance_proc_addr(instance.get(),"vkGetRandROutputDisplayEXT"));
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
    pfn_GetPhysicalDeviceSurfaceCapabilities2EXT = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfaceCapabilities2EXT"));
    pfn_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = reinterpret_cast<detail::PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>(get_instance_proc_addr(instance.get(),"vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR"));
    pfn_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR"));
    pfn_GetPhysicalDeviceSurfaceCapabilities2KHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfaceCapabilities2KHR"));
    pfn_GetPhysicalDeviceSurfaceFormats2KHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfaceFormats2KHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfaceFormats2KHR"));
    pfn_GetPhysicalDeviceDisplayProperties2KHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceDisplayProperties2KHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceDisplayProperties2KHR"));
    pfn_GetPhysicalDeviceDisplayPlaneProperties2KHR = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceDisplayPlaneProperties2KHR"));
    pfn_GetDisplayModeProperties2KHR = reinterpret_cast<detail::PFN_vkGetDisplayModeProperties2KHR>(get_instance_proc_addr(instance.get(),"vkGetDisplayModeProperties2KHR"));
    pfn_GetDisplayPlaneCapabilities2KHR = reinterpret_cast<detail::PFN_vkGetDisplayPlaneCapabilities2KHR>(get_instance_proc_addr(instance.get(),"vkGetDisplayPlaneCapabilities2KHR"));
#if defined(VK_USE_PLATFORM_IOS_MVK)
    pfn_CreateIOSSurfaceMVK = reinterpret_cast<detail::PFN_vkCreateIOSSurfaceMVK>(get_instance_proc_addr(instance.get(),"vkCreateIOSSurfaceMVK"));
#endif // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    pfn_CreateMacOSSurfaceMVK = reinterpret_cast<detail::PFN_vkCreateMacOSSurfaceMVK>(get_instance_proc_addr(instance.get(),"vkCreateMacOSSurfaceMVK"));
#endif // VK_USE_PLATFORM_MACOS_MVK
    pfn_CreateDebugUtilsMessengerEXT = reinterpret_cast<detail::PFN_vkCreateDebugUtilsMessengerEXT>(get_instance_proc_addr(instance.get(),"vkCreateDebugUtilsMessengerEXT"));
    pfn_DestroyDebugUtilsMessengerEXT = reinterpret_cast<detail::PFN_vkDestroyDebugUtilsMessengerEXT>(get_instance_proc_addr(instance.get(),"vkDestroyDebugUtilsMessengerEXT"));
    pfn_SubmitDebugUtilsMessageEXT = reinterpret_cast<detail::PFN_vkSubmitDebugUtilsMessageEXT>(get_instance_proc_addr(instance.get(),"vkSubmitDebugUtilsMessageEXT"));
    pfn_GetPhysicalDeviceMultisamplePropertiesEXT = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceMultisamplePropertiesEXT"));
    pfn_GetPhysicalDeviceCalibrateableTimeDomainsEXT = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceCalibrateableTimeDomainsEXT"));
#if defined(VK_USE_PLATFORM_FUCHSIA)
    pfn_CreateImagePipeSurfaceFUCHSIA = reinterpret_cast<detail::PFN_vkCreateImagePipeSurfaceFUCHSIA>(get_instance_proc_addr(instance.get(),"vkCreateImagePipeSurfaceFUCHSIA"));
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
    pfn_CreateMetalSurfaceEXT = reinterpret_cast<detail::PFN_vkCreateMetalSurfaceEXT>(get_instance_proc_addr(instance.get(),"vkCreateMetalSurfaceEXT"));
#endif // VK_USE_PLATFORM_METAL_EXT
    pfn_GetPhysicalDeviceToolPropertiesEXT = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceToolPropertiesEXT>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceToolPropertiesEXT"));
    pfn_GetPhysicalDeviceCooperativeMatrixPropertiesNV = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceCooperativeMatrixPropertiesNV"));
    pfn_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV"));
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetPhysicalDeviceSurfacePresentModes2EXT = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceSurfacePresentModes2EXT"));
#endif // VK_USE_PLATFORM_WIN32_KHR
    pfn_CreateHeadlessSurfaceEXT = reinterpret_cast<detail::PFN_vkCreateHeadlessSurfaceEXT>(get_instance_proc_addr(instance.get(),"vkCreateHeadlessSurfaceEXT"));
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    pfn_CreateDirectFBSurfaceEXT = reinterpret_cast<detail::PFN_vkCreateDirectFBSurfaceEXT>(get_instance_proc_addr(instance.get(),"vkCreateDirectFBSurfaceEXT"));
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    pfn_GetPhysicalDeviceDirectFBPresentationSupportEXT = reinterpret_cast<detail::PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>(get_instance_proc_addr(instance.get(),"vkGetPhysicalDeviceDirectFBPresentationSupportEXT"));
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
}
void DeviceFunctions::DestroyDevice(const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDevice(device.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Queue DeviceFunctions::GetDeviceQueue(uint32_t queueFamilyIndex, 
    uint32_t queueIndex) const {
    Queue pQueue;
    pfn_GetDeviceQueue(device.get(),
        queueFamilyIndex,
        queueIndex,
        reinterpret_cast<VkQueue*>(&pQueue));
    return pQueue;
}
[[nodiscard]] Result DeviceFunctions::QueueSubmit(Queue queue, 
    uint32_t submitCount, 
    const SubmitInfo* pSubmits, 
    Fence fence) const {
    return static_cast<Result>(pfn_QueueSubmit(queue.get(),
        submitCount,
        reinterpret_cast<const VkSubmitInfo*>(pSubmits),
        fence.get()));
}
[[nodiscard]] Result DeviceFunctions::QueueWaitIdle(Queue queue) const {
    return static_cast<Result>(pfn_QueueWaitIdle(queue.get()));
}
[[nodiscard]] Result DeviceFunctions::DeviceWaitIdle() const {
    return static_cast<Result>(pfn_DeviceWaitIdle(device.get()));
}
[[nodiscard]] expected<DeviceMemory> DeviceFunctions::AllocateMemory(const MemoryAllocateInfo&  pAllocateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DeviceMemory pMemory;
    vk::Result result = static_cast<Result>(pfn_AllocateMemory(device.get(),
        reinterpret_cast<const VkMemoryAllocateInfo*>(&pAllocateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDeviceMemory*>(&pMemory)));
    return expected<DeviceMemory>(pMemory, result);
}
void DeviceFunctions::FreeMemory(DeviceMemory memory, 
    const AllocationCallbacks* pAllocator) const {
    pfn_FreeMemory(device.get(),
        memory.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<void*> DeviceFunctions::MapMemory(DeviceMemory memory, 
    DeviceSize offset, 
    DeviceSize size, 
    MemoryMapFlags flags) const {
    void* ppData;
    vk::Result result = static_cast<Result>(pfn_MapMemory(device.get(),
        memory.get(),
        offset,
        size,
        static_cast<VkMemoryMapFlags>(flags),
        reinterpret_cast<void**>(&ppData)));
    return expected<void*>(ppData, result);
}
void DeviceFunctions::UnmapMemory(DeviceMemory memory) const {
    pfn_UnmapMemory(device.get(),
        memory.get());
}
[[nodiscard]] Result DeviceFunctions::FlushMappedMemoryRanges(uint32_t memoryRangeCount, 
    const MappedMemoryRange* pMemoryRanges) const {
    return static_cast<Result>(pfn_FlushMappedMemoryRanges(device.get(),
        memoryRangeCount,
        reinterpret_cast<const VkMappedMemoryRange*>(pMemoryRanges)));
}
[[nodiscard]] Result DeviceFunctions::InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, 
    const MappedMemoryRange* pMemoryRanges) const {
    return static_cast<Result>(pfn_InvalidateMappedMemoryRanges(device.get(),
        memoryRangeCount,
        reinterpret_cast<const VkMappedMemoryRange*>(pMemoryRanges)));
}
[[nodiscard]] DeviceSize DeviceFunctions::GetDeviceMemoryCommitment(DeviceMemory memory) const {
    DeviceSize pCommittedMemoryInBytes;
    pfn_GetDeviceMemoryCommitment(device.get(),
        memory.get(),
        &pCommittedMemoryInBytes);
    return pCommittedMemoryInBytes;
}
[[nodiscard]] MemoryRequirements DeviceFunctions::GetBufferMemoryRequirements(Buffer buffer) const {
    MemoryRequirements pMemoryRequirements;
    pfn_GetBufferMemoryRequirements(device.get(),
        buffer.get(),
        reinterpret_cast<VkMemoryRequirements*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
[[nodiscard]] Result DeviceFunctions::BindBufferMemory(Buffer buffer, 
    DeviceMemory memory, 
    DeviceSize memoryOffset) const {
    return static_cast<Result>(pfn_BindBufferMemory(device.get(),
        buffer.get(),
        memory.get(),
        memoryOffset));
}
[[nodiscard]] MemoryRequirements DeviceFunctions::GetImageMemoryRequirements(Image image) const {
    MemoryRequirements pMemoryRequirements;
    pfn_GetImageMemoryRequirements(device.get(),
        image.get(),
        reinterpret_cast<VkMemoryRequirements*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
[[nodiscard]] Result DeviceFunctions::BindImageMemory(Image image, 
    DeviceMemory memory, 
    DeviceSize memoryOffset) const {
    return static_cast<Result>(pfn_BindImageMemory(device.get(),
        image.get(),
        memory.get(),
        memoryOffset));
}
[[nodiscard]] detail::fixed_vector<SparseImageMemoryRequirements> DeviceFunctions::GetImageSparseMemoryRequirements(Image image) const {
    uint32_t pSparseMemoryRequirementCount = 0;
    pfn_GetImageSparseMemoryRequirements(device.get(),
        image.get(),
        &pSparseMemoryRequirementCount,
        nullptr);
    detail::fixed_vector<SparseImageMemoryRequirements> pSparseMemoryRequirements{pSparseMemoryRequirementCount};
    pfn_GetImageSparseMemoryRequirements(device.get(),
        image.get(),
        &pSparseMemoryRequirementCount,
        reinterpret_cast<VkSparseImageMemoryRequirements*>(pSparseMemoryRequirements.data()));
    if (pSparseMemoryRequirementCount < pSparseMemoryRequirements.size()) pSparseMemoryRequirements.shrink(pSparseMemoryRequirementCount);
    return pSparseMemoryRequirements;
}
[[nodiscard]] Result DeviceFunctions::QueueBindSparse(Queue queue, 
    uint32_t bindInfoCount, 
    const BindSparseInfo* pBindInfo, 
    Fence fence) const {
    return static_cast<Result>(pfn_QueueBindSparse(queue.get(),
        bindInfoCount,
        reinterpret_cast<const VkBindSparseInfo*>(pBindInfo),
        fence.get()));
}
[[nodiscard]] expected<Fence> DeviceFunctions::CreateFence(const FenceCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Fence pFence;
    vk::Result result = static_cast<Result>(pfn_CreateFence(device.get(),
        reinterpret_cast<const VkFenceCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkFence*>(&pFence)));
    return expected<Fence>(pFence, result);
}
void DeviceFunctions::DestroyFence(Fence fence, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyFence(device.get(),
        fence.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Result DeviceFunctions::ResetFences(uint32_t fenceCount, 
    const Fence* pFences) const {
    return static_cast<Result>(pfn_ResetFences(device.get(),
        fenceCount,
        reinterpret_cast<const VkFence*>(pFences)));
}
[[nodiscard]] Result DeviceFunctions::GetFenceStatus(Fence fence) const {
    return static_cast<Result>(pfn_GetFenceStatus(device.get(),
        fence.get()));
}
[[nodiscard]] Result DeviceFunctions::WaitForFences(uint32_t fenceCount, 
    const Fence* pFences, 
    Bool32 waitAll, 
    uint64_t timeout) const {
    return static_cast<Result>(pfn_WaitForFences(device.get(),
        fenceCount,
        reinterpret_cast<const VkFence*>(pFences),
        waitAll,
        timeout));
}
[[nodiscard]] expected<Semaphore> DeviceFunctions::CreateSemaphore(const SemaphoreCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Semaphore pSemaphore;
    vk::Result result = static_cast<Result>(pfn_CreateSemaphore(device.get(),
        reinterpret_cast<const VkSemaphoreCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSemaphore*>(&pSemaphore)));
    return expected<Semaphore>(pSemaphore, result);
}
void DeviceFunctions::DestroySemaphore(Semaphore semaphore, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroySemaphore(device.get(),
        semaphore.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<Event> DeviceFunctions::CreateEvent(const EventCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Event pEvent;
    vk::Result result = static_cast<Result>(pfn_CreateEvent(device.get(),
        reinterpret_cast<const VkEventCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkEvent*>(&pEvent)));
    return expected<Event>(pEvent, result);
}
void DeviceFunctions::DestroyEvent(Event event, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyEvent(device.get(),
        event.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Result DeviceFunctions::GetEventStatus(Event event) const {
    return static_cast<Result>(pfn_GetEventStatus(device.get(),
        event.get()));
}
[[nodiscard]] Result DeviceFunctions::SetEvent(Event event) const {
    return static_cast<Result>(pfn_SetEvent(device.get(),
        event.get()));
}
[[nodiscard]] Result DeviceFunctions::ResetEvent(Event event) const {
    return static_cast<Result>(pfn_ResetEvent(device.get(),
        event.get()));
}
[[nodiscard]] expected<QueryPool> DeviceFunctions::CreateQueryPool(const QueryPoolCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    QueryPool pQueryPool;
    vk::Result result = static_cast<Result>(pfn_CreateQueryPool(device.get(),
        reinterpret_cast<const VkQueryPoolCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkQueryPool*>(&pQueryPool)));
    return expected<QueryPool>(pQueryPool, result);
}
void DeviceFunctions::DestroyQueryPool(QueryPool queryPool, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyQueryPool(device.get(),
        queryPool.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Result DeviceFunctions::GetQueryPoolResults(QueryPool queryPool, 
    uint32_t firstQuery, 
    uint32_t queryCount, 
    size_t dataSize, 
    void* pData, 
    DeviceSize stride, 
    QueryResultFlags flags) const {
    return static_cast<Result>(pfn_GetQueryPoolResults(device.get(),
        queryPool.get(),
        firstQuery,
        queryCount,
        dataSize,
        reinterpret_cast<void*>(pData),
        stride,
        static_cast<VkQueryResultFlags>(flags)));
}
[[nodiscard]] expected<Buffer> DeviceFunctions::CreateBuffer(const BufferCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Buffer pBuffer;
    vk::Result result = static_cast<Result>(pfn_CreateBuffer(device.get(),
        reinterpret_cast<const VkBufferCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkBuffer*>(&pBuffer)));
    return expected<Buffer>(pBuffer, result);
}
void DeviceFunctions::DestroyBuffer(Buffer buffer, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyBuffer(device.get(),
        buffer.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<BufferView> DeviceFunctions::CreateBufferView(const BufferViewCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    BufferView pView;
    vk::Result result = static_cast<Result>(pfn_CreateBufferView(device.get(),
        reinterpret_cast<const VkBufferViewCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkBufferView*>(&pView)));
    return expected<BufferView>(pView, result);
}
void DeviceFunctions::DestroyBufferView(BufferView bufferView, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyBufferView(device.get(),
        bufferView.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<Image> DeviceFunctions::CreateImage(const ImageCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Image pImage;
    vk::Result result = static_cast<Result>(pfn_CreateImage(device.get(),
        reinterpret_cast<const VkImageCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkImage*>(&pImage)));
    return expected<Image>(pImage, result);
}
void DeviceFunctions::DestroyImage(Image image, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyImage(device.get(),
        image.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] SubresourceLayout DeviceFunctions::GetImageSubresourceLayout(Image image, 
    const ImageSubresource&  pSubresource) const {
    SubresourceLayout pLayout;
    pfn_GetImageSubresourceLayout(device.get(),
        image.get(),
        reinterpret_cast<const VkImageSubresource*>(&pSubresource),
        reinterpret_cast<VkSubresourceLayout*>(&pLayout));
    return pLayout;
}
[[nodiscard]] expected<ImageView> DeviceFunctions::CreateImageView(const ImageViewCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    ImageView pView;
    vk::Result result = static_cast<Result>(pfn_CreateImageView(device.get(),
        reinterpret_cast<const VkImageViewCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkImageView*>(&pView)));
    return expected<ImageView>(pView, result);
}
void DeviceFunctions::DestroyImageView(ImageView imageView, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyImageView(device.get(),
        imageView.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<ShaderModule> DeviceFunctions::CreateShaderModule(const ShaderModuleCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    ShaderModule pShaderModule;
    vk::Result result = static_cast<Result>(pfn_CreateShaderModule(device.get(),
        reinterpret_cast<const VkShaderModuleCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkShaderModule*>(&pShaderModule)));
    return expected<ShaderModule>(pShaderModule, result);
}
void DeviceFunctions::DestroyShaderModule(ShaderModule shaderModule, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyShaderModule(device.get(),
        shaderModule.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<PipelineCache> DeviceFunctions::CreatePipelineCache(const PipelineCacheCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    PipelineCache pPipelineCache;
    vk::Result result = static_cast<Result>(pfn_CreatePipelineCache(device.get(),
        reinterpret_cast<const VkPipelineCacheCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipelineCache*>(&pPipelineCache)));
    return expected<PipelineCache>(pPipelineCache, result);
}
void DeviceFunctions::DestroyPipelineCache(PipelineCache pipelineCache, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyPipelineCache(device.get(),
        pipelineCache.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<detail::fixed_vector<void*>> DeviceFunctions::GetPipelineCacheData(PipelineCache pipelineCache) const {
    size_t pDataSize = 0;
    vk::Result result = static_cast<Result>(pfn_GetPipelineCacheData(device.get(),
        pipelineCache.get(),
        &pDataSize,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<void*>{}, result);
    detail::fixed_vector<void*> pData{pDataSize};
    result = static_cast<Result>(pfn_GetPipelineCacheData(device.get(),
        pipelineCache.get(),
        &pDataSize,
        reinterpret_cast<void*>(pData.data())));
    if (pDataSize < pData.size()) pData.shrink(pDataSize);
    return expected(std::move(pData), result);
}
[[nodiscard]] Result DeviceFunctions::MergePipelineCaches(PipelineCache dstCache, 
    uint32_t srcCacheCount, 
    const PipelineCache* pSrcCaches) const {
    return static_cast<Result>(pfn_MergePipelineCaches(device.get(),
        dstCache.get(),
        srcCacheCount,
        reinterpret_cast<const VkPipelineCache*>(pSrcCaches)));
}
[[nodiscard]] Result DeviceFunctions::CreateGraphicsPipelines(PipelineCache pipelineCache, 
    uint32_t createInfoCount, 
    const GraphicsPipelineCreateInfo* pCreateInfos, 
    const AllocationCallbacks* pAllocator, 
    Pipeline* pPipelines) const {
    return static_cast<Result>(pfn_CreateGraphicsPipelines(device.get(),
        pipelineCache.get(),
        createInfoCount,
        reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipeline*>(pPipelines)));
}
[[nodiscard]] Result DeviceFunctions::CreateComputePipelines(PipelineCache pipelineCache, 
    uint32_t createInfoCount, 
    const ComputePipelineCreateInfo* pCreateInfos, 
    const AllocationCallbacks* pAllocator, 
    Pipeline* pPipelines) const {
    return static_cast<Result>(pfn_CreateComputePipelines(device.get(),
        pipelineCache.get(),
        createInfoCount,
        reinterpret_cast<const VkComputePipelineCreateInfo*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipeline*>(pPipelines)));
}
void DeviceFunctions::DestroyPipeline(Pipeline pipeline, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyPipeline(device.get(),
        pipeline.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<PipelineLayout> DeviceFunctions::CreatePipelineLayout(const PipelineLayoutCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    PipelineLayout pPipelineLayout;
    vk::Result result = static_cast<Result>(pfn_CreatePipelineLayout(device.get(),
        reinterpret_cast<const VkPipelineLayoutCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipelineLayout*>(&pPipelineLayout)));
    return expected<PipelineLayout>(pPipelineLayout, result);
}
void DeviceFunctions::DestroyPipelineLayout(PipelineLayout pipelineLayout, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyPipelineLayout(device.get(),
        pipelineLayout.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<Sampler> DeviceFunctions::CreateSampler(const SamplerCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Sampler pSampler;
    vk::Result result = static_cast<Result>(pfn_CreateSampler(device.get(),
        reinterpret_cast<const VkSamplerCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSampler*>(&pSampler)));
    return expected<Sampler>(pSampler, result);
}
void DeviceFunctions::DestroySampler(Sampler sampler, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroySampler(device.get(),
        sampler.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<DescriptorSetLayout> DeviceFunctions::CreateDescriptorSetLayout(const DescriptorSetLayoutCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DescriptorSetLayout pSetLayout;
    vk::Result result = static_cast<Result>(pfn_CreateDescriptorSetLayout(device.get(),
        reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDescriptorSetLayout*>(&pSetLayout)));
    return expected<DescriptorSetLayout>(pSetLayout, result);
}
void DeviceFunctions::DestroyDescriptorSetLayout(DescriptorSetLayout descriptorSetLayout, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDescriptorSetLayout(device.get(),
        descriptorSetLayout.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<DescriptorPool> DeviceFunctions::CreateDescriptorPool(const DescriptorPoolCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DescriptorPool pDescriptorPool;
    vk::Result result = static_cast<Result>(pfn_CreateDescriptorPool(device.get(),
        reinterpret_cast<const VkDescriptorPoolCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDescriptorPool*>(&pDescriptorPool)));
    return expected<DescriptorPool>(pDescriptorPool, result);
}
void DeviceFunctions::DestroyDescriptorPool(DescriptorPool descriptorPool, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDescriptorPool(device.get(),
        descriptorPool.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Result DeviceFunctions::ResetDescriptorPool(DescriptorPool descriptorPool, 
    DescriptorPoolResetFlags flags) const {
    return static_cast<Result>(pfn_ResetDescriptorPool(device.get(),
        descriptorPool.get(),
        static_cast<VkDescriptorPoolResetFlags>(flags)));
}
[[nodiscard]] Result DeviceFunctions::AllocateDescriptorSets(const DescriptorSetAllocateInfo&  pAllocateInfo, 
    DescriptorSet* pDescriptorSets) const {
    return static_cast<Result>(pfn_AllocateDescriptorSets(device.get(),
        reinterpret_cast<const VkDescriptorSetAllocateInfo*>(&pAllocateInfo),
        reinterpret_cast<VkDescriptorSet*>(pDescriptorSets)));
}
[[nodiscard]] Result DeviceFunctions::FreeDescriptorSets(DescriptorPool descriptorPool, 
    uint32_t descriptorSetCount, 
    const DescriptorSet* pDescriptorSets) const {
    return static_cast<Result>(pfn_FreeDescriptorSets(device.get(),
        descriptorPool.get(),
        descriptorSetCount,
        reinterpret_cast<const VkDescriptorSet*>(pDescriptorSets)));
}
void DeviceFunctions::UpdateDescriptorSets(uint32_t descriptorWriteCount, 
    const WriteDescriptorSet* pDescriptorWrites, 
    uint32_t descriptorCopyCount, 
    const CopyDescriptorSet* pDescriptorCopies) const {
    pfn_UpdateDescriptorSets(device.get(),
        descriptorWriteCount,
        reinterpret_cast<const VkWriteDescriptorSet*>(pDescriptorWrites),
        descriptorCopyCount,
        reinterpret_cast<const VkCopyDescriptorSet*>(pDescriptorCopies));
}
[[nodiscard]] expected<Framebuffer> DeviceFunctions::CreateFramebuffer(const FramebufferCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    Framebuffer pFramebuffer;
    vk::Result result = static_cast<Result>(pfn_CreateFramebuffer(device.get(),
        reinterpret_cast<const VkFramebufferCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkFramebuffer*>(&pFramebuffer)));
    return expected<Framebuffer>(pFramebuffer, result);
}
void DeviceFunctions::DestroyFramebuffer(Framebuffer framebuffer, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyFramebuffer(device.get(),
        framebuffer.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<RenderPass> DeviceFunctions::CreateRenderPass(const RenderPassCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    RenderPass pRenderPass;
    vk::Result result = static_cast<Result>(pfn_CreateRenderPass(device.get(),
        reinterpret_cast<const VkRenderPassCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkRenderPass*>(&pRenderPass)));
    return expected<RenderPass>(pRenderPass, result);
}
void DeviceFunctions::DestroyRenderPass(RenderPass renderPass, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyRenderPass(device.get(),
        renderPass.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Extent2D DeviceFunctions::GetRenderAreaGranularity(RenderPass renderPass) const {
    Extent2D pGranularity;
    pfn_GetRenderAreaGranularity(device.get(),
        renderPass.get(),
        reinterpret_cast<VkExtent2D*>(&pGranularity));
    return pGranularity;
}
[[nodiscard]] expected<CommandPool> DeviceFunctions::CreateCommandPool(const CommandPoolCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    CommandPool pCommandPool;
    vk::Result result = static_cast<Result>(pfn_CreateCommandPool(device.get(),
        reinterpret_cast<const VkCommandPoolCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkCommandPool*>(&pCommandPool)));
    return expected<CommandPool>(pCommandPool, result);
}
void DeviceFunctions::DestroyCommandPool(CommandPool commandPool, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyCommandPool(device.get(),
        commandPool.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Result DeviceFunctions::ResetCommandPool(CommandPool commandPool, 
    CommandPoolResetFlags flags) const {
    return static_cast<Result>(pfn_ResetCommandPool(device.get(),
        commandPool.get(),
        static_cast<VkCommandPoolResetFlags>(flags)));
}
[[nodiscard]] Result DeviceFunctions::AllocateCommandBuffers(const CommandBufferAllocateInfo&  pAllocateInfo, 
    CommandBuffer* pCommandBuffers) const {
    return static_cast<Result>(pfn_AllocateCommandBuffers(device.get(),
        reinterpret_cast<const VkCommandBufferAllocateInfo*>(&pAllocateInfo),
        reinterpret_cast<VkCommandBuffer*>(pCommandBuffers)));
}
void DeviceFunctions::FreeCommandBuffers(CommandPool commandPool, 
    uint32_t commandBufferCount, 
    const CommandBuffer* pCommandBuffers) const {
    pfn_FreeCommandBuffers(device.get(),
        commandPool.get(),
        commandBufferCount,
        reinterpret_cast<const VkCommandBuffer*>(pCommandBuffers));
}
[[nodiscard]] Result DeviceFunctions::BeginCommandBuffer(CommandBuffer commandBuffer, 
    const CommandBufferBeginInfo&  pBeginInfo) const {
    return static_cast<Result>(pfn_BeginCommandBuffer(commandBuffer.get(),
        reinterpret_cast<const VkCommandBufferBeginInfo*>(&pBeginInfo)));
}
[[nodiscard]] Result DeviceFunctions::EndCommandBuffer(CommandBuffer commandBuffer) const {
    return static_cast<Result>(pfn_EndCommandBuffer(commandBuffer.get()));
}
[[nodiscard]] Result DeviceFunctions::ResetCommandBuffer(CommandBuffer commandBuffer, 
    CommandBufferResetFlags flags) const {
    return static_cast<Result>(pfn_ResetCommandBuffer(commandBuffer.get(),
        static_cast<VkCommandBufferResetFlags>(flags)));
}
void DeviceFunctions::CmdBindPipeline(CommandBuffer commandBuffer, 
    PipelineBindPoint pipelineBindPoint, 
    Pipeline pipeline) const {
    pfn_CmdBindPipeline(commandBuffer.get(),
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        pipeline.get());
}
void DeviceFunctions::CmdSetViewport(CommandBuffer commandBuffer, 
    uint32_t firstViewport, 
    uint32_t viewportCount, 
    const Viewport* pViewports) const {
    pfn_CmdSetViewport(commandBuffer.get(),
        firstViewport,
        viewportCount,
        reinterpret_cast<const VkViewport*>(pViewports));
}
void DeviceFunctions::CmdSetScissor(CommandBuffer commandBuffer, 
    uint32_t firstScissor, 
    uint32_t scissorCount, 
    const Rect2D* pScissors) const {
    pfn_CmdSetScissor(commandBuffer.get(),
        firstScissor,
        scissorCount,
        reinterpret_cast<const VkRect2D*>(pScissors));
}
void DeviceFunctions::CmdSetLineWidth(CommandBuffer commandBuffer, 
    float lineWidth) const {
    pfn_CmdSetLineWidth(commandBuffer.get(),
        lineWidth);
}
void DeviceFunctions::CmdSetDepthBias(CommandBuffer commandBuffer, 
    float depthBiasConstantFactor, 
    float depthBiasClamp, 
    float depthBiasSlopeFactor) const {
    pfn_CmdSetDepthBias(commandBuffer.get(),
        depthBiasConstantFactor,
        depthBiasClamp,
        depthBiasSlopeFactor);
}
void DeviceFunctions::CmdSetBlendConstants(CommandBuffer commandBuffer, 
    const float blendConstants[4]) const {
    pfn_CmdSetBlendConstants(commandBuffer.get(),
        blendConstants);
}
void DeviceFunctions::CmdSetDepthBounds(CommandBuffer commandBuffer, 
    float minDepthBounds, 
    float maxDepthBounds) const {
    pfn_CmdSetDepthBounds(commandBuffer.get(),
        minDepthBounds,
        maxDepthBounds);
}
void DeviceFunctions::CmdSetStencilCompareMask(CommandBuffer commandBuffer, 
    StencilFaceFlags faceMask, 
    uint32_t compareMask) const {
    pfn_CmdSetStencilCompareMask(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        compareMask);
}
void DeviceFunctions::CmdSetStencilWriteMask(CommandBuffer commandBuffer, 
    StencilFaceFlags faceMask, 
    uint32_t writeMask) const {
    pfn_CmdSetStencilWriteMask(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        writeMask);
}
void DeviceFunctions::CmdSetStencilReference(CommandBuffer commandBuffer, 
    StencilFaceFlags faceMask, 
    uint32_t reference) const {
    pfn_CmdSetStencilReference(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        reference);
}
void DeviceFunctions::CmdBindDescriptorSets(CommandBuffer commandBuffer, 
    PipelineBindPoint pipelineBindPoint, 
    PipelineLayout layout, 
    uint32_t firstSet, 
    uint32_t descriptorSetCount, 
    const DescriptorSet* pDescriptorSets, 
    uint32_t dynamicOffsetCount, 
    const uint32_t* pDynamicOffsets) const {
    pfn_CmdBindDescriptorSets(commandBuffer.get(),
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        layout.get(),
        firstSet,
        descriptorSetCount,
        reinterpret_cast<const VkDescriptorSet*>(pDescriptorSets),
        dynamicOffsetCount,
        pDynamicOffsets);
}
void DeviceFunctions::CmdBindIndexBuffer(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    IndexType indexType) const {
    pfn_CmdBindIndexBuffer(commandBuffer.get(),
        buffer.get(),
        offset,
        static_cast<VkIndexType>(indexType));
}
void DeviceFunctions::CmdBindVertexBuffers(CommandBuffer commandBuffer, 
    uint32_t firstBinding, 
    uint32_t bindingCount, 
    const Buffer* pBuffers, 
    const DeviceSize* pOffsets) const {
    pfn_CmdBindVertexBuffers(commandBuffer.get(),
        firstBinding,
        bindingCount,
        reinterpret_cast<const VkBuffer*>(pBuffers),
        pOffsets);
}
void DeviceFunctions::CmdDraw(CommandBuffer commandBuffer, 
    uint32_t vertexCount, 
    uint32_t instanceCount, 
    uint32_t firstVertex, 
    uint32_t firstInstance) const {
    pfn_CmdDraw(commandBuffer.get(),
        vertexCount,
        instanceCount,
        firstVertex,
        firstInstance);
}
void DeviceFunctions::CmdDrawIndexed(CommandBuffer commandBuffer, 
    uint32_t indexCount, 
    uint32_t instanceCount, 
    uint32_t firstIndex, 
    int32_t vertexOffset, 
    uint32_t firstInstance) const {
    pfn_CmdDrawIndexed(commandBuffer.get(),
        indexCount,
        instanceCount,
        firstIndex,
        vertexOffset,
        firstInstance);
}
void DeviceFunctions::CmdDrawIndirect(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    uint32_t drawCount, 
    uint32_t stride) const {
    pfn_CmdDrawIndirect(commandBuffer.get(),
        buffer.get(),
        offset,
        drawCount,
        stride);
}
void DeviceFunctions::CmdDrawIndexedIndirect(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    uint32_t drawCount, 
    uint32_t stride) const {
    pfn_CmdDrawIndexedIndirect(commandBuffer.get(),
        buffer.get(),
        offset,
        drawCount,
        stride);
}
void DeviceFunctions::CmdDispatch(CommandBuffer commandBuffer, 
    uint32_t groupCountX, 
    uint32_t groupCountY, 
    uint32_t groupCountZ) const {
    pfn_CmdDispatch(commandBuffer.get(),
        groupCountX,
        groupCountY,
        groupCountZ);
}
void DeviceFunctions::CmdDispatchIndirect(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset) const {
    pfn_CmdDispatchIndirect(commandBuffer.get(),
        buffer.get(),
        offset);
}
void DeviceFunctions::CmdCopyBuffer(CommandBuffer commandBuffer, 
    Buffer srcBuffer, 
    Buffer dstBuffer, 
    uint32_t regionCount, 
    const BufferCopy* pRegions) const {
    pfn_CmdCopyBuffer(commandBuffer.get(),
        srcBuffer.get(),
        dstBuffer.get(),
        regionCount,
        reinterpret_cast<const VkBufferCopy*>(pRegions));
}
void DeviceFunctions::CmdCopyImage(CommandBuffer commandBuffer, 
    Image srcImage, 
    ImageLayout srcImageLayout, 
    Image dstImage, 
    ImageLayout dstImageLayout, 
    uint32_t regionCount, 
    const ImageCopy* pRegions) const {
    pfn_CmdCopyImage(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkImageCopy*>(pRegions));
}
void DeviceFunctions::CmdBlitImage(CommandBuffer commandBuffer, 
    Image srcImage, 
    ImageLayout srcImageLayout, 
    Image dstImage, 
    ImageLayout dstImageLayout, 
    uint32_t regionCount, 
    const ImageBlit* pRegions, 
    Filter filter) const {
    pfn_CmdBlitImage(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkImageBlit*>(pRegions),
        static_cast<VkFilter>(filter));
}
void DeviceFunctions::CmdCopyBufferToImage(CommandBuffer commandBuffer, 
    Buffer srcBuffer, 
    Image dstImage, 
    ImageLayout dstImageLayout, 
    uint32_t regionCount, 
    const BufferImageCopy* pRegions) const {
    pfn_CmdCopyBufferToImage(commandBuffer.get(),
        srcBuffer.get(),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkBufferImageCopy*>(pRegions));
}
void DeviceFunctions::CmdCopyImageToBuffer(CommandBuffer commandBuffer, 
    Image srcImage, 
    ImageLayout srcImageLayout, 
    Buffer dstBuffer, 
    uint32_t regionCount, 
    const BufferImageCopy* pRegions) const {
    pfn_CmdCopyImageToBuffer(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstBuffer.get(),
        regionCount,
        reinterpret_cast<const VkBufferImageCopy*>(pRegions));
}
void DeviceFunctions::CmdUpdateBuffer(CommandBuffer commandBuffer, 
    Buffer dstBuffer, 
    DeviceSize dstOffset, 
    DeviceSize dataSize, 
    const void* pData) const {
    pfn_CmdUpdateBuffer(commandBuffer.get(),
        dstBuffer.get(),
        dstOffset,
        dataSize,
        reinterpret_cast<const void*>(pData));
}
void DeviceFunctions::CmdFillBuffer(CommandBuffer commandBuffer, 
    Buffer dstBuffer, 
    DeviceSize dstOffset, 
    DeviceSize size, 
    uint32_t data) const {
    pfn_CmdFillBuffer(commandBuffer.get(),
        dstBuffer.get(),
        dstOffset,
        size,
        data);
}
void DeviceFunctions::CmdClearColorImage(CommandBuffer commandBuffer, 
    Image image, 
    ImageLayout imageLayout, 
    const ClearColorValue&  pColor, 
    uint32_t rangeCount, 
    const ImageSubresourceRange* pRanges) const {
    pfn_CmdClearColorImage(commandBuffer.get(),
        image.get(),
        static_cast<VkImageLayout>(imageLayout),
        reinterpret_cast<const VkClearColorValue*>(&pColor),
        rangeCount,
        reinterpret_cast<const VkImageSubresourceRange*>(pRanges));
}
void DeviceFunctions::CmdClearDepthStencilImage(CommandBuffer commandBuffer, 
    Image image, 
    ImageLayout imageLayout, 
    const ClearDepthStencilValue&  pDepthStencil, 
    uint32_t rangeCount, 
    const ImageSubresourceRange* pRanges) const {
    pfn_CmdClearDepthStencilImage(commandBuffer.get(),
        image.get(),
        static_cast<VkImageLayout>(imageLayout),
        reinterpret_cast<const VkClearDepthStencilValue*>(&pDepthStencil),
        rangeCount,
        reinterpret_cast<const VkImageSubresourceRange*>(pRanges));
}
void DeviceFunctions::CmdClearAttachments(CommandBuffer commandBuffer, 
    uint32_t attachmentCount, 
    const ClearAttachment* pAttachments, 
    uint32_t rectCount, 
    const ClearRect* pRects) const {
    pfn_CmdClearAttachments(commandBuffer.get(),
        attachmentCount,
        reinterpret_cast<const VkClearAttachment*>(pAttachments),
        rectCount,
        reinterpret_cast<const VkClearRect*>(pRects));
}
void DeviceFunctions::CmdResolveImage(CommandBuffer commandBuffer, 
    Image srcImage, 
    ImageLayout srcImageLayout, 
    Image dstImage, 
    ImageLayout dstImageLayout, 
    uint32_t regionCount, 
    const ImageResolve* pRegions) const {
    pfn_CmdResolveImage(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkImageResolve*>(pRegions));
}
void DeviceFunctions::CmdSetEvent(CommandBuffer commandBuffer, 
    Event event, 
    PipelineStageFlags stageMask) const {
    pfn_CmdSetEvent(commandBuffer.get(),
        event.get(),
        static_cast<VkPipelineStageFlags>(stageMask));
}
void DeviceFunctions::CmdResetEvent(CommandBuffer commandBuffer, 
    Event event, 
    PipelineStageFlags stageMask) const {
    pfn_CmdResetEvent(commandBuffer.get(),
        event.get(),
        static_cast<VkPipelineStageFlags>(stageMask));
}
void DeviceFunctions::CmdWaitEvents(CommandBuffer commandBuffer, 
    uint32_t eventCount, 
    const Event* pEvents, 
    PipelineStageFlags srcStageMask, 
    PipelineStageFlags dstStageMask, 
    uint32_t memoryBarrierCount, 
    const MemoryBarrier* pMemoryBarriers, 
    uint32_t bufferMemoryBarrierCount, 
    const BufferMemoryBarrier* pBufferMemoryBarriers, 
    uint32_t imageMemoryBarrierCount, 
    const ImageMemoryBarrier* pImageMemoryBarriers) const {
    pfn_CmdWaitEvents(commandBuffer.get(),
        eventCount,
        reinterpret_cast<const VkEvent*>(pEvents),
        static_cast<VkPipelineStageFlags>(srcStageMask),
        static_cast<VkPipelineStageFlags>(dstStageMask),
        memoryBarrierCount,
        reinterpret_cast<const VkMemoryBarrier*>(pMemoryBarriers),
        bufferMemoryBarrierCount,
        reinterpret_cast<const VkBufferMemoryBarrier*>(pBufferMemoryBarriers),
        imageMemoryBarrierCount,
        reinterpret_cast<const VkImageMemoryBarrier*>(pImageMemoryBarriers));
}
void DeviceFunctions::CmdPipelineBarrier(CommandBuffer commandBuffer, 
    PipelineStageFlags srcStageMask, 
    PipelineStageFlags dstStageMask, 
    DependencyFlags dependencyFlags, 
    uint32_t memoryBarrierCount, 
    const MemoryBarrier* pMemoryBarriers, 
    uint32_t bufferMemoryBarrierCount, 
    const BufferMemoryBarrier* pBufferMemoryBarriers, 
    uint32_t imageMemoryBarrierCount, 
    const ImageMemoryBarrier* pImageMemoryBarriers) const {
    pfn_CmdPipelineBarrier(commandBuffer.get(),
        static_cast<VkPipelineStageFlags>(srcStageMask),
        static_cast<VkPipelineStageFlags>(dstStageMask),
        static_cast<VkDependencyFlags>(dependencyFlags),
        memoryBarrierCount,
        reinterpret_cast<const VkMemoryBarrier*>(pMemoryBarriers),
        bufferMemoryBarrierCount,
        reinterpret_cast<const VkBufferMemoryBarrier*>(pBufferMemoryBarriers),
        imageMemoryBarrierCount,
        reinterpret_cast<const VkImageMemoryBarrier*>(pImageMemoryBarriers));
}
void DeviceFunctions::CmdBeginQuery(CommandBuffer commandBuffer, 
    QueryPool queryPool, 
    uint32_t query, 
    QueryControlFlags flags) const {
    pfn_CmdBeginQuery(commandBuffer.get(),
        queryPool.get(),
        query,
        static_cast<VkQueryControlFlags>(flags));
}
void DeviceFunctions::CmdEndQuery(CommandBuffer commandBuffer, 
    QueryPool queryPool, 
    uint32_t query) const {
    pfn_CmdEndQuery(commandBuffer.get(),
        queryPool.get(),
        query);
}
void DeviceFunctions::CmdResetQueryPool(CommandBuffer commandBuffer, 
    QueryPool queryPool, 
    uint32_t firstQuery, 
    uint32_t queryCount) const {
    pfn_CmdResetQueryPool(commandBuffer.get(),
        queryPool.get(),
        firstQuery,
        queryCount);
}
void DeviceFunctions::CmdWriteTimestamp(CommandBuffer commandBuffer, 
    PipelineStageFlagBits pipelineStage, 
    QueryPool queryPool, 
    uint32_t query) const {
    pfn_CmdWriteTimestamp(commandBuffer.get(),
        static_cast<VkPipelineStageFlagBits>(pipelineStage),
        queryPool.get(),
        query);
}
void DeviceFunctions::CmdCopyQueryPoolResults(CommandBuffer commandBuffer, 
    QueryPool queryPool, 
    uint32_t firstQuery, 
    uint32_t queryCount, 
    Buffer dstBuffer, 
    DeviceSize dstOffset, 
    DeviceSize stride, 
    QueryResultFlags flags) const {
    pfn_CmdCopyQueryPoolResults(commandBuffer.get(),
        queryPool.get(),
        firstQuery,
        queryCount,
        dstBuffer.get(),
        dstOffset,
        stride,
        static_cast<VkQueryResultFlags>(flags));
}
void DeviceFunctions::CmdPushConstants(CommandBuffer commandBuffer, 
    PipelineLayout layout, 
    ShaderStageFlags stageFlags, 
    uint32_t offset, 
    uint32_t size, 
    const void* pValues) const {
    pfn_CmdPushConstants(commandBuffer.get(),
        layout.get(),
        static_cast<VkShaderStageFlags>(stageFlags),
        offset,
        size,
        reinterpret_cast<const void*>(pValues));
}
void DeviceFunctions::CmdBeginRenderPass(CommandBuffer commandBuffer, 
    const RenderPassBeginInfo&  pRenderPassBegin, 
    SubpassContents contents) const {
    pfn_CmdBeginRenderPass(commandBuffer.get(),
        reinterpret_cast<const VkRenderPassBeginInfo*>(&pRenderPassBegin),
        static_cast<VkSubpassContents>(contents));
}
void DeviceFunctions::CmdNextSubpass(CommandBuffer commandBuffer, 
    SubpassContents contents) const {
    pfn_CmdNextSubpass(commandBuffer.get(),
        static_cast<VkSubpassContents>(contents));
}
void DeviceFunctions::CmdEndRenderPass(CommandBuffer commandBuffer) const {
    pfn_CmdEndRenderPass(commandBuffer.get());
}
void DeviceFunctions::CmdExecuteCommands(CommandBuffer commandBuffer, 
    uint32_t commandBufferCount, 
    const CommandBuffer* pCommandBuffers) const {
    pfn_CmdExecuteCommands(commandBuffer.get(),
        commandBufferCount,
        reinterpret_cast<const VkCommandBuffer*>(pCommandBuffers));
}
[[nodiscard]] Result DeviceFunctions::BindBufferMemory2(uint32_t bindInfoCount, 
    const BindBufferMemoryInfo* pBindInfos) const {
    return static_cast<Result>(pfn_BindBufferMemory2(device.get(),
        bindInfoCount,
        reinterpret_cast<const VkBindBufferMemoryInfo*>(pBindInfos)));
}
[[nodiscard]] Result DeviceFunctions::BindImageMemory2(uint32_t bindInfoCount, 
    const BindImageMemoryInfo* pBindInfos) const {
    return static_cast<Result>(pfn_BindImageMemory2(device.get(),
        bindInfoCount,
        reinterpret_cast<const VkBindImageMemoryInfo*>(pBindInfos)));
}
[[nodiscard]] PeerMemoryFeatureFlags DeviceFunctions::GetDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, 
    uint32_t localDeviceIndex, 
    uint32_t remoteDeviceIndex) const {
    PeerMemoryFeatureFlags pPeerMemoryFeatures;
    pfn_GetDeviceGroupPeerMemoryFeatures(device.get(),
        heapIndex,
        localDeviceIndex,
        remoteDeviceIndex,
        reinterpret_cast<VkPeerMemoryFeatureFlags*>(&pPeerMemoryFeatures));
    return pPeerMemoryFeatures;
}
void DeviceFunctions::CmdSetDeviceMask(CommandBuffer commandBuffer, 
    uint32_t deviceMask) const {
    pfn_CmdSetDeviceMask(commandBuffer.get(),
        deviceMask);
}
void DeviceFunctions::CmdDispatchBase(CommandBuffer commandBuffer, 
    uint32_t baseGroupX, 
    uint32_t baseGroupY, 
    uint32_t baseGroupZ, 
    uint32_t groupCountX, 
    uint32_t groupCountY, 
    uint32_t groupCountZ) const {
    pfn_CmdDispatchBase(commandBuffer.get(),
        baseGroupX,
        baseGroupY,
        baseGroupZ,
        groupCountX,
        groupCountY,
        groupCountZ);
}
[[nodiscard]] MemoryRequirements2 DeviceFunctions::GetBufferMemoryRequirements2(const BufferMemoryRequirementsInfo2&  pInfo) const {
    MemoryRequirements2 pMemoryRequirements;
    pfn_GetBufferMemoryRequirements2(device.get(),
        reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(&pInfo),
        reinterpret_cast<VkMemoryRequirements2*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
[[nodiscard]] MemoryRequirements2 DeviceFunctions::GetImageMemoryRequirements2(const ImageMemoryRequirementsInfo2&  pInfo) const {
    MemoryRequirements2 pMemoryRequirements;
    pfn_GetImageMemoryRequirements2(device.get(),
        reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(&pInfo),
        reinterpret_cast<VkMemoryRequirements2*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
[[nodiscard]] detail::fixed_vector<SparseImageMemoryRequirements2> DeviceFunctions::GetImageSparseMemoryRequirements2(const ImageSparseMemoryRequirementsInfo2&  pInfo) const {
    uint32_t pSparseMemoryRequirementCount = 0;
    pfn_GetImageSparseMemoryRequirements2(device.get(),
        reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(&pInfo),
        &pSparseMemoryRequirementCount,
        nullptr);
    detail::fixed_vector<SparseImageMemoryRequirements2> pSparseMemoryRequirements{pSparseMemoryRequirementCount};
    pfn_GetImageSparseMemoryRequirements2(device.get(),
        reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(&pInfo),
        &pSparseMemoryRequirementCount,
        reinterpret_cast<VkSparseImageMemoryRequirements2*>(pSparseMemoryRequirements.data()));
    if (pSparseMemoryRequirementCount < pSparseMemoryRequirements.size()) pSparseMemoryRequirements.shrink(pSparseMemoryRequirementCount);
    return pSparseMemoryRequirements;
}
void DeviceFunctions::TrimCommandPool(CommandPool commandPool, 
    CommandPoolTrimFlags flags) const {
    pfn_TrimCommandPool(device.get(),
        commandPool.get(),
        static_cast<VkCommandPoolTrimFlags>(flags));
}
[[nodiscard]] Queue DeviceFunctions::GetDeviceQueue2(const DeviceQueueInfo2&  pQueueInfo) const {
    Queue pQueue;
    pfn_GetDeviceQueue2(device.get(),
        reinterpret_cast<const VkDeviceQueueInfo2*>(&pQueueInfo),
        reinterpret_cast<VkQueue*>(&pQueue));
    return pQueue;
}
[[nodiscard]] expected<SamplerYcbcrConversion> DeviceFunctions::CreateSamplerYcbcrConversion(const SamplerYcbcrConversionCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SamplerYcbcrConversion pYcbcrConversion;
    vk::Result result = static_cast<Result>(pfn_CreateSamplerYcbcrConversion(device.get(),
        reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSamplerYcbcrConversion*>(&pYcbcrConversion)));
    return expected<SamplerYcbcrConversion>(pYcbcrConversion, result);
}
void DeviceFunctions::DestroySamplerYcbcrConversion(SamplerYcbcrConversion ycbcrConversion, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroySamplerYcbcrConversion(device.get(),
        ycbcrConversion.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<DescriptorUpdateTemplate> DeviceFunctions::CreateDescriptorUpdateTemplate(const DescriptorUpdateTemplateCreateInfo&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    DescriptorUpdateTemplate pDescriptorUpdateTemplate;
    vk::Result result = static_cast<Result>(pfn_CreateDescriptorUpdateTemplate(device.get(),
        reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDescriptorUpdateTemplate*>(&pDescriptorUpdateTemplate)));
    return expected<DescriptorUpdateTemplate>(pDescriptorUpdateTemplate, result);
}
void DeviceFunctions::DestroyDescriptorUpdateTemplate(DescriptorUpdateTemplate descriptorUpdateTemplate, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDescriptorUpdateTemplate(device.get(),
        descriptorUpdateTemplate.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
void DeviceFunctions::UpdateDescriptorSetWithTemplate(DescriptorSet descriptorSet, 
    DescriptorUpdateTemplate descriptorUpdateTemplate, 
    const void* pData) const {
    pfn_UpdateDescriptorSetWithTemplate(device.get(),
        descriptorSet.get(),
        descriptorUpdateTemplate.get(),
        reinterpret_cast<const void*>(pData));
}
[[nodiscard]] DescriptorSetLayoutSupport DeviceFunctions::GetDescriptorSetLayoutSupport(const DescriptorSetLayoutCreateInfo&  pCreateInfo) const {
    DescriptorSetLayoutSupport pSupport;
    pfn_GetDescriptorSetLayoutSupport(device.get(),
        reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(&pCreateInfo),
        reinterpret_cast<VkDescriptorSetLayoutSupport*>(&pSupport));
    return pSupport;
}
void DeviceFunctions::CmdDrawIndirectCount(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    Buffer countBuffer, 
    DeviceSize countBufferOffset, 
    uint32_t maxDrawCount, 
    uint32_t stride) const {
    pfn_CmdDrawIndirectCount(commandBuffer.get(),
        buffer.get(),
        offset,
        countBuffer.get(),
        countBufferOffset,
        maxDrawCount,
        stride);
}
void DeviceFunctions::CmdDrawIndexedIndirectCount(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    Buffer countBuffer, 
    DeviceSize countBufferOffset, 
    uint32_t maxDrawCount, 
    uint32_t stride) const {
    pfn_CmdDrawIndexedIndirectCount(commandBuffer.get(),
        buffer.get(),
        offset,
        countBuffer.get(),
        countBufferOffset,
        maxDrawCount,
        stride);
}
[[nodiscard]] expected<RenderPass> DeviceFunctions::CreateRenderPass2(const RenderPassCreateInfo2&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    RenderPass pRenderPass;
    vk::Result result = static_cast<Result>(pfn_CreateRenderPass2(device.get(),
        reinterpret_cast<const VkRenderPassCreateInfo2*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkRenderPass*>(&pRenderPass)));
    return expected<RenderPass>(pRenderPass, result);
}
void DeviceFunctions::CmdBeginRenderPass2(CommandBuffer commandBuffer, 
    const RenderPassBeginInfo&  pRenderPassBegin, 
    const SubpassBeginInfo&  pSubpassBeginInfo) const {
    pfn_CmdBeginRenderPass2(commandBuffer.get(),
        reinterpret_cast<const VkRenderPassBeginInfo*>(&pRenderPassBegin),
        reinterpret_cast<const VkSubpassBeginInfo*>(&pSubpassBeginInfo));
}
void DeviceFunctions::CmdNextSubpass2(CommandBuffer commandBuffer, 
    const SubpassBeginInfo&  pSubpassBeginInfo, 
    const SubpassEndInfo&  pSubpassEndInfo) const {
    pfn_CmdNextSubpass2(commandBuffer.get(),
        reinterpret_cast<const VkSubpassBeginInfo*>(&pSubpassBeginInfo),
        reinterpret_cast<const VkSubpassEndInfo*>(&pSubpassEndInfo));
}
void DeviceFunctions::CmdEndRenderPass2(CommandBuffer commandBuffer, 
    const SubpassEndInfo&  pSubpassEndInfo) const {
    pfn_CmdEndRenderPass2(commandBuffer.get(),
        reinterpret_cast<const VkSubpassEndInfo*>(&pSubpassEndInfo));
}
void DeviceFunctions::ResetQueryPool(QueryPool queryPool, 
    uint32_t firstQuery, 
    uint32_t queryCount) const {
    pfn_ResetQueryPool(device.get(),
        queryPool.get(),
        firstQuery,
        queryCount);
}
[[nodiscard]] expected<uint64_t> DeviceFunctions::GetSemaphoreCounterValue(Semaphore semaphore) const {
    uint64_t pValue;
    vk::Result result = static_cast<Result>(pfn_GetSemaphoreCounterValue(device.get(),
        semaphore.get(),
        &pValue));
    return expected<uint64_t>(pValue, result);
}
[[nodiscard]] Result DeviceFunctions::WaitSemaphores(const SemaphoreWaitInfo&  pWaitInfo, 
    uint64_t timeout) const {
    return static_cast<Result>(pfn_WaitSemaphores(device.get(),
        reinterpret_cast<const VkSemaphoreWaitInfo*>(&pWaitInfo),
        timeout));
}
[[nodiscard]] Result DeviceFunctions::SignalSemaphore(const SemaphoreSignalInfo&  pSignalInfo) const {
    return static_cast<Result>(pfn_SignalSemaphore(device.get(),
        reinterpret_cast<const VkSemaphoreSignalInfo*>(&pSignalInfo)));
}
[[nodiscard]] uint64_t DeviceFunctions::GetBufferOpaqueCaptureAddress(const BufferDeviceAddressInfo&  pInfo) const {
    return pfn_GetBufferOpaqueCaptureAddress(device.get(),
        reinterpret_cast<const VkBufferDeviceAddressInfo*>(&pInfo));
}
[[nodiscard]] VkDeviceAddress DeviceFunctions::GetBufferDeviceAddress(const BufferDeviceAddressInfo&  pInfo) const {
    return pfn_GetBufferDeviceAddress(device.get(),
        reinterpret_cast<const VkBufferDeviceAddressInfo*>(&pInfo));
}
[[nodiscard]] uint64_t DeviceFunctions::GetDeviceMemoryOpaqueCaptureAddress(const DeviceMemoryOpaqueCaptureAddressInfo&  pInfo) const {
    return pfn_GetDeviceMemoryOpaqueCaptureAddress(device.get(),
        reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(&pInfo));
}
[[nodiscard]] expected<SwapchainKHR> DeviceFunctions::CreateSwapchainKHR(const SwapchainCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    SwapchainKHR pSwapchain;
    vk::Result result = static_cast<Result>(pfn_CreateSwapchainKHR(device.get(),
        reinterpret_cast<const VkSwapchainCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSwapchainKHR*>(&pSwapchain)));
    return expected<SwapchainKHR>(pSwapchain, result);
}
void DeviceFunctions::DestroySwapchainKHR(SwapchainKHR swapchain, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroySwapchainKHR(device.get(),
        swapchain.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<detail::fixed_vector<Image>> DeviceFunctions::GetSwapchainImagesKHR(SwapchainKHR swapchain) const {
    uint32_t pSwapchainImageCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetSwapchainImagesKHR(device.get(),
        swapchain.get(),
        &pSwapchainImageCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<Image>{}, result);
    detail::fixed_vector<Image> pSwapchainImages{pSwapchainImageCount};
    result = static_cast<Result>(pfn_GetSwapchainImagesKHR(device.get(),
        swapchain.get(),
        &pSwapchainImageCount,
        reinterpret_cast<VkImage*>(pSwapchainImages.data())));
    if (pSwapchainImageCount < pSwapchainImages.size()) pSwapchainImages.shrink(pSwapchainImageCount);
    return expected(std::move(pSwapchainImages), result);
}
[[nodiscard]] expected<uint32_t> DeviceFunctions::AcquireNextImageKHR(SwapchainKHR swapchain, 
    uint64_t timeout, 
    Semaphore semaphore, 
    Fence fence) const {
    uint32_t pImageIndex;
    vk::Result result = static_cast<Result>(pfn_AcquireNextImageKHR(device.get(),
        swapchain.get(),
        timeout,
        semaphore.get(),
        fence.get(),
        &pImageIndex));
    return expected<uint32_t>(pImageIndex, result);
}
[[nodiscard]] Result DeviceFunctions::QueuePresentKHR(Queue queue, 
    const PresentInfoKHR&  pPresentInfo) const {
    return static_cast<Result>(pfn_QueuePresentKHR(queue.get(),
        reinterpret_cast<const VkPresentInfoKHR*>(&pPresentInfo)));
}
[[nodiscard]] expected<DeviceGroupPresentCapabilitiesKHR> DeviceFunctions::GetDeviceGroupPresentCapabilitiesKHR() const {
    DeviceGroupPresentCapabilitiesKHR pDeviceGroupPresentCapabilities;
    vk::Result result = static_cast<Result>(pfn_GetDeviceGroupPresentCapabilitiesKHR(device.get(),
        reinterpret_cast<VkDeviceGroupPresentCapabilitiesKHR*>(&pDeviceGroupPresentCapabilities)));
    return expected<DeviceGroupPresentCapabilitiesKHR>(pDeviceGroupPresentCapabilities, result);
}
[[nodiscard]] expected<DeviceGroupPresentModeFlagsKHR> DeviceFunctions::GetDeviceGroupSurfacePresentModesKHR(SurfaceKHR surface) const {
    DeviceGroupPresentModeFlagsKHR pModes;
    vk::Result result = static_cast<Result>(pfn_GetDeviceGroupSurfacePresentModesKHR(device.get(),
        surface.get(),
        reinterpret_cast<VkDeviceGroupPresentModeFlagsKHR*>(&pModes)));
    return expected<DeviceGroupPresentModeFlagsKHR>(pModes, result);
}
[[nodiscard]] expected<uint32_t> DeviceFunctions::AcquireNextImage2KHR(const AcquireNextImageInfoKHR&  pAcquireInfo) const {
    uint32_t pImageIndex;
    vk::Result result = static_cast<Result>(pfn_AcquireNextImage2KHR(device.get(),
        reinterpret_cast<const VkAcquireNextImageInfoKHR*>(&pAcquireInfo),
        &pImageIndex));
    return expected<uint32_t>(pImageIndex, result);
}
[[nodiscard]] Result DeviceFunctions::CreateSharedSwapchainsKHR(uint32_t swapchainCount, 
    const SwapchainCreateInfoKHR* pCreateInfos, 
    const AllocationCallbacks* pAllocator, 
    SwapchainKHR* pSwapchains) const {
    return static_cast<Result>(pfn_CreateSharedSwapchainsKHR(device.get(),
        swapchainCount,
        reinterpret_cast<const VkSwapchainCreateInfoKHR*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSwapchainKHR*>(pSwapchains)));
}
[[nodiscard]] Result DeviceFunctions::DebugMarkerSetObjectNameEXT(const DebugMarkerObjectNameInfoEXT&  pNameInfo) const {
    return static_cast<Result>(pfn_DebugMarkerSetObjectNameEXT(device.get(),
        reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(&pNameInfo)));
}
[[nodiscard]] Result DeviceFunctions::DebugMarkerSetObjectTagEXT(const DebugMarkerObjectTagInfoEXT&  pTagInfo) const {
    return static_cast<Result>(pfn_DebugMarkerSetObjectTagEXT(device.get(),
        reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(&pTagInfo)));
}
void DeviceFunctions::CmdDebugMarkerBeginEXT(CommandBuffer commandBuffer, 
    const DebugMarkerMarkerInfoEXT&  pMarkerInfo) const {
    pfn_CmdDebugMarkerBeginEXT(commandBuffer.get(),
        reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(&pMarkerInfo));
}
void DeviceFunctions::CmdDebugMarkerEndEXT(CommandBuffer commandBuffer) const {
    pfn_CmdDebugMarkerEndEXT(commandBuffer.get());
}
void DeviceFunctions::CmdDebugMarkerInsertEXT(CommandBuffer commandBuffer, 
    const DebugMarkerMarkerInfoEXT&  pMarkerInfo) const {
    pfn_CmdDebugMarkerInsertEXT(commandBuffer.get(),
        reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(&pMarkerInfo));
}
void DeviceFunctions::CmdBindTransformFeedbackBuffersEXT(CommandBuffer commandBuffer, 
    uint32_t firstBinding, 
    uint32_t bindingCount, 
    const Buffer* pBuffers, 
    const DeviceSize* pOffsets, 
    const DeviceSize* pSizes) const {
    pfn_CmdBindTransformFeedbackBuffersEXT(commandBuffer.get(),
        firstBinding,
        bindingCount,
        reinterpret_cast<const VkBuffer*>(pBuffers),
        pOffsets,
        pSizes);
}
void DeviceFunctions::CmdBeginTransformFeedbackEXT(CommandBuffer commandBuffer, 
    uint32_t firstCounterBuffer, 
    uint32_t counterBufferCount, 
    const Buffer* pCounterBuffers, 
    const DeviceSize* pCounterBufferOffsets) const {
    pfn_CmdBeginTransformFeedbackEXT(commandBuffer.get(),
        firstCounterBuffer,
        counterBufferCount,
        reinterpret_cast<const VkBuffer*>(pCounterBuffers),
        pCounterBufferOffsets);
}
void DeviceFunctions::CmdEndTransformFeedbackEXT(CommandBuffer commandBuffer, 
    uint32_t firstCounterBuffer, 
    uint32_t counterBufferCount, 
    const Buffer* pCounterBuffers, 
    const DeviceSize* pCounterBufferOffsets) const {
    pfn_CmdEndTransformFeedbackEXT(commandBuffer.get(),
        firstCounterBuffer,
        counterBufferCount,
        reinterpret_cast<const VkBuffer*>(pCounterBuffers),
        pCounterBufferOffsets);
}
void DeviceFunctions::CmdBeginQueryIndexedEXT(CommandBuffer commandBuffer, 
    QueryPool queryPool, 
    uint32_t query, 
    QueryControlFlags flags, 
    uint32_t index) const {
    pfn_CmdBeginQueryIndexedEXT(commandBuffer.get(),
        queryPool.get(),
        query,
        static_cast<VkQueryControlFlags>(flags),
        index);
}
void DeviceFunctions::CmdEndQueryIndexedEXT(CommandBuffer commandBuffer, 
    QueryPool queryPool, 
    uint32_t query, 
    uint32_t index) const {
    pfn_CmdEndQueryIndexedEXT(commandBuffer.get(),
        queryPool.get(),
        query,
        index);
}
void DeviceFunctions::CmdDrawIndirectByteCountEXT(CommandBuffer commandBuffer, 
    uint32_t instanceCount, 
    uint32_t firstInstance, 
    Buffer counterBuffer, 
    DeviceSize counterBufferOffset, 
    uint32_t counterOffset, 
    uint32_t vertexStride) const {
    pfn_CmdDrawIndirectByteCountEXT(commandBuffer.get(),
        instanceCount,
        firstInstance,
        counterBuffer.get(),
        counterBufferOffset,
        counterOffset,
        vertexStride);
}
[[nodiscard]] uint32_t DeviceFunctions::GetImageViewHandleNVX(const ImageViewHandleInfoNVX&  pInfo) const {
    return pfn_GetImageViewHandleNVX(device.get(),
        reinterpret_cast<const VkImageViewHandleInfoNVX*>(&pInfo));
}
[[nodiscard]] expected<ImageViewAddressPropertiesNVX> DeviceFunctions::GetImageViewAddressNVX(ImageView imageView) const {
    ImageViewAddressPropertiesNVX pProperties;
    vk::Result result = static_cast<Result>(pfn_GetImageViewAddressNVX(device.get(),
        imageView.get(),
        reinterpret_cast<VkImageViewAddressPropertiesNVX*>(&pProperties)));
    return expected<ImageViewAddressPropertiesNVX>(pProperties, result);
}
[[nodiscard]] expected<detail::fixed_vector<void*>> DeviceFunctions::GetShaderInfoAMD(Pipeline pipeline, 
    ShaderStageFlagBits shaderStage, 
    ShaderInfoTypeAMD infoType) const {
    size_t pInfoSize = 0;
    vk::Result result = static_cast<Result>(pfn_GetShaderInfoAMD(device.get(),
        pipeline.get(),
        static_cast<VkShaderStageFlagBits>(shaderStage),
        static_cast<VkShaderInfoTypeAMD>(infoType),
        &pInfoSize,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<void*>{}, result);
    detail::fixed_vector<void*> pInfo{pInfoSize};
    result = static_cast<Result>(pfn_GetShaderInfoAMD(device.get(),
        pipeline.get(),
        static_cast<VkShaderStageFlagBits>(shaderStage),
        static_cast<VkShaderInfoTypeAMD>(infoType),
        &pInfoSize,
        reinterpret_cast<void*>(pInfo.data())));
    if (pInfoSize < pInfo.size()) pInfo.shrink(pInfoSize);
    return expected(std::move(pInfo), result);
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<HANDLE> DeviceFunctions::GetMemoryWin32HandleNV(DeviceMemory memory, 
    ExternalMemoryHandleTypeFlagsNV handleType) const {
    HANDLE pHandle;
    vk::Result result = static_cast<Result>(pfn_GetMemoryWin32HandleNV(device.get(),
        memory.get(),
        static_cast<VkExternalMemoryHandleTypeFlagsNV>(handleType),
        reinterpret_cast<HANDLE*>(&pHandle)));
    return expected<HANDLE>(pHandle, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<HANDLE> DeviceFunctions::GetMemoryWin32HandleKHR(const MemoryGetWin32HandleInfoKHR&  pGetWin32HandleInfo) const {
    HANDLE pHandle;
    vk::Result result = static_cast<Result>(pfn_GetMemoryWin32HandleKHR(device.get(),
        reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(&pGetWin32HandleInfo),
        reinterpret_cast<HANDLE*>(&pHandle)));
    return expected<HANDLE>(pHandle, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<MemoryWin32HandlePropertiesKHR> DeviceFunctions::GetMemoryWin32HandlePropertiesKHR(ExternalMemoryHandleTypeFlagBits handleType, 
    HANDLE handle) const {
    MemoryWin32HandlePropertiesKHR pMemoryWin32HandleProperties;
    vk::Result result = static_cast<Result>(pfn_GetMemoryWin32HandlePropertiesKHR(device.get(),
        static_cast<VkExternalMemoryHandleTypeFlagBits>(handleType),
        static_cast<HANDLE>(handle),
        reinterpret_cast<VkMemoryWin32HandlePropertiesKHR*>(&pMemoryWin32HandleProperties)));
    return expected<MemoryWin32HandlePropertiesKHR>(pMemoryWin32HandleProperties, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
[[nodiscard]] expected<int> DeviceFunctions::GetMemoryFdKHR(const MemoryGetFdInfoKHR&  pGetFdInfo) const {
    int pFd;
    vk::Result result = static_cast<Result>(pfn_GetMemoryFdKHR(device.get(),
        reinterpret_cast<const VkMemoryGetFdInfoKHR*>(&pGetFdInfo),
        &pFd));
    return expected<int>(pFd, result);
}
[[nodiscard]] expected<MemoryFdPropertiesKHR> DeviceFunctions::GetMemoryFdPropertiesKHR(ExternalMemoryHandleTypeFlagBits handleType, 
    int fd) const {
    MemoryFdPropertiesKHR pMemoryFdProperties;
    vk::Result result = static_cast<Result>(pfn_GetMemoryFdPropertiesKHR(device.get(),
        static_cast<VkExternalMemoryHandleTypeFlagBits>(handleType),
        fd,
        reinterpret_cast<VkMemoryFdPropertiesKHR*>(&pMemoryFdProperties)));
    return expected<MemoryFdPropertiesKHR>(pMemoryFdProperties, result);
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<HANDLE> DeviceFunctions::GetSemaphoreWin32HandleKHR(const SemaphoreGetWin32HandleInfoKHR&  pGetWin32HandleInfo) const {
    HANDLE pHandle;
    vk::Result result = static_cast<Result>(pfn_GetSemaphoreWin32HandleKHR(device.get(),
        reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(&pGetWin32HandleInfo),
        reinterpret_cast<HANDLE*>(&pHandle)));
    return expected<HANDLE>(pHandle, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] Result DeviceFunctions::ImportSemaphoreWin32HandleKHR(const ImportSemaphoreWin32HandleInfoKHR&  pImportSemaphoreWin32HandleInfo) const {
    return static_cast<Result>(pfn_ImportSemaphoreWin32HandleKHR(device.get(),
        reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(&pImportSemaphoreWin32HandleInfo)));
}
#endif // VK_USE_PLATFORM_WIN32_KHR
[[nodiscard]] expected<int> DeviceFunctions::GetSemaphoreFdKHR(const SemaphoreGetFdInfoKHR&  pGetFdInfo) const {
    int pFd;
    vk::Result result = static_cast<Result>(pfn_GetSemaphoreFdKHR(device.get(),
        reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(&pGetFdInfo),
        &pFd));
    return expected<int>(pFd, result);
}
[[nodiscard]] Result DeviceFunctions::ImportSemaphoreFdKHR(const ImportSemaphoreFdInfoKHR&  pImportSemaphoreFdInfo) const {
    return static_cast<Result>(pfn_ImportSemaphoreFdKHR(device.get(),
        reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(&pImportSemaphoreFdInfo)));
}
void DeviceFunctions::CmdPushDescriptorSetKHR(CommandBuffer commandBuffer, 
    PipelineBindPoint pipelineBindPoint, 
    PipelineLayout layout, 
    uint32_t set, 
    uint32_t descriptorWriteCount, 
    const WriteDescriptorSet* pDescriptorWrites) const {
    pfn_CmdPushDescriptorSetKHR(commandBuffer.get(),
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        layout.get(),
        set,
        descriptorWriteCount,
        reinterpret_cast<const VkWriteDescriptorSet*>(pDescriptorWrites));
}
void DeviceFunctions::CmdPushDescriptorSetWithTemplateKHR(CommandBuffer commandBuffer, 
    DescriptorUpdateTemplate descriptorUpdateTemplate, 
    PipelineLayout layout, 
    uint32_t set, 
    const void* pData) const {
    pfn_CmdPushDescriptorSetWithTemplateKHR(commandBuffer.get(),
        descriptorUpdateTemplate.get(),
        layout.get(),
        set,
        reinterpret_cast<const void*>(pData));
}
void DeviceFunctions::CmdBeginConditionalRenderingEXT(CommandBuffer commandBuffer, 
    const ConditionalRenderingBeginInfoEXT&  pConditionalRenderingBegin) const {
    pfn_CmdBeginConditionalRenderingEXT(commandBuffer.get(),
        reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(&pConditionalRenderingBegin));
}
void DeviceFunctions::CmdEndConditionalRenderingEXT(CommandBuffer commandBuffer) const {
    pfn_CmdEndConditionalRenderingEXT(commandBuffer.get());
}
void DeviceFunctions::CmdSetViewportWScalingNV(CommandBuffer commandBuffer, 
    uint32_t firstViewport, 
    uint32_t viewportCount, 
    const ViewportWScalingNV* pViewportWScalings) const {
    pfn_CmdSetViewportWScalingNV(commandBuffer.get(),
        firstViewport,
        viewportCount,
        reinterpret_cast<const VkViewportWScalingNV*>(pViewportWScalings));
}
[[nodiscard]] Result DeviceFunctions::DisplayPowerControlEXT(DisplayKHR display, 
    const DisplayPowerInfoEXT&  pDisplayPowerInfo) const {
    return static_cast<Result>(pfn_DisplayPowerControlEXT(device.get(),
        display.get(),
        reinterpret_cast<const VkDisplayPowerInfoEXT*>(&pDisplayPowerInfo)));
}
[[nodiscard]] expected<Fence> DeviceFunctions::RegisterDeviceEventEXT(const DeviceEventInfoEXT&  pDeviceEventInfo, 
    const AllocationCallbacks* pAllocator) const {
    Fence pFence;
    vk::Result result = static_cast<Result>(pfn_RegisterDeviceEventEXT(device.get(),
        reinterpret_cast<const VkDeviceEventInfoEXT*>(&pDeviceEventInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkFence*>(&pFence)));
    return expected<Fence>(pFence, result);
}
[[nodiscard]] expected<Fence> DeviceFunctions::RegisterDisplayEventEXT(DisplayKHR display, 
    const DisplayEventInfoEXT&  pDisplayEventInfo, 
    const AllocationCallbacks* pAllocator) const {
    Fence pFence;
    vk::Result result = static_cast<Result>(pfn_RegisterDisplayEventEXT(device.get(),
        display.get(),
        reinterpret_cast<const VkDisplayEventInfoEXT*>(&pDisplayEventInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkFence*>(&pFence)));
    return expected<Fence>(pFence, result);
}
[[nodiscard]] expected<uint64_t> DeviceFunctions::GetSwapchainCounterEXT(SwapchainKHR swapchain, 
    SurfaceCounterFlagBitsEXT counter) const {
    uint64_t pCounterValue;
    vk::Result result = static_cast<Result>(pfn_GetSwapchainCounterEXT(device.get(),
        swapchain.get(),
        static_cast<VkSurfaceCounterFlagBitsEXT>(counter),
        &pCounterValue));
    return expected<uint64_t>(pCounterValue, result);
}
[[nodiscard]] expected<RefreshCycleDurationGOOGLE> DeviceFunctions::GetRefreshCycleDurationGOOGLE(SwapchainKHR swapchain) const {
    RefreshCycleDurationGOOGLE pDisplayTimingProperties;
    vk::Result result = static_cast<Result>(pfn_GetRefreshCycleDurationGOOGLE(device.get(),
        swapchain.get(),
        reinterpret_cast<VkRefreshCycleDurationGOOGLE*>(&pDisplayTimingProperties)));
    return expected<RefreshCycleDurationGOOGLE>(pDisplayTimingProperties, result);
}
[[nodiscard]] expected<detail::fixed_vector<PastPresentationTimingGOOGLE>> DeviceFunctions::GetPastPresentationTimingGOOGLE(SwapchainKHR swapchain) const {
    uint32_t pPresentationTimingCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPastPresentationTimingGOOGLE(device.get(),
        swapchain.get(),
        &pPresentationTimingCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PastPresentationTimingGOOGLE>{}, result);
    detail::fixed_vector<PastPresentationTimingGOOGLE> pPresentationTimings{pPresentationTimingCount};
    result = static_cast<Result>(pfn_GetPastPresentationTimingGOOGLE(device.get(),
        swapchain.get(),
        &pPresentationTimingCount,
        reinterpret_cast<VkPastPresentationTimingGOOGLE*>(pPresentationTimings.data())));
    if (pPresentationTimingCount < pPresentationTimings.size()) pPresentationTimings.shrink(pPresentationTimingCount);
    return expected(std::move(pPresentationTimings), result);
}
void DeviceFunctions::CmdSetDiscardRectangleEXT(CommandBuffer commandBuffer, 
    uint32_t firstDiscardRectangle, 
    uint32_t discardRectangleCount, 
    const Rect2D* pDiscardRectangles) const {
    pfn_CmdSetDiscardRectangleEXT(commandBuffer.get(),
        firstDiscardRectangle,
        discardRectangleCount,
        reinterpret_cast<const VkRect2D*>(pDiscardRectangles));
}
void DeviceFunctions::SetHdrMetadataEXT(uint32_t swapchainCount, 
    const SwapchainKHR* pSwapchains, 
    const HdrMetadataEXT* pMetadata) const {
    pfn_SetHdrMetadataEXT(device.get(),
        swapchainCount,
        reinterpret_cast<const VkSwapchainKHR*>(pSwapchains),
        reinterpret_cast<const VkHdrMetadataEXT*>(pMetadata));
}
[[nodiscard]] Result DeviceFunctions::GetSwapchainStatusKHR(SwapchainKHR swapchain) const {
    return static_cast<Result>(pfn_GetSwapchainStatusKHR(device.get(),
        swapchain.get()));
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<HANDLE> DeviceFunctions::GetFenceWin32HandleKHR(const FenceGetWin32HandleInfoKHR&  pGetWin32HandleInfo) const {
    HANDLE pHandle;
    vk::Result result = static_cast<Result>(pfn_GetFenceWin32HandleKHR(device.get(),
        reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(&pGetWin32HandleInfo),
        reinterpret_cast<HANDLE*>(&pHandle)));
    return expected<HANDLE>(pHandle, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] Result DeviceFunctions::ImportFenceWin32HandleKHR(const ImportFenceWin32HandleInfoKHR&  pImportFenceWin32HandleInfo) const {
    return static_cast<Result>(pfn_ImportFenceWin32HandleKHR(device.get(),
        reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(&pImportFenceWin32HandleInfo)));
}
#endif // VK_USE_PLATFORM_WIN32_KHR
[[nodiscard]] expected<int> DeviceFunctions::GetFenceFdKHR(const FenceGetFdInfoKHR&  pGetFdInfo) const {
    int pFd;
    vk::Result result = static_cast<Result>(pfn_GetFenceFdKHR(device.get(),
        reinterpret_cast<const VkFenceGetFdInfoKHR*>(&pGetFdInfo),
        &pFd));
    return expected<int>(pFd, result);
}
[[nodiscard]] Result DeviceFunctions::ImportFenceFdKHR(const ImportFenceFdInfoKHR&  pImportFenceFdInfo) const {
    return static_cast<Result>(pfn_ImportFenceFdKHR(device.get(),
        reinterpret_cast<const VkImportFenceFdInfoKHR*>(&pImportFenceFdInfo)));
}
[[nodiscard]] Result DeviceFunctions::AcquireProfilingLockKHR(const AcquireProfilingLockInfoKHR&  pInfo) const {
    return static_cast<Result>(pfn_AcquireProfilingLockKHR(device.get(),
        reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(&pInfo)));
}
void DeviceFunctions::ReleaseProfilingLockKHR() const {
    pfn_ReleaseProfilingLockKHR(device.get());
}
[[nodiscard]] Result DeviceFunctions::SetDebugUtilsObjectNameEXT(const DebugUtilsObjectNameInfoEXT&  pNameInfo) const {
    return static_cast<Result>(pfn_SetDebugUtilsObjectNameEXT(device.get(),
        reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(&pNameInfo)));
}
[[nodiscard]] Result DeviceFunctions::SetDebugUtilsObjectTagEXT(const DebugUtilsObjectTagInfoEXT&  pTagInfo) const {
    return static_cast<Result>(pfn_SetDebugUtilsObjectTagEXT(device.get(),
        reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(&pTagInfo)));
}
void DeviceFunctions::QueueBeginDebugUtilsLabelEXT(Queue queue, 
    const DebugUtilsLabelEXT&  pLabelInfo) const {
    pfn_QueueBeginDebugUtilsLabelEXT(queue.get(),
        reinterpret_cast<const VkDebugUtilsLabelEXT*>(&pLabelInfo));
}
void DeviceFunctions::QueueEndDebugUtilsLabelEXT(Queue queue) const {
    pfn_QueueEndDebugUtilsLabelEXT(queue.get());
}
void DeviceFunctions::QueueInsertDebugUtilsLabelEXT(Queue queue, 
    const DebugUtilsLabelEXT&  pLabelInfo) const {
    pfn_QueueInsertDebugUtilsLabelEXT(queue.get(),
        reinterpret_cast<const VkDebugUtilsLabelEXT*>(&pLabelInfo));
}
void DeviceFunctions::CmdBeginDebugUtilsLabelEXT(CommandBuffer commandBuffer, 
    const DebugUtilsLabelEXT&  pLabelInfo) const {
    pfn_CmdBeginDebugUtilsLabelEXT(commandBuffer.get(),
        reinterpret_cast<const VkDebugUtilsLabelEXT*>(&pLabelInfo));
}
void DeviceFunctions::CmdEndDebugUtilsLabelEXT(CommandBuffer commandBuffer) const {
    pfn_CmdEndDebugUtilsLabelEXT(commandBuffer.get());
}
void DeviceFunctions::CmdInsertDebugUtilsLabelEXT(CommandBuffer commandBuffer, 
    const DebugUtilsLabelEXT&  pLabelInfo) const {
    pfn_CmdInsertDebugUtilsLabelEXT(commandBuffer.get(),
        reinterpret_cast<const VkDebugUtilsLabelEXT*>(&pLabelInfo));
}
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
[[nodiscard]] expected<AndroidHardwareBufferPropertiesANDROID> DeviceFunctions::GetAndroidHardwareBufferPropertiesANDROID(const AHardwareBuffer&  buffer) const {
    AndroidHardwareBufferPropertiesANDROID pProperties;
    vk::Result result = static_cast<Result>(pfn_GetAndroidHardwareBufferPropertiesANDROID(device.get(),
        &buffer,
        reinterpret_cast<VkAndroidHardwareBufferPropertiesANDROID*>(&pProperties)));
    return expected<AndroidHardwareBufferPropertiesANDROID>(pProperties, result);
}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
[[nodiscard]] expected<AHardwareBuffer*> DeviceFunctions::GetMemoryAndroidHardwareBufferANDROID(const MemoryGetAndroidHardwareBufferInfoANDROID&  pInfo) const {
    AHardwareBuffer* pBuffer;
    vk::Result result = static_cast<Result>(pfn_GetMemoryAndroidHardwareBufferANDROID(device.get(),
        reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(&pInfo),
        &pBuffer));
    return expected<AHardwareBuffer*>(pBuffer, result);
}
#endif // VK_USE_PLATFORM_ANDROID_KHR
void DeviceFunctions::CmdSetSampleLocationsEXT(CommandBuffer commandBuffer, 
    const SampleLocationsInfoEXT&  pSampleLocationsInfo) const {
    pfn_CmdSetSampleLocationsEXT(commandBuffer.get(),
        reinterpret_cast<const VkSampleLocationsInfoEXT*>(&pSampleLocationsInfo));
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::DestroyAccelerationStructureKHR(AccelerationStructureKHR accelerationStructure, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyAccelerationStructureKHR(device.get(),
        accelerationStructure.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] MemoryRequirements2 DeviceFunctions::GetAccelerationStructureMemoryRequirementsKHR(const AccelerationStructureMemoryRequirementsInfoKHR&  pInfo) const {
    MemoryRequirements2 pMemoryRequirements;
    pfn_GetAccelerationStructureMemoryRequirementsKHR(device.get(),
        reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoKHR*>(&pInfo),
        reinterpret_cast<VkMemoryRequirements2*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::BindAccelerationStructureMemoryKHR(uint32_t bindInfoCount, 
    const BindAccelerationStructureMemoryInfoKHR* pBindInfos) const {
    return static_cast<Result>(pfn_BindAccelerationStructureMemoryKHR(device.get(),
        bindInfoCount,
        reinterpret_cast<const VkBindAccelerationStructureMemoryInfoKHR*>(pBindInfos)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdCopyAccelerationStructureKHR(CommandBuffer commandBuffer, 
    const CopyAccelerationStructureInfoKHR&  pInfo) const {
    pfn_CmdCopyAccelerationStructureKHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(&pInfo));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::CopyAccelerationStructureKHR(const CopyAccelerationStructureInfoKHR&  pInfo) const {
    return static_cast<Result>(pfn_CopyAccelerationStructureKHR(device.get(),
        reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(&pInfo)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdCopyAccelerationStructureToMemoryKHR(CommandBuffer commandBuffer, 
    const CopyAccelerationStructureToMemoryInfoKHR&  pInfo) const {
    pfn_CmdCopyAccelerationStructureToMemoryKHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(&pInfo));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::CopyAccelerationStructureToMemoryKHR(const CopyAccelerationStructureToMemoryInfoKHR&  pInfo) const {
    return static_cast<Result>(pfn_CopyAccelerationStructureToMemoryKHR(device.get(),
        reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(&pInfo)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdCopyMemoryToAccelerationStructureKHR(CommandBuffer commandBuffer, 
    const CopyMemoryToAccelerationStructureInfoKHR&  pInfo) const {
    pfn_CmdCopyMemoryToAccelerationStructureKHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(&pInfo));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::CopyMemoryToAccelerationStructureKHR(const CopyMemoryToAccelerationStructureInfoKHR&  pInfo) const {
    return static_cast<Result>(pfn_CopyMemoryToAccelerationStructureKHR(device.get(),
        reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(&pInfo)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdWriteAccelerationStructuresPropertiesKHR(CommandBuffer commandBuffer, 
    uint32_t accelerationStructureCount, 
    const AccelerationStructureKHR* pAccelerationStructures, 
    QueryType queryType, 
    QueryPool queryPool, 
    uint32_t firstQuery) const {
    pfn_CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer.get(),
        accelerationStructureCount,
        reinterpret_cast<const VkAccelerationStructureKHR*>(pAccelerationStructures),
        static_cast<VkQueryType>(queryType),
        queryPool.get(),
        firstQuery);
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::WriteAccelerationStructuresPropertiesKHR(uint32_t accelerationStructureCount, 
    const AccelerationStructureKHR* pAccelerationStructures, 
    QueryType queryType, 
    size_t dataSize, 
    void* pData, 
    size_t stride) const {
    return static_cast<Result>(pfn_WriteAccelerationStructuresPropertiesKHR(device.get(),
        accelerationStructureCount,
        reinterpret_cast<const VkAccelerationStructureKHR*>(pAccelerationStructures),
        static_cast<VkQueryType>(queryType),
        dataSize,
        reinterpret_cast<void*>(pData),
        stride));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdTraceRaysKHR(CommandBuffer commandBuffer, 
    const StridedBufferRegionKHR&  pRaygenShaderBindingTable, 
    const StridedBufferRegionKHR&  pMissShaderBindingTable, 
    const StridedBufferRegionKHR&  pHitShaderBindingTable, 
    const StridedBufferRegionKHR&  pCallableShaderBindingTable, 
    uint32_t width, 
    uint32_t height, 
    uint32_t depth) const {
    pfn_CmdTraceRaysKHR(commandBuffer.get(),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pRaygenShaderBindingTable),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pMissShaderBindingTable),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pHitShaderBindingTable),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pCallableShaderBindingTable),
        width,
        height,
        depth);
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::GetRayTracingShaderGroupHandlesKHR(Pipeline pipeline, 
    uint32_t firstGroup, 
    uint32_t groupCount, 
    size_t dataSize, 
    void* pData) const {
    return static_cast<Result>(pfn_GetRayTracingShaderGroupHandlesKHR(device.get(),
        pipeline.get(),
        firstGroup,
        groupCount,
        dataSize,
        reinterpret_cast<void*>(pData)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::GetRayTracingCaptureReplayShaderGroupHandlesKHR(Pipeline pipeline, 
    uint32_t firstGroup, 
    uint32_t groupCount, 
    size_t dataSize, 
    void* pData) const {
    return static_cast<Result>(pfn_GetRayTracingCaptureReplayShaderGroupHandlesKHR(device.get(),
        pipeline.get(),
        firstGroup,
        groupCount,
        dataSize,
        reinterpret_cast<void*>(pData)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::CreateRayTracingPipelinesKHR(PipelineCache pipelineCache, 
    uint32_t createInfoCount, 
    const RayTracingPipelineCreateInfoKHR* pCreateInfos, 
    const AllocationCallbacks* pAllocator, 
    Pipeline* pPipelines) const {
    return static_cast<Result>(pfn_CreateRayTracingPipelinesKHR(device.get(),
        pipelineCache.get(),
        createInfoCount,
        reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipeline*>(pPipelines)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdTraceRaysIndirectKHR(CommandBuffer commandBuffer, 
    const StridedBufferRegionKHR&  pRaygenShaderBindingTable, 
    const StridedBufferRegionKHR&  pMissShaderBindingTable, 
    const StridedBufferRegionKHR&  pHitShaderBindingTable, 
    const StridedBufferRegionKHR&  pCallableShaderBindingTable, 
    Buffer buffer, 
    DeviceSize offset) const {
    pfn_CmdTraceRaysIndirectKHR(commandBuffer.get(),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pRaygenShaderBindingTable),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pMissShaderBindingTable),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pHitShaderBindingTable),
        reinterpret_cast<const VkStridedBufferRegionKHR*>(&pCallableShaderBindingTable),
        buffer.get(),
        offset);
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::GetDeviceAccelerationStructureCompatibilityKHR(const AccelerationStructureVersionKHR&  version) const {
    return static_cast<Result>(pfn_GetDeviceAccelerationStructureCompatibilityKHR(device.get(),
        reinterpret_cast<const VkAccelerationStructureVersionKHR*>(&version)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] expected<AccelerationStructureKHR> DeviceFunctions::CreateAccelerationStructureKHR(const AccelerationStructureCreateInfoKHR&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    AccelerationStructureKHR pAccelerationStructure;
    vk::Result result = static_cast<Result>(pfn_CreateAccelerationStructureKHR(device.get(),
        reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkAccelerationStructureKHR*>(&pAccelerationStructure)));
    return expected<AccelerationStructureKHR>(pAccelerationStructure, result);
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdBuildAccelerationStructureKHR(CommandBuffer commandBuffer, 
    uint32_t infoCount, 
    const AccelerationStructureBuildGeometryInfoKHR* pInfos, 
    const AccelerationStructureBuildOffsetInfoKHR* const* ppOffsetInfos) const {
    pfn_CmdBuildAccelerationStructureKHR(commandBuffer.get(),
        infoCount,
        reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(pInfos),
        reinterpret_cast<const VkAccelerationStructureBuildOffsetInfoKHR* const*>(ppOffsetInfos));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::CmdBuildAccelerationStructureIndirectKHR(CommandBuffer commandBuffer, 
    const AccelerationStructureBuildGeometryInfoKHR&  pInfo, 
    Buffer indirectBuffer, 
    DeviceSize indirectOffset, 
    uint32_t indirectStride) const {
    pfn_CmdBuildAccelerationStructureIndirectKHR(commandBuffer.get(),
        reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(&pInfo),
        indirectBuffer.get(),
        indirectOffset,
        indirectStride);
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::BuildAccelerationStructureKHR(uint32_t infoCount, 
    const AccelerationStructureBuildGeometryInfoKHR* pInfos, 
    const AccelerationStructureBuildOffsetInfoKHR* const* ppOffsetInfos) const {
    return static_cast<Result>(pfn_BuildAccelerationStructureKHR(device.get(),
        infoCount,
        reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(pInfos),
        reinterpret_cast<const VkAccelerationStructureBuildOffsetInfoKHR* const*>(ppOffsetInfos)));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] VkDeviceAddress DeviceFunctions::GetAccelerationStructureDeviceAddressKHR(const AccelerationStructureDeviceAddressInfoKHR&  pInfo) const {
    return pfn_GetAccelerationStructureDeviceAddressKHR(device.get(),
        reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(&pInfo));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
[[nodiscard]] expected<ImageDrmFormatModifierPropertiesEXT> DeviceFunctions::GetImageDrmFormatModifierPropertiesEXT(Image image) const {
    ImageDrmFormatModifierPropertiesEXT pProperties;
    vk::Result result = static_cast<Result>(pfn_GetImageDrmFormatModifierPropertiesEXT(device.get(),
        image.get(),
        reinterpret_cast<VkImageDrmFormatModifierPropertiesEXT*>(&pProperties)));
    return expected<ImageDrmFormatModifierPropertiesEXT>(pProperties, result);
}
[[nodiscard]] expected<ValidationCacheEXT> DeviceFunctions::CreateValidationCacheEXT(const ValidationCacheCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    ValidationCacheEXT pValidationCache;
    vk::Result result = static_cast<Result>(pfn_CreateValidationCacheEXT(device.get(),
        reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkValidationCacheEXT*>(&pValidationCache)));
    return expected<ValidationCacheEXT>(pValidationCache, result);
}
void DeviceFunctions::DestroyValidationCacheEXT(ValidationCacheEXT validationCache, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyValidationCacheEXT(device.get(),
        validationCache.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<detail::fixed_vector<void*>> DeviceFunctions::GetValidationCacheDataEXT(ValidationCacheEXT validationCache) const {
    size_t pDataSize = 0;
    vk::Result result = static_cast<Result>(pfn_GetValidationCacheDataEXT(device.get(),
        validationCache.get(),
        &pDataSize,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<void*>{}, result);
    detail::fixed_vector<void*> pData{pDataSize};
    result = static_cast<Result>(pfn_GetValidationCacheDataEXT(device.get(),
        validationCache.get(),
        &pDataSize,
        reinterpret_cast<void*>(pData.data())));
    if (pDataSize < pData.size()) pData.shrink(pDataSize);
    return expected(std::move(pData), result);
}
[[nodiscard]] Result DeviceFunctions::MergeValidationCachesEXT(ValidationCacheEXT dstCache, 
    uint32_t srcCacheCount, 
    const ValidationCacheEXT* pSrcCaches) const {
    return static_cast<Result>(pfn_MergeValidationCachesEXT(device.get(),
        dstCache.get(),
        srcCacheCount,
        reinterpret_cast<const VkValidationCacheEXT*>(pSrcCaches)));
}
void DeviceFunctions::CmdBindShadingRateImageNV(CommandBuffer commandBuffer, 
    ImageView imageView, 
    ImageLayout imageLayout) const {
    pfn_CmdBindShadingRateImageNV(commandBuffer.get(),
        imageView.get(),
        static_cast<VkImageLayout>(imageLayout));
}
void DeviceFunctions::CmdSetViewportShadingRatePaletteNV(CommandBuffer commandBuffer, 
    uint32_t firstViewport, 
    uint32_t viewportCount, 
    const ShadingRatePaletteNV* pShadingRatePalettes) const {
    pfn_CmdSetViewportShadingRatePaletteNV(commandBuffer.get(),
        firstViewport,
        viewportCount,
        reinterpret_cast<const VkShadingRatePaletteNV*>(pShadingRatePalettes));
}
void DeviceFunctions::CmdSetCoarseSampleOrderNV(CommandBuffer commandBuffer, 
    CoarseSampleOrderTypeNV sampleOrderType, 
    uint32_t customSampleOrderCount, 
    const CoarseSampleOrderCustomNV* pCustomSampleOrders) const {
    pfn_CmdSetCoarseSampleOrderNV(commandBuffer.get(),
        static_cast<VkCoarseSampleOrderTypeNV>(sampleOrderType),
        customSampleOrderCount,
        reinterpret_cast<const VkCoarseSampleOrderCustomNV*>(pCustomSampleOrders));
}
[[nodiscard]] Result DeviceFunctions::CompileDeferredNV(Pipeline pipeline, 
    uint32_t shader) const {
    return static_cast<Result>(pfn_CompileDeferredNV(device.get(),
        pipeline.get(),
        shader));
}
[[nodiscard]] expected<AccelerationStructureNV> DeviceFunctions::CreateAccelerationStructureNV(const AccelerationStructureCreateInfoNV&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    AccelerationStructureNV pAccelerationStructure;
    vk::Result result = static_cast<Result>(pfn_CreateAccelerationStructureNV(device.get(),
        reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkAccelerationStructureNV*>(&pAccelerationStructure)));
    return expected<AccelerationStructureNV>(pAccelerationStructure, result);
}
[[nodiscard]] MemoryRequirements2KHR DeviceFunctions::GetAccelerationStructureMemoryRequirementsNV(const AccelerationStructureMemoryRequirementsInfoNV&  pInfo) const {
    MemoryRequirements2KHR pMemoryRequirements;
    pfn_GetAccelerationStructureMemoryRequirementsNV(device.get(),
        reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(&pInfo),
        reinterpret_cast<VkMemoryRequirements2KHR*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
void DeviceFunctions::CmdCopyAccelerationStructureNV(CommandBuffer commandBuffer, 
    AccelerationStructureKHR dst, 
    AccelerationStructureKHR src, 
    CopyAccelerationStructureModeKHR mode) const {
    pfn_CmdCopyAccelerationStructureNV(commandBuffer.get(),
        dst.get(),
        src.get(),
        static_cast<VkCopyAccelerationStructureModeKHR>(mode));
}
void DeviceFunctions::CmdBuildAccelerationStructureNV(CommandBuffer commandBuffer, 
    const AccelerationStructureInfoNV&  pInfo, 
    Buffer instanceData, 
    DeviceSize instanceOffset, 
    Bool32 update, 
    AccelerationStructureKHR dst, 
    AccelerationStructureKHR src, 
    Buffer scratch, 
    DeviceSize scratchOffset) const {
    pfn_CmdBuildAccelerationStructureNV(commandBuffer.get(),
        reinterpret_cast<const VkAccelerationStructureInfoNV*>(&pInfo),
        instanceData.get(),
        instanceOffset,
        update,
        dst.get(),
        src.get(),
        scratch.get(),
        scratchOffset);
}
void DeviceFunctions::CmdTraceRaysNV(CommandBuffer commandBuffer, 
    Buffer raygenShaderBindingTableBuffer, 
    DeviceSize raygenShaderBindingOffset, 
    Buffer missShaderBindingTableBuffer, 
    DeviceSize missShaderBindingOffset, 
    DeviceSize missShaderBindingStride, 
    Buffer hitShaderBindingTableBuffer, 
    DeviceSize hitShaderBindingOffset, 
    DeviceSize hitShaderBindingStride, 
    Buffer callableShaderBindingTableBuffer, 
    DeviceSize callableShaderBindingOffset, 
    DeviceSize callableShaderBindingStride, 
    uint32_t width, 
    uint32_t height, 
    uint32_t depth) const {
    pfn_CmdTraceRaysNV(commandBuffer.get(),
        raygenShaderBindingTableBuffer.get(),
        raygenShaderBindingOffset,
        missShaderBindingTableBuffer.get(),
        missShaderBindingOffset,
        missShaderBindingStride,
        hitShaderBindingTableBuffer.get(),
        hitShaderBindingOffset,
        hitShaderBindingStride,
        callableShaderBindingTableBuffer.get(),
        callableShaderBindingOffset,
        callableShaderBindingStride,
        width,
        height,
        depth);
}
[[nodiscard]] Result DeviceFunctions::GetAccelerationStructureHandleNV(AccelerationStructureKHR accelerationStructure, 
    size_t dataSize, 
    void* pData) const {
    return static_cast<Result>(pfn_GetAccelerationStructureHandleNV(device.get(),
        accelerationStructure.get(),
        dataSize,
        reinterpret_cast<void*>(pData)));
}
[[nodiscard]] Result DeviceFunctions::CreateRayTracingPipelinesNV(PipelineCache pipelineCache, 
    uint32_t createInfoCount, 
    const RayTracingPipelineCreateInfoNV* pCreateInfos, 
    const AllocationCallbacks* pAllocator, 
    Pipeline* pPipelines) const {
    return static_cast<Result>(pfn_CreateRayTracingPipelinesNV(device.get(),
        pipelineCache.get(),
        createInfoCount,
        reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipeline*>(pPipelines)));
}
[[nodiscard]] expected<MemoryHostPointerPropertiesEXT> DeviceFunctions::GetMemoryHostPointerPropertiesEXT(ExternalMemoryHandleTypeFlagBits handleType, 
    const void* pHostPointer) const {
    MemoryHostPointerPropertiesEXT pMemoryHostPointerProperties;
    vk::Result result = static_cast<Result>(pfn_GetMemoryHostPointerPropertiesEXT(device.get(),
        static_cast<VkExternalMemoryHandleTypeFlagBits>(handleType),
        reinterpret_cast<const void*>(pHostPointer),
        reinterpret_cast<VkMemoryHostPointerPropertiesEXT*>(&pMemoryHostPointerProperties)));
    return expected<MemoryHostPointerPropertiesEXT>(pMemoryHostPointerProperties, result);
}
void DeviceFunctions::CmdWriteBufferMarkerAMD(CommandBuffer commandBuffer, 
    PipelineStageFlagBits pipelineStage, 
    Buffer dstBuffer, 
    DeviceSize dstOffset, 
    uint32_t marker) const {
    pfn_CmdWriteBufferMarkerAMD(commandBuffer.get(),
        static_cast<VkPipelineStageFlagBits>(pipelineStage),
        dstBuffer.get(),
        dstOffset,
        marker);
}
[[nodiscard]] expected<uint64_t> DeviceFunctions::GetCalibratedTimestampsEXT(uint32_t timestampCount, 
    const CalibratedTimestampInfoEXT* pTimestampInfos, 
    uint64_t* pTimestamps) const {
    uint64_t pMaxDeviation;
    vk::Result result = static_cast<Result>(pfn_GetCalibratedTimestampsEXT(device.get(),
        timestampCount,
        reinterpret_cast<const VkCalibratedTimestampInfoEXT*>(pTimestampInfos),
        pTimestamps,
        &pMaxDeviation));
    return expected<uint64_t>(pMaxDeviation, result);
}
void DeviceFunctions::CmdDrawMeshTasksNV(CommandBuffer commandBuffer, 
    uint32_t taskCount, 
    uint32_t firstTask) const {
    pfn_CmdDrawMeshTasksNV(commandBuffer.get(),
        taskCount,
        firstTask);
}
void DeviceFunctions::CmdDrawMeshTasksIndirectNV(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    uint32_t drawCount, 
    uint32_t stride) const {
    pfn_CmdDrawMeshTasksIndirectNV(commandBuffer.get(),
        buffer.get(),
        offset,
        drawCount,
        stride);
}
void DeviceFunctions::CmdDrawMeshTasksIndirectCountNV(CommandBuffer commandBuffer, 
    Buffer buffer, 
    DeviceSize offset, 
    Buffer countBuffer, 
    DeviceSize countBufferOffset, 
    uint32_t maxDrawCount, 
    uint32_t stride) const {
    pfn_CmdDrawMeshTasksIndirectCountNV(commandBuffer.get(),
        buffer.get(),
        offset,
        countBuffer.get(),
        countBufferOffset,
        maxDrawCount,
        stride);
}
void DeviceFunctions::CmdSetExclusiveScissorNV(CommandBuffer commandBuffer, 
    uint32_t firstExclusiveScissor, 
    uint32_t exclusiveScissorCount, 
    const Rect2D* pExclusiveScissors) const {
    pfn_CmdSetExclusiveScissorNV(commandBuffer.get(),
        firstExclusiveScissor,
        exclusiveScissorCount,
        reinterpret_cast<const VkRect2D*>(pExclusiveScissors));
}
void DeviceFunctions::CmdSetCheckpointNV(CommandBuffer commandBuffer, 
    const void* pCheckpointMarker) const {
    pfn_CmdSetCheckpointNV(commandBuffer.get(),
        reinterpret_cast<const void*>(pCheckpointMarker));
}
[[nodiscard]] detail::fixed_vector<CheckpointDataNV> DeviceFunctions::GetQueueCheckpointDataNV(Queue queue) const {
    uint32_t pCheckpointDataCount = 0;
    pfn_GetQueueCheckpointDataNV(queue.get(),
        &pCheckpointDataCount,
        nullptr);
    detail::fixed_vector<CheckpointDataNV> pCheckpointData{pCheckpointDataCount};
    pfn_GetQueueCheckpointDataNV(queue.get(),
        &pCheckpointDataCount,
        reinterpret_cast<VkCheckpointDataNV*>(pCheckpointData.data()));
    if (pCheckpointDataCount < pCheckpointData.size()) pCheckpointData.shrink(pCheckpointDataCount);
    return pCheckpointData;
}
[[nodiscard]] Result DeviceFunctions::InitializePerformanceApiINTEL(const InitializePerformanceApiInfoINTEL&  pInitializeInfo) const {
    return static_cast<Result>(pfn_InitializePerformanceApiINTEL(device.get(),
        reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(&pInitializeInfo)));
}
void DeviceFunctions::UninitializePerformanceApiINTEL() const {
    pfn_UninitializePerformanceApiINTEL(device.get());
}
[[nodiscard]] Result DeviceFunctions::CmdSetPerformanceMarkerINTEL(CommandBuffer commandBuffer, 
    const PerformanceMarkerInfoINTEL&  pMarkerInfo) const {
    return static_cast<Result>(pfn_CmdSetPerformanceMarkerINTEL(commandBuffer.get(),
        reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(&pMarkerInfo)));
}
[[nodiscard]] Result DeviceFunctions::CmdSetPerformanceStreamMarkerINTEL(CommandBuffer commandBuffer, 
    const PerformanceStreamMarkerInfoINTEL&  pMarkerInfo) const {
    return static_cast<Result>(pfn_CmdSetPerformanceStreamMarkerINTEL(commandBuffer.get(),
        reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(&pMarkerInfo)));
}
[[nodiscard]] Result DeviceFunctions::CmdSetPerformanceOverrideINTEL(CommandBuffer commandBuffer, 
    const PerformanceOverrideInfoINTEL&  pOverrideInfo) const {
    return static_cast<Result>(pfn_CmdSetPerformanceOverrideINTEL(commandBuffer.get(),
        reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(&pOverrideInfo)));
}
[[nodiscard]] expected<PerformanceConfigurationINTEL> DeviceFunctions::AcquirePerformanceConfigurationINTEL(const PerformanceConfigurationAcquireInfoINTEL&  pAcquireInfo) const {
    PerformanceConfigurationINTEL pConfiguration;
    vk::Result result = static_cast<Result>(pfn_AcquirePerformanceConfigurationINTEL(device.get(),
        reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(&pAcquireInfo),
        reinterpret_cast<VkPerformanceConfigurationINTEL*>(&pConfiguration)));
    return expected<PerformanceConfigurationINTEL>(pConfiguration, result);
}
[[nodiscard]] Result DeviceFunctions::ReleasePerformanceConfigurationINTEL(PerformanceConfigurationINTEL configuration) const {
    return static_cast<Result>(pfn_ReleasePerformanceConfigurationINTEL(device.get(),
        configuration.get()));
}
[[nodiscard]] Result DeviceFunctions::QueueSetPerformanceConfigurationINTEL(Queue queue, 
    PerformanceConfigurationINTEL configuration) const {
    return static_cast<Result>(pfn_QueueSetPerformanceConfigurationINTEL(queue.get(),
        configuration.get()));
}
[[nodiscard]] expected<PerformanceValueINTEL> DeviceFunctions::GetPerformanceParameterINTEL(PerformanceParameterTypeINTEL parameter) const {
    PerformanceValueINTEL pValue;
    vk::Result result = static_cast<Result>(pfn_GetPerformanceParameterINTEL(device.get(),
        static_cast<VkPerformanceParameterTypeINTEL>(parameter),
        reinterpret_cast<VkPerformanceValueINTEL*>(&pValue)));
    return expected<PerformanceValueINTEL>(pValue, result);
}
void DeviceFunctions::SetLocalDimmingAMD(SwapchainKHR swapChain, 
    Bool32 localDimmingEnable) const {
    pfn_SetLocalDimmingAMD(device.get(),
        swapChain.get(),
        localDimmingEnable);
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] Result DeviceFunctions::AcquireFullScreenExclusiveModeEXT(SwapchainKHR swapchain) const {
    return static_cast<Result>(pfn_AcquireFullScreenExclusiveModeEXT(device.get(),
        swapchain.get()));
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] Result DeviceFunctions::ReleaseFullScreenExclusiveModeEXT(SwapchainKHR swapchain) const {
    return static_cast<Result>(pfn_ReleaseFullScreenExclusiveModeEXT(device.get(),
        swapchain.get()));
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<DeviceGroupPresentModeFlagsKHR> DeviceFunctions::GetDeviceGroupSurfacePresentModes2EXT(const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    DeviceGroupPresentModeFlagsKHR pModes;
    vk::Result result = static_cast<Result>(pfn_GetDeviceGroupSurfacePresentModes2EXT(device.get(),
        reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(&pSurfaceInfo),
        reinterpret_cast<VkDeviceGroupPresentModeFlagsKHR*>(&pModes)));
    return expected<DeviceGroupPresentModeFlagsKHR>(pModes, result);
}
#endif // VK_USE_PLATFORM_WIN32_KHR
void DeviceFunctions::CmdSetLineStippleEXT(CommandBuffer commandBuffer, 
    uint32_t lineStippleFactor, 
    uint16_t lineStipplePattern) const {
    pfn_CmdSetLineStippleEXT(commandBuffer.get(),
        lineStippleFactor,
        lineStipplePattern);
}
void DeviceFunctions::CmdSetCullModeEXT(CommandBuffer commandBuffer, 
    CullModeFlags cullMode) const {
    pfn_CmdSetCullModeEXT(commandBuffer.get(),
        static_cast<VkCullModeFlags>(cullMode));
}
void DeviceFunctions::CmdSetFrontFaceEXT(CommandBuffer commandBuffer, 
    FrontFace frontFace) const {
    pfn_CmdSetFrontFaceEXT(commandBuffer.get(),
        static_cast<VkFrontFace>(frontFace));
}
void DeviceFunctions::CmdSetPrimitiveTopologyEXT(CommandBuffer commandBuffer, 
    PrimitiveTopology primitiveTopology) const {
    pfn_CmdSetPrimitiveTopologyEXT(commandBuffer.get(),
        static_cast<VkPrimitiveTopology>(primitiveTopology));
}
void DeviceFunctions::CmdSetViewportWithCountEXT(CommandBuffer commandBuffer, 
    uint32_t viewportCount, 
    const Viewport* pViewports) const {
    pfn_CmdSetViewportWithCountEXT(commandBuffer.get(),
        viewportCount,
        reinterpret_cast<const VkViewport*>(pViewports));
}
void DeviceFunctions::CmdSetScissorWithCountEXT(CommandBuffer commandBuffer, 
    uint32_t scissorCount, 
    const Rect2D* pScissors) const {
    pfn_CmdSetScissorWithCountEXT(commandBuffer.get(),
        scissorCount,
        reinterpret_cast<const VkRect2D*>(pScissors));
}
void DeviceFunctions::CmdBindVertexBuffers2EXT(CommandBuffer commandBuffer, 
    uint32_t firstBinding, 
    uint32_t bindingCount, 
    const Buffer* pBuffers, 
    const DeviceSize* pOffsets, 
    const DeviceSize* pSizes, 
    const DeviceSize* pStrides) const {
    pfn_CmdBindVertexBuffers2EXT(commandBuffer.get(),
        firstBinding,
        bindingCount,
        reinterpret_cast<const VkBuffer*>(pBuffers),
        pOffsets,
        pSizes,
        pStrides);
}
void DeviceFunctions::CmdSetDepthTestEnableEXT(CommandBuffer commandBuffer, 
    Bool32 depthTestEnable) const {
    pfn_CmdSetDepthTestEnableEXT(commandBuffer.get(),
        depthTestEnable);
}
void DeviceFunctions::CmdSetDepthWriteEnableEXT(CommandBuffer commandBuffer, 
    Bool32 depthWriteEnable) const {
    pfn_CmdSetDepthWriteEnableEXT(commandBuffer.get(),
        depthWriteEnable);
}
void DeviceFunctions::CmdSetDepthCompareOpEXT(CommandBuffer commandBuffer, 
    CompareOp depthCompareOp) const {
    pfn_CmdSetDepthCompareOpEXT(commandBuffer.get(),
        static_cast<VkCompareOp>(depthCompareOp));
}
void DeviceFunctions::CmdSetDepthBoundsTestEnableEXT(CommandBuffer commandBuffer, 
    Bool32 depthBoundsTestEnable) const {
    pfn_CmdSetDepthBoundsTestEnableEXT(commandBuffer.get(),
        depthBoundsTestEnable);
}
void DeviceFunctions::CmdSetStencilTestEnableEXT(CommandBuffer commandBuffer, 
    Bool32 stencilTestEnable) const {
    pfn_CmdSetStencilTestEnableEXT(commandBuffer.get(),
        stencilTestEnable);
}
void DeviceFunctions::CmdSetStencilOpEXT(CommandBuffer commandBuffer, 
    StencilFaceFlags faceMask, 
    StencilOp failOp, 
    StencilOp passOp, 
    StencilOp depthFailOp, 
    CompareOp compareOp) const {
    pfn_CmdSetStencilOpEXT(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        static_cast<VkStencilOp>(failOp),
        static_cast<VkStencilOp>(passOp),
        static_cast<VkStencilOp>(depthFailOp),
        static_cast<VkCompareOp>(compareOp));
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] expected<DeferredOperationKHR> DeviceFunctions::CreateDeferredOperationKHR(const AllocationCallbacks* pAllocator) const {
    DeferredOperationKHR pDeferredOperation;
    vk::Result result = static_cast<Result>(pfn_CreateDeferredOperationKHR(device.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDeferredOperationKHR*>(&pDeferredOperation)));
    return expected<DeferredOperationKHR>(pDeferredOperation, result);
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void DeviceFunctions::DestroyDeferredOperationKHR(DeferredOperationKHR operation, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyDeferredOperationKHR(device.get(),
        operation.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] uint32_t DeviceFunctions::GetDeferredOperationMaxConcurrencyKHR(DeferredOperationKHR operation) const {
    return pfn_GetDeferredOperationMaxConcurrencyKHR(device.get(),
        operation.get());
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::GetDeferredOperationResultKHR(DeferredOperationKHR operation) const {
    return static_cast<Result>(pfn_GetDeferredOperationResultKHR(device.get(),
        operation.get()));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result DeviceFunctions::DeferredOperationJoinKHR(DeferredOperationKHR operation) const {
    return static_cast<Result>(pfn_DeferredOperationJoinKHR(device.get(),
        operation.get()));
}
#endif // VK_ENABLE_BETA_EXTENSIONS
[[nodiscard]] expected<detail::fixed_vector<PipelineExecutablePropertiesKHR>> DeviceFunctions::GetPipelineExecutablePropertiesKHR(const PipelineInfoKHR&  pPipelineInfo) const {
    uint32_t pExecutableCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPipelineExecutablePropertiesKHR(device.get(),
        reinterpret_cast<const VkPipelineInfoKHR*>(&pPipelineInfo),
        &pExecutableCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PipelineExecutablePropertiesKHR>{}, result);
    detail::fixed_vector<PipelineExecutablePropertiesKHR> pProperties{pExecutableCount};
    result = static_cast<Result>(pfn_GetPipelineExecutablePropertiesKHR(device.get(),
        reinterpret_cast<const VkPipelineInfoKHR*>(&pPipelineInfo),
        &pExecutableCount,
        reinterpret_cast<VkPipelineExecutablePropertiesKHR*>(pProperties.data())));
    if (pExecutableCount < pProperties.size()) pProperties.shrink(pExecutableCount);
    return expected(std::move(pProperties), result);
}
[[nodiscard]] expected<detail::fixed_vector<PipelineExecutableStatisticKHR>> DeviceFunctions::GetPipelineExecutableStatisticsKHR(const PipelineExecutableInfoKHR&  pExecutableInfo) const {
    uint32_t pStatisticCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPipelineExecutableStatisticsKHR(device.get(),
        reinterpret_cast<const VkPipelineExecutableInfoKHR*>(&pExecutableInfo),
        &pStatisticCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PipelineExecutableStatisticKHR>{}, result);
    detail::fixed_vector<PipelineExecutableStatisticKHR> pStatistics{pStatisticCount};
    result = static_cast<Result>(pfn_GetPipelineExecutableStatisticsKHR(device.get(),
        reinterpret_cast<const VkPipelineExecutableInfoKHR*>(&pExecutableInfo),
        &pStatisticCount,
        reinterpret_cast<VkPipelineExecutableStatisticKHR*>(pStatistics.data())));
    if (pStatisticCount < pStatistics.size()) pStatistics.shrink(pStatisticCount);
    return expected(std::move(pStatistics), result);
}
[[nodiscard]] expected<detail::fixed_vector<PipelineExecutableInternalRepresentationKHR>> DeviceFunctions::GetPipelineExecutableInternalRepresentationsKHR(const PipelineExecutableInfoKHR&  pExecutableInfo) const {
    uint32_t pInternalRepresentationCount = 0;
    vk::Result result = static_cast<Result>(pfn_GetPipelineExecutableInternalRepresentationsKHR(device.get(),
        reinterpret_cast<const VkPipelineExecutableInfoKHR*>(&pExecutableInfo),
        &pInternalRepresentationCount,
        nullptr));
    if (result < Result::Success) return expected(detail::fixed_vector<PipelineExecutableInternalRepresentationKHR>{}, result);
    detail::fixed_vector<PipelineExecutableInternalRepresentationKHR> pInternalRepresentations{pInternalRepresentationCount};
    result = static_cast<Result>(pfn_GetPipelineExecutableInternalRepresentationsKHR(device.get(),
        reinterpret_cast<const VkPipelineExecutableInfoKHR*>(&pExecutableInfo),
        &pInternalRepresentationCount,
        reinterpret_cast<VkPipelineExecutableInternalRepresentationKHR*>(pInternalRepresentations.data())));
    if (pInternalRepresentationCount < pInternalRepresentations.size()) pInternalRepresentations.shrink(pInternalRepresentationCount);
    return expected(std::move(pInternalRepresentations), result);
}
void DeviceFunctions::CmdExecuteGeneratedCommandsNV(CommandBuffer commandBuffer, 
    Bool32 isPreprocessed, 
    const GeneratedCommandsInfoNV&  pGeneratedCommandsInfo) const {
    pfn_CmdExecuteGeneratedCommandsNV(commandBuffer.get(),
        isPreprocessed,
        reinterpret_cast<const VkGeneratedCommandsInfoNV*>(&pGeneratedCommandsInfo));
}
void DeviceFunctions::CmdPreprocessGeneratedCommandsNV(CommandBuffer commandBuffer, 
    const GeneratedCommandsInfoNV&  pGeneratedCommandsInfo) const {
    pfn_CmdPreprocessGeneratedCommandsNV(commandBuffer.get(),
        reinterpret_cast<const VkGeneratedCommandsInfoNV*>(&pGeneratedCommandsInfo));
}
void DeviceFunctions::CmdBindPipelineShaderGroupNV(CommandBuffer commandBuffer, 
    PipelineBindPoint pipelineBindPoint, 
    Pipeline pipeline, 
    uint32_t groupIndex) const {
    pfn_CmdBindPipelineShaderGroupNV(commandBuffer.get(),
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        pipeline.get(),
        groupIndex);
}
[[nodiscard]] MemoryRequirements2 DeviceFunctions::GetGeneratedCommandsMemoryRequirementsNV(const GeneratedCommandsMemoryRequirementsInfoNV&  pInfo) const {
    MemoryRequirements2 pMemoryRequirements;
    pfn_GetGeneratedCommandsMemoryRequirementsNV(device.get(),
        reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(&pInfo),
        reinterpret_cast<VkMemoryRequirements2*>(&pMemoryRequirements));
    return pMemoryRequirements;
}
[[nodiscard]] expected<IndirectCommandsLayoutNV> DeviceFunctions::CreateIndirectCommandsLayoutNV(const IndirectCommandsLayoutCreateInfoNV&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    IndirectCommandsLayoutNV pIndirectCommandsLayout;
    vk::Result result = static_cast<Result>(pfn_CreateIndirectCommandsLayoutNV(device.get(),
        reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkIndirectCommandsLayoutNV*>(&pIndirectCommandsLayout)));
    return expected<IndirectCommandsLayoutNV>(pIndirectCommandsLayout, result);
}
void DeviceFunctions::DestroyIndirectCommandsLayoutNV(IndirectCommandsLayoutNV indirectCommandsLayout, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyIndirectCommandsLayoutNV(device.get(),
        indirectCommandsLayout.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] expected<PrivateDataSlotEXT> DeviceFunctions::CreatePrivateDataSlotEXT(const PrivateDataSlotCreateInfoEXT&  pCreateInfo, 
    const AllocationCallbacks* pAllocator) const {
    PrivateDataSlotEXT pPrivateDataSlot;
    vk::Result result = static_cast<Result>(pfn_CreatePrivateDataSlotEXT(device.get(),
        reinterpret_cast<const VkPrivateDataSlotCreateInfoEXT*>(&pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPrivateDataSlotEXT*>(&pPrivateDataSlot)));
    return expected<PrivateDataSlotEXT>(pPrivateDataSlot, result);
}
void DeviceFunctions::DestroyPrivateDataSlotEXT(PrivateDataSlotEXT privateDataSlot, 
    const AllocationCallbacks* pAllocator) const {
    pfn_DestroyPrivateDataSlotEXT(device.get(),
        privateDataSlot.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
[[nodiscard]] Result DeviceFunctions::SetPrivateDataEXT(ObjectType objectType, 
    uint64_t objectHandle, 
    PrivateDataSlotEXT privateDataSlot, 
    uint64_t data) const {
    return static_cast<Result>(pfn_SetPrivateDataEXT(device.get(),
        static_cast<VkObjectType>(objectType),
        objectHandle,
        privateDataSlot.get(),
        data));
}
[[nodiscard]] uint64_t DeviceFunctions::GetPrivateDataEXT(ObjectType objectType, 
    uint64_t objectHandle, 
    PrivateDataSlotEXT privateDataSlot) const {
    uint64_t pData;
    pfn_GetPrivateDataEXT(device.get(),
        static_cast<VkObjectType>(objectType),
        objectHandle,
        privateDataSlot.get(),
        &pData);
    return pData;
}
void DeviceFunctions::CmdCopyBuffer2KHR(CommandBuffer commandBuffer, 
    const CopyBufferInfo2KHR&  pCopyBufferInfo) const {
    pfn_CmdCopyBuffer2KHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyBufferInfo2KHR*>(&pCopyBufferInfo));
}
void DeviceFunctions::CmdCopyImage2KHR(CommandBuffer commandBuffer, 
    const CopyImageInfo2KHR&  pCopyImageInfo) const {
    pfn_CmdCopyImage2KHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyImageInfo2KHR*>(&pCopyImageInfo));
}
void DeviceFunctions::CmdBlitImage2KHR(CommandBuffer commandBuffer, 
    const BlitImageInfo2KHR&  pBlitImageInfo) const {
    pfn_CmdBlitImage2KHR(commandBuffer.get(),
        reinterpret_cast<const VkBlitImageInfo2KHR*>(&pBlitImageInfo));
}
void DeviceFunctions::CmdCopyBufferToImage2KHR(CommandBuffer commandBuffer, 
    const CopyBufferToImageInfo2KHR&  pCopyBufferToImageInfo) const {
    pfn_CmdCopyBufferToImage2KHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyBufferToImageInfo2KHR*>(&pCopyBufferToImageInfo));
}
void DeviceFunctions::CmdCopyImageToBuffer2KHR(CommandBuffer commandBuffer, 
    const CopyImageToBufferInfo2KHR&  pCopyImageToBufferInfo) const {
    pfn_CmdCopyImageToBuffer2KHR(commandBuffer.get(),
        reinterpret_cast<const VkCopyImageToBufferInfo2KHR*>(&pCopyImageToBufferInfo));
}
void DeviceFunctions::CmdResolveImage2KHR(CommandBuffer commandBuffer, 
    const ResolveImageInfo2KHR&  pResolveImageInfo) const {
    pfn_CmdResolveImage2KHR(commandBuffer.get(),
        reinterpret_cast<const VkResolveImageInfo2KHR*>(&pResolveImageInfo));
}
DeviceFunctions::DeviceFunctions() noexcept {}
DeviceFunctions::DeviceFunctions(InstanceFunctions const& instance_functions, Device device) noexcept 
    :device(device) {
    detail::PFN_vkGetDeviceProcAddr get_device_proc_addr = instance_functions.pfn_GetDeviceProcAddr;
    pfn_DestroyDevice = reinterpret_cast<detail::PFN_vkDestroyDevice>(get_device_proc_addr(device.get(),"vkDestroyDevice"));
    pfn_GetDeviceQueue = reinterpret_cast<detail::PFN_vkGetDeviceQueue>(get_device_proc_addr(device.get(),"vkGetDeviceQueue"));
    pfn_QueueSubmit = reinterpret_cast<detail::PFN_vkQueueSubmit>(get_device_proc_addr(device.get(),"vkQueueSubmit"));
    pfn_QueueWaitIdle = reinterpret_cast<detail::PFN_vkQueueWaitIdle>(get_device_proc_addr(device.get(),"vkQueueWaitIdle"));
    pfn_DeviceWaitIdle = reinterpret_cast<detail::PFN_vkDeviceWaitIdle>(get_device_proc_addr(device.get(),"vkDeviceWaitIdle"));
    pfn_AllocateMemory = reinterpret_cast<detail::PFN_vkAllocateMemory>(get_device_proc_addr(device.get(),"vkAllocateMemory"));
    pfn_FreeMemory = reinterpret_cast<detail::PFN_vkFreeMemory>(get_device_proc_addr(device.get(),"vkFreeMemory"));
    pfn_MapMemory = reinterpret_cast<detail::PFN_vkMapMemory>(get_device_proc_addr(device.get(),"vkMapMemory"));
    pfn_UnmapMemory = reinterpret_cast<detail::PFN_vkUnmapMemory>(get_device_proc_addr(device.get(),"vkUnmapMemory"));
    pfn_FlushMappedMemoryRanges = reinterpret_cast<detail::PFN_vkFlushMappedMemoryRanges>(get_device_proc_addr(device.get(),"vkFlushMappedMemoryRanges"));
    pfn_InvalidateMappedMemoryRanges = reinterpret_cast<detail::PFN_vkInvalidateMappedMemoryRanges>(get_device_proc_addr(device.get(),"vkInvalidateMappedMemoryRanges"));
    pfn_GetDeviceMemoryCommitment = reinterpret_cast<detail::PFN_vkGetDeviceMemoryCommitment>(get_device_proc_addr(device.get(),"vkGetDeviceMemoryCommitment"));
    pfn_GetBufferMemoryRequirements = reinterpret_cast<detail::PFN_vkGetBufferMemoryRequirements>(get_device_proc_addr(device.get(),"vkGetBufferMemoryRequirements"));
    pfn_BindBufferMemory = reinterpret_cast<detail::PFN_vkBindBufferMemory>(get_device_proc_addr(device.get(),"vkBindBufferMemory"));
    pfn_GetImageMemoryRequirements = reinterpret_cast<detail::PFN_vkGetImageMemoryRequirements>(get_device_proc_addr(device.get(),"vkGetImageMemoryRequirements"));
    pfn_BindImageMemory = reinterpret_cast<detail::PFN_vkBindImageMemory>(get_device_proc_addr(device.get(),"vkBindImageMemory"));
    pfn_GetImageSparseMemoryRequirements = reinterpret_cast<detail::PFN_vkGetImageSparseMemoryRequirements>(get_device_proc_addr(device.get(),"vkGetImageSparseMemoryRequirements"));
    pfn_QueueBindSparse = reinterpret_cast<detail::PFN_vkQueueBindSparse>(get_device_proc_addr(device.get(),"vkQueueBindSparse"));
    pfn_CreateFence = reinterpret_cast<detail::PFN_vkCreateFence>(get_device_proc_addr(device.get(),"vkCreateFence"));
    pfn_DestroyFence = reinterpret_cast<detail::PFN_vkDestroyFence>(get_device_proc_addr(device.get(),"vkDestroyFence"));
    pfn_ResetFences = reinterpret_cast<detail::PFN_vkResetFences>(get_device_proc_addr(device.get(),"vkResetFences"));
    pfn_GetFenceStatus = reinterpret_cast<detail::PFN_vkGetFenceStatus>(get_device_proc_addr(device.get(),"vkGetFenceStatus"));
    pfn_WaitForFences = reinterpret_cast<detail::PFN_vkWaitForFences>(get_device_proc_addr(device.get(),"vkWaitForFences"));
    pfn_CreateSemaphore = reinterpret_cast<detail::PFN_vkCreateSemaphore>(get_device_proc_addr(device.get(),"vkCreateSemaphore"));
    pfn_DestroySemaphore = reinterpret_cast<detail::PFN_vkDestroySemaphore>(get_device_proc_addr(device.get(),"vkDestroySemaphore"));
    pfn_CreateEvent = reinterpret_cast<detail::PFN_vkCreateEvent>(get_device_proc_addr(device.get(),"vkCreateEvent"));
    pfn_DestroyEvent = reinterpret_cast<detail::PFN_vkDestroyEvent>(get_device_proc_addr(device.get(),"vkDestroyEvent"));
    pfn_GetEventStatus = reinterpret_cast<detail::PFN_vkGetEventStatus>(get_device_proc_addr(device.get(),"vkGetEventStatus"));
    pfn_SetEvent = reinterpret_cast<detail::PFN_vkSetEvent>(get_device_proc_addr(device.get(),"vkSetEvent"));
    pfn_ResetEvent = reinterpret_cast<detail::PFN_vkResetEvent>(get_device_proc_addr(device.get(),"vkResetEvent"));
    pfn_CreateQueryPool = reinterpret_cast<detail::PFN_vkCreateQueryPool>(get_device_proc_addr(device.get(),"vkCreateQueryPool"));
    pfn_DestroyQueryPool = reinterpret_cast<detail::PFN_vkDestroyQueryPool>(get_device_proc_addr(device.get(),"vkDestroyQueryPool"));
    pfn_GetQueryPoolResults = reinterpret_cast<detail::PFN_vkGetQueryPoolResults>(get_device_proc_addr(device.get(),"vkGetQueryPoolResults"));
    pfn_CreateBuffer = reinterpret_cast<detail::PFN_vkCreateBuffer>(get_device_proc_addr(device.get(),"vkCreateBuffer"));
    pfn_DestroyBuffer = reinterpret_cast<detail::PFN_vkDestroyBuffer>(get_device_proc_addr(device.get(),"vkDestroyBuffer"));
    pfn_CreateBufferView = reinterpret_cast<detail::PFN_vkCreateBufferView>(get_device_proc_addr(device.get(),"vkCreateBufferView"));
    pfn_DestroyBufferView = reinterpret_cast<detail::PFN_vkDestroyBufferView>(get_device_proc_addr(device.get(),"vkDestroyBufferView"));
    pfn_CreateImage = reinterpret_cast<detail::PFN_vkCreateImage>(get_device_proc_addr(device.get(),"vkCreateImage"));
    pfn_DestroyImage = reinterpret_cast<detail::PFN_vkDestroyImage>(get_device_proc_addr(device.get(),"vkDestroyImage"));
    pfn_GetImageSubresourceLayout = reinterpret_cast<detail::PFN_vkGetImageSubresourceLayout>(get_device_proc_addr(device.get(),"vkGetImageSubresourceLayout"));
    pfn_CreateImageView = reinterpret_cast<detail::PFN_vkCreateImageView>(get_device_proc_addr(device.get(),"vkCreateImageView"));
    pfn_DestroyImageView = reinterpret_cast<detail::PFN_vkDestroyImageView>(get_device_proc_addr(device.get(),"vkDestroyImageView"));
    pfn_CreateShaderModule = reinterpret_cast<detail::PFN_vkCreateShaderModule>(get_device_proc_addr(device.get(),"vkCreateShaderModule"));
    pfn_DestroyShaderModule = reinterpret_cast<detail::PFN_vkDestroyShaderModule>(get_device_proc_addr(device.get(),"vkDestroyShaderModule"));
    pfn_CreatePipelineCache = reinterpret_cast<detail::PFN_vkCreatePipelineCache>(get_device_proc_addr(device.get(),"vkCreatePipelineCache"));
    pfn_DestroyPipelineCache = reinterpret_cast<detail::PFN_vkDestroyPipelineCache>(get_device_proc_addr(device.get(),"vkDestroyPipelineCache"));
    pfn_GetPipelineCacheData = reinterpret_cast<detail::PFN_vkGetPipelineCacheData>(get_device_proc_addr(device.get(),"vkGetPipelineCacheData"));
    pfn_MergePipelineCaches = reinterpret_cast<detail::PFN_vkMergePipelineCaches>(get_device_proc_addr(device.get(),"vkMergePipelineCaches"));
    pfn_CreateGraphicsPipelines = reinterpret_cast<detail::PFN_vkCreateGraphicsPipelines>(get_device_proc_addr(device.get(),"vkCreateGraphicsPipelines"));
    pfn_CreateComputePipelines = reinterpret_cast<detail::PFN_vkCreateComputePipelines>(get_device_proc_addr(device.get(),"vkCreateComputePipelines"));
    pfn_DestroyPipeline = reinterpret_cast<detail::PFN_vkDestroyPipeline>(get_device_proc_addr(device.get(),"vkDestroyPipeline"));
    pfn_CreatePipelineLayout = reinterpret_cast<detail::PFN_vkCreatePipelineLayout>(get_device_proc_addr(device.get(),"vkCreatePipelineLayout"));
    pfn_DestroyPipelineLayout = reinterpret_cast<detail::PFN_vkDestroyPipelineLayout>(get_device_proc_addr(device.get(),"vkDestroyPipelineLayout"));
    pfn_CreateSampler = reinterpret_cast<detail::PFN_vkCreateSampler>(get_device_proc_addr(device.get(),"vkCreateSampler"));
    pfn_DestroySampler = reinterpret_cast<detail::PFN_vkDestroySampler>(get_device_proc_addr(device.get(),"vkDestroySampler"));
    pfn_CreateDescriptorSetLayout = reinterpret_cast<detail::PFN_vkCreateDescriptorSetLayout>(get_device_proc_addr(device.get(),"vkCreateDescriptorSetLayout"));
    pfn_DestroyDescriptorSetLayout = reinterpret_cast<detail::PFN_vkDestroyDescriptorSetLayout>(get_device_proc_addr(device.get(),"vkDestroyDescriptorSetLayout"));
    pfn_CreateDescriptorPool = reinterpret_cast<detail::PFN_vkCreateDescriptorPool>(get_device_proc_addr(device.get(),"vkCreateDescriptorPool"));
    pfn_DestroyDescriptorPool = reinterpret_cast<detail::PFN_vkDestroyDescriptorPool>(get_device_proc_addr(device.get(),"vkDestroyDescriptorPool"));
    pfn_ResetDescriptorPool = reinterpret_cast<detail::PFN_vkResetDescriptorPool>(get_device_proc_addr(device.get(),"vkResetDescriptorPool"));
    pfn_AllocateDescriptorSets = reinterpret_cast<detail::PFN_vkAllocateDescriptorSets>(get_device_proc_addr(device.get(),"vkAllocateDescriptorSets"));
    pfn_FreeDescriptorSets = reinterpret_cast<detail::PFN_vkFreeDescriptorSets>(get_device_proc_addr(device.get(),"vkFreeDescriptorSets"));
    pfn_UpdateDescriptorSets = reinterpret_cast<detail::PFN_vkUpdateDescriptorSets>(get_device_proc_addr(device.get(),"vkUpdateDescriptorSets"));
    pfn_CreateFramebuffer = reinterpret_cast<detail::PFN_vkCreateFramebuffer>(get_device_proc_addr(device.get(),"vkCreateFramebuffer"));
    pfn_DestroyFramebuffer = reinterpret_cast<detail::PFN_vkDestroyFramebuffer>(get_device_proc_addr(device.get(),"vkDestroyFramebuffer"));
    pfn_CreateRenderPass = reinterpret_cast<detail::PFN_vkCreateRenderPass>(get_device_proc_addr(device.get(),"vkCreateRenderPass"));
    pfn_DestroyRenderPass = reinterpret_cast<detail::PFN_vkDestroyRenderPass>(get_device_proc_addr(device.get(),"vkDestroyRenderPass"));
    pfn_GetRenderAreaGranularity = reinterpret_cast<detail::PFN_vkGetRenderAreaGranularity>(get_device_proc_addr(device.get(),"vkGetRenderAreaGranularity"));
    pfn_CreateCommandPool = reinterpret_cast<detail::PFN_vkCreateCommandPool>(get_device_proc_addr(device.get(),"vkCreateCommandPool"));
    pfn_DestroyCommandPool = reinterpret_cast<detail::PFN_vkDestroyCommandPool>(get_device_proc_addr(device.get(),"vkDestroyCommandPool"));
    pfn_ResetCommandPool = reinterpret_cast<detail::PFN_vkResetCommandPool>(get_device_proc_addr(device.get(),"vkResetCommandPool"));
    pfn_AllocateCommandBuffers = reinterpret_cast<detail::PFN_vkAllocateCommandBuffers>(get_device_proc_addr(device.get(),"vkAllocateCommandBuffers"));
    pfn_FreeCommandBuffers = reinterpret_cast<detail::PFN_vkFreeCommandBuffers>(get_device_proc_addr(device.get(),"vkFreeCommandBuffers"));
    pfn_BeginCommandBuffer = reinterpret_cast<detail::PFN_vkBeginCommandBuffer>(get_device_proc_addr(device.get(),"vkBeginCommandBuffer"));
    pfn_EndCommandBuffer = reinterpret_cast<detail::PFN_vkEndCommandBuffer>(get_device_proc_addr(device.get(),"vkEndCommandBuffer"));
    pfn_ResetCommandBuffer = reinterpret_cast<detail::PFN_vkResetCommandBuffer>(get_device_proc_addr(device.get(),"vkResetCommandBuffer"));
    pfn_CmdBindPipeline = reinterpret_cast<detail::PFN_vkCmdBindPipeline>(get_device_proc_addr(device.get(),"vkCmdBindPipeline"));
    pfn_CmdSetViewport = reinterpret_cast<detail::PFN_vkCmdSetViewport>(get_device_proc_addr(device.get(),"vkCmdSetViewport"));
    pfn_CmdSetScissor = reinterpret_cast<detail::PFN_vkCmdSetScissor>(get_device_proc_addr(device.get(),"vkCmdSetScissor"));
    pfn_CmdSetLineWidth = reinterpret_cast<detail::PFN_vkCmdSetLineWidth>(get_device_proc_addr(device.get(),"vkCmdSetLineWidth"));
    pfn_CmdSetDepthBias = reinterpret_cast<detail::PFN_vkCmdSetDepthBias>(get_device_proc_addr(device.get(),"vkCmdSetDepthBias"));
    pfn_CmdSetBlendConstants = reinterpret_cast<detail::PFN_vkCmdSetBlendConstants>(get_device_proc_addr(device.get(),"vkCmdSetBlendConstants"));
    pfn_CmdSetDepthBounds = reinterpret_cast<detail::PFN_vkCmdSetDepthBounds>(get_device_proc_addr(device.get(),"vkCmdSetDepthBounds"));
    pfn_CmdSetStencilCompareMask = reinterpret_cast<detail::PFN_vkCmdSetStencilCompareMask>(get_device_proc_addr(device.get(),"vkCmdSetStencilCompareMask"));
    pfn_CmdSetStencilWriteMask = reinterpret_cast<detail::PFN_vkCmdSetStencilWriteMask>(get_device_proc_addr(device.get(),"vkCmdSetStencilWriteMask"));
    pfn_CmdSetStencilReference = reinterpret_cast<detail::PFN_vkCmdSetStencilReference>(get_device_proc_addr(device.get(),"vkCmdSetStencilReference"));
    pfn_CmdBindDescriptorSets = reinterpret_cast<detail::PFN_vkCmdBindDescriptorSets>(get_device_proc_addr(device.get(),"vkCmdBindDescriptorSets"));
    pfn_CmdBindIndexBuffer = reinterpret_cast<detail::PFN_vkCmdBindIndexBuffer>(get_device_proc_addr(device.get(),"vkCmdBindIndexBuffer"));
    pfn_CmdBindVertexBuffers = reinterpret_cast<detail::PFN_vkCmdBindVertexBuffers>(get_device_proc_addr(device.get(),"vkCmdBindVertexBuffers"));
    pfn_CmdDraw = reinterpret_cast<detail::PFN_vkCmdDraw>(get_device_proc_addr(device.get(),"vkCmdDraw"));
    pfn_CmdDrawIndexed = reinterpret_cast<detail::PFN_vkCmdDrawIndexed>(get_device_proc_addr(device.get(),"vkCmdDrawIndexed"));
    pfn_CmdDrawIndirect = reinterpret_cast<detail::PFN_vkCmdDrawIndirect>(get_device_proc_addr(device.get(),"vkCmdDrawIndirect"));
    pfn_CmdDrawIndexedIndirect = reinterpret_cast<detail::PFN_vkCmdDrawIndexedIndirect>(get_device_proc_addr(device.get(),"vkCmdDrawIndexedIndirect"));
    pfn_CmdDispatch = reinterpret_cast<detail::PFN_vkCmdDispatch>(get_device_proc_addr(device.get(),"vkCmdDispatch"));
    pfn_CmdDispatchIndirect = reinterpret_cast<detail::PFN_vkCmdDispatchIndirect>(get_device_proc_addr(device.get(),"vkCmdDispatchIndirect"));
    pfn_CmdCopyBuffer = reinterpret_cast<detail::PFN_vkCmdCopyBuffer>(get_device_proc_addr(device.get(),"vkCmdCopyBuffer"));
    pfn_CmdCopyImage = reinterpret_cast<detail::PFN_vkCmdCopyImage>(get_device_proc_addr(device.get(),"vkCmdCopyImage"));
    pfn_CmdBlitImage = reinterpret_cast<detail::PFN_vkCmdBlitImage>(get_device_proc_addr(device.get(),"vkCmdBlitImage"));
    pfn_CmdCopyBufferToImage = reinterpret_cast<detail::PFN_vkCmdCopyBufferToImage>(get_device_proc_addr(device.get(),"vkCmdCopyBufferToImage"));
    pfn_CmdCopyImageToBuffer = reinterpret_cast<detail::PFN_vkCmdCopyImageToBuffer>(get_device_proc_addr(device.get(),"vkCmdCopyImageToBuffer"));
    pfn_CmdUpdateBuffer = reinterpret_cast<detail::PFN_vkCmdUpdateBuffer>(get_device_proc_addr(device.get(),"vkCmdUpdateBuffer"));
    pfn_CmdFillBuffer = reinterpret_cast<detail::PFN_vkCmdFillBuffer>(get_device_proc_addr(device.get(),"vkCmdFillBuffer"));
    pfn_CmdClearColorImage = reinterpret_cast<detail::PFN_vkCmdClearColorImage>(get_device_proc_addr(device.get(),"vkCmdClearColorImage"));
    pfn_CmdClearDepthStencilImage = reinterpret_cast<detail::PFN_vkCmdClearDepthStencilImage>(get_device_proc_addr(device.get(),"vkCmdClearDepthStencilImage"));
    pfn_CmdClearAttachments = reinterpret_cast<detail::PFN_vkCmdClearAttachments>(get_device_proc_addr(device.get(),"vkCmdClearAttachments"));
    pfn_CmdResolveImage = reinterpret_cast<detail::PFN_vkCmdResolveImage>(get_device_proc_addr(device.get(),"vkCmdResolveImage"));
    pfn_CmdSetEvent = reinterpret_cast<detail::PFN_vkCmdSetEvent>(get_device_proc_addr(device.get(),"vkCmdSetEvent"));
    pfn_CmdResetEvent = reinterpret_cast<detail::PFN_vkCmdResetEvent>(get_device_proc_addr(device.get(),"vkCmdResetEvent"));
    pfn_CmdWaitEvents = reinterpret_cast<detail::PFN_vkCmdWaitEvents>(get_device_proc_addr(device.get(),"vkCmdWaitEvents"));
    pfn_CmdPipelineBarrier = reinterpret_cast<detail::PFN_vkCmdPipelineBarrier>(get_device_proc_addr(device.get(),"vkCmdPipelineBarrier"));
    pfn_CmdBeginQuery = reinterpret_cast<detail::PFN_vkCmdBeginQuery>(get_device_proc_addr(device.get(),"vkCmdBeginQuery"));
    pfn_CmdEndQuery = reinterpret_cast<detail::PFN_vkCmdEndQuery>(get_device_proc_addr(device.get(),"vkCmdEndQuery"));
    pfn_CmdResetQueryPool = reinterpret_cast<detail::PFN_vkCmdResetQueryPool>(get_device_proc_addr(device.get(),"vkCmdResetQueryPool"));
    pfn_CmdWriteTimestamp = reinterpret_cast<detail::PFN_vkCmdWriteTimestamp>(get_device_proc_addr(device.get(),"vkCmdWriteTimestamp"));
    pfn_CmdCopyQueryPoolResults = reinterpret_cast<detail::PFN_vkCmdCopyQueryPoolResults>(get_device_proc_addr(device.get(),"vkCmdCopyQueryPoolResults"));
    pfn_CmdPushConstants = reinterpret_cast<detail::PFN_vkCmdPushConstants>(get_device_proc_addr(device.get(),"vkCmdPushConstants"));
    pfn_CmdBeginRenderPass = reinterpret_cast<detail::PFN_vkCmdBeginRenderPass>(get_device_proc_addr(device.get(),"vkCmdBeginRenderPass"));
    pfn_CmdNextSubpass = reinterpret_cast<detail::PFN_vkCmdNextSubpass>(get_device_proc_addr(device.get(),"vkCmdNextSubpass"));
    pfn_CmdEndRenderPass = reinterpret_cast<detail::PFN_vkCmdEndRenderPass>(get_device_proc_addr(device.get(),"vkCmdEndRenderPass"));
    pfn_CmdExecuteCommands = reinterpret_cast<detail::PFN_vkCmdExecuteCommands>(get_device_proc_addr(device.get(),"vkCmdExecuteCommands"));
    pfn_BindBufferMemory2 = reinterpret_cast<detail::PFN_vkBindBufferMemory2>(get_device_proc_addr(device.get(),"vkBindBufferMemory2"));
    pfn_BindImageMemory2 = reinterpret_cast<detail::PFN_vkBindImageMemory2>(get_device_proc_addr(device.get(),"vkBindImageMemory2"));
    pfn_GetDeviceGroupPeerMemoryFeatures = reinterpret_cast<detail::PFN_vkGetDeviceGroupPeerMemoryFeatures>(get_device_proc_addr(device.get(),"vkGetDeviceGroupPeerMemoryFeatures"));
    pfn_CmdSetDeviceMask = reinterpret_cast<detail::PFN_vkCmdSetDeviceMask>(get_device_proc_addr(device.get(),"vkCmdSetDeviceMask"));
    pfn_CmdDispatchBase = reinterpret_cast<detail::PFN_vkCmdDispatchBase>(get_device_proc_addr(device.get(),"vkCmdDispatchBase"));
    pfn_GetBufferMemoryRequirements2 = reinterpret_cast<detail::PFN_vkGetBufferMemoryRequirements2>(get_device_proc_addr(device.get(),"vkGetBufferMemoryRequirements2"));
    pfn_GetImageMemoryRequirements2 = reinterpret_cast<detail::PFN_vkGetImageMemoryRequirements2>(get_device_proc_addr(device.get(),"vkGetImageMemoryRequirements2"));
    pfn_GetImageSparseMemoryRequirements2 = reinterpret_cast<detail::PFN_vkGetImageSparseMemoryRequirements2>(get_device_proc_addr(device.get(),"vkGetImageSparseMemoryRequirements2"));
    pfn_TrimCommandPool = reinterpret_cast<detail::PFN_vkTrimCommandPool>(get_device_proc_addr(device.get(),"vkTrimCommandPool"));
    pfn_GetDeviceQueue2 = reinterpret_cast<detail::PFN_vkGetDeviceQueue2>(get_device_proc_addr(device.get(),"vkGetDeviceQueue2"));
    pfn_CreateSamplerYcbcrConversion = reinterpret_cast<detail::PFN_vkCreateSamplerYcbcrConversion>(get_device_proc_addr(device.get(),"vkCreateSamplerYcbcrConversion"));
    pfn_DestroySamplerYcbcrConversion = reinterpret_cast<detail::PFN_vkDestroySamplerYcbcrConversion>(get_device_proc_addr(device.get(),"vkDestroySamplerYcbcrConversion"));
    pfn_CreateDescriptorUpdateTemplate = reinterpret_cast<detail::PFN_vkCreateDescriptorUpdateTemplate>(get_device_proc_addr(device.get(),"vkCreateDescriptorUpdateTemplate"));
    pfn_DestroyDescriptorUpdateTemplate = reinterpret_cast<detail::PFN_vkDestroyDescriptorUpdateTemplate>(get_device_proc_addr(device.get(),"vkDestroyDescriptorUpdateTemplate"));
    pfn_UpdateDescriptorSetWithTemplate = reinterpret_cast<detail::PFN_vkUpdateDescriptorSetWithTemplate>(get_device_proc_addr(device.get(),"vkUpdateDescriptorSetWithTemplate"));
    pfn_GetDescriptorSetLayoutSupport = reinterpret_cast<detail::PFN_vkGetDescriptorSetLayoutSupport>(get_device_proc_addr(device.get(),"vkGetDescriptorSetLayoutSupport"));
    pfn_CmdDrawIndirectCount = reinterpret_cast<detail::PFN_vkCmdDrawIndirectCount>(get_device_proc_addr(device.get(),"vkCmdDrawIndirectCount"));
    pfn_CmdDrawIndexedIndirectCount = reinterpret_cast<detail::PFN_vkCmdDrawIndexedIndirectCount>(get_device_proc_addr(device.get(),"vkCmdDrawIndexedIndirectCount"));
    pfn_CreateRenderPass2 = reinterpret_cast<detail::PFN_vkCreateRenderPass2>(get_device_proc_addr(device.get(),"vkCreateRenderPass2"));
    pfn_CmdBeginRenderPass2 = reinterpret_cast<detail::PFN_vkCmdBeginRenderPass2>(get_device_proc_addr(device.get(),"vkCmdBeginRenderPass2"));
    pfn_CmdNextSubpass2 = reinterpret_cast<detail::PFN_vkCmdNextSubpass2>(get_device_proc_addr(device.get(),"vkCmdNextSubpass2"));
    pfn_CmdEndRenderPass2 = reinterpret_cast<detail::PFN_vkCmdEndRenderPass2>(get_device_proc_addr(device.get(),"vkCmdEndRenderPass2"));
    pfn_ResetQueryPool = reinterpret_cast<detail::PFN_vkResetQueryPool>(get_device_proc_addr(device.get(),"vkResetQueryPool"));
    pfn_GetSemaphoreCounterValue = reinterpret_cast<detail::PFN_vkGetSemaphoreCounterValue>(get_device_proc_addr(device.get(),"vkGetSemaphoreCounterValue"));
    pfn_WaitSemaphores = reinterpret_cast<detail::PFN_vkWaitSemaphores>(get_device_proc_addr(device.get(),"vkWaitSemaphores"));
    pfn_SignalSemaphore = reinterpret_cast<detail::PFN_vkSignalSemaphore>(get_device_proc_addr(device.get(),"vkSignalSemaphore"));
    pfn_GetBufferOpaqueCaptureAddress = reinterpret_cast<detail::PFN_vkGetBufferOpaqueCaptureAddress>(get_device_proc_addr(device.get(),"vkGetBufferOpaqueCaptureAddress"));
    pfn_GetBufferDeviceAddress = reinterpret_cast<detail::PFN_vkGetBufferDeviceAddress>(get_device_proc_addr(device.get(),"vkGetBufferDeviceAddress"));
    pfn_GetDeviceMemoryOpaqueCaptureAddress = reinterpret_cast<detail::PFN_vkGetDeviceMemoryOpaqueCaptureAddress>(get_device_proc_addr(device.get(),"vkGetDeviceMemoryOpaqueCaptureAddress"));
    pfn_CreateSwapchainKHR = reinterpret_cast<detail::PFN_vkCreateSwapchainKHR>(get_device_proc_addr(device.get(),"vkCreateSwapchainKHR"));
    pfn_DestroySwapchainKHR = reinterpret_cast<detail::PFN_vkDestroySwapchainKHR>(get_device_proc_addr(device.get(),"vkDestroySwapchainKHR"));
    pfn_GetSwapchainImagesKHR = reinterpret_cast<detail::PFN_vkGetSwapchainImagesKHR>(get_device_proc_addr(device.get(),"vkGetSwapchainImagesKHR"));
    pfn_AcquireNextImageKHR = reinterpret_cast<detail::PFN_vkAcquireNextImageKHR>(get_device_proc_addr(device.get(),"vkAcquireNextImageKHR"));
    pfn_QueuePresentKHR = reinterpret_cast<detail::PFN_vkQueuePresentKHR>(get_device_proc_addr(device.get(),"vkQueuePresentKHR"));
    pfn_GetDeviceGroupPresentCapabilitiesKHR = reinterpret_cast<detail::PFN_vkGetDeviceGroupPresentCapabilitiesKHR>(get_device_proc_addr(device.get(),"vkGetDeviceGroupPresentCapabilitiesKHR"));
    pfn_GetDeviceGroupSurfacePresentModesKHR = reinterpret_cast<detail::PFN_vkGetDeviceGroupSurfacePresentModesKHR>(get_device_proc_addr(device.get(),"vkGetDeviceGroupSurfacePresentModesKHR"));
    pfn_AcquireNextImage2KHR = reinterpret_cast<detail::PFN_vkAcquireNextImage2KHR>(get_device_proc_addr(device.get(),"vkAcquireNextImage2KHR"));
    pfn_CreateSharedSwapchainsKHR = reinterpret_cast<detail::PFN_vkCreateSharedSwapchainsKHR>(get_device_proc_addr(device.get(),"vkCreateSharedSwapchainsKHR"));
    pfn_DebugMarkerSetObjectNameEXT = reinterpret_cast<detail::PFN_vkDebugMarkerSetObjectNameEXT>(get_device_proc_addr(device.get(),"vkDebugMarkerSetObjectNameEXT"));
    pfn_DebugMarkerSetObjectTagEXT = reinterpret_cast<detail::PFN_vkDebugMarkerSetObjectTagEXT>(get_device_proc_addr(device.get(),"vkDebugMarkerSetObjectTagEXT"));
    pfn_CmdDebugMarkerBeginEXT = reinterpret_cast<detail::PFN_vkCmdDebugMarkerBeginEXT>(get_device_proc_addr(device.get(),"vkCmdDebugMarkerBeginEXT"));
    pfn_CmdDebugMarkerEndEXT = reinterpret_cast<detail::PFN_vkCmdDebugMarkerEndEXT>(get_device_proc_addr(device.get(),"vkCmdDebugMarkerEndEXT"));
    pfn_CmdDebugMarkerInsertEXT = reinterpret_cast<detail::PFN_vkCmdDebugMarkerInsertEXT>(get_device_proc_addr(device.get(),"vkCmdDebugMarkerInsertEXT"));
    pfn_CmdBindTransformFeedbackBuffersEXT = reinterpret_cast<detail::PFN_vkCmdBindTransformFeedbackBuffersEXT>(get_device_proc_addr(device.get(),"vkCmdBindTransformFeedbackBuffersEXT"));
    pfn_CmdBeginTransformFeedbackEXT = reinterpret_cast<detail::PFN_vkCmdBeginTransformFeedbackEXT>(get_device_proc_addr(device.get(),"vkCmdBeginTransformFeedbackEXT"));
    pfn_CmdEndTransformFeedbackEXT = reinterpret_cast<detail::PFN_vkCmdEndTransformFeedbackEXT>(get_device_proc_addr(device.get(),"vkCmdEndTransformFeedbackEXT"));
    pfn_CmdBeginQueryIndexedEXT = reinterpret_cast<detail::PFN_vkCmdBeginQueryIndexedEXT>(get_device_proc_addr(device.get(),"vkCmdBeginQueryIndexedEXT"));
    pfn_CmdEndQueryIndexedEXT = reinterpret_cast<detail::PFN_vkCmdEndQueryIndexedEXT>(get_device_proc_addr(device.get(),"vkCmdEndQueryIndexedEXT"));
    pfn_CmdDrawIndirectByteCountEXT = reinterpret_cast<detail::PFN_vkCmdDrawIndirectByteCountEXT>(get_device_proc_addr(device.get(),"vkCmdDrawIndirectByteCountEXT"));
    pfn_GetImageViewHandleNVX = reinterpret_cast<detail::PFN_vkGetImageViewHandleNVX>(get_device_proc_addr(device.get(),"vkGetImageViewHandleNVX"));
    pfn_GetImageViewAddressNVX = reinterpret_cast<detail::PFN_vkGetImageViewAddressNVX>(get_device_proc_addr(device.get(),"vkGetImageViewAddressNVX"));
    pfn_GetShaderInfoAMD = reinterpret_cast<detail::PFN_vkGetShaderInfoAMD>(get_device_proc_addr(device.get(),"vkGetShaderInfoAMD"));
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetMemoryWin32HandleNV = reinterpret_cast<detail::PFN_vkGetMemoryWin32HandleNV>(get_device_proc_addr(device.get(),"vkGetMemoryWin32HandleNV"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetMemoryWin32HandleKHR = reinterpret_cast<detail::PFN_vkGetMemoryWin32HandleKHR>(get_device_proc_addr(device.get(),"vkGetMemoryWin32HandleKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetMemoryWin32HandlePropertiesKHR = reinterpret_cast<detail::PFN_vkGetMemoryWin32HandlePropertiesKHR>(get_device_proc_addr(device.get(),"vkGetMemoryWin32HandlePropertiesKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
    pfn_GetMemoryFdKHR = reinterpret_cast<detail::PFN_vkGetMemoryFdKHR>(get_device_proc_addr(device.get(),"vkGetMemoryFdKHR"));
    pfn_GetMemoryFdPropertiesKHR = reinterpret_cast<detail::PFN_vkGetMemoryFdPropertiesKHR>(get_device_proc_addr(device.get(),"vkGetMemoryFdPropertiesKHR"));
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetSemaphoreWin32HandleKHR = reinterpret_cast<detail::PFN_vkGetSemaphoreWin32HandleKHR>(get_device_proc_addr(device.get(),"vkGetSemaphoreWin32HandleKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_ImportSemaphoreWin32HandleKHR = reinterpret_cast<detail::PFN_vkImportSemaphoreWin32HandleKHR>(get_device_proc_addr(device.get(),"vkImportSemaphoreWin32HandleKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
    pfn_GetSemaphoreFdKHR = reinterpret_cast<detail::PFN_vkGetSemaphoreFdKHR>(get_device_proc_addr(device.get(),"vkGetSemaphoreFdKHR"));
    pfn_ImportSemaphoreFdKHR = reinterpret_cast<detail::PFN_vkImportSemaphoreFdKHR>(get_device_proc_addr(device.get(),"vkImportSemaphoreFdKHR"));
    pfn_CmdPushDescriptorSetKHR = reinterpret_cast<detail::PFN_vkCmdPushDescriptorSetKHR>(get_device_proc_addr(device.get(),"vkCmdPushDescriptorSetKHR"));
    pfn_CmdPushDescriptorSetWithTemplateKHR = reinterpret_cast<detail::PFN_vkCmdPushDescriptorSetWithTemplateKHR>(get_device_proc_addr(device.get(),"vkCmdPushDescriptorSetWithTemplateKHR"));
    pfn_CmdBeginConditionalRenderingEXT = reinterpret_cast<detail::PFN_vkCmdBeginConditionalRenderingEXT>(get_device_proc_addr(device.get(),"vkCmdBeginConditionalRenderingEXT"));
    pfn_CmdEndConditionalRenderingEXT = reinterpret_cast<detail::PFN_vkCmdEndConditionalRenderingEXT>(get_device_proc_addr(device.get(),"vkCmdEndConditionalRenderingEXT"));
    pfn_CmdSetViewportWScalingNV = reinterpret_cast<detail::PFN_vkCmdSetViewportWScalingNV>(get_device_proc_addr(device.get(),"vkCmdSetViewportWScalingNV"));
    pfn_DisplayPowerControlEXT = reinterpret_cast<detail::PFN_vkDisplayPowerControlEXT>(get_device_proc_addr(device.get(),"vkDisplayPowerControlEXT"));
    pfn_RegisterDeviceEventEXT = reinterpret_cast<detail::PFN_vkRegisterDeviceEventEXT>(get_device_proc_addr(device.get(),"vkRegisterDeviceEventEXT"));
    pfn_RegisterDisplayEventEXT = reinterpret_cast<detail::PFN_vkRegisterDisplayEventEXT>(get_device_proc_addr(device.get(),"vkRegisterDisplayEventEXT"));
    pfn_GetSwapchainCounterEXT = reinterpret_cast<detail::PFN_vkGetSwapchainCounterEXT>(get_device_proc_addr(device.get(),"vkGetSwapchainCounterEXT"));
    pfn_GetRefreshCycleDurationGOOGLE = reinterpret_cast<detail::PFN_vkGetRefreshCycleDurationGOOGLE>(get_device_proc_addr(device.get(),"vkGetRefreshCycleDurationGOOGLE"));
    pfn_GetPastPresentationTimingGOOGLE = reinterpret_cast<detail::PFN_vkGetPastPresentationTimingGOOGLE>(get_device_proc_addr(device.get(),"vkGetPastPresentationTimingGOOGLE"));
    pfn_CmdSetDiscardRectangleEXT = reinterpret_cast<detail::PFN_vkCmdSetDiscardRectangleEXT>(get_device_proc_addr(device.get(),"vkCmdSetDiscardRectangleEXT"));
    pfn_SetHdrMetadataEXT = reinterpret_cast<detail::PFN_vkSetHdrMetadataEXT>(get_device_proc_addr(device.get(),"vkSetHdrMetadataEXT"));
    pfn_GetSwapchainStatusKHR = reinterpret_cast<detail::PFN_vkGetSwapchainStatusKHR>(get_device_proc_addr(device.get(),"vkGetSwapchainStatusKHR"));
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetFenceWin32HandleKHR = reinterpret_cast<detail::PFN_vkGetFenceWin32HandleKHR>(get_device_proc_addr(device.get(),"vkGetFenceWin32HandleKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_ImportFenceWin32HandleKHR = reinterpret_cast<detail::PFN_vkImportFenceWin32HandleKHR>(get_device_proc_addr(device.get(),"vkImportFenceWin32HandleKHR"));
#endif // VK_USE_PLATFORM_WIN32_KHR
    pfn_GetFenceFdKHR = reinterpret_cast<detail::PFN_vkGetFenceFdKHR>(get_device_proc_addr(device.get(),"vkGetFenceFdKHR"));
    pfn_ImportFenceFdKHR = reinterpret_cast<detail::PFN_vkImportFenceFdKHR>(get_device_proc_addr(device.get(),"vkImportFenceFdKHR"));
    pfn_AcquireProfilingLockKHR = reinterpret_cast<detail::PFN_vkAcquireProfilingLockKHR>(get_device_proc_addr(device.get(),"vkAcquireProfilingLockKHR"));
    pfn_ReleaseProfilingLockKHR = reinterpret_cast<detail::PFN_vkReleaseProfilingLockKHR>(get_device_proc_addr(device.get(),"vkReleaseProfilingLockKHR"));
    pfn_SetDebugUtilsObjectNameEXT = reinterpret_cast<detail::PFN_vkSetDebugUtilsObjectNameEXT>(get_device_proc_addr(device.get(),"vkSetDebugUtilsObjectNameEXT"));
    pfn_SetDebugUtilsObjectTagEXT = reinterpret_cast<detail::PFN_vkSetDebugUtilsObjectTagEXT>(get_device_proc_addr(device.get(),"vkSetDebugUtilsObjectTagEXT"));
    pfn_QueueBeginDebugUtilsLabelEXT = reinterpret_cast<detail::PFN_vkQueueBeginDebugUtilsLabelEXT>(get_device_proc_addr(device.get(),"vkQueueBeginDebugUtilsLabelEXT"));
    pfn_QueueEndDebugUtilsLabelEXT = reinterpret_cast<detail::PFN_vkQueueEndDebugUtilsLabelEXT>(get_device_proc_addr(device.get(),"vkQueueEndDebugUtilsLabelEXT"));
    pfn_QueueInsertDebugUtilsLabelEXT = reinterpret_cast<detail::PFN_vkQueueInsertDebugUtilsLabelEXT>(get_device_proc_addr(device.get(),"vkQueueInsertDebugUtilsLabelEXT"));
    pfn_CmdBeginDebugUtilsLabelEXT = reinterpret_cast<detail::PFN_vkCmdBeginDebugUtilsLabelEXT>(get_device_proc_addr(device.get(),"vkCmdBeginDebugUtilsLabelEXT"));
    pfn_CmdEndDebugUtilsLabelEXT = reinterpret_cast<detail::PFN_vkCmdEndDebugUtilsLabelEXT>(get_device_proc_addr(device.get(),"vkCmdEndDebugUtilsLabelEXT"));
    pfn_CmdInsertDebugUtilsLabelEXT = reinterpret_cast<detail::PFN_vkCmdInsertDebugUtilsLabelEXT>(get_device_proc_addr(device.get(),"vkCmdInsertDebugUtilsLabelEXT"));
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    pfn_GetAndroidHardwareBufferPropertiesANDROID = reinterpret_cast<detail::PFN_vkGetAndroidHardwareBufferPropertiesANDROID>(get_device_proc_addr(device.get(),"vkGetAndroidHardwareBufferPropertiesANDROID"));
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    pfn_GetMemoryAndroidHardwareBufferANDROID = reinterpret_cast<detail::PFN_vkGetMemoryAndroidHardwareBufferANDROID>(get_device_proc_addr(device.get(),"vkGetMemoryAndroidHardwareBufferANDROID"));
#endif // VK_USE_PLATFORM_ANDROID_KHR
    pfn_CmdSetSampleLocationsEXT = reinterpret_cast<detail::PFN_vkCmdSetSampleLocationsEXT>(get_device_proc_addr(device.get(),"vkCmdSetSampleLocationsEXT"));
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_DestroyAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkDestroyAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkDestroyAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetAccelerationStructureMemoryRequirementsKHR = reinterpret_cast<detail::PFN_vkGetAccelerationStructureMemoryRequirementsKHR>(get_device_proc_addr(device.get(),"vkGetAccelerationStructureMemoryRequirementsKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_BindAccelerationStructureMemoryKHR = reinterpret_cast<detail::PFN_vkBindAccelerationStructureMemoryKHR>(get_device_proc_addr(device.get(),"vkBindAccelerationStructureMemoryKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdCopyAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkCmdCopyAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkCmdCopyAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CopyAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkCopyAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkCopyAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdCopyAccelerationStructureToMemoryKHR = reinterpret_cast<detail::PFN_vkCmdCopyAccelerationStructureToMemoryKHR>(get_device_proc_addr(device.get(),"vkCmdCopyAccelerationStructureToMemoryKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CopyAccelerationStructureToMemoryKHR = reinterpret_cast<detail::PFN_vkCopyAccelerationStructureToMemoryKHR>(get_device_proc_addr(device.get(),"vkCopyAccelerationStructureToMemoryKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdCopyMemoryToAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkCmdCopyMemoryToAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkCmdCopyMemoryToAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CopyMemoryToAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkCopyMemoryToAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkCopyMemoryToAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdWriteAccelerationStructuresPropertiesKHR = reinterpret_cast<detail::PFN_vkCmdWriteAccelerationStructuresPropertiesKHR>(get_device_proc_addr(device.get(),"vkCmdWriteAccelerationStructuresPropertiesKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_WriteAccelerationStructuresPropertiesKHR = reinterpret_cast<detail::PFN_vkWriteAccelerationStructuresPropertiesKHR>(get_device_proc_addr(device.get(),"vkWriteAccelerationStructuresPropertiesKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdTraceRaysKHR = reinterpret_cast<detail::PFN_vkCmdTraceRaysKHR>(get_device_proc_addr(device.get(),"vkCmdTraceRaysKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetRayTracingShaderGroupHandlesKHR = reinterpret_cast<detail::PFN_vkGetRayTracingShaderGroupHandlesKHR>(get_device_proc_addr(device.get(),"vkGetRayTracingShaderGroupHandlesKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetRayTracingCaptureReplayShaderGroupHandlesKHR = reinterpret_cast<detail::PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>(get_device_proc_addr(device.get(),"vkGetRayTracingCaptureReplayShaderGroupHandlesKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CreateRayTracingPipelinesKHR = reinterpret_cast<detail::PFN_vkCreateRayTracingPipelinesKHR>(get_device_proc_addr(device.get(),"vkCreateRayTracingPipelinesKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdTraceRaysIndirectKHR = reinterpret_cast<detail::PFN_vkCmdTraceRaysIndirectKHR>(get_device_proc_addr(device.get(),"vkCmdTraceRaysIndirectKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetDeviceAccelerationStructureCompatibilityKHR = reinterpret_cast<detail::PFN_vkGetDeviceAccelerationStructureCompatibilityKHR>(get_device_proc_addr(device.get(),"vkGetDeviceAccelerationStructureCompatibilityKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CreateAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkCreateAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkCreateAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdBuildAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkCmdBuildAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkCmdBuildAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CmdBuildAccelerationStructureIndirectKHR = reinterpret_cast<detail::PFN_vkCmdBuildAccelerationStructureIndirectKHR>(get_device_proc_addr(device.get(),"vkCmdBuildAccelerationStructureIndirectKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_BuildAccelerationStructureKHR = reinterpret_cast<detail::PFN_vkBuildAccelerationStructureKHR>(get_device_proc_addr(device.get(),"vkBuildAccelerationStructureKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetAccelerationStructureDeviceAddressKHR = reinterpret_cast<detail::PFN_vkGetAccelerationStructureDeviceAddressKHR>(get_device_proc_addr(device.get(),"vkGetAccelerationStructureDeviceAddressKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
    pfn_GetImageDrmFormatModifierPropertiesEXT = reinterpret_cast<detail::PFN_vkGetImageDrmFormatModifierPropertiesEXT>(get_device_proc_addr(device.get(),"vkGetImageDrmFormatModifierPropertiesEXT"));
    pfn_CreateValidationCacheEXT = reinterpret_cast<detail::PFN_vkCreateValidationCacheEXT>(get_device_proc_addr(device.get(),"vkCreateValidationCacheEXT"));
    pfn_DestroyValidationCacheEXT = reinterpret_cast<detail::PFN_vkDestroyValidationCacheEXT>(get_device_proc_addr(device.get(),"vkDestroyValidationCacheEXT"));
    pfn_GetValidationCacheDataEXT = reinterpret_cast<detail::PFN_vkGetValidationCacheDataEXT>(get_device_proc_addr(device.get(),"vkGetValidationCacheDataEXT"));
    pfn_MergeValidationCachesEXT = reinterpret_cast<detail::PFN_vkMergeValidationCachesEXT>(get_device_proc_addr(device.get(),"vkMergeValidationCachesEXT"));
    pfn_CmdBindShadingRateImageNV = reinterpret_cast<detail::PFN_vkCmdBindShadingRateImageNV>(get_device_proc_addr(device.get(),"vkCmdBindShadingRateImageNV"));
    pfn_CmdSetViewportShadingRatePaletteNV = reinterpret_cast<detail::PFN_vkCmdSetViewportShadingRatePaletteNV>(get_device_proc_addr(device.get(),"vkCmdSetViewportShadingRatePaletteNV"));
    pfn_CmdSetCoarseSampleOrderNV = reinterpret_cast<detail::PFN_vkCmdSetCoarseSampleOrderNV>(get_device_proc_addr(device.get(),"vkCmdSetCoarseSampleOrderNV"));
    pfn_CompileDeferredNV = reinterpret_cast<detail::PFN_vkCompileDeferredNV>(get_device_proc_addr(device.get(),"vkCompileDeferredNV"));
    pfn_CreateAccelerationStructureNV = reinterpret_cast<detail::PFN_vkCreateAccelerationStructureNV>(get_device_proc_addr(device.get(),"vkCreateAccelerationStructureNV"));
    pfn_GetAccelerationStructureMemoryRequirementsNV = reinterpret_cast<detail::PFN_vkGetAccelerationStructureMemoryRequirementsNV>(get_device_proc_addr(device.get(),"vkGetAccelerationStructureMemoryRequirementsNV"));
    pfn_CmdCopyAccelerationStructureNV = reinterpret_cast<detail::PFN_vkCmdCopyAccelerationStructureNV>(get_device_proc_addr(device.get(),"vkCmdCopyAccelerationStructureNV"));
    pfn_CmdBuildAccelerationStructureNV = reinterpret_cast<detail::PFN_vkCmdBuildAccelerationStructureNV>(get_device_proc_addr(device.get(),"vkCmdBuildAccelerationStructureNV"));
    pfn_CmdTraceRaysNV = reinterpret_cast<detail::PFN_vkCmdTraceRaysNV>(get_device_proc_addr(device.get(),"vkCmdTraceRaysNV"));
    pfn_GetAccelerationStructureHandleNV = reinterpret_cast<detail::PFN_vkGetAccelerationStructureHandleNV>(get_device_proc_addr(device.get(),"vkGetAccelerationStructureHandleNV"));
    pfn_CreateRayTracingPipelinesNV = reinterpret_cast<detail::PFN_vkCreateRayTracingPipelinesNV>(get_device_proc_addr(device.get(),"vkCreateRayTracingPipelinesNV"));
    pfn_GetMemoryHostPointerPropertiesEXT = reinterpret_cast<detail::PFN_vkGetMemoryHostPointerPropertiesEXT>(get_device_proc_addr(device.get(),"vkGetMemoryHostPointerPropertiesEXT"));
    pfn_CmdWriteBufferMarkerAMD = reinterpret_cast<detail::PFN_vkCmdWriteBufferMarkerAMD>(get_device_proc_addr(device.get(),"vkCmdWriteBufferMarkerAMD"));
    pfn_GetCalibratedTimestampsEXT = reinterpret_cast<detail::PFN_vkGetCalibratedTimestampsEXT>(get_device_proc_addr(device.get(),"vkGetCalibratedTimestampsEXT"));
    pfn_CmdDrawMeshTasksNV = reinterpret_cast<detail::PFN_vkCmdDrawMeshTasksNV>(get_device_proc_addr(device.get(),"vkCmdDrawMeshTasksNV"));
    pfn_CmdDrawMeshTasksIndirectNV = reinterpret_cast<detail::PFN_vkCmdDrawMeshTasksIndirectNV>(get_device_proc_addr(device.get(),"vkCmdDrawMeshTasksIndirectNV"));
    pfn_CmdDrawMeshTasksIndirectCountNV = reinterpret_cast<detail::PFN_vkCmdDrawMeshTasksIndirectCountNV>(get_device_proc_addr(device.get(),"vkCmdDrawMeshTasksIndirectCountNV"));
    pfn_CmdSetExclusiveScissorNV = reinterpret_cast<detail::PFN_vkCmdSetExclusiveScissorNV>(get_device_proc_addr(device.get(),"vkCmdSetExclusiveScissorNV"));
    pfn_CmdSetCheckpointNV = reinterpret_cast<detail::PFN_vkCmdSetCheckpointNV>(get_device_proc_addr(device.get(),"vkCmdSetCheckpointNV"));
    pfn_GetQueueCheckpointDataNV = reinterpret_cast<detail::PFN_vkGetQueueCheckpointDataNV>(get_device_proc_addr(device.get(),"vkGetQueueCheckpointDataNV"));
    pfn_InitializePerformanceApiINTEL = reinterpret_cast<detail::PFN_vkInitializePerformanceApiINTEL>(get_device_proc_addr(device.get(),"vkInitializePerformanceApiINTEL"));
    pfn_UninitializePerformanceApiINTEL = reinterpret_cast<detail::PFN_vkUninitializePerformanceApiINTEL>(get_device_proc_addr(device.get(),"vkUninitializePerformanceApiINTEL"));
    pfn_CmdSetPerformanceMarkerINTEL = reinterpret_cast<detail::PFN_vkCmdSetPerformanceMarkerINTEL>(get_device_proc_addr(device.get(),"vkCmdSetPerformanceMarkerINTEL"));
    pfn_CmdSetPerformanceStreamMarkerINTEL = reinterpret_cast<detail::PFN_vkCmdSetPerformanceStreamMarkerINTEL>(get_device_proc_addr(device.get(),"vkCmdSetPerformanceStreamMarkerINTEL"));
    pfn_CmdSetPerformanceOverrideINTEL = reinterpret_cast<detail::PFN_vkCmdSetPerformanceOverrideINTEL>(get_device_proc_addr(device.get(),"vkCmdSetPerformanceOverrideINTEL"));
    pfn_AcquirePerformanceConfigurationINTEL = reinterpret_cast<detail::PFN_vkAcquirePerformanceConfigurationINTEL>(get_device_proc_addr(device.get(),"vkAcquirePerformanceConfigurationINTEL"));
    pfn_ReleasePerformanceConfigurationINTEL = reinterpret_cast<detail::PFN_vkReleasePerformanceConfigurationINTEL>(get_device_proc_addr(device.get(),"vkReleasePerformanceConfigurationINTEL"));
    pfn_QueueSetPerformanceConfigurationINTEL = reinterpret_cast<detail::PFN_vkQueueSetPerformanceConfigurationINTEL>(get_device_proc_addr(device.get(),"vkQueueSetPerformanceConfigurationINTEL"));
    pfn_GetPerformanceParameterINTEL = reinterpret_cast<detail::PFN_vkGetPerformanceParameterINTEL>(get_device_proc_addr(device.get(),"vkGetPerformanceParameterINTEL"));
    pfn_SetLocalDimmingAMD = reinterpret_cast<detail::PFN_vkSetLocalDimmingAMD>(get_device_proc_addr(device.get(),"vkSetLocalDimmingAMD"));
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_AcquireFullScreenExclusiveModeEXT = reinterpret_cast<detail::PFN_vkAcquireFullScreenExclusiveModeEXT>(get_device_proc_addr(device.get(),"vkAcquireFullScreenExclusiveModeEXT"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_ReleaseFullScreenExclusiveModeEXT = reinterpret_cast<detail::PFN_vkReleaseFullScreenExclusiveModeEXT>(get_device_proc_addr(device.get(),"vkReleaseFullScreenExclusiveModeEXT"));
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    pfn_GetDeviceGroupSurfacePresentModes2EXT = reinterpret_cast<detail::PFN_vkGetDeviceGroupSurfacePresentModes2EXT>(get_device_proc_addr(device.get(),"vkGetDeviceGroupSurfacePresentModes2EXT"));
#endif // VK_USE_PLATFORM_WIN32_KHR
    pfn_CmdSetLineStippleEXT = reinterpret_cast<detail::PFN_vkCmdSetLineStippleEXT>(get_device_proc_addr(device.get(),"vkCmdSetLineStippleEXT"));
    pfn_CmdSetCullModeEXT = reinterpret_cast<detail::PFN_vkCmdSetCullModeEXT>(get_device_proc_addr(device.get(),"vkCmdSetCullModeEXT"));
    pfn_CmdSetFrontFaceEXT = reinterpret_cast<detail::PFN_vkCmdSetFrontFaceEXT>(get_device_proc_addr(device.get(),"vkCmdSetFrontFaceEXT"));
    pfn_CmdSetPrimitiveTopologyEXT = reinterpret_cast<detail::PFN_vkCmdSetPrimitiveTopologyEXT>(get_device_proc_addr(device.get(),"vkCmdSetPrimitiveTopologyEXT"));
    pfn_CmdSetViewportWithCountEXT = reinterpret_cast<detail::PFN_vkCmdSetViewportWithCountEXT>(get_device_proc_addr(device.get(),"vkCmdSetViewportWithCountEXT"));
    pfn_CmdSetScissorWithCountEXT = reinterpret_cast<detail::PFN_vkCmdSetScissorWithCountEXT>(get_device_proc_addr(device.get(),"vkCmdSetScissorWithCountEXT"));
    pfn_CmdBindVertexBuffers2EXT = reinterpret_cast<detail::PFN_vkCmdBindVertexBuffers2EXT>(get_device_proc_addr(device.get(),"vkCmdBindVertexBuffers2EXT"));
    pfn_CmdSetDepthTestEnableEXT = reinterpret_cast<detail::PFN_vkCmdSetDepthTestEnableEXT>(get_device_proc_addr(device.get(),"vkCmdSetDepthTestEnableEXT"));
    pfn_CmdSetDepthWriteEnableEXT = reinterpret_cast<detail::PFN_vkCmdSetDepthWriteEnableEXT>(get_device_proc_addr(device.get(),"vkCmdSetDepthWriteEnableEXT"));
    pfn_CmdSetDepthCompareOpEXT = reinterpret_cast<detail::PFN_vkCmdSetDepthCompareOpEXT>(get_device_proc_addr(device.get(),"vkCmdSetDepthCompareOpEXT"));
    pfn_CmdSetDepthBoundsTestEnableEXT = reinterpret_cast<detail::PFN_vkCmdSetDepthBoundsTestEnableEXT>(get_device_proc_addr(device.get(),"vkCmdSetDepthBoundsTestEnableEXT"));
    pfn_CmdSetStencilTestEnableEXT = reinterpret_cast<detail::PFN_vkCmdSetStencilTestEnableEXT>(get_device_proc_addr(device.get(),"vkCmdSetStencilTestEnableEXT"));
    pfn_CmdSetStencilOpEXT = reinterpret_cast<detail::PFN_vkCmdSetStencilOpEXT>(get_device_proc_addr(device.get(),"vkCmdSetStencilOpEXT"));
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_CreateDeferredOperationKHR = reinterpret_cast<detail::PFN_vkCreateDeferredOperationKHR>(get_device_proc_addr(device.get(),"vkCreateDeferredOperationKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_DestroyDeferredOperationKHR = reinterpret_cast<detail::PFN_vkDestroyDeferredOperationKHR>(get_device_proc_addr(device.get(),"vkDestroyDeferredOperationKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetDeferredOperationMaxConcurrencyKHR = reinterpret_cast<detail::PFN_vkGetDeferredOperationMaxConcurrencyKHR>(get_device_proc_addr(device.get(),"vkGetDeferredOperationMaxConcurrencyKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_GetDeferredOperationResultKHR = reinterpret_cast<detail::PFN_vkGetDeferredOperationResultKHR>(get_device_proc_addr(device.get(),"vkGetDeferredOperationResultKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    pfn_DeferredOperationJoinKHR = reinterpret_cast<detail::PFN_vkDeferredOperationJoinKHR>(get_device_proc_addr(device.get(),"vkDeferredOperationJoinKHR"));
#endif // VK_ENABLE_BETA_EXTENSIONS
    pfn_GetPipelineExecutablePropertiesKHR = reinterpret_cast<detail::PFN_vkGetPipelineExecutablePropertiesKHR>(get_device_proc_addr(device.get(),"vkGetPipelineExecutablePropertiesKHR"));
    pfn_GetPipelineExecutableStatisticsKHR = reinterpret_cast<detail::PFN_vkGetPipelineExecutableStatisticsKHR>(get_device_proc_addr(device.get(),"vkGetPipelineExecutableStatisticsKHR"));
    pfn_GetPipelineExecutableInternalRepresentationsKHR = reinterpret_cast<detail::PFN_vkGetPipelineExecutableInternalRepresentationsKHR>(get_device_proc_addr(device.get(),"vkGetPipelineExecutableInternalRepresentationsKHR"));
    pfn_CmdExecuteGeneratedCommandsNV = reinterpret_cast<detail::PFN_vkCmdExecuteGeneratedCommandsNV>(get_device_proc_addr(device.get(),"vkCmdExecuteGeneratedCommandsNV"));
    pfn_CmdPreprocessGeneratedCommandsNV = reinterpret_cast<detail::PFN_vkCmdPreprocessGeneratedCommandsNV>(get_device_proc_addr(device.get(),"vkCmdPreprocessGeneratedCommandsNV"));
    pfn_CmdBindPipelineShaderGroupNV = reinterpret_cast<detail::PFN_vkCmdBindPipelineShaderGroupNV>(get_device_proc_addr(device.get(),"vkCmdBindPipelineShaderGroupNV"));
    pfn_GetGeneratedCommandsMemoryRequirementsNV = reinterpret_cast<detail::PFN_vkGetGeneratedCommandsMemoryRequirementsNV>(get_device_proc_addr(device.get(),"vkGetGeneratedCommandsMemoryRequirementsNV"));
    pfn_CreateIndirectCommandsLayoutNV = reinterpret_cast<detail::PFN_vkCreateIndirectCommandsLayoutNV>(get_device_proc_addr(device.get(),"vkCreateIndirectCommandsLayoutNV"));
    pfn_DestroyIndirectCommandsLayoutNV = reinterpret_cast<detail::PFN_vkDestroyIndirectCommandsLayoutNV>(get_device_proc_addr(device.get(),"vkDestroyIndirectCommandsLayoutNV"));
    pfn_CreatePrivateDataSlotEXT = reinterpret_cast<detail::PFN_vkCreatePrivateDataSlotEXT>(get_device_proc_addr(device.get(),"vkCreatePrivateDataSlotEXT"));
    pfn_DestroyPrivateDataSlotEXT = reinterpret_cast<detail::PFN_vkDestroyPrivateDataSlotEXT>(get_device_proc_addr(device.get(),"vkDestroyPrivateDataSlotEXT"));
    pfn_SetPrivateDataEXT = reinterpret_cast<detail::PFN_vkSetPrivateDataEXT>(get_device_proc_addr(device.get(),"vkSetPrivateDataEXT"));
    pfn_GetPrivateDataEXT = reinterpret_cast<detail::PFN_vkGetPrivateDataEXT>(get_device_proc_addr(device.get(),"vkGetPrivateDataEXT"));
    pfn_CmdCopyBuffer2KHR = reinterpret_cast<detail::PFN_vkCmdCopyBuffer2KHR>(get_device_proc_addr(device.get(),"vkCmdCopyBuffer2KHR"));
    pfn_CmdCopyImage2KHR = reinterpret_cast<detail::PFN_vkCmdCopyImage2KHR>(get_device_proc_addr(device.get(),"vkCmdCopyImage2KHR"));
    pfn_CmdBlitImage2KHR = reinterpret_cast<detail::PFN_vkCmdBlitImage2KHR>(get_device_proc_addr(device.get(),"vkCmdBlitImage2KHR"));
    pfn_CmdCopyBufferToImage2KHR = reinterpret_cast<detail::PFN_vkCmdCopyBufferToImage2KHR>(get_device_proc_addr(device.get(),"vkCmdCopyBufferToImage2KHR"));
    pfn_CmdCopyImageToBuffer2KHR = reinterpret_cast<detail::PFN_vkCmdCopyImageToBuffer2KHR>(get_device_proc_addr(device.get(),"vkCmdCopyImageToBuffer2KHR"));
    pfn_CmdResolveImage2KHR = reinterpret_cast<detail::PFN_vkCmdResolveImage2KHR>(get_device_proc_addr(device.get(),"vkCmdResolveImage2KHR"));
}
PhysicalDeviceFunctions::PhysicalDeviceFunctions() noexcept {}
PhysicalDeviceFunctions::PhysicalDeviceFunctions(InstanceFunctions const& instance_functions, PhysicalDevice const physicaldevice) noexcept
    :instance_functions(&instance_functions), physicaldevice(physicaldevice){}
[[nodiscard]] PhysicalDeviceProperties PhysicalDeviceFunctions::GetProperties() const {
    return instance_functions->GetPhysicalDeviceProperties(physicaldevice); }
[[nodiscard]] detail::fixed_vector<QueueFamilyProperties> PhysicalDeviceFunctions::GetQueueFamilyProperties() const {
    return instance_functions->GetPhysicalDeviceQueueFamilyProperties(physicaldevice); }
[[nodiscard]] PhysicalDeviceMemoryProperties PhysicalDeviceFunctions::GetMemoryProperties() const {
    return instance_functions->GetPhysicalDeviceMemoryProperties(physicaldevice); }
[[nodiscard]] PhysicalDeviceFeatures PhysicalDeviceFunctions::GetFeatures() const {
    return instance_functions->GetPhysicalDeviceFeatures(physicaldevice); }
[[nodiscard]] FormatProperties PhysicalDeviceFunctions::GetFormatProperties(Format format) const {
    return instance_functions->GetPhysicalDeviceFormatProperties(physicaldevice, format); }
[[nodiscard]] expected<ImageFormatProperties> PhysicalDeviceFunctions::GetImageFormatProperties(Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags) const {
    return instance_functions->GetPhysicalDeviceImageFormatProperties(physicaldevice, format, type, tiling, usage, flags); }
[[nodiscard]] expected<Device> PhysicalDeviceFunctions::CreateDevice(const DeviceCreateInfo&  pCreateInfo, const AllocationCallbacks* pAllocator) const {
    return instance_functions->CreateDevice(physicaldevice, pCreateInfo, pAllocator); }
[[nodiscard]] expected<detail::fixed_vector<ExtensionProperties>> PhysicalDeviceFunctions::EnumerateDeviceExtensionProperties(const char* pLayerName) const {
    return instance_functions->EnumerateDeviceExtensionProperties(physicaldevice, pLayerName); }
[[nodiscard]] detail::fixed_vector<SparseImageFormatProperties> PhysicalDeviceFunctions::GetSparseImageFormatProperties(Format format, ImageType type, SampleCountFlagBits samples, ImageUsageFlags usage, ImageTiling tiling) const {
    return instance_functions->GetPhysicalDeviceSparseImageFormatProperties(physicaldevice, format, type, samples, usage, tiling); }
[[nodiscard]] expected<detail::fixed_vector<DisplayPropertiesKHR>> PhysicalDeviceFunctions::GetDisplayPropertiesKHR() const {
    return instance_functions->GetPhysicalDeviceDisplayPropertiesKHR(physicaldevice); }
[[nodiscard]] expected<detail::fixed_vector<DisplayPlanePropertiesKHR>> PhysicalDeviceFunctions::GetDisplayPlanePropertiesKHR() const {
    return instance_functions->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicaldevice); }
[[nodiscard]] expected<detail::fixed_vector<DisplayKHR>> PhysicalDeviceFunctions::GetDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex) const {
    return instance_functions->GetDisplayPlaneSupportedDisplaysKHR(physicaldevice, planeIndex); }
[[nodiscard]] expected<detail::fixed_vector<DisplayModePropertiesKHR>> PhysicalDeviceFunctions::GetDisplayModePropertiesKHR(DisplayKHR display) const {
    return instance_functions->GetDisplayModePropertiesKHR(physicaldevice, display); }
[[nodiscard]] expected<DisplayModeKHR> PhysicalDeviceFunctions::CreateDisplayModeKHR(DisplayKHR display, const DisplayModeCreateInfoKHR&  pCreateInfo, const AllocationCallbacks* pAllocator) const {
    return instance_functions->CreateDisplayModeKHR(physicaldevice, display, pCreateInfo, pAllocator); }
[[nodiscard]] expected<DisplayPlaneCapabilitiesKHR> PhysicalDeviceFunctions::GetDisplayPlaneCapabilitiesKHR(DisplayModeKHR mode, uint32_t planeIndex) const {
    return instance_functions->GetDisplayPlaneCapabilitiesKHR(physicaldevice, mode, planeIndex); }
[[nodiscard]] expected<Bool32> PhysicalDeviceFunctions::GetSurfaceSupportKHR(uint32_t queueFamilyIndex, SurfaceKHR surface) const {
    return instance_functions->GetPhysicalDeviceSurfaceSupportKHR(physicaldevice, queueFamilyIndex, surface); }
[[nodiscard]] expected<SurfaceCapabilitiesKHR> PhysicalDeviceFunctions::GetSurfaceCapabilitiesKHR(SurfaceKHR surface) const {
    return instance_functions->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicaldevice, surface); }
[[nodiscard]] expected<detail::fixed_vector<SurfaceFormatKHR>> PhysicalDeviceFunctions::GetSurfaceFormatsKHR(SurfaceKHR surface) const {
    return instance_functions->GetPhysicalDeviceSurfaceFormatsKHR(physicaldevice, surface); }
[[nodiscard]] expected<detail::fixed_vector<PresentModeKHR>> PhysicalDeviceFunctions::GetSurfacePresentModesKHR(SurfaceKHR surface) const {
    return instance_functions->GetPhysicalDeviceSurfacePresentModesKHR(physicaldevice, surface); }
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
[[nodiscard]] wl_display PhysicalDeviceFunctions::GetWaylandPresentationSupportKHR(uint32_t queueFamilyIndex) const {
    return instance_functions->GetPhysicalDeviceWaylandPresentationSupportKHR(physicaldevice, queueFamilyIndex); }
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] VkBool32 PhysicalDeviceFunctions::GetWin32PresentationSupportKHR(uint32_t queueFamilyIndex) const {
    return instance_functions->GetPhysicalDeviceWin32PresentationSupportKHR(physicaldevice, queueFamilyIndex); }
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_XLIB_KHR)
[[nodiscard]] VkBool32 PhysicalDeviceFunctions::GetXlibPresentationSupportKHR(uint32_t queueFamilyIndex, Display&  dpy, VisualID visualID) const {
    return instance_functions->GetPhysicalDeviceXlibPresentationSupportKHR(physicaldevice, queueFamilyIndex, dpy, visualID); }
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
[[nodiscard]] VkBool32 PhysicalDeviceFunctions::GetXcbPresentationSupportKHR(uint32_t queueFamilyIndex, xcb_connection_t&  connection, xcb_visualid_t visual_id) const {
    return instance_functions->GetPhysicalDeviceXcbPresentationSupportKHR(physicaldevice, queueFamilyIndex, connection, visual_id); }
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
[[nodiscard]] IDirectFB PhysicalDeviceFunctions::GetDirectFBPresentationSupportEXT(uint32_t queueFamilyIndex) const {
    return instance_functions->GetPhysicalDeviceDirectFBPresentationSupportEXT(physicaldevice, queueFamilyIndex); }
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
[[nodiscard]] expected<ExternalImageFormatPropertiesNV> PhysicalDeviceFunctions::GetExternalImageFormatPropertiesNV(Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags, ExternalMemoryHandleTypeFlagsNV externalHandleType) const {
    return instance_functions->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicaldevice, format, type, tiling, usage, flags, externalHandleType); }
[[nodiscard]] PhysicalDeviceFeatures2 PhysicalDeviceFunctions::GetFeatures2() const {
    return instance_functions->GetPhysicalDeviceFeatures2(physicaldevice); }
[[nodiscard]] PhysicalDeviceProperties2 PhysicalDeviceFunctions::GetProperties2() const {
    return instance_functions->GetPhysicalDeviceProperties2(physicaldevice); }
[[nodiscard]] FormatProperties2 PhysicalDeviceFunctions::GetFormatProperties2(Format format) const {
    return instance_functions->GetPhysicalDeviceFormatProperties2(physicaldevice, format); }
[[nodiscard]] expected<ImageFormatProperties2> PhysicalDeviceFunctions::GetImageFormatProperties2(const PhysicalDeviceImageFormatInfo2&  pImageFormatInfo) const {
    return instance_functions->GetPhysicalDeviceImageFormatProperties2(physicaldevice, pImageFormatInfo); }
[[nodiscard]] detail::fixed_vector<QueueFamilyProperties2> PhysicalDeviceFunctions::GetQueueFamilyProperties2() const {
    return instance_functions->GetPhysicalDeviceQueueFamilyProperties2(physicaldevice); }
[[nodiscard]] PhysicalDeviceMemoryProperties2 PhysicalDeviceFunctions::GetMemoryProperties2() const {
    return instance_functions->GetPhysicalDeviceMemoryProperties2(physicaldevice); }
[[nodiscard]] detail::fixed_vector<SparseImageFormatProperties2> PhysicalDeviceFunctions::GetSparseImageFormatProperties2(const PhysicalDeviceSparseImageFormatInfo2&  pFormatInfo) const {
    return instance_functions->GetPhysicalDeviceSparseImageFormatProperties2(physicaldevice, pFormatInfo); }
[[nodiscard]] ExternalBufferProperties PhysicalDeviceFunctions::GetExternalBufferProperties(const PhysicalDeviceExternalBufferInfo&  pExternalBufferInfo) const {
    return instance_functions->GetPhysicalDeviceExternalBufferProperties(physicaldevice, pExternalBufferInfo); }
[[nodiscard]] ExternalSemaphoreProperties PhysicalDeviceFunctions::GetExternalSemaphoreProperties(const PhysicalDeviceExternalSemaphoreInfo&  pExternalSemaphoreInfo) const {
    return instance_functions->GetPhysicalDeviceExternalSemaphoreProperties(physicaldevice, pExternalSemaphoreInfo); }
[[nodiscard]] ExternalFenceProperties PhysicalDeviceFunctions::GetExternalFenceProperties(const PhysicalDeviceExternalFenceInfo&  pExternalFenceInfo) const {
    return instance_functions->GetPhysicalDeviceExternalFenceProperties(physicaldevice, pExternalFenceInfo); }
[[nodiscard]] Result PhysicalDeviceFunctions::ReleaseDisplayEXT(DisplayKHR display) const {
    return instance_functions->ReleaseDisplayEXT(physicaldevice, display); }
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
[[nodiscard]] Result PhysicalDeviceFunctions::AcquireXlibDisplayEXT(Display&  dpy, DisplayKHR display) const {
    return instance_functions->AcquireXlibDisplayEXT(physicaldevice, dpy, display); }
[[nodiscard]] expected<DisplayKHR> PhysicalDeviceFunctions::GetRandROutputDisplayEXT(Display&  dpy, RROutput rrOutput) const {
    return instance_functions->GetRandROutputDisplayEXT(physicaldevice, dpy, rrOutput); }
#endif // defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
[[nodiscard]] expected<SurfaceCapabilities2EXT> PhysicalDeviceFunctions::GetSurfaceCapabilities2EXT(SurfaceKHR surface) const {
    return instance_functions->GetPhysicalDeviceSurfaceCapabilities2EXT(physicaldevice, surface); }
[[nodiscard]] expected<detail::fixed_vector<Rect2D>> PhysicalDeviceFunctions::GetPresentRectanglesKHR(SurfaceKHR surface) const {
    return instance_functions->GetPhysicalDevicePresentRectanglesKHR(physicaldevice, surface); }
[[nodiscard]] MultisamplePropertiesEXT PhysicalDeviceFunctions::GetMultisamplePropertiesEXT(SampleCountFlagBits samples) const {
    return instance_functions->GetPhysicalDeviceMultisamplePropertiesEXT(physicaldevice, samples); }
[[nodiscard]] expected<SurfaceCapabilities2KHR> PhysicalDeviceFunctions::GetSurfaceCapabilities2KHR(const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    return instance_functions->GetPhysicalDeviceSurfaceCapabilities2KHR(physicaldevice, pSurfaceInfo); }
[[nodiscard]] expected<detail::fixed_vector<SurfaceFormat2KHR>> PhysicalDeviceFunctions::GetSurfaceFormats2KHR(const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    return instance_functions->GetPhysicalDeviceSurfaceFormats2KHR(physicaldevice, pSurfaceInfo); }
[[nodiscard]] expected<detail::fixed_vector<DisplayProperties2KHR>> PhysicalDeviceFunctions::GetDisplayProperties2KHR() const {
    return instance_functions->GetPhysicalDeviceDisplayProperties2KHR(physicaldevice); }
[[nodiscard]] expected<detail::fixed_vector<DisplayPlaneProperties2KHR>> PhysicalDeviceFunctions::GetDisplayPlaneProperties2KHR() const {
    return instance_functions->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicaldevice); }
[[nodiscard]] expected<detail::fixed_vector<DisplayModeProperties2KHR>> PhysicalDeviceFunctions::GetDisplayModeProperties2KHR(DisplayKHR display) const {
    return instance_functions->GetDisplayModeProperties2KHR(physicaldevice, display); }
[[nodiscard]] expected<DisplayPlaneCapabilities2KHR> PhysicalDeviceFunctions::GetDisplayPlaneCapabilities2KHR(const DisplayPlaneInfo2KHR&  pDisplayPlaneInfo) const {
    return instance_functions->GetDisplayPlaneCapabilities2KHR(physicaldevice, pDisplayPlaneInfo); }
[[nodiscard]] expected<detail::fixed_vector<TimeDomainEXT>> PhysicalDeviceFunctions::GetCalibrateableTimeDomainsEXT() const {
    return instance_functions->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicaldevice); }
[[nodiscard]] expected<detail::fixed_vector<CooperativeMatrixPropertiesNV>> PhysicalDeviceFunctions::GetCooperativeMatrixPropertiesNV() const {
    return instance_functions->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicaldevice); }
#if defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] expected<detail::fixed_vector<PresentModeKHR>> PhysicalDeviceFunctions::GetSurfacePresentModes2EXT(const PhysicalDeviceSurfaceInfo2KHR&  pSurfaceInfo) const {
    return instance_functions->GetPhysicalDeviceSurfacePresentModes2EXT(physicaldevice, pSurfaceInfo); }
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
[[nodiscard]] Result PhysicalDeviceFunctions::EnumerateQueueFamilyPerformanceQueryCountersKHR(uint32_t queueFamilyIndex, uint32_t&  pCounterCount, PerformanceCounterKHR* pCounters, PerformanceCounterDescriptionKHR* pCounterDescriptions) const {
    return instance_functions->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicaldevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions); }
[[nodiscard]] uint32_t PhysicalDeviceFunctions::GetQueueFamilyPerformanceQueryPassesKHR(const QueryPoolPerformanceCreateInfoKHR&  pPerformanceQueryCreateInfo) const {
    return instance_functions->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicaldevice, pPerformanceQueryCreateInfo); }
[[nodiscard]] expected<detail::fixed_vector<FramebufferMixedSamplesCombinationNV>> PhysicalDeviceFunctions::GetSupportedFramebufferMixedSamplesCombinationsNV() const {
    return instance_functions->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicaldevice); }
[[nodiscard]] expected<detail::fixed_vector<PhysicalDeviceToolPropertiesEXT>> PhysicalDeviceFunctions::GetToolPropertiesEXT() const {
    return instance_functions->GetPhysicalDeviceToolPropertiesEXT(physicaldevice); }
QueueFunctions::QueueFunctions() noexcept {}
QueueFunctions::QueueFunctions(DeviceFunctions const& device_functions, Queue const queue) noexcept
    :device_functions(&device_functions), queue(queue){}
[[nodiscard]] Result QueueFunctions::Submit(uint32_t submitCount, const SubmitInfo* pSubmits, Fence fence) const {
    return device_functions->QueueSubmit(queue, submitCount, pSubmits, fence); }
[[nodiscard]] Result QueueFunctions::WaitIdle() const {
    return device_functions->QueueWaitIdle(queue); }
[[nodiscard]] Result QueueFunctions::BindSparse(uint32_t bindInfoCount, const BindSparseInfo* pBindInfo, Fence fence) const {
    return device_functions->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence); }
[[nodiscard]] Result QueueFunctions::PresentKHR(const PresentInfoKHR&  pPresentInfo) const {
    return device_functions->QueuePresentKHR(queue, pPresentInfo); }
void QueueFunctions::BeginDebugUtilsLabelEXT(const DebugUtilsLabelEXT&  pLabelInfo) const {
    device_functions->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo); }
void QueueFunctions::EndDebugUtilsLabelEXT() const {
    device_functions->QueueEndDebugUtilsLabelEXT(queue); }
void QueueFunctions::InsertDebugUtilsLabelEXT(const DebugUtilsLabelEXT&  pLabelInfo) const {
    device_functions->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo); }
[[nodiscard]] detail::fixed_vector<CheckpointDataNV> QueueFunctions::GetCheckpointDataNV() const {
    return device_functions->GetQueueCheckpointDataNV(queue); }
[[nodiscard]] Result QueueFunctions::SetPerformanceConfigurationINTEL(PerformanceConfigurationINTEL configuration) const {
    return device_functions->QueueSetPerformanceConfigurationINTEL(queue, configuration); }
CommandBufferFunctions::CommandBufferFunctions() noexcept {}
CommandBufferFunctions::CommandBufferFunctions(DeviceFunctions const& device_functions, CommandBuffer const commandbuffer) noexcept
    :device_functions(&device_functions), commandbuffer(commandbuffer){}
[[nodiscard]] Result CommandBufferFunctions::Begin(const CommandBufferBeginInfo&  pBeginInfo) const {
    return device_functions->BeginCommandBuffer(commandbuffer, pBeginInfo); }
[[nodiscard]] Result CommandBufferFunctions::End() const {
    return device_functions->EndCommandBuffer(commandbuffer); }
[[nodiscard]] Result CommandBufferFunctions::Reset(CommandBufferResetFlags flags) const {
    return device_functions->ResetCommandBuffer(commandbuffer, flags); }
CommandBufferFunctions const& CommandBufferFunctions::BindPipeline(PipelineBindPoint pipelineBindPoint, Pipeline pipeline) const {
    device_functions->CmdBindPipeline(commandbuffer, pipelineBindPoint, pipeline);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetViewport(uint32_t firstViewport, uint32_t viewportCount, const Viewport* pViewports) const {
    device_functions->CmdSetViewport(commandbuffer, firstViewport, viewportCount, pViewports);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetScissor(uint32_t firstScissor, uint32_t scissorCount, const Rect2D* pScissors) const {
    device_functions->CmdSetScissor(commandbuffer, firstScissor, scissorCount, pScissors);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetLineWidth(float lineWidth) const {
    device_functions->CmdSetLineWidth(commandbuffer, lineWidth);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) const {
    device_functions->CmdSetDepthBias(commandbuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetBlendConstants(const float blendConstants[4]) const {
    device_functions->CmdSetBlendConstants(commandbuffer, blendConstants);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDepthBounds(float minDepthBounds, float maxDepthBounds) const {
    device_functions->CmdSetDepthBounds(commandbuffer, minDepthBounds, maxDepthBounds);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetStencilCompareMask(StencilFaceFlags faceMask, uint32_t compareMask) const {
    device_functions->CmdSetStencilCompareMask(commandbuffer, faceMask, compareMask);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetStencilWriteMask(StencilFaceFlags faceMask, uint32_t writeMask) const {
    device_functions->CmdSetStencilWriteMask(commandbuffer, faceMask, writeMask);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetStencilReference(StencilFaceFlags faceMask, uint32_t reference) const {
    device_functions->CmdSetStencilReference(commandbuffer, faceMask, reference);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindDescriptorSets(PipelineBindPoint pipelineBindPoint, PipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const DescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) const {
    device_functions->CmdBindDescriptorSets(commandbuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindIndexBuffer(Buffer buffer, DeviceSize offset, IndexType indexType) const {
    device_functions->CmdBindIndexBuffer(commandbuffer, buffer, offset, indexType);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindVertexBuffers(uint32_t firstBinding, uint32_t bindingCount, const Buffer* pBuffers, const DeviceSize* pOffsets) const {
    device_functions->CmdBindVertexBuffers(commandbuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    device_functions->CmdDraw(commandbuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) const {
    device_functions->CmdDrawIndexed(commandbuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawIndirect(Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
    device_functions->CmdDrawIndirect(commandbuffer, buffer, offset, drawCount, stride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawIndexedIndirect(Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
    device_functions->CmdDrawIndexedIndirect(commandbuffer, buffer, offset, drawCount, stride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::Dispatch(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
    device_functions->CmdDispatch(commandbuffer, groupCountX, groupCountY, groupCountZ);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DispatchIndirect(Buffer buffer, DeviceSize offset) const {
    device_functions->CmdDispatchIndirect(commandbuffer, buffer, offset);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyBuffer(Buffer srcBuffer, Buffer dstBuffer, uint32_t regionCount, const BufferCopy* pRegions) const {
    device_functions->CmdCopyBuffer(commandbuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyImage(Image srcImage, ImageLayout srcImageLayout, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const ImageCopy* pRegions) const {
    device_functions->CmdCopyImage(commandbuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BlitImage(Image srcImage, ImageLayout srcImageLayout, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const ImageBlit* pRegions, Filter filter) const {
    device_functions->CmdBlitImage(commandbuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyBufferToImage(Buffer srcBuffer, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const BufferImageCopy* pRegions) const {
    device_functions->CmdCopyBufferToImage(commandbuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyImageToBuffer(Image srcImage, ImageLayout srcImageLayout, Buffer dstBuffer, uint32_t regionCount, const BufferImageCopy* pRegions) const {
    device_functions->CmdCopyImageToBuffer(commandbuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::UpdateBuffer(Buffer dstBuffer, DeviceSize dstOffset, DeviceSize dataSize, const void* pData) const {
    device_functions->CmdUpdateBuffer(commandbuffer, dstBuffer, dstOffset, dataSize, pData);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::FillBuffer(Buffer dstBuffer, DeviceSize dstOffset, DeviceSize size, uint32_t data) const {
    device_functions->CmdFillBuffer(commandbuffer, dstBuffer, dstOffset, size, data);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ClearColorImage(Image image, ImageLayout imageLayout, const ClearColorValue&  pColor, uint32_t rangeCount, const ImageSubresourceRange* pRanges) const {
    device_functions->CmdClearColorImage(commandbuffer, image, imageLayout, pColor, rangeCount, pRanges);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ClearDepthStencilImage(Image image, ImageLayout imageLayout, const ClearDepthStencilValue&  pDepthStencil, uint32_t rangeCount, const ImageSubresourceRange* pRanges) const {
    device_functions->CmdClearDepthStencilImage(commandbuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ClearAttachments(uint32_t attachmentCount, const ClearAttachment* pAttachments, uint32_t rectCount, const ClearRect* pRects) const {
    device_functions->CmdClearAttachments(commandbuffer, attachmentCount, pAttachments, rectCount, pRects);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ResolveImage(Image srcImage, ImageLayout srcImageLayout, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const ImageResolve* pRegions) const {
    device_functions->CmdResolveImage(commandbuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetEvent(Event event, PipelineStageFlags stageMask) const {
    device_functions->CmdSetEvent(commandbuffer, event, stageMask);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ResetEvent(Event event, PipelineStageFlags stageMask) const {
    device_functions->CmdResetEvent(commandbuffer, event, stageMask);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::WaitEvents(uint32_t eventCount, const Event* pEvents, PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const MemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const BufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const ImageMemoryBarrier* pImageMemoryBarriers) const {
    device_functions->CmdWaitEvents(commandbuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::PipelineBarrier(PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, DependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const MemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const BufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const ImageMemoryBarrier* pImageMemoryBarriers) const {
    device_functions->CmdPipelineBarrier(commandbuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginQuery(QueryPool queryPool, uint32_t query, QueryControlFlags flags) const {
    device_functions->CmdBeginQuery(commandbuffer, queryPool, query, flags);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndQuery(QueryPool queryPool, uint32_t query) const {
    device_functions->CmdEndQuery(commandbuffer, queryPool, query);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginConditionalRenderingEXT(const ConditionalRenderingBeginInfoEXT&  pConditionalRenderingBegin) const {
    device_functions->CmdBeginConditionalRenderingEXT(commandbuffer, pConditionalRenderingBegin);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndConditionalRenderingEXT() const {
    device_functions->CmdEndConditionalRenderingEXT(commandbuffer);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ResetQueryPool(QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const {
    device_functions->CmdResetQueryPool(commandbuffer, queryPool, firstQuery, queryCount);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::WriteTimestamp(PipelineStageFlagBits pipelineStage, QueryPool queryPool, uint32_t query) const {
    device_functions->CmdWriteTimestamp(commandbuffer, pipelineStage, queryPool, query);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyQueryPoolResults(QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, Buffer dstBuffer, DeviceSize dstOffset, DeviceSize stride, QueryResultFlags flags) const {
    device_functions->CmdCopyQueryPoolResults(commandbuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::PushConstants(PipelineLayout layout, ShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) const {
    device_functions->CmdPushConstants(commandbuffer, layout, stageFlags, offset, size, pValues);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginRenderPass(const RenderPassBeginInfo&  pRenderPassBegin, SubpassContents contents) const {
    device_functions->CmdBeginRenderPass(commandbuffer, pRenderPassBegin, contents);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::NextSubpass(SubpassContents contents) const {
    device_functions->CmdNextSubpass(commandbuffer, contents);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndRenderPass() const {
    device_functions->CmdEndRenderPass(commandbuffer);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ExecuteCommands(uint32_t commandBufferCount, const CommandBuffer* pCommandBuffers) const {
    device_functions->CmdExecuteCommands(commandbuffer, commandBufferCount, pCommandBuffers);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DebugMarkerBeginEXT(const DebugMarkerMarkerInfoEXT&  pMarkerInfo) const {
    device_functions->CmdDebugMarkerBeginEXT(commandbuffer, pMarkerInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DebugMarkerEndEXT() const {
    device_functions->CmdDebugMarkerEndEXT(commandbuffer);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DebugMarkerInsertEXT(const DebugMarkerMarkerInfoEXT&  pMarkerInfo) const {
    device_functions->CmdDebugMarkerInsertEXT(commandbuffer, pMarkerInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ExecuteGeneratedCommandsNV(Bool32 isPreprocessed, const GeneratedCommandsInfoNV&  pGeneratedCommandsInfo) const {
    device_functions->CmdExecuteGeneratedCommandsNV(commandbuffer, isPreprocessed, pGeneratedCommandsInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::PreprocessGeneratedCommandsNV(const GeneratedCommandsInfoNV&  pGeneratedCommandsInfo) const {
    device_functions->CmdPreprocessGeneratedCommandsNV(commandbuffer, pGeneratedCommandsInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindPipelineShaderGroupNV(PipelineBindPoint pipelineBindPoint, Pipeline pipeline, uint32_t groupIndex) const {
    device_functions->CmdBindPipelineShaderGroupNV(commandbuffer, pipelineBindPoint, pipeline, groupIndex);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::PushDescriptorSetKHR(PipelineBindPoint pipelineBindPoint, PipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const WriteDescriptorSet* pDescriptorWrites) const {
    device_functions->CmdPushDescriptorSetKHR(commandbuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDeviceMask(uint32_t deviceMask) const {
    device_functions->CmdSetDeviceMask(commandbuffer, deviceMask);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DispatchBase(uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
    device_functions->CmdDispatchBase(commandbuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::PushDescriptorSetWithTemplateKHR(DescriptorUpdateTemplate descriptorUpdateTemplate, PipelineLayout layout, uint32_t set, const void* pData) const {
    device_functions->CmdPushDescriptorSetWithTemplateKHR(commandbuffer, descriptorUpdateTemplate, layout, set, pData);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetViewportWScalingNV(uint32_t firstViewport, uint32_t viewportCount, const ViewportWScalingNV* pViewportWScalings) const {
    device_functions->CmdSetViewportWScalingNV(commandbuffer, firstViewport, viewportCount, pViewportWScalings);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDiscardRectangleEXT(uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const Rect2D* pDiscardRectangles) const {
    device_functions->CmdSetDiscardRectangleEXT(commandbuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetSampleLocationsEXT(const SampleLocationsInfoEXT&  pSampleLocationsInfo) const {
    device_functions->CmdSetSampleLocationsEXT(commandbuffer, pSampleLocationsInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginDebugUtilsLabelEXT(const DebugUtilsLabelEXT&  pLabelInfo) const {
    device_functions->CmdBeginDebugUtilsLabelEXT(commandbuffer, pLabelInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndDebugUtilsLabelEXT() const {
    device_functions->CmdEndDebugUtilsLabelEXT(commandbuffer);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::InsertDebugUtilsLabelEXT(const DebugUtilsLabelEXT&  pLabelInfo) const {
    device_functions->CmdInsertDebugUtilsLabelEXT(commandbuffer, pLabelInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::WriteBufferMarkerAMD(PipelineStageFlagBits pipelineStage, Buffer dstBuffer, DeviceSize dstOffset, uint32_t marker) const {
    device_functions->CmdWriteBufferMarkerAMD(commandbuffer, pipelineStage, dstBuffer, dstOffset, marker);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginRenderPass2(const RenderPassBeginInfo&  pRenderPassBegin, const SubpassBeginInfo&  pSubpassBeginInfo) const {
    device_functions->CmdBeginRenderPass2(commandbuffer, pRenderPassBegin, pSubpassBeginInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::NextSubpass2(const SubpassBeginInfo&  pSubpassBeginInfo, const SubpassEndInfo&  pSubpassEndInfo) const {
    device_functions->CmdNextSubpass2(commandbuffer, pSubpassBeginInfo, pSubpassEndInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndRenderPass2(const SubpassEndInfo&  pSubpassEndInfo) const {
    device_functions->CmdEndRenderPass2(commandbuffer, pSubpassEndInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawIndirectCount(Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
    device_functions->CmdDrawIndirectCount(commandbuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawIndexedIndirectCount(Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
    device_functions->CmdDrawIndexedIndirectCount(commandbuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetCheckpointNV(const void* pCheckpointMarker) const {
    device_functions->CmdSetCheckpointNV(commandbuffer, pCheckpointMarker);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindTransformFeedbackBuffersEXT(uint32_t firstBinding, uint32_t bindingCount, const Buffer* pBuffers, const DeviceSize* pOffsets, const DeviceSize* pSizes) const {
    device_functions->CmdBindTransformFeedbackBuffersEXT(commandbuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginTransformFeedbackEXT(uint32_t firstCounterBuffer, uint32_t counterBufferCount, const Buffer* pCounterBuffers, const DeviceSize* pCounterBufferOffsets) const {
    device_functions->CmdBeginTransformFeedbackEXT(commandbuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndTransformFeedbackEXT(uint32_t firstCounterBuffer, uint32_t counterBufferCount, const Buffer* pCounterBuffers, const DeviceSize* pCounterBufferOffsets) const {
    device_functions->CmdEndTransformFeedbackEXT(commandbuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BeginQueryIndexedEXT(QueryPool queryPool, uint32_t query, QueryControlFlags flags, uint32_t index) const {
    device_functions->CmdBeginQueryIndexedEXT(commandbuffer, queryPool, query, flags, index);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::EndQueryIndexedEXT(QueryPool queryPool, uint32_t query, uint32_t index) const {
    device_functions->CmdEndQueryIndexedEXT(commandbuffer, queryPool, query, index);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawIndirectByteCountEXT(uint32_t instanceCount, uint32_t firstInstance, Buffer counterBuffer, DeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) const {
    device_functions->CmdDrawIndirectByteCountEXT(commandbuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetExclusiveScissorNV(uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const Rect2D* pExclusiveScissors) const {
    device_functions->CmdSetExclusiveScissorNV(commandbuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindShadingRateImageNV(ImageView imageView, ImageLayout imageLayout) const {
    device_functions->CmdBindShadingRateImageNV(commandbuffer, imageView, imageLayout);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetViewportShadingRatePaletteNV(uint32_t firstViewport, uint32_t viewportCount, const ShadingRatePaletteNV* pShadingRatePalettes) const {
    device_functions->CmdSetViewportShadingRatePaletteNV(commandbuffer, firstViewport, viewportCount, pShadingRatePalettes);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetCoarseSampleOrderNV(CoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const CoarseSampleOrderCustomNV* pCustomSampleOrders) const {
    device_functions->CmdSetCoarseSampleOrderNV(commandbuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawMeshTasksNV(uint32_t taskCount, uint32_t firstTask) const {
    device_functions->CmdDrawMeshTasksNV(commandbuffer, taskCount, firstTask);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawMeshTasksIndirectNV(Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
    device_functions->CmdDrawMeshTasksIndirectNV(commandbuffer, buffer, offset, drawCount, stride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::DrawMeshTasksIndirectCountNV(Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
    device_functions->CmdDrawMeshTasksIndirectCountNV(commandbuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyAccelerationStructureNV(AccelerationStructureKHR dst, AccelerationStructureKHR src, CopyAccelerationStructureModeKHR mode) const {
    device_functions->CmdCopyAccelerationStructureNV(commandbuffer, dst, src, mode);
    return *this; }
#if defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::CopyAccelerationStructureKHR(const CopyAccelerationStructureInfoKHR&  pInfo) const {
    device_functions->CmdCopyAccelerationStructureKHR(commandbuffer, pInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyAccelerationStructureToMemoryKHR(const CopyAccelerationStructureToMemoryInfoKHR&  pInfo) const {
    device_functions->CmdCopyAccelerationStructureToMemoryKHR(commandbuffer, pInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyMemoryToAccelerationStructureKHR(const CopyMemoryToAccelerationStructureInfoKHR&  pInfo) const {
    device_functions->CmdCopyMemoryToAccelerationStructureKHR(commandbuffer, pInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::WriteAccelerationStructuresPropertiesKHR(uint32_t accelerationStructureCount, const AccelerationStructureKHR* pAccelerationStructures, QueryType queryType, QueryPool queryPool, uint32_t firstQuery) const {
    device_functions->CmdWriteAccelerationStructuresPropertiesKHR(commandbuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    return *this; }
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::BuildAccelerationStructureNV(const AccelerationStructureInfoNV&  pInfo, Buffer instanceData, DeviceSize instanceOffset, Bool32 update, AccelerationStructureKHR dst, AccelerationStructureKHR src, Buffer scratch, DeviceSize scratchOffset) const {
    device_functions->CmdBuildAccelerationStructureNV(commandbuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    return *this; }
#if defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::TraceRaysKHR(const StridedBufferRegionKHR&  pRaygenShaderBindingTable, const StridedBufferRegionKHR&  pMissShaderBindingTable, const StridedBufferRegionKHR&  pHitShaderBindingTable, const StridedBufferRegionKHR&  pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) const {
    device_functions->CmdTraceRaysKHR(commandbuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    return *this; }
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::TraceRaysNV(Buffer raygenShaderBindingTableBuffer, DeviceSize raygenShaderBindingOffset, Buffer missShaderBindingTableBuffer, DeviceSize missShaderBindingOffset, DeviceSize missShaderBindingStride, Buffer hitShaderBindingTableBuffer, DeviceSize hitShaderBindingOffset, DeviceSize hitShaderBindingStride, Buffer callableShaderBindingTableBuffer, DeviceSize callableShaderBindingOffset, DeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) const {
    device_functions->CmdTraceRaysNV(commandbuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    return *this; }
#if defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::TraceRaysIndirectKHR(const StridedBufferRegionKHR&  pRaygenShaderBindingTable, const StridedBufferRegionKHR&  pMissShaderBindingTable, const StridedBufferRegionKHR&  pHitShaderBindingTable, const StridedBufferRegionKHR&  pCallableShaderBindingTable, Buffer buffer, DeviceSize offset) const {
    device_functions->CmdTraceRaysIndirectKHR(commandbuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer, offset);
    return *this; }
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
[[nodiscard]] Result CommandBufferFunctions::SetPerformanceMarkerINTEL(const PerformanceMarkerInfoINTEL&  pMarkerInfo) const {
    return device_functions->CmdSetPerformanceMarkerINTEL(commandbuffer, pMarkerInfo); }
[[nodiscard]] Result CommandBufferFunctions::SetPerformanceStreamMarkerINTEL(const PerformanceStreamMarkerInfoINTEL&  pMarkerInfo) const {
    return device_functions->CmdSetPerformanceStreamMarkerINTEL(commandbuffer, pMarkerInfo); }
[[nodiscard]] Result CommandBufferFunctions::SetPerformanceOverrideINTEL(const PerformanceOverrideInfoINTEL&  pOverrideInfo) const {
    return device_functions->CmdSetPerformanceOverrideINTEL(commandbuffer, pOverrideInfo); }
CommandBufferFunctions const& CommandBufferFunctions::SetLineStippleEXT(uint32_t lineStippleFactor, uint16_t lineStipplePattern) const {
    device_functions->CmdSetLineStippleEXT(commandbuffer, lineStippleFactor, lineStipplePattern);
    return *this; }
#if defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::BuildAccelerationStructureKHR(uint32_t infoCount, const AccelerationStructureBuildGeometryInfoKHR* pInfos, const AccelerationStructureBuildOffsetInfoKHR* const* ppOffsetInfos) const {
    device_functions->CmdBuildAccelerationStructureKHR(commandbuffer, infoCount, pInfos, ppOffsetInfos);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BuildAccelerationStructureIndirectKHR(const AccelerationStructureBuildGeometryInfoKHR&  pInfo, Buffer indirectBuffer, DeviceSize indirectOffset, uint32_t indirectStride) const {
    device_functions->CmdBuildAccelerationStructureIndirectKHR(commandbuffer, pInfo, indirectBuffer, indirectOffset, indirectStride);
    return *this; }
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
CommandBufferFunctions const& CommandBufferFunctions::SetCullModeEXT(CullModeFlags cullMode) const {
    device_functions->CmdSetCullModeEXT(commandbuffer, cullMode);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetFrontFaceEXT(FrontFace frontFace) const {
    device_functions->CmdSetFrontFaceEXT(commandbuffer, frontFace);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetPrimitiveTopologyEXT(PrimitiveTopology primitiveTopology) const {
    device_functions->CmdSetPrimitiveTopologyEXT(commandbuffer, primitiveTopology);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetViewportWithCountEXT(uint32_t viewportCount, const Viewport* pViewports) const {
    device_functions->CmdSetViewportWithCountEXT(commandbuffer, viewportCount, pViewports);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetScissorWithCountEXT(uint32_t scissorCount, const Rect2D* pScissors) const {
    device_functions->CmdSetScissorWithCountEXT(commandbuffer, scissorCount, pScissors);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BindVertexBuffers2EXT(uint32_t firstBinding, uint32_t bindingCount, const Buffer* pBuffers, const DeviceSize* pOffsets, const DeviceSize* pSizes, const DeviceSize* pStrides) const {
    device_functions->CmdBindVertexBuffers2EXT(commandbuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDepthTestEnableEXT(Bool32 depthTestEnable) const {
    device_functions->CmdSetDepthTestEnableEXT(commandbuffer, depthTestEnable);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDepthWriteEnableEXT(Bool32 depthWriteEnable) const {
    device_functions->CmdSetDepthWriteEnableEXT(commandbuffer, depthWriteEnable);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDepthCompareOpEXT(CompareOp depthCompareOp) const {
    device_functions->CmdSetDepthCompareOpEXT(commandbuffer, depthCompareOp);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetDepthBoundsTestEnableEXT(Bool32 depthBoundsTestEnable) const {
    device_functions->CmdSetDepthBoundsTestEnableEXT(commandbuffer, depthBoundsTestEnable);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetStencilTestEnableEXT(Bool32 stencilTestEnable) const {
    device_functions->CmdSetStencilTestEnableEXT(commandbuffer, stencilTestEnable);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::SetStencilOpEXT(StencilFaceFlags faceMask, StencilOp failOp, StencilOp passOp, StencilOp depthFailOp, CompareOp compareOp) const {
    device_functions->CmdSetStencilOpEXT(commandbuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyBuffer2KHR(const CopyBufferInfo2KHR&  pCopyBufferInfo) const {
    device_functions->CmdCopyBuffer2KHR(commandbuffer, pCopyBufferInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyImage2KHR(const CopyImageInfo2KHR&  pCopyImageInfo) const {
    device_functions->CmdCopyImage2KHR(commandbuffer, pCopyImageInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::BlitImage2KHR(const BlitImageInfo2KHR&  pBlitImageInfo) const {
    device_functions->CmdBlitImage2KHR(commandbuffer, pBlitImageInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyBufferToImage2KHR(const CopyBufferToImageInfo2KHR&  pCopyBufferToImageInfo) const {
    device_functions->CmdCopyBufferToImage2KHR(commandbuffer, pCopyBufferToImageInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::CopyImageToBuffer2KHR(const CopyImageToBufferInfo2KHR&  pCopyImageToBufferInfo) const {
    device_functions->CmdCopyImageToBuffer2KHR(commandbuffer, pCopyImageToBufferInfo);
    return *this; }
CommandBufferFunctions const& CommandBufferFunctions::ResolveImage2KHR(const ResolveImageInfo2KHR&  pResolveImageInfo) const {
    device_functions->CmdResolveImage2KHR(commandbuffer, pResolveImageInfo);
    return *this; }
} // namespace vk
// clang-format on
