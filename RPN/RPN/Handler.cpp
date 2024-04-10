#include <iostream>
#include <string>
#include "Handler.h"
#include "Operator.h"

void Handler::toInt(std::vector<char> setToOperate) {
    for (char& elem : setToOperate) { (int)elem; }
}

std::vector<char> Handler::addToSubSet(std::vector<char> set, int begin, int end) {
    std::vector<char> subSet;

    if (begin >= end) {
        throw std::out_of_range("Begin value cannot be greater than end value");
    }
    for (int i = begin; i <= end; i++) {
        subSet.push_back(set[i]);
    }
    return subSet;
}

int Handler::handleOperator(const std::vector<char>& setToOperate, const char& oper)
{
    Operator operat(oper);
    return 0;
}

void Handler::stackifyExpression(Stack& stack)
{
    // Add digits and their operators to the new set
    for (int i = 0; i < stack.size(); i++) {
        char ch = expression[i];
        stack.push(ch);
    }
}

std::istream& operator>>(std::istream& is, Handler& h)
{
    std::string input;

    if (std::getline(is, input)) h.expression = input;

    return is;
    
}