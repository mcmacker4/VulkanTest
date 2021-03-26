#ifndef VULKANTEST_VULKANTEST_H
#define VULKANTEST_VULKANTEST_H

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

#include <memory>

#include "window/Window.h"

class VulkanTest {

    Window* window;
    vk::Instance instance;

  public:
    VulkanTest();
    VulkanTest(const VulkanTest&) = delete;

    void start();

  private:
    void init();
    void update();
    void render();
    void cleanup();

    void createInstance();

};

#endif // VULKANTEST_VULKANTEST_H
