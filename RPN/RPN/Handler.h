#pragma once
#include <iostream>
#include "stack.h"
#include <iomanip>


class Handler
{
private:
	std::string expression;

	bool checkIfDigit(const char& ch);
	bool checkIfOperator(const char& ch);

	friend std::istream& operator>>(std::istream& is, Handler& h);

public:
	Handler();
	Handler(std::string express);

	void stackifyExpression(Stack& stack);

};

