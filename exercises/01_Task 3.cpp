#include <iostream>

int main() {
    int num = 0;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num % 2 == 0) 
        std::cout << "The number is EVEN" << std::endl;
    else std::cout << "The number is ODD" << std::endl;

    return 0;
}