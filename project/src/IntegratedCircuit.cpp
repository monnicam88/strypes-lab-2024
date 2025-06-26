#include "IntegratedCircuit.h"

IntegratedCircuit createIntegratedCircuit() {
	IntegratedCircuit circuit;
	circuit.tokenizedExpressions = CustomizedString::createCharArray(ProjectConstants::MAX_ARRAY_SIZE);
	circuit.arguments = CustomizedString::createCharArray(ProjectConstants::MAX_ARRAY_SIZE);
	return circuit;
}

void deleteIntegratedCircuit(IntegratedCircuit& circuit) {
	CustomizedString::deleteCharArray(circuit.tokenizedExpressions);
	CustomizedString::deleteCharArray(circuit.arguments);
	circuit.name = "";
	circuit.expression = "";
}

void printIntegratedCircuit(const IntegratedCircuit& circuit) {
	const int length = circuit.arguments.length;

	std::cout << circuit.name << "(";
	for (int i = 0; i < length - 1; i++)
		std::cout << circuit.arguments.data[i] << ",";
	std::cout << circuit.arguments.data[length - 1] << "): " << circuit.expression << std::endl;
}

bool validateIntegratedCircuit(const IntegratedCircuit& circuit) {
	for (int i = 0; i < circuit.tokenizedExpressions.length; i++) {
		const auto token = circuit.tokenizedExpressions.data[i];
		
		if (token == '&' || token == '|' || token == '!' ||
			token == '(' || token == ')' || token == ',')
			continue;

		int j = 0;
		for (; j < circuit.arguments.length; j++) {
			const auto argument = circuit.arguments.data[j];
			if (token == argument)
				break;
		}

		if (j == circuit.arguments.length) {
			std::cerr << "Found NOT valid token {" << token << "}." << std::endl;
			return false;
		}
	}
	return true;
}
