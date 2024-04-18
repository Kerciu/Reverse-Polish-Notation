#include <iostream>
#include "Handler.h"
#include "stack.h"

int main()
{
    Handler handler;
    Stack stack;

    std::string input;
    std::cin >> handler;

    int result = handler.stackifyExpression(stack);

    std::cout << result;
}