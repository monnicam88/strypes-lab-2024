#include <iostream>

int main() {
    const short int DAYS_IN_ONE_YEAR = 365;
    const short int DAYS_IN_ONE_MONTH = 30;

    long long totalDays = 0;

    std::cout << "Enter total days count: ";
    std::cin >> totalDays;

    if (totalDays < 0) {
        std::cerr << "Error: The input must be a positive number." << std::endl;
        return 1;
    }

    int years = totalDays / DAYS_IN_ONE_YEAR;
    int months = (totalDays % DAYS_IN_ONE_YEAR) / DAYS_IN_ONE_MONTH;
    int days = (totalDays % DAYS_IN_ONE_YEAR) % DAYS_IN_ONE_MONTH;

    std::cout << totalDays << " days are equal to: " << years << "y "
              << months << "m " << days << "d" << std::endl;

    return 0;
}