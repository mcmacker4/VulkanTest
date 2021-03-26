#include "Window.h"

Window::Window(GLFWwindow* handle) : handle(handle) {}

Window::~Window() { glfwDestroyWindow(handle); }

glm::ivec2 Window::size() {
    glm::ivec2 size;
    glfwGetWindowSize(handle, &size.x, &size.y);
    return size;
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(handle) == GLFW_TRUE;
}

void Window::swapBuffers() { glfwSwapBuffers(handle); }

void Window::setVisible(bool visible) {
    if (visible) {
        glfwShowWindow(handle);
    } else {
        glfwHideWindow(handle);
    }
}

Window* Window::create_windowed(int width, int height, const char* title) {

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    GLFWwindow* hnd = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (hnd == nullptr) {
        std::string msg("Could not create GLFW window.");
        throw WindowException(msg);
    }

    const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(hnd, (vidmode->width - width) / 2,
                     (vidmode->height - height) / 2);

    return new Window(hnd);
}

const char* WindowException::what() const noexcept { return message.c_str(); }

std::ostream& operator<<(std::ostream& o, const WindowException& ex) {
    o << ex.message;
    return o;
}
