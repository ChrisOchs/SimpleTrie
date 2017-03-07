#ifndef TRIE_H
#define TRIE_H

#include <string>
#include "TrieNode.h"

using std::string;

class Trie {

private:
    TrieNode * root;

public:
    Trie();
    ~Trie();

    void insertStr(string&);

    bool strExists(string&);

    void printStrs();
};

#endif
