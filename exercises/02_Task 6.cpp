#include <iostream>

long long setBit(long long number, unsigned int position) {
    return number | (1 << (position - 1));
}

long long clearBit(long long number, unsigned int position) {
    return number & ~(1 << (position - 1));
}

int main() {
    long long number = 0;
    unsigned int bitPosition = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    bitPosition = 3;
    long long newNumber = setBit(number, bitPosition);
    std::cout << "Change the bit number " << bitPosition << " to 1: " << newNumber;

    if (newNumber == number)
        std::cout << " (it is already 1)";
    std::cout << std::endl;

    bitPosition = 4;
    newNumber = clearBit(number, bitPosition);
    std::cout << "Clear the bit number " << bitPosition << " (to 0): " << newNumber << std::endl;

    return 0;
}