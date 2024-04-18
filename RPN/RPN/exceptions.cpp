#include "exceptions.h"
#include "exceptions.h"

stack_overflow::stack_overflow(const char* message) noexcept : mMessage(message) { }

const char* stack_overflow::what() const noexcept
{
    return mMessage;
}
