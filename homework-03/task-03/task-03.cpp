#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [number1] [operation] [number2]" << std::endl;
        return 1;
    }

    double num1 = std::atof(argv[1]);
    double num2 = std::atof(argv[3]);
    char operation = argv[2][0];

    double result = 0.0;
    switch (operation) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case 'x':
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0) {
            std::cerr << "Error: Division by 0 is UNDEFINED mathemathical operation!" << std::endl;
            return 1;
        }
        result = num1 / num2;
        break;
    default:
        std::cerr << "Error: Invalid operation. Supported operations are +, -, x, /" << std::endl;
        return 1;
    }

    std::cout << "Result: " << std::fixed << std::setprecision(2) << result << std::endl;

    return 0;
}
