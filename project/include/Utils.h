#pragma once

#include <iomanip>
#include <string>

enum Commands {
    DEFINE,
    RUN,
    ALL,
    FIND,
    PRINT,
    EXIT,
    INVALID
};

Commands getCommandEnum(const std::string& command) {
    if (command == "DEFINE") return DEFINE;
    if (command == "RUN") return RUN;
    if (command == "ALL") return ALL;
    if (command == "FIND") return FIND;
    if (command == "PRINT") return PRINT;
    if (command == "EXIT") return EXIT;
    return INVALID;
}

void simulatorMenu() {
    std::cout << "\t\t   Digital Integrated Circuits console simulator" << std::endl;
    std::cout << std::endl;

    std::cout << "------------------------------------- Commands ------------------------------------" << std::endl;
    const int labelWidth = 5, descWidth = 7; 
    std::cout << std::left;
    std::cout << std::setw(labelWidth) << " 1." << std::setw(descWidth) << "DEFINE"
        << "| Creates a logic integrated circuit with a given name and parameters" << std::endl;
    std::cout << std::setw(labelWidth) << " 2." << std::setw(descWidth) << "RUN"
        << "| Executes any of defined integrated circuits with defined input values" << std::endl;
    std::cout << std::setw(labelWidth) << " 3." << std::setw(descWidth) << "ALL"
        << "| Enables execution and analysis of an integrated circuit in a table" << std::endl;
    std::cout << std::setw(labelWidth) << " 4." << std::setw(descWidth) << "FIND"
        << "| Allows to find an integrated circuit by a given truth table" << std::endl;
    std::cout << std::setw(labelWidth) << " 5." << std::setw(descWidth) << "PRINT"
        << "| Prints all defined integrated circuits in the storage" << std::endl;
    std::cout << std::setw(labelWidth) << " 6." << std::setw(descWidth) << "EXIT"
        << "| Allows to stop the program and exit" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "Enter a command: ";
}
