#include <iostream>

int main() {
    const short int PERCENTAGE_CONSTANT = 100;
    double A = 0.0, B = 0.0;

    std::cout << "Enter the value for A: ";
    std::cin >> A;
    std::cout << "Enter the value for B: ";
    std::cin >> B;

    if (A < 0 || B < 0) {
        std::cerr << "Error: Only positive values for A and B are allowed." << std::endl;
        return 1;
    }
    else if (B == 0) {
        std::cerr << "Error: Division by zero is not possible." << std::endl;
        return 1;
    }
 
    double percentageFrom = (A / B) * PERCENTAGE_CONSTANT;
    std::cout << A << " is " << percentageFrom << "% from " << B << std::endl;

    return 0;
}