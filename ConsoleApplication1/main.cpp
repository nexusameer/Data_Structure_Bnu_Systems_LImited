#include "StringLinkedList.h"

int main() {
    StringLinkedList L1;
    L1.addFront("Hello");
    L1.addFront("World");

    L1.display();
    string output = L1.concantenate();
    cout << "\n" << output << endl;

}