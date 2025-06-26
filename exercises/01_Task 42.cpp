#include <iostream>

int main() {
    int number = 0;
    
    std::cout << "Enter a whole number: ";
    std::cin >> number;

    if (number == 0) {
        std::cerr << "Error: The following operation is not defined for zero." << std::endl;
        return 1;
    }

    int copyNumber = number;
    int reversedNumber = 0;

    while (copyNumber != 0) {
        int digit = copyNumber % 10;
        reversedNumber = reversedNumber * 10 + digit;
        copyNumber /= 10;
    }

    std::cout << "The reciprocal of the number " << number << " is: 0." << reversedNumber << std::endl;

    return 0;
}