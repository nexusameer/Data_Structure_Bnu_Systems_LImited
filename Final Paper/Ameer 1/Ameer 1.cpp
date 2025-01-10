#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteLargest() {
        if (head == nullptr) {
            return;
        }

        Node* largest = head;
        Node* current = head;

        while (current != nullptr) {
            if (current->data > largest->data) {
                largest = current;
            }
            current = current->next;
        }

        if (largest == head) {
            head = head->next;
        }
        else {
            Node* prev = head;
            while (prev->next != largest) {
                prev = prev->next;
            }
            prev->next = largest->next;
        }

        delete largest;
    }
};

int main() {
    LinkedList list1;
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.insert(50);

    cout << "List 1 before deleting largest: ";
    list1.printList();

    list1.deleteLargest();

    cout << "List 1 after deleting largest: ";
    list1.printList();

    LinkedList list2;
    list2.insert(5);
    list2.insert(15);
    list2.insert(25);
    list2.insert(35);
    list2.insert(45);

    cout << "List 2 before deleting largest: ";
    list2.printList();

    list2.deleteLargest();

    cout << "List 2 after deleting largest: ";
    list2.printList();

    LinkedList list3;
    list3.insert(100);
    list3.insert(200);
    list3.insert(300);
    list3.insert(400);
    list3.insert(500);

    cout << "List 3 before deleting largest: ";
    list3.printList();

    list3.deleteLargest();

    cout << "List 3 after deleting largest: ";
    list3.printList();

    return 0;
}