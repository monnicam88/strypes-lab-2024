#include "TruthTable.h"

#include <fstream>
#include <sstream>
#include <string>

TruthTable createTruthTable(const int capacity) {
	TruthTable table;
	table.data = allocArrayMemory<int>(capacity);
	table.capacity = capacity;
	return table;
}

void addToTruthTable(TruthTable& table, const int value) {
	if (table.size + 1 == table.capacity) {
		int* newData = allocArrayMemory<int>(table.capacity * ProjectConstants::CAPACITY_RESIZER);
		for (int i = 0; i < table.size; i++)
			newData[i] = table.data[i];

		freeArrayMemory<int>(table.data);
		table.data = newData;
		table.size++;
		table.capacity = table.capacity * ProjectConstants::CAPACITY_RESIZER;
		return;
	}

	table.data[table.size++] = value;
}

void deleteTruthTable(TruthTable& table) {
	freeArrayMemory<int>(table.data);
	table.capacity = table.size = table.rows = table.cols = 0;
}

void printTruthTable(const TruthTable& table) {
    for (int i = 0; i < table.rows; i++) {
        for (int j = 0; j < table.cols; j++) {
            if (j == table.cols - 1)
                std::cout << "Output: ";
            std::cout << table.data[i * table.cols + j];
            if (j < table.cols - 1)
                std::cout << " | "; 
        }
        std::cout << std::endl;
    }
}

std::string executeCommandFIND(const TruthTable& table) {
    std::cout << "Integrated circuit: ";
    std::string logicFunction = "\"";
    for (int i = 0; i < table.rows; i++) {
        const int result = table.data[i * table.cols + table.cols - 1];
        if (1 == result) {
            int* currentInput = allocArrayMemory<int>(table.cols - 1);
            for (int j = 0; j < table.cols - 1; j++)
                currentInput[j] = table.data[i * table.cols + j];

            // Synthesis by 1
            logicFunction += synthesisByOne(currentInput, table.cols - 1);
            logicFunction += " | ";

            freeArrayMemory<int>(currentInput);
        }
    }

    if (!logicFunction.empty()) {
        logicFunction = logicFunction.substr(0, logicFunction.find_last_of(')') + 1);
        logicFunction.append("\"");
    }
    return logicFunction;
}

TruthTable parseTruthTableFromFile(const std::string& fileName) {
    TruthTable table = createTruthTable(ProjectConstants::TRUTH_TABLE_CAPACITY);
    std::ifstream inputFile(fileName, std::ios::in);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to parse truth table from file '" << fileName << "' " << std::endl;
        std::cerr << "Check if the file name is not wrong or if the file is missing." << std::endl;
        deleteTruthTable(table);
        return table;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream istream(line);
        int entry = -1;
        int colsCounter = 0;
        while (istream >> entry) {
            colsCounter++;
            addToTruthTable(table, entry);
        }
        table.rows++;
        table.cols = colsCounter;
    }

    inputFile.close();
    return table;
}
