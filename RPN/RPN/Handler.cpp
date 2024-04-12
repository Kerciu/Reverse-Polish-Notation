#include <iostream>
#include <string>
#include "Handler.h"
#include "Operator.h"

Handler::Handler() : expression("") { }

Handler::Handler(std::string express) : expression(express) { }

bool checkIfCorrectExpression(std::string express) {
    std::string correctChars = "0123456789 +-*/%^";
    for (const char& ch : express) {
        if (std::find(correctChars.begin(), correctChars.end(), ch) != correctChars.end()) return true;
    }
    return false;
}

bool Handler::checkIfDigit(const char& ch) {
    std::string digits = "0123456789";
    return std::find(digits.begin(), digits.end(), ch) != digits.end();
}

bool Handler::checkIfOperator(const char& ch) {
    std::string operators = "+-*/%";
    return std::find(operators.begin(), operators.end(), ch) != operators.end();
}

void Handler::stackifyExpression(Stack& stack)
{
    std::vector<int> setToCompute;
    Operator oper;
    // Add digits and their operators to the new set
    for (int i = 0; i < stack.size(); i++) {
        char ch = expression[i];

        if (checkIfDigit(ch)) {
            stack.push(ch - '0');
        }
        else if (checkIfOperator(ch)) {

            int operand1 = stack.pop();
            int operand2 = stack.pop();

            int result = oper.handleOperator(operand1, operand2);

            stack.push(result);
        }
    }
}

std::istream& operator>>(std::istream & is, Handler & h)
{
    std::string input;

    if (std::getline(is, input)) h.expression = input;

    return is;
    
}