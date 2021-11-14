#pragma once
#include "item.h"
#include <vector>
using namespace std;

class Stack {
private:
    Item top;
    vector  <Item> stackVector;

public:

    Stack() :top(0, 0, 0, Line::START) {}; // ctor

    void push(Item x);
    Item pop();
    void MakeEmpty();
    bool isEmpty();
 };