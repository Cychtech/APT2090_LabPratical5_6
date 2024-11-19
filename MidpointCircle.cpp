#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void plotCirclePoints(int xc, int yc, int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y); // Top-right
    glVertex2i(xc - x, yc + y); // Top-left
    glVertex2i(xc + x, yc - y); // Bottom-right
    glVertex2i(xc - x, yc - y); // Bottom-left
    glVertex2i(xc + y, yc + x); // Top-right rotated
    glVertex2i(xc - y, yc + x); // Top-left rotated
    glVertex2i(xc + y, yc - x); // Bottom-right rotated
    glVertex2i(xc - y, yc - x); // Bottom-left rotated
    glEnd();
}

void midpointCircle() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Midpoint Circle Algorithm", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    // Set up orthographic projection for 2D drawing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800, 0.0, 600, -1.0, 1.0); // Orthogonal projection for 2D

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        int xc = 400, yc = 300, r = 100; // Adjusted circle center and radius
        int x = 0, y = r;
        int p = 1 - r;

        plotCirclePoints(xc, yc, x, y);

        while (x < y) {
            x++;
            if (p < 0) {
                p += 2 * x + 1;
            }
            else {
                y--;
                p += 2 * x - 2 * y + 1;
            }
            plotCirclePoints(xc, yc, x, y);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
