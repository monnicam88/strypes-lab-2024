#include "LogicalExpressionHandler.h"

int logicalOperatorsPrecedence(const char customizedOperator) {
    switch (customizedOperator) {
        case '!': return 3;
        case '&': return 2;
        case '|': return 1;
        default: std::cerr << "Error: Unknown operator '" << customizedOperator << "' found" << std::endl;
    }
    return -1;
}

int postfixExpressionEvaluation(const CustomizedString::CharArray& postfixExpression) {
    CustomizedStack::Stack stack;
    
    for (int i = 0; i < postfixExpression.length; i++) {
        const char token = postfixExpression.data[i];
        
        if (std::isdigit(token)) {
            CustomizedStack::addToStack(stack, token - '0');
        }
        else {
            if (token == '!') {
                assert(CustomizedStack::getStackSize(stack) >= 1);
                const int operand = CustomizedStack::getStackTop(stack);
                CustomizedStack::deleteFromStack(stack);
                CustomizedStack::addToStack(stack, !operand);
            }
            else if (token == '&' || token == '|') {
                assert(CustomizedStack::getStackSize(stack) >= 2);
                const int operand2 = CustomizedStack::getStackTop(stack);
                CustomizedStack::deleteFromStack(stack);
                const int operand1 = CustomizedStack::getStackTop(stack);
                CustomizedStack::deleteFromStack(stack);

                CustomizedStack::addToStack(stack, (token == '&') ? (operand1 && operand2) : (operand1 || operand2));
            }
            else {
                std::cerr << "Error: Unknown token '" << token << "' found" << std::endl;
                assert(false);
            }
        }
    }

    assert(CustomizedStack::getStackSize(stack) == 1 && "Postfix evaluation error");
    return CustomizedStack::getStackTop(stack);
}

std::string synthesisByOne(const int* input, const int inputSize) {
    std::string result = "(";
    for (int i = 0; i < inputSize; i++) {
        char argument = i + 'a';
        if (i != inputSize - 1)
            result += "&";
        if (input[i] == 0)
            result.append("!");
        result += argument;
    }
    result += ")";
    return result;
}

// Converts an infix record of a logical expression 
// into a postfix one (Shunting Yard algorithm)
CustomizedString::CharArray convertInfixToPostfix(const CustomizedString::CharArray& infixTokens) {
    CustomizedString::CharArray operators = CustomizedString::createCharArray(infixTokens.capacity);
    CustomizedString::CharArray postfixExpression = CustomizedString::createCharArray(infixTokens.capacity);

    for (int i = 0; i < infixTokens.length; i++) {
        const char token = infixTokens.data[i];
        
        if (std::isdigit(token))
            CustomizedString::addToCharArray(postfixExpression, token);
        else if (token == '(')
            CustomizedString::addToCharArray(operators, token);
        else if (token == ')') {
            char op = CustomizedString::getCharArrayBack(operators);
            while (op != '(') {
                CustomizedString::removeFromCharArray(operators);
                CustomizedString::addToCharArray(postfixExpression, op);
                assert(operators.length > 0 && "Parenthesis mismatch found.");
                op = CustomizedString::getCharArrayBack(operators);
            }
            CustomizedString::removeFromCharArray(operators);
        }
        else if (token == '&' || token == '|' || token == '!') {
            if (operators.length == 0) {
                CustomizedString::addToCharArray(operators, token);
                continue;
            }
            char op = CustomizedString::getCharArrayBack(operators);
            while (op != '(' && operators.length > 0 && logicalOperatorsPrecedence(op) > logicalOperatorsPrecedence(token)) {
                CustomizedString::removeFromCharArray(operators);
                CustomizedString::addToCharArray(postfixExpression, op);
                if (operators.length > 0)
                    op = CustomizedString::getCharArrayBack(operators);
            }
            CustomizedString::addToCharArray(operators, token);
        }
    }

    while (operators.length > 0) {
        const char op = CustomizedString::getCharArrayBack(operators);
        CustomizedString::addToCharArray(postfixExpression, op);
        CustomizedString::removeFromCharArray(operators);
    }

    CustomizedString::deleteCharArray(operators);
    return postfixExpression;
}
