#include <iostream>

int main() {
    const double LITRES_IN_ONE_GALLON = 3.78541;
    long double litres = 0.0;

    std::cout << "Enter volume in litres: ";
    std::cin >> litres;

    if (litres < 0) {
        std::cerr << "Error: Input value must be a positive number." << std::endl;
        return 1;
    }

    if (litres == 1)
        std::cout << litres << "l equals to: " << (litres / LITRES_IN_ONE_GALLON) << " US gallons" << std::endl;
    else if (litres == LITRES_IN_ONE_GALLON)
        std::cout << litres << "l are equal to: " << (litres / LITRES_IN_ONE_GALLON) << " US gallon" << std::endl;
    else std::cout << litres << "l are equal to: " << (litres / LITRES_IN_ONE_GALLON) << " US gallons" << std::endl;

    return 0;
}