#pragma once

#include <iostream>
using namespace std;

#include "StringNode.h"
class StringLinkedList
{
public:
    StringLinkedList();				// empty list constructor
    ~StringLinkedList();			// destructor
    bool empty() const;				// is list empty?
    const string& front() const;		// get front element
    void addFront(const string& e);		// add to front of list
    void removeFront();				// remove front item list
    void display();
    string concantenate();
private:
    StringNode* head;				// pointer to the head of list
};