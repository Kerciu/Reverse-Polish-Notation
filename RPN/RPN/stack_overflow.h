#pragma once
#include <stdexcept>

class stack_overflow : std::exception
{
public:
	stack_overflow(char const* message) noexcept;
	virtual const char* what() const noexcept override;

private:
	const char* mMessage;
};

