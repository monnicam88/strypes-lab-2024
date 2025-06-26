#include <iostream>

int main() {
    bool A = 0, B = 0, C = 0;

    std::cout << "Enter value for A (0 or 1): ";
    std::cin >> A;
    std::cout << "Enter value for B (0 or 1): ";
    std::cin >> B;
    std::cout << "Enter value for C (0 or 1): ";
    std::cin >> C;

    bool result = (A && B) || !C;
    std::cout << "Result of (A AND B) OR NOT C is: " << result << std::endl;

    return 0;
}