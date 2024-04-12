#pragma once
#include <vector>

class Operator
{
private:
	char oper;
	bool validateOperator(const char& op) const;

public:
	Operator();
	Operator(const char& op);

	char getOperator(void) const;
	void setOperator(const char& newOp);
	int handleOperator(int operand1, int operand2);

};

