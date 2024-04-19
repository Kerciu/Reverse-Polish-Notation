#include <algorithm>
#include "Stack.h"
#include "../exceptions/exceptions.h"

// TODO
// Get rid of vectors - replace it with dynamic array

Stack::Stack() : content { }
{ }

bool Stack::checkIfOverflown(int stackSize)
{
    return (stackSize >= 1000);
}

void Stack::push(char elem)
{
    content.push_back(elem);
}

char Stack::pop()
{   
    if (content.empty()) {
        throw std::exception("e");  /*throw stack_empty("Stack is empty!");*/
    }
    if (checkIfOverflown(content.size())) throw stack_overflow("Stack overflow!");

    char lastElem = content.back();
    content.pop_back();
      

    return lastElem;
}

char Stack::peek()
{
    if (content.empty()) throw stack_underflow("Stack is empty!");
    return content.back();
}

int Stack::search(char val)
{
    if (content.empty()) throw stack_underflow("Stack is empty!");

    auto it = std::find(content.begin(), content.end(), val);
    if (it != content.end()) {
        return std::distance(content.begin(), it) + 1;
    }

    throw no_element_found("No such element found...");
}

bool Stack::isEmpty()
{
    return content.empty();
}

size_t Stack::size()
{
    return content.size();
}

void Stack::clear()
{
    content.clear();
}

Stack Stack::copyStack() const
{
    Stack* newStack = new Stack;

    for (char v : content) newStack->push(v);

    return *newStack;
}

Stack& Stack::operator=(const Stack& other)
{
    if (&other != this) {
        this->content.clear();
        this->content = other.content;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
    for (int i = 0; i < stack.content.size(); i++) {
        os << "[ " << stack.content[i] << " ]\n";
    }
    return os;
}
