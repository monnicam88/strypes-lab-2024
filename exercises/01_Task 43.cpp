#include <iostream>

int main() {
    int number = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    bool divisibleBy2 = (number % 2 == 0);
    bool divisibleBy3 = (number % 3 == 0);
    bool divisibleBy5 = (number % 5 == 0);

    if (divisibleBy2 && divisibleBy3 && divisibleBy5) 
        std::cout << number << " divides into 2, 3 and 5." << std::endl;
    else if (divisibleBy2 && divisibleBy3) 
        std::cout << number << " divides into 2 and 3." << std::endl;
    else if (divisibleBy2 && divisibleBy5) 
        std::cout << number << " divides into 2 and 5." << std::endl;
    else if (divisibleBy3 && divisibleBy5) 
        std::cout << number << " divides into 3 and 5." << std::endl;
    else if (divisibleBy2) 
        std::cout << number << " divides into 2." << std::endl;
    else if (divisibleBy3) 
        std::cout << number << " divides into 3." << std::endl;
    else if (divisibleBy5) 
        std::cout << number << " divides into 5." << std::endl;
    else std::cout << number << " is not divisible by 2, 3 or 5." << std::endl;

    return 0;
}