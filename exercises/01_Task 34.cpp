#include <iostream>

int main() {
    const double VAT_RATE = 0.20;
    long double priceWithoutVAT = 0.0;

    std::cout << "Enter the product price excluding VAT: ";
    std::cin >> priceWithoutVAT;

    if (priceWithoutVAT < 0) {
        std::cerr << "Error: The input must be a positive number." << std::endl;
        return 1;
    }

    double VAT = priceWithoutVAT * VAT_RATE;
    long double finalPrice = priceWithoutVAT + VAT;

    std::cout << "The final price including VAT is: " << finalPrice << " lv" << std::endl;

    return 0;
}