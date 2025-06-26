#include <iostream>
#include <cstdint>
#include <bitset>

union Float32Bits {
    float number;
    uint32_t bits;
};

void printIEEE754(float number) {
    const short int MANTISSA_BITS = 23;
    const short int EXPONENT_BITS = 8;
    const short int BITS = 31;

    Float32Bits floatBits;
    floatBits.number = number;

    uint32_t sign = (floatBits.bits >> BITS) & 0x1;
    uint32_t exponent = (floatBits.bits >> MANTISSA_BITS) & 0xFF;
    uint32_t mantissa = floatBits.bits & 0x7FFFFF; 

    std::cout << "Sign: " << sign << std::endl;
    std::cout << "Exponent: " << std::bitset<EXPONENT_BITS>(exponent) << std::endl;
    std::cout << "Mantissa: " << std::bitset<MANTISSA_BITS>(mantissa) << std::endl;
}

int main() {
    float number = 0.0;

    std::cout << "Enter real number: ";
    std::cin >> number;

    printIEEE754(number);

    return 0;
}