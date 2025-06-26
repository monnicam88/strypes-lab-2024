#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [string_to_count]" << std::endl;
        return 1;
    }

    std::cout << "Enter 'Ctrl+D' if you want to stop the program." << std::endl;

    std::string targetString = argv[1];
    std::string inputLine;
    int count = 0;

    while (std::getline(std::cin, inputLine)) {
        if (inputLine == targetString) 
            ++count;
    }
    std::cout << "Count = " << count << std::endl;

    return 0;
}
