#include <iostream>
#include <string>
#include "Trie.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
    string testStrs[19] = {
            "ant",
            "cat",
            "zoo",
            "zone",
            "bat",
            "band",
            "bean",
            "fish",
            "fishing",
            "banana",
            "catch",
            "cannot",
            "can",
            "find",
            "fix",
            "any",
            "zone",
            "zoos",
            "zoo"
    };

    int testStrCount = 19;


    Trie trie;

    for(int c = 0; c < testStrCount; c++) {
        trie.insertStr(testStrs[c]);
    }

    string ant = "ant";
    string zoo = "zoo";

    cout<<"Contains ant: "<< trie.strExists(ant)<<endl;
    cout<<"Contains zoo: "<< trie.strExists(zoo)<<endl;

    trie.printStrs();

    return 0;
}
