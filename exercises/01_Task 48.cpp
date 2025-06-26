#include <iostream>

int main() {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;

    std::cout << "Enter coordinates of the first point (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of the second point (x2, y2): ";
    std::cin >> x2 >> y2;

    if (x2 - x1 == 0)
        std::cout << "Straight is vertical, slope is undefined." << std::endl;
    else {
        double slope = (y2 - y1) / (x2 - x1);
        std::cout << "Slope of the straight is: " << slope << std::endl;
    }

    return 0;
}