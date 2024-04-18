#pragma once
#include <stdexcept>

class stack_overflow : public std::exception
{
public:
	stack_overflow(char const* message) noexcept;
	virtual const char* what() const noexcept override;

private:
	const char* mMessage;
};

class stack_underflow : public stack_overflow {
	using stack_overflow::stack_overflow;
};

class zero_division_error : public stack_overflow {
	using stack_overflow::stack_overflow;
};

class wrong_operator : public stack_overflow {
	using stack_overflow::stack_overflow;
};

class no_element_found : public stack_overflow {
	using stack_overflow::stack_overflow;
};

class empty_expression : public stack_overflow {
	using stack_overflow::stack_overflow;
};

class incorrect_expression : public stack_overflow {
	using stack_overflow::stack_overflow;
};

class insufficient_arguments : public stack_overflow {
	using stack_overflow::stack_overflow;
};