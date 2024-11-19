#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <cmath>
#include <iostream>
#include "Rotating3DCube.h"

void rotating3DCube() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Rotating 3D Cube", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST); // Enable depth testing

    // Initialize GLM for the projection matrix
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)); // Move the camera back

    float angleX = 0.0f, angleY = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen and depth buffer

        glLoadIdentity();
        glMultMatrixf(glm::value_ptr(projection));  // Apply projection matrix
        glMultMatrixf(glm::value_ptr(view));  // Apply view matrix

        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotate along X-axis
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotate along Y-axis

        // Front face (Red)
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glEnd();

        // Back face (Green)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glEnd();

        // Left face (Blue)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glEnd();

        // Right face (Yellow)
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glEnd();

        // Top face (Cyan)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glEnd();

        // Bottom face (Magenta)
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

        angleX += 0.005f;
        angleY += 0.005f;
    }

    glfwTerminate();
}


