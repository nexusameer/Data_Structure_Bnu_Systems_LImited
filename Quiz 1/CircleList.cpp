#include "CircleList.h"

bool CircleList::empty() const		// is list empty?
{
    return cursor == NULL;
}

const Elem& CircleList::back() const		// element at cursor
{
    return cursor->elem;
}

const Elem& CircleList::front() const		// element following cursor
{
    return cursor->next->elem;
}

void CircleList::advance()			// advance cursor
{
    cursor = cursor->next;
}

void CircleList::remove() {			// remove node after cursor
    CNode* old = cursor->next;			// the node being removed
    if (old == cursor) 				// removing the only node?
        cursor = NULL;				// list is now empty
    else
        cursor->next = old->next;			// link out the old node 
    delete old;					// delete the old node
}

CircleList::CircleList()			// constructor
    : cursor(NULL) { }

CircleList::~CircleList()			// destructor
{
    while (!empty()) remove();
}

void CircleList::add(const Elem& e) {		// add after cursor
    CNode* v = new CNode;			// create a new node
    v->elem = e;
    if (cursor == NULL) {			// list is empty?
        v->next = v;				// v points to itself
        cursor = v;				// cursor points to v
    }
    else {					// list is nonempty?
        v->next = cursor->next;			// link in v after cursor
        cursor->next = v;
    }
}

bool CircleList::isEqual(const CircleList& other) const {
    if (empty() && other.empty()) return true; // both lists are empty
    if (empty() || other.empty()) return false; // one list is empty, the other is not

    CNode* curr1 = cursor;
    CNode* curr2 = other.cursor;

    do {
        if (curr1->elem != curr2->elem) return false; // elements are not equal
        curr1 = curr1->next;
        curr2 = curr2->next;
    } while (curr1 != cursor); // loop until we reach the starting point again

    return true; // all elements are equal
}