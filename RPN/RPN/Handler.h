#pragma once
#include <iostream>
#include "stack.h"
#include <iomanip>


class Handler
{
private:
	std::string expression;

	void toInt(std::vector<char> setToOperate);
	std::vector<char> addToSubSet(std::vector<char> set, int begin, int end);
	int handleOperator(const std::vector<char>& setToOperate, const char& ch);

	friend std::istream& operator>>(std::istream& is, Handler& h);

public:
	void stackifyExpression(Stack& stack);

};

