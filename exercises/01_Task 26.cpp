#include <iostream>

const short int DAYS_IN_ONE_YEAR = 365;
const short int DAYS_IN_ONE_MONTH = 30;

long long int dateToDays(int day, int month, int year) {
    return (year * DAYS_IN_ONE_YEAR) + (month * DAYS_IN_ONE_MONTH) + day;
}

bool isValidDate(int day, int month, int year) {
    return day > 0 && month > 0 && year > 0;
}

int main() {
    int firstDay = 0, firstMonth = 0, firstYear = 0;
    int secondDay = 0, secondMonth = 0, secondYear = 0;

    std::cout << "Enter the first date in the format [day month year]: ";
    std::cin >> firstDay >> firstMonth >> firstYear;

    std::cout << "Enter the second date in the format [day month year]: ";
    std::cin >> secondDay >> secondMonth >> secondYear;

    if (!isValidDate(firstDay, firstMonth, firstYear) ||
        !isValidDate(secondDay, secondMonth, secondYear)) {
        std::cerr << "Error: Input is not a valid date." << std::endl;
        return 1;
    }

    long long int totalDays1 = dateToDays(firstDay, firstMonth, firstYear);
    long long int totalDays2 = dateToDays(secondDay, secondMonth, secondYear);

    int difference = totalDays1 - totalDays2;
    if (difference < 0)
        difference *= -1;

    std::cout << "The difference between both dates is: " << difference << " days" << std::endl;

    return 0;
}