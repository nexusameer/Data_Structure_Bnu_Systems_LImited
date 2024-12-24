#pragma once

#include "CNode.h"

#include <iostream>
using namespace std;

class CircleList {				// a circularly linked list
public:
    CircleList();				// constructor
    ~CircleList();				// destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;			// element at cursor
    const Elem& back() const;			// element following cursor 
    void advance();				// advance cursor
    void add(const Elem& e);			// add after cursor
    void remove();				// remove node after cursor
    bool isEqual(const CircleList& other) const;	// check if two lists are equal
private:
    CNode* cursor;				// the cursor 
};