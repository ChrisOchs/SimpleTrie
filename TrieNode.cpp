#include "TrieNode.h"

TrieNode::TrieNode() {

    this->endsStr = false;

    for(int c = 0; c < 26; c++) {
        children[c] = NULLPTR;
    }
}

bool
TrieNode::getNodeEndsStr() {
    return this->endsStr;
}

void
TrieNode::setNodeEndsStr(bool value) {
    this->endsStr = value;
}

TrieNode*
TrieNode::getChild(int index) {
    return children[index];
}

void
TrieNode::addChild(int index) {

    if( getChild(index) == NULLPTR ) {
        this->children[index] = new TrieNode();
    }

}

