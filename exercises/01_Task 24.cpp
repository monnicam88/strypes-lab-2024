#include <iostream>
#include <cmath>

int main() {
    long double number = 0.0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    if (number < 0)
        std::cout << "The square root is not defined for negative numbers." << std::endl;
    else {
        double squareRoot = std::sqrt(number);
        std::cout << "Square root of number " << number << " is: " << squareRoot << std::endl;
    }

    return 0;
}