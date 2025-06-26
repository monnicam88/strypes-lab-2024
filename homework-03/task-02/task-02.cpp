#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

const double M_PI = 3.14;

int circle(double radius, double* perimeter, double* area) {
    if (radius < 0)
        return -1; 

    *(perimeter) = 2 * M_PI * radius; 
    *(area) = M_PI * radius * radius; 
    
    return 0; 
}

int main() {
    double radius = 0.0, 
           perimeter = 0.0, 
           area = 0.0;

    std::cout << "Enter circle radius (Ctrl+D to stop):" << std::endl;
    while (std::cin >> radius) { 
        if (std::cin.fail()) { 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cerr << "Error: Invalid input data! Try again." << std::endl; 
            continue;
        }

        if (circle(radius, &perimeter, &area) == 0)
            std::cout << "P = " << std::fixed << std::setprecision(2) << perimeter << ", S = " << area << std::endl;
        else std::cerr << "Error: Invalid input data!" << std::endl;
    }

    return 0;
}
