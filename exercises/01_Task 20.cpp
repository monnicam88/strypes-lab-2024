#include <iostream>
#include <iomanip>

int main() {
    const double NUMBERS_COUNT = 3.0;
    long double firstNumber = 0.0, secondNumber = 0.0, thirdNumber = 0.0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;
    std::cout << "Enter the third number: ";
    std::cin >> thirdNumber;

    double average = (firstNumber + secondNumber + thirdNumber) / NUMBERS_COUNT;

    double deviation1 = firstNumber - average;
    double deviation2 = secondNumber - average;
    double deviation3 = thirdNumber - average;

    std::cout << std::fixed << std::setprecision(5) << "The average value is: " << average << std::endl;
    std::cout << std::fixed << std::setprecision(5) 
              << "The deviation of " << firstNumber << " than the average value is: " << deviation1 << std::endl;
    std::cout << std::fixed << std::setprecision(5) 
              << "The deviation of " << secondNumber << " than the average value is: " << deviation2 << std::endl;
    std::cout << std::fixed << std::setprecision(5) 
              << "The deviation of " << thirdNumber << " than the average value is: " << deviation3 << std::endl;

    return 0;
}