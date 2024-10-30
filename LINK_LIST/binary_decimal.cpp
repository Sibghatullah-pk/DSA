// // #include <iostream>
// // #include<cmath>
// // using namespace std;
// // class con
// // {

// // int convert (int a){
// //  int dec =0,i=0,rem;
// //   while(a!=0)
// //   {
// //     rem= a%10;
// //     a=a/10;
// //     dec+=rem*pow(2,i);
// //     i++;
// //   }
// //   return dec;
// // }
// // };

// // int main()
// // {

// // }

// #include <iostream>
// #include<cmath>
// class Stack {
// private:
//     int top;
//     int* data;
//     int capacity;
// public:
//     Stack(int capacity ) {
//         top = -1;
//         data = new int[capacity];
//         this->capacity = capacity;
//     }

//     void push(int element) {
//         if (isFull()) {
//             std::cerr << "Stack Overflow" << std::endl;
//             return;
//         }
//         top++;
//         data[top] = element;
//     }

//     int pop() {
//         if (isEmpty()) {
//             std::cerr << "Stack Underflow" << std::endl;
//             return -1; // Or throw an exception
//         }
//         int poppedElement = data[top];
//         top--;
//         return poppedElement;
//     }

//     bool isEmpty() {
//         return top == -1;
//     }

//     bool isFull() {
//         return top == capacity - 1;
//     }

//  int convert(int a) {
//     int binary = 0, base = 1;

//     while (a != 0) {
//         int remainder = a % 2;
//         binary += remainder * base;
//         base *= 10;
//         a /= 2;
//     }

//     return binary;
// }
// };

// int main() {
//     Stack myStack(10);
//     int value,converted;
//     // for (int i = 0; i < 11; i++)
//     // {
//         /* code */
//          std::cout<<"enter value";
//     std::cin>>value;
//     converted=myStack.convert(value);
//     myStack.push(converted);
//     // }

//     // myStack.push(20);
//     // myStack.push(30);
//  for (int i = 0; i < 11; i++)
//     {
//     std::cout << myStack.pop() << std::endl;
//     }
//     // std::cout << myStack.pop() << std::endl;

//         //   if (myStack.isEmpty()) {
//         //     return -1; // Or throw an exception
//         // }

//     return 0;
// }


#include <iostream>
#include <cmath>

    class Stack
{
private:
    int top;
    int *data;
    int capacity;

public:
    Stack(int capacity)
    {
        top = -1;
        data = new int[capacity];
        this->capacity = capacity;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(int element)
    {
        if (isFull())
        {
            std::cerr << "Stack Overflow" << std::endl;
            return;
        }
        top++;
        data[top] = element;
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cerr << "Stack Underflow" << std::endl;
            return -1; // Or throw an exception
        }
        int poppedElement = data[top];
        top--;
        return poppedElement;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void convertAndPush(int a)
    {
        while (a != 0)
        {
            int remainder = a % 2;
            push(remainder);
            a /= 2;
        }
    }
};

int main()
{
    Stack myStack(10);
    int value;

    std::cout << "Enter value: ";
    std::cin >> value;

    myStack.convertAndPush(value);

    // Print the converted value from the stack (reversed order)
    while (!myStack.isEmpty())
    {
        std::cout << myStack.pop();
    }

    return 0;
}
