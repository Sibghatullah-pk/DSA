#include<iostream>
#include<vector>
using namespace std;

class quee{
    int front;
    int back;
    vector<int> v;
    
public:
    quee() {
        this->front = -1;
        this->back = -1;
    }

    // Enqueue operation: adds an element to the queue
    void enquee(int data) {
        if (this->front == -1) {
            this->front = 0;  // Initialize front when the first element is enqueued
        }
        this->v.push_back(data);
        this->back++;
    }

    // Dequeue operation: removes an element from the queue
    void dequee() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            this->front++;
            if (this->front > this->back) {  // Reset the queue if all elements are dequeued
                this->front = -1;
                this->back = -1;
                this->v.clear();
            }
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (this->front == -1 || this->front > this->back);
    }

    // Get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;
        }
        return this->v[this->front];
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= back; i++) {
            cout << this->v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    quee q;
    
    q.enquee(10);
    q.enquee(20);
    q.enquee(30);
    q.display(); // Should print 10 20 30

    cout << "Front element: " << q.peek() << endl; // Should print 10
    
    q.dequee();
    q.display(); // Should print 20 30
    
    q.dequee();
    q.dequee();
    q.display(); // Should print "Queue is empty."
    
    q.dequee(); // Trying to dequeue from an empty queue
    
    return 0;
}
