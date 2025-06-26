#include <iostream>
#include <iomanip>

int main() {
    const double USD_TO_BGN = 1.85;
    double dollars = 0.0;

    std::cout << "Enter the dollar amount: ";
    std::cin >> dollars;

    if (dollars < 0) {
        std::cerr << "Error: Division by zero is not possible." << std::endl;
        return 1;
    }

    if (dollars == 1)
        std::cout << dollars << " USD is equal to: " << std::fixed 
                  << std::setprecision(2) << (dollars * USD_TO_BGN) << " BGN" << std::endl;
    else std::cout << dollars << " USDs are equal to: " << std::fixed
                   << std::setprecision(2) << (dollars * USD_TO_BGN) << " BGN" << std::endl;

    return 0;
}