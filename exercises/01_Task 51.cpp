#include <iostream>

int main() {
    const short int SECONDS_IN_ONE_DAY = 86400;
    const short int SECONDS_IN_ONE_HOUR = 3600;
    const short int SECONDS_IN_ONE_MINUTE = 60;

    long long int totalSeconds = 0;

    std::cout << "Enter total number of seconds: ";
    std::cin >> totalSeconds;

    if (totalSeconds < 0) {
        std::cerr << "Error: Input value must be a positive number." << std::endl;
        return 1;
    }

    int copyTotalSeconds = totalSeconds;

    int days = totalSeconds / SECONDS_IN_ONE_DAY;
    totalSeconds %= SECONDS_IN_ONE_DAY;

    int hours = totalSeconds / SECONDS_IN_ONE_HOUR;
    totalSeconds %= SECONDS_IN_ONE_HOUR;

    int minutes = totalSeconds / SECONDS_IN_ONE_MINUTE;
    int seconds = totalSeconds % SECONDS_IN_ONE_MINUTE;

    if (totalSeconds == 1)
        std::cout << copyTotalSeconds << "s equals to: " << days << "d " << hours
                  << "h " << minutes << "m " << seconds << "s" << std::endl;
    else std::cout << copyTotalSeconds << "s are equal to: " << days << "d " << hours
                   << "h " << minutes << "m " << seconds << "s" << std::endl;

    return 0;
}