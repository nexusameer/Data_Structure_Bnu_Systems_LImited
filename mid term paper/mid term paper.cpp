#include <iostream>
#include <string>
using namespace std;

typedef char Elem;				// list element type

class DNode {					// doubly linked list node
private:
    Elem elem;					// node element value
    DNode* prev;				// previous node in list
    DNode* next;				// next node in list
    friend class DLinkedList;			// allow DLinkedList access
};

class DLinkedList {				// doubly linked list
public:
    DLinkedList();				// constructor
    ~DLinkedList();				// destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;			// get front element
    const Elem& back() const;			// get back element
    void addFront(const Elem& e);		// add to front of list
    void addBack(const Elem& e);		// add to back of list
    void removeFront();				// remove from front
    void removeBack();				// remove from back
    DNode* findNode(string findme) const;	// find node with given string
    bool insertBetween(DNode* u, DNode* v, string newElement);	// insert new node between two nodes
    void printList(DLinkedList& list);

private:					// local type definitions
    DNode* header;				// list sentinels
    DNode* trailer;
protected:					// local utilities
    void add(DNode* v, const Elem& e);		// insert new node before v
    void remove(DNode* v);			// remove node v
};

DLinkedList::DLinkedList() {			// constructor
    header = new DNode;				// create sentinels
    trailer = new DNode;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}

bool DLinkedList::empty() const		// is list empty?
{
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const	// get front element
{
    return header->next->elem;
}

const Elem& DLinkedList::back() const		// get back element
{
    return trailer->prev->elem;
}

void DLinkedList::remove(DNode* v) {		// remove node v
    DNode* u = v->prev;				// predecessor
    DNode* w = v->next;				// successor
    u->next = w;				// unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront()		// remove from font
{
    remove(header->next);
}

void DLinkedList::removeBack()		// remove from back
{
    remove(trailer->prev);
}

// insert new node before v
void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;  u->elem = e;		// create a new node for e
    u->next = v;				            // link u in between v
    u->prev = v->prev;				        // ...and v->prev
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e)	// add to front of list
{
    add(header->next, e);
}

DLinkedList::~DLinkedList() {			// destructor
    while (!empty()) removeFront();		// remove all but sentinels
    delete header;				// remove the sentinels
    delete trailer;
}

void DLinkedList::addBack(const Elem& e)	// add to back of list
{
    add(trailer, e);
}

DNode* DLinkedList::findNode(string findme) const {
    DNode* v = header->next;
    while (v != trailer) {
        if (v->elem == findme[0]) {
            return v;
        }
        v = v->next;
    }
    return nullptr;
}

bool DLinkedList::insertBetween(DNode* u, DNode* v, string newElement) {
    if (u->next != v) {
        return false;
    }
    DNode* newNode = new DNode;
    newNode->elem = newElement[0];
    newNode->next = v;
    newNode->prev = u;
    u->next = newNode;
    v->prev = newNode;
    return true;
}
void DLinkedList::printList(DLinkedList& list) {
    DNode* v = list.header->next;
    while (v != list.trailer) {
        cout << v->elem;
        if (v->next != list.trailer) {
            cout << " -> ";
        }
        v = v->next;
    }
    cout << endl;
}


int main() {
    DLinkedList L1;
    L1.addBack('A');
    L1.addBack('B');
    L1.addBack('C');
    L1.addBack('D');
    L1.printList(L1);
    cout << "Test 1: Insert yy in the middle" << endl;
    L1.insertBetween(L1.findNode("B"), L1.findNode("C"), "Y");
    L1.printList(L1);
    cout << endl;

    DLinkedList L2;
    L2.addBack('X');
    L2.addBack('Y');
    L2.addBack('Z');
    L2.printList(L2);
    cout << "Test 2: Try to insert aa between xx and zz" << endl;
    if (L2.insertBetween(L2.findNode("X"), L2.findNode("Z"), "AA")) {
        L2.printList(L2);
    }
    else {
        cout << "Could not insert AA between X and Z" << endl;
    }
    cout << endl;

    DLinkedList L3;
    L3.addBack('A');
    L3.addBack('B');
    L3.addBack('C');
    L3.addBack('D');
    L3.printList(L3);
    cout << "Test 3: Insert yy in between AA and BB" << endl;
    L3.insertBetween(L3.findNode("A"), L3.findNode("B"), "Y");
    L3.printList(L3);
    cout << endl;

    DLinkedList L4;
    L4.addBack('A');
    L4.addBack('B');
    L4.addBack('C');
    L4.addBack('D');
    L4.printList(L4);
    cout << "Test 4: Insert yy in between CC and DD" << endl;
    L4.insertBetween(L4.findNode("C"), L4.findNode("D"), "Y");
    L4.printList(L4);
    cout << endl;

    return 0;
}