// GL includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#ifdef _WIN32
#pragma comment (lib, "glfw3") // force load library
#endif

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "windowName", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // clear background
        glClearColor(0.0f, 1.f, 0.0f, 1.0f);
        // clear buffer bits
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keyspressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // glfw: terminate, clearing all previously allocated GLFWresources.
    glfwTerminate();
    return 0;
}