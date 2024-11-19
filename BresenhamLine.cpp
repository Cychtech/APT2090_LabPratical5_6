#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void plotLineLow(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int D = 2 * dy - dx;
    int y = y0;

    for (int x = x0; x <= x1; x++) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        if (D > 0) {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
    }
}

void plotLineHigh(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = 2 * dx - dy;
    int x = x0;

    for (int y = y0; y <= y1; y++) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        if (D > 0) {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
    }
}

void bresenhamLine() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Bresenham's Line Algorithm", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    // Set up orthogonal projection for 2D drawing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800, 0.0, 600, -1.0, 1.0); // Orthogonal projection for 2D

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Line from (100, 100) to (700, 500)
        int x0 = 100, y0 = 100, x1 = 700, y1 = 500;

        // Check if the line is steep or not
        if (abs(y1 - y0) < abs(x1 - x0)) {
            if (x0 > x1) {
                plotLineLow(x1, y1, x0, y0);
            }
            else {
                plotLineLow(x0, y0, x1, y1);
            }
        }
        else {
            if (y0 > y1) {
                plotLineHigh(x1, y1, x0, y0);
            }
            else {
                plotLineHigh(x0, y0, x1, y1);
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
