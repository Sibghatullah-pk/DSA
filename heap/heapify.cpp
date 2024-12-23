#include <iostream>
#include <vector>
#include <string>

using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) // Insert function for max heap
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index]) // For max heap, parent must be greater than child
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteHeap() // Delete root and heapify
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        heapifyMax(i); // Max heapify from the root
    }

    void heapifyMax(int i) // Max-Heapify function
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;
        int largest = i;

        if (leftIndex <= size && arr[leftIndex] > arr[largest])
        {
            largest = leftIndex;
        }

        if (rightIndex <= size && arr[rightIndex] > arr[largest])
        {
            largest = rightIndex;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapifyMax(largest); // Recursively heapify the affected subtree
        }
    }

    void heapifyMin(int i) // Min-Heapify function
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;
        int smallest = i;

        if (leftIndex <= size && arr[leftIndex] < arr[smallest])
        {
            smallest = leftIndex;
        }

        if (rightIndex <= size && arr[rightIndex] < arr[smallest])
        {
            smallest = rightIndex;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapifyMin(smallest); // Recursively heapify the affected subtree
        }
    }
};

int main()
{
    heap h;

    // Inserting elements into max-heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Max Heap: ";
    h.print();

    h.deleteHeap(); // Deleting root and adjusting the heap
    cout << "After deletion (Max Heap): ";
    h.print();

    // You can also implement the Min-Heap by switching heapify functions
    h.insert(30);
    h.insert(20);
    h.insert(10);
    
    cout << "Min Heap: ";
    
    h.heapifyMin(1); // Calling heapifyMin for min heap construction
    h.print();

    return 0;
}
