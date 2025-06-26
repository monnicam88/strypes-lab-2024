#include <iostream>

int main() {
    long int number = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    long long int square = number * number;

    std::cout << "The square of number " << number << " is: " << square << std::endl;

    return 0;
}