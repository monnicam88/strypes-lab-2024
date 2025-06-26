#include <iostream>

int main() {
    unsigned int digitsSum = 0;
    long long int number = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    if (number < 0)
        number *= -1;

    while (number > 0) {
        digitsSum += number % 10; 
        number /= 10;        
    }
    std::cout << "The sum of the digits is: " << digitsSum << std::endl;

    return 0;
}