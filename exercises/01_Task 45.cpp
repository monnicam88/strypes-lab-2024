#include <iostream>

int main() {
    const double CENTIMETRES_IN_ONE_INCH = 2.54;
    double centimeters = 0.0;

    std::cout << "Enter length in cm: ";
    std::cin >> centimeters;

    if (centimeters < 0) {
        std::cerr << "Error: Input value must be a positive number." << std::endl;
        return 1;
    }

    if (centimeters == 1)
        std::cout << centimeters << " cm equals to: " << (centimeters / CENTIMETRES_IN_ONE_INCH) << " inch" << std::endl;
    else std::cout << centimeters << " cm are equal to: " << (centimeters / CENTIMETRES_IN_ONE_INCH) << " inch" << std::endl;

    return 0;
}