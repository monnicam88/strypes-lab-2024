#include <iostream>
#include <fstream>
#include <limits>
#include <array>

template <typename T, size_t N>
T findMaxNumber(const std::array<T, N>& numsArr) {
    T maxNum = std::numeric_limits<T>::min();
    
    for (const auto num : numsArr) {
        if (num > maxNum) 
           maxNum = num;
    }
    return maxNum;
}

int main() {
    std::ifstream inputFile("numbers.txt");

    if (!inputFile) {
        std::cerr << "Error opening the file numbers.txt" << std::endl;
        return 1;
    }

    std::array<float, 3> numsArr;
    while (!inputFile.eof()) {
        inputFile >> numsArr[0] >> numsArr[1] >> numsArr[2];
        std::cout << "Max number is: " << findMaxNumber(numsArr) << std::endl;
    }

    if (inputFile.fail()) {
        std::cerr << "Error while reading the numbers from file." << std::endl;
        return 1;
    }

    inputFile.close();
    return 0;
}
