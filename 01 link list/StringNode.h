#ifndef STRINGNODE_H
#define STRINGNODE_H

#include <string>
using namespace std;

class StringNode {
private:
    string elem;
    StringNode* next;
    friend class StringLinkedList;
};

#endif
  