#include "Stack.h"
#include "stack_overflow.h"

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
    return content.back();
}

void Stack::search()
{

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
    return Stack();
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
