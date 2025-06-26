#include <iostream>

int main() {
    long long int firstNumber = 0, secondNumber = 0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    std::cout << "The difference between " << firstNumber << " and " << secondNumber
              << " is: " << (firstNumber - secondNumber) << std::endl;

    return 0;
}