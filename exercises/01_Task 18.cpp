#include <iostream>

int main() {
    const short int SECONDS_IN_ONE_HOUR = 3600;
    int hours = 0.0;

    std::cout << "Enter a number of hours: ";
    std::cin >> hours;
    
    if (hours < 0) {
        std::cerr << "Error: The input must be a positive number." << std::endl;
        return 1;
    }

    long int seconds = hours * SECONDS_IN_ONE_HOUR;

    if (hours == 1)
        std::cout << hours << " hour is equal to " << seconds << " seconds." << std::endl;
    else std::cout << hours << " hours are equal to " << seconds << " seconds." << std::endl;

    return 0;
}