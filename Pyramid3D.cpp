#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

void pyramid3D() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Pyramid", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST); // Enable depth testing

    // Set up projection matrix (Perspective)
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    float cameraRadius = 5.0f; // Distance of the camera from the pyramid's center
    float cameraAngle = 0.0f;  // Initial camera angle (used for rotating around the pyramid)

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen and depth buffer

        // Calculate camera position using trigonometry (circular motion around the pyramid)
        float cameraX = cameraRadius * cos(glm::radians(cameraAngle));
        float cameraZ = cameraRadius * sin(glm::radians(cameraAngle));

        // Set up view matrix (Camera)
        glm::mat4 view = glm::lookAt(
            glm::vec3(cameraX, 2.0f, cameraZ),  // Camera position
            glm::vec3(0.0f, 0.0f, 0.0f),       // Focus point (center of pyramid)
            glm::vec3(0.0f, 1.0f, 0.0f)        // Up direction (Y-axis)
        );

        // Apply the projection and view matrix
        glLoadIdentity();
        glMultMatrixf(glm::value_ptr(projection));  // Apply projection matrix
        glMultMatrixf(glm::value_ptr(view));       // Apply view matrix

        glBegin(GL_TRIANGLES); // Draw the pyramid as triangles

        // Base of the pyramid (Square)
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for base
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-right
        glVertex3f(1.0f, -1.0f, 1.0f); // Top-right

        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(1.0f, -1.0f, 1.0f); // Top-right
        glVertex3f(-1.0f, -1.0f, 1.0f); // Top-left

        // Sides of the pyramid (4 triangles)
        glColor3f(0.0f, 1.0f, 0.0f); // Green color for sides

        // Front side
        glVertex3f(0.0f, 1.0f, 0.0f); // Top
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-right

        // Right side
        glVertex3f(0.0f, 1.0f, 0.0f); // Top
        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-right
        glVertex3f(1.0f, -1.0f, 1.0f); // Bottom-left

        // Back side
        glVertex3f(0.0f, 1.0f, 0.0f); // Top
        glVertex3f(1.0f, -1.0f, 1.0f); // Bottom-right
        glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left

        // Left side
        glVertex3f(0.0f, 1.0f, 0.0f); // Top
        glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left
        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-right

        glEnd(); // End drawing the pyramid

        glfwSwapBuffers(window);
        glfwPollEvents();

        cameraAngle += 0.005f; // Increment the camera angle to rotate around the pyramid
    }

    glfwTerminate();
}
