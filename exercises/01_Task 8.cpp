#include <iostream>

int main() {
    long long int firstNumber = 0, secondNumber = 0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    if (secondNumber == 0)
        std::cerr << "Error: Division by zero is not possible." << std::endl;
    else {
        if (firstNumber % secondNumber == 0)
            std::cout << firstNumber << " is divided exactly into " << secondNumber << std::endl;
        else std::cerr << "Error: " << firstNumber << " is not exactly divided into " << secondNumber << std::endl;
    }

    return 0;
}