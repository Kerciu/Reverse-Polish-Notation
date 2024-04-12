#include <iostream>
#include "Handler.h"
#include "stack.h"

int main()
{
    Handler handler;
    Stack stack;

    std::string expression;
    std::cin >> handler;

    handler.stackifyExpression(stack);

    std::cout << stack.peek();
}