#include <iostream>

int main() {
    const short int STEPS_IN_ONE_MILE = 2000; 
    double miles = 0.0;

    std::cout << "Въведете разстоянието в мили: ";
    std::cin >> miles;

    if (miles < 0) {
        std::cerr << "Error: The input must be a positive number." << std::endl;
        return 1;
    }

    if (miles == 1)
        std::cout << miles << " mile is equal to: " << (miles * STEPS_IN_ONE_MILE) << " steps" << std::endl;
    else std::cout << miles << " miles are equal to: " << (miles * STEPS_IN_ONE_MILE) << " steps" << std::endl;

    return 0;
}