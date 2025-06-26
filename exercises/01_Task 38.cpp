#include <iostream>

int main() {
    int firstNumber = 0, secondNumber = 0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    if (secondNumber == 0)
        std::cerr << "Error: Division by zero is not possible." << std::endl;
    else {
        int quotient = firstNumber / secondNumber;
        int residue = firstNumber % secondNumber;

        std::cout << std::endl;
        std::cout << "Division result: " << quotient << std::endl;
        std::cout << "Residue of division: " << residue << std::endl;
    }

    return 0;
}