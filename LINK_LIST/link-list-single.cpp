#include<iostream>
using namespace std;

class node
{
public:
int data;
node *ptr;

node*head=NULL;
void insertatstart(int x)
{
node *n=new node;
n->data=x;
n->ptr=head;
head=n;
}
 void insertAtEnd(int x) {
        node* newNode = new node;
        newNode->data=x;
        if (head == nullptr) {
            head = newNode;
            return;
        }

        node* temp2 = head;
        while(temp2!=NULL) {
            temp2 = temp2->ptr;
        }
        temp2->ptr = newNode; 
 }

void  display()
{
node *temp=head;
while(temp!=NULL)
{
cout<<temp->data;
temp=temp->ptr;
cout<<" -> ";
}

}
};

int main()
{
node n;

n.insertatstart(1);
n.insertatstart(6);
n.insertatstart(2);
n.insertatstart(9);
n.insertatstart(8);
n.insertatstart(3);
n.insertatstart(4);
n.insertatstart(7);
n.insertatstart(5);
n.insertatstart(7);





n.display();


n.insertAtEnd(2);
n.display();
n.display();
}