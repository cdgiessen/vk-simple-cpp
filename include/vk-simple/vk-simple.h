/*
 * Copyright 2024 Charles Giessen (cdgiessen@gmail.com)
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

// clang-format off
#include <vulkan/vulkan_core.h>

namespace vk {

    using SampleMask = VkSampleMask;
    using Bool32 = VkBool32;
    using Flags = VkFlags;
    using Flags64 = VkFlags64;
    using DeviceSize = VkDeviceSize;
    using DeviceAddress = VkDeviceAddress;
    using RemoteAddressNV = VkRemoteAddressNV;

using Instance = VkInstance;
using PhysicalDevice = VkPhysicalDevice;
using Device = VkDevice;
using Queue = VkQueue;
using CommandBuffer = VkCommandBuffer;
using DeviceMemory = VkDeviceMemory;
using CommandPool = VkCommandPool;
using Buffer = VkBuffer;
using BufferView = VkBufferView;
using Image = VkImage;
using ImageView = VkImageView;
using ShaderModule = VkShaderModule;
using Pipeline = VkPipeline;
using PipelineLayout = VkPipelineLayout;
using Sampler = VkSampler;
using DescriptorSet = VkDescriptorSet;
using DescriptorSetLayout = VkDescriptorSetLayout;
using DescriptorPool = VkDescriptorPool;
using Fence = VkFence;
using Semaphore = VkSemaphore;
using Event = VkEvent;
using QueryPool = VkQueryPool;
using Framebuffer = VkFramebuffer;
using RenderPass = VkRenderPass;
using PipelineCache = VkPipelineCache;
using IndirectCommandsLayoutNV = VkIndirectCommandsLayoutNV;
using DescriptorUpdateTemplate = VkDescriptorUpdateTemplate;
using DescriptorUpdateTemplateKHR = VkDescriptorUpdateTemplate;
using SamplerYcbcrConversion = VkSamplerYcbcrConversion;
using SamplerYcbcrConversionKHR = VkSamplerYcbcrConversion;
using ValidationCacheEXT = VkValidationCacheEXT;
using AccelerationStructureKHR = VkAccelerationStructureKHR;
using AccelerationStructureNV = VkAccelerationStructureNV;
using PerformanceConfigurationINTEL = VkPerformanceConfigurationINTEL;
#if defined(VK_USE_PLATFORM_FUCHSIA)
using BufferCollectionFUCHSIA = VkBufferCollectionFUCHSIA;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
using DeferredOperationKHR = VkDeferredOperationKHR;
using PrivateDataSlot = VkPrivateDataSlot;
using PrivateDataSlotEXT = VkPrivateDataSlot;
using CuModuleNVX = VkCuModuleNVX;
using CuFunctionNVX = VkCuFunctionNVX;
using OpticalFlowSessionNV = VkOpticalFlowSessionNV;
using MicromapEXT = VkMicromapEXT;
using ShaderEXT = VkShaderEXT;
using DisplayKHR = VkDisplayKHR;
using DisplayModeKHR = VkDisplayModeKHR;
using SurfaceKHR = VkSurfaceKHR;
using SwapchainKHR = VkSwapchainKHR;
using DebugReportCallbackEXT = VkDebugReportCallbackEXT;
using DebugUtilsMessengerEXT = VkDebugUtilsMessengerEXT;
using VideoSessionKHR = VkVideoSessionKHR;
using VideoSessionParametersKHR = VkVideoSessionParametersKHR;
using CudaModuleNV = VkCudaModuleNV;
using CudaFunctionNV = VkCudaFunctionNV;
enum class AttachmentLoadOp : uint32_t {
    Load = 0,
    Clear = 1,
    DontCare = 2,
    NoneKHR = 1000400000,
};
enum class AttachmentStoreOp : uint32_t {
    Store = 0,
    DontCare = 1,
    None = 1000301000,
};
enum class BlendFactor : uint32_t {
    Zero = 0,
    One = 1,
    SrcColor = 2,
    OneMinusSrcColor = 3,
    DstColor = 4,
    OneMinusDstColor = 5,
    SrcAlpha = 6,
    OneMinusSrcAlpha = 7,
    DstAlpha = 8,
    OneMinusDstAlpha = 9,
    ConstantColor = 10,
    OneMinusConstantColor = 11,
    ConstantAlpha = 12,
    OneMinusConstantAlpha = 13,
    SrcAlphaSaturate = 14,
    Src1Color = 15,
    OneMinusSrc1Color = 16,
    Src1Alpha = 17,
    OneMinusSrc1Alpha = 18,
};
enum class BlendOp : uint32_t {
    Add = 0,
    Subtract = 1,
    ReverseSubtract = 2,
    Min = 3,
    Max = 4,
    ZeroEXT = 1000148000,
    SrcEXT = 1000148001,
    DstEXT = 1000148002,
    SrcOverEXT = 1000148003,
    DstOverEXT = 1000148004,
    SrcInEXT = 1000148005,
    DstInEXT = 1000148006,
    SrcOutEXT = 1000148007,
    DstOutEXT = 1000148008,
    SrcAtopEXT = 1000148009,
    DstAtopEXT = 1000148010,
    XorEXT = 1000148011,
    MultiplyEXT = 1000148012,
    ScreenEXT = 1000148013,
    OverlayEXT = 1000148014,
    DarkenEXT = 1000148015,
    LightenEXT = 1000148016,
    ColordodgeEXT = 1000148017,
    ColorburnEXT = 1000148018,
    HardlightEXT = 1000148019,
    SoftlightEXT = 1000148020,
    DifferenceEXT = 1000148021,
    ExclusionEXT = 1000148022,
    InvertEXT = 1000148023,
    InvertRgbEXT = 1000148024,
    LineardodgeEXT = 1000148025,
    LinearburnEXT = 1000148026,
    VividlightEXT = 1000148027,
    LinearlightEXT = 1000148028,
    PinlightEXT = 1000148029,
    HardmixEXT = 1000148030,
    HslHueEXT = 1000148031,
    HslSaturationEXT = 1000148032,
    HslColorEXT = 1000148033,
    HslLuminosityEXT = 1000148034,
    PlusEXT = 1000148035,
    PlusClampedEXT = 1000148036,
    PlusClampedAlphaEXT = 1000148037,
    PlusDarkerEXT = 1000148038,
    MinusEXT = 1000148039,
    MinusClampedEXT = 1000148040,
    ContrastEXT = 1000148041,
    InvertOvgEXT = 1000148042,
    RedEXT = 1000148043,
    GreenEXT = 1000148044,
    BlueEXT = 1000148045,
};
enum class BorderColor : uint32_t {
    FloatTransparentBlack = 0,
    IntTransparentBlack = 1,
    FloatOpaqueBlack = 2,
    IntOpaqueBlack = 3,
    FloatOpaqueWhite = 4,
    IntOpaqueWhite = 5,
    FloatCustomEXT = 1000287003,
    IntCustomEXT = 1000287004,
};
enum class PipelineCacheHeaderVersion : uint32_t {
    One = 1,
};
enum class ComponentSwizzle : uint32_t {
    Identity = 0,
    Zero = 1,
    One = 2,
    R = 3,
    G = 4,
    B = 5,
    A = 6,
};
enum class CommandBufferLevel : uint32_t {
    Primary = 0,
    Secondary = 1,
};
enum class CompareOp : uint32_t {
    Never = 0,
    Less = 1,
    Equal = 2,
    LessOrEqual = 3,
    Greater = 4,
    NotEqual = 5,
    GreaterOrEqual = 6,
    Always = 7,
};
enum class DescriptorType : uint32_t {
    Sampler = 0,
    CombinedImageSampler = 1,
    SampledImage = 2,
    StorageImage = 3,
    UniformTexelBuffer = 4,
    StorageTexelBuffer = 5,
    UniformBuffer = 6,
    StorageBuffer = 7,
    UniformBufferDynamic = 8,
    StorageBufferDynamic = 9,
    InputAttachment = 10,
    InlineUniformBlock = 1000138000,
    AccelerationStructureKHR = 1000150000,
    AccelerationStructureNV = 1000165000,
    SampleWeightImageQCOM = 1000440000,
    BlockMatchImageQCOM = 1000440001,
    MutableEXT = 1000351000,
};
enum class DynamicState : uint32_t {
    Viewport = 0,
    Scissor = 1,
    LineWidth = 2,
    DepthBias = 3,
    BlendConstants = 4,
    DepthBounds = 5,
    StencilCompareMask = 6,
    StencilWriteMask = 7,
    StencilReference = 8,
    CullMode = 1000267000,
    FrontFace = 1000267001,
    PrimitiveTopology = 1000267002,
    ViewportWithCount = 1000267003,
    ScissorWithCount = 1000267004,
    VertexInputBindingStride = 1000267005,
    DepthTestEnable = 1000267006,
    DepthWriteEnable = 1000267007,
    DepthCompareOp = 1000267008,
    DepthBoundsTestEnable = 1000267009,
    StencilTestEnable = 1000267010,
    StencilOp = 1000267011,
    RasterizerDiscardEnable = 1000377001,
    DepthBiasEnable = 1000377002,
    PrimitiveRestartEnable = 1000377004,
    ViewportWScalingNV = 1000087000,
    DiscardRectangleEXT = 1000099000,
    DiscardRectangleEnableEXT = 1000099001,
    DiscardRectangleModeEXT = 1000099002,
    SampleLocationsEXT = 1000143000,
    RayTracingPipelineStackSizeKHR = 1000347000,
    ViewportShadingRatePaletteNV = 1000164004,
    ViewportCoarseSampleOrderNV = 1000164006,
    ExclusiveScissorEnableNV = 1000205000,
    ExclusiveScissorNV = 1000205001,
    FragmentShadingRateKHR = 1000226000,
    VertexInputEXT = 1000352000,
    PatchControlPointsEXT = 1000377000,
    LogicOpEXT = 1000377003,
    ColorWriteEnableEXT = 1000381000,
    DepthClampEnableEXT = 1000455003,
    PolygonModeEXT = 1000455004,
    RasterizationSamplesEXT = 1000455005,
    SampleMaskEXT = 1000455006,
    AlphaToCoverageEnableEXT = 1000455007,
    AlphaToOneEnableEXT = 1000455008,
    LogicOpEnableEXT = 1000455009,
    ColorBlendEnableEXT = 1000455010,
    ColorBlendEquationEXT = 1000455011,
    ColorWriteMaskEXT = 1000455012,
    TessellationDomainOriginEXT = 1000455002,
    RasterizationStreamEXT = 1000455013,
    ConservativeRasterizationModeEXT = 1000455014,
    ExtraPrimitiveOverestimationSizeEXT = 1000455015,
    DepthClipEnableEXT = 1000455016,
    SampleLocationsEnableEXT = 1000455017,
    ColorBlendAdvancedEXT = 1000455018,
    ProvokingVertexModeEXT = 1000455019,
    LineRasterizationModeEXT = 1000455020,
    LineStippleEnableEXT = 1000455021,
    DepthClipNegativeOneToOneEXT = 1000455022,
    ViewportWScalingEnableNV = 1000455023,
    ViewportSwizzleNV = 1000455024,
    CoverageToColorEnableNV = 1000455025,
    CoverageToColorLocationNV = 1000455026,
    CoverageModulationModeNV = 1000455027,
    CoverageModulationTableEnableNV = 1000455028,
    CoverageModulationTableNV = 1000455029,
    ShadingRateImageEnableNV = 1000455030,
    RepresentativeFragmentTestEnableNV = 1000455031,
    CoverageReductionModeNV = 1000455032,
    AttachmentFeedbackLoopEnableEXT = 1000524000,
    LineStippleKHR = 1000259000,
};
enum class PolygonMode : uint32_t {
    Fill = 0,
    Line = 1,
    Point = 2,
    FillRectangleNV = 1000153000,
};
enum class Format : uint32_t {
    Undefined = 0,
    R4G4UnormPack8 = 1,
    R4G4B4A4UnormPack16 = 2,
    B4G4R4A4UnormPack16 = 3,
    R5G6B5UnormPack16 = 4,
    B5G6R5UnormPack16 = 5,
    R5G5B5A1UnormPack16 = 6,
    B5G5R5A1UnormPack16 = 7,
    A1R5G5B5UnormPack16 = 8,
    R8Unorm = 9,
    R8Snorm = 10,
    R8Uscaled = 11,
    R8Sscaled = 12,
    R8Uint = 13,
    R8Sint = 14,
    R8Srgb = 15,
    R8G8Unorm = 16,
    R8G8Snorm = 17,
    R8G8Uscaled = 18,
    R8G8Sscaled = 19,
    R8G8Uint = 20,
    R8G8Sint = 21,
    R8G8Srgb = 22,
    R8G8B8Unorm = 23,
    R8G8B8Snorm = 24,
    R8G8B8Uscaled = 25,
    R8G8B8Sscaled = 26,
    R8G8B8Uint = 27,
    R8G8B8Sint = 28,
    R8G8B8Srgb = 29,
    B8G8R8Unorm = 30,
    B8G8R8Snorm = 31,
    B8G8R8Uscaled = 32,
    B8G8R8Sscaled = 33,
    B8G8R8Uint = 34,
    B8G8R8Sint = 35,
    B8G8R8Srgb = 36,
    R8G8B8A8Unorm = 37,
    R8G8B8A8Snorm = 38,
    R8G8B8A8Uscaled = 39,
    R8G8B8A8Sscaled = 40,
    R8G8B8A8Uint = 41,
    R8G8B8A8Sint = 42,
    R8G8B8A8Srgb = 43,
    B8G8R8A8Unorm = 44,
    B8G8R8A8Snorm = 45,
    B8G8R8A8Uscaled = 46,
    B8G8R8A8Sscaled = 47,
    B8G8R8A8Uint = 48,
    B8G8R8A8Sint = 49,
    B8G8R8A8Srgb = 50,
    A8B8G8R8UnormPack32 = 51,
    A8B8G8R8SnormPack32 = 52,
    A8B8G8R8UscaledPack32 = 53,
    A8B8G8R8SscaledPack32 = 54,
    A8B8G8R8UintPack32 = 55,
    A8B8G8R8SintPack32 = 56,
    A8B8G8R8SrgbPack32 = 57,
    A2R10G10B10UnormPack32 = 58,
    A2R10G10B10SnormPack32 = 59,
    A2R10G10B10UscaledPack32 = 60,
    A2R10G10B10SscaledPack32 = 61,
    A2R10G10B10UintPack32 = 62,
    A2R10G10B10SintPack32 = 63,
    A2B10G10R10UnormPack32 = 64,
    A2B10G10R10SnormPack32 = 65,
    A2B10G10R10UscaledPack32 = 66,
    A2B10G10R10SscaledPack32 = 67,
    A2B10G10R10UintPack32 = 68,
    A2B10G10R10SintPack32 = 69,
    R16Unorm = 70,
    R16Snorm = 71,
    R16Uscaled = 72,
    R16Sscaled = 73,
    R16Uint = 74,
    R16Sint = 75,
    R16Sfloat = 76,
    R16G16Unorm = 77,
    R16G16Snorm = 78,
    R16G16Uscaled = 79,
    R16G16Sscaled = 80,
    R16G16Uint = 81,
    R16G16Sint = 82,
    R16G16Sfloat = 83,
    R16G16B16Unorm = 84,
    R16G16B16Snorm = 85,
    R16G16B16Uscaled = 86,
    R16G16B16Sscaled = 87,
    R16G16B16Uint = 88,
    R16G16B16Sint = 89,
    R16G16B16Sfloat = 90,
    R16G16B16A16Unorm = 91,
    R16G16B16A16Snorm = 92,
    R16G16B16A16Uscaled = 93,
    R16G16B16A16Sscaled = 94,
    R16G16B16A16Uint = 95,
    R16G16B16A16Sint = 96,
    R16G16B16A16Sfloat = 97,
    R32Uint = 98,
    R32Sint = 99,
    R32Sfloat = 100,
    R32G32Uint = 101,
    R32G32Sint = 102,
    R32G32Sfloat = 103,
    R32G32B32Uint = 104,
    R32G32B32Sint = 105,
    R32G32B32Sfloat = 106,
    R32G32B32A32Uint = 107,
    R32G32B32A32Sint = 108,
    R32G32B32A32Sfloat = 109,
    R64Uint = 110,
    R64Sint = 111,
    R64Sfloat = 112,
    R64G64Uint = 113,
    R64G64Sint = 114,
    R64G64Sfloat = 115,
    R64G64B64Uint = 116,
    R64G64B64Sint = 117,
    R64G64B64Sfloat = 118,
    R64G64B64A64Uint = 119,
    R64G64B64A64Sint = 120,
    R64G64B64A64Sfloat = 121,
    B10G11R11UfloatPack32 = 122,
    E5B9G9R9UfloatPack32 = 123,
    D16Unorm = 124,
    X8D24UnormPack32 = 125,
    D32Sfloat = 126,
    S8Uint = 127,
    D16UnormS8Uint = 128,
    D24UnormS8Uint = 129,
    D32SfloatS8Uint = 130,
    Bc1RgbUnormBlock = 131,
    Bc1RgbSrgbBlock = 132,
    Bc1RgbaUnormBlock = 133,
    Bc1RgbaSrgbBlock = 134,
    Bc2UnormBlock = 135,
    Bc2SrgbBlock = 136,
    Bc3UnormBlock = 137,
    Bc3SrgbBlock = 138,
    Bc4UnormBlock = 139,
    Bc4SnormBlock = 140,
    Bc5UnormBlock = 141,
    Bc5SnormBlock = 142,
    Bc6HUfloatBlock = 143,
    Bc6HSfloatBlock = 144,
    Bc7UnormBlock = 145,
    Bc7SrgbBlock = 146,
    Etc2R8G8B8UnormBlock = 147,
    Etc2R8G8B8SrgbBlock = 148,
    Etc2R8G8B8A1UnormBlock = 149,
    Etc2R8G8B8A1SrgbBlock = 150,
    Etc2R8G8B8A8UnormBlock = 151,
    Etc2R8G8B8A8SrgbBlock = 152,
    EacR11UnormBlock = 153,
    EacR11SnormBlock = 154,
    EacR11G11UnormBlock = 155,
    EacR11G11SnormBlock = 156,
    Astc4X4UnormBlock = 157,
    Astc4X4SrgbBlock = 158,
    Astc5X4UnormBlock = 159,
    Astc5X4SrgbBlock = 160,
    Astc5X5UnormBlock = 161,
    Astc5X5SrgbBlock = 162,
    Astc6X5UnormBlock = 163,
    Astc6X5SrgbBlock = 164,
    Astc6X6UnormBlock = 165,
    Astc6X6SrgbBlock = 166,
    Astc8X5UnormBlock = 167,
    Astc8X5SrgbBlock = 168,
    Astc8X6UnormBlock = 169,
    Astc8X6SrgbBlock = 170,
    Astc8X8UnormBlock = 171,
    Astc8X8SrgbBlock = 172,
    Astc10X5UnormBlock = 173,
    Astc10X5SrgbBlock = 174,
    Astc10X6UnormBlock = 175,
    Astc10X6SrgbBlock = 176,
    Astc10X8UnormBlock = 177,
    Astc10X8SrgbBlock = 178,
    Astc10X10UnormBlock = 179,
    Astc10X10SrgbBlock = 180,
    Astc12X10UnormBlock = 181,
    Astc12X10SrgbBlock = 182,
    Astc12X12UnormBlock = 183,
    Astc12X12SrgbBlock = 184,
    G8B8G8R8422Unorm = 1000156000,
    B8G8R8G8422Unorm = 1000156001,
    G8B8R83Plane420Unorm = 1000156002,
    G8B8R82Plane420Unorm = 1000156003,
    G8B8R83Plane422Unorm = 1000156004,
    G8B8R82Plane422Unorm = 1000156005,
    G8B8R83Plane444Unorm = 1000156006,
    R10X6UnormPack16 = 1000156007,
    R10X6G10X6Unorm2Pack16 = 1000156008,
    R10X6G10X6B10X6A10X6Unorm4Pack16 = 1000156009,
    G10X6B10X6G10X6R10X6422Unorm4Pack16 = 1000156010,
    B10X6G10X6R10X6G10X6422Unorm4Pack16 = 1000156011,
    G10X6B10X6R10X63Plane420Unorm3Pack16 = 1000156012,
    G10X6B10X6R10X62Plane420Unorm3Pack16 = 1000156013,
    G10X6B10X6R10X63Plane422Unorm3Pack16 = 1000156014,
    G10X6B10X6R10X62Plane422Unorm3Pack16 = 1000156015,
    G10X6B10X6R10X63Plane444Unorm3Pack16 = 1000156016,
    R12X4UnormPack16 = 1000156017,
    R12X4G12X4Unorm2Pack16 = 1000156018,
    R12X4G12X4B12X4A12X4Unorm4Pack16 = 1000156019,
    G12X4B12X4G12X4R12X4422Unorm4Pack16 = 1000156020,
    B12X4G12X4R12X4G12X4422Unorm4Pack16 = 1000156021,
    G12X4B12X4R12X43Plane420Unorm3Pack16 = 1000156022,
    G12X4B12X4R12X42Plane420Unorm3Pack16 = 1000156023,
    G12X4B12X4R12X43Plane422Unorm3Pack16 = 1000156024,
    G12X4B12X4R12X42Plane422Unorm3Pack16 = 1000156025,
    G12X4B12X4R12X43Plane444Unorm3Pack16 = 1000156026,
    G16B16G16R16422Unorm = 1000156027,
    B16G16R16G16422Unorm = 1000156028,
    G16B16R163Plane420Unorm = 1000156029,
    G16B16R162Plane420Unorm = 1000156030,
    G16B16R163Plane422Unorm = 1000156031,
    G16B16R162Plane422Unorm = 1000156032,
    G16B16R163Plane444Unorm = 1000156033,
    G8B8R82Plane444Unorm = 1000330000,
    G10X6B10X6R10X62Plane444Unorm3Pack16 = 1000330001,
    G12X4B12X4R12X42Plane444Unorm3Pack16 = 1000330002,
    G16B16R162Plane444Unorm = 1000330003,
    A4R4G4B4UnormPack16 = 1000340000,
    A4B4G4R4UnormPack16 = 1000340001,
    Astc4X4SfloatBlock = 1000066000,
    Astc5X4SfloatBlock = 1000066001,
    Astc5X5SfloatBlock = 1000066002,
    Astc6X5SfloatBlock = 1000066003,
    Astc6X6SfloatBlock = 1000066004,
    Astc8X5SfloatBlock = 1000066005,
    Astc8X6SfloatBlock = 1000066006,
    Astc8X8SfloatBlock = 1000066007,
    Astc10X5SfloatBlock = 1000066008,
    Astc10X6SfloatBlock = 1000066009,
    Astc10X8SfloatBlock = 1000066010,
    Astc10X10SfloatBlock = 1000066011,
    Astc12X10SfloatBlock = 1000066012,
    Astc12X12SfloatBlock = 1000066013,
    Pvrtc12BppUnormBlockIMG = 1000054000,
    Pvrtc14BppUnormBlockIMG = 1000054001,
    Pvrtc22BppUnormBlockIMG = 1000054002,
    Pvrtc24BppUnormBlockIMG = 1000054003,
    Pvrtc12BppSrgbBlockIMG = 1000054004,
    Pvrtc14BppSrgbBlockIMG = 1000054005,
    Pvrtc22BppSrgbBlockIMG = 1000054006,
    Pvrtc24BppSrgbBlockIMG = 1000054007,
    R16G16S105NV = 1000464000,
    A1B5G5R5UnormPack16KHR = 1000470000,
    A8UnormKHR = 1000470001,
};
enum class FrontFace : uint32_t {
    CounterClockwise = 0,
    Clockwise = 1,
};
enum class ImageLayout : uint32_t {
    Undefined = 0,
    General = 1,
    ColorAttachmentOptimal = 2,
    DepthStencilAttachmentOptimal = 3,
    DepthStencilReadOnlyOptimal = 4,
    ShaderReadOnlyOptimal = 5,
    TransferSrcOptimal = 6,
    TransferDstOptimal = 7,
    Preinitialized = 8,
    DepthReadOnlyStencilAttachmentOptimal = 1000117000,
    DepthAttachmentStencilReadOnlyOptimal = 1000117001,
    DepthAttachmentOptimal = 1000241000,
    DepthReadOnlyOptimal = 1000241001,
    StencilAttachmentOptimal = 1000241002,
    StencilReadOnlyOptimal = 1000241003,
    ReadOnlyOptimal = 1000314000,
    AttachmentOptimal = 1000314001,
    PresentSrcKHR = 1000001002,
    VideoDecodeDstKHR = 1000024000,
    VideoDecodeSrcKHR = 1000024001,
    VideoDecodeDpbKHR = 1000024002,
    SharedPresentKHR = 1000111000,
    FragmentDensityMapOptimalEXT = 1000218000,
    FragmentShadingRateAttachmentOptimalKHR = 1000164003,
    RenderingLocalReadKHR = 1000232000,
    VideoEncodeDstKHR = 1000299000,
    VideoEncodeSrcKHR = 1000299001,
    VideoEncodeDpbKHR = 1000299002,
    AttachmentFeedbackLoopOptimalEXT = 1000339000,
};
enum class ImageTiling : uint32_t {
    Optimal = 0,
    Linear = 1,
    DrmFormatModifierEXT = 1000158000,
};
enum class ImageType : uint32_t {
    e1D = 0,
    e2D = 1,
    e3D = 2,
};
enum class ImageViewType : uint32_t {
    e1D = 0,
    e2D = 1,
    e3D = 2,
    Cube = 3,
    e1DArray = 4,
    e2DArray = 5,
    CubeArray = 6,
};
enum class SharingMode : uint32_t {
    Exclusive = 0,
    Concurrent = 1,
};
enum class IndexType : uint32_t {
    Uint16 = 0,
    Uint32 = 1,
    NoneKHR = 1000165000,
    Uint8KHR = 1000265000,
};
enum class LogicOp : uint32_t {
    Clear = 0,
    And = 1,
    AndReverse = 2,
    Copy = 3,
    AndInverted = 4,
    NoOp = 5,
    Xor = 6,
    Or = 7,
    Nor = 8,
    Equivalent = 9,
    Invert = 10,
    OrReverse = 11,
    CopyInverted = 12,
    OrInverted = 13,
    Nand = 14,
    Set = 15,
};
enum class PhysicalDeviceType : uint32_t {
    Other = 0,
    IntegratedGpu = 1,
    DiscreteGpu = 2,
    VirtualGpu = 3,
    Cpu = 4,
};
enum class PipelineBindPoint : uint32_t {
    Graphics = 0,
    Compute = 1,
    ExecutionGraphAMDX = 1000134000,
    RayTracingKHR = 1000165000,
    SubpassShadingHUAWEI = 1000369003,
};
enum class PrimitiveTopology : uint32_t {
    PointList = 0,
    LineList = 1,
    LineStrip = 2,
    TriangleList = 3,
    TriangleStrip = 4,
    TriangleFan = 5,
    LineListWithAdjacency = 6,
    LineStripWithAdjacency = 7,
    TriangleListWithAdjacency = 8,
    TriangleStripWithAdjacency = 9,
    PatchList = 10,
};
enum class QueryType : uint32_t {
    Occlusion = 0,
    PipelineStatistics = 1,
    Timestamp = 2,
    ResultStatusOnlyKHR = 1000023000,
    TransformFeedbackStreamEXT = 1000028004,
    PerformanceQueryKHR = 1000116000,
    AccelerationStructureCompactedSizeKHR = 1000150000,
    AccelerationStructureSerializationSizeKHR = 1000150001,
    AccelerationStructureCompactedSizeNV = 1000165000,
    PerformanceQueryINTEL = 1000210000,
    VideoEncodeFeedbackKHR = 1000299000,
    MeshPrimitivesGeneratedEXT = 1000328000,
    PrimitivesGeneratedEXT = 1000382000,
    AccelerationStructureSerializationBottomLevelPointersKHR = 1000386000,
    AccelerationStructureSizeKHR = 1000386001,
    MicromapSerializationSizeEXT = 1000396000,
    MicromapCompactedSizeEXT = 1000396001,
};
enum class SubpassContents : uint32_t {
    Inline = 0,
    SecondaryCommandBuffers = 1,
    InlineAndSecondaryCommandBuffersEXT = 1000451000,
};
enum class Result : int32_t {
    Success = 0,
    NotReady = 1,
    Timeout = 2,
    EventSet = 3,
    EventReset = 4,
    Incomplete = 5,
    ErrorOutOfHostMemory = -1,
    ErrorOutOfDeviceMemory = -2,
    ErrorInitializationFailed = -3,
    ErrorDeviceLost = -4,
    ErrorMemoryMapFailed = -5,
    ErrorLayerNotPresent = -6,
    ErrorExtensionNotPresent = -7,
    ErrorFeatureNotPresent = -8,
    ErrorIncompatibleDriver = -9,
    ErrorTooManyObjects = -10,
    ErrorFormatNotSupported = -11,
    ErrorFragmentedPool = -12,
    ErrorUnknown = -13,
    ErrorOutOfPoolMemory = -1000069000,
    ErrorInvalidExternalHandle = -1000072003,
    ErrorFragmentation = -1000161000,
    ErrorInvalidOpaqueCaptureAddress = -1000257000,
    PipelineCompileRequired = 1000297000,
    ErrorSurfaceLostKHR = -1000000000,
    ErrorNativeWindowInUseKHR = -1000000001,
    SuboptimalKHR = 1000001003,
    ErrorOutOfDateKHR = -1000001004,
    ErrorIncompatibleDisplayKHR = -1000003001,
    ErrorValidationFailedEXT = -1000011001,
    ErrorInvalidShaderNV = -1000012000,
    ErrorImageUsageNotSupportedKHR = -1000023000,
    ErrorVideoPictureLayoutNotSupportedKHR = -1000023001,
    ErrorVideoProfileOperationNotSupportedKHR = -1000023002,
    ErrorVideoProfileFormatNotSupportedKHR = -1000023003,
    ErrorVideoProfileCodecNotSupportedKHR = -1000023004,
    ErrorVideoStdVersionNotSupportedKHR = -1000023005,
    ErrorInvalidDrmFormatModifierPlaneLayoutEXT = -1000158000,
    ErrorNotPermittedKHR = -1000174001,
    ErrorFullScreenExclusiveModeLostEXT = -1000255000,
    ThreadIdleKHR = 1000268000,
    ThreadDoneKHR = 1000268001,
    OperationDeferredKHR = 1000268002,
    OperationNotDeferredKHR = 1000268003,
    ErrorInvalidVideoStdParametersKHR = -1000299000,
    ErrorCompressionExhaustedEXT = -1000338000,
    ErrorIncompatibleShaderBinaryEXT = 1000482000,
};
enum class StencilOp : uint32_t {
    Keep = 0,
    Zero = 1,
    Replace = 2,
    IncrementAndClamp = 3,
    DecrementAndClamp = 4,
    Invert = 5,
    IncrementAndWrap = 6,
    DecrementAndWrap = 7,
};
enum class StructureType : uint32_t {
    ApplicationInfo = 0,
    InstanceCreateInfo = 1,
    DeviceQueueCreateInfo = 2,
    DeviceCreateInfo = 3,
    SubmitInfo = 4,
    MemoryAllocateInfo = 5,
    MappedMemoryRange = 6,
    BindSparseInfo = 7,
    FenceCreateInfo = 8,
    SemaphoreCreateInfo = 9,
    EventCreateInfo = 10,
    QueryPoolCreateInfo = 11,
    BufferCreateInfo = 12,
    BufferViewCreateInfo = 13,
    ImageCreateInfo = 14,
    ImageViewCreateInfo = 15,
    ShaderModuleCreateInfo = 16,
    PipelineCacheCreateInfo = 17,
    PipelineShaderStageCreateInfo = 18,
    PipelineVertexInputStateCreateInfo = 19,
    PipelineInputAssemblyStateCreateInfo = 20,
    PipelineTessellationStateCreateInfo = 21,
    PipelineViewportStateCreateInfo = 22,
    PipelineRasterizationStateCreateInfo = 23,
    PipelineMultisampleStateCreateInfo = 24,
    PipelineDepthStencilStateCreateInfo = 25,
    PipelineColorBlendStateCreateInfo = 26,
    PipelineDynamicStateCreateInfo = 27,
    GraphicsPipelineCreateInfo = 28,
    ComputePipelineCreateInfo = 29,
    PipelineLayoutCreateInfo = 30,
    SamplerCreateInfo = 31,
    DescriptorSetLayoutCreateInfo = 32,
    DescriptorPoolCreateInfo = 33,
    DescriptorSetAllocateInfo = 34,
    WriteDescriptorSet = 35,
    CopyDescriptorSet = 36,
    FramebufferCreateInfo = 37,
    RenderPassCreateInfo = 38,
    CommandPoolCreateInfo = 39,
    CommandBufferAllocateInfo = 40,
    CommandBufferInheritanceInfo = 41,
    CommandBufferBeginInfo = 42,
    RenderPassBeginInfo = 43,
    BufferMemoryBarrier = 44,
    ImageMemoryBarrier = 45,
    MemoryBarrier = 46,
    LoaderInstanceCreateInfo = 47,
    LoaderDeviceCreateInfo = 48,
    PhysicalDeviceSubgroupProperties = 1000094000,
    BindBufferMemoryInfo = 1000157000,
    BindImageMemoryInfo = 1000157001,
    PhysicalDevice16StorageFeatures = 1000083000,
    MemoryDedicatedRequirements = 1000127000,
    MemoryDedicatedAllocateInfo = 1000127001,
    MemoryAllocateFlagsInfo = 1000060000,
    DeviceGroupRenderPassBeginInfo = 1000060003,
    DeviceGroupCommandBufferBeginInfo = 1000060004,
    DeviceGroupSubmitInfo = 1000060005,
    DeviceGroupBindSparseInfo = 1000060006,
    BindBufferMemoryDeviceGroupInfo = 1000060013,
    BindImageMemoryDeviceGroupInfo = 1000060014,
    PhysicalDeviceGroupProperties = 1000070000,
    DeviceGroupDeviceCreateInfo = 1000070001,
    BufferMemoryRequirementsInfo2 = 1000146000,
    ImageMemoryRequirementsInfo2 = 1000146001,
    ImageSparseMemoryRequirementsInfo2 = 1000146002,
    MemoryRequirements2 = 1000146003,
    SparseImageMemoryRequirements2 = 1000146004,
    PhysicalDeviceFeatures2 = 1000059000,
    PhysicalDeviceProperties2 = 1000059001,
    FormatProperties2 = 1000059002,
    ImageFormatProperties2 = 1000059003,
    PhysicalDeviceImageFormatInfo2 = 1000059004,
    QueueFamilyProperties2 = 1000059005,
    PhysicalDeviceMemoryProperties2 = 1000059006,
    SparseImageFormatProperties2 = 1000059007,
    PhysicalDeviceSparseImageFormatInfo2 = 1000059008,
    PhysicalDevicePointClippingProperties = 1000117000,
    RenderPassInputAttachmentAspectCreateInfo = 1000117001,
    ImageViewUsageCreateInfo = 1000117002,
    PipelineTessellationDomainOriginStateCreateInfo = 1000117003,
    RenderPassMultiviewCreateInfo = 1000053000,
    PhysicalDeviceMultiviewFeatures = 1000053001,
    PhysicalDeviceMultiviewProperties = 1000053002,
    PhysicalDeviceVariablePointersFeatures = 1000120000,
    ProtectedSubmitInfo = 1000145000,
    PhysicalDeviceProtectedMemoryFeatures = 1000145001,
    PhysicalDeviceProtectedMemoryProperties = 1000145002,
    DeviceQueueInfo2 = 1000145003,
    SamplerYcbcrConversionCreateInfo = 1000156000,
    SamplerYcbcrConversionInfo = 1000156001,
    BindImagePlaneMemoryInfo = 1000156002,
    ImagePlaneMemoryRequirementsInfo = 1000156003,
    PhysicalDeviceSamplerYcbcrConversionFeatures = 1000156004,
    SamplerYcbcrConversionImageFormatProperties = 1000156005,
    DescriptorUpdateTemplateCreateInfo = 1000085000,
    PhysicalDeviceExternalImageFormatInfo = 1000071000,
    ExternalImageFormatProperties = 1000071001,
    PhysicalDeviceExternalBufferInfo = 1000071002,
    ExternalBufferProperties = 1000071003,
    PhysicalDeviceIdProperties = 1000071004,
    ExternalMemoryBufferCreateInfo = 1000072000,
    ExternalMemoryImageCreateInfo = 1000072001,
    ExportMemoryAllocateInfo = 1000072002,
    PhysicalDeviceExternalFenceInfo = 1000112000,
    ExternalFenceProperties = 1000112001,
    ExportFenceCreateInfo = 1000113000,
    ExportSemaphoreCreateInfo = 1000077000,
    PhysicalDeviceExternalSemaphoreInfo = 1000076000,
    ExternalSemaphoreProperties = 1000076001,
    PhysicalDeviceMaintenance3Properties = 1000168000,
    DescriptorSetLayoutSupport = 1000168001,
    PhysicalDeviceShaderDrawParametersFeatures = 1000063000,
    PhysicalDeviceVulkan11Features = 49,
    PhysicalDeviceVulkan11Properties = 50,
    PhysicalDeviceVulkan12Features = 51,
    PhysicalDeviceVulkan12Properties = 52,
    ImageFormatListCreateInfo = 1000147000,
    AttachmentDescription2 = 1000109000,
    AttachmentReference2 = 1000109001,
    SubpassDescription2 = 1000109002,
    SubpassDependency2 = 1000109003,
    RenderPassCreateInfo2 = 1000109004,
    SubpassBeginInfo = 1000109005,
    SubpassEndInfo = 1000109006,
    PhysicalDevice8StorageFeatures = 1000177000,
    PhysicalDeviceDriverProperties = 1000196000,
    PhysicalDeviceShaderAtomicInt64Features = 1000180000,
    PhysicalDeviceShaderFloat16Int8Features = 1000082000,
    PhysicalDeviceFloatControlsProperties = 1000197000,
    DescriptorSetLayoutBindingFlagsCreateInfo = 1000161000,
    PhysicalDeviceDescriptorIndexingFeatures = 1000161001,
    PhysicalDeviceDescriptorIndexingProperties = 1000161002,
    DescriptorSetVariableDescriptorCountAllocateInfo = 1000161003,
    DescriptorSetVariableDescriptorCountLayoutSupport = 1000161004,
    PhysicalDeviceDepthStencilResolveProperties = 1000199000,
    SubpassDescriptionDepthStencilResolve = 1000199001,
    PhysicalDeviceScalarBlockLayoutFeatures = 1000221000,
    ImageStencilUsageCreateInfo = 1000246000,
    PhysicalDeviceSamplerFilterMinmaxProperties = 1000130000,
    SamplerReductionModeCreateInfo = 1000130001,
    PhysicalDeviceVulkanMemoryModelFeatures = 1000211000,
    PhysicalDeviceImagelessFramebufferFeatures = 1000108000,
    FramebufferAttachmentsCreateInfo = 1000108001,
    FramebufferAttachmentImageInfo = 1000108002,
    RenderPassAttachmentBeginInfo = 1000108003,
    PhysicalDeviceUniformBufferStandardLayoutFeatures = 1000253000,
    PhysicalDeviceShaderSubgroupExtendedTypesFeatures = 1000175000,
    PhysicalDeviceSeparateDepthStencilLayoutsFeatures = 1000241000,
    AttachmentReferenceStencilLayout = 1000241001,
    AttachmentDescriptionStencilLayout = 1000241002,
    PhysicalDeviceHostQueryResetFeatures = 1000261000,
    PhysicalDeviceTimelineSemaphoreFeatures = 1000207000,
    PhysicalDeviceTimelineSemaphoreProperties = 1000207001,
    SemaphoreTypeCreateInfo = 1000207002,
    TimelineSemaphoreSubmitInfo = 1000207003,
    SemaphoreWaitInfo = 1000207004,
    SemaphoreSignalInfo = 1000207005,
    PhysicalDeviceBufferDeviceAddressFeatures = 1000257000,
    BufferDeviceAddressInfo = 1000244001,
    BufferOpaqueCaptureAddressCreateInfo = 1000257002,
    MemoryOpaqueCaptureAddressAllocateInfo = 1000257003,
    DeviceMemoryOpaqueCaptureAddressInfo = 1000257004,
    PhysicalDeviceVulkan13Features = 53,
    PhysicalDeviceVulkan13Properties = 54,
    PipelineCreationFeedbackCreateInfo = 1000192000,
    PhysicalDeviceShaderTerminateInvocationFeatures = 1000215000,
    PhysicalDeviceToolProperties = 1000245000,
    PhysicalDeviceShaderDemoteToHelperInvocationFeatures = 1000276000,
    PhysicalDevicePrivateDataFeatures = 1000295000,
    DevicePrivateDataCreateInfo = 1000295001,
    PrivateDataSlotCreateInfo = 1000295002,
    PhysicalDevicePipelineCreationCacheControlFeatures = 1000297000,
    MemoryBarrier2 = 1000314000,
    BufferMemoryBarrier2 = 1000314001,
    ImageMemoryBarrier2 = 1000314002,
    DependencyInfo = 1000314003,
    SubmitInfo2 = 1000314004,
    SemaphoreSubmitInfo = 1000314005,
    CommandBufferSubmitInfo = 1000314006,
    PhysicalDeviceSynchronization2Features = 1000314007,
    PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures = 1000325000,
    PhysicalDeviceImageRobustnessFeatures = 1000335000,
    CopyBufferInfo2 = 1000337000,
    CopyImageInfo2 = 1000337001,
    CopyBufferToImageInfo2 = 1000337002,
    CopyImageToBufferInfo2 = 1000337003,
    BlitImageInfo2 = 1000337004,
    ResolveImageInfo2 = 1000337005,
    BufferCopy2 = 1000337006,
    ImageCopy2 = 1000337007,
    ImageBlit2 = 1000337008,
    BufferImageCopy2 = 1000337009,
    ImageResolve2 = 1000337010,
    PhysicalDeviceSubgroupSizeControlProperties = 1000225000,
    PipelineShaderStageRequiredSubgroupSizeCreateInfo = 1000225001,
    PhysicalDeviceSubgroupSizeControlFeatures = 1000225002,
    PhysicalDeviceInlineUniformBlockFeatures = 1000138000,
    PhysicalDeviceInlineUniformBlockProperties = 1000138001,
    WriteDescriptorSetInlineUniformBlock = 1000138002,
    DescriptorPoolInlineUniformBlockCreateInfo = 1000138003,
    PhysicalDeviceTextureCompressionAstcHdrFeatures = 1000066000,
    RenderingInfo = 1000044000,
    RenderingAttachmentInfo = 1000044001,
    PipelineRenderingCreateInfo = 1000044002,
    PhysicalDeviceDynamicRenderingFeatures = 1000044003,
    CommandBufferInheritanceRenderingInfo = 1000044004,
    PhysicalDeviceShaderIntegerDotProductFeatures = 1000280000,
    PhysicalDeviceShaderIntegerDotProductProperties = 1000280001,
    PhysicalDeviceTexelBufferAlignmentProperties = 1000281001,
    FormatProperties3 = 1000360000,
    PhysicalDeviceMaintenance4Features = 1000413000,
    PhysicalDeviceMaintenance4Properties = 1000413001,
    DeviceBufferMemoryRequirements = 1000413002,
    DeviceImageMemoryRequirements = 1000413003,
    SwapchainCreateInfoKHR = 1000001000,
    PresentInfoKHR = 1000001001,
    DeviceGroupPresentCapabilitiesKHR = 1000060007,
    ImageSwapchainCreateInfoKHR = 1000060008,
    BindImageMemorySwapchainInfoKHR = 1000060009,
    AcquireNextImageInfoKHR = 1000060010,
    DeviceGroupPresentInfoKHR = 1000060011,
    DeviceGroupSwapchainCreateInfoKHR = 1000060012,
    DisplayModeCreateInfoKHR = 1000002000,
    DisplaySurfaceCreateInfoKHR = 1000002001,
    DisplayPresentInfoKHR = 1000003000,
    XlibSurfaceCreateInfoKHR = 1000004000,
    XcbSurfaceCreateInfoKHR = 1000005000,
    WaylandSurfaceCreateInfoKHR = 1000006000,
    AndroidSurfaceCreateInfoKHR = 1000008000,
    Win32SurfaceCreateInfoKHR = 1000009000,
    DebugReportCallbackCreateInfoEXT = 1000011000,
    PipelineRasterizationStateRasterizationOrderAMD = 1000018000,
    DebugMarkerObjectNameInfoEXT = 1000022000,
    DebugMarkerObjectTagInfoEXT = 1000022001,
    DebugMarkerMarkerInfoEXT = 1000022002,
    VideoProfileInfoKHR = 1000023000,
    VideoCapabilitiesKHR = 1000023001,
    VideoPictureResourceInfoKHR = 1000023002,
    VideoSessionMemoryRequirementsKHR = 1000023003,
    BindVideoSessionMemoryInfoKHR = 1000023004,
    VideoSessionCreateInfoKHR = 1000023005,
    VideoSessionParametersCreateInfoKHR = 1000023006,
    VideoSessionParametersUpdateInfoKHR = 1000023007,
    VideoBeginCodingInfoKHR = 1000023008,
    VideoEndCodingInfoKHR = 1000023009,
    VideoCodingControlInfoKHR = 1000023010,
    VideoReferenceSlotInfoKHR = 1000023011,
    QueueFamilyVideoPropertiesKHR = 1000023012,
    VideoProfileListInfoKHR = 1000023013,
    PhysicalDeviceVideoFormatInfoKHR = 1000023014,
    VideoFormatPropertiesKHR = 1000023015,
    QueueFamilyQueryResultStatusPropertiesKHR = 1000023016,
    VideoDecodeInfoKHR = 1000024000,
    VideoDecodeCapabilitiesKHR = 1000024001,
    VideoDecodeUsageInfoKHR = 1000024002,
    DedicatedAllocationImageCreateInfoNV = 1000026000,
    DedicatedAllocationBufferCreateInfoNV = 1000026001,
    DedicatedAllocationMemoryAllocateInfoNV = 1000026002,
    PhysicalDeviceTransformFeedbackFeaturesEXT = 1000028000,
    PhysicalDeviceTransformFeedbackPropertiesEXT = 1000028001,
    PipelineRasterizationStateStreamCreateInfoEXT = 1000028002,
    CuModuleCreateInfoNVX = 1000029000,
    CuFunctionCreateInfoNVX = 1000029001,
    CuLaunchInfoNVX = 1000029002,
    ImageViewHandleInfoNVX = 1000030000,
    ImageViewAddressPropertiesNVX = 1000030001,
    VideoEncodeH264CapabilitiesKHR = 1000038000,
    VideoEncodeH264SessionParametersCreateInfoKHR = 1000038001,
    VideoEncodeH264SessionParametersAddInfoKHR = 1000038002,
    VideoEncodeH264PictureInfoKHR = 1000038003,
    VideoEncodeH264DpbSlotInfoKHR = 1000038004,
    VideoEncodeH264NaluSliceInfoKHR = 1000038005,
    VideoEncodeH264GopRemainingFrameInfoKHR = 1000038006,
    VideoEncodeH264ProfileInfoKHR = 1000038007,
    VideoEncodeH264RateControlInfoKHR = 1000038008,
    VideoEncodeH264RateControlLayerInfoKHR = 1000038009,
    VideoEncodeH264SessionCreateInfoKHR = 1000038010,
    VideoEncodeH264QualityLevelPropertiesKHR = 1000038011,
    VideoEncodeH264SessionParametersGetInfoKHR = 1000038012,
    VideoEncodeH264SessionParametersFeedbackInfoKHR = 1000038013,
    VideoEncodeH265CapabilitiesKHR = 1000039000,
    VideoEncodeH265SessionParametersCreateInfoKHR = 1000039001,
    VideoEncodeH265SessionParametersAddInfoKHR = 1000039002,
    VideoEncodeH265PictureInfoKHR = 1000039003,
    VideoEncodeH265DpbSlotInfoKHR = 1000039004,
    VideoEncodeH265NaluSliceSegmentInfoKHR = 1000039005,
    VideoEncodeH265GopRemainingFrameInfoKHR = 1000039006,
    VideoEncodeH265ProfileInfoKHR = 1000039007,
    VideoEncodeH265RateControlInfoKHR = 1000039009,
    VideoEncodeH265RateControlLayerInfoKHR = 1000039010,
    VideoEncodeH265SessionCreateInfoKHR = 1000039011,
    VideoEncodeH265QualityLevelPropertiesKHR = 1000039012,
    VideoEncodeH265SessionParametersGetInfoKHR = 1000039013,
    VideoEncodeH265SessionParametersFeedbackInfoKHR = 1000039014,
    VideoDecodeH264CapabilitiesKHR = 1000040000,
    VideoDecodeH264PictureInfoKHR = 1000040001,
    VideoDecodeH264ProfileInfoKHR = 1000040003,
    VideoDecodeH264SessionParametersCreateInfoKHR = 1000040004,
    VideoDecodeH264SessionParametersAddInfoKHR = 1000040005,
    VideoDecodeH264DpbSlotInfoKHR = 1000040006,
    TextureLodGatherFormatPropertiesAMD = 1000041000,
    RenderingFragmentShadingRateAttachmentInfoKHR = 1000044006,
    RenderingFragmentDensityMapAttachmentInfoEXT = 1000044007,
    AttachmentSampleCountInfoAMD = 1000044008,
    MultiviewPerViewAttributesInfoNVX = 1000044009,
    StreamDescriptorSurfaceCreateInfoGGP = 1000049000,
    PhysicalDeviceCornerSampledImageFeaturesNV = 1000050000,
    ExternalMemoryImageCreateInfoNV = 1000056000,
    ExportMemoryAllocateInfoNV = 1000056001,
    ImportMemoryWin32HandleInfoNV = 1000057000,
    ExportMemoryWin32HandleInfoNV = 1000057001,
    Win32KeyedMutexAcquireReleaseInfoNV = 1000058000,
    ValidationFlagsEXT = 1000061000,
    ViSurfaceCreateInfoNN = 1000062000,
    ImageViewAstcDecodeModeEXT = 1000067000,
    PhysicalDeviceAstcDecodeFeaturesEXT = 1000067001,
    PipelineRobustnessCreateInfoEXT = 1000068000,
    PhysicalDevicePipelineRobustnessFeaturesEXT = 1000068001,
    PhysicalDevicePipelineRobustnessPropertiesEXT = 1000068002,
    ImportMemoryWin32HandleInfoKHR = 1000073000,
    ExportMemoryWin32HandleInfoKHR = 1000073001,
    MemoryWin32HandlePropertiesKHR = 1000073002,
    MemoryGetWin32HandleInfoKHR = 1000073003,
    ImportMemoryFdInfoKHR = 1000074000,
    MemoryFdPropertiesKHR = 1000074001,
    MemoryGetFdInfoKHR = 1000074002,
    Win32KeyedMutexAcquireReleaseInfoKHR = 1000075000,
    ImportSemaphoreWin32HandleInfoKHR = 1000078000,
    ExportSemaphoreWin32HandleInfoKHR = 1000078001,
    D3D12FenceSubmitInfoKHR = 1000078002,
    SemaphoreGetWin32HandleInfoKHR = 1000078003,
    ImportSemaphoreFdInfoKHR = 1000079000,
    SemaphoreGetFdInfoKHR = 1000079001,
    PhysicalDevicePushDescriptorPropertiesKHR = 1000080000,
    CommandBufferInheritanceConditionalRenderingInfoEXT = 1000081000,
    PhysicalDeviceConditionalRenderingFeaturesEXT = 1000081001,
    ConditionalRenderingBeginInfoEXT = 1000081002,
    PresentRegionsKHR = 1000084000,
    PipelineViewportWScalingStateCreateInfoNV = 1000087000,
    SurfaceCapabilities2EXT = 1000090000,
    DisplayPowerInfoEXT = 1000091000,
    DeviceEventInfoEXT = 1000091001,
    DisplayEventInfoEXT = 1000091002,
    SwapchainCounterCreateInfoEXT = 1000091003,
    PresentTimesInfoGOOGLE = 1000092000,
    PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = 1000097000,
    PipelineViewportSwizzleStateCreateInfoNV = 1000098000,
    PhysicalDeviceDiscardRectanglePropertiesEXT = 1000099000,
    PipelineDiscardRectangleStateCreateInfoEXT = 1000099001,
    PhysicalDeviceConservativeRasterizationPropertiesEXT = 1000101000,
    PipelineRasterizationConservativeStateCreateInfoEXT = 1000101001,
    PhysicalDeviceDepthClipEnableFeaturesEXT = 1000102000,
    PipelineRasterizationDepthClipStateCreateInfoEXT = 1000102001,
    HdrMetadataEXT = 1000105000,
    PhysicalDeviceRelaxedLineRasterizationFeaturesIMG = 1000110000,
    SharedPresentSurfaceCapabilitiesKHR = 1000111000,
    ImportFenceWin32HandleInfoKHR = 1000114000,
    ExportFenceWin32HandleInfoKHR = 1000114001,
    FenceGetWin32HandleInfoKHR = 1000114002,
    ImportFenceFdInfoKHR = 1000115000,
    FenceGetFdInfoKHR = 1000115001,
    PhysicalDevicePerformanceQueryFeaturesKHR = 1000116000,
    PhysicalDevicePerformanceQueryPropertiesKHR = 1000116001,
    QueryPoolPerformanceCreateInfoKHR = 1000116002,
    PerformanceQuerySubmitInfoKHR = 1000116003,
    AcquireProfilingLockInfoKHR = 1000116004,
    PerformanceCounterKHR = 1000116005,
    PerformanceCounterDescriptionKHR = 1000116006,
    PhysicalDeviceSurfaceInfo2KHR = 1000119000,
    SurfaceCapabilities2KHR = 1000119001,
    SurfaceFormat2KHR = 1000119002,
    DisplayProperties2KHR = 1000121000,
    DisplayPlaneProperties2KHR = 1000121001,
    DisplayModeProperties2KHR = 1000121002,
    DisplayPlaneInfo2KHR = 1000121003,
    DisplayPlaneCapabilities2KHR = 1000121004,
    IosSurfaceCreateInfoMVK = 1000122000,
    MacosSurfaceCreateInfoMVK = 1000123000,
    DebugUtilsObjectNameInfoEXT = 1000128000,
    DebugUtilsObjectTagInfoEXT = 1000128001,
    DebugUtilsLabelEXT = 1000128002,
    DebugUtilsMessengerCallbackDataEXT = 1000128003,
    DebugUtilsMessengerCreateInfoEXT = 1000128004,
    AndroidHardwareBufferUsageANDROID = 1000129000,
    AndroidHardwareBufferPropertiesANDROID = 1000129001,
    AndroidHardwareBufferFormatPropertiesANDROID = 1000129002,
    ImportAndroidHardwareBufferInfoANDROID = 1000129003,
    MemoryGetAndroidHardwareBufferInfoANDROID = 1000129004,
    ExternalFormatANDROID = 1000129005,
    AndroidHardwareBufferFormatProperties2ANDROID = 1000129006,
    PhysicalDeviceShaderEnqueueFeaturesAMDX = 1000134000,
    PhysicalDeviceShaderEnqueuePropertiesAMDX = 1000134001,
    ExecutionGraphPipelineScratchSizeAMDX = 1000134002,
    ExecutionGraphPipelineCreateInfoAMDX = 1000134003,
    PipelineShaderStageNodeCreateInfoAMDX = 1000134004,
    SampleLocationsInfoEXT = 1000143000,
    RenderPassSampleLocationsBeginInfoEXT = 1000143001,
    PipelineSampleLocationsStateCreateInfoEXT = 1000143002,
    PhysicalDeviceSampleLocationsPropertiesEXT = 1000143003,
    MultisamplePropertiesEXT = 1000143004,
    PhysicalDeviceBlendOperationAdvancedFeaturesEXT = 1000148000,
    PhysicalDeviceBlendOperationAdvancedPropertiesEXT = 1000148001,
    PipelineColorBlendAdvancedStateCreateInfoEXT = 1000148002,
    PipelineCoverageToColorStateCreateInfoNV = 1000149000,
    WriteDescriptorSetAccelerationStructureKHR = 1000150007,
    AccelerationStructureBuildGeometryInfoKHR = 1000150000,
    AccelerationStructureDeviceAddressInfoKHR = 1000150002,
    AccelerationStructureGeometryAabbsDataKHR = 1000150003,
    AccelerationStructureGeometryInstancesDataKHR = 1000150004,
    AccelerationStructureGeometryTrianglesDataKHR = 1000150005,
    AccelerationStructureGeometryKHR = 1000150006,
    AccelerationStructureVersionInfoKHR = 1000150009,
    CopyAccelerationStructureInfoKHR = 1000150010,
    CopyAccelerationStructureToMemoryInfoKHR = 1000150011,
    CopyMemoryToAccelerationStructureInfoKHR = 1000150012,
    PhysicalDeviceAccelerationStructureFeaturesKHR = 1000150013,
    PhysicalDeviceAccelerationStructurePropertiesKHR = 1000150014,
    AccelerationStructureCreateInfoKHR = 1000150017,
    AccelerationStructureBuildSizesInfoKHR = 1000150020,
    PhysicalDeviceRayTracingPipelineFeaturesKHR = 1000347000,
    PhysicalDeviceRayTracingPipelinePropertiesKHR = 1000347001,
    RayTracingPipelineCreateInfoKHR = 1000150015,
    RayTracingShaderGroupCreateInfoKHR = 1000150016,
    RayTracingPipelineInterfaceCreateInfoKHR = 1000150018,
    PhysicalDeviceRayQueryFeaturesKHR = 1000348013,
    PipelineCoverageModulationStateCreateInfoNV = 1000152000,
    PhysicalDeviceShaderSmBuiltinsFeaturesNV = 1000154000,
    PhysicalDeviceShaderSmBuiltinsPropertiesNV = 1000154001,
    DrmFormatModifierPropertiesListEXT = 1000158000,
    PhysicalDeviceImageDrmFormatModifierInfoEXT = 1000158002,
    ImageDrmFormatModifierListCreateInfoEXT = 1000158003,
    ImageDrmFormatModifierExplicitCreateInfoEXT = 1000158004,
    ImageDrmFormatModifierPropertiesEXT = 1000158005,
    DrmFormatModifierPropertiesList2EXT = 1000158006,
    ValidationCacheCreateInfoEXT = 1000160000,
    ShaderModuleValidationCacheCreateInfoEXT = 1000160001,
    PhysicalDevicePortabilitySubsetFeaturesKHR = 1000163000,
    PhysicalDevicePortabilitySubsetPropertiesKHR = 1000163001,
    PipelineViewportShadingRateImageStateCreateInfoNV = 1000164000,
    PhysicalDeviceShadingRateImageFeaturesNV = 1000164001,
    PhysicalDeviceShadingRateImagePropertiesNV = 1000164002,
    PipelineViewportCoarseSampleOrderStateCreateInfoNV = 1000164005,
    RayTracingPipelineCreateInfoNV = 1000165000,
    AccelerationStructureCreateInfoNV = 1000165001,
    GeometryNV = 1000165003,
    GeometryTrianglesNV = 1000165004,
    GeometryAabbNV = 1000165005,
    BindAccelerationStructureMemoryInfoNV = 1000165006,
    WriteDescriptorSetAccelerationStructureNV = 1000165007,
    AccelerationStructureMemoryRequirementsInfoNV = 1000165008,
    PhysicalDeviceRayTracingPropertiesNV = 1000165009,
    RayTracingShaderGroupCreateInfoNV = 1000165011,
    AccelerationStructureInfoNV = 1000165012,
    PhysicalDeviceRepresentativeFragmentTestFeaturesNV = 1000166000,
    PipelineRepresentativeFragmentTestStateCreateInfoNV = 1000166001,
    PhysicalDeviceImageViewImageFormatInfoEXT = 1000170000,
    FilterCubicImageViewImageFormatPropertiesEXT = 1000170001,
    ImportMemoryHostPointerInfoEXT = 1000178000,
    MemoryHostPointerPropertiesEXT = 1000178001,
    PhysicalDeviceExternalMemoryHostPropertiesEXT = 1000178002,
    PhysicalDeviceShaderClockFeaturesKHR = 1000181000,
    PipelineCompilerControlCreateInfoAMD = 1000183000,
    PhysicalDeviceShaderCorePropertiesAMD = 1000185000,
    VideoDecodeH265CapabilitiesKHR = 1000187000,
    VideoDecodeH265SessionParametersCreateInfoKHR = 1000187001,
    VideoDecodeH265SessionParametersAddInfoKHR = 1000187002,
    VideoDecodeH265ProfileInfoKHR = 1000187003,
    VideoDecodeH265PictureInfoKHR = 1000187004,
    VideoDecodeH265DpbSlotInfoKHR = 1000187005,
    DeviceQueueGlobalPriorityCreateInfoKHR = 1000174000,
    PhysicalDeviceGlobalPriorityQueryFeaturesKHR = 1000388000,
    QueueFamilyGlobalPriorityPropertiesKHR = 1000388001,
    DeviceMemoryOverallocationCreateInfoAMD = 1000189000,
    PhysicalDeviceVertexAttributeDivisorPropertiesEXT = 1000190000,
    PresentFrameTokenGGP = 1000191000,
    PhysicalDeviceComputeShaderDerivativesFeaturesNV = 1000201000,
    PhysicalDeviceMeshShaderFeaturesNV = 1000202000,
    PhysicalDeviceMeshShaderPropertiesNV = 1000202001,
    PhysicalDeviceShaderImageFootprintFeaturesNV = 1000204000,
    PipelineViewportExclusiveScissorStateCreateInfoNV = 1000205000,
    PhysicalDeviceExclusiveScissorFeaturesNV = 1000205002,
    CheckpointDataNV = 1000206000,
    QueueFamilyCheckpointPropertiesNV = 1000206001,
    PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL = 1000209000,
    QueryPoolPerformanceQueryCreateInfoINTEL = 1000210000,
    InitializePerformanceApiInfoINTEL = 1000210001,
    PerformanceMarkerInfoINTEL = 1000210002,
    PerformanceStreamMarkerInfoINTEL = 1000210003,
    PerformanceOverrideInfoINTEL = 1000210004,
    PerformanceConfigurationAcquireInfoINTEL = 1000210005,
    PhysicalDevicePciBusInfoPropertiesEXT = 1000212000,
    DisplayNativeHdrSurfaceCapabilitiesAMD = 1000213000,
    SwapchainDisplayNativeHdrCreateInfoAMD = 1000213001,
    ImagepipeSurfaceCreateInfoFUCHSIA = 1000214000,
    MetalSurfaceCreateInfoEXT = 1000217000,
    PhysicalDeviceFragmentDensityMapFeaturesEXT = 1000218000,
    PhysicalDeviceFragmentDensityMapPropertiesEXT = 1000218001,
    RenderPassFragmentDensityMapCreateInfoEXT = 1000218002,
    FragmentShadingRateAttachmentInfoKHR = 1000226000,
    PipelineFragmentShadingRateStateCreateInfoKHR = 1000226001,
    PhysicalDeviceFragmentShadingRatePropertiesKHR = 1000226002,
    PhysicalDeviceFragmentShadingRateFeaturesKHR = 1000226003,
    PhysicalDeviceFragmentShadingRateKHR = 1000226004,
    PhysicalDeviceShaderCoreProperties2AMD = 1000227000,
    PhysicalDeviceCoherentMemoryFeaturesAMD = 1000229000,
    PhysicalDeviceDynamicRenderingLocalReadFeaturesKHR = 1000232000,
    RenderingAttachmentLocationInfoKHR = 1000232001,
    RenderingInputAttachmentIndexInfoKHR = 1000232002,
    PhysicalDeviceShaderImageAtomicInt64FeaturesEXT = 1000234000,
    PhysicalDeviceShaderQuadControlFeaturesKHR = 1000235000,
    PhysicalDeviceMemoryBudgetPropertiesEXT = 1000237000,
    PhysicalDeviceMemoryPriorityFeaturesEXT = 1000238000,
    MemoryPriorityAllocateInfoEXT = 1000238001,
    SurfaceProtectedCapabilitiesKHR = 1000239000,
    PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = 1000240000,
    PhysicalDeviceBufferDeviceAddressFeaturesEXT = 1000244000,
    BufferDeviceAddressCreateInfoEXT = 1000244002,
    ValidationFeaturesEXT = 1000247000,
    PhysicalDevicePresentWaitFeaturesKHR = 1000248000,
    PhysicalDeviceCooperativeMatrixFeaturesNV = 1000249000,
    CooperativeMatrixPropertiesNV = 1000249001,
    PhysicalDeviceCooperativeMatrixPropertiesNV = 1000249002,
    PhysicalDeviceCoverageReductionModeFeaturesNV = 1000250000,
    PipelineCoverageReductionStateCreateInfoNV = 1000250001,
    FramebufferMixedSamplesCombinationNV = 1000250002,
    PhysicalDeviceFragmentShaderInterlockFeaturesEXT = 1000251000,
    PhysicalDeviceYcbcrImageArraysFeaturesEXT = 1000252000,
    PhysicalDeviceProvokingVertexFeaturesEXT = 1000254000,
    PipelineRasterizationProvokingVertexStateCreateInfoEXT = 1000254001,
    PhysicalDeviceProvokingVertexPropertiesEXT = 1000254002,
    SurfaceFullScreenExclusiveInfoEXT = 1000255000,
    SurfaceCapabilitiesFullScreenExclusiveEXT = 1000255002,
    SurfaceFullScreenExclusiveWin32InfoEXT = 1000255001,
    HeadlessSurfaceCreateInfoEXT = 1000256000,
    PhysicalDeviceShaderAtomicFloatFeaturesEXT = 1000260000,
    PhysicalDeviceExtendedDynamicStateFeaturesEXT = 1000267000,
    PhysicalDevicePipelineExecutablePropertiesFeaturesKHR = 1000269000,
    PipelineInfoKHR = 1000269001,
    PipelineExecutablePropertiesKHR = 1000269002,
    PipelineExecutableInfoKHR = 1000269003,
    PipelineExecutableStatisticKHR = 1000269004,
    PipelineExecutableInternalRepresentationKHR = 1000269005,
    PhysicalDeviceHostImageCopyFeaturesEXT = 1000270000,
    PhysicalDeviceHostImageCopyPropertiesEXT = 1000270001,
    MemoryToImageCopyEXT = 1000270002,
    ImageToMemoryCopyEXT = 1000270003,
    CopyImageToMemoryInfoEXT = 1000270004,
    CopyMemoryToImageInfoEXT = 1000270005,
    HostImageLayoutTransitionInfoEXT = 1000270006,
    CopyImageToImageInfoEXT = 1000270007,
    SubresourceHostMemcpySizeEXT = 1000270008,
    HostImageCopyDevicePerformanceQueryEXT = 1000270009,
    MemoryMapInfoKHR = 1000271000,
    MemoryUnmapInfoKHR = 1000271001,
    PhysicalDeviceShaderAtomicFloat2FeaturesEXT = 1000273000,
    SurfacePresentModeEXT = 1000274000,
    SurfacePresentScalingCapabilitiesEXT = 1000274001,
    SurfacePresentModeCompatibilityEXT = 1000274002,
    PhysicalDeviceSwapchainMaintenance1FeaturesEXT = 1000275000,
    SwapchainPresentFenceInfoEXT = 1000275001,
    SwapchainPresentModesCreateInfoEXT = 1000275002,
    SwapchainPresentModeInfoEXT = 1000275003,
    SwapchainPresentScalingCreateInfoEXT = 1000275004,
    ReleaseSwapchainImagesInfoEXT = 1000275005,
    PhysicalDeviceDeviceGeneratedCommandsPropertiesNV = 1000277000,
    GraphicsShaderGroupCreateInfoNV = 1000277001,
    GraphicsPipelineShaderGroupsCreateInfoNV = 1000277002,
    IndirectCommandsLayoutTokenNV = 1000277003,
    IndirectCommandsLayoutCreateInfoNV = 1000277004,
    GeneratedCommandsInfoNV = 1000277005,
    GeneratedCommandsMemoryRequirementsInfoNV = 1000277006,
    PhysicalDeviceDeviceGeneratedCommandsFeaturesNV = 1000277007,
    PhysicalDeviceInheritedViewportScissorFeaturesNV = 1000278000,
    CommandBufferInheritanceViewportScissorInfoNV = 1000278001,
    PhysicalDeviceTexelBufferAlignmentFeaturesEXT = 1000281000,
    CommandBufferInheritanceRenderPassTransformInfoQCOM = 1000282000,
    RenderPassTransformBeginInfoQCOM = 1000282001,
    PhysicalDeviceDepthBiasControlFeaturesEXT = 1000283000,
    DepthBiasInfoEXT = 1000283001,
    DepthBiasRepresentationInfoEXT = 1000283002,
    PhysicalDeviceDeviceMemoryReportFeaturesEXT = 1000284000,
    DeviceDeviceMemoryReportCreateInfoEXT = 1000284001,
    DeviceMemoryReportCallbackDataEXT = 1000284002,
    PhysicalDeviceRobustness2FeaturesEXT = 1000286000,
    PhysicalDeviceRobustness2PropertiesEXT = 1000286001,
    SamplerCustomBorderColorCreateInfoEXT = 1000287000,
    PhysicalDeviceCustomBorderColorPropertiesEXT = 1000287001,
    PhysicalDeviceCustomBorderColorFeaturesEXT = 1000287002,
    PipelineLibraryCreateInfoKHR = 1000290000,
    PhysicalDevicePresentBarrierFeaturesNV = 1000292000,
    SurfaceCapabilitiesPresentBarrierNV = 1000292001,
    SwapchainPresentBarrierCreateInfoNV = 1000292002,
    PresentIdKHR = 1000294000,
    PhysicalDevicePresentIdFeaturesKHR = 1000294001,
    VideoEncodeInfoKHR = 1000299000,
    VideoEncodeRateControlInfoKHR = 1000299001,
    VideoEncodeRateControlLayerInfoKHR = 1000299002,
    VideoEncodeCapabilitiesKHR = 1000299003,
    VideoEncodeUsageInfoKHR = 1000299004,
    QueryPoolVideoEncodeFeedbackCreateInfoKHR = 1000299005,
    PhysicalDeviceVideoEncodeQualityLevelInfoKHR = 1000299006,
    VideoEncodeQualityLevelPropertiesKHR = 1000299007,
    VideoEncodeQualityLevelInfoKHR = 1000299008,
    VideoEncodeSessionParametersGetInfoKHR = 1000299009,
    VideoEncodeSessionParametersFeedbackInfoKHR = 1000299010,
    PhysicalDeviceDiagnosticsConfigFeaturesNV = 1000300000,
    DeviceDiagnosticsConfigCreateInfoNV = 1000300001,
    CudaModuleCreateInfoNV = 1000307000,
    CudaFunctionCreateInfoNV = 1000307001,
    CudaLaunchInfoNV = 1000307002,
    PhysicalDeviceCudaKernelLaunchFeaturesNV = 1000307003,
    PhysicalDeviceCudaKernelLaunchPropertiesNV = 1000307004,
    QueryLowLatencySupportNV = 1000310000,
    ExportMetalObjectCreateInfoEXT = 1000311000,
    ExportMetalObjectsInfoEXT = 1000311001,
    ExportMetalDeviceInfoEXT = 1000311002,
    ExportMetalCommandQueueInfoEXT = 1000311003,
    ExportMetalBufferInfoEXT = 1000311004,
    ImportMetalBufferInfoEXT = 1000311005,
    ExportMetalTextureInfoEXT = 1000311006,
    ImportMetalTextureInfoEXT = 1000311007,
    ExportMetalIoSurfaceInfoEXT = 1000311008,
    ImportMetalIoSurfaceInfoEXT = 1000311009,
    ExportMetalSharedEventInfoEXT = 1000311010,
    ImportMetalSharedEventInfoEXT = 1000311011,
    QueueFamilyCheckpointProperties2NV = 1000314008,
    CheckpointData2NV = 1000314009,
    PhysicalDeviceDescriptorBufferPropertiesEXT = 1000316000,
    PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT = 1000316001,
    PhysicalDeviceDescriptorBufferFeaturesEXT = 1000316002,
    DescriptorAddressInfoEXT = 1000316003,
    DescriptorGetInfoEXT = 1000316004,
    BufferCaptureDescriptorDataInfoEXT = 1000316005,
    ImageCaptureDescriptorDataInfoEXT = 1000316006,
    ImageViewCaptureDescriptorDataInfoEXT = 1000316007,
    SamplerCaptureDescriptorDataInfoEXT = 1000316008,
    OpaqueCaptureDescriptorDataCreateInfoEXT = 1000316010,
    DescriptorBufferBindingInfoEXT = 1000316011,
    DescriptorBufferBindingPushDescriptorBufferHandleEXT = 1000316012,
    AccelerationStructureCaptureDescriptorDataInfoEXT = 1000316009,
    PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT = 1000320000,
    PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT = 1000320001,
    GraphicsPipelineLibraryCreateInfoEXT = 1000320002,
    PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD = 1000321000,
    PhysicalDeviceFragmentShaderBarycentricFeaturesKHR = 1000203000,
    PhysicalDeviceFragmentShaderBarycentricPropertiesKHR = 1000322000,
    PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR = 1000323000,
    PhysicalDeviceFragmentShadingRateEnumsPropertiesNV = 1000326000,
    PhysicalDeviceFragmentShadingRateEnumsFeaturesNV = 1000326001,
    PipelineFragmentShadingRateEnumStateCreateInfoNV = 1000326002,
    AccelerationStructureGeometryMotionTrianglesDataNV = 1000327000,
    PhysicalDeviceRayTracingMotionBlurFeaturesNV = 1000327001,
    AccelerationStructureMotionInfoNV = 1000327002,
    PhysicalDeviceMeshShaderFeaturesEXT = 1000328000,
    PhysicalDeviceMeshShaderPropertiesEXT = 1000328001,
    PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT = 1000330000,
    PhysicalDeviceFragmentDensityMap2FeaturesEXT = 1000332000,
    PhysicalDeviceFragmentDensityMap2PropertiesEXT = 1000332001,
    CopyCommandTransformInfoQCOM = 1000333000,
    PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR = 1000336000,
    PhysicalDeviceImageCompressionControlFeaturesEXT = 1000338000,
    ImageCompressionControlEXT = 1000338001,
    ImageCompressionPropertiesEXT = 1000338004,
    PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT = 1000339000,
    PhysicalDevice4444FormatsFeaturesEXT = 1000340000,
    PhysicalDeviceFaultFeaturesEXT = 1000341000,
    DeviceFaultCountsEXT = 1000341001,
    DeviceFaultInfoEXT = 1000341002,
    PhysicalDeviceRgba10X6FormatsFeaturesEXT = 1000344000,
    DirectfbSurfaceCreateInfoEXT = 1000346000,
    PhysicalDeviceVertexInputDynamicStateFeaturesEXT = 1000352000,
    VertexInputBindingDescription2EXT = 1000352001,
    VertexInputAttributeDescription2EXT = 1000352002,
    PhysicalDeviceDrmPropertiesEXT = 1000353000,
    PhysicalDeviceAddressBindingReportFeaturesEXT = 1000354000,
    DeviceAddressBindingCallbackDataEXT = 1000354001,
    PhysicalDeviceDepthClipControlFeaturesEXT = 1000355000,
    PipelineViewportDepthClipControlCreateInfoEXT = 1000355001,
    PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT = 1000356000,
    ImportMemoryZirconHandleInfoFUCHSIA = 1000364000,
    MemoryZirconHandlePropertiesFUCHSIA = 1000364001,
    MemoryGetZirconHandleInfoFUCHSIA = 1000364002,
    ImportSemaphoreZirconHandleInfoFUCHSIA = 1000365000,
    SemaphoreGetZirconHandleInfoFUCHSIA = 1000365001,
    BufferCollectionCreateInfoFUCHSIA = 1000366000,
    ImportMemoryBufferCollectionFUCHSIA = 1000366001,
    BufferCollectionImageCreateInfoFUCHSIA = 1000366002,
    BufferCollectionPropertiesFUCHSIA = 1000366003,
    BufferConstraintsInfoFUCHSIA = 1000366004,
    BufferCollectionBufferCreateInfoFUCHSIA = 1000366005,
    ImageConstraintsInfoFUCHSIA = 1000366006,
    ImageFormatConstraintsInfoFUCHSIA = 1000366007,
    SysmemColorSpaceFUCHSIA = 1000366008,
    BufferCollectionConstraintsInfoFUCHSIA = 1000366009,
    SubpassShadingPipelineCreateInfoHUAWEI = 1000369000,
    PhysicalDeviceSubpassShadingFeaturesHUAWEI = 1000369001,
    PhysicalDeviceSubpassShadingPropertiesHUAWEI = 1000369002,
    PhysicalDeviceInvocationMaskFeaturesHUAWEI = 1000370000,
    MemoryGetRemoteAddressInfoNV = 1000371000,
    PhysicalDeviceExternalMemoryRdmaFeaturesNV = 1000371001,
    PipelinePropertiesIdentifierEXT = 1000372000,
    PhysicalDevicePipelinePropertiesFeaturesEXT = 1000372001,
    PhysicalDeviceFrameBoundaryFeaturesEXT = 1000375000,
    FrameBoundaryEXT = 1000375001,
    PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT = 1000376000,
    SubpassResolvePerformanceQueryEXT = 1000376001,
    MultisampledRenderToSingleSampledInfoEXT = 1000376002,
    PhysicalDeviceExtendedDynamicState2FeaturesEXT = 1000377000,
    ScreenSurfaceCreateInfoQNX = 1000378000,
    PhysicalDeviceColorWriteEnableFeaturesEXT = 1000381000,
    PipelineColorWriteCreateInfoEXT = 1000381001,
    PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT = 1000382000,
    PhysicalDeviceRayTracingMaintenance1FeaturesKHR = 1000386000,
    PhysicalDeviceImageViewMinLodFeaturesEXT = 1000391000,
    ImageViewMinLodCreateInfoEXT = 1000391001,
    PhysicalDeviceMultiDrawFeaturesEXT = 1000392000,
    PhysicalDeviceMultiDrawPropertiesEXT = 1000392001,
    PhysicalDeviceImage2DViewOf3DFeaturesEXT = 1000393000,
    PhysicalDeviceShaderTileImageFeaturesEXT = 1000395000,
    PhysicalDeviceShaderTileImagePropertiesEXT = 1000395001,
    MicromapBuildInfoEXT = 1000396000,
    MicromapVersionInfoEXT = 1000396001,
    CopyMicromapInfoEXT = 1000396002,
    CopyMicromapToMemoryInfoEXT = 1000396003,
    CopyMemoryToMicromapInfoEXT = 1000396004,
    PhysicalDeviceOpacityMicromapFeaturesEXT = 1000396005,
    PhysicalDeviceOpacityMicromapPropertiesEXT = 1000396006,
    MicromapCreateInfoEXT = 1000396007,
    MicromapBuildSizesInfoEXT = 1000396008,
    AccelerationStructureTrianglesOpacityMicromapEXT = 1000396009,
    PhysicalDeviceDisplacementMicromapFeaturesNV = 1000397000,
    PhysicalDeviceDisplacementMicromapPropertiesNV = 1000397001,
    AccelerationStructureTrianglesDisplacementMicromapNV = 1000397002,
    PhysicalDeviceClusterCullingShaderFeaturesHUAWEI = 1000404000,
    PhysicalDeviceClusterCullingShaderPropertiesHUAWEI = 1000404001,
    PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI = 1000404002,
    PhysicalDeviceBorderColorSwizzleFeaturesEXT = 1000411000,
    SamplerBorderColorComponentMappingCreateInfoEXT = 1000411001,
    PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT = 1000412000,
    PhysicalDeviceShaderCorePropertiesARM = 1000415000,
    PhysicalDeviceShaderSubgroupRotateFeaturesKHR = 1000416000,
    DeviceQueueShaderCoreControlCreateInfoARM = 1000417000,
    PhysicalDeviceSchedulingControlsFeaturesARM = 1000417001,
    PhysicalDeviceSchedulingControlsPropertiesARM = 1000417002,
    PhysicalDeviceImageSlicedViewOf3DFeaturesEXT = 1000418000,
    ImageViewSlicedCreateInfoEXT = 1000418001,
    PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE = 1000420000,
    DescriptorSetBindingReferenceVALVE = 1000420001,
    DescriptorSetLayoutHostMappingInfoVALVE = 1000420002,
    PhysicalDeviceDepthClampZeroOneFeaturesEXT = 1000421000,
    PhysicalDeviceNonSeamlessCubeMapFeaturesEXT = 1000422000,
    PhysicalDeviceRenderPassStripedFeaturesARM = 1000424000,
    PhysicalDeviceRenderPassStripedPropertiesARM = 1000424001,
    RenderPassStripeBeginInfoARM = 1000424002,
    RenderPassStripeInfoARM = 1000424003,
    RenderPassStripeSubmitInfoARM = 1000424004,
    PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM = 1000425000,
    PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM = 1000425001,
    SubpassFragmentDensityMapOffsetEndInfoQCOM = 1000425002,
    PhysicalDeviceCopyMemoryIndirectFeaturesNV = 1000426000,
    PhysicalDeviceCopyMemoryIndirectPropertiesNV = 1000426001,
    PhysicalDeviceMemoryDecompressionFeaturesNV = 1000427000,
    PhysicalDeviceMemoryDecompressionPropertiesNV = 1000427001,
    PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV = 1000428000,
    ComputePipelineIndirectBufferInfoNV = 1000428001,
    PipelineIndirectDeviceAddressInfoNV = 1000428002,
    PhysicalDeviceLinearColorAttachmentFeaturesNV = 1000430000,
    PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR = 1000434000,
    PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT = 1000437000,
    PhysicalDeviceImageProcessingFeaturesQCOM = 1000440000,
    PhysicalDeviceImageProcessingPropertiesQCOM = 1000440001,
    ImageViewSampleWeightCreateInfoQCOM = 1000440002,
    PhysicalDeviceNestedCommandBufferFeaturesEXT = 1000451000,
    PhysicalDeviceNestedCommandBufferPropertiesEXT = 1000451001,
    ExternalMemoryAcquireUnmodifiedEXT = 1000453000,
    PhysicalDeviceExtendedDynamicState3FeaturesEXT = 1000455000,
    PhysicalDeviceExtendedDynamicState3PropertiesEXT = 1000455001,
    PhysicalDeviceSubpassMergeFeedbackFeaturesEXT = 1000458000,
    RenderPassCreationControlEXT = 1000458001,
    RenderPassCreationFeedbackCreateInfoEXT = 1000458002,
    RenderPassSubpassFeedbackCreateInfoEXT = 1000458003,
    DirectDriverLoadingInfoLUNARG = 1000459000,
    DirectDriverLoadingListLUNARG = 1000459001,
    PhysicalDeviceShaderModuleIdentifierFeaturesEXT = 1000462000,
    PhysicalDeviceShaderModuleIdentifierPropertiesEXT = 1000462001,
    PipelineShaderStageModuleIdentifierCreateInfoEXT = 1000462002,
    ShaderModuleIdentifierEXT = 1000462003,
    PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT = 1000342000,
    PhysicalDeviceOpticalFlowFeaturesNV = 1000464000,
    PhysicalDeviceOpticalFlowPropertiesNV = 1000464001,
    OpticalFlowImageFormatInfoNV = 1000464002,
    OpticalFlowImageFormatPropertiesNV = 1000464003,
    OpticalFlowSessionCreateInfoNV = 1000464004,
    OpticalFlowExecuteInfoNV = 1000464005,
    OpticalFlowSessionCreatePrivateDataInfoNV = 1000464010,
    PhysicalDeviceLegacyDitheringFeaturesEXT = 1000465000,
    PhysicalDevicePipelineProtectedAccessFeaturesEXT = 1000466000,
    PhysicalDeviceExternalFormatResolveFeaturesANDROID = 1000468000,
    PhysicalDeviceExternalFormatResolvePropertiesANDROID = 1000468001,
    AndroidHardwareBufferFormatResolvePropertiesANDROID = 1000468002,
    PhysicalDeviceMaintenance5FeaturesKHR = 1000470000,
    PhysicalDeviceMaintenance5PropertiesKHR = 1000470001,
    RenderingAreaInfoKHR = 1000470003,
    DeviceImageSubresourceInfoKHR = 1000470004,
    SubresourceLayout2KHR = 1000338002,
    ImageSubresource2KHR = 1000338003,
    PipelineCreateFlags2CreateInfoKHR = 1000470005,
    BufferUsageFlags2CreateInfoKHR = 1000470006,
    PhysicalDeviceRayTracingPositionFetchFeaturesKHR = 1000481000,
    PhysicalDeviceShaderObjectFeaturesEXT = 1000482000,
    PhysicalDeviceShaderObjectPropertiesEXT = 1000482001,
    ShaderCreateInfoEXT = 1000482002,
    PhysicalDeviceTilePropertiesFeaturesQCOM = 1000484000,
    TilePropertiesQCOM = 1000484001,
    PhysicalDeviceAmigoProfilingFeaturesSEC = 1000485000,
    AmigoProfilingSubmitInfoSEC = 1000485001,
    PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM = 1000488000,
    PhysicalDeviceRayTracingInvocationReorderFeaturesNV = 1000490000,
    PhysicalDeviceRayTracingInvocationReorderPropertiesNV = 1000490001,
    PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV = 1000492000,
    PhysicalDeviceExtendedSparseAddressSpacePropertiesNV = 1000492001,
    PhysicalDeviceMutableDescriptorTypeFeaturesEXT = 1000351000,
    MutableDescriptorTypeCreateInfoEXT = 1000351002,
    LayerSettingsCreateInfoEXT = 1000496000,
    PhysicalDeviceShaderCoreBuiltinsFeaturesARM = 1000497000,
    PhysicalDeviceShaderCoreBuiltinsPropertiesARM = 1000497001,
    PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT = 1000498000,
    PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT = 1000499000,
    LatencySleepModeInfoNV = 1000505000,
    LatencySleepInfoNV = 1000505001,
    SetLatencyMarkerInfoNV = 1000505002,
    GetLatencyMarkerInfoNV = 1000505003,
    LatencyTimingsFrameReportNV = 1000505004,
    LatencySubmissionPresentIdNV = 1000505005,
    OutOfBandQueueTypeInfoNV = 1000505006,
    SwapchainLatencyCreateInfoNV = 1000505007,
    LatencySurfaceCapabilitiesNV = 1000505008,
    PhysicalDeviceCooperativeMatrixFeaturesKHR = 1000506000,
    CooperativeMatrixPropertiesKHR = 1000506001,
    PhysicalDeviceCooperativeMatrixPropertiesKHR = 1000506002,
    PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM = 1000510000,
    MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM = 1000510001,
    VideoDecodeAv1CapabilitiesKHR = 1000512000,
    VideoDecodeAv1PictureInfoKHR = 1000512001,
    VideoDecodeAv1ProfileInfoKHR = 1000512003,
    VideoDecodeAv1SessionParametersCreateInfoKHR = 1000512004,
    VideoDecodeAv1DpbSlotInfoKHR = 1000512005,
    PhysicalDeviceVideoMaintenance1FeaturesKHR = 1000515000,
    VideoInlineQueryInfoKHR = 1000515001,
    PhysicalDevicePerStageDescriptorSetFeaturesNV = 1000516000,
    PhysicalDeviceImageProcessing2FeaturesQCOM = 1000518000,
    PhysicalDeviceImageProcessing2PropertiesQCOM = 1000518001,
    SamplerBlockMatchWindowCreateInfoQCOM = 1000518002,
    SamplerCubicWeightsCreateInfoQCOM = 1000519000,
    PhysicalDeviceCubicWeightsFeaturesQCOM = 1000519001,
    BlitImageCubicWeightsInfoQCOM = 1000519002,
    PhysicalDeviceYcbcrDegammaFeaturesQCOM = 1000520000,
    SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM = 1000520001,
    PhysicalDeviceCubicClampFeaturesQCOM = 1000521000,
    PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT = 1000524000,
    PhysicalDeviceVertexAttributeDivisorPropertiesKHR = 1000525000,
    PipelineVertexInputDivisorStateCreateInfoKHR = 1000190001,
    PhysicalDeviceVertexAttributeDivisorFeaturesKHR = 1000190002,
    PhysicalDeviceShaderFloatControls2FeaturesKHR = 1000528000,
    ScreenBufferPropertiesQNX = 1000529000,
    ScreenBufferFormatPropertiesQNX = 1000529001,
    ImportScreenBufferInfoQNX = 1000529002,
    ExternalFormatQNX = 1000529003,
    PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX = 1000529004,
    PhysicalDeviceLayeredDriverPropertiesMSFT = 1000530000,
    PhysicalDeviceIndexTypeUint8FeaturesKHR = 1000265000,
    PhysicalDeviceLineRasterizationFeaturesKHR = 1000259000,
    PipelineRasterizationLineStateCreateInfoKHR = 1000259001,
    PhysicalDeviceLineRasterizationPropertiesKHR = 1000259002,
    CalibratedTimestampInfoKHR = 1000184000,
    PhysicalDeviceShaderExpectAssumeFeaturesKHR = 1000544000,
    PhysicalDeviceMaintenance6FeaturesKHR = 1000545000,
    PhysicalDeviceMaintenance6PropertiesKHR = 1000545001,
    BindMemoryStatusKHR = 1000545002,
    BindDescriptorSetsInfoKHR = 1000545003,
    PushConstantsInfoKHR = 1000545004,
    PushDescriptorSetInfoKHR = 1000545005,
    PushDescriptorSetWithTemplateInfoKHR = 1000545006,
    SetDescriptorBufferOffsetsInfoEXT = 1000545007,
    BindDescriptorBufferEmbeddedSamplersInfoEXT = 1000545008,
    PhysicalDeviceDescriptorPoolOverallocationFeaturesNV = 1000546000,
};
enum class SystemAllocationScope : uint32_t {
    Command = 0,
    Object = 1,
    Cache = 2,
    Device = 3,
    Instance = 4,
};
enum class InternalAllocationType : uint32_t {
    Executable = 0,
};
enum class SamplerAddressMode : uint32_t {
    Repeat = 0,
    MirroredRepeat = 1,
    ClampToEdge = 2,
    ClampToBorder = 3,
    MirrorClampToEdge = 4,
};
enum class Filter : uint32_t {
    Nearest = 0,
    Linear = 1,
    CubicEXT = 1000015000,
};
enum class SamplerMipmapMode : uint32_t {
    Nearest = 0,
    Linear = 1,
};
enum class VertexInputRate : uint32_t {
    Vertex = 0,
    Instance = 1,
};
enum class ObjectType : uint32_t {
    Unknown = 0,
    Instance = 1,
    PhysicalDevice = 2,
    Device = 3,
    Queue = 4,
    Semaphore = 5,
    CommandBuffer = 6,
    Fence = 7,
    DeviceMemory = 8,
    Buffer = 9,
    Image = 10,
    Event = 11,
    QueryPool = 12,
    BufferView = 13,
    ImageView = 14,
    ShaderModule = 15,
    PipelineCache = 16,
    PipelineLayout = 17,
    RenderPass = 18,
    Pipeline = 19,
    DescriptorSetLayout = 20,
    Sampler = 21,
    DescriptorPool = 22,
    DescriptorSet = 23,
    Framebuffer = 24,
    CommandPool = 25,
    SamplerYcbcrConversion = 1000156000,
    DescriptorUpdateTemplate = 1000085000,
    PrivateDataSlot = 1000295000,
    SurfaceKHR = 1000000000,
    SwapchainKHR = 1000001000,
    DisplayKHR = 1000002000,
    DisplayModeKHR = 1000002001,
    DebugReportCallbackEXT = 1000011000,
    VideoSessionKHR = 1000023000,
    VideoSessionParametersKHR = 1000023001,
    CuModuleNVX = 1000029000,
    CuFunctionNVX = 1000029001,
    DebugUtilsMessengerEXT = 1000128000,
    AccelerationStructureKHR = 1000150000,
    ValidationCacheEXT = 1000160000,
    AccelerationStructureNV = 1000165000,
    PerformanceConfigurationINTEL = 1000210000,
    DeferredOperationKHR = 1000268000,
    IndirectCommandsLayoutNV = 1000277000,
    CudaModuleNV = 1000307000,
    CudaFunctionNV = 1000307001,
    BufferCollectionFUCHSIA = 1000366000,
    MicromapEXT = 1000396000,
    OpticalFlowSessionNV = 1000464000,
    ShaderEXT = 1000482000,
};
enum class RayTracingInvocationReorderModeNV : uint32_t {
    NoneNV = 0,
    ReorderNV = 1,
};
enum class IndirectCommandsTokenTypeNV : uint32_t {
    ShaderGroupNV = 0,
    StateFlagsNV = 1,
    IndexBufferNV = 2,
    VertexBufferNV = 3,
    PushConstantNV = 4,
    DrawIndexedNV = 5,
    DrawNV = 6,
    DrawTasksNV = 7,
    DrawMeshTasksNV = 1000328000,
    PipelineNV = 1000428003,
    DispatchNV = 1000428004,
};
enum class DescriptorUpdateTemplateType : uint32_t {
    DescriptorSet = 0,
    PushDescriptorsKHR = 1,
};
using DescriptorUpdateTemplateTypeKHR = DescriptorUpdateTemplateType;
enum class ViewportCoordinateSwizzleNV : uint32_t {
    PositiveXNV = 0,
    NegativeXNV = 1,
    PositiveYNV = 2,
    NegativeYNV = 3,
    PositiveZNV = 4,
    NegativeZNV = 5,
    PositiveWNV = 6,
    NegativeWNV = 7,
};
enum class DiscardRectangleModeEXT : uint32_t {
    InclusiveEXT = 0,
    ExclusiveEXT = 1,
};
enum class PointClippingBehavior : uint32_t {
    AllClipPlanes = 0,
    UserClipPlanesOnly = 1,
};
using PointClippingBehaviorKHR = PointClippingBehavior;
enum class CoverageModulationModeNV : uint32_t {
    NoneNV = 0,
    RgbNV = 1,
    AlphaNV = 2,
    RgbaNV = 3,
};
enum class CoverageReductionModeNV : uint32_t {
    MergeNV = 0,
    TruncateNV = 1,
};
enum class ValidationCacheHeaderVersionEXT : uint32_t {
    OneEXT = 1,
};
enum class ShaderInfoTypeAMD : uint32_t {
    StatisticsAMD = 0,
    BinaryAMD = 1,
    DisassemblyAMD = 2,
};
enum class QueueGlobalPriorityKHR : uint32_t {
    LowKHR = 128,
    MediumKHR = 256,
    HighKHR = 512,
    RealtimeKHR = 1024,
};
using QueueGlobalPriorityEXT = QueueGlobalPriorityKHR;
enum class TimeDomainKHR : uint32_t {
    DeviceKHR = 0,
    ClockMonotonicKHR = 1,
    ClockMonotonicRawKHR = 2,
    QueryPerformanceCounterKHR = 3,
};
using TimeDomainEXT = TimeDomainKHR;
enum class ConservativeRasterizationModeEXT : uint32_t {
    DisabledEXT = 0,
    OverestimateEXT = 1,
    UnderestimateEXT = 2,
};
enum class SemaphoreType : uint32_t {
    Binary = 0,
    Timeline = 1,
};
using SemaphoreTypeKHR = SemaphoreType;
enum class BuildAccelerationStructureModeKHR : uint32_t {
    BuildKHR = 0,
    UpdateKHR = 1,
};
enum class CopyAccelerationStructureModeKHR : uint32_t {
    CloneKHR = 0,
    CompactKHR = 1,
    SerializeKHR = 2,
    DeserializeKHR = 3,
};
using CopyAccelerationStructureModeNV = CopyAccelerationStructureModeKHR;
enum class AccelerationStructureTypeKHR : uint32_t {
    TopLevelKHR = 0,
    BottomLevelKHR = 1,
    GenericKHR = 2,
};
using AccelerationStructureTypeNV = AccelerationStructureTypeKHR;
enum class GeometryTypeKHR : uint32_t {
    TrianglesKHR = 0,
    AabbsKHR = 1,
    InstancesKHR = 2,
};
using GeometryTypeNV = GeometryTypeKHR;
enum class RayTracingShaderGroupTypeKHR : uint32_t {
    GeneralKHR = 0,
    TrianglesHitGroupKHR = 1,
    ProceduralHitGroupKHR = 2,
};
using RayTracingShaderGroupTypeNV = RayTracingShaderGroupTypeKHR;
enum class AccelerationStructureMemoryRequirementsTypeNV : uint32_t {
    ObjectNV = 0,
    BuildScratchNV = 1,
    UpdateScratchNV = 2,
};
enum class AccelerationStructureBuildTypeKHR : uint32_t {
    HostKHR = 0,
    DeviceKHR = 1,
    HostOrDeviceKHR = 2,
};
enum class AccelerationStructureCompatibilityKHR : uint32_t {
    CompatibleKHR = 0,
    IncompatibleKHR = 1,
};
enum class ShaderGroupShaderKHR : uint32_t {
    GeneralKHR = 0,
    ClosestHitKHR = 1,
    AnyHitKHR = 2,
    IntersectionKHR = 3,
};
enum class MemoryOverallocationBehaviorAMD : uint32_t {
    DefaultAMD = 0,
    AllowedAMD = 1,
    DisallowedAMD = 2,
};
enum class PerformanceCounterScopeKHR : uint32_t {
    CommandBufferKHR = 0,
    RenderPassKHR = 1,
    CommandKHR = 2,
};
enum class PerformanceCounterUnitKHR : uint32_t {
    GenericKHR = 0,
    PercentageKHR = 1,
    NanosecondsKHR = 2,
    BytesKHR = 3,
    BytesPerSecondKHR = 4,
    KelvinKHR = 5,
    WattsKHR = 6,
    VoltsKHR = 7,
    AmpsKHR = 8,
    HertzKHR = 9,
    CyclesKHR = 10,
};
enum class PerformanceCounterStorageKHR : uint32_t {
    Int32KHR = 0,
    Int64KHR = 1,
    Uint32KHR = 2,
    Uint64KHR = 3,
    Float32KHR = 4,
    Float64KHR = 5,
};
enum class PerformanceConfigurationTypeINTEL : uint32_t {
    CommandQueueMetricsDiscoveryActivatedINTEL = 0,
};
enum class QueryPoolSamplingModeINTEL : uint32_t {
    ManualINTEL = 0,
};
enum class PerformanceOverrideTypeINTEL : uint32_t {
    NullHardwareINTEL = 0,
    FlushGpuCachesINTEL = 1,
};
enum class PerformanceParameterTypeINTEL : uint32_t {
    HwCountersSupportedINTEL = 0,
    StreamMarkerValidsINTEL = 1,
};
enum class PerformanceValueTypeINTEL : uint32_t {
    Uint32INTEL = 0,
    Uint64INTEL = 1,
    FloatINTEL = 2,
    BoolINTEL = 3,
    StringINTEL = 4,
};
enum class LineRasterizationModeKHR : uint32_t {
    DefaultKHR = 0,
    RectangularKHR = 1,
    BresenhamKHR = 2,
    RectangularSmoothKHR = 3,
};
using LineRasterizationModeEXT = LineRasterizationModeKHR;
enum class FragmentShadingRateNV : uint32_t {
    e1InvocationPerPixelNV = 0,
    e1InvocationPer1X2PixelsNV = 1,
    e1InvocationPer2X1PixelsNV = 4,
    e1InvocationPer2X2PixelsNV = 5,
    e1InvocationPer2X4PixelsNV = 6,
    e1InvocationPer4X2PixelsNV = 9,
    e1InvocationPer4X4PixelsNV = 10,
    e2InvocationsPerPixelNV = 11,
    e4InvocationsPerPixelNV = 12,
    e8InvocationsPerPixelNV = 13,
    e16InvocationsPerPixelNV = 14,
    NoInvocationsNV = 15,
};
enum class FragmentShadingRateTypeNV : uint32_t {
    FragmentSizeNV = 0,
    EnumsNV = 1,
};
enum class SubpassMergeStatusEXT : uint32_t {
    MergedEXT = 0,
    DisallowedEXT = 1,
    NotMergedSideEffectsEXT = 2,
    NotMergedSamplesMismatchEXT = 3,
    NotMergedViewsMismatchEXT = 4,
    NotMergedAliasingEXT = 5,
    NotMergedDependenciesEXT = 6,
    NotMergedIncompatibleInputAttachmentEXT = 7,
    NotMergedTooManyAttachmentsEXT = 8,
    NotMergedInsufficientStorageEXT = 9,
    NotMergedDepthStencilCountEXT = 10,
    NotMergedResolveAttachmentReuseEXT = 11,
    NotMergedSingleSubpassEXT = 12,
    NotMergedUnspecifiedEXT = 13,
};
enum class ProvokingVertexModeEXT : uint32_t {
    FirstVertexEXT = 0,
    LastVertexEXT = 1,
};
enum class PipelineRobustnessBufferBehaviorEXT : uint32_t {
    DeviceDefaultEXT = 0,
    DisabledEXT = 1,
    RobustBufferAccessEXT = 2,
    RobustBufferAccess2EXT = 3,
};
enum class PipelineRobustnessImageBehaviorEXT : uint32_t {
    DeviceDefaultEXT = 0,
    DisabledEXT = 1,
    RobustImageAccessEXT = 2,
    RobustImageAccess2EXT = 3,
};
enum class DeviceAddressBindingTypeEXT : uint32_t {
    BindEXT = 0,
    UnbindEXT = 1,
};
enum class MicromapTypeEXT : uint32_t {
    OpacityMicromapEXT = 0,
    DisplacementMicromapNV = 1000397000,
};
enum class BuildMicromapModeEXT : uint32_t {
    BuildEXT = 0,
};
enum class CopyMicromapModeEXT : uint32_t {
    CloneEXT = 0,
    SerializeEXT = 1,
    DeserializeEXT = 2,
    CompactEXT = 3,
};
enum class OpacityMicromapFormatEXT : uint32_t {
    e2StateEXT = 1,
    e4StateEXT = 2,
};
enum class OpacityMicromapSpecialIndexEXT : int32_t {
    FullyTransparentEXT = -1,
    FullyOpaqueEXT = -2,
    FullyUnknownTransparentEXT = -3,
    FullyUnknownOpaqueEXT = -4,
};
enum class DeviceFaultVendorBinaryHeaderVersionEXT : uint32_t {
    OneEXT = 1,
};
enum class DepthBiasRepresentationEXT : uint32_t {
    LeastRepresentableValueFormatEXT = 0,
    LeastRepresentableValueForceUnormEXT = 1,
    FloatEXT = 2,
};
enum class DirectDriverLoadingModeLUNARG : uint32_t {
    ExclusiveLUNARG = 0,
    InclusiveLUNARG = 1,
};
#if defined(VK_ENABLE_BETA_EXTENSIONS)
enum class DisplacementMicromapFormatNV : uint32_t {
    e64Triangles64BytesNV = 1,
    e256Triangles128BytesNV = 2,
    e1024Triangles128BytesNV = 3,
};
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
enum class ShaderCodeTypeEXT : uint32_t {
    BinaryEXT = 0,
    SpirvEXT = 1,
};
enum class ScopeKHR : uint32_t {
    DeviceKHR = 1,
    WorkgroupKHR = 2,
    SubgroupKHR = 3,
    QueueFamilyKHR = 5,
};
enum class ComponentTypeKHR : uint32_t {
    Float16KHR = 0,
    Float32KHR = 1,
    Float64KHR = 2,
    Sint8KHR = 3,
    Sint16KHR = 4,
    Sint32KHR = 5,
    Sint64KHR = 6,
    Uint8KHR = 7,
    Uint16KHR = 8,
    Uint32KHR = 9,
    Uint64KHR = 10,
};
using ScopeNV = ScopeKHR;
using ComponentTypeNV = ComponentTypeKHR;
enum class CubicFilterWeightsQCOM : uint32_t {
    CatmullRomQCOM = 0,
    ZeroTangentCardinalQCOM = 1,
    BSplineQCOM = 2,
    MitchellNetravaliQCOM = 3,
};
enum class BlockMatchWindowCompareModeQCOM : uint32_t {
    MinQCOM = 0,
    MaxQCOM = 1,
};
enum class LayeredDriverUnderlyingApiMSFT : uint32_t {
    NoneMSFT = 0,
    D3D12MSFT = 1,
};
enum class ColorSpaceKHR : uint32_t {
    SrgbNonlinearKHR = 0,
    DisplayP3NonlinearEXT = 1000104001,
    ExtendedSrgbLinearEXT = 1000104002,
    DisplayP3LinearEXT = 1000104003,
    DciP3NonlinearEXT = 1000104004,
    Bt709LinearEXT = 1000104005,
    Bt709NonlinearEXT = 1000104006,
    Bt2020LinearEXT = 1000104007,
    Hdr10St2084EXT = 1000104008,
    DolbyvisionEXT = 1000104009,
    Hdr10HlgEXT = 1000104010,
    AdobergbLinearEXT = 1000104011,
    AdobergbNonlinearEXT = 1000104012,
    PassThroughEXT = 1000104013,
    ExtendedSrgbNonlinearEXT = 1000104014,
    DisplayNativeAMD = 1000213000,
};
enum class PresentModeKHR : uint32_t {
    ImmediateKHR = 0,
    MailboxKHR = 1,
    FifoKHR = 2,
    FifoRelaxedKHR = 3,
    SharedDemandRefreshKHR = 1000111000,
    SharedContinuousRefreshKHR = 1000111001,
};
enum class DebugReportObjectTypeEXT : uint32_t {
    UnknownEXT = 0,
    InstanceEXT = 1,
    PhysicalDeviceEXT = 2,
    DeviceEXT = 3,
    QueueEXT = 4,
    SemaphoreEXT = 5,
    CommandBufferEXT = 6,
    FenceEXT = 7,
    DeviceMemoryEXT = 8,
    BufferEXT = 9,
    ImageEXT = 10,
    EventEXT = 11,
    QueryPoolEXT = 12,
    BufferViewEXT = 13,
    ImageViewEXT = 14,
    ShaderModuleEXT = 15,
    PipelineCacheEXT = 16,
    PipelineLayoutEXT = 17,
    RenderPassEXT = 18,
    PipelineEXT = 19,
    DescriptorSetLayoutEXT = 20,
    SamplerEXT = 21,
    DescriptorPoolEXT = 22,
    DescriptorSetEXT = 23,
    FramebufferEXT = 24,
    CommandPoolEXT = 25,
    SurfaceKhrEXT = 26,
    SwapchainKhrEXT = 27,
    DebugReportCallbackExtEXT = 28,
    DisplayKhrEXT = 29,
    DisplayModeKhrEXT = 30,
    ValidationCacheExtEXT = 33,
    SamplerYcbcrConversionEXT = 1000156000,
    DescriptorUpdateTemplateEXT = 1000085000,
    CuModuleNvxEXT = 1000029000,
    CuFunctionNvxEXT = 1000029001,
    AccelerationStructureKhrEXT = 1000150000,
    AccelerationStructureNvEXT = 1000165000,
    CudaModuleNvEXT = 1000307000,
    CudaFunctionNvEXT = 1000307001,
    BufferCollectionFuchsiaEXT = 1000366000,
};
enum class DeviceMemoryReportEventTypeEXT : uint32_t {
    AllocateEXT = 0,
    FreeEXT = 1,
    ImportEXT = 2,
    UnimportEXT = 3,
    AllocationFailedEXT = 4,
};
enum class RasterizationOrderAMD : uint32_t {
    StrictAMD = 0,
    RelaxedAMD = 1,
};
enum class ValidationCheckEXT : uint32_t {
    AllEXT = 0,
    ShadersEXT = 1,
};
enum class ValidationFeatureEnableEXT : uint32_t {
    GpuAssistedEXT = 0,
    GpuAssistedReserveBindingSlotEXT = 1,
    BestPracticesEXT = 2,
    DebugPrintfEXT = 3,
    SynchronizationValidationEXT = 4,
};
enum class ValidationFeatureDisableEXT : uint32_t {
    AllEXT = 0,
    ShadersEXT = 1,
    ThreadSafetyEXT = 2,
    ApiParametersEXT = 3,
    ObjectLifetimesEXT = 4,
    CoreChecksEXT = 5,
    UniqueHandlesEXT = 6,
    ShaderValidationCacheEXT = 7,
};
enum class DisplayPowerStateEXT : uint32_t {
    OffEXT = 0,
    SuspendEXT = 1,
    OnEXT = 2,
};
enum class DeviceEventTypeEXT : uint32_t {
    DisplayHotplugEXT = 0,
};
enum class DisplayEventTypeEXT : uint32_t {
    FirstPixelOutEXT = 0,
};
enum class TessellationDomainOrigin : uint32_t {
    UpperLeft = 0,
    LowerLeft = 1,
};
using TessellationDomainOriginKHR = TessellationDomainOrigin;
enum class SamplerYcbcrModelConversion : uint32_t {
    RgbIdentity = 0,
    YcbcrIdentity = 1,
    Ycbcr709 = 2,
    Ycbcr601 = 3,
    Ycbcr2020 = 4,
};
using SamplerYcbcrModelConversionKHR = SamplerYcbcrModelConversion;
enum class SamplerYcbcrRange : uint32_t {
    ItuFull = 0,
    ItuNarrow = 1,
};
using SamplerYcbcrRangeKHR = SamplerYcbcrRange;
enum class ChromaLocation : uint32_t {
    CositedEven = 0,
    Midpoint = 1,
};
using ChromaLocationKHR = ChromaLocation;
enum class SamplerReductionMode : uint32_t {
    WeightedAverage = 0,
    Min = 1,
    Max = 2,
    WeightedAverageRangeclampQCOM = 1000521000,
};
using SamplerReductionModeEXT = SamplerReductionMode;
enum class BlendOverlapEXT : uint32_t {
    UncorrelatedEXT = 0,
    DisjointEXT = 1,
    ConjointEXT = 2,
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
enum class FullScreenExclusiveEXT : uint32_t {
    DefaultEXT = 0,
    AllowedEXT = 1,
    DisallowedEXT = 2,
    ApplicationControlledEXT = 3,
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
enum class ShaderFloatControlsIndependence : uint32_t {
    e32Only = 0,
    All = 1,
    None = 2,
};
using ShaderFloatControlsIndependenceKHR = ShaderFloatControlsIndependence;
enum class FragmentShadingRateCombinerOpKHR : uint32_t {
    KeepKHR = 0,
    ReplaceKHR = 1,
    MinKHR = 2,
    MaxKHR = 3,
    MulKHR = 4,
};
enum class OpticalFlowPerformanceLevelNV : uint32_t {
    UnknownNV = 0,
    SlowNV = 1,
    MediumNV = 2,
    FastNV = 3,
};
enum class OpticalFlowSessionBindingPointNV : uint32_t {
    UnknownNV = 0,
    InputNV = 1,
    ReferenceNV = 2,
    HintNV = 3,
    FlowVectorNV = 4,
    BackwardFlowVectorNV = 5,
    CostNV = 6,
    BackwardCostNV = 7,
    GlobalFlowNV = 8,
};
enum class DeviceFaultAddressTypeEXT : uint32_t {
    NoneEXT = 0,
    ReadInvalidEXT = 1,
    WriteInvalidEXT = 2,
    ExecuteInvalidEXT = 3,
    InstructionPointerUnknownEXT = 4,
    InstructionPointerInvalidEXT = 5,
    InstructionPointerFaultEXT = 6,
};
enum class LayerSettingTypeEXT : uint32_t {
    Bool32EXT = 0,
    Int32EXT = 1,
    Int64EXT = 2,
    Uint32EXT = 3,
    Uint64EXT = 4,
    Float32EXT = 5,
    Float64EXT = 6,
    StringEXT = 7,
};
enum class LatencyMarkerNV : uint32_t {
    SimulationStartNV = 0,
    SimulationEndNV = 1,
    RendersubmitStartNV = 2,
    RendersubmitEndNV = 3,
    PresentStartNV = 4,
    PresentEndNV = 5,
    InputSampleNV = 6,
    TriggerFlashNV = 7,
    OutOfBandRendersubmitStartNV = 8,
    OutOfBandRendersubmitEndNV = 9,
    OutOfBandPresentStartNV = 10,
    OutOfBandPresentEndNV = 11,
};
enum class OutOfBandQueueTypeNV : uint32_t {
    RenderNV = 0,
    PresentNV = 1,
};
enum class VendorId : uint32_t {
    VIV = 0x10001,
    VSI = 0x10002,
    Kazan = 0x10003,
    Codeplay = 0x10004,
    MESA = 0x10005,
    Pocl = 0x10006,
    Mobileye = 0x10007,
};
enum class DriverId : uint32_t {
    AmdProprietary = 1,
    AmdOpenSource = 2,
    MesaRadv = 3,
    NvidiaProprietary = 4,
    IntelProprietaryWindows = 5,
    IntelOpenSourceMESA = 6,
    ImaginationProprietary = 7,
    QualcommProprietary = 8,
    ArmProprietary = 9,
    GoogleSwiftshader = 10,
    GgpProprietary = 11,
    BroadcomProprietary = 12,
    MesaLlvmpipe = 13,
    Moltenvk = 14,
    CoreaviProprietary = 15,
    JuiceProprietary = 16,
    VerisiliconProprietary = 17,
    MesaTurnip = 18,
    MesaV3Dv = 19,
    MesaPanvk = 20,
    SamsungProprietary = 21,
    MesaVenus = 22,
    MesaDozen = 23,
    MesaNvk = 24,
    ImaginationOpenSourceMESA = 25,
    MesaAgxv = 26,
};
using DriverIdKHR = DriverId;
enum class ShadingRatePaletteEntryNV : uint32_t {
    NoInvocationsNV = 0,
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
    DefaultNV = 0,
    CustomNV = 1,
    PixelMajorNV = 2,
    SampleMajorNV = 3,
};
enum class PipelineExecutableStatisticFormatKHR : uint32_t {
    Bool32KHR = 0,
    Int64KHR = 1,
    Uint64KHR = 2,
    Float64KHR = 3,
};
enum class QueryResultStatusKHR : int32_t {
    ErrorKHR = -1,
    NotReadyKHR = 0,
    CompleteKHR = 1,
    InsufficientstreamBufferRangeKHR = -1000299000,
};
enum class VideoEncodeTuningModeKHR : uint32_t {
    DefaultKHR = 0,
    HighQualityKHR = 1,
    LowLatencyKHR = 2,
    UltraLowLatencyKHR = 3,
    LosslessKHR = 4,
};
enum class AccelerationStructureMotionInstanceTypeNV : uint32_t {
    StaticNV = 0,
    MatrixMotionNV = 1,
    SrtMotionNV = 2,
};
enum class PipelineCacheCreateFlagBits: uint32_t {
    ExternallySynchronized = 1,
};
enum class QueueFlagBits: uint32_t {
    Graphics = 1,
    Compute = 2,
    Transfer = 4,
    SparseBinding = 8,
    Protected = 16,
    VideoDecodeKHR = 32,
    VideoEncodeKHR = 64,
    OpticalFlowNV = 256,
};
enum class CullModeFlagBits: uint32_t {
    None = 0,
    Front = 1,
    Back = 2,
    FrontAndBack = 0x00000003,
};
enum class RenderPassCreateFlagBits: uint32_t {
    TransformQCOM = 2,
};
enum class DeviceQueueCreateFlagBits: uint32_t {
    Protected = 1,
};
enum class MemoryPropertyFlagBits: uint32_t {
    DeviceLocal = 1,
    HostVisible = 2,
    HostCoherent = 4,
    HostCached = 8,
    LazilyAllocated = 16,
    Protected = 32,
    DeviceCoherentAMD = 64,
    DeviceUncachedAMD = 128,
    RdmaCapableNV = 256,
};
enum class MemoryHeapFlagBits: uint32_t {
    DeviceLocal = 1,
    MultiInstance = 2,
};
enum class AccessFlagBits: uint32_t {
    IndirectCommandRead = 1,
    IndexRead = 2,
    VertexAttributeRead = 4,
    UniformRead = 8,
    InputAttachmentRead = 16,
    ShaderRead = 32,
    ShaderWrite = 64,
    ColorAttachmentRead = 128,
    ColorAttachmentWrite = 256,
    DepthStencilAttachmentRead = 512,
    DepthStencilAttachmentWrite = 1024,
    TransferRead = 2048,
    TransferWrite = 4096,
    HostRead = 8192,
    HostWrite = 16384,
    MemoryRead = 32768,
    MemoryWrite = 65536,
    None = 0,
    TransformFeedbackWriteEXT = 33554432,
    TransformFeedbackCounterReadEXT = 67108864,
    TransformFeedbackCounterWriteEXT = 134217728,
    ConditionalRenderingReadEXT = 1048576,
    ColorAttachmentReadNoncoherentEXT = 524288,
    AccelerationStructureReadKHR = 2097152,
    AccelerationStructureWriteKHR = 4194304,
    FragmentDensityMapReadEXT = 16777216,
    FragmentShadingRateAttachmentReadKHR = 8388608,
    CommandPreprocessReadNV = 131072,
    CommandPreprocessWriteNV = 262144,
};
enum class BufferUsageFlagBits: uint32_t {
    TransferSrc = 1,
    TransferDst = 2,
    UniformTexelBuffer = 4,
    StorageTexelBuffer = 8,
    UniformBuffer = 16,
    StorageBuffer = 32,
    IndexBuffer = 64,
    VertexBuffer = 128,
    IndirectBuffer = 256,
    ShaderDeviceAddress = 131072,
    VideoDecodeSrcKHR = 8192,
    VideoDecodeDstKHR = 16384,
    TransformFeedbackBufferEXT = 2048,
    TransformFeedbackCounterBufferEXT = 4096,
    ConditionalRenderingEXT = 512,
    ExecutionGraphScratchAMDX = 33554432,
    AccelerationStructureBuildInputReadOnlyKHR = 524288,
    AccelerationStructureStorageKHR = 1048576,
    ShaderBindingTableKHR = 1024,
    VideoEncodeDstKHR = 32768,
    VideoEncodeSrcKHR = 65536,
    SamplerDescriptorBufferEXT = 2097152,
    ResourceDescriptorBufferEXT = 4194304,
    PushDescriptorsDescriptorBufferEXT = 67108864,
    MicromapBuildInputReadOnlyEXT = 8388608,
    MicromapStorageEXT = 16777216,
};
enum class BufferUsageFlagBits2KHR: uint64_t {
    BufferUsage2TransferSrcKHR = 1,
    BufferUsage2TransferDstKHR = 2,
    BufferUsage2UniformTexelBufferKHR = 4,
    BufferUsage2StorageTexelBufferKHR = 8,
    BufferUsage2UniformBufferKHR = 16,
    BufferUsage2StorageBufferKHR = 32,
    BufferUsage2IndexBufferKHR = 64,
    BufferUsage2VertexBufferKHR = 128,
    BufferUsage2IndirectBufferKHR = 256,
    BufferUsage2ExecutionGraphScratchAMDX = 33554432,
    BufferUsage2ConditionalRenderingEXT = 512,
    BufferUsage2ShaderBindingTableKHR = 1024,
    BufferUsage2TransformFeedbackBufferEXT = 2048,
    BufferUsage2TransformFeedbackCounterBufferEXT = 4096,
    BufferUsage2VideoDecodeSrcKHR = 8192,
    BufferUsage2VideoDecodeDstKHR = 16384,
    BufferUsage2VideoEncodeDstKHR = 32768,
    BufferUsage2VideoEncodeSrcKHR = 65536,
    BufferUsage2ShaderDeviceAddressKHR = 131072,
    BufferUsage2AccelerationStructureBuildInputReadOnlyKHR = 524288,
    BufferUsage2AccelerationStructureStorageKHR = 1048576,
    BufferUsage2SamplerDescriptorBufferEXT = 2097152,
    BufferUsage2ResourceDescriptorBufferEXT = 4194304,
    BufferUsage2PushDescriptorsDescriptorBufferEXT = 67108864,
    BufferUsage2MicromapBuildInputReadOnlyEXT = 8388608,
    BufferUsage2MicromapStorageEXT = 16777216,
};
enum class BufferCreateFlagBits: uint32_t {
    SparseBinding = 1,
    SparseResidency = 2,
    SparseAliased = 4,
    Protected = 8,
    DeviceAddressCaptureReplay = 16,
    DescriptorBufferCaptureReplayEXT = 32,
    VideoProfileIndependentKHR = 64,
};
enum class ShaderStageFlagBits: uint32_t {
    Vertex = 1,
    TessellationControl = 2,
    TessellationEvaluation = 4,
    Geometry = 8,
    Fragment = 16,
    Compute = 32,
    AllGraphics = 0x0000001F,
    All = 0x7FFFFFFF,
    RaygenKHR = 256,
    AnyHitKHR = 512,
    ClosestHitKHR = 1024,
    MissKHR = 2048,
    IntersectionKHR = 4096,
    CallableKHR = 8192,
    TaskEXT = 64,
    MeshEXT = 128,
    SubpassShadingHUAWEI = 16384,
    ClusterCullingHUAWEI = 524288,
};
enum class ImageUsageFlagBits: uint32_t {
    TransferSrc = 1,
    TransferDst = 2,
    Sampled = 4,
    Storage = 8,
    ColorAttachment = 16,
    DepthStencilAttachment = 32,
    TransientAttachment = 64,
    InputAttachment = 128,
    VideoDecodeDstKHR = 1024,
    VideoDecodeSrcKHR = 2048,
    VideoDecodeDpbKHR = 4096,
    FragmentDensityMapEXT = 512,
    FragmentShadingRateAttachmentKHR = 256,
    HostTransferEXT = 4194304,
    VideoEncodeDstKHR = 8192,
    VideoEncodeSrcKHR = 16384,
    VideoEncodeDpbKHR = 32768,
    AttachmentFeedbackLoopEXT = 524288,
    InvocationMaskHUAWEI = 262144,
    SampleWeightQCOM = 1048576,
    SampleBlockMatchQCOM = 2097152,
};
enum class ImageCreateFlagBits: uint32_t {
    SparseBinding = 1,
    SparseResidency = 2,
    SparseAliased = 4,
    MutableFormat = 8,
    CubeCompatible = 16,
    Alias = 1024,
    SplitInstanceBindRegions = 64,
    e2DArrayCompatible = 32,
    BlockTexelViewCompatible = 128,
    ExtendedUsage = 256,
    Protected = 2048,
    Disjoint = 512,
    CornerSampledNV = 8192,
    SampleLocationsCompatibleDepthEXT = 4096,
    SubsampledEXT = 16384,
    DescriptorBufferCaptureReplayEXT = 65536,
    MultisampledRenderToSingleSampledEXT = 262144,
    e2DViewCompatibleEXT = 131072,
    FragmentDensityMapOffsetQCOM = 32768,
    VideoProfileIndependentKHR = 1048576,
};
enum class ImageViewCreateFlagBits: uint32_t {
    FragmentDensityMapDynamicEXT = 1,
    DescriptorBufferCaptureReplayEXT = 4,
    FragmentDensityMapDeferredEXT = 2,
};
enum class SamplerCreateFlagBits: uint32_t {
    SubsampledEXT = 1,
    SubsampledCoarseReconstructionEXT = 2,
    DescriptorBufferCaptureReplayEXT = 8,
    NonSeamlessCubeMapEXT = 4,
    ImageProcessingQCOM = 16,
};
enum class PipelineCreateFlagBits: uint32_t {
    DisableOptimization = 1,
    AllowDerivatives = 2,
    Derivative = 4,
    ViewIndexFromDeviceIndex = 8,
    DispatchBase = 16,
    FailOnPipelineCompileRequired = 256,
    EarlyReturnOnFailure = 512,
    RenderingFragmentShadingRateAttachmentKHR = 2097152,
    RenderingFragmentDensityMapAttachmentEXT = 4194304,
    RayTracingNoNullAnyHitShadersKHR = 16384,
    RayTracingNoNullClosestHitShadersKHR = 32768,
    RayTracingNoNullMissShadersKHR = 65536,
    RayTracingNoNullIntersectionShadersKHR = 131072,
    RayTracingSkipTrianglesKHR = 4096,
    RayTracingSkipAabbsKHR = 8192,
    RayTracingShaderGroupHandleCaptureReplayKHR = 524288,
    DeferCompileNV = 32,
    CaptureStatisticsKHR = 64,
    CaptureInternalRepresentationsKHR = 128,
    IndirectBindableNV = 262144,
    LibraryKHR = 2048,
    DescriptorBufferEXT = 536870912,
    RetainLinkTimeOptimizationInfoEXT = 8388608,
    LinkTimeOptimizationEXT = 1024,
    RayTracingAllowMotionNV = 1048576,
    ColorAttachmentFeedbackLoopEXT = 33554432,
    DepthStencilAttachmentFeedbackLoopEXT = 67108864,
    RayTracingOpacityMicromapEXT = 16777216,
    RayTracingDisplacementMicromapNV = 268435456,
    NoProtectedAccessEXT = 134217728,
    ProtectedAccessOnlyEXT = 1073741824,
};
enum class PipelineCreateFlagBits2KHR: uint64_t {
    PipelineCreate2DisableOptimizationKHR = 1,
    PipelineCreate2AllowDerivativesKHR = 2,
    PipelineCreate2DerivativeKHR = 4,
    PipelineCreate2ViewIndexFromDeviceIndexKHR = 8,
    PipelineCreate2DispatchBaseKHR = 16,
    PipelineCreate2DeferCompileNV = 32,
    PipelineCreate2CaptureStatisticsKHR = 64,
    PipelineCreate2CaptureInternalRepresentationsKHR = 128,
    PipelineCreate2FailOnPipelineCompileRequiredKHR = 256,
    PipelineCreate2EarlyReturnOnFailureKHR = 512,
    PipelineCreate2LinkTimeOptimizationEXT = 1024,
    PipelineCreate2RetainLinkTimeOptimizationInfoEXT = 8388608,
    PipelineCreate2LibraryKHR = 2048,
    PipelineCreate2RayTracingSkipTrianglesKHR = 4096,
    PipelineCreate2RayTracingSkipAabbsKHR = 8192,
    PipelineCreate2RayTracingNoNullAnyHitShadersKHR = 16384,
    PipelineCreate2RayTracingNoNullClosestHitShadersKHR = 32768,
    PipelineCreate2RayTracingNoNullMissShadersKHR = 65536,
    PipelineCreate2RayTracingNoNullIntersectionShadersKHR = 131072,
    PipelineCreate2RayTracingShaderGroupHandleCaptureReplayKHR = 524288,
    PipelineCreate2IndirectBindableNV = 262144,
    PipelineCreate2RayTracingAllowMotionNV = 1048576,
    PipelineCreate2RenderingFragmentShadingRateAttachmentKHR = 2097152,
    PipelineCreate2RenderingFragmentDensityMapAttachmentEXT = 4194304,
    PipelineCreate2RayTracingOpacityMicromapEXT = 16777216,
    PipelineCreate2ColorAttachmentFeedbackLoopEXT = 33554432,
    PipelineCreate2DepthStencilAttachmentFeedbackLoopEXT = 67108864,
    PipelineCreate2NoProtectedAccessEXT = 134217728,
    PipelineCreate2ProtectedAccessOnlyEXT = 1073741824,
    PipelineCreate2RayTracingDisplacementMicromapNV = 268435456,
    PipelineCreate2DescriptorBufferEXT = 536870912,
};
enum class PipelineShaderStageCreateFlagBits: uint32_t {
    AllowVaryingSubgroupSize = 1,
    RequireFullSubgroups = 2,
};
enum class ColorComponentFlagBits: uint32_t {
    R = 1,
    G = 2,
    B = 4,
    A = 8,
};
enum class FenceCreateFlagBits: uint32_t {
    Signaled = 1,
};
enum class FormatFeatureFlagBits: uint32_t {
    SampledImage = 1,
    StorageImage = 2,
    StorageImageAtomic = 4,
    UniformTexelBuffer = 8,
    StorageTexelBuffer = 16,
    StorageTexelBufferAtomic = 32,
    VertexBuffer = 64,
    ColorAttachment = 128,
    ColorAttachmentBlend = 256,
    DepthStencilAttachment = 512,
    BlitSrc = 1024,
    BlitDst = 2048,
    SampledImageFilterLinear = 4096,
    TransferSrc = 16384,
    TransferDst = 32768,
    MidpointChromaSamples = 131072,
    SampledImageYcbcrConversionLinearFilter = 262144,
    SampledImageYcbcrConversionSeparateReconstructionFilter = 524288,
    SampledImageYcbcrConversionChromaReconstructionExplicit = 1048576,
    SampledImageYcbcrConversionChromaReconstructionExplicitForceable = 2097152,
    Disjoint = 4194304,
    CositedChromaSamples = 8388608,
    SampledImageFilterMinmax = 65536,
    VideoDecodeOutputKHR = 33554432,
    VideoDecodeDpbKHR = 67108864,
    AccelerationStructureVertexBufferKHR = 536870912,
    SampledImageFilterCubicEXT = 8192,
    FragmentDensityMapEXT = 16777216,
    FragmentShadingRateAttachmentKHR = 1073741824,
    VideoEncodeInputKHR = 134217728,
    VideoEncodeDpbKHR = 268435456,
};
enum class QueryControlFlagBits: uint32_t {
    Precise = 1,
};
enum class QueryResultFlagBits: uint32_t {
    e64 = 1,
    Wait = 2,
    WithAvailability = 4,
    Partial = 8,
    WithStatusKHR = 16,
};
enum class CommandBufferUsageFlagBits: uint32_t {
    OneTimeSubmit = 1,
    RenderPassContinue = 2,
    SimultaneousUse = 4,
};
enum class QueryPipelineStatisticFlagBits: uint32_t {
    InputAssemblyVertices = 1,
    InputAssemblyPrimitives = 2,
    VertexShaderInvocations = 4,
    GeometryShaderInvocations = 8,
    GeometryShaderPrimitives = 16,
    ClippingInvocations = 32,
    ClippingPrimitives = 64,
    FragmentShaderInvocations = 128,
    TessellationControlShaderPatches = 256,
    TessellationEvaluationShaderInvocations = 512,
    ComputeShaderInvocations = 1024,
    TaskShaderInvocationsEXT = 2048,
    MeshShaderInvocationsEXT = 4096,
    ClusterCullingShaderInvocationsHUAWEI = 8192,
};
enum class ImageAspectFlagBits: uint32_t {
    Color = 1,
    Depth = 2,
    Stencil = 4,
    Metadata = 8,
    Plane0 = 16,
    Plane1 = 32,
    Plane2 = 64,
    None = 0,
    MemoryPlane0EXT = 128,
    MemoryPlane1EXT = 256,
    MemoryPlane2EXT = 512,
    MemoryPlane3EXT = 1024,
};
enum class SparseImageFormatFlagBits: uint32_t {
    SingleMiptail = 1,
    AlignedMipSize = 2,
    NonstandardBlockSize = 4,
};
enum class SparseMemoryBindFlagBits: uint32_t {
    Metadata = 1,
};
enum class PipelineStageFlagBits: uint32_t {
    TopOfPipe = 1,
    DrawIndirect = 2,
    VertexInput = 4,
    VertexShader = 8,
    TessellationControlShader = 16,
    TessellationEvaluationShader = 32,
    GeometryShader = 64,
    FragmentShader = 128,
    EarlyFragmentTests = 256,
    LateFragmentTests = 512,
    ColorAttachmentOutput = 1024,
    ComputeShader = 2048,
    Transfer = 4096,
    BottomOfPipe = 8192,
    Host = 16384,
    AllGraphics = 32768,
    AllCommands = 65536,
    None = 0,
    TransformFeedbackEXT = 16777216,
    ConditionalRenderingEXT = 262144,
    AccelerationStructureBuildKHR = 33554432,
    RayTracingShaderKHR = 2097152,
    FragmentDensityProcessEXT = 8388608,
    FragmentShadingRateAttachmentKHR = 4194304,
    CommandPreprocessNV = 131072,
    TaskShaderEXT = 524288,
    MeshShaderEXT = 1048576,
};
enum class CommandPoolCreateFlagBits: uint32_t {
    Transient = 1,
    ResetCommandBuffer = 2,
    Protected = 4,
};
enum class CommandPoolResetFlagBits: uint32_t {
    ReleaseResources = 1,
};
enum class CommandBufferResetFlagBits: uint32_t {
    ReleaseResources = 1,
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
    MayAlias = 1,
};
enum class StencilFaceFlagBits: uint32_t {
    Front = 1,
    Back = 2,
    FrontAndBack = 0x00000003,
};
enum class DescriptorPoolCreateFlagBits: uint32_t {
    FreeDescriptorSet = 1,
    UpdateAfterBind = 2,
    HostOnlyEXT = 4,
    AllowOverallocationSetsNV = 8,
    AllowOverallocationPoolsNV = 16,
};
enum class DependencyFlagBits: uint32_t {
    ByRegion = 1,
    DeviceGroup = 4,
    ViewLocal = 2,
    FeedbackLoopEXT = 8,
};
enum class SemaphoreWaitFlagBits: uint32_t {
    Any = 1,
};
enum class DisplayPlaneAlphaFlagBitsKHR: uint32_t {
    OpaqueKHR = 1,
    GlobalKHR = 2,
    PerPixelKHR = 4,
    PerPixelPremultipliedKHR = 8,
};
enum class CompositeAlphaFlagBitsKHR: uint32_t {
    OpaqueKHR = 1,
    PreMultipliedKHR = 2,
    PostMultipliedKHR = 4,
    InheritKHR = 8,
};
enum class SurfaceTransformFlagBitsKHR: uint32_t {
    IdentityKHR = 1,
    Rotate90KHR = 2,
    Rotate180KHR = 4,
    Rotate270KHR = 8,
    HorizontalMirrorKHR = 16,
    HorizontalMirrorRotate90KHR = 32,
    HorizontalMirrorRotate180KHR = 64,
    HorizontalMirrorRotate270KHR = 128,
    InheritKHR = 256,
};
enum class DebugReportFlagBitsEXT: uint32_t {
    InformationEXT = 1,
    WarningEXT = 2,
    PerformanceWarningEXT = 4,
    ErrorEXT = 8,
    DebugEXT = 16,
};
enum class ExternalMemoryHandleTypeFlagBitsNV: uint32_t {
    OpaqueWin32NV = 1,
    OpaqueWin32KmtNV = 2,
    D3D11ImageNV = 4,
    D3D11ImageKmtNV = 8,
};
enum class ExternalMemoryFeatureFlagBitsNV: uint32_t {
    DedicatedOnlyNV = 1,
    ExportableNV = 2,
    ImportableNV = 4,
};
enum class SubgroupFeatureFlagBits: uint32_t {
    Basic = 1,
    Vote = 2,
    Arithmetic = 4,
    Ballot = 8,
    Shuffle = 16,
    ShuffleRelative = 32,
    Clustered = 64,
    Quad = 128,
    PartitionedNV = 256,
    RotateKHR = 512,
    RotateClusteredKHR = 1024,
};
enum class IndirectCommandsLayoutUsageFlagBitsNV: uint32_t {
    ExplicitPreprocessNV = 1,
    IndexedSequencesNV = 2,
    UnorderedSequencesNV = 4,
};
enum class IndirectStateFlagBitsNV: uint32_t {
    FlagFrontfaceNV = 1,
};
enum class DescriptorSetLayoutCreateFlagBits: uint32_t {
    UpdateAfterBindPool = 2,
    PushDescriptorKHR = 1,
    DescriptorBufferEXT = 16,
    EmbeddedImmutableSamplersEXT = 32,
    IndirectBindableNV = 128,
    HostOnlyPoolEXT = 4,
    PerStageNV = 64,
};
enum class ExternalMemoryHandleTypeFlagBits: uint32_t {
    OpaqueFd = 1,
    OpaqueWin32 = 2,
    OpaqueWin32Kmt = 4,
    D3D11Texture = 8,
    D3D11TextureKmt = 16,
    D3D12Heap = 32,
    D3D12Resource = 64,
    DmaBufEXT = 512,
    AndroidHardwareBufferANDROID = 1024,
    HostAllocationEXT = 128,
    HostMappedForeignMemoryEXT = 256,
    ZirconVmoFUCHSIA = 2048,
    RdmaAddressNV = 4096,
    ScreenBufferQNX = 16384,
};
enum class ExternalMemoryFeatureFlagBits: uint32_t {
    DedicatedOnly = 1,
    Exportable = 2,
    Importable = 4,
};
enum class ExternalSemaphoreHandleTypeFlagBits: uint32_t {
    OpaqueFd = 1,
    OpaqueWin32 = 2,
    OpaqueWin32Kmt = 4,
    D3D12Fence = 8,
    D3D11Fence = D3D12Fence,
    SyncFd = 16,
    ZirconEventFUCHSIA = 128,
};
enum class ExternalSemaphoreFeatureFlagBits: uint32_t {
    Exportable = 1,
    Importable = 2,
};
enum class SemaphoreImportFlagBits: uint32_t {
    Temporary = 1,
};
enum class ExternalFenceHandleTypeFlagBits: uint32_t {
    OpaqueFd = 1,
    OpaqueWin32 = 2,
    OpaqueWin32Kmt = 4,
    SyncFd = 8,
};
enum class ExternalFenceFeatureFlagBits: uint32_t {
    Exportable = 1,
    Importable = 2,
};
enum class FenceImportFlagBits: uint32_t {
    Temporary = 1,
};
enum class SurfaceCounterFlagBitsEXT: uint32_t {
    VblankEXT = 1,
};
enum class PeerMemoryFeatureFlagBits: uint32_t {
    CopySrc = 1,
    CopyDst = 2,
    GenericSrc = 4,
    GenericDst = 8,
};
enum class MemoryAllocateFlagBits: uint32_t {
    DeviceMask = 1,
    DeviceAddress = 2,
    DeviceAddressCaptureReplay = 4,
};
enum class DeviceGroupPresentModeFlagBitsKHR: uint32_t {
    LocalKHR = 1,
    RemoteKHR = 2,
    SumKHR = 4,
    LocalMultiDeviceKHR = 8,
};
enum class SwapchainCreateFlagBitsKHR: uint32_t {
    SplitInstanceBindRegionsKHR = 1,
    ProtectedKHR = 2,
    MutableFormatKHR = 4,
    DeferredMemoryAllocationEXT = 8,
};
enum class SubpassDescriptionFlagBits: uint32_t {
    PerViewAttributesNVX = 1,
    PerViewPositionXOnlyNVX = 2,
    FragmentRegionQCOM = 4,
    ShaderResolveQCOM = 8,
    RasterizationOrderAttachmentColorAccessEXT = 16,
    RasterizationOrderAttachmentDepthAccessEXT = 32,
    RasterizationOrderAttachmentStencilAccessEXT = 64,
    EnableLegacyDitheringEXT = 128,
};
enum class DebugUtilsMessageSeverityFlagBitsEXT: uint32_t {
    VerboseEXT = 1,
    InfoEXT = 16,
    WarningEXT = 256,
    ErrorEXT = 4096,
};
enum class DebugUtilsMessageTypeFlagBitsEXT: uint32_t {
    GeneralEXT = 1,
    ValidationEXT = 2,
    PerformanceEXT = 4,
    DeviceAddressBindingEXT = 8,
};
enum class DescriptorBindingFlagBits: uint32_t {
    UpdateAfterBind = 1,
    UpdateUnusedWhilePending = 2,
    PartiallyBound = 4,
    VariableDescriptorCount = 8,
};
enum class ConditionalRenderingFlagBitsEXT: uint32_t {
    InvertedEXT = 1,
};
enum class ResolveModeFlagBits: uint32_t {
    None = 0,
    SampleZero = 1,
    Average = 2,
    Min = 4,
    Max = 8,
    ExternalFormatDownsampleANDROID = 16,
};
enum class GeometryInstanceFlagBitsKHR: uint32_t {
    TriangleFacingCullDisableKHR = 1,
    TriangleFlipFacingKHR = 2,
    ForceOpaqueKHR = 4,
    ForceNoOpaqueKHR = 8,
    TriangleFrontCounterclockwiseKHR = TriangleFlipFacingKHR,
    ForceOpacityMicromap2StateEXT = 16,
    DisableOpacityMicromapsEXT = 32,
};
enum class GeometryFlagBitsKHR: uint32_t {
    OpaqueKHR = 1,
    NoDuplicateAnyHitInvocationKHR = 2,
};
enum class BuildAccelerationStructureFlagBitsKHR: uint32_t {
    AllowUpdateKHR = 1,
    AllowCompactionKHR = 2,
    PreferFastTraceKHR = 4,
    PreferFastBuildKHR = 8,
    LowMemoryKHR = 16,
    MotionNV = 32,
    AllowOpacityMicromapUpdateEXT = 64,
    AllowDisableOpacityMicromapsEXT = 128,
    AllowOpacityMicromapDataUpdateEXT = 256,
    AllowDisplacementMicromapUpdateNV = 512,
    AllowDataAccessKHR = 2048,
};
enum class AccelerationStructureCreateFlagBitsKHR: uint32_t {
    DeviceAddressCaptureReplayKHR = 1,
    DescriptorBufferCaptureReplayEXT = 8,
    MotionNV = 4,
};
enum class FramebufferCreateFlagBits: uint32_t {
    Imageless = 1,
};
enum class DeviceDiagnosticsConfigFlagBitsNV: uint32_t {
    EnableShaderDebugInfoNV = 1,
    EnableResourceTrackingNV = 2,
    EnableAutomaticCheckpointsNV = 4,
    EnableShaderErrorReportingNV = 8,
};
enum class PipelineCreationFeedbackFlagBits: uint32_t {
    Valid = 1,
    ValidEXT = Valid,
    ApplicationPipelineCacheHit = 2,
    ApplicationPipelineCacheHitEXT = ApplicationPipelineCacheHit,
    BasePipelineAcceleration = 4,
    BasePipelineAccelerationEXT = BasePipelineAcceleration,
};
enum class MemoryDecompressionMethodFlagBitsNV: uint64_t {
    Gdeflate10NV = 1,
};
enum class PerformanceCounterDescriptionFlagBitsKHR: uint32_t {
    PerformanceImpactingKHR = 1,
    ConcurrentlyImpactedKHR = 2,
};
enum class AcquireProfilingLockFlagBitsKHR: uint32_t {
};
enum class ShaderCorePropertiesFlagBitsAMD: uint32_t {
};
enum class PipelineCompilerControlFlagBitsAMD: uint32_t {
};
enum class ToolPurposeFlagBits: uint32_t {
    Validation = 1,
    ValidationEXT = Validation,
    Profiling = 2,
    ProfilingEXT = Profiling,
    Tracing = 4,
    TracingEXT = Tracing,
    AdditionalFeatures = 8,
    AdditionalFeaturesEXT = AdditionalFeatures,
    ModifyingFeatures = 16,
    ModifyingFeaturesEXT = ModifyingFeatures,
    DebugReportingEXT = 32,
    DebugMarkersEXT = 64,
};
enum class AccessFlagBits2: uint64_t {
    Access2None = 0,
    Access2NoneKHR = Access2None,
    Access2IndirectCommandRead = 1,
    Access2IndirectCommandReadKHR = Access2IndirectCommandRead,
    Access2IndexRead = 2,
    Access2IndexReadKHR = Access2IndexRead,
    Access2VertexAttributeRead = 4,
    Access2VertexAttributeReadKHR = Access2VertexAttributeRead,
    Access2UniformRead = 8,
    Access2UniformReadKHR = Access2UniformRead,
    Access2InputAttachmentRead = 16,
    Access2InputAttachmentReadKHR = Access2InputAttachmentRead,
    Access2ShaderRead = 32,
    Access2ShaderReadKHR = Access2ShaderRead,
    Access2ShaderWrite = 64,
    Access2ShaderWriteKHR = Access2ShaderWrite,
    Access2ColorAttachmentRead = 128,
    Access2ColorAttachmentReadKHR = Access2ColorAttachmentRead,
    Access2ColorAttachmentWrite = 256,
    Access2ColorAttachmentWriteKHR = Access2ColorAttachmentWrite,
    Access2DepthStencilAttachmentRead = 512,
    Access2DepthStencilAttachmentReadKHR = Access2DepthStencilAttachmentRead,
    Access2DepthStencilAttachmentWrite = 1024,
    Access2DepthStencilAttachmentWriteKHR = Access2DepthStencilAttachmentWrite,
    Access2TransferRead = 2048,
    Access2TransferReadKHR = Access2TransferRead,
    Access2TransferWrite = 4096,
    Access2TransferWriteKHR = Access2TransferWrite,
    Access2HostRead = 8192,
    Access2HostReadKHR = Access2HostRead,
    Access2HostWrite = 16384,
    Access2HostWriteKHR = Access2HostWrite,
    Access2MemoryRead = 32768,
    Access2MemoryReadKHR = Access2MemoryRead,
    Access2MemoryWrite = 65536,
    Access2MemoryWriteKHR = Access2MemoryWrite,
    Access2ShaderSampledRead = 4294967296,
    Access2ShaderSampledReadKHR = Access2ShaderSampledRead,
    Access2ShaderStorageRead = 8589934592,
    Access2ShaderStorageReadKHR = Access2ShaderStorageRead,
    Access2ShaderStorageWrite = 17179869184,
    Access2ShaderStorageWriteKHR = Access2ShaderStorageWrite,
    Access2VideoDecodeReadKHR = 34359738368,
    Access2VideoDecodeWriteKHR = 68719476736,
    Access2VideoEncodeReadKHR = 137438953472,
    Access2VideoEncodeWriteKHR = 274877906944,
    Access2TransformFeedbackWriteEXT = 33554432,
    Access2TransformFeedbackCounterReadEXT = 67108864,
    Access2TransformFeedbackCounterWriteEXT = 134217728,
    Access2ConditionalRenderingReadEXT = 1048576,
    Access2CommandPreprocessReadNV = 131072,
    Access2CommandPreprocessWriteNV = 262144,
    Access2FragmentShadingRateAttachmentReadKHR = 8388608,
    Access2AccelerationStructureReadKHR = 2097152,
    Access2AccelerationStructureWriteKHR = 4194304,
    Access2FragmentDensityMapReadEXT = 16777216,
    Access2ColorAttachmentReadNoncoherentEXT = 524288,
    Access2DescriptorBufferReadEXT = 2199023255552,
    Access2InvocationMaskReadHUAWEI = 549755813888,
    Access2ShaderBindingTableReadKHR = 1099511627776,
    Access2MicromapReadEXT = 17592186044416,
    Access2MicromapWriteEXT = 35184372088832,
    Access2OpticalFlowReadNV = 4398046511104,
    Access2OpticalFlowWriteNV = 8796093022208,
};
enum class PipelineStageFlagBits2: uint64_t {
    PipelineStage2None = 0,
    PipelineStage2NoneKHR = PipelineStage2None,
    PipelineStage2TopOfPipe = 1,
    PipelineStage2TopOfPipeKHR = PipelineStage2TopOfPipe,
    PipelineStage2DrawIndirect = 2,
    PipelineStage2DrawIndirectKHR = PipelineStage2DrawIndirect,
    PipelineStage2VertexInput = 4,
    PipelineStage2VertexInputKHR = PipelineStage2VertexInput,
    PipelineStage2VertexShader = 8,
    PipelineStage2VertexShaderKHR = PipelineStage2VertexShader,
    PipelineStage2TessellationControlShader = 16,
    PipelineStage2TessellationControlShaderKHR = PipelineStage2TessellationControlShader,
    PipelineStage2TessellationEvaluationShader = 32,
    PipelineStage2TessellationEvaluationShaderKHR = PipelineStage2TessellationEvaluationShader,
    PipelineStage2GeometryShader = 64,
    PipelineStage2GeometryShaderKHR = PipelineStage2GeometryShader,
    PipelineStage2FragmentShader = 128,
    PipelineStage2FragmentShaderKHR = PipelineStage2FragmentShader,
    PipelineStage2EarlyFragmentTests = 256,
    PipelineStage2EarlyFragmentTestsKHR = PipelineStage2EarlyFragmentTests,
    PipelineStage2LateFragmentTests = 512,
    PipelineStage2LateFragmentTestsKHR = PipelineStage2LateFragmentTests,
    PipelineStage2ColorAttachmentOutput = 1024,
    PipelineStage2ColorAttachmentOutputKHR = PipelineStage2ColorAttachmentOutput,
    PipelineStage2ComputeShader = 2048,
    PipelineStage2ComputeShaderKHR = PipelineStage2ComputeShader,
    PipelineStage2AllTransfer = 4096,
    PipelineStage2AllTransferKHR = PipelineStage2AllTransfer,
    PipelineStage2Transfer = PipelineStage2AllTransferKHR,
    PipelineStage2TransferKHR = PipelineStage2AllTransfer,
    PipelineStage2BottomOfPipe = 8192,
    PipelineStage2BottomOfPipeKHR = PipelineStage2BottomOfPipe,
    PipelineStage2Host = 16384,
    PipelineStage2HostKHR = PipelineStage2Host,
    PipelineStage2AllGraphics = 32768,
    PipelineStage2AllGraphicsKHR = PipelineStage2AllGraphics,
    PipelineStage2AllCommands = 65536,
    PipelineStage2AllCommandsKHR = PipelineStage2AllCommands,
    PipelineStage2Copy = 4294967296,
    PipelineStage2CopyKHR = PipelineStage2Copy,
    PipelineStage2Resolve = 8589934592,
    PipelineStage2ResolveKHR = PipelineStage2Resolve,
    PipelineStage2Blit = 17179869184,
    PipelineStage2BlitKHR = PipelineStage2Blit,
    PipelineStage2Clear = 34359738368,
    PipelineStage2ClearKHR = PipelineStage2Clear,
    PipelineStage2IndexInput = 68719476736,
    PipelineStage2IndexInputKHR = PipelineStage2IndexInput,
    PipelineStage2VertexAttributeInput = 137438953472,
    PipelineStage2VertexAttributeInputKHR = PipelineStage2VertexAttributeInput,
    PipelineStage2PreRasterizationShaders = 274877906944,
    PipelineStage2PreRasterizationShadersKHR = PipelineStage2PreRasterizationShaders,
    PipelineStage2VideoDecodeKHR = 67108864,
    PipelineStage2VideoEncodeKHR = 134217728,
    PipelineStage2TransformFeedbackEXT = 16777216,
    PipelineStage2ConditionalRenderingEXT = 262144,
    PipelineStage2CommandPreprocessNV = 131072,
    PipelineStage2FragmentShadingRateAttachmentKHR = 4194304,
    PipelineStage2AccelerationStructureBuildKHR = 33554432,
    PipelineStage2RayTracingShaderKHR = 2097152,
    PipelineStage2FragmentDensityProcessEXT = 8388608,
    PipelineStage2TaskShaderEXT = 524288,
    PipelineStage2MeshShaderEXT = 1048576,
    PipelineStage2SubpassShaderHUAWEI = 549755813888,
    PipelineStage2InvocationMaskHUAWEI = 1099511627776,
    PipelineStage2AccelerationStructureCopyKHR = 268435456,
    PipelineStage2MicromapBuildEXT = 1073741824,
    PipelineStage2ClusterCullingShaderHUAWEI = 2199023255552,
    PipelineStage2OpticalFlowNV = 536870912,
};
enum class SubmitFlagBits: uint32_t {
    Protected = 1,
    ProtectedKHR = Protected,
};
enum class EventCreateFlagBits: uint32_t {
    DeviceOnly = 1,
};
enum class PipelineLayoutCreateFlagBits: uint32_t {
    IndependentSetsEXT = 2,
};
enum class PipelineColorBlendStateCreateFlagBits: uint32_t {
    RasterizationOrderAttachmentAccessEXT = 1,
};
enum class PipelineDepthStencilStateCreateFlagBits: uint32_t {
    RasterizationOrderAttachmentDepthAccessEXT = 1,
    RasterizationOrderAttachmentStencilAccessEXT = 2,
};
enum class GraphicsPipelineLibraryFlagBitsEXT: uint32_t {
    VertexInputInterfaceEXT = 1,
    PreRasterizationShadersEXT = 2,
    FragmentShaderEXT = 4,
    FragmentOutputInterfaceEXT = 8,
};
enum class DeviceAddressBindingFlagBitsEXT: uint32_t {
    InternalObjectEXT = 1,
};
enum class FrameBoundaryFlagBitsEXT: uint32_t {
    FrameEndEXT = 1,
};
enum class PresentScalingFlagBitsEXT: uint32_t {
    OneToOneEXT = 1,
    AspectRatioStretchEXT = 2,
    StretchEXT = 4,
};
enum class PresentGravityFlagBitsEXT: uint32_t {
    MinEXT = 1,
    MaxEXT = 2,
    CenteredEXT = 4,
};
enum class PhysicalDeviceSchedulingControlsFlagBitsARM: uint64_t {
    ShaderCoreCountARM = 1,
};
enum class VideoCodecOperationFlagBitsKHR: uint32_t {
    NoneKHR = 0,
    EncodeH264KHR = 65536,
    EncodeH265KHR = 131072,
    DecodeH264KHR = 1,
    DecodeH265KHR = 2,
    DecodeAv1KHR = 4,
};
enum class VideoChromaSubsamplingFlagBitsKHR: uint32_t {
    InvalidKHR = 0,
    MonochromeKHR = 1,
    e420KHR = 2,
    e422KHR = 4,
    e444KHR = 8,
};
enum class VideoComponentBitDepthFlagBitsKHR: uint32_t {
    InvalidKHR = 0,
    e8KHR = 1,
    e10KHR = 4,
    e12KHR = 16,
};
enum class VideoCapabilityFlagBitsKHR: uint32_t {
    ProtectedContentKHR = 1,
    SeparateReferenceImagesKHR = 2,
};
enum class VideoSessionCreateFlagBitsKHR: uint32_t {
    ProtectedContentKHR = 1,
    AllowEncodeParameterOptimizationsKHR = 2,
    InlineQueriesKHR = 4,
};
enum class VideoDecodeH264PictureLayoutFlagBitsKHR: uint32_t {
    ProgressiveKHR = 0,
    InterlacedInterleavedLinesKHR = 1,
    InterlacedSeparatePlanesKHR = 2,
};
enum class VideoCodingControlFlagBitsKHR: uint32_t {
    ResetKHR = 1,
    EncodeRateControlKHR = 2,
    EncodeQualityLevelKHR = 4,
};
enum class VideoDecodeUsageFlagBitsKHR: uint32_t {
    DefaultKHR = 0,
    TranscodingKHR = 1,
    OfflineKHR = 2,
    StreamingKHR = 4,
};
enum class VideoDecodeCapabilityFlagBitsKHR: uint32_t {
    DpbAndOutputCoincideKHR = 1,
    DpbAndOutputDistinctKHR = 2,
};
enum class VideoEncodeUsageFlagBitsKHR: uint32_t {
    DefaultKHR = 0,
    TranscodingKHR = 1,
    StreamingKHR = 2,
    RecordingKHR = 4,
    ConferencingKHR = 8,
};
enum class VideoEncodeContentFlagBitsKHR: uint32_t {
    DefaultKHR = 0,
    CameraKHR = 1,
    DesktopKHR = 2,
    RenderedKHR = 4,
};
enum class VideoEncodeCapabilityFlagBitsKHR: uint32_t {
    PrecedingExternallyEncodedBytesKHR = 1,
    InsufficientstreamBufferRangeDetectionKHR = 2,
};
enum class VideoEncodeFeedbackFlagBitsKHR: uint32_t {
    streamBufferOffsetKHR = 1,
    streamBytesWrittenKHR = 2,
    streamHasOverridesKHR = 4,
};
enum class VideoEncodeRateControlModeFlagBitsKHR: uint32_t {
    DefaultKHR = 0,
    DisabledKHR = 1,
    CbrKHR = 2,
    VbrKHR = 4,
};
enum class VideoEncodeH264CapabilityFlagBitsKHR: uint32_t {
    HrdComplianceKHR = 1,
    PredictionWeightTableGeneratedKHR = 2,
    RowUnalignedSliceKHR = 4,
    DifferentSliceTypeKHR = 8,
    BFrameInL0ListKHR = 16,
    BFrameInL1ListKHR = 32,
    PerPictureTypeMinMaxQpKHR = 64,
    PerSliceConstantQpKHR = 128,
    GeneratePrefixNaluKHR = 256,
};
enum class VideoEncodeH264StdFlagBitsKHR: uint32_t {
    SeparateColorPlaneFlagSetKHR = 1,
    QpprimeYZeroTransformBypassFlagSetKHR = 2,
    ScalingMatrixPresentFlagSetKHR = 4,
    ChromaQpIndexOffsetKHR = 8,
    SecondChromaQpIndexOffsetKHR = 16,
    PicInitQpMinus26KHR = 32,
    WeightedPredFlagSetKHR = 64,
    WeightedBipredIdcExplicitKHR = 128,
    WeightedBipredIdcImplicitKHR = 256,
    Transform8X8ModeFlagSetKHR = 512,
    DirectSpatialMvPredFlagUnsetKHR = 1024,
    EntropyCodingModeFlagUnsetKHR = 2048,
    EntropyCodingModeFlagSetKHR = 4096,
    Direct8X8InferenceFlagUnsetKHR = 8192,
    ConstrainedIntraPredFlagSetKHR = 16384,
    DeblockingFilterDisabledKHR = 32768,
    DeblockingFilterEnabledKHR = 65536,
    DeblockingFilterPartialKHR = 131072,
    SliceQpDeltaKHR = 524288,
    DifferentSliceQpDeltaKHR = 1048576,
};
enum class VideoEncodeH264RateControlFlagBitsKHR: uint32_t {
    AttemptHrdComplianceKHR = 1,
    RegularGopKHR = 2,
    ReferencePatternFlatKHR = 4,
    ReferencePatternDyadicKHR = 8,
    TemporalLayerPatternDyadicKHR = 16,
};
enum class HostImageCopyFlagBitsEXT: uint32_t {
    MemcpyEXT = 1,
};
#if defined(VK_USE_PLATFORM_FUCHSIA)
enum class ImageConstraintsInfoFlagBitsFUCHSIA: uint32_t {
    CpuReadRarelyFUCHSIA = 1,
    CpuReadOftenFUCHSIA = 2,
    CpuWriteRarelyFUCHSIA = 4,
    CpuWriteOftenFUCHSIA = 8,
    ProtectedOptionalFUCHSIA = 16,
};
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
enum class FormatFeatureFlagBits2: uint64_t {
    FormatFeature2SampledImage = 1,
    FormatFeature2SampledImageKHR = FormatFeature2SampledImage,
    FormatFeature2StorageImage = 2,
    FormatFeature2StorageImageKHR = FormatFeature2StorageImage,
    FormatFeature2StorageImageAtomic = 4,
    FormatFeature2StorageImageAtomicKHR = FormatFeature2StorageImageAtomic,
    FormatFeature2UniformTexelBuffer = 8,
    FormatFeature2UniformTexelBufferKHR = FormatFeature2UniformTexelBuffer,
    FormatFeature2StorageTexelBuffer = 16,
    FormatFeature2StorageTexelBufferKHR = FormatFeature2StorageTexelBuffer,
    FormatFeature2StorageTexelBufferAtomic = 32,
    FormatFeature2StorageTexelBufferAtomicKHR = FormatFeature2StorageTexelBufferAtomic,
    FormatFeature2VertexBuffer = 64,
    FormatFeature2VertexBufferKHR = FormatFeature2VertexBuffer,
    FormatFeature2ColorAttachment = 128,
    FormatFeature2ColorAttachmentKHR = FormatFeature2ColorAttachment,
    FormatFeature2ColorAttachmentBlend = 256,
    FormatFeature2ColorAttachmentBlendKHR = FormatFeature2ColorAttachmentBlend,
    FormatFeature2DepthStencilAttachment = 512,
    FormatFeature2DepthStencilAttachmentKHR = FormatFeature2DepthStencilAttachment,
    FormatFeature2BlitSrc = 1024,
    FormatFeature2BlitSrcKHR = FormatFeature2BlitSrc,
    FormatFeature2BlitDst = 2048,
    FormatFeature2BlitDstKHR = FormatFeature2BlitDst,
    FormatFeature2SampledImageFilterLinear = 4096,
    FormatFeature2SampledImageFilterLinearKHR = FormatFeature2SampledImageFilterLinear,
    FormatFeature2SampledImageFilterCubic = 8192,
    FormatFeature2SampledImageFilterCubicEXT = FormatFeature2SampledImageFilterCubic,
    FormatFeature2TransferSrc = 16384,
    FormatFeature2TransferSrcKHR = FormatFeature2TransferSrc,
    FormatFeature2TransferDst = 32768,
    FormatFeature2TransferDstKHR = FormatFeature2TransferDst,
    FormatFeature2SampledImageFilterMinmax = 65536,
    FormatFeature2SampledImageFilterMinmaxKHR = FormatFeature2SampledImageFilterMinmax,
    FormatFeature2MidpointChromaSamples = 131072,
    FormatFeature2MidpointChromaSamplesKHR = FormatFeature2MidpointChromaSamples,
    FormatFeature2SampledImageYcbcrConversionLinearFilter = 262144,
    FormatFeature2SampledImageYcbcrConversionLinearFilterKHR = FormatFeature2SampledImageYcbcrConversionLinearFilter,
    FormatFeature2SampledImageYcbcrConversionSeparateReconstructionFilter = 524288,
    FormatFeature2SampledImageYcbcrConversionSeparateReconstructionFilterKHR = FormatFeature2SampledImageYcbcrConversionSeparateReconstructionFilter,
    FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicit = 1048576,
    FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicitKHR = FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicit,
    FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicitForceable = 2097152,
    FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicitForceableKHR = FormatFeature2SampledImageYcbcrConversionChromaReconstructionExplicitForceable,
    FormatFeature2Disjoint = 4194304,
    FormatFeature2DisjointKHR = FormatFeature2Disjoint,
    FormatFeature2CositedChromaSamples = 8388608,
    FormatFeature2CositedChromaSamplesKHR = FormatFeature2CositedChromaSamples,
    FormatFeature2StorageReadWithoutFormat = 2147483648,
    FormatFeature2StorageReadWithoutFormatKHR = FormatFeature2StorageReadWithoutFormat,
    FormatFeature2StorageWriteWithoutFormat = 4294967296,
    FormatFeature2StorageWriteWithoutFormatKHR = FormatFeature2StorageWriteWithoutFormat,
    FormatFeature2SampledImageDepthComparison = 8589934592,
    FormatFeature2SampledImageDepthComparisonKHR = FormatFeature2SampledImageDepthComparison,
    FormatFeature2VideoDecodeOutputKHR = 33554432,
    FormatFeature2VideoDecodeDpbKHR = 67108864,
    FormatFeature2AccelerationStructureVertexBufferKHR = 536870912,
    FormatFeature2FragmentDensityMapEXT = 16777216,
    FormatFeature2FragmentShadingRateAttachmentKHR = 1073741824,
    FormatFeature2HostImageTransferEXT = 70368744177664,
    FormatFeature2VideoEncodeInputKHR = 134217728,
    FormatFeature2VideoEncodeDpbKHR = 268435456,
    FormatFeature2LinearColorAttachmentNV = 274877906944,
    FormatFeature2WeightImageQCOM = 17179869184,
    FormatFeature2WeightSampledImageQCOM = 34359738368,
    FormatFeature2BlockMatchingQCOM = 68719476736,
    FormatFeature2BoxFilterSampledQCOM = 137438953472,
    FormatFeature2OpticalFlowImageNV = 1099511627776,
    FormatFeature2OpticalFlowVectorNV = 2199023255552,
    FormatFeature2OpticalFlowCostNV = 4398046511104,
};
enum class RenderingFlagBits: uint32_t {
    ContentsSecondaryCommandBuffers = 1,
    ContentsSecondaryCommandBuffersKHR = ContentsSecondaryCommandBuffers,
    Suspending = 2,
    SuspendingKHR = Suspending,
    Resuming = 4,
    ResumingKHR = Resuming,
    ContentsInlineEXT = 16,
    EnableLegacyDitheringEXT = 8,
};
enum class VideoEncodeH265CapabilityFlagBitsKHR: uint32_t {
    HrdComplianceKHR = 1,
    PredictionWeightTableGeneratedKHR = 2,
    RowUnalignedSliceSegmentKHR = 4,
    DifferentSliceSegmentTypeKHR = 8,
    BFrameInL0ListKHR = 16,
    BFrameInL1ListKHR = 32,
    PerPictureTypeMinMaxQpKHR = 64,
    PerSliceSegmentConstantQpKHR = 128,
    MultipleTilesPerSliceSegmentKHR = 256,
    MultipleSliceSegmentsPerTileKHR = 512,
};
enum class VideoEncodeH265StdFlagBitsKHR: uint32_t {
    SeparateColorPlaneFlagSetKHR = 1,
    SampleAdaptiveOffsetEnabledFlagSetKHR = 2,
    ScalingListDataPresentFlagSetKHR = 4,
    PcmEnabledFlagSetKHR = 8,
    SpsTemporalMvpEnabledFlagSetKHR = 16,
    InitQpMinus26KHR = 32,
    WeightedPredFlagSetKHR = 64,
    WeightedBipredFlagSetKHR = 128,
    Log2ParallelMergeLevelMinus2KHR = 256,
    SignDataHidingEnabledFlagSetKHR = 512,
    TransformSkipEnabledFlagSetKHR = 1024,
    TransformSkipEnabledFlagUnsetKHR = 2048,
    PpsSliceChromaQpOffsetsPresentFlagSetKHR = 4096,
    TransquantBypassEnabledFlagSetKHR = 8192,
    ConstrainedIntraPredFlagSetKHR = 16384,
    EntropyCodingSyncEnabledFlagSetKHR = 32768,
    DeblockingFilterOverrideEnabledFlagSetKHR = 65536,
    DependentSliceSegmentsEnabledFlagSetKHR = 131072,
    DependentSliceSegmentFlagSetKHR = 262144,
    SliceQpDeltaKHR = 524288,
    DifferentSliceQpDeltaKHR = 1048576,
};
enum class VideoEncodeH265RateControlFlagBitsKHR: uint32_t {
    AttemptHrdComplianceKHR = 1,
    RegularGopKHR = 2,
    ReferencePatternFlatKHR = 4,
    ReferencePatternDyadicKHR = 8,
    TemporalSubLayerPatternDyadicKHR = 16,
};
enum class VideoEncodeH265CtbSizeFlagBitsKHR: uint32_t {
    e16KHR = 1,
    e32KHR = 2,
    e64KHR = 4,
};
enum class VideoEncodeH265TransformBlockSizeFlagBitsKHR: uint32_t {
    e4KHR = 1,
    e8KHR = 2,
    e16KHR = 4,
    e32KHR = 8,
};
#if defined(VK_USE_PLATFORM_METAL_EXT)
enum class ExportMetalObjectTypeFlagBitsEXT: uint32_t {
    MetalDeviceEXT = 1,
    MetalCommandQueueEXT = 2,
    MetalBufferEXT = 4,
    MetalTextureEXT = 8,
    MetalIosurfaceEXT = 16,
    MetalSharedEventEXT = 32,
};
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
enum class InstanceCreateFlagBits: uint32_t {
    EnumeratePortabilityKHR = 1,
};
enum class ImageCompressionFlagBitsEXT: uint32_t {
    DefaultEXT = 0,
    FixedRateDefaultEXT = 1,
    FixedRateExplicitEXT = 2,
    DisabledEXT = 4,
};
enum class ImageCompressionFixedRateFlagBitsEXT: uint32_t {
    NoneEXT = 0,
    e1BpcEXT = 1,
    e2BpcEXT = 2,
    e3BpcEXT = 4,
    e4BpcEXT = 8,
    e5BpcEXT = 16,
    e6BpcEXT = 32,
    e7BpcEXT = 64,
    e8BpcEXT = 128,
    e9BpcEXT = 256,
    e10BpcEXT = 512,
    e11BpcEXT = 1024,
    e12BpcEXT = 2048,
    e13BpcEXT = 4096,
    e14BpcEXT = 8192,
    e15BpcEXT = 16384,
    e16BpcEXT = 32768,
    e17BpcEXT = 65536,
    e18BpcEXT = 131072,
    e19BpcEXT = 262144,
    e20BpcEXT = 524288,
    e21BpcEXT = 1048576,
    e22BpcEXT = 2097152,
    e23BpcEXT = 4194304,
    e24BpcEXT = 8388608,
};
enum class OpticalFlowGridSizeFlagBitsNV: uint32_t {
    UnknownNV = 0,
    e1X1NV = 1,
    e2X2NV = 2,
    e4X4NV = 4,
    e8X8NV = 8,
};
enum class OpticalFlowUsageFlagBitsNV: uint32_t {
    UnknownNV = 0,
    InputNV = 1,
    OutputNV = 2,
    HintNV = 4,
    CostNV = 8,
    GlobalFlowNV = 16,
};
enum class OpticalFlowSessionCreateFlagBitsNV: uint32_t {
    EnableHintNV = 1,
    EnableCostNV = 2,
    EnableGlobalFlowNV = 4,
    AllowRegionsNV = 8,
    BothDirectionsNV = 16,
};
enum class OpticalFlowExecuteFlagBitsNV: uint32_t {
    DisableTemporalHintsNV = 1,
};
enum class BuildMicromapFlagBitsEXT: uint32_t {
    PreferFastTraceEXT = 1,
    PreferFastBuildEXT = 2,
    AllowCompactionEXT = 4,
};
enum class MicromapCreateFlagBitsEXT: uint32_t {
    DeviceAddressCaptureReplayEXT = 1,
};
enum class ShaderCreateFlagBitsEXT: uint32_t {
    LinkStageEXT = 1,
    AllowVaryingSubgroupSizeEXT = 2,
    RequireFullSubgroupsEXT = 4,
    NoTaskShaderEXT = 8,
    DispatchBaseEXT = 16,
    FragmentShadingRateAttachmentEXT = 32,
    FragmentDensityMapAttachmentEXT = 64,
};
enum class QueryPoolCreateFlagBits: uint32_t { };
enum class PipelineDynamicStateCreateFlagBits: uint32_t { };
enum class PipelineMultisampleStateCreateFlagBits: uint32_t { };
enum class PipelineRasterizationStateCreateFlagBits: uint32_t { };
enum class PipelineViewportStateCreateFlagBits: uint32_t { };
enum class PipelineTessellationStateCreateFlagBits: uint32_t { };
enum class PipelineInputAssemblyStateCreateFlagBits: uint32_t { };
enum class PipelineVertexInputStateCreateFlagBits: uint32_t { };
enum class BufferViewCreateFlagBits: uint32_t { };
enum class DeviceCreateFlagBits: uint32_t { };
enum class SemaphoreCreateFlagBits: uint32_t { };
enum class ShaderModuleCreateFlagBits: uint32_t { };
enum class MemoryMapFlagBits: uint32_t { };
enum class MemoryUnmapFlagBitsKHR: uint32_t { };
enum class DescriptorPoolResetFlagBits: uint32_t { };
enum class PrivateDataSlotCreateFlagBits: uint32_t { };
enum class DescriptorUpdateTemplateCreateFlagBits: uint32_t { };
enum class AccelerationStructureMotionInfoFlagBitsNV: uint32_t { };
enum class AccelerationStructureMotionInstanceFlagBitsNV: uint32_t { };
enum class DirectDriverLoadingFlagBitsLUNARG: uint32_t { };
enum class DisplayModeCreateFlagBitsKHR: uint32_t { };
enum class DisplaySurfaceCreateFlagBitsKHR: uint32_t { };
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
enum class AndroidSurfaceCreateFlagBitsKHR: uint32_t { };
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
#if defined(VK_USE_PLATFORM_VI_NN)
enum class ViSurfaceCreateFlagBitsNN: uint32_t { };
#endif // defined(VK_USE_PLATFORM_VI_NN)
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
enum class WaylandSurfaceCreateFlagBitsKHR: uint32_t { };
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
enum class Win32SurfaceCreateFlagBitsKHR: uint32_t { };
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_XLIB_KHR)
enum class XlibSurfaceCreateFlagBitsKHR: uint32_t { };
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
enum class XcbSurfaceCreateFlagBitsKHR: uint32_t { };
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
enum class DirectFBSurfaceCreateFlagBitsEXT: uint32_t { };
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#if defined(VK_USE_PLATFORM_IOS_MVK)
enum class IOSSurfaceCreateFlagBitsMVK: uint32_t { };
#endif // defined(VK_USE_PLATFORM_IOS_MVK)
#if defined(VK_USE_PLATFORM_MACOS_MVK)
enum class MacOSSurfaceCreateFlagBitsMVK: uint32_t { };
#endif // defined(VK_USE_PLATFORM_MACOS_MVK)
#if defined(VK_USE_PLATFORM_METAL_EXT)
enum class MetalSurfaceCreateFlagBitsEXT: uint32_t { };
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
#if defined(VK_USE_PLATFORM_FUCHSIA)
enum class ImagePipeSurfaceCreateFlagBitsFUCHSIA: uint32_t { };
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_GGP)
enum class StreamDescriptorSurfaceCreateFlagBitsGGP: uint32_t { };
#endif // defined(VK_USE_PLATFORM_GGP)
enum class HeadlessSurfaceCreateFlagBitsEXT: uint32_t { };
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
enum class ScreenSurfaceCreateFlagBitsQNX: uint32_t { };
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
enum class CommandPoolTrimFlagBits: uint32_t { };
enum class PipelineViewportSwizzleStateCreateFlagBitsNV: uint32_t { };
enum class PipelineDiscardRectangleStateCreateFlagBitsEXT: uint32_t { };
enum class PipelineCoverageToColorStateCreateFlagBitsNV: uint32_t { };
enum class PipelineCoverageModulationStateCreateFlagBitsNV: uint32_t { };
enum class PipelineCoverageReductionStateCreateFlagBitsNV: uint32_t { };
enum class ValidationCacheCreateFlagBitsEXT: uint32_t { };
enum class DebugUtilsMessengerCreateFlagBitsEXT: uint32_t { };
enum class DebugUtilsMessengerCallbackDataFlagBitsEXT: uint32_t { };
enum class DeviceMemoryReportFlagBitsEXT: uint32_t { };
enum class PipelineRasterizationConservativeStateCreateFlagBitsEXT: uint32_t { };
enum class PipelineRasterizationStateStreamCreateFlagBitsEXT: uint32_t { };
enum class PipelineRasterizationDepthClipStateCreateFlagBitsEXT: uint32_t { };
#if defined(VK_USE_PLATFORM_FUCHSIA)
enum class ImageFormatConstraintsFlagBitsFUCHSIA: uint32_t { };
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
enum class VideoSessionParametersCreateFlagBitsKHR: uint32_t { };
enum class VideoBeginCodingFlagBitsKHR: uint32_t { };
enum class VideoEndCodingFlagBitsKHR: uint32_t { };
enum class VideoDecodeFlagBitsKHR: uint32_t { };
enum class VideoEncodeFlagBitsKHR: uint32_t { };
enum class VideoEncodeRateControlFlagBitsKHR: uint32_t { };

#define DECLARE_ENUM_FLAG_OPERATORS(FLAG_TYPE, FLAG_BITS, BASE_TYPE)                       \
                                                                                           \
struct FLAG_TYPE {                                                                         \
    BASE_TYPE flags = static_cast<BASE_TYPE>(0);                                           \
                                                                                           \
    constexpr FLAG_TYPE() noexcept = default;                                              \
    constexpr FLAG_TYPE(BASE_TYPE in) noexcept: flags(in){ }                      \
    constexpr FLAG_TYPE(FLAG_BITS in) noexcept: flags(static_cast<BASE_TYPE>(in)){ }       \
    constexpr bool operator==(FLAG_TYPE const& right) const { return flags == right.flags;}\
    constexpr bool operator!=(FLAG_TYPE const& right) const { return flags != right.flags;}\
    constexpr explicit operator BASE_TYPE() const { return flags;}                         \
    constexpr explicit operator bool() const noexcept {                                    \
      return flags != 0;                                                                   \
    }                                                                                      \
};                                                                                         \
constexpr FLAG_TYPE operator|(FLAG_TYPE a, FLAG_TYPE b) noexcept {                         \
    return static_cast<FLAG_TYPE>(a.flags | b.flags);                                      \
}                                                                                          \
constexpr FLAG_TYPE operator&(FLAG_TYPE a, FLAG_TYPE b) noexcept {                         \
    return static_cast<FLAG_TYPE>(a.flags & b.flags);                                      \
}                                                                                          \
constexpr FLAG_TYPE operator^(FLAG_TYPE a, FLAG_TYPE b) noexcept {                         \
    return static_cast<FLAG_TYPE>(a.flags ^ b.flags);                                      \
}                                                                                          \
constexpr FLAG_TYPE operator~(FLAG_TYPE a) noexcept {                                      \
    return static_cast<FLAG_TYPE>(~a.flags);                                               \
}                                                                                          \
constexpr FLAG_TYPE& operator|=(FLAG_TYPE& a, FLAG_TYPE b) noexcept {                      \
    a.flags = (a.flags | b.flags); return a;                                               \
}                                                                                          \
constexpr FLAG_TYPE& operator&=(FLAG_TYPE& a, FLAG_TYPE b) noexcept {                      \
    a.flags = (a.flags & b.flags); return a;                                               \
}                                                                                          \
constexpr FLAG_TYPE operator^=(FLAG_TYPE& a, FLAG_TYPE b) noexcept {                       \
    a.flags = (a.flags ^ b.flags); return a;                                               \
}                                                                                          \
constexpr FLAG_TYPE operator|(FLAG_BITS a, FLAG_BITS b) noexcept {                         \
    return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) | static_cast<BASE_TYPE>(b));  \
}                                                                                          \
constexpr FLAG_TYPE operator&(FLAG_BITS a, FLAG_BITS b) noexcept {                         \
    return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) & static_cast<BASE_TYPE>(b));  \
}                                                                                          \
constexpr FLAG_TYPE operator~(FLAG_BITS key) noexcept {                                    \
    return static_cast<FLAG_TYPE>(~static_cast<BASE_TYPE>(key));                           \
}                                                                                          \
constexpr FLAG_TYPE operator^(FLAG_BITS a, FLAG_BITS b) noexcept {                         \
    return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) ^ static_cast<BASE_TYPE>(b));  \
}                                                                                          \

DECLARE_ENUM_FLAG_OPERATORS(FramebufferCreateFlags, FramebufferCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(QueryPoolCreateFlags, QueryPoolCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(RenderPassCreateFlags, RenderPassCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SamplerCreateFlags, SamplerCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineLayoutCreateFlags, PipelineLayoutCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineCacheCreateFlags, PipelineCacheCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineDepthStencilStateCreateFlags, PipelineDepthStencilStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineDynamicStateCreateFlags, PipelineDynamicStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineColorBlendStateCreateFlags, PipelineColorBlendStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineMultisampleStateCreateFlags, PipelineMultisampleStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineRasterizationStateCreateFlags, PipelineRasterizationStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineViewportStateCreateFlags, PipelineViewportStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineTessellationStateCreateFlags, PipelineTessellationStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineInputAssemblyStateCreateFlags, PipelineInputAssemblyStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineVertexInputStateCreateFlags, PipelineVertexInputStateCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineShaderStageCreateFlags, PipelineShaderStageCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DescriptorSetLayoutCreateFlags, DescriptorSetLayoutCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(BufferViewCreateFlags, BufferViewCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(InstanceCreateFlags, InstanceCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DeviceCreateFlags, DeviceCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DeviceQueueCreateFlags, DeviceQueueCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(QueueFlags, QueueFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(MemoryPropertyFlags, MemoryPropertyFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(MemoryHeapFlags, MemoryHeapFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(AccessFlags, AccessFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(BufferUsageFlags, BufferUsageFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(BufferCreateFlags, BufferCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ShaderStageFlags, ShaderStageFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ImageUsageFlags, ImageUsageFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ImageCreateFlags, ImageCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ImageViewCreateFlags, ImageViewCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineCreateFlags, PipelineCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ColorComponentFlags, ColorComponentFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(FenceCreateFlags, FenceCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SemaphoreCreateFlags, SemaphoreCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(FormatFeatureFlags, FormatFeatureFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(QueryControlFlags, QueryControlFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(QueryResultFlags, QueryResultFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ShaderModuleCreateFlags, ShaderModuleCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(EventCreateFlags, EventCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(CommandPoolCreateFlags, CommandPoolCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(CommandPoolResetFlags, CommandPoolResetFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(CommandBufferResetFlags, CommandBufferResetFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(CommandBufferUsageFlags, CommandBufferUsageFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(QueryPipelineStatisticFlags, QueryPipelineStatisticFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(MemoryMapFlags, MemoryMapFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(MemoryUnmapFlagsKHR, MemoryUnmapFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ImageAspectFlags, ImageAspectFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SparseMemoryBindFlags, SparseMemoryBindFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SparseImageFormatFlags, SparseImageFormatFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SubpassDescriptionFlags, SubpassDescriptionFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineStageFlags, PipelineStageFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SampleCountFlags, SampleCountFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(AttachmentDescriptionFlags, AttachmentDescriptionFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(StencilFaceFlags, StencilFaceFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(CullModeFlags, CullModeFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DescriptorPoolCreateFlags, DescriptorPoolCreateFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DescriptorPoolResetFlags, DescriptorPoolResetFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DependencyFlags, DependencyFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SubgroupFeatureFlags, SubgroupFeatureFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(IndirectCommandsLayoutUsageFlagsNV, IndirectCommandsLayoutUsageFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(IndirectStateFlagsNV, IndirectStateFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(GeometryFlagsKHR, GeometryFlagBitsKHR, uint32_t)
using GeometryFlagsNV = GeometryFlagsKHR;
DECLARE_ENUM_FLAG_OPERATORS(GeometryInstanceFlagsKHR, GeometryInstanceFlagBitsKHR, uint32_t)
using GeometryInstanceFlagsNV = GeometryInstanceFlagsKHR;
DECLARE_ENUM_FLAG_OPERATORS(BuildAccelerationStructureFlagsKHR, BuildAccelerationStructureFlagBitsKHR, uint32_t)
using BuildAccelerationStructureFlagsNV = BuildAccelerationStructureFlagsKHR;
DECLARE_ENUM_FLAG_OPERATORS(PrivateDataSlotCreateFlags, PrivateDataSlotCreateFlagBits, uint32_t)
using PrivateDataSlotCreateFlagsEXT = PrivateDataSlotCreateFlags;
DECLARE_ENUM_FLAG_OPERATORS(AccelerationStructureCreateFlagsKHR, AccelerationStructureCreateFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DescriptorUpdateTemplateCreateFlags, DescriptorUpdateTemplateCreateFlagBits, uint32_t)
using DescriptorUpdateTemplateCreateFlagsKHR = DescriptorUpdateTemplateCreateFlags;
DECLARE_ENUM_FLAG_OPERATORS(PipelineCreationFeedbackFlags, PipelineCreationFeedbackFlagBits, uint32_t)
using PipelineCreationFeedbackFlagsEXT = PipelineCreationFeedbackFlags;
DECLARE_ENUM_FLAG_OPERATORS(PerformanceCounterDescriptionFlagsKHR, PerformanceCounterDescriptionFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(AcquireProfilingLockFlagsKHR, AcquireProfilingLockFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SemaphoreWaitFlags, SemaphoreWaitFlagBits, uint32_t)
using SemaphoreWaitFlagsKHR = SemaphoreWaitFlags;
DECLARE_ENUM_FLAG_OPERATORS(PipelineCompilerControlFlagsAMD, PipelineCompilerControlFlagBitsAMD, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ShaderCorePropertiesFlagsAMD, ShaderCorePropertiesFlagBitsAMD, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DeviceDiagnosticsConfigFlagsNV, DeviceDiagnosticsConfigFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(AccessFlags2, AccessFlagBits2, uint64_t)
using AccessFlags2KHR = AccessFlags2;
DECLARE_ENUM_FLAG_OPERATORS(PipelineStageFlags2, PipelineStageFlagBits2, uint64_t)
using PipelineStageFlags2KHR = PipelineStageFlags2;
DECLARE_ENUM_FLAG_OPERATORS(AccelerationStructureMotionInfoFlagsNV, AccelerationStructureMotionInfoFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(AccelerationStructureMotionInstanceFlagsNV, AccelerationStructureMotionInstanceFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(FormatFeatureFlags2, FormatFeatureFlagBits2, uint64_t)
using FormatFeatureFlags2KHR = FormatFeatureFlags2;
DECLARE_ENUM_FLAG_OPERATORS(RenderingFlags, RenderingFlagBits, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(MemoryDecompressionMethodFlagsNV, MemoryDecompressionMethodFlagBitsNV, uint64_t)
using RenderingFlagsKHR = RenderingFlags;
DECLARE_ENUM_FLAG_OPERATORS(BuildMicromapFlagsEXT, BuildMicromapFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(MicromapCreateFlagsEXT, MicromapCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DirectDriverLoadingFlagsLUNARG, DirectDriverLoadingFlagBitsLUNARG, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineCreateFlags2KHR, PipelineCreateFlagBits2KHR, uint64_t)
DECLARE_ENUM_FLAG_OPERATORS(BufferUsageFlags2KHR, BufferUsageFlagBits2KHR, uint64_t)
DECLARE_ENUM_FLAG_OPERATORS(CompositeAlphaFlagsKHR, CompositeAlphaFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DisplayPlaneAlphaFlagsKHR, DisplayPlaneAlphaFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SurfaceTransformFlagsKHR, SurfaceTransformFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(SwapchainCreateFlagsKHR, SwapchainCreateFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DisplayModeCreateFlagsKHR, DisplayModeCreateFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DisplaySurfaceCreateFlagsKHR, DisplaySurfaceCreateFlagBitsKHR, uint32_t)
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
DECLARE_ENUM_FLAG_OPERATORS(AndroidSurfaceCreateFlagsKHR, AndroidSurfaceCreateFlagBitsKHR, uint32_t)
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
#if defined(VK_USE_PLATFORM_VI_NN)
DECLARE_ENUM_FLAG_OPERATORS(ViSurfaceCreateFlagsNN, ViSurfaceCreateFlagBitsNN, uint32_t)
#endif // defined(VK_USE_PLATFORM_VI_NN)
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
DECLARE_ENUM_FLAG_OPERATORS(WaylandSurfaceCreateFlagsKHR, WaylandSurfaceCreateFlagBitsKHR, uint32_t)
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
DECLARE_ENUM_FLAG_OPERATORS(Win32SurfaceCreateFlagsKHR, Win32SurfaceCreateFlagBitsKHR, uint32_t)
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_XLIB_KHR)
DECLARE_ENUM_FLAG_OPERATORS(XlibSurfaceCreateFlagsKHR, XlibSurfaceCreateFlagBitsKHR, uint32_t)
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
DECLARE_ENUM_FLAG_OPERATORS(XcbSurfaceCreateFlagsKHR, XcbSurfaceCreateFlagBitsKHR, uint32_t)
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
DECLARE_ENUM_FLAG_OPERATORS(DirectFBSurfaceCreateFlagsEXT, DirectFBSurfaceCreateFlagBitsEXT, uint32_t)
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#if defined(VK_USE_PLATFORM_IOS_MVK)
DECLARE_ENUM_FLAG_OPERATORS(IOSSurfaceCreateFlagsMVK, IOSSurfaceCreateFlagBitsMVK, uint32_t)
#endif // defined(VK_USE_PLATFORM_IOS_MVK)
#if defined(VK_USE_PLATFORM_MACOS_MVK)
DECLARE_ENUM_FLAG_OPERATORS(MacOSSurfaceCreateFlagsMVK, MacOSSurfaceCreateFlagBitsMVK, uint32_t)
#endif // defined(VK_USE_PLATFORM_MACOS_MVK)
#if defined(VK_USE_PLATFORM_METAL_EXT)
DECLARE_ENUM_FLAG_OPERATORS(MetalSurfaceCreateFlagsEXT, MetalSurfaceCreateFlagBitsEXT, uint32_t)
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
#if defined(VK_USE_PLATFORM_FUCHSIA)
DECLARE_ENUM_FLAG_OPERATORS(ImagePipeSurfaceCreateFlagsFUCHSIA, ImagePipeSurfaceCreateFlagBitsFUCHSIA, uint32_t)
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_GGP)
DECLARE_ENUM_FLAG_OPERATORS(StreamDescriptorSurfaceCreateFlagsGGP, StreamDescriptorSurfaceCreateFlagBitsGGP, uint32_t)
#endif // defined(VK_USE_PLATFORM_GGP)
DECLARE_ENUM_FLAG_OPERATORS(HeadlessSurfaceCreateFlagsEXT, HeadlessSurfaceCreateFlagBitsEXT, uint32_t)
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
DECLARE_ENUM_FLAG_OPERATORS(ScreenSurfaceCreateFlagsQNX, ScreenSurfaceCreateFlagBitsQNX, uint32_t)
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
DECLARE_ENUM_FLAG_OPERATORS(PeerMemoryFeatureFlags, PeerMemoryFeatureFlagBits, uint32_t)
using PeerMemoryFeatureFlagsKHR = PeerMemoryFeatureFlags;
DECLARE_ENUM_FLAG_OPERATORS(MemoryAllocateFlags, MemoryAllocateFlagBits, uint32_t)
using MemoryAllocateFlagsKHR = MemoryAllocateFlags;
DECLARE_ENUM_FLAG_OPERATORS(DeviceGroupPresentModeFlagsKHR, DeviceGroupPresentModeFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DebugReportFlagsEXT, DebugReportFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(CommandPoolTrimFlags, CommandPoolTrimFlagBits, uint32_t)
using CommandPoolTrimFlagsKHR = CommandPoolTrimFlags;
DECLARE_ENUM_FLAG_OPERATORS(ExternalMemoryHandleTypeFlagsNV, ExternalMemoryHandleTypeFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ExternalMemoryFeatureFlagsNV, ExternalMemoryFeatureFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ExternalMemoryHandleTypeFlags, ExternalMemoryHandleTypeFlagBits, uint32_t)
using ExternalMemoryHandleTypeFlagsKHR = ExternalMemoryHandleTypeFlags;
DECLARE_ENUM_FLAG_OPERATORS(ExternalMemoryFeatureFlags, ExternalMemoryFeatureFlagBits, uint32_t)
using ExternalMemoryFeatureFlagsKHR = ExternalMemoryFeatureFlags;
DECLARE_ENUM_FLAG_OPERATORS(ExternalSemaphoreHandleTypeFlags, ExternalSemaphoreHandleTypeFlagBits, uint32_t)
using ExternalSemaphoreHandleTypeFlagsKHR = ExternalSemaphoreHandleTypeFlags;
DECLARE_ENUM_FLAG_OPERATORS(ExternalSemaphoreFeatureFlags, ExternalSemaphoreFeatureFlagBits, uint32_t)
using ExternalSemaphoreFeatureFlagsKHR = ExternalSemaphoreFeatureFlags;
DECLARE_ENUM_FLAG_OPERATORS(SemaphoreImportFlags, SemaphoreImportFlagBits, uint32_t)
using SemaphoreImportFlagsKHR = SemaphoreImportFlags;
DECLARE_ENUM_FLAG_OPERATORS(ExternalFenceHandleTypeFlags, ExternalFenceHandleTypeFlagBits, uint32_t)
using ExternalFenceHandleTypeFlagsKHR = ExternalFenceHandleTypeFlags;
DECLARE_ENUM_FLAG_OPERATORS(ExternalFenceFeatureFlags, ExternalFenceFeatureFlagBits, uint32_t)
using ExternalFenceFeatureFlagsKHR = ExternalFenceFeatureFlags;
DECLARE_ENUM_FLAG_OPERATORS(FenceImportFlags, FenceImportFlagBits, uint32_t)
using FenceImportFlagsKHR = FenceImportFlags;
DECLARE_ENUM_FLAG_OPERATORS(SurfaceCounterFlagsEXT, SurfaceCounterFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineViewportSwizzleStateCreateFlagsNV, PipelineViewportSwizzleStateCreateFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineDiscardRectangleStateCreateFlagsEXT, PipelineDiscardRectangleStateCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineCoverageToColorStateCreateFlagsNV, PipelineCoverageToColorStateCreateFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineCoverageModulationStateCreateFlagsNV, PipelineCoverageModulationStateCreateFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineCoverageReductionStateCreateFlagsNV, PipelineCoverageReductionStateCreateFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ValidationCacheCreateFlagsEXT, ValidationCacheCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DebugUtilsMessageSeverityFlagsEXT, DebugUtilsMessageSeverityFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DebugUtilsMessageTypeFlagsEXT, DebugUtilsMessageTypeFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DebugUtilsMessengerCreateFlagsEXT, DebugUtilsMessengerCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DebugUtilsMessengerCallbackDataFlagsEXT, DebugUtilsMessengerCallbackDataFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DeviceMemoryReportFlagsEXT, DeviceMemoryReportFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineRasterizationConservativeStateCreateFlagsEXT, PipelineRasterizationConservativeStateCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(DescriptorBindingFlags, DescriptorBindingFlagBits, uint32_t)
using DescriptorBindingFlagsEXT = DescriptorBindingFlags;
DECLARE_ENUM_FLAG_OPERATORS(ConditionalRenderingFlagsEXT, ConditionalRenderingFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ResolveModeFlags, ResolveModeFlagBits, uint32_t)
using ResolveModeFlagsKHR = ResolveModeFlags;
DECLARE_ENUM_FLAG_OPERATORS(PipelineRasterizationStateStreamCreateFlagsEXT, PipelineRasterizationStateStreamCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PipelineRasterizationDepthClipStateCreateFlagsEXT, PipelineRasterizationDepthClipStateCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ToolPurposeFlags, ToolPurposeFlagBits, uint32_t)
using ToolPurposeFlagsEXT = ToolPurposeFlags;
DECLARE_ENUM_FLAG_OPERATORS(SubmitFlags, SubmitFlagBits, uint32_t)
using SubmitFlagsKHR = SubmitFlags;
#if defined(VK_USE_PLATFORM_FUCHSIA)
DECLARE_ENUM_FLAG_OPERATORS(ImageFormatConstraintsFlagsFUCHSIA, ImageFormatConstraintsFlagBitsFUCHSIA, uint32_t)
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
DECLARE_ENUM_FLAG_OPERATORS(HostImageCopyFlagsEXT, HostImageCopyFlagBitsEXT, uint32_t)
#if defined(VK_USE_PLATFORM_FUCHSIA)
DECLARE_ENUM_FLAG_OPERATORS(ImageConstraintsInfoFlagsFUCHSIA, ImageConstraintsInfoFlagBitsFUCHSIA, uint32_t)
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
DECLARE_ENUM_FLAG_OPERATORS(GraphicsPipelineLibraryFlagsEXT, GraphicsPipelineLibraryFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ImageCompressionFlagsEXT, ImageCompressionFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ImageCompressionFixedRateFlagsEXT, ImageCompressionFixedRateFlagBitsEXT, uint32_t)
#if defined(VK_USE_PLATFORM_METAL_EXT)
DECLARE_ENUM_FLAG_OPERATORS(ExportMetalObjectTypeFlagsEXT, ExportMetalObjectTypeFlagBitsEXT, uint32_t)
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
DECLARE_ENUM_FLAG_OPERATORS(DeviceAddressBindingFlagsEXT, DeviceAddressBindingFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(OpticalFlowGridSizeFlagsNV, OpticalFlowGridSizeFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(OpticalFlowUsageFlagsNV, OpticalFlowUsageFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(OpticalFlowSessionCreateFlagsNV, OpticalFlowSessionCreateFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(OpticalFlowExecuteFlagsNV, OpticalFlowExecuteFlagBitsNV, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(FrameBoundaryFlagsEXT, FrameBoundaryFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PresentScalingFlagsEXT, PresentScalingFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PresentGravityFlagsEXT, PresentGravityFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(ShaderCreateFlagsEXT, ShaderCreateFlagBitsEXT, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(PhysicalDeviceSchedulingControlsFlagsARM, PhysicalDeviceSchedulingControlsFlagBitsARM, uint64_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoCodecOperationFlagsKHR, VideoCodecOperationFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoCapabilityFlagsKHR, VideoCapabilityFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoSessionCreateFlagsKHR, VideoSessionCreateFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoSessionParametersCreateFlagsKHR, VideoSessionParametersCreateFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoBeginCodingFlagsKHR, VideoBeginCodingFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEndCodingFlagsKHR, VideoEndCodingFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoCodingControlFlagsKHR, VideoCodingControlFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoDecodeUsageFlagsKHR, VideoDecodeUsageFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoDecodeCapabilityFlagsKHR, VideoDecodeCapabilityFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoDecodeFlagsKHR, VideoDecodeFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoDecodeH264PictureLayoutFlagsKHR, VideoDecodeH264PictureLayoutFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeFlagsKHR, VideoEncodeFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeUsageFlagsKHR, VideoEncodeUsageFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeContentFlagsKHR, VideoEncodeContentFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeCapabilityFlagsKHR, VideoEncodeCapabilityFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeFeedbackFlagsKHR, VideoEncodeFeedbackFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeRateControlFlagsKHR, VideoEncodeRateControlFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeRateControlModeFlagsKHR, VideoEncodeRateControlModeFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoChromaSubsamplingFlagsKHR, VideoChromaSubsamplingFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoComponentBitDepthFlagsKHR, VideoComponentBitDepthFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH264CapabilityFlagsKHR, VideoEncodeH264CapabilityFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH264StdFlagsKHR, VideoEncodeH264StdFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH264RateControlFlagsKHR, VideoEncodeH264RateControlFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH265CapabilityFlagsKHR, VideoEncodeH265CapabilityFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH265StdFlagsKHR, VideoEncodeH265StdFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH265RateControlFlagsKHR, VideoEncodeH265RateControlFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH265CtbSizeFlagsKHR, VideoEncodeH265CtbSizeFlagBitsKHR, uint32_t)
DECLARE_ENUM_FLAG_OPERATORS(VideoEncodeH265TransformBlockSizeFlagsKHR, VideoEncodeH265TransformBlockSizeFlagBitsKHR, uint32_t)
struct BaseOutStructure {
    StructureType sType{};
    struct BaseOutStructure * pNext{};
};
struct BaseInStructure {
    StructureType sType{};
    const struct BaseInStructure * pNext{};
};
struct Offset2D {
    int32_t x{};
    int32_t y{};
};
struct Offset3D {
    int32_t x{};
    int32_t y{};
    int32_t z{};
};
struct Extent2D {
    uint32_t width{};
    uint32_t height{};
};
struct Extent3D {
    uint32_t width{};
    uint32_t height{};
    uint32_t depth{};
};
struct Viewport {
    float x{};
    float y{};
    float width{};
    float height{};
    float minDepth{};
    float maxDepth{};
};
struct Rect2D {
    Offset2D offset{};
    Extent2D extent{};
};
struct ClearRect {
    Rect2D rect{};
    uint32_t baseArrayLayer{};
    uint32_t layerCount{};
};
struct ComponentMapping {
    ComponentSwizzle r{};
    ComponentSwizzle g{};
    ComponentSwizzle b{};
    ComponentSwizzle a{};
};
struct PhysicalDeviceSparseProperties {
    Bool32 residencyStandard2DBlockShape{};
    Bool32 residencyStandard2DMultisampleBlockShape{};
    Bool32 residencyStandard3DBlockShape{};
    Bool32 residencyAlignedMipSize{};
    Bool32 residencyNonResidentStrict{};
};
struct PhysicalDeviceLimits {
    uint32_t maxImageDimension1D{};
    uint32_t maxImageDimension2D{};
    uint32_t maxImageDimension3D{};
    uint32_t maxImageDimensionCube{};
    uint32_t maxImageArrayLayers{};
    uint32_t maxTexelBufferElements{};
    uint32_t maxUniformBufferRange{};
    uint32_t maxStorageBufferRange{};
    uint32_t maxPushConstantsSize{};
    uint32_t maxMemoryAllocationCount{};
    uint32_t maxSamplerAllocationCount{};
    DeviceSize bufferImageGranularity{};
    DeviceSize sparseAddressSpaceSize{};
    uint32_t maxBoundDescriptorSets{};
    uint32_t maxPerStageDescriptorSamplers{};
    uint32_t maxPerStageDescriptorUniformBuffers{};
    uint32_t maxPerStageDescriptorStorageBuffers{};
    uint32_t maxPerStageDescriptorSampledImages{};
    uint32_t maxPerStageDescriptorStorageImages{};
    uint32_t maxPerStageDescriptorInputAttachments{};
    uint32_t maxPerStageResources{};
    uint32_t maxDescriptorSetSamplers{};
    uint32_t maxDescriptorSetUniformBuffers{};
    uint32_t maxDescriptorSetUniformBuffersDynamic{};
    uint32_t maxDescriptorSetStorageBuffers{};
    uint32_t maxDescriptorSetStorageBuffersDynamic{};
    uint32_t maxDescriptorSetSampledImages{};
    uint32_t maxDescriptorSetStorageImages{};
    uint32_t maxDescriptorSetInputAttachments{};
    uint32_t maxVertexInputAttributes{};
    uint32_t maxVertexInputBindings{};
    uint32_t maxVertexInputAttributeOffset{};
    uint32_t maxVertexInputBindingStride{};
    uint32_t maxVertexOutputComponents{};
    uint32_t maxTessellationGenerationLevel{};
    uint32_t maxTessellationPatchSize{};
    uint32_t maxTessellationControlPerVertexInputComponents{};
    uint32_t maxTessellationControlPerVertexOutputComponents{};
    uint32_t maxTessellationControlPerPatchOutputComponents{};
    uint32_t maxTessellationControlTotalOutputComponents{};
    uint32_t maxTessellationEvaluationInputComponents{};
    uint32_t maxTessellationEvaluationOutputComponents{};
    uint32_t maxGeometryShaderInvocations{};
    uint32_t maxGeometryInputComponents{};
    uint32_t maxGeometryOutputComponents{};
    uint32_t maxGeometryOutputVertices{};
    uint32_t maxGeometryTotalOutputComponents{};
    uint32_t maxFragmentInputComponents{};
    uint32_t maxFragmentOutputAttachments{};
    uint32_t maxFragmentDualSrcAttachments{};
    uint32_t maxFragmentCombinedOutputResources{};
    uint32_t maxComputeSharedMemorySize{};
    uint32_t maxComputeWorkGroupCount [3]{};
    uint32_t maxComputeWorkGroupInvocations{};
    uint32_t maxComputeWorkGroupSize [3]{};
    uint32_t subPixelPrecisionBits{};
    uint32_t subTexelPrecisionBits{};
    uint32_t mipmapPrecisionBits{};
    uint32_t maxDrawIndexedIndexValue{};
    uint32_t maxDrawIndirectCount{};
    float maxSamplerLodBias{};
    float maxSamplerAnisotropy{};
    uint32_t maxViewports{};
    uint32_t maxViewportDimensions [2]{};
    float viewportBoundsRange [2]{};
    uint32_t viewportSubPixelBits{};
    size_t minMemoryMapAlignment{};
    DeviceSize minTexelBufferOffsetAlignment{};
    DeviceSize minUniformBufferOffsetAlignment{};
    DeviceSize minStorageBufferOffsetAlignment{};
    int32_t minTexelOffset{};
    uint32_t maxTexelOffset{};
    int32_t minTexelGatherOffset{};
    uint32_t maxTexelGatherOffset{};
    float minInterpolationOffset{};
    float maxInterpolationOffset{};
    uint32_t subPixelInterpolationOffsetBits{};
    uint32_t maxFramebufferWidth{};
    uint32_t maxFramebufferHeight{};
    uint32_t maxFramebufferLayers{};
    SampleCountFlags framebufferColorSampleCounts{};
    SampleCountFlags framebufferDepthSampleCounts{};
    SampleCountFlags framebufferStencilSampleCounts{};
    SampleCountFlags framebufferNoAttachmentsSampleCounts{};
    uint32_t maxColorAttachments{};
    SampleCountFlags sampledImageColorSampleCounts{};
    SampleCountFlags sampledImageIntegerSampleCounts{};
    SampleCountFlags sampledImageDepthSampleCounts{};
    SampleCountFlags sampledImageStencilSampleCounts{};
    SampleCountFlags storageImageSampleCounts{};
    uint32_t maxSampleMaskWords{};
    Bool32 timestampComputeAndGraphics{};
    float timestampPeriod{};
    uint32_t maxClipDistances{};
    uint32_t maxCullDistances{};
    uint32_t maxCombinedClipAndCullDistances{};
    uint32_t discreteQueuePriorities{};
    float pointSizeRange [2]{};
    float lineWidthRange [2]{};
    float pointSizeGranularity{};
    float lineWidthGranularity{};
    Bool32 strictLines{};
    Bool32 standardSampleLocations{};
    DeviceSize optimalBufferCopyOffsetAlignment{};
    DeviceSize optimalBufferCopyRowPitchAlignment{};
    DeviceSize nonCoherentAtomSize{};
};
struct PhysicalDeviceProperties {
    uint32_t apiVersion{};
    uint32_t driverVersion{};
    uint32_t vendorID{};
    uint32_t deviceID{};
    PhysicalDeviceType deviceType{};
    char deviceName [ VK_MAX_PHYSICAL_DEVICE_NAME_SIZE ]{};
    uint8_t pipelineCacheUUID [ VK_UUID_SIZE ]{};
    PhysicalDeviceLimits limits{};
    PhysicalDeviceSparseProperties sparseProperties{};
};
struct ExtensionProperties {
    char extensionName [ VK_MAX_EXTENSION_NAME_SIZE ]{};
    uint32_t specVersion{};
};
struct LayerProperties {
    char layerName [ VK_MAX_EXTENSION_NAME_SIZE ]{};
    uint32_t specVersion{};
    uint32_t implementationVersion{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
};
struct ApplicationInfo {
    StructureType sType = StructureType::ApplicationInfo;
    const void * pNext{};
    const char * pApplicationName{};
    uint32_t applicationVersion{};
    const char * pEngineName{};
    uint32_t engineVersion{};
    uint32_t apiVersion{};
};
struct AllocationCallbacks {
    void * pUserData{};
    PFN_vkAllocationFunction pfnAllocation{};
    PFN_vkReallocationFunction pfnReallocation{};
    PFN_vkFreeFunction pfnFree{};
    PFN_vkInternalAllocationNotification pfnInternalAllocation{};
    PFN_vkInternalFreeNotification pfnInternalFree{};
};
struct DeviceQueueCreateInfo {
    StructureType sType = StructureType::DeviceQueueCreateInfo;
    const void * pNext{};
    DeviceQueueCreateFlags flags{};
    uint32_t queueFamilyIndex{};
    uint32_t queueCount{};
    const float * pQueuePriorities{};
};
struct PhysicalDeviceFeatures {
    Bool32 robustBufferAccess{};
    Bool32 fullDrawIndexUint32{};
    Bool32 imageCubeArray{};
    Bool32 independentBlend{};
    Bool32 geometryShader{};
    Bool32 tessellationShader{};
    Bool32 sampleRateShading{};
    Bool32 dualSrcBlend{};
    Bool32 logicOp{};
    Bool32 multiDrawIndirect{};
    Bool32 drawIndirectFirstInstance{};
    Bool32 depthClamp{};
    Bool32 depthBiasClamp{};
    Bool32 fillModeNonSolid{};
    Bool32 depthBounds{};
    Bool32 wideLines{};
    Bool32 largePoints{};
    Bool32 alphaToOne{};
    Bool32 multiViewport{};
    Bool32 samplerAnisotropy{};
    Bool32 textureCompressionETC2{};
    Bool32 textureCompressionASTC_LDR{};
    Bool32 textureCompressionBC{};
    Bool32 occlusionQueryPrecise{};
    Bool32 pipelineStatisticsQuery{};
    Bool32 vertexPipelineStoresAndAtomics{};
    Bool32 fragmentStoresAndAtomics{};
    Bool32 shaderTessellationAndGeometryPointSize{};
    Bool32 shaderImageGatherExtended{};
    Bool32 shaderStorageImageExtendedFormats{};
    Bool32 shaderStorageImageMultisample{};
    Bool32 shaderStorageImageReadWithoutFormat{};
    Bool32 shaderStorageImageWriteWithoutFormat{};
    Bool32 shaderUniformBufferArrayDynamicIndexing{};
    Bool32 shaderSampledImageArrayDynamicIndexing{};
    Bool32 shaderStorageBufferArrayDynamicIndexing{};
    Bool32 shaderStorageImageArrayDynamicIndexing{};
    Bool32 shaderClipDistance{};
    Bool32 shaderCullDistance{};
    Bool32 shaderFloat64{};
    Bool32 shaderInt64{};
    Bool32 shaderInt16{};
    Bool32 shaderResourceResidency{};
    Bool32 shaderResourceMinLod{};
    Bool32 sparseBinding{};
    Bool32 sparseResidencyBuffer{};
    Bool32 sparseResidencyImage2D{};
    Bool32 sparseResidencyImage3D{};
    Bool32 sparseResidency2Samples{};
    Bool32 sparseResidency4Samples{};
    Bool32 sparseResidency8Samples{};
    Bool32 sparseResidency16Samples{};
    Bool32 sparseResidencyAliased{};
    Bool32 variableMultisampleRate{};
    Bool32 inheritedQueries{};
};
struct DeviceCreateInfo {
    StructureType sType = StructureType::DeviceCreateInfo;
    const void * pNext{};
    DeviceCreateFlags flags{};
    uint32_t queueCreateInfoCount{};
    const DeviceQueueCreateInfo * pQueueCreateInfos{};
    uint32_t enabledLayerCount{};
    const char * const* ppEnabledLayerNames{};
    uint32_t enabledExtensionCount{};
    const char * const* ppEnabledExtensionNames{};
    const PhysicalDeviceFeatures * pEnabledFeatures{};
};
struct InstanceCreateInfo {
    StructureType sType = StructureType::InstanceCreateInfo;
    const void * pNext{};
    InstanceCreateFlags flags{};
    const ApplicationInfo * pApplicationInfo{};
    uint32_t enabledLayerCount{};
    const char * const* ppEnabledLayerNames{};
    uint32_t enabledExtensionCount{};
    const char * const* ppEnabledExtensionNames{};
};
struct QueueFamilyProperties {
    QueueFlags queueFlags{};
    uint32_t queueCount{};
    uint32_t timestampValidBits{};
    Extent3D minImageTransferGranularity{};
};
struct MemoryHeap {
    DeviceSize size{};
    MemoryHeapFlags flags{};
};
struct MemoryType {
    MemoryPropertyFlags propertyFlags{};
    uint32_t heapIndex{};
};
struct PhysicalDeviceMemoryProperties {
    uint32_t memoryTypeCount{};
    MemoryType memoryTypes [ VK_MAX_MEMORY_TYPES ]{};
    uint32_t memoryHeapCount{};
    MemoryHeap memoryHeaps [ VK_MAX_MEMORY_HEAPS ]{};
};
struct MemoryAllocateInfo {
    StructureType sType = StructureType::MemoryAllocateInfo;
    const void * pNext{};
    DeviceSize allocationSize{};
    uint32_t memoryTypeIndex{};
};
struct MemoryRequirements {
    DeviceSize size{};
    DeviceSize alignment{};
    uint32_t memoryTypeBits{};
};
struct SparseImageFormatProperties {
    ImageAspectFlags aspectMask{};
    Extent3D imageGranularity{};
    SparseImageFormatFlags flags{};
};
struct SparseImageMemoryRequirements {
    SparseImageFormatProperties formatProperties{};
    uint32_t imageMipTailFirstLod{};
    DeviceSize imageMipTailSize{};
    DeviceSize imageMipTailOffset{};
    DeviceSize imageMipTailStride{};
};
struct MappedMemoryRange {
    StructureType sType = StructureType::MappedMemoryRange;
    const void * pNext{};
    DeviceMemory memory{};
    DeviceSize offset{};
    DeviceSize size{};
};
struct FormatProperties {
    FormatFeatureFlags linearTilingFeatures{};
    FormatFeatureFlags optimalTilingFeatures{};
    FormatFeatureFlags bufferFeatures{};
};
struct ImageFormatProperties {
    Extent3D maxExtent{};
    uint32_t maxMipLevels{};
    uint32_t maxArrayLayers{};
    SampleCountFlags sampleCounts{};
    DeviceSize maxResourceSize{};
};
struct DescriptorBufferInfo {
    Buffer buffer{};
    DeviceSize offset{};
    DeviceSize range{};
};
struct DescriptorImageInfo {
    Sampler sampler{};
    ImageView imageView{};
    ImageLayout imageLayout{};
};
struct WriteDescriptorSet {
    StructureType sType = StructureType::WriteDescriptorSet;
    const void * pNext{};
    DescriptorSet dstSet{};
    uint32_t dstBinding{};
    uint32_t dstArrayElement{};
    uint32_t descriptorCount{};
    DescriptorType descriptorType{};
    const DescriptorImageInfo * pImageInfo{};
    const DescriptorBufferInfo * pBufferInfo{};
    const BufferView * pTexelBufferView{};
};
struct CopyDescriptorSet {
    StructureType sType = StructureType::CopyDescriptorSet;
    const void * pNext{};
    DescriptorSet srcSet{};
    uint32_t srcBinding{};
    uint32_t srcArrayElement{};
    DescriptorSet dstSet{};
    uint32_t dstBinding{};
    uint32_t dstArrayElement{};
    uint32_t descriptorCount{};
};
struct BufferUsageFlags2CreateInfoKHR {
    StructureType sType = StructureType::BufferUsageFlags2CreateInfoKHR;
    const void * pNext{};
    BufferUsageFlags2KHR usage{};
};
struct BufferCreateInfo {
    StructureType sType = StructureType::BufferCreateInfo;
    const void * pNext{};
    BufferCreateFlags flags{};
    DeviceSize size{};
    BufferUsageFlags usage{};
    SharingMode sharingMode{};
    uint32_t queueFamilyIndexCount{};
    const uint32_t * pQueueFamilyIndices{};
};
struct BufferViewCreateInfo {
    StructureType sType = StructureType::BufferViewCreateInfo;
    const void * pNext{};
    BufferViewCreateFlags flags{};
    Buffer buffer{};
    Format format{};
    DeviceSize offset{};
    DeviceSize range{};
};
struct ImageSubresource {
    ImageAspectFlags aspectMask{};
    uint32_t mipLevel{};
    uint32_t arrayLayer{};
};
struct ImageSubresourceLayers {
    ImageAspectFlags aspectMask{};
    uint32_t mipLevel{};
    uint32_t baseArrayLayer{};
    uint32_t layerCount{};
};
struct ImageSubresourceRange {
    ImageAspectFlags aspectMask{};
    uint32_t baseMipLevel{};
    uint32_t levelCount{};
    uint32_t baseArrayLayer{};
    uint32_t layerCount{};
};
struct MemoryBarrier {
    StructureType sType = StructureType::MemoryBarrier;
    const void * pNext{};
    AccessFlags srcAccessMask{};
    AccessFlags dstAccessMask{};
};
struct BufferMemoryBarrier {
    StructureType sType = StructureType::BufferMemoryBarrier;
    const void * pNext{};
    AccessFlags srcAccessMask{};
    AccessFlags dstAccessMask{};
    uint32_t srcQueueFamilyIndex{};
    uint32_t dstQueueFamilyIndex{};
    Buffer buffer{};
    DeviceSize offset{};
    DeviceSize size{};
};
struct ImageMemoryBarrier {
    StructureType sType = StructureType::ImageMemoryBarrier;
    const void * pNext{};
    AccessFlags srcAccessMask{};
    AccessFlags dstAccessMask{};
    ImageLayout oldLayout{};
    ImageLayout newLayout{};
    uint32_t srcQueueFamilyIndex{};
    uint32_t dstQueueFamilyIndex{};
    Image image{};
    ImageSubresourceRange subresourceRange{};
};
struct ImageCreateInfo {
    StructureType sType = StructureType::ImageCreateInfo;
    const void * pNext{};
    ImageCreateFlags flags{};
    ImageType imageType{};
    Format format{};
    Extent3D extent{};
    uint32_t mipLevels{};
    uint32_t arrayLayers{};
    SampleCountFlagBits samples{};
    ImageTiling tiling{};
    ImageUsageFlags usage{};
    SharingMode sharingMode{};
    uint32_t queueFamilyIndexCount{};
    const uint32_t * pQueueFamilyIndices{};
    ImageLayout initialLayout{};
};
struct SubresourceLayout {
    DeviceSize offset{};
    DeviceSize size{};
    DeviceSize rowPitch{};
    DeviceSize arrayPitch{};
    DeviceSize depthPitch{};
};
struct ImageViewCreateInfo {
    StructureType sType = StructureType::ImageViewCreateInfo;
    const void * pNext{};
    ImageViewCreateFlags flags{};
    Image image{};
    ImageViewType viewType{};
    Format format{};
    ComponentMapping components{};
    ImageSubresourceRange subresourceRange{};
};
struct BufferCopy {
    DeviceSize srcOffset{};
    DeviceSize dstOffset{};
    DeviceSize size{};
};
struct SparseMemoryBind {
    DeviceSize resourceOffset{};
    DeviceSize size{};
    DeviceMemory memory{};
    DeviceSize memoryOffset{};
    SparseMemoryBindFlags flags{};
};
struct SparseImageMemoryBind {
    ImageSubresource subresource{};
    Offset3D offset{};
    Extent3D extent{};
    DeviceMemory memory{};
    DeviceSize memoryOffset{};
    SparseMemoryBindFlags flags{};
};
struct SparseBufferMemoryBindInfo {
    Buffer buffer{};
    uint32_t bindCount{};
    const SparseMemoryBind * pBinds{};
};
struct SparseImageOpaqueMemoryBindInfo {
    Image image{};
    uint32_t bindCount{};
    const SparseMemoryBind * pBinds{};
};
struct SparseImageMemoryBindInfo {
    Image image{};
    uint32_t bindCount{};
    const SparseImageMemoryBind * pBinds{};
};
struct BindSparseInfo {
    StructureType sType = StructureType::BindSparseInfo;
    const void * pNext{};
    uint32_t waitSemaphoreCount{};
    const Semaphore * pWaitSemaphores{};
    uint32_t bufferBindCount{};
    const SparseBufferMemoryBindInfo * pBufferBinds{};
    uint32_t imageOpaqueBindCount{};
    const SparseImageOpaqueMemoryBindInfo * pImageOpaqueBinds{};
    uint32_t imageBindCount{};
    const SparseImageMemoryBindInfo * pImageBinds{};
    uint32_t signalSemaphoreCount{};
    const Semaphore * pSignalSemaphores{};
};
struct ImageCopy {
    ImageSubresourceLayers srcSubresource{};
    Offset3D srcOffset{};
    ImageSubresourceLayers dstSubresource{};
    Offset3D dstOffset{};
    Extent3D extent{};
};
struct ImageBlit {
    ImageSubresourceLayers srcSubresource{};
    Offset3D srcOffsets [2]{};
    ImageSubresourceLayers dstSubresource{};
    Offset3D dstOffsets [2]{};
};
struct BufferImageCopy {
    DeviceSize bufferOffset{};
    uint32_t bufferRowLength{};
    uint32_t bufferImageHeight{};
    ImageSubresourceLayers imageSubresource{};
    Offset3D imageOffset{};
    Extent3D imageExtent{};
};
struct CopyMemoryIndirectCommandNV {
    DeviceAddress srcAddress{};
    DeviceAddress dstAddress{};
    DeviceSize size{};
};
struct CopyMemoryToImageIndirectCommandNV {
    DeviceAddress srcAddress{};
    uint32_t bufferRowLength{};
    uint32_t bufferImageHeight{};
    ImageSubresourceLayers imageSubresource{};
    Offset3D imageOffset{};
    Extent3D imageExtent{};
};
struct ImageResolve {
    ImageSubresourceLayers srcSubresource{};
    Offset3D srcOffset{};
    ImageSubresourceLayers dstSubresource{};
    Offset3D dstOffset{};
    Extent3D extent{};
};
struct ShaderModuleCreateInfo {
    StructureType sType = StructureType::ShaderModuleCreateInfo;
    const void * pNext{};
    ShaderModuleCreateFlags flags{};
    size_t codeSize{};
    const uint32_t * pCode{};
};
struct DescriptorSetLayoutBinding {
    uint32_t binding{};
    DescriptorType descriptorType{};
    uint32_t descriptorCount{};
    ShaderStageFlags stageFlags{};
    const Sampler * pImmutableSamplers{};
};
struct DescriptorSetLayoutCreateInfo {
    StructureType sType = StructureType::DescriptorSetLayoutCreateInfo;
    const void * pNext{};
    DescriptorSetLayoutCreateFlags flags{};
    uint32_t bindingCount{};
    const DescriptorSetLayoutBinding * pBindings{};
};
struct DescriptorPoolSize {
    DescriptorType type{};
    uint32_t descriptorCount{};
};
struct DescriptorPoolCreateInfo {
    StructureType sType = StructureType::DescriptorPoolCreateInfo;
    const void * pNext{};
    DescriptorPoolCreateFlags flags{};
    uint32_t maxSets{};
    uint32_t poolSizeCount{};
    const DescriptorPoolSize * pPoolSizes{};
};
struct DescriptorSetAllocateInfo {
    StructureType sType = StructureType::DescriptorSetAllocateInfo;
    const void * pNext{};
    DescriptorPool descriptorPool{};
    uint32_t descriptorSetCount{};
    const DescriptorSetLayout * pSetLayouts{};
};
struct SpecializationMapEntry {
    uint32_t constantID{};
    uint32_t offset{};
    size_t size{};
};
struct SpecializationInfo {
    uint32_t mapEntryCount{};
    const SpecializationMapEntry * pMapEntries{};
    size_t dataSize{};
    const void * pData{};
};
struct PipelineShaderStageCreateInfo {
    StructureType sType = StructureType::PipelineShaderStageCreateInfo;
    const void * pNext{};
    PipelineShaderStageCreateFlags flags{};
    ShaderStageFlagBits stage{};
    ShaderModule module{};
    const char * pName{};
    const SpecializationInfo * pSpecializationInfo{};
};
struct ComputePipelineCreateInfo {
    StructureType sType = StructureType::ComputePipelineCreateInfo;
    const void * pNext{};
    PipelineCreateFlags flags{};
    PipelineShaderStageCreateInfo stage{};
    PipelineLayout layout{};
    Pipeline basePipelineHandle{};
    int32_t basePipelineIndex{};
};
struct ComputePipelineIndirectBufferInfoNV {
    StructureType sType = StructureType::ComputePipelineIndirectBufferInfoNV;
    const void * pNext{};
    DeviceAddress deviceAddress{};
    DeviceSize size{};
    DeviceAddress pipelineDeviceAddressCaptureReplay{};
};
struct PipelineCreateFlags2CreateInfoKHR {
    StructureType sType = StructureType::PipelineCreateFlags2CreateInfoKHR;
    const void * pNext{};
    PipelineCreateFlags2KHR flags{};
};
struct VertexInputBindingDescription {
    uint32_t binding{};
    uint32_t stride{};
    VertexInputRate inputRate{};
};
struct VertexInputAttributeDescription {
    uint32_t location{};
    uint32_t binding{};
    Format format{};
    uint32_t offset{};
};
struct PipelineVertexInputStateCreateInfo {
    StructureType sType = StructureType::PipelineVertexInputStateCreateInfo;
    const void * pNext{};
    PipelineVertexInputStateCreateFlags flags{};
    uint32_t vertexBindingDescriptionCount{};
    const VertexInputBindingDescription * pVertexBindingDescriptions{};
    uint32_t vertexAttributeDescriptionCount{};
    const VertexInputAttributeDescription * pVertexAttributeDescriptions{};
};
struct PipelineInputAssemblyStateCreateInfo {
    StructureType sType = StructureType::PipelineInputAssemblyStateCreateInfo;
    const void * pNext{};
    PipelineInputAssemblyStateCreateFlags flags{};
    PrimitiveTopology topology{};
    Bool32 primitiveRestartEnable{};
};
struct PipelineTessellationStateCreateInfo {
    StructureType sType = StructureType::PipelineTessellationStateCreateInfo;
    const void * pNext{};
    PipelineTessellationStateCreateFlags flags{};
    uint32_t patchControlPoints{};
};
struct PipelineViewportStateCreateInfo {
    StructureType sType = StructureType::PipelineViewportStateCreateInfo;
    const void * pNext{};
    PipelineViewportStateCreateFlags flags{};
    uint32_t viewportCount{};
    const Viewport * pViewports{};
    uint32_t scissorCount{};
    const Rect2D * pScissors{};
};
struct PipelineRasterizationStateCreateInfo {
    StructureType sType = StructureType::PipelineRasterizationStateCreateInfo;
    const void * pNext{};
    PipelineRasterizationStateCreateFlags flags{};
    Bool32 depthClampEnable{};
    Bool32 rasterizerDiscardEnable{};
    PolygonMode polygonMode{};
    CullModeFlags cullMode{};
    FrontFace frontFace{};
    Bool32 depthBiasEnable{};
    float depthBiasConstantFactor{};
    float depthBiasClamp{};
    float depthBiasSlopeFactor{};
    float lineWidth{};
};
struct PipelineMultisampleStateCreateInfo {
    StructureType sType = StructureType::PipelineMultisampleStateCreateInfo;
    const void * pNext{};
    PipelineMultisampleStateCreateFlags flags{};
    SampleCountFlagBits rasterizationSamples{};
    Bool32 sampleShadingEnable{};
    float minSampleShading{};
    const SampleMask * pSampleMask{};
    Bool32 alphaToCoverageEnable{};
    Bool32 alphaToOneEnable{};
};
struct PipelineColorBlendAttachmentState {
    Bool32 blendEnable{};
    BlendFactor srcColorBlendFactor{};
    BlendFactor dstColorBlendFactor{};
    BlendOp colorBlendOp{};
    BlendFactor srcAlphaBlendFactor{};
    BlendFactor dstAlphaBlendFactor{};
    BlendOp alphaBlendOp{};
    ColorComponentFlags colorWriteMask{};
};
struct PipelineColorBlendStateCreateInfo {
    StructureType sType = StructureType::PipelineColorBlendStateCreateInfo;
    const void * pNext{};
    PipelineColorBlendStateCreateFlags flags{};
    Bool32 logicOpEnable{};
    LogicOp logicOp{};
    uint32_t attachmentCount{};
    const PipelineColorBlendAttachmentState * pAttachments{};
    float blendConstants [4]{};
};
struct PipelineDynamicStateCreateInfo {
    StructureType sType = StructureType::PipelineDynamicStateCreateInfo;
    const void * pNext{};
    PipelineDynamicStateCreateFlags flags{};
    uint32_t dynamicStateCount{};
    const DynamicState * pDynamicStates{};
};
struct StencilOpState {
    StencilOp failOp{};
    StencilOp passOp{};
    StencilOp depthFailOp{};
    CompareOp compareOp{};
    uint32_t compareMask{};
    uint32_t writeMask{};
    uint32_t reference{};
};
struct PipelineDepthStencilStateCreateInfo {
    StructureType sType = StructureType::PipelineDepthStencilStateCreateInfo;
    const void * pNext{};
    PipelineDepthStencilStateCreateFlags flags{};
    Bool32 depthTestEnable{};
    Bool32 depthWriteEnable{};
    CompareOp depthCompareOp{};
    Bool32 depthBoundsTestEnable{};
    Bool32 stencilTestEnable{};
    StencilOpState front{};
    StencilOpState back{};
    float minDepthBounds{};
    float maxDepthBounds{};
};
struct GraphicsPipelineCreateInfo {
    StructureType sType = StructureType::GraphicsPipelineCreateInfo;
    const void * pNext{};
    PipelineCreateFlags flags{};
    uint32_t stageCount{};
    const PipelineShaderStageCreateInfo * pStages{};
    const PipelineVertexInputStateCreateInfo * pVertexInputState{};
    const PipelineInputAssemblyStateCreateInfo * pInputAssemblyState{};
    const PipelineTessellationStateCreateInfo * pTessellationState{};
    const PipelineViewportStateCreateInfo * pViewportState{};
    const PipelineRasterizationStateCreateInfo * pRasterizationState{};
    const PipelineMultisampleStateCreateInfo * pMultisampleState{};
    const PipelineDepthStencilStateCreateInfo * pDepthStencilState{};
    const PipelineColorBlendStateCreateInfo * pColorBlendState{};
    const PipelineDynamicStateCreateInfo * pDynamicState{};
    PipelineLayout layout{};
    RenderPass renderPass{};
    uint32_t subpass{};
    Pipeline basePipelineHandle{};
    int32_t basePipelineIndex{};
};
struct PipelineCacheCreateInfo {
    StructureType sType = StructureType::PipelineCacheCreateInfo;
    const void * pNext{};
    PipelineCacheCreateFlags flags{};
    size_t initialDataSize{};
    const void * pInitialData{};
};
struct PipelineCacheHeaderVersionOne {
    uint32_t headerSize{};
    PipelineCacheHeaderVersion headerVersion{};
    uint32_t vendorID{};
    uint32_t deviceID{};
    uint8_t pipelineCacheUUID [ VK_UUID_SIZE ]{};
};
struct PushConstantRange {
    ShaderStageFlags stageFlags{};
    uint32_t offset{};
    uint32_t size{};
};
struct PipelineLayoutCreateInfo {
    StructureType sType = StructureType::PipelineLayoutCreateInfo;
    const void * pNext{};
    PipelineLayoutCreateFlags flags{};
    uint32_t setLayoutCount{};
    const DescriptorSetLayout * pSetLayouts{};
    uint32_t pushConstantRangeCount{};
    const PushConstantRange * pPushConstantRanges{};
};
struct SamplerCreateInfo {
    StructureType sType = StructureType::SamplerCreateInfo;
    const void * pNext{};
    SamplerCreateFlags flags{};
    Filter magFilter{};
    Filter minFilter{};
    SamplerMipmapMode mipmapMode{};
    SamplerAddressMode addressModeU{};
    SamplerAddressMode addressModeV{};
    SamplerAddressMode addressModeW{};
    float mipLodBias{};
    Bool32 anisotropyEnable{};
    float maxAnisotropy{};
    Bool32 compareEnable{};
    CompareOp compareOp{};
    float minLod{};
    float maxLod{};
    BorderColor borderColor{};
    Bool32 unnormalizedCoordinates{};
};
struct CommandPoolCreateInfo {
    StructureType sType = StructureType::CommandPoolCreateInfo;
    const void * pNext{};
    CommandPoolCreateFlags flags{};
    uint32_t queueFamilyIndex{};
};
struct CommandBufferAllocateInfo {
    StructureType sType = StructureType::CommandBufferAllocateInfo;
    const void * pNext{};
    CommandPool commandPool{};
    CommandBufferLevel level{};
    uint32_t commandBufferCount{};
};
struct CommandBufferInheritanceInfo {
    StructureType sType = StructureType::CommandBufferInheritanceInfo;
    const void * pNext{};
    RenderPass renderPass{};
    uint32_t subpass{};
    Framebuffer framebuffer{};
    Bool32 occlusionQueryEnable{};
    QueryControlFlags queryFlags{};
    QueryPipelineStatisticFlags pipelineStatistics{};
};
struct CommandBufferBeginInfo {
    StructureType sType = StructureType::CommandBufferBeginInfo;
    const void * pNext{};
    CommandBufferUsageFlags flags{};
    const CommandBufferInheritanceInfo * pInheritanceInfo{};
};
struct ClearDepthStencilValue {
    float depth{};
    uint32_t stencil{};
};
union ClearColorValue {
    float float32 [4];
    int32_t int32 [4];
    uint32_t uint32 [4];
};
union ClearValue {
    ClearColorValue color;
    ClearDepthStencilValue depthStencil;
};
struct RenderPassBeginInfo {
    StructureType sType = StructureType::RenderPassBeginInfo;
    const void * pNext{};
    RenderPass renderPass{};
    Framebuffer framebuffer{};
    Rect2D renderArea{};
    uint32_t clearValueCount{};
    const ClearValue * pClearValues{};
};
struct ClearAttachment {
    ImageAspectFlags aspectMask{};
    uint32_t colorAttachment{};
    ClearValue clearValue{};
};
struct AttachmentDescription {
    AttachmentDescriptionFlags flags{};
    Format format{};
    SampleCountFlagBits samples{};
    AttachmentLoadOp loadOp{};
    AttachmentStoreOp storeOp{};
    AttachmentLoadOp stencilLoadOp{};
    AttachmentStoreOp stencilStoreOp{};
    ImageLayout initialLayout{};
    ImageLayout finalLayout{};
};
struct AttachmentReference {
    uint32_t attachment{};
    ImageLayout layout{};
};
struct SubpassDescription {
    SubpassDescriptionFlags flags{};
    PipelineBindPoint pipelineBindPoint{};
    uint32_t inputAttachmentCount{};
    const AttachmentReference * pInputAttachments{};
    uint32_t colorAttachmentCount{};
    const AttachmentReference * pColorAttachments{};
    const AttachmentReference * pResolveAttachments{};
    const AttachmentReference * pDepthStencilAttachment{};
    uint32_t preserveAttachmentCount{};
    const uint32_t * pPreserveAttachments{};
};
struct SubpassDependency {
    uint32_t srcSubpass{};
    uint32_t dstSubpass{};
    PipelineStageFlags srcStageMask{};
    PipelineStageFlags dstStageMask{};
    AccessFlags srcAccessMask{};
    AccessFlags dstAccessMask{};
    DependencyFlags dependencyFlags{};
};
struct RenderPassCreateInfo {
    StructureType sType = StructureType::RenderPassCreateInfo;
    const void * pNext{};
    RenderPassCreateFlags flags{};
    uint32_t attachmentCount{};
    const AttachmentDescription * pAttachments{};
    uint32_t subpassCount{};
    const SubpassDescription * pSubpasses{};
    uint32_t dependencyCount{};
    const SubpassDependency * pDependencies{};
};
struct EventCreateInfo {
    StructureType sType = StructureType::EventCreateInfo;
    const void * pNext{};
    EventCreateFlags flags{};
};
struct FenceCreateInfo {
    StructureType sType = StructureType::FenceCreateInfo;
    const void * pNext{};
    FenceCreateFlags flags{};
};
struct SemaphoreCreateInfo {
    StructureType sType = StructureType::SemaphoreCreateInfo;
    const void * pNext{};
    SemaphoreCreateFlags flags{};
};
struct QueryPoolCreateInfo {
    StructureType sType = StructureType::QueryPoolCreateInfo;
    const void * pNext{};
    QueryPoolCreateFlags flags{};
    QueryType queryType{};
    uint32_t queryCount{};
    QueryPipelineStatisticFlags pipelineStatistics{};
};
struct FramebufferCreateInfo {
    StructureType sType = StructureType::FramebufferCreateInfo;
    const void * pNext{};
    FramebufferCreateFlags flags{};
    RenderPass renderPass{};
    uint32_t attachmentCount{};
    const ImageView * pAttachments{};
    uint32_t width{};
    uint32_t height{};
    uint32_t layers{};
};
struct DrawIndirectCommand {
    uint32_t vertexCount{};
    uint32_t instanceCount{};
    uint32_t firstVertex{};
    uint32_t firstInstance{};
};
struct DrawIndexedIndirectCommand {
    uint32_t indexCount{};
    uint32_t instanceCount{};
    uint32_t firstIndex{};
    int32_t vertexOffset{};
    uint32_t firstInstance{};
};
struct DispatchIndirectCommand {
    uint32_t x{};
    uint32_t y{};
    uint32_t z{};
};
struct MultiDrawInfoEXT {
    uint32_t firstVertex{};
    uint32_t vertexCount{};
};
struct MultiDrawIndexedInfoEXT {
    uint32_t firstIndex{};
    uint32_t indexCount{};
    int32_t vertexOffset{};
};
struct SubmitInfo {
    StructureType sType = StructureType::SubmitInfo;
    const void * pNext{};
    uint32_t waitSemaphoreCount{};
    const Semaphore * pWaitSemaphores{};
    const PipelineStageFlags * pWaitDstStageMask{};
    uint32_t commandBufferCount{};
    const CommandBuffer * pCommandBuffers{};
    uint32_t signalSemaphoreCount{};
    const Semaphore * pSignalSemaphores{};
};
struct DisplayPropertiesKHR {
    DisplayKHR display{};
    const char * displayName{};
    Extent2D physicalDimensions{};
    Extent2D physicalResolution{};
    SurfaceTransformFlagsKHR supportedTransforms{};
    Bool32 planeReorderPossible{};
    Bool32 persistentContent{};
};
struct DisplayPlanePropertiesKHR {
    DisplayKHR currentDisplay{};
    uint32_t currentStackIndex{};
};
struct DisplayModeParametersKHR {
    Extent2D visibleRegion{};
    uint32_t refreshRate{};
};
struct DisplayModePropertiesKHR {
    DisplayModeKHR displayMode{};
    DisplayModeParametersKHR parameters{};
};
struct DisplayModeCreateInfoKHR {
    StructureType sType = StructureType::DisplayModeCreateInfoKHR;
    const void * pNext{};
    DisplayModeCreateFlagsKHR flags{};
    DisplayModeParametersKHR parameters{};
};
struct DisplayPlaneCapabilitiesKHR {
    DisplayPlaneAlphaFlagsKHR supportedAlpha{};
    Offset2D minSrcPosition{};
    Offset2D maxSrcPosition{};
    Extent2D minSrcExtent{};
    Extent2D maxSrcExtent{};
    Offset2D minDstPosition{};
    Offset2D maxDstPosition{};
    Extent2D minDstExtent{};
    Extent2D maxDstExtent{};
};
struct DisplaySurfaceCreateInfoKHR {
    StructureType sType = StructureType::DisplaySurfaceCreateInfoKHR;
    const void * pNext{};
    DisplaySurfaceCreateFlagsKHR flags{};
    DisplayModeKHR displayMode{};
    uint32_t planeIndex{};
    uint32_t planeStackIndex{};
    SurfaceTransformFlagBitsKHR transform{};
    float globalAlpha{};
    DisplayPlaneAlphaFlagBitsKHR alphaMode{};
    Extent2D imageExtent{};
};
struct DisplayPresentInfoKHR {
    StructureType sType = StructureType::DisplayPresentInfoKHR;
    const void * pNext{};
    Rect2D srcRect{};
    Rect2D dstRect{};
    Bool32 persistent{};
};
struct SurfaceCapabilitiesKHR {
    uint32_t minImageCount{};
    uint32_t maxImageCount{};
    Extent2D currentExtent{};
    Extent2D minImageExtent{};
    Extent2D maxImageExtent{};
    uint32_t maxImageArrayLayers{};
    SurfaceTransformFlagsKHR supportedTransforms{};
    SurfaceTransformFlagBitsKHR currentTransform{};
    CompositeAlphaFlagsKHR supportedCompositeAlpha{};
    ImageUsageFlags supportedUsageFlags{};
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct AndroidSurfaceCreateInfoKHR {
    StructureType sType = StructureType::AndroidSurfaceCreateInfoKHR;
    const void * pNext{};
    AndroidSurfaceCreateFlagsKHR flags{};
    struct ANativeWindow * window{};
};
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
#if defined(VK_USE_PLATFORM_VI_NN)
struct ViSurfaceCreateInfoNN {
    StructureType sType = StructureType::ViSurfaceCreateInfoNN;
    const void * pNext{};
    ViSurfaceCreateFlagsNN flags{};
    void * window{};
};
#endif // defined(VK_USE_PLATFORM_VI_NN)
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
struct WaylandSurfaceCreateInfoKHR {
    StructureType sType = StructureType::WaylandSurfaceCreateInfoKHR;
    const void * pNext{};
    WaylandSurfaceCreateFlagsKHR flags{};
    struct wl_display * display{};
    struct wl_surface * surface{};
};
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct Win32SurfaceCreateInfoKHR {
    StructureType sType = StructureType::Win32SurfaceCreateInfoKHR;
    const void * pNext{};
    Win32SurfaceCreateFlagsKHR flags{};
    HINSTANCE hinstance{};
    HWND hwnd{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_XLIB_KHR)
struct XlibSurfaceCreateInfoKHR {
    StructureType sType = StructureType::XlibSurfaceCreateInfoKHR;
    const void * pNext{};
    XlibSurfaceCreateFlagsKHR flags{};
    Display * dpy{};
    Window window{};
};
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
struct XcbSurfaceCreateInfoKHR {
    StructureType sType = StructureType::XcbSurfaceCreateInfoKHR;
    const void * pNext{};
    XcbSurfaceCreateFlagsKHR flags{};
    xcb_connection_t * connection{};
    xcb_window_t window{};
};
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
struct DirectFBSurfaceCreateInfoEXT {
    StructureType sType = StructureType::DirectfbSurfaceCreateInfoEXT;
    const void * pNext{};
    DirectFBSurfaceCreateFlagsEXT flags{};
    IDirectFB * dfb{};
    IDirectFBSurface * surface{};
};
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#if defined(VK_USE_PLATFORM_FUCHSIA)
struct ImagePipeSurfaceCreateInfoFUCHSIA {
    StructureType sType = StructureType::ImagepipeSurfaceCreateInfoFUCHSIA;
    const void * pNext{};
    ImagePipeSurfaceCreateFlagsFUCHSIA flags{};
    zx_handle_t imagePipeHandle{};
};
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_GGP)
struct StreamDescriptorSurfaceCreateInfoGGP {
    StructureType sType = StructureType::StreamDescriptorSurfaceCreateInfoGGP;
    const void * pNext{};
    StreamDescriptorSurfaceCreateFlagsGGP flags{};
    GgpStreamDescriptor streamDescriptor{};
};
#endif // defined(VK_USE_PLATFORM_GGP)
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
struct ScreenSurfaceCreateInfoQNX {
    StructureType sType = StructureType::ScreenSurfaceCreateInfoQNX;
    const void * pNext{};
    ScreenSurfaceCreateFlagsQNX flags{};
    struct _screen_context * context{};
    struct _screen_window * window{};
};
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
struct SurfaceFormatKHR {
    Format format{};
    ColorSpaceKHR colorSpace{};
};
struct SwapchainCreateInfoKHR {
    StructureType sType = StructureType::SwapchainCreateInfoKHR;
    const void * pNext{};
    SwapchainCreateFlagsKHR flags{};
    SurfaceKHR surface{};
    uint32_t minImageCount{};
    Format imageFormat{};
    ColorSpaceKHR imageColorSpace{};
    Extent2D imageExtent{};
    uint32_t imageArrayLayers{};
    ImageUsageFlags imageUsage{};
    SharingMode imageSharingMode{};
    uint32_t queueFamilyIndexCount{};
    const uint32_t * pQueueFamilyIndices{};
    SurfaceTransformFlagBitsKHR preTransform{};
    CompositeAlphaFlagBitsKHR compositeAlpha{};
    PresentModeKHR presentMode{};
    Bool32 clipped{};
    SwapchainKHR oldSwapchain{};
};
struct PresentInfoKHR {
    StructureType sType = StructureType::PresentInfoKHR;
    const void * pNext{};
    uint32_t waitSemaphoreCount{};
    const Semaphore * pWaitSemaphores{};
    uint32_t swapchainCount{};
    const SwapchainKHR * pSwapchains{};
    const uint32_t * pImageIndices{};
    Result * pResults{};
};
struct DebugReportCallbackCreateInfoEXT {
    StructureType sType = StructureType::DebugReportCallbackCreateInfoEXT;
    const void * pNext{};
    DebugReportFlagsEXT flags{};
    PFN_vkDebugReportCallbackEXT pfnCallback{};
    void * pUserData{};
};
struct ValidationFlagsEXT {
    StructureType sType = StructureType::ValidationFlagsEXT;
    const void * pNext{};
    uint32_t disabledValidationCheckCount{};
    const ValidationCheckEXT * pDisabledValidationChecks{};
};
struct ValidationFeaturesEXT {
    StructureType sType = StructureType::ValidationFeaturesEXT;
    const void * pNext{};
    uint32_t enabledValidationFeatureCount{};
    const ValidationFeatureEnableEXT * pEnabledValidationFeatures{};
    uint32_t disabledValidationFeatureCount{};
    const ValidationFeatureDisableEXT * pDisabledValidationFeatures{};
};
struct LayerSettingEXT {
    const char * pLayerName{};
    const char * pSettingName{};
    LayerSettingTypeEXT type{};
    uint32_t valueCount{};
    const void * pValues{};
};
struct LayerSettingsCreateInfoEXT {
    StructureType sType = StructureType::LayerSettingsCreateInfoEXT;
    const void * pNext{};
    uint32_t settingCount{};
    const LayerSettingEXT * pSettings{};
};
struct PipelineRasterizationStateRasterizationOrderAMD {
    StructureType sType = StructureType::PipelineRasterizationStateRasterizationOrderAMD;
    const void * pNext{};
    RasterizationOrderAMD rasterizationOrder{};
};
struct DebugMarkerObjectNameInfoEXT {
    StructureType sType = StructureType::DebugMarkerObjectNameInfoEXT;
    const void * pNext{};
    DebugReportObjectTypeEXT objectType{};
    uint64_t object{};
    const char * pObjectName{};
};
struct DebugMarkerObjectTagInfoEXT {
    StructureType sType = StructureType::DebugMarkerObjectTagInfoEXT;
    const void * pNext{};
    DebugReportObjectTypeEXT objectType{};
    uint64_t object{};
    uint64_t tagName{};
    size_t tagSize{};
    const void * pTag{};
};
struct DebugMarkerMarkerInfoEXT {
    StructureType sType = StructureType::DebugMarkerMarkerInfoEXT;
    const void * pNext{};
    const char * pMarkerName{};
    float color [4]{};
};
struct DedicatedAllocationImageCreateInfoNV {
    StructureType sType = StructureType::DedicatedAllocationImageCreateInfoNV;
    const void * pNext{};
    Bool32 dedicatedAllocation{};
};
struct DedicatedAllocationBufferCreateInfoNV {
    StructureType sType = StructureType::DedicatedAllocationBufferCreateInfoNV;
    const void * pNext{};
    Bool32 dedicatedAllocation{};
};
struct DedicatedAllocationMemoryAllocateInfoNV {
    StructureType sType = StructureType::DedicatedAllocationMemoryAllocateInfoNV;
    const void * pNext{};
    Image image{};
    Buffer buffer{};
};
struct ExternalImageFormatPropertiesNV {
    ImageFormatProperties imageFormatProperties{};
    ExternalMemoryFeatureFlagsNV externalMemoryFeatures{};
    ExternalMemoryHandleTypeFlagsNV exportFromImportedHandleTypes{};
    ExternalMemoryHandleTypeFlagsNV compatibleHandleTypes{};
};
struct ExternalMemoryImageCreateInfoNV {
    StructureType sType = StructureType::ExternalMemoryImageCreateInfoNV;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagsNV handleTypes{};
};
struct ExportMemoryAllocateInfoNV {
    StructureType sType = StructureType::ExportMemoryAllocateInfoNV;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagsNV handleTypes{};
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportMemoryWin32HandleInfoNV {
    StructureType sType = StructureType::ImportMemoryWin32HandleInfoNV;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagsNV handleType{};
    HANDLE handle{};
};
struct ExportMemoryWin32HandleInfoNV {
    StructureType sType = StructureType::ExportMemoryWin32HandleInfoNV;
    const void * pNext{};
    const SECURITY_ATTRIBUTES * pAttributes{};
    DWORD dwAccess{};
};
struct Win32KeyedMutexAcquireReleaseInfoNV {
    StructureType sType = StructureType::Win32KeyedMutexAcquireReleaseInfoNV;
    const void * pNext{};
    uint32_t acquireCount{};
    const DeviceMemory * pAcquireSyncs{};
    const uint64_t * pAcquireKeys{};
    const uint32_t * pAcquireTimeoutMilliseconds{};
    uint32_t releaseCount{};
    const DeviceMemory * pReleaseSyncs{};
    const uint64_t * pReleaseKeys{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
struct PhysicalDeviceDeviceGeneratedCommandsFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
    void * pNext{};
    Bool32 deviceGeneratedCommands{};
};
struct PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;
    void * pNext{};
    Bool32 deviceGeneratedCompute{};
    Bool32 deviceGeneratedComputePipelines{};
    Bool32 deviceGeneratedComputeCaptureReplay{};
};
struct DevicePrivateDataCreateInfo {
    StructureType sType = StructureType::DevicePrivateDataCreateInfo;
    const void * pNext{};
    uint32_t privateDataSlotRequestCount{};
};
struct PrivateDataSlotCreateInfo {
    StructureType sType = StructureType::PrivateDataSlotCreateInfo;
    const void * pNext{};
    PrivateDataSlotCreateFlags flags{};
};
struct PhysicalDevicePrivateDataFeatures {
    StructureType sType = StructureType::PhysicalDevicePrivateDataFeatures;
    void * pNext{};
    Bool32 privateData{};
};
struct PhysicalDeviceDeviceGeneratedCommandsPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceDeviceGeneratedCommandsPropertiesNV;
    void * pNext{};
    uint32_t maxGraphicsShaderGroupCount{};
    uint32_t maxIndirectSequenceCount{};
    uint32_t maxIndirectCommandsTokenCount{};
    uint32_t maxIndirectCommandsStreamCount{};
    uint32_t maxIndirectCommandsTokenOffset{};
    uint32_t maxIndirectCommandsStreamStride{};
    uint32_t minSequencesCountBufferOffsetAlignment{};
    uint32_t minSequencesIndexBufferOffsetAlignment{};
    uint32_t minIndirectCommandsBufferOffsetAlignment{};
};
struct PhysicalDeviceMultiDrawPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceMultiDrawPropertiesEXT;
    void * pNext{};
    uint32_t maxMultiDrawCount{};
};
struct GraphicsShaderGroupCreateInfoNV {
    StructureType sType = StructureType::GraphicsShaderGroupCreateInfoNV;
    const void * pNext{};
    uint32_t stageCount{};
    const PipelineShaderStageCreateInfo * pStages{};
    const PipelineVertexInputStateCreateInfo * pVertexInputState{};
    const PipelineTessellationStateCreateInfo * pTessellationState{};
};
struct GraphicsPipelineShaderGroupsCreateInfoNV {
    StructureType sType = StructureType::GraphicsPipelineShaderGroupsCreateInfoNV;
    const void * pNext{};
    uint32_t groupCount{};
    const GraphicsShaderGroupCreateInfoNV * pGroups{};
    uint32_t pipelineCount{};
    const Pipeline * pPipelines{};
};
struct BindShaderGroupIndirectCommandNV {
    uint32_t groupIndex{};
};
struct BindIndexBufferIndirectCommandNV {
    DeviceAddress bufferAddress{};
    uint32_t size{};
    IndexType indexType{};
};
struct BindVertexBufferIndirectCommandNV {
    DeviceAddress bufferAddress{};
    uint32_t size{};
    uint32_t stride{};
};
struct SetStateFlagsIndirectCommandNV {
    uint32_t data{};
};
struct IndirectCommandsStreamNV {
    Buffer buffer{};
    DeviceSize offset{};
};
struct IndirectCommandsLayoutTokenNV {
    StructureType sType = StructureType::IndirectCommandsLayoutTokenNV;
    const void * pNext{};
    IndirectCommandsTokenTypeNV tokenType{};
    uint32_t stream{};
    uint32_t offset{};
    uint32_t vertexBindingUnit{};
    Bool32 vertexDynamicStride{};
    PipelineLayout pushconstantPipelineLayout{};
    ShaderStageFlags pushconstantShaderStageFlags{};
    uint32_t pushconstantOffset{};
    uint32_t pushconstantSize{};
    IndirectStateFlagsNV indirectStateFlags{};
    uint32_t indexTypeCount{};
    const IndexType * pIndexTypes{};
    const uint32_t * pIndexTypeValues{};
};
struct IndirectCommandsLayoutCreateInfoNV {
    StructureType sType = StructureType::IndirectCommandsLayoutCreateInfoNV;
    const void * pNext{};
    IndirectCommandsLayoutUsageFlagsNV flags{};
    PipelineBindPoint pipelineBindPoint{};
    uint32_t tokenCount{};
    const IndirectCommandsLayoutTokenNV * pTokens{};
    uint32_t streamCount{};
    const uint32_t * pStreamStrides{};
};
struct GeneratedCommandsInfoNV {
    StructureType sType = StructureType::GeneratedCommandsInfoNV;
    const void * pNext{};
    PipelineBindPoint pipelineBindPoint{};
    Pipeline pipeline{};
    IndirectCommandsLayoutNV indirectCommandsLayout{};
    uint32_t streamCount{};
    const IndirectCommandsStreamNV * pStreams{};
    uint32_t sequencesCount{};
    Buffer preprocessBuffer{};
    DeviceSize preprocessOffset{};
    DeviceSize preprocessSize{};
    Buffer sequencesCountBuffer{};
    DeviceSize sequencesCountOffset{};
    Buffer sequencesIndexBuffer{};
    DeviceSize sequencesIndexOffset{};
};
struct GeneratedCommandsMemoryRequirementsInfoNV {
    StructureType sType = StructureType::GeneratedCommandsMemoryRequirementsInfoNV;
    const void * pNext{};
    PipelineBindPoint pipelineBindPoint{};
    Pipeline pipeline{};
    IndirectCommandsLayoutNV indirectCommandsLayout{};
    uint32_t maxSequencesCount{};
};
struct PipelineIndirectDeviceAddressInfoNV {
    StructureType sType = StructureType::PipelineIndirectDeviceAddressInfoNV;
    const void * pNext{};
    PipelineBindPoint pipelineBindPoint{};
    Pipeline pipeline{};
};
struct BindPipelineIndirectCommandNV {
    DeviceAddress pipelineAddress{};
};
struct PhysicalDeviceFeatures2 {
    StructureType sType = StructureType::PhysicalDeviceFeatures2;
    void * pNext{};
    PhysicalDeviceFeatures features{};
};
struct PhysicalDeviceProperties2 {
    StructureType sType = StructureType::PhysicalDeviceProperties2;
    void * pNext{};
    PhysicalDeviceProperties properties{};
};
struct FormatProperties2 {
    StructureType sType = StructureType::FormatProperties2;
    void * pNext{};
    FormatProperties formatProperties{};
};
struct ImageFormatProperties2 {
    StructureType sType = StructureType::ImageFormatProperties2;
    void * pNext{};
    ImageFormatProperties imageFormatProperties{};
};
struct PhysicalDeviceImageFormatInfo2 {
    StructureType sType = StructureType::PhysicalDeviceImageFormatInfo2;
    const void * pNext{};
    Format format{};
    ImageType type{};
    ImageTiling tiling{};
    ImageUsageFlags usage{};
    ImageCreateFlags flags{};
};
struct QueueFamilyProperties2 {
    StructureType sType = StructureType::QueueFamilyProperties2;
    void * pNext{};
    QueueFamilyProperties queueFamilyProperties{};
};
struct PhysicalDeviceMemoryProperties2 {
    StructureType sType = StructureType::PhysicalDeviceMemoryProperties2;
    void * pNext{};
    PhysicalDeviceMemoryProperties memoryProperties{};
};
struct SparseImageFormatProperties2 {
    StructureType sType = StructureType::SparseImageFormatProperties2;
    void * pNext{};
    SparseImageFormatProperties properties{};
};
struct PhysicalDeviceSparseImageFormatInfo2 {
    StructureType sType = StructureType::PhysicalDeviceSparseImageFormatInfo2;
    const void * pNext{};
    Format format{};
    ImageType type{};
    SampleCountFlagBits samples{};
    ImageUsageFlags usage{};
    ImageTiling tiling{};
};
struct PhysicalDevicePushDescriptorPropertiesKHR {
    StructureType sType = StructureType::PhysicalDevicePushDescriptorPropertiesKHR;
    void * pNext{};
    uint32_t maxPushDescriptors{};
};
struct ConformanceVersion {
    uint8_t major{};
    uint8_t minor{};
    uint8_t subminor{};
    uint8_t patch{};
};
struct PhysicalDeviceDriverProperties {
    StructureType sType = StructureType::PhysicalDeviceDriverProperties;
    void * pNext{};
    DriverId driverID{};
    char driverName [ VK_MAX_DRIVER_NAME_SIZE ]{};
    char driverInfo [ VK_MAX_DRIVER_INFO_SIZE ]{};
    ConformanceVersion conformanceVersion{};
};
struct RectLayerKHR {
    Offset2D offset{};
    Extent2D extent{};
    uint32_t layer{};
};
struct PresentRegionKHR {
    uint32_t rectangleCount{};
    const RectLayerKHR * pRectangles{};
};
struct PresentRegionsKHR {
    StructureType sType = StructureType::PresentRegionsKHR;
    const void * pNext{};
    uint32_t swapchainCount{};
    const PresentRegionKHR * pRegions{};
};
struct PhysicalDeviceVariablePointersFeatures {
    StructureType sType = StructureType::PhysicalDeviceVariablePointersFeatures;
    void * pNext{};
    Bool32 variablePointersStorageBuffer{};
    Bool32 variablePointers{};
};
struct ExternalMemoryProperties {
    ExternalMemoryFeatureFlags externalMemoryFeatures{};
    ExternalMemoryHandleTypeFlags exportFromImportedHandleTypes{};
    ExternalMemoryHandleTypeFlags compatibleHandleTypes{};
};
struct PhysicalDeviceExternalImageFormatInfo {
    StructureType sType = StructureType::PhysicalDeviceExternalImageFormatInfo;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagBits handleType{};
};
struct ExternalImageFormatProperties {
    StructureType sType = StructureType::ExternalImageFormatProperties;
    void * pNext{};
    ExternalMemoryProperties externalMemoryProperties{};
};
struct PhysicalDeviceExternalBufferInfo {
    StructureType sType = StructureType::PhysicalDeviceExternalBufferInfo;
    const void * pNext{};
    BufferCreateFlags flags{};
    BufferUsageFlags usage{};
    ExternalMemoryHandleTypeFlagBits handleType{};
};
struct ExternalBufferProperties {
    StructureType sType = StructureType::ExternalBufferProperties;
    void * pNext{};
    ExternalMemoryProperties externalMemoryProperties{};
};
struct PhysicalDeviceIDProperties {
    StructureType sType = StructureType::PhysicalDeviceIdProperties;
    void * pNext{};
    uint8_t deviceUUID [ VK_UUID_SIZE ]{};
    uint8_t driverUUID [ VK_UUID_SIZE ]{};
    uint8_t deviceLUID [ VK_LUID_SIZE ]{};
    uint32_t deviceNodeMask{};
    Bool32 deviceLUIDValid{};
};
struct ExternalMemoryImageCreateInfo {
    StructureType sType = StructureType::ExternalMemoryImageCreateInfo;
    const void * pNext{};
    ExternalMemoryHandleTypeFlags handleTypes{};
};
struct ExternalMemoryBufferCreateInfo {
    StructureType sType = StructureType::ExternalMemoryBufferCreateInfo;
    const void * pNext{};
    ExternalMemoryHandleTypeFlags handleTypes{};
};
struct ExportMemoryAllocateInfo {
    StructureType sType = StructureType::ExportMemoryAllocateInfo;
    const void * pNext{};
    ExternalMemoryHandleTypeFlags handleTypes{};
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportMemoryWin32HandleInfoKHR {
    StructureType sType = StructureType::ImportMemoryWin32HandleInfoKHR;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagBits handleType{};
    HANDLE handle{};
    LPCWSTR name{};
};
struct ExportMemoryWin32HandleInfoKHR {
    StructureType sType = StructureType::ExportMemoryWin32HandleInfoKHR;
    const void * pNext{};
    const SECURITY_ATTRIBUTES * pAttributes{};
    DWORD dwAccess{};
    LPCWSTR name{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_FUCHSIA)
struct ImportMemoryZirconHandleInfoFUCHSIA {
    StructureType sType = StructureType::ImportMemoryZirconHandleInfoFUCHSIA;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagBits handleType{};
    zx_handle_t handle{};
};
struct MemoryZirconHandlePropertiesFUCHSIA {
    StructureType sType = StructureType::MemoryZirconHandlePropertiesFUCHSIA;
    void * pNext{};
    uint32_t memoryTypeBits{};
};
struct MemoryGetZirconHandleInfoFUCHSIA {
    StructureType sType = StructureType::MemoryGetZirconHandleInfoFUCHSIA;
    const void * pNext{};
    DeviceMemory memory{};
    ExternalMemoryHandleTypeFlagBits handleType{};
};
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct MemoryWin32HandlePropertiesKHR {
    StructureType sType = StructureType::MemoryWin32HandlePropertiesKHR;
    void * pNext{};
    uint32_t memoryTypeBits{};
};
struct MemoryGetWin32HandleInfoKHR {
    StructureType sType = StructureType::MemoryGetWin32HandleInfoKHR;
    const void * pNext{};
    DeviceMemory memory{};
    ExternalMemoryHandleTypeFlagBits handleType{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportMemoryFdInfoKHR {
    StructureType sType = StructureType::ImportMemoryFdInfoKHR;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagBits handleType{};
    int fd{};
};
struct MemoryFdPropertiesKHR {
    StructureType sType = StructureType::MemoryFdPropertiesKHR;
    void * pNext{};
    uint32_t memoryTypeBits{};
};
struct MemoryGetFdInfoKHR {
    StructureType sType = StructureType::MemoryGetFdInfoKHR;
    const void * pNext{};
    DeviceMemory memory{};
    ExternalMemoryHandleTypeFlagBits handleType{};
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct Win32KeyedMutexAcquireReleaseInfoKHR {
    StructureType sType = StructureType::Win32KeyedMutexAcquireReleaseInfoKHR;
    const void * pNext{};
    uint32_t acquireCount{};
    const DeviceMemory * pAcquireSyncs{};
    const uint64_t * pAcquireKeys{};
    const uint32_t * pAcquireTimeouts{};
    uint32_t releaseCount{};
    const DeviceMemory * pReleaseSyncs{};
    const uint64_t * pReleaseKeys{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
struct PhysicalDeviceExternalSemaphoreInfo {
    StructureType sType = StructureType::PhysicalDeviceExternalSemaphoreInfo;
    const void * pNext{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
};
struct ExternalSemaphoreProperties {
    StructureType sType = StructureType::ExternalSemaphoreProperties;
    void * pNext{};
    ExternalSemaphoreHandleTypeFlags exportFromImportedHandleTypes{};
    ExternalSemaphoreHandleTypeFlags compatibleHandleTypes{};
    ExternalSemaphoreFeatureFlags externalSemaphoreFeatures{};
};
struct ExportSemaphoreCreateInfo {
    StructureType sType = StructureType::ExportSemaphoreCreateInfo;
    const void * pNext{};
    ExternalSemaphoreHandleTypeFlags handleTypes{};
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportSemaphoreWin32HandleInfoKHR {
    StructureType sType = StructureType::ImportSemaphoreWin32HandleInfoKHR;
    const void * pNext{};
    Semaphore semaphore{};
    SemaphoreImportFlags flags{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
    HANDLE handle{};
    LPCWSTR name{};
};
struct ExportSemaphoreWin32HandleInfoKHR {
    StructureType sType = StructureType::ExportSemaphoreWin32HandleInfoKHR;
    const void * pNext{};
    const SECURITY_ATTRIBUTES * pAttributes{};
    DWORD dwAccess{};
    LPCWSTR name{};
};
struct D3D12FenceSubmitInfoKHR {
    StructureType sType = StructureType::D3D12FenceSubmitInfoKHR;
    const void * pNext{};
    uint32_t waitSemaphoreValuesCount{};
    const uint64_t * pWaitSemaphoreValues{};
    uint32_t signalSemaphoreValuesCount{};
    const uint64_t * pSignalSemaphoreValues{};
};
struct SemaphoreGetWin32HandleInfoKHR {
    StructureType sType = StructureType::SemaphoreGetWin32HandleInfoKHR;
    const void * pNext{};
    Semaphore semaphore{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportSemaphoreFdInfoKHR {
    StructureType sType = StructureType::ImportSemaphoreFdInfoKHR;
    const void * pNext{};
    Semaphore semaphore{};
    SemaphoreImportFlags flags{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
    int fd{};
};
struct SemaphoreGetFdInfoKHR {
    StructureType sType = StructureType::SemaphoreGetFdInfoKHR;
    const void * pNext{};
    Semaphore semaphore{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
};
#if defined(VK_USE_PLATFORM_FUCHSIA)
struct ImportSemaphoreZirconHandleInfoFUCHSIA {
    StructureType sType = StructureType::ImportSemaphoreZirconHandleInfoFUCHSIA;
    const void * pNext{};
    Semaphore semaphore{};
    SemaphoreImportFlags flags{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
    zx_handle_t zirconHandle{};
};
struct SemaphoreGetZirconHandleInfoFUCHSIA {
    StructureType sType = StructureType::SemaphoreGetZirconHandleInfoFUCHSIA;
    const void * pNext{};
    Semaphore semaphore{};
    ExternalSemaphoreHandleTypeFlagBits handleType{};
};
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
struct PhysicalDeviceExternalFenceInfo {
    StructureType sType = StructureType::PhysicalDeviceExternalFenceInfo;
    const void * pNext{};
    ExternalFenceHandleTypeFlagBits handleType{};
};
struct ExternalFenceProperties {
    StructureType sType = StructureType::ExternalFenceProperties;
    void * pNext{};
    ExternalFenceHandleTypeFlags exportFromImportedHandleTypes{};
    ExternalFenceHandleTypeFlags compatibleHandleTypes{};
    ExternalFenceFeatureFlags externalFenceFeatures{};
};
struct ExportFenceCreateInfo {
    StructureType sType = StructureType::ExportFenceCreateInfo;
    const void * pNext{};
    ExternalFenceHandleTypeFlags handleTypes{};
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportFenceWin32HandleInfoKHR {
    StructureType sType = StructureType::ImportFenceWin32HandleInfoKHR;
    const void * pNext{};
    Fence fence{};
    FenceImportFlags flags{};
    ExternalFenceHandleTypeFlagBits handleType{};
    HANDLE handle{};
    LPCWSTR name{};
};
struct ExportFenceWin32HandleInfoKHR {
    StructureType sType = StructureType::ExportFenceWin32HandleInfoKHR;
    const void * pNext{};
    const SECURITY_ATTRIBUTES * pAttributes{};
    DWORD dwAccess{};
    LPCWSTR name{};
};
struct FenceGetWin32HandleInfoKHR {
    StructureType sType = StructureType::FenceGetWin32HandleInfoKHR;
    const void * pNext{};
    Fence fence{};
    ExternalFenceHandleTypeFlagBits handleType{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
struct ImportFenceFdInfoKHR {
    StructureType sType = StructureType::ImportFenceFdInfoKHR;
    const void * pNext{};
    Fence fence{};
    FenceImportFlags flags{};
    ExternalFenceHandleTypeFlagBits handleType{};
    int fd{};
};
struct FenceGetFdInfoKHR {
    StructureType sType = StructureType::FenceGetFdInfoKHR;
    const void * pNext{};
    Fence fence{};
    ExternalFenceHandleTypeFlagBits handleType{};
};
struct PhysicalDeviceMultiviewFeatures {
    StructureType sType = StructureType::PhysicalDeviceMultiviewFeatures;
    void * pNext{};
    Bool32 multiview{};
    Bool32 multiviewGeometryShader{};
    Bool32 multiviewTessellationShader{};
};
struct PhysicalDeviceMultiviewProperties {
    StructureType sType = StructureType::PhysicalDeviceMultiviewProperties;
    void * pNext{};
    uint32_t maxMultiviewViewCount{};
    uint32_t maxMultiviewInstanceIndex{};
};
struct RenderPassMultiviewCreateInfo {
    StructureType sType = StructureType::RenderPassMultiviewCreateInfo;
    const void * pNext{};
    uint32_t subpassCount{};
    const uint32_t * pViewMasks{};
    uint32_t dependencyCount{};
    const int32_t * pViewOffsets{};
    uint32_t correlationMaskCount{};
    const uint32_t * pCorrelationMasks{};
};
struct SurfaceCapabilities2EXT {
    StructureType sType = StructureType::SurfaceCapabilities2EXT;
    void * pNext{};
    uint32_t minImageCount{};
    uint32_t maxImageCount{};
    Extent2D currentExtent{};
    Extent2D minImageExtent{};
    Extent2D maxImageExtent{};
    uint32_t maxImageArrayLayers{};
    SurfaceTransformFlagsKHR supportedTransforms{};
    SurfaceTransformFlagBitsKHR currentTransform{};
    CompositeAlphaFlagsKHR supportedCompositeAlpha{};
    ImageUsageFlags supportedUsageFlags{};
    SurfaceCounterFlagsEXT supportedSurfaceCounters{};
};
struct DisplayPowerInfoEXT {
    StructureType sType = StructureType::DisplayPowerInfoEXT;
    const void * pNext{};
    DisplayPowerStateEXT powerState{};
};
struct DeviceEventInfoEXT {
    StructureType sType = StructureType::DeviceEventInfoEXT;
    const void * pNext{};
    DeviceEventTypeEXT deviceEvent{};
};
struct DisplayEventInfoEXT {
    StructureType sType = StructureType::DisplayEventInfoEXT;
    const void * pNext{};
    DisplayEventTypeEXT displayEvent{};
};
struct SwapchainCounterCreateInfoEXT {
    StructureType sType = StructureType::SwapchainCounterCreateInfoEXT;
    const void * pNext{};
    SurfaceCounterFlagsEXT surfaceCounters{};
};
struct PhysicalDeviceGroupProperties {
    StructureType sType = StructureType::PhysicalDeviceGroupProperties;
    void * pNext{};
    uint32_t physicalDeviceCount{};
    PhysicalDevice physicalDevices [ VK_MAX_DEVICE_GROUP_SIZE ]{};
    Bool32 subsetAllocation{};
};
struct MemoryAllocateFlagsInfo {
    StructureType sType = StructureType::MemoryAllocateFlagsInfo;
    const void * pNext{};
    MemoryAllocateFlags flags{};
    uint32_t deviceMask{};
};
struct BindBufferMemoryInfo {
    StructureType sType = StructureType::BindBufferMemoryInfo;
    const void * pNext{};
    Buffer buffer{};
    DeviceMemory memory{};
    DeviceSize memoryOffset{};
};
struct BindBufferMemoryDeviceGroupInfo {
    StructureType sType = StructureType::BindBufferMemoryDeviceGroupInfo;
    const void * pNext{};
    uint32_t deviceIndexCount{};
    const uint32_t * pDeviceIndices{};
};
struct BindImageMemoryInfo {
    StructureType sType = StructureType::BindImageMemoryInfo;
    const void * pNext{};
    Image image{};
    DeviceMemory memory{};
    DeviceSize memoryOffset{};
};
struct BindImageMemoryDeviceGroupInfo {
    StructureType sType = StructureType::BindImageMemoryDeviceGroupInfo;
    const void * pNext{};
    uint32_t deviceIndexCount{};
    const uint32_t * pDeviceIndices{};
    uint32_t splitInstanceBindRegionCount{};
    const Rect2D * pSplitInstanceBindRegions{};
};
struct DeviceGroupRenderPassBeginInfo {
    StructureType sType = StructureType::DeviceGroupRenderPassBeginInfo;
    const void * pNext{};
    uint32_t deviceMask{};
    uint32_t deviceRenderAreaCount{};
    const Rect2D * pDeviceRenderAreas{};
};
struct DeviceGroupCommandBufferBeginInfo {
    StructureType sType = StructureType::DeviceGroupCommandBufferBeginInfo;
    const void * pNext{};
    uint32_t deviceMask{};
};
struct DeviceGroupSubmitInfo {
    StructureType sType = StructureType::DeviceGroupSubmitInfo;
    const void * pNext{};
    uint32_t waitSemaphoreCount{};
    const uint32_t * pWaitSemaphoreDeviceIndices{};
    uint32_t commandBufferCount{};
    const uint32_t * pCommandBufferDeviceMasks{};
    uint32_t signalSemaphoreCount{};
    const uint32_t * pSignalSemaphoreDeviceIndices{};
};
struct DeviceGroupBindSparseInfo {
    StructureType sType = StructureType::DeviceGroupBindSparseInfo;
    const void * pNext{};
    uint32_t resourceDeviceIndex{};
    uint32_t memoryDeviceIndex{};
};
struct DeviceGroupPresentCapabilitiesKHR {
    StructureType sType = StructureType::DeviceGroupPresentCapabilitiesKHR;
    void * pNext{};
    uint32_t presentMask [ VK_MAX_DEVICE_GROUP_SIZE ]{};
    DeviceGroupPresentModeFlagsKHR modes{};
};
struct ImageSwapchainCreateInfoKHR {
    StructureType sType = StructureType::ImageSwapchainCreateInfoKHR;
    const void * pNext{};
    SwapchainKHR swapchain{};
};
struct BindImageMemorySwapchainInfoKHR {
    StructureType sType = StructureType::BindImageMemorySwapchainInfoKHR;
    const void * pNext{};
    SwapchainKHR swapchain{};
    uint32_t imageIndex{};
};
struct AcquireNextImageInfoKHR {
    StructureType sType = StructureType::AcquireNextImageInfoKHR;
    const void * pNext{};
    SwapchainKHR swapchain{};
    uint64_t timeout{};
    Semaphore semaphore{};
    Fence fence{};
    uint32_t deviceMask{};
};
struct DeviceGroupPresentInfoKHR {
    StructureType sType = StructureType::DeviceGroupPresentInfoKHR;
    const void * pNext{};
    uint32_t swapchainCount{};
    const uint32_t * pDeviceMasks{};
    DeviceGroupPresentModeFlagBitsKHR mode{};
};
struct DeviceGroupDeviceCreateInfo {
    StructureType sType = StructureType::DeviceGroupDeviceCreateInfo;
    const void * pNext{};
    uint32_t physicalDeviceCount{};
    const PhysicalDevice * pPhysicalDevices{};
};
struct DeviceGroupSwapchainCreateInfoKHR {
    StructureType sType = StructureType::DeviceGroupSwapchainCreateInfoKHR;
    const void * pNext{};
    DeviceGroupPresentModeFlagsKHR modes{};
};
struct DescriptorUpdateTemplateEntry {
    uint32_t dstBinding{};
    uint32_t dstArrayElement{};
    uint32_t descriptorCount{};
    DescriptorType descriptorType{};
    size_t offset{};
    size_t stride{};
};
struct DescriptorUpdateTemplateCreateInfo {
    StructureType sType = StructureType::DescriptorUpdateTemplateCreateInfo;
    const void * pNext{};
    DescriptorUpdateTemplateCreateFlags flags{};
    uint32_t descriptorUpdateEntryCount{};
    const DescriptorUpdateTemplateEntry * pDescriptorUpdateEntries{};
    DescriptorUpdateTemplateType templateType{};
    DescriptorSetLayout descriptorSetLayout{};
    PipelineBindPoint pipelineBindPoint{};
    PipelineLayout pipelineLayout{};
    uint32_t set{};
};
struct XYColorEXT {
    float x{};
    float y{};
};
struct PhysicalDevicePresentIdFeaturesKHR {
    StructureType sType = StructureType::PhysicalDevicePresentIdFeaturesKHR;
    void * pNext{};
    Bool32 presentId{};
};
struct PresentIdKHR {
    StructureType sType = StructureType::PresentIdKHR;
    const void * pNext{};
    uint32_t swapchainCount{};
    const uint64_t * pPresentIds{};
};
struct PhysicalDevicePresentWaitFeaturesKHR {
    StructureType sType = StructureType::PhysicalDevicePresentWaitFeaturesKHR;
    void * pNext{};
    Bool32 presentWait{};
};
struct HdrMetadataEXT {
    StructureType sType = StructureType::HdrMetadataEXT;
    const void * pNext{};
    XYColorEXT displayPrimaryRed{};
    XYColorEXT displayPrimaryGreen{};
    XYColorEXT displayPrimaryBlue{};
    XYColorEXT whitePoint{};
    float maxLuminance{};
    float minLuminance{};
    float maxContentLightLevel{};
    float maxFrameAverageLightLevel{};
};
struct DisplayNativeHdrSurfaceCapabilitiesAMD {
    StructureType sType = StructureType::DisplayNativeHdrSurfaceCapabilitiesAMD;
    void * pNext{};
    Bool32 localDimmingSupport{};
};
struct SwapchainDisplayNativeHdrCreateInfoAMD {
    StructureType sType = StructureType::SwapchainDisplayNativeHdrCreateInfoAMD;
    const void * pNext{};
    Bool32 localDimmingEnable{};
};
struct RefreshCycleDurationGOOGLE {
    uint64_t refreshDuration{};
};
struct PastPresentationTimingGOOGLE {
    uint32_t presentID{};
    uint64_t desiredPresentTime{};
    uint64_t actualPresentTime{};
    uint64_t earliestPresentTime{};
    uint64_t presentMargin{};
};
struct PresentTimeGOOGLE {
    uint32_t presentID{};
    uint64_t desiredPresentTime{};
};
struct PresentTimesInfoGOOGLE {
    StructureType sType = StructureType::PresentTimesInfoGOOGLE;
    const void * pNext{};
    uint32_t swapchainCount{};
    const PresentTimeGOOGLE * pTimes{};
};
#if defined(VK_USE_PLATFORM_IOS_MVK)
struct IOSSurfaceCreateInfoMVK {
    StructureType sType = StructureType::IosSurfaceCreateInfoMVK;
    const void * pNext{};
    IOSSurfaceCreateFlagsMVK flags{};
    const void * pView{};
};
#endif // defined(VK_USE_PLATFORM_IOS_MVK)
#if defined(VK_USE_PLATFORM_MACOS_MVK)
struct MacOSSurfaceCreateInfoMVK {
    StructureType sType = StructureType::MacosSurfaceCreateInfoMVK;
    const void * pNext{};
    MacOSSurfaceCreateFlagsMVK flags{};
    const void * pView{};
};
#endif // defined(VK_USE_PLATFORM_MACOS_MVK)
#if defined(VK_USE_PLATFORM_METAL_EXT)
struct MetalSurfaceCreateInfoEXT {
    StructureType sType = StructureType::MetalSurfaceCreateInfoEXT;
    const void * pNext{};
    MetalSurfaceCreateFlagsEXT flags{};
    const CAMetalLayer * pLayer{};
};
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
struct ViewportWScalingNV {
    float xcoeff{};
    float ycoeff{};
};
struct PipelineViewportWScalingStateCreateInfoNV {
    StructureType sType = StructureType::PipelineViewportWScalingStateCreateInfoNV;
    const void * pNext{};
    Bool32 viewportWScalingEnable{};
    uint32_t viewportCount{};
    const ViewportWScalingNV * pViewportWScalings{};
};
struct ViewportSwizzleNV {
    ViewportCoordinateSwizzleNV x{};
    ViewportCoordinateSwizzleNV y{};
    ViewportCoordinateSwizzleNV z{};
    ViewportCoordinateSwizzleNV w{};
};
struct PipelineViewportSwizzleStateCreateInfoNV {
    StructureType sType = StructureType::PipelineViewportSwizzleStateCreateInfoNV;
    const void * pNext{};
    PipelineViewportSwizzleStateCreateFlagsNV flags{};
    uint32_t viewportCount{};
    const ViewportSwizzleNV * pViewportSwizzles{};
};
struct PhysicalDeviceDiscardRectanglePropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceDiscardRectanglePropertiesEXT;
    void * pNext{};
    uint32_t maxDiscardRectangles{};
};
struct PipelineDiscardRectangleStateCreateInfoEXT {
    StructureType sType = StructureType::PipelineDiscardRectangleStateCreateInfoEXT;
    const void * pNext{};
    PipelineDiscardRectangleStateCreateFlagsEXT flags{};
    DiscardRectangleModeEXT discardRectangleMode{};
    uint32_t discardRectangleCount{};
    const Rect2D * pDiscardRectangles{};
};
struct PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX {
    StructureType sType = StructureType::PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
    void * pNext{};
    Bool32 perViewPositionAllComponents{};
};
struct InputAttachmentAspectReference {
    uint32_t subpass{};
    uint32_t inputAttachmentIndex{};
    ImageAspectFlags aspectMask{};
};
struct RenderPassInputAttachmentAspectCreateInfo {
    StructureType sType = StructureType::RenderPassInputAttachmentAspectCreateInfo;
    const void * pNext{};
    uint32_t aspectReferenceCount{};
    const InputAttachmentAspectReference * pAspectReferences{};
};
struct PhysicalDeviceSurfaceInfo2KHR {
    StructureType sType = StructureType::PhysicalDeviceSurfaceInfo2KHR;
    const void * pNext{};
    SurfaceKHR surface{};
};
struct SurfaceCapabilities2KHR {
    StructureType sType = StructureType::SurfaceCapabilities2KHR;
    void * pNext{};
    SurfaceCapabilitiesKHR surfaceCapabilities{};
};
struct SurfaceFormat2KHR {
    StructureType sType = StructureType::SurfaceFormat2KHR;
    void * pNext{};
    SurfaceFormatKHR surfaceFormat{};
};
struct DisplayProperties2KHR {
    StructureType sType = StructureType::DisplayProperties2KHR;
    void * pNext{};
    DisplayPropertiesKHR displayProperties{};
};
struct DisplayPlaneProperties2KHR {
    StructureType sType = StructureType::DisplayPlaneProperties2KHR;
    void * pNext{};
    DisplayPlanePropertiesKHR displayPlaneProperties{};
};
struct DisplayModeProperties2KHR {
    StructureType sType = StructureType::DisplayModeProperties2KHR;
    void * pNext{};
    DisplayModePropertiesKHR displayModeProperties{};
};
struct DisplayPlaneInfo2KHR {
    StructureType sType = StructureType::DisplayPlaneInfo2KHR;
    const void * pNext{};
    DisplayModeKHR mode{};
    uint32_t planeIndex{};
};
struct DisplayPlaneCapabilities2KHR {
    StructureType sType = StructureType::DisplayPlaneCapabilities2KHR;
    void * pNext{};
    DisplayPlaneCapabilitiesKHR capabilities{};
};
struct SharedPresentSurfaceCapabilitiesKHR {
    StructureType sType = StructureType::SharedPresentSurfaceCapabilitiesKHR;
    void * pNext{};
    ImageUsageFlags sharedPresentSupportedUsageFlags{};
};
struct PhysicalDevice16BitStorageFeatures {
    StructureType sType = StructureType::PhysicalDevice16StorageFeatures;
    void * pNext{};
    Bool32 storageBuffer16BitAccess{};
    Bool32 uniformAndStorageBuffer16BitAccess{};
    Bool32 storagePushConstant16{};
    Bool32 storageInputOutput16{};
};
struct PhysicalDeviceSubgroupProperties {
    StructureType sType = StructureType::PhysicalDeviceSubgroupProperties;
    void * pNext{};
    uint32_t subgroupSize{};
    ShaderStageFlags supportedStages{};
    SubgroupFeatureFlags supportedOperations{};
    Bool32 quadOperationsInAllStages{};
};
struct PhysicalDeviceShaderSubgroupExtendedTypesFeatures {
    StructureType sType = StructureType::PhysicalDeviceShaderSubgroupExtendedTypesFeatures;
    void * pNext{};
    Bool32 shaderSubgroupExtendedTypes{};
};
struct BufferMemoryRequirementsInfo2 {
    StructureType sType = StructureType::BufferMemoryRequirementsInfo2;
    const void * pNext{};
    Buffer buffer{};
};
struct DeviceBufferMemoryRequirements {
    StructureType sType = StructureType::DeviceBufferMemoryRequirements;
    const void * pNext{};
    const BufferCreateInfo * pCreateInfo{};
};
struct ImageMemoryRequirementsInfo2 {
    StructureType sType = StructureType::ImageMemoryRequirementsInfo2;
    const void * pNext{};
    Image image{};
};
struct ImageSparseMemoryRequirementsInfo2 {
    StructureType sType = StructureType::ImageSparseMemoryRequirementsInfo2;
    const void * pNext{};
    Image image{};
};
struct DeviceImageMemoryRequirements {
    StructureType sType = StructureType::DeviceImageMemoryRequirements;
    const void * pNext{};
    const ImageCreateInfo * pCreateInfo{};
    ImageAspectFlagBits planeAspect{};
};
struct MemoryRequirements2 {
    StructureType sType = StructureType::MemoryRequirements2;
    void * pNext{};
    MemoryRequirements memoryRequirements{};
};
struct SparseImageMemoryRequirements2 {
    StructureType sType = StructureType::SparseImageMemoryRequirements2;
    void * pNext{};
    SparseImageMemoryRequirements memoryRequirements{};
};
struct PhysicalDevicePointClippingProperties {
    StructureType sType = StructureType::PhysicalDevicePointClippingProperties;
    void * pNext{};
    PointClippingBehavior pointClippingBehavior{};
};
struct MemoryDedicatedRequirements {
    StructureType sType = StructureType::MemoryDedicatedRequirements;
    void * pNext{};
    Bool32 prefersDedicatedAllocation{};
    Bool32 requiresDedicatedAllocation{};
};
struct MemoryDedicatedAllocateInfo {
    StructureType sType = StructureType::MemoryDedicatedAllocateInfo;
    const void * pNext{};
    Image image{};
    Buffer buffer{};
};
struct ImageViewUsageCreateInfo {
    StructureType sType = StructureType::ImageViewUsageCreateInfo;
    const void * pNext{};
    ImageUsageFlags usage{};
};
struct ImageViewSlicedCreateInfoEXT {
    StructureType sType = StructureType::ImageViewSlicedCreateInfoEXT;
    const void * pNext{};
    uint32_t sliceOffset{};
    uint32_t sliceCount{};
};
struct PipelineTessellationDomainOriginStateCreateInfo {
    StructureType sType = StructureType::PipelineTessellationDomainOriginStateCreateInfo;
    const void * pNext{};
    TessellationDomainOrigin domainOrigin{};
};
struct SamplerYcbcrConversionInfo {
    StructureType sType = StructureType::SamplerYcbcrConversionInfo;
    const void * pNext{};
    SamplerYcbcrConversion conversion{};
};
struct SamplerYcbcrConversionCreateInfo {
    StructureType sType = StructureType::SamplerYcbcrConversionCreateInfo;
    const void * pNext{};
    Format format{};
    SamplerYcbcrModelConversion ycbcrModel{};
    SamplerYcbcrRange ycbcrRange{};
    ComponentMapping components{};
    ChromaLocation xChromaOffset{};
    ChromaLocation yChromaOffset{};
    Filter chromaFilter{};
    Bool32 forceExplicitReconstruction{};
};
struct BindImagePlaneMemoryInfo {
    StructureType sType = StructureType::BindImagePlaneMemoryInfo;
    const void * pNext{};
    ImageAspectFlagBits planeAspect{};
};
struct ImagePlaneMemoryRequirementsInfo {
    StructureType sType = StructureType::ImagePlaneMemoryRequirementsInfo;
    const void * pNext{};
    ImageAspectFlagBits planeAspect{};
};
struct PhysicalDeviceSamplerYcbcrConversionFeatures {
    StructureType sType = StructureType::PhysicalDeviceSamplerYcbcrConversionFeatures;
    void * pNext{};
    Bool32 samplerYcbcrConversion{};
};
struct SamplerYcbcrConversionImageFormatProperties {
    StructureType sType = StructureType::SamplerYcbcrConversionImageFormatProperties;
    void * pNext{};
    uint32_t combinedImageSamplerDescriptorCount{};
};
struct TextureLODGatherFormatPropertiesAMD {
    StructureType sType = StructureType::TextureLodGatherFormatPropertiesAMD;
    void * pNext{};
    Bool32 supportsTextureGatherLODBiasAMD{};
};
struct ConditionalRenderingBeginInfoEXT {
    StructureType sType = StructureType::ConditionalRenderingBeginInfoEXT;
    const void * pNext{};
    Buffer buffer{};
    DeviceSize offset{};
    ConditionalRenderingFlagsEXT flags{};
};
struct ProtectedSubmitInfo {
    StructureType sType = StructureType::ProtectedSubmitInfo;
    const void * pNext{};
    Bool32 protectedSubmit{};
};
struct PhysicalDeviceProtectedMemoryFeatures {
    StructureType sType = StructureType::PhysicalDeviceProtectedMemoryFeatures;
    void * pNext{};
    Bool32 protectedMemory{};
};
struct PhysicalDeviceProtectedMemoryProperties {
    StructureType sType = StructureType::PhysicalDeviceProtectedMemoryProperties;
    void * pNext{};
    Bool32 protectedNoFault{};
};
struct DeviceQueueInfo2 {
    StructureType sType = StructureType::DeviceQueueInfo2;
    const void * pNext{};
    DeviceQueueCreateFlags flags{};
    uint32_t queueFamilyIndex{};
    uint32_t queueIndex{};
};
struct PipelineCoverageToColorStateCreateInfoNV {
    StructureType sType = StructureType::PipelineCoverageToColorStateCreateInfoNV;
    const void * pNext{};
    PipelineCoverageToColorStateCreateFlagsNV flags{};
    Bool32 coverageToColorEnable{};
    uint32_t coverageToColorLocation{};
};
struct PhysicalDeviceSamplerFilterMinmaxProperties {
    StructureType sType = StructureType::PhysicalDeviceSamplerFilterMinmaxProperties;
    void * pNext{};
    Bool32 filterMinmaxSingleComponentFormats{};
    Bool32 filterMinmaxImageComponentMapping{};
};
struct SampleLocationEXT {
    float x{};
    float y{};
};
struct SampleLocationsInfoEXT {
    StructureType sType = StructureType::SampleLocationsInfoEXT;
    const void * pNext{};
    SampleCountFlagBits sampleLocationsPerPixel{};
    Extent2D sampleLocationGridSize{};
    uint32_t sampleLocationsCount{};
    const SampleLocationEXT * pSampleLocations{};
};
struct AttachmentSampleLocationsEXT {
    uint32_t attachmentIndex{};
    SampleLocationsInfoEXT sampleLocationsInfo{};
};
struct SubpassSampleLocationsEXT {
    uint32_t subpassIndex{};
    SampleLocationsInfoEXT sampleLocationsInfo{};
};
struct RenderPassSampleLocationsBeginInfoEXT {
    StructureType sType = StructureType::RenderPassSampleLocationsBeginInfoEXT;
    const void * pNext{};
    uint32_t attachmentInitialSampleLocationsCount{};
    const AttachmentSampleLocationsEXT * pAttachmentInitialSampleLocations{};
    uint32_t postSubpassSampleLocationsCount{};
    const SubpassSampleLocationsEXT * pPostSubpassSampleLocations{};
};
struct PipelineSampleLocationsStateCreateInfoEXT {
    StructureType sType = StructureType::PipelineSampleLocationsStateCreateInfoEXT;
    const void * pNext{};
    Bool32 sampleLocationsEnable{};
    SampleLocationsInfoEXT sampleLocationsInfo{};
};
struct PhysicalDeviceSampleLocationsPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceSampleLocationsPropertiesEXT;
    void * pNext{};
    SampleCountFlags sampleLocationSampleCounts{};
    Extent2D maxSampleLocationGridSize{};
    float sampleLocationCoordinateRange [2]{};
    uint32_t sampleLocationSubPixelBits{};
    Bool32 variableSampleLocations{};
};
struct MultisamplePropertiesEXT {
    StructureType sType = StructureType::MultisamplePropertiesEXT;
    void * pNext{};
    Extent2D maxSampleLocationGridSize{};
};
struct SamplerReductionModeCreateInfo {
    StructureType sType = StructureType::SamplerReductionModeCreateInfo;
    const void * pNext{};
    SamplerReductionMode reductionMode{};
};
struct PhysicalDeviceBlendOperationAdvancedFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceBlendOperationAdvancedFeaturesEXT;
    void * pNext{};
    Bool32 advancedBlendCoherentOperations{};
};
struct PhysicalDeviceMultiDrawFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceMultiDrawFeaturesEXT;
    void * pNext{};
    Bool32 multiDraw{};
};
struct PhysicalDeviceBlendOperationAdvancedPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceBlendOperationAdvancedPropertiesEXT;
    void * pNext{};
    uint32_t advancedBlendMaxColorAttachments{};
    Bool32 advancedBlendIndependentBlend{};
    Bool32 advancedBlendNonPremultipliedSrcColor{};
    Bool32 advancedBlendNonPremultipliedDstColor{};
    Bool32 advancedBlendCorrelatedOverlap{};
    Bool32 advancedBlendAllOperations{};
};
struct PipelineColorBlendAdvancedStateCreateInfoEXT {
    StructureType sType = StructureType::PipelineColorBlendAdvancedStateCreateInfoEXT;
    const void * pNext{};
    Bool32 srcPremultiplied{};
    Bool32 dstPremultiplied{};
    BlendOverlapEXT blendOverlap{};
};
struct PhysicalDeviceInlineUniformBlockFeatures {
    StructureType sType = StructureType::PhysicalDeviceInlineUniformBlockFeatures;
    void * pNext{};
    Bool32 inlineUniformBlock{};
    Bool32 descriptorBindingInlineUniformBlockUpdateAfterBind{};
};
struct PhysicalDeviceInlineUniformBlockProperties {
    StructureType sType = StructureType::PhysicalDeviceInlineUniformBlockProperties;
    void * pNext{};
    uint32_t maxInlineUniformBlockSize{};
    uint32_t maxPerStageDescriptorInlineUniformBlocks{};
    uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks{};
    uint32_t maxDescriptorSetInlineUniformBlocks{};
    uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks{};
};
struct WriteDescriptorSetInlineUniformBlock {
    StructureType sType = StructureType::WriteDescriptorSetInlineUniformBlock;
    const void * pNext{};
    uint32_t dataSize{};
    const void * pData{};
};
struct DescriptorPoolInlineUniformBlockCreateInfo {
    StructureType sType = StructureType::DescriptorPoolInlineUniformBlockCreateInfo;
    const void * pNext{};
    uint32_t maxInlineUniformBlockBindings{};
};
struct PipelineCoverageModulationStateCreateInfoNV {
    StructureType sType = StructureType::PipelineCoverageModulationStateCreateInfoNV;
    const void * pNext{};
    PipelineCoverageModulationStateCreateFlagsNV flags{};
    CoverageModulationModeNV coverageModulationMode{};
    Bool32 coverageModulationTableEnable{};
    uint32_t coverageModulationTableCount{};
    const float * pCoverageModulationTable{};
};
struct ImageFormatListCreateInfo {
    StructureType sType = StructureType::ImageFormatListCreateInfo;
    const void * pNext{};
    uint32_t viewFormatCount{};
    const Format * pViewFormats{};
};
struct ValidationCacheCreateInfoEXT {
    StructureType sType = StructureType::ValidationCacheCreateInfoEXT;
    const void * pNext{};
    ValidationCacheCreateFlagsEXT flags{};
    size_t initialDataSize{};
    const void * pInitialData{};
};
struct ShaderModuleValidationCacheCreateInfoEXT {
    StructureType sType = StructureType::ShaderModuleValidationCacheCreateInfoEXT;
    const void * pNext{};
    ValidationCacheEXT validationCache{};
};
struct PhysicalDeviceMaintenance3Properties {
    StructureType sType = StructureType::PhysicalDeviceMaintenance3Properties;
    void * pNext{};
    uint32_t maxPerSetDescriptors{};
    DeviceSize maxMemoryAllocationSize{};
};
struct PhysicalDeviceMaintenance4Features {
    StructureType sType = StructureType::PhysicalDeviceMaintenance4Features;
    void * pNext{};
    Bool32 maintenance4{};
};
struct PhysicalDeviceMaintenance4Properties {
    StructureType sType = StructureType::PhysicalDeviceMaintenance4Properties;
    void * pNext{};
    DeviceSize maxBufferSize{};
};
struct PhysicalDeviceMaintenance5FeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceMaintenance5FeaturesKHR;
    void * pNext{};
    Bool32 maintenance5{};
};
struct PhysicalDeviceMaintenance5PropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceMaintenance5PropertiesKHR;
    void * pNext{};
    Bool32 earlyFragmentMultisampleCoverageAfterSampleCounting{};
    Bool32 earlyFragmentSampleMaskTestBeforeSampleCounting{};
    Bool32 depthStencilSwizzleOneSupport{};
    Bool32 polygonModePointSize{};
    Bool32 nonStrictSinglePixelWideLinesUseParallelogram{};
    Bool32 nonStrictWideLinesUseParallelogram{};
};
struct PhysicalDeviceMaintenance6FeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceMaintenance6FeaturesKHR;
    void * pNext{};
    Bool32 maintenance6{};
};
struct PhysicalDeviceMaintenance6PropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceMaintenance6PropertiesKHR;
    void * pNext{};
    Bool32 blockTexelViewCompatibleMultipleLayers{};
    uint32_t maxCombinedImageSamplerDescriptorCount{};
    Bool32 fragmentShadingRateClampCombinerInputs{};
};
struct RenderingAreaInfoKHR {
    StructureType sType = StructureType::RenderingAreaInfoKHR;
    const void * pNext{};
    uint32_t viewMask{};
    uint32_t colorAttachmentCount{};
    const Format * pColorAttachmentFormats{};
    Format depthAttachmentFormat{};
    Format stencilAttachmentFormat{};
};
struct DescriptorSetLayoutSupport {
    StructureType sType = StructureType::DescriptorSetLayoutSupport;
    void * pNext{};
    Bool32 supported{};
};
struct PhysicalDeviceShaderDrawParametersFeatures {
    StructureType sType = StructureType::PhysicalDeviceShaderDrawParametersFeatures;
    void * pNext{};
    Bool32 shaderDrawParameters{};
};
struct PhysicalDeviceShaderFloat16Int8Features {
    StructureType sType = StructureType::PhysicalDeviceShaderFloat16Int8Features;
    void * pNext{};
    Bool32 shaderFloat16{};
    Bool32 shaderInt8{};
};
struct PhysicalDeviceFloatControlsProperties {
    StructureType sType = StructureType::PhysicalDeviceFloatControlsProperties;
    void * pNext{};
    ShaderFloatControlsIndependence denormBehaviorIndependence{};
    ShaderFloatControlsIndependence roundingModeIndependence{};
    Bool32 shaderSignedZeroInfNanPreserveFloat16{};
    Bool32 shaderSignedZeroInfNanPreserveFloat32{};
    Bool32 shaderSignedZeroInfNanPreserveFloat64{};
    Bool32 shaderDenormPreserveFloat16{};
    Bool32 shaderDenormPreserveFloat32{};
    Bool32 shaderDenormPreserveFloat64{};
    Bool32 shaderDenormFlushToZeroFloat16{};
    Bool32 shaderDenormFlushToZeroFloat32{};
    Bool32 shaderDenormFlushToZeroFloat64{};
    Bool32 shaderRoundingModeRTEFloat16{};
    Bool32 shaderRoundingModeRTEFloat32{};
    Bool32 shaderRoundingModeRTEFloat64{};
    Bool32 shaderRoundingModeRTZFloat16{};
    Bool32 shaderRoundingModeRTZFloat32{};
    Bool32 shaderRoundingModeRTZFloat64{};
};
struct PhysicalDeviceHostQueryResetFeatures {
    StructureType sType = StructureType::PhysicalDeviceHostQueryResetFeatures;
    void * pNext{};
    Bool32 hostQueryReset{};
};
struct ShaderResourceUsageAMD {
    uint32_t numUsedVgprs{};
    uint32_t numUsedSgprs{};
    uint32_t ldsSizePerLocalWorkGroup{};
    size_t ldsUsageSizeInBytes{};
    size_t scratchMemUsageInBytes{};
};
struct ShaderStatisticsInfoAMD {
    ShaderStageFlags shaderStageMask{};
    ShaderResourceUsageAMD resourceUsage{};
    uint32_t numPhysicalVgprs{};
    uint32_t numPhysicalSgprs{};
    uint32_t numAvailableVgprs{};
    uint32_t numAvailableSgprs{};
    uint32_t computeWorkGroupSize [3]{};
};
struct DeviceQueueGlobalPriorityCreateInfoKHR {
    StructureType sType = StructureType::DeviceQueueGlobalPriorityCreateInfoKHR;
    const void * pNext{};
    QueueGlobalPriorityKHR globalPriority{};
};
struct PhysicalDeviceGlobalPriorityQueryFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceGlobalPriorityQueryFeaturesKHR;
    void * pNext{};
    Bool32 globalPriorityQuery{};
};
struct QueueFamilyGlobalPriorityPropertiesKHR {
    StructureType sType = StructureType::QueueFamilyGlobalPriorityPropertiesKHR;
    void * pNext{};
    uint32_t priorityCount{};
    QueueGlobalPriorityKHR priorities [ VK_MAX_GLOBAL_PRIORITY_SIZE_KHR ]{};
};
struct DebugUtilsObjectNameInfoEXT {
    StructureType sType = StructureType::DebugUtilsObjectNameInfoEXT;
    const void * pNext{};
    ObjectType objectType{};
    uint64_t objectHandle{};
    const char * pObjectName{};
};
struct DebugUtilsObjectTagInfoEXT {
    StructureType sType = StructureType::DebugUtilsObjectTagInfoEXT;
    const void * pNext{};
    ObjectType objectType{};
    uint64_t objectHandle{};
    uint64_t tagName{};
    size_t tagSize{};
    const void * pTag{};
};
struct DebugUtilsLabelEXT {
    StructureType sType = StructureType::DebugUtilsLabelEXT;
    const void * pNext{};
    const char * pLabelName{};
    float color [4]{};
};
struct DebugUtilsMessengerCreateInfoEXT {
    StructureType sType = StructureType::DebugUtilsMessengerCreateInfoEXT;
    const void * pNext{};
    DebugUtilsMessengerCreateFlagsEXT flags{};
    DebugUtilsMessageSeverityFlagsEXT messageSeverity{};
    DebugUtilsMessageTypeFlagsEXT messageType{};
    PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback{};
    void * pUserData{};
};
struct DebugUtilsMessengerCallbackDataEXT {
    StructureType sType = StructureType::DebugUtilsMessengerCallbackDataEXT;
    const void * pNext{};
    DebugUtilsMessengerCallbackDataFlagsEXT flags{};
    const char * pMessageIdName{};
    int32_t messageIdNumber{};
    const char * pMessage{};
    uint32_t queueLabelCount{};
    const DebugUtilsLabelEXT * pQueueLabels{};
    uint32_t cmdBufLabelCount{};
    const DebugUtilsLabelEXT * pCmdBufLabels{};
    uint32_t objectCount{};
    const DebugUtilsObjectNameInfoEXT * pObjects{};
};
struct PhysicalDeviceDeviceMemoryReportFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDeviceMemoryReportFeaturesEXT;
    void * pNext{};
    Bool32 deviceMemoryReport{};
};
struct DeviceDeviceMemoryReportCreateInfoEXT {
    StructureType sType = StructureType::DeviceDeviceMemoryReportCreateInfoEXT;
    const void * pNext{};
    DeviceMemoryReportFlagsEXT flags{};
    PFN_vkDeviceMemoryReportCallbackEXT pfnUserCallback{};
    void * pUserData{};
};
struct DeviceMemoryReportCallbackDataEXT {
    StructureType sType = StructureType::DeviceMemoryReportCallbackDataEXT;
    void * pNext{};
    DeviceMemoryReportFlagsEXT flags{};
    DeviceMemoryReportEventTypeEXT type{};
    uint64_t memoryObjectId{};
    DeviceSize size{};
    ObjectType objectType{};
    uint64_t objectHandle{};
    uint32_t heapIndex{};
};
struct ImportMemoryHostPointerInfoEXT {
    StructureType sType = StructureType::ImportMemoryHostPointerInfoEXT;
    const void * pNext{};
    ExternalMemoryHandleTypeFlagBits handleType{};
    void * pHostPointer{};
};
struct MemoryHostPointerPropertiesEXT {
    StructureType sType = StructureType::MemoryHostPointerPropertiesEXT;
    void * pNext{};
    uint32_t memoryTypeBits{};
};
struct PhysicalDeviceExternalMemoryHostPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceExternalMemoryHostPropertiesEXT;
    void * pNext{};
    DeviceSize minImportedHostPointerAlignment{};
};
struct PhysicalDeviceConservativeRasterizationPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceConservativeRasterizationPropertiesEXT;
    void * pNext{};
    float primitiveOverestimationSize{};
    float maxExtraPrimitiveOverestimationSize{};
    float extraPrimitiveOverestimationSizeGranularity{};
    Bool32 primitiveUnderestimation{};
    Bool32 conservativePointAndLineRasterization{};
    Bool32 degenerateTrianglesRasterized{};
    Bool32 degenerateLinesRasterized{};
    Bool32 fullyCoveredFragmentShaderInputVariable{};
    Bool32 conservativeRasterizationPostDepthCoverage{};
};
struct CalibratedTimestampInfoKHR {
    StructureType sType = StructureType::CalibratedTimestampInfoKHR;
    const void * pNext{};
    TimeDomainKHR timeDomain{};
};
struct PhysicalDeviceShaderCorePropertiesAMD {
    StructureType sType = StructureType::PhysicalDeviceShaderCorePropertiesAMD;
    void * pNext{};
    uint32_t shaderEngineCount{};
    uint32_t shaderArraysPerEngineCount{};
    uint32_t computeUnitsPerShaderArray{};
    uint32_t simdPerComputeUnit{};
    uint32_t wavefrontsPerSimd{};
    uint32_t wavefrontSize{};
    uint32_t sgprsPerSimd{};
    uint32_t minSgprAllocation{};
    uint32_t maxSgprAllocation{};
    uint32_t sgprAllocationGranularity{};
    uint32_t vgprsPerSimd{};
    uint32_t minVgprAllocation{};
    uint32_t maxVgprAllocation{};
    uint32_t vgprAllocationGranularity{};
};
struct PhysicalDeviceShaderCoreProperties2AMD {
    StructureType sType = StructureType::PhysicalDeviceShaderCoreProperties2AMD;
    void * pNext{};
    ShaderCorePropertiesFlagsAMD shaderCoreFeatures{};
    uint32_t activeComputeUnitCount{};
};
struct PipelineRasterizationConservativeStateCreateInfoEXT {
    StructureType sType = StructureType::PipelineRasterizationConservativeStateCreateInfoEXT;
    const void * pNext{};
    PipelineRasterizationConservativeStateCreateFlagsEXT flags{};
    ConservativeRasterizationModeEXT conservativeRasterizationMode{};
    float extraPrimitiveOverestimationSize{};
};
struct PhysicalDeviceDescriptorIndexingFeatures {
    StructureType sType = StructureType::PhysicalDeviceDescriptorIndexingFeatures;
    void * pNext{};
    Bool32 shaderInputAttachmentArrayDynamicIndexing{};
    Bool32 shaderUniformTexelBufferArrayDynamicIndexing{};
    Bool32 shaderStorageTexelBufferArrayDynamicIndexing{};
    Bool32 shaderUniformBufferArrayNonUniformIndexing{};
    Bool32 shaderSampledImageArrayNonUniformIndexing{};
    Bool32 shaderStorageBufferArrayNonUniformIndexing{};
    Bool32 shaderStorageImageArrayNonUniformIndexing{};
    Bool32 shaderInputAttachmentArrayNonUniformIndexing{};
    Bool32 shaderUniformTexelBufferArrayNonUniformIndexing{};
    Bool32 shaderStorageTexelBufferArrayNonUniformIndexing{};
    Bool32 descriptorBindingUniformBufferUpdateAfterBind{};
    Bool32 descriptorBindingSampledImageUpdateAfterBind{};
    Bool32 descriptorBindingStorageImageUpdateAfterBind{};
    Bool32 descriptorBindingStorageBufferUpdateAfterBind{};
    Bool32 descriptorBindingUniformTexelBufferUpdateAfterBind{};
    Bool32 descriptorBindingStorageTexelBufferUpdateAfterBind{};
    Bool32 descriptorBindingUpdateUnusedWhilePending{};
    Bool32 descriptorBindingPartiallyBound{};
    Bool32 descriptorBindingVariableDescriptorCount{};
    Bool32 runtimeDescriptorArray{};
};
struct PhysicalDeviceDescriptorIndexingProperties {
    StructureType sType = StructureType::PhysicalDeviceDescriptorIndexingProperties;
    void * pNext{};
    uint32_t maxUpdateAfterBindDescriptorsInAllPools{};
    Bool32 shaderUniformBufferArrayNonUniformIndexingNative{};
    Bool32 shaderSampledImageArrayNonUniformIndexingNative{};
    Bool32 shaderStorageBufferArrayNonUniformIndexingNative{};
    Bool32 shaderStorageImageArrayNonUniformIndexingNative{};
    Bool32 shaderInputAttachmentArrayNonUniformIndexingNative{};
    Bool32 robustBufferAccessUpdateAfterBind{};
    Bool32 quadDivergentImplicitLod{};
    uint32_t maxPerStageDescriptorUpdateAfterBindSamplers{};
    uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers{};
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers{};
    uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages{};
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages{};
    uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments{};
    uint32_t maxPerStageUpdateAfterBindResources{};
    uint32_t maxDescriptorSetUpdateAfterBindSamplers{};
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers{};
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic{};
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers{};
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic{};
    uint32_t maxDescriptorSetUpdateAfterBindSampledImages{};
    uint32_t maxDescriptorSetUpdateAfterBindStorageImages{};
    uint32_t maxDescriptorSetUpdateAfterBindInputAttachments{};
};
struct DescriptorSetLayoutBindingFlagsCreateInfo {
    StructureType sType = StructureType::DescriptorSetLayoutBindingFlagsCreateInfo;
    const void * pNext{};
    uint32_t bindingCount{};
    const DescriptorBindingFlags * pBindingFlags{};
};
struct DescriptorSetVariableDescriptorCountAllocateInfo {
    StructureType sType = StructureType::DescriptorSetVariableDescriptorCountAllocateInfo;
    const void * pNext{};
    uint32_t descriptorSetCount{};
    const uint32_t * pDescriptorCounts{};
};
struct DescriptorSetVariableDescriptorCountLayoutSupport {
    StructureType sType = StructureType::DescriptorSetVariableDescriptorCountLayoutSupport;
    void * pNext{};
    uint32_t maxVariableDescriptorCount{};
};
struct AttachmentDescription2 {
    StructureType sType = StructureType::AttachmentDescription2;
    const void * pNext{};
    AttachmentDescriptionFlags flags{};
    Format format{};
    SampleCountFlagBits samples{};
    AttachmentLoadOp loadOp{};
    AttachmentStoreOp storeOp{};
    AttachmentLoadOp stencilLoadOp{};
    AttachmentStoreOp stencilStoreOp{};
    ImageLayout initialLayout{};
    ImageLayout finalLayout{};
};
struct AttachmentReference2 {
    StructureType sType = StructureType::AttachmentReference2;
    const void * pNext{};
    uint32_t attachment{};
    ImageLayout layout{};
    ImageAspectFlags aspectMask{};
};
struct SubpassDescription2 {
    StructureType sType = StructureType::SubpassDescription2;
    const void * pNext{};
    SubpassDescriptionFlags flags{};
    PipelineBindPoint pipelineBindPoint{};
    uint32_t viewMask{};
    uint32_t inputAttachmentCount{};
    const AttachmentReference2 * pInputAttachments{};
    uint32_t colorAttachmentCount{};
    const AttachmentReference2 * pColorAttachments{};
    const AttachmentReference2 * pResolveAttachments{};
    const AttachmentReference2 * pDepthStencilAttachment{};
    uint32_t preserveAttachmentCount{};
    const uint32_t * pPreserveAttachments{};
};
struct SubpassDependency2 {
    StructureType sType = StructureType::SubpassDependency2;
    const void * pNext{};
    uint32_t srcSubpass{};
    uint32_t dstSubpass{};
    PipelineStageFlags srcStageMask{};
    PipelineStageFlags dstStageMask{};
    AccessFlags srcAccessMask{};
    AccessFlags dstAccessMask{};
    DependencyFlags dependencyFlags{};
    int32_t viewOffset{};
};
struct RenderPassCreateInfo2 {
    StructureType sType = StructureType::RenderPassCreateInfo2;
    const void * pNext{};
    RenderPassCreateFlags flags{};
    uint32_t attachmentCount{};
    const AttachmentDescription2 * pAttachments{};
    uint32_t subpassCount{};
    const SubpassDescription2 * pSubpasses{};
    uint32_t dependencyCount{};
    const SubpassDependency2 * pDependencies{};
    uint32_t correlatedViewMaskCount{};
    const uint32_t * pCorrelatedViewMasks{};
};
struct SubpassBeginInfo {
    StructureType sType = StructureType::SubpassBeginInfo;
    const void * pNext{};
    SubpassContents contents{};
};
struct SubpassEndInfo {
    StructureType sType = StructureType::SubpassEndInfo;
    const void * pNext{};
};
struct PhysicalDeviceTimelineSemaphoreFeatures {
    StructureType sType = StructureType::PhysicalDeviceTimelineSemaphoreFeatures;
    void * pNext{};
    Bool32 timelineSemaphore{};
};
struct PhysicalDeviceTimelineSemaphoreProperties {
    StructureType sType = StructureType::PhysicalDeviceTimelineSemaphoreProperties;
    void * pNext{};
    uint64_t maxTimelineSemaphoreValueDifference{};
};
struct SemaphoreTypeCreateInfo {
    StructureType sType = StructureType::SemaphoreTypeCreateInfo;
    const void * pNext{};
    SemaphoreType semaphoreType{};
    uint64_t initialValue{};
};
struct TimelineSemaphoreSubmitInfo {
    StructureType sType = StructureType::TimelineSemaphoreSubmitInfo;
    const void * pNext{};
    uint32_t waitSemaphoreValueCount{};
    const uint64_t * pWaitSemaphoreValues{};
    uint32_t signalSemaphoreValueCount{};
    const uint64_t * pSignalSemaphoreValues{};
};
struct SemaphoreWaitInfo {
    StructureType sType = StructureType::SemaphoreWaitInfo;
    const void * pNext{};
    SemaphoreWaitFlags flags{};
    uint32_t semaphoreCount{};
    const Semaphore * pSemaphores{};
    const uint64_t * pValues{};
};
struct SemaphoreSignalInfo {
    StructureType sType = StructureType::SemaphoreSignalInfo;
    const void * pNext{};
    Semaphore semaphore{};
    uint64_t value{};
};
struct VertexInputBindingDivisorDescriptionKHR {
    uint32_t binding{};
    uint32_t divisor{};
};
struct PipelineVertexInputDivisorStateCreateInfoKHR {
    StructureType sType = StructureType::PipelineVertexInputDivisorStateCreateInfoKHR;
    const void * pNext{};
    uint32_t vertexBindingDivisorCount{};
    const VertexInputBindingDivisorDescriptionKHR * pVertexBindingDivisors{};
};
struct PhysicalDeviceVertexAttributeDivisorPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceVertexAttributeDivisorPropertiesEXT;
    void * pNext{};
    uint32_t maxVertexAttribDivisor{};
};
struct PhysicalDeviceVertexAttributeDivisorPropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceVertexAttributeDivisorPropertiesKHR;
    void * pNext{};
    uint32_t maxVertexAttribDivisor{};
    Bool32 supportsNonZeroFirstInstance{};
};
struct PhysicalDevicePCIBusInfoPropertiesEXT {
    StructureType sType = StructureType::PhysicalDevicePciBusInfoPropertiesEXT;
    void * pNext{};
    uint32_t pciDomain{};
    uint32_t pciBus{};
    uint32_t pciDevice{};
    uint32_t pciFunction{};
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct ImportAndroidHardwareBufferInfoANDROID {
    StructureType sType = StructureType::ImportAndroidHardwareBufferInfoANDROID;
    const void * pNext{};
    struct AHardwareBuffer * buffer{};
};
struct AndroidHardwareBufferUsageANDROID {
    StructureType sType = StructureType::AndroidHardwareBufferUsageANDROID;
    void * pNext{};
    uint64_t androidHardwareBufferUsage{};
};
struct AndroidHardwareBufferPropertiesANDROID {
    StructureType sType = StructureType::AndroidHardwareBufferPropertiesANDROID;
    void * pNext{};
    DeviceSize allocationSize{};
    uint32_t memoryTypeBits{};
};
struct MemoryGetAndroidHardwareBufferInfoANDROID {
    StructureType sType = StructureType::MemoryGetAndroidHardwareBufferInfoANDROID;
    const void * pNext{};
    DeviceMemory memory{};
};
struct AndroidHardwareBufferFormatPropertiesANDROID {
    StructureType sType = StructureType::AndroidHardwareBufferFormatPropertiesANDROID;
    void * pNext{};
    Format format{};
    uint64_t externalFormat{};
    FormatFeatureFlags formatFeatures{};
    ComponentMapping samplerYcbcrConversionComponents{};
    SamplerYcbcrModelConversion suggestedYcbcrModel{};
    SamplerYcbcrRange suggestedYcbcrRange{};
    ChromaLocation suggestedXChromaOffset{};
    ChromaLocation suggestedYChromaOffset{};
};
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
struct CommandBufferInheritanceConditionalRenderingInfoEXT {
    StructureType sType = StructureType::CommandBufferInheritanceConditionalRenderingInfoEXT;
    const void * pNext{};
    Bool32 conditionalRenderingEnable{};
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct ExternalFormatANDROID {
    StructureType sType = StructureType::ExternalFormatANDROID;
    void * pNext{};
    uint64_t externalFormat{};
};
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
struct PhysicalDevice8BitStorageFeatures {
    StructureType sType = StructureType::PhysicalDevice8StorageFeatures;
    void * pNext{};
    Bool32 storageBuffer8BitAccess{};
    Bool32 uniformAndStorageBuffer8BitAccess{};
    Bool32 storagePushConstant8{};
};
struct PhysicalDeviceConditionalRenderingFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceConditionalRenderingFeaturesEXT;
    void * pNext{};
    Bool32 conditionalRendering{};
    Bool32 inheritedConditionalRendering{};
};
struct PhysicalDeviceVulkanMemoryModelFeatures {
    StructureType sType = StructureType::PhysicalDeviceVulkanMemoryModelFeatures;
    void * pNext{};
    Bool32 vulkanMemoryModel{};
    Bool32 vulkanMemoryModelDeviceScope{};
    Bool32 vulkanMemoryModelAvailabilityVisibilityChains{};
};
struct PhysicalDeviceShaderAtomicInt64Features {
    StructureType sType = StructureType::PhysicalDeviceShaderAtomicInt64Features;
    void * pNext{};
    Bool32 shaderBufferInt64Atomics{};
    Bool32 shaderSharedInt64Atomics{};
};
struct PhysicalDeviceShaderAtomicFloatFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderAtomicFloatFeaturesEXT;
    void * pNext{};
    Bool32 shaderBufferFloat32Atomics{};
    Bool32 shaderBufferFloat32AtomicAdd{};
    Bool32 shaderBufferFloat64Atomics{};
    Bool32 shaderBufferFloat64AtomicAdd{};
    Bool32 shaderSharedFloat32Atomics{};
    Bool32 shaderSharedFloat32AtomicAdd{};
    Bool32 shaderSharedFloat64Atomics{};
    Bool32 shaderSharedFloat64AtomicAdd{};
    Bool32 shaderImageFloat32Atomics{};
    Bool32 shaderImageFloat32AtomicAdd{};
    Bool32 sparseImageFloat32Atomics{};
    Bool32 sparseImageFloat32AtomicAdd{};
};
struct PhysicalDeviceShaderAtomicFloat2FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderAtomicFloat2FeaturesEXT;
    void * pNext{};
    Bool32 shaderBufferFloat16Atomics{};
    Bool32 shaderBufferFloat16AtomicAdd{};
    Bool32 shaderBufferFloat16AtomicMinMax{};
    Bool32 shaderBufferFloat32AtomicMinMax{};
    Bool32 shaderBufferFloat64AtomicMinMax{};
    Bool32 shaderSharedFloat16Atomics{};
    Bool32 shaderSharedFloat16AtomicAdd{};
    Bool32 shaderSharedFloat16AtomicMinMax{};
    Bool32 shaderSharedFloat32AtomicMinMax{};
    Bool32 shaderSharedFloat64AtomicMinMax{};
    Bool32 shaderImageFloat32AtomicMinMax{};
    Bool32 sparseImageFloat32AtomicMinMax{};
};
struct PhysicalDeviceVertexAttributeDivisorFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceVertexAttributeDivisorFeaturesKHR;
    void * pNext{};
    Bool32 vertexAttributeInstanceRateDivisor{};
    Bool32 vertexAttributeInstanceRateZeroDivisor{};
};
struct QueueFamilyCheckpointPropertiesNV {
    StructureType sType = StructureType::QueueFamilyCheckpointPropertiesNV;
    void * pNext{};
    PipelineStageFlags checkpointExecutionStageMask{};
};
struct CheckpointDataNV {
    StructureType sType = StructureType::CheckpointDataNV;
    void * pNext{};
    PipelineStageFlagBits stage{};
    void * pCheckpointMarker{};
};
struct PhysicalDeviceDepthStencilResolveProperties {
    StructureType sType = StructureType::PhysicalDeviceDepthStencilResolveProperties;
    void * pNext{};
    ResolveModeFlags supportedDepthResolveModes{};
    ResolveModeFlags supportedStencilResolveModes{};
    Bool32 independentResolveNone{};
    Bool32 independentResolve{};
};
struct SubpassDescriptionDepthStencilResolve {
    StructureType sType = StructureType::SubpassDescriptionDepthStencilResolve;
    const void * pNext{};
    ResolveModeFlagBits depthResolveMode{};
    ResolveModeFlagBits stencilResolveMode{};
    const AttachmentReference2 * pDepthStencilResolveAttachment{};
};
struct ImageViewASTCDecodeModeEXT {
    StructureType sType = StructureType::ImageViewAstcDecodeModeEXT;
    const void * pNext{};
    Format decodeMode{};
};
struct PhysicalDeviceASTCDecodeFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceAstcDecodeFeaturesEXT;
    void * pNext{};
    Bool32 decodeModeSharedExponent{};
};
struct PhysicalDeviceTransformFeedbackFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceTransformFeedbackFeaturesEXT;
    void * pNext{};
    Bool32 transformFeedback{};
    Bool32 geometryStreams{};
};
struct PhysicalDeviceTransformFeedbackPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceTransformFeedbackPropertiesEXT;
    void * pNext{};
    uint32_t maxTransformFeedbackStreams{};
    uint32_t maxTransformFeedbackBuffers{};
    DeviceSize maxTransformFeedbackBufferSize{};
    uint32_t maxTransformFeedbackStreamDataSize{};
    uint32_t maxTransformFeedbackBufferDataSize{};
    uint32_t maxTransformFeedbackBufferDataStride{};
    Bool32 transformFeedbackQueries{};
    Bool32 transformFeedbackStreamsLinesTriangles{};
    Bool32 transformFeedbackRasterizationStreamSelect{};
    Bool32 transformFeedbackDraw{};
};
struct PipelineRasterizationStateStreamCreateInfoEXT {
    StructureType sType = StructureType::PipelineRasterizationStateStreamCreateInfoEXT;
    const void * pNext{};
    PipelineRasterizationStateStreamCreateFlagsEXT flags{};
    uint32_t rasterizationStream{};
};
struct PhysicalDeviceRepresentativeFragmentTestFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceRepresentativeFragmentTestFeaturesNV;
    void * pNext{};
    Bool32 representativeFragmentTest{};
};
struct PipelineRepresentativeFragmentTestStateCreateInfoNV {
    StructureType sType = StructureType::PipelineRepresentativeFragmentTestStateCreateInfoNV;
    const void * pNext{};
    Bool32 representativeFragmentTestEnable{};
};
struct PhysicalDeviceExclusiveScissorFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceExclusiveScissorFeaturesNV;
    void * pNext{};
    Bool32 exclusiveScissor{};
};
struct PipelineViewportExclusiveScissorStateCreateInfoNV {
    StructureType sType = StructureType::PipelineViewportExclusiveScissorStateCreateInfoNV;
    const void * pNext{};
    uint32_t exclusiveScissorCount{};
    const Rect2D * pExclusiveScissors{};
};
struct PhysicalDeviceCornerSampledImageFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceCornerSampledImageFeaturesNV;
    void * pNext{};
    Bool32 cornerSampledImage{};
};
struct PhysicalDeviceComputeShaderDerivativesFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceComputeShaderDerivativesFeaturesNV;
    void * pNext{};
    Bool32 computeDerivativeGroupQuads{};
    Bool32 computeDerivativeGroupLinear{};
};
struct PhysicalDeviceShaderImageFootprintFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceShaderImageFootprintFeaturesNV;
    void * pNext{};
    Bool32 imageFootprint{};
};
struct PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
    void * pNext{};
    Bool32 dedicatedAllocationImageAliasing{};
};
struct PhysicalDeviceCopyMemoryIndirectFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceCopyMemoryIndirectFeaturesNV;
    void * pNext{};
    Bool32 indirectCopy{};
};
struct PhysicalDeviceCopyMemoryIndirectPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceCopyMemoryIndirectPropertiesNV;
    void * pNext{};
    QueueFlags supportedQueues{};
};
struct PhysicalDeviceMemoryDecompressionFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceMemoryDecompressionFeaturesNV;
    void * pNext{};
    Bool32 memoryDecompression{};
};
struct PhysicalDeviceMemoryDecompressionPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceMemoryDecompressionPropertiesNV;
    void * pNext{};
    MemoryDecompressionMethodFlagsNV decompressionMethods{};
    uint64_t maxDecompressionIndirectCount{};
};
struct ShadingRatePaletteNV {
    uint32_t shadingRatePaletteEntryCount{};
    const ShadingRatePaletteEntryNV * pShadingRatePaletteEntries{};
};
struct PipelineViewportShadingRateImageStateCreateInfoNV {
    StructureType sType = StructureType::PipelineViewportShadingRateImageStateCreateInfoNV;
    const void * pNext{};
    Bool32 shadingRateImageEnable{};
    uint32_t viewportCount{};
    const ShadingRatePaletteNV * pShadingRatePalettes{};
};
struct PhysicalDeviceShadingRateImageFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceShadingRateImageFeaturesNV;
    void * pNext{};
    Bool32 shadingRateImage{};
    Bool32 shadingRateCoarseSampleOrder{};
};
struct PhysicalDeviceShadingRateImagePropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceShadingRateImagePropertiesNV;
    void * pNext{};
    Extent2D shadingRateTexelSize{};
    uint32_t shadingRatePaletteSize{};
    uint32_t shadingRateMaxCoarseSamples{};
};
struct PhysicalDeviceInvocationMaskFeaturesHUAWEI {
    StructureType sType = StructureType::PhysicalDeviceInvocationMaskFeaturesHUAWEI;
    void * pNext{};
    Bool32 invocationMask{};
};
struct CoarseSampleLocationNV {
    uint32_t pixelX{};
    uint32_t pixelY{};
    uint32_t sample{};
};
struct CoarseSampleOrderCustomNV {
    ShadingRatePaletteEntryNV shadingRate{};
    uint32_t sampleCount{};
    uint32_t sampleLocationCount{};
    const CoarseSampleLocationNV * pSampleLocations{};
};
struct PipelineViewportCoarseSampleOrderStateCreateInfoNV {
    StructureType sType = StructureType::PipelineViewportCoarseSampleOrderStateCreateInfoNV;
    const void * pNext{};
    CoarseSampleOrderTypeNV sampleOrderType{};
    uint32_t customSampleOrderCount{};
    const CoarseSampleOrderCustomNV * pCustomSampleOrders{};
};
struct PhysicalDeviceMeshShaderFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceMeshShaderFeaturesNV;
    void * pNext{};
    Bool32 taskShader{};
    Bool32 meshShader{};
};
struct PhysicalDeviceMeshShaderPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceMeshShaderPropertiesNV;
    void * pNext{};
    uint32_t maxDrawMeshTasksCount{};
    uint32_t maxTaskWorkGroupInvocations{};
    uint32_t maxTaskWorkGroupSize [3]{};
    uint32_t maxTaskTotalMemorySize{};
    uint32_t maxTaskOutputCount{};
    uint32_t maxMeshWorkGroupInvocations{};
    uint32_t maxMeshWorkGroupSize [3]{};
    uint32_t maxMeshTotalMemorySize{};
    uint32_t maxMeshOutputVertices{};
    uint32_t maxMeshOutputPrimitives{};
    uint32_t maxMeshMultiviewViewCount{};
    uint32_t meshOutputPerVertexGranularity{};
    uint32_t meshOutputPerPrimitiveGranularity{};
};
struct DrawMeshTasksIndirectCommandNV {
    uint32_t taskCount{};
    uint32_t firstTask{};
};
struct PhysicalDeviceMeshShaderFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceMeshShaderFeaturesEXT;
    void * pNext{};
    Bool32 taskShader{};
    Bool32 meshShader{};
    Bool32 multiviewMeshShader{};
    Bool32 primitiveFragmentShadingRateMeshShader{};
    Bool32 meshShaderQueries{};
};
struct PhysicalDeviceMeshShaderPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceMeshShaderPropertiesEXT;
    void * pNext{};
    uint32_t maxTaskWorkGroupTotalCount{};
    uint32_t maxTaskWorkGroupCount [3]{};
    uint32_t maxTaskWorkGroupInvocations{};
    uint32_t maxTaskWorkGroupSize [3]{};
    uint32_t maxTaskPayloadSize{};
    uint32_t maxTaskSharedMemorySize{};
    uint32_t maxTaskPayloadAndSharedMemorySize{};
    uint32_t maxMeshWorkGroupTotalCount{};
    uint32_t maxMeshWorkGroupCount [3]{};
    uint32_t maxMeshWorkGroupInvocations{};
    uint32_t maxMeshWorkGroupSize [3]{};
    uint32_t maxMeshSharedMemorySize{};
    uint32_t maxMeshPayloadAndSharedMemorySize{};
    uint32_t maxMeshOutputMemorySize{};
    uint32_t maxMeshPayloadAndOutputMemorySize{};
    uint32_t maxMeshOutputComponents{};
    uint32_t maxMeshOutputVertices{};
    uint32_t maxMeshOutputPrimitives{};
    uint32_t maxMeshOutputLayers{};
    uint32_t maxMeshMultiviewViewCount{};
    uint32_t meshOutputPerVertexGranularity{};
    uint32_t meshOutputPerPrimitiveGranularity{};
    uint32_t maxPreferredTaskWorkGroupInvocations{};
    uint32_t maxPreferredMeshWorkGroupInvocations{};
    Bool32 prefersLocalInvocationVertexOutput{};
    Bool32 prefersLocalInvocationPrimitiveOutput{};
    Bool32 prefersCompactVertexOutput{};
    Bool32 prefersCompactPrimitiveOutput{};
};
struct DrawMeshTasksIndirectCommandEXT {
    uint32_t groupCountX{};
    uint32_t groupCountY{};
    uint32_t groupCountZ{};
};
struct RayTracingShaderGroupCreateInfoNV {
    StructureType sType = StructureType::RayTracingShaderGroupCreateInfoNV;
    const void * pNext{};
    RayTracingShaderGroupTypeKHR type{};
    uint32_t generalShader{};
    uint32_t closestHitShader{};
    uint32_t anyHitShader{};
    uint32_t intersectionShader{};
};
struct RayTracingShaderGroupCreateInfoKHR {
    StructureType sType = StructureType::RayTracingShaderGroupCreateInfoKHR;
    const void * pNext{};
    RayTracingShaderGroupTypeKHR type{};
    uint32_t generalShader{};
    uint32_t closestHitShader{};
    uint32_t anyHitShader{};
    uint32_t intersectionShader{};
    const void * pShaderGroupCaptureReplayHandle{};
};
struct RayTracingPipelineCreateInfoNV {
    StructureType sType = StructureType::RayTracingPipelineCreateInfoNV;
    const void * pNext{};
    PipelineCreateFlags flags{};
    uint32_t stageCount{};
    const PipelineShaderStageCreateInfo * pStages{};
    uint32_t groupCount{};
    const RayTracingShaderGroupCreateInfoNV * pGroups{};
    uint32_t maxRecursionDepth{};
    PipelineLayout layout{};
    Pipeline basePipelineHandle{};
    int32_t basePipelineIndex{};
};
struct RayTracingPipelineInterfaceCreateInfoKHR {
    StructureType sType = StructureType::RayTracingPipelineInterfaceCreateInfoKHR;
    const void * pNext{};
    uint32_t maxPipelineRayPayloadSize{};
    uint32_t maxPipelineRayHitAttributeSize{};
};
struct PipelineLibraryCreateInfoKHR {
    StructureType sType = StructureType::PipelineLibraryCreateInfoKHR;
    const void * pNext{};
    uint32_t libraryCount{};
    const Pipeline * pLibraries{};
};
struct RayTracingPipelineCreateInfoKHR {
    StructureType sType = StructureType::RayTracingPipelineCreateInfoKHR;
    const void * pNext{};
    PipelineCreateFlags flags{};
    uint32_t stageCount{};
    const PipelineShaderStageCreateInfo * pStages{};
    uint32_t groupCount{};
    const RayTracingShaderGroupCreateInfoKHR * pGroups{};
    uint32_t maxPipelineRayRecursionDepth{};
    const PipelineLibraryCreateInfoKHR * pLibraryInfo{};
    const RayTracingPipelineInterfaceCreateInfoKHR * pLibraryInterface{};
    const PipelineDynamicStateCreateInfo * pDynamicState{};
    PipelineLayout layout{};
    Pipeline basePipelineHandle{};
    int32_t basePipelineIndex{};
};
struct GeometryTrianglesNV {
    StructureType sType = StructureType::GeometryTrianglesNV;
    const void * pNext{};
    Buffer vertexData{};
    DeviceSize vertexOffset{};
    uint32_t vertexCount{};
    DeviceSize vertexStride{};
    Format vertexFormat{};
    Buffer indexData{};
    DeviceSize indexOffset{};
    uint32_t indexCount{};
    IndexType indexType{};
    Buffer transformData{};
    DeviceSize transformOffset{};
};
struct GeometryAABBNV {
    StructureType sType = StructureType::GeometryAabbNV;
    const void * pNext{};
    Buffer aabbData{};
    uint32_t numAABBs{};
    uint32_t stride{};
    DeviceSize offset{};
};
struct GeometryDataNV {
    GeometryTrianglesNV triangles{};
    GeometryAABBNV aabbs{};
};
struct GeometryNV {
    StructureType sType = StructureType::GeometryNV;
    const void * pNext{};
    GeometryTypeKHR geometryType{};
    GeometryDataNV geometry{};
    GeometryFlagsKHR flags{};
};
struct AccelerationStructureInfoNV {
    StructureType sType = StructureType::AccelerationStructureInfoNV;
    const void * pNext{};
    AccelerationStructureTypeNV type{};
    BuildAccelerationStructureFlagsNV flags{};
    uint32_t instanceCount{};
    uint32_t geometryCount{};
    const GeometryNV * pGeometries{};
};
struct AccelerationStructureCreateInfoNV {
    StructureType sType = StructureType::AccelerationStructureCreateInfoNV;
    const void * pNext{};
    DeviceSize compactedSize{};
    AccelerationStructureInfoNV info{};
};
struct BindAccelerationStructureMemoryInfoNV {
    StructureType sType = StructureType::BindAccelerationStructureMemoryInfoNV;
    const void * pNext{};
    AccelerationStructureNV accelerationStructure{};
    DeviceMemory memory{};
    DeviceSize memoryOffset{};
    uint32_t deviceIndexCount{};
    const uint32_t * pDeviceIndices{};
};
struct WriteDescriptorSetAccelerationStructureKHR {
    StructureType sType = StructureType::WriteDescriptorSetAccelerationStructureKHR;
    const void * pNext{};
    uint32_t accelerationStructureCount{};
    const AccelerationStructureKHR * pAccelerationStructures{};
};
struct WriteDescriptorSetAccelerationStructureNV {
    StructureType sType = StructureType::WriteDescriptorSetAccelerationStructureNV;
    const void * pNext{};
    uint32_t accelerationStructureCount{};
    const AccelerationStructureNV * pAccelerationStructures{};
};
struct AccelerationStructureMemoryRequirementsInfoNV {
    StructureType sType = StructureType::AccelerationStructureMemoryRequirementsInfoNV;
    const void * pNext{};
    AccelerationStructureMemoryRequirementsTypeNV type{};
    AccelerationStructureNV accelerationStructure{};
};
struct PhysicalDeviceAccelerationStructureFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceAccelerationStructureFeaturesKHR;
    void * pNext{};
    Bool32 accelerationStructure{};
    Bool32 accelerationStructureCaptureReplay{};
    Bool32 accelerationStructureIndirectBuild{};
    Bool32 accelerationStructureHostCommands{};
    Bool32 descriptorBindingAccelerationStructureUpdateAfterBind{};
};
struct PhysicalDeviceRayTracingPipelineFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceRayTracingPipelineFeaturesKHR;
    void * pNext{};
    Bool32 rayTracingPipeline{};
    Bool32 rayTracingPipelineShaderGroupHandleCaptureReplay{};
    Bool32 rayTracingPipelineShaderGroupHandleCaptureReplayMixed{};
    Bool32 rayTracingPipelineTraceRaysIndirect{};
    Bool32 rayTraversalPrimitiveCulling{};
};
struct PhysicalDeviceRayQueryFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceRayQueryFeaturesKHR;
    void * pNext{};
    Bool32 rayQuery{};
};
struct PhysicalDeviceAccelerationStructurePropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceAccelerationStructurePropertiesKHR;
    void * pNext{};
    uint64_t maxGeometryCount{};
    uint64_t maxInstanceCount{};
    uint64_t maxPrimitiveCount{};
    uint32_t maxPerStageDescriptorAccelerationStructures{};
    uint32_t maxPerStageDescriptorUpdateAfterBindAccelerationStructures{};
    uint32_t maxDescriptorSetAccelerationStructures{};
    uint32_t maxDescriptorSetUpdateAfterBindAccelerationStructures{};
    uint32_t minAccelerationStructureScratchOffsetAlignment{};
};
struct PhysicalDeviceRayTracingPipelinePropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceRayTracingPipelinePropertiesKHR;
    void * pNext{};
    uint32_t shaderGroupHandleSize{};
    uint32_t maxRayRecursionDepth{};
    uint32_t maxShaderGroupStride{};
    uint32_t shaderGroupBaseAlignment{};
    uint32_t shaderGroupHandleCaptureReplaySize{};
    uint32_t maxRayDispatchInvocationCount{};
    uint32_t shaderGroupHandleAlignment{};
    uint32_t maxRayHitAttributeSize{};
};
struct PhysicalDeviceRayTracingPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceRayTracingPropertiesNV;
    void * pNext{};
    uint32_t shaderGroupHandleSize{};
    uint32_t maxRecursionDepth{};
    uint32_t maxShaderGroupStride{};
    uint32_t shaderGroupBaseAlignment{};
    uint64_t maxGeometryCount{};
    uint64_t maxInstanceCount{};
    uint64_t maxTriangleCount{};
    uint32_t maxDescriptorSetAccelerationStructures{};
};
struct StridedDeviceAddressRegionKHR {
    DeviceAddress deviceAddress{};
    DeviceSize stride{};
    DeviceSize size{};
};
struct TraceRaysIndirectCommandKHR {
    uint32_t width{};
    uint32_t height{};
    uint32_t depth{};
};
struct TraceRaysIndirectCommand2KHR {
    DeviceAddress raygenShaderRecordAddress{};
    DeviceSize raygenShaderRecordSize{};
    DeviceAddress missShaderBindingTableAddress{};
    DeviceSize missShaderBindingTableSize{};
    DeviceSize missShaderBindingTableStride{};
    DeviceAddress hitShaderBindingTableAddress{};
    DeviceSize hitShaderBindingTableSize{};
    DeviceSize hitShaderBindingTableStride{};
    DeviceAddress callableShaderBindingTableAddress{};
    DeviceSize callableShaderBindingTableSize{};
    DeviceSize callableShaderBindingTableStride{};
    uint32_t width{};
    uint32_t height{};
    uint32_t depth{};
};
struct PhysicalDeviceRayTracingMaintenance1FeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceRayTracingMaintenance1FeaturesKHR;
    void * pNext{};
    Bool32 rayTracingMaintenance1{};
    Bool32 rayTracingPipelineTraceRaysIndirect2{};
};
struct DrmFormatModifierPropertiesEXT {
    uint64_t drmFormatModifier{};
    uint32_t drmFormatModifierPlaneCount{};
    FormatFeatureFlags drmFormatModifierTilingFeatures{};
};
struct DrmFormatModifierPropertiesListEXT {
    StructureType sType = StructureType::DrmFormatModifierPropertiesListEXT;
    void * pNext{};
    uint32_t drmFormatModifierCount{};
    DrmFormatModifierPropertiesEXT * pDrmFormatModifierProperties{};
};
struct PhysicalDeviceImageDrmFormatModifierInfoEXT {
    StructureType sType = StructureType::PhysicalDeviceImageDrmFormatModifierInfoEXT;
    const void * pNext{};
    uint64_t drmFormatModifier{};
    SharingMode sharingMode{};
    uint32_t queueFamilyIndexCount{};
    const uint32_t * pQueueFamilyIndices{};
};
struct ImageDrmFormatModifierListCreateInfoEXT {
    StructureType sType = StructureType::ImageDrmFormatModifierListCreateInfoEXT;
    const void * pNext{};
    uint32_t drmFormatModifierCount{};
    const uint64_t * pDrmFormatModifiers{};
};
struct ImageDrmFormatModifierExplicitCreateInfoEXT {
    StructureType sType = StructureType::ImageDrmFormatModifierExplicitCreateInfoEXT;
    const void * pNext{};
    uint64_t drmFormatModifier{};
    uint32_t drmFormatModifierPlaneCount{};
    const SubresourceLayout * pPlaneLayouts{};
};
struct ImageDrmFormatModifierPropertiesEXT {
    StructureType sType = StructureType::ImageDrmFormatModifierPropertiesEXT;
    void * pNext{};
    uint64_t drmFormatModifier{};
};
struct ImageStencilUsageCreateInfo {
    StructureType sType = StructureType::ImageStencilUsageCreateInfo;
    const void * pNext{};
    ImageUsageFlags stencilUsage{};
};
struct DeviceMemoryOverallocationCreateInfoAMD {
    StructureType sType = StructureType::DeviceMemoryOverallocationCreateInfoAMD;
    const void * pNext{};
    MemoryOverallocationBehaviorAMD overallocationBehavior{};
};
struct PhysicalDeviceFragmentDensityMapFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceFragmentDensityMapFeaturesEXT;
    void * pNext{};
    Bool32 fragmentDensityMap{};
    Bool32 fragmentDensityMapDynamic{};
    Bool32 fragmentDensityMapNonSubsampledImages{};
};
struct PhysicalDeviceFragmentDensityMap2FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceFragmentDensityMap2FeaturesEXT;
    void * pNext{};
    Bool32 fragmentDensityMapDeferred{};
};
struct PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM;
    void * pNext{};
    Bool32 fragmentDensityMapOffset{};
};
struct PhysicalDeviceFragmentDensityMapPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceFragmentDensityMapPropertiesEXT;
    void * pNext{};
    Extent2D minFragmentDensityTexelSize{};
    Extent2D maxFragmentDensityTexelSize{};
    Bool32 fragmentDensityInvocations{};
};
struct PhysicalDeviceFragmentDensityMap2PropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceFragmentDensityMap2PropertiesEXT;
    void * pNext{};
    Bool32 subsampledLoads{};
    Bool32 subsampledCoarseReconstructionEarlyAccess{};
    uint32_t maxSubsampledArrayLayers{};
    uint32_t maxDescriptorSetSubsampledSamplers{};
};
struct PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM {
    StructureType sType = StructureType::PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM;
    void * pNext{};
    Extent2D fragmentDensityOffsetGranularity{};
};
struct RenderPassFragmentDensityMapCreateInfoEXT {
    StructureType sType = StructureType::RenderPassFragmentDensityMapCreateInfoEXT;
    const void * pNext{};
    AttachmentReference fragmentDensityMapAttachment{};
};
struct SubpassFragmentDensityMapOffsetEndInfoQCOM {
    StructureType sType = StructureType::SubpassFragmentDensityMapOffsetEndInfoQCOM;
    const void * pNext{};
    uint32_t fragmentDensityOffsetCount{};
    const Offset2D * pFragmentDensityOffsets{};
};
struct PhysicalDeviceScalarBlockLayoutFeatures {
    StructureType sType = StructureType::PhysicalDeviceScalarBlockLayoutFeatures;
    void * pNext{};
    Bool32 scalarBlockLayout{};
};
struct SurfaceProtectedCapabilitiesKHR {
    StructureType sType = StructureType::SurfaceProtectedCapabilitiesKHR;
    const void * pNext{};
    Bool32 supportsProtected{};
};
struct PhysicalDeviceUniformBufferStandardLayoutFeatures {
    StructureType sType = StructureType::PhysicalDeviceUniformBufferStandardLayoutFeatures;
    void * pNext{};
    Bool32 uniformBufferStandardLayout{};
};
struct PhysicalDeviceDepthClipEnableFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDepthClipEnableFeaturesEXT;
    void * pNext{};
    Bool32 depthClipEnable{};
};
struct PipelineRasterizationDepthClipStateCreateInfoEXT {
    StructureType sType = StructureType::PipelineRasterizationDepthClipStateCreateInfoEXT;
    const void * pNext{};
    PipelineRasterizationDepthClipStateCreateFlagsEXT flags{};
    Bool32 depthClipEnable{};
};
struct PhysicalDeviceMemoryBudgetPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceMemoryBudgetPropertiesEXT;
    void * pNext{};
    DeviceSize heapBudget [ VK_MAX_MEMORY_HEAPS ]{};
    DeviceSize heapUsage [ VK_MAX_MEMORY_HEAPS ]{};
};
struct PhysicalDeviceMemoryPriorityFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceMemoryPriorityFeaturesEXT;
    void * pNext{};
    Bool32 memoryPriority{};
};
struct MemoryPriorityAllocateInfoEXT {
    StructureType sType = StructureType::MemoryPriorityAllocateInfoEXT;
    const void * pNext{};
    float priority{};
};
struct PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;
    void * pNext{};
    Bool32 pageableDeviceLocalMemory{};
};
struct PhysicalDeviceBufferDeviceAddressFeatures {
    StructureType sType = StructureType::PhysicalDeviceBufferDeviceAddressFeatures;
    void * pNext{};
    Bool32 bufferDeviceAddress{};
    Bool32 bufferDeviceAddressCaptureReplay{};
    Bool32 bufferDeviceAddressMultiDevice{};
};
struct PhysicalDeviceBufferDeviceAddressFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceBufferDeviceAddressFeaturesEXT;
    void * pNext{};
    Bool32 bufferDeviceAddress{};
    Bool32 bufferDeviceAddressCaptureReplay{};
    Bool32 bufferDeviceAddressMultiDevice{};
};
struct BufferDeviceAddressInfo {
    StructureType sType = StructureType::BufferDeviceAddressInfo;
    const void * pNext{};
    Buffer buffer{};
};
struct BufferOpaqueCaptureAddressCreateInfo {
    StructureType sType = StructureType::BufferOpaqueCaptureAddressCreateInfo;
    const void * pNext{};
    uint64_t opaqueCaptureAddress{};
};
struct BufferDeviceAddressCreateInfoEXT {
    StructureType sType = StructureType::BufferDeviceAddressCreateInfoEXT;
    const void * pNext{};
    DeviceAddress deviceAddress{};
};
struct PhysicalDeviceImageViewImageFormatInfoEXT {
    StructureType sType = StructureType::PhysicalDeviceImageViewImageFormatInfoEXT;
    void * pNext{};
    ImageViewType imageViewType{};
};
struct FilterCubicImageViewImageFormatPropertiesEXT {
    StructureType sType = StructureType::FilterCubicImageViewImageFormatPropertiesEXT;
    void * pNext{};
    Bool32 filterCubic{};
    Bool32 filterCubicMinmax{};
};
struct PhysicalDeviceImagelessFramebufferFeatures {
    StructureType sType = StructureType::PhysicalDeviceImagelessFramebufferFeatures;
    void * pNext{};
    Bool32 imagelessFramebuffer{};
};
struct FramebufferAttachmentImageInfo {
    StructureType sType = StructureType::FramebufferAttachmentImageInfo;
    const void * pNext{};
    ImageCreateFlags flags{};
    ImageUsageFlags usage{};
    uint32_t width{};
    uint32_t height{};
    uint32_t layerCount{};
    uint32_t viewFormatCount{};
    const Format * pViewFormats{};
};
struct FramebufferAttachmentsCreateInfo {
    StructureType sType = StructureType::FramebufferAttachmentsCreateInfo;
    const void * pNext{};
    uint32_t attachmentImageInfoCount{};
    const FramebufferAttachmentImageInfo * pAttachmentImageInfos{};
};
struct RenderPassAttachmentBeginInfo {
    StructureType sType = StructureType::RenderPassAttachmentBeginInfo;
    const void * pNext{};
    uint32_t attachmentCount{};
    const ImageView * pAttachments{};
};
struct PhysicalDeviceTextureCompressionASTCHDRFeatures {
    StructureType sType = StructureType::PhysicalDeviceTextureCompressionAstcHdrFeatures;
    void * pNext{};
    Bool32 textureCompressionASTC_HDR{};
};
struct PhysicalDeviceCooperativeMatrixFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceCooperativeMatrixFeaturesNV;
    void * pNext{};
    Bool32 cooperativeMatrix{};
    Bool32 cooperativeMatrixRobustBufferAccess{};
};
struct PhysicalDeviceCooperativeMatrixPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceCooperativeMatrixPropertiesNV;
    void * pNext{};
    ShaderStageFlags cooperativeMatrixSupportedStages{};
};
struct CooperativeMatrixPropertiesNV {
    StructureType sType = StructureType::CooperativeMatrixPropertiesNV;
    void * pNext{};
    uint32_t MSize{};
    uint32_t NSize{};
    uint32_t KSize{};
    ComponentTypeNV AType{};
    ComponentTypeNV BType{};
    ComponentTypeNV CType{};
    ComponentTypeNV DType{};
    ScopeNV scope{};
};
struct PhysicalDeviceYcbcrImageArraysFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceYcbcrImageArraysFeaturesEXT;
    void * pNext{};
    Bool32 ycbcrImageArrays{};
};
struct ImageViewHandleInfoNVX {
    StructureType sType = StructureType::ImageViewHandleInfoNVX;
    const void * pNext{};
    ImageView imageView{};
    DescriptorType descriptorType{};
    Sampler sampler{};
};
struct ImageViewAddressPropertiesNVX {
    StructureType sType = StructureType::ImageViewAddressPropertiesNVX;
    void * pNext{};
    DeviceAddress deviceAddress{};
    DeviceSize size{};
};
#if defined(VK_USE_PLATFORM_GGP)
struct PresentFrameTokenGGP {
    StructureType sType = StructureType::PresentFrameTokenGGP;
    const void * pNext{};
    GgpFrameToken frameToken{};
};
#endif // defined(VK_USE_PLATFORM_GGP)
struct PipelineCreationFeedback {
    PipelineCreationFeedbackFlags flags{};
    uint64_t duration{};
};
struct PipelineCreationFeedbackCreateInfo {
    StructureType sType = StructureType::PipelineCreationFeedbackCreateInfo;
    const void * pNext{};
    PipelineCreationFeedback * pPipelineCreationFeedback{};
    uint32_t pipelineStageCreationFeedbackCount{};
    PipelineCreationFeedback * pPipelineStageCreationFeedbacks{};
};
#if defined(VK_USE_PLATFORM_WIN32_KHR)
struct SurfaceFullScreenExclusiveInfoEXT {
    StructureType sType = StructureType::SurfaceFullScreenExclusiveInfoEXT;
    void * pNext{};
    FullScreenExclusiveEXT fullScreenExclusive{};
};
struct SurfaceFullScreenExclusiveWin32InfoEXT {
    StructureType sType = StructureType::SurfaceFullScreenExclusiveWin32InfoEXT;
    const void * pNext{};
    HMONITOR hmonitor{};
};
struct SurfaceCapabilitiesFullScreenExclusiveEXT {
    StructureType sType = StructureType::SurfaceCapabilitiesFullScreenExclusiveEXT;
    void * pNext{};
    Bool32 fullScreenExclusiveSupported{};
};
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
struct PhysicalDevicePresentBarrierFeaturesNV {
    StructureType sType = StructureType::PhysicalDevicePresentBarrierFeaturesNV;
    void * pNext{};
    Bool32 presentBarrier{};
};
struct SurfaceCapabilitiesPresentBarrierNV {
    StructureType sType = StructureType::SurfaceCapabilitiesPresentBarrierNV;
    void * pNext{};
    Bool32 presentBarrierSupported{};
};
struct SwapchainPresentBarrierCreateInfoNV {
    StructureType sType = StructureType::SwapchainPresentBarrierCreateInfoNV;
    void * pNext{};
    Bool32 presentBarrierEnable{};
};
struct PhysicalDevicePerformanceQueryFeaturesKHR {
    StructureType sType = StructureType::PhysicalDevicePerformanceQueryFeaturesKHR;
    void * pNext{};
    Bool32 performanceCounterQueryPools{};
    Bool32 performanceCounterMultipleQueryPools{};
};
struct PhysicalDevicePerformanceQueryPropertiesKHR {
    StructureType sType = StructureType::PhysicalDevicePerformanceQueryPropertiesKHR;
    void * pNext{};
    Bool32 allowCommandBufferQueryCopies{};
};
struct PerformanceCounterKHR {
    StructureType sType = StructureType::PerformanceCounterKHR;
    void * pNext{};
    PerformanceCounterUnitKHR unit{};
    PerformanceCounterScopeKHR scope{};
    PerformanceCounterStorageKHR storage{};
    uint8_t uuid [ VK_UUID_SIZE ]{};
};
struct PerformanceCounterDescriptionKHR {
    StructureType sType = StructureType::PerformanceCounterDescriptionKHR;
    void * pNext{};
    PerformanceCounterDescriptionFlagsKHR flags{};
    char name [ VK_MAX_DESCRIPTION_SIZE ]{};
    char category [ VK_MAX_DESCRIPTION_SIZE ]{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
};
struct QueryPoolPerformanceCreateInfoKHR {
    StructureType sType = StructureType::QueryPoolPerformanceCreateInfoKHR;
    const void * pNext{};
    uint32_t queueFamilyIndex{};
    uint32_t counterIndexCount{};
    const uint32_t * pCounterIndices{};
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
    StructureType sType = StructureType::AcquireProfilingLockInfoKHR;
    const void * pNext{};
    AcquireProfilingLockFlagsKHR flags{};
    uint64_t timeout{};
};
struct PerformanceQuerySubmitInfoKHR {
    StructureType sType = StructureType::PerformanceQuerySubmitInfoKHR;
    const void * pNext{};
    uint32_t counterPassIndex{};
};
struct HeadlessSurfaceCreateInfoEXT {
    StructureType sType = StructureType::HeadlessSurfaceCreateInfoEXT;
    const void * pNext{};
    HeadlessSurfaceCreateFlagsEXT flags{};
};
struct PhysicalDeviceCoverageReductionModeFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceCoverageReductionModeFeaturesNV;
    void * pNext{};
    Bool32 coverageReductionMode{};
};
struct PipelineCoverageReductionStateCreateInfoNV {
    StructureType sType = StructureType::PipelineCoverageReductionStateCreateInfoNV;
    const void * pNext{};
    PipelineCoverageReductionStateCreateFlagsNV flags{};
    CoverageReductionModeNV coverageReductionMode{};
};
struct FramebufferMixedSamplesCombinationNV {
    StructureType sType = StructureType::FramebufferMixedSamplesCombinationNV;
    void * pNext{};
    CoverageReductionModeNV coverageReductionMode{};
    SampleCountFlagBits rasterizationSamples{};
    SampleCountFlags depthStencilSamples{};
    SampleCountFlags colorSamples{};
};
struct PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL {
    StructureType sType = StructureType::PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;
    void * pNext{};
    Bool32 shaderIntegerFunctions2{};
};
union PerformanceValueDataINTEL {
    uint32_t value32;
    uint64_t value64;
    float valueFloat;
    Bool32 valueBool;
    const char * valueString;
};
struct PerformanceValueINTEL {
    PerformanceValueTypeINTEL type{};
    PerformanceValueDataINTEL data{};
};
struct InitializePerformanceApiInfoINTEL {
    StructureType sType = StructureType::InitializePerformanceApiInfoINTEL;
    const void * pNext{};
    void * pUserData{};
};
struct QueryPoolPerformanceQueryCreateInfoINTEL {
    StructureType sType = StructureType::QueryPoolPerformanceQueryCreateInfoINTEL;
    const void * pNext{};
    QueryPoolSamplingModeINTEL performanceCountersSampling{};
};
struct PerformanceMarkerInfoINTEL {
    StructureType sType = StructureType::PerformanceMarkerInfoINTEL;
    const void * pNext{};
    uint64_t marker{};
};
struct PerformanceStreamMarkerInfoINTEL {
    StructureType sType = StructureType::PerformanceStreamMarkerInfoINTEL;
    const void * pNext{};
    uint32_t marker{};
};
struct PerformanceOverrideInfoINTEL {
    StructureType sType = StructureType::PerformanceOverrideInfoINTEL;
    const void * pNext{};
    PerformanceOverrideTypeINTEL type{};
    Bool32 enable{};
    uint64_t parameter{};
};
struct PerformanceConfigurationAcquireInfoINTEL {
    StructureType sType = StructureType::PerformanceConfigurationAcquireInfoINTEL;
    const void * pNext{};
    PerformanceConfigurationTypeINTEL type{};
};
struct PhysicalDeviceShaderClockFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderClockFeaturesKHR;
    void * pNext{};
    Bool32 shaderSubgroupClock{};
    Bool32 shaderDeviceClock{};
};
struct PhysicalDeviceIndexTypeUint8FeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceIndexTypeUint8FeaturesKHR;
    void * pNext{};
    Bool32 indexTypeUint8{};
};
struct PhysicalDeviceShaderSMBuiltinsPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceShaderSmBuiltinsPropertiesNV;
    void * pNext{};
    uint32_t shaderSMCount{};
    uint32_t shaderWarpsPerSM{};
};
struct PhysicalDeviceShaderSMBuiltinsFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceShaderSmBuiltinsFeaturesNV;
    void * pNext{};
    Bool32 shaderSMBuiltins{};
};
struct PhysicalDeviceFragmentShaderInterlockFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceFragmentShaderInterlockFeaturesEXT;
    void * pNext{};
    Bool32 fragmentShaderSampleInterlock{};
    Bool32 fragmentShaderPixelInterlock{};
    Bool32 fragmentShaderShadingRateInterlock{};
};
struct PhysicalDeviceSeparateDepthStencilLayoutsFeatures {
    StructureType sType = StructureType::PhysicalDeviceSeparateDepthStencilLayoutsFeatures;
    void * pNext{};
    Bool32 separateDepthStencilLayouts{};
};
struct AttachmentReferenceStencilLayout {
    StructureType sType = StructureType::AttachmentReferenceStencilLayout;
    void * pNext{};
    ImageLayout stencilLayout{};
};
struct PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;
    void * pNext{};
    Bool32 primitiveTopologyListRestart{};
    Bool32 primitiveTopologyPatchListRestart{};
};
struct AttachmentDescriptionStencilLayout {
    StructureType sType = StructureType::AttachmentDescriptionStencilLayout;
    void * pNext{};
    ImageLayout stencilInitialLayout{};
    ImageLayout stencilFinalLayout{};
};
struct PhysicalDevicePipelineExecutablePropertiesFeaturesKHR {
    StructureType sType = StructureType::PhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
    void * pNext{};
    Bool32 pipelineExecutableInfo{};
};
struct PipelineInfoKHR {
    StructureType sType = StructureType::PipelineInfoKHR;
    const void * pNext{};
    Pipeline pipeline{};
};
struct PipelineExecutablePropertiesKHR {
    StructureType sType = StructureType::PipelineExecutablePropertiesKHR;
    void * pNext{};
    ShaderStageFlags stages{};
    char name [ VK_MAX_DESCRIPTION_SIZE ]{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    uint32_t subgroupSize{};
};
struct PipelineExecutableInfoKHR {
    StructureType sType = StructureType::PipelineExecutableInfoKHR;
    const void * pNext{};
    Pipeline pipeline{};
    uint32_t executableIndex{};
};
union PipelineExecutableStatisticValueKHR {
    Bool32 b32;
    int64_t i64;
    uint64_t u64;
    double f64;
};
struct PipelineExecutableStatisticKHR {
    StructureType sType = StructureType::PipelineExecutableStatisticKHR;
    void * pNext{};
    char name [ VK_MAX_DESCRIPTION_SIZE ]{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    PipelineExecutableStatisticFormatKHR format{};
    PipelineExecutableStatisticValueKHR value{};
};
struct PipelineExecutableInternalRepresentationKHR {
    StructureType sType = StructureType::PipelineExecutableInternalRepresentationKHR;
    void * pNext{};
    char name [ VK_MAX_DESCRIPTION_SIZE ]{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    Bool32 isText{};
    size_t dataSize{};
    void * pData{};
};
struct PhysicalDeviceShaderDemoteToHelperInvocationFeatures {
    StructureType sType = StructureType::PhysicalDeviceShaderDemoteToHelperInvocationFeatures;
    void * pNext{};
    Bool32 shaderDemoteToHelperInvocation{};
};
struct PhysicalDeviceTexelBufferAlignmentFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceTexelBufferAlignmentFeaturesEXT;
    void * pNext{};
    Bool32 texelBufferAlignment{};
};
struct PhysicalDeviceTexelBufferAlignmentProperties {
    StructureType sType = StructureType::PhysicalDeviceTexelBufferAlignmentProperties;
    void * pNext{};
    DeviceSize storageTexelBufferOffsetAlignmentBytes{};
    Bool32 storageTexelBufferOffsetSingleTexelAlignment{};
    DeviceSize uniformTexelBufferOffsetAlignmentBytes{};
    Bool32 uniformTexelBufferOffsetSingleTexelAlignment{};
};
struct PhysicalDeviceSubgroupSizeControlFeatures {
    StructureType sType = StructureType::PhysicalDeviceSubgroupSizeControlFeatures;
    void * pNext{};
    Bool32 subgroupSizeControl{};
    Bool32 computeFullSubgroups{};
};
struct PhysicalDeviceSubgroupSizeControlProperties {
    StructureType sType = StructureType::PhysicalDeviceSubgroupSizeControlProperties;
    void * pNext{};
    uint32_t minSubgroupSize{};
    uint32_t maxSubgroupSize{};
    uint32_t maxComputeWorkgroupSubgroups{};
    ShaderStageFlags requiredSubgroupSizeStages{};
};
struct PipelineShaderStageRequiredSubgroupSizeCreateInfo {
    StructureType sType = StructureType::PipelineShaderStageRequiredSubgroupSizeCreateInfo;
    void * pNext{};
    uint32_t requiredSubgroupSize{};
};
struct SubpassShadingPipelineCreateInfoHUAWEI {
    StructureType sType = StructureType::SubpassShadingPipelineCreateInfoHUAWEI;
    void * pNext{};
    RenderPass renderPass{};
    uint32_t subpass{};
};
struct PhysicalDeviceSubpassShadingPropertiesHUAWEI {
    StructureType sType = StructureType::PhysicalDeviceSubpassShadingPropertiesHUAWEI;
    void * pNext{};
    uint32_t maxSubpassShadingWorkgroupSizeAspectRatio{};
};
struct PhysicalDeviceClusterCullingShaderPropertiesHUAWEI {
    StructureType sType = StructureType::PhysicalDeviceClusterCullingShaderPropertiesHUAWEI;
    void * pNext{};
    uint32_t maxWorkGroupCount [3]{};
    uint32_t maxWorkGroupSize [3]{};
    uint32_t maxOutputClusterCount{};
    DeviceSize indirectBufferOffsetAlignment{};
};
struct MemoryOpaqueCaptureAddressAllocateInfo {
    StructureType sType = StructureType::MemoryOpaqueCaptureAddressAllocateInfo;
    const void * pNext{};
    uint64_t opaqueCaptureAddress{};
};
struct DeviceMemoryOpaqueCaptureAddressInfo {
    StructureType sType = StructureType::DeviceMemoryOpaqueCaptureAddressInfo;
    const void * pNext{};
    DeviceMemory memory{};
};
struct PhysicalDeviceLineRasterizationFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceLineRasterizationFeaturesKHR;
    void * pNext{};
    Bool32 rectangularLines{};
    Bool32 bresenhamLines{};
    Bool32 smoothLines{};
    Bool32 stippledRectangularLines{};
    Bool32 stippledBresenhamLines{};
    Bool32 stippledSmoothLines{};
};
struct PhysicalDeviceLineRasterizationPropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceLineRasterizationPropertiesKHR;
    void * pNext{};
    uint32_t lineSubPixelPrecisionBits{};
};
struct PipelineRasterizationLineStateCreateInfoKHR {
    StructureType sType = StructureType::PipelineRasterizationLineStateCreateInfoKHR;
    const void * pNext{};
    LineRasterizationModeKHR lineRasterizationMode{};
    Bool32 stippledLineEnable{};
    uint32_t lineStippleFactor{};
    uint16_t lineStipplePattern{};
};
struct PhysicalDevicePipelineCreationCacheControlFeatures {
    StructureType sType = StructureType::PhysicalDevicePipelineCreationCacheControlFeatures;
    void * pNext{};
    Bool32 pipelineCreationCacheControl{};
};
struct PhysicalDeviceVulkan11Features {
    StructureType sType = StructureType::PhysicalDeviceVulkan11Features;
    void * pNext{};
    Bool32 storageBuffer16BitAccess{};
    Bool32 uniformAndStorageBuffer16BitAccess{};
    Bool32 storagePushConstant16{};
    Bool32 storageInputOutput16{};
    Bool32 multiview{};
    Bool32 multiviewGeometryShader{};
    Bool32 multiviewTessellationShader{};
    Bool32 variablePointersStorageBuffer{};
    Bool32 variablePointers{};
    Bool32 protectedMemory{};
    Bool32 samplerYcbcrConversion{};
    Bool32 shaderDrawParameters{};
};
struct PhysicalDeviceVulkan11Properties {
    StructureType sType = StructureType::PhysicalDeviceVulkan11Properties;
    void * pNext{};
    uint8_t deviceUUID [ VK_UUID_SIZE ]{};
    uint8_t driverUUID [ VK_UUID_SIZE ]{};
    uint8_t deviceLUID [ VK_LUID_SIZE ]{};
    uint32_t deviceNodeMask{};
    Bool32 deviceLUIDValid{};
    uint32_t subgroupSize{};
    ShaderStageFlags subgroupSupportedStages{};
    SubgroupFeatureFlags subgroupSupportedOperations{};
    Bool32 subgroupQuadOperationsInAllStages{};
    PointClippingBehavior pointClippingBehavior{};
    uint32_t maxMultiviewViewCount{};
    uint32_t maxMultiviewInstanceIndex{};
    Bool32 protectedNoFault{};
    uint32_t maxPerSetDescriptors{};
    DeviceSize maxMemoryAllocationSize{};
};
struct PhysicalDeviceVulkan12Features {
    StructureType sType = StructureType::PhysicalDeviceVulkan12Features;
    void * pNext{};
    Bool32 samplerMirrorClampToEdge{};
    Bool32 drawIndirectCount{};
    Bool32 storageBuffer8BitAccess{};
    Bool32 uniformAndStorageBuffer8BitAccess{};
    Bool32 storagePushConstant8{};
    Bool32 shaderBufferInt64Atomics{};
    Bool32 shaderSharedInt64Atomics{};
    Bool32 shaderFloat16{};
    Bool32 shaderInt8{};
    Bool32 descriptorIndexing{};
    Bool32 shaderInputAttachmentArrayDynamicIndexing{};
    Bool32 shaderUniformTexelBufferArrayDynamicIndexing{};
    Bool32 shaderStorageTexelBufferArrayDynamicIndexing{};
    Bool32 shaderUniformBufferArrayNonUniformIndexing{};
    Bool32 shaderSampledImageArrayNonUniformIndexing{};
    Bool32 shaderStorageBufferArrayNonUniformIndexing{};
    Bool32 shaderStorageImageArrayNonUniformIndexing{};
    Bool32 shaderInputAttachmentArrayNonUniformIndexing{};
    Bool32 shaderUniformTexelBufferArrayNonUniformIndexing{};
    Bool32 shaderStorageTexelBufferArrayNonUniformIndexing{};
    Bool32 descriptorBindingUniformBufferUpdateAfterBind{};
    Bool32 descriptorBindingSampledImageUpdateAfterBind{};
    Bool32 descriptorBindingStorageImageUpdateAfterBind{};
    Bool32 descriptorBindingStorageBufferUpdateAfterBind{};
    Bool32 descriptorBindingUniformTexelBufferUpdateAfterBind{};
    Bool32 descriptorBindingStorageTexelBufferUpdateAfterBind{};
    Bool32 descriptorBindingUpdateUnusedWhilePending{};
    Bool32 descriptorBindingPartiallyBound{};
    Bool32 descriptorBindingVariableDescriptorCount{};
    Bool32 runtimeDescriptorArray{};
    Bool32 samplerFilterMinmax{};
    Bool32 scalarBlockLayout{};
    Bool32 imagelessFramebuffer{};
    Bool32 uniformBufferStandardLayout{};
    Bool32 shaderSubgroupExtendedTypes{};
    Bool32 separateDepthStencilLayouts{};
    Bool32 hostQueryReset{};
    Bool32 timelineSemaphore{};
    Bool32 bufferDeviceAddress{};
    Bool32 bufferDeviceAddressCaptureReplay{};
    Bool32 bufferDeviceAddressMultiDevice{};
    Bool32 vulkanMemoryModel{};
    Bool32 vulkanMemoryModelDeviceScope{};
    Bool32 vulkanMemoryModelAvailabilityVisibilityChains{};
    Bool32 shaderOutputViewportIndex{};
    Bool32 shaderOutputLayer{};
    Bool32 subgroupBroadcastDynamicId{};
};
struct PhysicalDeviceVulkan12Properties {
    StructureType sType = StructureType::PhysicalDeviceVulkan12Properties;
    void * pNext{};
    DriverId driverID{};
    char driverName [ VK_MAX_DRIVER_NAME_SIZE ]{};
    char driverInfo [ VK_MAX_DRIVER_INFO_SIZE ]{};
    ConformanceVersion conformanceVersion{};
    ShaderFloatControlsIndependence denormBehaviorIndependence{};
    ShaderFloatControlsIndependence roundingModeIndependence{};
    Bool32 shaderSignedZeroInfNanPreserveFloat16{};
    Bool32 shaderSignedZeroInfNanPreserveFloat32{};
    Bool32 shaderSignedZeroInfNanPreserveFloat64{};
    Bool32 shaderDenormPreserveFloat16{};
    Bool32 shaderDenormPreserveFloat32{};
    Bool32 shaderDenormPreserveFloat64{};
    Bool32 shaderDenormFlushToZeroFloat16{};
    Bool32 shaderDenormFlushToZeroFloat32{};
    Bool32 shaderDenormFlushToZeroFloat64{};
    Bool32 shaderRoundingModeRTEFloat16{};
    Bool32 shaderRoundingModeRTEFloat32{};
    Bool32 shaderRoundingModeRTEFloat64{};
    Bool32 shaderRoundingModeRTZFloat16{};
    Bool32 shaderRoundingModeRTZFloat32{};
    Bool32 shaderRoundingModeRTZFloat64{};
    uint32_t maxUpdateAfterBindDescriptorsInAllPools{};
    Bool32 shaderUniformBufferArrayNonUniformIndexingNative{};
    Bool32 shaderSampledImageArrayNonUniformIndexingNative{};
    Bool32 shaderStorageBufferArrayNonUniformIndexingNative{};
    Bool32 shaderStorageImageArrayNonUniformIndexingNative{};
    Bool32 shaderInputAttachmentArrayNonUniformIndexingNative{};
    Bool32 robustBufferAccessUpdateAfterBind{};
    Bool32 quadDivergentImplicitLod{};
    uint32_t maxPerStageDescriptorUpdateAfterBindSamplers{};
    uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers{};
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers{};
    uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages{};
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages{};
    uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments{};
    uint32_t maxPerStageUpdateAfterBindResources{};
    uint32_t maxDescriptorSetUpdateAfterBindSamplers{};
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers{};
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic{};
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers{};
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic{};
    uint32_t maxDescriptorSetUpdateAfterBindSampledImages{};
    uint32_t maxDescriptorSetUpdateAfterBindStorageImages{};
    uint32_t maxDescriptorSetUpdateAfterBindInputAttachments{};
    ResolveModeFlags supportedDepthResolveModes{};
    ResolveModeFlags supportedStencilResolveModes{};
    Bool32 independentResolveNone{};
    Bool32 independentResolve{};
    Bool32 filterMinmaxSingleComponentFormats{};
    Bool32 filterMinmaxImageComponentMapping{};
    uint64_t maxTimelineSemaphoreValueDifference{};
    SampleCountFlags framebufferIntegerColorSampleCounts{};
};
struct PhysicalDeviceVulkan13Features {
    StructureType sType = StructureType::PhysicalDeviceVulkan13Features;
    void * pNext{};
    Bool32 robustImageAccess{};
    Bool32 inlineUniformBlock{};
    Bool32 descriptorBindingInlineUniformBlockUpdateAfterBind{};
    Bool32 pipelineCreationCacheControl{};
    Bool32 privateData{};
    Bool32 shaderDemoteToHelperInvocation{};
    Bool32 shaderTerminateInvocation{};
    Bool32 subgroupSizeControl{};
    Bool32 computeFullSubgroups{};
    Bool32 synchronization2{};
    Bool32 textureCompressionASTC_HDR{};
    Bool32 shaderZeroInitializeWorkgroupMemory{};
    Bool32 dynamicRendering{};
    Bool32 shaderIntegerDotProduct{};
    Bool32 maintenance4{};
};
struct PhysicalDeviceVulkan13Properties {
    StructureType sType = StructureType::PhysicalDeviceVulkan13Properties;
    void * pNext{};
    uint32_t minSubgroupSize{};
    uint32_t maxSubgroupSize{};
    uint32_t maxComputeWorkgroupSubgroups{};
    ShaderStageFlags requiredSubgroupSizeStages{};
    uint32_t maxInlineUniformBlockSize{};
    uint32_t maxPerStageDescriptorInlineUniformBlocks{};
    uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks{};
    uint32_t maxDescriptorSetInlineUniformBlocks{};
    uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks{};
    uint32_t maxInlineUniformTotalSize{};
    Bool32 integerDotProduct8BitUnsignedAccelerated{};
    Bool32 integerDotProduct8BitSignedAccelerated{};
    Bool32 integerDotProduct8BitMixedSignednessAccelerated{};
    Bool32 integerDotProduct4x8BitPackedUnsignedAccelerated{};
    Bool32 integerDotProduct4x8BitPackedSignedAccelerated{};
    Bool32 integerDotProduct4x8BitPackedMixedSignednessAccelerated{};
    Bool32 integerDotProduct16BitUnsignedAccelerated{};
    Bool32 integerDotProduct16BitSignedAccelerated{};
    Bool32 integerDotProduct16BitMixedSignednessAccelerated{};
    Bool32 integerDotProduct32BitUnsignedAccelerated{};
    Bool32 integerDotProduct32BitSignedAccelerated{};
    Bool32 integerDotProduct32BitMixedSignednessAccelerated{};
    Bool32 integerDotProduct64BitUnsignedAccelerated{};
    Bool32 integerDotProduct64BitSignedAccelerated{};
    Bool32 integerDotProduct64BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating8BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating8BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating16BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating16BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating32BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating32BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating64BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating64BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated{};
    DeviceSize storageTexelBufferOffsetAlignmentBytes{};
    Bool32 storageTexelBufferOffsetSingleTexelAlignment{};
    DeviceSize uniformTexelBufferOffsetAlignmentBytes{};
    Bool32 uniformTexelBufferOffsetSingleTexelAlignment{};
    DeviceSize maxBufferSize{};
};
struct PipelineCompilerControlCreateInfoAMD {
    StructureType sType = StructureType::PipelineCompilerControlCreateInfoAMD;
    const void * pNext{};
    PipelineCompilerControlFlagsAMD compilerControlFlags{};
};
struct PhysicalDeviceCoherentMemoryFeaturesAMD {
    StructureType sType = StructureType::PhysicalDeviceCoherentMemoryFeaturesAMD;
    void * pNext{};
    Bool32 deviceCoherentMemory{};
};
struct PhysicalDeviceToolProperties {
    StructureType sType = StructureType::PhysicalDeviceToolProperties;
    void * pNext{};
    char name [ VK_MAX_EXTENSION_NAME_SIZE ]{};
    char version [ VK_MAX_EXTENSION_NAME_SIZE ]{};
    ToolPurposeFlags purposes{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    char layer [ VK_MAX_EXTENSION_NAME_SIZE ]{};
};
struct SamplerCustomBorderColorCreateInfoEXT {
    StructureType sType = StructureType::SamplerCustomBorderColorCreateInfoEXT;
    const void * pNext{};
    ClearColorValue customBorderColor{};
    Format format{};
};
struct PhysicalDeviceCustomBorderColorPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceCustomBorderColorPropertiesEXT;
    void * pNext{};
    uint32_t maxCustomBorderColorSamplers{};
};
struct PhysicalDeviceCustomBorderColorFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceCustomBorderColorFeaturesEXT;
    void * pNext{};
    Bool32 customBorderColors{};
    Bool32 customBorderColorWithoutFormat{};
};
struct SamplerBorderColorComponentMappingCreateInfoEXT {
    StructureType sType = StructureType::SamplerBorderColorComponentMappingCreateInfoEXT;
    const void * pNext{};
    ComponentMapping components{};
    Bool32 srgb{};
};
struct PhysicalDeviceBorderColorSwizzleFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceBorderColorSwizzleFeaturesEXT;
    void * pNext{};
    Bool32 borderColorSwizzle{};
    Bool32 borderColorSwizzleFromImage{};
};
union DeviceOrHostAddressKHR {
    DeviceAddress deviceAddress;
    void * hostAddress;
};
union DeviceOrHostAddressConstKHR {
    DeviceAddress deviceAddress;
    const void * hostAddress;
};
#if defined(VK_ENABLE_BETA_EXTENSIONS)
union DeviceOrHostAddressConstAMDX {
    DeviceAddress deviceAddress;
    const void * hostAddress;
};
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
struct AccelerationStructureGeometryTrianglesDataKHR {
    StructureType sType = StructureType::AccelerationStructureGeometryTrianglesDataKHR;
    const void * pNext{};
    Format vertexFormat{};
    DeviceOrHostAddressConstKHR vertexData{};
    DeviceSize vertexStride{};
    uint32_t maxVertex{};
    IndexType indexType{};
    DeviceOrHostAddressConstKHR indexData{};
    DeviceOrHostAddressConstKHR transformData{};
};
struct AccelerationStructureGeometryAabbsDataKHR {
    StructureType sType = StructureType::AccelerationStructureGeometryAabbsDataKHR;
    const void * pNext{};
    DeviceOrHostAddressConstKHR data{};
    DeviceSize stride{};
};
struct AccelerationStructureGeometryInstancesDataKHR {
    StructureType sType = StructureType::AccelerationStructureGeometryInstancesDataKHR;
    const void * pNext{};
    Bool32 arrayOfPointers{};
    DeviceOrHostAddressConstKHR data{};
};
union AccelerationStructureGeometryDataKHR {
    AccelerationStructureGeometryTrianglesDataKHR triangles;
    AccelerationStructureGeometryAabbsDataKHR aabbs;
    AccelerationStructureGeometryInstancesDataKHR instances;
};
struct AccelerationStructureGeometryKHR {
    StructureType sType = StructureType::AccelerationStructureGeometryKHR;
    const void * pNext{};
    GeometryTypeKHR geometryType{};
    AccelerationStructureGeometryDataKHR geometry{};
    GeometryFlagsKHR flags{};
};
struct AccelerationStructureBuildGeometryInfoKHR {
    StructureType sType = StructureType::AccelerationStructureBuildGeometryInfoKHR;
    const void * pNext{};
    AccelerationStructureTypeKHR type{};
    BuildAccelerationStructureFlagsKHR flags{};
    BuildAccelerationStructureModeKHR mode{};
    AccelerationStructureKHR srcAccelerationStructure{};
    AccelerationStructureKHR dstAccelerationStructure{};
    uint32_t geometryCount{};
    const AccelerationStructureGeometryKHR * pGeometries{};
    const AccelerationStructureGeometryKHR * const* ppGeometries{};
    DeviceOrHostAddressKHR scratchData{};
};
struct AccelerationStructureBuildRangeInfoKHR {
    uint32_t primitiveCount{};
    uint32_t primitiveOffset{};
    uint32_t firstVertex{};
    uint32_t transformOffset{};
};
struct AccelerationStructureCreateInfoKHR {
    StructureType sType = StructureType::AccelerationStructureCreateInfoKHR;
    const void * pNext{};
    AccelerationStructureCreateFlagsKHR createFlags{};
    Buffer buffer{};
    DeviceSize offset{};
    DeviceSize size{};
    AccelerationStructureTypeKHR type{};
    DeviceAddress deviceAddress{};
};
struct AabbPositionsKHR {
    float minX{};
    float minY{};
    float minZ{};
    float maxX{};
    float maxY{};
    float maxZ{};
};
struct TransformMatrixKHR {
    float matrix [3][4]{};
};
struct AccelerationStructureInstanceKHR {
    VkTransformMatrixKHR transform{};
    uint32_t instanceCustomIndex :24;
    uint32_t mask :8;
    uint32_t instanceShaderBindingTableRecordOffset :24;
    uint32_t flags :8;
    uint64_t accelerationStructureReference{};
};
struct AccelerationStructureDeviceAddressInfoKHR {
    StructureType sType = StructureType::AccelerationStructureDeviceAddressInfoKHR;
    const void * pNext{};
    AccelerationStructureKHR accelerationStructure{};
};
struct AccelerationStructureVersionInfoKHR {
    StructureType sType = StructureType::AccelerationStructureVersionInfoKHR;
    const void * pNext{};
    const uint8_t * pVersionData{};
};
struct CopyAccelerationStructureInfoKHR {
    StructureType sType = StructureType::CopyAccelerationStructureInfoKHR;
    const void * pNext{};
    AccelerationStructureKHR src{};
    AccelerationStructureKHR dst{};
    CopyAccelerationStructureModeKHR mode{};
};
struct CopyAccelerationStructureToMemoryInfoKHR {
    StructureType sType = StructureType::CopyAccelerationStructureToMemoryInfoKHR;
    const void * pNext{};
    AccelerationStructureKHR src{};
    DeviceOrHostAddressKHR dst{};
    CopyAccelerationStructureModeKHR mode{};
};
struct CopyMemoryToAccelerationStructureInfoKHR {
    StructureType sType = StructureType::CopyMemoryToAccelerationStructureInfoKHR;
    const void * pNext{};
    DeviceOrHostAddressConstKHR src{};
    AccelerationStructureKHR dst{};
    CopyAccelerationStructureModeKHR mode{};
};
struct PhysicalDeviceExtendedDynamicStateFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceExtendedDynamicStateFeaturesEXT;
    void * pNext{};
    Bool32 extendedDynamicState{};
};
struct PhysicalDeviceExtendedDynamicState2FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceExtendedDynamicState2FeaturesEXT;
    void * pNext{};
    Bool32 extendedDynamicState2{};
    Bool32 extendedDynamicState2LogicOp{};
    Bool32 extendedDynamicState2PatchControlPoints{};
};
struct PhysicalDeviceExtendedDynamicState3FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceExtendedDynamicState3FeaturesEXT;
    void * pNext{};
    Bool32 extendedDynamicState3TessellationDomainOrigin{};
    Bool32 extendedDynamicState3DepthClampEnable{};
    Bool32 extendedDynamicState3PolygonMode{};
    Bool32 extendedDynamicState3RasterizationSamples{};
    Bool32 extendedDynamicState3SampleMask{};
    Bool32 extendedDynamicState3AlphaToCoverageEnable{};
    Bool32 extendedDynamicState3AlphaToOneEnable{};
    Bool32 extendedDynamicState3LogicOpEnable{};
    Bool32 extendedDynamicState3ColorBlendEnable{};
    Bool32 extendedDynamicState3ColorBlendEquation{};
    Bool32 extendedDynamicState3ColorWriteMask{};
    Bool32 extendedDynamicState3RasterizationStream{};
    Bool32 extendedDynamicState3ConservativeRasterizationMode{};
    Bool32 extendedDynamicState3ExtraPrimitiveOverestimationSize{};
    Bool32 extendedDynamicState3DepthClipEnable{};
    Bool32 extendedDynamicState3SampleLocationsEnable{};
    Bool32 extendedDynamicState3ColorBlendAdvanced{};
    Bool32 extendedDynamicState3ProvokingVertexMode{};
    Bool32 extendedDynamicState3LineRasterizationMode{};
    Bool32 extendedDynamicState3LineStippleEnable{};
    Bool32 extendedDynamicState3DepthClipNegativeOneToOne{};
    Bool32 extendedDynamicState3ViewportWScalingEnable{};
    Bool32 extendedDynamicState3ViewportSwizzle{};
    Bool32 extendedDynamicState3CoverageToColorEnable{};
    Bool32 extendedDynamicState3CoverageToColorLocation{};
    Bool32 extendedDynamicState3CoverageModulationMode{};
    Bool32 extendedDynamicState3CoverageModulationTableEnable{};
    Bool32 extendedDynamicState3CoverageModulationTable{};
    Bool32 extendedDynamicState3CoverageReductionMode{};
    Bool32 extendedDynamicState3RepresentativeFragmentTestEnable{};
    Bool32 extendedDynamicState3ShadingRateImageEnable{};
};
struct PhysicalDeviceExtendedDynamicState3PropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceExtendedDynamicState3PropertiesEXT;
    void * pNext{};
    Bool32 dynamicPrimitiveTopologyUnrestricted{};
};
struct ColorBlendEquationEXT {
    BlendFactor srcColorBlendFactor{};
    BlendFactor dstColorBlendFactor{};
    BlendOp colorBlendOp{};
    BlendFactor srcAlphaBlendFactor{};
    BlendFactor dstAlphaBlendFactor{};
    BlendOp alphaBlendOp{};
};
struct ColorBlendAdvancedEXT {
    BlendOp advancedBlendOp{};
    Bool32 srcPremultiplied{};
    Bool32 dstPremultiplied{};
    BlendOverlapEXT blendOverlap{};
    Bool32 clampResults{};
};
struct RenderPassTransformBeginInfoQCOM {
    StructureType sType = StructureType::RenderPassTransformBeginInfoQCOM;
    void * pNext{};
    SurfaceTransformFlagBitsKHR transform{};
};
struct CopyCommandTransformInfoQCOM {
    StructureType sType = StructureType::CopyCommandTransformInfoQCOM;
    const void * pNext{};
    SurfaceTransformFlagBitsKHR transform{};
};
struct CommandBufferInheritanceRenderPassTransformInfoQCOM {
    StructureType sType = StructureType::CommandBufferInheritanceRenderPassTransformInfoQCOM;
    void * pNext{};
    SurfaceTransformFlagBitsKHR transform{};
    Rect2D renderArea{};
};
struct PhysicalDeviceDiagnosticsConfigFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceDiagnosticsConfigFeaturesNV;
    void * pNext{};
    Bool32 diagnosticsConfig{};
};
struct DeviceDiagnosticsConfigCreateInfoNV {
    StructureType sType = StructureType::DeviceDiagnosticsConfigCreateInfoNV;
    const void * pNext{};
    DeviceDiagnosticsConfigFlagsNV flags{};
};
struct PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures {
    StructureType sType = StructureType::PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;
    void * pNext{};
    Bool32 shaderZeroInitializeWorkgroupMemory{};
};
struct PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;
    void * pNext{};
    Bool32 shaderSubgroupUniformControlFlow{};
};
struct PhysicalDeviceRobustness2FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceRobustness2FeaturesEXT;
    void * pNext{};
    Bool32 robustBufferAccess2{};
    Bool32 robustImageAccess2{};
    Bool32 nullDescriptor{};
};
struct PhysicalDeviceRobustness2PropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceRobustness2PropertiesEXT;
    void * pNext{};
    DeviceSize robustStorageBufferAccessSizeAlignment{};
    DeviceSize robustUniformBufferAccessSizeAlignment{};
};
struct PhysicalDeviceImageRobustnessFeatures {
    StructureType sType = StructureType::PhysicalDeviceImageRobustnessFeatures;
    void * pNext{};
    Bool32 robustImageAccess{};
};
struct PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;
    void * pNext{};
    Bool32 workgroupMemoryExplicitLayout{};
    Bool32 workgroupMemoryExplicitLayoutScalarBlockLayout{};
    Bool32 workgroupMemoryExplicitLayout8BitAccess{};
    Bool32 workgroupMemoryExplicitLayout16BitAccess{};
};
#if defined(VK_ENABLE_BETA_EXTENSIONS)
struct PhysicalDevicePortabilitySubsetFeaturesKHR {
    StructureType sType = StructureType::PhysicalDevicePortabilitySubsetFeaturesKHR;
    void * pNext{};
    Bool32 constantAlphaColorBlendFactors{};
    Bool32 events{};
    Bool32 imageViewFormatReinterpretation{};
    Bool32 imageViewFormatSwizzle{};
    Bool32 imageView2DOn3DImage{};
    Bool32 multisampleArrayImage{};
    Bool32 mutableComparisonSamplers{};
    Bool32 pointPolygons{};
    Bool32 samplerMipLodBias{};
    Bool32 separateStencilMaskRef{};
    Bool32 shaderSampleRateInterpolationFunctions{};
    Bool32 tessellationIsolines{};
    Bool32 tessellationPointMode{};
    Bool32 triangleFans{};
    Bool32 vertexAttributeAccessBeyondStride{};
};
struct PhysicalDevicePortabilitySubsetPropertiesKHR {
    StructureType sType = StructureType::PhysicalDevicePortabilitySubsetPropertiesKHR;
    void * pNext{};
    uint32_t minVertexInputBindingStrideAlignment{};
};
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
struct PhysicalDevice4444FormatsFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevice4444FormatsFeaturesEXT;
    void * pNext{};
    Bool32 formatA4R4G4B4{};
    Bool32 formatA4B4G4R4{};
};
struct PhysicalDeviceSubpassShadingFeaturesHUAWEI {
    StructureType sType = StructureType::PhysicalDeviceSubpassShadingFeaturesHUAWEI;
    void * pNext{};
    Bool32 subpassShading{};
};
struct PhysicalDeviceClusterCullingShaderFeaturesHUAWEI {
    StructureType sType = StructureType::PhysicalDeviceClusterCullingShaderFeaturesHUAWEI;
    void * pNext{};
    Bool32 clustercullingShader{};
    Bool32 multiviewClusterCullingShader{};
};
struct PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI {
    StructureType sType = StructureType::PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;
    void * pNext{};
    Bool32 clusterShadingRate{};
};
struct BufferCopy2 {
    StructureType sType = StructureType::BufferCopy2;
    const void * pNext{};
    DeviceSize srcOffset{};
    DeviceSize dstOffset{};
    DeviceSize size{};
};
struct ImageCopy2 {
    StructureType sType = StructureType::ImageCopy2;
    const void * pNext{};
    ImageSubresourceLayers srcSubresource{};
    Offset3D srcOffset{};
    ImageSubresourceLayers dstSubresource{};
    Offset3D dstOffset{};
    Extent3D extent{};
};
struct ImageBlit2 {
    StructureType sType = StructureType::ImageBlit2;
    const void * pNext{};
    ImageSubresourceLayers srcSubresource{};
    Offset3D srcOffsets [2]{};
    ImageSubresourceLayers dstSubresource{};
    Offset3D dstOffsets [2]{};
};
struct BufferImageCopy2 {
    StructureType sType = StructureType::BufferImageCopy2;
    const void * pNext{};
    DeviceSize bufferOffset{};
    uint32_t bufferRowLength{};
    uint32_t bufferImageHeight{};
    ImageSubresourceLayers imageSubresource{};
    Offset3D imageOffset{};
    Extent3D imageExtent{};
};
struct ImageResolve2 {
    StructureType sType = StructureType::ImageResolve2;
    const void * pNext{};
    ImageSubresourceLayers srcSubresource{};
    Offset3D srcOffset{};
    ImageSubresourceLayers dstSubresource{};
    Offset3D dstOffset{};
    Extent3D extent{};
};
struct CopyBufferInfo2 {
    StructureType sType = StructureType::CopyBufferInfo2;
    const void * pNext{};
    Buffer srcBuffer{};
    Buffer dstBuffer{};
    uint32_t regionCount{};
    const BufferCopy2 * pRegions{};
};
struct CopyImageInfo2 {
    StructureType sType = StructureType::CopyImageInfo2;
    const void * pNext{};
    Image srcImage{};
    ImageLayout srcImageLayout{};
    Image dstImage{};
    ImageLayout dstImageLayout{};
    uint32_t regionCount{};
    const ImageCopy2 * pRegions{};
};
struct BlitImageInfo2 {
    StructureType sType = StructureType::BlitImageInfo2;
    const void * pNext{};
    Image srcImage{};
    ImageLayout srcImageLayout{};
    Image dstImage{};
    ImageLayout dstImageLayout{};
    uint32_t regionCount{};
    const ImageBlit2 * pRegions{};
    Filter filter{};
};
struct CopyBufferToImageInfo2 {
    StructureType sType = StructureType::CopyBufferToImageInfo2;
    const void * pNext{};
    Buffer srcBuffer{};
    Image dstImage{};
    ImageLayout dstImageLayout{};
    uint32_t regionCount{};
    const BufferImageCopy2 * pRegions{};
};
struct CopyImageToBufferInfo2 {
    StructureType sType = StructureType::CopyImageToBufferInfo2;
    const void * pNext{};
    Image srcImage{};
    ImageLayout srcImageLayout{};
    Buffer dstBuffer{};
    uint32_t regionCount{};
    const BufferImageCopy2 * pRegions{};
};
struct ResolveImageInfo2 {
    StructureType sType = StructureType::ResolveImageInfo2;
    const void * pNext{};
    Image srcImage{};
    ImageLayout srcImageLayout{};
    Image dstImage{};
    ImageLayout dstImageLayout{};
    uint32_t regionCount{};
    const ImageResolve2 * pRegions{};
};
struct PhysicalDeviceShaderImageAtomicInt64FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderImageAtomicInt64FeaturesEXT;
    void * pNext{};
    Bool32 shaderImageInt64Atomics{};
    Bool32 sparseImageInt64Atomics{};
};
struct FragmentShadingRateAttachmentInfoKHR {
    StructureType sType = StructureType::FragmentShadingRateAttachmentInfoKHR;
    const void * pNext{};
    const AttachmentReference2 * pFragmentShadingRateAttachment{};
    Extent2D shadingRateAttachmentTexelSize{};
};
struct PipelineFragmentShadingRateStateCreateInfoKHR {
    StructureType sType = StructureType::PipelineFragmentShadingRateStateCreateInfoKHR;
    const void * pNext{};
    Extent2D fragmentSize{};
    FragmentShadingRateCombinerOpKHR combinerOps [2]{};
};
struct PhysicalDeviceFragmentShadingRateFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceFragmentShadingRateFeaturesKHR;
    void * pNext{};
    Bool32 pipelineFragmentShadingRate{};
    Bool32 primitiveFragmentShadingRate{};
    Bool32 attachmentFragmentShadingRate{};
};
struct PhysicalDeviceFragmentShadingRatePropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceFragmentShadingRatePropertiesKHR;
    void * pNext{};
    Extent2D minFragmentShadingRateAttachmentTexelSize{};
    Extent2D maxFragmentShadingRateAttachmentTexelSize{};
    uint32_t maxFragmentShadingRateAttachmentTexelSizeAspectRatio{};
    Bool32 primitiveFragmentShadingRateWithMultipleViewports{};
    Bool32 layeredShadingRateAttachments{};
    Bool32 fragmentShadingRateNonTrivialCombinerOps{};
    Extent2D maxFragmentSize{};
    uint32_t maxFragmentSizeAspectRatio{};
    uint32_t maxFragmentShadingRateCoverageSamples{};
    SampleCountFlagBits maxFragmentShadingRateRasterizationSamples{};
    Bool32 fragmentShadingRateWithShaderDepthStencilWrites{};
    Bool32 fragmentShadingRateWithSampleMask{};
    Bool32 fragmentShadingRateWithShaderSampleMask{};
    Bool32 fragmentShadingRateWithConservativeRasterization{};
    Bool32 fragmentShadingRateWithFragmentShaderInterlock{};
    Bool32 fragmentShadingRateWithCustomSampleLocations{};
    Bool32 fragmentShadingRateStrictMultiplyCombiner{};
};
struct PhysicalDeviceFragmentShadingRateKHR {
    StructureType sType = StructureType::PhysicalDeviceFragmentShadingRateKHR;
    void * pNext{};
    SampleCountFlags sampleCounts{};
    Extent2D fragmentSize{};
};
struct PhysicalDeviceShaderTerminateInvocationFeatures {
    StructureType sType = StructureType::PhysicalDeviceShaderTerminateInvocationFeatures;
    void * pNext{};
    Bool32 shaderTerminateInvocation{};
};
struct PhysicalDeviceFragmentShadingRateEnumsFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceFragmentShadingRateEnumsFeaturesNV;
    void * pNext{};
    Bool32 fragmentShadingRateEnums{};
    Bool32 supersampleFragmentShadingRates{};
    Bool32 noInvocationFragmentShadingRates{};
};
struct PhysicalDeviceFragmentShadingRateEnumsPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceFragmentShadingRateEnumsPropertiesNV;
    void * pNext{};
    SampleCountFlagBits maxFragmentShadingRateInvocationCount{};
};
struct PipelineFragmentShadingRateEnumStateCreateInfoNV {
    StructureType sType = StructureType::PipelineFragmentShadingRateEnumStateCreateInfoNV;
    const void * pNext{};
    FragmentShadingRateTypeNV shadingRateType{};
    FragmentShadingRateNV shadingRate{};
    FragmentShadingRateCombinerOpKHR combinerOps [2]{};
};
struct AccelerationStructureBuildSizesInfoKHR {
    StructureType sType = StructureType::AccelerationStructureBuildSizesInfoKHR;
    const void * pNext{};
    DeviceSize accelerationStructureSize{};
    DeviceSize updateScratchSize{};
    DeviceSize buildScratchSize{};
};
struct PhysicalDeviceImage2DViewOf3DFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceImage2DViewOf3DFeaturesEXT;
    void * pNext{};
    Bool32 image2DViewOf3D{};
    Bool32 sampler2DViewOf3D{};
};
struct PhysicalDeviceImageSlicedViewOf3DFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceImageSlicedViewOf3DFeaturesEXT;
    void * pNext{};
    Bool32 imageSlicedViewOf3D{};
};
struct PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;
    void * pNext{};
    Bool32 attachmentFeedbackLoopDynamicState{};
};
struct PhysicalDeviceMutableDescriptorTypeFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceMutableDescriptorTypeFeaturesEXT;
    void * pNext{};
    Bool32 mutableDescriptorType{};
};
struct MutableDescriptorTypeListEXT {
    uint32_t descriptorTypeCount{};
    const DescriptorType * pDescriptorTypes{};
};
struct MutableDescriptorTypeCreateInfoEXT {
    StructureType sType = StructureType::MutableDescriptorTypeCreateInfoEXT;
    const void * pNext{};
    uint32_t mutableDescriptorTypeListCount{};
    const MutableDescriptorTypeListEXT * pMutableDescriptorTypeLists{};
};
struct PhysicalDeviceDepthClipControlFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDepthClipControlFeaturesEXT;
    void * pNext{};
    Bool32 depthClipControl{};
};
struct PipelineViewportDepthClipControlCreateInfoEXT {
    StructureType sType = StructureType::PipelineViewportDepthClipControlCreateInfoEXT;
    const void * pNext{};
    Bool32 negativeOneToOne{};
};
struct PhysicalDeviceVertexInputDynamicStateFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceVertexInputDynamicStateFeaturesEXT;
    void * pNext{};
    Bool32 vertexInputDynamicState{};
};
struct PhysicalDeviceExternalMemoryRDMAFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceExternalMemoryRdmaFeaturesNV;
    void * pNext{};
    Bool32 externalMemoryRDMA{};
};
struct VertexInputBindingDescription2EXT {
    StructureType sType = StructureType::VertexInputBindingDescription2EXT;
    void * pNext{};
    uint32_t binding{};
    uint32_t stride{};
    VertexInputRate inputRate{};
    uint32_t divisor{};
};
struct VertexInputAttributeDescription2EXT {
    StructureType sType = StructureType::VertexInputAttributeDescription2EXT;
    void * pNext{};
    uint32_t location{};
    uint32_t binding{};
    Format format{};
    uint32_t offset{};
};
struct PhysicalDeviceColorWriteEnableFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceColorWriteEnableFeaturesEXT;
    void * pNext{};
    Bool32 colorWriteEnable{};
};
struct PipelineColorWriteCreateInfoEXT {
    StructureType sType = StructureType::PipelineColorWriteCreateInfoEXT;
    const void * pNext{};
    uint32_t attachmentCount{};
    const Bool32 * pColorWriteEnables{};
};
struct MemoryBarrier2 {
    StructureType sType = StructureType::MemoryBarrier2;
    const void * pNext{};
    PipelineStageFlags2 srcStageMask{};
    AccessFlags2 srcAccessMask{};
    PipelineStageFlags2 dstStageMask{};
    AccessFlags2 dstAccessMask{};
};
struct ImageMemoryBarrier2 {
    StructureType sType = StructureType::ImageMemoryBarrier2;
    const void * pNext{};
    PipelineStageFlags2 srcStageMask{};
    AccessFlags2 srcAccessMask{};
    PipelineStageFlags2 dstStageMask{};
    AccessFlags2 dstAccessMask{};
    ImageLayout oldLayout{};
    ImageLayout newLayout{};
    uint32_t srcQueueFamilyIndex{};
    uint32_t dstQueueFamilyIndex{};
    Image image{};
    ImageSubresourceRange subresourceRange{};
};
struct BufferMemoryBarrier2 {
    StructureType sType = StructureType::BufferMemoryBarrier2;
    const void * pNext{};
    PipelineStageFlags2 srcStageMask{};
    AccessFlags2 srcAccessMask{};
    PipelineStageFlags2 dstStageMask{};
    AccessFlags2 dstAccessMask{};
    uint32_t srcQueueFamilyIndex{};
    uint32_t dstQueueFamilyIndex{};
    Buffer buffer{};
    DeviceSize offset{};
    DeviceSize size{};
};
struct DependencyInfo {
    StructureType sType = StructureType::DependencyInfo;
    const void * pNext{};
    DependencyFlags dependencyFlags{};
    uint32_t memoryBarrierCount{};
    const MemoryBarrier2 * pMemoryBarriers{};
    uint32_t bufferMemoryBarrierCount{};
    const BufferMemoryBarrier2 * pBufferMemoryBarriers{};
    uint32_t imageMemoryBarrierCount{};
    const ImageMemoryBarrier2 * pImageMemoryBarriers{};
};
struct SemaphoreSubmitInfo {
    StructureType sType = StructureType::SemaphoreSubmitInfo;
    const void * pNext{};
    Semaphore semaphore{};
    uint64_t value{};
    PipelineStageFlags2 stageMask{};
    uint32_t deviceIndex{};
};
struct CommandBufferSubmitInfo {
    StructureType sType = StructureType::CommandBufferSubmitInfo;
    const void * pNext{};
    CommandBuffer commandBuffer{};
    uint32_t deviceMask{};
};
struct SubmitInfo2 {
    StructureType sType = StructureType::SubmitInfo2;
    const void * pNext{};
    SubmitFlags flags{};
    uint32_t waitSemaphoreInfoCount{};
    const SemaphoreSubmitInfo * pWaitSemaphoreInfos{};
    uint32_t commandBufferInfoCount{};
    const CommandBufferSubmitInfo * pCommandBufferInfos{};
    uint32_t signalSemaphoreInfoCount{};
    const SemaphoreSubmitInfo * pSignalSemaphoreInfos{};
};
struct QueueFamilyCheckpointProperties2NV {
    StructureType sType = StructureType::QueueFamilyCheckpointProperties2NV;
    void * pNext{};
    PipelineStageFlags2 checkpointExecutionStageMask{};
};
struct CheckpointData2NV {
    StructureType sType = StructureType::CheckpointData2NV;
    void * pNext{};
    PipelineStageFlags2 stage{};
    void * pCheckpointMarker{};
};
struct PhysicalDeviceSynchronization2Features {
    StructureType sType = StructureType::PhysicalDeviceSynchronization2Features;
    void * pNext{};
    Bool32 synchronization2{};
};
struct PhysicalDeviceHostImageCopyFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceHostImageCopyFeaturesEXT;
    void * pNext{};
    Bool32 hostImageCopy{};
};
struct PhysicalDeviceHostImageCopyPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceHostImageCopyPropertiesEXT;
    void * pNext{};
    uint32_t copySrcLayoutCount{};
    ImageLayout * pCopySrcLayouts{};
    uint32_t copyDstLayoutCount{};
    ImageLayout * pCopyDstLayouts{};
    uint8_t optimalTilingLayoutUUID [ VK_UUID_SIZE ]{};
    Bool32 identicalMemoryTypeRequirements{};
};
struct MemoryToImageCopyEXT {
    StructureType sType = StructureType::MemoryToImageCopyEXT;
    const void * pNext{};
    const void * pHostPointer{};
    uint32_t memoryRowLength{};
    uint32_t memoryImageHeight{};
    ImageSubresourceLayers imageSubresource{};
    Offset3D imageOffset{};
    Extent3D imageExtent{};
};
struct ImageToMemoryCopyEXT {
    StructureType sType = StructureType::ImageToMemoryCopyEXT;
    const void * pNext{};
    void * pHostPointer{};
    uint32_t memoryRowLength{};
    uint32_t memoryImageHeight{};
    ImageSubresourceLayers imageSubresource{};
    Offset3D imageOffset{};
    Extent3D imageExtent{};
};
struct CopyMemoryToImageInfoEXT {
    StructureType sType = StructureType::CopyMemoryToImageInfoEXT;
    const void * pNext{};
    HostImageCopyFlagsEXT flags{};
    Image dstImage{};
    ImageLayout dstImageLayout{};
    uint32_t regionCount{};
    const MemoryToImageCopyEXT * pRegions{};
};
struct CopyImageToMemoryInfoEXT {
    StructureType sType = StructureType::CopyImageToMemoryInfoEXT;
    const void * pNext{};
    HostImageCopyFlagsEXT flags{};
    Image srcImage{};
    ImageLayout srcImageLayout{};
    uint32_t regionCount{};
    const ImageToMemoryCopyEXT * pRegions{};
};
struct CopyImageToImageInfoEXT {
    StructureType sType = StructureType::CopyImageToImageInfoEXT;
    const void * pNext{};
    HostImageCopyFlagsEXT flags{};
    Image srcImage{};
    ImageLayout srcImageLayout{};
    Image dstImage{};
    ImageLayout dstImageLayout{};
    uint32_t regionCount{};
    const ImageCopy2 * pRegions{};
};
struct HostImageLayoutTransitionInfoEXT {
    StructureType sType = StructureType::HostImageLayoutTransitionInfoEXT;
    const void * pNext{};
    Image image{};
    ImageLayout oldLayout{};
    ImageLayout newLayout{};
    ImageSubresourceRange subresourceRange{};
};
struct SubresourceHostMemcpySizeEXT {
    StructureType sType = StructureType::SubresourceHostMemcpySizeEXT;
    void * pNext{};
    DeviceSize size{};
};
struct HostImageCopyDevicePerformanceQueryEXT {
    StructureType sType = StructureType::HostImageCopyDevicePerformanceQueryEXT;
    void * pNext{};
    Bool32 optimalDeviceAccess{};
    Bool32 identicalMemoryLayout{};
};
struct PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;
    void * pNext{};
    Bool32 primitivesGeneratedQuery{};
    Bool32 primitivesGeneratedQueryWithRasterizerDiscard{};
    Bool32 primitivesGeneratedQueryWithNonZeroStreams{};
};
struct PhysicalDeviceLegacyDitheringFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceLegacyDitheringFeaturesEXT;
    void * pNext{};
    Bool32 legacyDithering{};
};
struct PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
    void * pNext{};
    Bool32 multisampledRenderToSingleSampled{};
};
struct SubpassResolvePerformanceQueryEXT {
    StructureType sType = StructureType::SubpassResolvePerformanceQueryEXT;
    void * pNext{};
    Bool32 optimal{};
};
struct MultisampledRenderToSingleSampledInfoEXT {
    StructureType sType = StructureType::MultisampledRenderToSingleSampledInfoEXT;
    const void * pNext{};
    Bool32 multisampledRenderToSingleSampledEnable{};
    SampleCountFlagBits rasterizationSamples{};
};
struct PhysicalDevicePipelineProtectedAccessFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePipelineProtectedAccessFeaturesEXT;
    void * pNext{};
    Bool32 pipelineProtectedAccess{};
};
struct QueueFamilyVideoPropertiesKHR {
    StructureType sType = StructureType::QueueFamilyVideoPropertiesKHR;
    void * pNext{};
    VideoCodecOperationFlagsKHR videoCodecOperations{};
};
struct QueueFamilyQueryResultStatusPropertiesKHR {
    StructureType sType = StructureType::QueueFamilyQueryResultStatusPropertiesKHR;
    void * pNext{};
    Bool32 queryResultStatusSupport{};
};
struct VideoProfileInfoKHR {
    StructureType sType = StructureType::VideoProfileInfoKHR;
    const void * pNext{};
    VideoCodecOperationFlagBitsKHR videoCodecOperation{};
    VideoChromaSubsamplingFlagsKHR chromaSubsampling{};
    VideoComponentBitDepthFlagsKHR lumaBitDepth{};
    VideoComponentBitDepthFlagsKHR chromaBitDepth{};
};
struct VideoProfileListInfoKHR {
    StructureType sType = StructureType::VideoProfileListInfoKHR;
    const void * pNext{};
    uint32_t profileCount{};
    const VideoProfileInfoKHR * pProfiles{};
};
struct PhysicalDeviceVideoFormatInfoKHR {
    StructureType sType = StructureType::PhysicalDeviceVideoFormatInfoKHR;
    const void * pNext{};
    ImageUsageFlags imageUsage{};
};
struct VideoFormatPropertiesKHR {
    StructureType sType = StructureType::VideoFormatPropertiesKHR;
    void * pNext{};
    Format format{};
    ComponentMapping componentMapping{};
    ImageCreateFlags imageCreateFlags{};
    ImageType imageType{};
    ImageTiling imageTiling{};
    ImageUsageFlags imageUsageFlags{};
};
struct VideoCapabilitiesKHR {
    StructureType sType = StructureType::VideoCapabilitiesKHR;
    void * pNext{};
    VideoCapabilityFlagsKHR flags{};
    DeviceSize minBitstreamBufferOffsetAlignment{};
    DeviceSize minBitstreamBufferSizeAlignment{};
    Extent2D pictureAccessGranularity{};
    Extent2D minCodedExtent{};
    Extent2D maxCodedExtent{};
    uint32_t maxDpbSlots{};
    uint32_t maxActiveReferencePictures{};
    ExtensionProperties stdHeaderVersion{};
};
struct VideoSessionMemoryRequirementsKHR {
    StructureType sType = StructureType::VideoSessionMemoryRequirementsKHR;
    void * pNext{};
    uint32_t memoryBindIndex{};
    MemoryRequirements memoryRequirements{};
};
struct BindVideoSessionMemoryInfoKHR {
    StructureType sType = StructureType::BindVideoSessionMemoryInfoKHR;
    const void * pNext{};
    uint32_t memoryBindIndex{};
    DeviceMemory memory{};
    DeviceSize memoryOffset{};
    DeviceSize memorySize{};
};
struct VideoPictureResourceInfoKHR {
    StructureType sType = StructureType::VideoPictureResourceInfoKHR;
    const void * pNext{};
    Offset2D codedOffset{};
    Extent2D codedExtent{};
    uint32_t baseArrayLayer{};
    ImageView imageViewBinding{};
};
struct VideoReferenceSlotInfoKHR {
    StructureType sType = StructureType::VideoReferenceSlotInfoKHR;
    const void * pNext{};
    int32_t slotIndex{};
    const VideoPictureResourceInfoKHR * pPictureResource{};
};
struct VideoDecodeCapabilitiesKHR {
    StructureType sType = StructureType::VideoDecodeCapabilitiesKHR;
    void * pNext{};
    VideoDecodeCapabilityFlagsKHR flags{};
};
struct VideoDecodeUsageInfoKHR {
    StructureType sType = StructureType::VideoDecodeUsageInfoKHR;
    const void * pNext{};
    VideoDecodeUsageFlagsKHR videoUsageHints{};
};
struct VideoDecodeInfoKHR {
    StructureType sType = StructureType::VideoDecodeInfoKHR;
    const void * pNext{};
    VideoDecodeFlagsKHR flags{};
    Buffer srcBuffer{};
    DeviceSize srcBufferOffset{};
    DeviceSize srcBufferRange{};
    VideoPictureResourceInfoKHR dstPictureResource{};
    const VideoReferenceSlotInfoKHR * pSetupReferenceSlot{};
    uint32_t referenceSlotCount{};
    const VideoReferenceSlotInfoKHR * pReferenceSlots{};
};
struct PhysicalDeviceVideoMaintenance1FeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceVideoMaintenance1FeaturesKHR;
    void * pNext{};
    Bool32 videoMaintenance1{};
};
struct VideoInlineQueryInfoKHR {
    StructureType sType = StructureType::VideoInlineQueryInfoKHR;
    const void * pNext{};
    QueryPool queryPool{};
    uint32_t firstQuery{};
    uint32_t queryCount{};
};
struct VideoDecodeH264ProfileInfoKHR {
    StructureType sType = StructureType::VideoDecodeH264ProfileInfoKHR;
    const void * pNext{};
    StdVideoH264ProfileIdc stdProfileIdc{};
    VideoDecodeH264PictureLayoutFlagBitsKHR pictureLayout{};
};
struct VideoDecodeH264CapabilitiesKHR {
    StructureType sType = StructureType::VideoDecodeH264CapabilitiesKHR;
    void * pNext{};
    StdVideoH264LevelIdc maxLevelIdc{};
    Offset2D fieldOffsetGranularity{};
};
struct VideoDecodeH264SessionParametersAddInfoKHR {
    StructureType sType = StructureType::VideoDecodeH264SessionParametersAddInfoKHR;
    const void * pNext{};
    uint32_t stdSPSCount{};
    const StdVideoH264SequenceParameterSet * pStdSPSs{};
    uint32_t stdPPSCount{};
    const StdVideoH264PictureParameterSet * pStdPPSs{};
};
struct VideoDecodeH264SessionParametersCreateInfoKHR {
    StructureType sType = StructureType::VideoDecodeH264SessionParametersCreateInfoKHR;
    const void * pNext{};
    uint32_t maxStdSPSCount{};
    uint32_t maxStdPPSCount{};
    const VideoDecodeH264SessionParametersAddInfoKHR * pParametersAddInfo{};
};
struct VideoDecodeH264PictureInfoKHR {
    StructureType sType = StructureType::VideoDecodeH264PictureInfoKHR;
    const void * pNext{};
    const StdVideoDecodeH264PictureInfo * pStdPictureInfo{};
    uint32_t sliceCount{};
    const uint32_t * pSliceOffsets{};
};
struct VideoDecodeH264DpbSlotInfoKHR {
    StructureType sType = StructureType::VideoDecodeH264DpbSlotInfoKHR;
    const void * pNext{};
    const StdVideoDecodeH264ReferenceInfo * pStdReferenceInfo{};
};
struct VideoDecodeH265ProfileInfoKHR {
    StructureType sType = StructureType::VideoDecodeH265ProfileInfoKHR;
    const void * pNext{};
    StdVideoH265ProfileIdc stdProfileIdc{};
};
struct VideoDecodeH265CapabilitiesKHR {
    StructureType sType = StructureType::VideoDecodeH265CapabilitiesKHR;
    void * pNext{};
    StdVideoH265LevelIdc maxLevelIdc{};
};
struct VideoDecodeH265SessionParametersAddInfoKHR {
    StructureType sType = StructureType::VideoDecodeH265SessionParametersAddInfoKHR;
    const void * pNext{};
    uint32_t stdVPSCount{};
    const StdVideoH265VideoParameterSet * pStdVPSs{};
    uint32_t stdSPSCount{};
    const StdVideoH265SequenceParameterSet * pStdSPSs{};
    uint32_t stdPPSCount{};
    const StdVideoH265PictureParameterSet * pStdPPSs{};
};
struct VideoDecodeH265SessionParametersCreateInfoKHR {
    StructureType sType = StructureType::VideoDecodeH265SessionParametersCreateInfoKHR;
    const void * pNext{};
    uint32_t maxStdVPSCount{};
    uint32_t maxStdSPSCount{};
    uint32_t maxStdPPSCount{};
    const VideoDecodeH265SessionParametersAddInfoKHR * pParametersAddInfo{};
};
struct VideoDecodeH265PictureInfoKHR {
    StructureType sType = StructureType::VideoDecodeH265PictureInfoKHR;
    const void * pNext{};
    const StdVideoDecodeH265PictureInfo * pStdPictureInfo{};
    uint32_t sliceSegmentCount{};
    const uint32_t * pSliceSegmentOffsets{};
};
struct VideoDecodeH265DpbSlotInfoKHR {
    StructureType sType = StructureType::VideoDecodeH265DpbSlotInfoKHR;
    const void * pNext{};
    const StdVideoDecodeH265ReferenceInfo * pStdReferenceInfo{};
};
struct VideoDecodeAV1ProfileInfoKHR {
    StructureType sType = StructureType::VideoDecodeAv1ProfileInfoKHR;
    const void * pNext{};
    StdVideoAV1Profile stdProfile{};
    Bool32 filmGrainSupport{};
};
struct VideoDecodeAV1CapabilitiesKHR {
    StructureType sType = StructureType::VideoDecodeAv1CapabilitiesKHR;
    void * pNext{};
    StdVideoAV1Level maxLevel{};
};
struct VideoDecodeAV1SessionParametersCreateInfoKHR {
    StructureType sType = StructureType::VideoDecodeAv1SessionParametersCreateInfoKHR;
    const void * pNext{};
    const StdVideoAV1SequenceHeader * pStdSequenceHeader{};
};
struct VideoDecodeAV1PictureInfoKHR {
    StructureType sType = StructureType::VideoDecodeAv1PictureInfoKHR;
    const void * pNext{};
    const StdVideoDecodeAV1PictureInfo * pStdPictureInfo{};
    int32_t referenceNameSlotIndices [ VK_MAX_VIDEO_AV1_REFERENCES_PER_FRAME_KHR ]{};
    uint32_t frameHeaderOffset{};
    uint32_t tileCount{};
    const uint32_t * pTileOffsets{};
    const uint32_t * pTileSizes{};
};
struct VideoDecodeAV1DpbSlotInfoKHR {
    StructureType sType = StructureType::VideoDecodeAv1DpbSlotInfoKHR;
    const void * pNext{};
    const StdVideoDecodeAV1ReferenceInfo * pStdReferenceInfo{};
};
struct VideoSessionCreateInfoKHR {
    StructureType sType = StructureType::VideoSessionCreateInfoKHR;
    const void * pNext{};
    uint32_t queueFamilyIndex{};
    VideoSessionCreateFlagsKHR flags{};
    const VideoProfileInfoKHR * pVideoProfile{};
    Format pictureFormat{};
    Extent2D maxCodedExtent{};
    Format referencePictureFormat{};
    uint32_t maxDpbSlots{};
    uint32_t maxActiveReferencePictures{};
    const ExtensionProperties * pStdHeaderVersion{};
};
struct VideoSessionParametersCreateInfoKHR {
    StructureType sType = StructureType::VideoSessionParametersCreateInfoKHR;
    const void * pNext{};
    VideoSessionParametersCreateFlagsKHR flags{};
    VideoSessionParametersKHR videoSessionParametersTemplate{};
    VideoSessionKHR videoSession{};
};
struct VideoSessionParametersUpdateInfoKHR {
    StructureType sType = StructureType::VideoSessionParametersUpdateInfoKHR;
    const void * pNext{};
    uint32_t updateSequenceCount{};
};
struct VideoEncodeSessionParametersGetInfoKHR {
    StructureType sType = StructureType::VideoEncodeSessionParametersGetInfoKHR;
    const void * pNext{};
    VideoSessionParametersKHR videoSessionParameters{};
};
struct VideoEncodeSessionParametersFeedbackInfoKHR {
    StructureType sType = StructureType::VideoEncodeSessionParametersFeedbackInfoKHR;
    void * pNext{};
    Bool32 hasOverrides{};
};
struct VideoBeginCodingInfoKHR {
    StructureType sType = StructureType::VideoBeginCodingInfoKHR;
    const void * pNext{};
    VideoBeginCodingFlagsKHR flags{};
    VideoSessionKHR videoSession{};
    VideoSessionParametersKHR videoSessionParameters{};
    uint32_t referenceSlotCount{};
    const VideoReferenceSlotInfoKHR * pReferenceSlots{};
};
struct VideoEndCodingInfoKHR {
    StructureType sType = StructureType::VideoEndCodingInfoKHR;
    const void * pNext{};
    VideoEndCodingFlagsKHR flags{};
};
struct VideoCodingControlInfoKHR {
    StructureType sType = StructureType::VideoCodingControlInfoKHR;
    const void * pNext{};
    VideoCodingControlFlagsKHR flags{};
};
struct VideoEncodeUsageInfoKHR {
    StructureType sType = StructureType::VideoEncodeUsageInfoKHR;
    const void * pNext{};
    VideoEncodeUsageFlagsKHR videoUsageHints{};
    VideoEncodeContentFlagsKHR videoContentHints{};
    VideoEncodeTuningModeKHR tuningMode{};
};
struct VideoEncodeInfoKHR {
    StructureType sType = StructureType::VideoEncodeInfoKHR;
    const void * pNext{};
    VideoEncodeFlagsKHR flags{};
    Buffer dstBuffer{};
    DeviceSize dstBufferOffset{};
    DeviceSize dstBufferRange{};
    VideoPictureResourceInfoKHR srcPictureResource{};
    const VideoReferenceSlotInfoKHR * pSetupReferenceSlot{};
    uint32_t referenceSlotCount{};
    const VideoReferenceSlotInfoKHR * pReferenceSlots{};
    uint32_t precedingExternallyEncodedBytes{};
};
struct QueryPoolVideoEncodeFeedbackCreateInfoKHR {
    StructureType sType = StructureType::QueryPoolVideoEncodeFeedbackCreateInfoKHR;
    const void * pNext{};
    VideoEncodeFeedbackFlagsKHR encodeFeedbackFlags{};
};
struct VideoEncodeQualityLevelInfoKHR {
    StructureType sType = StructureType::VideoEncodeQualityLevelInfoKHR;
    const void * pNext{};
    uint32_t qualityLevel{};
};
struct PhysicalDeviceVideoEncodeQualityLevelInfoKHR {
    StructureType sType = StructureType::PhysicalDeviceVideoEncodeQualityLevelInfoKHR;
    const void * pNext{};
    const VideoProfileInfoKHR * pVideoProfile{};
    uint32_t qualityLevel{};
};
struct VideoEncodeQualityLevelPropertiesKHR {
    StructureType sType = StructureType::VideoEncodeQualityLevelPropertiesKHR;
    void * pNext{};
    VideoEncodeRateControlModeFlagBitsKHR preferredRateControlMode{};
    uint32_t preferredRateControlLayerCount{};
};
struct VideoEncodeRateControlLayerInfoKHR {
    StructureType sType = StructureType::VideoEncodeRateControlLayerInfoKHR;
    const void * pNext{};
    uint64_t averageBitrate{};
    uint64_t maxBitrate{};
    uint32_t frameRateNumerator{};
    uint32_t frameRateDenominator{};
};
struct VideoEncodeRateControlInfoKHR {
    StructureType sType = StructureType::VideoEncodeRateControlInfoKHR;
    const void * pNext{};
    VideoEncodeRateControlFlagsKHR flags{};
    VideoEncodeRateControlModeFlagBitsKHR rateControlMode{};
    uint32_t layerCount{};
    const VideoEncodeRateControlLayerInfoKHR * pLayers{};
    uint32_t virtualBufferSizeInMs{};
    uint32_t initialVirtualBufferSizeInMs{};
};
struct VideoEncodeCapabilitiesKHR {
    StructureType sType = StructureType::VideoEncodeCapabilitiesKHR;
    void * pNext{};
    VideoEncodeCapabilityFlagsKHR flags{};
    VideoEncodeRateControlModeFlagsKHR rateControlModes{};
    uint32_t maxRateControlLayers{};
    uint64_t maxBitrate{};
    uint32_t maxQualityLevels{};
    Extent2D encodeInputPictureGranularity{};
    VideoEncodeFeedbackFlagsKHR supportedEncodeFeedbackFlags{};
};
struct VideoEncodeH264CapabilitiesKHR {
    StructureType sType = StructureType::VideoEncodeH264CapabilitiesKHR;
    void * pNext{};
    VideoEncodeH264CapabilityFlagsKHR flags{};
    StdVideoH264LevelIdc maxLevelIdc{};
    uint32_t maxSliceCount{};
    uint32_t maxPPictureL0ReferenceCount{};
    uint32_t maxBPictureL0ReferenceCount{};
    uint32_t maxL1ReferenceCount{};
    uint32_t maxTemporalLayerCount{};
    Bool32 expectDyadicTemporalLayerPattern{};
    int32_t minQp{};
    int32_t maxQp{};
    Bool32 prefersGopRemainingFrames{};
    Bool32 requiresGopRemainingFrames{};
    VideoEncodeH264StdFlagsKHR stdSyntaxFlags{};
};
struct VideoEncodeH264QpKHR {
    int32_t qpI{};
    int32_t qpP{};
    int32_t qpB{};
};
struct VideoEncodeH264QualityLevelPropertiesKHR {
    StructureType sType = StructureType::VideoEncodeH264QualityLevelPropertiesKHR;
    void * pNext{};
    VideoEncodeH264RateControlFlagsKHR preferredRateControlFlags{};
    uint32_t preferredGopFrameCount{};
    uint32_t preferredIdrPeriod{};
    uint32_t preferredConsecutiveBFrameCount{};
    uint32_t preferredTemporalLayerCount{};
    VideoEncodeH264QpKHR preferredConstantQp{};
    uint32_t preferredMaxL0ReferenceCount{};
    uint32_t preferredMaxL1ReferenceCount{};
    Bool32 preferredStdEntropyCodingModeFlag{};
};
struct VideoEncodeH264SessionCreateInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264SessionCreateInfoKHR;
    const void * pNext{};
    Bool32 useMaxLevelIdc{};
    StdVideoH264LevelIdc maxLevelIdc{};
};
struct VideoEncodeH264SessionParametersAddInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264SessionParametersAddInfoKHR;
    const void * pNext{};
    uint32_t stdSPSCount{};
    const StdVideoH264SequenceParameterSet * pStdSPSs{};
    uint32_t stdPPSCount{};
    const StdVideoH264PictureParameterSet * pStdPPSs{};
};
struct VideoEncodeH264SessionParametersCreateInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264SessionParametersCreateInfoKHR;
    const void * pNext{};
    uint32_t maxStdSPSCount{};
    uint32_t maxStdPPSCount{};
    const VideoEncodeH264SessionParametersAddInfoKHR * pParametersAddInfo{};
};
struct VideoEncodeH264SessionParametersGetInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264SessionParametersGetInfoKHR;
    const void * pNext{};
    Bool32 writeStdSPS{};
    Bool32 writeStdPPS{};
    uint32_t stdSPSId{};
    uint32_t stdPPSId{};
};
struct VideoEncodeH264SessionParametersFeedbackInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264SessionParametersFeedbackInfoKHR;
    void * pNext{};
    Bool32 hasStdSPSOverrides{};
    Bool32 hasStdPPSOverrides{};
};
struct VideoEncodeH264DpbSlotInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264DpbSlotInfoKHR;
    const void * pNext{};
    const StdVideoEncodeH264ReferenceInfo * pStdReferenceInfo{};
};
struct VideoEncodeH264NaluSliceInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264NaluSliceInfoKHR;
    const void * pNext{};
    int32_t constantQp{};
    const StdVideoEncodeH264SliceHeader * pStdSliceHeader{};
};
struct VideoEncodeH264PictureInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264PictureInfoKHR;
    const void * pNext{};
    uint32_t naluSliceEntryCount{};
    const VideoEncodeH264NaluSliceInfoKHR * pNaluSliceEntries{};
    const StdVideoEncodeH264PictureInfo * pStdPictureInfo{};
    Bool32 generatePrefixNalu{};
};
struct VideoEncodeH264ProfileInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264ProfileInfoKHR;
    const void * pNext{};
    StdVideoH264ProfileIdc stdProfileIdc{};
};
struct VideoEncodeH264RateControlInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264RateControlInfoKHR;
    const void * pNext{};
    VideoEncodeH264RateControlFlagsKHR flags{};
    uint32_t gopFrameCount{};
    uint32_t idrPeriod{};
    uint32_t consecutiveBFrameCount{};
    uint32_t temporalLayerCount{};
};
struct VideoEncodeH264FrameSizeKHR {
    uint32_t frameISize{};
    uint32_t framePSize{};
    uint32_t frameBSize{};
};
struct VideoEncodeH264GopRemainingFrameInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264GopRemainingFrameInfoKHR;
    const void * pNext{};
    Bool32 useGopRemainingFrames{};
    uint32_t gopRemainingI{};
    uint32_t gopRemainingP{};
    uint32_t gopRemainingB{};
};
struct VideoEncodeH264RateControlLayerInfoKHR {
    StructureType sType = StructureType::VideoEncodeH264RateControlLayerInfoKHR;
    const void * pNext{};
    Bool32 useMinQp{};
    VideoEncodeH264QpKHR minQp{};
    Bool32 useMaxQp{};
    VideoEncodeH264QpKHR maxQp{};
    Bool32 useMaxFrameSize{};
    VideoEncodeH264FrameSizeKHR maxFrameSize{};
};
struct VideoEncodeH265CapabilitiesKHR {
    StructureType sType = StructureType::VideoEncodeH265CapabilitiesKHR;
    void * pNext{};
    VideoEncodeH265CapabilityFlagsKHR flags{};
    StdVideoH265LevelIdc maxLevelIdc{};
    uint32_t maxSliceSegmentCount{};
    Extent2D maxTiles{};
    VideoEncodeH265CtbSizeFlagsKHR ctbSizes{};
    VideoEncodeH265TransformBlockSizeFlagsKHR transformBlockSizes{};
    uint32_t maxPPictureL0ReferenceCount{};
    uint32_t maxBPictureL0ReferenceCount{};
    uint32_t maxL1ReferenceCount{};
    uint32_t maxSubLayerCount{};
    Bool32 expectDyadicTemporalSubLayerPattern{};
    int32_t minQp{};
    int32_t maxQp{};
    Bool32 prefersGopRemainingFrames{};
    Bool32 requiresGopRemainingFrames{};
    VideoEncodeH265StdFlagsKHR stdSyntaxFlags{};
};
struct VideoEncodeH265QpKHR {
    int32_t qpI{};
    int32_t qpP{};
    int32_t qpB{};
};
struct VideoEncodeH265QualityLevelPropertiesKHR {
    StructureType sType = StructureType::VideoEncodeH265QualityLevelPropertiesKHR;
    void * pNext{};
    VideoEncodeH265RateControlFlagsKHR preferredRateControlFlags{};
    uint32_t preferredGopFrameCount{};
    uint32_t preferredIdrPeriod{};
    uint32_t preferredConsecutiveBFrameCount{};
    uint32_t preferredSubLayerCount{};
    VideoEncodeH265QpKHR preferredConstantQp{};
    uint32_t preferredMaxL0ReferenceCount{};
    uint32_t preferredMaxL1ReferenceCount{};
};
struct VideoEncodeH265SessionCreateInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265SessionCreateInfoKHR;
    const void * pNext{};
    Bool32 useMaxLevelIdc{};
    StdVideoH265LevelIdc maxLevelIdc{};
};
struct VideoEncodeH265SessionParametersAddInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265SessionParametersAddInfoKHR;
    const void * pNext{};
    uint32_t stdVPSCount{};
    const StdVideoH265VideoParameterSet * pStdVPSs{};
    uint32_t stdSPSCount{};
    const StdVideoH265SequenceParameterSet * pStdSPSs{};
    uint32_t stdPPSCount{};
    const StdVideoH265PictureParameterSet * pStdPPSs{};
};
struct VideoEncodeH265SessionParametersCreateInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265SessionParametersCreateInfoKHR;
    const void * pNext{};
    uint32_t maxStdVPSCount{};
    uint32_t maxStdSPSCount{};
    uint32_t maxStdPPSCount{};
    const VideoEncodeH265SessionParametersAddInfoKHR * pParametersAddInfo{};
};
struct VideoEncodeH265SessionParametersGetInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265SessionParametersGetInfoKHR;
    const void * pNext{};
    Bool32 writeStdVPS{};
    Bool32 writeStdSPS{};
    Bool32 writeStdPPS{};
    uint32_t stdVPSId{};
    uint32_t stdSPSId{};
    uint32_t stdPPSId{};
};
struct VideoEncodeH265SessionParametersFeedbackInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265SessionParametersFeedbackInfoKHR;
    void * pNext{};
    Bool32 hasStdVPSOverrides{};
    Bool32 hasStdSPSOverrides{};
    Bool32 hasStdPPSOverrides{};
};
struct VideoEncodeH265NaluSliceSegmentInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265NaluSliceSegmentInfoKHR;
    const void * pNext{};
    int32_t constantQp{};
    const StdVideoEncodeH265SliceSegmentHeader * pStdSliceSegmentHeader{};
};
struct VideoEncodeH265PictureInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265PictureInfoKHR;
    const void * pNext{};
    uint32_t naluSliceSegmentEntryCount{};
    const VideoEncodeH265NaluSliceSegmentInfoKHR * pNaluSliceSegmentEntries{};
    const StdVideoEncodeH265PictureInfo * pStdPictureInfo{};
};
struct VideoEncodeH265RateControlInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265RateControlInfoKHR;
    const void * pNext{};
    VideoEncodeH265RateControlFlagsKHR flags{};
    uint32_t gopFrameCount{};
    uint32_t idrPeriod{};
    uint32_t consecutiveBFrameCount{};
    uint32_t subLayerCount{};
};
struct VideoEncodeH265FrameSizeKHR {
    uint32_t frameISize{};
    uint32_t framePSize{};
    uint32_t frameBSize{};
};
struct VideoEncodeH265GopRemainingFrameInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265GopRemainingFrameInfoKHR;
    const void * pNext{};
    Bool32 useGopRemainingFrames{};
    uint32_t gopRemainingI{};
    uint32_t gopRemainingP{};
    uint32_t gopRemainingB{};
};
struct VideoEncodeH265RateControlLayerInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265RateControlLayerInfoKHR;
    const void * pNext{};
    Bool32 useMinQp{};
    VideoEncodeH265QpKHR minQp{};
    Bool32 useMaxQp{};
    VideoEncodeH265QpKHR maxQp{};
    Bool32 useMaxFrameSize{};
    VideoEncodeH265FrameSizeKHR maxFrameSize{};
};
struct VideoEncodeH265ProfileInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265ProfileInfoKHR;
    const void * pNext{};
    StdVideoH265ProfileIdc stdProfileIdc{};
};
struct VideoEncodeH265DpbSlotInfoKHR {
    StructureType sType = StructureType::VideoEncodeH265DpbSlotInfoKHR;
    const void * pNext{};
    const StdVideoEncodeH265ReferenceInfo * pStdReferenceInfo{};
};
struct PhysicalDeviceInheritedViewportScissorFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceInheritedViewportScissorFeaturesNV;
    void * pNext{};
    Bool32 inheritedViewportScissor2D{};
};
struct CommandBufferInheritanceViewportScissorInfoNV {
    StructureType sType = StructureType::CommandBufferInheritanceViewportScissorInfoNV;
    const void * pNext{};
    Bool32 viewportScissor2D{};
    uint32_t viewportDepthCount{};
    const Viewport * pViewportDepths{};
};
struct PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;
    void * pNext{};
    Bool32 ycbcr2plane444Formats{};
};
struct PhysicalDeviceProvokingVertexFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceProvokingVertexFeaturesEXT;
    void * pNext{};
    Bool32 provokingVertexLast{};
    Bool32 transformFeedbackPreservesProvokingVertex{};
};
struct PhysicalDeviceProvokingVertexPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceProvokingVertexPropertiesEXT;
    void * pNext{};
    Bool32 provokingVertexModePerPipeline{};
    Bool32 transformFeedbackPreservesTriangleFanProvokingVertex{};
};
struct PipelineRasterizationProvokingVertexStateCreateInfoEXT {
    StructureType sType = StructureType::PipelineRasterizationProvokingVertexStateCreateInfoEXT;
    const void * pNext{};
    ProvokingVertexModeEXT provokingVertexMode{};
};
struct CuModuleCreateInfoNVX {
    StructureType sType = StructureType::CuModuleCreateInfoNVX;
    const void * pNext{};
    size_t dataSize{};
    const void * pData{};
};
struct CuFunctionCreateInfoNVX {
    StructureType sType = StructureType::CuFunctionCreateInfoNVX;
    const void * pNext{};
    CuModuleNVX module{};
    const char * pName{};
};
struct CuLaunchInfoNVX {
    StructureType sType = StructureType::CuLaunchInfoNVX;
    const void * pNext{};
    CuFunctionNVX function{};
    uint32_t gridDimX{};
    uint32_t gridDimY{};
    uint32_t gridDimZ{};
    uint32_t blockDimX{};
    uint32_t blockDimY{};
    uint32_t blockDimZ{};
    uint32_t sharedMemBytes{};
    size_t paramCount{};
    const void * const * pParams{};
    size_t extraCount{};
    const void * const * pExtras{};
};
struct PhysicalDeviceDescriptorBufferFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDescriptorBufferFeaturesEXT;
    void * pNext{};
    Bool32 descriptorBuffer{};
    Bool32 descriptorBufferCaptureReplay{};
    Bool32 descriptorBufferImageLayoutIgnored{};
    Bool32 descriptorBufferPushDescriptors{};
};
struct PhysicalDeviceDescriptorBufferPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceDescriptorBufferPropertiesEXT;
    void * pNext{};
    Bool32 combinedImageSamplerDescriptorSingleArray{};
    Bool32 bufferlessPushDescriptors{};
    Bool32 allowSamplerImageViewPostSubmitCreation{};
    DeviceSize descriptorBufferOffsetAlignment{};
    uint32_t maxDescriptorBufferBindings{};
    uint32_t maxResourceDescriptorBufferBindings{};
    uint32_t maxSamplerDescriptorBufferBindings{};
    uint32_t maxEmbeddedImmutableSamplerBindings{};
    uint32_t maxEmbeddedImmutableSamplers{};
    size_t bufferCaptureReplayDescriptorDataSize{};
    size_t imageCaptureReplayDescriptorDataSize{};
    size_t imageViewCaptureReplayDescriptorDataSize{};
    size_t samplerCaptureReplayDescriptorDataSize{};
    size_t accelerationStructureCaptureReplayDescriptorDataSize{};
    size_t samplerDescriptorSize{};
    size_t combinedImageSamplerDescriptorSize{};
    size_t sampledImageDescriptorSize{};
    size_t storageImageDescriptorSize{};
    size_t uniformTexelBufferDescriptorSize{};
    size_t robustUniformTexelBufferDescriptorSize{};
    size_t storageTexelBufferDescriptorSize{};
    size_t robustStorageTexelBufferDescriptorSize{};
    size_t uniformBufferDescriptorSize{};
    size_t robustUniformBufferDescriptorSize{};
    size_t storageBufferDescriptorSize{};
    size_t robustStorageBufferDescriptorSize{};
    size_t inputAttachmentDescriptorSize{};
    size_t accelerationStructureDescriptorSize{};
    DeviceSize maxSamplerDescriptorBufferRange{};
    DeviceSize maxResourceDescriptorBufferRange{};
    DeviceSize samplerDescriptorBufferAddressSpaceSize{};
    DeviceSize resourceDescriptorBufferAddressSpaceSize{};
    DeviceSize descriptorBufferAddressSpaceSize{};
};
struct PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT;
    void * pNext{};
    size_t combinedImageSamplerDensityMapDescriptorSize{};
};
struct DescriptorAddressInfoEXT {
    StructureType sType = StructureType::DescriptorAddressInfoEXT;
    void * pNext{};
    DeviceAddress address{};
    DeviceSize range{};
    Format format{};
};
struct DescriptorBufferBindingInfoEXT {
    StructureType sType = StructureType::DescriptorBufferBindingInfoEXT;
    void * pNext{};
    DeviceAddress address{};
    BufferUsageFlags usage{};
};
struct DescriptorBufferBindingPushDescriptorBufferHandleEXT {
    StructureType sType = StructureType::DescriptorBufferBindingPushDescriptorBufferHandleEXT;
    void * pNext{};
    Buffer buffer{};
};
union DescriptorDataEXT {
    const Sampler * pSampler;
    const DescriptorImageInfo * pCombinedImageSampler;
    const DescriptorImageInfo * pInputAttachmentImage;
    const DescriptorImageInfo * pSampledImage;
    const DescriptorImageInfo * pStorageImage;
    const DescriptorAddressInfoEXT * pUniformTexelBuffer;
    const DescriptorAddressInfoEXT * pStorageTexelBuffer;
    const DescriptorAddressInfoEXT * pUniformBuffer;
    const DescriptorAddressInfoEXT * pStorageBuffer;
    DeviceAddress accelerationStructure;
};
struct DescriptorGetInfoEXT {
    StructureType sType = StructureType::DescriptorGetInfoEXT;
    const void * pNext{};
    DescriptorType type{};
    DescriptorDataEXT data{};
};
struct BufferCaptureDescriptorDataInfoEXT {
    StructureType sType = StructureType::BufferCaptureDescriptorDataInfoEXT;
    const void * pNext{};
    Buffer buffer{};
};
struct ImageCaptureDescriptorDataInfoEXT {
    StructureType sType = StructureType::ImageCaptureDescriptorDataInfoEXT;
    const void * pNext{};
    Image image{};
};
struct ImageViewCaptureDescriptorDataInfoEXT {
    StructureType sType = StructureType::ImageViewCaptureDescriptorDataInfoEXT;
    const void * pNext{};
    ImageView imageView{};
};
struct SamplerCaptureDescriptorDataInfoEXT {
    StructureType sType = StructureType::SamplerCaptureDescriptorDataInfoEXT;
    const void * pNext{};
    Sampler sampler{};
};
struct AccelerationStructureCaptureDescriptorDataInfoEXT {
    StructureType sType = StructureType::AccelerationStructureCaptureDescriptorDataInfoEXT;
    const void * pNext{};
    AccelerationStructureKHR accelerationStructure{};
    AccelerationStructureNV accelerationStructureNV{};
};
struct OpaqueCaptureDescriptorDataCreateInfoEXT {
    StructureType sType = StructureType::OpaqueCaptureDescriptorDataCreateInfoEXT;
    const void * pNext{};
    const void * opaqueCaptureDescriptorData{};
};
struct PhysicalDeviceShaderIntegerDotProductFeatures {
    StructureType sType = StructureType::PhysicalDeviceShaderIntegerDotProductFeatures;
    void * pNext{};
    Bool32 shaderIntegerDotProduct{};
};
struct PhysicalDeviceShaderIntegerDotProductProperties {
    StructureType sType = StructureType::PhysicalDeviceShaderIntegerDotProductProperties;
    void * pNext{};
    Bool32 integerDotProduct8BitUnsignedAccelerated{};
    Bool32 integerDotProduct8BitSignedAccelerated{};
    Bool32 integerDotProduct8BitMixedSignednessAccelerated{};
    Bool32 integerDotProduct4x8BitPackedUnsignedAccelerated{};
    Bool32 integerDotProduct4x8BitPackedSignedAccelerated{};
    Bool32 integerDotProduct4x8BitPackedMixedSignednessAccelerated{};
    Bool32 integerDotProduct16BitUnsignedAccelerated{};
    Bool32 integerDotProduct16BitSignedAccelerated{};
    Bool32 integerDotProduct16BitMixedSignednessAccelerated{};
    Bool32 integerDotProduct32BitUnsignedAccelerated{};
    Bool32 integerDotProduct32BitSignedAccelerated{};
    Bool32 integerDotProduct32BitMixedSignednessAccelerated{};
    Bool32 integerDotProduct64BitUnsignedAccelerated{};
    Bool32 integerDotProduct64BitSignedAccelerated{};
    Bool32 integerDotProduct64BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating8BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating8BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating16BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating16BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating32BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating32BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating64BitUnsignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating64BitSignedAccelerated{};
    Bool32 integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated{};
};
struct PhysicalDeviceDrmPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceDrmPropertiesEXT;
    void * pNext{};
    Bool32 hasPrimary{};
    Bool32 hasRender{};
    int64_t primaryMajor{};
    int64_t primaryMinor{};
    int64_t renderMajor{};
    int64_t renderMinor{};
};
struct PhysicalDeviceFragmentShaderBarycentricFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
    void * pNext{};
    Bool32 fragmentShaderBarycentric{};
};
struct PhysicalDeviceFragmentShaderBarycentricPropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceFragmentShaderBarycentricPropertiesKHR;
    void * pNext{};
    Bool32 triStripVertexOrderIndependentOfProvokingVertex{};
};
struct PhysicalDeviceRayTracingMotionBlurFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceRayTracingMotionBlurFeaturesNV;
    void * pNext{};
    Bool32 rayTracingMotionBlur{};
    Bool32 rayTracingMotionBlurPipelineTraceRaysIndirect{};
};
struct AccelerationStructureGeometryMotionTrianglesDataNV {
    StructureType sType = StructureType::AccelerationStructureGeometryMotionTrianglesDataNV;
    const void * pNext{};
    DeviceOrHostAddressConstKHR vertexData{};
};
struct AccelerationStructureMotionInfoNV {
    StructureType sType = StructureType::AccelerationStructureMotionInfoNV;
    const void * pNext{};
    uint32_t maxInstances{};
    AccelerationStructureMotionInfoFlagsNV flags{};
};
struct SRTDataNV {
    float sx{};
    float a{};
    float b{};
    float pvx{};
    float sy{};
    float c{};
    float pvy{};
    float sz{};
    float pvz{};
    float qx{};
    float qy{};
    float qz{};
    float qw{};
    float tx{};
    float ty{};
    float tz{};
};
struct AccelerationStructureSRTMotionInstanceNV {
    VkSRTDataNV transformT0{};
    VkSRTDataNV transformT1{};
    uint32_t instanceCustomIndex :24;
    uint32_t mask :8;
    uint32_t instanceShaderBindingTableRecordOffset :24;
    uint32_t flags :8;
    uint64_t accelerationStructureReference{};
};
struct AccelerationStructureMatrixMotionInstanceNV {
    VkTransformMatrixKHR transformT0{};
    VkTransformMatrixKHR transformT1{};
    uint32_t instanceCustomIndex :24;
    uint32_t mask :8;
    uint32_t instanceShaderBindingTableRecordOffset :24;
    uint32_t flags :8;
    uint64_t accelerationStructureReference{};
};
union AccelerationStructureMotionInstanceDataNV {
    AccelerationStructureInstanceKHR staticInstance;
    AccelerationStructureMatrixMotionInstanceNV matrixMotionInstance;
    AccelerationStructureSRTMotionInstanceNV srtMotionInstance;
};
struct AccelerationStructureMotionInstanceNV {
    AccelerationStructureMotionInstanceTypeNV type{};
    AccelerationStructureMotionInstanceFlagsNV flags{};
    AccelerationStructureMotionInstanceDataNV data{};
};
struct MemoryGetRemoteAddressInfoNV {
    StructureType sType = StructureType::MemoryGetRemoteAddressInfoNV;
    const void * pNext{};
    DeviceMemory memory{};
    ExternalMemoryHandleTypeFlagBits handleType{};
};
#if defined(VK_USE_PLATFORM_FUCHSIA)
struct ImportMemoryBufferCollectionFUCHSIA {
    StructureType sType = StructureType::ImportMemoryBufferCollectionFUCHSIA;
    const void * pNext{};
    BufferCollectionFUCHSIA collection{};
    uint32_t index{};
};
struct BufferCollectionImageCreateInfoFUCHSIA {
    StructureType sType = StructureType::BufferCollectionImageCreateInfoFUCHSIA;
    const void * pNext{};
    BufferCollectionFUCHSIA collection{};
    uint32_t index{};
};
struct BufferCollectionBufferCreateInfoFUCHSIA {
    StructureType sType = StructureType::BufferCollectionBufferCreateInfoFUCHSIA;
    const void * pNext{};
    BufferCollectionFUCHSIA collection{};
    uint32_t index{};
};
struct BufferCollectionCreateInfoFUCHSIA {
    StructureType sType = StructureType::BufferCollectionCreateInfoFUCHSIA;
    const void * pNext{};
    zx_handle_t collectionToken{};
};
struct SysmemColorSpaceFUCHSIA {
    StructureType sType = StructureType::SysmemColorSpaceFUCHSIA;
    const void * pNext{};
    uint32_t colorSpace{};
};
struct BufferCollectionPropertiesFUCHSIA {
    StructureType sType = StructureType::BufferCollectionPropertiesFUCHSIA;
    void * pNext{};
    uint32_t memoryTypeBits{};
    uint32_t bufferCount{};
    uint32_t createInfoIndex{};
    uint64_t sysmemPixelFormat{};
    FormatFeatureFlags formatFeatures{};
    SysmemColorSpaceFUCHSIA sysmemColorSpaceIndex{};
    ComponentMapping samplerYcbcrConversionComponents{};
    SamplerYcbcrModelConversion suggestedYcbcrModel{};
    SamplerYcbcrRange suggestedYcbcrRange{};
    ChromaLocation suggestedXChromaOffset{};
    ChromaLocation suggestedYChromaOffset{};
};
struct BufferCollectionConstraintsInfoFUCHSIA {
    StructureType sType = StructureType::BufferCollectionConstraintsInfoFUCHSIA;
    const void * pNext{};
    uint32_t minBufferCount{};
    uint32_t maxBufferCount{};
    uint32_t minBufferCountForCamping{};
    uint32_t minBufferCountForDedicatedSlack{};
    uint32_t minBufferCountForSharedSlack{};
};
struct BufferConstraintsInfoFUCHSIA {
    StructureType sType = StructureType::BufferConstraintsInfoFUCHSIA;
    const void * pNext{};
    BufferCreateInfo createInfo{};
    FormatFeatureFlags requiredFormatFeatures{};
    BufferCollectionConstraintsInfoFUCHSIA bufferCollectionConstraints{};
};
struct ImageFormatConstraintsInfoFUCHSIA {
    StructureType sType = StructureType::ImageFormatConstraintsInfoFUCHSIA;
    const void * pNext{};
    ImageCreateInfo imageCreateInfo{};
    FormatFeatureFlags requiredFormatFeatures{};
    ImageFormatConstraintsFlagsFUCHSIA flags{};
    uint64_t sysmemPixelFormat{};
    uint32_t colorSpaceCount{};
    const SysmemColorSpaceFUCHSIA * pColorSpaces{};
};
struct ImageConstraintsInfoFUCHSIA {
    StructureType sType = StructureType::ImageConstraintsInfoFUCHSIA;
    const void * pNext{};
    uint32_t formatConstraintsCount{};
    const ImageFormatConstraintsInfoFUCHSIA * pFormatConstraints{};
    BufferCollectionConstraintsInfoFUCHSIA bufferCollectionConstraints{};
    ImageConstraintsInfoFlagsFUCHSIA flags{};
};
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
struct CudaModuleCreateInfoNV {
    StructureType sType = StructureType::CudaModuleCreateInfoNV;
    const void * pNext{};
    size_t dataSize{};
    const void * pData{};
};
struct CudaFunctionCreateInfoNV {
    StructureType sType = StructureType::CudaFunctionCreateInfoNV;
    const void * pNext{};
    CudaModuleNV module{};
    const char * pName{};
};
struct CudaLaunchInfoNV {
    StructureType sType = StructureType::CudaLaunchInfoNV;
    const void * pNext{};
    CudaFunctionNV function{};
    uint32_t gridDimX{};
    uint32_t gridDimY{};
    uint32_t gridDimZ{};
    uint32_t blockDimX{};
    uint32_t blockDimY{};
    uint32_t blockDimZ{};
    uint32_t sharedMemBytes{};
    size_t paramCount{};
    const void * const * pParams{};
    size_t extraCount{};
    const void * const * pExtras{};
};
struct PhysicalDeviceRGBA10X6FormatsFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceRgba10X6FormatsFeaturesEXT;
    void * pNext{};
    Bool32 formatRgba10x6WithoutYCbCrSampler{};
};
struct FormatProperties3 {
    StructureType sType = StructureType::FormatProperties3;
    void * pNext{};
    FormatFeatureFlags2 linearTilingFeatures{};
    FormatFeatureFlags2 optimalTilingFeatures{};
    FormatFeatureFlags2 bufferFeatures{};
};
struct DrmFormatModifierProperties2EXT {
    uint64_t drmFormatModifier{};
    uint32_t drmFormatModifierPlaneCount{};
    FormatFeatureFlags2 drmFormatModifierTilingFeatures{};
};
struct DrmFormatModifierPropertiesList2EXT {
    StructureType sType = StructureType::DrmFormatModifierPropertiesList2EXT;
    void * pNext{};
    uint32_t drmFormatModifierCount{};
    DrmFormatModifierProperties2EXT * pDrmFormatModifierProperties{};
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct AndroidHardwareBufferFormatProperties2ANDROID {
    StructureType sType = StructureType::AndroidHardwareBufferFormatProperties2ANDROID;
    void * pNext{};
    Format format{};
    uint64_t externalFormat{};
    FormatFeatureFlags2 formatFeatures{};
    ComponentMapping samplerYcbcrConversionComponents{};
    SamplerYcbcrModelConversion suggestedYcbcrModel{};
    SamplerYcbcrRange suggestedYcbcrRange{};
    ChromaLocation suggestedXChromaOffset{};
    ChromaLocation suggestedYChromaOffset{};
};
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
struct PipelineRenderingCreateInfo {
    StructureType sType = StructureType::PipelineRenderingCreateInfo;
    const void * pNext{};
    uint32_t viewMask{};
    uint32_t colorAttachmentCount{};
    const Format * pColorAttachmentFormats{};
    Format depthAttachmentFormat{};
    Format stencilAttachmentFormat{};
};
struct RenderingAttachmentInfo {
    StructureType sType = StructureType::RenderingAttachmentInfo;
    const void * pNext{};
    ImageView imageView{};
    ImageLayout imageLayout{};
    ResolveModeFlagBits resolveMode{};
    ImageView resolveImageView{};
    ImageLayout resolveImageLayout{};
    AttachmentLoadOp loadOp{};
    AttachmentStoreOp storeOp{};
    ClearValue clearValue{};
};
struct RenderingInfo {
    StructureType sType = StructureType::RenderingInfo;
    const void * pNext{};
    RenderingFlags flags{};
    Rect2D renderArea{};
    uint32_t layerCount{};
    uint32_t viewMask{};
    uint32_t colorAttachmentCount{};
    const RenderingAttachmentInfo * pColorAttachments{};
    const RenderingAttachmentInfo * pDepthAttachment{};
    const RenderingAttachmentInfo * pStencilAttachment{};
};
struct RenderingFragmentShadingRateAttachmentInfoKHR {
    StructureType sType = StructureType::RenderingFragmentShadingRateAttachmentInfoKHR;
    const void * pNext{};
    ImageView imageView{};
    ImageLayout imageLayout{};
    Extent2D shadingRateAttachmentTexelSize{};
};
struct RenderingFragmentDensityMapAttachmentInfoEXT {
    StructureType sType = StructureType::RenderingFragmentDensityMapAttachmentInfoEXT;
    const void * pNext{};
    ImageView imageView{};
    ImageLayout imageLayout{};
};
struct PhysicalDeviceDynamicRenderingFeatures {
    StructureType sType = StructureType::PhysicalDeviceDynamicRenderingFeatures;
    void * pNext{};
    Bool32 dynamicRendering{};
};
struct CommandBufferInheritanceRenderingInfo {
    StructureType sType = StructureType::CommandBufferInheritanceRenderingInfo;
    const void * pNext{};
    RenderingFlags flags{};
    uint32_t viewMask{};
    uint32_t colorAttachmentCount{};
    const Format * pColorAttachmentFormats{};
    Format depthAttachmentFormat{};
    Format stencilAttachmentFormat{};
    SampleCountFlagBits rasterizationSamples{};
};
struct AttachmentSampleCountInfoAMD {
    StructureType sType = StructureType::AttachmentSampleCountInfoAMD;
    const void * pNext{};
    uint32_t colorAttachmentCount{};
    const SampleCountFlagBits * pColorAttachmentSamples{};
    SampleCountFlagBits depthStencilAttachmentSamples{};
};
struct MultiviewPerViewAttributesInfoNVX {
    StructureType sType = StructureType::MultiviewPerViewAttributesInfoNVX;
    const void * pNext{};
    Bool32 perViewAttributes{};
    Bool32 perViewAttributesPositionXOnly{};
};
struct PhysicalDeviceImageViewMinLodFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceImageViewMinLodFeaturesEXT;
    void * pNext{};
    Bool32 minLod{};
};
struct ImageViewMinLodCreateInfoEXT {
    StructureType sType = StructureType::ImageViewMinLodCreateInfoEXT;
    const void * pNext{};
    float minLod{};
};
struct PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
    void * pNext{};
    Bool32 rasterizationOrderColorAttachmentAccess{};
    Bool32 rasterizationOrderDepthAttachmentAccess{};
    Bool32 rasterizationOrderStencilAttachmentAccess{};
};
struct PhysicalDeviceLinearColorAttachmentFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceLinearColorAttachmentFeaturesNV;
    void * pNext{};
    Bool32 linearColorAttachment{};
};
struct PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;
    void * pNext{};
    Bool32 graphicsPipelineLibrary{};
};
struct PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;
    void * pNext{};
    Bool32 graphicsPipelineLibraryFastLinking{};
    Bool32 graphicsPipelineLibraryIndependentInterpolationDecoration{};
};
struct GraphicsPipelineLibraryCreateInfoEXT {
    StructureType sType = StructureType::GraphicsPipelineLibraryCreateInfoEXT;
    const void * pNext{};
    GraphicsPipelineLibraryFlagsEXT flags{};
};
struct PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE {
    StructureType sType = StructureType::PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;
    void * pNext{};
    Bool32 descriptorSetHostMapping{};
};
struct DescriptorSetBindingReferenceVALVE {
    StructureType sType = StructureType::DescriptorSetBindingReferenceVALVE;
    const void * pNext{};
    DescriptorSetLayout descriptorSetLayout{};
    uint32_t binding{};
};
struct DescriptorSetLayoutHostMappingInfoVALVE {
    StructureType sType = StructureType::DescriptorSetLayoutHostMappingInfoVALVE;
    void * pNext{};
    size_t descriptorOffset{};
    uint32_t descriptorSize{};
};
struct PhysicalDeviceNestedCommandBufferFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceNestedCommandBufferFeaturesEXT;
    void * pNext{};
    Bool32 nestedCommandBuffer{};
    Bool32 nestedCommandBufferRendering{};
    Bool32 nestedCommandBufferSimultaneousUse{};
};
struct PhysicalDeviceNestedCommandBufferPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceNestedCommandBufferPropertiesEXT;
    void * pNext{};
    uint32_t maxCommandBufferNestingLevel{};
};
struct PhysicalDeviceShaderModuleIdentifierFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderModuleIdentifierFeaturesEXT;
    void * pNext{};
    Bool32 shaderModuleIdentifier{};
};
struct PhysicalDeviceShaderModuleIdentifierPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderModuleIdentifierPropertiesEXT;
    void * pNext{};
    uint8_t shaderModuleIdentifierAlgorithmUUID [ VK_UUID_SIZE ]{};
};
struct PipelineShaderStageModuleIdentifierCreateInfoEXT {
    StructureType sType = StructureType::PipelineShaderStageModuleIdentifierCreateInfoEXT;
    const void * pNext{};
    uint32_t identifierSize{};
    const uint8_t * pIdentifier{};
};
struct ShaderModuleIdentifierEXT {
    StructureType sType = StructureType::ShaderModuleIdentifierEXT;
    void * pNext{};
    uint32_t identifierSize{};
    uint8_t identifier [ VK_MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT ]{};
};
struct ImageCompressionControlEXT {
    StructureType sType = StructureType::ImageCompressionControlEXT;
    const void * pNext{};
    ImageCompressionFlagsEXT flags{};
    uint32_t compressionControlPlaneCount{};
    ImageCompressionFixedRateFlagsEXT * pFixedRateFlags{};
};
struct PhysicalDeviceImageCompressionControlFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceImageCompressionControlFeaturesEXT;
    void * pNext{};
    Bool32 imageCompressionControl{};
};
struct ImageCompressionPropertiesEXT {
    StructureType sType = StructureType::ImageCompressionPropertiesEXT;
    void * pNext{};
    ImageCompressionFlagsEXT imageCompressionFlags{};
    ImageCompressionFixedRateFlagsEXT imageCompressionFixedRateFlags{};
};
struct PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;
    void * pNext{};
    Bool32 imageCompressionControlSwapchain{};
};
struct ImageSubresource2KHR {
    StructureType sType = StructureType::ImageSubresource2KHR;
    void * pNext{};
    ImageSubresource imageSubresource{};
};
struct SubresourceLayout2KHR {
    StructureType sType = StructureType::SubresourceLayout2KHR;
    void * pNext{};
    SubresourceLayout subresourceLayout{};
};
struct RenderPassCreationControlEXT {
    StructureType sType = StructureType::RenderPassCreationControlEXT;
    const void * pNext{};
    Bool32 disallowMerging{};
};
struct RenderPassCreationFeedbackInfoEXT {
    uint32_t postMergeSubpassCount{};
};
struct RenderPassCreationFeedbackCreateInfoEXT {
    StructureType sType = StructureType::RenderPassCreationFeedbackCreateInfoEXT;
    const void * pNext{};
    RenderPassCreationFeedbackInfoEXT * pRenderPassFeedback{};
};
struct RenderPassSubpassFeedbackInfoEXT {
    SubpassMergeStatusEXT subpassMergeStatus{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    uint32_t postMergeIndex{};
};
struct RenderPassSubpassFeedbackCreateInfoEXT {
    StructureType sType = StructureType::RenderPassSubpassFeedbackCreateInfoEXT;
    const void * pNext{};
    RenderPassSubpassFeedbackInfoEXT * pSubpassFeedback{};
};
struct PhysicalDeviceSubpassMergeFeedbackFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceSubpassMergeFeedbackFeaturesEXT;
    void * pNext{};
    Bool32 subpassMergeFeedback{};
};
struct MicromapUsageEXT {
    uint32_t count{};
    uint32_t subdivisionLevel{};
    uint32_t format{};
};
struct MicromapBuildInfoEXT {
    StructureType sType = StructureType::MicromapBuildInfoEXT;
    const void * pNext{};
    MicromapTypeEXT type{};
    BuildMicromapFlagsEXT flags{};
    BuildMicromapModeEXT mode{};
    MicromapEXT dstMicromap{};
    uint32_t usageCountsCount{};
    const MicromapUsageEXT * pUsageCounts{};
    const MicromapUsageEXT * const* ppUsageCounts{};
    DeviceOrHostAddressConstKHR data{};
    DeviceOrHostAddressKHR scratchData{};
    DeviceOrHostAddressConstKHR triangleArray{};
    DeviceSize triangleArrayStride{};
};
struct MicromapCreateInfoEXT {
    StructureType sType = StructureType::MicromapCreateInfoEXT;
    const void * pNext{};
    MicromapCreateFlagsEXT createFlags{};
    Buffer buffer{};
    DeviceSize offset{};
    DeviceSize size{};
    MicromapTypeEXT type{};
    DeviceAddress deviceAddress{};
};
struct MicromapVersionInfoEXT {
    StructureType sType = StructureType::MicromapVersionInfoEXT;
    const void * pNext{};
    const uint8_t * pVersionData{};
};
struct CopyMicromapInfoEXT {
    StructureType sType = StructureType::CopyMicromapInfoEXT;
    const void * pNext{};
    MicromapEXT src{};
    MicromapEXT dst{};
    CopyMicromapModeEXT mode{};
};
struct CopyMicromapToMemoryInfoEXT {
    StructureType sType = StructureType::CopyMicromapToMemoryInfoEXT;
    const void * pNext{};
    MicromapEXT src{};
    DeviceOrHostAddressKHR dst{};
    CopyMicromapModeEXT mode{};
};
struct CopyMemoryToMicromapInfoEXT {
    StructureType sType = StructureType::CopyMemoryToMicromapInfoEXT;
    const void * pNext{};
    DeviceOrHostAddressConstKHR src{};
    MicromapEXT dst{};
    CopyMicromapModeEXT mode{};
};
struct MicromapBuildSizesInfoEXT {
    StructureType sType = StructureType::MicromapBuildSizesInfoEXT;
    const void * pNext{};
    DeviceSize micromapSize{};
    DeviceSize buildScratchSize{};
    Bool32 discardable{};
};
struct MicromapTriangleEXT {
    uint32_t dataOffset{};
    uint16_t subdivisionLevel{};
    uint16_t format{};
};
struct PhysicalDeviceOpacityMicromapFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceOpacityMicromapFeaturesEXT;
    void * pNext{};
    Bool32 micromap{};
    Bool32 micromapCaptureReplay{};
    Bool32 micromapHostCommands{};
};
struct PhysicalDeviceOpacityMicromapPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceOpacityMicromapPropertiesEXT;
    void * pNext{};
    uint32_t maxOpacity2StateSubdivisionLevel{};
    uint32_t maxOpacity4StateSubdivisionLevel{};
};
struct AccelerationStructureTrianglesOpacityMicromapEXT {
    StructureType sType = StructureType::AccelerationStructureTrianglesOpacityMicromapEXT;
    void * pNext{};
    IndexType indexType{};
    DeviceOrHostAddressConstKHR indexBuffer{};
    DeviceSize indexStride{};
    uint32_t baseTriangle{};
    uint32_t usageCountsCount{};
    const MicromapUsageEXT * pUsageCounts{};
    const MicromapUsageEXT * const* ppUsageCounts{};
    MicromapEXT micromap{};
};
#if defined(VK_ENABLE_BETA_EXTENSIONS)
struct PhysicalDeviceDisplacementMicromapFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceDisplacementMicromapFeaturesNV;
    void * pNext{};
    Bool32 displacementMicromap{};
};
struct PhysicalDeviceDisplacementMicromapPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceDisplacementMicromapPropertiesNV;
    void * pNext{};
    uint32_t maxDisplacementMicromapSubdivisionLevel{};
};
struct AccelerationStructureTrianglesDisplacementMicromapNV {
    StructureType sType = StructureType::AccelerationStructureTrianglesDisplacementMicromapNV;
    void * pNext{};
    Format displacementBiasAndScaleFormat{};
    Format displacementVectorFormat{};
    DeviceOrHostAddressConstKHR displacementBiasAndScaleBuffer{};
    DeviceSize displacementBiasAndScaleStride{};
    DeviceOrHostAddressConstKHR displacementVectorBuffer{};
    DeviceSize displacementVectorStride{};
    DeviceOrHostAddressConstKHR displacedMicromapPrimitiveFlags{};
    DeviceSize displacedMicromapPrimitiveFlagsStride{};
    IndexType indexType{};
    DeviceOrHostAddressConstKHR indexBuffer{};
    DeviceSize indexStride{};
    uint32_t baseTriangle{};
    uint32_t usageCountsCount{};
    const MicromapUsageEXT * pUsageCounts{};
    const MicromapUsageEXT * const* ppUsageCounts{};
    MicromapEXT micromap{};
};
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
struct PipelinePropertiesIdentifierEXT {
    StructureType sType = StructureType::PipelinePropertiesIdentifierEXT;
    void * pNext{};
    uint8_t pipelineIdentifier [ VK_UUID_SIZE ]{};
};
struct PhysicalDevicePipelinePropertiesFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePipelinePropertiesFeaturesEXT;
    void * pNext{};
    Bool32 pipelinePropertiesIdentifier{};
};
struct PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD {
    StructureType sType = StructureType::PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;
    void * pNext{};
    Bool32 shaderEarlyAndLateFragmentTests{};
};
struct ExternalMemoryAcquireUnmodifiedEXT {
    StructureType sType = StructureType::ExternalMemoryAcquireUnmodifiedEXT;
    const void * pNext{};
    Bool32 acquireUnmodifiedMemory{};
};
#if defined(VK_USE_PLATFORM_METAL_EXT)
struct ExportMetalObjectCreateInfoEXT {
    StructureType sType = StructureType::ExportMetalObjectCreateInfoEXT;
    const void * pNext{};
    ExportMetalObjectTypeFlagBitsEXT exportObjectType{};
};
struct ExportMetalObjectsInfoEXT {
    StructureType sType = StructureType::ExportMetalObjectsInfoEXT;
    const void * pNext{};
};
struct ExportMetalDeviceInfoEXT {
    StructureType sType = StructureType::ExportMetalDeviceInfoEXT;
    const void * pNext{};
    MTLDevice_id mtlDevice{};
};
struct ExportMetalCommandQueueInfoEXT {
    StructureType sType = StructureType::ExportMetalCommandQueueInfoEXT;
    const void * pNext{};
    Queue queue{};
    MTLCommandQueue_id mtlCommandQueue{};
};
struct ExportMetalBufferInfoEXT {
    StructureType sType = StructureType::ExportMetalBufferInfoEXT;
    const void * pNext{};
    DeviceMemory memory{};
    MTLBuffer_id mtlBuffer{};
};
struct ImportMetalBufferInfoEXT {
    StructureType sType = StructureType::ImportMetalBufferInfoEXT;
    const void * pNext{};
    MTLBuffer_id mtlBuffer{};
};
struct ExportMetalTextureInfoEXT {
    StructureType sType = StructureType::ExportMetalTextureInfoEXT;
    const void * pNext{};
    Image image{};
    ImageView imageView{};
    BufferView bufferView{};
    ImageAspectFlagBits plane{};
    MTLTexture_id mtlTexture{};
};
struct ImportMetalTextureInfoEXT {
    StructureType sType = StructureType::ImportMetalTextureInfoEXT;
    const void * pNext{};
    ImageAspectFlagBits plane{};
    MTLTexture_id mtlTexture{};
};
struct ExportMetalIOSurfaceInfoEXT {
    StructureType sType = StructureType::ExportMetalIoSurfaceInfoEXT;
    const void * pNext{};
    Image image{};
    IOSurfaceRef ioSurface{};
};
struct ImportMetalIOSurfaceInfoEXT {
    StructureType sType = StructureType::ImportMetalIoSurfaceInfoEXT;
    const void * pNext{};
    IOSurfaceRef ioSurface{};
};
struct ExportMetalSharedEventInfoEXT {
    StructureType sType = StructureType::ExportMetalSharedEventInfoEXT;
    const void * pNext{};
    Semaphore semaphore{};
    Event event{};
    MTLSharedEvent_id mtlSharedEvent{};
};
struct ImportMetalSharedEventInfoEXT {
    StructureType sType = StructureType::ImportMetalSharedEventInfoEXT;
    const void * pNext{};
    MTLSharedEvent_id mtlSharedEvent{};
};
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
struct PhysicalDeviceNonSeamlessCubeMapFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceNonSeamlessCubeMapFeaturesEXT;
    void * pNext{};
    Bool32 nonSeamlessCubeMap{};
};
struct PhysicalDevicePipelineRobustnessFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePipelineRobustnessFeaturesEXT;
    void * pNext{};
    Bool32 pipelineRobustness{};
};
struct PipelineRobustnessCreateInfoEXT {
    StructureType sType = StructureType::PipelineRobustnessCreateInfoEXT;
    const void * pNext{};
    PipelineRobustnessBufferBehaviorEXT storageBuffers{};
    PipelineRobustnessBufferBehaviorEXT uniformBuffers{};
    PipelineRobustnessBufferBehaviorEXT vertexInputs{};
    PipelineRobustnessImageBehaviorEXT images{};
};
struct PhysicalDevicePipelineRobustnessPropertiesEXT {
    StructureType sType = StructureType::PhysicalDevicePipelineRobustnessPropertiesEXT;
    void * pNext{};
    PipelineRobustnessBufferBehaviorEXT defaultRobustnessStorageBuffers{};
    PipelineRobustnessBufferBehaviorEXT defaultRobustnessUniformBuffers{};
    PipelineRobustnessBufferBehaviorEXT defaultRobustnessVertexInputs{};
    PipelineRobustnessImageBehaviorEXT defaultRobustnessImages{};
};
struct ImageViewSampleWeightCreateInfoQCOM {
    StructureType sType = StructureType::ImageViewSampleWeightCreateInfoQCOM;
    const void * pNext{};
    Offset2D filterCenter{};
    Extent2D filterSize{};
    uint32_t numPhases{};
};
struct PhysicalDeviceImageProcessingFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceImageProcessingFeaturesQCOM;
    void * pNext{};
    Bool32 textureSampleWeighted{};
    Bool32 textureBoxFilter{};
    Bool32 textureBlockMatch{};
};
struct PhysicalDeviceImageProcessingPropertiesQCOM {
    StructureType sType = StructureType::PhysicalDeviceImageProcessingPropertiesQCOM;
    void * pNext{};
    uint32_t maxWeightFilterPhases{};
    Extent2D maxWeightFilterDimension{};
    Extent2D maxBlockMatchRegion{};
    Extent2D maxBoxFilterBlockSize{};
};
struct PhysicalDeviceTilePropertiesFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceTilePropertiesFeaturesQCOM;
    void * pNext{};
    Bool32 tileProperties{};
};
struct TilePropertiesQCOM {
    StructureType sType = StructureType::TilePropertiesQCOM;
    void * pNext{};
    Extent3D tileSize{};
    Extent2D apronSize{};
    Offset2D origin{};
};
struct PhysicalDeviceAmigoProfilingFeaturesSEC {
    StructureType sType = StructureType::PhysicalDeviceAmigoProfilingFeaturesSEC;
    void * pNext{};
    Bool32 amigoProfiling{};
};
struct AmigoProfilingSubmitInfoSEC {
    StructureType sType = StructureType::AmigoProfilingSubmitInfoSEC;
    const void * pNext{};
    uint64_t firstDrawTimestamp{};
    uint64_t swapBufferTimestamp{};
};
struct PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;
    void * pNext{};
    Bool32 attachmentFeedbackLoopLayout{};
};
struct PhysicalDeviceDepthClampZeroOneFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDepthClampZeroOneFeaturesEXT;
    void * pNext{};
    Bool32 depthClampZeroOne{};
};
struct PhysicalDeviceAddressBindingReportFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceAddressBindingReportFeaturesEXT;
    void * pNext{};
    Bool32 reportAddressBinding{};
};
struct DeviceAddressBindingCallbackDataEXT {
    StructureType sType = StructureType::DeviceAddressBindingCallbackDataEXT;
    void * pNext{};
    DeviceAddressBindingFlagsEXT flags{};
    DeviceAddress baseAddress{};
    DeviceSize size{};
    DeviceAddressBindingTypeEXT bindingType{};
};
struct PhysicalDeviceOpticalFlowFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceOpticalFlowFeaturesNV;
    void * pNext{};
    Bool32 opticalFlow{};
};
struct PhysicalDeviceOpticalFlowPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceOpticalFlowPropertiesNV;
    void * pNext{};
    OpticalFlowGridSizeFlagsNV supportedOutputGridSizes{};
    OpticalFlowGridSizeFlagsNV supportedHintGridSizes{};
    Bool32 hintSupported{};
    Bool32 costSupported{};
    Bool32 bidirectionalFlowSupported{};
    Bool32 globalFlowSupported{};
    uint32_t minWidth{};
    uint32_t minHeight{};
    uint32_t maxWidth{};
    uint32_t maxHeight{};
    uint32_t maxNumRegionsOfInterest{};
};
struct OpticalFlowImageFormatInfoNV {
    StructureType sType = StructureType::OpticalFlowImageFormatInfoNV;
    const void * pNext{};
    OpticalFlowUsageFlagsNV usage{};
};
struct OpticalFlowImageFormatPropertiesNV {
    StructureType sType = StructureType::OpticalFlowImageFormatPropertiesNV;
    const void * pNext{};
    Format format{};
};
struct OpticalFlowSessionCreateInfoNV {
    StructureType sType = StructureType::OpticalFlowSessionCreateInfoNV;
    void * pNext{};
    uint32_t width{};
    uint32_t height{};
    Format imageFormat{};
    Format flowVectorFormat{};
    Format costFormat{};
    OpticalFlowGridSizeFlagsNV outputGridSize{};
    OpticalFlowGridSizeFlagsNV hintGridSize{};
    OpticalFlowPerformanceLevelNV performanceLevel{};
    OpticalFlowSessionCreateFlagsNV flags{};
};
struct OpticalFlowSessionCreatePrivateDataInfoNV {
    StructureType sType = StructureType::OpticalFlowSessionCreatePrivateDataInfoNV;
    void * pNext{};
    uint32_t id{};
    uint32_t size{};
    const void * pPrivateData{};
};
struct OpticalFlowExecuteInfoNV {
    StructureType sType = StructureType::OpticalFlowExecuteInfoNV;
    void * pNext{};
    OpticalFlowExecuteFlagsNV flags{};
    uint32_t regionCount{};
    const Rect2D * pRegions{};
};
struct PhysicalDeviceFaultFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceFaultFeaturesEXT;
    void * pNext{};
    Bool32 deviceFault{};
    Bool32 deviceFaultVendorBinary{};
};
struct DeviceFaultAddressInfoEXT {
    DeviceFaultAddressTypeEXT addressType{};
    DeviceAddress reportedAddress{};
    DeviceSize addressPrecision{};
};
struct DeviceFaultVendorInfoEXT {
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    uint64_t vendorFaultCode{};
    uint64_t vendorFaultData{};
};
struct DeviceFaultCountsEXT {
    StructureType sType = StructureType::DeviceFaultCountsEXT;
    void * pNext{};
    uint32_t addressInfoCount{};
    uint32_t vendorInfoCount{};
    DeviceSize vendorBinarySize{};
};
struct DeviceFaultInfoEXT {
    StructureType sType = StructureType::DeviceFaultInfoEXT;
    void * pNext{};
    char description [ VK_MAX_DESCRIPTION_SIZE ]{};
    DeviceFaultAddressInfoEXT * pAddressInfos{};
    DeviceFaultVendorInfoEXT * pVendorInfos{};
    void * pVendorBinaryData{};
};
struct DeviceFaultVendorBinaryHeaderVersionOneEXT {
    uint32_t headerSize{};
    DeviceFaultVendorBinaryHeaderVersionEXT headerVersion{};
    uint32_t vendorID{};
    uint32_t deviceID{};
    uint32_t driverVersion{};
    uint8_t pipelineCacheUUID [ VK_UUID_SIZE ]{};
    uint32_t applicationNameOffset{};
    uint32_t applicationVersion{};
    uint32_t engineNameOffset{};
    uint32_t engineVersion{};
    uint32_t apiVersion{};
};
struct PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT {
    StructureType sType = StructureType::PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;
    void * pNext{};
    Bool32 pipelineLibraryGroupHandles{};
};
struct DepthBiasInfoEXT {
    StructureType sType = StructureType::DepthBiasInfoEXT;
    const void * pNext{};
    float depthBiasConstantFactor{};
    float depthBiasClamp{};
    float depthBiasSlopeFactor{};
};
struct DepthBiasRepresentationInfoEXT {
    StructureType sType = StructureType::DepthBiasRepresentationInfoEXT;
    const void * pNext{};
    DepthBiasRepresentationEXT depthBiasRepresentation{};
    Bool32 depthBiasExact{};
};
struct DecompressMemoryRegionNV {
    DeviceAddress srcAddress{};
    DeviceAddress dstAddress{};
    DeviceSize compressedSize{};
    DeviceSize decompressedSize{};
    MemoryDecompressionMethodFlagsNV decompressionMethod{};
};
struct PhysicalDeviceShaderCoreBuiltinsPropertiesARM {
    StructureType sType = StructureType::PhysicalDeviceShaderCoreBuiltinsPropertiesARM;
    void * pNext{};
    uint64_t shaderCoreMask{};
    uint32_t shaderCoreCount{};
    uint32_t shaderWarpsPerCore{};
};
struct PhysicalDeviceShaderCoreBuiltinsFeaturesARM {
    StructureType sType = StructureType::PhysicalDeviceShaderCoreBuiltinsFeaturesARM;
    void * pNext{};
    Bool32 shaderCoreBuiltins{};
};
struct FrameBoundaryEXT {
    StructureType sType = StructureType::FrameBoundaryEXT;
    const void * pNext{};
    FrameBoundaryFlagsEXT flags{};
    uint64_t frameID{};
    uint32_t imageCount{};
    const Image * pImages{};
    uint32_t bufferCount{};
    const Buffer * pBuffers{};
    uint64_t tagName{};
    size_t tagSize{};
    const void * pTag{};
};
struct PhysicalDeviceFrameBoundaryFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceFrameBoundaryFeaturesEXT;
    void * pNext{};
    Bool32 frameBoundary{};
};
struct PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;
    void * pNext{};
    Bool32 dynamicRenderingUnusedAttachments{};
};
struct SurfacePresentModeEXT {
    StructureType sType = StructureType::SurfacePresentModeEXT;
    void * pNext{};
    PresentModeKHR presentMode{};
};
struct SurfacePresentScalingCapabilitiesEXT {
    StructureType sType = StructureType::SurfacePresentScalingCapabilitiesEXT;
    void * pNext{};
    PresentScalingFlagsEXT supportedPresentScaling{};
    PresentGravityFlagsEXT supportedPresentGravityX{};
    PresentGravityFlagsEXT supportedPresentGravityY{};
    Extent2D minScaledImageExtent{};
    Extent2D maxScaledImageExtent{};
};
struct SurfacePresentModeCompatibilityEXT {
    StructureType sType = StructureType::SurfacePresentModeCompatibilityEXT;
    void * pNext{};
    uint32_t presentModeCount{};
    PresentModeKHR * pPresentModes{};
};
struct PhysicalDeviceSwapchainMaintenance1FeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceSwapchainMaintenance1FeaturesEXT;
    void * pNext{};
    Bool32 swapchainMaintenance1{};
};
struct SwapchainPresentFenceInfoEXT {
    StructureType sType = StructureType::SwapchainPresentFenceInfoEXT;
    const void * pNext{};
    uint32_t swapchainCount{};
    const Fence * pFences{};
};
struct SwapchainPresentModesCreateInfoEXT {
    StructureType sType = StructureType::SwapchainPresentModesCreateInfoEXT;
    const void * pNext{};
    uint32_t presentModeCount{};
    const PresentModeKHR * pPresentModes{};
};
struct SwapchainPresentModeInfoEXT {
    StructureType sType = StructureType::SwapchainPresentModeInfoEXT;
    const void * pNext{};
    uint32_t swapchainCount{};
    const PresentModeKHR * pPresentModes{};
};
struct SwapchainPresentScalingCreateInfoEXT {
    StructureType sType = StructureType::SwapchainPresentScalingCreateInfoEXT;
    const void * pNext{};
    PresentScalingFlagsEXT scalingBehavior{};
    PresentGravityFlagsEXT presentGravityX{};
    PresentGravityFlagsEXT presentGravityY{};
};
struct ReleaseSwapchainImagesInfoEXT {
    StructureType sType = StructureType::ReleaseSwapchainImagesInfoEXT;
    const void * pNext{};
    SwapchainKHR swapchain{};
    uint32_t imageIndexCount{};
    const uint32_t * pImageIndices{};
};
struct PhysicalDeviceDepthBiasControlFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceDepthBiasControlFeaturesEXT;
    void * pNext{};
    Bool32 depthBiasControl{};
    Bool32 leastRepresentableValueForceUnormRepresentation{};
    Bool32 floatRepresentation{};
    Bool32 depthBiasExact{};
};
struct PhysicalDeviceRayTracingInvocationReorderFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceRayTracingInvocationReorderFeaturesNV;
    void * pNext{};
    Bool32 rayTracingInvocationReorder{};
};
struct PhysicalDeviceRayTracingInvocationReorderPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceRayTracingInvocationReorderPropertiesNV;
    void * pNext{};
    RayTracingInvocationReorderModeNV rayTracingInvocationReorderReorderingHint{};
};
struct PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;
    void * pNext{};
    Bool32 extendedSparseAddressSpace{};
};
struct PhysicalDeviceExtendedSparseAddressSpacePropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceExtendedSparseAddressSpacePropertiesNV;
    void * pNext{};
    DeviceSize extendedSparseAddressSpaceSize{};
    ImageUsageFlags extendedSparseImageUsageFlags{};
    BufferUsageFlags extendedSparseBufferUsageFlags{};
};
struct DirectDriverLoadingInfoLUNARG {
    StructureType sType = StructureType::DirectDriverLoadingInfoLUNARG;
    void * pNext{};
    DirectDriverLoadingFlagsLUNARG flags{};
    PFN_vkGetInstanceProcAddrLUNARG pfnGetInstanceProcAddr{};
};
struct DirectDriverLoadingListLUNARG {
    StructureType sType = StructureType::DirectDriverLoadingListLUNARG;
    const void * pNext{};
    DirectDriverLoadingModeLUNARG mode{};
    uint32_t driverCount{};
    const DirectDriverLoadingInfoLUNARG * pDrivers{};
};
struct PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;
    void * pNext{};
    Bool32 multiviewPerViewViewports{};
};
struct PhysicalDeviceRayTracingPositionFetchFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceRayTracingPositionFetchFeaturesKHR;
    void * pNext{};
    Bool32 rayTracingPositionFetch{};
};
struct DeviceImageSubresourceInfoKHR {
    StructureType sType = StructureType::DeviceImageSubresourceInfoKHR;
    const void * pNext{};
    const ImageCreateInfo * pCreateInfo{};
    const ImageSubresource2KHR * pSubresource{};
};
struct PhysicalDeviceShaderCorePropertiesARM {
    StructureType sType = StructureType::PhysicalDeviceShaderCorePropertiesARM;
    void * pNext{};
    uint32_t pixelRate{};
    uint32_t texelRate{};
    uint32_t fmaRate{};
};
struct PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;
    void * pNext{};
    Bool32 multiviewPerViewRenderAreas{};
};
struct MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM {
    StructureType sType = StructureType::MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;
    const void * pNext{};
    uint32_t perViewRenderAreaCount{};
    const Rect2D * pPerViewRenderAreas{};
};
struct QueryLowLatencySupportNV {
    StructureType sType = StructureType::QueryLowLatencySupportNV;
    const void * pNext{};
    void * pQueriedLowLatencyData{};
};
struct MemoryMapInfoKHR {
    StructureType sType = StructureType::MemoryMapInfoKHR;
    const void * pNext{};
    MemoryMapFlags flags{};
    DeviceMemory memory{};
    DeviceSize offset{};
    DeviceSize size{};
};
struct MemoryUnmapInfoKHR {
    StructureType sType = StructureType::MemoryUnmapInfoKHR;
    const void * pNext{};
    MemoryUnmapFlagsKHR flags{};
    DeviceMemory memory{};
};
struct PhysicalDeviceShaderObjectFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderObjectFeaturesEXT;
    void * pNext{};
    Bool32 shaderObject{};
};
struct PhysicalDeviceShaderObjectPropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderObjectPropertiesEXT;
    void * pNext{};
    uint8_t shaderBinaryUUID [ VK_UUID_SIZE ]{};
    uint32_t shaderBinaryVersion{};
};
struct ShaderCreateInfoEXT {
    StructureType sType = StructureType::ShaderCreateInfoEXT;
    const void * pNext{};
    ShaderCreateFlagsEXT flags{};
    ShaderStageFlagBits stage{};
    ShaderStageFlags nextStage{};
    ShaderCodeTypeEXT codeType{};
    size_t codeSize{};
    const void * pCode{};
    const char * pName{};
    uint32_t setLayoutCount{};
    const DescriptorSetLayout * pSetLayouts{};
    uint32_t pushConstantRangeCount{};
    const PushConstantRange * pPushConstantRanges{};
    const SpecializationInfo * pSpecializationInfo{};
};
struct PhysicalDeviceShaderTileImageFeaturesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderTileImageFeaturesEXT;
    void * pNext{};
    Bool32 shaderTileImageColorReadAccess{};
    Bool32 shaderTileImageDepthReadAccess{};
    Bool32 shaderTileImageStencilReadAccess{};
};
struct PhysicalDeviceShaderTileImagePropertiesEXT {
    StructureType sType = StructureType::PhysicalDeviceShaderTileImagePropertiesEXT;
    void * pNext{};
    Bool32 shaderTileImageCoherentReadAccelerated{};
    Bool32 shaderTileImageReadSampleFromPixelRateInvocation{};
    Bool32 shaderTileImageReadFromHelperInvocation{};
};
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
struct ImportScreenBufferInfoQNX {
    StructureType sType = StructureType::ImportScreenBufferInfoQNX;
    const void * pNext{};
    struct _screen_buffer * buffer{};
};
struct ScreenBufferPropertiesQNX {
    StructureType sType = StructureType::ScreenBufferPropertiesQNX;
    void * pNext{};
    DeviceSize allocationSize{};
    uint32_t memoryTypeBits{};
};
struct ScreenBufferFormatPropertiesQNX {
    StructureType sType = StructureType::ScreenBufferFormatPropertiesQNX;
    void * pNext{};
    Format format{};
    uint64_t externalFormat{};
    uint64_t screenUsage{};
    FormatFeatureFlags formatFeatures{};
    ComponentMapping samplerYcbcrConversionComponents{};
    SamplerYcbcrModelConversion suggestedYcbcrModel{};
    SamplerYcbcrRange suggestedYcbcrRange{};
    ChromaLocation suggestedXChromaOffset{};
    ChromaLocation suggestedYChromaOffset{};
};
struct ExternalFormatQNX {
    StructureType sType = StructureType::ExternalFormatQNX;
    void * pNext{};
    uint64_t externalFormat{};
};
struct PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX {
    StructureType sType = StructureType::PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX;
    void * pNext{};
    Bool32 screenBufferImport{};
};
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
struct PhysicalDeviceCooperativeMatrixFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceCooperativeMatrixFeaturesKHR;
    void * pNext{};
    Bool32 cooperativeMatrix{};
    Bool32 cooperativeMatrixRobustBufferAccess{};
};
struct CooperativeMatrixPropertiesKHR {
    StructureType sType = StructureType::CooperativeMatrixPropertiesKHR;
    void * pNext{};
    uint32_t MSize{};
    uint32_t NSize{};
    uint32_t KSize{};
    ComponentTypeKHR AType{};
    ComponentTypeKHR BType{};
    ComponentTypeKHR CType{};
    ComponentTypeKHR ResultType{};
    Bool32 saturatingAccumulation{};
    ScopeKHR scope{};
};
struct PhysicalDeviceCooperativeMatrixPropertiesKHR {
    StructureType sType = StructureType::PhysicalDeviceCooperativeMatrixPropertiesKHR;
    void * pNext{};
    ShaderStageFlags cooperativeMatrixSupportedStages{};
};
#if defined(VK_ENABLE_BETA_EXTENSIONS)
struct PhysicalDeviceShaderEnqueuePropertiesAMDX {
    StructureType sType = StructureType::PhysicalDeviceShaderEnqueuePropertiesAMDX;
    void * pNext{};
    uint32_t maxExecutionGraphDepth{};
    uint32_t maxExecutionGraphShaderOutputNodes{};
    uint32_t maxExecutionGraphShaderPayloadSize{};
    uint32_t maxExecutionGraphShaderPayloadCount{};
    uint32_t executionGraphDispatchAddressAlignment{};
};
struct PhysicalDeviceShaderEnqueueFeaturesAMDX {
    StructureType sType = StructureType::PhysicalDeviceShaderEnqueueFeaturesAMDX;
    void * pNext{};
    Bool32 shaderEnqueue{};
};
struct ExecutionGraphPipelineCreateInfoAMDX {
    StructureType sType = StructureType::ExecutionGraphPipelineCreateInfoAMDX;
    const void * pNext{};
    PipelineCreateFlags flags{};
    uint32_t stageCount{};
    const PipelineShaderStageCreateInfo * pStages{};
    const PipelineLibraryCreateInfoKHR * pLibraryInfo{};
    PipelineLayout layout{};
    Pipeline basePipelineHandle{};
    int32_t basePipelineIndex{};
};
struct PipelineShaderStageNodeCreateInfoAMDX {
    StructureType sType = StructureType::PipelineShaderStageNodeCreateInfoAMDX;
    const void * pNext{};
    const char * pName{};
    uint32_t index{};
};
struct ExecutionGraphPipelineScratchSizeAMDX {
    StructureType sType = StructureType::ExecutionGraphPipelineScratchSizeAMDX;
    void * pNext{};
    DeviceSize size{};
};
struct DispatchGraphInfoAMDX {
    uint32_t nodeIndex{};
    uint32_t payloadCount{};
    DeviceOrHostAddressConstAMDX payloads{};
    uint64_t payloadStride{};
};
struct DispatchGraphCountInfoAMDX {
    uint32_t count{};
    DeviceOrHostAddressConstAMDX infos{};
    uint64_t stride{};
};
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
struct BindMemoryStatusKHR {
    StructureType sType = StructureType::BindMemoryStatusKHR;
    const void * pNext{};
    Result * pResult{};
};
struct BindDescriptorSetsInfoKHR {
    StructureType sType = StructureType::BindDescriptorSetsInfoKHR;
    const void * pNext{};
    ShaderStageFlags stageFlags{};
    PipelineLayout layout{};
    uint32_t firstSet{};
    uint32_t descriptorSetCount{};
    const DescriptorSet * pDescriptorSets{};
    uint32_t dynamicOffsetCount{};
    const uint32_t * pDynamicOffsets{};
};
struct PushConstantsInfoKHR {
    StructureType sType = StructureType::PushConstantsInfoKHR;
    const void * pNext{};
    PipelineLayout layout{};
    ShaderStageFlags stageFlags{};
    uint32_t offset{};
    uint32_t size{};
    const void * pValues{};
};
struct PushDescriptorSetInfoKHR {
    StructureType sType = StructureType::PushDescriptorSetInfoKHR;
    const void * pNext{};
    ShaderStageFlags stageFlags{};
    PipelineLayout layout{};
    uint32_t set{};
    uint32_t descriptorWriteCount{};
    const WriteDescriptorSet * pDescriptorWrites{};
};
struct PushDescriptorSetWithTemplateInfoKHR {
    StructureType sType = StructureType::PushDescriptorSetWithTemplateInfoKHR;
    const void * pNext{};
    DescriptorUpdateTemplate descriptorUpdateTemplate{};
    PipelineLayout layout{};
    uint32_t set{};
    const void * pData{};
};
struct SetDescriptorBufferOffsetsInfoEXT {
    StructureType sType = StructureType::SetDescriptorBufferOffsetsInfoEXT;
    const void * pNext{};
    ShaderStageFlags stageFlags{};
    PipelineLayout layout{};
    uint32_t firstSet{};
    uint32_t setCount{};
    const uint32_t * pBufferIndices{};
    const DeviceSize * pOffsets{};
};
struct BindDescriptorBufferEmbeddedSamplersInfoEXT {
    StructureType sType = StructureType::BindDescriptorBufferEmbeddedSamplersInfoEXT;
    const void * pNext{};
    ShaderStageFlags stageFlags{};
    PipelineLayout layout{};
    uint32_t set{};
};
struct PhysicalDeviceCubicClampFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceCubicClampFeaturesQCOM;
    void * pNext{};
    Bool32 cubicRangeClamp{};
};
struct PhysicalDeviceYcbcrDegammaFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceYcbcrDegammaFeaturesQCOM;
    void * pNext{};
    Bool32 ycbcrDegamma{};
};
struct SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM {
    StructureType sType = StructureType::SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;
    void * pNext{};
    Bool32 enableYDegamma{};
    Bool32 enableCbCrDegamma{};
};
struct PhysicalDeviceCubicWeightsFeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceCubicWeightsFeaturesQCOM;
    void * pNext{};
    Bool32 selectableCubicWeights{};
};
struct SamplerCubicWeightsCreateInfoQCOM {
    StructureType sType = StructureType::SamplerCubicWeightsCreateInfoQCOM;
    const void * pNext{};
    CubicFilterWeightsQCOM cubicWeights{};
};
struct BlitImageCubicWeightsInfoQCOM {
    StructureType sType = StructureType::BlitImageCubicWeightsInfoQCOM;
    const void * pNext{};
    CubicFilterWeightsQCOM cubicWeights{};
};
struct PhysicalDeviceImageProcessing2FeaturesQCOM {
    StructureType sType = StructureType::PhysicalDeviceImageProcessing2FeaturesQCOM;
    void * pNext{};
    Bool32 textureBlockMatch2{};
};
struct PhysicalDeviceImageProcessing2PropertiesQCOM {
    StructureType sType = StructureType::PhysicalDeviceImageProcessing2PropertiesQCOM;
    void * pNext{};
    Extent2D maxBlockMatchWindow{};
};
struct SamplerBlockMatchWindowCreateInfoQCOM {
    StructureType sType = StructureType::SamplerBlockMatchWindowCreateInfoQCOM;
    const void * pNext{};
    Extent2D windowExtent{};
    BlockMatchWindowCompareModeQCOM windowCompareMode{};
};
struct PhysicalDeviceDescriptorPoolOverallocationFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceDescriptorPoolOverallocationFeaturesNV;
    void * pNext{};
    Bool32 descriptorPoolOverallocation{};
};
struct PhysicalDeviceLayeredDriverPropertiesMSFT {
    StructureType sType = StructureType::PhysicalDeviceLayeredDriverPropertiesMSFT;
    void * pNext{};
    LayeredDriverUnderlyingApiMSFT underlyingAPI{};
};
struct PhysicalDevicePerStageDescriptorSetFeaturesNV {
    StructureType sType = StructureType::PhysicalDevicePerStageDescriptorSetFeaturesNV;
    void * pNext{};
    Bool32 perStageDescriptorSet{};
    Bool32 dynamicPipelineLayout{};
};
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
struct PhysicalDeviceExternalFormatResolveFeaturesANDROID {
    StructureType sType = StructureType::PhysicalDeviceExternalFormatResolveFeaturesANDROID;
    void * pNext{};
    Bool32 externalFormatResolve{};
};
struct PhysicalDeviceExternalFormatResolvePropertiesANDROID {
    StructureType sType = StructureType::PhysicalDeviceExternalFormatResolvePropertiesANDROID;
    void * pNext{};
    Bool32 nullColorAttachmentWithExternalFormatResolve{};
    ChromaLocation externalFormatResolveChromaOffsetX{};
    ChromaLocation externalFormatResolveChromaOffsetY{};
};
struct AndroidHardwareBufferFormatResolvePropertiesANDROID {
    StructureType sType = StructureType::AndroidHardwareBufferFormatResolvePropertiesANDROID;
    void * pNext{};
    Format colorAttachmentFormat{};
};
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
struct LatencySleepModeInfoNV {
    StructureType sType = StructureType::LatencySleepModeInfoNV;
    const void * pNext{};
    Bool32 lowLatencyMode{};
    Bool32 lowLatencyBoost{};
    uint32_t minimumIntervalUs{};
};
struct LatencySleepInfoNV {
    StructureType sType = StructureType::LatencySleepInfoNV;
    const void * pNext{};
    Semaphore signalSemaphore{};
    uint64_t value{};
};
struct SetLatencyMarkerInfoNV {
    StructureType sType = StructureType::SetLatencyMarkerInfoNV;
    const void * pNext{};
    uint64_t presentID{};
    LatencyMarkerNV marker{};
};
struct LatencyTimingsFrameReportNV {
    StructureType sType = StructureType::LatencyTimingsFrameReportNV;
    const void * pNext{};
    uint64_t presentID{};
    uint64_t inputSampleTimeUs{};
    uint64_t simStartTimeUs{};
    uint64_t simEndTimeUs{};
    uint64_t renderSubmitStartTimeUs{};
    uint64_t renderSubmitEndTimeUs{};
    uint64_t presentStartTimeUs{};
    uint64_t presentEndTimeUs{};
    uint64_t driverStartTimeUs{};
    uint64_t driverEndTimeUs{};
    uint64_t osRenderQueueStartTimeUs{};
    uint64_t osRenderQueueEndTimeUs{};
    uint64_t gpuRenderStartTimeUs{};
    uint64_t gpuRenderEndTimeUs{};
};
struct GetLatencyMarkerInfoNV {
    StructureType sType = StructureType::GetLatencyMarkerInfoNV;
    const void * pNext{};
    uint32_t timingCount{};
    LatencyTimingsFrameReportNV * pTimings{};
};
struct OutOfBandQueueTypeInfoNV {
    StructureType sType = StructureType::OutOfBandQueueTypeInfoNV;
    const void * pNext{};
    OutOfBandQueueTypeNV queueType{};
};
struct LatencySubmissionPresentIdNV {
    StructureType sType = StructureType::LatencySubmissionPresentIdNV;
    const void * pNext{};
    uint64_t presentID{};
};
struct SwapchainLatencyCreateInfoNV {
    StructureType sType = StructureType::SwapchainLatencyCreateInfoNV;
    const void * pNext{};
    Bool32 latencyModeEnable{};
};
struct LatencySurfaceCapabilitiesNV {
    StructureType sType = StructureType::LatencySurfaceCapabilitiesNV;
    const void * pNext{};
    uint32_t presentModeCount{};
    PresentModeKHR * pPresentModes{};
};
struct PhysicalDeviceCudaKernelLaunchFeaturesNV {
    StructureType sType = StructureType::PhysicalDeviceCudaKernelLaunchFeaturesNV;
    void * pNext{};
    Bool32 cudaKernelLaunchFeatures{};
};
struct PhysicalDeviceCudaKernelLaunchPropertiesNV {
    StructureType sType = StructureType::PhysicalDeviceCudaKernelLaunchPropertiesNV;
    void * pNext{};
    uint32_t computeCapabilityMinor{};
    uint32_t computeCapabilityMajor{};
};
struct DeviceQueueShaderCoreControlCreateInfoARM {
    StructureType sType = StructureType::DeviceQueueShaderCoreControlCreateInfoARM;
    void * pNext{};
    uint32_t shaderCoreCount{};
};
struct PhysicalDeviceSchedulingControlsFeaturesARM {
    StructureType sType = StructureType::PhysicalDeviceSchedulingControlsFeaturesARM;
    void * pNext{};
    Bool32 schedulingControls{};
};
struct PhysicalDeviceSchedulingControlsPropertiesARM {
    StructureType sType = StructureType::PhysicalDeviceSchedulingControlsPropertiesARM;
    void * pNext{};
    PhysicalDeviceSchedulingControlsFlagsARM schedulingControlsFlags{};
};
struct PhysicalDeviceRelaxedLineRasterizationFeaturesIMG {
    StructureType sType = StructureType::PhysicalDeviceRelaxedLineRasterizationFeaturesIMG;
    void * pNext{};
    Bool32 relaxedLineRasterization{};
};
struct PhysicalDeviceRenderPassStripedFeaturesARM {
    StructureType sType = StructureType::PhysicalDeviceRenderPassStripedFeaturesARM;
    void * pNext{};
    Bool32 renderPassStriped{};
};
struct PhysicalDeviceRenderPassStripedPropertiesARM {
    StructureType sType = StructureType::PhysicalDeviceRenderPassStripedPropertiesARM;
    void * pNext{};
    Extent2D renderPassStripeGranularity{};
    uint32_t maxRenderPassStripes{};
};
struct RenderPassStripeInfoARM {
    StructureType sType = StructureType::RenderPassStripeInfoARM;
    const void * pNext{};
    Rect2D stripeArea{};
};
struct RenderPassStripeBeginInfoARM {
    StructureType sType = StructureType::RenderPassStripeBeginInfoARM;
    const void * pNext{};
    uint32_t stripeInfoCount{};
    const RenderPassStripeInfoARM * pStripeInfos{};
};
struct RenderPassStripeSubmitInfoARM {
    StructureType sType = StructureType::RenderPassStripeSubmitInfoARM;
    const void * pNext{};
    uint32_t stripeSemaphoreInfoCount{};
    const SemaphoreSubmitInfo * pStripeSemaphoreInfos{};
};
struct PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;
    void * pNext{};
    Bool32 shaderMaximalReconvergence{};
};
struct PhysicalDeviceShaderSubgroupRotateFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderSubgroupRotateFeaturesKHR;
    void * pNext{};
    Bool32 shaderSubgroupRotate{};
    Bool32 shaderSubgroupRotateClustered{};
};
struct PhysicalDeviceShaderExpectAssumeFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderExpectAssumeFeaturesKHR;
    void * pNext{};
    Bool32 shaderExpectAssume{};
};
struct PhysicalDeviceShaderFloatControls2FeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderFloatControls2FeaturesKHR;
    void * pNext{};
    Bool32 shaderFloatControls2{};
};
struct PhysicalDeviceDynamicRenderingLocalReadFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceDynamicRenderingLocalReadFeaturesKHR;
    void * pNext{};
    Bool32 dynamicRenderingLocalRead{};
};
struct RenderingAttachmentLocationInfoKHR {
    StructureType sType = StructureType::RenderingAttachmentLocationInfoKHR;
    const void * pNext{};
    uint32_t colorAttachmentCount{};
    const uint32_t * pColorAttachmentLocations{};
};
struct RenderingInputAttachmentIndexInfoKHR {
    StructureType sType = StructureType::RenderingInputAttachmentIndexInfoKHR;
    const void * pNext{};
    uint32_t colorAttachmentCount{};
    const uint32_t * pColorAttachmentInputIndices{};
    const uint32_t * pDepthInputAttachmentIndex{};
    const uint32_t * pStencilInputAttachmentIndex{};
};
struct PhysicalDeviceShaderQuadControlFeaturesKHR {
    StructureType sType = StructureType::PhysicalDeviceShaderQuadControlFeaturesKHR;
    void * pNext{};
    Bool32 shaderQuadControl{};
};
using DevicePrivateDataCreateInfoEXT = DevicePrivateDataCreateInfo;
using PrivateDataSlotCreateInfoEXT = PrivateDataSlotCreateInfo;
using PhysicalDevicePrivateDataFeaturesEXT = PhysicalDevicePrivateDataFeatures;
using PhysicalDeviceFeatures2KHR = PhysicalDeviceFeatures2;
using PhysicalDeviceProperties2KHR = PhysicalDeviceProperties2;
using FormatProperties2KHR = FormatProperties2;
using ImageFormatProperties2KHR = ImageFormatProperties2;
using PhysicalDeviceImageFormatInfo2KHR = PhysicalDeviceImageFormatInfo2;
using QueueFamilyProperties2KHR = QueueFamilyProperties2;
using PhysicalDeviceMemoryProperties2KHR = PhysicalDeviceMemoryProperties2;
using SparseImageFormatProperties2KHR = SparseImageFormatProperties2;
using PhysicalDeviceSparseImageFormatInfo2KHR = PhysicalDeviceSparseImageFormatInfo2;
using ConformanceVersionKHR = ConformanceVersion;
using PhysicalDeviceDriverPropertiesKHR = PhysicalDeviceDriverProperties;
using PhysicalDeviceVariablePointersFeaturesKHR = PhysicalDeviceVariablePointersFeatures;
using PhysicalDeviceVariablePointerFeaturesKHR = PhysicalDeviceVariablePointersFeatures;
using PhysicalDeviceVariablePointerFeatures = PhysicalDeviceVariablePointersFeatures;
using ExternalMemoryPropertiesKHR = ExternalMemoryProperties;
using PhysicalDeviceExternalImageFormatInfoKHR = PhysicalDeviceExternalImageFormatInfo;
using ExternalImageFormatPropertiesKHR = ExternalImageFormatProperties;
using PhysicalDeviceExternalBufferInfoKHR = PhysicalDeviceExternalBufferInfo;
using ExternalBufferPropertiesKHR = ExternalBufferProperties;
using PhysicalDeviceIDPropertiesKHR = PhysicalDeviceIDProperties;
using ExternalMemoryImageCreateInfoKHR = ExternalMemoryImageCreateInfo;
using ExternalMemoryBufferCreateInfoKHR = ExternalMemoryBufferCreateInfo;
using ExportMemoryAllocateInfoKHR = ExportMemoryAllocateInfo;
using PhysicalDeviceExternalSemaphoreInfoKHR = PhysicalDeviceExternalSemaphoreInfo;
using ExternalSemaphorePropertiesKHR = ExternalSemaphoreProperties;
using ExportSemaphoreCreateInfoKHR = ExportSemaphoreCreateInfo;
using PhysicalDeviceExternalFenceInfoKHR = PhysicalDeviceExternalFenceInfo;
using ExternalFencePropertiesKHR = ExternalFenceProperties;
using ExportFenceCreateInfoKHR = ExportFenceCreateInfo;
using PhysicalDeviceMultiviewFeaturesKHR = PhysicalDeviceMultiviewFeatures;
using PhysicalDeviceMultiviewPropertiesKHR = PhysicalDeviceMultiviewProperties;
using RenderPassMultiviewCreateInfoKHR = RenderPassMultiviewCreateInfo;
using PhysicalDeviceGroupPropertiesKHR = PhysicalDeviceGroupProperties;
using MemoryAllocateFlagsInfoKHR = MemoryAllocateFlagsInfo;
using BindBufferMemoryInfoKHR = BindBufferMemoryInfo;
using BindBufferMemoryDeviceGroupInfoKHR = BindBufferMemoryDeviceGroupInfo;
using BindImageMemoryInfoKHR = BindImageMemoryInfo;
using BindImageMemoryDeviceGroupInfoKHR = BindImageMemoryDeviceGroupInfo;
using DeviceGroupRenderPassBeginInfoKHR = DeviceGroupRenderPassBeginInfo;
using DeviceGroupCommandBufferBeginInfoKHR = DeviceGroupCommandBufferBeginInfo;
using DeviceGroupSubmitInfoKHR = DeviceGroupSubmitInfo;
using DeviceGroupBindSparseInfoKHR = DeviceGroupBindSparseInfo;
using DeviceGroupDeviceCreateInfoKHR = DeviceGroupDeviceCreateInfo;
using DescriptorUpdateTemplateEntryKHR = DescriptorUpdateTemplateEntry;
using DescriptorUpdateTemplateCreateInfoKHR = DescriptorUpdateTemplateCreateInfo;
using InputAttachmentAspectReferenceKHR = InputAttachmentAspectReference;
using RenderPassInputAttachmentAspectCreateInfoKHR = RenderPassInputAttachmentAspectCreateInfo;
using PhysicalDevice16BitStorageFeaturesKHR = PhysicalDevice16BitStorageFeatures;
using PhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR = PhysicalDeviceShaderSubgroupExtendedTypesFeatures;
using BufferMemoryRequirementsInfo2KHR = BufferMemoryRequirementsInfo2;
using DeviceBufferMemoryRequirementsKHR = DeviceBufferMemoryRequirements;
using ImageMemoryRequirementsInfo2KHR = ImageMemoryRequirementsInfo2;
using ImageSparseMemoryRequirementsInfo2KHR = ImageSparseMemoryRequirementsInfo2;
using DeviceImageMemoryRequirementsKHR = DeviceImageMemoryRequirements;
using MemoryRequirements2KHR = MemoryRequirements2;
using SparseImageMemoryRequirements2KHR = SparseImageMemoryRequirements2;
using PhysicalDevicePointClippingPropertiesKHR = PhysicalDevicePointClippingProperties;
using MemoryDedicatedRequirementsKHR = MemoryDedicatedRequirements;
using MemoryDedicatedAllocateInfoKHR = MemoryDedicatedAllocateInfo;
using ImageViewUsageCreateInfoKHR = ImageViewUsageCreateInfo;
using PipelineTessellationDomainOriginStateCreateInfoKHR = PipelineTessellationDomainOriginStateCreateInfo;
using SamplerYcbcrConversionInfoKHR = SamplerYcbcrConversionInfo;
using SamplerYcbcrConversionCreateInfoKHR = SamplerYcbcrConversionCreateInfo;
using BindImagePlaneMemoryInfoKHR = BindImagePlaneMemoryInfo;
using ImagePlaneMemoryRequirementsInfoKHR = ImagePlaneMemoryRequirementsInfo;
using PhysicalDeviceSamplerYcbcrConversionFeaturesKHR = PhysicalDeviceSamplerYcbcrConversionFeatures;
using SamplerYcbcrConversionImageFormatPropertiesKHR = SamplerYcbcrConversionImageFormatProperties;
using PhysicalDeviceSamplerFilterMinmaxPropertiesEXT = PhysicalDeviceSamplerFilterMinmaxProperties;
using SamplerReductionModeCreateInfoEXT = SamplerReductionModeCreateInfo;
using PhysicalDeviceInlineUniformBlockFeaturesEXT = PhysicalDeviceInlineUniformBlockFeatures;
using PhysicalDeviceInlineUniformBlockPropertiesEXT = PhysicalDeviceInlineUniformBlockProperties;
using WriteDescriptorSetInlineUniformBlockEXT = WriteDescriptorSetInlineUniformBlock;
using DescriptorPoolInlineUniformBlockCreateInfoEXT = DescriptorPoolInlineUniformBlockCreateInfo;
using ImageFormatListCreateInfoKHR = ImageFormatListCreateInfo;
using PhysicalDeviceMaintenance3PropertiesKHR = PhysicalDeviceMaintenance3Properties;
using PhysicalDeviceMaintenance4FeaturesKHR = PhysicalDeviceMaintenance4Features;
using PhysicalDeviceMaintenance4PropertiesKHR = PhysicalDeviceMaintenance4Properties;
using DescriptorSetLayoutSupportKHR = DescriptorSetLayoutSupport;
using PhysicalDeviceShaderDrawParameterFeatures = PhysicalDeviceShaderDrawParametersFeatures;
using PhysicalDeviceShaderFloat16Int8FeaturesKHR = PhysicalDeviceShaderFloat16Int8Features;
using PhysicalDeviceFloat16Int8FeaturesKHR = PhysicalDeviceShaderFloat16Int8Features;
using PhysicalDeviceFloatControlsPropertiesKHR = PhysicalDeviceFloatControlsProperties;
using PhysicalDeviceHostQueryResetFeaturesEXT = PhysicalDeviceHostQueryResetFeatures;
using DeviceQueueGlobalPriorityCreateInfoEXT = DeviceQueueGlobalPriorityCreateInfoKHR;
using PhysicalDeviceGlobalPriorityQueryFeaturesEXT = PhysicalDeviceGlobalPriorityQueryFeaturesKHR;
using QueueFamilyGlobalPriorityPropertiesEXT = QueueFamilyGlobalPriorityPropertiesKHR;
using CalibratedTimestampInfoEXT = CalibratedTimestampInfoKHR;
using PhysicalDeviceDescriptorIndexingFeaturesEXT = PhysicalDeviceDescriptorIndexingFeatures;
using PhysicalDeviceDescriptorIndexingPropertiesEXT = PhysicalDeviceDescriptorIndexingProperties;
using DescriptorSetLayoutBindingFlagsCreateInfoEXT = DescriptorSetLayoutBindingFlagsCreateInfo;
using DescriptorSetVariableDescriptorCountAllocateInfoEXT = DescriptorSetVariableDescriptorCountAllocateInfo;
using DescriptorSetVariableDescriptorCountLayoutSupportEXT = DescriptorSetVariableDescriptorCountLayoutSupport;
using AttachmentDescription2KHR = AttachmentDescription2;
using AttachmentReference2KHR = AttachmentReference2;
using SubpassDescription2KHR = SubpassDescription2;
using SubpassDependency2KHR = SubpassDependency2;
using RenderPassCreateInfo2KHR = RenderPassCreateInfo2;
using SubpassBeginInfoKHR = SubpassBeginInfo;
using SubpassEndInfoKHR = SubpassEndInfo;
using PhysicalDeviceTimelineSemaphoreFeaturesKHR = PhysicalDeviceTimelineSemaphoreFeatures;
using PhysicalDeviceTimelineSemaphorePropertiesKHR = PhysicalDeviceTimelineSemaphoreProperties;
using SemaphoreTypeCreateInfoKHR = SemaphoreTypeCreateInfo;
using TimelineSemaphoreSubmitInfoKHR = TimelineSemaphoreSubmitInfo;
using SemaphoreWaitInfoKHR = SemaphoreWaitInfo;
using SemaphoreSignalInfoKHR = SemaphoreSignalInfo;
using VertexInputBindingDivisorDescriptionEXT = VertexInputBindingDivisorDescriptionKHR;
using PipelineVertexInputDivisorStateCreateInfoEXT = PipelineVertexInputDivisorStateCreateInfoKHR;
using PhysicalDevice8BitStorageFeaturesKHR = PhysicalDevice8BitStorageFeatures;
using PhysicalDeviceVulkanMemoryModelFeaturesKHR = PhysicalDeviceVulkanMemoryModelFeatures;
using PhysicalDeviceShaderAtomicInt64FeaturesKHR = PhysicalDeviceShaderAtomicInt64Features;
using PhysicalDeviceVertexAttributeDivisorFeaturesEXT = PhysicalDeviceVertexAttributeDivisorFeaturesKHR;
using PhysicalDeviceDepthStencilResolvePropertiesKHR = PhysicalDeviceDepthStencilResolveProperties;
using SubpassDescriptionDepthStencilResolveKHR = SubpassDescriptionDepthStencilResolve;
using PhysicalDeviceFragmentShaderBarycentricFeaturesNV = PhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
using ImageStencilUsageCreateInfoEXT = ImageStencilUsageCreateInfo;
using PhysicalDeviceScalarBlockLayoutFeaturesEXT = PhysicalDeviceScalarBlockLayoutFeatures;
using PhysicalDeviceUniformBufferStandardLayoutFeaturesKHR = PhysicalDeviceUniformBufferStandardLayoutFeatures;
using PhysicalDeviceBufferDeviceAddressFeaturesKHR = PhysicalDeviceBufferDeviceAddressFeatures;
using PhysicalDeviceBufferAddressFeaturesEXT = PhysicalDeviceBufferDeviceAddressFeaturesEXT;
using BufferDeviceAddressInfoKHR = BufferDeviceAddressInfo;
using BufferDeviceAddressInfoEXT = BufferDeviceAddressInfo;
using BufferOpaqueCaptureAddressCreateInfoKHR = BufferOpaqueCaptureAddressCreateInfo;
using PhysicalDeviceImagelessFramebufferFeaturesKHR = PhysicalDeviceImagelessFramebufferFeatures;
using FramebufferAttachmentsCreateInfoKHR = FramebufferAttachmentsCreateInfo;
using FramebufferAttachmentImageInfoKHR = FramebufferAttachmentImageInfo;
using RenderPassAttachmentBeginInfoKHR = RenderPassAttachmentBeginInfo;
using PhysicalDeviceTextureCompressionASTCHDRFeaturesEXT = PhysicalDeviceTextureCompressionASTCHDRFeatures;
using PipelineCreationFeedbackEXT = PipelineCreationFeedback;
using PipelineCreationFeedbackCreateInfoEXT = PipelineCreationFeedbackCreateInfo;
using QueryPoolCreateInfoINTEL = QueryPoolPerformanceQueryCreateInfoINTEL;
using PhysicalDeviceIndexTypeUint8FeaturesEXT = PhysicalDeviceIndexTypeUint8FeaturesKHR;
using PhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR = PhysicalDeviceSeparateDepthStencilLayoutsFeatures;
using AttachmentReferenceStencilLayoutKHR = AttachmentReferenceStencilLayout;
using AttachmentDescriptionStencilLayoutKHR = AttachmentDescriptionStencilLayout;
using PipelineInfoEXT = PipelineInfoKHR;
using PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = PhysicalDeviceShaderDemoteToHelperInvocationFeatures;
using PhysicalDeviceTexelBufferAlignmentPropertiesEXT = PhysicalDeviceTexelBufferAlignmentProperties;
using PhysicalDeviceSubgroupSizeControlFeaturesEXT = PhysicalDeviceSubgroupSizeControlFeatures;
using PhysicalDeviceSubgroupSizeControlPropertiesEXT = PhysicalDeviceSubgroupSizeControlProperties;
using PipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = PipelineShaderStageRequiredSubgroupSizeCreateInfo;
using ShaderRequiredSubgroupSizeCreateInfoEXT = PipelineShaderStageRequiredSubgroupSizeCreateInfo;
using MemoryOpaqueCaptureAddressAllocateInfoKHR = MemoryOpaqueCaptureAddressAllocateInfo;
using DeviceMemoryOpaqueCaptureAddressInfoKHR = DeviceMemoryOpaqueCaptureAddressInfo;
using PhysicalDeviceLineRasterizationFeaturesEXT = PhysicalDeviceLineRasterizationFeaturesKHR;
using PhysicalDeviceLineRasterizationPropertiesEXT = PhysicalDeviceLineRasterizationPropertiesKHR;
using PipelineRasterizationLineStateCreateInfoEXT = PipelineRasterizationLineStateCreateInfoKHR;
using PhysicalDevicePipelineCreationCacheControlFeaturesEXT = PhysicalDevicePipelineCreationCacheControlFeatures;
using PhysicalDeviceToolPropertiesEXT = PhysicalDeviceToolProperties;
using AabbPositionsNV = AabbPositionsKHR;
using TransformMatrixNV = TransformMatrixKHR;
using AccelerationStructureInstanceNV = AccelerationStructureInstanceKHR;
using PhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR = PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;
using PhysicalDeviceImageRobustnessFeaturesEXT = PhysicalDeviceImageRobustnessFeatures;
using BufferCopy2KHR = BufferCopy2;
using ImageCopy2KHR = ImageCopy2;
using ImageBlit2KHR = ImageBlit2;
using BufferImageCopy2KHR = BufferImageCopy2;
using ImageResolve2KHR = ImageResolve2;
using CopyBufferInfo2KHR = CopyBufferInfo2;
using CopyImageInfo2KHR = CopyImageInfo2;
using BlitImageInfo2KHR = BlitImageInfo2;
using CopyBufferToImageInfo2KHR = CopyBufferToImageInfo2;
using CopyImageToBufferInfo2KHR = CopyImageToBufferInfo2;
using ResolveImageInfo2KHR = ResolveImageInfo2;
using PhysicalDeviceShaderTerminateInvocationFeaturesKHR = PhysicalDeviceShaderTerminateInvocationFeatures;
using PhysicalDeviceMutableDescriptorTypeFeaturesVALVE = PhysicalDeviceMutableDescriptorTypeFeaturesEXT;
using MutableDescriptorTypeListVALVE = MutableDescriptorTypeListEXT;
using MutableDescriptorTypeCreateInfoVALVE = MutableDescriptorTypeCreateInfoEXT;
using MemoryBarrier2KHR = MemoryBarrier2;
using ImageMemoryBarrier2KHR = ImageMemoryBarrier2;
using BufferMemoryBarrier2KHR = BufferMemoryBarrier2;
using DependencyInfoKHR = DependencyInfo;
using SemaphoreSubmitInfoKHR = SemaphoreSubmitInfo;
using CommandBufferSubmitInfoKHR = CommandBufferSubmitInfo;
using SubmitInfo2KHR = SubmitInfo2;
using PhysicalDeviceSynchronization2FeaturesKHR = PhysicalDeviceSynchronization2Features;
using PhysicalDeviceShaderIntegerDotProductFeaturesKHR = PhysicalDeviceShaderIntegerDotProductFeatures;
using PhysicalDeviceShaderIntegerDotProductPropertiesKHR = PhysicalDeviceShaderIntegerDotProductProperties;
using FormatProperties3KHR = FormatProperties3;
using PipelineRenderingCreateInfoKHR = PipelineRenderingCreateInfo;
using RenderingInfoKHR = RenderingInfo;
using RenderingAttachmentInfoKHR = RenderingAttachmentInfo;
using PhysicalDeviceDynamicRenderingFeaturesKHR = PhysicalDeviceDynamicRenderingFeatures;
using CommandBufferInheritanceRenderingInfoKHR = CommandBufferInheritanceRenderingInfo;
using AttachmentSampleCountInfoNV = AttachmentSampleCountInfoAMD;
using PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM = PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
using ImageSubresource2EXT = ImageSubresource2KHR;
using SubresourceLayout2EXT = SubresourceLayout2KHR;
using PFN_CreateInstance = Result (*) (const InstanceCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Instance * pInstance);
using PFN_DestroyInstance = void (*) (Instance instance, const AllocationCallbacks * pAllocator);
using PFN_EnumeratePhysicalDevices = Result (*) (Instance instance, uint32_t * pPhysicalDeviceCount, PhysicalDevice * pPhysicalDevices);
using PFN_GetDeviceProcAddr = PFN_vkVoidFunction (*) (Device device, const char * pName);
using PFN_GetInstanceProcAddr = PFN_vkVoidFunction (*) (Instance instance, const char * pName);
using PFN_GetPhysicalDeviceProperties = void (*) (PhysicalDevice physicalDevice, PhysicalDeviceProperties * pProperties);
using PFN_GetPhysicalDeviceQueueFamilyProperties = void (*) (PhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, QueueFamilyProperties * pQueueFamilyProperties);
using PFN_GetPhysicalDeviceMemoryProperties = void (*) (PhysicalDevice physicalDevice, PhysicalDeviceMemoryProperties * pMemoryProperties);
using PFN_GetPhysicalDeviceFeatures = void (*) (PhysicalDevice physicalDevice, PhysicalDeviceFeatures * pFeatures);
using PFN_GetPhysicalDeviceFormatProperties = void (*) (PhysicalDevice physicalDevice, Format format, FormatProperties * pFormatProperties);
using PFN_GetPhysicalDeviceImageFormatProperties = Result (*) (PhysicalDevice physicalDevice, Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags, ImageFormatProperties * pImageFormatProperties);
using PFN_CreateDevice = Result (*) (PhysicalDevice physicalDevice, const DeviceCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Device * pDevice);
using PFN_CreateDevice = Result (*) (PhysicalDevice physicalDevice, const DeviceCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Device * pDevice);
using PFN_DestroyDevice = void (*) (Device device, const AllocationCallbacks * pAllocator);
using PFN_EnumerateInstanceVersion = Result (*) (uint32_t * pApiVersion);
using PFN_EnumerateInstanceLayerProperties = Result (*) (uint32_t * pPropertyCount, LayerProperties * pProperties);
using PFN_EnumerateInstanceExtensionProperties = Result (*) (const char * pLayerName, uint32_t * pPropertyCount, ExtensionProperties * pProperties);
using PFN_EnumerateDeviceExtensionProperties = Result (*) (PhysicalDevice physicalDevice, const char * pLayerName, uint32_t * pPropertyCount, ExtensionProperties * pProperties);
using PFN_GetDeviceQueue = void (*) (Device device, uint32_t queueFamilyIndex, uint32_t queueIndex, Queue * pQueue);
using PFN_QueueSubmit = Result (*) (Queue queue, uint32_t submitCount, const SubmitInfo * pSubmits, Fence fence);
using PFN_QueueWaitIdle = Result (*) (Queue queue);
using PFN_DeviceWaitIdle = Result (*) (Device device);
using PFN_AllocateMemory = Result (*) (Device device, const MemoryAllocateInfo * pAllocateInfo, const AllocationCallbacks * pAllocator, DeviceMemory * pMemory);
using PFN_FreeMemory = void (*) (Device device, DeviceMemory memory, const AllocationCallbacks * pAllocator);
using PFN_MapMemory = Result (*) (Device device, DeviceMemory memory, DeviceSize offset, DeviceSize size, MemoryMapFlags flags, void ** ppData);
using PFN_UnmapMemory = void (*) (Device device, DeviceMemory memory);
using PFN_FlushMappedMemoryRanges = Result (*) (Device device, uint32_t memoryRangeCount, const MappedMemoryRange * pMemoryRanges);
using PFN_InvalidateMappedMemoryRanges = Result (*) (Device device, uint32_t memoryRangeCount, const MappedMemoryRange * pMemoryRanges);
using PFN_GetDeviceMemoryCommitment = void (*) (Device device, DeviceMemory memory, DeviceSize * pCommittedMemoryInBytes);
using PFN_GetBufferMemoryRequirements = void (*) (Device device, Buffer buffer, MemoryRequirements * pMemoryRequirements);
using PFN_BindBufferMemory = Result (*) (Device device, Buffer buffer, DeviceMemory memory, DeviceSize memoryOffset);
using PFN_GetImageMemoryRequirements = void (*) (Device device, Image image, MemoryRequirements * pMemoryRequirements);
using PFN_BindImageMemory = Result (*) (Device device, Image image, DeviceMemory memory, DeviceSize memoryOffset);
using PFN_GetImageSparseMemoryRequirements = void (*) (Device device, Image image, uint32_t * pSparseMemoryRequirementCount, SparseImageMemoryRequirements * pSparseMemoryRequirements);
using PFN_GetPhysicalDeviceSparseImageFormatProperties = void (*) (PhysicalDevice physicalDevice, Format format, ImageType type, SampleCountFlagBits samples, ImageUsageFlags usage, ImageTiling tiling, uint32_t * pPropertyCount, SparseImageFormatProperties * pProperties);
using PFN_QueueBindSparse = Result (*) (Queue queue, uint32_t bindInfoCount, const BindSparseInfo * pBindInfo, Fence fence);
using PFN_CreateFence = Result (*) (Device device, const FenceCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Fence * pFence);
using PFN_DestroyFence = void (*) (Device device, Fence fence, const AllocationCallbacks * pAllocator);
using PFN_ResetFences = Result (*) (Device device, uint32_t fenceCount, const Fence * pFences);
using PFN_GetFenceStatus = Result (*) (Device device, Fence fence);
using PFN_WaitForFences = Result (*) (Device device, uint32_t fenceCount, const Fence * pFences, Bool32 waitAll, uint64_t timeout);
using PFN_CreateSemaphore = Result (*) (Device device, const SemaphoreCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Semaphore * pSemaphore);
using PFN_DestroySemaphore = void (*) (Device device, Semaphore semaphore, const AllocationCallbacks * pAllocator);
using PFN_CreateEvent = Result (*) (Device device, const EventCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Event * pEvent);
using PFN_DestroyEvent = void (*) (Device device, Event event, const AllocationCallbacks * pAllocator);
using PFN_GetEventStatus = Result (*) (Device device, Event event);
using PFN_SetEvent = Result (*) (Device device, Event event);
using PFN_ResetEvent = Result (*) (Device device, Event event);
using PFN_CreateQueryPool = Result (*) (Device device, const QueryPoolCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, QueryPool * pQueryPool);
using PFN_DestroyQueryPool = void (*) (Device device, QueryPool queryPool, const AllocationCallbacks * pAllocator);
using PFN_GetQueryPoolResults = Result (*) (Device device, QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void * pData, DeviceSize stride, QueryResultFlags flags);
using PFN_ResetQueryPool = void (*) (Device device, QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
using PFN_ResetQueryPoolEXT = PFN_ResetQueryPool;
using PFN_CreateBuffer = Result (*) (Device device, const BufferCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Buffer * pBuffer);
using PFN_DestroyBuffer = void (*) (Device device, Buffer buffer, const AllocationCallbacks * pAllocator);
using PFN_CreateBufferView = Result (*) (Device device, const BufferViewCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, BufferView * pView);
using PFN_DestroyBufferView = void (*) (Device device, BufferView bufferView, const AllocationCallbacks * pAllocator);
using PFN_CreateImage = Result (*) (Device device, const ImageCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Image * pImage);
using PFN_DestroyImage = void (*) (Device device, Image image, const AllocationCallbacks * pAllocator);
using PFN_GetImageSubresourceLayout = void (*) (Device device, Image image, const ImageSubresource * pSubresource, SubresourceLayout * pLayout);
using PFN_CreateImageView = Result (*) (Device device, const ImageViewCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, ImageView * pView);
using PFN_DestroyImageView = void (*) (Device device, ImageView imageView, const AllocationCallbacks * pAllocator);
using PFN_CreateShaderModule = Result (*) (Device device, const ShaderModuleCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, ShaderModule * pShaderModule);
using PFN_DestroyShaderModule = void (*) (Device device, ShaderModule shaderModule, const AllocationCallbacks * pAllocator);
using PFN_CreatePipelineCache = Result (*) (Device device, const PipelineCacheCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, PipelineCache * pPipelineCache);
using PFN_CreatePipelineCache = Result (*) (Device device, const PipelineCacheCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, PipelineCache * pPipelineCache);
using PFN_DestroyPipelineCache = void (*) (Device device, PipelineCache pipelineCache, const AllocationCallbacks * pAllocator);
using PFN_GetPipelineCacheData = Result (*) (Device device, PipelineCache pipelineCache, size_t * pDataSize, void * pData);
using PFN_MergePipelineCaches = Result (*) (Device device, PipelineCache dstCache, uint32_t srcCacheCount, const PipelineCache * pSrcCaches);
using PFN_CreateGraphicsPipelines = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const GraphicsPipelineCreateInfo * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CreateGraphicsPipelines = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const GraphicsPipelineCreateInfo * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CreateComputePipelines = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const ComputePipelineCreateInfo * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CreateComputePipelines = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const ComputePipelineCreateInfo * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = Result (*) (Device device, RenderPass renderpass, Extent2D * pMaxWorkgroupSize);
using PFN_DestroyPipeline = void (*) (Device device, Pipeline pipeline, const AllocationCallbacks * pAllocator);
using PFN_CreatePipelineLayout = Result (*) (Device device, const PipelineLayoutCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, PipelineLayout * pPipelineLayout);
using PFN_DestroyPipelineLayout = void (*) (Device device, PipelineLayout pipelineLayout, const AllocationCallbacks * pAllocator);
using PFN_CreateSampler = Result (*) (Device device, const SamplerCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Sampler * pSampler);
using PFN_DestroySampler = void (*) (Device device, Sampler sampler, const AllocationCallbacks * pAllocator);
using PFN_CreateDescriptorSetLayout = Result (*) (Device device, const DescriptorSetLayoutCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, DescriptorSetLayout * pSetLayout);
using PFN_DestroyDescriptorSetLayout = void (*) (Device device, DescriptorSetLayout descriptorSetLayout, const AllocationCallbacks * pAllocator);
using PFN_CreateDescriptorPool = Result (*) (Device device, const DescriptorPoolCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, DescriptorPool * pDescriptorPool);
using PFN_DestroyDescriptorPool = void (*) (Device device, DescriptorPool descriptorPool, const AllocationCallbacks * pAllocator);
using PFN_ResetDescriptorPool = Result (*) (Device device, DescriptorPool descriptorPool, DescriptorPoolResetFlags flags);
using PFN_AllocateDescriptorSets = Result (*) (Device device, const DescriptorSetAllocateInfo * pAllocateInfo, DescriptorSet * pDescriptorSets);
using PFN_FreeDescriptorSets = Result (*) (Device device, DescriptorPool descriptorPool, uint32_t descriptorSetCount, const DescriptorSet * pDescriptorSets);
using PFN_UpdateDescriptorSets = void (*) (Device device, uint32_t descriptorWriteCount, const WriteDescriptorSet * pDescriptorWrites, uint32_t descriptorCopyCount, const CopyDescriptorSet * pDescriptorCopies);
using PFN_CreateFramebuffer = Result (*) (Device device, const FramebufferCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, Framebuffer * pFramebuffer);
using PFN_DestroyFramebuffer = void (*) (Device device, Framebuffer framebuffer, const AllocationCallbacks * pAllocator);
using PFN_CreateRenderPass = Result (*) (Device device, const RenderPassCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, RenderPass * pRenderPass);
using PFN_DestroyRenderPass = void (*) (Device device, RenderPass renderPass, const AllocationCallbacks * pAllocator);
using PFN_GetRenderAreaGranularity = void (*) (Device device, RenderPass renderPass, Extent2D * pGranularity);
using PFN_GetRenderingAreaGranularityKHR = void (*) (Device device, const RenderingAreaInfoKHR * pRenderingAreaInfo, Extent2D * pGranularity);
using PFN_CreateCommandPool = Result (*) (Device device, const CommandPoolCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, CommandPool * pCommandPool);
using PFN_DestroyCommandPool = void (*) (Device device, CommandPool commandPool, const AllocationCallbacks * pAllocator);
using PFN_ResetCommandPool = Result (*) (Device device, CommandPool commandPool, CommandPoolResetFlags flags);
using PFN_AllocateCommandBuffers = Result (*) (Device device, const CommandBufferAllocateInfo * pAllocateInfo, CommandBuffer * pCommandBuffers);
using PFN_FreeCommandBuffers = void (*) (Device device, CommandPool commandPool, uint32_t commandBufferCount, const CommandBuffer * pCommandBuffers);
using PFN_BeginCommandBuffer = Result (*) (CommandBuffer commandBuffer, const CommandBufferBeginInfo * pBeginInfo);
using PFN_EndCommandBuffer = Result (*) (CommandBuffer commandBuffer);
using PFN_ResetCommandBuffer = Result (*) (CommandBuffer commandBuffer, CommandBufferResetFlags flags);
using PFN_CmdBindPipeline = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, Pipeline pipeline);
using PFN_CmdSetAttachmentFeedbackLoopEnableEXT = void (*) (CommandBuffer commandBuffer, ImageAspectFlags aspectMask);
using PFN_CmdSetViewport = void (*) (CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const Viewport * pViewports);
using PFN_CmdSetScissor = void (*) (CommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const Rect2D * pScissors);
using PFN_CmdSetLineWidth = void (*) (CommandBuffer commandBuffer, float lineWidth);
using PFN_CmdSetDepthBias = void (*) (CommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
using PFN_CmdSetBlendConstants = void (*) (CommandBuffer commandBuffer, const float blendConstants [4]);
using PFN_CmdSetDepthBounds = void (*) (CommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
using PFN_CmdSetStencilCompareMask = void (*) (CommandBuffer commandBuffer, StencilFaceFlags faceMask, uint32_t compareMask);
using PFN_CmdSetStencilWriteMask = void (*) (CommandBuffer commandBuffer, StencilFaceFlags faceMask, uint32_t writeMask);
using PFN_CmdSetStencilReference = void (*) (CommandBuffer commandBuffer, StencilFaceFlags faceMask, uint32_t reference);
using PFN_CmdBindDescriptorSets = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, PipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const DescriptorSet * pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t * pDynamicOffsets);
using PFN_CmdBindIndexBuffer = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, IndexType indexType);
using PFN_CmdBindVertexBuffers = void (*) (CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const Buffer * pBuffers, const DeviceSize * pOffsets);
using PFN_CmdDraw = void (*) (CommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
using PFN_CmdDrawIndexed = void (*) (CommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
using PFN_CmdDrawMultiEXT = void (*) (CommandBuffer commandBuffer, uint32_t drawCount, const MultiDrawInfoEXT * pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
using PFN_CmdDrawMultiIndexedEXT = void (*) (CommandBuffer commandBuffer, uint32_t drawCount, const MultiDrawIndexedInfoEXT * pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t * pVertexOffset);
using PFN_CmdDrawIndirect = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride);
using PFN_CmdDrawIndexedIndirect = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride);
using PFN_CmdDispatch = void (*) (CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
using PFN_CmdDispatchIndirect = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset);
using PFN_CmdSubpassShadingHUAWEI = void (*) (CommandBuffer commandBuffer);
using PFN_CmdDrawClusterHUAWEI = void (*) (CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
using PFN_CmdDrawClusterIndirectHUAWEI = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset);
using PFN_CmdUpdatePipelineIndirectBufferNV = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, Pipeline pipeline);
using PFN_CmdCopyBuffer = void (*) (CommandBuffer commandBuffer, Buffer srcBuffer, Buffer dstBuffer, uint32_t regionCount, const BufferCopy * pRegions);
using PFN_CmdCopyImage = void (*) (CommandBuffer commandBuffer, Image srcImage, ImageLayout srcImageLayout, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const ImageCopy * pRegions);
using PFN_CmdBlitImage = void (*) (CommandBuffer commandBuffer, Image srcImage, ImageLayout srcImageLayout, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const ImageBlit * pRegions, Filter filter);
using PFN_CmdCopyBufferToImage = void (*) (CommandBuffer commandBuffer, Buffer srcBuffer, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const BufferImageCopy * pRegions);
using PFN_CmdCopyImageToBuffer = void (*) (CommandBuffer commandBuffer, Image srcImage, ImageLayout srcImageLayout, Buffer dstBuffer, uint32_t regionCount, const BufferImageCopy * pRegions);
using PFN_CmdCopyMemoryIndirectNV = void (*) (CommandBuffer commandBuffer, DeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride);
using PFN_CmdCopyMemoryToImageIndirectNV = void (*) (CommandBuffer commandBuffer, DeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, Image dstImage, ImageLayout dstImageLayout, const ImageSubresourceLayers * pImageSubresources);
using PFN_CmdUpdateBuffer = void (*) (CommandBuffer commandBuffer, Buffer dstBuffer, DeviceSize dstOffset, DeviceSize dataSize, const void * pData);
using PFN_CmdFillBuffer = void (*) (CommandBuffer commandBuffer, Buffer dstBuffer, DeviceSize dstOffset, DeviceSize size, uint32_t data);
using PFN_CmdClearColorImage = void (*) (CommandBuffer commandBuffer, Image image, ImageLayout imageLayout, const ClearColorValue * pColor, uint32_t rangeCount, const ImageSubresourceRange * pRanges);
using PFN_CmdClearDepthStencilImage = void (*) (CommandBuffer commandBuffer, Image image, ImageLayout imageLayout, const ClearDepthStencilValue * pDepthStencil, uint32_t rangeCount, const ImageSubresourceRange * pRanges);
using PFN_CmdClearAttachments = void (*) (CommandBuffer commandBuffer, uint32_t attachmentCount, const ClearAttachment * pAttachments, uint32_t rectCount, const ClearRect * pRects);
using PFN_CmdResolveImage = void (*) (CommandBuffer commandBuffer, Image srcImage, ImageLayout srcImageLayout, Image dstImage, ImageLayout dstImageLayout, uint32_t regionCount, const ImageResolve * pRegions);
using PFN_CmdSetEvent = void (*) (CommandBuffer commandBuffer, Event event, PipelineStageFlags stageMask);
using PFN_CmdResetEvent = void (*) (CommandBuffer commandBuffer, Event event, PipelineStageFlags stageMask);
using PFN_CmdWaitEvents = void (*) (CommandBuffer commandBuffer, uint32_t eventCount, const Event * pEvents, PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const MemoryBarrier * pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const BufferMemoryBarrier * pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const ImageMemoryBarrier * pImageMemoryBarriers);
using PFN_CmdPipelineBarrier = void (*) (CommandBuffer commandBuffer, PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, DependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const MemoryBarrier * pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const BufferMemoryBarrier * pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const ImageMemoryBarrier * pImageMemoryBarriers);
using PFN_CmdBeginQuery = void (*) (CommandBuffer commandBuffer, QueryPool queryPool, uint32_t query, QueryControlFlags flags);
using PFN_CmdEndQuery = void (*) (CommandBuffer commandBuffer, QueryPool queryPool, uint32_t query);
using PFN_CmdBeginConditionalRenderingEXT = void (*) (CommandBuffer commandBuffer, const ConditionalRenderingBeginInfoEXT * pConditionalRenderingBegin);
using PFN_CmdEndConditionalRenderingEXT = void (*) (CommandBuffer commandBuffer);
using PFN_CmdResetQueryPool = void (*) (CommandBuffer commandBuffer, QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
using PFN_CmdWriteTimestamp = void (*) (CommandBuffer commandBuffer, PipelineStageFlagBits pipelineStage, QueryPool queryPool, uint32_t query);
using PFN_CmdCopyQueryPoolResults = void (*) (CommandBuffer commandBuffer, QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, Buffer dstBuffer, DeviceSize dstOffset, DeviceSize stride, QueryResultFlags flags);
using PFN_CmdPushConstants = void (*) (CommandBuffer commandBuffer, PipelineLayout layout, ShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void * pValues);
using PFN_CmdBeginRenderPass = void (*) (CommandBuffer commandBuffer, const RenderPassBeginInfo * pRenderPassBegin, SubpassContents contents);
using PFN_CmdNextSubpass = void (*) (CommandBuffer commandBuffer, SubpassContents contents);
using PFN_CmdEndRenderPass = void (*) (CommandBuffer commandBuffer);
using PFN_CmdExecuteCommands = void (*) (CommandBuffer commandBuffer, uint32_t commandBufferCount, const CommandBuffer * pCommandBuffers);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
using PFN_CreateAndroidSurfaceKHR = Result (*) (Instance instance, const AndroidSurfaceCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
using PFN_GetPhysicalDeviceDisplayPropertiesKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pPropertyCount, DisplayPropertiesKHR * pProperties);
using PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pPropertyCount, DisplayPlanePropertiesKHR * pProperties);
using PFN_GetDisplayPlaneSupportedDisplaysKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t * pDisplayCount, DisplayKHR * pDisplays);
using PFN_GetDisplayModePropertiesKHR = Result (*) (PhysicalDevice physicalDevice, DisplayKHR display, uint32_t * pPropertyCount, DisplayModePropertiesKHR * pProperties);
using PFN_CreateDisplayModeKHR = Result (*) (PhysicalDevice physicalDevice, DisplayKHR display, const DisplayModeCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, DisplayModeKHR * pMode);
using PFN_GetDisplayPlaneCapabilitiesKHR = Result (*) (PhysicalDevice physicalDevice, DisplayModeKHR mode, uint32_t planeIndex, DisplayPlaneCapabilitiesKHR * pCapabilities);
using PFN_CreateDisplayPlaneSurfaceKHR = Result (*) (Instance instance, const DisplaySurfaceCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_CreateSharedSwapchainsKHR = Result (*) (Device device, uint32_t swapchainCount, const SwapchainCreateInfoKHR * pCreateInfos, const AllocationCallbacks * pAllocator, SwapchainKHR * pSwapchains);
using PFN_DestroySurfaceKHR = void (*) (Instance instance, SurfaceKHR surface, const AllocationCallbacks * pAllocator);
using PFN_GetPhysicalDeviceSurfaceSupportKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, SurfaceKHR surface, Bool32 * pSupported);
using PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR = Result (*) (PhysicalDevice physicalDevice, SurfaceKHR surface, SurfaceCapabilitiesKHR * pSurfaceCapabilities);
using PFN_GetPhysicalDeviceSurfaceFormatsKHR = Result (*) (PhysicalDevice physicalDevice, SurfaceKHR surface, uint32_t * pSurfaceFormatCount, SurfaceFormatKHR * pSurfaceFormats);
using PFN_GetPhysicalDeviceSurfacePresentModesKHR = Result (*) (PhysicalDevice physicalDevice, SurfaceKHR surface, uint32_t * pPresentModeCount, PresentModeKHR * pPresentModes);
using PFN_CreateSwapchainKHR = Result (*) (Device device, const SwapchainCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SwapchainKHR * pSwapchain);
using PFN_DestroySwapchainKHR = void (*) (Device device, SwapchainKHR swapchain, const AllocationCallbacks * pAllocator);
using PFN_GetSwapchainImagesKHR = Result (*) (Device device, SwapchainKHR swapchain, uint32_t * pSwapchainImageCount, Image * pSwapchainImages);
using PFN_AcquireNextImageKHR = Result (*) (Device device, SwapchainKHR swapchain, uint64_t timeout, Semaphore semaphore, Fence fence, uint32_t * pImageIndex);
using PFN_QueuePresentKHR = Result (*) (Queue queue, const PresentInfoKHR * pPresentInfo);
#if defined(VK_USE_PLATFORM_VI_NN)
using PFN_CreateViSurfaceNN = Result (*) (Instance instance, const ViSurfaceCreateInfoNN * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_VI_NN)
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
using PFN_CreateWaylandSurfaceKHR = Result (*) (Instance instance, const WaylandSurfaceCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceWaylandPresentationSupportKHR = VkBool32 (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display * display);
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_CreateWin32SurfaceKHR = Result (*) (Instance instance, const Win32SurfaceCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceWin32PresentationSupportKHR = VkBool32 (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_XLIB_KHR)
using PFN_CreateXlibSurfaceKHR = Result (*) (Instance instance, const XlibSurfaceCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceXlibPresentationSupportKHR = VkBool32 (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display * dpy, VisualID visualID);
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
using PFN_CreateXcbSurfaceKHR = Result (*) (Instance instance, const XcbSurfaceCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceXcbPresentationSupportKHR = VkBool32 (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t * connection, xcb_visualid_t visual_id);
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
using PFN_CreateDirectFBSurfaceEXT = Result (*) (Instance instance, const DirectFBSurfaceCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT = VkBool32 (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB * dfb);
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#if defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_CreateImagePipeSurfaceFUCHSIA = Result (*) (Instance instance, const ImagePipeSurfaceCreateInfoFUCHSIA * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_GGP)
using PFN_CreateStreamDescriptorSurfaceGGP = Result (*) (Instance instance, const StreamDescriptorSurfaceCreateInfoGGP * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_GGP)
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
using PFN_CreateScreenSurfaceQNX = Result (*) (Instance instance, const ScreenSurfaceCreateInfoQNX * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceScreenPresentationSupportQNX = VkBool32 (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window * window);
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
using PFN_CreateDebugReportCallbackEXT = Result (*) (Instance instance, const DebugReportCallbackCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, DebugReportCallbackEXT * pCallback);
using PFN_DestroyDebugReportCallbackEXT = void (*) (Instance instance, DebugReportCallbackEXT callback, const AllocationCallbacks * pAllocator);
using PFN_DebugReportMessageEXT = void (*) (Instance instance, DebugReportFlagsEXT flags, DebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char * pLayerPrefix, const char * pMessage);
using PFN_DebugMarkerSetObjectNameEXT = Result (*) (Device device, const DebugMarkerObjectNameInfoEXT * pNameInfo);
using PFN_DebugMarkerSetObjectTagEXT = Result (*) (Device device, const DebugMarkerObjectTagInfoEXT * pTagInfo);
using PFN_CmdDebugMarkerBeginEXT = void (*) (CommandBuffer commandBuffer, const DebugMarkerMarkerInfoEXT * pMarkerInfo);
using PFN_CmdDebugMarkerEndEXT = void (*) (CommandBuffer commandBuffer);
using PFN_CmdDebugMarkerInsertEXT = void (*) (CommandBuffer commandBuffer, const DebugMarkerMarkerInfoEXT * pMarkerInfo);
using PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV = Result (*) (PhysicalDevice physicalDevice, Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags, ExternalMemoryHandleTypeFlagsNV externalHandleType, ExternalImageFormatPropertiesNV * pExternalImageFormatProperties);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetMemoryWin32HandleNV = Result (*) (Device device, DeviceMemory memory, ExternalMemoryHandleTypeFlagsNV handleType, HANDLE * pHandle);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_CmdExecuteGeneratedCommandsNV = void (*) (CommandBuffer commandBuffer, Bool32 isPreprocessed, const GeneratedCommandsInfoNV * pGeneratedCommandsInfo);
using PFN_CmdPreprocessGeneratedCommandsNV = void (*) (CommandBuffer commandBuffer, const GeneratedCommandsInfoNV * pGeneratedCommandsInfo);
using PFN_CmdBindPipelineShaderGroupNV = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, Pipeline pipeline, uint32_t groupIndex);
using PFN_GetGeneratedCommandsMemoryRequirementsNV = void (*) (Device device, const GeneratedCommandsMemoryRequirementsInfoNV * pInfo, MemoryRequirements2 * pMemoryRequirements);
using PFN_CreateIndirectCommandsLayoutNV = Result (*) (Device device, const IndirectCommandsLayoutCreateInfoNV * pCreateInfo, const AllocationCallbacks * pAllocator, IndirectCommandsLayoutNV * pIndirectCommandsLayout);
using PFN_DestroyIndirectCommandsLayoutNV = void (*) (Device device, IndirectCommandsLayoutNV indirectCommandsLayout, const AllocationCallbacks * pAllocator);
using PFN_GetPhysicalDeviceFeatures2 = void (*) (PhysicalDevice physicalDevice, PhysicalDeviceFeatures2 * pFeatures);
using PFN_GetPhysicalDeviceFeatures2KHR = PFN_GetPhysicalDeviceFeatures2;
using PFN_GetPhysicalDeviceProperties2 = void (*) (PhysicalDevice physicalDevice, PhysicalDeviceProperties2 * pProperties);
using PFN_GetPhysicalDeviceProperties2KHR = PFN_GetPhysicalDeviceProperties2;
using PFN_GetPhysicalDeviceFormatProperties2 = void (*) (PhysicalDevice physicalDevice, Format format, FormatProperties2 * pFormatProperties);
using PFN_GetPhysicalDeviceFormatProperties2KHR = PFN_GetPhysicalDeviceFormatProperties2;
using PFN_GetPhysicalDeviceImageFormatProperties2 = Result (*) (PhysicalDevice physicalDevice, const PhysicalDeviceImageFormatInfo2 * pImageFormatInfo, ImageFormatProperties2 * pImageFormatProperties);
using PFN_GetPhysicalDeviceImageFormatProperties2KHR = PFN_GetPhysicalDeviceImageFormatProperties2;
using PFN_GetPhysicalDeviceQueueFamilyProperties2 = void (*) (PhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, QueueFamilyProperties2 * pQueueFamilyProperties);
using PFN_GetPhysicalDeviceQueueFamilyProperties2KHR = PFN_GetPhysicalDeviceQueueFamilyProperties2;
using PFN_GetPhysicalDeviceMemoryProperties2 = void (*) (PhysicalDevice physicalDevice, PhysicalDeviceMemoryProperties2 * pMemoryProperties);
using PFN_GetPhysicalDeviceMemoryProperties2KHR = PFN_GetPhysicalDeviceMemoryProperties2;
using PFN_GetPhysicalDeviceSparseImageFormatProperties2 = void (*) (PhysicalDevice physicalDevice, const PhysicalDeviceSparseImageFormatInfo2 * pFormatInfo, uint32_t * pPropertyCount, SparseImageFormatProperties2 * pProperties);
using PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR = PFN_GetPhysicalDeviceSparseImageFormatProperties2;
using PFN_CmdPushDescriptorSetKHR = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, PipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const WriteDescriptorSet * pDescriptorWrites);
using PFN_TrimCommandPool = void (*) (Device device, CommandPool commandPool, CommandPoolTrimFlags flags);
using PFN_TrimCommandPoolKHR = PFN_TrimCommandPool;
using PFN_GetPhysicalDeviceExternalBufferProperties = void (*) (PhysicalDevice physicalDevice, const PhysicalDeviceExternalBufferInfo * pExternalBufferInfo, ExternalBufferProperties * pExternalBufferProperties);
using PFN_GetPhysicalDeviceExternalBufferPropertiesKHR = PFN_GetPhysicalDeviceExternalBufferProperties;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetMemoryWin32HandleKHR = Result (*) (Device device, const MemoryGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle);
using PFN_GetMemoryWin32HandlePropertiesKHR = Result (*) (Device device, ExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, MemoryWin32HandlePropertiesKHR * pMemoryWin32HandleProperties);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetMemoryFdKHR = Result (*) (Device device, const MemoryGetFdInfoKHR * pGetFdInfo, int * pFd);
using PFN_GetMemoryFdPropertiesKHR = Result (*) (Device device, ExternalMemoryHandleTypeFlagBits handleType, int fd, MemoryFdPropertiesKHR * pMemoryFdProperties);
#if defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_GetMemoryZirconHandleFUCHSIA = Result (*) (Device device, const MemoryGetZirconHandleInfoFUCHSIA * pGetZirconHandleInfo, zx_handle_t * pZirconHandle);
using PFN_GetMemoryZirconHandlePropertiesFUCHSIA = Result (*) (Device device, ExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, MemoryZirconHandlePropertiesFUCHSIA * pMemoryZirconHandleProperties);
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_GetMemoryRemoteAddressNV = Result (*) (Device device, const MemoryGetRemoteAddressInfoNV * pMemoryGetRemoteAddressInfo, RemoteAddressNV * pAddress);
using PFN_GetPhysicalDeviceExternalSemaphoreProperties = void (*) (PhysicalDevice physicalDevice, const PhysicalDeviceExternalSemaphoreInfo * pExternalSemaphoreInfo, ExternalSemaphoreProperties * pExternalSemaphoreProperties);
using PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR = PFN_GetPhysicalDeviceExternalSemaphoreProperties;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetSemaphoreWin32HandleKHR = Result (*) (Device device, const SemaphoreGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle);
using PFN_ImportSemaphoreWin32HandleKHR = Result (*) (Device device, const ImportSemaphoreWin32HandleInfoKHR * pImportSemaphoreWin32HandleInfo);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetSemaphoreFdKHR = Result (*) (Device device, const SemaphoreGetFdInfoKHR * pGetFdInfo, int * pFd);
using PFN_ImportSemaphoreFdKHR = Result (*) (Device device, const ImportSemaphoreFdInfoKHR * pImportSemaphoreFdInfo);
#if defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_GetSemaphoreZirconHandleFUCHSIA = Result (*) (Device device, const SemaphoreGetZirconHandleInfoFUCHSIA * pGetZirconHandleInfo, zx_handle_t * pZirconHandle);
using PFN_ImportSemaphoreZirconHandleFUCHSIA = Result (*) (Device device, const ImportSemaphoreZirconHandleInfoFUCHSIA * pImportSemaphoreZirconHandleInfo);
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_GetPhysicalDeviceExternalFenceProperties = void (*) (PhysicalDevice physicalDevice, const PhysicalDeviceExternalFenceInfo * pExternalFenceInfo, ExternalFenceProperties * pExternalFenceProperties);
using PFN_GetPhysicalDeviceExternalFencePropertiesKHR = PFN_GetPhysicalDeviceExternalFenceProperties;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetFenceWin32HandleKHR = Result (*) (Device device, const FenceGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle);
using PFN_ImportFenceWin32HandleKHR = Result (*) (Device device, const ImportFenceWin32HandleInfoKHR * pImportFenceWin32HandleInfo);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetFenceFdKHR = Result (*) (Device device, const FenceGetFdInfoKHR * pGetFdInfo, int * pFd);
using PFN_ImportFenceFdKHR = Result (*) (Device device, const ImportFenceFdInfoKHR * pImportFenceFdInfo);
using PFN_ReleaseDisplayEXT = Result (*) (PhysicalDevice physicalDevice, DisplayKHR display);
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
using PFN_AcquireXlibDisplayEXT = Result (*) (PhysicalDevice physicalDevice, Display * dpy, DisplayKHR display);
using PFN_GetRandROutputDisplayEXT = Result (*) (PhysicalDevice physicalDevice, Display * dpy, RROutput rrOutput, DisplayKHR * pDisplay);
#endif // defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_AcquireWinrtDisplayNV = Result (*) (PhysicalDevice physicalDevice, DisplayKHR display);
using PFN_GetWinrtDisplayNV = Result (*) (PhysicalDevice physicalDevice, uint32_t deviceRelativeId, DisplayKHR * pDisplay);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_DisplayPowerControlEXT = Result (*) (Device device, DisplayKHR display, const DisplayPowerInfoEXT * pDisplayPowerInfo);
using PFN_RegisterDeviceEventEXT = Result (*) (Device device, const DeviceEventInfoEXT * pDeviceEventInfo, const AllocationCallbacks * pAllocator, Fence * pFence);
using PFN_RegisterDisplayEventEXT = Result (*) (Device device, DisplayKHR display, const DisplayEventInfoEXT * pDisplayEventInfo, const AllocationCallbacks * pAllocator, Fence * pFence);
using PFN_GetSwapchainCounterEXT = Result (*) (Device device, SwapchainKHR swapchain, SurfaceCounterFlagBitsEXT counter, uint64_t * pCounterValue);
using PFN_GetPhysicalDeviceSurfaceCapabilities2EXT = Result (*) (PhysicalDevice physicalDevice, SurfaceKHR surface, SurfaceCapabilities2EXT * pSurfaceCapabilities);
using PFN_EnumeratePhysicalDeviceGroups = Result (*) (Instance instance, uint32_t * pPhysicalDeviceGroupCount, PhysicalDeviceGroupProperties * pPhysicalDeviceGroupProperties);
using PFN_EnumeratePhysicalDeviceGroupsKHR = PFN_EnumeratePhysicalDeviceGroups;
using PFN_GetDeviceGroupPeerMemoryFeatures = void (*) (Device device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PeerMemoryFeatureFlags * pPeerMemoryFeatures);
using PFN_GetDeviceGroupPeerMemoryFeaturesKHR = PFN_GetDeviceGroupPeerMemoryFeatures;
using PFN_BindBufferMemory2 = Result (*) (Device device, uint32_t bindInfoCount, const BindBufferMemoryInfo * pBindInfos);
using PFN_BindBufferMemory2KHR = PFN_BindBufferMemory2;
using PFN_BindImageMemory2 = Result (*) (Device device, uint32_t bindInfoCount, const BindImageMemoryInfo * pBindInfos);
using PFN_BindImageMemory2KHR = PFN_BindImageMemory2;
using PFN_CmdSetDeviceMask = void (*) (CommandBuffer commandBuffer, uint32_t deviceMask);
using PFN_CmdSetDeviceMaskKHR = PFN_CmdSetDeviceMask;
using PFN_GetDeviceGroupPresentCapabilitiesKHR = Result (*) (Device device, DeviceGroupPresentCapabilitiesKHR * pDeviceGroupPresentCapabilities);
using PFN_GetDeviceGroupSurfacePresentModesKHR = Result (*) (Device device, SurfaceKHR surface, DeviceGroupPresentModeFlagsKHR * pModes);
using PFN_AcquireNextImage2KHR = Result (*) (Device device, const AcquireNextImageInfoKHR * pAcquireInfo, uint32_t * pImageIndex);
using PFN_CmdDispatchBase = void (*) (CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
using PFN_CmdDispatchBaseKHR = PFN_CmdDispatchBase;
using PFN_GetPhysicalDevicePresentRectanglesKHR = Result (*) (PhysicalDevice physicalDevice, SurfaceKHR surface, uint32_t * pRectCount, Rect2D * pRects);
using PFN_CreateDescriptorUpdateTemplate = Result (*) (Device device, const DescriptorUpdateTemplateCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, DescriptorUpdateTemplate * pDescriptorUpdateTemplate);
using PFN_CreateDescriptorUpdateTemplateKHR = PFN_CreateDescriptorUpdateTemplate;
using PFN_DestroyDescriptorUpdateTemplate = void (*) (Device device, DescriptorUpdateTemplate descriptorUpdateTemplate, const AllocationCallbacks * pAllocator);
using PFN_DestroyDescriptorUpdateTemplateKHR = PFN_DestroyDescriptorUpdateTemplate;
using PFN_UpdateDescriptorSetWithTemplate = void (*) (Device device, DescriptorSet descriptorSet, DescriptorUpdateTemplate descriptorUpdateTemplate, const void * pData);
using PFN_UpdateDescriptorSetWithTemplateKHR = PFN_UpdateDescriptorSetWithTemplate;
using PFN_CmdPushDescriptorSetWithTemplateKHR = void (*) (CommandBuffer commandBuffer, DescriptorUpdateTemplate descriptorUpdateTemplate, PipelineLayout layout, uint32_t set, const void * pData);
using PFN_SetHdrMetadataEXT = void (*) (Device device, uint32_t swapchainCount, const SwapchainKHR * pSwapchains, const HdrMetadataEXT * pMetadata);
using PFN_GetSwapchainStatusKHR = Result (*) (Device device, SwapchainKHR swapchain);
using PFN_GetRefreshCycleDurationGOOGLE = Result (*) (Device device, SwapchainKHR swapchain, RefreshCycleDurationGOOGLE * pDisplayTimingProperties);
using PFN_GetPastPresentationTimingGOOGLE = Result (*) (Device device, SwapchainKHR swapchain, uint32_t * pPresentationTimingCount, PastPresentationTimingGOOGLE * pPresentationTimings);
#if defined(VK_USE_PLATFORM_IOS_MVK)
using PFN_CreateIOSSurfaceMVK = Result (*) (Instance instance, const IOSSurfaceCreateInfoMVK * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_IOS_MVK)
#if defined(VK_USE_PLATFORM_MACOS_MVK)
using PFN_CreateMacOSSurfaceMVK = Result (*) (Instance instance, const MacOSSurfaceCreateInfoMVK * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_MACOS_MVK)
#if defined(VK_USE_PLATFORM_METAL_EXT)
using PFN_CreateMetalSurfaceEXT = Result (*) (Instance instance, const MetalSurfaceCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
using PFN_CmdSetViewportWScalingNV = void (*) (CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const ViewportWScalingNV * pViewportWScalings);
using PFN_CmdSetDiscardRectangleEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const Rect2D * pDiscardRectangles);
using PFN_CmdSetDiscardRectangleEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 discardRectangleEnable);
using PFN_CmdSetDiscardRectangleModeEXT = void (*) (CommandBuffer commandBuffer, DiscardRectangleModeEXT discardRectangleMode);
using PFN_CmdSetSampleLocationsEXT = void (*) (CommandBuffer commandBuffer, const SampleLocationsInfoEXT * pSampleLocationsInfo);
using PFN_GetPhysicalDeviceMultisamplePropertiesEXT = void (*) (PhysicalDevice physicalDevice, SampleCountFlagBits samples, MultisamplePropertiesEXT * pMultisampleProperties);
using PFN_GetPhysicalDeviceSurfaceCapabilities2KHR = Result (*) (PhysicalDevice physicalDevice, const PhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, SurfaceCapabilities2KHR * pSurfaceCapabilities);
using PFN_GetPhysicalDeviceSurfaceFormats2KHR = Result (*) (PhysicalDevice physicalDevice, const PhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, uint32_t * pSurfaceFormatCount, SurfaceFormat2KHR * pSurfaceFormats);
using PFN_GetPhysicalDeviceDisplayProperties2KHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pPropertyCount, DisplayProperties2KHR * pProperties);
using PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pPropertyCount, DisplayPlaneProperties2KHR * pProperties);
using PFN_GetDisplayModeProperties2KHR = Result (*) (PhysicalDevice physicalDevice, DisplayKHR display, uint32_t * pPropertyCount, DisplayModeProperties2KHR * pProperties);
using PFN_GetDisplayPlaneCapabilities2KHR = Result (*) (PhysicalDevice physicalDevice, const DisplayPlaneInfo2KHR * pDisplayPlaneInfo, DisplayPlaneCapabilities2KHR * pCapabilities);
using PFN_GetBufferMemoryRequirements2 = void (*) (Device device, const BufferMemoryRequirementsInfo2 * pInfo, MemoryRequirements2 * pMemoryRequirements);
using PFN_GetBufferMemoryRequirements2KHR = PFN_GetBufferMemoryRequirements2;
using PFN_GetImageMemoryRequirements2 = void (*) (Device device, const ImageMemoryRequirementsInfo2 * pInfo, MemoryRequirements2 * pMemoryRequirements);
using PFN_GetImageMemoryRequirements2KHR = PFN_GetImageMemoryRequirements2;
using PFN_GetImageSparseMemoryRequirements2 = void (*) (Device device, const ImageSparseMemoryRequirementsInfo2 * pInfo, uint32_t * pSparseMemoryRequirementCount, SparseImageMemoryRequirements2 * pSparseMemoryRequirements);
using PFN_GetImageSparseMemoryRequirements2KHR = PFN_GetImageSparseMemoryRequirements2;
using PFN_GetDeviceBufferMemoryRequirements = void (*) (Device device, const DeviceBufferMemoryRequirements * pInfo, MemoryRequirements2 * pMemoryRequirements);
using PFN_GetDeviceBufferMemoryRequirementsKHR = PFN_GetDeviceBufferMemoryRequirements;
using PFN_GetDeviceImageMemoryRequirements = void (*) (Device device, const DeviceImageMemoryRequirements * pInfo, MemoryRequirements2 * pMemoryRequirements);
using PFN_GetDeviceImageMemoryRequirementsKHR = PFN_GetDeviceImageMemoryRequirements;
using PFN_GetDeviceImageSparseMemoryRequirements = void (*) (Device device, const DeviceImageMemoryRequirements * pInfo, uint32_t * pSparseMemoryRequirementCount, SparseImageMemoryRequirements2 * pSparseMemoryRequirements);
using PFN_GetDeviceImageSparseMemoryRequirementsKHR = PFN_GetDeviceImageSparseMemoryRequirements;
using PFN_CreateSamplerYcbcrConversion = Result (*) (Device device, const SamplerYcbcrConversionCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, SamplerYcbcrConversion * pYcbcrConversion);
using PFN_CreateSamplerYcbcrConversionKHR = PFN_CreateSamplerYcbcrConversion;
using PFN_DestroySamplerYcbcrConversion = void (*) (Device device, SamplerYcbcrConversion ycbcrConversion, const AllocationCallbacks * pAllocator);
using PFN_DestroySamplerYcbcrConversionKHR = PFN_DestroySamplerYcbcrConversion;
using PFN_GetDeviceQueue2 = void (*) (Device device, const DeviceQueueInfo2 * pQueueInfo, Queue * pQueue);
using PFN_CreateValidationCacheEXT = Result (*) (Device device, const ValidationCacheCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, ValidationCacheEXT * pValidationCache);
using PFN_DestroyValidationCacheEXT = void (*) (Device device, ValidationCacheEXT validationCache, const AllocationCallbacks * pAllocator);
using PFN_GetValidationCacheDataEXT = Result (*) (Device device, ValidationCacheEXT validationCache, size_t * pDataSize, void * pData);
using PFN_MergeValidationCachesEXT = Result (*) (Device device, ValidationCacheEXT dstCache, uint32_t srcCacheCount, const ValidationCacheEXT * pSrcCaches);
using PFN_GetDescriptorSetLayoutSupport = void (*) (Device device, const DescriptorSetLayoutCreateInfo * pCreateInfo, DescriptorSetLayoutSupport * pSupport);
using PFN_GetDescriptorSetLayoutSupportKHR = PFN_GetDescriptorSetLayoutSupport;
using PFN_GetShaderInfoAMD = Result (*) (Device device, Pipeline pipeline, ShaderStageFlagBits shaderStage, ShaderInfoTypeAMD infoType, size_t * pInfoSize, void * pInfo);
using PFN_SetLocalDimmingAMD = void (*) (Device device, SwapchainKHR swapChain, Bool32 localDimmingEnable);
using PFN_GetPhysicalDeviceCalibrateableTimeDomainsKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pTimeDomainCount, TimeDomainKHR * pTimeDomains);
using PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT = PFN_GetPhysicalDeviceCalibrateableTimeDomainsKHR;
using PFN_GetCalibratedTimestampsKHR = Result (*) (Device device, uint32_t timestampCount, const CalibratedTimestampInfoKHR * pTimestampInfos, uint64_t * pTimestamps, uint64_t * pMaxDeviation);
using PFN_GetCalibratedTimestampsEXT = PFN_GetCalibratedTimestampsKHR;
using PFN_SetDebugUtilsObjectNameEXT = Result (*) (Device device, const DebugUtilsObjectNameInfoEXT * pNameInfo);
using PFN_SetDebugUtilsObjectTagEXT = Result (*) (Device device, const DebugUtilsObjectTagInfoEXT * pTagInfo);
using PFN_QueueBeginDebugUtilsLabelEXT = void (*) (Queue queue, const DebugUtilsLabelEXT * pLabelInfo);
using PFN_QueueEndDebugUtilsLabelEXT = void (*) (Queue queue);
using PFN_QueueInsertDebugUtilsLabelEXT = void (*) (Queue queue, const DebugUtilsLabelEXT * pLabelInfo);
using PFN_CmdBeginDebugUtilsLabelEXT = void (*) (CommandBuffer commandBuffer, const DebugUtilsLabelEXT * pLabelInfo);
using PFN_CmdEndDebugUtilsLabelEXT = void (*) (CommandBuffer commandBuffer);
using PFN_CmdInsertDebugUtilsLabelEXT = void (*) (CommandBuffer commandBuffer, const DebugUtilsLabelEXT * pLabelInfo);
using PFN_CreateDebugUtilsMessengerEXT = Result (*) (Instance instance, const DebugUtilsMessengerCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, DebugUtilsMessengerEXT * pMessenger);
using PFN_DestroyDebugUtilsMessengerEXT = void (*) (Instance instance, DebugUtilsMessengerEXT messenger, const AllocationCallbacks * pAllocator);
using PFN_SubmitDebugUtilsMessageEXT = void (*) (Instance instance, DebugUtilsMessageSeverityFlagBitsEXT messageSeverity, DebugUtilsMessageTypeFlagsEXT messageTypes, const DebugUtilsMessengerCallbackDataEXT * pCallbackData);
using PFN_GetMemoryHostPointerPropertiesEXT = Result (*) (Device device, ExternalMemoryHandleTypeFlagBits handleType, const void * pHostPointer, MemoryHostPointerPropertiesEXT * pMemoryHostPointerProperties);
using PFN_CmdWriteBufferMarkerAMD = void (*) (CommandBuffer commandBuffer, PipelineStageFlagBits pipelineStage, Buffer dstBuffer, DeviceSize dstOffset, uint32_t marker);
using PFN_CreateRenderPass2 = Result (*) (Device device, const RenderPassCreateInfo2 * pCreateInfo, const AllocationCallbacks * pAllocator, RenderPass * pRenderPass);
using PFN_CreateRenderPass2KHR = PFN_CreateRenderPass2;
using PFN_CmdBeginRenderPass2 = void (*) (CommandBuffer commandBuffer, const RenderPassBeginInfo * pRenderPassBegin, const SubpassBeginInfo * pSubpassBeginInfo);
using PFN_CmdBeginRenderPass2KHR = PFN_CmdBeginRenderPass2;
using PFN_CmdNextSubpass2 = void (*) (CommandBuffer commandBuffer, const SubpassBeginInfo * pSubpassBeginInfo, const SubpassEndInfo * pSubpassEndInfo);
using PFN_CmdNextSubpass2KHR = PFN_CmdNextSubpass2;
using PFN_CmdEndRenderPass2 = void (*) (CommandBuffer commandBuffer, const SubpassEndInfo * pSubpassEndInfo);
using PFN_CmdEndRenderPass2KHR = PFN_CmdEndRenderPass2;
using PFN_GetSemaphoreCounterValue = Result (*) (Device device, Semaphore semaphore, uint64_t * pValue);
using PFN_GetSemaphoreCounterValueKHR = PFN_GetSemaphoreCounterValue;
using PFN_WaitSemaphores = Result (*) (Device device, const SemaphoreWaitInfo * pWaitInfo, uint64_t timeout);
using PFN_WaitSemaphoresKHR = PFN_WaitSemaphores;
using PFN_SignalSemaphore = Result (*) (Device device, const SemaphoreSignalInfo * pSignalInfo);
using PFN_SignalSemaphoreKHR = PFN_SignalSemaphore;
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
using PFN_GetAndroidHardwareBufferPropertiesANDROID = Result (*) (Device device, const struct AHardwareBuffer * buffer, AndroidHardwareBufferPropertiesANDROID * pProperties);
using PFN_GetMemoryAndroidHardwareBufferANDROID = Result (*) (Device device, const MemoryGetAndroidHardwareBufferInfoANDROID * pInfo, struct AHardwareBuffer ** pBuffer);
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
using PFN_CmdDrawIndirectCount = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
using PFN_CmdDrawIndirectCountKHR = PFN_CmdDrawIndirectCount;
using PFN_CmdDrawIndirectCountAMD = PFN_CmdDrawIndirectCount;
using PFN_CmdDrawIndexedIndirectCount = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
using PFN_CmdDrawIndexedIndirectCountKHR = PFN_CmdDrawIndexedIndirectCount;
using PFN_CmdDrawIndexedIndirectCountAMD = PFN_CmdDrawIndexedIndirectCount;
using PFN_CmdSetCheckpointNV = void (*) (CommandBuffer commandBuffer, const void * pCheckpointMarker);
using PFN_GetQueueCheckpointDataNV = void (*) (Queue queue, uint32_t * pCheckpointDataCount, CheckpointDataNV * pCheckpointData);
using PFN_CmdBindTransformFeedbackBuffersEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const Buffer * pBuffers, const DeviceSize * pOffsets, const DeviceSize * pSizes);
using PFN_CmdBeginTransformFeedbackEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const Buffer * pCounterBuffers, const DeviceSize * pCounterBufferOffsets);
using PFN_CmdEndTransformFeedbackEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const Buffer * pCounterBuffers, const DeviceSize * pCounterBufferOffsets);
using PFN_CmdBeginQueryIndexedEXT = void (*) (CommandBuffer commandBuffer, QueryPool queryPool, uint32_t query, QueryControlFlags flags, uint32_t index);
using PFN_CmdEndQueryIndexedEXT = void (*) (CommandBuffer commandBuffer, QueryPool queryPool, uint32_t query, uint32_t index);
using PFN_CmdDrawIndirectByteCountEXT = void (*) (CommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, Buffer counterBuffer, DeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
using PFN_CmdSetExclusiveScissorNV = void (*) (CommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const Rect2D * pExclusiveScissors);
using PFN_CmdSetExclusiveScissorEnableNV = void (*) (CommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const Bool32 * pExclusiveScissorEnables);
using PFN_CmdBindShadingRateImageNV = void (*) (CommandBuffer commandBuffer, ImageView imageView, ImageLayout imageLayout);
using PFN_CmdSetViewportShadingRatePaletteNV = void (*) (CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const ShadingRatePaletteNV * pShadingRatePalettes);
using PFN_CmdSetCoarseSampleOrderNV = void (*) (CommandBuffer commandBuffer, CoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const CoarseSampleOrderCustomNV * pCustomSampleOrders);
using PFN_CmdDrawMeshTasksNV = void (*) (CommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);
using PFN_CmdDrawMeshTasksIndirectNV = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride);
using PFN_CmdDrawMeshTasksIndirectCountNV = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
using PFN_CmdDrawMeshTasksEXT = void (*) (CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
using PFN_CmdDrawMeshTasksIndirectEXT = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride);
using PFN_CmdDrawMeshTasksIndirectCountEXT = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, Buffer countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
using PFN_CompileDeferredNV = Result (*) (Device device, Pipeline pipeline, uint32_t shader);
using PFN_CreateAccelerationStructureNV = Result (*) (Device device, const AccelerationStructureCreateInfoNV * pCreateInfo, const AllocationCallbacks * pAllocator, AccelerationStructureNV * pAccelerationStructure);
using PFN_CmdBindInvocationMaskHUAWEI = void (*) (CommandBuffer commandBuffer, ImageView imageView, ImageLayout imageLayout);
using PFN_DestroyAccelerationStructureKHR = void (*) (Device device, AccelerationStructureKHR accelerationStructure, const AllocationCallbacks * pAllocator);
using PFN_DestroyAccelerationStructureNV = void (*) (Device device, AccelerationStructureNV accelerationStructure, const AllocationCallbacks * pAllocator);
using PFN_GetAccelerationStructureMemoryRequirementsNV = void (*) (Device device, const AccelerationStructureMemoryRequirementsInfoNV * pInfo, MemoryRequirements2KHR * pMemoryRequirements);
using PFN_BindAccelerationStructureMemoryNV = Result (*) (Device device, uint32_t bindInfoCount, const BindAccelerationStructureMemoryInfoNV * pBindInfos);
using PFN_CmdCopyAccelerationStructureNV = void (*) (CommandBuffer commandBuffer, AccelerationStructureNV dst, AccelerationStructureNV src, CopyAccelerationStructureModeKHR mode);
using PFN_CmdCopyAccelerationStructureKHR = void (*) (CommandBuffer commandBuffer, const CopyAccelerationStructureInfoKHR * pInfo);
using PFN_CopyAccelerationStructureKHR = Result (*) (Device device, DeferredOperationKHR deferredOperation, const CopyAccelerationStructureInfoKHR * pInfo);
using PFN_CmdCopyAccelerationStructureToMemoryKHR = void (*) (CommandBuffer commandBuffer, const CopyAccelerationStructureToMemoryInfoKHR * pInfo);
using PFN_CopyAccelerationStructureToMemoryKHR = Result (*) (Device device, DeferredOperationKHR deferredOperation, const CopyAccelerationStructureToMemoryInfoKHR * pInfo);
using PFN_CmdCopyMemoryToAccelerationStructureKHR = void (*) (CommandBuffer commandBuffer, const CopyMemoryToAccelerationStructureInfoKHR * pInfo);
using PFN_CopyMemoryToAccelerationStructureKHR = Result (*) (Device device, DeferredOperationKHR deferredOperation, const CopyMemoryToAccelerationStructureInfoKHR * pInfo);
using PFN_CmdWriteAccelerationStructuresPropertiesKHR = void (*) (CommandBuffer commandBuffer, uint32_t accelerationStructureCount, const AccelerationStructureKHR * pAccelerationStructures, QueryType queryType, QueryPool queryPool, uint32_t firstQuery);
using PFN_CmdWriteAccelerationStructuresPropertiesNV = void (*) (CommandBuffer commandBuffer, uint32_t accelerationStructureCount, const AccelerationStructureNV * pAccelerationStructures, QueryType queryType, QueryPool queryPool, uint32_t firstQuery);
using PFN_CmdBuildAccelerationStructureNV = void (*) (CommandBuffer commandBuffer, const AccelerationStructureInfoNV * pInfo, Buffer instanceData, DeviceSize instanceOffset, Bool32 update, AccelerationStructureNV dst, AccelerationStructureNV src, Buffer scratch, DeviceSize scratchOffset);
using PFN_WriteAccelerationStructuresPropertiesKHR = Result (*) (Device device, uint32_t accelerationStructureCount, const AccelerationStructureKHR * pAccelerationStructures, QueryType queryType, size_t dataSize, void * pData, size_t stride);
using PFN_CmdTraceRaysKHR = void (*) (CommandBuffer commandBuffer, const StridedDeviceAddressRegionKHR * pRaygenShaderBindingTable, const StridedDeviceAddressRegionKHR * pMissShaderBindingTable, const StridedDeviceAddressRegionKHR * pHitShaderBindingTable, const StridedDeviceAddressRegionKHR * pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
using PFN_CmdTraceRaysNV = void (*) (CommandBuffer commandBuffer, Buffer raygenShaderBindingTableBuffer, DeviceSize raygenShaderBindingOffset, Buffer missShaderBindingTableBuffer, DeviceSize missShaderBindingOffset, DeviceSize missShaderBindingStride, Buffer hitShaderBindingTableBuffer, DeviceSize hitShaderBindingOffset, DeviceSize hitShaderBindingStride, Buffer callableShaderBindingTableBuffer, DeviceSize callableShaderBindingOffset, DeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
using PFN_GetRayTracingShaderGroupHandlesKHR = Result (*) (Device device, Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void * pData);
using PFN_GetRayTracingShaderGroupHandlesNV = PFN_GetRayTracingShaderGroupHandlesKHR;
using PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR = Result (*) (Device device, Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void * pData);
using PFN_GetAccelerationStructureHandleNV = Result (*) (Device device, AccelerationStructureNV accelerationStructure, size_t dataSize, void * pData);
using PFN_CreateRayTracingPipelinesNV = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const RayTracingPipelineCreateInfoNV * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CreateRayTracingPipelinesNV = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const RayTracingPipelineCreateInfoNV * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CreateRayTracingPipelinesKHR = Result (*) (Device device, DeferredOperationKHR deferredOperation, PipelineCache pipelineCache, uint32_t createInfoCount, const RayTracingPipelineCreateInfoKHR * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CreateRayTracingPipelinesKHR = Result (*) (Device device, DeferredOperationKHR deferredOperation, PipelineCache pipelineCache, uint32_t createInfoCount, const RayTracingPipelineCreateInfoKHR * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV = Result (*) (PhysicalDevice physicalDevice, uint32_t * pPropertyCount, CooperativeMatrixPropertiesNV * pProperties);
using PFN_CmdTraceRaysIndirectKHR = void (*) (CommandBuffer commandBuffer, const StridedDeviceAddressRegionKHR * pRaygenShaderBindingTable, const StridedDeviceAddressRegionKHR * pMissShaderBindingTable, const StridedDeviceAddressRegionKHR * pHitShaderBindingTable, const StridedDeviceAddressRegionKHR * pCallableShaderBindingTable, DeviceAddress indirectDeviceAddress);
using PFN_CmdTraceRaysIndirect2KHR = void (*) (CommandBuffer commandBuffer, DeviceAddress indirectDeviceAddress);
using PFN_GetDeviceAccelerationStructureCompatibilityKHR = void (*) (Device device, const AccelerationStructureVersionInfoKHR * pVersionInfo, AccelerationStructureCompatibilityKHR * pCompatibility);
using PFN_GetRayTracingShaderGroupStackSizeKHR = VkDeviceSize (*) (Device device, Pipeline pipeline, uint32_t group, ShaderGroupShaderKHR groupShader);
using PFN_CmdSetRayTracingPipelineStackSizeKHR = void (*) (CommandBuffer commandBuffer, uint32_t pipelineStackSize);
using PFN_GetImageViewHandleNVX = uint32_t (*) (Device device, const ImageViewHandleInfoNVX * pInfo);
using PFN_GetImageViewAddressNVX = Result (*) (Device device, ImageView imageView, ImageViewAddressPropertiesNVX * pProperties);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_GetPhysicalDeviceSurfacePresentModes2EXT = Result (*) (PhysicalDevice physicalDevice, const PhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, uint32_t * pPresentModeCount, PresentModeKHR * pPresentModes);
using PFN_GetDeviceGroupSurfacePresentModes2EXT = Result (*) (Device device, const PhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, DeviceGroupPresentModeFlagsKHR * pModes);
using PFN_AcquireFullScreenExclusiveModeEXT = Result (*) (Device device, SwapchainKHR swapchain);
using PFN_ReleaseFullScreenExclusiveModeEXT = Result (*) (Device device, SwapchainKHR swapchain);
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
using PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t * pCounterCount, PerformanceCounterKHR * pCounters, PerformanceCounterDescriptionKHR * pCounterDescriptions);
using PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = void (*) (PhysicalDevice physicalDevice, const QueryPoolPerformanceCreateInfoKHR * pPerformanceQueryCreateInfo, uint32_t * pNumPasses);
using PFN_AcquireProfilingLockKHR = Result (*) (Device device, const AcquireProfilingLockInfoKHR * pInfo);
using PFN_ReleaseProfilingLockKHR = void (*) (Device device);
using PFN_GetImageDrmFormatModifierPropertiesEXT = Result (*) (Device device, Image image, ImageDrmFormatModifierPropertiesEXT * pProperties);
using PFN_GetBufferOpaqueCaptureAddress = uint64_t (*) (Device device, const BufferDeviceAddressInfo * pInfo);
using PFN_GetBufferOpaqueCaptureAddressKHR = PFN_GetBufferOpaqueCaptureAddress;
using PFN_GetBufferDeviceAddress = VkDeviceAddress (*) (Device device, const BufferDeviceAddressInfo * pInfo);
using PFN_GetBufferDeviceAddressKHR = PFN_GetBufferDeviceAddress;
using PFN_GetBufferDeviceAddressEXT = PFN_GetBufferDeviceAddress;
using PFN_CreateHeadlessSurfaceEXT = Result (*) (Instance instance, const HeadlessSurfaceCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, SurfaceKHR * pSurface);
using PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = Result (*) (PhysicalDevice physicalDevice, uint32_t * pCombinationCount, FramebufferMixedSamplesCombinationNV * pCombinations);
using PFN_InitializePerformanceApiINTEL = Result (*) (Device device, const InitializePerformanceApiInfoINTEL * pInitializeInfo);
using PFN_UninitializePerformanceApiINTEL = void (*) (Device device);
using PFN_CmdSetPerformanceMarkerINTEL = Result (*) (CommandBuffer commandBuffer, const PerformanceMarkerInfoINTEL * pMarkerInfo);
using PFN_CmdSetPerformanceStreamMarkerINTEL = Result (*) (CommandBuffer commandBuffer, const PerformanceStreamMarkerInfoINTEL * pMarkerInfo);
using PFN_CmdSetPerformanceOverrideINTEL = Result (*) (CommandBuffer commandBuffer, const PerformanceOverrideInfoINTEL * pOverrideInfo);
using PFN_AcquirePerformanceConfigurationINTEL = Result (*) (Device device, const PerformanceConfigurationAcquireInfoINTEL * pAcquireInfo, PerformanceConfigurationINTEL * pConfiguration);
using PFN_ReleasePerformanceConfigurationINTEL = Result (*) (Device device, PerformanceConfigurationINTEL configuration);
using PFN_QueueSetPerformanceConfigurationINTEL = Result (*) (Queue queue, PerformanceConfigurationINTEL configuration);
using PFN_GetPerformanceParameterINTEL = Result (*) (Device device, PerformanceParameterTypeINTEL parameter, PerformanceValueINTEL * pValue);
using PFN_GetDeviceMemoryOpaqueCaptureAddress = uint64_t (*) (Device device, const DeviceMemoryOpaqueCaptureAddressInfo * pInfo);
using PFN_GetDeviceMemoryOpaqueCaptureAddressKHR = PFN_GetDeviceMemoryOpaqueCaptureAddress;
using PFN_GetPipelineExecutablePropertiesKHR = Result (*) (Device device, const PipelineInfoKHR * pPipelineInfo, uint32_t * pExecutableCount, PipelineExecutablePropertiesKHR * pProperties);
using PFN_GetPipelineExecutableStatisticsKHR = Result (*) (Device device, const PipelineExecutableInfoKHR * pExecutableInfo, uint32_t * pStatisticCount, PipelineExecutableStatisticKHR * pStatistics);
using PFN_GetPipelineExecutableInternalRepresentationsKHR = Result (*) (Device device, const PipelineExecutableInfoKHR * pExecutableInfo, uint32_t * pInternalRepresentationCount, PipelineExecutableInternalRepresentationKHR * pInternalRepresentations);
using PFN_CmdSetLineStippleKHR = void (*) (CommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
using PFN_CmdSetLineStippleEXT = PFN_CmdSetLineStippleKHR;
using PFN_GetPhysicalDeviceToolProperties = Result (*) (PhysicalDevice physicalDevice, uint32_t * pToolCount, PhysicalDeviceToolProperties * pToolProperties);
using PFN_GetPhysicalDeviceToolPropertiesEXT = PFN_GetPhysicalDeviceToolProperties;
using PFN_CreateAccelerationStructureKHR = Result (*) (Device device, const AccelerationStructureCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, AccelerationStructureKHR * pAccelerationStructure);
using PFN_CmdBuildAccelerationStructuresKHR = void (*) (CommandBuffer commandBuffer, uint32_t infoCount, const AccelerationStructureBuildGeometryInfoKHR * pInfos, const AccelerationStructureBuildRangeInfoKHR * const* ppBuildRangeInfos);
using PFN_CmdBuildAccelerationStructuresIndirectKHR = void (*) (CommandBuffer commandBuffer, uint32_t infoCount, const AccelerationStructureBuildGeometryInfoKHR * pInfos, const DeviceAddress * pIndirectDeviceAddresses, const uint32_t * pIndirectStrides, const uint32_t * const* ppMaxPrimitiveCounts);
using PFN_BuildAccelerationStructuresKHR = Result (*) (Device device, DeferredOperationKHR deferredOperation, uint32_t infoCount, const AccelerationStructureBuildGeometryInfoKHR * pInfos, const AccelerationStructureBuildRangeInfoKHR * const* ppBuildRangeInfos);
using PFN_GetAccelerationStructureDeviceAddressKHR = VkDeviceAddress (*) (Device device, const AccelerationStructureDeviceAddressInfoKHR * pInfo);
using PFN_CreateDeferredOperationKHR = Result (*) (Device device, const AllocationCallbacks * pAllocator, DeferredOperationKHR * pDeferredOperation);
using PFN_DestroyDeferredOperationKHR = void (*) (Device device, DeferredOperationKHR operation, const AllocationCallbacks * pAllocator);
using PFN_GetDeferredOperationMaxConcurrencyKHR = uint32_t (*) (Device device, DeferredOperationKHR operation);
using PFN_GetDeferredOperationResultKHR = Result (*) (Device device, DeferredOperationKHR operation);
using PFN_DeferredOperationJoinKHR = Result (*) (Device device, DeferredOperationKHR operation);
using PFN_GetPipelineIndirectMemoryRequirementsNV = void (*) (Device device, const ComputePipelineCreateInfo * pCreateInfo, MemoryRequirements2 * pMemoryRequirements);
using PFN_GetPipelineIndirectDeviceAddressNV = VkDeviceAddress (*) (Device device, const PipelineIndirectDeviceAddressInfoNV * pInfo);
using PFN_CmdSetCullMode = void (*) (CommandBuffer commandBuffer, CullModeFlags cullMode);
using PFN_CmdSetCullModeEXT = PFN_CmdSetCullMode;
using PFN_CmdSetFrontFace = void (*) (CommandBuffer commandBuffer, FrontFace frontFace);
using PFN_CmdSetFrontFaceEXT = PFN_CmdSetFrontFace;
using PFN_CmdSetPrimitiveTopology = void (*) (CommandBuffer commandBuffer, PrimitiveTopology primitiveTopology);
using PFN_CmdSetPrimitiveTopologyEXT = PFN_CmdSetPrimitiveTopology;
using PFN_CmdSetViewportWithCount = void (*) (CommandBuffer commandBuffer, uint32_t viewportCount, const Viewport * pViewports);
using PFN_CmdSetViewportWithCountEXT = PFN_CmdSetViewportWithCount;
using PFN_CmdSetScissorWithCount = void (*) (CommandBuffer commandBuffer, uint32_t scissorCount, const Rect2D * pScissors);
using PFN_CmdSetScissorWithCountEXT = PFN_CmdSetScissorWithCount;
using PFN_CmdBindIndexBuffer2KHR = void (*) (CommandBuffer commandBuffer, Buffer buffer, DeviceSize offset, DeviceSize size, IndexType indexType);
using PFN_CmdBindVertexBuffers2 = void (*) (CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const Buffer * pBuffers, const DeviceSize * pOffsets, const DeviceSize * pSizes, const DeviceSize * pStrides);
using PFN_CmdBindVertexBuffers2EXT = PFN_CmdBindVertexBuffers2;
using PFN_CmdSetDepthTestEnable = void (*) (CommandBuffer commandBuffer, Bool32 depthTestEnable);
using PFN_CmdSetDepthTestEnableEXT = PFN_CmdSetDepthTestEnable;
using PFN_CmdSetDepthWriteEnable = void (*) (CommandBuffer commandBuffer, Bool32 depthWriteEnable);
using PFN_CmdSetDepthWriteEnableEXT = PFN_CmdSetDepthWriteEnable;
using PFN_CmdSetDepthCompareOp = void (*) (CommandBuffer commandBuffer, CompareOp depthCompareOp);
using PFN_CmdSetDepthCompareOpEXT = PFN_CmdSetDepthCompareOp;
using PFN_CmdSetDepthBoundsTestEnable = void (*) (CommandBuffer commandBuffer, Bool32 depthBoundsTestEnable);
using PFN_CmdSetDepthBoundsTestEnableEXT = PFN_CmdSetDepthBoundsTestEnable;
using PFN_CmdSetStencilTestEnable = void (*) (CommandBuffer commandBuffer, Bool32 stencilTestEnable);
using PFN_CmdSetStencilTestEnableEXT = PFN_CmdSetStencilTestEnable;
using PFN_CmdSetStencilOp = void (*) (CommandBuffer commandBuffer, StencilFaceFlags faceMask, StencilOp failOp, StencilOp passOp, StencilOp depthFailOp, CompareOp compareOp);
using PFN_CmdSetStencilOpEXT = PFN_CmdSetStencilOp;
using PFN_CmdSetPatchControlPointsEXT = void (*) (CommandBuffer commandBuffer, uint32_t patchControlPoints);
using PFN_CmdSetRasterizerDiscardEnable = void (*) (CommandBuffer commandBuffer, Bool32 rasterizerDiscardEnable);
using PFN_CmdSetRasterizerDiscardEnableEXT = PFN_CmdSetRasterizerDiscardEnable;
using PFN_CmdSetDepthBiasEnable = void (*) (CommandBuffer commandBuffer, Bool32 depthBiasEnable);
using PFN_CmdSetDepthBiasEnableEXT = PFN_CmdSetDepthBiasEnable;
using PFN_CmdSetLogicOpEXT = void (*) (CommandBuffer commandBuffer, LogicOp logicOp);
using PFN_CmdSetPrimitiveRestartEnable = void (*) (CommandBuffer commandBuffer, Bool32 primitiveRestartEnable);
using PFN_CmdSetPrimitiveRestartEnableEXT = PFN_CmdSetPrimitiveRestartEnable;
using PFN_CmdSetTessellationDomainOriginEXT = void (*) (CommandBuffer commandBuffer, TessellationDomainOrigin domainOrigin);
using PFN_CmdSetDepthClampEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 depthClampEnable);
using PFN_CmdSetPolygonModeEXT = void (*) (CommandBuffer commandBuffer, PolygonMode polygonMode);
using PFN_CmdSetRasterizationSamplesEXT = void (*) (CommandBuffer commandBuffer, SampleCountFlagBits rasterizationSamples);
using PFN_CmdSetSampleMaskEXT = void (*) (CommandBuffer commandBuffer, SampleCountFlagBits samples, const SampleMask * pSampleMask);
using PFN_CmdSetAlphaToCoverageEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 alphaToCoverageEnable);
using PFN_CmdSetAlphaToOneEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 alphaToOneEnable);
using PFN_CmdSetLogicOpEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 logicOpEnable);
using PFN_CmdSetColorBlendEnableEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const Bool32 * pColorBlendEnables);
using PFN_CmdSetColorBlendEquationEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const ColorBlendEquationEXT * pColorBlendEquations);
using PFN_CmdSetColorWriteMaskEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const ColorComponentFlags * pColorWriteMasks);
using PFN_CmdSetRasterizationStreamEXT = void (*) (CommandBuffer commandBuffer, uint32_t rasterizationStream);
using PFN_CmdSetConservativeRasterizationModeEXT = void (*) (CommandBuffer commandBuffer, ConservativeRasterizationModeEXT conservativeRasterizationMode);
using PFN_CmdSetExtraPrimitiveOverestimationSizeEXT = void (*) (CommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);
using PFN_CmdSetDepthClipEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 depthClipEnable);
using PFN_CmdSetSampleLocationsEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 sampleLocationsEnable);
using PFN_CmdSetColorBlendAdvancedEXT = void (*) (CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const ColorBlendAdvancedEXT * pColorBlendAdvanced);
using PFN_CmdSetProvokingVertexModeEXT = void (*) (CommandBuffer commandBuffer, ProvokingVertexModeEXT provokingVertexMode);
using PFN_CmdSetLineRasterizationModeEXT = void (*) (CommandBuffer commandBuffer, LineRasterizationModeEXT lineRasterizationMode);
using PFN_CmdSetLineStippleEnableEXT = void (*) (CommandBuffer commandBuffer, Bool32 stippledLineEnable);
using PFN_CmdSetDepthClipNegativeOneToOneEXT = void (*) (CommandBuffer commandBuffer, Bool32 negativeOneToOne);
using PFN_CmdSetViewportWScalingEnableNV = void (*) (CommandBuffer commandBuffer, Bool32 viewportWScalingEnable);
using PFN_CmdSetViewportSwizzleNV = void (*) (CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const ViewportSwizzleNV * pViewportSwizzles);
using PFN_CmdSetCoverageToColorEnableNV = void (*) (CommandBuffer commandBuffer, Bool32 coverageToColorEnable);
using PFN_CmdSetCoverageToColorLocationNV = void (*) (CommandBuffer commandBuffer, uint32_t coverageToColorLocation);
using PFN_CmdSetCoverageModulationModeNV = void (*) (CommandBuffer commandBuffer, CoverageModulationModeNV coverageModulationMode);
using PFN_CmdSetCoverageModulationTableEnableNV = void (*) (CommandBuffer commandBuffer, Bool32 coverageModulationTableEnable);
using PFN_CmdSetCoverageModulationTableNV = void (*) (CommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float * pCoverageModulationTable);
using PFN_CmdSetShadingRateImageEnableNV = void (*) (CommandBuffer commandBuffer, Bool32 shadingRateImageEnable);
using PFN_CmdSetCoverageReductionModeNV = void (*) (CommandBuffer commandBuffer, CoverageReductionModeNV coverageReductionMode);
using PFN_CmdSetRepresentativeFragmentTestEnableNV = void (*) (CommandBuffer commandBuffer, Bool32 representativeFragmentTestEnable);
using PFN_CreatePrivateDataSlot = Result (*) (Device device, const PrivateDataSlotCreateInfo * pCreateInfo, const AllocationCallbacks * pAllocator, PrivateDataSlot * pPrivateDataSlot);
using PFN_CreatePrivateDataSlotEXT = PFN_CreatePrivateDataSlot;
using PFN_DestroyPrivateDataSlot = void (*) (Device device, PrivateDataSlot privateDataSlot, const AllocationCallbacks * pAllocator);
using PFN_DestroyPrivateDataSlotEXT = PFN_DestroyPrivateDataSlot;
using PFN_SetPrivateData = Result (*) (Device device, ObjectType objectType, uint64_t objectHandle, PrivateDataSlot privateDataSlot, uint64_t data);
using PFN_SetPrivateDataEXT = PFN_SetPrivateData;
using PFN_GetPrivateData = void (*) (Device device, ObjectType objectType, uint64_t objectHandle, PrivateDataSlot privateDataSlot, uint64_t * pData);
using PFN_GetPrivateDataEXT = PFN_GetPrivateData;
using PFN_CmdCopyBuffer2 = void (*) (CommandBuffer commandBuffer, const CopyBufferInfo2 * pCopyBufferInfo);
using PFN_CmdCopyBuffer2KHR = PFN_CmdCopyBuffer2;
using PFN_CmdCopyImage2 = void (*) (CommandBuffer commandBuffer, const CopyImageInfo2 * pCopyImageInfo);
using PFN_CmdCopyImage2KHR = PFN_CmdCopyImage2;
using PFN_CmdBlitImage2 = void (*) (CommandBuffer commandBuffer, const BlitImageInfo2 * pBlitImageInfo);
using PFN_CmdBlitImage2KHR = PFN_CmdBlitImage2;
using PFN_CmdCopyBufferToImage2 = void (*) (CommandBuffer commandBuffer, const CopyBufferToImageInfo2 * pCopyBufferToImageInfo);
using PFN_CmdCopyBufferToImage2KHR = PFN_CmdCopyBufferToImage2;
using PFN_CmdCopyImageToBuffer2 = void (*) (CommandBuffer commandBuffer, const CopyImageToBufferInfo2 * pCopyImageToBufferInfo);
using PFN_CmdCopyImageToBuffer2KHR = PFN_CmdCopyImageToBuffer2;
using PFN_CmdResolveImage2 = void (*) (CommandBuffer commandBuffer, const ResolveImageInfo2 * pResolveImageInfo);
using PFN_CmdResolveImage2KHR = PFN_CmdResolveImage2;
using PFN_CmdSetFragmentShadingRateKHR = void (*) (CommandBuffer commandBuffer, const Extent2D * pFragmentSize, const FragmentShadingRateCombinerOpKHR combinerOps [2]);
using PFN_GetPhysicalDeviceFragmentShadingRatesKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pFragmentShadingRateCount, PhysicalDeviceFragmentShadingRateKHR * pFragmentShadingRates);
using PFN_CmdSetFragmentShadingRateEnumNV = void (*) (CommandBuffer commandBuffer, FragmentShadingRateNV shadingRate, const FragmentShadingRateCombinerOpKHR combinerOps [2]);
using PFN_GetAccelerationStructureBuildSizesKHR = void (*) (Device device, AccelerationStructureBuildTypeKHR buildType, const AccelerationStructureBuildGeometryInfoKHR * pBuildInfo, const uint32_t * pMaxPrimitiveCounts, AccelerationStructureBuildSizesInfoKHR * pSizeInfo);
using PFN_CmdSetVertexInputEXT = void (*) (CommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VertexInputBindingDescription2EXT * pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VertexInputAttributeDescription2EXT * pVertexAttributeDescriptions);
using PFN_CmdSetColorWriteEnableEXT = void (*) (CommandBuffer commandBuffer, uint32_t attachmentCount, const Bool32 * pColorWriteEnables);
using PFN_CmdSetEvent2 = void (*) (CommandBuffer commandBuffer, Event event, const DependencyInfo * pDependencyInfo);
using PFN_CmdSetEvent2KHR = PFN_CmdSetEvent2;
using PFN_CmdResetEvent2 = void (*) (CommandBuffer commandBuffer, Event event, PipelineStageFlags2 stageMask);
using PFN_CmdResetEvent2KHR = PFN_CmdResetEvent2;
using PFN_CmdWaitEvents2 = void (*) (CommandBuffer commandBuffer, uint32_t eventCount, const Event * pEvents, const DependencyInfo * pDependencyInfos);
using PFN_CmdWaitEvents2KHR = PFN_CmdWaitEvents2;
using PFN_CmdPipelineBarrier2 = void (*) (CommandBuffer commandBuffer, const DependencyInfo * pDependencyInfo);
using PFN_CmdPipelineBarrier2KHR = PFN_CmdPipelineBarrier2;
using PFN_QueueSubmit2 = Result (*) (Queue queue, uint32_t submitCount, const SubmitInfo2 * pSubmits, Fence fence);
using PFN_QueueSubmit2KHR = PFN_QueueSubmit2;
using PFN_CmdWriteTimestamp2 = void (*) (CommandBuffer commandBuffer, PipelineStageFlags2 stage, QueryPool queryPool, uint32_t query);
using PFN_CmdWriteTimestamp2KHR = PFN_CmdWriteTimestamp2;
using PFN_CmdWriteBufferMarker2AMD = void (*) (CommandBuffer commandBuffer, PipelineStageFlags2 stage, Buffer dstBuffer, DeviceSize dstOffset, uint32_t marker);
using PFN_GetQueueCheckpointData2NV = void (*) (Queue queue, uint32_t * pCheckpointDataCount, CheckpointData2NV * pCheckpointData);
using PFN_CopyMemoryToImageEXT = Result (*) (Device device, const CopyMemoryToImageInfoEXT * pCopyMemoryToImageInfo);
using PFN_CopyImageToMemoryEXT = Result (*) (Device device, const CopyImageToMemoryInfoEXT * pCopyImageToMemoryInfo);
using PFN_CopyImageToImageEXT = Result (*) (Device device, const CopyImageToImageInfoEXT * pCopyImageToImageInfo);
using PFN_TransitionImageLayoutEXT = Result (*) (Device device, uint32_t transitionCount, const HostImageLayoutTransitionInfoEXT * pTransitions);
using PFN_GetPhysicalDeviceVideoCapabilitiesKHR = Result (*) (PhysicalDevice physicalDevice, const VideoProfileInfoKHR * pVideoProfile, VideoCapabilitiesKHR * pCapabilities);
using PFN_GetPhysicalDeviceVideoFormatPropertiesKHR = Result (*) (PhysicalDevice physicalDevice, const PhysicalDeviceVideoFormatInfoKHR * pVideoFormatInfo, uint32_t * pVideoFormatPropertyCount, VideoFormatPropertiesKHR * pVideoFormatProperties);
using PFN_GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = Result (*) (PhysicalDevice physicalDevice, const PhysicalDeviceVideoEncodeQualityLevelInfoKHR * pQualityLevelInfo, VideoEncodeQualityLevelPropertiesKHR * pQualityLevelProperties);
using PFN_CreateVideoSessionKHR = Result (*) (Device device, const VideoSessionCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, VideoSessionKHR * pVideoSession);
using PFN_DestroyVideoSessionKHR = void (*) (Device device, VideoSessionKHR videoSession, const AllocationCallbacks * pAllocator);
using PFN_CreateVideoSessionParametersKHR = Result (*) (Device device, const VideoSessionParametersCreateInfoKHR * pCreateInfo, const AllocationCallbacks * pAllocator, VideoSessionParametersKHR * pVideoSessionParameters);
using PFN_UpdateVideoSessionParametersKHR = Result (*) (Device device, VideoSessionParametersKHR videoSessionParameters, const VideoSessionParametersUpdateInfoKHR * pUpdateInfo);
using PFN_GetEncodedVideoSessionParametersKHR = Result (*) (Device device, const VideoEncodeSessionParametersGetInfoKHR * pVideoSessionParametersInfo, VideoEncodeSessionParametersFeedbackInfoKHR * pFeedbackInfo, size_t * pDataSize, void * pData);
using PFN_DestroyVideoSessionParametersKHR = void (*) (Device device, VideoSessionParametersKHR videoSessionParameters, const AllocationCallbacks * pAllocator);
using PFN_GetVideoSessionMemoryRequirementsKHR = Result (*) (Device device, VideoSessionKHR videoSession, uint32_t * pMemoryRequirementsCount, VideoSessionMemoryRequirementsKHR * pMemoryRequirements);
using PFN_BindVideoSessionMemoryKHR = Result (*) (Device device, VideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const BindVideoSessionMemoryInfoKHR * pBindSessionMemoryInfos);
using PFN_CmdDecodeVideoKHR = void (*) (CommandBuffer commandBuffer, const VideoDecodeInfoKHR * pDecodeInfo);
using PFN_CmdBeginVideoCodingKHR = void (*) (CommandBuffer commandBuffer, const VideoBeginCodingInfoKHR * pBeginInfo);
using PFN_CmdControlVideoCodingKHR = void (*) (CommandBuffer commandBuffer, const VideoCodingControlInfoKHR * pCodingControlInfo);
using PFN_CmdEndVideoCodingKHR = void (*) (CommandBuffer commandBuffer, const VideoEndCodingInfoKHR * pEndCodingInfo);
using PFN_CmdEncodeVideoKHR = void (*) (CommandBuffer commandBuffer, const VideoEncodeInfoKHR * pEncodeInfo);
using PFN_CmdDecompressMemoryNV = void (*) (CommandBuffer commandBuffer, uint32_t decompressRegionCount, const DecompressMemoryRegionNV * pDecompressMemoryRegions);
using PFN_CmdDecompressMemoryIndirectCountNV = void (*) (CommandBuffer commandBuffer, DeviceAddress indirectCommandsAddress, DeviceAddress indirectCommandsCountAddress, uint32_t stride);
using PFN_CreateCuModuleNVX = Result (*) (Device device, const CuModuleCreateInfoNVX * pCreateInfo, const AllocationCallbacks * pAllocator, CuModuleNVX * pModule);
using PFN_CreateCuFunctionNVX = Result (*) (Device device, const CuFunctionCreateInfoNVX * pCreateInfo, const AllocationCallbacks * pAllocator, CuFunctionNVX * pFunction);
using PFN_DestroyCuModuleNVX = void (*) (Device device, CuModuleNVX module, const AllocationCallbacks * pAllocator);
using PFN_DestroyCuFunctionNVX = void (*) (Device device, CuFunctionNVX function, const AllocationCallbacks * pAllocator);
using PFN_CmdCuLaunchKernelNVX = void (*) (CommandBuffer commandBuffer, const CuLaunchInfoNVX * pLaunchInfo);
using PFN_GetDescriptorSetLayoutSizeEXT = void (*) (Device device, DescriptorSetLayout layout, DeviceSize * pLayoutSizeInBytes);
using PFN_GetDescriptorSetLayoutBindingOffsetEXT = void (*) (Device device, DescriptorSetLayout layout, uint32_t binding, DeviceSize * pOffset);
using PFN_GetDescriptorEXT = void (*) (Device device, const DescriptorGetInfoEXT * pDescriptorInfo, size_t dataSize, void * pDescriptor);
using PFN_CmdBindDescriptorBuffersEXT = void (*) (CommandBuffer commandBuffer, uint32_t bufferCount, const DescriptorBufferBindingInfoEXT * pBindingInfos);
using PFN_CmdSetDescriptorBufferOffsetsEXT = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, PipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t * pBufferIndices, const DeviceSize * pOffsets);
using PFN_CmdBindDescriptorBufferEmbeddedSamplersEXT = void (*) (CommandBuffer commandBuffer, PipelineBindPoint pipelineBindPoint, PipelineLayout layout, uint32_t set);
using PFN_GetBufferOpaqueCaptureDescriptorDataEXT = Result (*) (Device device, const BufferCaptureDescriptorDataInfoEXT * pInfo, void * pData);
using PFN_GetImageOpaqueCaptureDescriptorDataEXT = Result (*) (Device device, const ImageCaptureDescriptorDataInfoEXT * pInfo, void * pData);
using PFN_GetImageViewOpaqueCaptureDescriptorDataEXT = Result (*) (Device device, const ImageViewCaptureDescriptorDataInfoEXT * pInfo, void * pData);
using PFN_GetSamplerOpaqueCaptureDescriptorDataEXT = Result (*) (Device device, const SamplerCaptureDescriptorDataInfoEXT * pInfo, void * pData);
using PFN_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT = Result (*) (Device device, const AccelerationStructureCaptureDescriptorDataInfoEXT * pInfo, void * pData);
using PFN_SetDeviceMemoryPriorityEXT = void (*) (Device device, DeviceMemory memory, float priority);
using PFN_AcquireDrmDisplayEXT = Result (*) (PhysicalDevice physicalDevice, int32_t drmFd, DisplayKHR display);
using PFN_GetDrmDisplayEXT = Result (*) (PhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, DisplayKHR * display);
using PFN_WaitForPresentKHR = Result (*) (Device device, SwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);
#if defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_CreateBufferCollectionFUCHSIA = Result (*) (Device device, const BufferCollectionCreateInfoFUCHSIA * pCreateInfo, const AllocationCallbacks * pAllocator, BufferCollectionFUCHSIA * pCollection);
using PFN_SetBufferCollectionBufferConstraintsFUCHSIA = Result (*) (Device device, BufferCollectionFUCHSIA collection, const BufferConstraintsInfoFUCHSIA * pBufferConstraintsInfo);
using PFN_SetBufferCollectionImageConstraintsFUCHSIA = Result (*) (Device device, BufferCollectionFUCHSIA collection, const ImageConstraintsInfoFUCHSIA * pImageConstraintsInfo);
using PFN_DestroyBufferCollectionFUCHSIA = void (*) (Device device, BufferCollectionFUCHSIA collection, const AllocationCallbacks * pAllocator);
using PFN_GetBufferCollectionPropertiesFUCHSIA = Result (*) (Device device, BufferCollectionFUCHSIA collection, BufferCollectionPropertiesFUCHSIA * pProperties);
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
using PFN_CreateCudaModuleNV = Result (*) (Device device, const CudaModuleCreateInfoNV * pCreateInfo, const AllocationCallbacks * pAllocator, CudaModuleNV * pModule);
using PFN_GetCudaModuleCacheNV = Result (*) (Device device, CudaModuleNV module, size_t * pCacheSize, void * pCacheData);
using PFN_CreateCudaFunctionNV = Result (*) (Device device, const CudaFunctionCreateInfoNV * pCreateInfo, const AllocationCallbacks * pAllocator, CudaFunctionNV * pFunction);
using PFN_DestroyCudaModuleNV = void (*) (Device device, CudaModuleNV module, const AllocationCallbacks * pAllocator);
using PFN_DestroyCudaFunctionNV = void (*) (Device device, CudaFunctionNV function, const AllocationCallbacks * pAllocator);
using PFN_CmdCudaLaunchKernelNV = void (*) (CommandBuffer commandBuffer, const CudaLaunchInfoNV * pLaunchInfo);
using PFN_CmdBeginRendering = void (*) (CommandBuffer commandBuffer, const RenderingInfo * pRenderingInfo);
using PFN_CmdBeginRenderingKHR = PFN_CmdBeginRendering;
using PFN_CmdEndRendering = void (*) (CommandBuffer commandBuffer);
using PFN_CmdEndRenderingKHR = PFN_CmdEndRendering;
using PFN_GetDescriptorSetLayoutHostMappingInfoVALVE = void (*) (Device device, const DescriptorSetBindingReferenceVALVE * pBindingReference, DescriptorSetLayoutHostMappingInfoVALVE * pHostMapping);
using PFN_GetDescriptorSetHostMappingVALVE = void (*) (Device device, DescriptorSet descriptorSet, void ** ppData);
using PFN_CreateMicromapEXT = Result (*) (Device device, const MicromapCreateInfoEXT * pCreateInfo, const AllocationCallbacks * pAllocator, MicromapEXT * pMicromap);
using PFN_CmdBuildMicromapsEXT = void (*) (CommandBuffer commandBuffer, uint32_t infoCount, const MicromapBuildInfoEXT * pInfos);
using PFN_BuildMicromapsEXT = Result (*) (Device device, DeferredOperationKHR deferredOperation, uint32_t infoCount, const MicromapBuildInfoEXT * pInfos);
using PFN_DestroyMicromapEXT = void (*) (Device device, MicromapEXT micromap, const AllocationCallbacks * pAllocator);
using PFN_CmdCopyMicromapEXT = void (*) (CommandBuffer commandBuffer, const CopyMicromapInfoEXT * pInfo);
using PFN_CopyMicromapEXT = Result (*) (Device device, DeferredOperationKHR deferredOperation, const CopyMicromapInfoEXT * pInfo);
using PFN_CmdCopyMicromapToMemoryEXT = void (*) (CommandBuffer commandBuffer, const CopyMicromapToMemoryInfoEXT * pInfo);
using PFN_CopyMicromapToMemoryEXT = Result (*) (Device device, DeferredOperationKHR deferredOperation, const CopyMicromapToMemoryInfoEXT * pInfo);
using PFN_CmdCopyMemoryToMicromapEXT = void (*) (CommandBuffer commandBuffer, const CopyMemoryToMicromapInfoEXT * pInfo);
using PFN_CopyMemoryToMicromapEXT = Result (*) (Device device, DeferredOperationKHR deferredOperation, const CopyMemoryToMicromapInfoEXT * pInfo);
using PFN_CmdWriteMicromapsPropertiesEXT = void (*) (CommandBuffer commandBuffer, uint32_t micromapCount, const MicromapEXT * pMicromaps, QueryType queryType, QueryPool queryPool, uint32_t firstQuery);
using PFN_WriteMicromapsPropertiesEXT = Result (*) (Device device, uint32_t micromapCount, const MicromapEXT * pMicromaps, QueryType queryType, size_t dataSize, void * pData, size_t stride);
using PFN_GetDeviceMicromapCompatibilityEXT = void (*) (Device device, const MicromapVersionInfoEXT * pVersionInfo, AccelerationStructureCompatibilityKHR * pCompatibility);
using PFN_GetMicromapBuildSizesEXT = void (*) (Device device, AccelerationStructureBuildTypeKHR buildType, const MicromapBuildInfoEXT * pBuildInfo, MicromapBuildSizesInfoEXT * pSizeInfo);
using PFN_GetShaderModuleIdentifierEXT = void (*) (Device device, ShaderModule shaderModule, ShaderModuleIdentifierEXT * pIdentifier);
using PFN_GetShaderModuleCreateInfoIdentifierEXT = void (*) (Device device, const ShaderModuleCreateInfo * pCreateInfo, ShaderModuleIdentifierEXT * pIdentifier);
using PFN_GetImageSubresourceLayout2KHR = void (*) (Device device, Image image, const ImageSubresource2KHR * pSubresource, SubresourceLayout2KHR * pLayout);
using PFN_GetImageSubresourceLayout2EXT = PFN_GetImageSubresourceLayout2KHR;
using PFN_GetPipelinePropertiesEXT = Result (*) (Device device, const PipelineInfoEXT * pPipelineInfo, BaseOutStructure * pPipelineProperties);
#if defined(VK_USE_PLATFORM_METAL_EXT)
using PFN_ExportMetalObjectsEXT = void (*) (Device device, ExportMetalObjectsInfoEXT * pMetalObjectsInfo);
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
using PFN_GetFramebufferTilePropertiesQCOM = Result (*) (Device device, Framebuffer framebuffer, uint32_t * pPropertiesCount, TilePropertiesQCOM * pProperties);
using PFN_GetDynamicRenderingTilePropertiesQCOM = Result (*) (Device device, const RenderingInfo * pRenderingInfo, TilePropertiesQCOM * pProperties);
using PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV = Result (*) (PhysicalDevice physicalDevice, const OpticalFlowImageFormatInfoNV * pOpticalFlowImageFormatInfo, uint32_t * pFormatCount, OpticalFlowImageFormatPropertiesNV * pImageFormatProperties);
using PFN_CreateOpticalFlowSessionNV = Result (*) (Device device, const OpticalFlowSessionCreateInfoNV * pCreateInfo, const AllocationCallbacks * pAllocator, OpticalFlowSessionNV * pSession);
using PFN_DestroyOpticalFlowSessionNV = void (*) (Device device, OpticalFlowSessionNV session, const AllocationCallbacks * pAllocator);
using PFN_BindOpticalFlowSessionImageNV = Result (*) (Device device, OpticalFlowSessionNV session, OpticalFlowSessionBindingPointNV bindingPoint, ImageView view, ImageLayout layout);
using PFN_CmdOpticalFlowExecuteNV = void (*) (CommandBuffer commandBuffer, OpticalFlowSessionNV session, const OpticalFlowExecuteInfoNV * pExecuteInfo);
using PFN_GetDeviceFaultInfoEXT = Result (*) (Device device, DeviceFaultCountsEXT * pFaultCounts, DeviceFaultInfoEXT * pFaultInfo);
using PFN_CmdSetDepthBias2EXT = void (*) (CommandBuffer commandBuffer, const DepthBiasInfoEXT * pDepthBiasInfo);
using PFN_ReleaseSwapchainImagesEXT = Result (*) (Device device, const ReleaseSwapchainImagesInfoEXT * pReleaseInfo);
using PFN_GetDeviceImageSubresourceLayoutKHR = void (*) (Device device, const DeviceImageSubresourceInfoKHR * pInfo, SubresourceLayout2KHR * pLayout);
using PFN_MapMemory2KHR = Result (*) (Device device, const MemoryMapInfoKHR * pMemoryMapInfo, void ** ppData);
using PFN_UnmapMemory2KHR = Result (*) (Device device, const MemoryUnmapInfoKHR * pMemoryUnmapInfo);
using PFN_CreateShadersEXT = Result (*) (Device device, uint32_t createInfoCount, const ShaderCreateInfoEXT * pCreateInfos, const AllocationCallbacks * pAllocator, ShaderEXT * pShaders);
using PFN_DestroyShaderEXT = void (*) (Device device, ShaderEXT shader, const AllocationCallbacks * pAllocator);
using PFN_GetShaderBinaryDataEXT = Result (*) (Device device, ShaderEXT shader, size_t * pDataSize, void * pData);
using PFN_CmdBindShadersEXT = void (*) (CommandBuffer commandBuffer, uint32_t stageCount, const ShaderStageFlagBits * pStages, const ShaderEXT * pShaders);
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
using PFN_GetScreenBufferPropertiesQNX = Result (*) (Device device, const struct _screen_buffer * buffer, ScreenBufferPropertiesQNX * pProperties);
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
using PFN_GetPhysicalDeviceCooperativeMatrixPropertiesKHR = Result (*) (PhysicalDevice physicalDevice, uint32_t * pPropertyCount, CooperativeMatrixPropertiesKHR * pProperties);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
using PFN_GetExecutionGraphPipelineScratchSizeAMDX = Result (*) (Device device, Pipeline executionGraph, ExecutionGraphPipelineScratchSizeAMDX * pSizeInfo);
using PFN_GetExecutionGraphPipelineNodeIndexAMDX = Result (*) (Device device, Pipeline executionGraph, const PipelineShaderStageNodeCreateInfoAMDX * pNodeInfo, uint32_t * pNodeIndex);
using PFN_CreateExecutionGraphPipelinesAMDX = Result (*) (Device device, PipelineCache pipelineCache, uint32_t createInfoCount, const ExecutionGraphPipelineCreateInfoAMDX * pCreateInfos, const AllocationCallbacks * pAllocator, Pipeline * pPipelines);
using PFN_CmdInitializeGraphScratchMemoryAMDX = void (*) (CommandBuffer commandBuffer, DeviceAddress scratch);
using PFN_CmdDispatchGraphAMDX = void (*) (CommandBuffer commandBuffer, DeviceAddress scratch, const DispatchGraphCountInfoAMDX * pCountInfo);
using PFN_CmdDispatchGraphIndirectAMDX = void (*) (CommandBuffer commandBuffer, DeviceAddress scratch, const DispatchGraphCountInfoAMDX * pCountInfo);
using PFN_CmdDispatchGraphIndirectCountAMDX = void (*) (CommandBuffer commandBuffer, DeviceAddress scratch, DeviceAddress countInfo);
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
using PFN_CmdBindDescriptorSets2KHR = void (*) (CommandBuffer commandBuffer, const BindDescriptorSetsInfoKHR * pBindDescriptorSetsInfo);
using PFN_CmdPushConstants2KHR = void (*) (CommandBuffer commandBuffer, const PushConstantsInfoKHR * pPushConstantsInfo);
using PFN_CmdPushDescriptorSet2KHR = void (*) (CommandBuffer commandBuffer, const PushDescriptorSetInfoKHR * pPushDescriptorSetInfo);
using PFN_CmdPushDescriptorSetWithTemplate2KHR = void (*) (CommandBuffer commandBuffer, const PushDescriptorSetWithTemplateInfoKHR * pPushDescriptorSetWithTemplateInfo);
using PFN_CmdSetDescriptorBufferOffsets2EXT = void (*) (CommandBuffer commandBuffer, const SetDescriptorBufferOffsetsInfoEXT * pSetDescriptorBufferOffsetsInfo);
using PFN_CmdBindDescriptorBufferEmbeddedSamplers2EXT = void (*) (CommandBuffer commandBuffer, const BindDescriptorBufferEmbeddedSamplersInfoEXT * pBindDescriptorBufferEmbeddedSamplersInfo);
using PFN_SetLatencySleepModeNV = Result (*) (Device device, SwapchainKHR swapchain, const LatencySleepModeInfoNV * pSleepModeInfo);
using PFN_LatencySleepNV = Result (*) (Device device, SwapchainKHR swapchain, const LatencySleepInfoNV * pSleepInfo);
using PFN_SetLatencyMarkerNV = void (*) (Device device, SwapchainKHR swapchain, const SetLatencyMarkerInfoNV * pLatencyMarkerInfo);
using PFN_GetLatencyTimingsNV = void (*) (Device device, SwapchainKHR swapchain, GetLatencyMarkerInfoNV * pLatencyMarkerInfo);
using PFN_QueueNotifyOutOfBandNV = void (*) (Queue queue, const OutOfBandQueueTypeInfoNV * pQueueTypeInfo);
using PFN_CmdSetRenderingAttachmentLocationsKHR = void (*) (CommandBuffer commandBuffer, const RenderingAttachmentLocationInfoKHR * pLocationInfo);
using PFN_CmdSetRenderingInputAttachmentIndicesKHR = void (*) (CommandBuffer commandBuffer, const RenderingInputAttachmentIndexInfoKHR * pLocationInfo);
struct GlobalDispatchTable {
    PFN_CreateInstance CreateInstance = nullptr;
    PFN_GetInstanceProcAddr GetInstanceProcAddr = nullptr;
    PFN_EnumerateInstanceExtensionProperties EnumerateInstanceExtensionProperties = nullptr;
    PFN_EnumerateInstanceLayerProperties EnumerateInstanceLayerProperties = nullptr;
    PFN_EnumerateInstanceVersion EnumerateInstanceVersion = nullptr;
};
struct InstanceDispatchTable {
    PFN_DestroyInstance DestroyInstance = nullptr;
    PFN_EnumeratePhysicalDevices EnumeratePhysicalDevices = nullptr;
    PFN_GetDeviceProcAddr GetDeviceProcAddr = nullptr;
    PFN_GetInstanceProcAddr GetInstanceProcAddr = nullptr;
    PFN_GetPhysicalDeviceProperties GetPhysicalDeviceProperties = nullptr;
    PFN_GetPhysicalDeviceQueueFamilyProperties GetPhysicalDeviceQueueFamilyProperties = nullptr;
    PFN_GetPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties = nullptr;
    PFN_GetPhysicalDeviceFeatures GetPhysicalDeviceFeatures = nullptr;
    PFN_GetPhysicalDeviceFormatProperties GetPhysicalDeviceFormatProperties = nullptr;
    PFN_GetPhysicalDeviceImageFormatProperties GetPhysicalDeviceImageFormatProperties = nullptr;
    PFN_CreateDevice CreateDevice = nullptr;
    PFN_EnumerateDeviceExtensionProperties EnumerateDeviceExtensionProperties = nullptr;
    PFN_GetPhysicalDeviceSparseImageFormatProperties GetPhysicalDeviceSparseImageFormatProperties = nullptr;
    PFN_EnumeratePhysicalDeviceGroups EnumeratePhysicalDeviceGroups = nullptr;
    PFN_GetPhysicalDeviceFeatures2 GetPhysicalDeviceFeatures2 = nullptr;
    PFN_GetPhysicalDeviceProperties2 GetPhysicalDeviceProperties2 = nullptr;
    PFN_GetPhysicalDeviceFormatProperties2 GetPhysicalDeviceFormatProperties2 = nullptr;
    PFN_GetPhysicalDeviceImageFormatProperties2 GetPhysicalDeviceImageFormatProperties2 = nullptr;
    PFN_GetPhysicalDeviceQueueFamilyProperties2 GetPhysicalDeviceQueueFamilyProperties2 = nullptr;
    PFN_GetPhysicalDeviceMemoryProperties2 GetPhysicalDeviceMemoryProperties2 = nullptr;
    PFN_GetPhysicalDeviceSparseImageFormatProperties2 GetPhysicalDeviceSparseImageFormatProperties2 = nullptr;
    PFN_GetPhysicalDeviceExternalBufferProperties GetPhysicalDeviceExternalBufferProperties = nullptr;
    PFN_GetPhysicalDeviceExternalFenceProperties GetPhysicalDeviceExternalFenceProperties = nullptr;
    PFN_GetPhysicalDeviceExternalSemaphoreProperties GetPhysicalDeviceExternalSemaphoreProperties = nullptr;
    PFN_GetPhysicalDeviceToolProperties GetPhysicalDeviceToolProperties = nullptr;
    PFN_DestroySurfaceKHR DestroySurfaceKHR = nullptr;
    PFN_GetPhysicalDeviceSurfaceSupportKHR GetPhysicalDeviceSurfaceSupportKHR = nullptr;
    PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR GetPhysicalDeviceSurfaceCapabilitiesKHR = nullptr;
    PFN_GetPhysicalDeviceSurfaceFormatsKHR GetPhysicalDeviceSurfaceFormatsKHR = nullptr;
    PFN_GetPhysicalDeviceSurfacePresentModesKHR GetPhysicalDeviceSurfacePresentModesKHR = nullptr;
    PFN_GetPhysicalDevicePresentRectanglesKHR GetPhysicalDevicePresentRectanglesKHR = nullptr;
    PFN_GetPhysicalDeviceDisplayPropertiesKHR GetPhysicalDeviceDisplayPropertiesKHR = nullptr;
    PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR GetPhysicalDeviceDisplayPlanePropertiesKHR = nullptr;
    PFN_GetDisplayPlaneSupportedDisplaysKHR GetDisplayPlaneSupportedDisplaysKHR = nullptr;
    PFN_GetDisplayModePropertiesKHR GetDisplayModePropertiesKHR = nullptr;
    PFN_CreateDisplayModeKHR CreateDisplayModeKHR = nullptr;
    PFN_GetDisplayPlaneCapabilitiesKHR GetDisplayPlaneCapabilitiesKHR = nullptr;
    PFN_CreateDisplayPlaneSurfaceKHR CreateDisplayPlaneSurfaceKHR = nullptr;
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    PFN_CreateXlibSurfaceKHR CreateXlibSurfaceKHR = nullptr;
#else
    void* z_padding_CreateXlibSurfaceKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    PFN_GetPhysicalDeviceXlibPresentationSupportKHR GetPhysicalDeviceXlibPresentationSupportKHR = nullptr;
#else
    void* z_padding_GetPhysicalDeviceXlibPresentationSupportKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_XLIB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
    PFN_CreateXcbSurfaceKHR CreateXcbSurfaceKHR = nullptr;
#else
    void* z_padding_CreateXcbSurfaceKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_XCB_KHR)
    PFN_GetPhysicalDeviceXcbPresentationSupportKHR GetPhysicalDeviceXcbPresentationSupportKHR = nullptr;
#else
    void* z_padding_GetPhysicalDeviceXcbPresentationSupportKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_XCB_KHR)
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    PFN_CreateWaylandSurfaceKHR CreateWaylandSurfaceKHR = nullptr;
#else
    void* z_padding_CreateWaylandSurfaceKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    PFN_GetPhysicalDeviceWaylandPresentationSupportKHR GetPhysicalDeviceWaylandPresentationSupportKHR = nullptr;
#else
    void* z_padding_GetPhysicalDeviceWaylandPresentationSupportKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WAYLAND_KHR)
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    PFN_CreateAndroidSurfaceKHR CreateAndroidSurfaceKHR = nullptr;
#else
    void* z_padding_CreateAndroidSurfaceKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_CreateWin32SurfaceKHR CreateWin32SurfaceKHR = nullptr;
#else
    void* z_padding_CreateWin32SurfaceKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetPhysicalDeviceWin32PresentationSupportKHR GetPhysicalDeviceWin32PresentationSupportKHR = nullptr;
#else
    void* z_padding_GetPhysicalDeviceWin32PresentationSupportKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_CreateDebugReportCallbackEXT CreateDebugReportCallbackEXT = nullptr;
    PFN_DestroyDebugReportCallbackEXT DestroyDebugReportCallbackEXT = nullptr;
    PFN_DebugReportMessageEXT DebugReportMessageEXT = nullptr;
    PFN_GetPhysicalDeviceVideoCapabilitiesKHR GetPhysicalDeviceVideoCapabilitiesKHR = nullptr;
    PFN_GetPhysicalDeviceVideoFormatPropertiesKHR GetPhysicalDeviceVideoFormatPropertiesKHR = nullptr;
#if defined(VK_USE_PLATFORM_GGP)
    PFN_CreateStreamDescriptorSurfaceGGP CreateStreamDescriptorSurfaceGGP = nullptr;
#else
    void* z_padding_CreateStreamDescriptorSurfaceGGP = nullptr;
#endif // defined(VK_USE_PLATFORM_GGP)
    PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV GetPhysicalDeviceExternalImageFormatPropertiesNV = nullptr;
#if defined(VK_USE_PLATFORM_VI_NN)
    PFN_CreateViSurfaceNN CreateViSurfaceNN = nullptr;
#else
    void* z_padding_CreateViSurfaceNN = nullptr;
#endif // defined(VK_USE_PLATFORM_VI_NN)
    PFN_ReleaseDisplayEXT ReleaseDisplayEXT = nullptr;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    PFN_AcquireXlibDisplayEXT AcquireXlibDisplayEXT = nullptr;
#else
    void* z_padding_AcquireXlibDisplayEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    PFN_GetRandROutputDisplayEXT GetRandROutputDisplayEXT = nullptr;
#else
    void* z_padding_GetRandROutputDisplayEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    PFN_GetPhysicalDeviceSurfaceCapabilities2EXT GetPhysicalDeviceSurfaceCapabilities2EXT = nullptr;
    PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = nullptr;
    PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = nullptr;
    PFN_GetPhysicalDeviceSurfaceCapabilities2KHR GetPhysicalDeviceSurfaceCapabilities2KHR = nullptr;
    PFN_GetPhysicalDeviceSurfaceFormats2KHR GetPhysicalDeviceSurfaceFormats2KHR = nullptr;
    PFN_GetPhysicalDeviceDisplayProperties2KHR GetPhysicalDeviceDisplayProperties2KHR = nullptr;
    PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR GetPhysicalDeviceDisplayPlaneProperties2KHR = nullptr;
    PFN_GetDisplayModeProperties2KHR GetDisplayModeProperties2KHR = nullptr;
    PFN_GetDisplayPlaneCapabilities2KHR GetDisplayPlaneCapabilities2KHR = nullptr;
#if defined(VK_USE_PLATFORM_IOS_MVK)
    PFN_CreateIOSSurfaceMVK CreateIOSSurfaceMVK = nullptr;
#else
    void* z_padding_CreateIOSSurfaceMVK = nullptr;
#endif // defined(VK_USE_PLATFORM_IOS_MVK)
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    PFN_CreateMacOSSurfaceMVK CreateMacOSSurfaceMVK = nullptr;
#else
    void* z_padding_CreateMacOSSurfaceMVK = nullptr;
#endif // defined(VK_USE_PLATFORM_MACOS_MVK)
    PFN_CreateDebugUtilsMessengerEXT CreateDebugUtilsMessengerEXT = nullptr;
    PFN_DestroyDebugUtilsMessengerEXT DestroyDebugUtilsMessengerEXT = nullptr;
    PFN_SubmitDebugUtilsMessageEXT SubmitDebugUtilsMessageEXT = nullptr;
    PFN_GetPhysicalDeviceMultisamplePropertiesEXT GetPhysicalDeviceMultisamplePropertiesEXT = nullptr;
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_CreateImagePipeSurfaceFUCHSIA CreateImagePipeSurfaceFUCHSIA = nullptr;
#else
    void* z_padding_CreateImagePipeSurfaceFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_METAL_EXT)
    PFN_CreateMetalSurfaceEXT CreateMetalSurfaceEXT = nullptr;
#else
    void* z_padding_CreateMetalSurfaceEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
    PFN_GetPhysicalDeviceFragmentShadingRatesKHR GetPhysicalDeviceFragmentShadingRatesKHR = nullptr;
    PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV GetPhysicalDeviceCooperativeMatrixPropertiesNV = nullptr;
    PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = nullptr;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetPhysicalDeviceSurfacePresentModes2EXT GetPhysicalDeviceSurfacePresentModes2EXT = nullptr;
#else
    void* z_padding_GetPhysicalDeviceSurfacePresentModes2EXT = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_CreateHeadlessSurfaceEXT CreateHeadlessSurfaceEXT = nullptr;
    PFN_AcquireDrmDisplayEXT AcquireDrmDisplayEXT = nullptr;
    PFN_GetDrmDisplayEXT GetDrmDisplayEXT = nullptr;
    PFN_GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = nullptr;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_AcquireWinrtDisplayNV AcquireWinrtDisplayNV = nullptr;
#else
    void* z_padding_AcquireWinrtDisplayNV = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetWinrtDisplayNV GetWinrtDisplayNV = nullptr;
#else
    void* z_padding_GetWinrtDisplayNV = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    PFN_CreateDirectFBSurfaceEXT CreateDirectFBSurfaceEXT = nullptr;
#else
    void* z_padding_CreateDirectFBSurfaceEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT GetPhysicalDeviceDirectFBPresentationSupportEXT = nullptr;
#else
    void* z_padding_GetPhysicalDeviceDirectFBPresentationSupportEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    PFN_CreateScreenSurfaceQNX CreateScreenSurfaceQNX = nullptr;
#else
    void* z_padding_CreateScreenSurfaceQNX = nullptr;
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    PFN_GetPhysicalDeviceScreenPresentationSupportQNX GetPhysicalDeviceScreenPresentationSupportQNX = nullptr;
#else
    void* z_padding_GetPhysicalDeviceScreenPresentationSupportQNX = nullptr;
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
    PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV GetPhysicalDeviceOpticalFlowImageFormatsNV = nullptr;
    PFN_GetPhysicalDeviceCooperativeMatrixPropertiesKHR GetPhysicalDeviceCooperativeMatrixPropertiesKHR = nullptr;
    PFN_GetPhysicalDeviceCalibrateableTimeDomainsKHR GetPhysicalDeviceCalibrateableTimeDomainsKHR = nullptr;
};
struct DeviceDispatchTable {
    PFN_DestroyDevice DestroyDevice = nullptr;
    PFN_GetDeviceQueue GetDeviceQueue = nullptr;
    PFN_QueueSubmit QueueSubmit = nullptr;
    PFN_QueueWaitIdle QueueWaitIdle = nullptr;
    PFN_DeviceWaitIdle DeviceWaitIdle = nullptr;
    PFN_AllocateMemory AllocateMemory = nullptr;
    PFN_FreeMemory FreeMemory = nullptr;
    PFN_MapMemory MapMemory = nullptr;
    PFN_UnmapMemory UnmapMemory = nullptr;
    PFN_FlushMappedMemoryRanges FlushMappedMemoryRanges = nullptr;
    PFN_InvalidateMappedMemoryRanges InvalidateMappedMemoryRanges = nullptr;
    PFN_GetDeviceMemoryCommitment GetDeviceMemoryCommitment = nullptr;
    PFN_GetBufferMemoryRequirements GetBufferMemoryRequirements = nullptr;
    PFN_BindBufferMemory BindBufferMemory = nullptr;
    PFN_GetImageMemoryRequirements GetImageMemoryRequirements = nullptr;
    PFN_BindImageMemory BindImageMemory = nullptr;
    PFN_GetImageSparseMemoryRequirements GetImageSparseMemoryRequirements = nullptr;
    PFN_QueueBindSparse QueueBindSparse = nullptr;
    PFN_CreateFence CreateFence = nullptr;
    PFN_DestroyFence DestroyFence = nullptr;
    PFN_ResetFences ResetFences = nullptr;
    PFN_GetFenceStatus GetFenceStatus = nullptr;
    PFN_WaitForFences WaitForFences = nullptr;
    PFN_CreateSemaphore CreateSemaphore = nullptr;
    PFN_DestroySemaphore DestroySemaphore = nullptr;
    PFN_CreateEvent CreateEvent = nullptr;
    PFN_DestroyEvent DestroyEvent = nullptr;
    PFN_GetEventStatus GetEventStatus = nullptr;
    PFN_SetEvent SetEvent = nullptr;
    PFN_ResetEvent ResetEvent = nullptr;
    PFN_CreateQueryPool CreateQueryPool = nullptr;
    PFN_DestroyQueryPool DestroyQueryPool = nullptr;
    PFN_GetQueryPoolResults GetQueryPoolResults = nullptr;
    PFN_CreateBuffer CreateBuffer = nullptr;
    PFN_DestroyBuffer DestroyBuffer = nullptr;
    PFN_CreateBufferView CreateBufferView = nullptr;
    PFN_DestroyBufferView DestroyBufferView = nullptr;
    PFN_CreateImage CreateImage = nullptr;
    PFN_DestroyImage DestroyImage = nullptr;
    PFN_GetImageSubresourceLayout GetImageSubresourceLayout = nullptr;
    PFN_CreateImageView CreateImageView = nullptr;
    PFN_DestroyImageView DestroyImageView = nullptr;
    PFN_CreateShaderModule CreateShaderModule = nullptr;
    PFN_DestroyShaderModule DestroyShaderModule = nullptr;
    PFN_CreatePipelineCache CreatePipelineCache = nullptr;
    PFN_DestroyPipelineCache DestroyPipelineCache = nullptr;
    PFN_GetPipelineCacheData GetPipelineCacheData = nullptr;
    PFN_MergePipelineCaches MergePipelineCaches = nullptr;
    PFN_CreateGraphicsPipelines CreateGraphicsPipelines = nullptr;
    PFN_CreateComputePipelines CreateComputePipelines = nullptr;
    PFN_DestroyPipeline DestroyPipeline = nullptr;
    PFN_CreatePipelineLayout CreatePipelineLayout = nullptr;
    PFN_DestroyPipelineLayout DestroyPipelineLayout = nullptr;
    PFN_CreateSampler CreateSampler = nullptr;
    PFN_DestroySampler DestroySampler = nullptr;
    PFN_CreateDescriptorSetLayout CreateDescriptorSetLayout = nullptr;
    PFN_DestroyDescriptorSetLayout DestroyDescriptorSetLayout = nullptr;
    PFN_CreateDescriptorPool CreateDescriptorPool = nullptr;
    PFN_DestroyDescriptorPool DestroyDescriptorPool = nullptr;
    PFN_ResetDescriptorPool ResetDescriptorPool = nullptr;
    PFN_AllocateDescriptorSets AllocateDescriptorSets = nullptr;
    PFN_FreeDescriptorSets FreeDescriptorSets = nullptr;
    PFN_UpdateDescriptorSets UpdateDescriptorSets = nullptr;
    PFN_CreateFramebuffer CreateFramebuffer = nullptr;
    PFN_DestroyFramebuffer DestroyFramebuffer = nullptr;
    PFN_CreateRenderPass CreateRenderPass = nullptr;
    PFN_DestroyRenderPass DestroyRenderPass = nullptr;
    PFN_GetRenderAreaGranularity GetRenderAreaGranularity = nullptr;
    PFN_CreateCommandPool CreateCommandPool = nullptr;
    PFN_DestroyCommandPool DestroyCommandPool = nullptr;
    PFN_ResetCommandPool ResetCommandPool = nullptr;
    PFN_AllocateCommandBuffers AllocateCommandBuffers = nullptr;
    PFN_FreeCommandBuffers FreeCommandBuffers = nullptr;
    PFN_BeginCommandBuffer BeginCommandBuffer = nullptr;
    PFN_EndCommandBuffer EndCommandBuffer = nullptr;
    PFN_ResetCommandBuffer ResetCommandBuffer = nullptr;
    PFN_CmdBindPipeline CmdBindPipeline = nullptr;
    PFN_CmdSetViewport CmdSetViewport = nullptr;
    PFN_CmdSetScissor CmdSetScissor = nullptr;
    PFN_CmdSetLineWidth CmdSetLineWidth = nullptr;
    PFN_CmdSetDepthBias CmdSetDepthBias = nullptr;
    PFN_CmdSetBlendConstants CmdSetBlendConstants = nullptr;
    PFN_CmdSetDepthBounds CmdSetDepthBounds = nullptr;
    PFN_CmdSetStencilCompareMask CmdSetStencilCompareMask = nullptr;
    PFN_CmdSetStencilWriteMask CmdSetStencilWriteMask = nullptr;
    PFN_CmdSetStencilReference CmdSetStencilReference = nullptr;
    PFN_CmdBindDescriptorSets CmdBindDescriptorSets = nullptr;
    PFN_CmdBindIndexBuffer CmdBindIndexBuffer = nullptr;
    PFN_CmdBindVertexBuffers CmdBindVertexBuffers = nullptr;
    PFN_CmdDraw CmdDraw = nullptr;
    PFN_CmdDrawIndexed CmdDrawIndexed = nullptr;
    PFN_CmdDrawIndirect CmdDrawIndirect = nullptr;
    PFN_CmdDrawIndexedIndirect CmdDrawIndexedIndirect = nullptr;
    PFN_CmdDispatch CmdDispatch = nullptr;
    PFN_CmdDispatchIndirect CmdDispatchIndirect = nullptr;
    PFN_CmdCopyBuffer CmdCopyBuffer = nullptr;
    PFN_CmdCopyImage CmdCopyImage = nullptr;
    PFN_CmdBlitImage CmdBlitImage = nullptr;
    PFN_CmdCopyBufferToImage CmdCopyBufferToImage = nullptr;
    PFN_CmdCopyImageToBuffer CmdCopyImageToBuffer = nullptr;
    PFN_CmdUpdateBuffer CmdUpdateBuffer = nullptr;
    PFN_CmdFillBuffer CmdFillBuffer = nullptr;
    PFN_CmdClearColorImage CmdClearColorImage = nullptr;
    PFN_CmdClearDepthStencilImage CmdClearDepthStencilImage = nullptr;
    PFN_CmdClearAttachments CmdClearAttachments = nullptr;
    PFN_CmdResolveImage CmdResolveImage = nullptr;
    PFN_CmdSetEvent CmdSetEvent = nullptr;
    PFN_CmdResetEvent CmdResetEvent = nullptr;
    PFN_CmdWaitEvents CmdWaitEvents = nullptr;
    PFN_CmdPipelineBarrier CmdPipelineBarrier = nullptr;
    PFN_CmdBeginQuery CmdBeginQuery = nullptr;
    PFN_CmdEndQuery CmdEndQuery = nullptr;
    PFN_CmdResetQueryPool CmdResetQueryPool = nullptr;
    PFN_CmdWriteTimestamp CmdWriteTimestamp = nullptr;
    PFN_CmdCopyQueryPoolResults CmdCopyQueryPoolResults = nullptr;
    PFN_CmdPushConstants CmdPushConstants = nullptr;
    PFN_CmdBeginRenderPass CmdBeginRenderPass = nullptr;
    PFN_CmdNextSubpass CmdNextSubpass = nullptr;
    PFN_CmdEndRenderPass CmdEndRenderPass = nullptr;
    PFN_CmdExecuteCommands CmdExecuteCommands = nullptr;
    PFN_BindBufferMemory2 BindBufferMemory2 = nullptr;
    PFN_BindImageMemory2 BindImageMemory2 = nullptr;
    PFN_GetDeviceGroupPeerMemoryFeatures GetDeviceGroupPeerMemoryFeatures = nullptr;
    PFN_CmdSetDeviceMask CmdSetDeviceMask = nullptr;
    PFN_CmdDispatchBase CmdDispatchBase = nullptr;
    PFN_GetBufferMemoryRequirements2 GetBufferMemoryRequirements2 = nullptr;
    PFN_GetImageMemoryRequirements2 GetImageMemoryRequirements2 = nullptr;
    PFN_GetImageSparseMemoryRequirements2 GetImageSparseMemoryRequirements2 = nullptr;
    PFN_TrimCommandPool TrimCommandPool = nullptr;
    PFN_GetDeviceQueue2 GetDeviceQueue2 = nullptr;
    PFN_CreateSamplerYcbcrConversion CreateSamplerYcbcrConversion = nullptr;
    PFN_DestroySamplerYcbcrConversion DestroySamplerYcbcrConversion = nullptr;
    PFN_CreateDescriptorUpdateTemplate CreateDescriptorUpdateTemplate = nullptr;
    PFN_DestroyDescriptorUpdateTemplate DestroyDescriptorUpdateTemplate = nullptr;
    PFN_UpdateDescriptorSetWithTemplate UpdateDescriptorSetWithTemplate = nullptr;
    PFN_GetDescriptorSetLayoutSupport GetDescriptorSetLayoutSupport = nullptr;
    PFN_CmdDrawIndirectCount CmdDrawIndirectCount = nullptr;
    PFN_CmdDrawIndexedIndirectCount CmdDrawIndexedIndirectCount = nullptr;
    PFN_CreateRenderPass2 CreateRenderPass2 = nullptr;
    PFN_CmdBeginRenderPass2 CmdBeginRenderPass2 = nullptr;
    PFN_CmdNextSubpass2 CmdNextSubpass2 = nullptr;
    PFN_CmdEndRenderPass2 CmdEndRenderPass2 = nullptr;
    PFN_ResetQueryPool ResetQueryPool = nullptr;
    PFN_GetSemaphoreCounterValue GetSemaphoreCounterValue = nullptr;
    PFN_WaitSemaphores WaitSemaphores = nullptr;
    PFN_SignalSemaphore SignalSemaphore = nullptr;
    PFN_GetBufferOpaqueCaptureAddress GetBufferOpaqueCaptureAddress = nullptr;
    PFN_GetBufferDeviceAddress GetBufferDeviceAddress = nullptr;
    PFN_GetDeviceMemoryOpaqueCaptureAddress GetDeviceMemoryOpaqueCaptureAddress = nullptr;
    PFN_CreatePrivateDataSlot CreatePrivateDataSlot = nullptr;
    PFN_DestroyPrivateDataSlot DestroyPrivateDataSlot = nullptr;
    PFN_SetPrivateData SetPrivateData = nullptr;
    PFN_GetPrivateData GetPrivateData = nullptr;
    PFN_CmdSetEvent2 CmdSetEvent2 = nullptr;
    PFN_CmdResetEvent2 CmdResetEvent2 = nullptr;
    PFN_CmdWaitEvents2 CmdWaitEvents2 = nullptr;
    PFN_CmdPipelineBarrier2 CmdPipelineBarrier2 = nullptr;
    PFN_QueueSubmit2 QueueSubmit2 = nullptr;
    PFN_CmdWriteTimestamp2 CmdWriteTimestamp2 = nullptr;
    PFN_CmdCopyBuffer2 CmdCopyBuffer2 = nullptr;
    PFN_CmdCopyImage2 CmdCopyImage2 = nullptr;
    PFN_CmdBlitImage2 CmdBlitImage2 = nullptr;
    PFN_CmdCopyBufferToImage2 CmdCopyBufferToImage2 = nullptr;
    PFN_CmdCopyImageToBuffer2 CmdCopyImageToBuffer2 = nullptr;
    PFN_CmdResolveImage2 CmdResolveImage2 = nullptr;
    PFN_CmdBeginRendering CmdBeginRendering = nullptr;
    PFN_CmdEndRendering CmdEndRendering = nullptr;
    PFN_CmdSetCullMode CmdSetCullMode = nullptr;
    PFN_CmdSetFrontFace CmdSetFrontFace = nullptr;
    PFN_CmdSetPrimitiveTopology CmdSetPrimitiveTopology = nullptr;
    PFN_CmdSetViewportWithCount CmdSetViewportWithCount = nullptr;
    PFN_CmdSetScissorWithCount CmdSetScissorWithCount = nullptr;
    PFN_CmdBindVertexBuffers2 CmdBindVertexBuffers2 = nullptr;
    PFN_CmdSetDepthTestEnable CmdSetDepthTestEnable = nullptr;
    PFN_CmdSetDepthWriteEnable CmdSetDepthWriteEnable = nullptr;
    PFN_CmdSetDepthCompareOp CmdSetDepthCompareOp = nullptr;
    PFN_CmdSetDepthBoundsTestEnable CmdSetDepthBoundsTestEnable = nullptr;
    PFN_CmdSetStencilTestEnable CmdSetStencilTestEnable = nullptr;
    PFN_CmdSetStencilOp CmdSetStencilOp = nullptr;
    PFN_CmdSetRasterizerDiscardEnable CmdSetRasterizerDiscardEnable = nullptr;
    PFN_CmdSetDepthBiasEnable CmdSetDepthBiasEnable = nullptr;
    PFN_CmdSetPrimitiveRestartEnable CmdSetPrimitiveRestartEnable = nullptr;
    PFN_GetDeviceBufferMemoryRequirements GetDeviceBufferMemoryRequirements = nullptr;
    PFN_GetDeviceImageMemoryRequirements GetDeviceImageMemoryRequirements = nullptr;
    PFN_GetDeviceImageSparseMemoryRequirements GetDeviceImageSparseMemoryRequirements = nullptr;
    PFN_CreateSwapchainKHR CreateSwapchainKHR = nullptr;
    PFN_DestroySwapchainKHR DestroySwapchainKHR = nullptr;
    PFN_GetSwapchainImagesKHR GetSwapchainImagesKHR = nullptr;
    PFN_AcquireNextImageKHR AcquireNextImageKHR = nullptr;
    PFN_QueuePresentKHR QueuePresentKHR = nullptr;
    PFN_GetDeviceGroupPresentCapabilitiesKHR GetDeviceGroupPresentCapabilitiesKHR = nullptr;
    PFN_GetDeviceGroupSurfacePresentModesKHR GetDeviceGroupSurfacePresentModesKHR = nullptr;
    PFN_AcquireNextImage2KHR AcquireNextImage2KHR = nullptr;
    PFN_CreateSharedSwapchainsKHR CreateSharedSwapchainsKHR = nullptr;
    PFN_DebugMarkerSetObjectNameEXT DebugMarkerSetObjectNameEXT = nullptr;
    PFN_DebugMarkerSetObjectTagEXT DebugMarkerSetObjectTagEXT = nullptr;
    PFN_CmdDebugMarkerBeginEXT CmdDebugMarkerBeginEXT = nullptr;
    PFN_CmdDebugMarkerEndEXT CmdDebugMarkerEndEXT = nullptr;
    PFN_CmdDebugMarkerInsertEXT CmdDebugMarkerInsertEXT = nullptr;
    PFN_CreateVideoSessionKHR CreateVideoSessionKHR = nullptr;
    PFN_DestroyVideoSessionKHR DestroyVideoSessionKHR = nullptr;
    PFN_CreateVideoSessionParametersKHR CreateVideoSessionParametersKHR = nullptr;
    PFN_UpdateVideoSessionParametersKHR UpdateVideoSessionParametersKHR = nullptr;
    PFN_DestroyVideoSessionParametersKHR DestroyVideoSessionParametersKHR = nullptr;
    PFN_GetVideoSessionMemoryRequirementsKHR GetVideoSessionMemoryRequirementsKHR = nullptr;
    PFN_BindVideoSessionMemoryKHR BindVideoSessionMemoryKHR = nullptr;
    PFN_CmdBeginVideoCodingKHR CmdBeginVideoCodingKHR = nullptr;
    PFN_CmdControlVideoCodingKHR CmdControlVideoCodingKHR = nullptr;
    PFN_CmdEndVideoCodingKHR CmdEndVideoCodingKHR = nullptr;
    PFN_CmdDecodeVideoKHR CmdDecodeVideoKHR = nullptr;
    PFN_CmdBindTransformFeedbackBuffersEXT CmdBindTransformFeedbackBuffersEXT = nullptr;
    PFN_CmdBeginTransformFeedbackEXT CmdBeginTransformFeedbackEXT = nullptr;
    PFN_CmdEndTransformFeedbackEXT CmdEndTransformFeedbackEXT = nullptr;
    PFN_CmdBeginQueryIndexedEXT CmdBeginQueryIndexedEXT = nullptr;
    PFN_CmdEndQueryIndexedEXT CmdEndQueryIndexedEXT = nullptr;
    PFN_CmdDrawIndirectByteCountEXT CmdDrawIndirectByteCountEXT = nullptr;
    PFN_CreateCuModuleNVX CreateCuModuleNVX = nullptr;
    PFN_CreateCuFunctionNVX CreateCuFunctionNVX = nullptr;
    PFN_DestroyCuModuleNVX DestroyCuModuleNVX = nullptr;
    PFN_DestroyCuFunctionNVX DestroyCuFunctionNVX = nullptr;
    PFN_CmdCuLaunchKernelNVX CmdCuLaunchKernelNVX = nullptr;
    PFN_GetImageViewHandleNVX GetImageViewHandleNVX = nullptr;
    PFN_GetImageViewAddressNVX GetImageViewAddressNVX = nullptr;
    PFN_GetShaderInfoAMD GetShaderInfoAMD = nullptr;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetMemoryWin32HandleNV GetMemoryWin32HandleNV = nullptr;
#else
    void* z_padding_GetMemoryWin32HandleNV = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetMemoryWin32HandleKHR GetMemoryWin32HandleKHR = nullptr;
#else
    void* z_padding_GetMemoryWin32HandleKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetMemoryWin32HandlePropertiesKHR GetMemoryWin32HandlePropertiesKHR = nullptr;
#else
    void* z_padding_GetMemoryWin32HandlePropertiesKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetMemoryFdKHR GetMemoryFdKHR = nullptr;
    PFN_GetMemoryFdPropertiesKHR GetMemoryFdPropertiesKHR = nullptr;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetSemaphoreWin32HandleKHR GetSemaphoreWin32HandleKHR = nullptr;
#else
    void* z_padding_GetSemaphoreWin32HandleKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_ImportSemaphoreWin32HandleKHR ImportSemaphoreWin32HandleKHR = nullptr;
#else
    void* z_padding_ImportSemaphoreWin32HandleKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetSemaphoreFdKHR GetSemaphoreFdKHR = nullptr;
    PFN_ImportSemaphoreFdKHR ImportSemaphoreFdKHR = nullptr;
    PFN_CmdPushDescriptorSetKHR CmdPushDescriptorSetKHR = nullptr;
    PFN_CmdPushDescriptorSetWithTemplateKHR CmdPushDescriptorSetWithTemplateKHR = nullptr;
    PFN_CmdBeginConditionalRenderingEXT CmdBeginConditionalRenderingEXT = nullptr;
    PFN_CmdEndConditionalRenderingEXT CmdEndConditionalRenderingEXT = nullptr;
    PFN_CmdSetViewportWScalingNV CmdSetViewportWScalingNV = nullptr;
    PFN_DisplayPowerControlEXT DisplayPowerControlEXT = nullptr;
    PFN_RegisterDeviceEventEXT RegisterDeviceEventEXT = nullptr;
    PFN_RegisterDisplayEventEXT RegisterDisplayEventEXT = nullptr;
    PFN_GetSwapchainCounterEXT GetSwapchainCounterEXT = nullptr;
    PFN_GetRefreshCycleDurationGOOGLE GetRefreshCycleDurationGOOGLE = nullptr;
    PFN_GetPastPresentationTimingGOOGLE GetPastPresentationTimingGOOGLE = nullptr;
    PFN_CmdSetDiscardRectangleEXT CmdSetDiscardRectangleEXT = nullptr;
    PFN_CmdSetDiscardRectangleEnableEXT CmdSetDiscardRectangleEnableEXT = nullptr;
    PFN_CmdSetDiscardRectangleModeEXT CmdSetDiscardRectangleModeEXT = nullptr;
    PFN_SetHdrMetadataEXT SetHdrMetadataEXT = nullptr;
    PFN_GetSwapchainStatusKHR GetSwapchainStatusKHR = nullptr;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetFenceWin32HandleKHR GetFenceWin32HandleKHR = nullptr;
#else
    void* z_padding_GetFenceWin32HandleKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_ImportFenceWin32HandleKHR ImportFenceWin32HandleKHR = nullptr;
#else
    void* z_padding_ImportFenceWin32HandleKHR = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetFenceFdKHR GetFenceFdKHR = nullptr;
    PFN_ImportFenceFdKHR ImportFenceFdKHR = nullptr;
    PFN_AcquireProfilingLockKHR AcquireProfilingLockKHR = nullptr;
    PFN_ReleaseProfilingLockKHR ReleaseProfilingLockKHR = nullptr;
    PFN_SetDebugUtilsObjectNameEXT SetDebugUtilsObjectNameEXT = nullptr;
    PFN_SetDebugUtilsObjectTagEXT SetDebugUtilsObjectTagEXT = nullptr;
    PFN_QueueBeginDebugUtilsLabelEXT QueueBeginDebugUtilsLabelEXT = nullptr;
    PFN_QueueEndDebugUtilsLabelEXT QueueEndDebugUtilsLabelEXT = nullptr;
    PFN_QueueInsertDebugUtilsLabelEXT QueueInsertDebugUtilsLabelEXT = nullptr;
    PFN_CmdBeginDebugUtilsLabelEXT CmdBeginDebugUtilsLabelEXT = nullptr;
    PFN_CmdEndDebugUtilsLabelEXT CmdEndDebugUtilsLabelEXT = nullptr;
    PFN_CmdInsertDebugUtilsLabelEXT CmdInsertDebugUtilsLabelEXT = nullptr;
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    PFN_GetAndroidHardwareBufferPropertiesANDROID GetAndroidHardwareBufferPropertiesANDROID = nullptr;
#else
    void* z_padding_GetAndroidHardwareBufferPropertiesANDROID = nullptr;
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    PFN_GetMemoryAndroidHardwareBufferANDROID GetMemoryAndroidHardwareBufferANDROID = nullptr;
#else
    void* z_padding_GetMemoryAndroidHardwareBufferANDROID = nullptr;
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_GetExecutionGraphPipelineScratchSizeAMDX GetExecutionGraphPipelineScratchSizeAMDX = nullptr;
#else
    void* z_padding_GetExecutionGraphPipelineScratchSizeAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_GetExecutionGraphPipelineNodeIndexAMDX GetExecutionGraphPipelineNodeIndexAMDX = nullptr;
#else
    void* z_padding_GetExecutionGraphPipelineNodeIndexAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_CreateExecutionGraphPipelinesAMDX CreateExecutionGraphPipelinesAMDX = nullptr;
#else
    void* z_padding_CreateExecutionGraphPipelinesAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_CmdInitializeGraphScratchMemoryAMDX CmdInitializeGraphScratchMemoryAMDX = nullptr;
#else
    void* z_padding_CmdInitializeGraphScratchMemoryAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_CmdDispatchGraphAMDX CmdDispatchGraphAMDX = nullptr;
#else
    void* z_padding_CmdDispatchGraphAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_CmdDispatchGraphIndirectAMDX CmdDispatchGraphIndirectAMDX = nullptr;
#else
    void* z_padding_CmdDispatchGraphIndirectAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_CmdDispatchGraphIndirectCountAMDX CmdDispatchGraphIndirectCountAMDX = nullptr;
#else
    void* z_padding_CmdDispatchGraphIndirectCountAMDX = nullptr;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
    PFN_CmdSetSampleLocationsEXT CmdSetSampleLocationsEXT = nullptr;
    PFN_DestroyAccelerationStructureKHR DestroyAccelerationStructureKHR = nullptr;
    PFN_CmdCopyAccelerationStructureKHR CmdCopyAccelerationStructureKHR = nullptr;
    PFN_CopyAccelerationStructureKHR CopyAccelerationStructureKHR = nullptr;
    PFN_CmdCopyAccelerationStructureToMemoryKHR CmdCopyAccelerationStructureToMemoryKHR = nullptr;
    PFN_CopyAccelerationStructureToMemoryKHR CopyAccelerationStructureToMemoryKHR = nullptr;
    PFN_CmdCopyMemoryToAccelerationStructureKHR CmdCopyMemoryToAccelerationStructureKHR = nullptr;
    PFN_CopyMemoryToAccelerationStructureKHR CopyMemoryToAccelerationStructureKHR = nullptr;
    PFN_CmdWriteAccelerationStructuresPropertiesKHR CmdWriteAccelerationStructuresPropertiesKHR = nullptr;
    PFN_WriteAccelerationStructuresPropertiesKHR WriteAccelerationStructuresPropertiesKHR = nullptr;
    PFN_GetDeviceAccelerationStructureCompatibilityKHR GetDeviceAccelerationStructureCompatibilityKHR = nullptr;
    PFN_CreateAccelerationStructureKHR CreateAccelerationStructureKHR = nullptr;
    PFN_CmdBuildAccelerationStructuresKHR CmdBuildAccelerationStructuresKHR = nullptr;
    PFN_CmdBuildAccelerationStructuresIndirectKHR CmdBuildAccelerationStructuresIndirectKHR = nullptr;
    PFN_BuildAccelerationStructuresKHR BuildAccelerationStructuresKHR = nullptr;
    PFN_GetAccelerationStructureDeviceAddressKHR GetAccelerationStructureDeviceAddressKHR = nullptr;
    PFN_GetAccelerationStructureBuildSizesKHR GetAccelerationStructureBuildSizesKHR = nullptr;
    PFN_CmdTraceRaysKHR CmdTraceRaysKHR = nullptr;
    PFN_GetRayTracingShaderGroupHandlesKHR GetRayTracingShaderGroupHandlesKHR = nullptr;
    PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR GetRayTracingCaptureReplayShaderGroupHandlesKHR = nullptr;
    PFN_CreateRayTracingPipelinesKHR CreateRayTracingPipelinesKHR = nullptr;
    PFN_CmdTraceRaysIndirectKHR CmdTraceRaysIndirectKHR = nullptr;
    PFN_GetRayTracingShaderGroupStackSizeKHR GetRayTracingShaderGroupStackSizeKHR = nullptr;
    PFN_CmdSetRayTracingPipelineStackSizeKHR CmdSetRayTracingPipelineStackSizeKHR = nullptr;
    PFN_GetImageDrmFormatModifierPropertiesEXT GetImageDrmFormatModifierPropertiesEXT = nullptr;
    PFN_CreateValidationCacheEXT CreateValidationCacheEXT = nullptr;
    PFN_DestroyValidationCacheEXT DestroyValidationCacheEXT = nullptr;
    PFN_GetValidationCacheDataEXT GetValidationCacheDataEXT = nullptr;
    PFN_MergeValidationCachesEXT MergeValidationCachesEXT = nullptr;
    PFN_CmdBindShadingRateImageNV CmdBindShadingRateImageNV = nullptr;
    PFN_CmdSetViewportShadingRatePaletteNV CmdSetViewportShadingRatePaletteNV = nullptr;
    PFN_CmdSetCoarseSampleOrderNV CmdSetCoarseSampleOrderNV = nullptr;
    PFN_CompileDeferredNV CompileDeferredNV = nullptr;
    PFN_CreateAccelerationStructureNV CreateAccelerationStructureNV = nullptr;
    PFN_DestroyAccelerationStructureNV DestroyAccelerationStructureNV = nullptr;
    PFN_GetAccelerationStructureMemoryRequirementsNV GetAccelerationStructureMemoryRequirementsNV = nullptr;
    PFN_BindAccelerationStructureMemoryNV BindAccelerationStructureMemoryNV = nullptr;
    PFN_CmdCopyAccelerationStructureNV CmdCopyAccelerationStructureNV = nullptr;
    PFN_CmdWriteAccelerationStructuresPropertiesNV CmdWriteAccelerationStructuresPropertiesNV = nullptr;
    PFN_CmdBuildAccelerationStructureNV CmdBuildAccelerationStructureNV = nullptr;
    PFN_CmdTraceRaysNV CmdTraceRaysNV = nullptr;
    PFN_GetAccelerationStructureHandleNV GetAccelerationStructureHandleNV = nullptr;
    PFN_CreateRayTracingPipelinesNV CreateRayTracingPipelinesNV = nullptr;
    PFN_GetMemoryHostPointerPropertiesEXT GetMemoryHostPointerPropertiesEXT = nullptr;
    PFN_CmdWriteBufferMarkerAMD CmdWriteBufferMarkerAMD = nullptr;
    PFN_CmdDrawMeshTasksNV CmdDrawMeshTasksNV = nullptr;
    PFN_CmdDrawMeshTasksIndirectNV CmdDrawMeshTasksIndirectNV = nullptr;
    PFN_CmdDrawMeshTasksIndirectCountNV CmdDrawMeshTasksIndirectCountNV = nullptr;
    PFN_CmdSetExclusiveScissorNV CmdSetExclusiveScissorNV = nullptr;
    PFN_CmdSetExclusiveScissorEnableNV CmdSetExclusiveScissorEnableNV = nullptr;
    PFN_CmdSetCheckpointNV CmdSetCheckpointNV = nullptr;
    PFN_GetQueueCheckpointDataNV GetQueueCheckpointDataNV = nullptr;
    PFN_InitializePerformanceApiINTEL InitializePerformanceApiINTEL = nullptr;
    PFN_UninitializePerformanceApiINTEL UninitializePerformanceApiINTEL = nullptr;
    PFN_CmdSetPerformanceMarkerINTEL CmdSetPerformanceMarkerINTEL = nullptr;
    PFN_CmdSetPerformanceStreamMarkerINTEL CmdSetPerformanceStreamMarkerINTEL = nullptr;
    PFN_CmdSetPerformanceOverrideINTEL CmdSetPerformanceOverrideINTEL = nullptr;
    PFN_AcquirePerformanceConfigurationINTEL AcquirePerformanceConfigurationINTEL = nullptr;
    PFN_ReleasePerformanceConfigurationINTEL ReleasePerformanceConfigurationINTEL = nullptr;
    PFN_QueueSetPerformanceConfigurationINTEL QueueSetPerformanceConfigurationINTEL = nullptr;
    PFN_GetPerformanceParameterINTEL GetPerformanceParameterINTEL = nullptr;
    PFN_SetLocalDimmingAMD SetLocalDimmingAMD = nullptr;
    PFN_CmdSetFragmentShadingRateKHR CmdSetFragmentShadingRateKHR = nullptr;
    PFN_CmdSetRenderingAttachmentLocationsKHR CmdSetRenderingAttachmentLocationsKHR = nullptr;
    PFN_CmdSetRenderingInputAttachmentIndicesKHR CmdSetRenderingInputAttachmentIndicesKHR = nullptr;
    PFN_WaitForPresentKHR WaitForPresentKHR = nullptr;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_AcquireFullScreenExclusiveModeEXT AcquireFullScreenExclusiveModeEXT = nullptr;
#else
    void* z_padding_AcquireFullScreenExclusiveModeEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_ReleaseFullScreenExclusiveModeEXT ReleaseFullScreenExclusiveModeEXT = nullptr;
#else
    void* z_padding_ReleaseFullScreenExclusiveModeEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_GetDeviceGroupSurfacePresentModes2EXT GetDeviceGroupSurfacePresentModes2EXT = nullptr;
#else
    void* z_padding_GetDeviceGroupSurfacePresentModes2EXT = nullptr;
#endif // defined(VK_USE_PLATFORM_WIN32_KHR)
    PFN_CreateDeferredOperationKHR CreateDeferredOperationKHR = nullptr;
    PFN_DestroyDeferredOperationKHR DestroyDeferredOperationKHR = nullptr;
    PFN_GetDeferredOperationMaxConcurrencyKHR GetDeferredOperationMaxConcurrencyKHR = nullptr;
    PFN_GetDeferredOperationResultKHR GetDeferredOperationResultKHR = nullptr;
    PFN_DeferredOperationJoinKHR DeferredOperationJoinKHR = nullptr;
    PFN_GetPipelineExecutablePropertiesKHR GetPipelineExecutablePropertiesKHR = nullptr;
    PFN_GetPipelineExecutableStatisticsKHR GetPipelineExecutableStatisticsKHR = nullptr;
    PFN_GetPipelineExecutableInternalRepresentationsKHR GetPipelineExecutableInternalRepresentationsKHR = nullptr;
    PFN_CopyMemoryToImageEXT CopyMemoryToImageEXT = nullptr;
    PFN_CopyImageToMemoryEXT CopyImageToMemoryEXT = nullptr;
    PFN_CopyImageToImageEXT CopyImageToImageEXT = nullptr;
    PFN_TransitionImageLayoutEXT TransitionImageLayoutEXT = nullptr;
    PFN_MapMemory2KHR MapMemory2KHR = nullptr;
    PFN_UnmapMemory2KHR UnmapMemory2KHR = nullptr;
    PFN_ReleaseSwapchainImagesEXT ReleaseSwapchainImagesEXT = nullptr;
    PFN_CmdExecuteGeneratedCommandsNV CmdExecuteGeneratedCommandsNV = nullptr;
    PFN_CmdPreprocessGeneratedCommandsNV CmdPreprocessGeneratedCommandsNV = nullptr;
    PFN_CmdBindPipelineShaderGroupNV CmdBindPipelineShaderGroupNV = nullptr;
    PFN_GetGeneratedCommandsMemoryRequirementsNV GetGeneratedCommandsMemoryRequirementsNV = nullptr;
    PFN_CreateIndirectCommandsLayoutNV CreateIndirectCommandsLayoutNV = nullptr;
    PFN_DestroyIndirectCommandsLayoutNV DestroyIndirectCommandsLayoutNV = nullptr;
    PFN_CmdSetDepthBias2EXT CmdSetDepthBias2EXT = nullptr;
    PFN_GetEncodedVideoSessionParametersKHR GetEncodedVideoSessionParametersKHR = nullptr;
    PFN_CmdEncodeVideoKHR CmdEncodeVideoKHR = nullptr;
    PFN_CreateCudaModuleNV CreateCudaModuleNV = nullptr;
    PFN_GetCudaModuleCacheNV GetCudaModuleCacheNV = nullptr;
    PFN_CreateCudaFunctionNV CreateCudaFunctionNV = nullptr;
    PFN_DestroyCudaModuleNV DestroyCudaModuleNV = nullptr;
    PFN_DestroyCudaFunctionNV DestroyCudaFunctionNV = nullptr;
    PFN_CmdCudaLaunchKernelNV CmdCudaLaunchKernelNV = nullptr;
#if defined(VK_USE_PLATFORM_METAL_EXT)
    PFN_ExportMetalObjectsEXT ExportMetalObjectsEXT = nullptr;
#else
    void* z_padding_ExportMetalObjectsEXT = nullptr;
#endif // defined(VK_USE_PLATFORM_METAL_EXT)
    PFN_CmdWriteBufferMarker2AMD CmdWriteBufferMarker2AMD = nullptr;
    PFN_GetQueueCheckpointData2NV GetQueueCheckpointData2NV = nullptr;
    PFN_GetDescriptorSetLayoutSizeEXT GetDescriptorSetLayoutSizeEXT = nullptr;
    PFN_GetDescriptorSetLayoutBindingOffsetEXT GetDescriptorSetLayoutBindingOffsetEXT = nullptr;
    PFN_GetDescriptorEXT GetDescriptorEXT = nullptr;
    PFN_CmdBindDescriptorBuffersEXT CmdBindDescriptorBuffersEXT = nullptr;
    PFN_CmdSetDescriptorBufferOffsetsEXT CmdSetDescriptorBufferOffsetsEXT = nullptr;
    PFN_CmdBindDescriptorBufferEmbeddedSamplersEXT CmdBindDescriptorBufferEmbeddedSamplersEXT = nullptr;
    PFN_GetBufferOpaqueCaptureDescriptorDataEXT GetBufferOpaqueCaptureDescriptorDataEXT = nullptr;
    PFN_GetImageOpaqueCaptureDescriptorDataEXT GetImageOpaqueCaptureDescriptorDataEXT = nullptr;
    PFN_GetImageViewOpaqueCaptureDescriptorDataEXT GetImageViewOpaqueCaptureDescriptorDataEXT = nullptr;
    PFN_GetSamplerOpaqueCaptureDescriptorDataEXT GetSamplerOpaqueCaptureDescriptorDataEXT = nullptr;
    PFN_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT GetAccelerationStructureOpaqueCaptureDescriptorDataEXT = nullptr;
    PFN_CmdSetFragmentShadingRateEnumNV CmdSetFragmentShadingRateEnumNV = nullptr;
    PFN_CmdDrawMeshTasksEXT CmdDrawMeshTasksEXT = nullptr;
    PFN_CmdDrawMeshTasksIndirectEXT CmdDrawMeshTasksIndirectEXT = nullptr;
    PFN_CmdDrawMeshTasksIndirectCountEXT CmdDrawMeshTasksIndirectCountEXT = nullptr;
    PFN_GetDeviceFaultInfoEXT GetDeviceFaultInfoEXT = nullptr;
    PFN_CmdSetVertexInputEXT CmdSetVertexInputEXT = nullptr;
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_GetMemoryZirconHandleFUCHSIA GetMemoryZirconHandleFUCHSIA = nullptr;
#else
    void* z_padding_GetMemoryZirconHandleFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_GetMemoryZirconHandlePropertiesFUCHSIA GetMemoryZirconHandlePropertiesFUCHSIA = nullptr;
#else
    void* z_padding_GetMemoryZirconHandlePropertiesFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_GetSemaphoreZirconHandleFUCHSIA GetSemaphoreZirconHandleFUCHSIA = nullptr;
#else
    void* z_padding_GetSemaphoreZirconHandleFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_ImportSemaphoreZirconHandleFUCHSIA ImportSemaphoreZirconHandleFUCHSIA = nullptr;
#else
    void* z_padding_ImportSemaphoreZirconHandleFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_CreateBufferCollectionFUCHSIA CreateBufferCollectionFUCHSIA = nullptr;
#else
    void* z_padding_CreateBufferCollectionFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_SetBufferCollectionBufferConstraintsFUCHSIA SetBufferCollectionBufferConstraintsFUCHSIA = nullptr;
#else
    void* z_padding_SetBufferCollectionBufferConstraintsFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_SetBufferCollectionImageConstraintsFUCHSIA SetBufferCollectionImageConstraintsFUCHSIA = nullptr;
#else
    void* z_padding_SetBufferCollectionImageConstraintsFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_DestroyBufferCollectionFUCHSIA DestroyBufferCollectionFUCHSIA = nullptr;
#else
    void* z_padding_DestroyBufferCollectionFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
#if defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_GetBufferCollectionPropertiesFUCHSIA GetBufferCollectionPropertiesFUCHSIA = nullptr;
#else
    void* z_padding_GetBufferCollectionPropertiesFUCHSIA = nullptr;
#endif // defined(VK_USE_PLATFORM_FUCHSIA)
    PFN_GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = nullptr;
    PFN_CmdSubpassShadingHUAWEI CmdSubpassShadingHUAWEI = nullptr;
    PFN_CmdBindInvocationMaskHUAWEI CmdBindInvocationMaskHUAWEI = nullptr;
    PFN_GetMemoryRemoteAddressNV GetMemoryRemoteAddressNV = nullptr;
    PFN_GetPipelinePropertiesEXT GetPipelinePropertiesEXT = nullptr;
    PFN_CmdSetPatchControlPointsEXT CmdSetPatchControlPointsEXT = nullptr;
    PFN_CmdSetLogicOpEXT CmdSetLogicOpEXT = nullptr;
    PFN_CmdSetColorWriteEnableEXT CmdSetColorWriteEnableEXT = nullptr;
    PFN_CmdTraceRaysIndirect2KHR CmdTraceRaysIndirect2KHR = nullptr;
    PFN_CmdDrawMultiEXT CmdDrawMultiEXT = nullptr;
    PFN_CmdDrawMultiIndexedEXT CmdDrawMultiIndexedEXT = nullptr;
    PFN_CreateMicromapEXT CreateMicromapEXT = nullptr;
    PFN_CmdBuildMicromapsEXT CmdBuildMicromapsEXT = nullptr;
    PFN_BuildMicromapsEXT BuildMicromapsEXT = nullptr;
    PFN_DestroyMicromapEXT DestroyMicromapEXT = nullptr;
    PFN_CmdCopyMicromapEXT CmdCopyMicromapEXT = nullptr;
    PFN_CopyMicromapEXT CopyMicromapEXT = nullptr;
    PFN_CmdCopyMicromapToMemoryEXT CmdCopyMicromapToMemoryEXT = nullptr;
    PFN_CopyMicromapToMemoryEXT CopyMicromapToMemoryEXT = nullptr;
    PFN_CmdCopyMemoryToMicromapEXT CmdCopyMemoryToMicromapEXT = nullptr;
    PFN_CopyMemoryToMicromapEXT CopyMemoryToMicromapEXT = nullptr;
    PFN_CmdWriteMicromapsPropertiesEXT CmdWriteMicromapsPropertiesEXT = nullptr;
    PFN_WriteMicromapsPropertiesEXT WriteMicromapsPropertiesEXT = nullptr;
    PFN_GetDeviceMicromapCompatibilityEXT GetDeviceMicromapCompatibilityEXT = nullptr;
    PFN_GetMicromapBuildSizesEXT GetMicromapBuildSizesEXT = nullptr;
    PFN_CmdDrawClusterHUAWEI CmdDrawClusterHUAWEI = nullptr;
    PFN_CmdDrawClusterIndirectHUAWEI CmdDrawClusterIndirectHUAWEI = nullptr;
    PFN_SetDeviceMemoryPriorityEXT SetDeviceMemoryPriorityEXT = nullptr;
    PFN_GetDescriptorSetLayoutHostMappingInfoVALVE GetDescriptorSetLayoutHostMappingInfoVALVE = nullptr;
    PFN_GetDescriptorSetHostMappingVALVE GetDescriptorSetHostMappingVALVE = nullptr;
    PFN_CmdCopyMemoryIndirectNV CmdCopyMemoryIndirectNV = nullptr;
    PFN_CmdCopyMemoryToImageIndirectNV CmdCopyMemoryToImageIndirectNV = nullptr;
    PFN_CmdDecompressMemoryNV CmdDecompressMemoryNV = nullptr;
    PFN_CmdDecompressMemoryIndirectCountNV CmdDecompressMemoryIndirectCountNV = nullptr;
    PFN_CmdUpdatePipelineIndirectBufferNV CmdUpdatePipelineIndirectBufferNV = nullptr;
    PFN_GetPipelineIndirectMemoryRequirementsNV GetPipelineIndirectMemoryRequirementsNV = nullptr;
    PFN_GetPipelineIndirectDeviceAddressNV GetPipelineIndirectDeviceAddressNV = nullptr;
    PFN_CmdSetDepthClampEnableEXT CmdSetDepthClampEnableEXT = nullptr;
    PFN_CmdSetPolygonModeEXT CmdSetPolygonModeEXT = nullptr;
    PFN_CmdSetRasterizationSamplesEXT CmdSetRasterizationSamplesEXT = nullptr;
    PFN_CmdSetSampleMaskEXT CmdSetSampleMaskEXT = nullptr;
    PFN_CmdSetAlphaToCoverageEnableEXT CmdSetAlphaToCoverageEnableEXT = nullptr;
    PFN_CmdSetAlphaToOneEnableEXT CmdSetAlphaToOneEnableEXT = nullptr;
    PFN_CmdSetLogicOpEnableEXT CmdSetLogicOpEnableEXT = nullptr;
    PFN_CmdSetColorBlendEnableEXT CmdSetColorBlendEnableEXT = nullptr;
    PFN_CmdSetColorBlendEquationEXT CmdSetColorBlendEquationEXT = nullptr;
    PFN_CmdSetColorWriteMaskEXT CmdSetColorWriteMaskEXT = nullptr;
    PFN_CmdSetTessellationDomainOriginEXT CmdSetTessellationDomainOriginEXT = nullptr;
    PFN_CmdSetRasterizationStreamEXT CmdSetRasterizationStreamEXT = nullptr;
    PFN_CmdSetConservativeRasterizationModeEXT CmdSetConservativeRasterizationModeEXT = nullptr;
    PFN_CmdSetExtraPrimitiveOverestimationSizeEXT CmdSetExtraPrimitiveOverestimationSizeEXT = nullptr;
    PFN_CmdSetDepthClipEnableEXT CmdSetDepthClipEnableEXT = nullptr;
    PFN_CmdSetSampleLocationsEnableEXT CmdSetSampleLocationsEnableEXT = nullptr;
    PFN_CmdSetColorBlendAdvancedEXT CmdSetColorBlendAdvancedEXT = nullptr;
    PFN_CmdSetProvokingVertexModeEXT CmdSetProvokingVertexModeEXT = nullptr;
    PFN_CmdSetLineRasterizationModeEXT CmdSetLineRasterizationModeEXT = nullptr;
    PFN_CmdSetLineStippleEnableEXT CmdSetLineStippleEnableEXT = nullptr;
    PFN_CmdSetDepthClipNegativeOneToOneEXT CmdSetDepthClipNegativeOneToOneEXT = nullptr;
    PFN_CmdSetViewportWScalingEnableNV CmdSetViewportWScalingEnableNV = nullptr;
    PFN_CmdSetViewportSwizzleNV CmdSetViewportSwizzleNV = nullptr;
    PFN_CmdSetCoverageToColorEnableNV CmdSetCoverageToColorEnableNV = nullptr;
    PFN_CmdSetCoverageToColorLocationNV CmdSetCoverageToColorLocationNV = nullptr;
    PFN_CmdSetCoverageModulationModeNV CmdSetCoverageModulationModeNV = nullptr;
    PFN_CmdSetCoverageModulationTableEnableNV CmdSetCoverageModulationTableEnableNV = nullptr;
    PFN_CmdSetCoverageModulationTableNV CmdSetCoverageModulationTableNV = nullptr;
    PFN_CmdSetShadingRateImageEnableNV CmdSetShadingRateImageEnableNV = nullptr;
    PFN_CmdSetRepresentativeFragmentTestEnableNV CmdSetRepresentativeFragmentTestEnableNV = nullptr;
    PFN_CmdSetCoverageReductionModeNV CmdSetCoverageReductionModeNV = nullptr;
    PFN_GetShaderModuleIdentifierEXT GetShaderModuleIdentifierEXT = nullptr;
    PFN_GetShaderModuleCreateInfoIdentifierEXT GetShaderModuleCreateInfoIdentifierEXT = nullptr;
    PFN_CreateOpticalFlowSessionNV CreateOpticalFlowSessionNV = nullptr;
    PFN_DestroyOpticalFlowSessionNV DestroyOpticalFlowSessionNV = nullptr;
    PFN_BindOpticalFlowSessionImageNV BindOpticalFlowSessionImageNV = nullptr;
    PFN_CmdOpticalFlowExecuteNV CmdOpticalFlowExecuteNV = nullptr;
    PFN_GetRenderingAreaGranularityKHR GetRenderingAreaGranularityKHR = nullptr;
    PFN_CmdBindIndexBuffer2KHR CmdBindIndexBuffer2KHR = nullptr;
    PFN_GetImageSubresourceLayout2KHR GetImageSubresourceLayout2KHR = nullptr;
    PFN_GetDeviceImageSubresourceLayoutKHR GetDeviceImageSubresourceLayoutKHR = nullptr;
    PFN_CreateShadersEXT CreateShadersEXT = nullptr;
    PFN_DestroyShaderEXT DestroyShaderEXT = nullptr;
    PFN_GetShaderBinaryDataEXT GetShaderBinaryDataEXT = nullptr;
    PFN_CmdBindShadersEXT CmdBindShadersEXT = nullptr;
    PFN_GetFramebufferTilePropertiesQCOM GetFramebufferTilePropertiesQCOM = nullptr;
    PFN_GetDynamicRenderingTilePropertiesQCOM GetDynamicRenderingTilePropertiesQCOM = nullptr;
    PFN_SetLatencySleepModeNV SetLatencySleepModeNV = nullptr;
    PFN_LatencySleepNV LatencySleepNV = nullptr;
    PFN_SetLatencyMarkerNV SetLatencyMarkerNV = nullptr;
    PFN_GetLatencyTimingsNV GetLatencyTimingsNV = nullptr;
    PFN_QueueNotifyOutOfBandNV QueueNotifyOutOfBandNV = nullptr;
    PFN_CmdSetAttachmentFeedbackLoopEnableEXT CmdSetAttachmentFeedbackLoopEnableEXT = nullptr;
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    PFN_GetScreenBufferPropertiesQNX GetScreenBufferPropertiesQNX = nullptr;
#else
    void* z_padding_GetScreenBufferPropertiesQNX = nullptr;
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
    PFN_CmdSetLineStippleKHR CmdSetLineStippleKHR = nullptr;
    PFN_GetCalibratedTimestampsKHR GetCalibratedTimestampsKHR = nullptr;
    PFN_CmdBindDescriptorSets2KHR CmdBindDescriptorSets2KHR = nullptr;
    PFN_CmdPushConstants2KHR CmdPushConstants2KHR = nullptr;
    PFN_CmdPushDescriptorSet2KHR CmdPushDescriptorSet2KHR = nullptr;
    PFN_CmdPushDescriptorSetWithTemplate2KHR CmdPushDescriptorSetWithTemplate2KHR = nullptr;
    PFN_CmdSetDescriptorBufferOffsets2EXT CmdSetDescriptorBufferOffsets2EXT = nullptr;
    PFN_CmdBindDescriptorBufferEmbeddedSamplers2EXT CmdBindDescriptorBufferEmbeddedSamplers2EXT = nullptr;
};

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
VkResult SimpleCppInitializeLoaderLibrary(PFN_vkGetInstanceProcAddr pfn_vkGetInstanceProcAddr = VK_NULL_HANDLE);

// Close the Vulkan-Loader and assigns VK_NULL_HANDLE to vkGetInstanceProcAddr
//
// Note:
// After this function is called, no further vulkan calls can be made, except for `vk::SimpleCppInitializeLoaderLibrary()`
void SimpleCppCloseLoaderLibrary();

// Initialize the instance and physical device functions into the global function pointers
// (all functions which take a VkInstance or VkPhysicalDevice as the first parameter)
//
// Note: This must only be called after the application has created a valid VkInstance with vkCreateInstance
//
// Parameter:
// VkInstance instance
// The VkInstance handle which the application has created. Must not be VK_NULL_HANDLE
void SimpleCppInitializeInstanceFunctions(VkInstance instance);

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
void SimpleCppInitializeDeviceFunctions(VkDevice device);

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
void SimpleCppInitializeDeviceDispatchTable(VkDevice device, DeviceDispatchTable& table);

#if defined(VULKAN_CPP_IMPLEMENTATION)
#include "vulkan.cpp"
#endif //defined(VULKAN_CPP_IMPLEMENTATION)

} // namespace vk

// clang-format on
