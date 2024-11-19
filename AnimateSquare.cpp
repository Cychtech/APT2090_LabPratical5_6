#include <GLFW/glfw3.h>
#include <iostream>
#include "AnimateSquare.h"

void animateSquare() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Animate 2D Square", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    float xPos = -0.9f; // Starting position
    float speed = 0.0001f; // Speed of movement

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glLoadIdentity();
        glTranslatef(xPos, 0.0f, 0.0f); // Move the square horizontally

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
        glEnd();

        // Move the square to the right
        xPos += speed;
        if (xPos > 1.0f) {
            xPos = -1.0f; // Reset position when it goes off screen
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
