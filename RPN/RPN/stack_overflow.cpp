#include "stack_overflow.h"

stack_overflow::stack_overflow(const char* message) noexcept : mMessage(message) { }

const char* stack_overflow::what() const noexcept
{
    return mMessage;
}
