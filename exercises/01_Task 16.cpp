#include <iostream>

int main() {
    long long int N = 0;
    long double sum = 0.0;

    std::cout << "Enter a whole number (N): ";
    std::cin >> N;

    if (N <= 0) {
        std::cerr << "The number must be positive." << std::endl;
        return 1; 
    }

    std::cout << "Enter N real numbers: ";
    long long int copyOfN = N;
    while (copyOfN > 0) {
        double number = 0.0;
        std::cin >> number;
        sum += number;
        --copyOfN;
    }

    double averageValue = sum / (double)N;

    std::cout << "The arithmetic mean of numbers is: " << averageValue << std::endl;

    return 0;
}