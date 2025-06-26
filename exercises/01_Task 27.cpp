#include <iostream>

int main() {
    const double RECIPROCAL_DIVISIBLE = 1.0;
    double number = 0.0;

    std::cout << "Enter a real number: ";
    std::cin >> number;

    if (number == 0) 
        std::cerr << "Error: The reciprocal is not defined for zero." << std::endl;
    else {
        double inverse = RECIPROCAL_DIVISIBLE / number;
        std::cout << "The reciprocal of number " << number << " is: " 
                  << inverse << " = 1/" << number << std::endl;
    }

    return 0;
}