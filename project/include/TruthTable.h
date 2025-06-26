#pragma once

#include "MemoryManagement.h"
#include "LogicalExpressionHandler.h"

struct TruthTable {
	int* data = nullptr;
	int capacity = 0;
	int size = 0;
	int rows = 0;
	int cols = 0;
};

TruthTable createTruthTable(const int capacity);
void addToTruthTable(TruthTable& table, const int value);
void deleteTruthTable(TruthTable& table);
void printTruthTable(const TruthTable& table);
std::string executeCommandFIND(const TruthTable& table);
TruthTable parseTruthTableFromFile(const std::string& fileName);
