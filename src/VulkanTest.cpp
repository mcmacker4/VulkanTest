#include "VulkanTest.h"

VulkanTest::VulkanTest() { window = nullptr; }

void VulkanTest::start() {
    init();

    window->setVisible(true);

    while (!window->shouldClose()) {
        update();
        render();
    }

    cleanup();
}

void VulkanTest::init() {
    if (glfwInit() != GLFW_TRUE) {
        throw WindowException("Could not initialize GLFW window.");
    }
    window = Window::create_windowed(1024, 576, "Vulkan Test");
}

void VulkanTest::createInstance() {
    vk::ApplicationInfo appInfo("Vulkan Test", VK_MAKE_VERSION(1, 0, 0),
                                "No Engine", VK_MAKE_VERSION(1, 0, 0),
                                VK_API_VERSION_1_0);
    uint32_t glfwExtensionsCount;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);

    vk::InstanceCreateInfo createInfo({}, &appInfo, 0, nullptr, glfwExtensionsCount, glfwExtensions);

    if (vk::createInstance(&createInfo, nullptr, &instance) != vk::Result::eSuccess) {
        throw std::runtime_error("Could not create VkInstance.");
    }

}

void VulkanTest::update() { glfwPollEvents(); }

void VulkanTest::render() { window->swapBuffers(); }

void VulkanTest::cleanup() {
    delete window;
    glfwTerminate();
}