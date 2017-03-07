#include "StackEntry.h"

StackEntry::StackEntry(TrieNode* node, string& strSoFar) {
    this->node = node;
    this->strSoFar = new string(strSoFar);
}

StackEntry::~StackEntry() {
    delete this->strSoFar;
}

TrieNode*
StackEntry::getNode() {
    return this->node;
}

string&
StackEntry::getStrSoFar() {
    return *this->strSoFar;
}
