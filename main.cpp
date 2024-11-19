#include <iostream>
#include "Basic2DShapes.h"
#include "Rotating3DCube.h"
#include "BresenhamLine.h"
#include "MidpointCircle.h"
#include "Pyramid3D.h"
#include "AnimateSquare.h"
#include "CohenSutherland.h"

void displayMenu() {
    std::cout << "Select an option:\n";
    std::cout << "1. Draw Basic 2D Shapes\n";
    std::cout << "2. Rotate a 3D Cube\n";
    std::cout << "3. Bresenham's Line Drawing Algorithm\n";
    std::cout << "4. Midpoint Circle Algorithm\n";
    std::cout << "5. Draw a 3D Pyramid\n";
    std::cout << "6. Animate a 2D Square\n";
    std::cout << "7. Cohen-Sutherland Line Clipping\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            basic2DShapes();
            break;
        case 2:
            rotating3DCube();
            break;
        case 3:
            bresenhamLine();
            break;
        case 4:
            midpointCircle();
            break;
        case 5:
            pyramid3D();
            break;
        case 6:
            animateSquare();
            break;
        case 7:
            cohenSutherlandClipping();
            break;
        case 0:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
