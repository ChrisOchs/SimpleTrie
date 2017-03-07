#include <iostream>
#include <string>

#include "TrieNode.h"
#include "Trie.h"
#include "StackEntry.h"
#include "Stack.h"

#define MAX_CHARS 25

using std::cout;
using std::endl;
using std::string;

char getChar(int);
int getIndex(char);

Trie::Trie() {
    this->root = NULLPTR;
}

Trie::~Trie() {
    if(this->root == NULLPTR) {
        return;
    }

    Stack stk;

    string emptyStr = "";

    stk.push(new StackEntry(this->root, emptyStr));

    while(!stk.isEmpty()) {
        StackEntry * entry = stk.pop();

        for(int c = 0; c <= MAX_CHARS; c++) {
            TrieNode * childPtr = entry ->getNode()->getChild(c);

            if(childPtr != NULLPTR) {
                stk.push(new StackEntry(childPtr, emptyStr));
            }
        }

        delete entry->getNode();
        delete entry;
    }
}

void
Trie::insertStr(string& str) {

    if(this->root == NULLPTR) {
        this->root = new TrieNode();
    }

    TrieNode * ptr = this->root;

    for(int c = 0; c < str.length(); ++c) {
        int idx = getIndex(str[c]);

        ptr->addChild(idx);

        ptr = ptr->getChild(idx);

        if(c == str.length() - 1) {
            ptr->setNodeEndsStr(true);
        }
    }
}

bool
Trie::strExists(string& str) {
    if(this->root == NULLPTR) {
        return false;
    }

    TrieNode * ptr = this->root;

    for(int c = 0; c < str.length(); ++c) {
        int idx = getIndex(str[c]);

        ptr = ptr->getChild(idx);

        if(ptr == NULLPTR) {
            return false;
        }

        if(c == str.length() - 1) {
            return ptr->getNodeEndsStr();
        }
    }

    return false;
}

void
Trie::printStrs() {

    if(this->root == NULLPTR) {
        return;
    }

    Stack stk;

    string emptyStr = "";

    stk.push(new StackEntry(this->root, emptyStr));

    int count = 1;

    while(!stk.isEmpty()) {
        StackEntry * entry = stk.pop();

        TrieNode* node = entry->getNode();

        if(node->getNodeEndsStr()) {
            cout<<count<<": "<<entry->getStrSoFar()<<endl;

            count++;
        }

        for(int c = MAX_CHARS; c >= 0; c--) {
            TrieNode* child = node->getChild(c);

            if(child != NULLPTR) {
                string strSoFar = entry->getStrSoFar() + getChar(c);

                stk.push(new StackEntry(child, strSoFar));
            }
        }

        delete entry;
    }
}

char getChar(int idx) {
    return (char)(idx + 97);
}

int getIndex(char c) {
    return c - 97;
}


