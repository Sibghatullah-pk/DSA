#include <iostream>

using namespace std;

class stack {
    int capacity;
    int *arr;
    int top;
public:
    stack(int c) : capacity(c), arr(new int[c]), top(-1) {}

    bool push(int data) {
        if (top == capacity - 1) {
            cout << "Overflow" << endl;
            return false;
        }
        arr[++top] = data;
        return true;
    }

    bool pop() {
        if (top == -1) {
            cout << "Underflow" << endl;
            return false;
        }
        --top;
        return true;
    }

    int gettop() {
        if (top == -1) {
            cout << "Underflow" << endl;
            return 0; // Or throw an exception
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }


};

int main() {
    stack st(4);

    st.push(22);
    st.push(2);
    cout << st.gettop() << endl;

    st.push(12);
    st.push(14);
     cout << st.gettop() << endl;
    st.push(144);
    st.push(143); // This will cause overflow
    cout << st.gettop() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop(); // This will cause underflow
}