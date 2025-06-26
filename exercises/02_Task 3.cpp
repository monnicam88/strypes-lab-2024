#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>

const short int BITS = 32;

unsigned int binaryStringToInt(const std::string& binary) {
    return std::bitset<BITS>(binary).to_ulong();
}

std::string intToBinaryString(unsigned int num, int length) {
    std::string binary = std::bitset<BITS>(num).to_string();
    return binary.substr(BITS - length);
}

std::string notOperation(const std::string& binary) {
    unsigned int num = binaryStringToInt(binary);
    unsigned int notResult = ~num; 
    
    return intToBinaryString(notResult, binary.length());
}

int main() {
    std::string firstBINnumber, secondBINnumber;

    std::cout << "Enter the first number: ";
    std::cin >> firstBINnumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondBINnumber;

    int length = std::max(firstBINnumber.length(), secondBINnumber.length());
    
    firstBINnumber.insert(0, length - firstBINnumber.length(), '0');
    secondBINnumber.insert(0, length - secondBINnumber.length(), '0');

    unsigned int firstDECnumber = binaryStringToInt(firstBINnumber);
    unsigned int secondDECnumber = binaryStringToInt(secondBINnumber);

    unsigned int logicalANDresult = firstDECnumber & secondDECnumber;
    unsigned int logicalORresult = firstDECnumber | secondDECnumber;
    unsigned int logicalXORresult = firstDECnumber ^ secondDECnumber;

    std::cout << "AND: " << intToBinaryString(logicalANDresult, length) << std::endl;
    std::cout << "OR: " << intToBinaryString(logicalORresult, length) << std::endl;
    std::cout << "XOR: " << intToBinaryString(logicalXORresult, length) << std::endl;
    std::cout << "NOT of first number: " << notOperation(firstBINnumber) << std::endl;

    return 0;
}