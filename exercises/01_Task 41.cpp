#include <iostream>
#include <iomanip>

int main() {
    const double BGN_TO_USD = 0.54;  
    const double BGN_TO_EUR = 0.51;  
    const double BGN_TO_GBP = 0.44;  

    long double leva = 0.0;
    std::cout << "Enter amount in BGN: ";
    std::cin >> leva;

    if (leva < 0) {
        std::cerr << "Error: Input must be a positive value." << std::endl;
        return 1;
    }

    long double dollars = leva * BGN_TO_USD;
    long double euros = leva * BGN_TO_EUR;
    long double pounds = leva * BGN_TO_GBP;

    std::cout << leva << " BGN are equal to: " << std::fixed 
              << std::setprecision(2) << dollars << " USD" << std::endl;
    std::cout << leva << " BGN are equal to: " << std::fixed 
              << std::setprecision(2) << euros << " EUR" << std::endl;
    std::cout << leva << " BGN are equal to: " << std::fixed 
              << std::setprecision(2) << pounds << " GBP" << std::endl;

    return 0;
}