#include <iostream>

struct Node {
    int data;
    Node* next;
};

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Node** head) {
    int swapped;
    Node* last = nullptr;
    Node* current = *head;

    do {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                swap(&current, &current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void push(Node** head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    push(&head, 64);
    push(&head, 34);
    push(&head, 25);
    push(&head, 12);
    push(&head, 22);
    push(&head, 11);
    push(&head, 90);

    std::cout << "Unsorted Linked List: ";
    printList(head);

    bubbleSort(&head);

    std::cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}