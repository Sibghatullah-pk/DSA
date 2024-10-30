#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Create a global head pointer to the linked list
Node* head = nullptr;

// Function to insert a new node at the beginning of the linked list
void insertNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to display all nodes in the linked list
void displayList() {
    cout << "The list contains the data entered:\n";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    insertNode(1);
    insertNode(3);
    insertNode(5);
    insertNode(7);
    insertNode(9);
    insertNode(11);

    displayList();

    return 0;
}