#include <iostream>

int main() {
    const double ONE_MILE_TO_KILOMETER = 1.609344;
    double miles = 0.0;

    std::cout << "Enter a distance in miles: ";
    std::cin >> miles;

    if (miles < 0) {
        std::cerr << "Error: The input must be a positive number." << std::endl;
        return 1;
    }

    long double kilometres = miles * ONE_MILE_TO_KILOMETER;

    if (miles == 1) 
        std::cout << miles << " mile is equal to " << kilometres << " km." << std::endl;
    else std::cout << miles << " miles are equal to " << kilometres << " km." << std::endl;

    return 0;
}