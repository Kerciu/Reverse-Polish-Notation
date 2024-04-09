#include "Stack.h"

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

    char lastElem = content.back();
    content.pop_back();
      

    return lastElem;
}

void Stack::peek()
{
}

void Stack::search()
{
}

bool Stack::isEmpty()
{
    return false;
}

size_t Stack::size()
{
    return size_t();
}

void Stack::clear()
{
}

Stack Stack::copyStack() const
{
    return Stack();
}

Stack& Stack::operator=(const Stack& other)
{
    // TODO: tu wstawiæ instrukcjê return
}

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
    for (int i = 0; i < stack.content.size(); i++) {
        os << "[ " << stack.content[i] << " ]\n";
    }
    return os;
}
