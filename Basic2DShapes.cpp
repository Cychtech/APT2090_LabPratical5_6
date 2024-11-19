#include <GLFW/glfw3.h>
#include <iostream>
#include "Basic2DShapes.h"

void basic2DShapes() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Basic 2D Shapes", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}


