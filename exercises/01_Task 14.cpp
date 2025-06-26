#include <iostream>

int main() {
    const double METRES_IN_ONE_KILOMETER = 1000.0;
    double metres = 0.0;

    std::cout << "Enter distance in metres: ";
    std::cin >> metres;

    double kilometers = metres / METRES_IN_ONE_KILOMETER;
    std::cout << "The distance in kilometres is: " << kilometers << std::endl;

    return 0;
}