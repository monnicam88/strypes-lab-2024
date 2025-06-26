#include <iostream>

int main() {
    const double AVERAGE_DIVIDER = 3.0;
    double a = 0.0, b = 0.0, c = 0.0;

    std::cout << "Enter 3 real numbers: ";
    std::cin >> a >> b >> c;
    std::cout << "The AVERAGE value is: " << (a + b + c) / AVERAGE_DIVIDER << std::endl;

    return 0;
}