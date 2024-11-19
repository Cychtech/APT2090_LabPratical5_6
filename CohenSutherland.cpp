#include <GLFW/glfw3.h>
#include <iostream>
#include "CohenSutherland.h"

// Define the clipping window bounds
const int LEFT = -1, RIGHT = 1, BOTTOM = -1, TOP = 1;

// Outcode bits
const int INSIDE = 0x0, LEFT_BIT = 0x1, RIGHT_BIT = 0x2, BOTTOM_BIT = 0x4, TOP_BIT = 0x8;

int computeOutCode(float x, float y) {
    int code = INSIDE;
    if (x < LEFT) code |= LEFT_BIT;
    else if (x > RIGHT) code |= RIGHT_BIT;
    if (y < BOTTOM) code |= BOTTOM_BIT;
    else if (y > TOP) code |= TOP_BIT;
    return code;
}

void cohenSutherlandClipping() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Cohen-Sutherland Line Clipping", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Define the line endpoints
        float x0 = -1.5f, y0 = -1.5f, x1 = 1.5f, y1 = 1.5f;

        int outcode0 = computeOutCode(x0, y0);
        int outcode1 = computeOutCode(x1, y1);
        bool accept = false;

        while (true) {
            if ((outcode0 & outcode1) != 0) { // Trivial reject
                break;
            }
            else if ((outcode0 | outcode1) == 0) { // Trivial accept
                accept = true;
                break;
            }
            else { // Compute intersection
                float x, y;
                int outcodeOut = (outcode0 != 0) ? outcode0 : outcode1;

                // Find intersection point
                if (outcodeOut & TOP_BIT) { // Line is above the clip window
                    x = x0 + (x1 - x0) * (TOP - y0) / (y1 - y0);
                    y = TOP;
                }
                else if (outcodeOut & BOTTOM_BIT) { // Line is below the clip window
                    x = x0 + (x1 - x0) * (BOTTOM - y0) / (y1 - y0);
                    y = BOTTOM;
                }
                else if (outcodeOut & RIGHT_BIT) { // Line is to the right of the clip window
                    y = y0 + (y1 - y0) * (RIGHT - x0) / (x1 - x0);
                    x = RIGHT;
                }
                else if (outcodeOut & LEFT_BIT) { // Line is to the left of the clip window
                    y = y0 + (y1 - y0) * (LEFT - x0) / (x1 - x0);
                    x = LEFT;
                }

                // Update the endpoint outside the clipping window
                if (outcodeOut == outcode0) {
                    x0 = x;
                    y0 = y;
                    outcode0 = computeOutCode(x0, y0);
                }
                else {
                    x1 = x;
                    y1 = y;
                    outcode1 = computeOutCode(x1, y1);
                }
            }
        }

        if (accept) {
            // Draw the clipped line
            glBegin(GL_LINES);
            glVertex2f(x0, y0);
            glVertex2f(x1, y1);
            glEnd();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
