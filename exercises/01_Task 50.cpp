#include <iostream>

bool isValidLengthOfSide(double firstSide, double secondSide, double thirdSide) {
    return firstSide > 0 && secondSide > 0 && thirdSide > 0;
}

int main() {
    double a = 0.0, b = 0.0, c = 0.0;

    std::cout << "Enter lengths of the three sides of the triangle (a, b, c): ";
    std::cin >> a >> b >> c;

    if (!isValidLengthOfSide(a, b, c)) {
        std::cerr << "Error: All input values must be positive numbers and other than 0" << std::endl;
        return 0;
    }

    if ((a + b > c) && (a + c > b) && (b + c > a))
        std::cout << "The sides can form a triangle." << std::endl;
    else std::cout << "The sides can NOT form a triangle." << std::endl;

    return 0;
}