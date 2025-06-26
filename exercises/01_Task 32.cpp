#include <iostream>
#include <iomanip>

int main() {
    const short int DAYS = 7;

    double temperature = 0.0;  
    long double sum = 0.0;       

    std::cout << "Enter the temperatures for 7 days: ";
    
    short int copyOfDays = DAYS;
    while (copyOfDays-- > 0) {
        std::cin >> temperature;
        sum += temperature;  
    }

    double averageTemperature = sum / DAYS;

    std::cout << "Average temperature for the week is: " << std::fixed 
              << std::setprecision(1) << averageTemperature << (char)39 << "C" << std::endl;

    return 0;
}