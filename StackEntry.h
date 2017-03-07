#ifndef STACKENTRY_H_INCLUDED
#define STACKENTRY_H_INCLUDED

#include <string>
#include "TrieNode.h"

using std::string;

class StackEntry {

private:
    TrieNode* node;
    string* strSoFar;

public:
    StackEntry(TrieNode*, string&);
    ~StackEntry();

    TrieNode* getNode();
    string& getStrSoFar();


};


#endif
