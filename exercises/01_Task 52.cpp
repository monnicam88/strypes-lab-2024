#include <iostream>

int main() {
    long double a = 0.0, b = 0.0;

    std::cout << "Enter two numbers (A and B): ";
    std::cin >> a >> b;

    long double result = (a + b) * (a - b);

    std::cout << "The result of expression (A + B) * (A - B) is: " << result << std::endl;

    return 0;
}