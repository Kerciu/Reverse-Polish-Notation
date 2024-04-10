#include "Operator.h"

Operator::Operator(const char& op) : oper(op) { }

bool Operator::validateOperator(const char& op) const 
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%');
}

int Operator::handleOperator(std::vector<int> setToCompute)
{
	int computeResult = 0;
	switch (oper)
	{
	case '+':

		for (const int& elem : setToCompute) {
			computeResult += elem;
		}
		break;
	case '-':
		for (const int& elem : setToCompute) {
			computeResult -= elem;
		}
		break;
	case '*':
		for (const int& elem : setToCompute) {
			computeResult *= elem;
		}
		break;
	case '/':
		for (const int& elem : setToCompute) {
			computeResult /= elem;
		}
		break;
	case '%':
		for (const int& elem : setToCompute) {
			computeResult %= elem;
		}
		break;
	default:
		break;
	}
	return computeResult;
}
