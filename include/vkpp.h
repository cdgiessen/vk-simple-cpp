#pragma once
// clang-format off
#include <stdint.h>
#include <string>
#include <vector>
#include <span>
#define VK_ENABLE_BETA_EXTENSIONS
#include <vulkan/vulkan.h>
namespace vk {
constexpr size_t ATTACHMENT_UNUSED = (~0U);
constexpr size_t LOD_CLAMP_NONE = 1000.0f;
constexpr size_t QUEUE_FAMILY_IGNORED = (~0U);
constexpr size_t REMAINING_ARRAY_LAYERS = (~0U);
constexpr size_t REMAINING_MIP_LEVELS = (~0U);
constexpr size_t SUBPASS_EXTERNAL = (~0U);
constexpr size_t WHOLE_SIZE = (~0ULL);
constexpr size_t MAX_DEVICE_GROUP_SIZE = 32;
constexpr size_t LUID_SIZE = 8;
constexpr size_t QUEUE_FAMILY_EXTERNAL = (~0U-1);
constexpr size_t MAX_DRIVER_NAME_SIZE = 256;
constexpr size_t MAX_DRIVER_INFO_SIZE = 256;
constexpr size_t MAX_PHYSICAL_DEVICE_NAME_SIZE = 256;
constexpr size_t UUID_SIZE = 16;
constexpr auto LUID_SIZE_KHR = LUID_SIZE;
constexpr size_t MAX_EXTENSION_NAME_SIZE = 256;
constexpr size_t MAX_DESCRIPTION_SIZE = 256;
constexpr size_t MAX_MEMORY_TYPES = 32;
constexpr size_t MAX_MEMORY_HEAPS = 16;
constexpr auto QUEUE_FAMILY_EXTERNAL_KHR = QUEUE_FAMILY_EXTERNAL;
constexpr size_t QUEUE_FAMILY_FOREIGN_EXT = (~0U-2);
constexpr auto MAX_DEVICE_GROUP_SIZE_KHR = MAX_DEVICE_GROUP_SIZE;
constexpr auto MAX_DRIVER_NAME_SIZE_KHR = MAX_DRIVER_NAME_SIZE;
constexpr auto MAX_DRIVER_INFO_SIZE_KHR = MAX_DRIVER_INFO_SIZE;
constexpr size_t SHADER_UNUSED_KHR = (~0U);
constexpr auto SHADER_UNUSED_NV = SHADER_UNUSED_KHR;
using SampleMask = uint32_t;
using Bool32 = uint32_t;
using Flags = uint32_t;
using DeviceSize = uint64_t;
using DeviceAddress = uint64_t;
typedef void (VKAPI_PTR *PFN_vkInternalAllocationNotification)(
    void*                                       pUserData,
    size_t                                      size,
    VkInternalAllocationType                    allocationType,
    VkSystemAllocationScope                     allocationScope);
typedef void (VKAPI_PTR *PFN_vkInternalFreeNotification)(
    void*                                       pUserData,
    size_t                                      size,
    VkInternalAllocationType                    allocationType,
    VkSystemAllocationScope                     allocationScope);
typedef void* (VKAPI_PTR *PFN_vkReallocationFunction)(
    void*                                       pUserData,
    void*                                       pOriginal,
    size_t                                      size,
    size_t                                      alignment,
    VkSystemAllocationScope                     allocationScope);
typedef void* (VKAPI_PTR *PFN_vkAllocationFunction)(
    void*                                       pUserData,
    size_t                                      size,
    size_t                                      alignment,
    VkSystemAllocationScope                     allocationScope);
typedef void (VKAPI_PTR *PFN_vkFreeFunction)(
    void*                                       pUserData,
    void*                                       pMemory);
typedef void (VKAPI_PTR *PFN_vkVoidFunction)(void);
typedef VkBool32 (VKAPI_PTR *PFN_vkDebugReportCallbackEXT)(
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage,
    void*                                       pUserData);
typedef VkBool32 (VKAPI_PTR *PFN_vkDebugUtilsMessengerCallbackEXT)(
    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,
    void*                                            pUserData);
enum class ImageLayout : uint32_t {
    eUndefined = 0,
    eGeneral = 1,
    eColorAttachmentOptimal = 2,
    eDepthStencilAttachmentOptimal = 3,
    eDepthStencilReadOnlyOptimal = 4,
    eShaderReadOnlyOptimal = 5,
    eTransferSrcOptimal = 6,
    eTransferDstOptimal = 7,
    ePreinitialized = 8,
    ePresentSrcKHR = 1000001002,
    eSharedPresentKHR = 1000111000,
    eShadingRateOptimalNV = 1000164003,
    eFragmentDensityMapOptimalEXT = 1000218000,
    eDepthReadOnlyStencilAttachmentOptimal = 1000117000,
    eDepthAttachmentStencilReadOnlyOptimal = 1000117001,
    eDepthAttachmentOptimal = 1000241000,
    eDepthReadOnlyOptimal = 1000241001,
    eStencilAttachmentOptimal = 1000241002,
    eStencilReadOnlyOptimal = 1000241003,
};
enum class AttachmentLoadOp : uint32_t {
    eLoad = 0,
    eClear = 1,
    eDontCare = 2,
};
enum class AttachmentStoreOp : uint32_t {
    eStore = 0,
    eDontCare = 1,
    eNoneQCOM = 1000301000,
};
enum class ImageType : uint32_t {
    e1D = 0,
    e2D = 1,
    e3D = 2,
};
enum class ImageTiling : uint32_t {
    eOptimal = 0,
    eLinear = 1,
    eDrmFormatModifierEXT = 1000158000,
};
enum class ImageViewType : uint32_t {
    e1D = 0,
    e2D = 1,
    e3D = 2,
    eCube = 3,
    e1DArray = 4,
    e2DArray = 5,
    eCubeArray = 6,
};
enum class CommandBufferLevel : uint32_t {
    ePrimary = 0,
    eSecondary = 1,
};
enum class ComponentSwizzle : uint32_t {
    eIdentity = 0,
    eZero = 1,
    eOne = 2,
    eR = 3,
    eG = 4,
    eB = 5,
    eA = 6,
};
enum class DescriptorType : uint32_t {
    eSampler = 0,
    eCombinedImageSampler = 1,
    eSampledImage = 2,
    eStorageImage = 3,
    eUniformTexelBuffer = 4,
    eStorageTexelBuffer = 5,
    eUniformBuffer = 6,
    eStorageBuffer = 7,
    eUniformBufferDynamic = 8,
    eStorageBufferDynamic = 9,
    eInputAttachment = 10,
    eInlineUniformBlockEXT = 1000138000,
    eAccelerationStructureKHR = 1000150000,
};
enum class QueryType : uint32_t {
    eOcclusion = 0,
    ePipelineStatistics = 1,
    eTimestamp = 2,
    eReserved8 = 1000023008,
    eReserved4 = 1000024004,
    eTransformFeedbackStreamEXT = 1000028004,
    ePerformanceQueryKHR = 1000116000,
    eAccelerationStructureCompactedSizeKHR = 1000150000,
    eAccelerationStructureSerializationSizeKHR = 1000150000,
    ePerformanceQueryINTEL = 1000210000,
};
enum class BorderColor : uint32_t {
    eFloatTransparentBlack = 0,
    eIntTransparentBlack = 1,
    eFloatOpaqueBlack = 2,
    eIntOpaqueBlack = 3,
    eFloatOpaqueWhite = 4,
    eIntOpaqueWhite = 5,
    eFloatCustomEXT = 1000287003,
    eIntCustomEXT = 1000287004,
};
enum class PipelineBindPoint : uint32_t {
    eGraphics = 0,
    eCompute = 1,
    eRayTracingKHR = 1000150000,
};
enum class PipelineCacheHeaderVersion : uint32_t {
    eOne = 1,
};
enum class PrimitiveTopology : uint32_t {
    ePointList = 0,
    eLineList = 1,
    eLineStrip = 2,
    eTriangleList = 3,
    eTriangleStrip = 4,
    eTriangleFan = 5,
    eLineListWithAdjacency = 6,
    eLineStripWithAdjacency = 7,
    eTriangleListWithAdjacency = 8,
    eTriangleStripWithAdjacency = 9,
    ePatchList = 10,
};
enum class SharingMode : uint32_t {
    eExclusive = 0,
    eConcurrent = 1,
};
enum class IndexType : uint32_t {
    eUint16 = 0,
    eUint32 = 1,
    eNoneKHR = 1000150000,
    eUint8EXT = 1000265000,
};
enum class Filter : uint32_t {
    eNearest = 0,
    eLinear = 1,
    eCubicIMG = 1000015000,
};
enum class SamplerMipmapMode : uint32_t {
    eNearest = 0,
    eLinear = 1,
};
enum class SamplerAddressMode : uint32_t {
    eRepeat = 0,
    eMirroredRepeat = 1,
    eClampToEdge = 2,
    eClampToBorder = 3,
    eMirrorClampToEdge = 4,
};
enum class CompareOp : uint32_t {
    eNever = 0,
    eLess = 1,
    eEqual = 2,
    eLessOrEqual = 3,
    eGreater = 4,
    eNotEqual = 5,
    eGreaterOrEqual = 6,
    eAlways = 7,
};
enum class PolygonMode : uint32_t {
    eFill = 0,
    eLine = 1,
    ePoint = 2,
    eFillRectangleNV = 1000153000,
};
enum class FrontFace : uint32_t {
    eCounterClockwise = 0,
    eClockwise = 1,
};
enum class BlendFactor : uint32_t {
    eZero = 0,
    eOne = 1,
    eSrcColor = 2,
    eOneMinusSrcColor = 3,
    eDstColor = 4,
    eOneMinusDstColor = 5,
    eSrcAlpha = 6,
    eOneMinusSrcAlpha = 7,
    eDstAlpha = 8,
    eOneMinusDstAlpha = 9,
    eConstantColor = 10,
    eOneMinusConstantColor = 11,
    eConstantAlpha = 12,
    eOneMinusConstantAlpha = 13,
    eSrcAlphaSaturate = 14,
    eSrc1Color = 15,
    eOneMinusSrc1Color = 16,
    eSrc1Alpha = 17,
    eOneMinusSrc1Alpha = 18,
};
enum class BlendOp : uint32_t {
    eAdd = 0,
    eSubtract = 1,
    eReverseSubtract = 2,
    eMin = 3,
    eMax = 4,
    eZeroEXT = 1000148000,
    eSrcEXT = 1000148001,
    eDstEXT = 1000148002,
    eSrcOverEXT = 1000148003,
    eDstOverEXT = 1000148004,
    eSrcInEXT = 1000148005,
    eDstInEXT = 1000148006,
    eSrcOutEXT = 1000148007,
    eDstOutEXT = 1000148008,
    eSrcAtopEXT = 1000148009,
    eDstAtopEXT = 1000148010,
    eXorEXT = 1000148011,
    eMultiplyEXT = 1000148012,
    eScreenEXT = 1000148013,
    eOverlayEXT = 1000148014,
    eDarkenEXT = 1000148015,
    eLightenEXT = 1000148016,
    eColordodgeEXT = 1000148017,
    eColorburnEXT = 1000148018,
    eHardlightEXT = 1000148019,
    eSoftlightEXT = 1000148020,
    eDifferenceEXT = 1000148021,
    eExclusionEXT = 1000148022,
    eInvertEXT = 1000148023,
    eInvertRgbEXT = 1000148024,
    eLineardodgeEXT = 1000148025,
    eLinearburnEXT = 1000148026,
    eVividlightEXT = 1000148027,
    eLinearlightEXT = 1000148028,
    ePinlightEXT = 1000148029,
    eHardmixEXT = 1000148030,
    eHslHueEXT = 1000148031,
    eHslSaturationEXT = 1000148032,
    eHslColorEXT = 1000148033,
    eHslLuminosityEXT = 1000148034,
    ePlusEXT = 1000148035,
    ePlusClampedEXT = 1000148036,
    ePlusClampedAlphaEXT = 1000148037,
    ePlusDarkerEXT = 1000148038,
    eMinusEXT = 1000148039,
    eMinusClampedEXT = 1000148040,
    eContrastEXT = 1000148041,
    eInvertOvgEXT = 1000148042,
    eRedEXT = 1000148043,
    eGreenEXT = 1000148044,
    eBlueEXT = 1000148045,
};
enum class StencilOp : uint32_t {
    eKeep = 0,
    eZero = 1,
    eReplace = 2,
    eIncrementAndClamp = 3,
    eDecrementAndClamp = 4,
    eInvert = 5,
    eIncrementAndWrap = 6,
    eDecrementAndWrap = 7,
};
enum class LogicOp : uint32_t {
    eClear = 0,
    eAnd = 1,
    eAndReverse = 2,
    eCopy = 3,
    eAndInverted = 4,
    eNoOp = 5,
    eXor = 6,
    eOr = 7,
    eNor = 8,
    eEquivalent = 9,
    eInvert = 10,
    eOrReverse = 11,
    eCopyInverted = 12,
    eOrInverted = 13,
    eNand = 14,
    eSet = 15,
};
enum class InternalAllocationType : uint32_t {
    eExecutable = 0,
};
enum class SystemAllocationScope : uint32_t {
    eCommand = 0,
    eObject = 1,
    eCache = 2,
    eDevice = 3,
    eInstance = 4,
};
enum class PhysicalDeviceType : uint32_t {
    eOther = 0,
    eIntegratedGpu = 1,
    eDiscreteGpu = 2,
    eVirtualGpu = 3,
    eCpu = 4,
};
enum class VertexInputRate : uint32_t {
    eVertex = 0,
    eInstance = 1,
};
enum class Format : uint32_t {
    eUndefined = 0,
    eR4G4UnormPack8 = 1,
    eR4G4B4A4UnormPack16 = 2,
    eB4G4R4A4UnormPack16 = 3,
    eR5G6B5UnormPack16 = 4,
    eB5G6R5UnormPack16 = 5,
    eR5G5B5A1UnormPack16 = 6,
    eB5G5R5A1UnormPack16 = 7,
    eA1R5G5B5UnormPack16 = 8,
    eR8Unorm = 9,
    eR8Snorm = 10,
    eR8Uscaled = 11,
    eR8Sscaled = 12,
    eR8Uint = 13,
    eR8Sint = 14,
    eR8Srgb = 15,
    eR8G8Unorm = 16,
    eR8G8Snorm = 17,
    eR8G8Uscaled = 18,
    eR8G8Sscaled = 19,
    eR8G8Uint = 20,
    eR8G8Sint = 21,
    eR8G8Srgb = 22,
    eR8G8B8Unorm = 23,
    eR8G8B8Snorm = 24,
    eR8G8B8Uscaled = 25,
    eR8G8B8Sscaled = 26,
    eR8G8B8Uint = 27,
    eR8G8B8Sint = 28,
    eR8G8B8Srgb = 29,
    eB8G8R8Unorm = 30,
    eB8G8R8Snorm = 31,
    eB8G8R8Uscaled = 32,
    eB8G8R8Sscaled = 33,
    eB8G8R8Uint = 34,
    eB8G8R8Sint = 35,
    eB8G8R8Srgb = 36,
    eR8G8B8A8Unorm = 37,
    eR8G8B8A8Snorm = 38,
    eR8G8B8A8Uscaled = 39,
    eR8G8B8A8Sscaled = 40,
    eR8G8B8A8Uint = 41,
    eR8G8B8A8Sint = 42,
    eR8G8B8A8Srgb = 43,
    eB8G8R8A8Unorm = 44,
    eB8G8R8A8Snorm = 45,
    eB8G8R8A8Uscaled = 46,
    eB8G8R8A8Sscaled = 47,
    eB8G8R8A8Uint = 48,
    eB8G8R8A8Sint = 49,
    eB8G8R8A8Srgb = 50,
    eA8B8G8R8UnormPack32 = 51,
    eA8B8G8R8SnormPack32 = 52,
    eA8B8G8R8UscaledPack32 = 53,
    eA8B8G8R8SscaledPack32 = 54,
    eA8B8G8R8UintPack32 = 55,
    eA8B8G8R8SintPack32 = 56,
    eA8B8G8R8SrgbPack32 = 57,
    eA2R10G10B10UnormPack32 = 58,
    eA2R10G10B10SnormPack32 = 59,
    eA2R10G10B10UscaledPack32 = 60,
    eA2R10G10B10SscaledPack32 = 61,
    eA2R10G10B10UintPack32 = 62,
    eA2R10G10B10SintPack32 = 63,
    eA2B10G10R10UnormPack32 = 64,
    eA2B10G10R10SnormPack32 = 65,
    eA2B10G10R10UscaledPack32 = 66,
    eA2B10G10R10SscaledPack32 = 67,
    eA2B10G10R10UintPack32 = 68,
    eA2B10G10R10SintPack32 = 69,
    eR16Unorm = 70,
    eR16Snorm = 71,
    eR16Uscaled = 72,
    eR16Sscaled = 73,
    eR16Uint = 74,
    eR16Sint = 75,
    eR16Sfloat = 76,
    eR16G16Unorm = 77,
    eR16G16Snorm = 78,
    eR16G16Uscaled = 79,
    eR16G16Sscaled = 80,
    eR16G16Uint = 81,
    eR16G16Sint = 82,
    eR16G16Sfloat = 83,
    eR16G16B16Unorm = 84,
    eR16G16B16Snorm = 85,
    eR16G16B16Uscaled = 86,
    eR16G16B16Sscaled = 87,
    eR16G16B16Uint = 88,
    eR16G16B16Sint = 89,
    eR16G16B16Sfloat = 90,
    eR16G16B16A16Unorm = 91,
    eR16G16B16A16Snorm = 92,
    eR16G16B16A16Uscaled = 93,
    eR16G16B16A16Sscaled = 94,
    eR16G16B16A16Uint = 95,
    eR16G16B16A16Sint = 96,
    eR16G16B16A16Sfloat = 97,
    eR32Uint = 98,
    eR32Sint = 99,
    eR32Sfloat = 100,
    eR32G32Uint = 101,
    eR32G32Sint = 102,
    eR32G32Sfloat = 103,
    eR32G32B32Uint = 104,
    eR32G32B32Sint = 105,
    eR32G32B32Sfloat = 106,
    eR32G32B32A32Uint = 107,
    eR32G32B32A32Sint = 108,
    eR32G32B32A32Sfloat = 109,
    eR64Uint = 110,
    eR64Sint = 111,
    eR64Sfloat = 112,
    eR64G64Uint = 113,
    eR64G64Sint = 114,
    eR64G64Sfloat = 115,
    eR64G64B64Uint = 116,
    eR64G64B64Sint = 117,
    eR64G64B64Sfloat = 118,
    eR64G64B64A64Uint = 119,
    eR64G64B64A64Sint = 120,
    eR64G64B64A64Sfloat = 121,
    eB10G11R11UfloatPack32 = 122,
    eE5B9G9R9UfloatPack32 = 123,
    eD16Unorm = 124,
    eX8D24UnormPack32 = 125,
    eD32Sfloat = 126,
    eS8Uint = 127,
    eD16UnormS8Uint = 128,
    eD24UnormS8Uint = 129,
    eD32SfloatS8Uint = 130,
    eBc1RgbUnormBlock = 131,
    eBc1RgbSrgbBlock = 132,
    eBc1RgbaUnormBlock = 133,
    eBc1RgbaSrgbBlock = 134,
    eBc2UnormBlock = 135,
    eBc2SrgbBlock = 136,
    eBc3UnormBlock = 137,
    eBc3SrgbBlock = 138,
    eBc4UnormBlock = 139,
    eBc4SnormBlock = 140,
    eBc5UnormBlock = 141,
    eBc5SnormBlock = 142,
    eBc6HUfloatBlock = 143,
    eBc6HSfloatBlock = 144,
    eBc7UnormBlock = 145,
    eBc7SrgbBlock = 146,
    eEtc2R8G8B8UnormBlock = 147,
    eEtc2R8G8B8SrgbBlock = 148,
    eEtc2R8G8B8A1UnormBlock = 149,
    eEtc2R8G8B8A1SrgbBlock = 150,
    eEtc2R8G8B8A8UnormBlock = 151,
    eEtc2R8G8B8A8SrgbBlock = 152,
    eEacR11UnormBlock = 153,
    eEacR11SnormBlock = 154,
    eEacR11G11UnormBlock = 155,
    eEacR11G11SnormBlock = 156,
    eAstc4X4UnormBlock = 157,
    eAstc4X4SrgbBlock = 158,
    eAstc5X4UnormBlock = 159,
    eAstc5X4SrgbBlock = 160,
    eAstc5X5UnormBlock = 161,
    eAstc5X5SrgbBlock = 162,
    eAstc6X5UnormBlock = 163,
    eAstc6X5SrgbBlock = 164,
    eAstc6X6UnormBlock = 165,
    eAstc6X6SrgbBlock = 166,
    eAstc8X5UnormBlock = 167,
    eAstc8X5SrgbBlock = 168,
    eAstc8X6UnormBlock = 169,
    eAstc8X6SrgbBlock = 170,
    eAstc8X8UnormBlock = 171,
    eAstc8X8SrgbBlock = 172,
    eAstc10X5UnormBlock = 173,
    eAstc10X5SrgbBlock = 174,
    eAstc10X6UnormBlock = 175,
    eAstc10X6SrgbBlock = 176,
    eAstc10X8UnormBlock = 177,
    eAstc10X8SrgbBlock = 178,
    eAstc10X10UnormBlock = 179,
    eAstc10X10SrgbBlock = 180,
    eAstc12X10UnormBlock = 181,
    eAstc12X10SrgbBlock = 182,
    eAstc12X12UnormBlock = 183,
    eAstc12X12SrgbBlock = 184,
    ePvrtc12BppUnormBlockIMG = 1000054000,
    ePvrtc14BppUnormBlockIMG = 1000054001,
    ePvrtc22BppUnormBlockIMG = 1000054002,
    ePvrtc24BppUnormBlockIMG = 1000054003,
    ePvrtc12BppSrgbBlockIMG = 1000054004,
    ePvrtc14BppSrgbBlockIMG = 1000054005,
    ePvrtc22BppSrgbBlockIMG = 1000054006,
    ePvrtc24BppSrgbBlockIMG = 1000054007,
    eAstc4X4SfloatBlockEXT = 1000066000,
    eAstc5X4SfloatBlockEXT = 1000066001,
    eAstc5X5SfloatBlockEXT = 1000066002,
    eAstc6X5SfloatBlockEXT = 1000066003,
    eAstc6X6SfloatBlockEXT = 1000066004,
    eAstc8X5SfloatBlockEXT = 1000066005,
    eAstc8X6SfloatBlockEXT = 1000066006,
    eAstc8X8SfloatBlockEXT = 1000066007,
    eAstc10X5SfloatBlockEXT = 1000066008,
    eAstc10X6SfloatBlockEXT = 1000066009,
    eAstc10X8SfloatBlockEXT = 1000066010,
    eAstc10X10SfloatBlockEXT = 1000066011,
    eAstc12X10SfloatBlockEXT = 1000066012,
    eAstc12X12SfloatBlockEXT = 1000066013,
    eAstc3X3X3UnormBlockEXT = 1000288000,
    eAstc3X3X3SrgbBlockEXT = 1000288001,
    eAstc3X3X3SfloatBlockEXT = 1000288002,
    eAstc4X3X3UnormBlockEXT = 1000288003,
    eAstc4X3X3SrgbBlockEXT = 1000288004,
    eAstc4X3X3SfloatBlockEXT = 1000288005,
    eAstc4X4X3UnormBlockEXT = 1000288006,
    eAstc4X4X3SrgbBlockEXT = 1000288007,
    eAstc4X4X3SfloatBlockEXT = 1000288008,
    eAstc4X4X4UnormBlockEXT = 1000288009,
    eAstc4X4X4SrgbBlockEXT = 1000288010,
    eAstc4X4X4SfloatBlockEXT = 1000288011,
    eAstc5X4X4UnormBlockEXT = 1000288012,
    eAstc5X4X4SrgbBlockEXT = 1000288013,
    eAstc5X4X4SfloatBlockEXT = 1000288014,
    eAstc5X5X4UnormBlockEXT = 1000288015,
    eAstc5X5X4SrgbBlockEXT = 1000288016,
    eAstc5X5X4SfloatBlockEXT = 1000288017,
    eAstc5X5X5UnormBlockEXT = 1000288018,
    eAstc5X5X5SrgbBlockEXT = 1000288019,
    eAstc5X5X5SfloatBlockEXT = 1000288020,
    eAstc6X5X5UnormBlockEXT = 1000288021,
    eAstc6X5X5SrgbBlockEXT = 1000288022,
    eAstc6X5X5SfloatBlockEXT = 1000288023,
    eAstc6X6X5UnormBlockEXT = 1000288024,
    eAstc6X6X5SrgbBlockEXT = 1000288025,
    eAstc6X6X5SfloatBlockEXT = 1000288026,
    eAstc6X6X6UnormBlockEXT = 1000288027,
    eAstc6X6X6SrgbBlockEXT = 1000288028,
    eAstc6X6X6SfloatBlockEXT = 1000288029,
    eA4R4G4B4UnormPack16EXT = 1000340000,
    eA4B4G4R4UnormPack16EXT = 1000340001,
    eG8B8G8R8422Unorm = 1000156000,
    eB8G8R8G8422Unorm = 1000156001,
    eG8B8R83Plane420Unorm = 1000156002,
    eG8B8R82Plane420Unorm = 1000156003,
    eG8B8R83Plane422Unorm = 1000156004,
    eG8B8R82Plane422Unorm = 1000156005,
    eG8B8R83Plane444Unorm = 1000156006,
    eR10X6UnormPack16 = 1000156007,
    eR10X6G10X6Unorm2Pack16 = 1000156008,
    eR10X6G10X6B10X6A10X6Unorm4Pack16 = 1000156009,
    eG10X6B10X6G10X6R10X6422Unorm4Pack16 = 1000156010,
    eB10X6G10X6R10X6G10X6422Unorm4Pack16 = 1000156011,
    eG10X6B10X6R10X63Plane420Unorm3Pack16 = 1000156012,
    eG10X6B10X6R10X62Plane420Unorm3Pack16 = 1000156013,
    eG10X6B10X6R10X63Plane422Unorm3Pack16 = 1000156014,
    eG10X6B10X6R10X62Plane422Unorm3Pack16 = 1000156015,
    eG10X6B10X6R10X63Plane444Unorm3Pack16 = 1000156016,
    eR12X4UnormPack16 = 1000156017,
    eR12X4G12X4Unorm2Pack16 = 1000156018,
    eR12X4G12X4B12X4A12X4Unorm4Pack16 = 1000156019,
    eG12X4B12X4G12X4R12X4422Unorm4Pack16 = 1000156020,
    eB12X4G12X4R12X4G12X4422Unorm4Pack16 = 1000156021,
    eG12X4B12X4R12X43Plane420Unorm3Pack16 = 1000156022,
    eG12X4B12X4R12X42Plane420Unorm3Pack16 = 1000156023,
    eG12X4B12X4R12X43Plane422Unorm3Pack16 = 1000156024,
    eG12X4B12X4R12X42Plane422Unorm3Pack16 = 1000156025,
    eG12X4B12X4R12X43Plane444Unorm3Pack16 = 1000156026,
    eG16B16G16R16422Unorm = 1000156027,
    eB16G16R16G16422Unorm = 1000156028,
    eG16B16R163Plane420Unorm = 1000156029,
    eG16B16R162Plane420Unorm = 1000156030,
    eG16B16R163Plane422Unorm = 1000156031,
    eG16B16R162Plane422Unorm = 1000156032,
    eG16B16R163Plane444Unorm = 1000156033,
};
enum class StructureType : uint32_t {
    eApplicationInfo = 0,
    eInstanceCreateInfo = 1,
    eDeviceQueueCreateInfo = 2,
    eDeviceCreateInfo = 3,
    eSubmitInfo = 4,
    eMemoryAllocateInfo = 5,
    eMappedMemoryRange = 6,
    eBindSparseInfo = 7,
    eFenceCreateInfo = 8,
    eSemaphoreCreateInfo = 9,
    eEventCreateInfo = 10,
    eQueryPoolCreateInfo = 11,
    eBufferCreateInfo = 12,
    eBufferViewCreateInfo = 13,
    eImageCreateInfo = 14,
    eImageViewCreateInfo = 15,
    eShaderModuleCreateInfo = 16,
    ePipelineCacheCreateInfo = 17,
    ePipelineShaderStageCreateInfo = 18,
    ePipelineVertexInputStateCreateInfo = 19,
    ePipelineInputAssemblyStateCreateInfo = 20,
    ePipelineTessellationStateCreateInfo = 21,
    ePipelineViewportStateCreateInfo = 22,
    ePipelineRasterizationStateCreateInfo = 23,
    ePipelineMultisampleStateCreateInfo = 24,
    ePipelineDepthStencilStateCreateInfo = 25,
    ePipelineColorBlendStateCreateInfo = 26,
    ePipelineDynamicStateCreateInfo = 27,
    eGraphicsPipelineCreateInfo = 28,
    eComputePipelineCreateInfo = 29,
    ePipelineLayoutCreateInfo = 30,
    eSamplerCreateInfo = 31,
    eDescriptorSetLayoutCreateInfo = 32,
    eDescriptorPoolCreateInfo = 33,
    eDescriptorSetAllocateInfo = 34,
    eWriteDescriptorSet = 35,
    eCopyDescriptorSet = 36,
    eFramebufferCreateInfo = 37,
    eRenderPassCreateInfo = 38,
    eCommandPoolCreateInfo = 39,
    eCommandBufferAllocateInfo = 40,
    eCommandBufferInheritanceInfo = 41,
    eCommandBufferBeginInfo = 42,
    eRenderPassBeginInfo = 43,
    eBufferMemoryBarrier = 44,
    eImageMemoryBarrier = 45,
    eMemoryBarrier = 46,
    eLoaderInstanceCreateInfo = 47,
    eLoaderDeviceCreateInfo = 48,
    eSwapchainCreateInfoKHR = 1000001000,
    ePresentInfoKHR = 1000001001,
    eDeviceGroupPresentCapabilitiesKHR = 1000001007,
    eImageSwapchainCreateInfoKHR = 1000001008,
    eBindImageMemorySwapchainInfoKHR = 1000001009,
    eAcquireNextImageInfoKHR = 1000001010,
    eDeviceGroupPresentInfoKHR = 1000001011,
    eDeviceGroupSwapchainCreateInfoKHR = 1000001012,
    eDisplayModeCreateInfoKHR = 1000002000,
    eDisplaySurfaceCreateInfoKHR = 1000002001,
    eDisplayPresentInfoKHR = 1000003000,
    eXlibSurfaceCreateInfoKHR = 1000004000,
    eXcbSurfaceCreateInfoKHR = 1000005000,
    eWaylandSurfaceCreateInfoKHR = 1000006000,
    eAndroidSurfaceCreateInfoKHR = 1000008000,
    eWin32SurfaceCreateInfoKHR = 1000009000,
    eNativeBufferANDROID = 1000010000,
    eSwapchainImageCreateInfoANDROID = 1000010001,
    ePhysicalDevicePresentationPropertiesANDROID = 1000010002,
    eDebugReportCallbackCreateInfoEXT = 1000011000,
    ePipelineRasterizationStateRasterizationOrderAMD = 1000018000,
    eDebugMarkerObjectNameInfoEXT = 1000022000,
    eDebugMarkerObjectTagInfoEXT = 1000022001,
    eDebugMarkerMarkerInfoEXT = 1000022002,
    eDedicatedAllocationImageCreateInfoNV = 1000026000,
    eDedicatedAllocationBufferCreateInfoNV = 1000026001,
    eDedicatedAllocationMemoryAllocateInfoNV = 1000026002,
    ePhysicalDeviceTransformFeedbackFeaturesEXT = 1000028000,
    ePhysicalDeviceTransformFeedbackPropertiesEXT = 1000028001,
    ePipelineRasterizationStateStreamCreateInfoEXT = 1000028002,
    eImageViewHandleInfoNVX = 1000030000,
    eImageViewAddressPropertiesNVX = 1000030001,
    eTextureLodGatherFormatPropertiesAMD = 1000041000,
    eStreamDescriptorSurfaceCreateInfoGGP = 1000049000,
    ePhysicalDeviceCornerSampledImageFeaturesNV = 1000050000,
    eExternalMemoryImageCreateInfoNV = 1000056000,
    eExportMemoryAllocateInfoNV = 1000056001,
    eImportMemoryWin32HandleInfoNV = 1000057000,
    eExportMemoryWin32HandleInfoNV = 1000057001,
    eWin32KeyedMutexAcquireReleaseInfoNV = 1000058000,
    eValidationFlagsEXT = 1000061000,
    eViSurfaceCreateInfoNN = 1000062000,
    ePhysicalDeviceTextureCompressionAstcHdrFeaturesEXT = 1000066000,
    eImageViewAstcDecodeModeEXT = 1000067000,
    ePhysicalDeviceAstcDecodeFeaturesEXT = 1000067001,
    eImportMemoryWin32HandleInfoKHR = 1000073000,
    eExportMemoryWin32HandleInfoKHR = 1000073001,
    eMemoryWin32HandlePropertiesKHR = 1000073002,
    eMemoryGetWin32HandleInfoKHR = 1000073003,
    eImportMemoryFdInfoKHR = 1000074000,
    eMemoryFdPropertiesKHR = 1000074001,
    eMemoryGetFdInfoKHR = 1000074002,
    eWin32KeyedMutexAcquireReleaseInfoKHR = 1000075000,
    eImportSemaphoreWin32HandleInfoKHR = 1000078000,
    eExportSemaphoreWin32HandleInfoKHR = 1000078001,
    eD3D12FenceSubmitInfoKHR = 1000078002,
    eSemaphoreGetWin32HandleInfoKHR = 1000078003,
    eImportSemaphoreFdInfoKHR = 1000079000,
    eSemaphoreGetFdInfoKHR = 1000079001,
    ePhysicalDevicePushDescriptorPropertiesKHR = 1000080000,
    eCommandBufferInheritanceConditionalRenderingInfoEXT = 1000081000,
    ePhysicalDeviceConditionalRenderingFeaturesEXT = 1000081001,
    eConditionalRenderingBeginInfoEXT = 1000081002,
    ePresentRegionsKHR = 1000084000,
    ePipelineViewportWScalingStateCreateInfoNV = 1000087000,
    eSurfaceCapabilities2EXT = 1000090000,
    eDisplayPowerInfoEXT = 1000091000,
    eDeviceEventInfoEXT = 1000091001,
    eDisplayEventInfoEXT = 1000091002,
    eSwapchainCounterCreateInfoEXT = 1000091003,
    ePresentTimesInfoGOOGLE = 1000092000,
    ePhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = 1000097000,
    ePipelineViewportSwizzleStateCreateInfoNV = 1000098000,
    ePhysicalDeviceDiscardRectanglePropertiesEXT = 1000099000,
    ePipelineDiscardRectangleStateCreateInfoEXT = 1000099001,
    ePhysicalDeviceConservativeRasterizationPropertiesEXT = 1000101000,
    ePipelineRasterizationConservativeStateCreateInfoEXT = 1000101001,
    ePhysicalDeviceDepthClipEnableFeaturesEXT = 1000102000,
    ePipelineRasterizationDepthClipStateCreateInfoEXT = 1000102001,
    eHdrMetadataEXT = 1000105000,
    eSharedPresentSurfaceCapabilitiesKHR = 1000111000,
    eImportFenceWin32HandleInfoKHR = 1000114000,
    eExportFenceWin32HandleInfoKHR = 1000114001,
    eFenceGetWin32HandleInfoKHR = 1000114002,
    eImportFenceFdInfoKHR = 1000115000,
    eFenceGetFdInfoKHR = 1000115001,
    ePhysicalDevicePerformanceQueryFeaturesKHR = 1000116000,
    ePhysicalDevicePerformanceQueryPropertiesKHR = 1000116001,
    eQueryPoolPerformanceCreateInfoKHR = 1000116002,
    ePerformanceQuerySubmitInfoKHR = 1000116003,
    eAcquireProfilingLockInfoKHR = 1000116004,
    ePerformanceCounterKHR = 1000116005,
    ePerformanceCounterDescriptionKHR = 1000116006,
    ePhysicalDeviceSurfaceInfo2KHR = 1000119000,
    eSurfaceCapabilities2KHR = 1000119001,
    eSurfaceFormat2KHR = 1000119002,
    eDisplayProperties2KHR = 1000121000,
    eDisplayPlaneProperties2KHR = 1000121001,
    eDisplayModeProperties2KHR = 1000121002,
    eDisplayPlaneInfo2KHR = 1000121003,
    eDisplayPlaneCapabilities2KHR = 1000121004,
    eIosSurfaceCreateInfoMVK = 1000122000,
    eMacosSurfaceCreateInfoMVK = 1000123000,
    eDebugUtilsObjectNameInfoEXT = 1000128000,
    eDebugUtilsObjectTagInfoEXT = 1000128001,
    eDebugUtilsLabelEXT = 1000128002,
    eDebugUtilsMessengerCallbackDataEXT = 1000128003,
    eDebugUtilsMessengerCreateInfoEXT = 1000128004,
    eAndroidHardwareBufferUsageANDROID = 1000129000,
    eAndroidHardwareBufferPropertiesANDROID = 1000129001,
    eAndroidHardwareBufferFormatPropertiesANDROID = 1000129002,
    eImportAndroidHardwareBufferInfoANDROID = 1000129003,
    eMemoryGetAndroidHardwareBufferInfoANDROID = 1000129004,
    eExternalFormatANDROID = 1000129005,
    ePhysicalDeviceInlineUniformBlockFeaturesEXT = 1000138000,
    ePhysicalDeviceInlineUniformBlockPropertiesEXT = 1000138001,
    eWriteDescriptorSetInlineUniformBlockEXT = 1000138002,
    eDescriptorPoolInlineUniformBlockCreateInfoEXT = 1000138003,
    eSampleLocationsInfoEXT = 1000143000,
    eRenderPassSampleLocationsBeginInfoEXT = 1000143001,
    ePipelineSampleLocationsStateCreateInfoEXT = 1000143002,
    ePhysicalDeviceSampleLocationsPropertiesEXT = 1000143003,
    eMultisamplePropertiesEXT = 1000143004,
    ePhysicalDeviceBlendOperationAdvancedFeaturesEXT = 1000148000,
    ePhysicalDeviceBlendOperationAdvancedPropertiesEXT = 1000148001,
    ePipelineColorBlendAdvancedStateCreateInfoEXT = 1000148002,
    ePipelineCoverageToColorStateCreateInfoNV = 1000149000,
    eBindAccelerationStructureMemoryInfoKHR = 1000150006,
    eWriteDescriptorSetAccelerationStructureKHR = 1000150007,
    eAccelerationStructureBuildGeometryInfoKHR = 1000150000,
    eAccelerationStructureCreateGeometryTypeInfoKHR = 1000150001,
    eAccelerationStructureDeviceAddressInfoKHR = 1000150002,
    eAccelerationStructureGeometryAabbsDataKHR = 1000150003,
    eAccelerationStructureGeometryInstancesDataKHR = 1000150004,
    eAccelerationStructureGeometryTrianglesDataKHR = 1000150005,
    eAccelerationStructureGeometryKHR = 1000150006,
    eAccelerationStructureMemoryRequirementsInfoKHR = 1000150008,
    eAccelerationStructureVersionKHR = 1000150009,
    eCopyAccelerationStructureInfoKHR = 1000150010,
    eCopyAccelerationStructureToMemoryInfoKHR = 1000150011,
    eCopyMemoryToAccelerationStructureInfoKHR = 1000150012,
    ePhysicalDeviceRayTracingFeaturesKHR = 1000150013,
    ePhysicalDeviceRayTracingPropertiesKHR = 1000150014,
    eRayTracingPipelineCreateInfoKHR = 1000150015,
    eRayTracingShaderGroupCreateInfoKHR = 1000150016,
    eAccelerationStructureCreateInfoKHR = 1000150017,
    eRayTracingPipelineInterfaceCreateInfoKHR = 1000150018,
    ePipelineCoverageModulationStateCreateInfoNV = 1000152000,
    ePhysicalDeviceShaderSmBuiltinsFeaturesNV = 1000154000,
    ePhysicalDeviceShaderSmBuiltinsPropertiesNV = 1000154001,
    eDrmFormatModifierPropertiesListEXT = 1000158000,
    eDrmFormatModifierPropertiesEXT = 1000158001,
    ePhysicalDeviceImageDrmFormatModifierInfoEXT = 1000158002,
    eImageDrmFormatModifierListCreateInfoEXT = 1000158003,
    eImageDrmFormatModifierExplicitCreateInfoEXT = 1000158004,
    eImageDrmFormatModifierPropertiesEXT = 1000158005,
    eValidationCacheCreateInfoEXT = 1000160000,
    eShaderModuleValidationCacheCreateInfoEXT = 1000160001,
    ePipelineViewportShadingRateImageStateCreateInfoNV = 1000164000,
    ePhysicalDeviceShadingRateImageFeaturesNV = 1000164001,
    ePhysicalDeviceShadingRateImagePropertiesNV = 1000164002,
    ePipelineViewportCoarseSampleOrderStateCreateInfoNV = 1000164005,
    eRayTracingPipelineCreateInfoNV = 1000165000,
    eAccelerationStructureCreateInfoNV = 1000165001,
    eGeometryNV = 1000165003,
    eGeometryTrianglesNV = 1000165004,
    eGeometryAabbNV = 1000165005,
    eAccelerationStructureMemoryRequirementsInfoNV = 1000165008,
    ePhysicalDeviceRayTracingPropertiesNV = 1000165009,
    eRayTracingShaderGroupCreateInfoNV = 1000165011,
    eAccelerationStructureInfoNV = 1000165012,
    ePhysicalDeviceRepresentativeFragmentTestFeaturesNV = 1000166000,
    ePipelineRepresentativeFragmentTestStateCreateInfoNV = 1000166001,
    ePhysicalDeviceImageViewImageFormatInfoEXT = 1000170000,
    eFilterCubicImageViewImageFormatPropertiesEXT = 1000170001,
    eDeviceQueueGlobalPriorityCreateInfoEXT = 1000174000,
    eImportMemoryHostPointerInfoEXT = 1000178000,
    eMemoryHostPointerPropertiesEXT = 1000178001,
    ePhysicalDeviceExternalMemoryHostPropertiesEXT = 1000178002,
    ePhysicalDeviceShaderClockFeaturesKHR = 1000181000,
    ePipelineCompilerControlCreateInfoAMD = 1000183000,
    eCalibratedTimestampInfoEXT = 1000184000,
    ePhysicalDeviceShaderCorePropertiesAMD = 1000185000,
    eDeviceMemoryOverallocationCreateInfoAMD = 1000189000,
    ePhysicalDeviceVertexAttributeDivisorPropertiesEXT = 1000190000,
    ePipelineVertexInputDivisorStateCreateInfoEXT = 1000190001,
    ePhysicalDeviceVertexAttributeDivisorFeaturesEXT = 1000190002,
    ePresentFrameTokenGGP = 1000191000,
    ePipelineCreationFeedbackCreateInfoEXT = 1000192000,
    ePhysicalDeviceComputeShaderDerivativesFeaturesNV = 1000201000,
    ePhysicalDeviceMeshShaderFeaturesNV = 1000202000,
    ePhysicalDeviceMeshShaderPropertiesNV = 1000202001,
    ePhysicalDeviceFragmentShaderBarycentricFeaturesNV = 1000203000,
    ePhysicalDeviceShaderImageFootprintFeaturesNV = 1000204000,
    ePipelineViewportExclusiveScissorStateCreateInfoNV = 1000205000,
    ePhysicalDeviceExclusiveScissorFeaturesNV = 1000205002,
    eCheckpointDataNV = 1000206000,
    eQueueFamilyCheckpointPropertiesNV = 1000206001,
    ePhysicalDeviceShaderIntegerFunctions2FeaturesINTEL = 1000209000,
    eQueryPoolPerformanceQueryCreateInfoINTEL = 1000210000,
    eInitializePerformanceApiInfoINTEL = 1000210001,
    ePerformanceMarkerInfoINTEL = 1000210002,
    ePerformanceStreamMarkerInfoINTEL = 1000210003,
    ePerformanceOverrideInfoINTEL = 1000210004,
    ePerformanceConfigurationAcquireInfoINTEL = 1000210005,
    ePhysicalDevicePciBusInfoPropertiesEXT = 1000212000,
    eDisplayNativeHdrSurfaceCapabilitiesAMD = 1000213000,
    eSwapchainDisplayNativeHdrCreateInfoAMD = 1000213001,
    eImagepipeSurfaceCreateInfoFUCHSIA = 1000214000,
    eMetalSurfaceCreateInfoEXT = 1000217000,
    ePhysicalDeviceFragmentDensityMapFeaturesEXT = 1000218000,
    ePhysicalDeviceFragmentDensityMapPropertiesEXT = 1000218001,
    eRenderPassFragmentDensityMapCreateInfoEXT = 1000218002,
    ePhysicalDeviceSubgroupSizeControlPropertiesEXT = 1000225000,
    ePipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = 1000225001,
    ePhysicalDeviceSubgroupSizeControlFeaturesEXT = 1000225002,
    ePhysicalDeviceShaderCoreProperties2AMD = 1000227000,
    ePhysicalDeviceCoherentMemoryFeaturesAMD = 1000229000,
    ePhysicalDeviceMemoryBudgetPropertiesEXT = 1000237000,
    ePhysicalDeviceMemoryPriorityFeaturesEXT = 1000238000,
    eMemoryPriorityAllocateInfoEXT = 1000238001,
    eSurfaceProtectedCapabilitiesKHR = 1000239000,
    ePhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = 1000240000,
    ePhysicalDeviceBufferDeviceAddressFeaturesEXT = 1000244000,
    eBufferDeviceAddressCreateInfoEXT = 1000244002,
    ePhysicalDeviceToolPropertiesEXT = 1000245000,
    eValidationFeaturesEXT = 1000247000,
    ePhysicalDeviceCooperativeMatrixFeaturesNV = 1000249000,
    eCooperativeMatrixPropertiesNV = 1000249001,
    ePhysicalDeviceCooperativeMatrixPropertiesNV = 1000249002,
    ePhysicalDeviceCoverageReductionModeFeaturesNV = 1000250000,
    ePipelineCoverageReductionStateCreateInfoNV = 1000250001,
    eFramebufferMixedSamplesCombinationNV = 1000250002,
    ePhysicalDeviceFragmentShaderInterlockFeaturesEXT = 1000251000,
    ePhysicalDeviceYcbcrImageArraysFeaturesEXT = 1000252000,
    eSurfaceFullScreenExclusiveInfoEXT = 1000255000,
    eSurfaceCapabilitiesFullScreenExclusiveEXT = 1000255002,
    eSurfaceFullScreenExclusiveWin32InfoEXT = 1000255001,
    eHeadlessSurfaceCreateInfoEXT = 1000256000,
    ePhysicalDeviceLineRasterizationFeaturesEXT = 1000259000,
    ePipelineRasterizationLineStateCreateInfoEXT = 1000259001,
    ePhysicalDeviceLineRasterizationPropertiesEXT = 1000259002,
    ePhysicalDeviceShaderAtomicFloatFeaturesEXT = 1000260000,
    ePhysicalDeviceIndexTypeUint8FeaturesEXT = 1000265000,
    ePhysicalDeviceExtendedDynamicStateFeaturesEXT = 1000267000,
    eDeferredOperationInfoKHR = 1000268000,
    ePhysicalDevicePipelineExecutablePropertiesFeaturesKHR = 1000269000,
    ePipelineInfoKHR = 1000269001,
    ePipelineExecutablePropertiesKHR = 1000269002,
    ePipelineExecutableInfoKHR = 1000269003,
    ePipelineExecutableStatisticKHR = 1000269004,
    ePipelineExecutableInternalRepresentationKHR = 1000269005,
    ePhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = 1000276000,
    ePhysicalDeviceDeviceGeneratedCommandsPropertiesNV = 1000277000,
    eGraphicsShaderGroupCreateInfoNV = 1000277001,
    eGraphicsPipelineShaderGroupsCreateInfoNV = 1000277002,
    eIndirectCommandsLayoutTokenNV = 1000277003,
    eIndirectCommandsLayoutCreateInfoNV = 1000277004,
    eGeneratedCommandsInfoNV = 1000277005,
    eGeneratedCommandsMemoryRequirementsInfoNV = 1000277006,
    ePhysicalDeviceDeviceGeneratedCommandsFeaturesNV = 1000277007,
    ePhysicalDeviceTexelBufferAlignmentFeaturesEXT = 1000281000,
    ePhysicalDeviceTexelBufferAlignmentPropertiesEXT = 1000281001,
    eCommandBufferInheritanceRenderPassTransformInfoQCOM = 1000282000,
    eRenderPassTransformBeginInfoQCOM = 1000282001,
    ePhysicalDeviceRobustness2FeaturesEXT = 1000286000,
    ePhysicalDeviceRobustness2PropertiesEXT = 1000286001,
    eSamplerCustomBorderColorCreateInfoEXT = 1000287000,
    ePhysicalDeviceCustomBorderColorPropertiesEXT = 1000287001,
    ePhysicalDeviceCustomBorderColorFeaturesEXT = 1000287002,
    ePipelineLibraryCreateInfoKHR = 1000290000,
    ePhysicalDevicePrivateDataFeaturesEXT = 1000295000,
    eDevicePrivateDataCreateInfoEXT = 1000295001,
    ePrivateDataSlotCreateInfoEXT = 1000295002,
    ePhysicalDevicePipelineCreationCacheControlFeaturesEXT = 1000297000,
    ePhysicalDeviceDiagnosticsConfigFeaturesNV = 1000300000,
    eDeviceDiagnosticsConfigCreateInfoNV = 1000300001,
    eReservedQCOM = 1000309000,
    ePhysicalDeviceFragmentDensityMap2FeaturesEXT = 1000332000,
    ePhysicalDeviceFragmentDensityMap2PropertiesEXT = 1000332001,
    ePhysicalDeviceImageRobustnessFeaturesEXT = 1000335000,
    ePhysicalDevice4444FormatsFeaturesEXT = 1000340000,
    eDirectfbSurfaceCreateInfoEXT = 1000346000,
    ePhysicalDeviceSubgroupProperties = 1000094000,
    eBindBufferMemoryInfo = 1000157000,
    eBindImageMemoryInfo = 1000157001,
    ePhysicalDevice16BitStorageFeatures = 1000083000,
    eMemoryDedicatedRequirements = 1000127000,
    eMemoryDedicatedAllocateInfo = 1000127001,
    eMemoryAllocateFlagsInfo = 1000060000,
    eDeviceGroupRenderPassBeginInfo = 1000060003,
    eDeviceGroupCommandBufferBeginInfo = 1000060004,
    eDeviceGroupSubmitInfo = 1000060005,
    eDeviceGroupBindSparseInfo = 1000060006,
    eBindBufferMemoryDeviceGroupInfo = 1000060013,
    eBindImageMemoryDeviceGroupInfo = 1000060014,
    ePhysicalDeviceGroupProperties = 1000070000,
    eDeviceGroupDeviceCreateInfo = 1000070001,
    eBufferMemoryRequirementsInfo2 = 1000146000,
    eImageMemoryRequirementsInfo2 = 1000146001,
    eImageSparseMemoryRequirementsInfo2 = 1000146002,
    eMemoryRequirements2 = 1000146003,
    eSparseImageMemoryRequirements2 = 1000146004,
    ePhysicalDeviceFeatures2 = 1000059000,
    ePhysicalDeviceProperties2 = 1000059001,
    eFormatProperties2 = 1000059002,
    eImageFormatProperties2 = 1000059003,
    ePhysicalDeviceImageFormatInfo2 = 1000059004,
    eQueueFamilyProperties2 = 1000059005,
    ePhysicalDeviceMemoryProperties2 = 1000059006,
    eSparseImageFormatProperties2 = 1000059007,
    ePhysicalDeviceSparseImageFormatInfo2 = 1000059008,
    ePhysicalDevicePointClippingProperties = 1000117000,
    eRenderPassInputAttachmentAspectCreateInfo = 1000117001,
    eImageViewUsageCreateInfo = 1000117002,
    ePipelineTessellationDomainOriginStateCreateInfo = 1000117003,
    eRenderPassMultiviewCreateInfo = 1000053000,
    ePhysicalDeviceMultiviewFeatures = 1000053001,
    ePhysicalDeviceMultiviewProperties = 1000053002,
    ePhysicalDeviceVariablePointersFeatures = 1000120000,
    eProtectedSubmitInfo = 1000145000,
    ePhysicalDeviceProtectedMemoryFeatures = 1000145001,
    ePhysicalDeviceProtectedMemoryProperties = 1000145002,
    eDeviceQueueInfo2 = 1000145003,
    eSamplerYcbcrConversionCreateInfo = 1000156000,
    eSamplerYcbcrConversionInfo = 1000156001,
    eBindImagePlaneMemoryInfo = 1000156002,
    eImagePlaneMemoryRequirementsInfo = 1000156003,
    ePhysicalDeviceSamplerYcbcrConversionFeatures = 1000156004,
    eSamplerYcbcrConversionImageFormatProperties = 1000156005,
    eDescriptorUpdateTemplateCreateInfo = 1000085000,
    ePhysicalDeviceExternalImageFormatInfo = 1000071000,
    eExternalImageFormatProperties = 1000071001,
    ePhysicalDeviceExternalBufferInfo = 1000071002,
    eExternalBufferProperties = 1000071003,
    ePhysicalDeviceIdProperties = 1000071004,
    eExternalMemoryBufferCreateInfo = 1000072000,
    eExternalMemoryImageCreateInfo = 1000072001,
    eExportMemoryAllocateInfo = 1000072002,
    ePhysicalDeviceExternalFenceInfo = 1000112000,
    eExternalFenceProperties = 1000112001,
    eExportFenceCreateInfo = 1000113000,
    eExportSemaphoreCreateInfo = 1000077000,
    ePhysicalDeviceExternalSemaphoreInfo = 1000076000,
    eExternalSemaphoreProperties = 1000076001,
    ePhysicalDeviceMaintenance3Properties = 1000168000,
    eDescriptorSetLayoutSupport = 1000168001,
    ePhysicalDeviceShaderDrawParametersFeatures = 1000063000,
    ePhysicalDeviceVulkan11Features = 49,
    ePhysicalDeviceVulkan11Properties = 50,
    ePhysicalDeviceVulkan12Features = 51,
    ePhysicalDeviceVulkan12Properties = 52,
    eImageFormatListCreateInfo = 1000147000,
    eAttachmentDescription2 = 1000109000,
    eAttachmentReference2 = 1000109001,
    eSubpassDescription2 = 1000109002,
    eSubpassDependency2 = 1000109003,
    eRenderPassCreateInfo2 = 1000109004,
    eSubpassBeginInfo = 1000109005,
    eSubpassEndInfo = 1000109006,
    ePhysicalDevice8BitStorageFeatures = 1000177000,
    ePhysicalDeviceDriverProperties = 1000196000,
    ePhysicalDeviceShaderAtomicInt64Features = 1000180000,
    ePhysicalDeviceShaderFloat16Int8Features = 1000082000,
    ePhysicalDeviceFloatControlsProperties = 1000197000,
    eDescriptorSetLayoutBindingFlagsCreateInfo = 1000161000,
    ePhysicalDeviceDescriptorIndexingFeatures = 1000161001,
    ePhysicalDeviceDescriptorIndexingProperties = 1000161002,
    eDescriptorSetVariableDescriptorCountAllocateInfo = 1000161003,
    eDescriptorSetVariableDescriptorCountLayoutSupport = 1000161004,
    ePhysicalDeviceDepthStencilResolveProperties = 1000199000,
    eSubpassDescriptionDepthStencilResolve = 1000199001,
    ePhysicalDeviceScalarBlockLayoutFeatures = 1000221000,
    eImageStencilUsageCreateInfo = 1000246000,
    ePhysicalDeviceSamplerFilterMinmaxProperties = 1000130000,
    eSamplerReductionModeCreateInfo = 1000130001,
    ePhysicalDeviceVulkanMemoryModelFeatures = 1000211000,
    ePhysicalDeviceImagelessFramebufferFeatures = 1000108000,
    eFramebufferAttachmentsCreateInfo = 1000108001,
    eFramebufferAttachmentImageInfo = 1000108002,
    eRenderPassAttachmentBeginInfo = 1000108003,
    ePhysicalDeviceUniformBufferStandardLayoutFeatures = 1000253000,
    ePhysicalDeviceShaderSubgroupExtendedTypesFeatures = 1000175000,
    ePhysicalDeviceSeparateDepthStencilLayoutsFeatures = 1000241000,
    eAttachmentReferenceStencilLayout = 1000241001,
    eAttachmentDescriptionStencilLayout = 1000241002,
    ePhysicalDeviceHostQueryResetFeatures = 1000261000,
    ePhysicalDeviceTimelineSemaphoreFeatures = 1000207000,
    ePhysicalDeviceTimelineSemaphoreProperties = 1000207001,
    eSemaphoreTypeCreateInfo = 1000207002,
    eTimelineSemaphoreSubmitInfo = 1000207003,
    eSemaphoreWaitInfo = 1000207004,
    eSemaphoreSignalInfo = 1000207005,
    ePhysicalDeviceBufferDeviceAddressFeatures = 1000257000,
    eBufferDeviceAddressInfo = 1000244001,
    eBufferOpaqueCaptureAddressCreateInfo = 1000257002,
    eMemoryOpaqueCaptureAddressAllocateInfo = 1000257003,
    eDeviceMemoryOpaqueCaptureAddressInfo = 1000257004,
};
enum class SubpassContents : uint32_t {
    eInline = 0,
    eSecondaryCommandBuffers = 1,
};
enum class Result : int32_t {
    eSuccess = 0,
    eNotReady = 1,
    eTimeout = 2,
    eEventSet = 3,
    eEventReset = 4,
    eIncomplete = 5,
    eErrorOutOfHostMemory = -1,
    eErrorOutOfDeviceMemory = -2,
    eErrorInitializationFailed = -3,
    eErrorDeviceLost = -4,
    eErrorMemoryMapFailed = -5,
    eErrorLayerNotPresent = -6,
    eErrorExtensionNotPresent = -7,
    eErrorFeatureNotPresent = -8,
    eErrorIncompatibleDriver = -9,
    eErrorTooManyObjects = -10,
    eErrorFormatNotSupported = -11,
    eErrorFragmentedPool = -12,
    eErrorUnknown = -13,
    eErrorSurfaceLostKHR = -1000000000,
    eErrorNativeWindowInUseKHR = -1000000001,
    eSuboptimalKHR = 1000001003,
    eErrorOutOfDateKHR = -1000001004,
    eErrorIncompatibleDisplayKHR = -1000003001,
    eErrorValidationFailedEXT = -1000011001,
    eErrorInvalidShaderNV = -1000012000,
    eErrorIncompatibleVersionKHR = -1000150000,
    eErrorInvalidDrmFormatModifierPlaneLayoutEXT = -1000158000,
    eErrorNotPermittedEXT = -1000174001,
    eErrorFullScreenExclusiveModeLostEXT = -1000255000,
    eThreadIdleKHR = 1000268000,
    eThreadDoneKHR = 1000268001,
    eOperationDeferredKHR = 1000268002,
    eOperationNotDeferredKHR = 1000268003,
    ePipelineCompileRequiredEXT = 1000297000,
    eErrorOutOfPoolMemory = -1000069000,
    eErrorInvalidExternalHandle = -1000072003,
    eErrorFragmentation = -1000161000,
    eErrorInvalidOpaqueCaptureAddress = -1000257000,
};
enum class DynamicState : uint32_t {
    eViewport = 0,
    eScissor = 1,
    eLineWidth = 2,
    eDepthBias = 3,
    eBlendConstants = 4,
    eDepthBounds = 5,
    eStencilCompareMask = 6,
    eStencilWriteMask = 7,
    eStencilReference = 8,
    eViewportWScalingNV = 1000087000,
    eDiscardRectangleEXT = 1000099000,
    eSampleLocationsEXT = 1000143000,
    eViewportShadingRatePaletteNV = 1000164004,
    eViewportCoarseSampleOrderNV = 1000164006,
    eExclusiveScissorNV = 1000205001,
    eLineStippleEXT = 1000259000,
    eCullModeEXT = 1000267000,
    eFrontFaceEXT = 1000267001,
    ePrimitiveTopologyEXT = 1000267002,
    eViewportWithCountEXT = 1000267003,
    eScissorWithCountEXT = 1000267004,
    eVertexInputBindingStrideEXT = 1000267005,
    eDepthTestEnableEXT = 1000267006,
    eDepthWriteEnableEXT = 1000267007,
    eDepthCompareOpEXT = 1000267008,
    eDepthBoundsTestEnableEXT = 1000267009,
    eStencilTestEnableEXT = 1000267010,
    eStencilOpEXT = 1000267011,
};
enum class DescriptorUpdateTemplateType : uint32_t {
    eDescriptorSet = 0,
};
enum class ObjectType : uint32_t {
    eUnknown = 0,
    eInstance = 1,
    ePhysicalDevice = 2,
    eDevice = 3,
    eQueue = 4,
    eSemaphore = 5,
    eCommandBuffer = 6,
    eFence = 7,
    eDeviceMemory = 8,
    eBuffer = 9,
    eImage = 10,
    eEvent = 11,
    eQueryPool = 12,
    eBufferView = 13,
    eImageView = 14,
    eShaderModule = 15,
    ePipelineCache = 16,
    ePipelineLayout = 17,
    eRenderPass = 18,
    ePipeline = 19,
    eDescriptorSetLayout = 20,
    eSampler = 21,
    eDescriptorPool = 22,
    eDescriptorSet = 23,
    eFramebuffer = 24,
    eCommandPool = 25,
    eSurfaceKHR = 1000000000,
    eSwapchainKHR = 1000001000,
    eDisplayKHR = 1000002000,
    eDisplayModeKHR = 1000002001,
    eDebugReportCallbackEXT = 1000011000,
    eDebugUtilsMessengerEXT = 1000128000,
    eAccelerationStructureKHR = 1000150000,
    eValidationCacheEXT = 1000160000,
    ePerformanceConfigurationINTEL = 1000210000,
    eDeferredOperationKHR = 1000268000,
    eIndirectCommandsLayoutNV = 1000277000,
    ePrivateDataSlotEXT = 1000295000,
    eSamplerYcbcrConversion = 1000156000,
    eDescriptorUpdateTemplate = 1000085000,
};
enum class SemaphoreType : uint32_t {
    eBinary = 0,
    eTimeline = 1,
};
enum class PresentModeKHR : uint32_t {
    eImmediateKHR = 0,
    eMailboxKHR = 1,
    eFifoKHR = 2,
    eFifoRelaxedKHR = 3,
    eSharedDemandRefreshKHR = 1000111000,
    eSharedContinuousRefreshKHR = 1000111001,
};
enum class ColorSpaceKHR : uint32_t {
    eSrgbNonlinearKHR = 0,
    eDisplayP3NonlinearEXT = 1000104001,
    eExtendedSrgbLinearEXT = 1000104002,
    eDisplayP3LinearEXT = 1000104003,
    eDciP3NonlinearEXT = 1000104004,
    eBt709LinearEXT = 1000104005,
    eBt709NonlinearEXT = 1000104006,
    eBt2020LinearEXT = 1000104007,
    eHdr10St2084EXT = 1000104008,
    eDolbyvisionEXT = 1000104009,
    eHdr10HlgEXT = 1000104010,
    eAdobergbLinearEXT = 1000104011,
    eAdobergbNonlinearEXT = 1000104012,
    ePassThroughEXT = 1000104013,
    eExtendedSrgbNonlinearEXT = 1000104014,
    eDisplayNativeAMD = 1000213000,
};
enum class TimeDomainEXT : uint32_t {
    eDeviceEXT = 0,
    eClockMonotonicEXT = 1,
    eClockMonotonicRawEXT = 2,
    eQueryPerformanceCounterEXT = 3,
};
enum class DebugReportObjectTypeEXT : uint32_t {
    eUnknownEXT = 0,
    eInstanceEXT = 1,
    ePhysicalDeviceEXT = 2,
    eDeviceEXT = 3,
    eQueueEXT = 4,
    eSemaphoreEXT = 5,
    eCommandBufferEXT = 6,
    eFenceEXT = 7,
    eDeviceMemoryEXT = 8,
    eBufferEXT = 9,
    eImageEXT = 10,
    eEventEXT = 11,
    eQueryPoolEXT = 12,
    eBufferViewEXT = 13,
    eImageViewEXT = 14,
    eShaderModuleEXT = 15,
    ePipelineCacheEXT = 16,
    ePipelineLayoutEXT = 17,
    eRenderPassEXT = 18,
    ePipelineEXT = 19,
    eDescriptorSetLayoutEXT = 20,
    eSamplerEXT = 21,
    eDescriptorPoolEXT = 22,
    eDescriptorSetEXT = 23,
    eFramebufferEXT = 24,
    eCommandPoolEXT = 25,
    eSurfaceKhrEXT = 26,
    eSwapchainKhrEXT = 27,
    eDebugReportCallbackExtEXT = 28,
    eDisplayKhrEXT = 29,
    eDisplayModeKhrEXT = 30,
    eValidationCacheExtEXT = 33,
    eSamplerYcbcrConversionEXT = 1000011000,
    eDescriptorUpdateTemplateEXT = 1000011000,
    eAccelerationStructureKhrEXT = 1000150000,
};
enum class RasterizationOrderAMD : uint32_t {
    eStrictAMD = 0,
    eRelaxedAMD = 1,
};
enum class ValidationCheckEXT : uint32_t {
    eAllEXT = 0,
    eShadersEXT = 1,
};
enum class ValidationFeatureEnableEXT : uint32_t {
    eGpuAssistedEXT = 0,
    eGpuAssistedReserveBindingSlotEXT = 1,
    eBestPracticesEXT = 2,
    eDebugPrintfEXT = 3,
    eSynchronizationValidationEXT = 4,
};
enum class ValidationFeatureDisableEXT : uint32_t {
    eAllEXT = 0,
    eShadersEXT = 1,
    eThreadSafetyEXT = 2,
    eApiParametersEXT = 3,
    eObjectLifetimesEXT = 4,
    eCoreChecksEXT = 5,
    eUniqueHandlesEXT = 6,
};
enum class IndirectCommandsTokenTypeNV : uint32_t {
    eShaderGroupNV = 0,
    eStateFlagsNV = 1,
    eIndexBufferNV = 2,
    eVertexBufferNV = 3,
    ePushConstantNV = 4,
    eDrawIndexedNV = 5,
    eDrawNV = 6,
    eDrawTasksNV = 7,
};
enum class DisplayPowerStateEXT : uint32_t {
    eOffEXT = 0,
    eSuspendEXT = 1,
    eOnEXT = 2,
};
enum class DeviceEventTypeEXT : uint32_t {
    eDisplayHotplugEXT = 0,
};
enum class DisplayEventTypeEXT : uint32_t {
    eFirstPixelOutEXT = 0,
};
enum class ViewportCoordinateSwizzleNV : uint32_t {
    ePositiveXNV = 0,
    eNegativeXNV = 1,
    ePositiveYNV = 2,
    eNegativeYNV = 3,
    ePositiveZNV = 4,
    eNegativeZNV = 5,
    ePositiveWNV = 6,
    eNegativeWNV = 7,
};
enum class DiscardRectangleModeEXT : uint32_t {
    eInclusiveEXT = 0,
    eExclusiveEXT = 1,
};
enum class PointClippingBehavior : uint32_t {
    eAllClipPlanes = 0,
    eUserClipPlanesOnly = 1,
};
enum class SamplerReductionMode : uint32_t {
    eWeightedAverage = 0,
    eMin = 1,
    eMax = 2,
};
enum class TessellationDomainOrigin : uint32_t {
    eUpperLeft = 0,
    eLowerLeft = 1,
};
enum class SamplerYcbcrModelConversion : uint32_t {
    eRgbIdentity = 0,
    eYcbcrIdentity = 1,
    eYcbcr709 = 2,
    eYcbcr601 = 3,
    eYcbcr2020 = 4,
};
enum class SamplerYcbcrRange : uint32_t {
    eItuFull = 0,
    eItuNarrow = 1,
};
enum class ChromaLocation : uint32_t {
    eCositedEven = 0,
    eMidpoint = 1,
};
enum class BlendOverlapEXT : uint32_t {
    eUncorrelatedEXT = 0,
    eDisjointEXT = 1,
    eConjointEXT = 2,
};
enum class CoverageModulationModeNV : uint32_t {
    eNoneNV = 0,
    eRgbNV = 1,
    eAlphaNV = 2,
    eRgbaNV = 3,
};
enum class CoverageReductionModeNV : uint32_t {
    eMergeNV = 0,
    eTruncateNV = 1,
};
enum class ValidationCacheHeaderVersionEXT : uint32_t {
    eOneEXT = 1,
};
enum class ShaderInfoTypeAMD : uint32_t {
    eStatisticsAMD = 0,
    eBinaryAMD = 1,
    eDisassemblyAMD = 2,
};
enum class QueueGlobalPriorityEXT : uint32_t {
    eLowEXT = 128,
    eMediumEXT = 256,
    eHighEXT = 512,
    eRealtimeEXT = 1024,
};
enum class ConservativeRasterizationModeEXT : uint32_t {
    eDisabledEXT = 0,
    eOverestimateEXT = 1,
    eUnderestimateEXT = 2,
};
enum class VendorId : uint32_t {
    eVIV = 0x10001,
    eVSI = 0x10002,
    eKazan = 0x10003,
    eCodeplay = 0x10004,
    eMESA = 0x10005,
};
enum class DriverId : uint32_t {
    eAmdProprietary = 1,
    eAmdOpenSource = 2,
    eMesaRadv = 3,
    eNvidiaProprietary = 4,
    eIntelProprietaryWindows = 5,
    eIntelOpenSourceMESA = 6,
    eImaginationProprietary = 7,
    eQualcommProprietary = 8,
    eArmProprietary = 9,
    eGoogleSwiftshader = 10,
    eGgpProprietary = 11,
    eBroadcomProprietary = 12,
    eMesaLlvmpipe = 13,
    eMoltenvk = 14,
};
enum class ShadingRatePaletteEntryNV : uint32_t {
    eNoInvocationsNV = 0,
    e16InvocationsPerPixelNV = 1,
    e8InvocationsPerPixelNV = 2,
    e4InvocationsPerPixelNV = 3,
    e2InvocationsPerPixelNV = 4,
    e1InvocationPerPixelNV = 5,
    e1InvocationPer2X1PixelsNV = 6,
    e1InvocationPer1X2PixelsNV = 7,
    e1InvocationPer2X2PixelsNV = 8,
    e1InvocationPer4X2PixelsNV = 9,
    e1InvocationPer2X4PixelsNV = 10,
    e1InvocationPer4X4PixelsNV = 11,
};
enum class CoarseSampleOrderTypeNV : uint32_t {
    eDefaultNV = 0,
    eCustomNV = 1,
    ePixelMajorNV = 2,
    eSampleMajorNV = 3,
};
enum class CopyAccelerationStructureModeKHR : uint32_t {
    eCloneKHR = 0,
    eCompactKHR = 1,
    eSerializeKHR = 2,
    eDeserializeKHR = 3,
};
enum class AccelerationStructureTypeKHR : uint32_t {
    eTopLevelKHR = 0,
    eBottomLevelKHR = 1,
};
enum class GeometryTypeKHR : uint32_t {
    eTrianglesKHR = 0,
    eAabbsKHR = 1,
    eInstancesKHR = 1000150000,
};
enum class AccelerationStructureMemoryRequirementsTypeKHR : uint32_t {
    eObjectKHR = 0,
    eBuildScratchKHR = 1,
    eUpdateScratchKHR = 2,
};
enum class AccelerationStructureBuildTypeKHR : uint32_t {
    eHostKHR = 0,
    eDeviceKHR = 1,
    eHostOrDeviceKHR = 2,
};
enum class RayTracingShaderGroupTypeKHR : uint32_t {
    eGeneralKHR = 0,
    eTrianglesHitGroupKHR = 1,
    eProceduralHitGroupKHR = 2,
};
enum class MemoryOverallocationBehaviorAMD : uint32_t {
    eDefaultAMD = 0,
    eAllowedAMD = 1,
    eDisallowedAMD = 2,
};
enum class ScopeNV : uint32_t {
    eDeviceNV = 1,
    eWorkgroupNV = 2,
    eSubgroupNV = 3,
    eQueueFamilyNV = 5,
};
enum class ComponentTypeNV : uint32_t {
    eFloat16NV = 0,
    eFloat32NV = 1,
    eFloat64NV = 2,
    eSint8NV = 3,
    eSint16NV = 4,
    eSint32NV = 5,
    eSint64NV = 6,
    eUint8NV = 7,
    eUint16NV = 8,
    eUint32NV = 9,
    eUint64NV = 10,
};
enum class FullScreenExclusiveEXT : uint32_t {
    eDefaultEXT = 0,
    eAllowedEXT = 1,
    eDisallowedEXT = 2,
    eApplicationControlledEXT = 3,
};
enum class PerformanceCounterScopeKHR : uint32_t {
    eCommandBufferKHR = 0,
    eRenderPassKHR = 1,
    eCommandKHR = 2,
};
enum class PerformanceCounterUnitKHR : uint32_t {
    eGenericKHR = 0,
    ePercentageKHR = 1,
    eNanosecondsKHR = 2,
    eBytesKHR = 3,
    eBytesPerSecondKHR = 4,
    eKelvinKHR = 5,
    eWattsKHR = 6,
    eVoltsKHR = 7,
    eAmpsKHR = 8,
    eHertzKHR = 9,
    eCyclesKHR = 10,
};
enum class PerformanceCounterStorageKHR : uint32_t {
    eInt32KHR = 0,
    eInt64KHR = 1,
    eUint32KHR = 2,
    eUint64KHR = 3,
    eFloat32KHR = 4,
    eFloat64KHR = 5,
};
enum class PerformanceConfigurationTypeINTEL : uint32_t {
    eCommandQueueMetricsDiscoveryActivatedINTEL = 0,
};
enum class QueryPoolSamplingModeINTEL : uint32_t {
    eManualINTEL = 0,
};
enum class PerformanceOverrideTypeINTEL : uint32_t {
    eNullHardwareINTEL = 0,
    eFlushGpuCachesINTEL = 1,
};
enum class PerformanceParameterTypeINTEL : uint32_t {
    eHwCountersSupportedINTEL = 0,
    eStreamMarkerValidBitsINTEL = 1,
};
enum class PerformanceValueTypeINTEL : uint32_t {
    eUint32INTEL = 0,
    eUint64INTEL = 1,
    eFloatINTEL = 2,
    eBoolINTEL = 3,
    eStringINTEL = 4,
};
enum class ShaderFloatControlsIndependence : uint32_t {
    e32BitOnly = 0,
    eAll = 1,
    eNone = 2,
};
enum class PipelineExecutableStatisticFormatKHR : uint32_t {
    eBool32KHR = 0,
    eInt64KHR = 1,
    eUint64KHR = 2,
    eFloat64KHR = 3,
};
enum class LineRasterizationModeEXT : uint32_t {
    eDefaultEXT = 0,
    eRectangularEXT = 1,
    eBresenhamEXT = 2,
    eRectangularSmoothEXT = 3,
};
enum class PipelineCacheCreateFlagBits: uint32_t {
    eExternallySynchronizedBitEXT = 1,
};
enum class CullModeFlagBits: uint32_t {
    eNone = 0,
    eFront = 1,
    eBack = 2,
    eFrontAndBack = 0x00000003,
};
enum class QueueFlagBits: uint32_t {
    eGraphics = 1,
    eCompute = 2,
    eTransfer = 4,
    eSparseBinding = 8,
    eReserved6BitKHR = 64,
    eReserved5BitKHR = 32,
    eProtected = 16,
};
enum class RenderPassCreateFlagBits: uint32_t {
    eReserved0BitKHR = 1,
    eTransformBitQCOM = 2,
};
enum class DeviceQueueCreateFlagBits: uint32_t {
    eProtected = 1,
};
enum class MemoryPropertyFlagBits: uint32_t {
    eDeviceLocal = 1,
    eHostVisible = 2,
    eHostCoherent = 4,
    eHostCached = 8,
    eLazilyAllocated = 16,
    eDeviceCoherentBitAMD = 64,
    eDeviceUncachedBitAMD = 128,
    eProtected = 32,
};
enum class MemoryHeapFlagBits: uint32_t {
    eDeviceLocal = 1,
    eReserved2BitKHR = 4,
    eMultiInstance = 2,
};
enum class AccessFlagBits: uint32_t {
    eIndirectCommandRead = 1,
    eIndexRead = 2,
    eVertexAttributeRead = 4,
    eUniformRead = 8,
    eInputAttachmentRead = 16,
    eShaderRead = 32,
    eShaderWrite = 64,
    eColorAttachmentRead = 128,
    eColorAttachmentWrite = 256,
    eDepthStencilAttachmentRead = 512,
    eDepthStencilAttachmentWrite = 1024,
    eTransferRead = 2048,
    eTransferWrite = 4096,
    eHostRead = 8192,
    eHostWrite = 16384,
    eMemoryRead = 32768,
    eMemoryWrite = 65536,
    eReserved30BitKHR = 1073741824,
    eReserved28BitKHR = 268435456,
    eReserved29BitKHR = 536870912,
    eTransformFeedbackWriteBitEXT = 33554432,
    eTransformFeedbackCounterReadBitEXT = 67108864,
    eTransformFeedbackCounterWriteBitEXT = 134217728,
    eConditionalRenderingReadBitEXT = 1048576,
    eColorAttachmentReadNoncoherentBitEXT = 524288,
    eAccelerationStructureReadBitKHR = 2097152,
    eAccelerationStructureWriteBitKHR = 4194304,
    eShadingRateImageReadBitNV = 8388608,
    eFragmentDensityMapReadBitEXT = 16777216,
    eCommandPreprocessReadBitNV = 131072,
    eCommandPreprocessWriteBitNV = 262144,
};
enum class BufferUsageFlagBits: uint32_t {
    eTransferSrc = 1,
    eTransferDst = 2,
    eUniformTexelBuffer = 4,
    eStorageTexelBuffer = 8,
    eUniformBuffer = 16,
    eStorageBuffer = 32,
    eIndexBuffer = 64,
    eVertexBuffer = 128,
    eIndirectBuffer = 256,
    eReserved15BitKHR = 32768,
    eReserved16BitKHR = 65536,
    eReserved13BitKHR = 8192,
    eReserved14BitKHR = 16384,
    eTransformFeedbackBufferBitEXT = 2048,
    eTransformFeedbackCounterBufferBitEXT = 4096,
    eConditionalRenderingBitEXT = 512,
    eRayTracingBitKHR = 1024,
    eReserved19BitKHR = 524288,
    eReserved20BitKHR = 1048576,
    eReserved18BitQCOM = 262144,
    eShaderDeviceAddress = 131072,
};
enum class BufferCreateFlagBits: uint32_t {
    eSparseBinding = 1,
    eSparseResidency = 2,
    eSparseAliased = 4,
    eProtected = 8,
    eDeviceAddressCaptureReplay = 16,
};
enum class ShaderStageFlagBits: uint32_t {
    eVertex = 1,
    eTessellationControl = 2,
    eTessellationEvaluation = 4,
    eGeometry = 8,
    eFragment = 16,
    eCompute = 32,
    eAllGraphics = 0x0000001F,
    eAll = 0x7FFFFFFF,
    eRaygenBitKHR = 256,
    eAnyHitBitKHR = 512,
    eClosestHitBitKHR = 1024,
    eMissBitKHR = 2048,
    eIntersectionBitKHR = 4096,
    eCallableBitKHR = 8192,
    eTaskBitNV = 64,
    eMeshBitNV = 128,
};
enum class ImageUsageFlagBits: uint32_t {
    eTransferSrc = 1,
    eTransferDst = 2,
    eSampled = 4,
    eStorage = 8,
    eColorAttachment = 16,
    eDepthStencilAttachment = 32,
    eTransientAttachment = 64,
    eInputAttachment = 128,
    eReserved13BitKHR = 8192,
    eReserved14BitKHR = 16384,
    eReserved15BitKHR = 32768,
    eReserved10BitKHR = 1024,
    eReserved11BitKHR = 2048,
    eReserved12BitKHR = 4096,
    eShadingRateImageBitNV = 256,
    eReserved16BitQCOM = 65536,
    eReserved17BitQCOM = 131072,
    eFragmentDensityMapBitEXT = 512,
};
enum class ImageCreateFlagBits: uint32_t {
    eSparseBinding = 1,
    eSparseResidency = 2,
    eSparseAliased = 4,
    eMutableFormat = 8,
    eCubeCompatible = 16,
    eCornerSampledBitNV = 8192,
    eSampleLocationsCompatibleDepthBitEXT = 4096,
    eSubsampledBitEXT = 16384,
    eAlias = 1024,
    eSplitInstanceBindRegions = 64,
    e2DArrayCompatible = 32,
    eBlockTexelViewCompatible = 128,
    eExtendedUsage = 256,
    eProtected = 2048,
    eDisjoint = 512,
};
enum class ImageViewCreateFlagBits: uint32_t {
    eFragmentDensityMapDynamicBitEXT = 1,
    eFragmentDensityMapDeferredBitEXT = 2,
};
enum class SamplerCreateFlagBits: uint32_t {
    eSubsampledBitEXT = 1,
    eSubsampledCoarseReconstructionBitEXT = 2,
};
enum class PipelineCreateFlagBits: uint32_t {
    eDisableOptimization = 1,
    eAllowDerivatives = 2,
    eDerivative = 4,
    eRayTracingNoNullAnyHitShadersBitKHR = 16384,
    eRayTracingNoNullClosestHitShadersBitKHR = 32768,
    eRayTracingNoNullMissShadersBitKHR = 65536,
    eRayTracingNoNullIntersectionShadersBitKHR = 131072,
    eRayTracingSkipTrianglesBitKHR = 4096,
    eRayTracingSkipAabbsBitKHR = 8192,
    eDeferCompileBitNV = 32,
    eReserved19BitKHR = 524288,
    eCaptureStatisticsBitKHR = 64,
    eCaptureInternalRepresentationsBitKHR = 128,
    eIndirectBindableBitNV = 262144,
    eLibraryBitKHR = 2048,
    eFailOnPipelineCompileRequiredBitEXT = 256,
    eEarlyReturnOnFailureBitEXT = 512,
    eViewIndexFromDeviceIndex = 8,
    eDispatchBase = 16,
};
enum class PipelineShaderStageCreateFlagBits: uint32_t {
    eReserved2BitNV = 4,
    eAllowVaryingSubgroupSizeBitEXT = 1,
    eRequireFullSubgroupsBitEXT = 2,
    eReserved3BitKHR = 8,
};
enum class ColorComponentFlagBits: uint32_t {
    eR = 1,
    eG = 2,
    eB = 4,
    eA = 8,
};
enum class FenceCreateFlagBits: uint32_t {
    eSignaled = 1,
};
enum class SemaphoreCreateFlagBits: uint32_t {
};
enum class FormatFeatureFlagBits: uint32_t {
    eSampledImage = 1,
    eStorageImage = 2,
    eStorageImageAtomic = 4,
    eUniformTexelBuffer = 8,
    eStorageTexelBuffer = 16,
    eStorageTexelBufferAtomic = 32,
    eVertexBuffer = 64,
    eColorAttachment = 128,
    eColorAttachmentBlend = 256,
    eDepthStencilAttachment = 512,
    eBlitSrc = 1024,
    eBlitDst = 2048,
    eSampledImageFilterLinear = 4096,
    eSampledImageFilterCubicBitIMG = 8192,
    eReserved27BitKHR = 134217728,
    eReserved28BitKHR = 268435456,
    eReserved25BitKHR = 33554432,
    eReserved26BitKHR = 67108864,
    eAccelerationStructureVertexBufferBitKHR = 536870912,
    eFragmentDensityMapBitEXT = 16777216,
    eAmdReserved30 = 1073741824,
    eTransferSrc = 16384,
    eTransferDst = 32768,
    eMidpointChromaSamples = 131072,
    eSampledImageYcbcrConversionLinearFilter = 262144,
    eSampledImageYcbcrConversionSeparateReconstructionFilter = 524288,
    eSampledImageYcbcrConversionChromaReconstructionExplicit = 1048576,
    eSampledImageYcbcrConversionChromaReconstructionExplicitForceable = 2097152,
    eDisjoint = 4194304,
    eCositedChromaSamples = 8388608,
    eSampledImageFilterMinmax = 65536,
};
enum class QueryControlFlagBits: uint32_t {
    ePrecise = 1,
};
enum class QueryResultFlagBits: uint32_t {
    e64 = 1,
    eWait = 2,
    eWithAvailability = 4,
    ePartial = 8,
};
enum class CommandBufferUsageFlagBits: uint32_t {
    eOneTimeSubmit = 1,
    eRenderPassContinue = 2,
    eSimultaneousUse = 4,
};
enum class QueryPipelineStatisticFlagBits: uint32_t {
    eInputAssemblyVertices = 1,
    eInputAssemblyPrimitives = 2,
    eVertexShaderInvocations = 4,
    eGeometryShaderInvocations = 8,
    eGeometryShaderPrimitives = 16,
    eClippingInvocations = 32,
    eClippingPrimitives = 64,
    eFragmentShaderInvocations = 128,
    eTessellationControlShaderPatches = 256,
    eTessellationEvaluationShaderInvocations = 512,
    eComputeShaderInvocations = 1024,
};
enum class ImageAspectFlagBits: uint32_t {
    eColor = 1,
    eDepth = 2,
    eStencil = 4,
    eMetadata = 8,
    eMemoryPlane0BitEXT = 128,
    eMemoryPlane1BitEXT = 256,
    eMemoryPlane2BitEXT = 512,
    eMemoryPlane3BitEXT = 1024,
    ePlane0 = 16,
    ePlane1 = 32,
    ePlane2 = 64,
};
enum class SparseImageFormatFlagBits: uint32_t {
    eSingleMiptail = 1,
    eAlignedMipSize = 2,
    eNonstandardBlockSize = 4,
};
enum class SparseMemoryBindFlagBits: uint32_t {
    eMetadata = 1,
};
enum class PipelineStageFlagBits: uint32_t {
    eTopOfPipe = 1,
    eDrawIndirect = 2,
    eVertexInput = 4,
    eVertexShader = 8,
    eTessellationControlShader = 16,
    eTessellationEvaluationShader = 32,
    eGeometryShader = 64,
    eFragmentShader = 128,
    eEarlyFragmentTests = 256,
    eLateFragmentTests = 512,
    eColorAttachmentOutput = 1024,
    eComputeShader = 2048,
    eTransfer = 4096,
    eBottomOfPipe = 8192,
    eHost = 16384,
    eAllGraphics = 32768,
    eAllCommands = 65536,
    eReserved27BitKHR = 134217728,
    eReserved26BitKHR = 67108864,
    eTransformFeedbackBitEXT = 16777216,
    eConditionalRenderingBitEXT = 262144,
    eRayTracingShaderBitKHR = 2097152,
    eAccelerationStructureBuildBitKHR = 33554432,
    eShadingRateImageBitNV = 4194304,
    eTaskShaderBitNV = 524288,
    eMeshShaderBitNV = 1048576,
    eFragmentDensityProcessBitEXT = 8388608,
    eCommandPreprocessBitNV = 131072,
};
enum class CommandPoolCreateFlagBits: uint32_t {
    eTransient = 1,
    eResetCommandBuffer = 2,
    eProtected = 4,
};
enum class CommandPoolResetFlagBits: uint32_t {
    eReleaseResources = 1,
};
enum class CommandBufferResetFlagBits: uint32_t {
    eReleaseResources = 1,
};
enum class SampleCountFlagBits: uint32_t {
    e1 = 1,
    e2 = 2,
    e4 = 4,
    e8 = 8,
    e16 = 16,
    e32 = 32,
    e64 = 64,
};
enum class AttachmentDescriptionFlagBits: uint32_t {
    eMayAlias = 1,
};
enum class StencilFaceFlagBits: uint32_t {
    eFront = 1,
    eBack = 2,
    eFrontAndBack = 0x00000003,
    eAndBack = eFrontAndBack,
};
enum class DescriptorPoolCreateFlagBits: uint32_t {
    eFreeDescriptorSet = 1,
    eUpdateAfterBind = 2,
};
enum class DependencyFlagBits: uint32_t {
    eByRegion = 1,
    eDeviceGroup = 4,
    eViewLocal = 2,
};
enum class SemaphoreWaitFlagBits: uint32_t {
    eAny = 1,
};
enum class DisplayPlaneAlphaFlagBitsKHR: uint32_t {
    eOpaqueBitKHR = 1,
    eGlobalBitKHR = 2,
    ePerPixelBitKHR = 4,
    ePerPixelPremultipliedBitKHR = 8,
};
enum class CompositeAlphaFlagBitsKHR: uint32_t {
    eOpaqueBitKHR = 1,
    ePreMultipliedBitKHR = 2,
    ePostMultipliedBitKHR = 4,
    eInheritBitKHR = 8,
};
enum class SurfaceTransformFlagBitsKHR: uint32_t {
    eIdentityBitKHR = 1,
    eRotate90BitKHR = 2,
    eRotate180BitKHR = 4,
    eRotate270BitKHR = 8,
    eHorizontalMirrorBitKHR = 16,
    eHorizontalMirrorRotate90BitKHR = 32,
    eHorizontalMirrorRotate180BitKHR = 64,
    eHorizontalMirrorRotate270BitKHR = 128,
    eInheritBitKHR = 256,
};
enum class SwapchainImageUsageFlagBitsANDROID: uint32_t {
    eSharedBitANDROID = 1,
};
enum class DebugReportFlagBitsEXT: uint32_t {
    eInformationBitEXT = 1,
    eWarningBitEXT = 2,
    ePerformanceWarningBitEXT = 4,
    eErrorBitEXT = 8,
    eDebugBitEXT = 16,
};
enum class ExternalMemoryHandleTypeFlagBitsNV: uint32_t {
    eOpaqueWin32BitNV = 1,
    eOpaqueWin32KmtBitNV = 2,
    eD3D11ImageBitNV = 4,
    eD3D11ImageKmtBitNV = 8,
};
enum class ExternalMemoryFeatureFlagBitsNV: uint32_t {
    eDedicatedOnlyBitNV = 1,
    eExportableBitNV = 2,
    eImportableBitNV = 4,
};
enum class SubgroupFeatureFlagBits: uint32_t {
    eBasic = 1,
    eVote = 2,
    eArithmetic = 4,
    eBallot = 8,
    eShuffle = 16,
    eShuffleRelative = 32,
    eClustered = 64,
    eQuad = 128,
    ePartitionedBitNV = 256,
};
enum class IndirectCommandsLayoutUsageFlagBitsNV: uint32_t {
    eExplicitPreprocessBitNV = 1,
    eIndexedSequencesBitNV = 2,
    eUnorderedSequencesBitNV = 4,
};
enum class IndirectStateFlagBitsNV: uint32_t {
    eFlagFrontfaceBitNV = 1,
};
enum class PrivateDataSlotCreateFlagBitsEXT: uint32_t {
};
enum class DescriptorSetLayoutCreateFlagBits: uint32_t {
    ePushDescriptorBitKHR = 1,
    eUpdateAfterBindPool = 2,
};
enum class ExternalMemoryHandleTypeFlagBits: uint32_t {
    eOpaqueFd = 1,
    eOpaqueWin32 = 2,
    eOpaqueWin32Kmt = 4,
    eD3D11Texture = 8,
    eD3D11TextureKmt = 16,
    eD3D12Heap = 32,
    eD3D12Resource = 64,
    eDmaBufBitEXT = 512,
    eAndroidHardwareBufferBitANDROID = 1024,
    eHostAllocationBitEXT = 128,
    eHostMappedForeignMemoryBitEXT = 256,
};
enum class ExternalMemoryFeatureFlagBits: uint32_t {
    eDedicatedOnly = 1,
    eExportable = 2,
    eImportable = 4,
};
enum class ExternalSemaphoreHandleTypeFlagBits: uint32_t {
    eOpaqueFd = 1,
    eOpaqueWin32 = 2,
    eOpaqueWin32Kmt = 4,
    eD3D12Fence = 8,
    eD3D11Fence = eD3D12Fence,
    eSyncFd = 16,
};
enum class ExternalSemaphoreFeatureFlagBits: uint32_t {
    eExportable = 1,
    eImportable = 2,
};
enum class SemaphoreImportFlagBits: uint32_t {
    eTemporary = 1,
};
enum class ExternalFenceHandleTypeFlagBits: uint32_t {
    eOpaqueFd = 1,
    eOpaqueWin32 = 2,
    eOpaqueWin32Kmt = 4,
    eSyncFd = 8,
};
enum class ExternalFenceFeatureFlagBits: uint32_t {
    eExportable = 1,
    eImportable = 2,
};
enum class FenceImportFlagBits: uint32_t {
    eTemporary = 1,
};
enum class SurfaceCounterFlagBitsEXT: uint32_t {
    eVblankEXT = 1,
};
enum class PeerMemoryFeatureFlagBits: uint32_t {
    eCopySrc = 1,
    eCopyDst = 2,
    eGenericSrc = 4,
    eGenericDst = 8,
};
enum class MemoryAllocateFlagBits: uint32_t {
    eDeviceMask = 1,
    eDeviceAddress = 2,
    eDeviceAddressCaptureReplay = 4,
};
enum class DeviceGroupPresentModeFlagBitsKHR: uint32_t {
    eLocalBitKHR = 1,
    eRemoteBitKHR = 2,
    eSumBitKHR = 4,
    eLocalMultiDeviceBitKHR = 8,
};
enum class SwapchainCreateFlagBitsKHR: uint32_t {
    eSplitInstanceBindRegionsBitKHR = 1,
    eProtectedBitKHR = 2,
    eMutableFormatBitKHR = 4,
};
enum class SubpassDescriptionFlagBits: uint32_t {
    ePerViewAttributesBitNVX = 1,
    ePerViewPositionXOnlyBitNVX = 2,
    eFragmentRegionBitQCOM = 4,
    eShaderResolveBitQCOM = 8,
};
enum class DebugUtilsMessageSeverityFlagBitsEXT: uint32_t {
    eVerboseBitEXT = 1,
    eInfoBitEXT = 16,
    eWarningBitEXT = 256,
    eErrorBitEXT = 4096,
};
enum class DebugUtilsMessageTypeFlagBitsEXT: uint32_t {
    eGeneralBitEXT = 1,
    eValidationBitEXT = 2,
    ePerformanceBitEXT = 4,
};
enum class DescriptorBindingFlagBits: uint32_t {
    eUpdateAfterBind = 1,
    eUpdateUnusedWhilePending = 2,
    ePartiallyBound = 4,
    eVariableDescriptorCount = 8,
};
enum class ConditionalRenderingFlagBitsEXT: uint32_t {
    eInvertedBitEXT = 1,
};
enum class ResolveModeFlagBits: uint32_t {
    eNone = 0,
    eSampleZero = 1,
    eAverage = 2,
    eMin = 4,
    eMax = 8,
};
enum class GeometryInstanceFlagBitsKHR: uint32_t {
    eTriangleFacingCullDisableBitKHR = 1,
    eTriangleFrontCounterclockwiseBitKHR = 2,
    eForceOpaqueBitKHR = 4,
    eForceNoOpaqueBitKHR = 8,
};
enum class GeometryFlagBitsKHR: uint32_t {
    eOpaqueBitKHR = 1,
    eNoDuplicateAnyHitInvocationBitKHR = 2,
};
enum class BuildAccelerationStructureFlagBitsKHR: uint32_t {
    eAllowUpdateBitKHR = 1,
    eAllowCompactionBitKHR = 2,
    ePreferFastTraceBitKHR = 4,
    ePreferFastBuildBitKHR = 8,
    eLowMemoryBitKHR = 16,
};
enum class FramebufferCreateFlagBits: uint32_t {
    eImageless = 1,
};
enum class DeviceDiagnosticsConfigFlagBitsNV: uint32_t {
    eEnableShaderDebugInfoBitNV = 1,
    eEnableResourceTrackingBitNV = 2,
    eEnableAutomaticCheckpointsBitNV = 4,
};
enum class PipelineCreationFeedbackFlagBitsEXT: uint32_t {
    eValidBitEXT = 1,
    eApplicationPipelineCacheHitBitEXT = 2,
    eBasePipelineAccelerationBitEXT = 4,
};
enum class PerformanceCounterDescriptionFlagBitsKHR: uint32_t {
    ePerformanceImpactingKHR = 1,
    eConcurrentlyImpactedKHR = 2,
};
enum class AcquireProfilingLockFlagBitsKHR: uint32_t {
};
enum class ShaderCorePropertiesFlagBitsAMD: uint32_t {
};
enum class ShaderModuleCreateFlagBits: uint32_t {
    eReserved0BitNV = 1,
};
enum class PipelineCompilerControlFlagBitsAMD: uint32_t {
};
enum class ToolPurposeFlagBitsEXT: uint32_t {
    eValidationBitEXT = 1,
    eProfilingBitEXT = 2,
    eTracingBitEXT = 4,
    eAdditionalFeaturesBitEXT = 8,
    eModifyingFeaturesBitEXT = 16,
    eDebugReportingBitEXT = 32,
    eDebugMarkersBitEXT = 64,
};
using DescriptorUpdateTemplateTypeKHR = DescriptorUpdateTemplateType;
using PointClippingBehaviorKHR = PointClippingBehavior;
using ResolveModeFlagBitsKHR = ResolveModeFlagBits;
using DescriptorBindingFlagBitsEXT = DescriptorBindingFlagBits;
using SemaphoreTypeKHR = SemaphoreType;
using GeometryFlagBitsNV = GeometryFlagBitsKHR;
using GeometryInstanceFlagBitsNV = GeometryInstanceFlagBitsKHR;
using BuildAccelerationStructureFlagBitsNV = BuildAccelerationStructureFlagBitsKHR;
using CopyAccelerationStructureModeNV = CopyAccelerationStructureModeKHR;
using AccelerationStructureTypeNV = AccelerationStructureTypeKHR;
using GeometryTypeNV = GeometryTypeKHR;
using RayTracingShaderGroupTypeNV = RayTracingShaderGroupTypeKHR;
using AccelerationStructureMemoryRequirementsTypeNV = AccelerationStructureMemoryRequirementsTypeKHR;
using SemaphoreWaitFlagBitsKHR = SemaphoreWaitFlagBits;
using ExternalMemoryHandleTypeFlagBitsKHR = ExternalMemoryHandleTypeFlagBits;
using ExternalMemoryFeatureFlagBitsKHR = ExternalMemoryFeatureFlagBits;
using ExternalSemaphoreHandleTypeFlagBitsKHR = ExternalSemaphoreHandleTypeFlagBits;
using ExternalSemaphoreFeatureFlagBitsKHR = ExternalSemaphoreFeatureFlagBits;
using SemaphoreImportFlagBitsKHR = SemaphoreImportFlagBits;
using ExternalFenceHandleTypeFlagBitsKHR = ExternalFenceHandleTypeFlagBits;
using ExternalFenceFeatureFlagBitsKHR = ExternalFenceFeatureFlagBits;
using FenceImportFlagBitsKHR = FenceImportFlagBits;
using PeerMemoryFeatureFlagBitsKHR = PeerMemoryFeatureFlagBits;
using MemoryAllocateFlagBitsKHR = MemoryAllocateFlagBits;
using TessellationDomainOriginKHR = TessellationDomainOrigin;
using SamplerYcbcrModelConversionKHR = SamplerYcbcrModelConversion;
using SamplerYcbcrRangeKHR = SamplerYcbcrRange;
using ChromaLocationKHR = ChromaLocation;
using SamplerReductionModeEXT = SamplerReductionMode;
using ShaderFloatControlsIndependenceKHR = ShaderFloatControlsIndependence;
using DriverIdKHR = DriverId;
using FramebufferCreateFlags = uint32_t;
using QueryPoolCreateFlags = uint32_t;
using RenderPassCreateFlags = uint32_t;
using SamplerCreateFlags = uint32_t;
using PipelineLayoutCreateFlags = uint32_t;
using PipelineCacheCreateFlags = uint32_t;
using PipelineDepthStencilStateCreateFlags = uint32_t;
using PipelineDynamicStateCreateFlags = uint32_t;
using PipelineColorBlendStateCreateFlags = uint32_t;
using PipelineMultisampleStateCreateFlags = uint32_t;
using PipelineRasterizationStateCreateFlags = uint32_t;
using PipelineViewportStateCreateFlags = uint32_t;
using PipelineTessellationStateCreateFlags = uint32_t;
using PipelineInputAssemblyStateCreateFlags = uint32_t;
using PipelineVertexInputStateCreateFlags = uint32_t;
using PipelineShaderStageCreateFlags = uint32_t;
using DescriptorSetLayoutCreateFlags = uint32_t;
using BufferViewCreateFlags = uint32_t;
using InstanceCreateFlags = uint32_t;
using DeviceCreateFlags = uint32_t;
using DeviceQueueCreateFlags = uint32_t;
using QueueFlags = uint32_t;
using MemoryPropertyFlags = uint32_t;
using MemoryHeapFlags = uint32_t;
using AccessFlags = uint32_t;
using BufferUsageFlags = uint32_t;
using BufferCreateFlags = uint32_t;
using ShaderStageFlags = uint32_t;
using ImageUsageFlags = uint32_t;
using ImageCreateFlags = uint32_t;
using ImageViewCreateFlags = uint32_t;
using PipelineCreateFlags = uint32_t;
using ColorComponentFlags = uint32_t;
using FenceCreateFlags = uint32_t;
using SemaphoreCreateFlags = uint32_t;
using FormatFeatureFlags = uint32_t;
using QueryControlFlags = uint32_t;
using QueryResultFlags = uint32_t;
using ShaderModuleCreateFlags = uint32_t;
using EventCreateFlags = uint32_t;
using CommandPoolCreateFlags = uint32_t;
using CommandPoolResetFlags = uint32_t;
using CommandBufferResetFlags = uint32_t;
using CommandBufferUsageFlags = uint32_t;
using QueryPipelineStatisticFlags = uint32_t;
using MemoryMapFlags = uint32_t;
using ImageAspectFlags = uint32_t;
using SparseMemoryBindFlags = uint32_t;
using SparseImageFormatFlags = uint32_t;
using SubpassDescriptionFlags = uint32_t;
using PipelineStageFlags = uint32_t;
using SampleCountFlags = uint32_t;
using AttachmentDescriptionFlags = uint32_t;
using StencilFaceFlags = uint32_t;
using CullModeFlags = uint32_t;
using DescriptorPoolCreateFlags = uint32_t;
using DescriptorPoolResetFlags = uint32_t;
using DependencyFlags = uint32_t;
using SubgroupFeatureFlags = uint32_t;
using IndirectCommandsLayoutUsageFlagsNV = uint32_t;
using IndirectStateFlagsNV = uint32_t;
using GeometryFlagsKHR = uint32_t;
using GeometryFlagsNV = uint32_t;
using GeometryInstanceFlagsKHR = uint32_t;
using GeometryInstanceFlagsNV = uint32_t;
using BuildAccelerationStructureFlagsKHR = uint32_t;
using BuildAccelerationStructureFlagsNV = uint32_t;
using PrivateDataSlotCreateFlagsEXT = uint32_t;
using DescriptorUpdateTemplateCreateFlags = uint32_t;
using DescriptorUpdateTemplateCreateFlagsKHR = uint32_t;
using PipelineCreationFeedbackFlagsEXT = uint32_t;
using PerformanceCounterDescriptionFlagsKHR = uint32_t;
using AcquireProfilingLockFlagsKHR = uint32_t;
using SemaphoreWaitFlags = uint32_t;
using SemaphoreWaitFlagsKHR = uint32_t;
using PipelineCompilerControlFlagsAMD = uint32_t;
using ShaderCorePropertiesFlagsAMD = uint32_t;
using DeviceDiagnosticsConfigFlagsNV = uint32_t;
using CompositeAlphaFlagsKHR = uint32_t;
using DisplayPlaneAlphaFlagsKHR = uint32_t;
using SurfaceTransformFlagsKHR = uint32_t;
using SwapchainCreateFlagsKHR = uint32_t;
using DisplayModeCreateFlagsKHR = uint32_t;
using DisplaySurfaceCreateFlagsKHR = uint32_t;
using AndroidSurfaceCreateFlagsKHR = uint32_t;
using ViSurfaceCreateFlagsNN = uint32_t;
using WaylandSurfaceCreateFlagsKHR = uint32_t;
using Win32SurfaceCreateFlagsKHR = uint32_t;
using XlibSurfaceCreateFlagsKHR = uint32_t;
using XcbSurfaceCreateFlagsKHR = uint32_t;
using DirectFBSurfaceCreateFlagsEXT = uint32_t;
using IOSSurfaceCreateFlagsMVK = uint32_t;
using MacOSSurfaceCreateFlagsMVK = uint32_t;
using MetalSurfaceCreateFlagsEXT = uint32_t;
using ImagePipeSurfaceCreateFlagsFUCHSIA = uint32_t;
using StreamDescriptorSurfaceCreateFlagsGGP = uint32_t;
using HeadlessSurfaceCreateFlagsEXT = uint32_t;
using PeerMemoryFeatureFlags = uint32_t;
using PeerMemoryFeatureFlagsKHR = uint32_t;
using MemoryAllocateFlags = uint32_t;
using MemoryAllocateFlagsKHR = uint32_t;
using DeviceGroupPresentModeFlagsKHR = uint32_t;
using DebugReportFlagsEXT = uint32_t;
using CommandPoolTrimFlags = uint32_t;
using CommandPoolTrimFlagsKHR = uint32_t;
using ExternalMemoryHandleTypeFlagsNV = uint32_t;
using ExternalMemoryFeatureFlagsNV = uint32_t;
using ExternalMemoryHandleTypeFlags = uint32_t;
using ExternalMemoryHandleTypeFlagsKHR = uint32_t;
using ExternalMemoryFeatureFlags = uint32_t;
using ExternalMemoryFeatureFlagsKHR = uint32_t;
using ExternalSemaphoreHandleTypeFlags = uint32_t;
using ExternalSemaphoreHandleTypeFlagsKHR = uint32_t;
using ExternalSemaphoreFeatureFlags = uint32_t;
using ExternalSemaphoreFeatureFlagsKHR = uint32_t;
using SemaphoreImportFlags = uint32_t;
using SemaphoreImportFlagsKHR = uint32_t;
using ExternalFenceHandleTypeFlags = uint32_t;
using ExternalFenceHandleTypeFlagsKHR = uint32_t;
using ExternalFenceFeatureFlags = uint32_t;
using ExternalFenceFeatureFlagsKHR = uint32_t;
using FenceImportFlags = uint32_t;
using FenceImportFlagsKHR = uint32_t;
using SurfaceCounterFlagsEXT = uint32_t;
using PipelineViewportSwizzleStateCreateFlagsNV = uint32_t;
using PipelineDiscardRectangleStateCreateFlagsEXT = uint32_t;
using PipelineCoverageToColorStateCreateFlagsNV = uint32_t;
using PipelineCoverageModulationStateCreateFlagsNV = uint32_t;
using PipelineCoverageReductionStateCreateFlagsNV = uint32_t;
using ValidationCacheCreateFlagsEXT = uint32_t;
using DebugUtilsMessageSeverityFlagsEXT = uint32_t;
using DebugUtilsMessageTypeFlagsEXT = uint32_t;
using DebugUtilsMessengerCreateFlagsEXT = uint32_t;
using DebugUtilsMessengerCallbackDataFlagsEXT = uint32_t;
using PipelineRasterizationConservativeStateCreateFlagsEXT = uint32_t;
using DescriptorBindingFlags = uint32_t;
using DescriptorBindingFlagsEXT = uint32_t;
using ConditionalRenderingFlagsEXT = uint32_t;
using ResolveModeFlags = uint32_t;
using ResolveModeFlagsKHR = uint32_t;
using PipelineRasterizationStateStreamCreateFlagsEXT = uint32_t;
using PipelineRasterizationDepthClipStateCreateFlagsEXT = uint32_t;
using SwapchainImageUsageFlagsANDROID = uint32_t;
using ToolPurposeFlagsEXT = uint32_t;
struct Instance;
struct PhysicalDevice;
struct Device;
struct Queue;
struct CommandBuffer;
struct Instance {
    VkInstance handle;
    VkInstance get() const { return handle; }
};
struct PhysicalDevice {
    VkPhysicalDevice handle;
    VkPhysicalDevice get() const { return handle; }
};
struct Device {
    VkDevice handle;
    VkDevice get() const { return handle; }
};
struct Queue {
    VkQueue handle;
    VkQueue get() const { return handle; }
};
struct CommandBuffer {
    VkCommandBuffer handle;
    VkCommandBuffer get() const { return handle; }
};
class DeviceMemory {
   VkDeviceMemory handle = VK_NULL_HANDLE;
   public:
   VkDeviceMemory get() { return handle; }
};
class CommandPool {
   VkCommandPool handle = VK_NULL_HANDLE;
   public:
   VkCommandPool get() { return handle; }
};
class Buffer {
   VkBuffer handle = VK_NULL_HANDLE;
   public:
   VkBuffer get() { return handle; }
};
class BufferView {
   VkBufferView handle = VK_NULL_HANDLE;
   public:
   VkBufferView get() { return handle; }
};
class Image {
   VkImage handle = VK_NULL_HANDLE;
   public:
   VkImage get() { return handle; }
};
class ImageView {
   VkImageView handle = VK_NULL_HANDLE;
   public:
   VkImageView get() { return handle; }
};
class ShaderModule {
   VkShaderModule handle = VK_NULL_HANDLE;
   public:
   VkShaderModule get() { return handle; }
};
class Pipeline {
   VkPipeline handle = VK_NULL_HANDLE;
   public:
   VkPipeline get() { return handle; }
};
class PipelineLayout {
   VkPipelineLayout handle = VK_NULL_HANDLE;
   public:
   VkPipelineLayout get() { return handle; }
};
class Sampler {
   VkSampler handle = VK_NULL_HANDLE;
   public:
   VkSampler get() { return handle; }
};
class DescriptorSet {
   VkDescriptorSet handle = VK_NULL_HANDLE;
   public:
   VkDescriptorSet get() { return handle; }
};
class DescriptorSetLayout {
   VkDescriptorSetLayout handle = VK_NULL_HANDLE;
   public:
   VkDescriptorSetLayout get() { return handle; }
};
class DescriptorPool {
   VkDescriptorPool handle = VK_NULL_HANDLE;
   public:
   VkDescriptorPool get() { return handle; }
};
class Fence {
   VkFence handle = VK_NULL_HANDLE;
   public:
   VkFence get() { return handle; }
};
class Semaphore {
   VkSemaphore handle = VK_NULL_HANDLE;
   public:
   VkSemaphore get() { return handle; }
};
class Event {
   VkEvent handle = VK_NULL_HANDLE;
   public:
   VkEvent get() { return handle; }
};
class QueryPool {
   VkQueryPool handle = VK_NULL_HANDLE;
   public:
   VkQueryPool get() { return handle; }
};
class Framebuffer {
   VkFramebuffer handle = VK_NULL_HANDLE;
   public:
   VkFramebuffer get() { return handle; }
};
class RenderPass {
   VkRenderPass handle = VK_NULL_HANDLE;
   public:
   VkRenderPass get() { return handle; }
};
class PipelineCache {
   VkPipelineCache handle = VK_NULL_HANDLE;
   public:
   VkPipelineCache get() { return handle; }
};
class IndirectCommandsLayoutNV {
   VkIndirectCommandsLayoutNV handle = VK_NULL_HANDLE;
   public:
   VkIndirectCommandsLayoutNV get() { return handle; }
};
class DescriptorUpdateTemplate {
   VkDescriptorUpdateTemplate handle = VK_NULL_HANDLE;
   public:
   VkDescriptorUpdateTemplate get() { return handle; }
};
class SamplerYcbcrConversion {
   VkSamplerYcbcrConversion handle = VK_NULL_HANDLE;
   public:
   VkSamplerYcbcrConversion get() { return handle; }
};
class ValidationCacheEXT {
   VkValidationCacheEXT handle = VK_NULL_HANDLE;
   public:
   VkValidationCacheEXT get() { return handle; }
};
class AccelerationStructureKHR {
   VkAccelerationStructureKHR handle = VK_NULL_HANDLE;
   public:
   VkAccelerationStructureKHR get() { return handle; }
};
class PerformanceConfigurationINTEL {
   VkPerformanceConfigurationINTEL handle = VK_NULL_HANDLE;
   public:
   VkPerformanceConfigurationINTEL get() { return handle; }
};
class DeferredOperationKHR {
   VkDeferredOperationKHR handle = VK_NULL_HANDLE;
   public:
   VkDeferredOperationKHR get() { return handle; }
};
class PrivateDataSlotEXT {
   VkPrivateDataSlotEXT handle = VK_NULL_HANDLE;
   public:
   VkPrivateDataSlotEXT get() { return handle; }
};
class DisplayKHR {
   VkDisplayKHR handle = VK_NULL_HANDLE;
   public:
   VkDisplayKHR get() { return handle; }
};
class DisplayModeKHR {
   VkDisplayModeKHR handle = VK_NULL_HANDLE;
   public:
   VkDisplayModeKHR get() { return handle; }
};
class SurfaceKHR {
   VkSurfaceKHR handle = VK_NULL_HANDLE;
   public:
   VkSurfaceKHR get() { return handle; }
};
class SwapchainKHR {
   VkSwapchainKHR handle = VK_NULL_HANDLE;
   public:
   VkSwapchainKHR get() { return handle; }
};
class DebugReportCallbackEXT {
   VkDebugReportCallbackEXT handle = VK_NULL_HANDLE;
   public:
   VkDebugReportCallbackEXT get() { return handle; }
};
class DebugUtilsMessengerEXT {
   VkDebugUtilsMessengerEXT handle = VK_NULL_HANDLE;
   public:
   VkDebugUtilsMessengerEXT get() { return handle; }
};
using DescriptorUpdateTemplateKHR = DescriptorUpdateTemplate;
using SamplerYcbcrConversionKHR = SamplerYcbcrConversion;
using AccelerationStructureNV = AccelerationStructureKHR;
struct BaseOutStructure {
    StructureType sType = static_cast<StructureType>(0);
    BaseOutStructure* pNext = nullptr;
    operator VkBaseOutStructure const &() const noexcept {
        return *reinterpret_cast<const VkBaseOutStructure*>(this);
    }
    operator VkBaseOutStructure &() noexcept {
        return *reinterpret_cast<VkBaseOutStructure*>(this);
    }
};
struct BaseInStructure {
    StructureType sType = static_cast<StructureType>(0);
    const BaseInStructure* pNext = nullptr;
    operator VkBaseInStructure const &() const noexcept {
        return *reinterpret_cast<const VkBaseInStructure*>(this);
    }
    operator VkBaseInStructure &() noexcept {
        return *reinterpret_cast<VkBaseInStructure*>(this);
    }
};
struct Offset2D {
    int32_t x = 0;
    int32_t y = 0;
    operator VkOffset2D const &() const noexcept {
        return *reinterpret_cast<const VkOffset2D*>(this);
    }
    operator VkOffset2D &() noexcept {
        return *reinterpret_cast<VkOffset2D*>(this);
    }
};
struct Offset3D {
    int32_t x = 0;
    int32_t y = 0;
    int32_t z = 0;
    operator VkOffset3D const &() const noexcept {
        return *reinterpret_cast<const VkOffset3D*>(this);
    }
    operator VkOffset3D &() noexcept {
        return *reinterpret_cast<VkOffset3D*>(this);
    }
};
struct Extent2D {
    uint32_t width = 0;
    uint32_t height = 0;
    operator VkExtent2D const &() const noexcept {
        return *reinterpret_cast<const VkExtent2D*>(this);
    }
    operator VkExtent2D &() noexcept {
        return *reinterpret_cast<VkExtent2D*>(this);
    }
};
struct Extent3D {
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t depth = 0;
    operator VkExtent3D const &() const noexcept {
        return *reinterpret_cast<const VkExtent3D*>(this);
    }
    operator VkExtent3D &() noexcept {
        return *reinterpret_cast<VkExtent3D*>(this);
    }
};
struct Viewport {
    float x = 0.f;
    float y = 0.f;
    float width = 0.f;
    float height = 0.f;
    float minDepth = 0.f;
    float maxDepth = 0.f;
    operator VkViewport const &() const noexcept {
        return *reinterpret_cast<const VkViewport*>(this);
    }
    operator VkViewport &() noexcept {
        return *reinterpret_cast<VkViewport*>(this);
    }
};
struct Rect2D {
    Offset2D offset;
    Extent2D extent;
    operator VkRect2D const &() const noexcept {
        return *reinterpret_cast<const VkRect2D*>(this);
    }
    operator VkRect2D &() noexcept {
        return *reinterpret_cast<VkRect2D*>(this);
    }
};
struct ClearRect {
    Rect2D rect;
    uint32_t baseArrayLayer = 0;
    uint32_t layerCount = 0;
    operator VkClearRect const &() const noexcept {
        return *reinterpret_cast<const VkClearRect*>(this);
    }
    operator VkClearRect &() noexcept {
        return *reinterpret_cast<VkClearRect*>(this);
    }
};
struct ComponentMapping {
    ComponentSwizzle r = static_cast<ComponentSwizzle>(0);
    ComponentSwizzle g = static_cast<ComponentSwizzle>(0);
    ComponentSwizzle b = static_cast<ComponentSwizzle>(0);
    ComponentSwizzle a = static_cast<ComponentSwizzle>(0);
    operator VkComponentMapping const &() const noexcept {
        return *reinterpret_cast<const VkComponentMapping*>(this);
    }
    operator VkComponentMapping &() noexcept {
        return *reinterpret_cast<VkComponentMapping*>(this);
    }
};
struct PhysicalDeviceSparseProperties {
    bool residencyStandard2DBlockShape = false;
    bool residencyStandard2DMultisampleBlockShape = false;
    bool residencyStandard3DBlockShape = false;
    bool residencyAlignedMipSize = false;
    bool residencyNonResidentStrict = false;
    operator VkPhysicalDeviceSparseProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSparseProperties*>(this);
    }
    operator VkPhysicalDeviceSparseProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSparseProperties*>(this);
    }
};
struct PhysicalDeviceLimits {
    uint32_t maxImageDimension1D = 0;
    uint32_t maxImageDimension2D = 0;
    uint32_t maxImageDimension3D = 0;
    uint32_t maxImageDimensionCube = 0;
    uint32_t maxImageArrayLayers = 0;
    uint32_t maxTexelBufferElements = 0;
    uint32_t maxUniformBufferRange = 0;
    uint32_t maxStorageBufferRange = 0;
    uint32_t maxPushConstantsSize = 0;
    uint32_t maxMemoryAllocationCount = 0;
    uint32_t maxSamplerAllocationCount = 0;
    DeviceSize bufferImageGranularity = 0;
    DeviceSize sparseAddressSpaceSize = 0;
    uint32_t maxBoundDescriptorSets = 0;
    uint32_t maxPerStageDescriptorSamplers = 0;
    uint32_t maxPerStageDescriptorUniformBuffers = 0;
    uint32_t maxPerStageDescriptorStorageBuffers = 0;
    uint32_t maxPerStageDescriptorSampledImages = 0;
    uint32_t maxPerStageDescriptorStorageImages = 0;
    uint32_t maxPerStageDescriptorInputAttachments = 0;
    uint32_t maxPerStageResources = 0;
    uint32_t maxDescriptorSetSamplers = 0;
    uint32_t maxDescriptorSetUniformBuffers = 0;
    uint32_t maxDescriptorSetUniformBuffersDynamic = 0;
    uint32_t maxDescriptorSetStorageBuffers = 0;
    uint32_t maxDescriptorSetStorageBuffersDynamic = 0;
    uint32_t maxDescriptorSetSampledImages = 0;
    uint32_t maxDescriptorSetStorageImages = 0;
    uint32_t maxDescriptorSetInputAttachments = 0;
    uint32_t maxVertexInputAttributes = 0;
    uint32_t maxVertexInputBindings = 0;
    uint32_t maxVertexInputAttributeOffset = 0;
    uint32_t maxVertexInputBindingStride = 0;
    uint32_t maxVertexOutputComponents = 0;
    uint32_t maxTessellationGenerationLevel = 0;
    uint32_t maxTessellationPatchSize = 0;
    uint32_t maxTessellationControlPerVertexInputComponents = 0;
    uint32_t maxTessellationControlPerVertexOutputComponents = 0;
    uint32_t maxTessellationControlPerPatchOutputComponents = 0;
    uint32_t maxTessellationControlTotalOutputComponents = 0;
    uint32_t maxTessellationEvaluationInputComponents = 0;
    uint32_t maxTessellationEvaluationOutputComponents = 0;
    uint32_t maxGeometryShaderInvocations = 0;
    uint32_t maxGeometryInputComponents = 0;
    uint32_t maxGeometryOutputComponents = 0;
    uint32_t maxGeometryOutputVertices = 0;
    uint32_t maxGeometryTotalOutputComponents = 0;
    uint32_t maxFragmentInputComponents = 0;
    uint32_t maxFragmentOutputAttachments = 0;
    uint32_t maxFragmentDualSrcAttachments = 0;
    uint32_t maxFragmentCombinedOutputResources = 0;
    uint32_t maxComputeSharedMemorySize = 0;
    uint32_t maxComputeWorkGroupCount[3] = {};
    uint32_t maxComputeWorkGroupInvocations = 0;
    uint32_t maxComputeWorkGroupSize[3] = {};
    uint32_t subPixelPrecisionBits = 0;
    uint32_t subTexelPrecisionBits = 0;
    uint32_t mipmapPrecisionBits = 0;
    uint32_t maxDrawIndexedIndexValue = 0;
    uint32_t maxDrawIndirectCount = 0;
    float maxSamplerLodBias = 0.f;
    float maxSamplerAnisotropy = 0.f;
    uint32_t maxViewports = 0;
    uint32_t maxViewportDimensions[2] = {};
    float viewportBoundsRange[2] = {};
    uint32_t viewportSubPixelBits = 0;
    size_t minMemoryMapAlignment = 0;
    DeviceSize minTexelBufferOffsetAlignment = 0;
    DeviceSize minUniformBufferOffsetAlignment = 0;
    DeviceSize minStorageBufferOffsetAlignment = 0;
    int32_t minTexelOffset = 0;
    uint32_t maxTexelOffset = 0;
    int32_t minTexelGatherOffset = 0;
    uint32_t maxTexelGatherOffset = 0;
    float minInterpolationOffset = 0.f;
    float maxInterpolationOffset = 0.f;
    uint32_t subPixelInterpolationOffsetBits = 0;
    uint32_t maxFramebufferWidth = 0;
    uint32_t maxFramebufferHeight = 0;
    uint32_t maxFramebufferLayers = 0;
    SampleCountFlags framebufferColorSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags framebufferDepthSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags framebufferStencilSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags framebufferNoAttachmentsSampleCounts = static_cast<SampleCountFlags>(0);
    uint32_t maxColorAttachments = 0;
    SampleCountFlags sampledImageColorSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags sampledImageIntegerSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags sampledImageDepthSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags sampledImageStencilSampleCounts = static_cast<SampleCountFlags>(0);
    SampleCountFlags storageImageSampleCounts = static_cast<SampleCountFlags>(0);
    uint32_t maxSampleMaskWords = 0;
    bool timestampComputeAndGraphics = false;
    float timestampPeriod = 0.f;
    uint32_t maxClipDistances = 0;
    uint32_t maxCullDistances = 0;
    uint32_t maxCombinedClipAndCullDistances = 0;
    uint32_t discreteQueuePriorities = 0;
    float pointSizeRange[2] = {};
    float lineWidthRange[2] = {};
    float pointSizeGranularity = 0.f;
    float lineWidthGranularity = 0.f;
    bool strictLines = false;
    bool standardSampleLocations = false;
    DeviceSize optimalBufferCopyOffsetAlignment = 0;
    DeviceSize optimalBufferCopyRowPitchAlignment = 0;
    DeviceSize nonCoherentAtomSize = 0;
    operator VkPhysicalDeviceLimits const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceLimits*>(this);
    }
    operator VkPhysicalDeviceLimits &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceLimits*>(this);
    }
};
struct PhysicalDeviceProperties {
    uint32_t apiVersion = 0;
    uint32_t driverVersion = 0;
    uint32_t vendorID = 0;
    uint32_t deviceID = 0;
    PhysicalDeviceType deviceType = static_cast<PhysicalDeviceType>(0);
    char deviceName[MAX_PHYSICAL_DEVICE_NAME_SIZE] = {};
    uint8_t pipelineCacheUUID[UUID_SIZE] = {};
    PhysicalDeviceLimits limits;
    PhysicalDeviceSparseProperties sparseProperties;
    operator VkPhysicalDeviceProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceProperties*>(this);
    }
    operator VkPhysicalDeviceProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceProperties*>(this);
    }
};
struct ExtensionProperties {
    char extensionName[MAX_EXTENSION_NAME_SIZE] = {};
    uint32_t specVersion = 0;
    operator VkExtensionProperties const &() const noexcept {
        return *reinterpret_cast<const VkExtensionProperties*>(this);
    }
    operator VkExtensionProperties &() noexcept {
        return *reinterpret_cast<VkExtensionProperties*>(this);
    }
};
struct LayerProperties {
    char layerName[MAX_EXTENSION_NAME_SIZE] = {};
    uint32_t specVersion = 0;
    uint32_t implementationVersion = 0;
    char description[MAX_DESCRIPTION_SIZE] = {};
    operator VkLayerProperties const &() const noexcept {
        return *reinterpret_cast<const VkLayerProperties*>(this);
    }
    operator VkLayerProperties &() noexcept {
        return *reinterpret_cast<VkLayerProperties*>(this);
    }
};
struct ApplicationInfo {
    StructureType sType = StructureType::eApplicationInfo;
    const void* pNext = nullptr;
    const char* pApplicationName = nullptr;
    uint32_t applicationVersion = 0;
    const char* pEngineName = nullptr;
    uint32_t engineVersion = 0;
    uint32_t apiVersion = 0;
    operator VkApplicationInfo const &() const noexcept {
        return *reinterpret_cast<const VkApplicationInfo*>(this);
    }
    operator VkApplicationInfo &() noexcept {
        return *reinterpret_cast<VkApplicationInfo*>(this);
    }
};
struct AllocationCallbacks {
    void* pUserData = nullptr;
    PFN_vkAllocationFunction pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
    operator VkAllocationCallbacks const &() const noexcept {
        return *reinterpret_cast<const VkAllocationCallbacks*>(this);
    }
    operator VkAllocationCallbacks &() noexcept {
        return *reinterpret_cast<VkAllocationCallbacks*>(this);
    }
};
struct DeviceQueueCreateInfo {
    StructureType sType = StructureType::eDeviceQueueCreateInfo;
    const void* pNext = nullptr;
    DeviceQueueCreateFlags flags = static_cast<DeviceQueueCreateFlags>(0);
    uint32_t queueFamilyIndex = 0;
    uint32_t queueCount = 0;
    const float* pQueuePriorities = nullptr;
    operator VkDeviceQueueCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceQueueCreateInfo*>(this);
    }
    operator VkDeviceQueueCreateInfo &() noexcept {
        return *reinterpret_cast<VkDeviceQueueCreateInfo*>(this);
    }
};
struct PhysicalDeviceFeatures {
    bool robustBufferAccess = false;
    bool fullDrawIndexUint32 = false;
    bool imageCubeArray = false;
    bool independentBlend = false;
    bool geometryShader = false;
    bool tessellationShader = false;
    bool sampleRateShading = false;
    bool dualSrcBlend = false;
    bool logicOp = false;
    bool multiDrawIndirect = false;
    bool drawIndirectFirstInstance = false;
    bool depthClamp = false;
    bool depthBiasClamp = false;
    bool fillModeNonSolid = false;
    bool depthBounds = false;
    bool wideLines = false;
    bool largePoints = false;
    bool alphaToOne = false;
    bool multiViewport = false;
    bool samplerAnisotropy = false;
    bool textureCompressionETC2 = false;
    bool textureCompressionASTC_LDR = false;
    bool textureCompressionBC = false;
    bool occlusionQueryPrecise = false;
    bool pipelineStatisticsQuery = false;
    bool vertexPipelineStoresAndAtomics = false;
    bool fragmentStoresAndAtomics = false;
    bool shaderTessellationAndGeometryPointSize = false;
    bool shaderImageGatherExtended = false;
    bool shaderStorageImageExtendedFormats = false;
    bool shaderStorageImageMultisample = false;
    bool shaderStorageImageReadWithoutFormat = false;
    bool shaderStorageImageWriteWithoutFormat = false;
    bool shaderUniformBufferArrayDynamicIndexing = false;
    bool shaderSampledImageArrayDynamicIndexing = false;
    bool shaderStorageBufferArrayDynamicIndexing = false;
    bool shaderStorageImageArrayDynamicIndexing = false;
    bool shaderClipDistance = false;
    bool shaderCullDistance = false;
    bool shaderFloat64 = false;
    bool shaderInt64 = false;
    bool shaderInt16 = false;
    bool shaderResourceResidency = false;
    bool shaderResourceMinLod = false;
    bool sparseBinding = false;
    bool sparseResidencyBuffer = false;
    bool sparseResidencyImage2D = false;
    bool sparseResidencyImage3D = false;
    bool sparseResidency2Samples = false;
    bool sparseResidency4Samples = false;
    bool sparseResidency8Samples = false;
    bool sparseResidency16Samples = false;
    bool sparseResidencyAliased = false;
    bool variableMultisampleRate = false;
    bool inheritedQueries = false;
    operator VkPhysicalDeviceFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFeatures*>(this);
    }
    operator VkPhysicalDeviceFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFeatures*>(this);
    }
};
struct DeviceCreateInfo {
    StructureType sType = StructureType::eDeviceCreateInfo;
    const void* pNext = nullptr;
    DeviceCreateFlags flags = static_cast<DeviceCreateFlags>(0);
    uint32_t queueCreateInfoCount = 0;
    const DeviceQueueCreateInfo* pQueueCreateInfos = nullptr;
    uint32_t enabledLayerCount = 0;
    const char* const* ppEnabledLayerNames = nullptr;
    uint32_t enabledExtensionCount = 0;
    const char* const* ppEnabledExtensionNames = nullptr;
    const PhysicalDeviceFeatures* pEnabledFeatures = nullptr;
    operator VkDeviceCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceCreateInfo*>(this);
    }
    operator VkDeviceCreateInfo &() noexcept {
        return *reinterpret_cast<VkDeviceCreateInfo*>(this);
    }
};
struct InstanceCreateInfo {
    StructureType sType = StructureType::eInstanceCreateInfo;
    const void* pNext = nullptr;
    InstanceCreateFlags flags = static_cast<InstanceCreateFlags>(0);
    const ApplicationInfo* pApplicationInfo = nullptr;
    uint32_t enabledLayerCount = 0;
    const char* const* ppEnabledLayerNames = nullptr;
    uint32_t enabledExtensionCount = 0;
    const char* const* ppEnabledExtensionNames = nullptr;
    operator VkInstanceCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkInstanceCreateInfo*>(this);
    }
    operator VkInstanceCreateInfo &() noexcept {
        return *reinterpret_cast<VkInstanceCreateInfo*>(this);
    }
};
struct QueueFamilyProperties {
    QueueFlags queueFlags = static_cast<QueueFlags>(0);
    uint32_t queueCount = 0;
    uint32_t timestampValidBits = 0;
    Extent3D minImageTransferGranularity;
    operator VkQueueFamilyProperties const &() const noexcept {
        return *reinterpret_cast<const VkQueueFamilyProperties*>(this);
    }
    operator VkQueueFamilyProperties &() noexcept {
        return *reinterpret_cast<VkQueueFamilyProperties*>(this);
    }
};
struct MemoryHeap {
    DeviceSize size = 0;
    MemoryHeapFlags flags = static_cast<MemoryHeapFlags>(0);
    operator VkMemoryHeap const &() const noexcept {
        return *reinterpret_cast<const VkMemoryHeap*>(this);
    }
    operator VkMemoryHeap &() noexcept {
        return *reinterpret_cast<VkMemoryHeap*>(this);
    }
};
struct MemoryType {
    MemoryPropertyFlags propertyFlags = static_cast<MemoryPropertyFlags>(0);
    uint32_t heapIndex = 0;
    operator VkMemoryType const &() const noexcept {
        return *reinterpret_cast<const VkMemoryType*>(this);
    }
    operator VkMemoryType &() noexcept {
        return *reinterpret_cast<VkMemoryType*>(this);
    }
};
struct PhysicalDeviceMemoryProperties {
    uint32_t memoryTypeCount = 0;
    MemoryType memoryTypes[MAX_MEMORY_TYPES];
    uint32_t memoryHeapCount = 0;
    MemoryHeap memoryHeaps[MAX_MEMORY_HEAPS];
    operator VkPhysicalDeviceMemoryProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMemoryProperties*>(this);
    }
    operator VkPhysicalDeviceMemoryProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMemoryProperties*>(this);
    }
};
struct MemoryAllocateInfo {
    StructureType sType = StructureType::eMemoryAllocateInfo;
    const void* pNext = nullptr;
    DeviceSize allocationSize = 0;
    uint32_t memoryTypeIndex = 0;
    operator VkMemoryAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkMemoryAllocateInfo*>(this);
    }
    operator VkMemoryAllocateInfo &() noexcept {
        return *reinterpret_cast<VkMemoryAllocateInfo*>(this);
    }
};
struct MemoryRequirements {
    DeviceSize size = 0;
    DeviceSize alignment = 0;
    uint32_t memoryTypeBits = 0;
    operator VkMemoryRequirements const &() const noexcept {
        return *reinterpret_cast<const VkMemoryRequirements*>(this);
    }
    operator VkMemoryRequirements &() noexcept {
        return *reinterpret_cast<VkMemoryRequirements*>(this);
    }
};
struct SparseImageFormatProperties {
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    Extent3D imageGranularity;
    SparseImageFormatFlags flags = static_cast<SparseImageFormatFlags>(0);
    operator VkSparseImageFormatProperties const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageFormatProperties*>(this);
    }
    operator VkSparseImageFormatProperties &() noexcept {
        return *reinterpret_cast<VkSparseImageFormatProperties*>(this);
    }
};
struct SparseImageMemoryRequirements {
    SparseImageFormatProperties formatProperties;
    uint32_t imageMipTailFirstLod = 0;
    DeviceSize imageMipTailSize = 0;
    DeviceSize imageMipTailOffset = 0;
    DeviceSize imageMipTailStride = 0;
    operator VkSparseImageMemoryRequirements const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageMemoryRequirements*>(this);
    }
    operator VkSparseImageMemoryRequirements &() noexcept {
        return *reinterpret_cast<VkSparseImageMemoryRequirements*>(this);
    }
};
struct MappedMemoryRange {
    StructureType sType = StructureType::eMappedMemoryRange;
    const void* pNext = nullptr;
    DeviceMemory memory;
    DeviceSize offset = 0;
    DeviceSize size = 0;
    operator VkMappedMemoryRange const &() const noexcept {
        return *reinterpret_cast<const VkMappedMemoryRange*>(this);
    }
    operator VkMappedMemoryRange &() noexcept {
        return *reinterpret_cast<VkMappedMemoryRange*>(this);
    }
};
struct FormatProperties {
    FormatFeatureFlags linearTilingFeatures = static_cast<FormatFeatureFlags>(0);
    FormatFeatureFlags optimalTilingFeatures = static_cast<FormatFeatureFlags>(0);
    FormatFeatureFlags bufferFeatures = static_cast<FormatFeatureFlags>(0);
    operator VkFormatProperties const &() const noexcept {
        return *reinterpret_cast<const VkFormatProperties*>(this);
    }
    operator VkFormatProperties &() noexcept {
        return *reinterpret_cast<VkFormatProperties*>(this);
    }
};
struct ImageFormatProperties {
    Extent3D maxExtent;
    uint32_t maxMipLevels = 0;
    uint32_t maxArrayLayers = 0;
    SampleCountFlags sampleCounts = static_cast<SampleCountFlags>(0);
    DeviceSize maxResourceSize = 0;
    operator VkImageFormatProperties const &() const noexcept {
        return *reinterpret_cast<const VkImageFormatProperties*>(this);
    }
    operator VkImageFormatProperties &() noexcept {
        return *reinterpret_cast<VkImageFormatProperties*>(this);
    }
};
struct DescriptorBufferInfo {
    Buffer buffer;
    DeviceSize offset = 0;
    DeviceSize range = 0;
    operator VkDescriptorBufferInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorBufferInfo*>(this);
    }
    operator VkDescriptorBufferInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorBufferInfo*>(this);
    }
};
struct DescriptorImageInfo {
    Sampler sampler;
    ImageView imageView;
    ImageLayout imageLayout = static_cast<ImageLayout>(0);
    operator VkDescriptorImageInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorImageInfo*>(this);
    }
    operator VkDescriptorImageInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorImageInfo*>(this);
    }
};
struct WriteDescriptorSet {
    StructureType sType = StructureType::eWriteDescriptorSet;
    const void* pNext = nullptr;
    DescriptorSet dstSet;
    uint32_t dstBinding = 0;
    uint32_t dstArrayElement = 0;
    uint32_t descriptorCount = 0;
    DescriptorType descriptorType = static_cast<DescriptorType>(0);
    const DescriptorImageInfo* pImageInfo = nullptr;
    const DescriptorBufferInfo* pBufferInfo = nullptr;
    const BufferView* pTexelBufferView = nullptr;
    operator VkWriteDescriptorSet const &() const noexcept {
        return *reinterpret_cast<const VkWriteDescriptorSet*>(this);
    }
    operator VkWriteDescriptorSet &() noexcept {
        return *reinterpret_cast<VkWriteDescriptorSet*>(this);
    }
};
struct CopyDescriptorSet {
    StructureType sType = StructureType::eCopyDescriptorSet;
    const void* pNext = nullptr;
    DescriptorSet srcSet;
    uint32_t srcBinding = 0;
    uint32_t srcArrayElement = 0;
    DescriptorSet dstSet;
    uint32_t dstBinding = 0;
    uint32_t dstArrayElement = 0;
    uint32_t descriptorCount = 0;
    operator VkCopyDescriptorSet const &() const noexcept {
        return *reinterpret_cast<const VkCopyDescriptorSet*>(this);
    }
    operator VkCopyDescriptorSet &() noexcept {
        return *reinterpret_cast<VkCopyDescriptorSet*>(this);
    }
};
struct BufferCreateInfo {
    StructureType sType = StructureType::eBufferCreateInfo;
    const void* pNext = nullptr;
    BufferCreateFlags flags = static_cast<BufferCreateFlags>(0);
    DeviceSize size = 0;
    BufferUsageFlags usage = static_cast<BufferUsageFlags>(0);
    SharingMode sharingMode = static_cast<SharingMode>(0);
    uint32_t queueFamilyIndexCount = 0;
    const uint32_t* pQueueFamilyIndices = nullptr;
    operator VkBufferCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkBufferCreateInfo*>(this);
    }
    operator VkBufferCreateInfo &() noexcept {
        return *reinterpret_cast<VkBufferCreateInfo*>(this);
    }
};
struct BufferViewCreateInfo {
    StructureType sType = StructureType::eBufferViewCreateInfo;
    const void* pNext = nullptr;
    BufferViewCreateFlags flags = static_cast<BufferViewCreateFlags>(0);
    Buffer buffer;
    Format format = static_cast<Format>(0);
    DeviceSize offset = 0;
    DeviceSize range = 0;
    operator VkBufferViewCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkBufferViewCreateInfo*>(this);
    }
    operator VkBufferViewCreateInfo &() noexcept {
        return *reinterpret_cast<VkBufferViewCreateInfo*>(this);
    }
};
struct ImageSubresource {
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    uint32_t mipLevel = 0;
    uint32_t arrayLayer = 0;
    operator VkImageSubresource const &() const noexcept {
        return *reinterpret_cast<const VkImageSubresource*>(this);
    }
    operator VkImageSubresource &() noexcept {
        return *reinterpret_cast<VkImageSubresource*>(this);
    }
};
struct ImageSubresourceLayers {
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    uint32_t mipLevel = 0;
    uint32_t baseArrayLayer = 0;
    uint32_t layerCount = 0;
    operator VkImageSubresourceLayers const &() const noexcept {
        return *reinterpret_cast<const VkImageSubresourceLayers*>(this);
    }
    operator VkImageSubresourceLayers &() noexcept {
        return *reinterpret_cast<VkImageSubresourceLayers*>(this);
    }
};
struct ImageSubresourceRange {
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    uint32_t baseMipLevel = 0;
    uint32_t levelCount = 0;
    uint32_t baseArrayLayer = 0;
    uint32_t layerCount = 0;
    operator VkImageSubresourceRange const &() const noexcept {
        return *reinterpret_cast<const VkImageSubresourceRange*>(this);
    }
    operator VkImageSubresourceRange &() noexcept {
        return *reinterpret_cast<VkImageSubresourceRange*>(this);
    }
};
struct MemoryBarrier {
    StructureType sType = StructureType::eMemoryBarrier;
    const void* pNext = nullptr;
    AccessFlags srcAccessMask = static_cast<AccessFlags>(0);
    AccessFlags dstAccessMask = static_cast<AccessFlags>(0);
    operator VkMemoryBarrier const &() const noexcept {
        return *reinterpret_cast<const VkMemoryBarrier*>(this);
    }
    operator VkMemoryBarrier &() noexcept {
        return *reinterpret_cast<VkMemoryBarrier*>(this);
    }
};
struct BufferMemoryBarrier {
    StructureType sType = StructureType::eBufferMemoryBarrier;
    const void* pNext = nullptr;
    AccessFlags srcAccessMask = static_cast<AccessFlags>(0);
    AccessFlags dstAccessMask = static_cast<AccessFlags>(0);
    uint32_t srcQueueFamilyIndex = 0;
    uint32_t dstQueueFamilyIndex = 0;
    Buffer buffer;
    DeviceSize offset = 0;
    DeviceSize size = 0;
    operator VkBufferMemoryBarrier const &() const noexcept {
        return *reinterpret_cast<const VkBufferMemoryBarrier*>(this);
    }
    operator VkBufferMemoryBarrier &() noexcept {
        return *reinterpret_cast<VkBufferMemoryBarrier*>(this);
    }
};
struct ImageMemoryBarrier {
    StructureType sType = StructureType::eImageMemoryBarrier;
    const void* pNext = nullptr;
    AccessFlags srcAccessMask = static_cast<AccessFlags>(0);
    AccessFlags dstAccessMask = static_cast<AccessFlags>(0);
    ImageLayout oldLayout = static_cast<ImageLayout>(0);
    ImageLayout newLayout = static_cast<ImageLayout>(0);
    uint32_t srcQueueFamilyIndex = 0;
    uint32_t dstQueueFamilyIndex = 0;
    Image image;
    ImageSubresourceRange subresourceRange;
    operator VkImageMemoryBarrier const &() const noexcept {
        return *reinterpret_cast<const VkImageMemoryBarrier*>(this);
    }
    operator VkImageMemoryBarrier &() noexcept {
        return *reinterpret_cast<VkImageMemoryBarrier*>(this);
    }
};
struct ImageCreateInfo {
    StructureType sType = StructureType::eImageCreateInfo;
    const void* pNext = nullptr;
    ImageCreateFlags flags = static_cast<ImageCreateFlags>(0);
    ImageType imageType = static_cast<ImageType>(0);
    Format format = static_cast<Format>(0);
    Extent3D extent;
    uint32_t mipLevels = 0;
    uint32_t arrayLayers = 0;
    SampleCountFlagBits samples = static_cast<SampleCountFlagBits>(0);
    ImageTiling tiling = static_cast<ImageTiling>(0);
    ImageUsageFlags usage = static_cast<ImageUsageFlags>(0);
    SharingMode sharingMode = static_cast<SharingMode>(0);
    uint32_t queueFamilyIndexCount = 0;
    const uint32_t* pQueueFamilyIndices = nullptr;
    ImageLayout initialLayout = static_cast<ImageLayout>(0);
    operator VkImageCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkImageCreateInfo*>(this);
    }
    operator VkImageCreateInfo &() noexcept {
        return *reinterpret_cast<VkImageCreateInfo*>(this);
    }
};
struct SubresourceLayout {
    DeviceSize offset = 0;
    DeviceSize size = 0;
    DeviceSize rowPitch = 0;
    DeviceSize arrayPitch = 0;
    DeviceSize depthPitch = 0;
    operator VkSubresourceLayout const &() const noexcept {
        return *reinterpret_cast<const VkSubresourceLayout*>(this);
    }
    operator VkSubresourceLayout &() noexcept {
        return *reinterpret_cast<VkSubresourceLayout*>(this);
    }
};
struct ImageViewCreateInfo {
    StructureType sType = StructureType::eImageViewCreateInfo;
    const void* pNext = nullptr;
    ImageViewCreateFlags flags = static_cast<ImageViewCreateFlags>(0);
    Image image;
    ImageViewType viewType = static_cast<ImageViewType>(0);
    Format format = static_cast<Format>(0);
    ComponentMapping components;
    ImageSubresourceRange subresourceRange;
    operator VkImageViewCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkImageViewCreateInfo*>(this);
    }
    operator VkImageViewCreateInfo &() noexcept {
        return *reinterpret_cast<VkImageViewCreateInfo*>(this);
    }
};
struct BufferCopy {
    DeviceSize srcOffset = 0;
    DeviceSize dstOffset = 0;
    DeviceSize size = 0;
    operator VkBufferCopy const &() const noexcept {
        return *reinterpret_cast<const VkBufferCopy*>(this);
    }
    operator VkBufferCopy &() noexcept {
        return *reinterpret_cast<VkBufferCopy*>(this);
    }
};
struct SparseMemoryBind {
    DeviceSize resourceOffset = 0;
    DeviceSize size = 0;
    DeviceMemory memory;
    DeviceSize memoryOffset = 0;
    SparseMemoryBindFlags flags = static_cast<SparseMemoryBindFlags>(0);
    operator VkSparseMemoryBind const &() const noexcept {
        return *reinterpret_cast<const VkSparseMemoryBind*>(this);
    }
    operator VkSparseMemoryBind &() noexcept {
        return *reinterpret_cast<VkSparseMemoryBind*>(this);
    }
};
struct SparseImageMemoryBind {
    ImageSubresource subresource;
    Offset3D offset;
    Extent3D extent;
    DeviceMemory memory;
    DeviceSize memoryOffset = 0;
    SparseMemoryBindFlags flags = static_cast<SparseMemoryBindFlags>(0);
    operator VkSparseImageMemoryBind const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageMemoryBind*>(this);
    }
    operator VkSparseImageMemoryBind &() noexcept {
        return *reinterpret_cast<VkSparseImageMemoryBind*>(this);
    }
};
struct SparseBufferMemoryBindInfo {
    Buffer buffer;
    uint32_t bindCount = 0;
    const SparseMemoryBind* pBinds = nullptr;
    operator VkSparseBufferMemoryBindInfo const &() const noexcept {
        return *reinterpret_cast<const VkSparseBufferMemoryBindInfo*>(this);
    }
    operator VkSparseBufferMemoryBindInfo &() noexcept {
        return *reinterpret_cast<VkSparseBufferMemoryBindInfo*>(this);
    }
};
struct SparseImageOpaqueMemoryBindInfo {
    Image image;
    uint32_t bindCount = 0;
    const SparseMemoryBind* pBinds = nullptr;
    operator VkSparseImageOpaqueMemoryBindInfo const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageOpaqueMemoryBindInfo*>(this);
    }
    operator VkSparseImageOpaqueMemoryBindInfo &() noexcept {
        return *reinterpret_cast<VkSparseImageOpaqueMemoryBindInfo*>(this);
    }
};
struct SparseImageMemoryBindInfo {
    Image image;
    uint32_t bindCount = 0;
    const SparseImageMemoryBind* pBinds = nullptr;
    operator VkSparseImageMemoryBindInfo const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageMemoryBindInfo*>(this);
    }
    operator VkSparseImageMemoryBindInfo &() noexcept {
        return *reinterpret_cast<VkSparseImageMemoryBindInfo*>(this);
    }
};
struct BindSparseInfo {
    StructureType sType = StructureType::eBindSparseInfo;
    const void* pNext = nullptr;
    uint32_t waitSemaphoreCount = 0;
    const Semaphore* pWaitSemaphores = nullptr;
    uint32_t bufferBindCount = 0;
    const SparseBufferMemoryBindInfo* pBufferBinds = nullptr;
    uint32_t imageOpaqueBindCount = 0;
    const SparseImageOpaqueMemoryBindInfo* pImageOpaqueBinds = nullptr;
    uint32_t imageBindCount = 0;
    const SparseImageMemoryBindInfo* pImageBinds = nullptr;
    uint32_t signalSemaphoreCount = 0;
    const Semaphore* pSignalSemaphores = nullptr;
    operator VkBindSparseInfo const &() const noexcept {
        return *reinterpret_cast<const VkBindSparseInfo*>(this);
    }
    operator VkBindSparseInfo &() noexcept {
        return *reinterpret_cast<VkBindSparseInfo*>(this);
    }
};
struct ImageCopy {
    ImageSubresourceLayers srcSubresource;
    Offset3D srcOffset;
    ImageSubresourceLayers dstSubresource;
    Offset3D dstOffset;
    Extent3D extent;
    operator VkImageCopy const &() const noexcept {
        return *reinterpret_cast<const VkImageCopy*>(this);
    }
    operator VkImageCopy &() noexcept {
        return *reinterpret_cast<VkImageCopy*>(this);
    }
};
struct ImageBlit {
    ImageSubresourceLayers srcSubresource;
    Offset3D srcOffsets[2];
    ImageSubresourceLayers dstSubresource;
    Offset3D dstOffsets[2];
    operator VkImageBlit const &() const noexcept {
        return *reinterpret_cast<const VkImageBlit*>(this);
    }
    operator VkImageBlit &() noexcept {
        return *reinterpret_cast<VkImageBlit*>(this);
    }
};
struct BufferImageCopy {
    DeviceSize bufferOffset = 0;
    uint32_t bufferRowLength = 0;
    uint32_t bufferImageHeight = 0;
    ImageSubresourceLayers imageSubresource;
    Offset3D imageOffset;
    Extent3D imageExtent;
    operator VkBufferImageCopy const &() const noexcept {
        return *reinterpret_cast<const VkBufferImageCopy*>(this);
    }
    operator VkBufferImageCopy &() noexcept {
        return *reinterpret_cast<VkBufferImageCopy*>(this);
    }
};
struct ImageResolve {
    ImageSubresourceLayers srcSubresource;
    Offset3D srcOffset;
    ImageSubresourceLayers dstSubresource;
    Offset3D dstOffset;
    Extent3D extent;
    operator VkImageResolve const &() const noexcept {
        return *reinterpret_cast<const VkImageResolve*>(this);
    }
    operator VkImageResolve &() noexcept {
        return *reinterpret_cast<VkImageResolve*>(this);
    }
};
struct ShaderModuleCreateInfo {
    StructureType sType = StructureType::eShaderModuleCreateInfo;
    const void* pNext = nullptr;
    ShaderModuleCreateFlags flags = static_cast<ShaderModuleCreateFlags>(0);
    size_t codeSize = 0;
    const uint32_t* pCode = nullptr;
    operator VkShaderModuleCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkShaderModuleCreateInfo*>(this);
    }
    operator VkShaderModuleCreateInfo &() noexcept {
        return *reinterpret_cast<VkShaderModuleCreateInfo*>(this);
    }
};
struct DescriptorSetLayoutBinding {
    uint32_t binding = 0;
    DescriptorType descriptorType = static_cast<DescriptorType>(0);
    uint32_t descriptorCount = 0;
    ShaderStageFlags stageFlags = static_cast<ShaderStageFlags>(0);
    const Sampler* pImmutableSamplers = nullptr;
    operator VkDescriptorSetLayoutBinding const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetLayoutBinding*>(this);
    }
    operator VkDescriptorSetLayoutBinding &() noexcept {
        return *reinterpret_cast<VkDescriptorSetLayoutBinding*>(this);
    }
};
struct DescriptorSetLayoutCreateInfo {
    StructureType sType = StructureType::eDescriptorSetLayoutCreateInfo;
    const void* pNext = nullptr;
    DescriptorSetLayoutCreateFlags flags = static_cast<DescriptorSetLayoutCreateFlags>(0);
    uint32_t bindingCount = 0;
    const DescriptorSetLayoutBinding* pBindings = nullptr;
    operator VkDescriptorSetLayoutCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(this);
    }
    operator VkDescriptorSetLayoutCreateInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorSetLayoutCreateInfo*>(this);
    }
};
struct DescriptorPoolSize {
    DescriptorType type = static_cast<DescriptorType>(0);
    uint32_t descriptorCount = 0;
    operator VkDescriptorPoolSize const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorPoolSize*>(this);
    }
    operator VkDescriptorPoolSize &() noexcept {
        return *reinterpret_cast<VkDescriptorPoolSize*>(this);
    }
};
struct DescriptorPoolCreateInfo {
    StructureType sType = StructureType::eDescriptorPoolCreateInfo;
    const void* pNext = nullptr;
    DescriptorPoolCreateFlags flags = static_cast<DescriptorPoolCreateFlags>(0);
    uint32_t maxSets = 0;
    uint32_t poolSizeCount = 0;
    const DescriptorPoolSize* pPoolSizes = nullptr;
    operator VkDescriptorPoolCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorPoolCreateInfo*>(this);
    }
    operator VkDescriptorPoolCreateInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorPoolCreateInfo*>(this);
    }
};
struct DescriptorSetAllocateInfo {
    StructureType sType = StructureType::eDescriptorSetAllocateInfo;
    const void* pNext = nullptr;
    DescriptorPool descriptorPool;
    uint32_t descriptorSetCount = 0;
    const DescriptorSetLayout* pSetLayouts = nullptr;
    operator VkDescriptorSetAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetAllocateInfo*>(this);
    }
    operator VkDescriptorSetAllocateInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorSetAllocateInfo*>(this);
    }
};
struct SpecializationMapEntry {
    uint32_t constantID = 0;
    uint32_t offset = 0;
    size_t size = 0;
    operator VkSpecializationMapEntry const &() const noexcept {
        return *reinterpret_cast<const VkSpecializationMapEntry*>(this);
    }
    operator VkSpecializationMapEntry &() noexcept {
        return *reinterpret_cast<VkSpecializationMapEntry*>(this);
    }
};
struct SpecializationInfo {
    uint32_t mapEntryCount = 0;
    const SpecializationMapEntry* pMapEntries = nullptr;
    size_t dataSize = 0;
    const void* pData = nullptr;
    operator VkSpecializationInfo const &() const noexcept {
        return *reinterpret_cast<const VkSpecializationInfo*>(this);
    }
    operator VkSpecializationInfo &() noexcept {
        return *reinterpret_cast<VkSpecializationInfo*>(this);
    }
};
struct PipelineShaderStageCreateInfo {
    StructureType sType = StructureType::ePipelineShaderStageCreateInfo;
    const void* pNext = nullptr;
    PipelineShaderStageCreateFlags flags = static_cast<PipelineShaderStageCreateFlags>(0);
    ShaderStageFlagBits stage = static_cast<ShaderStageFlagBits>(0);
    ShaderModule module;
    const char* pName = nullptr;
    const SpecializationInfo* pSpecializationInfo = nullptr;
    operator VkPipelineShaderStageCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(this);
    }
    operator VkPipelineShaderStageCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineShaderStageCreateInfo*>(this);
    }
};
struct ComputePipelineCreateInfo {
    StructureType sType = StructureType::eComputePipelineCreateInfo;
    const void* pNext = nullptr;
    PipelineCreateFlags flags = static_cast<PipelineCreateFlags>(0);
    PipelineShaderStageCreateInfo stage;
    PipelineLayout layout;
    Pipeline basePipelineHandle;
    int32_t basePipelineIndex = 0;
    operator VkComputePipelineCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkComputePipelineCreateInfo*>(this);
    }
    operator VkComputePipelineCreateInfo &() noexcept {
        return *reinterpret_cast<VkComputePipelineCreateInfo*>(this);
    }
};
struct VertexInputBindingDescription {
    uint32_t binding = 0;
    uint32_t stride = 0;
    VertexInputRate inputRate = static_cast<VertexInputRate>(0);
    operator VkVertexInputBindingDescription const &() const noexcept {
        return *reinterpret_cast<const VkVertexInputBindingDescription*>(this);
    }
    operator VkVertexInputBindingDescription &() noexcept {
        return *reinterpret_cast<VkVertexInputBindingDescription*>(this);
    }
};
struct VertexInputAttributeDescription {
    uint32_t location = 0;
    uint32_t binding = 0;
    Format format = static_cast<Format>(0);
    uint32_t offset = 0;
    operator VkVertexInputAttributeDescription const &() const noexcept {
        return *reinterpret_cast<const VkVertexInputAttributeDescription*>(this);
    }
    operator VkVertexInputAttributeDescription &() noexcept {
        return *reinterpret_cast<VkVertexInputAttributeDescription*>(this);
    }
};
struct PipelineVertexInputStateCreateInfo {
    StructureType sType = StructureType::ePipelineVertexInputStateCreateInfo;
    const void* pNext = nullptr;
    PipelineVertexInputStateCreateFlags flags = static_cast<PipelineVertexInputStateCreateFlags>(0);
    uint32_t vertexBindingDescriptionCount = 0;
    const VertexInputBindingDescription* pVertexBindingDescriptions = nullptr;
    uint32_t vertexAttributeDescriptionCount = 0;
    const VertexInputAttributeDescription* pVertexAttributeDescriptions = nullptr;
    operator VkPipelineVertexInputStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineVertexInputStateCreateInfo*>(this);
    }
    operator VkPipelineVertexInputStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineVertexInputStateCreateInfo*>(this);
    }
};
struct PipelineInputAssemblyStateCreateInfo {
    StructureType sType = StructureType::ePipelineInputAssemblyStateCreateInfo;
    const void* pNext = nullptr;
    PipelineInputAssemblyStateCreateFlags flags = static_cast<PipelineInputAssemblyStateCreateFlags>(0);
    PrimitiveTopology topology = static_cast<PrimitiveTopology>(0);
    bool primitiveRestartEnable = false;
    operator VkPipelineInputAssemblyStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineInputAssemblyStateCreateInfo*>(this);
    }
    operator VkPipelineInputAssemblyStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineInputAssemblyStateCreateInfo*>(this);
    }
};
struct PipelineTessellationStateCreateInfo {
    StructureType sType = StructureType::ePipelineTessellationStateCreateInfo;
    const void* pNext = nullptr;
    PipelineTessellationStateCreateFlags flags = static_cast<PipelineTessellationStateCreateFlags>(0);
    uint32_t patchControlPoints = 0;
    operator VkPipelineTessellationStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineTessellationStateCreateInfo*>(this);
    }
    operator VkPipelineTessellationStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineTessellationStateCreateInfo*>(this);
    }
};
struct PipelineViewportStateCreateInfo {
    StructureType sType = StructureType::ePipelineViewportStateCreateInfo;
    const void* pNext = nullptr;
    PipelineViewportStateCreateFlags flags = static_cast<PipelineViewportStateCreateFlags>(0);
    uint32_t viewportCount = 0;
    const Viewport* pViewports = nullptr;
    uint32_t scissorCount = 0;
    const Rect2D* pScissors = nullptr;
    operator VkPipelineViewportStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineViewportStateCreateInfo*>(this);
    }
    operator VkPipelineViewportStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineViewportStateCreateInfo*>(this);
    }
};
struct PipelineRasterizationStateCreateInfo {
    StructureType sType = StructureType::ePipelineRasterizationStateCreateInfo;
    const void* pNext = nullptr;
    PipelineRasterizationStateCreateFlags flags = static_cast<PipelineRasterizationStateCreateFlags>(0);
    bool depthClampEnable = false;
    bool rasterizerDiscardEnable = false;
    PolygonMode polygonMode = static_cast<PolygonMode>(0);
    CullModeFlags cullMode = static_cast<CullModeFlags>(0);
    FrontFace frontFace = static_cast<FrontFace>(0);
    bool depthBiasEnable = false;
    float depthBiasConstantFactor = 0.f;
    float depthBiasClamp = 0.f;
    float depthBiasSlopeFactor = 0.f;
    float lineWidth = 0.f;
    operator VkPipelineRasterizationStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRasterizationStateCreateInfo*>(this);
    }
    operator VkPipelineRasterizationStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineRasterizationStateCreateInfo*>(this);
    }
};
struct PipelineMultisampleStateCreateInfo {
    StructureType sType = StructureType::ePipelineMultisampleStateCreateInfo;
    const void* pNext = nullptr;
    PipelineMultisampleStateCreateFlags flags = static_cast<PipelineMultisampleStateCreateFlags>(0);
    SampleCountFlagBits rasterizationSamples = static_cast<SampleCountFlagBits>(0);
    bool sampleShadingEnable = false;
    float minSampleShading = 0.f;
    const SampleMask* pSampleMask = nullptr;
    bool alphaToCoverageEnable = false;
    bool alphaToOneEnable = false;
    operator VkPipelineMultisampleStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineMultisampleStateCreateInfo*>(this);
    }
    operator VkPipelineMultisampleStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineMultisampleStateCreateInfo*>(this);
    }
};
struct PipelineColorBlendAttachmentState {
    bool blendEnable = false;
    BlendFactor srcColorBlendFactor = static_cast<BlendFactor>(0);
    BlendFactor dstColorBlendFactor = static_cast<BlendFactor>(0);
    BlendOp colorBlendOp = static_cast<BlendOp>(0);
    BlendFactor srcAlphaBlendFactor = static_cast<BlendFactor>(0);
    BlendFactor dstAlphaBlendFactor = static_cast<BlendFactor>(0);
    BlendOp alphaBlendOp = static_cast<BlendOp>(0);
    ColorComponentFlags colorWriteMask = static_cast<ColorComponentFlags>(0);
    operator VkPipelineColorBlendAttachmentState const &() const noexcept {
        return *reinterpret_cast<const VkPipelineColorBlendAttachmentState*>(this);
    }
    operator VkPipelineColorBlendAttachmentState &() noexcept {
        return *reinterpret_cast<VkPipelineColorBlendAttachmentState*>(this);
    }
};
struct PipelineColorBlendStateCreateInfo {
    StructureType sType = StructureType::ePipelineColorBlendStateCreateInfo;
    const void* pNext = nullptr;
    PipelineColorBlendStateCreateFlags flags = static_cast<PipelineColorBlendStateCreateFlags>(0);
    bool logicOpEnable = false;
    LogicOp logicOp = static_cast<LogicOp>(0);
    uint32_t attachmentCount = 0;
    const PipelineColorBlendAttachmentState* pAttachments = nullptr;
    float blendConstants[4] = {};
    operator VkPipelineColorBlendStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineColorBlendStateCreateInfo*>(this);
    }
    operator VkPipelineColorBlendStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineColorBlendStateCreateInfo*>(this);
    }
};
struct PipelineDynamicStateCreateInfo {
    StructureType sType = StructureType::ePipelineDynamicStateCreateInfo;
    const void* pNext = nullptr;
    PipelineDynamicStateCreateFlags flags = static_cast<PipelineDynamicStateCreateFlags>(0);
    uint32_t dynamicStateCount = 0;
    const DynamicState* pDynamicStates = nullptr;
    operator VkPipelineDynamicStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineDynamicStateCreateInfo*>(this);
    }
    operator VkPipelineDynamicStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineDynamicStateCreateInfo*>(this);
    }
};
struct StencilOpState {
    StencilOp failOp = static_cast<StencilOp>(0);
    StencilOp passOp = static_cast<StencilOp>(0);
    StencilOp depthFailOp = static_cast<StencilOp>(0);
    CompareOp compareOp = static_cast<CompareOp>(0);
    uint32_t compareMask = 0;
    uint32_t writeMask = 0;
    uint32_t reference = 0;
    operator VkStencilOpState const &() const noexcept {
        return *reinterpret_cast<const VkStencilOpState*>(this);
    }
    operator VkStencilOpState &() noexcept {
        return *reinterpret_cast<VkStencilOpState*>(this);
    }
};
struct PipelineDepthStencilStateCreateInfo {
    StructureType sType = StructureType::ePipelineDepthStencilStateCreateInfo;
    const void* pNext = nullptr;
    PipelineDepthStencilStateCreateFlags flags = static_cast<PipelineDepthStencilStateCreateFlags>(0);
    bool depthTestEnable = false;
    bool depthWriteEnable = false;
    CompareOp depthCompareOp = static_cast<CompareOp>(0);
    bool depthBoundsTestEnable = false;
    bool stencilTestEnable = false;
    StencilOpState front;
    StencilOpState back;
    float minDepthBounds = 0.f;
    float maxDepthBounds = 0.f;
    operator VkPipelineDepthStencilStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineDepthStencilStateCreateInfo*>(this);
    }
    operator VkPipelineDepthStencilStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineDepthStencilStateCreateInfo*>(this);
    }
};
struct GraphicsPipelineCreateInfo {
    StructureType sType = StructureType::eGraphicsPipelineCreateInfo;
    const void* pNext = nullptr;
    PipelineCreateFlags flags = static_cast<PipelineCreateFlags>(0);
    uint32_t stageCount = 0;
    const PipelineShaderStageCreateInfo* pStages = nullptr;
    const PipelineVertexInputStateCreateInfo* pVertexInputState = nullptr;
    const PipelineInputAssemblyStateCreateInfo* pInputAssemblyState = nullptr;
    const PipelineTessellationStateCreateInfo* pTessellationState = nullptr;
    const PipelineViewportStateCreateInfo* pViewportState = nullptr;
    const PipelineRasterizationStateCreateInfo* pRasterizationState = nullptr;
    const PipelineMultisampleStateCreateInfo* pMultisampleState = nullptr;
    const PipelineDepthStencilStateCreateInfo* pDepthStencilState = nullptr;
    const PipelineColorBlendStateCreateInfo* pColorBlendState = nullptr;
    const PipelineDynamicStateCreateInfo* pDynamicState = nullptr;
    PipelineLayout layout;
    RenderPass renderPass;
    uint32_t subpass = 0;
    Pipeline basePipelineHandle;
    int32_t basePipelineIndex = 0;
    operator VkGraphicsPipelineCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(this);
    }
    operator VkGraphicsPipelineCreateInfo &() noexcept {
        return *reinterpret_cast<VkGraphicsPipelineCreateInfo*>(this);
    }
};
struct PipelineCacheCreateInfo {
    StructureType sType = StructureType::ePipelineCacheCreateInfo;
    const void* pNext = nullptr;
    PipelineCacheCreateFlags flags = static_cast<PipelineCacheCreateFlags>(0);
    size_t initialDataSize = 0;
    const void* pInitialData = nullptr;
    operator VkPipelineCacheCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCacheCreateInfo*>(this);
    }
    operator VkPipelineCacheCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineCacheCreateInfo*>(this);
    }
};
struct PushConstantRange {
    ShaderStageFlags stageFlags = static_cast<ShaderStageFlags>(0);
    uint32_t offset = 0;
    uint32_t size = 0;
    operator VkPushConstantRange const &() const noexcept {
        return *reinterpret_cast<const VkPushConstantRange*>(this);
    }
    operator VkPushConstantRange &() noexcept {
        return *reinterpret_cast<VkPushConstantRange*>(this);
    }
};
struct PipelineLayoutCreateInfo {
    StructureType sType = StructureType::ePipelineLayoutCreateInfo;
    const void* pNext = nullptr;
    PipelineLayoutCreateFlags flags = static_cast<PipelineLayoutCreateFlags>(0);
    uint32_t setLayoutCount = 0;
    const DescriptorSetLayout* pSetLayouts = nullptr;
    uint32_t pushConstantRangeCount = 0;
    const PushConstantRange* pPushConstantRanges = nullptr;
    operator VkPipelineLayoutCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineLayoutCreateInfo*>(this);
    }
    operator VkPipelineLayoutCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineLayoutCreateInfo*>(this);
    }
};
struct SamplerCreateInfo {
    StructureType sType = StructureType::eSamplerCreateInfo;
    const void* pNext = nullptr;
    SamplerCreateFlags flags = static_cast<SamplerCreateFlags>(0);
    Filter magFilter = static_cast<Filter>(0);
    Filter minFilter = static_cast<Filter>(0);
    SamplerMipmapMode mipmapMode = static_cast<SamplerMipmapMode>(0);
    SamplerAddressMode addressModeU = static_cast<SamplerAddressMode>(0);
    SamplerAddressMode addressModeV = static_cast<SamplerAddressMode>(0);
    SamplerAddressMode addressModeW = static_cast<SamplerAddressMode>(0);
    float mipLodBias = 0.f;
    bool anisotropyEnable = false;
    float maxAnisotropy = 0.f;
    bool compareEnable = false;
    CompareOp compareOp = static_cast<CompareOp>(0);
    float minLod = 0.f;
    float maxLod = 0.f;
    BorderColor borderColor = static_cast<BorderColor>(0);
    bool unnormalizedCoordinates = false;
    operator VkSamplerCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkSamplerCreateInfo*>(this);
    }
    operator VkSamplerCreateInfo &() noexcept {
        return *reinterpret_cast<VkSamplerCreateInfo*>(this);
    }
};
struct CommandPoolCreateInfo {
    StructureType sType = StructureType::eCommandPoolCreateInfo;
    const void* pNext = nullptr;
    CommandPoolCreateFlags flags = static_cast<CommandPoolCreateFlags>(0);
    uint32_t queueFamilyIndex = 0;
    operator VkCommandPoolCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkCommandPoolCreateInfo*>(this);
    }
    operator VkCommandPoolCreateInfo &() noexcept {
        return *reinterpret_cast<VkCommandPoolCreateInfo*>(this);
    }
};
struct CommandBufferAllocateInfo {
    StructureType sType = StructureType::eCommandBufferAllocateInfo;
    const void* pNext = nullptr;
    CommandPool commandPool;
    CommandBufferLevel level = static_cast<CommandBufferLevel>(0);
    uint32_t commandBufferCount = 0;
    operator VkCommandBufferAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkCommandBufferAllocateInfo*>(this);
    }
    operator VkCommandBufferAllocateInfo &() noexcept {
        return *reinterpret_cast<VkCommandBufferAllocateInfo*>(this);
    }
};
struct CommandBufferInheritanceInfo {
    StructureType sType = StructureType::eCommandBufferInheritanceInfo;
    const void* pNext = nullptr;
    RenderPass renderPass;
    uint32_t subpass = 0;
    Framebuffer framebuffer;
    bool occlusionQueryEnable = false;
    QueryControlFlags queryFlags = static_cast<QueryControlFlags>(0);
    QueryPipelineStatisticFlags pipelineStatistics = static_cast<QueryPipelineStatisticFlags>(0);
    operator VkCommandBufferInheritanceInfo const &() const noexcept {
        return *reinterpret_cast<const VkCommandBufferInheritanceInfo*>(this);
    }
    operator VkCommandBufferInheritanceInfo &() noexcept {
        return *reinterpret_cast<VkCommandBufferInheritanceInfo*>(this);
    }
};
struct CommandBufferBeginInfo {
    StructureType sType = StructureType::eCommandBufferBeginInfo;
    const void* pNext = nullptr;
    CommandBufferUsageFlags flags = static_cast<CommandBufferUsageFlags>(0);
    const CommandBufferInheritanceInfo* pInheritanceInfo = nullptr;
    operator VkCommandBufferBeginInfo const &() const noexcept {
        return *reinterpret_cast<const VkCommandBufferBeginInfo*>(this);
    }
    operator VkCommandBufferBeginInfo &() noexcept {
        return *reinterpret_cast<VkCommandBufferBeginInfo*>(this);
    }
};
struct ClearDepthStencilValue {
    float depth = 0.f;
    uint32_t stencil = 0;
    operator VkClearDepthStencilValue const &() const noexcept {
        return *reinterpret_cast<const VkClearDepthStencilValue*>(this);
    }
    operator VkClearDepthStencilValue &() noexcept {
        return *reinterpret_cast<VkClearDepthStencilValue*>(this);
    }
};
union ClearColorValue {
    float float32[4];
    int32_t int32[4];
    uint32_t uint32[4];
};
union ClearValue {
    ClearColorValue color;
    ClearDepthStencilValue depthStencil;
};
struct RenderPassBeginInfo {
    StructureType sType = StructureType::eRenderPassBeginInfo;
    const void* pNext = nullptr;
    RenderPass renderPass;
    Framebuffer framebuffer;
    Rect2D renderArea;
    uint32_t clearValueCount = 0;
    const ClearValue* pClearValues = nullptr;
    operator VkRenderPassBeginInfo const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassBeginInfo*>(this);
    }
    operator VkRenderPassBeginInfo &() noexcept {
        return *reinterpret_cast<VkRenderPassBeginInfo*>(this);
    }
};
struct ClearAttachment {
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    uint32_t colorAttachment = 0;
    ClearValue clearValue;
    operator VkClearAttachment const &() const noexcept {
        return *reinterpret_cast<const VkClearAttachment*>(this);
    }
    operator VkClearAttachment &() noexcept {
        return *reinterpret_cast<VkClearAttachment*>(this);
    }
};
struct AttachmentDescription {
    AttachmentDescriptionFlags flags = static_cast<AttachmentDescriptionFlags>(0);
    Format format = static_cast<Format>(0);
    SampleCountFlagBits samples = static_cast<SampleCountFlagBits>(0);
    AttachmentLoadOp loadOp = static_cast<AttachmentLoadOp>(0);
    AttachmentStoreOp storeOp = static_cast<AttachmentStoreOp>(0);
    AttachmentLoadOp stencilLoadOp = static_cast<AttachmentLoadOp>(0);
    AttachmentStoreOp stencilStoreOp = static_cast<AttachmentStoreOp>(0);
    ImageLayout initialLayout = static_cast<ImageLayout>(0);
    ImageLayout finalLayout = static_cast<ImageLayout>(0);
    operator VkAttachmentDescription const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentDescription*>(this);
    }
    operator VkAttachmentDescription &() noexcept {
        return *reinterpret_cast<VkAttachmentDescription*>(this);
    }
};
struct AttachmentReference {
    uint32_t attachment = 0;
    ImageLayout layout = static_cast<ImageLayout>(0);
    operator VkAttachmentReference const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentReference*>(this);
    }
    operator VkAttachmentReference &() noexcept {
        return *reinterpret_cast<VkAttachmentReference*>(this);
    }
};
struct SubpassDescription {
    SubpassDescriptionFlags flags = static_cast<SubpassDescriptionFlags>(0);
    PipelineBindPoint pipelineBindPoint = static_cast<PipelineBindPoint>(0);
    uint32_t inputAttachmentCount = 0;
    const AttachmentReference* pInputAttachments = nullptr;
    uint32_t colorAttachmentCount = 0;
    const AttachmentReference* pColorAttachments = nullptr;
    const AttachmentReference* pResolveAttachments = nullptr;
    const AttachmentReference* pDepthStencilAttachment = nullptr;
    uint32_t preserveAttachmentCount = 0;
    const uint32_t* pPreserveAttachments = nullptr;
    operator VkSubpassDescription const &() const noexcept {
        return *reinterpret_cast<const VkSubpassDescription*>(this);
    }
    operator VkSubpassDescription &() noexcept {
        return *reinterpret_cast<VkSubpassDescription*>(this);
    }
};
struct SubpassDependency {
    uint32_t srcSubpass = 0;
    uint32_t dstSubpass = 0;
    PipelineStageFlags srcStageMask = static_cast<PipelineStageFlags>(0);
    PipelineStageFlags dstStageMask = static_cast<PipelineStageFlags>(0);
    AccessFlags srcAccessMask = static_cast<AccessFlags>(0);
    AccessFlags dstAccessMask = static_cast<AccessFlags>(0);
    DependencyFlags dependencyFlags = static_cast<DependencyFlags>(0);
    operator VkSubpassDependency const &() const noexcept {
        return *reinterpret_cast<const VkSubpassDependency*>(this);
    }
    operator VkSubpassDependency &() noexcept {
        return *reinterpret_cast<VkSubpassDependency*>(this);
    }
};
struct RenderPassCreateInfo {
    StructureType sType = StructureType::eRenderPassCreateInfo;
    const void* pNext = nullptr;
    RenderPassCreateFlags flags = static_cast<RenderPassCreateFlags>(0);
    uint32_t attachmentCount = 0;
    const AttachmentDescription* pAttachments = nullptr;
    uint32_t subpassCount = 0;
    const SubpassDescription* pSubpasses = nullptr;
    uint32_t dependencyCount = 0;
    const SubpassDependency* pDependencies = nullptr;
    operator VkRenderPassCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassCreateInfo*>(this);
    }
    operator VkRenderPassCreateInfo &() noexcept {
        return *reinterpret_cast<VkRenderPassCreateInfo*>(this);
    }
};
struct EventCreateInfo {
    StructureType sType = StructureType::eEventCreateInfo;
    const void* pNext = nullptr;
    EventCreateFlags flags = static_cast<EventCreateFlags>(0);
    operator VkEventCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkEventCreateInfo*>(this);
    }
    operator VkEventCreateInfo &() noexcept {
        return *reinterpret_cast<VkEventCreateInfo*>(this);
    }
};
struct FenceCreateInfo {
    StructureType sType = StructureType::eFenceCreateInfo;
    const void* pNext = nullptr;
    FenceCreateFlags flags = static_cast<FenceCreateFlags>(0);
    operator VkFenceCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkFenceCreateInfo*>(this);
    }
    operator VkFenceCreateInfo &() noexcept {
        return *reinterpret_cast<VkFenceCreateInfo*>(this);
    }
};
struct SemaphoreCreateInfo {
    StructureType sType = StructureType::eSemaphoreCreateInfo;
    const void* pNext = nullptr;
    SemaphoreCreateFlags flags = static_cast<SemaphoreCreateFlags>(0);
    operator VkSemaphoreCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkSemaphoreCreateInfo*>(this);
    }
    operator VkSemaphoreCreateInfo &() noexcept {
        return *reinterpret_cast<VkSemaphoreCreateInfo*>(this);
    }
};
struct QueryPoolCreateInfo {
    StructureType sType = StructureType::eQueryPoolCreateInfo;
    const void* pNext = nullptr;
    QueryPoolCreateFlags flags = static_cast<QueryPoolCreateFlags>(0);
    QueryType queryType = static_cast<QueryType>(0);
    uint32_t queryCount = 0;
    QueryPipelineStatisticFlags pipelineStatistics = static_cast<QueryPipelineStatisticFlags>(0);
    operator VkQueryPoolCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkQueryPoolCreateInfo*>(this);
    }
    operator VkQueryPoolCreateInfo &() noexcept {
        return *reinterpret_cast<VkQueryPoolCreateInfo*>(this);
    }
};
struct FramebufferCreateInfo {
    StructureType sType = StructureType::eFramebufferCreateInfo;
    const void* pNext = nullptr;
    FramebufferCreateFlags flags = static_cast<FramebufferCreateFlags>(0);
    RenderPass renderPass;
    uint32_t attachmentCount = 0;
    const ImageView* pAttachments = nullptr;
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t layers = 0;
    operator VkFramebufferCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkFramebufferCreateInfo*>(this);
    }
    operator VkFramebufferCreateInfo &() noexcept {
        return *reinterpret_cast<VkFramebufferCreateInfo*>(this);
    }
};
struct DrawIndirectCommand {
    uint32_t vertexCount = 0;
    uint32_t instanceCount = 0;
    uint32_t firstVertex = 0;
    uint32_t firstInstance = 0;
    operator VkDrawIndirectCommand const &() const noexcept {
        return *reinterpret_cast<const VkDrawIndirectCommand*>(this);
    }
    operator VkDrawIndirectCommand &() noexcept {
        return *reinterpret_cast<VkDrawIndirectCommand*>(this);
    }
};
struct DrawIndexedIndirectCommand {
    uint32_t indexCount = 0;
    uint32_t instanceCount = 0;
    uint32_t firstIndex = 0;
    int32_t vertexOffset = 0;
    uint32_t firstInstance = 0;
    operator VkDrawIndexedIndirectCommand const &() const noexcept {
        return *reinterpret_cast<const VkDrawIndexedIndirectCommand*>(this);
    }
    operator VkDrawIndexedIndirectCommand &() noexcept {
        return *reinterpret_cast<VkDrawIndexedIndirectCommand*>(this);
    }
};
struct DispatchIndirectCommand {
    uint32_t x = 0;
    uint32_t y = 0;
    uint32_t z = 0;
    operator VkDispatchIndirectCommand const &() const noexcept {
        return *reinterpret_cast<const VkDispatchIndirectCommand*>(this);
    }
    operator VkDispatchIndirectCommand &() noexcept {
        return *reinterpret_cast<VkDispatchIndirectCommand*>(this);
    }
};
struct SubmitInfo {
    StructureType sType = StructureType::eSubmitInfo;
    const void* pNext = nullptr;
    uint32_t waitSemaphoreCount = 0;
    const Semaphore* pWaitSemaphores = nullptr;
    const PipelineStageFlags* pWaitDstStageMask = nullptr;
    uint32_t commandBufferCount = 0;
    const CommandBuffer* pCommandBuffers = nullptr;
    uint32_t signalSemaphoreCount = 0;
    const Semaphore* pSignalSemaphores = nullptr;
    operator VkSubmitInfo const &() const noexcept {
        return *reinterpret_cast<const VkSubmitInfo*>(this);
    }
    operator VkSubmitInfo &() noexcept {
        return *reinterpret_cast<VkSubmitInfo*>(this);
    }
};
struct DisplayPropertiesKHR {
    DisplayKHR display;
    const char* displayName = nullptr;
    Extent2D physicalDimensions;
    Extent2D physicalResolution;
    SurfaceTransformFlagsKHR supportedTransforms = static_cast<SurfaceTransformFlagsKHR>(0);
    bool planeReorderPossible = false;
    bool persistentContent = false;
    operator VkDisplayPropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPropertiesKHR*>(this);
    }
    operator VkDisplayPropertiesKHR &() noexcept {
        return *reinterpret_cast<VkDisplayPropertiesKHR*>(this);
    }
};
struct DisplayPlanePropertiesKHR {
    DisplayKHR currentDisplay;
    uint32_t currentStackIndex = 0;
    operator VkDisplayPlanePropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPlanePropertiesKHR*>(this);
    }
    operator VkDisplayPlanePropertiesKHR &() noexcept {
        return *reinterpret_cast<VkDisplayPlanePropertiesKHR*>(this);
    }
};
struct DisplayModeParametersKHR {
    Extent2D visibleRegion;
    uint32_t refreshRate = 0;
    operator VkDisplayModeParametersKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayModeParametersKHR*>(this);
    }
    operator VkDisplayModeParametersKHR &() noexcept {
        return *reinterpret_cast<VkDisplayModeParametersKHR*>(this);
    }
};
struct DisplayModePropertiesKHR {
    DisplayModeKHR displayMode;
    DisplayModeParametersKHR parameters;
    operator VkDisplayModePropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayModePropertiesKHR*>(this);
    }
    operator VkDisplayModePropertiesKHR &() noexcept {
        return *reinterpret_cast<VkDisplayModePropertiesKHR*>(this);
    }
};
struct DisplayModeCreateInfoKHR {
    StructureType sType = StructureType::eDisplayModeCreateInfoKHR;
    const void* pNext = nullptr;
    DisplayModeCreateFlagsKHR flags = static_cast<DisplayModeCreateFlagsKHR>(0);
    DisplayModeParametersKHR parameters;
    operator VkDisplayModeCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(this);
    }
    operator VkDisplayModeCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkDisplayModeCreateInfoKHR*>(this);
    }
};
struct DisplayPlaneCapabilitiesKHR {
    DisplayPlaneAlphaFlagsKHR supportedAlpha = static_cast<DisplayPlaneAlphaFlagsKHR>(0);
    Offset2D minSrcPosition;
    Offset2D maxSrcPosition;
    Extent2D minSrcExtent;
    Extent2D maxSrcExtent;
    Offset2D minDstPosition;
    Offset2D maxDstPosition;
    Extent2D minDstExtent;
    Extent2D maxDstExtent;
    operator VkDisplayPlaneCapabilitiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPlaneCapabilitiesKHR*>(this);
    }
    operator VkDisplayPlaneCapabilitiesKHR &() noexcept {
        return *reinterpret_cast<VkDisplayPlaneCapabilitiesKHR*>(this);
    }
};
struct DisplaySurfaceCreateInfoKHR {
    StructureType sType = StructureType::eDisplaySurfaceCreateInfoKHR;
    const void* pNext = nullptr;
    DisplaySurfaceCreateFlagsKHR flags = static_cast<DisplaySurfaceCreateFlagsKHR>(0);
    DisplayModeKHR displayMode;
    uint32_t planeIndex = 0;
    uint32_t planeStackIndex = 0;
    SurfaceTransformFlagBitsKHR transform = static_cast<SurfaceTransformFlagBitsKHR>(0);
    float globalAlpha = 0.f;
    DisplayPlaneAlphaFlagBitsKHR alphaMode = static_cast<DisplayPlaneAlphaFlagBitsKHR>(0);
    Extent2D imageExtent;
    operator VkDisplaySurfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(this);
    }
    operator VkDisplaySurfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkDisplaySurfaceCreateInfoKHR*>(this);
    }
};
struct DisplayPresentInfoKHR {
    StructureType sType = StructureType::eDisplayPresentInfoKHR;
    const void* pNext = nullptr;
    Rect2D srcRect;
    Rect2D dstRect;
    bool persistent = false;
    operator VkDisplayPresentInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPresentInfoKHR*>(this);
    }
    operator VkDisplayPresentInfoKHR &() noexcept {
        return *reinterpret_cast<VkDisplayPresentInfoKHR*>(this);
    }
};
struct SurfaceCapabilitiesKHR {
    uint32_t minImageCount = 0;
    uint32_t maxImageCount = 0;
    Extent2D currentExtent;
    Extent2D minImageExtent;
    Extent2D maxImageExtent;
    uint32_t maxImageArrayLayers = 0;
    SurfaceTransformFlagsKHR supportedTransforms = static_cast<SurfaceTransformFlagsKHR>(0);
    SurfaceTransformFlagBitsKHR currentTransform = static_cast<SurfaceTransformFlagBitsKHR>(0);
    CompositeAlphaFlagsKHR supportedCompositeAlpha = static_cast<CompositeAlphaFlagsKHR>(0);
    ImageUsageFlags supportedUsageFlags = static_cast<ImageUsageFlags>(0);
    operator VkSurfaceCapabilitiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceCapabilitiesKHR*>(this);
    }
    operator VkSurfaceCapabilitiesKHR &() noexcept {
        return *reinterpret_cast<VkSurfaceCapabilitiesKHR*>(this);
    }
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct AndroidSurfaceCreateInfoKHR {
    StructureType sType = StructureType::eAndroidSurfaceCreateInfoKHR;
    const void* pNext = nullptr;
    AndroidSurfaceCreateFlagsKHR flags = static_cast<AndroidSurfaceCreateFlagsKHR>(0);
    ANativeWindow* window = nullptr;
    operator VkAndroidSurfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(this);
    }
    operator VkAndroidSurfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkAndroidSurfaceCreateInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_VI_NN)
struct ViSurfaceCreateInfoNN {
    StructureType sType = StructureType::eViSurfaceCreateInfoNN;
    const void* pNext = nullptr;
    ViSurfaceCreateFlagsNN flags = static_cast<ViSurfaceCreateFlagsNN>(0);
    void* window = nullptr;
    operator VkViSurfaceCreateInfoNN const &() const noexcept {
        return *reinterpret_cast<const VkViSurfaceCreateInfoNN*>(this);
    }
    operator VkViSurfaceCreateInfoNN &() noexcept {
        return *reinterpret_cast<VkViSurfaceCreateInfoNN*>(this);
    }
};
#endif // VK_USE_PLATFORM_VI_NN
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
struct WaylandSurfaceCreateInfoKHR {
    StructureType sType = StructureType::eWaylandSurfaceCreateInfoKHR;
    const void* pNext = nullptr;
    WaylandSurfaceCreateFlagsKHR flags = static_cast<WaylandSurfaceCreateFlagsKHR>(0);
    wl_display* display = nullptr;
    wl_surface* surface = nullptr;
    operator VkWaylandSurfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(this);
    }
    operator VkWaylandSurfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkWaylandSurfaceCreateInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct Win32SurfaceCreateInfoKHR {
    StructureType sType = StructureType::eWin32SurfaceCreateInfoKHR;
    const void* pNext = nullptr;
    Win32SurfaceCreateFlagsKHR flags = static_cast<Win32SurfaceCreateFlagsKHR>(0);
    HINSTANCE hinstance;
    HWND hwnd;
    operator VkWin32SurfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(this);
    }
    operator VkWin32SurfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkWin32SurfaceCreateInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_XLIB_KHR)
struct XlibSurfaceCreateInfoKHR {
    StructureType sType = StructureType::eXlibSurfaceCreateInfoKHR;
    const void* pNext = nullptr;
    XlibSurfaceCreateFlagsKHR flags = static_cast<XlibSurfaceCreateFlagsKHR>(0);
    Display* dpy = nullptr;
    Window window;
    operator VkXlibSurfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(this);
    }
    operator VkXlibSurfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkXlibSurfaceCreateInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
struct XcbSurfaceCreateInfoKHR {
    StructureType sType = StructureType::eXcbSurfaceCreateInfoKHR;
    const void* pNext = nullptr;
    XcbSurfaceCreateFlagsKHR flags = static_cast<XcbSurfaceCreateFlagsKHR>(0);
    xcb_connection_t* connection = nullptr;
    xcb_window_t window;
    operator VkXcbSurfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(this);
    }
    operator VkXcbSurfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkXcbSurfaceCreateInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
struct DirectFBSurfaceCreateInfoEXT {
    StructureType sType = StructureType::eDirectfbSurfaceCreateInfoEXT;
    const void* pNext = nullptr;
    DirectFBSurfaceCreateFlagsEXT flags = static_cast<DirectFBSurfaceCreateFlagsEXT>(0);
    IDirectFB* dfb = nullptr;
    IDirectFBSurface* surface = nullptr;
    operator VkDirectFBSurfaceCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDirectFBSurfaceCreateInfoEXT*>(this);
    }
    operator VkDirectFBSurfaceCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkDirectFBSurfaceCreateInfoEXT*>(this);
    }
};
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_FUCHSIA)
struct ImagePipeSurfaceCreateInfoFUCHSIA {
    StructureType sType = StructureType::eImagepipeSurfaceCreateInfoFUCHSIA;
    const void* pNext = nullptr;
    ImagePipeSurfaceCreateFlagsFUCHSIA flags = static_cast<ImagePipeSurfaceCreateFlagsFUCHSIA>(0);
    zx_handle_t imagePipeHandle;
    operator VkImagePipeSurfaceCreateInfoFUCHSIA const &() const noexcept {
        return *reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(this);
    }
    operator VkImagePipeSurfaceCreateInfoFUCHSIA &() noexcept {
        return *reinterpret_cast<VkImagePipeSurfaceCreateInfoFUCHSIA*>(this);
    }
};
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_GGP)
struct StreamDescriptorSurfaceCreateInfoGGP {
    StructureType sType = StructureType::eStreamDescriptorSurfaceCreateInfoGGP;
    const void* pNext = nullptr;
    StreamDescriptorSurfaceCreateFlagsGGP flags = static_cast<StreamDescriptorSurfaceCreateFlagsGGP>(0);
    GgpStreamDescriptor streamDescriptor;
    operator VkStreamDescriptorSurfaceCreateInfoGGP const &() const noexcept {
        return *reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(this);
    }
    operator VkStreamDescriptorSurfaceCreateInfoGGP &() noexcept {
        return *reinterpret_cast<VkStreamDescriptorSurfaceCreateInfoGGP*>(this);
    }
};
#endif // VK_USE_PLATFORM_GGP
struct SurfaceFormatKHR {
    Format format = static_cast<Format>(0);
    ColorSpaceKHR colorSpace = static_cast<ColorSpaceKHR>(0);
    operator VkSurfaceFormatKHR const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceFormatKHR*>(this);
    }
    operator VkSurfaceFormatKHR &() noexcept {
        return *reinterpret_cast<VkSurfaceFormatKHR*>(this);
    }
};
struct SwapchainCreateInfoKHR {
    StructureType sType = StructureType::eSwapchainCreateInfoKHR;
    const void* pNext = nullptr;
    SwapchainCreateFlagsKHR flags = static_cast<SwapchainCreateFlagsKHR>(0);
    SurfaceKHR surface;
    uint32_t minImageCount = 0;
    Format imageFormat = static_cast<Format>(0);
    ColorSpaceKHR imageColorSpace = static_cast<ColorSpaceKHR>(0);
    Extent2D imageExtent;
    uint32_t imageArrayLayers = 0;
    ImageUsageFlags imageUsage = static_cast<ImageUsageFlags>(0);
    SharingMode imageSharingMode = static_cast<SharingMode>(0);
    uint32_t queueFamilyIndexCount = 0;
    const uint32_t* pQueueFamilyIndices = nullptr;
    SurfaceTransformFlagBitsKHR preTransform = static_cast<SurfaceTransformFlagBitsKHR>(0);
    CompositeAlphaFlagBitsKHR compositeAlpha = static_cast<CompositeAlphaFlagBitsKHR>(0);
    PresentModeKHR presentMode = static_cast<PresentModeKHR>(0);
    bool clipped = false;
    SwapchainKHR oldSwapchain;
    operator VkSwapchainCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkSwapchainCreateInfoKHR*>(this);
    }
    operator VkSwapchainCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkSwapchainCreateInfoKHR*>(this);
    }
};
struct PresentInfoKHR {
    StructureType sType = StructureType::ePresentInfoKHR;
    const void* pNext = nullptr;
    uint32_t waitSemaphoreCount = 0;
    const Semaphore* pWaitSemaphores = nullptr;
    uint32_t swapchainCount = 0;
    const SwapchainKHR* pSwapchains = nullptr;
    const uint32_t* pImageIndices = nullptr;
    Result* pResults = nullptr;
    operator VkPresentInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkPresentInfoKHR*>(this);
    }
    operator VkPresentInfoKHR &() noexcept {
        return *reinterpret_cast<VkPresentInfoKHR*>(this);
    }
};
struct DebugReportCallbackCreateInfoEXT {
    StructureType sType = StructureType::eDebugReportCallbackCreateInfoEXT;
    const void* pNext = nullptr;
    DebugReportFlagsEXT flags = static_cast<DebugReportFlagsEXT>(0);
    PFN_vkDebugReportCallbackEXT pfnCallback;
    void* pUserData = nullptr;
    operator VkDebugReportCallbackCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(this);
    }
    operator VkDebugReportCallbackCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugReportCallbackCreateInfoEXT*>(this);
    }
};
struct ValidationFlagsEXT {
    StructureType sType = StructureType::eValidationFlagsEXT;
    const void* pNext = nullptr;
    uint32_t disabledValidationCheckCount = 0;
    const ValidationCheckEXT* pDisabledValidationChecks = nullptr;
    operator VkValidationFlagsEXT const &() const noexcept {
        return *reinterpret_cast<const VkValidationFlagsEXT*>(this);
    }
    operator VkValidationFlagsEXT &() noexcept {
        return *reinterpret_cast<VkValidationFlagsEXT*>(this);
    }
};
struct ValidationFeaturesEXT {
    StructureType sType = StructureType::eValidationFeaturesEXT;
    const void* pNext = nullptr;
    uint32_t enabledValidationFeatureCount = 0;
    const ValidationFeatureEnableEXT* pEnabledValidationFeatures = nullptr;
    uint32_t disabledValidationFeatureCount = 0;
    const ValidationFeatureDisableEXT* pDisabledValidationFeatures = nullptr;
    operator VkValidationFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkValidationFeaturesEXT*>(this);
    }
    operator VkValidationFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkValidationFeaturesEXT*>(this);
    }
};
struct PipelineRasterizationStateRasterizationOrderAMD {
    StructureType sType = StructureType::ePipelineRasterizationStateRasterizationOrderAMD;
    const void* pNext = nullptr;
    RasterizationOrderAMD rasterizationOrder = static_cast<RasterizationOrderAMD>(0);
    operator VkPipelineRasterizationStateRasterizationOrderAMD const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(this);
    }
    operator VkPipelineRasterizationStateRasterizationOrderAMD &() noexcept {
        return *reinterpret_cast<VkPipelineRasterizationStateRasterizationOrderAMD*>(this);
    }
};
struct DebugMarkerObjectNameInfoEXT {
    StructureType sType = StructureType::eDebugMarkerObjectNameInfoEXT;
    const void* pNext = nullptr;
    DebugReportObjectTypeEXT objectType = static_cast<DebugReportObjectTypeEXT>(0);
    uint64_t object = 0;
    const char* pObjectName = nullptr;
    operator VkDebugMarkerObjectNameInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(this);
    }
    operator VkDebugMarkerObjectNameInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugMarkerObjectNameInfoEXT*>(this);
    }
};
struct DebugMarkerObjectTagInfoEXT {
    StructureType sType = StructureType::eDebugMarkerObjectTagInfoEXT;
    const void* pNext = nullptr;
    DebugReportObjectTypeEXT objectType = static_cast<DebugReportObjectTypeEXT>(0);
    uint64_t object = 0;
    uint64_t tagName = 0;
    size_t tagSize = 0;
    const void* pTag = nullptr;
    operator VkDebugMarkerObjectTagInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(this);
    }
    operator VkDebugMarkerObjectTagInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugMarkerObjectTagInfoEXT*>(this);
    }
};
struct DebugMarkerMarkerInfoEXT {
    StructureType sType = StructureType::eDebugMarkerMarkerInfoEXT;
    const void* pNext = nullptr;
    const char* pMarkerName = nullptr;
    float color[4] = {};
    operator VkDebugMarkerMarkerInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(this);
    }
    operator VkDebugMarkerMarkerInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugMarkerMarkerInfoEXT*>(this);
    }
};
struct DedicatedAllocationImageCreateInfoNV {
    StructureType sType = StructureType::eDedicatedAllocationImageCreateInfoNV;
    const void* pNext = nullptr;
    bool dedicatedAllocation = false;
    operator VkDedicatedAllocationImageCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(this);
    }
    operator VkDedicatedAllocationImageCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkDedicatedAllocationImageCreateInfoNV*>(this);
    }
};
struct DedicatedAllocationBufferCreateInfoNV {
    StructureType sType = StructureType::eDedicatedAllocationBufferCreateInfoNV;
    const void* pNext = nullptr;
    bool dedicatedAllocation = false;
    operator VkDedicatedAllocationBufferCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(this);
    }
    operator VkDedicatedAllocationBufferCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkDedicatedAllocationBufferCreateInfoNV*>(this);
    }
};
struct DedicatedAllocationMemoryAllocateInfoNV {
    StructureType sType = StructureType::eDedicatedAllocationMemoryAllocateInfoNV;
    const void* pNext = nullptr;
    Image image;
    Buffer buffer;
    operator VkDedicatedAllocationMemoryAllocateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(this);
    }
    operator VkDedicatedAllocationMemoryAllocateInfoNV &() noexcept {
        return *reinterpret_cast<VkDedicatedAllocationMemoryAllocateInfoNV*>(this);
    }
};
struct ExternalImageFormatPropertiesNV {
    ImageFormatProperties imageFormatProperties;
    ExternalMemoryFeatureFlagsNV externalMemoryFeatures = static_cast<ExternalMemoryFeatureFlagsNV>(0);
    ExternalMemoryHandleTypeFlagsNV exportFromImportedHandleTypes = static_cast<ExternalMemoryHandleTypeFlagsNV>(0);
    ExternalMemoryHandleTypeFlagsNV compatibleHandleTypes = static_cast<ExternalMemoryHandleTypeFlagsNV>(0);
    operator VkExternalImageFormatPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkExternalImageFormatPropertiesNV*>(this);
    }
    operator VkExternalImageFormatPropertiesNV &() noexcept {
        return *reinterpret_cast<VkExternalImageFormatPropertiesNV*>(this);
    }
};
struct ExternalMemoryImageCreateInfoNV {
    StructureType sType = StructureType::eExternalMemoryImageCreateInfoNV;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagsNV handleTypes = static_cast<ExternalMemoryHandleTypeFlagsNV>(0);
    operator VkExternalMemoryImageCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(this);
    }
    operator VkExternalMemoryImageCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkExternalMemoryImageCreateInfoNV*>(this);
    }
};
struct ExportMemoryAllocateInfoNV {
    StructureType sType = StructureType::eExportMemoryAllocateInfoNV;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagsNV handleTypes = static_cast<ExternalMemoryHandleTypeFlagsNV>(0);
    operator VkExportMemoryAllocateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(this);
    }
    operator VkExportMemoryAllocateInfoNV &() noexcept {
        return *reinterpret_cast<VkExportMemoryAllocateInfoNV*>(this);
    }
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportMemoryWin32HandleInfoNV {
    StructureType sType = StructureType::eImportMemoryWin32HandleInfoNV;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagsNV handleType = static_cast<ExternalMemoryHandleTypeFlagsNV>(0);
    HANDLE handle;
    operator VkImportMemoryWin32HandleInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(this);
    }
    operator VkImportMemoryWin32HandleInfoNV &() noexcept {
        return *reinterpret_cast<VkImportMemoryWin32HandleInfoNV*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ExportMemoryWin32HandleInfoNV {
    StructureType sType = StructureType::eExportMemoryWin32HandleInfoNV;
    const void* pNext = nullptr;
    const SECURITY_ATTRIBUTES* pAttributes = nullptr;
    DWORD dwAccess;
    operator VkExportMemoryWin32HandleInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(this);
    }
    operator VkExportMemoryWin32HandleInfoNV &() noexcept {
        return *reinterpret_cast<VkExportMemoryWin32HandleInfoNV*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct Win32KeyedMutexAcquireReleaseInfoNV {
    StructureType sType = StructureType::eWin32KeyedMutexAcquireReleaseInfoNV;
    const void* pNext = nullptr;
    uint32_t acquireCount = 0;
    const DeviceMemory* pAcquireSyncs = nullptr;
    const uint64_t* pAcquireKeys = nullptr;
    const uint32_t* pAcquireTimeoutMilliseconds = nullptr;
    uint32_t releaseCount = 0;
    const DeviceMemory* pReleaseSyncs = nullptr;
    const uint64_t* pReleaseKeys = nullptr;
    operator VkWin32KeyedMutexAcquireReleaseInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(this);
    }
    operator VkWin32KeyedMutexAcquireReleaseInfoNV &() noexcept {
        return *reinterpret_cast<VkWin32KeyedMutexAcquireReleaseInfoNV*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
struct PhysicalDeviceDeviceGeneratedCommandsFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
    void* pNext = nullptr;
    bool deviceGeneratedCommands = false;
    operator VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(this);
    }
};
struct DevicePrivateDataCreateInfoEXT {
    StructureType sType = StructureType::eDevicePrivateDataCreateInfoEXT;
    const void* pNext = nullptr;
    uint32_t privateDataSlotRequestCount = 0;
    operator VkDevicePrivateDataCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDevicePrivateDataCreateInfoEXT*>(this);
    }
    operator VkDevicePrivateDataCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkDevicePrivateDataCreateInfoEXT*>(this);
    }
};
struct PrivateDataSlotCreateInfoEXT {
    StructureType sType = StructureType::ePrivateDataSlotCreateInfoEXT;
    const void* pNext = nullptr;
    PrivateDataSlotCreateFlagsEXT flags = static_cast<PrivateDataSlotCreateFlagsEXT>(0);
    operator VkPrivateDataSlotCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPrivateDataSlotCreateInfoEXT*>(this);
    }
    operator VkPrivateDataSlotCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPrivateDataSlotCreateInfoEXT*>(this);
    }
};
struct PhysicalDevicePrivateDataFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDevicePrivateDataFeaturesEXT;
    void* pNext = nullptr;
    bool privateData = false;
    operator VkPhysicalDevicePrivateDataFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePrivateDataFeaturesEXT*>(this);
    }
    operator VkPhysicalDevicePrivateDataFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePrivateDataFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceDeviceGeneratedCommandsPropertiesNV {
    StructureType sType = StructureType::ePhysicalDeviceDeviceGeneratedCommandsPropertiesNV;
    void* pNext = nullptr;
    uint32_t maxGraphicsShaderGroupCount = 0;
    uint32_t maxIndirectSequenceCount = 0;
    uint32_t maxIndirectCommandsTokenCount = 0;
    uint32_t maxIndirectCommandsStreamCount = 0;
    uint32_t maxIndirectCommandsTokenOffset = 0;
    uint32_t maxIndirectCommandsStreamStride = 0;
    uint32_t minSequencesCountBufferOffsetAlignment = 0;
    uint32_t minSequencesIndexBufferOffsetAlignment = 0;
    uint32_t minIndirectCommandsBufferOffsetAlignment = 0;
    operator VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(this);
    }
    operator VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(this);
    }
};
struct GraphicsShaderGroupCreateInfoNV {
    StructureType sType = StructureType::eGraphicsShaderGroupCreateInfoNV;
    const void* pNext = nullptr;
    uint32_t stageCount = 0;
    const PipelineShaderStageCreateInfo* pStages = nullptr;
    const PipelineVertexInputStateCreateInfo* pVertexInputState = nullptr;
    const PipelineTessellationStateCreateInfo* pTessellationState = nullptr;
    operator VkGraphicsShaderGroupCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(this);
    }
    operator VkGraphicsShaderGroupCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkGraphicsShaderGroupCreateInfoNV*>(this);
    }
};
struct GraphicsPipelineShaderGroupsCreateInfoNV {
    StructureType sType = StructureType::eGraphicsPipelineShaderGroupsCreateInfoNV;
    const void* pNext = nullptr;
    uint32_t groupCount = 0;
    const GraphicsShaderGroupCreateInfoNV* pGroups = nullptr;
    uint32_t pipelineCount = 0;
    const Pipeline* pPipelines = nullptr;
    operator VkGraphicsPipelineShaderGroupsCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(this);
    }
    operator VkGraphicsPipelineShaderGroupsCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkGraphicsPipelineShaderGroupsCreateInfoNV*>(this);
    }
};
struct BindShaderGroupIndirectCommandNV {
    uint32_t groupIndex = 0;
    operator VkBindShaderGroupIndirectCommandNV const &() const noexcept {
        return *reinterpret_cast<const VkBindShaderGroupIndirectCommandNV*>(this);
    }
    operator VkBindShaderGroupIndirectCommandNV &() noexcept {
        return *reinterpret_cast<VkBindShaderGroupIndirectCommandNV*>(this);
    }
};
struct BindIndexBufferIndirectCommandNV {
    DeviceAddress bufferAddress = 0;
    uint32_t size = 0;
    IndexType indexType = static_cast<IndexType>(0);
    operator VkBindIndexBufferIndirectCommandNV const &() const noexcept {
        return *reinterpret_cast<const VkBindIndexBufferIndirectCommandNV*>(this);
    }
    operator VkBindIndexBufferIndirectCommandNV &() noexcept {
        return *reinterpret_cast<VkBindIndexBufferIndirectCommandNV*>(this);
    }
};
struct BindVertexBufferIndirectCommandNV {
    DeviceAddress bufferAddress = 0;
    uint32_t size = 0;
    uint32_t stride = 0;
    operator VkBindVertexBufferIndirectCommandNV const &() const noexcept {
        return *reinterpret_cast<const VkBindVertexBufferIndirectCommandNV*>(this);
    }
    operator VkBindVertexBufferIndirectCommandNV &() noexcept {
        return *reinterpret_cast<VkBindVertexBufferIndirectCommandNV*>(this);
    }
};
struct SetStateFlagsIndirectCommandNV {
    uint32_t data = 0;
    operator VkSetStateFlagsIndirectCommandNV const &() const noexcept {
        return *reinterpret_cast<const VkSetStateFlagsIndirectCommandNV*>(this);
    }
    operator VkSetStateFlagsIndirectCommandNV &() noexcept {
        return *reinterpret_cast<VkSetStateFlagsIndirectCommandNV*>(this);
    }
};
struct IndirectCommandsStreamNV {
    Buffer buffer;
    DeviceSize offset = 0;
    operator VkIndirectCommandsStreamNV const &() const noexcept {
        return *reinterpret_cast<const VkIndirectCommandsStreamNV*>(this);
    }
    operator VkIndirectCommandsStreamNV &() noexcept {
        return *reinterpret_cast<VkIndirectCommandsStreamNV*>(this);
    }
};
struct IndirectCommandsLayoutTokenNV {
    StructureType sType = StructureType::eIndirectCommandsLayoutTokenNV;
    const void* pNext = nullptr;
    IndirectCommandsTokenTypeNV tokenType = static_cast<IndirectCommandsTokenTypeNV>(0);
    uint32_t stream = 0;
    uint32_t offset = 0;
    uint32_t vertexBindingUnit = 0;
    bool vertexDynamicStride = false;
    PipelineLayout pushconstantPipelineLayout;
    ShaderStageFlags pushconstantShaderStageFlags = static_cast<ShaderStageFlags>(0);
    uint32_t pushconstantOffset = 0;
    uint32_t pushconstantSize = 0;
    IndirectStateFlagsNV indirectStateFlags = static_cast<IndirectStateFlagsNV>(0);
    uint32_t indexTypeCount = 0;
    const IndexType* pIndexTypes = nullptr;
    const uint32_t* pIndexTypeValues = nullptr;
    operator VkIndirectCommandsLayoutTokenNV const &() const noexcept {
        return *reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(this);
    }
    operator VkIndirectCommandsLayoutTokenNV &() noexcept {
        return *reinterpret_cast<VkIndirectCommandsLayoutTokenNV*>(this);
    }
};
struct IndirectCommandsLayoutCreateInfoNV {
    StructureType sType = StructureType::eIndirectCommandsLayoutCreateInfoNV;
    const void* pNext = nullptr;
    IndirectCommandsLayoutUsageFlagsNV flags = static_cast<IndirectCommandsLayoutUsageFlagsNV>(0);
    PipelineBindPoint pipelineBindPoint = static_cast<PipelineBindPoint>(0);
    uint32_t tokenCount = 0;
    const IndirectCommandsLayoutTokenNV* pTokens = nullptr;
    uint32_t streamCount = 0;
    const uint32_t* pStreamStrides = nullptr;
    operator VkIndirectCommandsLayoutCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(this);
    }
    operator VkIndirectCommandsLayoutCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkIndirectCommandsLayoutCreateInfoNV*>(this);
    }
};
struct GeneratedCommandsInfoNV {
    StructureType sType = StructureType::eGeneratedCommandsInfoNV;
    const void* pNext = nullptr;
    PipelineBindPoint pipelineBindPoint = static_cast<PipelineBindPoint>(0);
    Pipeline pipeline;
    IndirectCommandsLayoutNV indirectCommandsLayout;
    uint32_t streamCount = 0;
    const IndirectCommandsStreamNV* pStreams = nullptr;
    uint32_t sequencesCount = 0;
    Buffer preprocessBuffer;
    DeviceSize preprocessOffset = 0;
    DeviceSize preprocessSize = 0;
    Buffer sequencesCountBuffer;
    DeviceSize sequencesCountOffset = 0;
    Buffer sequencesIndexBuffer;
    DeviceSize sequencesIndexOffset = 0;
    operator VkGeneratedCommandsInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkGeneratedCommandsInfoNV*>(this);
    }
    operator VkGeneratedCommandsInfoNV &() noexcept {
        return *reinterpret_cast<VkGeneratedCommandsInfoNV*>(this);
    }
};
struct GeneratedCommandsMemoryRequirementsInfoNV {
    StructureType sType = StructureType::eGeneratedCommandsMemoryRequirementsInfoNV;
    const void* pNext = nullptr;
    PipelineBindPoint pipelineBindPoint = static_cast<PipelineBindPoint>(0);
    Pipeline pipeline;
    IndirectCommandsLayoutNV indirectCommandsLayout;
    uint32_t maxSequencesCount = 0;
    operator VkGeneratedCommandsMemoryRequirementsInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(this);
    }
    operator VkGeneratedCommandsMemoryRequirementsInfoNV &() noexcept {
        return *reinterpret_cast<VkGeneratedCommandsMemoryRequirementsInfoNV*>(this);
    }
};
struct PhysicalDeviceFeatures2 {
    StructureType sType = StructureType::ePhysicalDeviceFeatures2;
    void* pNext = nullptr;
    PhysicalDeviceFeatures features;
    operator VkPhysicalDeviceFeatures2 const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFeatures2*>(this);
    }
    operator VkPhysicalDeviceFeatures2 &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFeatures2*>(this);
    }
};
using PhysicalDeviceFeatures2KHR = PhysicalDeviceFeatures2;
struct PhysicalDeviceProperties2 {
    StructureType sType = StructureType::ePhysicalDeviceProperties2;
    void* pNext = nullptr;
    PhysicalDeviceProperties properties;
    operator VkPhysicalDeviceProperties2 const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceProperties2*>(this);
    }
    operator VkPhysicalDeviceProperties2 &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceProperties2*>(this);
    }
};
using PhysicalDeviceProperties2KHR = PhysicalDeviceProperties2;
struct FormatProperties2 {
    StructureType sType = StructureType::eFormatProperties2;
    void* pNext = nullptr;
    FormatProperties formatProperties;
    operator VkFormatProperties2 const &() const noexcept {
        return *reinterpret_cast<const VkFormatProperties2*>(this);
    }
    operator VkFormatProperties2 &() noexcept {
        return *reinterpret_cast<VkFormatProperties2*>(this);
    }
};
using FormatProperties2KHR = FormatProperties2;
struct ImageFormatProperties2 {
    StructureType sType = StructureType::eImageFormatProperties2;
    void* pNext = nullptr;
    ImageFormatProperties imageFormatProperties;
    operator VkImageFormatProperties2 const &() const noexcept {
        return *reinterpret_cast<const VkImageFormatProperties2*>(this);
    }
    operator VkImageFormatProperties2 &() noexcept {
        return *reinterpret_cast<VkImageFormatProperties2*>(this);
    }
};
using ImageFormatProperties2KHR = ImageFormatProperties2;
struct PhysicalDeviceImageFormatInfo2 {
    StructureType sType = StructureType::ePhysicalDeviceImageFormatInfo2;
    const void* pNext = nullptr;
    Format format = static_cast<Format>(0);
    ImageType type = static_cast<ImageType>(0);
    ImageTiling tiling = static_cast<ImageTiling>(0);
    ImageUsageFlags usage = static_cast<ImageUsageFlags>(0);
    ImageCreateFlags flags = static_cast<ImageCreateFlags>(0);
    operator VkPhysicalDeviceImageFormatInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(this);
    }
    operator VkPhysicalDeviceImageFormatInfo2 &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceImageFormatInfo2*>(this);
    }
};
using PhysicalDeviceImageFormatInfo2KHR = PhysicalDeviceImageFormatInfo2;
struct QueueFamilyProperties2 {
    StructureType sType = StructureType::eQueueFamilyProperties2;
    void* pNext = nullptr;
    QueueFamilyProperties queueFamilyProperties;
    operator VkQueueFamilyProperties2 const &() const noexcept {
        return *reinterpret_cast<const VkQueueFamilyProperties2*>(this);
    }
    operator VkQueueFamilyProperties2 &() noexcept {
        return *reinterpret_cast<VkQueueFamilyProperties2*>(this);
    }
};
using QueueFamilyProperties2KHR = QueueFamilyProperties2;
struct PhysicalDeviceMemoryProperties2 {
    StructureType sType = StructureType::ePhysicalDeviceMemoryProperties2;
    void* pNext = nullptr;
    PhysicalDeviceMemoryProperties memoryProperties;
    operator VkPhysicalDeviceMemoryProperties2 const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMemoryProperties2*>(this);
    }
    operator VkPhysicalDeviceMemoryProperties2 &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMemoryProperties2*>(this);
    }
};
using PhysicalDeviceMemoryProperties2KHR = PhysicalDeviceMemoryProperties2;
struct SparseImageFormatProperties2 {
    StructureType sType = StructureType::eSparseImageFormatProperties2;
    void* pNext = nullptr;
    SparseImageFormatProperties properties;
    operator VkSparseImageFormatProperties2 const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageFormatProperties2*>(this);
    }
    operator VkSparseImageFormatProperties2 &() noexcept {
        return *reinterpret_cast<VkSparseImageFormatProperties2*>(this);
    }
};
using SparseImageFormatProperties2KHR = SparseImageFormatProperties2;
struct PhysicalDeviceSparseImageFormatInfo2 {
    StructureType sType = StructureType::ePhysicalDeviceSparseImageFormatInfo2;
    const void* pNext = nullptr;
    Format format = static_cast<Format>(0);
    ImageType type = static_cast<ImageType>(0);
    SampleCountFlagBits samples = static_cast<SampleCountFlagBits>(0);
    ImageUsageFlags usage = static_cast<ImageUsageFlags>(0);
    ImageTiling tiling = static_cast<ImageTiling>(0);
    operator VkPhysicalDeviceSparseImageFormatInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(this);
    }
    operator VkPhysicalDeviceSparseImageFormatInfo2 &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSparseImageFormatInfo2*>(this);
    }
};
using PhysicalDeviceSparseImageFormatInfo2KHR = PhysicalDeviceSparseImageFormatInfo2;
struct PhysicalDevicePushDescriptorPropertiesKHR {
    StructureType sType = StructureType::ePhysicalDevicePushDescriptorPropertiesKHR;
    void* pNext = nullptr;
    uint32_t maxPushDescriptors = 0;
    operator VkPhysicalDevicePushDescriptorPropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(this);
    }
    operator VkPhysicalDevicePushDescriptorPropertiesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePushDescriptorPropertiesKHR*>(this);
    }
};
struct ConformanceVersion {
    uint8_t major = 0;
    uint8_t minor = 0;
    uint8_t subminor = 0;
    uint8_t patch = 0;
    operator VkConformanceVersion const &() const noexcept {
        return *reinterpret_cast<const VkConformanceVersion*>(this);
    }
    operator VkConformanceVersion &() noexcept {
        return *reinterpret_cast<VkConformanceVersion*>(this);
    }
};
using ConformanceVersionKHR = ConformanceVersion;
struct PhysicalDeviceDriverProperties {
    StructureType sType = StructureType::ePhysicalDeviceDriverProperties;
    void* pNext = nullptr;
    DriverId driverID = static_cast<DriverId>(0);
    char driverName[MAX_DRIVER_NAME_SIZE] = {};
    char driverInfo[MAX_DRIVER_INFO_SIZE] = {};
    ConformanceVersion conformanceVersion;
    operator VkPhysicalDeviceDriverProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(this);
    }
    operator VkPhysicalDeviceDriverProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDriverProperties*>(this);
    }
};
using PhysicalDeviceDriverPropertiesKHR = PhysicalDeviceDriverProperties;
struct RectLayerKHR {
    Offset2D offset;
    Extent2D extent;
    uint32_t layer = 0;
    operator VkRectLayerKHR const &() const noexcept {
        return *reinterpret_cast<const VkRectLayerKHR*>(this);
    }
    operator VkRectLayerKHR &() noexcept {
        return *reinterpret_cast<VkRectLayerKHR*>(this);
    }
};
struct PresentRegionKHR {
    uint32_t rectangleCount = 0;
    const RectLayerKHR* pRectangles = nullptr;
    operator VkPresentRegionKHR const &() const noexcept {
        return *reinterpret_cast<const VkPresentRegionKHR*>(this);
    }
    operator VkPresentRegionKHR &() noexcept {
        return *reinterpret_cast<VkPresentRegionKHR*>(this);
    }
};
struct PresentRegionsKHR {
    StructureType sType = StructureType::ePresentRegionsKHR;
    const void* pNext = nullptr;
    uint32_t swapchainCount = 0;
    const PresentRegionKHR* pRegions = nullptr;
    operator VkPresentRegionsKHR const &() const noexcept {
        return *reinterpret_cast<const VkPresentRegionsKHR*>(this);
    }
    operator VkPresentRegionsKHR &() noexcept {
        return *reinterpret_cast<VkPresentRegionsKHR*>(this);
    }
};
struct PhysicalDeviceVariablePointersFeatures {
    StructureType sType = StructureType::ePhysicalDeviceVariablePointersFeatures;
    void* pNext = nullptr;
    bool variablePointersStorageBuffer = false;
    bool variablePointers = false;
    operator VkPhysicalDeviceVariablePointersFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(this);
    }
    operator VkPhysicalDeviceVariablePointersFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVariablePointersFeatures*>(this);
    }
};
using PhysicalDeviceVariablePointersFeaturesKHR = PhysicalDeviceVariablePointersFeatures;
using PhysicalDeviceVariablePointerFeaturesKHR = PhysicalDeviceVariablePointersFeatures;
using PhysicalDeviceVariablePointerFeatures = PhysicalDeviceVariablePointersFeatures;
struct ExternalMemoryProperties {
    ExternalMemoryFeatureFlags externalMemoryFeatures = static_cast<ExternalMemoryFeatureFlags>(0);
    ExternalMemoryHandleTypeFlags exportFromImportedHandleTypes = static_cast<ExternalMemoryHandleTypeFlags>(0);
    ExternalMemoryHandleTypeFlags compatibleHandleTypes = static_cast<ExternalMemoryHandleTypeFlags>(0);
    operator VkExternalMemoryProperties const &() const noexcept {
        return *reinterpret_cast<const VkExternalMemoryProperties*>(this);
    }
    operator VkExternalMemoryProperties &() noexcept {
        return *reinterpret_cast<VkExternalMemoryProperties*>(this);
    }
};
using ExternalMemoryPropertiesKHR = ExternalMemoryProperties;
struct PhysicalDeviceExternalImageFormatInfo {
    StructureType sType = StructureType::ePhysicalDeviceExternalImageFormatInfo;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    operator VkPhysicalDeviceExternalImageFormatInfo const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(this);
    }
    operator VkPhysicalDeviceExternalImageFormatInfo &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExternalImageFormatInfo*>(this);
    }
};
using PhysicalDeviceExternalImageFormatInfoKHR = PhysicalDeviceExternalImageFormatInfo;
struct ExternalImageFormatProperties {
    StructureType sType = StructureType::eExternalImageFormatProperties;
    void* pNext = nullptr;
    ExternalMemoryProperties externalMemoryProperties;
    operator VkExternalImageFormatProperties const &() const noexcept {
        return *reinterpret_cast<const VkExternalImageFormatProperties*>(this);
    }
    operator VkExternalImageFormatProperties &() noexcept {
        return *reinterpret_cast<VkExternalImageFormatProperties*>(this);
    }
};
using ExternalImageFormatPropertiesKHR = ExternalImageFormatProperties;
struct PhysicalDeviceExternalBufferInfo {
    StructureType sType = StructureType::ePhysicalDeviceExternalBufferInfo;
    const void* pNext = nullptr;
    BufferCreateFlags flags = static_cast<BufferCreateFlags>(0);
    BufferUsageFlags usage = static_cast<BufferUsageFlags>(0);
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    operator VkPhysicalDeviceExternalBufferInfo const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(this);
    }
    operator VkPhysicalDeviceExternalBufferInfo &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExternalBufferInfo*>(this);
    }
};
using PhysicalDeviceExternalBufferInfoKHR = PhysicalDeviceExternalBufferInfo;
struct ExternalBufferProperties {
    StructureType sType = StructureType::eExternalBufferProperties;
    void* pNext = nullptr;
    ExternalMemoryProperties externalMemoryProperties;
    operator VkExternalBufferProperties const &() const noexcept {
        return *reinterpret_cast<const VkExternalBufferProperties*>(this);
    }
    operator VkExternalBufferProperties &() noexcept {
        return *reinterpret_cast<VkExternalBufferProperties*>(this);
    }
};
using ExternalBufferPropertiesKHR = ExternalBufferProperties;
struct PhysicalDeviceIDProperties {
    StructureType sType = StructureType::ePhysicalDeviceIdProperties;
    void* pNext = nullptr;
    uint8_t deviceUUID[UUID_SIZE] = {};
    uint8_t driverUUID[UUID_SIZE] = {};
    uint8_t deviceLUID[LUID_SIZE] = {};
    uint32_t deviceNodeMask = 0;
    bool deviceLUIDValid = false;
    operator VkPhysicalDeviceIDProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceIDProperties*>(this);
    }
    operator VkPhysicalDeviceIDProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceIDProperties*>(this);
    }
};
using PhysicalDeviceIDPropertiesKHR = PhysicalDeviceIDProperties;
struct ExternalMemoryImageCreateInfo {
    StructureType sType = StructureType::eExternalMemoryImageCreateInfo;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlags handleTypes = static_cast<ExternalMemoryHandleTypeFlags>(0);
    operator VkExternalMemoryImageCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(this);
    }
    operator VkExternalMemoryImageCreateInfo &() noexcept {
        return *reinterpret_cast<VkExternalMemoryImageCreateInfo*>(this);
    }
};
using ExternalMemoryImageCreateInfoKHR = ExternalMemoryImageCreateInfo;
struct ExternalMemoryBufferCreateInfo {
    StructureType sType = StructureType::eExternalMemoryBufferCreateInfo;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlags handleTypes = static_cast<ExternalMemoryHandleTypeFlags>(0);
    operator VkExternalMemoryBufferCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(this);
    }
    operator VkExternalMemoryBufferCreateInfo &() noexcept {
        return *reinterpret_cast<VkExternalMemoryBufferCreateInfo*>(this);
    }
};
using ExternalMemoryBufferCreateInfoKHR = ExternalMemoryBufferCreateInfo;
struct ExportMemoryAllocateInfo {
    StructureType sType = StructureType::eExportMemoryAllocateInfo;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlags handleTypes = static_cast<ExternalMemoryHandleTypeFlags>(0);
    operator VkExportMemoryAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkExportMemoryAllocateInfo*>(this);
    }
    operator VkExportMemoryAllocateInfo &() noexcept {
        return *reinterpret_cast<VkExportMemoryAllocateInfo*>(this);
    }
};
using ExportMemoryAllocateInfoKHR = ExportMemoryAllocateInfo;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportMemoryWin32HandleInfoKHR {
    StructureType sType = StructureType::eImportMemoryWin32HandleInfoKHR;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    HANDLE handle;
    LPCWSTR name;
    operator VkImportMemoryWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(this);
    }
    operator VkImportMemoryWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkImportMemoryWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ExportMemoryWin32HandleInfoKHR {
    StructureType sType = StructureType::eExportMemoryWin32HandleInfoKHR;
    const void* pNext = nullptr;
    const SECURITY_ATTRIBUTES* pAttributes = nullptr;
    DWORD dwAccess;
    LPCWSTR name;
    operator VkExportMemoryWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(this);
    }
    operator VkExportMemoryWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkExportMemoryWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct MemoryWin32HandlePropertiesKHR {
    StructureType sType = StructureType::eMemoryWin32HandlePropertiesKHR;
    void* pNext = nullptr;
    uint32_t memoryTypeBits = 0;
    operator VkMemoryWin32HandlePropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(this);
    }
    operator VkMemoryWin32HandlePropertiesKHR &() noexcept {
        return *reinterpret_cast<VkMemoryWin32HandlePropertiesKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct MemoryGetWin32HandleInfoKHR {
    StructureType sType = StructureType::eMemoryGetWin32HandleInfoKHR;
    const void* pNext = nullptr;
    DeviceMemory memory;
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    operator VkMemoryGetWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(this);
    }
    operator VkMemoryGetWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkMemoryGetWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
struct ImportMemoryFdInfoKHR {
    StructureType sType = StructureType::eImportMemoryFdInfoKHR;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    int fd = 0;
    operator VkImportMemoryFdInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImportMemoryFdInfoKHR*>(this);
    }
    operator VkImportMemoryFdInfoKHR &() noexcept {
        return *reinterpret_cast<VkImportMemoryFdInfoKHR*>(this);
    }
};
struct MemoryFdPropertiesKHR {
    StructureType sType = StructureType::eMemoryFdPropertiesKHR;
    void* pNext = nullptr;
    uint32_t memoryTypeBits = 0;
    operator VkMemoryFdPropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkMemoryFdPropertiesKHR*>(this);
    }
    operator VkMemoryFdPropertiesKHR &() noexcept {
        return *reinterpret_cast<VkMemoryFdPropertiesKHR*>(this);
    }
};
struct MemoryGetFdInfoKHR {
    StructureType sType = StructureType::eMemoryGetFdInfoKHR;
    const void* pNext = nullptr;
    DeviceMemory memory;
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    operator VkMemoryGetFdInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkMemoryGetFdInfoKHR*>(this);
    }
    operator VkMemoryGetFdInfoKHR &() noexcept {
        return *reinterpret_cast<VkMemoryGetFdInfoKHR*>(this);
    }
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct Win32KeyedMutexAcquireReleaseInfoKHR {
    StructureType sType = StructureType::eWin32KeyedMutexAcquireReleaseInfoKHR;
    const void* pNext = nullptr;
    uint32_t acquireCount = 0;
    const DeviceMemory* pAcquireSyncs = nullptr;
    const uint64_t* pAcquireKeys = nullptr;
    const uint32_t* pAcquireTimeouts = nullptr;
    uint32_t releaseCount = 0;
    const DeviceMemory* pReleaseSyncs = nullptr;
    const uint64_t* pReleaseKeys = nullptr;
    operator VkWin32KeyedMutexAcquireReleaseInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(this);
    }
    operator VkWin32KeyedMutexAcquireReleaseInfoKHR &() noexcept {
        return *reinterpret_cast<VkWin32KeyedMutexAcquireReleaseInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
struct PhysicalDeviceExternalSemaphoreInfo {
    StructureType sType = StructureType::ePhysicalDeviceExternalSemaphoreInfo;
    const void* pNext = nullptr;
    ExternalSemaphoreHandleTypeFlagBits handleType = static_cast<ExternalSemaphoreHandleTypeFlagBits>(0);
    operator VkPhysicalDeviceExternalSemaphoreInfo const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(this);
    }
    operator VkPhysicalDeviceExternalSemaphoreInfo &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExternalSemaphoreInfo*>(this);
    }
};
using PhysicalDeviceExternalSemaphoreInfoKHR = PhysicalDeviceExternalSemaphoreInfo;
struct ExternalSemaphoreProperties {
    StructureType sType = StructureType::eExternalSemaphoreProperties;
    void* pNext = nullptr;
    ExternalSemaphoreHandleTypeFlags exportFromImportedHandleTypes = static_cast<ExternalSemaphoreHandleTypeFlags>(0);
    ExternalSemaphoreHandleTypeFlags compatibleHandleTypes = static_cast<ExternalSemaphoreHandleTypeFlags>(0);
    ExternalSemaphoreFeatureFlags externalSemaphoreFeatures = static_cast<ExternalSemaphoreFeatureFlags>(0);
    operator VkExternalSemaphoreProperties const &() const noexcept {
        return *reinterpret_cast<const VkExternalSemaphoreProperties*>(this);
    }
    operator VkExternalSemaphoreProperties &() noexcept {
        return *reinterpret_cast<VkExternalSemaphoreProperties*>(this);
    }
};
using ExternalSemaphorePropertiesKHR = ExternalSemaphoreProperties;
struct ExportSemaphoreCreateInfo {
    StructureType sType = StructureType::eExportSemaphoreCreateInfo;
    const void* pNext = nullptr;
    ExternalSemaphoreHandleTypeFlags handleTypes = static_cast<ExternalSemaphoreHandleTypeFlags>(0);
    operator VkExportSemaphoreCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkExportSemaphoreCreateInfo*>(this);
    }
    operator VkExportSemaphoreCreateInfo &() noexcept {
        return *reinterpret_cast<VkExportSemaphoreCreateInfo*>(this);
    }
};
using ExportSemaphoreCreateInfoKHR = ExportSemaphoreCreateInfo;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportSemaphoreWin32HandleInfoKHR {
    StructureType sType = StructureType::eImportSemaphoreWin32HandleInfoKHR;
    const void* pNext = nullptr;
    Semaphore semaphore;
    SemaphoreImportFlags flags = static_cast<SemaphoreImportFlags>(0);
    ExternalSemaphoreHandleTypeFlagBits handleType = static_cast<ExternalSemaphoreHandleTypeFlagBits>(0);
    HANDLE handle;
    LPCWSTR name;
    operator VkImportSemaphoreWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(this);
    }
    operator VkImportSemaphoreWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkImportSemaphoreWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ExportSemaphoreWin32HandleInfoKHR {
    StructureType sType = StructureType::eExportSemaphoreWin32HandleInfoKHR;
    const void* pNext = nullptr;
    const SECURITY_ATTRIBUTES* pAttributes = nullptr;
    DWORD dwAccess;
    LPCWSTR name;
    operator VkExportSemaphoreWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(this);
    }
    operator VkExportSemaphoreWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkExportSemaphoreWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct D3D12FenceSubmitInfoKHR {
    StructureType sType = StructureType::eD3D12FenceSubmitInfoKHR;
    const void* pNext = nullptr;
    uint32_t waitSemaphoreValuesCount = 0;
    const uint64_t* pWaitSemaphoreValues = nullptr;
    uint32_t signalSemaphoreValuesCount = 0;
    const uint64_t* pSignalSemaphoreValues = nullptr;
    operator VkD3D12FenceSubmitInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(this);
    }
    operator VkD3D12FenceSubmitInfoKHR &() noexcept {
        return *reinterpret_cast<VkD3D12FenceSubmitInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct SemaphoreGetWin32HandleInfoKHR {
    StructureType sType = StructureType::eSemaphoreGetWin32HandleInfoKHR;
    const void* pNext = nullptr;
    Semaphore semaphore;
    ExternalSemaphoreHandleTypeFlagBits handleType = static_cast<ExternalSemaphoreHandleTypeFlagBits>(0);
    operator VkSemaphoreGetWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(this);
    }
    operator VkSemaphoreGetWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkSemaphoreGetWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
struct ImportSemaphoreFdInfoKHR {
    StructureType sType = StructureType::eImportSemaphoreFdInfoKHR;
    const void* pNext = nullptr;
    Semaphore semaphore;
    SemaphoreImportFlags flags = static_cast<SemaphoreImportFlags>(0);
    ExternalSemaphoreHandleTypeFlagBits handleType = static_cast<ExternalSemaphoreHandleTypeFlagBits>(0);
    int fd = 0;
    operator VkImportSemaphoreFdInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(this);
    }
    operator VkImportSemaphoreFdInfoKHR &() noexcept {
        return *reinterpret_cast<VkImportSemaphoreFdInfoKHR*>(this);
    }
};
struct SemaphoreGetFdInfoKHR {
    StructureType sType = StructureType::eSemaphoreGetFdInfoKHR;
    const void* pNext = nullptr;
    Semaphore semaphore;
    ExternalSemaphoreHandleTypeFlagBits handleType = static_cast<ExternalSemaphoreHandleTypeFlagBits>(0);
    operator VkSemaphoreGetFdInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(this);
    }
    operator VkSemaphoreGetFdInfoKHR &() noexcept {
        return *reinterpret_cast<VkSemaphoreGetFdInfoKHR*>(this);
    }
};
struct PhysicalDeviceExternalFenceInfo {
    StructureType sType = StructureType::ePhysicalDeviceExternalFenceInfo;
    const void* pNext = nullptr;
    ExternalFenceHandleTypeFlagBits handleType = static_cast<ExternalFenceHandleTypeFlagBits>(0);
    operator VkPhysicalDeviceExternalFenceInfo const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(this);
    }
    operator VkPhysicalDeviceExternalFenceInfo &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExternalFenceInfo*>(this);
    }
};
using PhysicalDeviceExternalFenceInfoKHR = PhysicalDeviceExternalFenceInfo;
struct ExternalFenceProperties {
    StructureType sType = StructureType::eExternalFenceProperties;
    void* pNext = nullptr;
    ExternalFenceHandleTypeFlags exportFromImportedHandleTypes = static_cast<ExternalFenceHandleTypeFlags>(0);
    ExternalFenceHandleTypeFlags compatibleHandleTypes = static_cast<ExternalFenceHandleTypeFlags>(0);
    ExternalFenceFeatureFlags externalFenceFeatures = static_cast<ExternalFenceFeatureFlags>(0);
    operator VkExternalFenceProperties const &() const noexcept {
        return *reinterpret_cast<const VkExternalFenceProperties*>(this);
    }
    operator VkExternalFenceProperties &() noexcept {
        return *reinterpret_cast<VkExternalFenceProperties*>(this);
    }
};
using ExternalFencePropertiesKHR = ExternalFenceProperties;
struct ExportFenceCreateInfo {
    StructureType sType = StructureType::eExportFenceCreateInfo;
    const void* pNext = nullptr;
    ExternalFenceHandleTypeFlags handleTypes = static_cast<ExternalFenceHandleTypeFlags>(0);
    operator VkExportFenceCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkExportFenceCreateInfo*>(this);
    }
    operator VkExportFenceCreateInfo &() noexcept {
        return *reinterpret_cast<VkExportFenceCreateInfo*>(this);
    }
};
using ExportFenceCreateInfoKHR = ExportFenceCreateInfo;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportFenceWin32HandleInfoKHR {
    StructureType sType = StructureType::eImportFenceWin32HandleInfoKHR;
    const void* pNext = nullptr;
    Fence fence;
    FenceImportFlags flags = static_cast<FenceImportFlags>(0);
    ExternalFenceHandleTypeFlagBits handleType = static_cast<ExternalFenceHandleTypeFlagBits>(0);
    HANDLE handle;
    LPCWSTR name;
    operator VkImportFenceWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(this);
    }
    operator VkImportFenceWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkImportFenceWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ExportFenceWin32HandleInfoKHR {
    StructureType sType = StructureType::eExportFenceWin32HandleInfoKHR;
    const void* pNext = nullptr;
    const SECURITY_ATTRIBUTES* pAttributes = nullptr;
    DWORD dwAccess;
    LPCWSTR name;
    operator VkExportFenceWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(this);
    }
    operator VkExportFenceWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkExportFenceWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct FenceGetWin32HandleInfoKHR {
    StructureType sType = StructureType::eFenceGetWin32HandleInfoKHR;
    const void* pNext = nullptr;
    Fence fence;
    ExternalFenceHandleTypeFlagBits handleType = static_cast<ExternalFenceHandleTypeFlagBits>(0);
    operator VkFenceGetWin32HandleInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(this);
    }
    operator VkFenceGetWin32HandleInfoKHR &() noexcept {
        return *reinterpret_cast<VkFenceGetWin32HandleInfoKHR*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
struct ImportFenceFdInfoKHR {
    StructureType sType = StructureType::eImportFenceFdInfoKHR;
    const void* pNext = nullptr;
    Fence fence;
    FenceImportFlags flags = static_cast<FenceImportFlags>(0);
    ExternalFenceHandleTypeFlagBits handleType = static_cast<ExternalFenceHandleTypeFlagBits>(0);
    int fd = 0;
    operator VkImportFenceFdInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImportFenceFdInfoKHR*>(this);
    }
    operator VkImportFenceFdInfoKHR &() noexcept {
        return *reinterpret_cast<VkImportFenceFdInfoKHR*>(this);
    }
};
struct FenceGetFdInfoKHR {
    StructureType sType = StructureType::eFenceGetFdInfoKHR;
    const void* pNext = nullptr;
    Fence fence;
    ExternalFenceHandleTypeFlagBits handleType = static_cast<ExternalFenceHandleTypeFlagBits>(0);
    operator VkFenceGetFdInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkFenceGetFdInfoKHR*>(this);
    }
    operator VkFenceGetFdInfoKHR &() noexcept {
        return *reinterpret_cast<VkFenceGetFdInfoKHR*>(this);
    }
};
struct PhysicalDeviceMultiviewFeatures {
    StructureType sType = StructureType::ePhysicalDeviceMultiviewFeatures;
    void* pNext = nullptr;
    bool multiview = false;
    bool multiviewGeometryShader = false;
    bool multiviewTessellationShader = false;
    operator VkPhysicalDeviceMultiviewFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(this);
    }
    operator VkPhysicalDeviceMultiviewFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMultiviewFeatures*>(this);
    }
};
using PhysicalDeviceMultiviewFeaturesKHR = PhysicalDeviceMultiviewFeatures;
struct PhysicalDeviceMultiviewProperties {
    StructureType sType = StructureType::ePhysicalDeviceMultiviewProperties;
    void* pNext = nullptr;
    uint32_t maxMultiviewViewCount = 0;
    uint32_t maxMultiviewInstanceIndex = 0;
    operator VkPhysicalDeviceMultiviewProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(this);
    }
    operator VkPhysicalDeviceMultiviewProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMultiviewProperties*>(this);
    }
};
using PhysicalDeviceMultiviewPropertiesKHR = PhysicalDeviceMultiviewProperties;
struct RenderPassMultiviewCreateInfo {
    StructureType sType = StructureType::eRenderPassMultiviewCreateInfo;
    const void* pNext = nullptr;
    uint32_t subpassCount = 0;
    const uint32_t* pViewMasks = nullptr;
    uint32_t dependencyCount = 0;
    const int32_t* pViewOffsets = nullptr;
    uint32_t correlationMaskCount = 0;
    const uint32_t* pCorrelationMasks = nullptr;
    operator VkRenderPassMultiviewCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(this);
    }
    operator VkRenderPassMultiviewCreateInfo &() noexcept {
        return *reinterpret_cast<VkRenderPassMultiviewCreateInfo*>(this);
    }
};
using RenderPassMultiviewCreateInfoKHR = RenderPassMultiviewCreateInfo;
struct SurfaceCapabilities2EXT {
    StructureType sType = StructureType::eSurfaceCapabilities2EXT;
    void* pNext = nullptr;
    uint32_t minImageCount = 0;
    uint32_t maxImageCount = 0;
    Extent2D currentExtent;
    Extent2D minImageExtent;
    Extent2D maxImageExtent;
    uint32_t maxImageArrayLayers = 0;
    SurfaceTransformFlagsKHR supportedTransforms = static_cast<SurfaceTransformFlagsKHR>(0);
    SurfaceTransformFlagBitsKHR currentTransform = static_cast<SurfaceTransformFlagBitsKHR>(0);
    CompositeAlphaFlagsKHR supportedCompositeAlpha = static_cast<CompositeAlphaFlagsKHR>(0);
    ImageUsageFlags supportedUsageFlags = static_cast<ImageUsageFlags>(0);
    SurfaceCounterFlagsEXT supportedSurfaceCounters = static_cast<SurfaceCounterFlagsEXT>(0);
    operator VkSurfaceCapabilities2EXT const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceCapabilities2EXT*>(this);
    }
    operator VkSurfaceCapabilities2EXT &() noexcept {
        return *reinterpret_cast<VkSurfaceCapabilities2EXT*>(this);
    }
};
struct DisplayPowerInfoEXT {
    StructureType sType = StructureType::eDisplayPowerInfoEXT;
    const void* pNext = nullptr;
    DisplayPowerStateEXT powerState = static_cast<DisplayPowerStateEXT>(0);
    operator VkDisplayPowerInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPowerInfoEXT*>(this);
    }
    operator VkDisplayPowerInfoEXT &() noexcept {
        return *reinterpret_cast<VkDisplayPowerInfoEXT*>(this);
    }
};
struct DeviceEventInfoEXT {
    StructureType sType = StructureType::eDeviceEventInfoEXT;
    const void* pNext = nullptr;
    DeviceEventTypeEXT deviceEvent = static_cast<DeviceEventTypeEXT>(0);
    operator VkDeviceEventInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDeviceEventInfoEXT*>(this);
    }
    operator VkDeviceEventInfoEXT &() noexcept {
        return *reinterpret_cast<VkDeviceEventInfoEXT*>(this);
    }
};
struct DisplayEventInfoEXT {
    StructureType sType = StructureType::eDisplayEventInfoEXT;
    const void* pNext = nullptr;
    DisplayEventTypeEXT displayEvent = static_cast<DisplayEventTypeEXT>(0);
    operator VkDisplayEventInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDisplayEventInfoEXT*>(this);
    }
    operator VkDisplayEventInfoEXT &() noexcept {
        return *reinterpret_cast<VkDisplayEventInfoEXT*>(this);
    }
};
struct SwapchainCounterCreateInfoEXT {
    StructureType sType = StructureType::eSwapchainCounterCreateInfoEXT;
    const void* pNext = nullptr;
    SurfaceCounterFlagsEXT surfaceCounters = static_cast<SurfaceCounterFlagsEXT>(0);
    operator VkSwapchainCounterCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(this);
    }
    operator VkSwapchainCounterCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkSwapchainCounterCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceGroupProperties {
    StructureType sType = StructureType::ePhysicalDeviceGroupProperties;
    void* pNext = nullptr;
    uint32_t physicalDeviceCount = 0;
    PhysicalDevice physicalDevices[MAX_DEVICE_GROUP_SIZE];
    bool subsetAllocation = false;
    operator VkPhysicalDeviceGroupProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(this);
    }
    operator VkPhysicalDeviceGroupProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceGroupProperties*>(this);
    }
};
using PhysicalDeviceGroupPropertiesKHR = PhysicalDeviceGroupProperties;
struct MemoryAllocateFlagsInfo {
    StructureType sType = StructureType::eMemoryAllocateFlagsInfo;
    const void* pNext = nullptr;
    MemoryAllocateFlags flags = static_cast<MemoryAllocateFlags>(0);
    uint32_t deviceMask = 0;
    operator VkMemoryAllocateFlagsInfo const &() const noexcept {
        return *reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(this);
    }
    operator VkMemoryAllocateFlagsInfo &() noexcept {
        return *reinterpret_cast<VkMemoryAllocateFlagsInfo*>(this);
    }
};
using MemoryAllocateFlagsInfoKHR = MemoryAllocateFlagsInfo;
struct BindBufferMemoryInfo {
    StructureType sType = StructureType::eBindBufferMemoryInfo;
    const void* pNext = nullptr;
    Buffer buffer;
    DeviceMemory memory;
    DeviceSize memoryOffset = 0;
    operator VkBindBufferMemoryInfo const &() const noexcept {
        return *reinterpret_cast<const VkBindBufferMemoryInfo*>(this);
    }
    operator VkBindBufferMemoryInfo &() noexcept {
        return *reinterpret_cast<VkBindBufferMemoryInfo*>(this);
    }
};
using BindBufferMemoryInfoKHR = BindBufferMemoryInfo;
struct BindBufferMemoryDeviceGroupInfo {
    StructureType sType = StructureType::eBindBufferMemoryDeviceGroupInfo;
    const void* pNext = nullptr;
    uint32_t deviceIndexCount = 0;
    const uint32_t* pDeviceIndices = nullptr;
    operator VkBindBufferMemoryDeviceGroupInfo const &() const noexcept {
        return *reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(this);
    }
    operator VkBindBufferMemoryDeviceGroupInfo &() noexcept {
        return *reinterpret_cast<VkBindBufferMemoryDeviceGroupInfo*>(this);
    }
};
using BindBufferMemoryDeviceGroupInfoKHR = BindBufferMemoryDeviceGroupInfo;
struct BindImageMemoryInfo {
    StructureType sType = StructureType::eBindImageMemoryInfo;
    const void* pNext = nullptr;
    Image image;
    DeviceMemory memory;
    DeviceSize memoryOffset = 0;
    operator VkBindImageMemoryInfo const &() const noexcept {
        return *reinterpret_cast<const VkBindImageMemoryInfo*>(this);
    }
    operator VkBindImageMemoryInfo &() noexcept {
        return *reinterpret_cast<VkBindImageMemoryInfo*>(this);
    }
};
using BindImageMemoryInfoKHR = BindImageMemoryInfo;
struct BindImageMemoryDeviceGroupInfo {
    StructureType sType = StructureType::eBindImageMemoryDeviceGroupInfo;
    const void* pNext = nullptr;
    uint32_t deviceIndexCount = 0;
    const uint32_t* pDeviceIndices = nullptr;
    uint32_t splitInstanceBindRegionCount = 0;
    const Rect2D* pSplitInstanceBindRegions = nullptr;
    operator VkBindImageMemoryDeviceGroupInfo const &() const noexcept {
        return *reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(this);
    }
    operator VkBindImageMemoryDeviceGroupInfo &() noexcept {
        return *reinterpret_cast<VkBindImageMemoryDeviceGroupInfo*>(this);
    }
};
using BindImageMemoryDeviceGroupInfoKHR = BindImageMemoryDeviceGroupInfo;
struct DeviceGroupRenderPassBeginInfo {
    StructureType sType = StructureType::eDeviceGroupRenderPassBeginInfo;
    const void* pNext = nullptr;
    uint32_t deviceMask = 0;
    uint32_t deviceRenderAreaCount = 0;
    const Rect2D* pDeviceRenderAreas = nullptr;
    operator VkDeviceGroupRenderPassBeginInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(this);
    }
    operator VkDeviceGroupRenderPassBeginInfo &() noexcept {
        return *reinterpret_cast<VkDeviceGroupRenderPassBeginInfo*>(this);
    }
};
using DeviceGroupRenderPassBeginInfoKHR = DeviceGroupRenderPassBeginInfo;
struct DeviceGroupCommandBufferBeginInfo {
    StructureType sType = StructureType::eDeviceGroupCommandBufferBeginInfo;
    const void* pNext = nullptr;
    uint32_t deviceMask = 0;
    operator VkDeviceGroupCommandBufferBeginInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(this);
    }
    operator VkDeviceGroupCommandBufferBeginInfo &() noexcept {
        return *reinterpret_cast<VkDeviceGroupCommandBufferBeginInfo*>(this);
    }
};
using DeviceGroupCommandBufferBeginInfoKHR = DeviceGroupCommandBufferBeginInfo;
struct DeviceGroupSubmitInfo {
    StructureType sType = StructureType::eDeviceGroupSubmitInfo;
    const void* pNext = nullptr;
    uint32_t waitSemaphoreCount = 0;
    const uint32_t* pWaitSemaphoreDeviceIndices = nullptr;
    uint32_t commandBufferCount = 0;
    const uint32_t* pCommandBufferDeviceMasks = nullptr;
    uint32_t signalSemaphoreCount = 0;
    const uint32_t* pSignalSemaphoreDeviceIndices = nullptr;
    operator VkDeviceGroupSubmitInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupSubmitInfo*>(this);
    }
    operator VkDeviceGroupSubmitInfo &() noexcept {
        return *reinterpret_cast<VkDeviceGroupSubmitInfo*>(this);
    }
};
using DeviceGroupSubmitInfoKHR = DeviceGroupSubmitInfo;
struct DeviceGroupBindSparseInfo {
    StructureType sType = StructureType::eDeviceGroupBindSparseInfo;
    const void* pNext = nullptr;
    uint32_t resourceDeviceIndex = 0;
    uint32_t memoryDeviceIndex = 0;
    operator VkDeviceGroupBindSparseInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(this);
    }
    operator VkDeviceGroupBindSparseInfo &() noexcept {
        return *reinterpret_cast<VkDeviceGroupBindSparseInfo*>(this);
    }
};
using DeviceGroupBindSparseInfoKHR = DeviceGroupBindSparseInfo;
struct DeviceGroupPresentCapabilitiesKHR {
    StructureType sType = StructureType::eDeviceGroupPresentCapabilitiesKHR;
    const void* pNext = nullptr;
    uint32_t presentMask[MAX_DEVICE_GROUP_SIZE] = {};
    DeviceGroupPresentModeFlagsKHR modes = static_cast<DeviceGroupPresentModeFlagsKHR>(0);
    operator VkDeviceGroupPresentCapabilitiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(this);
    }
    operator VkDeviceGroupPresentCapabilitiesKHR &() noexcept {
        return *reinterpret_cast<VkDeviceGroupPresentCapabilitiesKHR*>(this);
    }
};
struct ImageSwapchainCreateInfoKHR {
    StructureType sType = StructureType::eImageSwapchainCreateInfoKHR;
    const void* pNext = nullptr;
    SwapchainKHR swapchain;
    operator VkImageSwapchainCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(this);
    }
    operator VkImageSwapchainCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkImageSwapchainCreateInfoKHR*>(this);
    }
};
struct BindImageMemorySwapchainInfoKHR {
    StructureType sType = StructureType::eBindImageMemorySwapchainInfoKHR;
    const void* pNext = nullptr;
    SwapchainKHR swapchain;
    uint32_t imageIndex = 0;
    operator VkBindImageMemorySwapchainInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(this);
    }
    operator VkBindImageMemorySwapchainInfoKHR &() noexcept {
        return *reinterpret_cast<VkBindImageMemorySwapchainInfoKHR*>(this);
    }
};
struct AcquireNextImageInfoKHR {
    StructureType sType = StructureType::eAcquireNextImageInfoKHR;
    const void* pNext = nullptr;
    SwapchainKHR swapchain;
    uint64_t timeout = 0;
    Semaphore semaphore;
    Fence fence;
    uint32_t deviceMask = 0;
    operator VkAcquireNextImageInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAcquireNextImageInfoKHR*>(this);
    }
    operator VkAcquireNextImageInfoKHR &() noexcept {
        return *reinterpret_cast<VkAcquireNextImageInfoKHR*>(this);
    }
};
struct DeviceGroupPresentInfoKHR {
    StructureType sType = StructureType::eDeviceGroupPresentInfoKHR;
    const void* pNext = nullptr;
    uint32_t swapchainCount = 0;
    const uint32_t* pDeviceMasks = nullptr;
    DeviceGroupPresentModeFlagBitsKHR mode = static_cast<DeviceGroupPresentModeFlagBitsKHR>(0);
    operator VkDeviceGroupPresentInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(this);
    }
    operator VkDeviceGroupPresentInfoKHR &() noexcept {
        return *reinterpret_cast<VkDeviceGroupPresentInfoKHR*>(this);
    }
};
struct DeviceGroupDeviceCreateInfo {
    StructureType sType = StructureType::eDeviceGroupDeviceCreateInfo;
    const void* pNext = nullptr;
    uint32_t physicalDeviceCount = 0;
    const PhysicalDevice* pPhysicalDevices = nullptr;
    operator VkDeviceGroupDeviceCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(this);
    }
    operator VkDeviceGroupDeviceCreateInfo &() noexcept {
        return *reinterpret_cast<VkDeviceGroupDeviceCreateInfo*>(this);
    }
};
using DeviceGroupDeviceCreateInfoKHR = DeviceGroupDeviceCreateInfo;
struct DeviceGroupSwapchainCreateInfoKHR {
    StructureType sType = StructureType::eDeviceGroupSwapchainCreateInfoKHR;
    const void* pNext = nullptr;
    DeviceGroupPresentModeFlagsKHR modes = static_cast<DeviceGroupPresentModeFlagsKHR>(0);
    operator VkDeviceGroupSwapchainCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(this);
    }
    operator VkDeviceGroupSwapchainCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkDeviceGroupSwapchainCreateInfoKHR*>(this);
    }
};
struct DescriptorUpdateTemplateEntry {
    uint32_t dstBinding = 0;
    uint32_t dstArrayElement = 0;
    uint32_t descriptorCount = 0;
    DescriptorType descriptorType = static_cast<DescriptorType>(0);
    size_t offset = 0;
    size_t stride = 0;
    operator VkDescriptorUpdateTemplateEntry const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorUpdateTemplateEntry*>(this);
    }
    operator VkDescriptorUpdateTemplateEntry &() noexcept {
        return *reinterpret_cast<VkDescriptorUpdateTemplateEntry*>(this);
    }
};
using DescriptorUpdateTemplateEntryKHR = DescriptorUpdateTemplateEntry;
struct DescriptorUpdateTemplateCreateInfo {
    StructureType sType = StructureType::eDescriptorUpdateTemplateCreateInfo;
    const void* pNext = nullptr;
    DescriptorUpdateTemplateCreateFlags flags = static_cast<DescriptorUpdateTemplateCreateFlags>(0);
    uint32_t descriptorUpdateEntryCount = 0;
    const DescriptorUpdateTemplateEntry* pDescriptorUpdateEntries = nullptr;
    DescriptorUpdateTemplateType templateType = static_cast<DescriptorUpdateTemplateType>(0);
    DescriptorSetLayout descriptorSetLayout;
    PipelineBindPoint pipelineBindPoint = static_cast<PipelineBindPoint>(0);
    PipelineLayout pipelineLayout;
    uint32_t set = 0;
    operator VkDescriptorUpdateTemplateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(this);
    }
    operator VkDescriptorUpdateTemplateCreateInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorUpdateTemplateCreateInfo*>(this);
    }
};
using DescriptorUpdateTemplateCreateInfoKHR = DescriptorUpdateTemplateCreateInfo;
struct XYColorEXT {
    float x = 0.f;
    float y = 0.f;
    operator VkXYColorEXT const &() const noexcept {
        return *reinterpret_cast<const VkXYColorEXT*>(this);
    }
    operator VkXYColorEXT &() noexcept {
        return *reinterpret_cast<VkXYColorEXT*>(this);
    }
};
struct HdrMetadataEXT {
    StructureType sType = StructureType::eHdrMetadataEXT;
    const void* pNext = nullptr;
    XYColorEXT displayPrimaryRed;
    XYColorEXT displayPrimaryGreen;
    XYColorEXT displayPrimaryBlue;
    XYColorEXT whitePoint;
    float maxLuminance = 0.f;
    float minLuminance = 0.f;
    float maxContentLightLevel = 0.f;
    float maxFrameAverageLightLevel = 0.f;
    operator VkHdrMetadataEXT const &() const noexcept {
        return *reinterpret_cast<const VkHdrMetadataEXT*>(this);
    }
    operator VkHdrMetadataEXT &() noexcept {
        return *reinterpret_cast<VkHdrMetadataEXT*>(this);
    }
};
struct DisplayNativeHdrSurfaceCapabilitiesAMD {
    StructureType sType = StructureType::eDisplayNativeHdrSurfaceCapabilitiesAMD;
    void* pNext = nullptr;
    bool localDimmingSupport = false;
    operator VkDisplayNativeHdrSurfaceCapabilitiesAMD const &() const noexcept {
        return *reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(this);
    }
    operator VkDisplayNativeHdrSurfaceCapabilitiesAMD &() noexcept {
        return *reinterpret_cast<VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(this);
    }
};
struct SwapchainDisplayNativeHdrCreateInfoAMD {
    StructureType sType = StructureType::eSwapchainDisplayNativeHdrCreateInfoAMD;
    const void* pNext = nullptr;
    bool localDimmingEnable = false;
    operator VkSwapchainDisplayNativeHdrCreateInfoAMD const &() const noexcept {
        return *reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(this);
    }
    operator VkSwapchainDisplayNativeHdrCreateInfoAMD &() noexcept {
        return *reinterpret_cast<VkSwapchainDisplayNativeHdrCreateInfoAMD*>(this);
    }
};
struct RefreshCycleDurationGOOGLE {
    uint64_t refreshDuration = 0;
    operator VkRefreshCycleDurationGOOGLE const &() const noexcept {
        return *reinterpret_cast<const VkRefreshCycleDurationGOOGLE*>(this);
    }
    operator VkRefreshCycleDurationGOOGLE &() noexcept {
        return *reinterpret_cast<VkRefreshCycleDurationGOOGLE*>(this);
    }
};
struct PastPresentationTimingGOOGLE {
    uint32_t presentID = 0;
    uint64_t desiredPresentTime = 0;
    uint64_t actualPresentTime = 0;
    uint64_t earliestPresentTime = 0;
    uint64_t presentMargin = 0;
    operator VkPastPresentationTimingGOOGLE const &() const noexcept {
        return *reinterpret_cast<const VkPastPresentationTimingGOOGLE*>(this);
    }
    operator VkPastPresentationTimingGOOGLE &() noexcept {
        return *reinterpret_cast<VkPastPresentationTimingGOOGLE*>(this);
    }
};
struct PresentTimeGOOGLE {
    uint32_t presentID = 0;
    uint64_t desiredPresentTime = 0;
    operator VkPresentTimeGOOGLE const &() const noexcept {
        return *reinterpret_cast<const VkPresentTimeGOOGLE*>(this);
    }
    operator VkPresentTimeGOOGLE &() noexcept {
        return *reinterpret_cast<VkPresentTimeGOOGLE*>(this);
    }
};
struct PresentTimesInfoGOOGLE {
    StructureType sType = StructureType::ePresentTimesInfoGOOGLE;
    const void* pNext = nullptr;
    uint32_t swapchainCount = 0;
    const PresentTimeGOOGLE* pTimes = nullptr;
    operator VkPresentTimesInfoGOOGLE const &() const noexcept {
        return *reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(this);
    }
    operator VkPresentTimesInfoGOOGLE &() noexcept {
        return *reinterpret_cast<VkPresentTimesInfoGOOGLE*>(this);
    }
};
#if defined(VK_USE_PLATFORM_IOS_MVK)
struct IOSSurfaceCreateInfoMVK {
    StructureType sType = StructureType::eIosSurfaceCreateInfoMVK;
    const void* pNext = nullptr;
    IOSSurfaceCreateFlagsMVK flags = static_cast<IOSSurfaceCreateFlagsMVK>(0);
    const void* pView = nullptr;
    operator VkIOSSurfaceCreateInfoMVK const &() const noexcept {
        return *reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(this);
    }
    operator VkIOSSurfaceCreateInfoMVK &() noexcept {
        return *reinterpret_cast<VkIOSSurfaceCreateInfoMVK*>(this);
    }
};
#endif // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
struct MacOSSurfaceCreateInfoMVK {
    StructureType sType = StructureType::eMacosSurfaceCreateInfoMVK;
    const void* pNext = nullptr;
    MacOSSurfaceCreateFlagsMVK flags = static_cast<MacOSSurfaceCreateFlagsMVK>(0);
    const void* pView = nullptr;
    operator VkMacOSSurfaceCreateInfoMVK const &() const noexcept {
        return *reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(this);
    }
    operator VkMacOSSurfaceCreateInfoMVK &() noexcept {
        return *reinterpret_cast<VkMacOSSurfaceCreateInfoMVK*>(this);
    }
};
#endif // VK_USE_PLATFORM_MACOS_MVK
#if defined(VK_USE_PLATFORM_METAL_EXT)
struct MetalSurfaceCreateInfoEXT {
    StructureType sType = StructureType::eMetalSurfaceCreateInfoEXT;
    const void* pNext = nullptr;
    MetalSurfaceCreateFlagsEXT flags = static_cast<MetalSurfaceCreateFlagsEXT>(0);
    const CAMetalLayer* pLayer = nullptr;
    operator VkMetalSurfaceCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkMetalSurfaceCreateInfoEXT*>(this);
    }
    operator VkMetalSurfaceCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkMetalSurfaceCreateInfoEXT*>(this);
    }
};
#endif // VK_USE_PLATFORM_METAL_EXT
struct ViewportWScalingNV {
    float xcoeff = 0.f;
    float ycoeff = 0.f;
    operator VkViewportWScalingNV const &() const noexcept {
        return *reinterpret_cast<const VkViewportWScalingNV*>(this);
    }
    operator VkViewportWScalingNV &() noexcept {
        return *reinterpret_cast<VkViewportWScalingNV*>(this);
    }
};
struct PipelineViewportWScalingStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineViewportWScalingStateCreateInfoNV;
    const void* pNext = nullptr;
    bool viewportWScalingEnable = false;
    uint32_t viewportCount = 0;
    const ViewportWScalingNV* pViewportWScalings = nullptr;
    operator VkPipelineViewportWScalingStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(this);
    }
    operator VkPipelineViewportWScalingStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineViewportWScalingStateCreateInfoNV*>(this);
    }
};
struct ViewportSwizzleNV {
    ViewportCoordinateSwizzleNV x = static_cast<ViewportCoordinateSwizzleNV>(0);
    ViewportCoordinateSwizzleNV y = static_cast<ViewportCoordinateSwizzleNV>(0);
    ViewportCoordinateSwizzleNV z = static_cast<ViewportCoordinateSwizzleNV>(0);
    ViewportCoordinateSwizzleNV w = static_cast<ViewportCoordinateSwizzleNV>(0);
    operator VkViewportSwizzleNV const &() const noexcept {
        return *reinterpret_cast<const VkViewportSwizzleNV*>(this);
    }
    operator VkViewportSwizzleNV &() noexcept {
        return *reinterpret_cast<VkViewportSwizzleNV*>(this);
    }
};
struct PipelineViewportSwizzleStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineViewportSwizzleStateCreateInfoNV;
    const void* pNext = nullptr;
    PipelineViewportSwizzleStateCreateFlagsNV flags = static_cast<PipelineViewportSwizzleStateCreateFlagsNV>(0);
    uint32_t viewportCount = 0;
    const ViewportSwizzleNV* pViewportSwizzles = nullptr;
    operator VkPipelineViewportSwizzleStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(this);
    }
    operator VkPipelineViewportSwizzleStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineViewportSwizzleStateCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceDiscardRectanglePropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceDiscardRectanglePropertiesEXT;
    void* pNext = nullptr;
    uint32_t maxDiscardRectangles = 0;
    operator VkPhysicalDeviceDiscardRectanglePropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceDiscardRectanglePropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(this);
    }
};
struct PipelineDiscardRectangleStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineDiscardRectangleStateCreateInfoEXT;
    const void* pNext = nullptr;
    PipelineDiscardRectangleStateCreateFlagsEXT flags = static_cast<PipelineDiscardRectangleStateCreateFlagsEXT>(0);
    DiscardRectangleModeEXT discardRectangleMode = static_cast<DiscardRectangleModeEXT>(0);
    uint32_t discardRectangleCount = 0;
    const Rect2D* pDiscardRectangles = nullptr;
    operator VkPipelineDiscardRectangleStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(this);
    }
    operator VkPipelineDiscardRectangleStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineDiscardRectangleStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX {
    StructureType sType = StructureType::ePhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
    void* pNext = nullptr;
    bool perViewPositionAllComponents = false;
    operator VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(this);
    }
    operator VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(this);
    }
};
struct InputAttachmentAspectReference {
    uint32_t subpass = 0;
    uint32_t inputAttachmentIndex = 0;
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    operator VkInputAttachmentAspectReference const &() const noexcept {
        return *reinterpret_cast<const VkInputAttachmentAspectReference*>(this);
    }
    operator VkInputAttachmentAspectReference &() noexcept {
        return *reinterpret_cast<VkInputAttachmentAspectReference*>(this);
    }
};
using InputAttachmentAspectReferenceKHR = InputAttachmentAspectReference;
struct RenderPassInputAttachmentAspectCreateInfo {
    StructureType sType = StructureType::eRenderPassInputAttachmentAspectCreateInfo;
    const void* pNext = nullptr;
    uint32_t aspectReferenceCount = 0;
    const InputAttachmentAspectReference* pAspectReferences = nullptr;
    operator VkRenderPassInputAttachmentAspectCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(this);
    }
    operator VkRenderPassInputAttachmentAspectCreateInfo &() noexcept {
        return *reinterpret_cast<VkRenderPassInputAttachmentAspectCreateInfo*>(this);
    }
};
using RenderPassInputAttachmentAspectCreateInfoKHR = RenderPassInputAttachmentAspectCreateInfo;
struct PhysicalDeviceSurfaceInfo2KHR {
    StructureType sType = StructureType::ePhysicalDeviceSurfaceInfo2KHR;
    const void* pNext = nullptr;
    SurfaceKHR surface;
    operator VkPhysicalDeviceSurfaceInfo2KHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(this);
    }
    operator VkPhysicalDeviceSurfaceInfo2KHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSurfaceInfo2KHR*>(this);
    }
};
struct SurfaceCapabilities2KHR {
    StructureType sType = StructureType::eSurfaceCapabilities2KHR;
    void* pNext = nullptr;
    SurfaceCapabilitiesKHR surfaceCapabilities;
    operator VkSurfaceCapabilities2KHR const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceCapabilities2KHR*>(this);
    }
    operator VkSurfaceCapabilities2KHR &() noexcept {
        return *reinterpret_cast<VkSurfaceCapabilities2KHR*>(this);
    }
};
struct SurfaceFormat2KHR {
    StructureType sType = StructureType::eSurfaceFormat2KHR;
    void* pNext = nullptr;
    SurfaceFormatKHR surfaceFormat;
    operator VkSurfaceFormat2KHR const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceFormat2KHR*>(this);
    }
    operator VkSurfaceFormat2KHR &() noexcept {
        return *reinterpret_cast<VkSurfaceFormat2KHR*>(this);
    }
};
struct DisplayProperties2KHR {
    StructureType sType = StructureType::eDisplayProperties2KHR;
    void* pNext = nullptr;
    DisplayPropertiesKHR displayProperties;
    operator VkDisplayProperties2KHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayProperties2KHR*>(this);
    }
    operator VkDisplayProperties2KHR &() noexcept {
        return *reinterpret_cast<VkDisplayProperties2KHR*>(this);
    }
};
struct DisplayPlaneProperties2KHR {
    StructureType sType = StructureType::eDisplayPlaneProperties2KHR;
    void* pNext = nullptr;
    DisplayPlanePropertiesKHR displayPlaneProperties;
    operator VkDisplayPlaneProperties2KHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(this);
    }
    operator VkDisplayPlaneProperties2KHR &() noexcept {
        return *reinterpret_cast<VkDisplayPlaneProperties2KHR*>(this);
    }
};
struct DisplayModeProperties2KHR {
    StructureType sType = StructureType::eDisplayModeProperties2KHR;
    void* pNext = nullptr;
    DisplayModePropertiesKHR displayModeProperties;
    operator VkDisplayModeProperties2KHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayModeProperties2KHR*>(this);
    }
    operator VkDisplayModeProperties2KHR &() noexcept {
        return *reinterpret_cast<VkDisplayModeProperties2KHR*>(this);
    }
};
struct DisplayPlaneInfo2KHR {
    StructureType sType = StructureType::eDisplayPlaneInfo2KHR;
    const void* pNext = nullptr;
    DisplayModeKHR mode;
    uint32_t planeIndex = 0;
    operator VkDisplayPlaneInfo2KHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(this);
    }
    operator VkDisplayPlaneInfo2KHR &() noexcept {
        return *reinterpret_cast<VkDisplayPlaneInfo2KHR*>(this);
    }
};
struct DisplayPlaneCapabilities2KHR {
    StructureType sType = StructureType::eDisplayPlaneCapabilities2KHR;
    void* pNext = nullptr;
    DisplayPlaneCapabilitiesKHR capabilities;
    operator VkDisplayPlaneCapabilities2KHR const &() const noexcept {
        return *reinterpret_cast<const VkDisplayPlaneCapabilities2KHR*>(this);
    }
    operator VkDisplayPlaneCapabilities2KHR &() noexcept {
        return *reinterpret_cast<VkDisplayPlaneCapabilities2KHR*>(this);
    }
};
struct SharedPresentSurfaceCapabilitiesKHR {
    StructureType sType = StructureType::eSharedPresentSurfaceCapabilitiesKHR;
    void* pNext = nullptr;
    ImageUsageFlags sharedPresentSupportedUsageFlags = static_cast<ImageUsageFlags>(0);
    operator VkSharedPresentSurfaceCapabilitiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(this);
    }
    operator VkSharedPresentSurfaceCapabilitiesKHR &() noexcept {
        return *reinterpret_cast<VkSharedPresentSurfaceCapabilitiesKHR*>(this);
    }
};
struct PhysicalDevice16BitStorageFeatures {
    StructureType sType = StructureType::ePhysicalDevice16BitStorageFeatures;
    void* pNext = nullptr;
    bool storageBuffer16BitAccess = false;
    bool uniformAndStorageBuffer16BitAccess = false;
    bool storagePushConstant16 = false;
    bool storageInputOutput16 = false;
    operator VkPhysicalDevice16BitStorageFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(this);
    }
    operator VkPhysicalDevice16BitStorageFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDevice16BitStorageFeatures*>(this);
    }
};
using PhysicalDevice16BitStorageFeaturesKHR = PhysicalDevice16BitStorageFeatures;
struct PhysicalDeviceSubgroupProperties {
    StructureType sType = StructureType::ePhysicalDeviceSubgroupProperties;
    void* pNext = nullptr;
    uint32_t subgroupSize = 0;
    ShaderStageFlags supportedStages = static_cast<ShaderStageFlags>(0);
    SubgroupFeatureFlags supportedOperations = static_cast<SubgroupFeatureFlags>(0);
    bool quadOperationsInAllStages = false;
    operator VkPhysicalDeviceSubgroupProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(this);
    }
    operator VkPhysicalDeviceSubgroupProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSubgroupProperties*>(this);
    }
};
struct PhysicalDeviceShaderSubgroupExtendedTypesFeatures {
    StructureType sType = StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeatures;
    void* pNext = nullptr;
    bool shaderSubgroupExtendedTypes = false;
    operator VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(this);
    }
    operator VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(this);
    }
};
using PhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR = PhysicalDeviceShaderSubgroupExtendedTypesFeatures;
struct BufferMemoryRequirementsInfo2 {
    StructureType sType = StructureType::eBufferMemoryRequirementsInfo2;
    const void* pNext = nullptr;
    Buffer buffer;
    operator VkBufferMemoryRequirementsInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(this);
    }
    operator VkBufferMemoryRequirementsInfo2 &() noexcept {
        return *reinterpret_cast<VkBufferMemoryRequirementsInfo2*>(this);
    }
};
using BufferMemoryRequirementsInfo2KHR = BufferMemoryRequirementsInfo2;
struct ImageMemoryRequirementsInfo2 {
    StructureType sType = StructureType::eImageMemoryRequirementsInfo2;
    const void* pNext = nullptr;
    Image image;
    operator VkImageMemoryRequirementsInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(this);
    }
    operator VkImageMemoryRequirementsInfo2 &() noexcept {
        return *reinterpret_cast<VkImageMemoryRequirementsInfo2*>(this);
    }
};
using ImageMemoryRequirementsInfo2KHR = ImageMemoryRequirementsInfo2;
struct ImageSparseMemoryRequirementsInfo2 {
    StructureType sType = StructureType::eImageSparseMemoryRequirementsInfo2;
    const void* pNext = nullptr;
    Image image;
    operator VkImageSparseMemoryRequirementsInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(this);
    }
    operator VkImageSparseMemoryRequirementsInfo2 &() noexcept {
        return *reinterpret_cast<VkImageSparseMemoryRequirementsInfo2*>(this);
    }
};
using ImageSparseMemoryRequirementsInfo2KHR = ImageSparseMemoryRequirementsInfo2;
struct MemoryRequirements2 {
    StructureType sType = StructureType::eMemoryRequirements2;
    void* pNext = nullptr;
    MemoryRequirements memoryRequirements;
    operator VkMemoryRequirements2 const &() const noexcept {
        return *reinterpret_cast<const VkMemoryRequirements2*>(this);
    }
    operator VkMemoryRequirements2 &() noexcept {
        return *reinterpret_cast<VkMemoryRequirements2*>(this);
    }
};
using MemoryRequirements2KHR = MemoryRequirements2;
struct SparseImageMemoryRequirements2 {
    StructureType sType = StructureType::eSparseImageMemoryRequirements2;
    void* pNext = nullptr;
    SparseImageMemoryRequirements memoryRequirements;
    operator VkSparseImageMemoryRequirements2 const &() const noexcept {
        return *reinterpret_cast<const VkSparseImageMemoryRequirements2*>(this);
    }
    operator VkSparseImageMemoryRequirements2 &() noexcept {
        return *reinterpret_cast<VkSparseImageMemoryRequirements2*>(this);
    }
};
using SparseImageMemoryRequirements2KHR = SparseImageMemoryRequirements2;
struct PhysicalDevicePointClippingProperties {
    StructureType sType = StructureType::ePhysicalDevicePointClippingProperties;
    void* pNext = nullptr;
    PointClippingBehavior pointClippingBehavior = static_cast<PointClippingBehavior>(0);
    operator VkPhysicalDevicePointClippingProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(this);
    }
    operator VkPhysicalDevicePointClippingProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePointClippingProperties*>(this);
    }
};
using PhysicalDevicePointClippingPropertiesKHR = PhysicalDevicePointClippingProperties;
struct MemoryDedicatedRequirements {
    StructureType sType = StructureType::eMemoryDedicatedRequirements;
    void* pNext = nullptr;
    bool prefersDedicatedAllocation = false;
    bool requiresDedicatedAllocation = false;
    operator VkMemoryDedicatedRequirements const &() const noexcept {
        return *reinterpret_cast<const VkMemoryDedicatedRequirements*>(this);
    }
    operator VkMemoryDedicatedRequirements &() noexcept {
        return *reinterpret_cast<VkMemoryDedicatedRequirements*>(this);
    }
};
using MemoryDedicatedRequirementsKHR = MemoryDedicatedRequirements;
struct MemoryDedicatedAllocateInfo {
    StructureType sType = StructureType::eMemoryDedicatedAllocateInfo;
    const void* pNext = nullptr;
    Image image;
    Buffer buffer;
    operator VkMemoryDedicatedAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(this);
    }
    operator VkMemoryDedicatedAllocateInfo &() noexcept {
        return *reinterpret_cast<VkMemoryDedicatedAllocateInfo*>(this);
    }
};
using MemoryDedicatedAllocateInfoKHR = MemoryDedicatedAllocateInfo;
struct ImageViewUsageCreateInfo {
    StructureType sType = StructureType::eImageViewUsageCreateInfo;
    const void* pNext = nullptr;
    ImageUsageFlags usage = static_cast<ImageUsageFlags>(0);
    operator VkImageViewUsageCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkImageViewUsageCreateInfo*>(this);
    }
    operator VkImageViewUsageCreateInfo &() noexcept {
        return *reinterpret_cast<VkImageViewUsageCreateInfo*>(this);
    }
};
using ImageViewUsageCreateInfoKHR = ImageViewUsageCreateInfo;
struct PipelineTessellationDomainOriginStateCreateInfo {
    StructureType sType = StructureType::ePipelineTessellationDomainOriginStateCreateInfo;
    const void* pNext = nullptr;
    TessellationDomainOrigin domainOrigin = static_cast<TessellationDomainOrigin>(0);
    operator VkPipelineTessellationDomainOriginStateCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(this);
    }
    operator VkPipelineTessellationDomainOriginStateCreateInfo &() noexcept {
        return *reinterpret_cast<VkPipelineTessellationDomainOriginStateCreateInfo*>(this);
    }
};
using PipelineTessellationDomainOriginStateCreateInfoKHR = PipelineTessellationDomainOriginStateCreateInfo;
struct SamplerYcbcrConversionInfo {
    StructureType sType = StructureType::eSamplerYcbcrConversionInfo;
    const void* pNext = nullptr;
    SamplerYcbcrConversion conversion;
    operator VkSamplerYcbcrConversionInfo const &() const noexcept {
        return *reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(this);
    }
    operator VkSamplerYcbcrConversionInfo &() noexcept {
        return *reinterpret_cast<VkSamplerYcbcrConversionInfo*>(this);
    }
};
using SamplerYcbcrConversionInfoKHR = SamplerYcbcrConversionInfo;
struct SamplerYcbcrConversionCreateInfo {
    StructureType sType = StructureType::eSamplerYcbcrConversionCreateInfo;
    const void* pNext = nullptr;
    Format format = static_cast<Format>(0);
    SamplerYcbcrModelConversion ycbcrModel = static_cast<SamplerYcbcrModelConversion>(0);
    SamplerYcbcrRange ycbcrRange = static_cast<SamplerYcbcrRange>(0);
    ComponentMapping components;
    ChromaLocation xChromaOffset = static_cast<ChromaLocation>(0);
    ChromaLocation yChromaOffset = static_cast<ChromaLocation>(0);
    Filter chromaFilter = static_cast<Filter>(0);
    bool forceExplicitReconstruction = false;
    operator VkSamplerYcbcrConversionCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(this);
    }
    operator VkSamplerYcbcrConversionCreateInfo &() noexcept {
        return *reinterpret_cast<VkSamplerYcbcrConversionCreateInfo*>(this);
    }
};
using SamplerYcbcrConversionCreateInfoKHR = SamplerYcbcrConversionCreateInfo;
struct BindImagePlaneMemoryInfo {
    StructureType sType = StructureType::eBindImagePlaneMemoryInfo;
    const void* pNext = nullptr;
    ImageAspectFlagBits planeAspect = static_cast<ImageAspectFlagBits>(0);
    operator VkBindImagePlaneMemoryInfo const &() const noexcept {
        return *reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(this);
    }
    operator VkBindImagePlaneMemoryInfo &() noexcept {
        return *reinterpret_cast<VkBindImagePlaneMemoryInfo*>(this);
    }
};
using BindImagePlaneMemoryInfoKHR = BindImagePlaneMemoryInfo;
struct ImagePlaneMemoryRequirementsInfo {
    StructureType sType = StructureType::eImagePlaneMemoryRequirementsInfo;
    const void* pNext = nullptr;
    ImageAspectFlagBits planeAspect = static_cast<ImageAspectFlagBits>(0);
    operator VkImagePlaneMemoryRequirementsInfo const &() const noexcept {
        return *reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(this);
    }
    operator VkImagePlaneMemoryRequirementsInfo &() noexcept {
        return *reinterpret_cast<VkImagePlaneMemoryRequirementsInfo*>(this);
    }
};
using ImagePlaneMemoryRequirementsInfoKHR = ImagePlaneMemoryRequirementsInfo;
struct PhysicalDeviceSamplerYcbcrConversionFeatures {
    StructureType sType = StructureType::ePhysicalDeviceSamplerYcbcrConversionFeatures;
    void* pNext = nullptr;
    bool samplerYcbcrConversion = false;
    operator VkPhysicalDeviceSamplerYcbcrConversionFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(this);
    }
    operator VkPhysicalDeviceSamplerYcbcrConversionFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(this);
    }
};
using PhysicalDeviceSamplerYcbcrConversionFeaturesKHR = PhysicalDeviceSamplerYcbcrConversionFeatures;
struct SamplerYcbcrConversionImageFormatProperties {
    StructureType sType = StructureType::eSamplerYcbcrConversionImageFormatProperties;
    void* pNext = nullptr;
    uint32_t combinedImageSamplerDescriptorCount = 0;
    operator VkSamplerYcbcrConversionImageFormatProperties const &() const noexcept {
        return *reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(this);
    }
    operator VkSamplerYcbcrConversionImageFormatProperties &() noexcept {
        return *reinterpret_cast<VkSamplerYcbcrConversionImageFormatProperties*>(this);
    }
};
using SamplerYcbcrConversionImageFormatPropertiesKHR = SamplerYcbcrConversionImageFormatProperties;
struct TextureLODGatherFormatPropertiesAMD {
    StructureType sType = StructureType::eTextureLodGatherFormatPropertiesAMD;
    void* pNext = nullptr;
    bool supportsTextureGatherLODBiasAMD = false;
    operator VkTextureLODGatherFormatPropertiesAMD const &() const noexcept {
        return *reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(this);
    }
    operator VkTextureLODGatherFormatPropertiesAMD &() noexcept {
        return *reinterpret_cast<VkTextureLODGatherFormatPropertiesAMD*>(this);
    }
};
struct ConditionalRenderingBeginInfoEXT {
    StructureType sType = StructureType::eConditionalRenderingBeginInfoEXT;
    const void* pNext = nullptr;
    Buffer buffer;
    DeviceSize offset = 0;
    ConditionalRenderingFlagsEXT flags = static_cast<ConditionalRenderingFlagsEXT>(0);
    operator VkConditionalRenderingBeginInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(this);
    }
    operator VkConditionalRenderingBeginInfoEXT &() noexcept {
        return *reinterpret_cast<VkConditionalRenderingBeginInfoEXT*>(this);
    }
};
struct ProtectedSubmitInfo {
    StructureType sType = StructureType::eProtectedSubmitInfo;
    const void* pNext = nullptr;
    bool protectedSubmit = false;
    operator VkProtectedSubmitInfo const &() const noexcept {
        return *reinterpret_cast<const VkProtectedSubmitInfo*>(this);
    }
    operator VkProtectedSubmitInfo &() noexcept {
        return *reinterpret_cast<VkProtectedSubmitInfo*>(this);
    }
};
struct PhysicalDeviceProtectedMemoryFeatures {
    StructureType sType = StructureType::ePhysicalDeviceProtectedMemoryFeatures;
    void* pNext = nullptr;
    bool protectedMemory = false;
    operator VkPhysicalDeviceProtectedMemoryFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(this);
    }
    operator VkPhysicalDeviceProtectedMemoryFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceProtectedMemoryFeatures*>(this);
    }
};
struct PhysicalDeviceProtectedMemoryProperties {
    StructureType sType = StructureType::ePhysicalDeviceProtectedMemoryProperties;
    void* pNext = nullptr;
    bool protectedNoFault = false;
    operator VkPhysicalDeviceProtectedMemoryProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(this);
    }
    operator VkPhysicalDeviceProtectedMemoryProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceProtectedMemoryProperties*>(this);
    }
};
struct DeviceQueueInfo2 {
    StructureType sType = StructureType::eDeviceQueueInfo2;
    const void* pNext = nullptr;
    DeviceQueueCreateFlags flags = static_cast<DeviceQueueCreateFlags>(0);
    uint32_t queueFamilyIndex = 0;
    uint32_t queueIndex = 0;
    operator VkDeviceQueueInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkDeviceQueueInfo2*>(this);
    }
    operator VkDeviceQueueInfo2 &() noexcept {
        return *reinterpret_cast<VkDeviceQueueInfo2*>(this);
    }
};
struct PipelineCoverageToColorStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineCoverageToColorStateCreateInfoNV;
    const void* pNext = nullptr;
    PipelineCoverageToColorStateCreateFlagsNV flags = static_cast<PipelineCoverageToColorStateCreateFlagsNV>(0);
    bool coverageToColorEnable = false;
    uint32_t coverageToColorLocation = 0;
    operator VkPipelineCoverageToColorStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(this);
    }
    operator VkPipelineCoverageToColorStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineCoverageToColorStateCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceSamplerFilterMinmaxProperties {
    StructureType sType = StructureType::ePhysicalDeviceSamplerFilterMinmaxProperties;
    void* pNext = nullptr;
    bool filterMinmaxSingleComponentFormats = false;
    bool filterMinmaxImageComponentMapping = false;
    operator VkPhysicalDeviceSamplerFilterMinmaxProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(this);
    }
    operator VkPhysicalDeviceSamplerFilterMinmaxProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSamplerFilterMinmaxProperties*>(this);
    }
};
using PhysicalDeviceSamplerFilterMinmaxPropertiesEXT = PhysicalDeviceSamplerFilterMinmaxProperties;
struct SampleLocationEXT {
    float x = 0.f;
    float y = 0.f;
    operator VkSampleLocationEXT const &() const noexcept {
        return *reinterpret_cast<const VkSampleLocationEXT*>(this);
    }
    operator VkSampleLocationEXT &() noexcept {
        return *reinterpret_cast<VkSampleLocationEXT*>(this);
    }
};
struct SampleLocationsInfoEXT {
    StructureType sType = StructureType::eSampleLocationsInfoEXT;
    const void* pNext = nullptr;
    SampleCountFlagBits sampleLocationsPerPixel = static_cast<SampleCountFlagBits>(0);
    Extent2D sampleLocationGridSize;
    uint32_t sampleLocationsCount = 0;
    const SampleLocationEXT* pSampleLocations = nullptr;
    operator VkSampleLocationsInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkSampleLocationsInfoEXT*>(this);
    }
    operator VkSampleLocationsInfoEXT &() noexcept {
        return *reinterpret_cast<VkSampleLocationsInfoEXT*>(this);
    }
};
struct AttachmentSampleLocationsEXT {
    uint32_t attachmentIndex = 0;
    SampleLocationsInfoEXT sampleLocationsInfo;
    operator VkAttachmentSampleLocationsEXT const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentSampleLocationsEXT*>(this);
    }
    operator VkAttachmentSampleLocationsEXT &() noexcept {
        return *reinterpret_cast<VkAttachmentSampleLocationsEXT*>(this);
    }
};
struct SubpassSampleLocationsEXT {
    uint32_t subpassIndex = 0;
    SampleLocationsInfoEXT sampleLocationsInfo;
    operator VkSubpassSampleLocationsEXT const &() const noexcept {
        return *reinterpret_cast<const VkSubpassSampleLocationsEXT*>(this);
    }
    operator VkSubpassSampleLocationsEXT &() noexcept {
        return *reinterpret_cast<VkSubpassSampleLocationsEXT*>(this);
    }
};
struct RenderPassSampleLocationsBeginInfoEXT {
    StructureType sType = StructureType::eRenderPassSampleLocationsBeginInfoEXT;
    const void* pNext = nullptr;
    uint32_t attachmentInitialSampleLocationsCount = 0;
    const AttachmentSampleLocationsEXT* pAttachmentInitialSampleLocations = nullptr;
    uint32_t postSubpassSampleLocationsCount = 0;
    const SubpassSampleLocationsEXT* pPostSubpassSampleLocations = nullptr;
    operator VkRenderPassSampleLocationsBeginInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(this);
    }
    operator VkRenderPassSampleLocationsBeginInfoEXT &() noexcept {
        return *reinterpret_cast<VkRenderPassSampleLocationsBeginInfoEXT*>(this);
    }
};
struct PipelineSampleLocationsStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineSampleLocationsStateCreateInfoEXT;
    const void* pNext = nullptr;
    bool sampleLocationsEnable = false;
    SampleLocationsInfoEXT sampleLocationsInfo;
    operator VkPipelineSampleLocationsStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(this);
    }
    operator VkPipelineSampleLocationsStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineSampleLocationsStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceSampleLocationsPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceSampleLocationsPropertiesEXT;
    void* pNext = nullptr;
    SampleCountFlags sampleLocationSampleCounts = static_cast<SampleCountFlags>(0);
    Extent2D maxSampleLocationGridSize;
    float sampleLocationCoordinateRange[2] = {};
    uint32_t sampleLocationSubPixelBits = 0;
    bool variableSampleLocations = false;
    operator VkPhysicalDeviceSampleLocationsPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceSampleLocationsPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSampleLocationsPropertiesEXT*>(this);
    }
};
struct MultisamplePropertiesEXT {
    StructureType sType = StructureType::eMultisamplePropertiesEXT;
    void* pNext = nullptr;
    Extent2D maxSampleLocationGridSize;
    operator VkMultisamplePropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkMultisamplePropertiesEXT*>(this);
    }
    operator VkMultisamplePropertiesEXT &() noexcept {
        return *reinterpret_cast<VkMultisamplePropertiesEXT*>(this);
    }
};
struct SamplerReductionModeCreateInfo {
    StructureType sType = StructureType::eSamplerReductionModeCreateInfo;
    const void* pNext = nullptr;
    SamplerReductionMode reductionMode = static_cast<SamplerReductionMode>(0);
    operator VkSamplerReductionModeCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(this);
    }
    operator VkSamplerReductionModeCreateInfo &() noexcept {
        return *reinterpret_cast<VkSamplerReductionModeCreateInfo*>(this);
    }
};
using SamplerReductionModeCreateInfoEXT = SamplerReductionModeCreateInfo;
struct PhysicalDeviceBlendOperationAdvancedFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceBlendOperationAdvancedFeaturesEXT;
    void* pNext = nullptr;
    bool advancedBlendCoherentOperations = false;
    operator VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceBlendOperationAdvancedPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceBlendOperationAdvancedPropertiesEXT;
    void* pNext = nullptr;
    uint32_t advancedBlendMaxColorAttachments = 0;
    bool advancedBlendIndependentBlend = false;
    bool advancedBlendNonPremultipliedSrcColor = false;
    bool advancedBlendNonPremultipliedDstColor = false;
    bool advancedBlendCorrelatedOverlap = false;
    bool advancedBlendAllOperations = false;
    operator VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(this);
    }
};
struct PipelineColorBlendAdvancedStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineColorBlendAdvancedStateCreateInfoEXT;
    const void* pNext = nullptr;
    bool srcPremultiplied = false;
    bool dstPremultiplied = false;
    BlendOverlapEXT blendOverlap = static_cast<BlendOverlapEXT>(0);
    operator VkPipelineColorBlendAdvancedStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(this);
    }
    operator VkPipelineColorBlendAdvancedStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceInlineUniformBlockFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceInlineUniformBlockFeaturesEXT;
    void* pNext = nullptr;
    bool inlineUniformBlock = false;
    bool descriptorBindingInlineUniformBlockUpdateAfterBind = false;
    operator VkPhysicalDeviceInlineUniformBlockFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceInlineUniformBlockFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceInlineUniformBlockPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceInlineUniformBlockPropertiesEXT;
    void* pNext = nullptr;
    uint32_t maxInlineUniformBlockSize = 0;
    uint32_t maxPerStageDescriptorInlineUniformBlocks = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = 0;
    uint32_t maxDescriptorSetInlineUniformBlocks = 0;
    uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks = 0;
    operator VkPhysicalDeviceInlineUniformBlockPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceInlineUniformBlockPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(this);
    }
};
struct WriteDescriptorSetInlineUniformBlockEXT {
    StructureType sType = StructureType::eWriteDescriptorSetInlineUniformBlockEXT;
    const void* pNext = nullptr;
    uint32_t dataSize = 0;
    const void* pData = nullptr;
    operator VkWriteDescriptorSetInlineUniformBlockEXT const &() const noexcept {
        return *reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlockEXT*>(this);
    }
    operator VkWriteDescriptorSetInlineUniformBlockEXT &() noexcept {
        return *reinterpret_cast<VkWriteDescriptorSetInlineUniformBlockEXT*>(this);
    }
};
struct DescriptorPoolInlineUniformBlockCreateInfoEXT {
    StructureType sType = StructureType::eDescriptorPoolInlineUniformBlockCreateInfoEXT;
    const void* pNext = nullptr;
    uint32_t maxInlineUniformBlockBindings = 0;
    operator VkDescriptorPoolInlineUniformBlockCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(this);
    }
    operator VkDescriptorPoolInlineUniformBlockCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(this);
    }
};
struct PipelineCoverageModulationStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineCoverageModulationStateCreateInfoNV;
    const void* pNext = nullptr;
    PipelineCoverageModulationStateCreateFlagsNV flags = static_cast<PipelineCoverageModulationStateCreateFlagsNV>(0);
    CoverageModulationModeNV coverageModulationMode = static_cast<CoverageModulationModeNV>(0);
    bool coverageModulationTableEnable = false;
    uint32_t coverageModulationTableCount = 0;
    const float* pCoverageModulationTable = nullptr;
    operator VkPipelineCoverageModulationStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(this);
    }
    operator VkPipelineCoverageModulationStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineCoverageModulationStateCreateInfoNV*>(this);
    }
};
struct ImageFormatListCreateInfo {
    StructureType sType = StructureType::eImageFormatListCreateInfo;
    const void* pNext = nullptr;
    uint32_t viewFormatCount = 0;
    const Format* pViewFormats = nullptr;
    operator VkImageFormatListCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkImageFormatListCreateInfo*>(this);
    }
    operator VkImageFormatListCreateInfo &() noexcept {
        return *reinterpret_cast<VkImageFormatListCreateInfo*>(this);
    }
};
using ImageFormatListCreateInfoKHR = ImageFormatListCreateInfo;
struct ValidationCacheCreateInfoEXT {
    StructureType sType = StructureType::eValidationCacheCreateInfoEXT;
    const void* pNext = nullptr;
    ValidationCacheCreateFlagsEXT flags = static_cast<ValidationCacheCreateFlagsEXT>(0);
    size_t initialDataSize = 0;
    const void* pInitialData = nullptr;
    operator VkValidationCacheCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(this);
    }
    operator VkValidationCacheCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkValidationCacheCreateInfoEXT*>(this);
    }
};
struct ShaderModuleValidationCacheCreateInfoEXT {
    StructureType sType = StructureType::eShaderModuleValidationCacheCreateInfoEXT;
    const void* pNext = nullptr;
    ValidationCacheEXT validationCache;
    operator VkShaderModuleValidationCacheCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(this);
    }
    operator VkShaderModuleValidationCacheCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkShaderModuleValidationCacheCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceMaintenance3Properties {
    StructureType sType = StructureType::ePhysicalDeviceMaintenance3Properties;
    void* pNext = nullptr;
    uint32_t maxPerSetDescriptors = 0;
    DeviceSize maxMemoryAllocationSize = 0;
    operator VkPhysicalDeviceMaintenance3Properties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(this);
    }
    operator VkPhysicalDeviceMaintenance3Properties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMaintenance3Properties*>(this);
    }
};
using PhysicalDeviceMaintenance3PropertiesKHR = PhysicalDeviceMaintenance3Properties;
struct DescriptorSetLayoutSupport {
    StructureType sType = StructureType::eDescriptorSetLayoutSupport;
    void* pNext = nullptr;
    bool supported = false;
    operator VkDescriptorSetLayoutSupport const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetLayoutSupport*>(this);
    }
    operator VkDescriptorSetLayoutSupport &() noexcept {
        return *reinterpret_cast<VkDescriptorSetLayoutSupport*>(this);
    }
};
using DescriptorSetLayoutSupportKHR = DescriptorSetLayoutSupport;
struct PhysicalDeviceShaderDrawParametersFeatures {
    StructureType sType = StructureType::ePhysicalDeviceShaderDrawParametersFeatures;
    void* pNext = nullptr;
    bool shaderDrawParameters = false;
    operator VkPhysicalDeviceShaderDrawParametersFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(this);
    }
    operator VkPhysicalDeviceShaderDrawParametersFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderDrawParametersFeatures*>(this);
    }
};
using PhysicalDeviceShaderDrawParameterFeatures = PhysicalDeviceShaderDrawParametersFeatures;
struct PhysicalDeviceShaderFloat16Int8Features {
    StructureType sType = StructureType::ePhysicalDeviceShaderFloat16Int8Features;
    void* pNext = nullptr;
    bool shaderFloat16 = false;
    bool shaderInt8 = false;
    operator VkPhysicalDeviceShaderFloat16Int8Features const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(this);
    }
    operator VkPhysicalDeviceShaderFloat16Int8Features &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderFloat16Int8Features*>(this);
    }
};
using PhysicalDeviceShaderFloat16Int8FeaturesKHR = PhysicalDeviceShaderFloat16Int8Features;
using PhysicalDeviceFloat16Int8FeaturesKHR = PhysicalDeviceShaderFloat16Int8Features;
struct PhysicalDeviceFloatControlsProperties {
    StructureType sType = StructureType::ePhysicalDeviceFloatControlsProperties;
    void* pNext = nullptr;
    ShaderFloatControlsIndependence denormBehaviorIndependence = static_cast<ShaderFloatControlsIndependence>(0);
    ShaderFloatControlsIndependence roundingModeIndependence = static_cast<ShaderFloatControlsIndependence>(0);
    bool shaderSignedZeroInfNanPreserveFloat16 = false;
    bool shaderSignedZeroInfNanPreserveFloat32 = false;
    bool shaderSignedZeroInfNanPreserveFloat64 = false;
    bool shaderDenormPreserveFloat16 = false;
    bool shaderDenormPreserveFloat32 = false;
    bool shaderDenormPreserveFloat64 = false;
    bool shaderDenormFlushToZeroFloat16 = false;
    bool shaderDenormFlushToZeroFloat32 = false;
    bool shaderDenormFlushToZeroFloat64 = false;
    bool shaderRoundingModeRTEFloat16 = false;
    bool shaderRoundingModeRTEFloat32 = false;
    bool shaderRoundingModeRTEFloat64 = false;
    bool shaderRoundingModeRTZFloat16 = false;
    bool shaderRoundingModeRTZFloat32 = false;
    bool shaderRoundingModeRTZFloat64 = false;
    operator VkPhysicalDeviceFloatControlsProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(this);
    }
    operator VkPhysicalDeviceFloatControlsProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFloatControlsProperties*>(this);
    }
};
using PhysicalDeviceFloatControlsPropertiesKHR = PhysicalDeviceFloatControlsProperties;
struct PhysicalDeviceHostQueryResetFeatures {
    StructureType sType = StructureType::ePhysicalDeviceHostQueryResetFeatures;
    void* pNext = nullptr;
    bool hostQueryReset = false;
    operator VkPhysicalDeviceHostQueryResetFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(this);
    }
    operator VkPhysicalDeviceHostQueryResetFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceHostQueryResetFeatures*>(this);
    }
};
using PhysicalDeviceHostQueryResetFeaturesEXT = PhysicalDeviceHostQueryResetFeatures;
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct NativeBufferUsage2ANDROID {
    uint64_t consumer = 0;
    uint64_t producer = 0;
    operator VkNativeBufferUsage2ANDROID const &() const noexcept {
        return *reinterpret_cast<const VkNativeBufferUsage2ANDROID*>(this);
    }
    operator VkNativeBufferUsage2ANDROID &() noexcept {
        return *reinterpret_cast<VkNativeBufferUsage2ANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct NativeBufferANDROID {
    StructureType sType = StructureType::eNativeBufferANDROID;
    const void* pNext = nullptr;
    const void* handle = nullptr;
    int stride = 0;
    int format = 0;
    int usage = 0;
    NativeBufferUsage2ANDROID usage2;
    operator VkNativeBufferANDROID const &() const noexcept {
        return *reinterpret_cast<const VkNativeBufferANDROID*>(this);
    }
    operator VkNativeBufferANDROID &() noexcept {
        return *reinterpret_cast<VkNativeBufferANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct SwapchainImageCreateInfoANDROID {
    StructureType sType = StructureType::eSwapchainImageCreateInfoANDROID;
    const void* pNext = nullptr;
    SwapchainImageUsageFlagsANDROID usage = static_cast<SwapchainImageUsageFlagsANDROID>(0);
    operator VkSwapchainImageCreateInfoANDROID const &() const noexcept {
        return *reinterpret_cast<const VkSwapchainImageCreateInfoANDROID*>(this);
    }
    operator VkSwapchainImageCreateInfoANDROID &() noexcept {
        return *reinterpret_cast<VkSwapchainImageCreateInfoANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct PhysicalDevicePresentationPropertiesANDROID {
    StructureType sType = StructureType::ePhysicalDevicePresentationPropertiesANDROID;
    const void* pNext = nullptr;
    bool sharedImage = false;
    operator VkPhysicalDevicePresentationPropertiesANDROID const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePresentationPropertiesANDROID*>(this);
    }
    operator VkPhysicalDevicePresentationPropertiesANDROID &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePresentationPropertiesANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
struct ShaderResourceUsageAMD {
    uint32_t numUsedVgprs = 0;
    uint32_t numUsedSgprs = 0;
    uint32_t ldsSizePerLocalWorkGroup = 0;
    size_t ldsUsageSizeInBytes = 0;
    size_t scratchMemUsageInBytes = 0;
    operator VkShaderResourceUsageAMD const &() const noexcept {
        return *reinterpret_cast<const VkShaderResourceUsageAMD*>(this);
    }
    operator VkShaderResourceUsageAMD &() noexcept {
        return *reinterpret_cast<VkShaderResourceUsageAMD*>(this);
    }
};
struct ShaderStatisticsInfoAMD {
    ShaderStageFlags shaderStageMask = static_cast<ShaderStageFlags>(0);
    ShaderResourceUsageAMD resourceUsage;
    uint32_t numPhysicalVgprs = 0;
    uint32_t numPhysicalSgprs = 0;
    uint32_t numAvailableVgprs = 0;
    uint32_t numAvailableSgprs = 0;
    uint32_t computeWorkGroupSize[3] = {};
    operator VkShaderStatisticsInfoAMD const &() const noexcept {
        return *reinterpret_cast<const VkShaderStatisticsInfoAMD*>(this);
    }
    operator VkShaderStatisticsInfoAMD &() noexcept {
        return *reinterpret_cast<VkShaderStatisticsInfoAMD*>(this);
    }
};
struct DeviceQueueGlobalPriorityCreateInfoEXT {
    StructureType sType = StructureType::eDeviceQueueGlobalPriorityCreateInfoEXT;
    const void* pNext = nullptr;
    QueueGlobalPriorityEXT globalPriority = static_cast<QueueGlobalPriorityEXT>(0);
    operator VkDeviceQueueGlobalPriorityCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoEXT*>(this);
    }
    operator VkDeviceQueueGlobalPriorityCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkDeviceQueueGlobalPriorityCreateInfoEXT*>(this);
    }
};
struct DebugUtilsObjectNameInfoEXT {
    StructureType sType = StructureType::eDebugUtilsObjectNameInfoEXT;
    const void* pNext = nullptr;
    ObjectType objectType = static_cast<ObjectType>(0);
    uint64_t objectHandle = 0;
    const char* pObjectName = nullptr;
    operator VkDebugUtilsObjectNameInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(this);
    }
    operator VkDebugUtilsObjectNameInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugUtilsObjectNameInfoEXT*>(this);
    }
};
struct DebugUtilsObjectTagInfoEXT {
    StructureType sType = StructureType::eDebugUtilsObjectTagInfoEXT;
    const void* pNext = nullptr;
    ObjectType objectType = static_cast<ObjectType>(0);
    uint64_t objectHandle = 0;
    uint64_t tagName = 0;
    size_t tagSize = 0;
    const void* pTag = nullptr;
    operator VkDebugUtilsObjectTagInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(this);
    }
    operator VkDebugUtilsObjectTagInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugUtilsObjectTagInfoEXT*>(this);
    }
};
struct DebugUtilsLabelEXT {
    StructureType sType = StructureType::eDebugUtilsLabelEXT;
    const void* pNext = nullptr;
    const char* pLabelName = nullptr;
    float color[4] = {};
    operator VkDebugUtilsLabelEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugUtilsLabelEXT*>(this);
    }
    operator VkDebugUtilsLabelEXT &() noexcept {
        return *reinterpret_cast<VkDebugUtilsLabelEXT*>(this);
    }
};
struct DebugUtilsMessengerCreateInfoEXT {
    StructureType sType = StructureType::eDebugUtilsMessengerCreateInfoEXT;
    const void* pNext = nullptr;
    DebugUtilsMessengerCreateFlagsEXT flags = static_cast<DebugUtilsMessengerCreateFlagsEXT>(0);
    DebugUtilsMessageSeverityFlagsEXT messageSeverity = static_cast<DebugUtilsMessageSeverityFlagsEXT>(0);
    DebugUtilsMessageTypeFlagsEXT messageType = static_cast<DebugUtilsMessageTypeFlagsEXT>(0);
    PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback;
    void* pUserData = nullptr;
    operator VkDebugUtilsMessengerCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(this);
    }
    operator VkDebugUtilsMessengerCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkDebugUtilsMessengerCreateInfoEXT*>(this);
    }
};
struct DebugUtilsMessengerCallbackDataEXT {
    StructureType sType = StructureType::eDebugUtilsMessengerCallbackDataEXT;
    const void* pNext = nullptr;
    DebugUtilsMessengerCallbackDataFlagsEXT flags = static_cast<DebugUtilsMessengerCallbackDataFlagsEXT>(0);
    const char* pMessageIdName = nullptr;
    int32_t messageIdNumber = 0;
    const char* pMessage = nullptr;
    uint32_t queueLabelCount = 0;
    const DebugUtilsLabelEXT* pQueueLabels = nullptr;
    uint32_t cmdBufLabelCount = 0;
    const DebugUtilsLabelEXT* pCmdBufLabels = nullptr;
    uint32_t objectCount = 0;
    const DebugUtilsObjectNameInfoEXT* pObjects = nullptr;
    operator VkDebugUtilsMessengerCallbackDataEXT const &() const noexcept {
        return *reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(this);
    }
    operator VkDebugUtilsMessengerCallbackDataEXT &() noexcept {
        return *reinterpret_cast<VkDebugUtilsMessengerCallbackDataEXT*>(this);
    }
};
struct ImportMemoryHostPointerInfoEXT {
    StructureType sType = StructureType::eImportMemoryHostPointerInfoEXT;
    const void* pNext = nullptr;
    ExternalMemoryHandleTypeFlagBits handleType = static_cast<ExternalMemoryHandleTypeFlagBits>(0);
    void* pHostPointer = nullptr;
    operator VkImportMemoryHostPointerInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(this);
    }
    operator VkImportMemoryHostPointerInfoEXT &() noexcept {
        return *reinterpret_cast<VkImportMemoryHostPointerInfoEXT*>(this);
    }
};
struct MemoryHostPointerPropertiesEXT {
    StructureType sType = StructureType::eMemoryHostPointerPropertiesEXT;
    void* pNext = nullptr;
    uint32_t memoryTypeBits = 0;
    operator VkMemoryHostPointerPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(this);
    }
    operator VkMemoryHostPointerPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkMemoryHostPointerPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceExternalMemoryHostPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceExternalMemoryHostPropertiesEXT;
    void* pNext = nullptr;
    DeviceSize minImportedHostPointerAlignment = 0;
    operator VkPhysicalDeviceExternalMemoryHostPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceExternalMemoryHostPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceConservativeRasterizationPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceConservativeRasterizationPropertiesEXT;
    void* pNext = nullptr;
    float primitiveOverestimationSize = 0.f;
    float maxExtraPrimitiveOverestimationSize = 0.f;
    float extraPrimitiveOverestimationSizeGranularity = 0.f;
    bool primitiveUnderestimation = false;
    bool conservativePointAndLineRasterization = false;
    bool degenerateTrianglesRasterized = false;
    bool degenerateLinesRasterized = false;
    bool fullyCoveredFragmentShaderInputVariable = false;
    bool conservativeRasterizationPostDepthCoverage = false;
    operator VkPhysicalDeviceConservativeRasterizationPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceConservativeRasterizationPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(this);
    }
};
struct CalibratedTimestampInfoEXT {
    StructureType sType = StructureType::eCalibratedTimestampInfoEXT;
    const void* pNext = nullptr;
    TimeDomainEXT timeDomain = static_cast<TimeDomainEXT>(0);
    operator VkCalibratedTimestampInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkCalibratedTimestampInfoEXT*>(this);
    }
    operator VkCalibratedTimestampInfoEXT &() noexcept {
        return *reinterpret_cast<VkCalibratedTimestampInfoEXT*>(this);
    }
};
struct PhysicalDeviceShaderCorePropertiesAMD {
    StructureType sType = StructureType::ePhysicalDeviceShaderCorePropertiesAMD;
    void* pNext = nullptr;
    uint32_t shaderEngineCount = 0;
    uint32_t shaderArraysPerEngineCount = 0;
    uint32_t computeUnitsPerShaderArray = 0;
    uint32_t simdPerComputeUnit = 0;
    uint32_t wavefrontsPerSimd = 0;
    uint32_t wavefrontSize = 0;
    uint32_t sgprsPerSimd = 0;
    uint32_t minSgprAllocation = 0;
    uint32_t maxSgprAllocation = 0;
    uint32_t sgprAllocationGranularity = 0;
    uint32_t vgprsPerSimd = 0;
    uint32_t minVgprAllocation = 0;
    uint32_t maxVgprAllocation = 0;
    uint32_t vgprAllocationGranularity = 0;
    operator VkPhysicalDeviceShaderCorePropertiesAMD const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(this);
    }
    operator VkPhysicalDeviceShaderCorePropertiesAMD &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderCorePropertiesAMD*>(this);
    }
};
struct PhysicalDeviceShaderCoreProperties2AMD {
    StructureType sType = StructureType::ePhysicalDeviceShaderCoreProperties2AMD;
    void* pNext = nullptr;
    ShaderCorePropertiesFlagsAMD shaderCoreFeatures = static_cast<ShaderCorePropertiesFlagsAMD>(0);
    uint32_t activeComputeUnitCount = 0;
    operator VkPhysicalDeviceShaderCoreProperties2AMD const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(this);
    }
    operator VkPhysicalDeviceShaderCoreProperties2AMD &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderCoreProperties2AMD*>(this);
    }
};
struct PipelineRasterizationConservativeStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineRasterizationConservativeStateCreateInfoEXT;
    const void* pNext = nullptr;
    PipelineRasterizationConservativeStateCreateFlagsEXT flags = static_cast<PipelineRasterizationConservativeStateCreateFlagsEXT>(0);
    ConservativeRasterizationModeEXT conservativeRasterizationMode = static_cast<ConservativeRasterizationModeEXT>(0);
    float extraPrimitiveOverestimationSize = 0.f;
    operator VkPipelineRasterizationConservativeStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(this);
    }
    operator VkPipelineRasterizationConservativeStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineRasterizationConservativeStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceDescriptorIndexingFeatures {
    StructureType sType = StructureType::ePhysicalDeviceDescriptorIndexingFeatures;
    void* pNext = nullptr;
    bool shaderInputAttachmentArrayDynamicIndexing = false;
    bool shaderUniformTexelBufferArrayDynamicIndexing = false;
    bool shaderStorageTexelBufferArrayDynamicIndexing = false;
    bool shaderUniformBufferArrayNonUniformIndexing = false;
    bool shaderSampledImageArrayNonUniformIndexing = false;
    bool shaderStorageBufferArrayNonUniformIndexing = false;
    bool shaderStorageImageArrayNonUniformIndexing = false;
    bool shaderInputAttachmentArrayNonUniformIndexing = false;
    bool shaderUniformTexelBufferArrayNonUniformIndexing = false;
    bool shaderStorageTexelBufferArrayNonUniformIndexing = false;
    bool descriptorBindingUniformBufferUpdateAfterBind = false;
    bool descriptorBindingSampledImageUpdateAfterBind = false;
    bool descriptorBindingStorageImageUpdateAfterBind = false;
    bool descriptorBindingStorageBufferUpdateAfterBind = false;
    bool descriptorBindingUniformTexelBufferUpdateAfterBind = false;
    bool descriptorBindingStorageTexelBufferUpdateAfterBind = false;
    bool descriptorBindingUpdateUnusedWhilePending = false;
    bool descriptorBindingPartiallyBound = false;
    bool descriptorBindingVariableDescriptorCount = false;
    bool runtimeDescriptorArray = false;
    operator VkPhysicalDeviceDescriptorIndexingFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(this);
    }
    operator VkPhysicalDeviceDescriptorIndexingFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(this);
    }
};
using PhysicalDeviceDescriptorIndexingFeaturesEXT = PhysicalDeviceDescriptorIndexingFeatures;
struct PhysicalDeviceDescriptorIndexingProperties {
    StructureType sType = StructureType::ePhysicalDeviceDescriptorIndexingProperties;
    void* pNext = nullptr;
    uint32_t maxUpdateAfterBindDescriptorsInAllPools = 0;
    bool shaderUniformBufferArrayNonUniformIndexingNative = false;
    bool shaderSampledImageArrayNonUniformIndexingNative = false;
    bool shaderStorageBufferArrayNonUniformIndexingNative = false;
    bool shaderStorageImageArrayNonUniformIndexingNative = false;
    bool shaderInputAttachmentArrayNonUniformIndexingNative = false;
    bool robustBufferAccessUpdateAfterBind = false;
    bool quadDivergentImplicitLod = false;
    uint32_t maxPerStageDescriptorUpdateAfterBindSamplers = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments = 0;
    uint32_t maxPerStageUpdateAfterBindResources = 0;
    uint32_t maxDescriptorSetUpdateAfterBindSamplers = 0;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers = 0;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 0;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers = 0;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 0;
    uint32_t maxDescriptorSetUpdateAfterBindSampledImages = 0;
    uint32_t maxDescriptorSetUpdateAfterBindStorageImages = 0;
    uint32_t maxDescriptorSetUpdateAfterBindInputAttachments = 0;
    operator VkPhysicalDeviceDescriptorIndexingProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(this);
    }
    operator VkPhysicalDeviceDescriptorIndexingProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDescriptorIndexingProperties*>(this);
    }
};
using PhysicalDeviceDescriptorIndexingPropertiesEXT = PhysicalDeviceDescriptorIndexingProperties;
struct DescriptorSetLayoutBindingFlagsCreateInfo {
    StructureType sType = StructureType::eDescriptorSetLayoutBindingFlagsCreateInfo;
    const void* pNext = nullptr;
    uint32_t bindingCount = 0;
    const DescriptorBindingFlags* pBindingFlags = nullptr;
    operator VkDescriptorSetLayoutBindingFlagsCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(this);
    }
    operator VkDescriptorSetLayoutBindingFlagsCreateInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorSetLayoutBindingFlagsCreateInfo*>(this);
    }
};
using DescriptorSetLayoutBindingFlagsCreateInfoEXT = DescriptorSetLayoutBindingFlagsCreateInfo;
struct DescriptorSetVariableDescriptorCountAllocateInfo {
    StructureType sType = StructureType::eDescriptorSetVariableDescriptorCountAllocateInfo;
    const void* pNext = nullptr;
    uint32_t descriptorSetCount = 0;
    const uint32_t* pDescriptorCounts = nullptr;
    operator VkDescriptorSetVariableDescriptorCountAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(this);
    }
    operator VkDescriptorSetVariableDescriptorCountAllocateInfo &() noexcept {
        return *reinterpret_cast<VkDescriptorSetVariableDescriptorCountAllocateInfo*>(this);
    }
};
using DescriptorSetVariableDescriptorCountAllocateInfoEXT = DescriptorSetVariableDescriptorCountAllocateInfo;
struct DescriptorSetVariableDescriptorCountLayoutSupport {
    StructureType sType = StructureType::eDescriptorSetVariableDescriptorCountLayoutSupport;
    void* pNext = nullptr;
    uint32_t maxVariableDescriptorCount = 0;
    operator VkDescriptorSetVariableDescriptorCountLayoutSupport const &() const noexcept {
        return *reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(this);
    }
    operator VkDescriptorSetVariableDescriptorCountLayoutSupport &() noexcept {
        return *reinterpret_cast<VkDescriptorSetVariableDescriptorCountLayoutSupport*>(this);
    }
};
using DescriptorSetVariableDescriptorCountLayoutSupportEXT = DescriptorSetVariableDescriptorCountLayoutSupport;
struct AttachmentDescription2 {
    StructureType sType = StructureType::eAttachmentDescription2;
    const void* pNext = nullptr;
    AttachmentDescriptionFlags flags = static_cast<AttachmentDescriptionFlags>(0);
    Format format = static_cast<Format>(0);
    SampleCountFlagBits samples = static_cast<SampleCountFlagBits>(0);
    AttachmentLoadOp loadOp = static_cast<AttachmentLoadOp>(0);
    AttachmentStoreOp storeOp = static_cast<AttachmentStoreOp>(0);
    AttachmentLoadOp stencilLoadOp = static_cast<AttachmentLoadOp>(0);
    AttachmentStoreOp stencilStoreOp = static_cast<AttachmentStoreOp>(0);
    ImageLayout initialLayout = static_cast<ImageLayout>(0);
    ImageLayout finalLayout = static_cast<ImageLayout>(0);
    operator VkAttachmentDescription2 const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentDescription2*>(this);
    }
    operator VkAttachmentDescription2 &() noexcept {
        return *reinterpret_cast<VkAttachmentDescription2*>(this);
    }
};
using AttachmentDescription2KHR = AttachmentDescription2;
struct AttachmentReference2 {
    StructureType sType = StructureType::eAttachmentReference2;
    const void* pNext = nullptr;
    uint32_t attachment = 0;
    ImageLayout layout = static_cast<ImageLayout>(0);
    ImageAspectFlags aspectMask = static_cast<ImageAspectFlags>(0);
    operator VkAttachmentReference2 const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentReference2*>(this);
    }
    operator VkAttachmentReference2 &() noexcept {
        return *reinterpret_cast<VkAttachmentReference2*>(this);
    }
};
using AttachmentReference2KHR = AttachmentReference2;
struct SubpassDescription2 {
    StructureType sType = StructureType::eSubpassDescription2;
    const void* pNext = nullptr;
    SubpassDescriptionFlags flags = static_cast<SubpassDescriptionFlags>(0);
    PipelineBindPoint pipelineBindPoint = static_cast<PipelineBindPoint>(0);
    uint32_t viewMask = 0;
    uint32_t inputAttachmentCount = 0;
    const AttachmentReference2* pInputAttachments = nullptr;
    uint32_t colorAttachmentCount = 0;
    const AttachmentReference2* pColorAttachments = nullptr;
    const AttachmentReference2* pResolveAttachments = nullptr;
    const AttachmentReference2* pDepthStencilAttachment = nullptr;
    uint32_t preserveAttachmentCount = 0;
    const uint32_t* pPreserveAttachments = nullptr;
    operator VkSubpassDescription2 const &() const noexcept {
        return *reinterpret_cast<const VkSubpassDescription2*>(this);
    }
    operator VkSubpassDescription2 &() noexcept {
        return *reinterpret_cast<VkSubpassDescription2*>(this);
    }
};
using SubpassDescription2KHR = SubpassDescription2;
struct SubpassDependency2 {
    StructureType sType = StructureType::eSubpassDependency2;
    const void* pNext = nullptr;
    uint32_t srcSubpass = 0;
    uint32_t dstSubpass = 0;
    PipelineStageFlags srcStageMask = static_cast<PipelineStageFlags>(0);
    PipelineStageFlags dstStageMask = static_cast<PipelineStageFlags>(0);
    AccessFlags srcAccessMask = static_cast<AccessFlags>(0);
    AccessFlags dstAccessMask = static_cast<AccessFlags>(0);
    DependencyFlags dependencyFlags = static_cast<DependencyFlags>(0);
    int32_t viewOffset = 0;
    operator VkSubpassDependency2 const &() const noexcept {
        return *reinterpret_cast<const VkSubpassDependency2*>(this);
    }
    operator VkSubpassDependency2 &() noexcept {
        return *reinterpret_cast<VkSubpassDependency2*>(this);
    }
};
using SubpassDependency2KHR = SubpassDependency2;
struct RenderPassCreateInfo2 {
    StructureType sType = StructureType::eRenderPassCreateInfo2;
    const void* pNext = nullptr;
    RenderPassCreateFlags flags = static_cast<RenderPassCreateFlags>(0);
    uint32_t attachmentCount = 0;
    const AttachmentDescription2* pAttachments = nullptr;
    uint32_t subpassCount = 0;
    const SubpassDescription2* pSubpasses = nullptr;
    uint32_t dependencyCount = 0;
    const SubpassDependency2* pDependencies = nullptr;
    uint32_t correlatedViewMaskCount = 0;
    const uint32_t* pCorrelatedViewMasks = nullptr;
    operator VkRenderPassCreateInfo2 const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassCreateInfo2*>(this);
    }
    operator VkRenderPassCreateInfo2 &() noexcept {
        return *reinterpret_cast<VkRenderPassCreateInfo2*>(this);
    }
};
using RenderPassCreateInfo2KHR = RenderPassCreateInfo2;
struct SubpassBeginInfo {
    StructureType sType = StructureType::eSubpassBeginInfo;
    const void* pNext = nullptr;
    SubpassContents contents = static_cast<SubpassContents>(0);
    operator VkSubpassBeginInfo const &() const noexcept {
        return *reinterpret_cast<const VkSubpassBeginInfo*>(this);
    }
    operator VkSubpassBeginInfo &() noexcept {
        return *reinterpret_cast<VkSubpassBeginInfo*>(this);
    }
};
using SubpassBeginInfoKHR = SubpassBeginInfo;
struct SubpassEndInfo {
    StructureType sType = StructureType::eSubpassEndInfo;
    const void* pNext = nullptr;
    operator VkSubpassEndInfo const &() const noexcept {
        return *reinterpret_cast<const VkSubpassEndInfo*>(this);
    }
    operator VkSubpassEndInfo &() noexcept {
        return *reinterpret_cast<VkSubpassEndInfo*>(this);
    }
};
using SubpassEndInfoKHR = SubpassEndInfo;
struct PhysicalDeviceTimelineSemaphoreFeatures {
    StructureType sType = StructureType::ePhysicalDeviceTimelineSemaphoreFeatures;
    void* pNext = nullptr;
    bool timelineSemaphore = false;
    operator VkPhysicalDeviceTimelineSemaphoreFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(this);
    }
    operator VkPhysicalDeviceTimelineSemaphoreFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreFeatures*>(this);
    }
};
using PhysicalDeviceTimelineSemaphoreFeaturesKHR = PhysicalDeviceTimelineSemaphoreFeatures;
struct PhysicalDeviceTimelineSemaphoreProperties {
    StructureType sType = StructureType::ePhysicalDeviceTimelineSemaphoreProperties;
    void* pNext = nullptr;
    uint64_t maxTimelineSemaphoreValueDifference = 0;
    operator VkPhysicalDeviceTimelineSemaphoreProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(this);
    }
    operator VkPhysicalDeviceTimelineSemaphoreProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreProperties*>(this);
    }
};
using PhysicalDeviceTimelineSemaphorePropertiesKHR = PhysicalDeviceTimelineSemaphoreProperties;
struct SemaphoreTypeCreateInfo {
    StructureType sType = StructureType::eSemaphoreTypeCreateInfo;
    const void* pNext = nullptr;
    SemaphoreType semaphoreType = static_cast<SemaphoreType>(0);
    uint64_t initialValue = 0;
    operator VkSemaphoreTypeCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(this);
    }
    operator VkSemaphoreTypeCreateInfo &() noexcept {
        return *reinterpret_cast<VkSemaphoreTypeCreateInfo*>(this);
    }
};
using SemaphoreTypeCreateInfoKHR = SemaphoreTypeCreateInfo;
struct TimelineSemaphoreSubmitInfo {
    StructureType sType = StructureType::eTimelineSemaphoreSubmitInfo;
    const void* pNext = nullptr;
    uint32_t waitSemaphoreValueCount = 0;
    const uint64_t* pWaitSemaphoreValues = nullptr;
    uint32_t signalSemaphoreValueCount = 0;
    const uint64_t* pSignalSemaphoreValues = nullptr;
    operator VkTimelineSemaphoreSubmitInfo const &() const noexcept {
        return *reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(this);
    }
    operator VkTimelineSemaphoreSubmitInfo &() noexcept {
        return *reinterpret_cast<VkTimelineSemaphoreSubmitInfo*>(this);
    }
};
using TimelineSemaphoreSubmitInfoKHR = TimelineSemaphoreSubmitInfo;
struct SemaphoreWaitInfo {
    StructureType sType = StructureType::eSemaphoreWaitInfo;
    const void* pNext = nullptr;
    SemaphoreWaitFlags flags = static_cast<SemaphoreWaitFlags>(0);
    uint32_t semaphoreCount = 0;
    const Semaphore* pSemaphores = nullptr;
    const uint64_t* pValues = nullptr;
    operator VkSemaphoreWaitInfo const &() const noexcept {
        return *reinterpret_cast<const VkSemaphoreWaitInfo*>(this);
    }
    operator VkSemaphoreWaitInfo &() noexcept {
        return *reinterpret_cast<VkSemaphoreWaitInfo*>(this);
    }
};
using SemaphoreWaitInfoKHR = SemaphoreWaitInfo;
struct SemaphoreSignalInfo {
    StructureType sType = StructureType::eSemaphoreSignalInfo;
    const void* pNext = nullptr;
    Semaphore semaphore;
    uint64_t value = 0;
    operator VkSemaphoreSignalInfo const &() const noexcept {
        return *reinterpret_cast<const VkSemaphoreSignalInfo*>(this);
    }
    operator VkSemaphoreSignalInfo &() noexcept {
        return *reinterpret_cast<VkSemaphoreSignalInfo*>(this);
    }
};
using SemaphoreSignalInfoKHR = SemaphoreSignalInfo;
struct VertexInputBindingDivisorDescriptionEXT {
    uint32_t binding = 0;
    uint32_t divisor = 0;
    operator VkVertexInputBindingDivisorDescriptionEXT const &() const noexcept {
        return *reinterpret_cast<const VkVertexInputBindingDivisorDescriptionEXT*>(this);
    }
    operator VkVertexInputBindingDivisorDescriptionEXT &() noexcept {
        return *reinterpret_cast<VkVertexInputBindingDivisorDescriptionEXT*>(this);
    }
};
struct PipelineVertexInputDivisorStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineVertexInputDivisorStateCreateInfoEXT;
    const void* pNext = nullptr;
    uint32_t vertexBindingDivisorCount = 0;
    const VertexInputBindingDivisorDescriptionEXT* pVertexBindingDivisors = nullptr;
    operator VkPipelineVertexInputDivisorStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(this);
    }
    operator VkPipelineVertexInputDivisorStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineVertexInputDivisorStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceVertexAttributeDivisorPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesEXT;
    void* pNext = nullptr;
    uint32_t maxVertexAttribDivisor = 0;
    operator VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(this);
    }
};
struct PhysicalDevicePCIBusInfoPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDevicePciBusInfoPropertiesEXT;
    void* pNext = nullptr;
    uint32_t pciDomain = 0;
    uint32_t pciBus = 0;
    uint32_t pciDevice = 0;
    uint32_t pciFunction = 0;
    operator VkPhysicalDevicePCIBusInfoPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(this);
    }
    operator VkPhysicalDevicePCIBusInfoPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePCIBusInfoPropertiesEXT*>(this);
    }
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct ImportAndroidHardwareBufferInfoANDROID {
    StructureType sType = StructureType::eImportAndroidHardwareBufferInfoANDROID;
    const void* pNext = nullptr;
    AHardwareBuffer* buffer = nullptr;
    operator VkImportAndroidHardwareBufferInfoANDROID const &() const noexcept {
        return *reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(this);
    }
    operator VkImportAndroidHardwareBufferInfoANDROID &() noexcept {
        return *reinterpret_cast<VkImportAndroidHardwareBufferInfoANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct AndroidHardwareBufferUsageANDROID {
    StructureType sType = StructureType::eAndroidHardwareBufferUsageANDROID;
    void* pNext = nullptr;
    uint64_t androidHardwareBufferUsage = 0;
    operator VkAndroidHardwareBufferUsageANDROID const &() const noexcept {
        return *reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(this);
    }
    operator VkAndroidHardwareBufferUsageANDROID &() noexcept {
        return *reinterpret_cast<VkAndroidHardwareBufferUsageANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct AndroidHardwareBufferPropertiesANDROID {
    StructureType sType = StructureType::eAndroidHardwareBufferPropertiesANDROID;
    void* pNext = nullptr;
    DeviceSize allocationSize = 0;
    uint32_t memoryTypeBits = 0;
    operator VkAndroidHardwareBufferPropertiesANDROID const &() const noexcept {
        return *reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(this);
    }
    operator VkAndroidHardwareBufferPropertiesANDROID &() noexcept {
        return *reinterpret_cast<VkAndroidHardwareBufferPropertiesANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct MemoryGetAndroidHardwareBufferInfoANDROID {
    StructureType sType = StructureType::eMemoryGetAndroidHardwareBufferInfoANDROID;
    const void* pNext = nullptr;
    DeviceMemory memory;
    operator VkMemoryGetAndroidHardwareBufferInfoANDROID const &() const noexcept {
        return *reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(this);
    }
    operator VkMemoryGetAndroidHardwareBufferInfoANDROID &() noexcept {
        return *reinterpret_cast<VkMemoryGetAndroidHardwareBufferInfoANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct AndroidHardwareBufferFormatPropertiesANDROID {
    StructureType sType = StructureType::eAndroidHardwareBufferFormatPropertiesANDROID;
    void* pNext = nullptr;
    Format format = static_cast<Format>(0);
    uint64_t externalFormat = 0;
    FormatFeatureFlags formatFeatures = static_cast<FormatFeatureFlags>(0);
    ComponentMapping samplerYcbcrConversionComponents;
    SamplerYcbcrModelConversion suggestedYcbcrModel = static_cast<SamplerYcbcrModelConversion>(0);
    SamplerYcbcrRange suggestedYcbcrRange = static_cast<SamplerYcbcrRange>(0);
    ChromaLocation suggestedXChromaOffset = static_cast<ChromaLocation>(0);
    ChromaLocation suggestedYChromaOffset = static_cast<ChromaLocation>(0);
    operator VkAndroidHardwareBufferFormatPropertiesANDROID const &() const noexcept {
        return *reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(this);
    }
    operator VkAndroidHardwareBufferFormatPropertiesANDROID &() noexcept {
        return *reinterpret_cast<VkAndroidHardwareBufferFormatPropertiesANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
struct CommandBufferInheritanceConditionalRenderingInfoEXT {
    StructureType sType = StructureType::eCommandBufferInheritanceConditionalRenderingInfoEXT;
    const void* pNext = nullptr;
    bool conditionalRenderingEnable = false;
    operator VkCommandBufferInheritanceConditionalRenderingInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(this);
    }
    operator VkCommandBufferInheritanceConditionalRenderingInfoEXT &() noexcept {
        return *reinterpret_cast<VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(this);
    }
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct ExternalFormatANDROID {
    StructureType sType = StructureType::eExternalFormatANDROID;
    void* pNext = nullptr;
    uint64_t externalFormat = 0;
    operator VkExternalFormatANDROID const &() const noexcept {
        return *reinterpret_cast<const VkExternalFormatANDROID*>(this);
    }
    operator VkExternalFormatANDROID &() noexcept {
        return *reinterpret_cast<VkExternalFormatANDROID*>(this);
    }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR
struct PhysicalDevice8BitStorageFeatures {
    StructureType sType = StructureType::ePhysicalDevice8BitStorageFeatures;
    void* pNext = nullptr;
    bool storageBuffer8BitAccess = false;
    bool uniformAndStorageBuffer8BitAccess = false;
    bool storagePushConstant8 = false;
    operator VkPhysicalDevice8BitStorageFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(this);
    }
    operator VkPhysicalDevice8BitStorageFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDevice8BitStorageFeatures*>(this);
    }
};
using PhysicalDevice8BitStorageFeaturesKHR = PhysicalDevice8BitStorageFeatures;
struct PhysicalDeviceConditionalRenderingFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceConditionalRenderingFeaturesEXT;
    void* pNext = nullptr;
    bool conditionalRendering = false;
    bool inheritedConditionalRendering = false;
    operator VkPhysicalDeviceConditionalRenderingFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceConditionalRenderingFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceVulkanMemoryModelFeatures {
    StructureType sType = StructureType::ePhysicalDeviceVulkanMemoryModelFeatures;
    void* pNext = nullptr;
    bool vulkanMemoryModel = false;
    bool vulkanMemoryModelDeviceScope = false;
    bool vulkanMemoryModelAvailabilityVisibilityChains = false;
    operator VkPhysicalDeviceVulkanMemoryModelFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(this);
    }
    operator VkPhysicalDeviceVulkanMemoryModelFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(this);
    }
};
using PhysicalDeviceVulkanMemoryModelFeaturesKHR = PhysicalDeviceVulkanMemoryModelFeatures;
struct PhysicalDeviceShaderAtomicInt64Features {
    StructureType sType = StructureType::ePhysicalDeviceShaderAtomicInt64Features;
    void* pNext = nullptr;
    bool shaderBufferInt64Atomics = false;
    bool shaderSharedInt64Atomics = false;
    operator VkPhysicalDeviceShaderAtomicInt64Features const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(this);
    }
    operator VkPhysicalDeviceShaderAtomicInt64Features &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderAtomicInt64Features*>(this);
    }
};
using PhysicalDeviceShaderAtomicInt64FeaturesKHR = PhysicalDeviceShaderAtomicInt64Features;
struct PhysicalDeviceShaderAtomicFloatFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceShaderAtomicFloatFeaturesEXT;
    void* pNext = nullptr;
    bool shaderBufferFloat32Atomics = false;
    bool shaderBufferFloat32AtomicAdd = false;
    bool shaderBufferFloat64Atomics = false;
    bool shaderBufferFloat64AtomicAdd = false;
    bool shaderSharedFloat32Atomics = false;
    bool shaderSharedFloat32AtomicAdd = false;
    bool shaderSharedFloat64Atomics = false;
    bool shaderSharedFloat64AtomicAdd = false;
    bool shaderImageFloat32Atomics = false;
    bool shaderImageFloat32AtomicAdd = false;
    bool sparseImageFloat32Atomics = false;
    bool sparseImageFloat32AtomicAdd = false;
    operator VkPhysicalDeviceShaderAtomicFloatFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceShaderAtomicFloatFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceVertexAttributeDivisorFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesEXT;
    void* pNext = nullptr;
    bool vertexAttributeInstanceRateDivisor = false;
    bool vertexAttributeInstanceRateZeroDivisor = false;
    operator VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(this);
    }
};
struct QueueFamilyCheckpointPropertiesNV {
    StructureType sType = StructureType::eQueueFamilyCheckpointPropertiesNV;
    void* pNext = nullptr;
    PipelineStageFlags checkpointExecutionStageMask = static_cast<PipelineStageFlags>(0);
    operator VkQueueFamilyCheckpointPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(this);
    }
    operator VkQueueFamilyCheckpointPropertiesNV &() noexcept {
        return *reinterpret_cast<VkQueueFamilyCheckpointPropertiesNV*>(this);
    }
};
struct CheckpointDataNV {
    StructureType sType = StructureType::eCheckpointDataNV;
    void* pNext = nullptr;
    PipelineStageFlagBits stage = static_cast<PipelineStageFlagBits>(0);
    void* pCheckpointMarker = nullptr;
    operator VkCheckpointDataNV const &() const noexcept {
        return *reinterpret_cast<const VkCheckpointDataNV*>(this);
    }
    operator VkCheckpointDataNV &() noexcept {
        return *reinterpret_cast<VkCheckpointDataNV*>(this);
    }
};
struct PhysicalDeviceDepthStencilResolveProperties {
    StructureType sType = StructureType::ePhysicalDeviceDepthStencilResolveProperties;
    void* pNext = nullptr;
    ResolveModeFlags supportedDepthResolveModes = static_cast<ResolveModeFlags>(0);
    ResolveModeFlags supportedStencilResolveModes = static_cast<ResolveModeFlags>(0);
    bool independentResolveNone = false;
    bool independentResolve = false;
    operator VkPhysicalDeviceDepthStencilResolveProperties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(this);
    }
    operator VkPhysicalDeviceDepthStencilResolveProperties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDepthStencilResolveProperties*>(this);
    }
};
using PhysicalDeviceDepthStencilResolvePropertiesKHR = PhysicalDeviceDepthStencilResolveProperties;
struct SubpassDescriptionDepthStencilResolve {
    StructureType sType = StructureType::eSubpassDescriptionDepthStencilResolve;
    const void* pNext = nullptr;
    ResolveModeFlagBits depthResolveMode = static_cast<ResolveModeFlagBits>(0);
    ResolveModeFlagBits stencilResolveMode = static_cast<ResolveModeFlagBits>(0);
    const AttachmentReference2* pDepthStencilResolveAttachment = nullptr;
    operator VkSubpassDescriptionDepthStencilResolve const &() const noexcept {
        return *reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(this);
    }
    operator VkSubpassDescriptionDepthStencilResolve &() noexcept {
        return *reinterpret_cast<VkSubpassDescriptionDepthStencilResolve*>(this);
    }
};
using SubpassDescriptionDepthStencilResolveKHR = SubpassDescriptionDepthStencilResolve;
struct ImageViewASTCDecodeModeEXT {
    StructureType sType = StructureType::eImageViewAstcDecodeModeEXT;
    const void* pNext = nullptr;
    Format decodeMode = static_cast<Format>(0);
    operator VkImageViewASTCDecodeModeEXT const &() const noexcept {
        return *reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(this);
    }
    operator VkImageViewASTCDecodeModeEXT &() noexcept {
        return *reinterpret_cast<VkImageViewASTCDecodeModeEXT*>(this);
    }
};
struct PhysicalDeviceASTCDecodeFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceAstcDecodeFeaturesEXT;
    void* pNext = nullptr;
    bool decodeModeSharedExponent = false;
    operator VkPhysicalDeviceASTCDecodeFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceASTCDecodeFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceASTCDecodeFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceTransformFeedbackFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceTransformFeedbackFeaturesEXT;
    void* pNext = nullptr;
    bool transformFeedback = false;
    bool geometryStreams = false;
    operator VkPhysicalDeviceTransformFeedbackFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceTransformFeedbackFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceTransformFeedbackPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceTransformFeedbackPropertiesEXT;
    void* pNext = nullptr;
    uint32_t maxTransformFeedbackStreams = 0;
    uint32_t maxTransformFeedbackBuffers = 0;
    DeviceSize maxTransformFeedbackBufferSize = 0;
    uint32_t maxTransformFeedbackStreamDataSize = 0;
    uint32_t maxTransformFeedbackBufferDataSize = 0;
    uint32_t maxTransformFeedbackBufferDataStride = 0;
    bool transformFeedbackQueries = false;
    bool transformFeedbackStreamsLinesTriangles = false;
    bool transformFeedbackRasterizationStreamSelect = false;
    bool transformFeedbackDraw = false;
    operator VkPhysicalDeviceTransformFeedbackPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceTransformFeedbackPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(this);
    }
};
struct PipelineRasterizationStateStreamCreateInfoEXT {
    StructureType sType = StructureType::ePipelineRasterizationStateStreamCreateInfoEXT;
    const void* pNext = nullptr;
    PipelineRasterizationStateStreamCreateFlagsEXT flags = static_cast<PipelineRasterizationStateStreamCreateFlagsEXT>(0);
    uint32_t rasterizationStream = 0;
    operator VkPipelineRasterizationStateStreamCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(this);
    }
    operator VkPipelineRasterizationStateStreamCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineRasterizationStateStreamCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceRepresentativeFragmentTestFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceRepresentativeFragmentTestFeaturesNV;
    void* pNext = nullptr;
    bool representativeFragmentTest = false;
    operator VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(this);
    }
};
struct PipelineRepresentativeFragmentTestStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineRepresentativeFragmentTestStateCreateInfoNV;
    const void* pNext = nullptr;
    bool representativeFragmentTestEnable = false;
    operator VkPipelineRepresentativeFragmentTestStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(this);
    }
    operator VkPipelineRepresentativeFragmentTestStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceExclusiveScissorFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceExclusiveScissorFeaturesNV;
    void* pNext = nullptr;
    bool exclusiveScissor = false;
    operator VkPhysicalDeviceExclusiveScissorFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceExclusiveScissorFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExclusiveScissorFeaturesNV*>(this);
    }
};
struct PipelineViewportExclusiveScissorStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineViewportExclusiveScissorStateCreateInfoNV;
    const void* pNext = nullptr;
    uint32_t exclusiveScissorCount = 0;
    const Rect2D* pExclusiveScissors = nullptr;
    operator VkPipelineViewportExclusiveScissorStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(this);
    }
    operator VkPipelineViewportExclusiveScissorStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceCornerSampledImageFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceCornerSampledImageFeaturesNV;
    void* pNext = nullptr;
    bool cornerSampledImage = false;
    operator VkPhysicalDeviceCornerSampledImageFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceCornerSampledImageFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCornerSampledImageFeaturesNV*>(this);
    }
};
struct PhysicalDeviceComputeShaderDerivativesFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceComputeShaderDerivativesFeaturesNV;
    void* pNext = nullptr;
    bool computeDerivativeGroupQuads = false;
    bool computeDerivativeGroupLinear = false;
    operator VkPhysicalDeviceComputeShaderDerivativesFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceComputeShaderDerivativesFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(this);
    }
};
struct PhysicalDeviceFragmentShaderBarycentricFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesNV;
    void* pNext = nullptr;
    bool fragmentShaderBarycentric = false;
    operator VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(this);
    }
};
struct PhysicalDeviceShaderImageFootprintFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceShaderImageFootprintFeaturesNV;
    void* pNext = nullptr;
    bool imageFootprint = false;
    operator VkPhysicalDeviceShaderImageFootprintFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceShaderImageFootprintFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(this);
    }
};
struct PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
    void* pNext = nullptr;
    bool dedicatedAllocationImageAliasing = false;
    operator VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(this);
    }
};
struct ShadingRatePaletteNV {
    uint32_t shadingRatePaletteEntryCount = 0;
    const ShadingRatePaletteEntryNV* pShadingRatePaletteEntries = nullptr;
    operator VkShadingRatePaletteNV const &() const noexcept {
        return *reinterpret_cast<const VkShadingRatePaletteNV*>(this);
    }
    operator VkShadingRatePaletteNV &() noexcept {
        return *reinterpret_cast<VkShadingRatePaletteNV*>(this);
    }
};
struct PipelineViewportShadingRateImageStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineViewportShadingRateImageStateCreateInfoNV;
    const void* pNext = nullptr;
    bool shadingRateImageEnable = false;
    uint32_t viewportCount = 0;
    const ShadingRatePaletteNV* pShadingRatePalettes = nullptr;
    operator VkPipelineViewportShadingRateImageStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(this);
    }
    operator VkPipelineViewportShadingRateImageStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineViewportShadingRateImageStateCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceShadingRateImageFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceShadingRateImageFeaturesNV;
    void* pNext = nullptr;
    bool shadingRateImage = false;
    bool shadingRateCoarseSampleOrder = false;
    operator VkPhysicalDeviceShadingRateImageFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceShadingRateImageFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShadingRateImageFeaturesNV*>(this);
    }
};
struct PhysicalDeviceShadingRateImagePropertiesNV {
    StructureType sType = StructureType::ePhysicalDeviceShadingRateImagePropertiesNV;
    void* pNext = nullptr;
    Extent2D shadingRateTexelSize;
    uint32_t shadingRatePaletteSize = 0;
    uint32_t shadingRateMaxCoarseSamples = 0;
    operator VkPhysicalDeviceShadingRateImagePropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(this);
    }
    operator VkPhysicalDeviceShadingRateImagePropertiesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShadingRateImagePropertiesNV*>(this);
    }
};
struct CoarseSampleLocationNV {
    uint32_t pixelX = 0;
    uint32_t pixelY = 0;
    uint32_t sample = 0;
    operator VkCoarseSampleLocationNV const &() const noexcept {
        return *reinterpret_cast<const VkCoarseSampleLocationNV*>(this);
    }
    operator VkCoarseSampleLocationNV &() noexcept {
        return *reinterpret_cast<VkCoarseSampleLocationNV*>(this);
    }
};
struct CoarseSampleOrderCustomNV {
    ShadingRatePaletteEntryNV shadingRate = static_cast<ShadingRatePaletteEntryNV>(0);
    uint32_t sampleCount = 0;
    uint32_t sampleLocationCount = 0;
    const CoarseSampleLocationNV* pSampleLocations = nullptr;
    operator VkCoarseSampleOrderCustomNV const &() const noexcept {
        return *reinterpret_cast<const VkCoarseSampleOrderCustomNV*>(this);
    }
    operator VkCoarseSampleOrderCustomNV &() noexcept {
        return *reinterpret_cast<VkCoarseSampleOrderCustomNV*>(this);
    }
};
struct PipelineViewportCoarseSampleOrderStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineViewportCoarseSampleOrderStateCreateInfoNV;
    const void* pNext = nullptr;
    CoarseSampleOrderTypeNV sampleOrderType = static_cast<CoarseSampleOrderTypeNV>(0);
    uint32_t customSampleOrderCount = 0;
    const CoarseSampleOrderCustomNV* pCustomSampleOrders = nullptr;
    operator VkPipelineViewportCoarseSampleOrderStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(this);
    }
    operator VkPipelineViewportCoarseSampleOrderStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceMeshShaderFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceMeshShaderFeaturesNV;
    void* pNext = nullptr;
    bool taskShader = false;
    bool meshShader = false;
    operator VkPhysicalDeviceMeshShaderFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceMeshShaderFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMeshShaderFeaturesNV*>(this);
    }
};
struct PhysicalDeviceMeshShaderPropertiesNV {
    StructureType sType = StructureType::ePhysicalDeviceMeshShaderPropertiesNV;
    void* pNext = nullptr;
    uint32_t maxDrawMeshTasksCount = 0;
    uint32_t maxTaskWorkGroupInvocations = 0;
    uint32_t maxTaskWorkGroupSize[3] = {};
    uint32_t maxTaskTotalMemorySize = 0;
    uint32_t maxTaskOutputCount = 0;
    uint32_t maxMeshWorkGroupInvocations = 0;
    uint32_t maxMeshWorkGroupSize[3] = {};
    uint32_t maxMeshTotalMemorySize = 0;
    uint32_t maxMeshOutputVertices = 0;
    uint32_t maxMeshOutputPrimitives = 0;
    uint32_t maxMeshMultiviewViewCount = 0;
    uint32_t meshOutputPerVertexGranularity = 0;
    uint32_t meshOutputPerPrimitiveGranularity = 0;
    operator VkPhysicalDeviceMeshShaderPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(this);
    }
    operator VkPhysicalDeviceMeshShaderPropertiesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMeshShaderPropertiesNV*>(this);
    }
};
struct DrawMeshTasksIndirectCommandNV {
    uint32_t taskCount = 0;
    uint32_t firstTask = 0;
    operator VkDrawMeshTasksIndirectCommandNV const &() const noexcept {
        return *reinterpret_cast<const VkDrawMeshTasksIndirectCommandNV*>(this);
    }
    operator VkDrawMeshTasksIndirectCommandNV &() noexcept {
        return *reinterpret_cast<VkDrawMeshTasksIndirectCommandNV*>(this);
    }
};
struct RayTracingShaderGroupCreateInfoNV {
    StructureType sType = StructureType::eRayTracingShaderGroupCreateInfoNV;
    const void* pNext = nullptr;
    RayTracingShaderGroupTypeKHR type = static_cast<RayTracingShaderGroupTypeKHR>(0);
    uint32_t generalShader = 0;
    uint32_t closestHitShader = 0;
    uint32_t anyHitShader = 0;
    uint32_t intersectionShader = 0;
    operator VkRayTracingShaderGroupCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkRayTracingShaderGroupCreateInfoNV*>(this);
    }
    operator VkRayTracingShaderGroupCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkRayTracingShaderGroupCreateInfoNV*>(this);
    }
};
struct RayTracingShaderGroupCreateInfoKHR {
    StructureType sType = StructureType::eRayTracingShaderGroupCreateInfoKHR;
    const void* pNext = nullptr;
    RayTracingShaderGroupTypeKHR type = static_cast<RayTracingShaderGroupTypeKHR>(0);
    uint32_t generalShader = 0;
    uint32_t closestHitShader = 0;
    uint32_t anyHitShader = 0;
    uint32_t intersectionShader = 0;
    const void* pShaderGroupCaptureReplayHandle = nullptr;
    operator VkRayTracingShaderGroupCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkRayTracingShaderGroupCreateInfoKHR*>(this);
    }
    operator VkRayTracingShaderGroupCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkRayTracingShaderGroupCreateInfoKHR*>(this);
    }
};
struct RayTracingPipelineCreateInfoNV {
    StructureType sType = StructureType::eRayTracingPipelineCreateInfoNV;
    const void* pNext = nullptr;
    PipelineCreateFlags flags = static_cast<PipelineCreateFlags>(0);
    uint32_t stageCount = 0;
    const PipelineShaderStageCreateInfo* pStages = nullptr;
    uint32_t groupCount = 0;
    const RayTracingShaderGroupCreateInfoNV* pGroups = nullptr;
    uint32_t maxRecursionDepth = 0;
    PipelineLayout layout;
    Pipeline basePipelineHandle;
    int32_t basePipelineIndex = 0;
    operator VkRayTracingPipelineCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(this);
    }
    operator VkRayTracingPipelineCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkRayTracingPipelineCreateInfoNV*>(this);
    }
};
struct RayTracingPipelineInterfaceCreateInfoKHR {
    StructureType sType = StructureType::eRayTracingPipelineInterfaceCreateInfoKHR;
    const void* pNext = nullptr;
    uint32_t maxPayloadSize = 0;
    uint32_t maxAttributeSize = 0;
    uint32_t maxCallableSize = 0;
    operator VkRayTracingPipelineInterfaceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkRayTracingPipelineInterfaceCreateInfoKHR*>(this);
    }
    operator VkRayTracingPipelineInterfaceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkRayTracingPipelineInterfaceCreateInfoKHR*>(this);
    }
};
struct PipelineLibraryCreateInfoKHR {
    StructureType sType = StructureType::ePipelineLibraryCreateInfoKHR;
    const void* pNext = nullptr;
    uint32_t libraryCount = 0;
    const Pipeline* pLibraries = nullptr;
    operator VkPipelineLibraryCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(this);
    }
    operator VkPipelineLibraryCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkPipelineLibraryCreateInfoKHR*>(this);
    }
};
struct RayTracingPipelineCreateInfoKHR {
    StructureType sType = StructureType::eRayTracingPipelineCreateInfoKHR;
    const void* pNext = nullptr;
    PipelineCreateFlags flags = static_cast<PipelineCreateFlags>(0);
    uint32_t stageCount = 0;
    const PipelineShaderStageCreateInfo* pStages = nullptr;
    uint32_t groupCount = 0;
    const RayTracingShaderGroupCreateInfoKHR* pGroups = nullptr;
    uint32_t maxRecursionDepth = 0;
    PipelineLibraryCreateInfoKHR libraries;
    const RayTracingPipelineInterfaceCreateInfoKHR* pLibraryInterface = nullptr;
    PipelineLayout layout;
    Pipeline basePipelineHandle;
    int32_t basePipelineIndex = 0;
    operator VkRayTracingPipelineCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(this);
    }
    operator VkRayTracingPipelineCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkRayTracingPipelineCreateInfoKHR*>(this);
    }
};
struct GeometryTrianglesNV {
    StructureType sType = StructureType::eGeometryTrianglesNV;
    const void* pNext = nullptr;
    Buffer vertexData;
    DeviceSize vertexOffset = 0;
    uint32_t vertexCount = 0;
    DeviceSize vertexStride = 0;
    Format vertexFormat = static_cast<Format>(0);
    Buffer indexData;
    DeviceSize indexOffset = 0;
    uint32_t indexCount = 0;
    IndexType indexType = static_cast<IndexType>(0);
    Buffer transformData;
    DeviceSize transformOffset = 0;
    operator VkGeometryTrianglesNV const &() const noexcept {
        return *reinterpret_cast<const VkGeometryTrianglesNV*>(this);
    }
    operator VkGeometryTrianglesNV &() noexcept {
        return *reinterpret_cast<VkGeometryTrianglesNV*>(this);
    }
};
struct GeometryAABBNV {
    StructureType sType = StructureType::eGeometryAabbNV;
    const void* pNext = nullptr;
    Buffer aabbData;
    uint32_t numAABBs = 0;
    uint32_t stride = 0;
    DeviceSize offset = 0;
    operator VkGeometryAABBNV const &() const noexcept {
        return *reinterpret_cast<const VkGeometryAABBNV*>(this);
    }
    operator VkGeometryAABBNV &() noexcept {
        return *reinterpret_cast<VkGeometryAABBNV*>(this);
    }
};
struct GeometryDataNV {
    GeometryTrianglesNV triangles;
    GeometryAABBNV aabbs;
    operator VkGeometryDataNV const &() const noexcept {
        return *reinterpret_cast<const VkGeometryDataNV*>(this);
    }
    operator VkGeometryDataNV &() noexcept {
        return *reinterpret_cast<VkGeometryDataNV*>(this);
    }
};
struct GeometryNV {
    StructureType sType = StructureType::eGeometryNV;
    const void* pNext = nullptr;
    GeometryTypeKHR geometryType = static_cast<GeometryTypeKHR>(0);
    GeometryDataNV geometry;
    GeometryFlagsKHR flags = static_cast<GeometryFlagsKHR>(0);
    operator VkGeometryNV const &() const noexcept {
        return *reinterpret_cast<const VkGeometryNV*>(this);
    }
    operator VkGeometryNV &() noexcept {
        return *reinterpret_cast<VkGeometryNV*>(this);
    }
};
struct AccelerationStructureInfoNV {
    StructureType sType = StructureType::eAccelerationStructureInfoNV;
    const void* pNext = nullptr;
    AccelerationStructureTypeNV type;
    BuildAccelerationStructureFlagsNV flags = static_cast<BuildAccelerationStructureFlagsNV>(0);
    uint32_t instanceCount = 0;
    uint32_t geometryCount = 0;
    const GeometryNV* pGeometries = nullptr;
    operator VkAccelerationStructureInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureInfoNV*>(this);
    }
    operator VkAccelerationStructureInfoNV &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureInfoNV*>(this);
    }
};
struct AccelerationStructureCreateInfoNV {
    StructureType sType = StructureType::eAccelerationStructureCreateInfoNV;
    const void* pNext = nullptr;
    DeviceSize compactedSize = 0;
    AccelerationStructureInfoNV info;
    operator VkAccelerationStructureCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(this);
    }
    operator VkAccelerationStructureCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureCreateInfoNV*>(this);
    }
};
struct BindAccelerationStructureMemoryInfoKHR {
    StructureType sType = StructureType::eBindAccelerationStructureMemoryInfoKHR;
    const void* pNext = nullptr;
    AccelerationStructureKHR accelerationStructure;
    DeviceMemory memory;
    DeviceSize memoryOffset = 0;
    uint32_t deviceIndexCount = 0;
    const uint32_t* pDeviceIndices = nullptr;
    operator VkBindAccelerationStructureMemoryInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkBindAccelerationStructureMemoryInfoKHR*>(this);
    }
    operator VkBindAccelerationStructureMemoryInfoKHR &() noexcept {
        return *reinterpret_cast<VkBindAccelerationStructureMemoryInfoKHR*>(this);
    }
};
using BindAccelerationStructureMemoryInfoNV = BindAccelerationStructureMemoryInfoKHR;
struct WriteDescriptorSetAccelerationStructureKHR {
    StructureType sType = StructureType::eWriteDescriptorSetAccelerationStructureKHR;
    const void* pNext = nullptr;
    uint32_t accelerationStructureCount = 0;
    const AccelerationStructureKHR* pAccelerationStructures = nullptr;
    operator VkWriteDescriptorSetAccelerationStructureKHR const &() const noexcept {
        return *reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(this);
    }
    operator VkWriteDescriptorSetAccelerationStructureKHR &() noexcept {
        return *reinterpret_cast<VkWriteDescriptorSetAccelerationStructureKHR*>(this);
    }
};
using WriteDescriptorSetAccelerationStructureNV = WriteDescriptorSetAccelerationStructureKHR;
struct AccelerationStructureMemoryRequirementsInfoKHR {
    StructureType sType = StructureType::eAccelerationStructureMemoryRequirementsInfoKHR;
    const void* pNext = nullptr;
    AccelerationStructureMemoryRequirementsTypeKHR type = static_cast<AccelerationStructureMemoryRequirementsTypeKHR>(0);
    AccelerationStructureBuildTypeKHR buildType = static_cast<AccelerationStructureBuildTypeKHR>(0);
    AccelerationStructureKHR accelerationStructure;
    operator VkAccelerationStructureMemoryRequirementsInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoKHR*>(this);
    }
    operator VkAccelerationStructureMemoryRequirementsInfoKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureMemoryRequirementsInfoKHR*>(this);
    }
};
struct AccelerationStructureMemoryRequirementsInfoNV {
    StructureType sType = StructureType::eAccelerationStructureMemoryRequirementsInfoNV;
    const void* pNext = nullptr;
    AccelerationStructureMemoryRequirementsTypeNV type;
    AccelerationStructureNV accelerationStructure;
    operator VkAccelerationStructureMemoryRequirementsInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(this);
    }
    operator VkAccelerationStructureMemoryRequirementsInfoNV &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureMemoryRequirementsInfoNV*>(this);
    }
};
struct PhysicalDeviceRayTracingFeaturesKHR {
    StructureType sType = StructureType::ePhysicalDeviceRayTracingFeaturesKHR;
    void* pNext = nullptr;
    bool rayTracing = false;
    bool rayTracingShaderGroupHandleCaptureReplay = false;
    bool rayTracingShaderGroupHandleCaptureReplayMixed = false;
    bool rayTracingAccelerationStructureCaptureReplay = false;
    bool rayTracingIndirectTraceRays = false;
    bool rayTracingIndirectAccelerationStructureBuild = false;
    bool rayTracingHostAccelerationStructureCommands = false;
    bool rayQuery = false;
    bool rayTracingPrimitiveCulling = false;
    operator VkPhysicalDeviceRayTracingFeaturesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceRayTracingFeaturesKHR*>(this);
    }
    operator VkPhysicalDeviceRayTracingFeaturesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceRayTracingFeaturesKHR*>(this);
    }
};
struct PhysicalDeviceRayTracingPropertiesKHR {
    StructureType sType = StructureType::ePhysicalDeviceRayTracingPropertiesKHR;
    void* pNext = nullptr;
    uint32_t shaderGroupHandleSize = 0;
    uint32_t maxRecursionDepth = 0;
    uint32_t maxShaderGroupStride = 0;
    uint32_t shaderGroupBaseAlignment = 0;
    uint64_t maxGeometryCount = 0;
    uint64_t maxInstanceCount = 0;
    uint64_t maxPrimitiveCount = 0;
    uint32_t maxDescriptorSetAccelerationStructures = 0;
    uint32_t shaderGroupHandleCaptureReplaySize = 0;
    operator VkPhysicalDeviceRayTracingPropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesKHR*>(this);
    }
    operator VkPhysicalDeviceRayTracingPropertiesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceRayTracingPropertiesKHR*>(this);
    }
};
struct PhysicalDeviceRayTracingPropertiesNV {
    StructureType sType = StructureType::ePhysicalDeviceRayTracingPropertiesNV;
    void* pNext = nullptr;
    uint32_t shaderGroupHandleSize = 0;
    uint32_t maxRecursionDepth = 0;
    uint32_t maxShaderGroupStride = 0;
    uint32_t shaderGroupBaseAlignment = 0;
    uint64_t maxGeometryCount = 0;
    uint64_t maxInstanceCount = 0;
    uint64_t maxTriangleCount = 0;
    uint32_t maxDescriptorSetAccelerationStructures = 0;
    operator VkPhysicalDeviceRayTracingPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(this);
    }
    operator VkPhysicalDeviceRayTracingPropertiesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceRayTracingPropertiesNV*>(this);
    }
};
struct StridedBufferRegionKHR {
    Buffer buffer;
    DeviceSize offset = 0;
    DeviceSize stride = 0;
    DeviceSize size = 0;
    operator VkStridedBufferRegionKHR const &() const noexcept {
        return *reinterpret_cast<const VkStridedBufferRegionKHR*>(this);
    }
    operator VkStridedBufferRegionKHR &() noexcept {
        return *reinterpret_cast<VkStridedBufferRegionKHR*>(this);
    }
};
struct TraceRaysIndirectCommandKHR {
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t depth = 0;
    operator VkTraceRaysIndirectCommandKHR const &() const noexcept {
        return *reinterpret_cast<const VkTraceRaysIndirectCommandKHR*>(this);
    }
    operator VkTraceRaysIndirectCommandKHR &() noexcept {
        return *reinterpret_cast<VkTraceRaysIndirectCommandKHR*>(this);
    }
};
struct DrmFormatModifierPropertiesEXT {
    uint64_t drmFormatModifier = 0;
    uint32_t drmFormatModifierPlaneCount = 0;
    FormatFeatureFlags drmFormatModifierTilingFeatures = static_cast<FormatFeatureFlags>(0);
    operator VkDrmFormatModifierPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkDrmFormatModifierPropertiesEXT*>(this);
    }
    operator VkDrmFormatModifierPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkDrmFormatModifierPropertiesEXT*>(this);
    }
};
struct DrmFormatModifierPropertiesListEXT {
    StructureType sType = StructureType::eDrmFormatModifierPropertiesListEXT;
    void* pNext = nullptr;
    uint32_t drmFormatModifierCount = 0;
    DrmFormatModifierPropertiesEXT* pDrmFormatModifierProperties = nullptr;
    operator VkDrmFormatModifierPropertiesListEXT const &() const noexcept {
        return *reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(this);
    }
    operator VkDrmFormatModifierPropertiesListEXT &() noexcept {
        return *reinterpret_cast<VkDrmFormatModifierPropertiesListEXT*>(this);
    }
};
struct PhysicalDeviceImageDrmFormatModifierInfoEXT {
    StructureType sType = StructureType::ePhysicalDeviceImageDrmFormatModifierInfoEXT;
    const void* pNext = nullptr;
    uint64_t drmFormatModifier = 0;
    SharingMode sharingMode = static_cast<SharingMode>(0);
    uint32_t queueFamilyIndexCount = 0;
    const uint32_t* pQueueFamilyIndices = nullptr;
    operator VkPhysicalDeviceImageDrmFormatModifierInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(this);
    }
    operator VkPhysicalDeviceImageDrmFormatModifierInfoEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(this);
    }
};
struct ImageDrmFormatModifierListCreateInfoEXT {
    StructureType sType = StructureType::eImageDrmFormatModifierListCreateInfoEXT;
    const void* pNext = nullptr;
    uint32_t drmFormatModifierCount = 0;
    const uint64_t* pDrmFormatModifiers = nullptr;
    operator VkImageDrmFormatModifierListCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(this);
    }
    operator VkImageDrmFormatModifierListCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkImageDrmFormatModifierListCreateInfoEXT*>(this);
    }
};
struct ImageDrmFormatModifierExplicitCreateInfoEXT {
    StructureType sType = StructureType::eImageDrmFormatModifierExplicitCreateInfoEXT;
    const void* pNext = nullptr;
    uint64_t drmFormatModifier = 0;
    uint32_t drmFormatModifierPlaneCount = 0;
    const SubresourceLayout* pPlaneLayouts = nullptr;
    operator VkImageDrmFormatModifierExplicitCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(this);
    }
    operator VkImageDrmFormatModifierExplicitCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkImageDrmFormatModifierExplicitCreateInfoEXT*>(this);
    }
};
struct ImageDrmFormatModifierPropertiesEXT {
    StructureType sType = StructureType::eImageDrmFormatModifierPropertiesEXT;
    void* pNext = nullptr;
    uint64_t drmFormatModifier = 0;
    operator VkImageDrmFormatModifierPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkImageDrmFormatModifierPropertiesEXT*>(this);
    }
    operator VkImageDrmFormatModifierPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkImageDrmFormatModifierPropertiesEXT*>(this);
    }
};
struct ImageStencilUsageCreateInfo {
    StructureType sType = StructureType::eImageStencilUsageCreateInfo;
    const void* pNext = nullptr;
    ImageUsageFlags stencilUsage = static_cast<ImageUsageFlags>(0);
    operator VkImageStencilUsageCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkImageStencilUsageCreateInfo*>(this);
    }
    operator VkImageStencilUsageCreateInfo &() noexcept {
        return *reinterpret_cast<VkImageStencilUsageCreateInfo*>(this);
    }
};
using ImageStencilUsageCreateInfoEXT = ImageStencilUsageCreateInfo;
struct DeviceMemoryOverallocationCreateInfoAMD {
    StructureType sType = StructureType::eDeviceMemoryOverallocationCreateInfoAMD;
    const void* pNext = nullptr;
    MemoryOverallocationBehaviorAMD overallocationBehavior = static_cast<MemoryOverallocationBehaviorAMD>(0);
    operator VkDeviceMemoryOverallocationCreateInfoAMD const &() const noexcept {
        return *reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(this);
    }
    operator VkDeviceMemoryOverallocationCreateInfoAMD &() noexcept {
        return *reinterpret_cast<VkDeviceMemoryOverallocationCreateInfoAMD*>(this);
    }
};
struct PhysicalDeviceFragmentDensityMapFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceFragmentDensityMapFeaturesEXT;
    void* pNext = nullptr;
    bool fragmentDensityMap = false;
    bool fragmentDensityMapDynamic = false;
    bool fragmentDensityMapNonSubsampledImages = false;
    operator VkPhysicalDeviceFragmentDensityMapFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceFragmentDensityMapFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceFragmentDensityMap2FeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceFragmentDensityMap2FeaturesEXT;
    void* pNext = nullptr;
    bool fragmentDensityMapDeferred = false;
    operator VkPhysicalDeviceFragmentDensityMap2FeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceFragmentDensityMap2FeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(this);
    }
};
struct PhysicalDeviceFragmentDensityMapPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceFragmentDensityMapPropertiesEXT;
    void* pNext = nullptr;
    Extent2D minFragmentDensityTexelSize;
    Extent2D maxFragmentDensityTexelSize;
    bool fragmentDensityInvocations = false;
    operator VkPhysicalDeviceFragmentDensityMapPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceFragmentDensityMapPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceFragmentDensityMap2PropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceFragmentDensityMap2PropertiesEXT;
    void* pNext = nullptr;
    bool subsampledLoads = false;
    bool subsampledCoarseReconstructionEarlyAccess = false;
    uint32_t maxSubsampledArrayLayers = 0;
    uint32_t maxDescriptorSetSubsampledSamplers = 0;
    operator VkPhysicalDeviceFragmentDensityMap2PropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceFragmentDensityMap2PropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(this);
    }
};
struct RenderPassFragmentDensityMapCreateInfoEXT {
    StructureType sType = StructureType::eRenderPassFragmentDensityMapCreateInfoEXT;
    const void* pNext = nullptr;
    AttachmentReference fragmentDensityMapAttachment;
    operator VkRenderPassFragmentDensityMapCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(this);
    }
    operator VkRenderPassFragmentDensityMapCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkRenderPassFragmentDensityMapCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceScalarBlockLayoutFeatures {
    StructureType sType = StructureType::ePhysicalDeviceScalarBlockLayoutFeatures;
    void* pNext = nullptr;
    bool scalarBlockLayout = false;
    operator VkPhysicalDeviceScalarBlockLayoutFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(this);
    }
    operator VkPhysicalDeviceScalarBlockLayoutFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceScalarBlockLayoutFeatures*>(this);
    }
};
using PhysicalDeviceScalarBlockLayoutFeaturesEXT = PhysicalDeviceScalarBlockLayoutFeatures;
struct SurfaceProtectedCapabilitiesKHR {
    StructureType sType = StructureType::eSurfaceProtectedCapabilitiesKHR;
    const void* pNext = nullptr;
    bool supportsProtected = false;
    operator VkSurfaceProtectedCapabilitiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(this);
    }
    operator VkSurfaceProtectedCapabilitiesKHR &() noexcept {
        return *reinterpret_cast<VkSurfaceProtectedCapabilitiesKHR*>(this);
    }
};
struct PhysicalDeviceUniformBufferStandardLayoutFeatures {
    StructureType sType = StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeatures;
    void* pNext = nullptr;
    bool uniformBufferStandardLayout = false;
    operator VkPhysicalDeviceUniformBufferStandardLayoutFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(this);
    }
    operator VkPhysicalDeviceUniformBufferStandardLayoutFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(this);
    }
};
using PhysicalDeviceUniformBufferStandardLayoutFeaturesKHR = PhysicalDeviceUniformBufferStandardLayoutFeatures;
struct PhysicalDeviceDepthClipEnableFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceDepthClipEnableFeaturesEXT;
    void* pNext = nullptr;
    bool depthClipEnable = false;
    operator VkPhysicalDeviceDepthClipEnableFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceDepthClipEnableFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(this);
    }
};
struct PipelineRasterizationDepthClipStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineRasterizationDepthClipStateCreateInfoEXT;
    const void* pNext = nullptr;
    PipelineRasterizationDepthClipStateCreateFlagsEXT flags = static_cast<PipelineRasterizationDepthClipStateCreateFlagsEXT>(0);
    bool depthClipEnable = false;
    operator VkPipelineRasterizationDepthClipStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(this);
    }
    operator VkPipelineRasterizationDepthClipStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceMemoryBudgetPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceMemoryBudgetPropertiesEXT;
    void* pNext = nullptr;
    DeviceSize heapBudget[MAX_MEMORY_HEAPS] = {};
    DeviceSize heapUsage[MAX_MEMORY_HEAPS] = {};
    operator VkPhysicalDeviceMemoryBudgetPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceMemoryBudgetPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceMemoryPriorityFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceMemoryPriorityFeaturesEXT;
    void* pNext = nullptr;
    bool memoryPriority = false;
    operator VkPhysicalDeviceMemoryPriorityFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceMemoryPriorityFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(this);
    }
};
struct MemoryPriorityAllocateInfoEXT {
    StructureType sType = StructureType::eMemoryPriorityAllocateInfoEXT;
    const void* pNext = nullptr;
    float priority = 0.f;
    operator VkMemoryPriorityAllocateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(this);
    }
    operator VkMemoryPriorityAllocateInfoEXT &() noexcept {
        return *reinterpret_cast<VkMemoryPriorityAllocateInfoEXT*>(this);
    }
};
struct PhysicalDeviceBufferDeviceAddressFeatures {
    StructureType sType = StructureType::ePhysicalDeviceBufferDeviceAddressFeatures;
    void* pNext = nullptr;
    bool bufferDeviceAddress = false;
    bool bufferDeviceAddressCaptureReplay = false;
    bool bufferDeviceAddressMultiDevice = false;
    operator VkPhysicalDeviceBufferDeviceAddressFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(this);
    }
    operator VkPhysicalDeviceBufferDeviceAddressFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(this);
    }
};
using PhysicalDeviceBufferDeviceAddressFeaturesKHR = PhysicalDeviceBufferDeviceAddressFeatures;
struct PhysicalDeviceBufferDeviceAddressFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesEXT;
    void* pNext = nullptr;
    bool bufferDeviceAddress = false;
    bool bufferDeviceAddressCaptureReplay = false;
    bool bufferDeviceAddressMultiDevice = false;
    operator VkPhysicalDeviceBufferDeviceAddressFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceBufferDeviceAddressFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(this);
    }
};
using PhysicalDeviceBufferAddressFeaturesEXT = PhysicalDeviceBufferDeviceAddressFeaturesEXT;
struct BufferDeviceAddressInfo {
    StructureType sType = StructureType::eBufferDeviceAddressInfo;
    const void* pNext = nullptr;
    Buffer buffer;
    operator VkBufferDeviceAddressInfo const &() const noexcept {
        return *reinterpret_cast<const VkBufferDeviceAddressInfo*>(this);
    }
    operator VkBufferDeviceAddressInfo &() noexcept {
        return *reinterpret_cast<VkBufferDeviceAddressInfo*>(this);
    }
};
using BufferDeviceAddressInfoKHR = BufferDeviceAddressInfo;
using BufferDeviceAddressInfoEXT = BufferDeviceAddressInfo;
struct BufferOpaqueCaptureAddressCreateInfo {
    StructureType sType = StructureType::eBufferOpaqueCaptureAddressCreateInfo;
    const void* pNext = nullptr;
    uint64_t opaqueCaptureAddress = 0;
    operator VkBufferOpaqueCaptureAddressCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(this);
    }
    operator VkBufferOpaqueCaptureAddressCreateInfo &() noexcept {
        return *reinterpret_cast<VkBufferOpaqueCaptureAddressCreateInfo*>(this);
    }
};
using BufferOpaqueCaptureAddressCreateInfoKHR = BufferOpaqueCaptureAddressCreateInfo;
struct BufferDeviceAddressCreateInfoEXT {
    StructureType sType = StructureType::eBufferDeviceAddressCreateInfoEXT;
    const void* pNext = nullptr;
    DeviceAddress deviceAddress = 0;
    operator VkBufferDeviceAddressCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(this);
    }
    operator VkBufferDeviceAddressCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkBufferDeviceAddressCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceImageViewImageFormatInfoEXT {
    StructureType sType = StructureType::ePhysicalDeviceImageViewImageFormatInfoEXT;
    void* pNext = nullptr;
    ImageViewType imageViewType = static_cast<ImageViewType>(0);
    operator VkPhysicalDeviceImageViewImageFormatInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(this);
    }
    operator VkPhysicalDeviceImageViewImageFormatInfoEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceImageViewImageFormatInfoEXT*>(this);
    }
};
struct FilterCubicImageViewImageFormatPropertiesEXT {
    StructureType sType = StructureType::eFilterCubicImageViewImageFormatPropertiesEXT;
    void* pNext = nullptr;
    bool filterCubic = false;
    bool filterCubicMinmax = false;
    operator VkFilterCubicImageViewImageFormatPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(this);
    }
    operator VkFilterCubicImageViewImageFormatPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkFilterCubicImageViewImageFormatPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceImagelessFramebufferFeatures {
    StructureType sType = StructureType::ePhysicalDeviceImagelessFramebufferFeatures;
    void* pNext = nullptr;
    bool imagelessFramebuffer = false;
    operator VkPhysicalDeviceImagelessFramebufferFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(this);
    }
    operator VkPhysicalDeviceImagelessFramebufferFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceImagelessFramebufferFeatures*>(this);
    }
};
using PhysicalDeviceImagelessFramebufferFeaturesKHR = PhysicalDeviceImagelessFramebufferFeatures;
struct FramebufferAttachmentImageInfo {
    StructureType sType = StructureType::eFramebufferAttachmentImageInfo;
    const void* pNext = nullptr;
    ImageCreateFlags flags = static_cast<ImageCreateFlags>(0);
    ImageUsageFlags usage = static_cast<ImageUsageFlags>(0);
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t layerCount = 0;
    uint32_t viewFormatCount = 0;
    const Format* pViewFormats = nullptr;
    operator VkFramebufferAttachmentImageInfo const &() const noexcept {
        return *reinterpret_cast<const VkFramebufferAttachmentImageInfo*>(this);
    }
    operator VkFramebufferAttachmentImageInfo &() noexcept {
        return *reinterpret_cast<VkFramebufferAttachmentImageInfo*>(this);
    }
};
struct FramebufferAttachmentsCreateInfo {
    StructureType sType = StructureType::eFramebufferAttachmentsCreateInfo;
    const void* pNext = nullptr;
    uint32_t attachmentImageInfoCount = 0;
    const FramebufferAttachmentImageInfo* pAttachmentImageInfos = nullptr;
    operator VkFramebufferAttachmentsCreateInfo const &() const noexcept {
        return *reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(this);
    }
    operator VkFramebufferAttachmentsCreateInfo &() noexcept {
        return *reinterpret_cast<VkFramebufferAttachmentsCreateInfo*>(this);
    }
};
using FramebufferAttachmentsCreateInfoKHR = FramebufferAttachmentsCreateInfo;
using FramebufferAttachmentImageInfoKHR = FramebufferAttachmentImageInfo;
struct RenderPassAttachmentBeginInfo {
    StructureType sType = StructureType::eRenderPassAttachmentBeginInfo;
    const void* pNext = nullptr;
    uint32_t attachmentCount = 0;
    const ImageView* pAttachments = nullptr;
    operator VkRenderPassAttachmentBeginInfo const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(this);
    }
    operator VkRenderPassAttachmentBeginInfo &() noexcept {
        return *reinterpret_cast<VkRenderPassAttachmentBeginInfo*>(this);
    }
};
using RenderPassAttachmentBeginInfoKHR = RenderPassAttachmentBeginInfo;
struct PhysicalDeviceTextureCompressionASTCHDRFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeaturesEXT;
    void* pNext = nullptr;
    bool textureCompressionASTC_HDR = false;
    operator VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceCooperativeMatrixFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceCooperativeMatrixFeaturesNV;
    void* pNext = nullptr;
    bool cooperativeMatrix = false;
    bool cooperativeMatrixRobustBufferAccess = false;
    operator VkPhysicalDeviceCooperativeMatrixFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceCooperativeMatrixFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(this);
    }
};
struct PhysicalDeviceCooperativeMatrixPropertiesNV {
    StructureType sType = StructureType::ePhysicalDeviceCooperativeMatrixPropertiesNV;
    void* pNext = nullptr;
    ShaderStageFlags cooperativeMatrixSupportedStages = static_cast<ShaderStageFlags>(0);
    operator VkPhysicalDeviceCooperativeMatrixPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(this);
    }
    operator VkPhysicalDeviceCooperativeMatrixPropertiesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(this);
    }
};
struct CooperativeMatrixPropertiesNV {
    StructureType sType = StructureType::eCooperativeMatrixPropertiesNV;
    void* pNext = nullptr;
    uint32_t MSize = 0;
    uint32_t NSize = 0;
    uint32_t KSize = 0;
    ComponentTypeNV AType = static_cast<ComponentTypeNV>(0);
    ComponentTypeNV BType = static_cast<ComponentTypeNV>(0);
    ComponentTypeNV CType = static_cast<ComponentTypeNV>(0);
    ComponentTypeNV DType = static_cast<ComponentTypeNV>(0);
    ScopeNV scope = static_cast<ScopeNV>(0);
    operator VkCooperativeMatrixPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkCooperativeMatrixPropertiesNV*>(this);
    }
    operator VkCooperativeMatrixPropertiesNV &() noexcept {
        return *reinterpret_cast<VkCooperativeMatrixPropertiesNV*>(this);
    }
};
struct PhysicalDeviceYcbcrImageArraysFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceYcbcrImageArraysFeaturesEXT;
    void* pNext = nullptr;
    bool ycbcrImageArrays = false;
    operator VkPhysicalDeviceYcbcrImageArraysFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceYcbcrImageArraysFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(this);
    }
};
struct ImageViewHandleInfoNVX {
    StructureType sType = StructureType::eImageViewHandleInfoNVX;
    const void* pNext = nullptr;
    ImageView imageView;
    DescriptorType descriptorType = static_cast<DescriptorType>(0);
    Sampler sampler;
    operator VkImageViewHandleInfoNVX const &() const noexcept {
        return *reinterpret_cast<const VkImageViewHandleInfoNVX*>(this);
    }
    operator VkImageViewHandleInfoNVX &() noexcept {
        return *reinterpret_cast<VkImageViewHandleInfoNVX*>(this);
    }
};
struct ImageViewAddressPropertiesNVX {
    StructureType sType = StructureType::eImageViewAddressPropertiesNVX;
    void* pNext = nullptr;
    DeviceAddress deviceAddress = 0;
    DeviceSize size = 0;
    operator VkImageViewAddressPropertiesNVX const &() const noexcept {
        return *reinterpret_cast<const VkImageViewAddressPropertiesNVX*>(this);
    }
    operator VkImageViewAddressPropertiesNVX &() noexcept {
        return *reinterpret_cast<VkImageViewAddressPropertiesNVX*>(this);
    }
};
#if defined(VK_USE_PLATFORM_GGP)
struct PresentFrameTokenGGP {
    StructureType sType = StructureType::ePresentFrameTokenGGP;
    const void* pNext = nullptr;
    GgpFrameToken frameToken;
    operator VkPresentFrameTokenGGP const &() const noexcept {
        return *reinterpret_cast<const VkPresentFrameTokenGGP*>(this);
    }
    operator VkPresentFrameTokenGGP &() noexcept {
        return *reinterpret_cast<VkPresentFrameTokenGGP*>(this);
    }
};
#endif // VK_USE_PLATFORM_GGP
struct PipelineCreationFeedbackEXT {
    PipelineCreationFeedbackFlagsEXT flags = static_cast<PipelineCreationFeedbackFlagsEXT>(0);
    uint64_t duration = 0;
    operator VkPipelineCreationFeedbackEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCreationFeedbackEXT*>(this);
    }
    operator VkPipelineCreationFeedbackEXT &() noexcept {
        return *reinterpret_cast<VkPipelineCreationFeedbackEXT*>(this);
    }
};
struct PipelineCreationFeedbackCreateInfoEXT {
    StructureType sType = StructureType::ePipelineCreationFeedbackCreateInfoEXT;
    const void* pNext = nullptr;
    PipelineCreationFeedbackEXT* pPipelineCreationFeedback = nullptr;
    uint32_t pipelineStageCreationFeedbackCount = 0;
    PipelineCreationFeedbackEXT* pPipelineStageCreationFeedbacks = nullptr;
    operator VkPipelineCreationFeedbackCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCreationFeedbackCreateInfoEXT*>(this);
    }
    operator VkPipelineCreationFeedbackCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineCreationFeedbackCreateInfoEXT*>(this);
    }
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct SurfaceFullScreenExclusiveInfoEXT {
    StructureType sType = StructureType::eSurfaceFullScreenExclusiveInfoEXT;
    void* pNext = nullptr;
    FullScreenExclusiveEXT fullScreenExclusive = static_cast<FullScreenExclusiveEXT>(0);
    operator VkSurfaceFullScreenExclusiveInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(this);
    }
    operator VkSurfaceFullScreenExclusiveInfoEXT &() noexcept {
        return *reinterpret_cast<VkSurfaceFullScreenExclusiveInfoEXT*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct SurfaceFullScreenExclusiveWin32InfoEXT {
    StructureType sType = StructureType::eSurfaceFullScreenExclusiveWin32InfoEXT;
    const void* pNext = nullptr;
    HMONITOR hmonitor;
    operator VkSurfaceFullScreenExclusiveWin32InfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(this);
    }
    operator VkSurfaceFullScreenExclusiveWin32InfoEXT &() noexcept {
        return *reinterpret_cast<VkSurfaceFullScreenExclusiveWin32InfoEXT*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct SurfaceCapabilitiesFullScreenExclusiveEXT {
    StructureType sType = StructureType::eSurfaceCapabilitiesFullScreenExclusiveEXT;
    void* pNext = nullptr;
    bool fullScreenExclusiveSupported = false;
    operator VkSurfaceCapabilitiesFullScreenExclusiveEXT const &() const noexcept {
        return *reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(this);
    }
    operator VkSurfaceCapabilitiesFullScreenExclusiveEXT &() noexcept {
        return *reinterpret_cast<VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(this);
    }
};
#endif // VK_USE_PLATFORM_WIN32_KHR
struct PhysicalDevicePerformanceQueryFeaturesKHR {
    StructureType sType = StructureType::ePhysicalDevicePerformanceQueryFeaturesKHR;
    void* pNext = nullptr;
    bool performanceCounterQueryPools = false;
    bool performanceCounterMultipleQueryPools = false;
    operator VkPhysicalDevicePerformanceQueryFeaturesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(this);
    }
    operator VkPhysicalDevicePerformanceQueryFeaturesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR*>(this);
    }
};
struct PhysicalDevicePerformanceQueryPropertiesKHR {
    StructureType sType = StructureType::ePhysicalDevicePerformanceQueryPropertiesKHR;
    void* pNext = nullptr;
    bool allowCommandBufferQueryCopies = false;
    operator VkPhysicalDevicePerformanceQueryPropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(this);
    }
    operator VkPhysicalDevicePerformanceQueryPropertiesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePerformanceQueryPropertiesKHR*>(this);
    }
};
struct PerformanceCounterKHR {
    StructureType sType = StructureType::ePerformanceCounterKHR;
    const void* pNext = nullptr;
    PerformanceCounterUnitKHR unit = static_cast<PerformanceCounterUnitKHR>(0);
    PerformanceCounterScopeKHR scope = static_cast<PerformanceCounterScopeKHR>(0);
    PerformanceCounterStorageKHR storage = static_cast<PerformanceCounterStorageKHR>(0);
    uint8_t uuid[UUID_SIZE] = {};
    operator VkPerformanceCounterKHR const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceCounterKHR*>(this);
    }
    operator VkPerformanceCounterKHR &() noexcept {
        return *reinterpret_cast<VkPerformanceCounterKHR*>(this);
    }
};
struct PerformanceCounterDescriptionKHR {
    StructureType sType = StructureType::ePerformanceCounterDescriptionKHR;
    const void* pNext = nullptr;
    PerformanceCounterDescriptionFlagsKHR flags = static_cast<PerformanceCounterDescriptionFlagsKHR>(0);
    char name[MAX_DESCRIPTION_SIZE] = {};
    char category[MAX_DESCRIPTION_SIZE] = {};
    char description[MAX_DESCRIPTION_SIZE] = {};
    operator VkPerformanceCounterDescriptionKHR const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceCounterDescriptionKHR*>(this);
    }
    operator VkPerformanceCounterDescriptionKHR &() noexcept {
        return *reinterpret_cast<VkPerformanceCounterDescriptionKHR*>(this);
    }
};
struct QueryPoolPerformanceCreateInfoKHR {
    StructureType sType = StructureType::eQueryPoolPerformanceCreateInfoKHR;
    const void* pNext = nullptr;
    uint32_t queueFamilyIndex = 0;
    uint32_t counterIndexCount = 0;
    const uint32_t* pCounterIndices = nullptr;
    operator VkQueryPoolPerformanceCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(this);
    }
    operator VkQueryPoolPerformanceCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkQueryPoolPerformanceCreateInfoKHR*>(this);
    }
};
union PerformanceCounterResultKHR {
    int32_t int32;
    int64_t int64;
    uint32_t uint32;
    uint64_t uint64;
    float float32;
    double float64;
};
struct AcquireProfilingLockInfoKHR {
    StructureType sType = StructureType::eAcquireProfilingLockInfoKHR;
    const void* pNext = nullptr;
    AcquireProfilingLockFlagsKHR flags = static_cast<AcquireProfilingLockFlagsKHR>(0);
    uint64_t timeout = 0;
    operator VkAcquireProfilingLockInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(this);
    }
    operator VkAcquireProfilingLockInfoKHR &() noexcept {
        return *reinterpret_cast<VkAcquireProfilingLockInfoKHR*>(this);
    }
};
struct PerformanceQuerySubmitInfoKHR {
    StructureType sType = StructureType::ePerformanceQuerySubmitInfoKHR;
    const void* pNext = nullptr;
    uint32_t counterPassIndex = 0;
    operator VkPerformanceQuerySubmitInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(this);
    }
    operator VkPerformanceQuerySubmitInfoKHR &() noexcept {
        return *reinterpret_cast<VkPerformanceQuerySubmitInfoKHR*>(this);
    }
};
struct HeadlessSurfaceCreateInfoEXT {
    StructureType sType = StructureType::eHeadlessSurfaceCreateInfoEXT;
    const void* pNext = nullptr;
    HeadlessSurfaceCreateFlagsEXT flags = static_cast<HeadlessSurfaceCreateFlagsEXT>(0);
    operator VkHeadlessSurfaceCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(this);
    }
    operator VkHeadlessSurfaceCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkHeadlessSurfaceCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceCoverageReductionModeFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceCoverageReductionModeFeaturesNV;
    void* pNext = nullptr;
    bool coverageReductionMode = false;
    operator VkPhysicalDeviceCoverageReductionModeFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceCoverageReductionModeFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(this);
    }
};
struct PipelineCoverageReductionStateCreateInfoNV {
    StructureType sType = StructureType::ePipelineCoverageReductionStateCreateInfoNV;
    const void* pNext = nullptr;
    PipelineCoverageReductionStateCreateFlagsNV flags = static_cast<PipelineCoverageReductionStateCreateFlagsNV>(0);
    CoverageReductionModeNV coverageReductionMode = static_cast<CoverageReductionModeNV>(0);
    operator VkPipelineCoverageReductionStateCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(this);
    }
    operator VkPipelineCoverageReductionStateCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkPipelineCoverageReductionStateCreateInfoNV*>(this);
    }
};
struct FramebufferMixedSamplesCombinationNV {
    StructureType sType = StructureType::eFramebufferMixedSamplesCombinationNV;
    void* pNext = nullptr;
    CoverageReductionModeNV coverageReductionMode = static_cast<CoverageReductionModeNV>(0);
    SampleCountFlagBits rasterizationSamples = static_cast<SampleCountFlagBits>(0);
    SampleCountFlags depthStencilSamples = static_cast<SampleCountFlags>(0);
    SampleCountFlags colorSamples = static_cast<SampleCountFlags>(0);
    operator VkFramebufferMixedSamplesCombinationNV const &() const noexcept {
        return *reinterpret_cast<const VkFramebufferMixedSamplesCombinationNV*>(this);
    }
    operator VkFramebufferMixedSamplesCombinationNV &() noexcept {
        return *reinterpret_cast<VkFramebufferMixedSamplesCombinationNV*>(this);
    }
};
struct PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL {
    StructureType sType = StructureType::ePhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;
    void* pNext = nullptr;
    bool shaderIntegerFunctions2 = false;
    operator VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(this);
    }
    operator VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(this);
    }
};
union PerformanceValueDataINTEL {
    uint32_t value32;
    uint64_t value64;
    float valueFloat;
    bool valueBool;
    const char* valueString;
};
struct PerformanceValueINTEL {
    PerformanceValueTypeINTEL type = static_cast<PerformanceValueTypeINTEL>(0);
    PerformanceValueDataINTEL data;
    operator VkPerformanceValueINTEL const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceValueINTEL*>(this);
    }
    operator VkPerformanceValueINTEL &() noexcept {
        return *reinterpret_cast<VkPerformanceValueINTEL*>(this);
    }
};
struct InitializePerformanceApiInfoINTEL {
    StructureType sType = StructureType::eInitializePerformanceApiInfoINTEL;
    const void* pNext = nullptr;
    void* pUserData = nullptr;
    operator VkInitializePerformanceApiInfoINTEL const &() const noexcept {
        return *reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(this);
    }
    operator VkInitializePerformanceApiInfoINTEL &() noexcept {
        return *reinterpret_cast<VkInitializePerformanceApiInfoINTEL*>(this);
    }
};
struct QueryPoolPerformanceQueryCreateInfoINTEL {
    StructureType sType = StructureType::eQueryPoolPerformanceQueryCreateInfoINTEL;
    const void* pNext = nullptr;
    QueryPoolSamplingModeINTEL performanceCountersSampling = static_cast<QueryPoolSamplingModeINTEL>(0);
    operator VkQueryPoolPerformanceQueryCreateInfoINTEL const &() const noexcept {
        return *reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(this);
    }
    operator VkQueryPoolPerformanceQueryCreateInfoINTEL &() noexcept {
        return *reinterpret_cast<VkQueryPoolPerformanceQueryCreateInfoINTEL*>(this);
    }
};
using QueryPoolCreateInfoINTEL = QueryPoolPerformanceQueryCreateInfoINTEL;
struct PerformanceMarkerInfoINTEL {
    StructureType sType = StructureType::ePerformanceMarkerInfoINTEL;
    const void* pNext = nullptr;
    uint64_t marker = 0;
    operator VkPerformanceMarkerInfoINTEL const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(this);
    }
    operator VkPerformanceMarkerInfoINTEL &() noexcept {
        return *reinterpret_cast<VkPerformanceMarkerInfoINTEL*>(this);
    }
};
struct PerformanceStreamMarkerInfoINTEL {
    StructureType sType = StructureType::ePerformanceStreamMarkerInfoINTEL;
    const void* pNext = nullptr;
    uint32_t marker = 0;
    operator VkPerformanceStreamMarkerInfoINTEL const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(this);
    }
    operator VkPerformanceStreamMarkerInfoINTEL &() noexcept {
        return *reinterpret_cast<VkPerformanceStreamMarkerInfoINTEL*>(this);
    }
};
struct PerformanceOverrideInfoINTEL {
    StructureType sType = StructureType::ePerformanceOverrideInfoINTEL;
    const void* pNext = nullptr;
    PerformanceOverrideTypeINTEL type = static_cast<PerformanceOverrideTypeINTEL>(0);
    bool enable = false;
    uint64_t parameter = 0;
    operator VkPerformanceOverrideInfoINTEL const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(this);
    }
    operator VkPerformanceOverrideInfoINTEL &() noexcept {
        return *reinterpret_cast<VkPerformanceOverrideInfoINTEL*>(this);
    }
};
struct PerformanceConfigurationAcquireInfoINTEL {
    StructureType sType = StructureType::ePerformanceConfigurationAcquireInfoINTEL;
    const void* pNext = nullptr;
    PerformanceConfigurationTypeINTEL type = static_cast<PerformanceConfigurationTypeINTEL>(0);
    operator VkPerformanceConfigurationAcquireInfoINTEL const &() const noexcept {
        return *reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(this);
    }
    operator VkPerformanceConfigurationAcquireInfoINTEL &() noexcept {
        return *reinterpret_cast<VkPerformanceConfigurationAcquireInfoINTEL*>(this);
    }
};
struct PhysicalDeviceShaderClockFeaturesKHR {
    StructureType sType = StructureType::ePhysicalDeviceShaderClockFeaturesKHR;
    void* pNext = nullptr;
    bool shaderSubgroupClock = false;
    bool shaderDeviceClock = false;
    operator VkPhysicalDeviceShaderClockFeaturesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(this);
    }
    operator VkPhysicalDeviceShaderClockFeaturesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(this);
    }
};
struct PhysicalDeviceIndexTypeUint8FeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceIndexTypeUint8FeaturesEXT;
    void* pNext = nullptr;
    bool indexTypeUint8 = false;
    operator VkPhysicalDeviceIndexTypeUint8FeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceIndexTypeUint8FeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(this);
    }
};
struct PhysicalDeviceShaderSMBuiltinsPropertiesNV {
    StructureType sType = StructureType::ePhysicalDeviceShaderSmBuiltinsPropertiesNV;
    void* pNext = nullptr;
    uint32_t shaderSMCount = 0;
    uint32_t shaderWarpsPerSM = 0;
    operator VkPhysicalDeviceShaderSMBuiltinsPropertiesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(this);
    }
    operator VkPhysicalDeviceShaderSMBuiltinsPropertiesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(this);
    }
};
struct PhysicalDeviceShaderSMBuiltinsFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceShaderSmBuiltinsFeaturesNV;
    void* pNext = nullptr;
    bool shaderSMBuiltins = false;
    operator VkPhysicalDeviceShaderSMBuiltinsFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceShaderSMBuiltinsFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(this);
    }
};
struct PhysicalDeviceFragmentShaderInterlockFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceFragmentShaderInterlockFeaturesEXT;
    void* pNext = nullptr;
    bool fragmentShaderSampleInterlock = false;
    bool fragmentShaderPixelInterlock = false;
    bool fragmentShaderShadingRateInterlock = false;
    operator VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceSeparateDepthStencilLayoutsFeatures {
    StructureType sType = StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeatures;
    void* pNext = nullptr;
    bool separateDepthStencilLayouts = false;
    operator VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(this);
    }
    operator VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(this);
    }
};
using PhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR = PhysicalDeviceSeparateDepthStencilLayoutsFeatures;
struct AttachmentReferenceStencilLayout {
    StructureType sType = StructureType::eAttachmentReferenceStencilLayout;
    void* pNext = nullptr;
    ImageLayout stencilLayout = static_cast<ImageLayout>(0);
    operator VkAttachmentReferenceStencilLayout const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(this);
    }
    operator VkAttachmentReferenceStencilLayout &() noexcept {
        return *reinterpret_cast<VkAttachmentReferenceStencilLayout*>(this);
    }
};
using AttachmentReferenceStencilLayoutKHR = AttachmentReferenceStencilLayout;
struct AttachmentDescriptionStencilLayout {
    StructureType sType = StructureType::eAttachmentDescriptionStencilLayout;
    void* pNext = nullptr;
    ImageLayout stencilInitialLayout = static_cast<ImageLayout>(0);
    ImageLayout stencilFinalLayout = static_cast<ImageLayout>(0);
    operator VkAttachmentDescriptionStencilLayout const &() const noexcept {
        return *reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(this);
    }
    operator VkAttachmentDescriptionStencilLayout &() noexcept {
        return *reinterpret_cast<VkAttachmentDescriptionStencilLayout*>(this);
    }
};
using AttachmentDescriptionStencilLayoutKHR = AttachmentDescriptionStencilLayout;
struct PhysicalDevicePipelineExecutablePropertiesFeaturesKHR {
    StructureType sType = StructureType::ePhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
    void* pNext = nullptr;
    bool pipelineExecutableInfo = false;
    operator VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(this);
    }
    operator VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(this);
    }
};
struct PipelineInfoKHR {
    StructureType sType = StructureType::ePipelineInfoKHR;
    const void* pNext = nullptr;
    Pipeline pipeline;
    operator VkPipelineInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkPipelineInfoKHR*>(this);
    }
    operator VkPipelineInfoKHR &() noexcept {
        return *reinterpret_cast<VkPipelineInfoKHR*>(this);
    }
};
struct PipelineExecutablePropertiesKHR {
    StructureType sType = StructureType::ePipelineExecutablePropertiesKHR;
    void* pNext = nullptr;
    ShaderStageFlags stages = static_cast<ShaderStageFlags>(0);
    char name[MAX_DESCRIPTION_SIZE] = {};
    char description[MAX_DESCRIPTION_SIZE] = {};
    uint32_t subgroupSize = 0;
    operator VkPipelineExecutablePropertiesKHR const &() const noexcept {
        return *reinterpret_cast<const VkPipelineExecutablePropertiesKHR*>(this);
    }
    operator VkPipelineExecutablePropertiesKHR &() noexcept {
        return *reinterpret_cast<VkPipelineExecutablePropertiesKHR*>(this);
    }
};
struct PipelineExecutableInfoKHR {
    StructureType sType = StructureType::ePipelineExecutableInfoKHR;
    const void* pNext = nullptr;
    Pipeline pipeline;
    uint32_t executableIndex = 0;
    operator VkPipelineExecutableInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkPipelineExecutableInfoKHR*>(this);
    }
    operator VkPipelineExecutableInfoKHR &() noexcept {
        return *reinterpret_cast<VkPipelineExecutableInfoKHR*>(this);
    }
};
union PipelineExecutableStatisticValueKHR {
    bool b32;
    int64_t i64;
    uint64_t u64;
    double f64;
};
struct PipelineExecutableStatisticKHR {
    StructureType sType = StructureType::ePipelineExecutableStatisticKHR;
    void* pNext = nullptr;
    char name[MAX_DESCRIPTION_SIZE] = {};
    char description[MAX_DESCRIPTION_SIZE] = {};
    PipelineExecutableStatisticFormatKHR format = static_cast<PipelineExecutableStatisticFormatKHR>(0);
    PipelineExecutableStatisticValueKHR value;
    operator VkPipelineExecutableStatisticKHR const &() const noexcept {
        return *reinterpret_cast<const VkPipelineExecutableStatisticKHR*>(this);
    }
    operator VkPipelineExecutableStatisticKHR &() noexcept {
        return *reinterpret_cast<VkPipelineExecutableStatisticKHR*>(this);
    }
};
struct PipelineExecutableInternalRepresentationKHR {
    StructureType sType = StructureType::ePipelineExecutableInternalRepresentationKHR;
    void* pNext = nullptr;
    char name[MAX_DESCRIPTION_SIZE] = {};
    char description[MAX_DESCRIPTION_SIZE] = {};
    bool isText = false;
    size_t dataSize = 0;
    void* pData = nullptr;
    operator VkPipelineExecutableInternalRepresentationKHR const &() const noexcept {
        return *reinterpret_cast<const VkPipelineExecutableInternalRepresentationKHR*>(this);
    }
    operator VkPipelineExecutableInternalRepresentationKHR &() noexcept {
        return *reinterpret_cast<VkPipelineExecutableInternalRepresentationKHR*>(this);
    }
};
struct PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT;
    void* pNext = nullptr;
    bool shaderDemoteToHelperInvocation = false;
    operator VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceTexelBufferAlignmentFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceTexelBufferAlignmentFeaturesEXT;
    void* pNext = nullptr;
    bool texelBufferAlignment = false;
    operator VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceTexelBufferAlignmentPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceTexelBufferAlignmentPropertiesEXT;
    void* pNext = nullptr;
    DeviceSize storageTexelBufferOffsetAlignmentBytes = 0;
    bool storageTexelBufferOffsetSingleTexelAlignment = false;
    DeviceSize uniformTexelBufferOffsetAlignmentBytes = 0;
    bool uniformTexelBufferOffsetSingleTexelAlignment = false;
    operator VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceSubgroupSizeControlFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceSubgroupSizeControlFeaturesEXT;
    void* pNext = nullptr;
    bool subgroupSizeControl = false;
    bool computeFullSubgroups = false;
    operator VkPhysicalDeviceSubgroupSizeControlFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceSubgroupSizeControlFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceSubgroupSizeControlPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceSubgroupSizeControlPropertiesEXT;
    void* pNext = nullptr;
    uint32_t minSubgroupSize = 0;
    uint32_t maxSubgroupSize = 0;
    uint32_t maxComputeWorkgroupSubgroups = 0;
    ShaderStageFlags requiredSubgroupSizeStages = static_cast<ShaderStageFlags>(0);
    operator VkPhysicalDeviceSubgroupSizeControlPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceSubgroupSizeControlPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlPropertiesEXT*>(this);
    }
};
struct PipelineShaderStageRequiredSubgroupSizeCreateInfoEXT {
    StructureType sType = StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfoEXT;
    void* pNext = nullptr;
    uint32_t requiredSubgroupSize = 0;
    operator VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT*>(this);
    }
    operator VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT*>(this);
    }
};
struct MemoryOpaqueCaptureAddressAllocateInfo {
    StructureType sType = StructureType::eMemoryOpaqueCaptureAddressAllocateInfo;
    const void* pNext = nullptr;
    uint64_t opaqueCaptureAddress = 0;
    operator VkMemoryOpaqueCaptureAddressAllocateInfo const &() const noexcept {
        return *reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(this);
    }
    operator VkMemoryOpaqueCaptureAddressAllocateInfo &() noexcept {
        return *reinterpret_cast<VkMemoryOpaqueCaptureAddressAllocateInfo*>(this);
    }
};
using MemoryOpaqueCaptureAddressAllocateInfoKHR = MemoryOpaqueCaptureAddressAllocateInfo;
struct DeviceMemoryOpaqueCaptureAddressInfo {
    StructureType sType = StructureType::eDeviceMemoryOpaqueCaptureAddressInfo;
    const void* pNext = nullptr;
    DeviceMemory memory;
    operator VkDeviceMemoryOpaqueCaptureAddressInfo const &() const noexcept {
        return *reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(this);
    }
    operator VkDeviceMemoryOpaqueCaptureAddressInfo &() noexcept {
        return *reinterpret_cast<VkDeviceMemoryOpaqueCaptureAddressInfo*>(this);
    }
};
using DeviceMemoryOpaqueCaptureAddressInfoKHR = DeviceMemoryOpaqueCaptureAddressInfo;
struct PhysicalDeviceLineRasterizationFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceLineRasterizationFeaturesEXT;
    void* pNext = nullptr;
    bool rectangularLines = false;
    bool bresenhamLines = false;
    bool smoothLines = false;
    bool stippledRectangularLines = false;
    bool stippledBresenhamLines = false;
    bool stippledSmoothLines = false;
    operator VkPhysicalDeviceLineRasterizationFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceLineRasterizationFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceLineRasterizationPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceLineRasterizationPropertiesEXT;
    void* pNext = nullptr;
    uint32_t lineSubPixelPrecisionBits = 0;
    operator VkPhysicalDeviceLineRasterizationPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceLineRasterizationPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceLineRasterizationPropertiesEXT*>(this);
    }
};
struct PipelineRasterizationLineStateCreateInfoEXT {
    StructureType sType = StructureType::ePipelineRasterizationLineStateCreateInfoEXT;
    const void* pNext = nullptr;
    LineRasterizationModeEXT lineRasterizationMode = static_cast<LineRasterizationModeEXT>(0);
    bool stippledLineEnable = false;
    uint32_t lineStippleFactor = 0;
    uint16_t lineStipplePattern = 0;
    operator VkPipelineRasterizationLineStateCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(this);
    }
    operator VkPipelineRasterizationLineStateCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkPipelineRasterizationLineStateCreateInfoEXT*>(this);
    }
};
struct PhysicalDevicePipelineCreationCacheControlFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDevicePipelineCreationCacheControlFeaturesEXT;
    void* pNext = nullptr;
    bool pipelineCreationCacheControl = false;
    operator VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT*>(this);
    }
    operator VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT*>(this);
    }
};
struct PhysicalDeviceVulkan11Features {
    StructureType sType = StructureType::ePhysicalDeviceVulkan11Features;
    void* pNext = nullptr;
    bool storageBuffer16BitAccess = false;
    bool uniformAndStorageBuffer16BitAccess = false;
    bool storagePushConstant16 = false;
    bool storageInputOutput16 = false;
    bool multiview = false;
    bool multiviewGeometryShader = false;
    bool multiviewTessellationShader = false;
    bool variablePointersStorageBuffer = false;
    bool variablePointers = false;
    bool protectedMemory = false;
    bool samplerYcbcrConversion = false;
    bool shaderDrawParameters = false;
    operator VkPhysicalDeviceVulkan11Features const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(this);
    }
    operator VkPhysicalDeviceVulkan11Features &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVulkan11Features*>(this);
    }
};
struct PhysicalDeviceVulkan11Properties {
    StructureType sType = StructureType::ePhysicalDeviceVulkan11Properties;
    void* pNext = nullptr;
    uint8_t deviceUUID[UUID_SIZE] = {};
    uint8_t driverUUID[UUID_SIZE] = {};
    uint8_t deviceLUID[LUID_SIZE] = {};
    uint32_t deviceNodeMask = 0;
    bool deviceLUIDValid = false;
    uint32_t subgroupSize = 0;
    ShaderStageFlags subgroupSupportedStages = static_cast<ShaderStageFlags>(0);
    SubgroupFeatureFlags subgroupSupportedOperations = static_cast<SubgroupFeatureFlags>(0);
    bool subgroupQuadOperationsInAllStages = false;
    PointClippingBehavior pointClippingBehavior = static_cast<PointClippingBehavior>(0);
    uint32_t maxMultiviewViewCount = 0;
    uint32_t maxMultiviewInstanceIndex = 0;
    bool protectedNoFault = false;
    uint32_t maxPerSetDescriptors = 0;
    DeviceSize maxMemoryAllocationSize = 0;
    operator VkPhysicalDeviceVulkan11Properties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(this);
    }
    operator VkPhysicalDeviceVulkan11Properties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVulkan11Properties*>(this);
    }
};
struct PhysicalDeviceVulkan12Features {
    StructureType sType = StructureType::ePhysicalDeviceVulkan12Features;
    void* pNext = nullptr;
    bool samplerMirrorClampToEdge = false;
    bool drawIndirectCount = false;
    bool storageBuffer8BitAccess = false;
    bool uniformAndStorageBuffer8BitAccess = false;
    bool storagePushConstant8 = false;
    bool shaderBufferInt64Atomics = false;
    bool shaderSharedInt64Atomics = false;
    bool shaderFloat16 = false;
    bool shaderInt8 = false;
    bool descriptorIndexing = false;
    bool shaderInputAttachmentArrayDynamicIndexing = false;
    bool shaderUniformTexelBufferArrayDynamicIndexing = false;
    bool shaderStorageTexelBufferArrayDynamicIndexing = false;
    bool shaderUniformBufferArrayNonUniformIndexing = false;
    bool shaderSampledImageArrayNonUniformIndexing = false;
    bool shaderStorageBufferArrayNonUniformIndexing = false;
    bool shaderStorageImageArrayNonUniformIndexing = false;
    bool shaderInputAttachmentArrayNonUniformIndexing = false;
    bool shaderUniformTexelBufferArrayNonUniformIndexing = false;
    bool shaderStorageTexelBufferArrayNonUniformIndexing = false;
    bool descriptorBindingUniformBufferUpdateAfterBind = false;
    bool descriptorBindingSampledImageUpdateAfterBind = false;
    bool descriptorBindingStorageImageUpdateAfterBind = false;
    bool descriptorBindingStorageBufferUpdateAfterBind = false;
    bool descriptorBindingUniformTexelBufferUpdateAfterBind = false;
    bool descriptorBindingStorageTexelBufferUpdateAfterBind = false;
    bool descriptorBindingUpdateUnusedWhilePending = false;
    bool descriptorBindingPartiallyBound = false;
    bool descriptorBindingVariableDescriptorCount = false;
    bool runtimeDescriptorArray = false;
    bool samplerFilterMinmax = false;
    bool scalarBlockLayout = false;
    bool imagelessFramebuffer = false;
    bool uniformBufferStandardLayout = false;
    bool shaderSubgroupExtendedTypes = false;
    bool separateDepthStencilLayouts = false;
    bool hostQueryReset = false;
    bool timelineSemaphore = false;
    bool bufferDeviceAddress = false;
    bool bufferDeviceAddressCaptureReplay = false;
    bool bufferDeviceAddressMultiDevice = false;
    bool vulkanMemoryModel = false;
    bool vulkanMemoryModelDeviceScope = false;
    bool vulkanMemoryModelAvailabilityVisibilityChains = false;
    bool shaderOutputViewportIndex = false;
    bool shaderOutputLayer = false;
    bool subgroupBroadcastDynamicId = false;
    operator VkPhysicalDeviceVulkan12Features const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(this);
    }
    operator VkPhysicalDeviceVulkan12Features &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(this);
    }
};
struct PhysicalDeviceVulkan12Properties {
    StructureType sType = StructureType::ePhysicalDeviceVulkan12Properties;
    void* pNext = nullptr;
    DriverId driverID = static_cast<DriverId>(0);
    char driverName[MAX_DRIVER_NAME_SIZE] = {};
    char driverInfo[MAX_DRIVER_INFO_SIZE] = {};
    ConformanceVersion conformanceVersion;
    ShaderFloatControlsIndependence denormBehaviorIndependence = static_cast<ShaderFloatControlsIndependence>(0);
    ShaderFloatControlsIndependence roundingModeIndependence = static_cast<ShaderFloatControlsIndependence>(0);
    bool shaderSignedZeroInfNanPreserveFloat16 = false;
    bool shaderSignedZeroInfNanPreserveFloat32 = false;
    bool shaderSignedZeroInfNanPreserveFloat64 = false;
    bool shaderDenormPreserveFloat16 = false;
    bool shaderDenormPreserveFloat32 = false;
    bool shaderDenormPreserveFloat64 = false;
    bool shaderDenormFlushToZeroFloat16 = false;
    bool shaderDenormFlushToZeroFloat32 = false;
    bool shaderDenormFlushToZeroFloat64 = false;
    bool shaderRoundingModeRTEFloat16 = false;
    bool shaderRoundingModeRTEFloat32 = false;
    bool shaderRoundingModeRTEFloat64 = false;
    bool shaderRoundingModeRTZFloat16 = false;
    bool shaderRoundingModeRTZFloat32 = false;
    bool shaderRoundingModeRTZFloat64 = false;
    uint32_t maxUpdateAfterBindDescriptorsInAllPools = 0;
    bool shaderUniformBufferArrayNonUniformIndexingNative = false;
    bool shaderSampledImageArrayNonUniformIndexingNative = false;
    bool shaderStorageBufferArrayNonUniformIndexingNative = false;
    bool shaderStorageImageArrayNonUniformIndexingNative = false;
    bool shaderInputAttachmentArrayNonUniformIndexingNative = false;
    bool robustBufferAccessUpdateAfterBind = false;
    bool quadDivergentImplicitLod = false;
    uint32_t maxPerStageDescriptorUpdateAfterBindSamplers = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages = 0;
    uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments = 0;
    uint32_t maxPerStageUpdateAfterBindResources = 0;
    uint32_t maxDescriptorSetUpdateAfterBindSamplers = 0;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers = 0;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 0;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers = 0;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 0;
    uint32_t maxDescriptorSetUpdateAfterBindSampledImages = 0;
    uint32_t maxDescriptorSetUpdateAfterBindStorageImages = 0;
    uint32_t maxDescriptorSetUpdateAfterBindInputAttachments = 0;
    ResolveModeFlags supportedDepthResolveModes = static_cast<ResolveModeFlags>(0);
    ResolveModeFlags supportedStencilResolveModes = static_cast<ResolveModeFlags>(0);
    bool independentResolveNone = false;
    bool independentResolve = false;
    bool filterMinmaxSingleComponentFormats = false;
    bool filterMinmaxImageComponentMapping = false;
    uint64_t maxTimelineSemaphoreValueDifference = 0;
    SampleCountFlags framebufferIntegerColorSampleCounts = static_cast<SampleCountFlags>(0);
    operator VkPhysicalDeviceVulkan12Properties const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(this);
    }
    operator VkPhysicalDeviceVulkan12Properties &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceVulkan12Properties*>(this);
    }
};
struct PipelineCompilerControlCreateInfoAMD {
    StructureType sType = StructureType::ePipelineCompilerControlCreateInfoAMD;
    const void* pNext = nullptr;
    PipelineCompilerControlFlagsAMD compilerControlFlags = static_cast<PipelineCompilerControlFlagsAMD>(0);
    operator VkPipelineCompilerControlCreateInfoAMD const &() const noexcept {
        return *reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(this);
    }
    operator VkPipelineCompilerControlCreateInfoAMD &() noexcept {
        return *reinterpret_cast<VkPipelineCompilerControlCreateInfoAMD*>(this);
    }
};
struct PhysicalDeviceCoherentMemoryFeaturesAMD {
    StructureType sType = StructureType::ePhysicalDeviceCoherentMemoryFeaturesAMD;
    void* pNext = nullptr;
    bool deviceCoherentMemory = false;
    operator VkPhysicalDeviceCoherentMemoryFeaturesAMD const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(this);
    }
    operator VkPhysicalDeviceCoherentMemoryFeaturesAMD &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(this);
    }
};
struct PhysicalDeviceToolPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceToolPropertiesEXT;
    void* pNext = nullptr;
    char name[MAX_EXTENSION_NAME_SIZE] = {};
    char version[MAX_EXTENSION_NAME_SIZE] = {};
    ToolPurposeFlagsEXT purposes = static_cast<ToolPurposeFlagsEXT>(0);
    char description[MAX_DESCRIPTION_SIZE] = {};
    char layer[MAX_EXTENSION_NAME_SIZE] = {};
    operator VkPhysicalDeviceToolPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceToolPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceToolPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceToolPropertiesEXT*>(this);
    }
};
struct SamplerCustomBorderColorCreateInfoEXT {
    StructureType sType = StructureType::eSamplerCustomBorderColorCreateInfoEXT;
    const void* pNext = nullptr;
    ClearColorValue customBorderColor;
    Format format = static_cast<Format>(0);
    operator VkSamplerCustomBorderColorCreateInfoEXT const &() const noexcept {
        return *reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(this);
    }
    operator VkSamplerCustomBorderColorCreateInfoEXT &() noexcept {
        return *reinterpret_cast<VkSamplerCustomBorderColorCreateInfoEXT*>(this);
    }
};
struct PhysicalDeviceCustomBorderColorPropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceCustomBorderColorPropertiesEXT;
    void* pNext = nullptr;
    uint32_t maxCustomBorderColorSamplers = 0;
    operator VkPhysicalDeviceCustomBorderColorPropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceCustomBorderColorPropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(this);
    }
};
struct PhysicalDeviceCustomBorderColorFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceCustomBorderColorFeaturesEXT;
    void* pNext = nullptr;
    bool customBorderColors = false;
    bool customBorderColorWithoutFormat = false;
    operator VkPhysicalDeviceCustomBorderColorFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceCustomBorderColorFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(this);
    }
};
union DeviceOrHostAddressKHR {
    DeviceAddress deviceAddress;
    void* hostAddress;
};
union DeviceOrHostAddressConstKHR {
    DeviceAddress deviceAddress;
    const void* hostAddress;
};
struct AccelerationStructureGeometryTrianglesDataKHR {
    StructureType sType = StructureType::eAccelerationStructureGeometryTrianglesDataKHR;
    const void* pNext = nullptr;
    Format vertexFormat = static_cast<Format>(0);
    DeviceOrHostAddressConstKHR vertexData;
    DeviceSize vertexStride = 0;
    IndexType indexType = static_cast<IndexType>(0);
    DeviceOrHostAddressConstKHR indexData;
    DeviceOrHostAddressConstKHR transformData;
    operator VkAccelerationStructureGeometryTrianglesDataKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(this);
    }
    operator VkAccelerationStructureGeometryTrianglesDataKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureGeometryTrianglesDataKHR*>(this);
    }
};
struct AccelerationStructureGeometryAabbsDataKHR {
    StructureType sType = StructureType::eAccelerationStructureGeometryAabbsDataKHR;
    const void* pNext = nullptr;
    DeviceOrHostAddressConstKHR data;
    DeviceSize stride = 0;
    operator VkAccelerationStructureGeometryAabbsDataKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureGeometryAabbsDataKHR*>(this);
    }
    operator VkAccelerationStructureGeometryAabbsDataKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureGeometryAabbsDataKHR*>(this);
    }
};
struct AccelerationStructureGeometryInstancesDataKHR {
    StructureType sType = StructureType::eAccelerationStructureGeometryInstancesDataKHR;
    const void* pNext = nullptr;
    bool arrayOfPointers = false;
    DeviceOrHostAddressConstKHR data;
    operator VkAccelerationStructureGeometryInstancesDataKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureGeometryInstancesDataKHR*>(this);
    }
    operator VkAccelerationStructureGeometryInstancesDataKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureGeometryInstancesDataKHR*>(this);
    }
};
union AccelerationStructureGeometryDataKHR {
    AccelerationStructureGeometryTrianglesDataKHR triangles;
    AccelerationStructureGeometryAabbsDataKHR aabbs;
    AccelerationStructureGeometryInstancesDataKHR instances;
};
struct AccelerationStructureGeometryKHR {
    StructureType sType = StructureType::eAccelerationStructureGeometryKHR;
    const void* pNext = nullptr;
    GeometryTypeKHR geometryType = static_cast<GeometryTypeKHR>(0);
    AccelerationStructureGeometryDataKHR geometry;
    GeometryFlagsKHR flags = static_cast<GeometryFlagsKHR>(0);
    operator VkAccelerationStructureGeometryKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureGeometryKHR*>(this);
    }
    operator VkAccelerationStructureGeometryKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureGeometryKHR*>(this);
    }
};
struct AccelerationStructureBuildGeometryInfoKHR {
    StructureType sType = StructureType::eAccelerationStructureBuildGeometryInfoKHR;
    const void* pNext = nullptr;
    AccelerationStructureTypeKHR type = static_cast<AccelerationStructureTypeKHR>(0);
    BuildAccelerationStructureFlagsKHR flags = static_cast<BuildAccelerationStructureFlagsKHR>(0);
    bool update = false;
    AccelerationStructureKHR srcAccelerationStructure;
    AccelerationStructureKHR dstAccelerationStructure;
    bool geometryArrayOfPointers = false;
    uint32_t geometryCount = 0;
    const AccelerationStructureGeometryKHR* const* ppGeometries = nullptr;
    DeviceOrHostAddressKHR scratchData;
    operator VkAccelerationStructureBuildGeometryInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(this);
    }
    operator VkAccelerationStructureBuildGeometryInfoKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureBuildGeometryInfoKHR*>(this);
    }
};
struct AccelerationStructureBuildOffsetInfoKHR {
    uint32_t primitiveCount = 0;
    uint32_t primitiveOffset = 0;
    uint32_t firstVertex = 0;
    uint32_t transformOffset = 0;
    operator VkAccelerationStructureBuildOffsetInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureBuildOffsetInfoKHR*>(this);
    }
    operator VkAccelerationStructureBuildOffsetInfoKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureBuildOffsetInfoKHR*>(this);
    }
};
struct AccelerationStructureCreateGeometryTypeInfoKHR {
    StructureType sType = StructureType::eAccelerationStructureCreateGeometryTypeInfoKHR;
    const void* pNext = nullptr;
    GeometryTypeKHR geometryType = static_cast<GeometryTypeKHR>(0);
    uint32_t maxPrimitiveCount = 0;
    IndexType indexType = static_cast<IndexType>(0);
    uint32_t maxVertexCount = 0;
    Format vertexFormat = static_cast<Format>(0);
    bool allowsTransforms = false;
    operator VkAccelerationStructureCreateGeometryTypeInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureCreateGeometryTypeInfoKHR*>(this);
    }
    operator VkAccelerationStructureCreateGeometryTypeInfoKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureCreateGeometryTypeInfoKHR*>(this);
    }
};
struct AccelerationStructureCreateInfoKHR {
    StructureType sType = StructureType::eAccelerationStructureCreateInfoKHR;
    const void* pNext = nullptr;
    DeviceSize compactedSize = 0;
    AccelerationStructureTypeKHR type = static_cast<AccelerationStructureTypeKHR>(0);
    BuildAccelerationStructureFlagsKHR flags = static_cast<BuildAccelerationStructureFlagsKHR>(0);
    uint32_t maxGeometryCount = 0;
    const AccelerationStructureCreateGeometryTypeInfoKHR* pGeometryInfos = nullptr;
    DeviceAddress deviceAddress = 0;
    operator VkAccelerationStructureCreateInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(this);
    }
    operator VkAccelerationStructureCreateInfoKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureCreateInfoKHR*>(this);
    }
};
struct AabbPositionsKHR {
    float minX = 0.f;
    float minY = 0.f;
    float minZ = 0.f;
    float maxX = 0.f;
    float maxY = 0.f;
    float maxZ = 0.f;
    operator VkAabbPositionsKHR const &() const noexcept {
        return *reinterpret_cast<const VkAabbPositionsKHR*>(this);
    }
    operator VkAabbPositionsKHR &() noexcept {
        return *reinterpret_cast<VkAabbPositionsKHR*>(this);
    }
};
using AabbPositionsNV = AabbPositionsKHR;
struct TransformMatrixKHR {
    float matrix[3][4] = {};
    operator VkTransformMatrixKHR const &() const noexcept {
        return *reinterpret_cast<const VkTransformMatrixKHR*>(this);
    }
    operator VkTransformMatrixKHR &() noexcept {
        return *reinterpret_cast<VkTransformMatrixKHR*>(this);
    }
};
using TransformMatrixNV = TransformMatrixKHR;
struct AccelerationStructureInstanceKHR {
    TransformMatrixKHR transform;
    uint32_t instanceCustomIndex = 0;
    uint32_t mask = 0;
    uint32_t instanceShaderBindingTableRecordOffset = 0;
    GeometryInstanceFlagsKHR flags = static_cast<GeometryInstanceFlagsKHR>(0);
    uint64_t accelerationStructureReference = 0;
    operator VkAccelerationStructureInstanceKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(this);
    }
    operator VkAccelerationStructureInstanceKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureInstanceKHR*>(this);
    }
};
using AccelerationStructureInstanceNV = AccelerationStructureInstanceKHR;
struct AccelerationStructureDeviceAddressInfoKHR {
    StructureType sType = StructureType::eAccelerationStructureDeviceAddressInfoKHR;
    const void* pNext = nullptr;
    AccelerationStructureKHR accelerationStructure;
    operator VkAccelerationStructureDeviceAddressInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(this);
    }
    operator VkAccelerationStructureDeviceAddressInfoKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureDeviceAddressInfoKHR*>(this);
    }
};
struct AccelerationStructureVersionKHR {
    StructureType sType = StructureType::eAccelerationStructureVersionKHR;
    const void* pNext = nullptr;
    const uint8_t* versionData = nullptr;
    operator VkAccelerationStructureVersionKHR const &() const noexcept {
        return *reinterpret_cast<const VkAccelerationStructureVersionKHR*>(this);
    }
    operator VkAccelerationStructureVersionKHR &() noexcept {
        return *reinterpret_cast<VkAccelerationStructureVersionKHR*>(this);
    }
};
struct CopyAccelerationStructureInfoKHR {
    StructureType sType = StructureType::eCopyAccelerationStructureInfoKHR;
    const void* pNext = nullptr;
    AccelerationStructureKHR src;
    AccelerationStructureKHR dst;
    CopyAccelerationStructureModeKHR mode = static_cast<CopyAccelerationStructureModeKHR>(0);
    operator VkCopyAccelerationStructureInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(this);
    }
    operator VkCopyAccelerationStructureInfoKHR &() noexcept {
        return *reinterpret_cast<VkCopyAccelerationStructureInfoKHR*>(this);
    }
};
struct CopyAccelerationStructureToMemoryInfoKHR {
    StructureType sType = StructureType::eCopyAccelerationStructureToMemoryInfoKHR;
    const void* pNext = nullptr;
    AccelerationStructureKHR src;
    DeviceOrHostAddressKHR dst;
    CopyAccelerationStructureModeKHR mode = static_cast<CopyAccelerationStructureModeKHR>(0);
    operator VkCopyAccelerationStructureToMemoryInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(this);
    }
    operator VkCopyAccelerationStructureToMemoryInfoKHR &() noexcept {
        return *reinterpret_cast<VkCopyAccelerationStructureToMemoryInfoKHR*>(this);
    }
};
struct CopyMemoryToAccelerationStructureInfoKHR {
    StructureType sType = StructureType::eCopyMemoryToAccelerationStructureInfoKHR;
    const void* pNext = nullptr;
    DeviceOrHostAddressConstKHR src;
    AccelerationStructureKHR dst;
    CopyAccelerationStructureModeKHR mode = static_cast<CopyAccelerationStructureModeKHR>(0);
    operator VkCopyMemoryToAccelerationStructureInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(this);
    }
    operator VkCopyMemoryToAccelerationStructureInfoKHR &() noexcept {
        return *reinterpret_cast<VkCopyMemoryToAccelerationStructureInfoKHR*>(this);
    }
};
struct DeferredOperationInfoKHR {
    StructureType sType = StructureType::eDeferredOperationInfoKHR;
    const void* pNext = nullptr;
    DeferredOperationKHR operationHandle;
    operator VkDeferredOperationInfoKHR const &() const noexcept {
        return *reinterpret_cast<const VkDeferredOperationInfoKHR*>(this);
    }
    operator VkDeferredOperationInfoKHR &() noexcept {
        return *reinterpret_cast<VkDeferredOperationInfoKHR*>(this);
    }
};
struct PhysicalDeviceExtendedDynamicStateFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceExtendedDynamicStateFeaturesEXT;
    void* pNext = nullptr;
    bool extendedDynamicState = false;
    operator VkPhysicalDeviceExtendedDynamicStateFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceExtendedDynamicStateFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(this);
    }
};
struct RenderPassTransformBeginInfoQCOM {
    StructureType sType = StructureType::eRenderPassTransformBeginInfoQCOM;
    void* pNext = nullptr;
    SurfaceTransformFlagBitsKHR transform = static_cast<SurfaceTransformFlagBitsKHR>(0);
    operator VkRenderPassTransformBeginInfoQCOM const &() const noexcept {
        return *reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(this);
    }
    operator VkRenderPassTransformBeginInfoQCOM &() noexcept {
        return *reinterpret_cast<VkRenderPassTransformBeginInfoQCOM*>(this);
    }
};
struct CommandBufferInheritanceRenderPassTransformInfoQCOM {
    StructureType sType = StructureType::eCommandBufferInheritanceRenderPassTransformInfoQCOM;
    void* pNext = nullptr;
    SurfaceTransformFlagBitsKHR transform = static_cast<SurfaceTransformFlagBitsKHR>(0);
    Rect2D renderArea;
    operator VkCommandBufferInheritanceRenderPassTransformInfoQCOM const &() const noexcept {
        return *reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(this);
    }
    operator VkCommandBufferInheritanceRenderPassTransformInfoQCOM &() noexcept {
        return *reinterpret_cast<VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(this);
    }
};
struct PhysicalDeviceDiagnosticsConfigFeaturesNV {
    StructureType sType = StructureType::ePhysicalDeviceDiagnosticsConfigFeaturesNV;
    void* pNext = nullptr;
    bool diagnosticsConfig = false;
    operator VkPhysicalDeviceDiagnosticsConfigFeaturesNV const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(this);
    }
    operator VkPhysicalDeviceDiagnosticsConfigFeaturesNV &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(this);
    }
};
struct DeviceDiagnosticsConfigCreateInfoNV {
    StructureType sType = StructureType::eDeviceDiagnosticsConfigCreateInfoNV;
    const void* pNext = nullptr;
    DeviceDiagnosticsConfigFlagsNV flags = static_cast<DeviceDiagnosticsConfigFlagsNV>(0);
    operator VkDeviceDiagnosticsConfigCreateInfoNV const &() const noexcept {
        return *reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(this);
    }
    operator VkDeviceDiagnosticsConfigCreateInfoNV &() noexcept {
        return *reinterpret_cast<VkDeviceDiagnosticsConfigCreateInfoNV*>(this);
    }
};
struct PhysicalDeviceRobustness2FeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceRobustness2FeaturesEXT;
    void* pNext = nullptr;
    bool robustBufferAccess2 = false;
    bool robustImageAccess2 = false;
    bool nullDescriptor = false;
    operator VkPhysicalDeviceRobustness2FeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceRobustness2FeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceRobustness2FeaturesEXT*>(this);
    }
};
struct PhysicalDeviceRobustness2PropertiesEXT {
    StructureType sType = StructureType::ePhysicalDeviceRobustness2PropertiesEXT;
    void* pNext = nullptr;
    DeviceSize robustStorageBufferAccessSizeAlignment = 0;
    DeviceSize robustUniformBufferAccessSizeAlignment = 0;
    operator VkPhysicalDeviceRobustness2PropertiesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(this);
    }
    operator VkPhysicalDeviceRobustness2PropertiesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceRobustness2PropertiesEXT*>(this);
    }
};
struct PhysicalDeviceImageRobustnessFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDeviceImageRobustnessFeaturesEXT;
    void* pNext = nullptr;
    bool robustImageAccess = false;
    operator VkPhysicalDeviceImageRobustnessFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeaturesEXT*>(this);
    }
    operator VkPhysicalDeviceImageRobustnessFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDeviceImageRobustnessFeaturesEXT*>(this);
    }
};
struct PhysicalDevice4444FormatsFeaturesEXT {
    StructureType sType = StructureType::ePhysicalDevice4444FormatsFeaturesEXT;
    void* pNext = nullptr;
    bool formatA4R4G4B4 = false;
    bool formatA4B4G4R4 = false;
    operator VkPhysicalDevice4444FormatsFeaturesEXT const &() const noexcept {
        return *reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(this);
    }
    operator VkPhysicalDevice4444FormatsFeaturesEXT &() noexcept {
        return *reinterpret_cast<VkPhysicalDevice4444FormatsFeaturesEXT*>(this);
    }
};
Result CreateInstance(
    const InstanceCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Instance* pInstance) {
    return static_cast<Result>(vkCreateInstance(reinterpret_cast<const VkInstanceCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkInstance*>(pInstance)));
}
void DestroyInstance(
    Instance const& instance,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyInstance(instance.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result EnumeratePhysicalDevices(
    Instance const& instance,
    uint32_t* pPhysicalDeviceCount,
    PhysicalDevice* pPhysicalDevices) {
    return static_cast<Result>(vkEnumeratePhysicalDevices(instance.get(),
        reinterpret_cast<uint32_t*>(pPhysicalDeviceCount),
        reinterpret_cast<VkPhysicalDevice*>(pPhysicalDevices)));
}
PFN_vkVoidFunction GetDeviceProcAddr(
    Device const& device,
    const char* pName) {
    return vkGetDeviceProcAddr(device.get(),
        reinterpret_cast<const char*>(pName));
}
PFN_vkVoidFunction GetInstanceProcAddr(
    Instance const& instance,
    const char* pName) {
    return vkGetInstanceProcAddr(instance.get(),
        reinterpret_cast<const char*>(pName));
}
void GetPhysicalDeviceProperties(
    PhysicalDevice const& physicalDevice,
    PhysicalDeviceProperties* pProperties) {
    return vkGetPhysicalDeviceProperties(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceProperties*>(pProperties));
}
void GetPhysicalDeviceQueueFamilyProperties(
    PhysicalDevice const& physicalDevice,
    uint32_t* pQueueFamilyPropertyCount,
    QueueFamilyProperties* pQueueFamilyProperties) {
    return vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice.get(),
        reinterpret_cast<uint32_t*>(pQueueFamilyPropertyCount),
        reinterpret_cast<VkQueueFamilyProperties*>(pQueueFamilyProperties));
}
void GetPhysicalDeviceMemoryProperties(
    PhysicalDevice const& physicalDevice,
    PhysicalDeviceMemoryProperties* pMemoryProperties) {
    return vkGetPhysicalDeviceMemoryProperties(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceMemoryProperties*>(pMemoryProperties));
}
void GetPhysicalDeviceFeatures(
    PhysicalDevice const& physicalDevice,
    PhysicalDeviceFeatures* pFeatures) {
    return vkGetPhysicalDeviceFeatures(physicalDevice.get(),
        reinterpret_cast<VkPhysicalDeviceFeatures*>(pFeatures));
}
void GetPhysicalDeviceFormatProperties(
    PhysicalDevice const& physicalDevice,
    Format format,
    FormatProperties* pFormatProperties) {
    return vkGetPhysicalDeviceFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        reinterpret_cast<VkFormatProperties*>(pFormatProperties));
}
Result GetPhysicalDeviceImageFormatProperties(
    PhysicalDevice const& physicalDevice,
    Format format,
    ImageType type,
    ImageTiling tiling,
    ImageUsageFlags usage,
    ImageCreateFlags flags,
    ImageFormatProperties* pImageFormatProperties) {
    return static_cast<Result>(vkGetPhysicalDeviceImageFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkImageTiling>(tiling),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageCreateFlags>(flags),
        reinterpret_cast<VkImageFormatProperties*>(pImageFormatProperties)));
}
Result CreateDevice(
    PhysicalDevice const& physicalDevice,
    const DeviceCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Device* pDevice) {
    return static_cast<Result>(vkCreateDevice(physicalDevice.get(),
        reinterpret_cast<const VkDeviceCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDevice*>(pDevice)));
}
void DestroyDevice(
    Device const& device,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyDevice(device.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result EnumerateInstanceLayerProperties(
    uint32_t* pPropertyCount,
    LayerProperties* pProperties) {
    return static_cast<Result>(vkEnumerateInstanceLayerProperties(reinterpret_cast<uint32_t*>(pPropertyCount),
        reinterpret_cast<VkLayerProperties*>(pProperties)));
}
Result EnumerateInstanceExtensionProperties(
    const char* pLayerName,
    uint32_t* pPropertyCount,
    ExtensionProperties* pProperties) {
    return static_cast<Result>(vkEnumerateInstanceExtensionProperties(reinterpret_cast<const char*>(pLayerName),
        reinterpret_cast<uint32_t*>(pPropertyCount),
        reinterpret_cast<VkExtensionProperties*>(pProperties)));
}
Result EnumerateDeviceLayerProperties(
    PhysicalDevice const& physicalDevice,
    uint32_t* pPropertyCount,
    LayerProperties* pProperties) {
    return static_cast<Result>(vkEnumerateDeviceLayerProperties(physicalDevice.get(),
        reinterpret_cast<uint32_t*>(pPropertyCount),
        reinterpret_cast<VkLayerProperties*>(pProperties)));
}
Result EnumerateDeviceExtensionProperties(
    PhysicalDevice const& physicalDevice,
    const char* pLayerName,
    uint32_t* pPropertyCount,
    ExtensionProperties* pProperties) {
    return static_cast<Result>(vkEnumerateDeviceExtensionProperties(physicalDevice.get(),
        reinterpret_cast<const char*>(pLayerName),
        reinterpret_cast<uint32_t*>(pPropertyCount),
        reinterpret_cast<VkExtensionProperties*>(pProperties)));
}
void GetDeviceQueue(
    Device const& device,
    uint32_t queueFamilyIndex,
    uint32_t queueIndex,
    Queue* pQueue) {
    return vkGetDeviceQueue(device.get(),
        queueFamilyIndex,
        queueIndex,
        reinterpret_cast<VkQueue*>(pQueue));
}
Result QueueSubmit(
    Queue const& queue,
    uint32_t submitCount,
    const SubmitInfo* pSubmits,
    Fence fence) {
    return static_cast<Result>(vkQueueSubmit(queue.get(),
        submitCount,
        reinterpret_cast<const VkSubmitInfo*>(pSubmits),
        fence.get()));
}
Result QueueWaitIdle(
    Queue const& queue) {
    return static_cast<Result>(vkQueueWaitIdle(queue.get()));
}
Result DeviceWaitIdle(
    Device const& device) {
    return static_cast<Result>(vkDeviceWaitIdle(device.get()));
}
Result AllocateMemory(
    Device const& device,
    const MemoryAllocateInfo* pAllocateInfo,
    const AllocationCallbacks* pAllocator,
    DeviceMemory* pMemory) {
    return static_cast<Result>(vkAllocateMemory(device.get(),
        reinterpret_cast<const VkMemoryAllocateInfo*>(pAllocateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDeviceMemory*>(pMemory)));
}
void FreeMemory(
    Device const& device,
    DeviceMemory memory,
    const AllocationCallbacks* pAllocator) {
    return vkFreeMemory(device.get(),
        memory.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result MapMemory(
    Device const& device,
    DeviceMemory memory,
    DeviceSize offset,
    DeviceSize size,
    MemoryMapFlags flags,
    void** ppData) {
    return static_cast<Result>(vkMapMemory(device.get(),
        memory.get(),
        static_cast<VkDeviceSize>(offset),
        static_cast<VkDeviceSize>(size),
        static_cast<VkMemoryMapFlags>(flags),
        static_cast<void**>(ppData)));
}
void UnmapMemory(
    Device const& device,
    DeviceMemory memory) {
    return vkUnmapMemory(device.get(),
        memory.get());
}
Result FlushMappedMemoryRanges(
    Device const& device,
    uint32_t memoryRangeCount,
    const MappedMemoryRange* pMemoryRanges) {
    return static_cast<Result>(vkFlushMappedMemoryRanges(device.get(),
        memoryRangeCount,
        reinterpret_cast<const VkMappedMemoryRange*>(pMemoryRanges)));
}
Result InvalidateMappedMemoryRanges(
    Device const& device,
    uint32_t memoryRangeCount,
    const MappedMemoryRange* pMemoryRanges) {
    return static_cast<Result>(vkInvalidateMappedMemoryRanges(device.get(),
        memoryRangeCount,
        reinterpret_cast<const VkMappedMemoryRange*>(pMemoryRanges)));
}
void GetDeviceMemoryCommitment(
    Device const& device,
    DeviceMemory memory,
    DeviceSize* pCommittedMemoryInBytes) {
    return vkGetDeviceMemoryCommitment(device.get(),
        memory.get(),
        reinterpret_cast<VkDeviceSize*>(pCommittedMemoryInBytes));
}
void GetBufferMemoryRequirements(
    Device const& device,
    Buffer buffer,
    MemoryRequirements* pMemoryRequirements) {
    return vkGetBufferMemoryRequirements(device.get(),
        buffer.get(),
        reinterpret_cast<VkMemoryRequirements*>(pMemoryRequirements));
}
Result BindBufferMemory(
    Device const& device,
    Buffer buffer,
    DeviceMemory memory,
    DeviceSize memoryOffset) {
    return static_cast<Result>(vkBindBufferMemory(device.get(),
        buffer.get(),
        memory.get(),
        static_cast<VkDeviceSize>(memoryOffset)));
}
void GetImageMemoryRequirements(
    Device const& device,
    Image image,
    MemoryRequirements* pMemoryRequirements) {
    return vkGetImageMemoryRequirements(device.get(),
        image.get(),
        reinterpret_cast<VkMemoryRequirements*>(pMemoryRequirements));
}
Result BindImageMemory(
    Device const& device,
    Image image,
    DeviceMemory memory,
    DeviceSize memoryOffset) {
    return static_cast<Result>(vkBindImageMemory(device.get(),
        image.get(),
        memory.get(),
        static_cast<VkDeviceSize>(memoryOffset)));
}
void GetImageSparseMemoryRequirements(
    Device const& device,
    Image image,
    uint32_t* pSparseMemoryRequirementCount,
    SparseImageMemoryRequirements* pSparseMemoryRequirements) {
    return vkGetImageSparseMemoryRequirements(device.get(),
        image.get(),
        reinterpret_cast<uint32_t*>(pSparseMemoryRequirementCount),
        reinterpret_cast<VkSparseImageMemoryRequirements*>(pSparseMemoryRequirements));
}
void GetPhysicalDeviceSparseImageFormatProperties(
    PhysicalDevice const& physicalDevice,
    Format format,
    ImageType type,
    SampleCountFlagBits samples,
    ImageUsageFlags usage,
    ImageTiling tiling,
    uint32_t* pPropertyCount,
    SparseImageFormatProperties* pProperties) {
    return vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice.get(),
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkSampleCountFlagBits>(samples),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageTiling>(tiling),
        reinterpret_cast<uint32_t*>(pPropertyCount),
        reinterpret_cast<VkSparseImageFormatProperties*>(pProperties));
}
Result QueueBindSparse(
    Queue const& queue,
    uint32_t bindInfoCount,
    const BindSparseInfo* pBindInfo,
    Fence fence) {
    return static_cast<Result>(vkQueueBindSparse(queue.get(),
        bindInfoCount,
        reinterpret_cast<const VkBindSparseInfo*>(pBindInfo),
        fence.get()));
}
Result CreateFence(
    Device const& device,
    const FenceCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Fence* pFence) {
    return static_cast<Result>(vkCreateFence(device.get(),
        reinterpret_cast<const VkFenceCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkFence*>(pFence)));
}
void DestroyFence(
    Device const& device,
    Fence fence,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyFence(device.get(),
        fence.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result ResetFences(
    Device const& device,
    uint32_t fenceCount,
    const Fence* pFences) {
    return static_cast<Result>(vkResetFences(device.get(),
        fenceCount,
        reinterpret_cast<const VkFence*>(pFences)));
}
Result GetFenceStatus(
    Device const& device,
    Fence fence) {
    return static_cast<Result>(vkGetFenceStatus(device.get(),
        fence.get()));
}
Result WaitForFences(
    Device const& device,
    uint32_t fenceCount,
    const Fence* pFences,
    bool waitAll,
    uint64_t timeout) {
    return static_cast<Result>(vkWaitForFences(device.get(),
        fenceCount,
        reinterpret_cast<const VkFence*>(pFences),
        waitAll,
        timeout));
}
Result CreateSemaphore(
    Device const& device,
    const SemaphoreCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Semaphore* pSemaphore) {
    return static_cast<Result>(vkCreateSemaphore(device.get(),
        reinterpret_cast<const VkSemaphoreCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSemaphore*>(pSemaphore)));
}
void DestroySemaphore(
    Device const& device,
    Semaphore semaphore,
    const AllocationCallbacks* pAllocator) {
    return vkDestroySemaphore(device.get(),
        semaphore.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateEvent(
    Device const& device,
    const EventCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Event* pEvent) {
    return static_cast<Result>(vkCreateEvent(device.get(),
        reinterpret_cast<const VkEventCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkEvent*>(pEvent)));
}
void DestroyEvent(
    Device const& device,
    Event event,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyEvent(device.get(),
        event.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result GetEventStatus(
    Device const& device,
    Event event) {
    return static_cast<Result>(vkGetEventStatus(device.get(),
        event.get()));
}
Result SetEvent(
    Device const& device,
    Event event) {
    return static_cast<Result>(vkSetEvent(device.get(),
        event.get()));
}
Result ResetEvent(
    Device const& device,
    Event event) {
    return static_cast<Result>(vkResetEvent(device.get(),
        event.get()));
}
Result CreateQueryPool(
    Device const& device,
    const QueryPoolCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    QueryPool* pQueryPool) {
    return static_cast<Result>(vkCreateQueryPool(device.get(),
        reinterpret_cast<const VkQueryPoolCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkQueryPool*>(pQueryPool)));
}
void DestroyQueryPool(
    Device const& device,
    QueryPool queryPool,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyQueryPool(device.get(),
        queryPool.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result GetQueryPoolResults(
    Device const& device,
    QueryPool queryPool,
    uint32_t firstQuery,
    uint32_t queryCount,
    size_t dataSize,
    void* pData,
    DeviceSize stride,
    QueryResultFlags flags) {
    return static_cast<Result>(vkGetQueryPoolResults(device.get(),
        queryPool.get(),
        firstQuery,
        queryCount,
        dataSize,
        reinterpret_cast<void*>(pData),
        static_cast<VkDeviceSize>(stride),
        static_cast<VkQueryResultFlags>(flags)));
}
Result CreateBuffer(
    Device const& device,
    const BufferCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Buffer* pBuffer) {
    return static_cast<Result>(vkCreateBuffer(device.get(),
        reinterpret_cast<const VkBufferCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkBuffer*>(pBuffer)));
}
void DestroyBuffer(
    Device const& device,
    Buffer buffer,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyBuffer(device.get(),
        buffer.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateBufferView(
    Device const& device,
    const BufferViewCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    BufferView* pView) {
    return static_cast<Result>(vkCreateBufferView(device.get(),
        reinterpret_cast<const VkBufferViewCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkBufferView*>(pView)));
}
void DestroyBufferView(
    Device const& device,
    BufferView bufferView,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyBufferView(device.get(),
        bufferView.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateImage(
    Device const& device,
    const ImageCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Image* pImage) {
    return static_cast<Result>(vkCreateImage(device.get(),
        reinterpret_cast<const VkImageCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkImage*>(pImage)));
}
void DestroyImage(
    Device const& device,
    Image image,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyImage(device.get(),
        image.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
void GetImageSubresourceLayout(
    Device const& device,
    Image image,
    const ImageSubresource* pSubresource,
    SubresourceLayout* pLayout) {
    return vkGetImageSubresourceLayout(device.get(),
        image.get(),
        reinterpret_cast<const VkImageSubresource*>(pSubresource),
        reinterpret_cast<VkSubresourceLayout*>(pLayout));
}
Result CreateImageView(
    Device const& device,
    const ImageViewCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    ImageView* pView) {
    return static_cast<Result>(vkCreateImageView(device.get(),
        reinterpret_cast<const VkImageViewCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkImageView*>(pView)));
}
void DestroyImageView(
    Device const& device,
    ImageView imageView,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyImageView(device.get(),
        imageView.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateShaderModule(
    Device const& device,
    const ShaderModuleCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    ShaderModule* pShaderModule) {
    return static_cast<Result>(vkCreateShaderModule(device.get(),
        reinterpret_cast<const VkShaderModuleCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkShaderModule*>(pShaderModule)));
}
void DestroyShaderModule(
    Device const& device,
    ShaderModule shaderModule,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyShaderModule(device.get(),
        shaderModule.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreatePipelineCache(
    Device const& device,
    const PipelineCacheCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    PipelineCache* pPipelineCache) {
    return static_cast<Result>(vkCreatePipelineCache(device.get(),
        reinterpret_cast<const VkPipelineCacheCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipelineCache*>(pPipelineCache)));
}
void DestroyPipelineCache(
    Device const& device,
    PipelineCache pipelineCache,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyPipelineCache(device.get(),
        pipelineCache.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result GetPipelineCacheData(
    Device const& device,
    PipelineCache pipelineCache,
    size_t* pDataSize,
    void* pData) {
    return static_cast<Result>(vkGetPipelineCacheData(device.get(),
        pipelineCache.get(),
        reinterpret_cast<size_t*>(pDataSize),
        reinterpret_cast<void*>(pData)));
}
Result MergePipelineCaches(
    Device const& device,
    PipelineCache dstCache,
    uint32_t srcCacheCount,
    const PipelineCache* pSrcCaches) {
    return static_cast<Result>(vkMergePipelineCaches(device.get(),
        dstCache.get(),
        srcCacheCount,
        reinterpret_cast<const VkPipelineCache*>(pSrcCaches)));
}
Result CreateGraphicsPipelines(
    Device const& device,
    PipelineCache pipelineCache,
    uint32_t createInfoCount,
    const GraphicsPipelineCreateInfo* pCreateInfos,
    const AllocationCallbacks* pAllocator,
    Pipeline* pPipelines) {
    return static_cast<Result>(vkCreateGraphicsPipelines(device.get(),
        pipelineCache.get(),
        createInfoCount,
        reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipeline*>(pPipelines)));
}
Result CreateComputePipelines(
    Device const& device,
    PipelineCache pipelineCache,
    uint32_t createInfoCount,
    const ComputePipelineCreateInfo* pCreateInfos,
    const AllocationCallbacks* pAllocator,
    Pipeline* pPipelines) {
    return static_cast<Result>(vkCreateComputePipelines(device.get(),
        pipelineCache.get(),
        createInfoCount,
        reinterpret_cast<const VkComputePipelineCreateInfo*>(pCreateInfos),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipeline*>(pPipelines)));
}
void DestroyPipeline(
    Device const& device,
    Pipeline pipeline,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyPipeline(device.get(),
        pipeline.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreatePipelineLayout(
    Device const& device,
    const PipelineLayoutCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    PipelineLayout* pPipelineLayout) {
    return static_cast<Result>(vkCreatePipelineLayout(device.get(),
        reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkPipelineLayout*>(pPipelineLayout)));
}
void DestroyPipelineLayout(
    Device const& device,
    PipelineLayout pipelineLayout,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyPipelineLayout(device.get(),
        pipelineLayout.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateSampler(
    Device const& device,
    const SamplerCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Sampler* pSampler) {
    return static_cast<Result>(vkCreateSampler(device.get(),
        reinterpret_cast<const VkSamplerCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkSampler*>(pSampler)));
}
void DestroySampler(
    Device const& device,
    Sampler sampler,
    const AllocationCallbacks* pAllocator) {
    return vkDestroySampler(device.get(),
        sampler.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateDescriptorSetLayout(
    Device const& device,
    const DescriptorSetLayoutCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    DescriptorSetLayout* pSetLayout) {
    return static_cast<Result>(vkCreateDescriptorSetLayout(device.get(),
        reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDescriptorSetLayout*>(pSetLayout)));
}
void DestroyDescriptorSetLayout(
    Device const& device,
    DescriptorSetLayout descriptorSetLayout,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyDescriptorSetLayout(device.get(),
        descriptorSetLayout.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateDescriptorPool(
    Device const& device,
    const DescriptorPoolCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    DescriptorPool* pDescriptorPool) {
    return static_cast<Result>(vkCreateDescriptorPool(device.get(),
        reinterpret_cast<const VkDescriptorPoolCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkDescriptorPool*>(pDescriptorPool)));
}
void DestroyDescriptorPool(
    Device const& device,
    DescriptorPool descriptorPool,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyDescriptorPool(device.get(),
        descriptorPool.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result ResetDescriptorPool(
    Device const& device,
    DescriptorPool descriptorPool,
    DescriptorPoolResetFlags flags) {
    return static_cast<Result>(vkResetDescriptorPool(device.get(),
        descriptorPool.get(),
        static_cast<VkDescriptorPoolResetFlags>(flags)));
}
Result AllocateDescriptorSets(
    Device const& device,
    const DescriptorSetAllocateInfo* pAllocateInfo,
    DescriptorSet* pDescriptorSets) {
    return static_cast<Result>(vkAllocateDescriptorSets(device.get(),
        reinterpret_cast<const VkDescriptorSetAllocateInfo*>(pAllocateInfo),
        reinterpret_cast<VkDescriptorSet*>(pDescriptorSets)));
}
Result FreeDescriptorSets(
    Device const& device,
    DescriptorPool descriptorPool,
    uint32_t descriptorSetCount,
    const DescriptorSet* pDescriptorSets) {
    return static_cast<Result>(vkFreeDescriptorSets(device.get(),
        descriptorPool.get(),
        descriptorSetCount,
        reinterpret_cast<const VkDescriptorSet*>(pDescriptorSets)));
}
void UpdateDescriptorSets(
    Device const& device,
    uint32_t descriptorWriteCount,
    const WriteDescriptorSet* pDescriptorWrites,
    uint32_t descriptorCopyCount,
    const CopyDescriptorSet* pDescriptorCopies) {
    return vkUpdateDescriptorSets(device.get(),
        descriptorWriteCount,
        reinterpret_cast<const VkWriteDescriptorSet*>(pDescriptorWrites),
        descriptorCopyCount,
        reinterpret_cast<const VkCopyDescriptorSet*>(pDescriptorCopies));
}
Result CreateFramebuffer(
    Device const& device,
    const FramebufferCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    Framebuffer* pFramebuffer) {
    return static_cast<Result>(vkCreateFramebuffer(device.get(),
        reinterpret_cast<const VkFramebufferCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkFramebuffer*>(pFramebuffer)));
}
void DestroyFramebuffer(
    Device const& device,
    Framebuffer framebuffer,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyFramebuffer(device.get(),
        framebuffer.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result CreateRenderPass(
    Device const& device,
    const RenderPassCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    RenderPass* pRenderPass) {
    return static_cast<Result>(vkCreateRenderPass(device.get(),
        reinterpret_cast<const VkRenderPassCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkRenderPass*>(pRenderPass)));
}
void DestroyRenderPass(
    Device const& device,
    RenderPass renderPass,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyRenderPass(device.get(),
        renderPass.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
void GetRenderAreaGranularity(
    Device const& device,
    RenderPass renderPass,
    Extent2D* pGranularity) {
    return vkGetRenderAreaGranularity(device.get(),
        renderPass.get(),
        reinterpret_cast<VkExtent2D*>(pGranularity));
}
Result CreateCommandPool(
    Device const& device,
    const CommandPoolCreateInfo* pCreateInfo,
    const AllocationCallbacks* pAllocator,
    CommandPool* pCommandPool) {
    return static_cast<Result>(vkCreateCommandPool(device.get(),
        reinterpret_cast<const VkCommandPoolCreateInfo*>(pCreateInfo),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator),
        reinterpret_cast<VkCommandPool*>(pCommandPool)));
}
void DestroyCommandPool(
    Device const& device,
    CommandPool commandPool,
    const AllocationCallbacks* pAllocator) {
    return vkDestroyCommandPool(device.get(),
        commandPool.get(),
        reinterpret_cast<const VkAllocationCallbacks*>(pAllocator));
}
Result ResetCommandPool(
    Device const& device,
    CommandPool commandPool,
    CommandPoolResetFlags flags) {
    return static_cast<Result>(vkResetCommandPool(device.get(),
        commandPool.get(),
        static_cast<VkCommandPoolResetFlags>(flags)));
}
Result AllocateCommandBuffers(
    Device const& device,
    const CommandBufferAllocateInfo* pAllocateInfo,
    CommandBuffer* pCommandBuffers) {
    return static_cast<Result>(vkAllocateCommandBuffers(device.get(),
        reinterpret_cast<const VkCommandBufferAllocateInfo*>(pAllocateInfo),
        reinterpret_cast<VkCommandBuffer*>(pCommandBuffers)));
}
void FreeCommandBuffers(
    Device const& device,
    CommandPool commandPool,
    uint32_t commandBufferCount,
    const CommandBuffer* pCommandBuffers) {
    return vkFreeCommandBuffers(device.get(),
        commandPool.get(),
        commandBufferCount,
        reinterpret_cast<const VkCommandBuffer*>(pCommandBuffers));
}
Result BeginCommandBuffer(
    CommandBuffer const& commandBuffer,
    const CommandBufferBeginInfo* pBeginInfo) {
    return static_cast<Result>(vkBeginCommandBuffer(commandBuffer.get(),
        reinterpret_cast<const VkCommandBufferBeginInfo*>(pBeginInfo)));
}
Result EndCommandBuffer(
    CommandBuffer const& commandBuffer) {
    return static_cast<Result>(vkEndCommandBuffer(commandBuffer.get()));
}
Result ResetCommandBuffer(
    CommandBuffer const& commandBuffer,
    CommandBufferResetFlags flags) {
    return static_cast<Result>(vkResetCommandBuffer(commandBuffer.get(),
        static_cast<VkCommandBufferResetFlags>(flags)));
}
void CmdBindPipeline(
    CommandBuffer const& commandBuffer,
    PipelineBindPoint pipelineBindPoint,
    Pipeline pipeline) {
    return vkCmdBindPipeline(commandBuffer.get(),
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        pipeline.get());
}
void CmdSetViewport(
    CommandBuffer const& commandBuffer,
    uint32_t firstViewport,
    uint32_t viewportCount,
    const Viewport* pViewports) {
    return vkCmdSetViewport(commandBuffer.get(),
        firstViewport,
        viewportCount,
        reinterpret_cast<const VkViewport*>(pViewports));
}
void CmdSetScissor(
    CommandBuffer const& commandBuffer,
    uint32_t firstScissor,
    uint32_t scissorCount,
    const Rect2D* pScissors) {
    return vkCmdSetScissor(commandBuffer.get(),
        firstScissor,
        scissorCount,
        reinterpret_cast<const VkRect2D*>(pScissors));
}
void CmdSetLineWidth(
    CommandBuffer const& commandBuffer,
    float lineWidth) {
    return vkCmdSetLineWidth(commandBuffer.get(),
        lineWidth);
}
void CmdSetDepthBias(
    CommandBuffer const& commandBuffer,
    float depthBiasConstantFactor,
    float depthBiasClamp,
    float depthBiasSlopeFactor) {
    return vkCmdSetDepthBias(commandBuffer.get(),
        depthBiasConstantFactor,
        depthBiasClamp,
        depthBiasSlopeFactor);
}
void CmdSetBlendConstants(
    CommandBuffer const& commandBuffer,
    const float blendConstants[4]) {
    return vkCmdSetBlendConstants(commandBuffer.get(),
        blendConstants);
}
void CmdSetDepthBounds(
    CommandBuffer const& commandBuffer,
    float minDepthBounds,
    float maxDepthBounds) {
    return vkCmdSetDepthBounds(commandBuffer.get(),
        minDepthBounds,
        maxDepthBounds);
}
void CmdSetStencilCompareMask(
    CommandBuffer const& commandBuffer,
    StencilFaceFlags faceMask,
    uint32_t compareMask) {
    return vkCmdSetStencilCompareMask(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        compareMask);
}
void CmdSetStencilWriteMask(
    CommandBuffer const& commandBuffer,
    StencilFaceFlags faceMask,
    uint32_t writeMask) {
    return vkCmdSetStencilWriteMask(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        writeMask);
}
void CmdSetStencilReference(
    CommandBuffer const& commandBuffer,
    StencilFaceFlags faceMask,
    uint32_t reference) {
    return vkCmdSetStencilReference(commandBuffer.get(),
        static_cast<VkStencilFaceFlags>(faceMask),
        reference);
}
void CmdBindDescriptorSets(
    CommandBuffer const& commandBuffer,
    PipelineBindPoint pipelineBindPoint,
    PipelineLayout layout,
    uint32_t firstSet,
    uint32_t descriptorSetCount,
    const DescriptorSet* pDescriptorSets,
    uint32_t dynamicOffsetCount,
    const uint32_t* pDynamicOffsets) {
    return vkCmdBindDescriptorSets(commandBuffer.get(),
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        layout.get(),
        firstSet,
        descriptorSetCount,
        reinterpret_cast<const VkDescriptorSet*>(pDescriptorSets),
        dynamicOffsetCount,
        reinterpret_cast<const uint32_t*>(pDynamicOffsets));
}
void CmdBindIndexBuffer(
    CommandBuffer const& commandBuffer,
    Buffer buffer,
    DeviceSize offset,
    IndexType indexType) {
    return vkCmdBindIndexBuffer(commandBuffer.get(),
        buffer.get(),
        static_cast<VkDeviceSize>(offset),
        static_cast<VkIndexType>(indexType));
}
void CmdBindVertexBuffers(
    CommandBuffer const& commandBuffer,
    uint32_t firstBinding,
    uint32_t bindingCount,
    const Buffer* pBuffers,
    const DeviceSize* pOffsets) {
    return vkCmdBindVertexBuffers(commandBuffer.get(),
        firstBinding,
        bindingCount,
        reinterpret_cast<const VkBuffer*>(pBuffers),
        reinterpret_cast<const VkDeviceSize*>(pOffsets));
}
void CmdDraw(
    CommandBuffer const& commandBuffer,
    uint32_t vertexCount,
    uint32_t instanceCount,
    uint32_t firstVertex,
    uint32_t firstInstance) {
    return vkCmdDraw(commandBuffer.get(),
        vertexCount,
        instanceCount,
        firstVertex,
        firstInstance);
}
void CmdDrawIndexed(
    CommandBuffer const& commandBuffer,
    uint32_t indexCount,
    uint32_t instanceCount,
    uint32_t firstIndex,
    int32_t vertexOffset,
    uint32_t firstInstance) {
    return vkCmdDrawIndexed(commandBuffer.get(),
        indexCount,
        instanceCount,
        firstIndex,
        vertexOffset,
        firstInstance);
}
void CmdDrawIndirect(
    CommandBuffer const& commandBuffer,
    Buffer buffer,
    DeviceSize offset,
    uint32_t drawCount,
    uint32_t stride) {
    return vkCmdDrawIndirect(commandBuffer.get(),
        buffer.get(),
        static_cast<VkDeviceSize>(offset),
        drawCount,
        stride);
}
void CmdDrawIndexedIndirect(
    CommandBuffer const& commandBuffer,
    Buffer buffer,
    DeviceSize offset,
    uint32_t drawCount,
    uint32_t stride) {
    return vkCmdDrawIndexedIndirect(commandBuffer.get(),
        buffer.get(),
        static_cast<VkDeviceSize>(offset),
        drawCount,
        stride);
}
void CmdDispatch(
    CommandBuffer const& commandBuffer,
    uint32_t groupCountX,
    uint32_t groupCountY,
    uint32_t groupCountZ) {
    return vkCmdDispatch(commandBuffer.get(),
        groupCountX,
        groupCountY,
        groupCountZ);
}
void CmdDispatchIndirect(
    CommandBuffer const& commandBuffer,
    Buffer buffer,
    DeviceSize offset) {
    return vkCmdDispatchIndirect(commandBuffer.get(),
        buffer.get(),
        static_cast<VkDeviceSize>(offset));
}
void CmdCopyBuffer(
    CommandBuffer const& commandBuffer,
    Buffer srcBuffer,
    Buffer dstBuffer,
    uint32_t regionCount,
    const BufferCopy* pRegions) {
    return vkCmdCopyBuffer(commandBuffer.get(),
        srcBuffer.get(),
        dstBuffer.get(),
        regionCount,
        reinterpret_cast<const VkBufferCopy*>(pRegions));
}
void CmdCopyImage(
    CommandBuffer const& commandBuffer,
    Image srcImage,
    ImageLayout srcImageLayout,
    Image dstImage,
    ImageLayout dstImageLayout,
    uint32_t regionCount,
    const ImageCopy* pRegions) {
    return vkCmdCopyImage(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkImageCopy*>(pRegions));
}
void CmdBlitImage(
    CommandBuffer const& commandBuffer,
    Image srcImage,
    ImageLayout srcImageLayout,
    Image dstImage,
    ImageLayout dstImageLayout,
    uint32_t regionCount,
    const ImageBlit* pRegions,
    Filter filter) {
    return vkCmdBlitImage(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkImageBlit*>(pRegions),
        static_cast<VkFilter>(filter));
}
void CmdCopyBufferToImage(
    CommandBuffer const& commandBuffer,
    Buffer srcBuffer,
    Image dstImage,
    ImageLayout dstImageLayout,
    uint32_t regionCount,
    const BufferImageCopy* pRegions) {
    return vkCmdCopyBufferToImage(commandBuffer.get(),
        srcBuffer.get(),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkBufferImageCopy*>(pRegions));
}
void CmdCopyImageToBuffer(
    CommandBuffer const& commandBuffer,
    Image srcImage,
    ImageLayout srcImageLayout,
    Buffer dstBuffer,
    uint32_t regionCount,
    const BufferImageCopy* pRegions) {
    return vkCmdCopyImageToBuffer(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstBuffer.get(),
        regionCount,
        reinterpret_cast<const VkBufferImageCopy*>(pRegions));
}
void CmdUpdateBuffer(
    CommandBuffer const& commandBuffer,
    Buffer dstBuffer,
    DeviceSize dstOffset,
    DeviceSize dataSize,
    const void* pData) {
    return vkCmdUpdateBuffer(commandBuffer.get(),
        dstBuffer.get(),
        static_cast<VkDeviceSize>(dstOffset),
        static_cast<VkDeviceSize>(dataSize),
        reinterpret_cast<const void*>(pData));
}
void CmdFillBuffer(
    CommandBuffer const& commandBuffer,
    Buffer dstBuffer,
    DeviceSize dstOffset,
    DeviceSize size,
    uint32_t data) {
    return vkCmdFillBuffer(commandBuffer.get(),
        dstBuffer.get(),
        static_cast<VkDeviceSize>(dstOffset),
        static_cast<VkDeviceSize>(size),
        data);
}
void CmdClearColorImage(
    CommandBuffer const& commandBuffer,
    Image image,
    ImageLayout imageLayout,
    const ClearColorValue* pColor,
    uint32_t rangeCount,
    const ImageSubresourceRange* pRanges) {
    return vkCmdClearColorImage(commandBuffer.get(),
        image.get(),
        static_cast<VkImageLayout>(imageLayout),
        reinterpret_cast<const VkClearColorValue*>(pColor),
        rangeCount,
        reinterpret_cast<const VkImageSubresourceRange*>(pRanges));
}
void CmdClearDepthStencilImage(
    CommandBuffer const& commandBuffer,
    Image image,
    ImageLayout imageLayout,
    const ClearDepthStencilValue* pDepthStencil,
    uint32_t rangeCount,
    const ImageSubresourceRange* pRanges) {
    return vkCmdClearDepthStencilImage(commandBuffer.get(),
        image.get(),
        static_cast<VkImageLayout>(imageLayout),
        reinterpret_cast<const VkClearDepthStencilValue*>(pDepthStencil),
        rangeCount,
        reinterpret_cast<const VkImageSubresourceRange*>(pRanges));
}
void CmdClearAttachments(
    CommandBuffer const& commandBuffer,
    uint32_t attachmentCount,
    const ClearAttachment* pAttachments,
    uint32_t rectCount,
    const ClearRect* pRects) {
    return vkCmdClearAttachments(commandBuffer.get(),
        attachmentCount,
        reinterpret_cast<const VkClearAttachment*>(pAttachments),
        rectCount,
        reinterpret_cast<const VkClearRect*>(pRects));
}
void CmdResolveImage(
    CommandBuffer const& commandBuffer,
    Image srcImage,
    ImageLayout srcImageLayout,
    Image dstImage,
    ImageLayout dstImageLayout,
    uint32_t regionCount,
    const ImageResolve* pRegions) {
    return vkCmdResolveImage(commandBuffer.get(),
        srcImage.get(),
        static_cast<VkImageLayout>(srcImageLayout),
        dstImage.get(),
        static_cast<VkImageLayout>(dstImageLayout),
        regionCount,
        reinterpret_cast<const VkImageResolve*>(pRegions));
}
void CmdSetEvent(
    CommandBuffer const& commandBuffer,
    Event event,
    PipelineStageFlags stageMask) {
    return vkCmdSetEvent(commandBuffer.get(),
        event.get(),
        static_cast<VkPipelineStageFlags>(stageMask));
}
void CmdResetEvent(
    CommandBuffer const& commandBuffer,
    Event event,
    PipelineStageFlags stageMask) {
    return vkCmdResetEvent(commandBuffer.get(),
        event.get(),
        static_cast<VkPipelineStageFlags>(stageMask));
}
void CmdWaitEvents(
    CommandBuffer const& commandBuffer,
    uint32_t eventCount,
    const Event* pEvents,
    PipelineStageFlags srcStageMask,
    PipelineStageFlags dstStageMask,
    uint32_t memoryBarrierCount,
    const MemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount,
    const BufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t imageMemoryBarrierCount,
    const ImageMemoryBarrier* pImageMemoryBarriers) {
    return vkCmdWaitEvents(commandBuffer.get(),
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
void CmdPipelineBarrier(
    CommandBuffer const& commandBuffer,
    PipelineStageFlags srcStageMask,
    PipelineStageFlags dstStageMask,
    DependencyFlags dependencyFlags,
    uint32_t memoryBarrierCount,
    const MemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount,
    const BufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t imageMemoryBarrierCount,
    const ImageMemoryBarrier* pImageMemoryBarriers) {
    return vkCmdPipelineBarrier(commandBuffer.get(),
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
void CmdBeginQuery(
    CommandBuffer const& commandBuffer,
    QueryPool queryPool,
    uint32_t query,
    QueryControlFlags flags) {
    return vkCmdBeginQuery(commandBuffer.get(),
        queryPool.get(),
        query,
        static_cast<VkQueryControlFlags>(flags));
}
void CmdEndQuery(
    CommandBuffer const& commandBuffer,
    QueryPool queryPool,
    uint32_t query) {
    return vkCmdEndQuery(commandBuffer.get(),
        queryPool.get(),
        query);
}
void CmdResetQueryPool(
    CommandBuffer const& commandBuffer,
    QueryPool queryPool,
    uint32_t firstQuery,
    uint32_t queryCount) {
    return vkCmdResetQueryPool(commandBuffer.get(),
        queryPool.get(),
        firstQuery,
        queryCount);
}
void CmdWriteTimestamp(
    CommandBuffer const& commandBuffer,
    PipelineStageFlagBits pipelineStage,
    QueryPool queryPool,
    uint32_t query) {
    return vkCmdWriteTimestamp(commandBuffer.get(),
        static_cast<VkPipelineStageFlagBits>(pipelineStage),
        queryPool.get(),
        query);
}
void CmdCopyQueryPoolResults(
    CommandBuffer const& commandBuffer,
    QueryPool queryPool,
    uint32_t firstQuery,
    uint32_t queryCount,
    Buffer dstBuffer,
    DeviceSize dstOffset,
    DeviceSize stride,
    QueryResultFlags flags) {
    return vkCmdCopyQueryPoolResults(commandBuffer.get(),
        queryPool.get(),
        firstQuery,
        queryCount,
        dstBuffer.get(),
        static_cast<VkDeviceSize>(dstOffset),
        static_cast<VkDeviceSize>(stride),
        static_cast<VkQueryResultFlags>(flags));
}
void CmdPushConstants(
    CommandBuffer const& commandBuffer,
    PipelineLayout layout,
    ShaderStageFlags stageFlags,
    uint32_t offset,
    uint32_t size,
    const void* pValues) {
    return vkCmdPushConstants(commandBuffer.get(),
        layout.get(),
        static_cast<VkShaderStageFlags>(stageFlags),
        offset,
        size,
        reinterpret_cast<const void*>(pValues));
}
void CmdBeginRenderPass(
    CommandBuffer const& commandBuffer,
    const RenderPassBeginInfo* pRenderPassBegin,
    SubpassContents contents) {
    return vkCmdBeginRenderPass(commandBuffer.get(),
        reinterpret_cast<const VkRenderPassBeginInfo*>(pRenderPassBegin),
        static_cast<VkSubpassContents>(contents));
}
void CmdNextSubpass(
    CommandBuffer const& commandBuffer,
    SubpassContents contents) {
    return vkCmdNextSubpass(commandBuffer.get(),
        static_cast<VkSubpassContents>(contents));
}
void CmdEndRenderPass(
    CommandBuffer const& commandBuffer) {
    return vkCmdEndRenderPass(commandBuffer.get());
}
void CmdExecuteCommands(
    CommandBuffer const& commandBuffer,
    uint32_t commandBufferCount,
    const CommandBuffer* pCommandBuffers) {
    return vkCmdExecuteCommands(commandBuffer.get(),
        commandBufferCount,
        reinterpret_cast<const VkCommandBuffer*>(pCommandBuffers));
}
} // namespace vk
// clang-format on
