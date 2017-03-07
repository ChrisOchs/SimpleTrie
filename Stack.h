#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "StackEntry.h"

class Stack {

 private:
    int currStackSize;
    int currEntries;

    StackEntry ** arr;

    void expand();
    void contract();

 public:
    Stack();
    ~Stack();

    void push(StackEntry*);
    StackEntry* pop();
    StackEntry* top();

    bool isEmpty();

    int size();
};

#endif // STACK_H_INCLUDED
