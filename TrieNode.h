#ifndef TRIENODE_H_INCLUDED
#define TRIENODE_H_INCLUDED

#define NULLPTR 0

class TrieNode {
    private:
        bool endsStr;
        TrieNode* children[26];

    public:
        TrieNode();

        bool getNodeEndsStr();
        void setNodeEndsStr(bool);

        TrieNode* getChild(int);

        void addChild(int);
};

#endif // TRIENODE_H_INCLUDED
