#include <iostream>

int main() {
    unsigned long long factorial = 1;
    long long int number = 0;

    std::cout << "Input a whole number: ";
    std::cin >> number;

    if (number < 0) 
        std::cout << "The factorial is NOT defined for negative numbers." << std::endl;
    else {
        for (int i = 1; i <= number; ++i) 
            factorial *= i;
        std::cout << "The factorial of " << number << " is " << factorial << std::endl;
    }

    return 0;
}