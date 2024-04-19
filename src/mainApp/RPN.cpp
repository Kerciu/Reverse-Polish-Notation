#include <iostream>
#include "../handler/Handler.h"
#include "../stack/stack.h"

int main()
{
    try {
        Handler handler;
        Stack stack;

        std::string input;
        std::cin >> handler;

        int result = handler.stackifyExpression(stack);

        std::cout << result;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}