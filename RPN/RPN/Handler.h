#pragma once
#include <iostream>
#include "stack.h"
#include <iomanip>


class Handler
{
private:
	std::string expression;

	int calculateStringLength(std::string str);
	bool checkIfCorrectExpression(std::string express);

	bool checkIfDigit(const char& ch);
	bool checkIfOperator(const char& ch);

	friend std::istream& operator>>(std::istream& is, Handler& h);

public:
	Handler();
	Handler(std::string express);

	int stackifyExpression(Stack& stack);

};

