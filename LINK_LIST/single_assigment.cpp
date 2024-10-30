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

class SingleLinkedList {
private:
    Node* head;
    
public:

    SingleLinkedList() {
        head = nullptr;
    }

    // Initialize the list with values
    void initializeList() {
        int values[] = {5, 7, 4, 3, 8, 9, 2, 6, 1};
        for (int val : values) {
            addAtEnd(val);
        }
    }

    // Add node at the start
    void addAtStart(int val) {
        Node* newNode = new Node(val);
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
        }
    }

    // Add after a specific value (middle insertion)
    void addAfterValue(int afterVal, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterVal) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SingleLinkedList list;
    list.initializeList();
    cout << "Initial List: ";
    list.display();

    // Perform operations
    list.addAtStart(7);
     cout << "After Additions: at start ";
    list.display();
    list.addAfterValue(4, 0);
     cout << "Additions:After  4 ";
    list.display();
    list.addAtEnd(2);
    
    cout << "After Additions:at end  ";
    list.display();
    
    list.deleteByValue(5);
      cout << "After Deletions:5 ";
    list.display();
    list.deleteByValue(9);  
      cout << "After Deletions: 9";
    list.display();
    list.deleteByValue(1);
    
    cout << "After Deletions:1 ";
    list.display();

    return 0;
}
