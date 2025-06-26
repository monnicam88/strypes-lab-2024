#include <iostream>

int main() {
    long long int firstNumber = 0, secondNumber = 0, thirdNumber = 0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;
    std::cout << "Enter the third number: ";
    std::cin >> thirdNumber;

    long long int maxNumber = firstNumber;

    if (secondNumber > maxNumber)
        maxNumber = secondNumber;
    if (thirdNumber > maxNumber)
        maxNumber = thirdNumber;
    std::cout << "The largest of the three numbers is: " << maxNumber << std::endl;

    return 0;
}