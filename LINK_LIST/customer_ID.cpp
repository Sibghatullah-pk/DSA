#include <iostream>
#include <string>

class CustomerNode {
public:
    std::string name;
    int id;
    CustomerNode* next;

    CustomerNode(std::string customerName, int customerId) 
        : name(customerName), id(customerId), next(nullptr) {}
};

class CustomerLinkedList {
private:
    CustomerNode* head;

public:
    CustomerLinkedList() : head(nullptr) {}

    void addCustomer(const std::string& name, int id) {
        CustomerNode* newNode = new CustomerNode(name, id);
        if (!head) {
            head = newNode;
        } else {
            CustomerNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeCustomer(int id) {
        if (!head) return;

        if (head->id == id) {
            CustomerNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        CustomerNode* current = head;
        while (current->next && current->next->id != id) {
            current = current->next;
        }

        if (current->next) {
            CustomerNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void displayCustomers() const {
        CustomerNode* current = head;
        while (current) {
            std::cout << "Customer ID: " << current->id << ", Name: " << current->name << '\n';
            current = current->next;
        }
    }
};



class InventoryNode {
public:
    std::string itemName;
    int id;
    InventoryNode* next;
    InventoryNode* prev;

    InventoryNode(std::string name, int itemId) 
        : itemName(name), id(itemId), next(nullptr), prev(nullptr) {}
};

class InventoryDoublyLinkedList {
private:
    InventoryNode* head;

public:
    InventoryDoublyLinkedList() : head(nullptr) {}

    void addItem(const std::string& name, int id) {
        InventoryNode* newNode = new InventoryNode(name, id);
        if (!head) {
            head = newNode;
        } else {
            InventoryNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void removeItem(int id) {
        InventoryNode* current = head;
        while (current) {
            if (current->id == id) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next; // Update head if needed
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void displayItems() const {
        InventoryNode* current = head;
        while (current) {
            std::cout << "Item ID: " << current->id << ", Item Name: " << current->itemName << '\n';
            current = current->next;
        }
    }
};



class TransactionNode {
public:
    std::string transactionDetails;
    int id;
    TransactionNode* next;

    TransactionNode(std::string details, int transactionId) 
        : transactionDetails(details), id(transactionId), next(nullptr) {}
};

class TransactionCircularLinkedList {
private:
    TransactionNode* head;

public:
    TransactionCircularLinkedList() : head(nullptr) {}

    void addTransaction(const std::string& details, int id) {
        TransactionNode* newNode = new TransactionNode(details, id);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            TransactionNode* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    void removeTransaction(int id) {
        if (!head) return;

        TransactionNode* current = head;
        TransactionNode* previous = nullptr;

        do {
            if (current->id == id) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    if (current->next == head) {
                        head = nullptr; // Only one node
                    } else {
                        TransactionNode* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        head = current->next;
                        last->next = head;
                    }
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }

    void displayTransactions() const {
        if (!head) return;

        TransactionNode* current = head;
        do {
            std::cout << "Transaction ID: " << current->id << ", Details: " << current->transactionDetails << '\n';
            current = current->next;
        } while (current != head);
    }
};


int main() {
    // Customer Records Management
    CustomerLinkedList customerList;
    customerList.addCustomer("Sbghatullah", 230896);
    customerList.addCustomer("ASIF", 2);
    std::cout << "Customer Records:\n";
    customerList.displayCustomers();
    
    customerList.removeCustomer(230896);
    std::cout << "\nAfter removing customer with ID 230896:\n";
    customerList.displayCustomers();

    // Inventory Tracking
    InventoryDoublyLinkedList inventoryList;
    inventoryList.addItem("Laptop", 101);
    inventoryList.addItem("Mouse", 102);
    std::cout << "\nInventory Items:\n";
    inventoryList.displayItems();

    inventoryList.removeItem(101);
    std::cout << "\nAfter deleting item with ID 101:\n";
    inventoryList.displayItems();
    
    // Transaction History Management
    TransactionCircularLinkedList transactionList;
    transactionList.addTransaction("Purchase of Laptop", 1001);
    transactionList.addTransaction("Purchase of Mouse", 1002);
    std::cout << "\nTransaction History:\n";
    transactionList.displayTransactions();

    transactionList.removeTransaction(1001);
    std::cout << "\nAfter deleting transaction with ID 1001:\n";
    transactionList.displayTransactions();

    return 0;
}
