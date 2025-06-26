#include <iostream>

int main() {
    long double firstNumber = 0.0, secondNumber = 0.0, thirdNumber = 0.0;

    std::cout << "Enter three real numbers: ";
    std::cin >> firstNumber >> secondNumber >> thirdNumber;

    double maxNumber = std::max(firstNumber, std::max(secondNumber, thirdNumber));
    double minNumber = std::min(firstNumber, std::min(secondNumber, thirdNumber));

    std::cout << "The difference between the MAX and MIN number is: " 
              << (maxNumber - minNumber) << std::endl;

    return 0;
}