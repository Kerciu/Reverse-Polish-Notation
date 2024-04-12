#include <cmath>
#include "Operator.h"
#include <stdexcept>

Operator::Operator() : oper('+') { }

Operator::Operator(const char& op) : oper(op)
{
	if (!validateOperator(op)) throw std::out_of_range("This is not an operator!");
}

bool Operator::validateOperator(const char& op) const 
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%');
}

char Operator::getOperator(void) const
{
	return oper;
}

void Operator::setOperator(const char& newOp) {
	if (validateOperator(newOp)) oper = newOp;
}

int Operator::handleOperator(int operand1, int operand2)
{
	int computeResult = 0;
	switch (oper)
	{
	case '+':
		computeResult = operand1 + operand2;
		break;
	case '-':
		computeResult = operand1 - operand2;
		break;
	case '*':
		computeResult = operand1 * operand2;
		break;
	case '/':
		computeResult = operand1 / operand2;
		break;
	case '%':
		computeResult = operand1 % operand2;
		break;
	case '^':
		computeResult = std::pow(operand1, operand2);
	default:
		break;
	}
	return computeResult;
}
