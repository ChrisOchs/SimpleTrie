#include "Stack.h"

Stack::Stack() {
    this->currStackSize = 4;
    this->currEntries = 0;

    this->arr = new StackEntry*[4];
}

Stack::~Stack() {
    for(int c = 0; c < this->currEntries - 1; c++) {
        delete this->arr[c];
    }

    delete this->arr;
}

void
Stack::push(StackEntry* entry) {

    if((this->currEntries + 1) > this->currStackSize * 0.75) {
        expand();
    }

    this->arr[this->currEntries] = entry;
    this->currEntries++;
}

StackEntry*
Stack::top() {
    if(this->currEntries > 0) {
        return this->arr[this->currEntries - 1];
    } else {
        return NULL;
    }
}

StackEntry*
Stack::pop() {

    if((this->currEntries - 1) < this->currStackSize * 0.33) {
        contract();
    }

    if(this->currEntries > 0) {
        StackEntry* entry = this->arr[this->currEntries - 1];
        this->currEntries--;

        return entry;
    } else {
        return NULL;
    }
}

bool
Stack::isEmpty() {
    return size() == 0;
}

int
Stack::size() {
    return this->currEntries;

}

void
Stack::expand() {
    int nextStackSize = this->currStackSize * 2;

    StackEntry** nextArr = new StackEntry*[nextStackSize];

    for(int c = 0; c < this->currEntries; c++) {
        nextArr[c] = this->arr[c];
    }

    delete[] this->arr;

    this->currStackSize = nextStackSize;
    this->arr = nextArr;
}

void Stack::contract() {

    int nextStackSize = this->currStackSize / 2;

    if(nextStackSize == 0) {
        return;
    }

    StackEntry** nextArr = new StackEntry*[nextStackSize];

    for(int c = 0; c < this->currEntries; c++) {
        nextArr[c] = this->arr[c];
    }

    delete[] this->arr;

    this->currStackSize = nextStackSize;
    this->arr = nextArr;
}

