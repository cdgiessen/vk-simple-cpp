/*
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

#include "vk-simple/vk-simple.h"

#include <assert.h>
#include <cstring>
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <GLFW/glfw3.h>

constexpr uint32_t width = 512;
constexpr uint32_t height = 512;

struct RendererContext
{
    vk::GlobalDispatchTable global_functions;
    GLFWwindow* window;
    vk::Instance instance;
    vk::InstanceDispatchTable instance_functions;
    vk::SurfaceKHR surface;
    vk::PhysicalDevice physical_device;
    vk::Device device;
    vk::DeviceDispatchTable functions;
    vk::Queue graphics_queue;
    vk::SwapchainKHR swapchain;
    std::vector<vk::Image> swapchain_images;
    uint32_t image_count = 0;
    std::vector<vk::ImageView> swapchain_image_views;
    vk::Format swapchain_img_format;
    vk::RenderPass render_pass;
    std::vector<vk::Framebuffer> framebuffers;
    vk::PipelineLayout pipeline_layout;
    vk::Pipeline pipeline;
    vk::CommandPool cmd_pool;
    std::vector<vk::CommandBuffer> cmd_buffers;
    uint32_t current_frame = 0;
    std::vector<vk::Fence> fences;
    std::vector<vk::Semaphore> available_semaphores;
    std::vector<vk::Semaphore> finished_semaphores;

    operator vk::Device() { return device; }
    vk::DeviceDispatchTable* operator->() { return &functions; }
};
void check_res(vk::Bool32 result, const char* msg)
{
    if (result != 0) {
        std::cerr << msg << "\n";
        assert(false);
    }
}
void check_res(vk::Result result, const char* msg)
{
    if (result != vk::Result::Success) {
        std::cerr << msg << ": Result = " << std::to_string(static_cast<uint32_t>(result)) << "\n";
        assert(false);
    }
}
GLFWwindow* create_window_glfw(const char* window_name = "", bool resize = true)
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    if (!resize)
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    return glfwCreateWindow(width, height, window_name, NULL, NULL);
}
void destroy_window_glfw(GLFWwindow* window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
vk::SurfaceKHR create_surface_glfw(vk::Instance instance, GLFWwindow* window)
{
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    vk::Result err = static_cast<vk::Result>(glfwCreateWindowSurface(instance, window, NULL, &surface));
    if (err != vk::Result::Success) {
        const char* error_msg;
        int ret = glfwGetError(&error_msg);
        if (ret != 0) {
            std::cerr << ret << " ";
            if (error_msg != nullptr)
                std::cerr << error_msg;
            std::cerr << "\n";
        }
        surface = VK_NULL_HANDLE;
    }
    return surface;
}

// Helper for robustly executing the two-call pattern
// NOTE: doesn't work on functions that dont return vk::Result
template<typename T, typename F, typename... Ts>
auto GetVectorInit(F&& f, T init, Ts&&... ts) -> std::vector<T>
{
    uint32_t count = 0;
    std::vector<T> results;
    vk::Result err;
    do {
        err = f(ts..., &count, nullptr);
        check_res(err, "failed to get size");
        results.resize(count, init);
        err = f(ts..., &count, results.data());
        results.resize(count);
    } while (err == vk::Result::Incomplete);
    check_res(err, "failed to get data");
    return results;
}

template<typename T, typename F, typename... Ts>
auto GetVector(F&& f, Ts&&... ts) -> std::vector<T>
{
    return GetVectorInit(f, T(), ts...);
}

void create_renderer_context(RendererContext& context)
{

    check_res(vk::SimpleCppInitializeLoaderLibrary(), "Failed to initialize the loader library");

    context.window = create_window_glfw("Sample Triangle", false);
    check_res(context.window != nullptr, "Failed to create glfw window");

    uint32_t glfw_extension_count = 0;
    const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
    vk::InstanceCreateInfo inst_info{};
    inst_info.enabledExtensionCount = glfw_extension_count;
    inst_info.ppEnabledExtensionNames = glfw_extensions;

    auto layer_props = GetVector<vk::LayerProperties>(context.global_functions.EnumerateInstanceLayerProperties);

    const char* layer_names[] = { "VK_LAYER_KHRONOS_validation" };
    for (auto& layer : layer_props) {
        if (std::strcmp(layer.layerName, "VK_LAYER_KHRONOS_validation") == 0) {
            inst_info.ppEnabledLayerNames = layer_names;
            inst_info.enabledLayerCount = 1;
            break;
        }
    }

    check_res(context.global_functions.CreateInstance(&inst_info, nullptr, &context.instance), "Failed to init Vulkan Instance");

    vk::SimpleCppInitializeInstanceFunctions(context.instance);

    context.surface = create_surface_glfw(context.instance, context.window);
    check_res(context.surface != VK_NULL_HANDLE, "Failed to create glfw surface");

    auto physical_devices = GetVector<vk::PhysicalDevice>(context.instance_functions.EnumeratePhysicalDevices, context.instance);

    context.physical_device = physical_devices[0]; // get first physical device returned
    vk::Bool32 suppprted = 0;
    check_res(
      context.instance_functions.GetPhysicalDeviceSurfaceSupportKHR(context.physical_device, 0, context.surface, &suppprted),
      "Failed to query surface support");
    check_res(suppprted, "Surface doesn't support present");
}

void create_device_context(RendererContext& context)
{
    const char* extensions[] = { "VK_KHR_swapchain" };
    float priority = 1.f;
    vk::DeviceQueueCreateInfo queue_infos;
    queue_infos.pQueuePriorities = &priority;
    queue_infos.queueCount = 1;
    queue_infos.queueFamilyIndex = 0;
    vk::DeviceCreateInfo info;
    info.enabledExtensionCount = 1;
    info.ppEnabledExtensionNames = extensions;
    info.queueCreateInfoCount = 1;
    info.pQueueCreateInfos = &queue_infos;
    check_res(context.instance_functions.CreateDevice(context.physical_device, &info, nullptr, &context.device),
              "Failed to create a vulkan device");

    vk::SimpleCppInitializeDeviceDispatchTable(context.device, context.functions);
}

void setup_queues(RendererContext& context)
{
    uint32_t queue_family_size = 0;
    context.instance_functions.GetPhysicalDeviceQueueFamilyProperties(context.physical_device, &queue_family_size, nullptr);
    std::vector<vk::QueueFamilyProperties> queue_family_props(queue_family_size);
    context.instance_functions.GetPhysicalDeviceQueueFamilyProperties(
      context.physical_device, &queue_family_size, queue_family_props.data());

    uint32_t graphics_queue_family = 0;
    for (uint32_t i = 0; i < queue_family_props.size(); i++) {
        if (queue_family_props[0].queueFlags & vk::QueueFlagBits::Graphics && queue_family_props[0].queueCount > 0) {
            graphics_queue_family = i;
            break;
        }
    }
    check_res(graphics_queue_family == 0, "First queue isn't the graphics queue, implicit assumptions failed");

    context.functions.GetDeviceQueue(context.device, graphics_queue_family, 0, &context.graphics_queue);
}

void setup_swapchain(RendererContext& context)
{
    auto surf_formats = GetVector<vk::SurfaceFormatKHR>(
      context.instance_functions.GetPhysicalDeviceSurfaceFormatsKHR, context.physical_device, context.surface);

    vk::SurfaceCapabilitiesKHR surf_caps;
    check_res(
      context.instance_functions.GetPhysicalDeviceSurfaceCapabilitiesKHR(context.physical_device, context.surface, &surf_caps),
      "Failed to get surface capabilities");

    context.swapchain_img_format = surf_formats[0].format;
    context.image_count = 3;

    vk::SwapchainCreateInfoKHR info;
    info.surface = context.surface;
    info.minImageCount = 3;
    info.imageFormat = context.swapchain_img_format;
    info.imageColorSpace = surf_formats[0].colorSpace;
    info.imageExtent = { width, height };
    info.imageArrayLayers = 1;
    info.imageUsage = vk::ImageUsageFlagBits::ColorAttachment;
    info.imageSharingMode = vk::SharingMode::Exclusive;
    info.pQueueFamilyIndices = nullptr;
    info.preTransform = surf_caps.currentTransform;
    info.compositeAlpha = vk::CompositeAlphaFlagBitsKHR::OpaqueKHR;
    info.presentMode = vk::PresentModeKHR::FifoKHR;

    check_res(context.functions.CreateSwapchainKHR(context, &info, nullptr, &context.swapchain), "Unable to create Swapchain");

    context.swapchain_images = GetVector<vk::Image>(context.functions.GetSwapchainImagesKHR, context.device, context.swapchain);

    for (auto& image : context.swapchain_images) {
        vk::ImageViewCreateInfo view_info;
        view_info.image = image;
        view_info.viewType = vk::ImageViewType::e2D;
        view_info.format = context.swapchain_img_format;
        view_info.subresourceRange = { vk::ImageAspectFlagBits::Color, 0, 1, 0, 1 };
        vk::ImageView view;
        check_res(context.functions.CreateImageView(context, &view_info, nullptr, &view), "Failed to create swapchain image view");

        context.swapchain_image_views.push_back(view);
    }
}

void setup_renderpass(RendererContext& context)
{
    vk::AttachmentDescription desc;
    desc.format = context.swapchain_img_format;
    desc.samples = vk::SampleCountFlagBits::e1;
    desc.loadOp = vk::AttachmentLoadOp::Clear;
    desc.storeOp = vk::AttachmentStoreOp::Store;
    desc.stencilLoadOp = vk::AttachmentLoadOp::DontCare;
    desc.stencilStoreOp = vk::AttachmentStoreOp::DontCare;
    desc.initialLayout = vk::ImageLayout::Undefined;
    desc.finalLayout = vk::ImageLayout::PresentSrcKHR;

    vk::AttachmentReference ref{ 0, vk::ImageLayout::ColorAttachmentOptimal };
    vk::SubpassDescription sub_desc;
    sub_desc.pipelineBindPoint = vk::PipelineBindPoint::Graphics;
    sub_desc.pColorAttachments = &ref;
    sub_desc.colorAttachmentCount = 1;
    vk::SubpassDependency dep;
    dep.srcSubpass = VK_SUBPASS_EXTERNAL;
    dep.dstSubpass = 0;
    dep.srcStageMask = vk::PipelineStageFlagBits::ColorAttachmentOutput;
    dep.dstStageMask = vk::PipelineStageFlagBits::ColorAttachmentOutput;
    dep.dstAccessMask = vk::AccessFlagBits::ColorAttachmentRead | vk::AccessFlagBits::ColorAttachmentWrite;

    vk::RenderPassCreateInfo info;
    info.attachmentCount = 1;
    info.pAttachments = &desc;
    info.dependencyCount = 1;
    info.pDependencies = &dep;
    info.subpassCount = 1;
    info.pSubpasses = &sub_desc;
    check_res(context.functions.CreateRenderPass(context, &info, nullptr, &context.render_pass), "Failed to create renderpass");
}
void create_framebuffers(RendererContext& context)
{
    for (auto& view : context.swapchain_image_views) {
        vk::FramebufferCreateInfo info;
        info.renderPass = context.render_pass;
        info.attachmentCount = 1;
        info.pAttachments = &view;
        info.width = width;
        info.height = height;
        info.layers = 1;
        vk::Framebuffer framebuffer;
        check_res(context.functions.CreateFramebuffer(context, &info, nullptr, &framebuffer), "Failed to create framebuffer");
        context.framebuffers.push_back(framebuffer);
    }
}

std::vector<char> read_file(const std::string& filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);
    check_res(file.is_open(), "Failed to open shader file");

    size_t file_size = (size_t)file.tellg();
    std::vector<char> buffer(file_size);
    file.seekg(0);
    file.read(buffer.data(), static_cast<std::streamsize>(file_size));
    file.close();
    return buffer;
}

vk::ShaderModule create_shader_module(RendererContext& context, std::string const& filename)
{
    auto code = read_file(filename);
    vk::ShaderModule mod;
    vk::ShaderModuleCreateInfo info;
    info.codeSize = code.size();
    info.pCode = reinterpret_cast<const uint32_t*>(code.data());
    check_res(context.functions.CreateShaderModule(context, &info, nullptr, &mod), "Failed to create shader module");
    return mod;
}

void create_pipeline(RendererContext& context)
{
    vk::ShaderModule vert = create_shader_module(context, "vert.spv");
    vk::ShaderModule frag = create_shader_module(context, "frag.spv");
    vk::PipelineLayoutCreateInfo p_info_cr;
    check_res(context.functions.CreatePipelineLayout(context, &p_info_cr, nullptr, &context.pipeline_layout),
              "Failed to create pipeline layout");

    vk::Viewport viewport = { 0.f, 0.f, static_cast<float>(width), static_cast<float>(height), 0.f, 1.f };
    vk::Rect2D scissor = { { 0, 0 }, { width, height } };
    vk::PipelineShaderStageCreateInfo vert_stage;
    vert_stage.stage = vk::ShaderStageFlagBits::Vertex;
    vert_stage.module = vert;
    vert_stage.pName = "main";
    vk::PipelineShaderStageCreateInfo frag_stage;
    frag_stage.stage = vk::ShaderStageFlagBits::Fragment;
    frag_stage.module = frag;
    frag_stage.pName = "main";
    vk::PipelineShaderStageCreateInfo shaders[2] = { vert_stage, frag_stage };
    vk::PipelineVertexInputStateCreateInfo vert_input;
    vk::PipelineInputAssemblyStateCreateInfo input_assembly;
    input_assembly.topology = vk::PrimitiveTopology::TriangleList;
    vk::PipelineViewportStateCreateInfo viewport_state;
    viewport_state.viewportCount = 1;
    viewport_state.pViewports = &viewport;
    viewport_state.scissorCount = 1;
    viewport_state.pScissors = &scissor;
    vk::PipelineRasterizationStateCreateInfo rasterization;
    rasterization.polygonMode = vk::PolygonMode::Fill;
    rasterization.cullMode = vk::CullModeFlagBits::Back;
    rasterization.frontFace = vk::FrontFace::Clockwise;
    rasterization.lineWidth = 1.f;
    vk::PipelineMultisampleStateCreateInfo multisample;
    multisample.rasterizationSamples = vk::SampleCountFlagBits::e1;
    multisample.sampleShadingEnable = false;
    vk::PipelineColorBlendAttachmentState blend_attachment;
    blend_attachment.blendEnable = false;
    blend_attachment.colorWriteMask =
      vk::ColorComponentFlagBits::R | vk::ColorComponentFlagBits::G | vk::ColorComponentFlagBits::B | vk::ColorComponentFlagBits::A;
    vk::PipelineColorBlendStateCreateInfo color_blend;
    color_blend.logicOpEnable = false;
    color_blend.pAttachments = &blend_attachment;
    color_blend.attachmentCount = 1;

    vk::DynamicState states[2] = { vk::DynamicState::Viewport, vk::DynamicState::Scissor };
    vk::PipelineDynamicStateCreateInfo dynamic_state;
    dynamic_state.dynamicStateCount = 2;
    dynamic_state.pDynamicStates = states;

    vk::GraphicsPipelineCreateInfo info;
    info.renderPass = context.render_pass;
    info.layout = context.pipeline_layout;
    info.stageCount = 2;
    info.pStages = &shaders[0];
    info.pVertexInputState = &vert_input;
    info.pInputAssemblyState = &input_assembly;
    info.pViewportState = &viewport_state;
    info.pRasterizationState = &rasterization;
    info.pMultisampleState = &multisample;
    info.pColorBlendState = &color_blend;
    info.pDynamicState = &dynamic_state;

    check_res(context.functions.CreateGraphicsPipelines(context, VK_NULL_HANDLE, 1, &info, nullptr, &context.pipeline),
              "Failed to create graphipcs pipeline");
    context.functions.DestroyShaderModule(context, vert, nullptr);
    context.functions.DestroyShaderModule(context, frag, nullptr);
}

void create_command_buffers(RendererContext& context)
{
    vk::CommandPoolCreateInfo pool_info;
    check_res(context.functions.CreateCommandPool(context, &pool_info, nullptr, &context.cmd_pool),
              "Failed to create command pool");

    vk::CommandBufferAllocateInfo alloc_info;
    alloc_info.commandPool = context.cmd_pool;
    alloc_info.level = vk::CommandBufferLevel::Primary;
    alloc_info.commandBufferCount = context.image_count;
    context.cmd_buffers.resize(3);
    check_res(context.functions.AllocateCommandBuffers(context, &alloc_info, context.cmd_buffers.data()),
              "Failed to create command buffers");

    size_t i = 0;
    for (auto& cmd_buf : context.cmd_buffers) {

        vk::CommandBufferBeginInfo begin_info{};
        check_res(context.functions.BeginCommandBuffer(cmd_buf, &begin_info), "Failed to begin command buffer");

        vk::Viewport viewport = { 0.f, 0.f, static_cast<float>(width), static_cast<float>(height), 0.f, 1.f };
        vk::Rect2D scissor = { { 0, 0 }, { width, height } };
        vk::ClearValue clear_colors = { { 0.f, 0.f, 0.f, 1.f } };

        vk::RenderPassBeginInfo renderpass_info;
        renderpass_info.renderPass = context.render_pass;
        renderpass_info.framebuffer = context.framebuffers[i++];
        renderpass_info.renderArea = scissor;
        renderpass_info.clearValueCount = 4;
        renderpass_info.pClearValues = &clear_colors;

        context.functions.CmdBeginRenderPass(cmd_buf, &renderpass_info, vk::SubpassContents::Inline);
        context.functions.CmdBindPipeline(cmd_buf, vk::PipelineBindPoint::Graphics, context.pipeline);
        context.functions.CmdSetViewport(cmd_buf, 0, 1, &viewport);
        context.functions.CmdSetScissor(cmd_buf, 0, 1, &scissor);
        context.functions.CmdDraw(cmd_buf, 3, 1, 0, 0);
        context.functions.CmdEndRenderPass(cmd_buf);
        check_res(context.functions.EndCommandBuffer(cmd_buf), "Failed to end command buffer");
    }
}

void setup_sync_objects(RendererContext& context)
{
    context.fences.resize(context.image_count);
    context.available_semaphores.resize(context.image_count);
    context.finished_semaphores.resize(context.image_count);
    for (uint32_t i = 0; i < context.image_count; i++) {
        vk::FenceCreateInfo fence_info;
        fence_info.flags = vk::FenceCreateFlagBits::Signaled;
        check_res(context.functions.CreateFence(context, &fence_info, nullptr, &context.fences[i]), "Failed to create fence");
        vk::SemaphoreCreateInfo sem_info;
        check_res(context.functions.CreateSemaphore(context, &sem_info, nullptr, &context.available_semaphores[i]),
                  "Failed to create semaphore");
        check_res(context.functions.CreateSemaphore(context, &sem_info, nullptr, &context.finished_semaphores[i]),
                  "Failed to create semaphore");
    }
}

void recreate_swapchain(RendererContext& context)
{
    check_res(context.functions.QueueWaitIdle(context.graphics_queue), "");
    context.functions.DestroyCommandPool(context, context.cmd_pool, nullptr);

    for (auto& framebuffer : context.framebuffers) {
        context.functions.DestroyFramebuffer(context, framebuffer, nullptr);
    }
    for (auto& image_view : context.swapchain_image_views) {
        context.functions.DestroyImageView(context, image_view, nullptr);
    }

    setup_swapchain(context);
    create_framebuffers(context);
    create_command_buffers(context);
}

void draw_frame(RendererContext& context)
{
    check_res(context.functions.WaitForFences(context, 1, &context.fences[context.current_frame], true, UINT64_MAX),
              "Failed to wait for fence");

    check_res(context.functions.ResetFences(context, 1, &context.fences[context.current_frame]), "Failed to reset fence");

    uint32_t image_index;
    auto image_index_ret = context.functions.AcquireNextImageKHR(
      context, context.swapchain, UINT64_MAX, context.available_semaphores[context.current_frame], nullptr, &image_index);
    if (image_index_ret == vk::Result::ErrorOutOfDateKHR) {
        return recreate_swapchain(context);
    } else if (image_index_ret != vk::Result::Success && image_index_ret != vk::Result::SuboptimalKHR) {
        std::cerr << "failed to acquire swapchain image. Error " << std::to_string(static_cast<uint32_t>(image_index_ret)) << "\n";
    }
    vk::PipelineStageFlags dst_stage_mask = vk::PipelineStageFlagBits::ColorAttachmentOutput;
    vk::SubmitInfo submit_info;
    submit_info.waitSemaphoreCount = 1;
    submit_info.pWaitSemaphores = &context.available_semaphores[context.current_frame];
    submit_info.pWaitDstStageMask = &dst_stage_mask;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers = &context.cmd_buffers[image_index];
    submit_info.signalSemaphoreCount = 1;
    submit_info.pSignalSemaphores = &context.finished_semaphores[context.current_frame];
    check_res(context.functions.QueueSubmit(context.graphics_queue, 1, &submit_info, context.fences[context.current_frame]),
              "Failed to submit command buffer");

    vk::PresentInfoKHR present_info;
    present_info.waitSemaphoreCount = 1;
    present_info.pWaitSemaphores = &context.finished_semaphores[context.current_frame];
    present_info.swapchainCount = 1;
    present_info.pSwapchains = &context.swapchain;
    present_info.pImageIndices = &image_index;
    auto present_ret = context.functions.QueuePresentKHR(context.graphics_queue, &present_info);
    if (present_ret == vk::Result::ErrorOutOfDateKHR || present_ret == vk::Result::SuboptimalKHR) {
        return recreate_swapchain(context);
    }
    check_res(present_ret, "Failed to present");

    context.current_frame = (context.current_frame + 1) % context.image_count;
}

void destroy_device(RendererContext& context)
{
    for (auto& sem : context.available_semaphores) {
        context.functions.DestroySemaphore(context, sem, nullptr);
    }
    for (auto& sem : context.finished_semaphores) {
        context.functions.DestroySemaphore(context, sem, nullptr);
    }
    for (auto& fence : context.fences) {
        context.functions.DestroyFence(context, fence, nullptr);
    }
    context.functions.DestroyCommandPool(context, context.cmd_pool, nullptr);
    for (auto& framebuffer : context.framebuffers) {
        context.functions.DestroyFramebuffer(context, framebuffer, nullptr);
    }
    context.functions.DestroyPipeline(context, context.pipeline, nullptr);
    context.functions.DestroyPipelineLayout(context, context.pipeline_layout, nullptr);
    context.functions.DestroyRenderPass(context, context.render_pass, nullptr);
    for (auto& image_view : context.swapchain_image_views) {
        context.functions.DestroyImageView(context, image_view, nullptr);
    }
    context.functions.DestroySwapchainKHR(context, context.swapchain, nullptr);
    context.functions.DestroyDevice(context, nullptr);
}

void destroy_renderer(RendererContext& context)
{
    context.instance_functions.DestroySurfaceKHR(context.instance, context.surface, nullptr);
    context.instance_functions.DestroyInstance(context.instance, nullptr);
    vk::SimpleCppCloseLoaderLibrary();
    destroy_window_glfw(context.window);
}

int main()
{
    RendererContext context;

    create_renderer_context(context);
    create_device_context(context);
    setup_queues(context);
    setup_swapchain(context);
    setup_renderpass(context);
    create_framebuffers(context);
    create_pipeline(context);
    create_command_buffers(context);
    setup_sync_objects(context);

    while (!glfwWindowShouldClose(context.window)) {
        glfwPollEvents();
        draw_frame(context);
    }
    check_res(context.functions.QueueWaitIdle(context.graphics_queue), "Couldn't wait to shut down");
    destroy_device(context);
    destroy_renderer(context);
    return 0;
}
