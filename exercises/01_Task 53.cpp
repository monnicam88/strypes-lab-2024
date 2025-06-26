#include <iostream>

int main() {
    const short int MINUTES_IN_ONE_HOUR = 60;
    int totalMinutes = 0;

    std::cout << "Enter total minutes: ";
    std::cin >> totalMinutes;

    if (totalMinutes < 0) {
        std::cerr << "Error: Input value must be a positive number." << std::endl;
        return 1;
    }

    int copyTotalMinutes = totalMinutes;

    int hours = totalMinutes / MINUTES_IN_ONE_HOUR;
    int minutes = totalMinutes % MINUTES_IN_ONE_HOUR;

    if (copyTotalMinutes == 1)
        std::cout << copyTotalMinutes << "min equals to: " << hours << "h " << minutes << "m" << std::endl;
    else std::cout << copyTotalMinutes << "mins are equal to: " <<  hours << "h " << minutes << "m" << std::endl;

    return 0;
}