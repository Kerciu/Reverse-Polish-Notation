#pragma once
#include <vector>
#include <iomanip>

class Stack
{
private:
	std::vector<char> content;

	bool checkIfOverflown(int stackSize);

	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

public:
	Stack();

	void push(char elem);
	char pop();
	void peek();
	void search();
	bool isEmpty();
	size_t size();
	void clear();

	Stack copyStack() const;
	Stack& operator=(const Stack & other);

};

