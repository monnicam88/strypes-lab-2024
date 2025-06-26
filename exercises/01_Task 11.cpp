#include <iostream>

int main() {
    double edgeLength = 0.0;

    std::cout << "Enter the cube edge length: ";
    std::cin >> edgeLength;
    std::cout << "The cube volume is: " << (edgeLength * edgeLength * edgeLength) << std::endl;

    return 0;
}