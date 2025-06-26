#pragma once

#include <iostream>

#include "DataStructures.h"

int logicalOperatorsPrecedence(const char customizedOperator);
int postfixExpressionEvaluation(const CustomizedString::CharArray& postfixExpression);
std::string synthesisByOne(const int* input, const int inputSize);
CustomizedString::CharArray convertInfixToPostfix(const CustomizedString::CharArray& infixTokens);
