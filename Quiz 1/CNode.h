#pragma once

#include <string>
using namespace std;

typedef string Elem;				// element type
class CNode {					// circularly linked list node
public:
    Elem elem;					// linked list element value
    CNode* next;				// next item in the list

    friend class CircleList;			// provide CircleList access
};