#include <iostream>

int main() {
    long double price = 0.0, paid = 0.0;

    std::cout << "Enter a product price: ";
    std::cin >> price;
    std::cout << "Enter the amount paid: ";
    std::cin >> paid;

    if (price < 0 || paid < 0) {
        std::cerr << "Error: Both input values must be positive numbers." << std::endl;
        return 1;
    }   
    else if (paid < price) {
        std::cerr << "Error: The amount paid is less than the price of the product." << std::endl;
        return 1;
    }

    std::cout << "Change: " << (paid - price) << " BGN" << std::endl;

    return 0;
}