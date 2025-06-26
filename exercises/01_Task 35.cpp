#include <iostream>

int main() {
    int number = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    if (number % 3 == 0 && number % 5 == 0)
        std::cout << "This number is divisible by both 3 and 5." << std::endl;
    else if (number % 3 == 0) 
        std::cout << "The number is divisible only by 3." << std::endl;
    else if (number % 5 == 0) 
        std::cout << "The number is divisible only by 5." << std::endl;
    else std::cout << "The number is neither divisible by 3 nor by 5." << std::endl;

    return 0;
}