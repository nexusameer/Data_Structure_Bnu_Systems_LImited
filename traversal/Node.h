#include <iostream>
using namespace std;

struct Node {

    // Data part of the node
    int data;


    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    // Pointer to the next node in the list
    Node* next;
    void traverseLinkedList(Node* head)
    {
        // Start from the head of the linked list
        Node* current = head;

        // Traverse the linked list until reaching the end
        // (nullptr)
        while (current != nullptr) {

            // Print the data of the current node
            cout << current->data << " ";

            // Move to the next node
            current = current->next;
        }

        cout << std::endl;
    }

    // Function to search for a value in the Linked List
    bool searchLinkedList(struct Node* head, int target)
    {
        // Traverse the Linked List
        while (head != nullptr) {

            // Check if the current node's
            // data matches the target value
            if (head->data == target) {
                return true; // Value found
            }

            // Move to the next node
            head = head->next;
        }

        return false; // Value not found
    }

    // C++ function to find the length of the linked list
    int findLength(Node* head)
    {
        // Initialize a counter for the length
        int length = 0;

        // Start from the head of the list
        Node* current = head;

        // Traverse the list and increment the length for each
        // node
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // Return the final length of the linked list
        return length;
    }
    
    // C++ function to insert a new node at the beginning of the
// linked list
    Node* insertAtBeginning(Node* head, int value)
    {
        // Create a new node with the given value
        Node* newNode = new Node(value);

        // Set the next pointer of the new node to the current
        // head
        newNode->next = head;

        // Move the head to point to the new node
        head = newNode;

        // Return the new head of the linked list
        return head;
    }
    
    // C++ Function to insert a node at the end of the linked
// list
    Node* insertAtEnd(Node* head, int value)
    {
        // Create a new node with the given value
        Node* newNode = new Node(value);

        // If the list is empty, make the new node the head
        if (head == nullptr)
            return newNode;

        // Traverse the list until the last node is reached
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        // Link the new node to the current last node
        curr->next = newNode;
        return head;
    }

    // Function to insert a Node at a specified position
// without using a double pointer
    Node* insertPos(Node* head, int pos, int data)
    {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return head;
        }

        // Special case for inserting at the head
        if (pos == 1) {
            Node* temp = new Node(data);
            temp->next = head;
            return temp;
        }

        // Traverse the list to find the node
        // before the insertion point
        Node* prev = head;
        int count = 1;
        while (count < pos - 1 && prev != nullptr) {
            prev = prev->next;
            count++;
        }

        // If position is greater than the number of nodes
        if (prev == nullptr) {
            cout << "Invalid position!" << endl;
            return head;
        }

        // Insert the new node at the specified position
        Node* temp = new Node(data);
        temp->next = prev->next;
        prev->next = temp;

        return head;
    }

    // C++ Function to remove the last node of the linked list
    Node* removeLastNode(Node* head)
    {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Find the second last node
        Node* second_last = head;
        while (second_last->next->next != nullptr)
            second_last = second_last->next;

        // Delete last node
        delete (second_last->next);

        // Change next of second last
        second_last->next = nullptr;

        return head;
    }

    // C++ function to delete a node at a specific position
    Node* deleteAtPosition(Node* head, int position)
    {
        // If the list is empty or the position is invalid
        if (head == nullptr || position < 1) {
            return head;
        }

        // If the head needs to be deleted
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Traverse to the node before the position to be
        // deleted
        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr;
            i++) {
            current = current->next;
        }

        // If the position is out of range
        if (current == NULL || current->next == nullptr) {
            return;
        }

        // Store the node to be deleted
        Node* temp = current->next;

        // Update the links to bypass the node to be deleted
        current->next = current->next->next;

        // Delete the node
        delete temp;

        return head;
    }

    
};