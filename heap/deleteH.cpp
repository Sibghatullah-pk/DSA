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
        arr[0] = -1; // Dummy node for 1-based indexing
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Bubble up to maintain max heap property
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
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

    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Replace root with the last element
        arr[1] = arr[size];
        size--;

        // Bubble down to maintain max heap property
        int i = 1;
        while (i <= size)
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
                i = largest;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap after insertion: ";
    h.print();

    h.deleteHeap();
    cout << "Heap after deletion: ";
    h.print();

    return 0;
}
