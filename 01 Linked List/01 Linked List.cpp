#include<iostream>
using namespace std;
class StringNode {
private:
	string elem;
	StringNode* next;
public:
	StringNode(string e) {
		elem = e;
		next = nullptr;
	}
	void set_next(StringNode* nextnode) {
		next = nextnode;
	}
	void print() {
		cout << elem << " " << next << endl;
	}
};
int main() {
	StringNode node1("Muhammad");
	StringNode node2("Ameer");
	StringNode node3("Hamza");
	StringNode node4("Kamboh");
;
	node2.set_next(&node1);
	node3.set_next(&node2);
	node4.set_next(&node3);
	cout << &node1 << " 1st node" << endl;
	node1.print();
	cout << &node2 << " 2nd node" << endl;
	node2.print();
	cout << &node3 << " 3rd node"  << endl;
	node3.print();
	cout << &node3 << " 4th node" << endl;
	node4.print();
}