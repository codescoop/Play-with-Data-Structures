/*
    TOPIC: Linked List - Insertion-I

    we can create linked list using:
    - Linked List Class   (Object Oriented Programming)
    - Function            (Procedural Programming)
      (functions to perform different operations in linked list)
      
    Insertion in linked  list can be done at:
    - head
    - middle
    - tail

    Why Dynamic Allocation not Static Allocation in Linked List ?
    - In static allocation, when the function call is over, all the variables that are created statically 
      are destroyed. 
      Thus, the Node which we create inside the function will also get destroyed, when the function call is over.
      Like: insertAtHead(head,3);
            insertAtHead(head,99);
            insertAtHead(head,10);
    - So, to create chain of Nodes, we use dynamic memory allocation.

*/

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Linked List Class (Object Oriented Programming)-----------------------------
/* 
class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        ...
    }

    void insert(int d)
    {
        ...
    }
    ...
    ...
};
*/

// Functions (Procedural Programming)-----------------------------------------

// pass by value 
// void insertAtHead(Node *headCopy, int d)

// pass a pointer by reference (because we want to make changes to the original head pointer)
void insertAtHead(Node *&head, int d)
{
    if(head == NULL)
    {
        head = new Node(d);
        return;
    }

    Node *n = new Node(d);
    n->next = head;
    head = n;
}



// pass by value (because we don't want to change the original head pointer)
void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // since we don't have linked list class, we have to keep the track of head pointer
    Node *head = NULL;        // to store address of the first node

    insertAtHead(head,3);
    insertAtHead(head,99);
    insertAtHead(head,10);

    cout << "Linked List: ";
    print(head);
    print(head);

    /* When using print() twice, Does data will be printed Twice or just Once ??
       - As, print() function is taking parameter as "call by value". So, it will print data twice
       But
       - if print() function should have using "call by reference", then it will print data only once.
         As, we have changed the original "head pointer" to NULL. 
     */

    return 0;
}


/* 
OUTPUT:

    Linked List: 10 -> 99 -> 3

    10 -> 99 -> 3

 */