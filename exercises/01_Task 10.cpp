#include <iostream>

int main() {
    const double FORMULA_MULTIPLIER = (9.0 / 5.0);
    const double FORMULA_DIVIDER = 32.0;
    double celsius = 0.0, fahrenheit = 0.0;

    std::cout << "Enter temperature in Celsius degrees: ";
    std::cin >> celsius;

    fahrenheit = (celsius * FORMULA_MULTIPLIER) + FORMULA_DIVIDER;
    std::cout << "The Fahrenheit temperature is: " << fahrenheit << std::endl;

    return 0;
}