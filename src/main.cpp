#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib> // EXIT_SUCCESS & EXIT_FAILURE macros

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:

    void initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Don't create an OpenGL context
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resize of window for now

        // The first three parameters specify the width, height and title of the window. The fourth parameter allows you to optionally
        // specify a monitor to open the window on and the last parameter is only relevant to OpenGL.
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr); // Create the window
    }

    void initVulkan() {

    }

    void mainLoop() {
        // Keep the application running until either an error occurs or the window is closed
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
    }

private:

    GLFWwindow* window;
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}