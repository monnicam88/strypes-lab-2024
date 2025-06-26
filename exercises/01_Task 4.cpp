#include <iostream>

int main() {
    long long int num = 0;
    
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "The reversed number is: ";
    while (num != 0) {
        std::cout << num % 10;
        num = num / 10;            
    }
    std::cout << std::endl;

    return 0;
}