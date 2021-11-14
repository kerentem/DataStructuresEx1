#include "stack.h"
//Stack::Stack() :top(0, 0, 0, Line::START) {};

void Stack::push(Item x)
{
    stackVector.push_back(x);
}

Item Stack::pop()
{
    Item temp = stackVector.back();
    stackVector.pop_back();
    return temp;
}

void Stack::MakeEmpty()
{
    stackVector.clear();
}

bool Stack::isEmpty()
{
    return stackVector.empty();
}