#include <iostream>

int main() {
    double width = 0.0, height = 0.0;

    std::cout << "Enter the rectangle width: ";
    std::cin >> width;
    std::cout << "Enter the rectangle height: ";
    std::cin >> height;

    double area = width * height;
    double perimeter = 2 * (width + height);

    std::cout << "The area of rectangle is: " << area << std::endl;
    std::cout << "The perimeter of rectangle is: " << perimeter << std::endl;

    return 0;
}