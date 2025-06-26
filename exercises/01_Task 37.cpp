#include <iostream>

int main() {
    const double TRIANGLE_AREA_FORMULA_CONSTANT = 0.5;
    double base = 0.0, height = 0.0;

    std::cout << "Enter the triangle base: ";
    std::cin >> base;
    std::cout << "Enter the triangle height: ";
    std::cin >> height;

    if (base < 0 || height < 0) {
        std::cerr << "Error: Both input values must be positive numbers." << std::endl;
        return 1;
    }

    long double area = TRIANGLE_AREA_FORMULA_CONSTANT * base * height;
    std::cout << "Area of the triangle is: " << area << std::endl;

    return 0;
}