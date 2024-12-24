#include<iostream>
using namespace std;

class Student {
public:
    int ID;
    double GPA;
    string name;
};

class DNode {                  // doubly linked list node
private:
    Student elem;              // node element value
    DNode* prev;               // previous node in list
    DNode* next;               // next node in list
    friend class DLinkedList;  // allow DLinkedList access
};

class DLinkedList {            // doubly linked list
public:
    DLinkedList();             // constructor
    ~DLinkedList();            // destructor
    bool empty() const;        // is list empty?
    const Student& front() const;  // get front element
    const Student& back() const;   // get back element
    void addFront(const Student& e);  // add to front of list
    void addBack(const Student& e);   // add to back of list
    void removeFront();         // remove from front
    void removeBack();          // remove from back
    void print() const;
    void HighestGPA() const;
    string InsertNode(string n,string a);
    string DeleteNode(string n);
    void findStudent(int ID) const;  // find student by ID

private:                   // local type definitions
    DNode* header;          // list sentinels
    DNode* trailer;
protected:                 // local utilities
    void add(DNode* v, const Student& e);  // insert new node before v
    void remove(DNode* v);  // remove node v
};

DLinkedList::DLinkedList() {          // constructor
    header = new DNode;              // create sentinels
    trailer = new DNode;
    header->next = trailer;          // have them point to each other
    trailer->prev = header;
}

bool DLinkedList::empty() const       // is list empty?
{
    return (header->next == trailer);
}

const Student& DLinkedList::front() const  // get front element
{
    return header->next->elem;
}

const Student& DLinkedList::back() const   // get back element
{
    return trailer->prev->elem;
}

void DLinkedList::remove(DNode* v) {      // remove node v
    DNode* u = v->prev;              // predecessor
    DNode* w = v->next;              // successor
    u->next = w;              // unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront()        // remove from font
{
    remove(header->next);
}

void DLinkedList::removeBack()         // remove from back
{
    remove(trailer->prev);
}

// insert new node before v
void DLinkedList::add(DNode* v, const Student& e) {
    DNode* u = new DNode;  u->elem = e;      // create a new node for e
    u->next = v;                          // link u in between v
    u->prev = v->prev;                    // ...and v->prev
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Student& e)  // add to front of list
{
    add(header->next, e);
}

DLinkedList::~DLinkedList() {          // destructor
    while (!empty()) removeFront();     // remove all but sentinels
    delete header;              // remove the sentinels
    delete trailer;
}

void DLinkedList::addBack(const Student& e)   // add to back of list
{
    add(trailer, e);
}

void DLinkedList::print() const {
    DNode* curr = header->next;
    while (curr != trailer) {
        cout << "ID: " << curr->elem.ID << ", Name: " << curr->elem.name << ", GPA: " << curr->elem.GPA << endl;
        curr = curr->next;
    }
}

void DLinkedList::findStudent(int ID) const {
    DNode* curr = header->next;
    while (curr != trailer) {
        if (curr->elem.ID == ID) {
            cout << "Student found: " << curr->elem.name << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Student not found." << endl;
}

void DLinkedList::HighestGPA() const {
	DNode* curr = header->next;
	double max = curr->elem.GPA;
	while (curr != trailer) {
		if (curr->elem.GPA > max) {
			max = curr->elem.GPA;
		}
		curr = curr->next;
	}
	cout << "Highest GPA: " << max << endl;
}
//add a func to doubly linked list class which a user can call to delete a node by value

string DLinkedList::DeleteNode(string n) {
    DNode* curr = header->next;
    while (curr != trailer) {
        if (curr->elem.name == n) {
            remove(curr);
            return "Node deleted successfully";
        }
        curr = curr->next;
    }
    return "Node not found";
}

string DLinkedList::InsertNode(string n, string a) {
    DNode* curr = header->next;
    while (curr != trailer) {
        if (curr->elem.name == n) {
            Student s6;
            s6.ID = 6;
            s6.GPA = 3.5;
            s6.name = a;
            add(curr, s6);
            return "Node inserted successfully";
        }
        curr = curr->next;
    }
    cout << "not found" << endl;
    return "Node not found";
}
int main() {
    DLinkedList L1;
    Student s1;
    s1.ID = 1;
    s1.GPA = 1;
    s1.name = "Ameer";
    L1.addBack(s1);

    Student s2;
    s2.ID = 2;
    s2.GPA = 3;
    s2.name = "Hamza";
    L1.addBack(s2);

    Student s3;
    s3.ID = 3;
    s3.GPA = 1;
	s3.name = "Ali";
	L1.addBack(s3);


    Student s5;
    s5.GPA = 4;
	s5.ID = 5;
	s5.name = "Ahmed";
	L1.addFront(s5);


    L1.InsertNode("Ahmed","abc");
    L1.InsertNode("Hamza", "xyz");


    L1.print();
	return 0;
}