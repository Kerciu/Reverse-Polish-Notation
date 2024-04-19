#include <cmath>
#include "Operator.h"
#include "../exceptions/exceptions.h"
#include <stdexcept>

Operator::Operator() : oper('+') { }

Operator::Operator(const char& op) : oper(op)
{
	if (!validateOperator(op)) throw wrong_operator("This is not an operator!");
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

	if (operand2 == 0) throw zero_division_error("Zero division!!");

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
