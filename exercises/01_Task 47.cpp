#include <iostream>

int main() {
    const double FORMULA_MULTIPLIER = (5.0 / 9.0);
    const double FORMULA_CONSTANT_SUBSTRACTED = 32.0;
    double celsius = 0.0, fahrenheit = 0.0;

    std::cout << "Enter temperature in Fahrenheit degrees: ";
    std::cin >> fahrenheit;

    celsius = (fahrenheit - FORMULA_CONSTANT_SUBSTRACTED) * FORMULA_MULTIPLIER;
    std::cout << "The Celsius temperature is: " << celsius << std::endl;

    return 0;
}