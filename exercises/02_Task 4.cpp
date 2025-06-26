#include <iostream>

int main() {
    int firstNumber = 0, secondNumber = 0, choice = 0;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    std::cout << "Choose one option:" << std::endl;
    std::cout << "1: AND" << std::endl;
    std::cout << "2: OR" << std::endl;
    std::cout << "3: XOR" << std::endl;
    std::cout << "4: Left shift (first number)" << std::endl;
    std::cout << "5: Right shift (first number)" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Result (AND): " << (firstNumber & secondNumber) << std::endl;
        break;
    case 2:
        std::cout << "Result (OR): " << (firstNumber | secondNumber) << std::endl;
        break;
    case 3:
        std::cout << "Result (XOR): " << (firstNumber ^ secondNumber) << std::endl;
        break;
    case 4:
        std::cout << "Enter the number of left shifts: ";
        int shiftLeft = 0;
        std::cin >> shiftLeft;
  
        std::cout << "Result (LEFT SHIFT): " << (firstNumber << shiftLeft) << std::endl;
        break;
    case 5:
        std::cout << "Enter the number of right shifts: ";
        int shiftRight = 0;
        std::cin >> shiftRight;
   
        std::cout << "Result (RIGHT SHIFT): " << (firstNumber >> shiftRight) << std::endl;
        break;
    default:
        std::cout << "Error: Invalid operation!" << std::endl;
        break;
    }

    return 0;
}