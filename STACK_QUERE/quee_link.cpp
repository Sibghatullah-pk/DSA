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
    // adding data to queue
    void enque(int data) {
        node* newnode = new node(data);
        if (this->head == NULL) { 
            this->head = this->tail = newnode;
        } else {
            this->tail->next = newnode;
            this->tail = newnode;
        }
        size++;
    }

    void deque() {
        if (this->head == NULL) { // Corrected comparison
            return;
        }
        else {
            node* oldhead = this->head;
            this->head = oldhead->next;
            if (this->head == NULL) { // Corrected comparison
                this->tail = NULL; // If queue becomes empty, update tail to NULL
            }
            oldhead->next = NULL;
            delete oldhead;
            size--;
        }
    }

    int getsize() {
        return this->size;
    }
    bool empty()
    {
        return this->head==NULL;
    }
    int get() {
        if (this->head == NULL) { // Corrected comparison
            return -1; // Return -1 if queue is empty
        }
        return this->head->data;
    }
};

int main() {
    queue qu;
    qu.enque(14);
    qu.enque(20);
    qu.enque(15);
    qu.enque(1);
    qu.deque();
    qu.enque(10);
    qu.deque();
    
    cout << "Size is: " << qu.getsize() << endl;
    while( !qu.empty())
    {
    cout << "Front element is: " << qu.get() << endl;
    qu.deque();
    }
    return 0;
}
