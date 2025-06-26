#include <regex>

#include "IntegratedCircuitInput.h"
#include "LogicalExpressionHandler.h"

std::string getFileName(std::istream& istream) {
    std::string fileName;
    std::getline(istream >> std::ws, fileName);
    fileName = fileName.substr(fileName.find_first_of('\"') + 1, fileName.find_last_of('\"') - 1);
    return fileName;
}

CircuitInput createCircuitInput() {
    CircuitInput input;
    input.arguments = CustomizedVector::createIntArray(ProjectConstants::MAX_ARRAY_SIZE);
    return input;
}

CircuitInput parseCommandRUN(std::istream& istream) {
    CircuitInput input = createCircuitInput();
    std::getline(istream >> std::ws, input.circuitName, '(');

    char argument;
    while (istream.get(argument) && argument != ')') {
        if (argument == ' ' || argument == ',')
            continue;
        if (std::isdigit(argument))
            CustomizedVector::addToIntArray(input.arguments, argument - '0');
        else assert(false && "RUN command invalid argument.");
    }

    return input;
}

void freeCircuitInputMemory(CircuitInput& input) {
    CustomizedVector::deleteIntArray(input.arguments);
    input.circuitName = "";
}

void executeCommandALL(IntegratedCircuit& circuit) {
    CircuitInput input = createCircuitInput();
    input.circuitName = circuit.name;
    
    for (int i = 0; i < circuit.arguments.length; i++)
        CustomizedVector::addToIntArray(input.arguments, 0);
   
    std::cout << "Execute " << circuit.name << " " << circuit.expression << std::endl;
    printCommandALL(circuit, input, 0);
    freeCircuitInputMemory(input);
}

void tokenizeExpression(CustomizedString::CharArray& tokens, const std::string& expression) {
    for (const auto symbol : expression) {
        if (symbol == ' ' || symbol == '\"')
            continue;
        CustomizedString::addToCharArray(tokens, symbol);
    }
}

void printCommandALL(const IntegratedCircuit& circuit, CircuitInput& input, const int currentIndex) {
    const int length = input.arguments.length;

    if (currentIndex == length) {
        for (int i = 0; i < length - 1; i++)
            std::cout << input.arguments.data[i] << " | ";

        std::cout << input.arguments.data[length - 1] << " | Output: ";
        const int result = executeCommandRUN(circuit, input);
        std::cout << result << std::endl;
        return;
    }

    for (int i = 0; i <= 1; i++) {
        input.arguments.data[currentIndex] = i;
        printCommandALL(circuit, input, currentIndex + 1);
    }
}

int executeCommandRUN(const IntegratedCircuit& circuit, const CircuitInput& input) {
    CustomizedString::CharArray infixExpression = getInputExpression(circuit, input);
    CustomizedString::CharArray postfixExpression = convertInfixToPostfix(infixExpression);
    const int result = postfixExpressionEvaluation(postfixExpression);

    deleteCharArray(infixExpression);
    deleteCharArray(postfixExpression);
    return result;
}

// Replace logical expression inputs with specific numeric 
// values taken from a RUN command or generated automatically
CustomizedString::CharArray getInputExpression(const IntegratedCircuit& circuit, const CircuitInput& input) {
    CustomizedString::CharArray inputExpr = CustomizedString::createCharArray(ProjectConstants::MAX_ARRAY_SIZE);
    const int tokensLength = circuit.tokenizedExpressions.length;
    const int argumentsLength = input.arguments.length;
    
    for (int i = 0; i < tokensLength; i++) {
        const char token = circuit.tokenizedExpressions.data[i];
        CustomizedString::addToCharArray(inputExpr, token);
    }

    for (int i = 0; i < argumentsLength; i++) {
        for (int j = 0; j < tokensLength; j++) {
            if (circuit.tokenizedExpressions.data[j] == circuit.arguments.data[i])
                inputExpr.data[j] = (char)input.arguments.data[i] + '0';
        }
    }
    return inputExpr;
}

IntegratedCircuit readIntegratedCircuit(std::istream& istream) {
    IntegratedCircuit circuit = createIntegratedCircuit();

    std::getline(istream >> std::ws, circuit.name, '(');
    assert(!circuit.name.empty() && circuit.name.length() == 1 && std::isalnum(circuit.name[0]),
           "Invalid circuit name. Names must be a single character.");

    char argument;
    while (istream.get(argument) && argument != ')') {
        if (argument == ' ' || argument == ',')
            continue;
        CustomizedString::addToCharArray(circuit.arguments, argument);
    }

    std::string expression;
    std::getline(istream, expression);
    circuit.expression = expression.substr(expression.find_first_of("\""));

    tokenizeExpression(circuit.tokenizedExpressions, circuit.expression);
    if (!validateIntegratedCircuit(circuit))
        deleteIntegratedCircuit(circuit);

    return circuit;
}
