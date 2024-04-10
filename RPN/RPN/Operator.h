#pragma once
#include <vector>

class Operator
{
private:
	char oper;
	bool validateOperator(const char& op) const;

public:
	Operator(const char& op);
	int handleOperator(std::vector<int> setToCompute);

};

