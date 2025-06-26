#include <iostream>
#include <fstream>
//#include <sstream>

int32_t logicalXor(const int32_t a, const int32_t b) {
    return (a || b) && !(a && b);   
}

int main() {
    std::ifstream inputFile("numbers.txt");

    if (!inputFile) {
        std::cerr << "Error opening the file numbers.txt" << std::endl;
        return 1;
    }

    std::cout << "Logical XOR function" << std::endl;
    
    int32_t a, b;
    while (!inputFile.eof()) {
        inputFile >> a >> b;
        std::cout << "xor(" << a << ", " << b << ") = " << logicalXor(a, b) << std::endl;
    }

    if (inputFile.fail()) {
        std::cerr << "Error while reading the numbers from file." << std::endl;
        return 1;
    }

    inputFile.close();
    return 0;
}
