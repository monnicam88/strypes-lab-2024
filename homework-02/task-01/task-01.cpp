#include <iostream>
#include <bitset>    
#include <iomanip>   

const short int BITS = 32;  

void dec2bin(int number) {
    std::cout << "BIN: " << std::bitset<BITS>(number) << std::endl;
}

void dec2oct(int number) {
    std::cout << "OCT: " << std::oct << number << std::endl;
}

void dec2hex(int number) {
    std::cout << "HEX: " << std::hex << number << std::endl;
}

int main() {
    int number = 0;
    std::cout << "Input a decimal number: ";
    std::cin >> number;
    std::cout << std::endl;

    dec2bin(number);
    dec2oct(number);
    dec2hex(number);

    return 0;
}
