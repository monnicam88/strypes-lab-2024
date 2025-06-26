#include <iostream>

int main() {
    double leva = 0.0, exchangeRateBGNtoEUR = 1.95583;

    std::cout << "Input monetary amount in leva: ";
    std::cin >> leva;
    std::cout << "The monetary amount exchanged in euro is: " << (leva / exchangeRateBGNtoEUR) << std::endl;

    return 0;
}
