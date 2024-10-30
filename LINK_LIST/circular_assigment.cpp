#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
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
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Add node at the end
    void addAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Add after a specific value
    void addAfterValue(int afterVal, int val) {
        Node* temp = head;
        do {
            if (temp->data == afterVal) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) return;

        if (head->data == val && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        do {
            if (temp->data == val) {
                if (prev != nullptr) prev->next = temp->next;
                else {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = head->next;
                    head = head->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    // Display the list
    void display() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
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
