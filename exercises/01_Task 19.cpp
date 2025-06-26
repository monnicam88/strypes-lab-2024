#include <iostream>

int main() {
    int firstNumber = 0, secondNumber = 0, thirdNumber = 0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;
    std::cout << "Enter the third number: ";
    std::cin >> thirdNumber;

    long long int product = firstNumber * secondNumber * thirdNumber;

    std::cout << "The multiplication of " << firstNumber << ", " << secondNumber
              << " and " << thirdNumber << " is: " << product << std::endl;

    return 0;
}