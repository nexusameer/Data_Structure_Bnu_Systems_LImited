#ifndef STRINGLINKEDLIST_H
#define STRINGLINKEDLIST_H

#include "StringNode.h"

class StringLinkedList {
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const std::string& front() const;
    void addFront(const std::string& e);
    void removeFront();

private:
    StringNode* head;
};

#endif
