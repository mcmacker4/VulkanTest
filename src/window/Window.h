#ifndef VULKANTEST_WINDOW_H
#define VULKANTEST_WINDOW_H

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include <string>

class Window {

    GLFWwindow* handle;

    explicit Window(GLFWwindow* handle);

  public:
    ~Window();

    glm::ivec2 size();

    bool shouldClose();
    void swapBuffers();
    void setVisible(bool visible);

    static Window* create_windowed(int width, int height, const char* title);
    // static Window create_fullscreen(int width, int height, const char* title, GLFWmonitor* monitor);

};


class WindowException : public std::exception {
    std::string message;

  public:
    explicit WindowException(std::string msg) : message(std::move(msg)) {}

    const char* what() const noexcept override;

    friend std::ostream& operator<<(std::ostream& o, const WindowException& ex);
};

#endif // VULKANTEST_WINDOW_H
