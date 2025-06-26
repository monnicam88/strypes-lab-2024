#include <iostream>

int main() {
    long long int number = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    if (number > 0) 
        std::cout << "Number is positive." << std::endl;
    else if (number < 0)
        std::cout << "Number is negative." << std::endl;
    else std::cout << "Number is zero." << std::endl;

    return 0;
}