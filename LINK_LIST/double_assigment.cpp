#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() {
        head = nullptr;
    }

    // Initialize the list
    void initializeList() {
        int values[] = {5, 7, 4, 3, 8, 9, 2, 6, 1};
        for (int val : values) {
            addAtEnd(val);
        }
    }

    // Add node at the start
    void addAtStart(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    // Add node at the end
    void addAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Add after a specific value
    void addAfterValue(int afterVal, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterVal) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) return;

        Node* temp = head;

        if (temp->data == val) {
            head = temp->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            if (temp->prev != nullptr) temp->prev->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoubleLinkedList list;
    list.initializeList();
    cout << "Initial List: ";
    list.display();

    // Perform operations
    list.addAtStart(7);
    list.addAfterValue(4, 0);
    list.addAtEnd(2);
    
    cout << "After Additions: ";
    list.display();
    
    list.deleteByValue(5);
    list.deleteByValue(9);
    list.deleteByValue(1);
    
    cout << "After Deletions: ";
    list.display();

    return 0;
}
