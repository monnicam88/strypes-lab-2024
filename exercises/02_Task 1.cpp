#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

std::string decimalToBinary(int decimal) {
    std::string binary = "";
    while (decimal > 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal /= 2;
    }
    return binary.empty() ? "0" : binary;
}

std::string decimalToOctal(int decimal) {
    std::ostringstream oss;
    oss << std::oct << decimal;
    return oss.str();
}

std::string decimalToHexadecimal(int decimal) {
    std::ostringstream oss;
    oss << std::hex << std::uppercase << decimal;
    return oss.str();
}

int binaryToDecimal(const std::string& binary) {
    return std::stoi(binary, nullptr, 2);
}

int octalToDecimal(const std::string& octal) {
    return std::stoi(octal, nullptr, 8);
}

int hexadecimalToDecimal(const std::string& hexadecimal) {
    return std::stoi(hexadecimal, nullptr, 16);
}

void convertDecimal(int decimal) {
    std::cout << "BIN: " << decimalToBinary(decimal) << std::endl;
    std::cout << "OCT: " << decimalToOctal(decimal) << std::endl;
    std::cout << "HEX: " << decimalToHexadecimal(decimal) << std::endl;
}

void convertFromOtherBase() {
    int choice = 0;

    std::cout << "Select numerical system:" << std::endl;
    std::cout << "1. BIN" << std::endl;
    std::cout << "2. OCT" << std::endl;
    std::cout << "3. HEX" << std::endl;
    std::cin >> choice;

    std::string input;
    int decimal = 0;

    switch (choice) {
    case 1:
        std::cout << "Enter BIN number: ";
        std::cin >> input;
        decimal = binaryToDecimal(input);
        break;
    case 2:
        std::cout << "Enter OCT number: ";
        std::cin >> input;
        decimal = octalToDecimal(input);
        break;
    case 3:
        std::cout << "Enter HEX number: ";
        std::cin >> input;
        decimal = hexadecimalToDecimal(input);
        break;
    default:
        std::cout << "Error: Invalid choice!" << std::endl;
        return;
    }

    std::cout << "DEC: " << decimal << std::endl;
    convertDecimal(decimal);
}

int main() {
    int choice = 0;

    do {
        std::cout << "Choose an option [0, 1, 2]:" << std::endl;
        std::cout << "1. Converting a DEC number to other numerical systems" << std::endl;
        std::cout << "2. Converting from another numerical system to DEC" << std::endl;
        std::cout << "0. Exit" << std::endl;
        
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int decimal = 0;
            std::cout << "Enter DEC number: ";
            std::cin >> decimal;
            convertDecimal(decimal);
            break;
        }
        case 2:
            convertFromOtherBase();
            break;
        case 0:
            std::cout << "Close the program and have a nice day!" << std::endl;
            break;
        default:
            std::cout << "Error: Invalid choice!" << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}