#include <iostream>

int main() {
    long long int a = 0, b = 0;

    std::cout << "Input value for A: ";
    std::cin >> a;
    std::cout << "Input value for B: ";
    std::cin >> b;

    a = (a += b) - (b = a - b);

    std::cout << "After the swap: A = " << a << ", B = " << b << std::endl;

    return 0;
}