/*
    TOPIC: Linked List - Insertion-II
           [Insertion at Middle & Tail]

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



// function to find length of linked list
int length(Node*head)
{
    int cnt = 0;
    while(head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}



// function to insert data at last position of linked list
void insertAtTail(Node*&head, int data)
{
    // corner case
    if(head == NULL)
    {
        // Node *n =  new Node(data);
        // head = n;
        head = new Node(data);
        return;
    }
    Node *tail = head;             // using temp pointer
    // Moving head towards tail
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    // create & attach new node
    tail->next = new Node(data);
}



// function to insert data at middle of linked list
void insertAtMiddle(Node*&head, int data, int pos)
{
    //corner case
    if(head==NULL or pos==0)
    {
        insertAtHead(head, data);
        return;
    }
    else if (pos >= length(head))
    {
        insertAtTail(head, data);
        return;
    }
    Node *temp = head;       // temp pointer is static. So, it will be deleted at the end of function call
    // take pos-1 jumps
    int i=1;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    // create a new node
    Node *n = new Node(data);
    n->next = temp->next;
    temp->next = n;
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

    // insert at head of linked list
    insertAtHead(head,3);
    insertAtHead(head,19);
    insertAtHead(head,10);
    cout << "Linked List [Insert at Head]  : ";
    print(head);

    // insert at middle postion of linked list
    insertAtMiddle(head,99,1);
    cout << "Linked List [Insert at Pos=1] : ";
    print(head);

    insertAtMiddle(head,44,3);
    cout << "Linked List [Insert at Pos=3] : ";
    print(head);

    // insert at tail of linked list
    insertAtTail(head,88);
    cout << "Linked List [Insert at Tail]  : ";
    print(head);

    return 0;
}


/* 
OUTPUT:

    Linked List [Insert at Head]  : 10 -> 19 -> 3

    Linked List [Insert at Pos=1] : 10 -> 99 -> 19 -> 3
    Linked List [Insert at Pos=3] : 10 -> 99 -> 19 -> 44 -> 3

    Linked List [Insert at Tail]  : 10 -> 99 -> 19 -> 44 -> 3 -> 88

 */