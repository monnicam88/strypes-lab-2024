#include <iostream>
#include <cmath> 

int main() {
    double firstNumber = 0.0, secondNumber = 0.0;

    std::cout << "Enter the first positive number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second positive number: ";
    std::cin >> secondNumber;

    if (firstNumber <= 0 || secondNumber <= 0) 
        std::cout << "Please, enter only positive numbers." << std::endl;
    else {
        double geometricMean = std::sqrt(firstNumber * secondNumber);
        std::cout << "The geometric mean of " << firstNumber << " and " << secondNumber << " is: " << geometricMean << std::endl;
    }

    return 0;
}