#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class queue {
    node* head;
    node* tail;
    int size;

public:
    queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    // Adding data to the queue
    void enqueue(int data) {
        node* newnode = new node(data);
        if (this->head == NULL) { 
            this->head = this->tail = newnode;
        } else {
            this->tail->next = newnode;
            this->tail = newnode;
        }
        size++;
    }

    // Removing data from the queue (dequeuing)
    void dequeue() {
        if (this->head == NULL) {
            cout << "No tickets to process.\n";
            return;
        } else {
            node* oldhead = this->head;
            cout << "Processing Ticket ID " << this->head->data << endl;
            this->head = oldhead->next;
            if (this->head == NULL) {
                this->tail = NULL; // If the queue becomes empty, reset tail
            }
            delete oldhead;
            size--;
        }
    }

    // Getting the size of the queue
    int getSize() {
        return this->size;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return this->head == NULL;
    }

    // Get the data from the front of the queue
    int front() {
        if (this->head == NULL) {
            return -1; // Return -1 if queue is empty
        }
        return this->head->data;
    }

    // Display all current tickets in the queue without dequeuing them
    void displayQueue() {
        if (this->head == NULL) {
            cout << "No tickets in the queue.\n";
            return;
        }

        node* temp = this->head;
        cout << "Current tickets in the queue:\n";
        while (temp != NULL) {
            cout << "Ticket ID: " << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    queue qu;
    int ticketID;
    int choice;

    // Main loop to demonstrate queue functionality
    do {
        cout << "\nCustomer Support Ticketing System\n";
        cout << "1. Add a new support ticket\n";
        cout << "2. Process the next ticket\n";
        cout << "3. Display all current tickets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter ticket ID: ";
                cin >> ticketID;
                qu.enqueue(ticketID);
                break;
            }
            case 2: {
                if (qu.front() != -1) {
                    cout << "Processing ticket: " << qu.front() << endl;
                }
                qu.dequeue();
                break;
            }
            case 3: {
                cout << "Size of the queue: " << qu.getSize() << endl;
                qu.displayQueue();
                break;
            }
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
