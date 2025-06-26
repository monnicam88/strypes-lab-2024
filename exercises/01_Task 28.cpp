#include <iostream>

int main() {
    const short int SECONDS_IN_ONE_HOUR = 3600;
    const short int SECONDS_IN_ONE_MINUTE = 60;

    long long int totalSeconds = 0;

    std::cout << "Enter total number of seconds: ";
    std::cin >> totalSeconds;

    if (totalSeconds < 0) {
        std::cerr << "Error: Input must be a positive number." << std::endl;
        return 1;
    }

    long int hours = totalSeconds / SECONDS_IN_ONE_HOUR;
    int minutes = (totalSeconds % SECONDS_IN_ONE_HOUR) / SECONDS_IN_ONE_MINUTE;
    int seconds = totalSeconds % SECONDS_IN_ONE_MINUTE;

    std::cout << totalSeconds << " seconds are equal to: " << hours << "h "
              << minutes << "min " << seconds << "sec" << std::endl;

    return 0;
}