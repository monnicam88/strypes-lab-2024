#pragma once

#include <fstream>
#include <sstream>

#include "IntegratedCircuit.h"

struct CircuitInput {
	std::string circuitName = "";			
	CustomizedVector::IntArray arguments;
};

std::string getFileName(std::istream& istream);
CircuitInput createCircuitInput();
CircuitInput parseCommandRUN(std::istream& istream);
void freeCircuitInputMemory(CircuitInput& input);
void executeCommandALL(IntegratedCircuit& circuit);
void tokenizeExpression(CustomizedString::CharArray& tokens, const std::string& expression);
void printCommandALL(const IntegratedCircuit& circuit, CircuitInput& input, const int currentIndex);
int executeCommandRUN(const IntegratedCircuit& circuit, const CircuitInput& input);
CustomizedString::CharArray getInputExpression(const IntegratedCircuit& circuit, const CircuitInput& input);
IntegratedCircuit readIntegratedCircuit(std::istream& istream);
