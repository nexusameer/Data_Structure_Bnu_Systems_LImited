#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(string data) {
        root = insertRecursive(root, data);
    }

    Node* insertRecursive(Node* current, string data) {
        if (current == nullptr) {
            current = new Node();
            current->data = data;
            current->left = nullptr;
            current->right = nullptr;
            return current;
        }

        if (data < current->data) {
            current->left = insertRecursive(current->left, data);
        }
        else if (data > current->data) {
            current->right = insertRecursive(current->right, data);
        }

        return current;
    }

    void printInOrder() {
        printInOrderRecursive(root);
    }

    void printInOrderRecursive(Node* current) {
        if (current != nullptr) {
            printInOrderRecursive(current->left);
            cout << current->data << " ";
            printInOrderRecursive(current->right);
        }
    }
};

class HashTable {
public:
    int size;
    BST* table;

    HashTable(int size) {
        this->size = size;
        table = new BST[size];
    }

    int hashFunction(string data) {
        int sum = 0;
        for (int i = 0; i < data.length(); i++) {
            sum += data[i];
        }
        return sum % size;
    }

    void insert(string data) {
        int index = hashFunction(data);
        table[index].insert(data);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            table[i].printInOrder();
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    string names[] = { "Jack", "Noor Gul", "Ertughral", "Bamsi", "Roshan", "Gonalap", "Halima", "bala", "malhun", "yoyo", "Ron", "colgate", "fernanda", "yaksal", "harry", "rascal", "mainu", "wonder woman", "vickesen", "hoor", "faron", "jaikan", "kashi", "hira naz", "deol", "sunny", "noora fateh", "butt", "rafy", "synsodyne" };

    for (int i = 0; i < 30; i++) {
        hashTable.insert(names[i]);
    }

    hashTable.print();

    return 0;
}