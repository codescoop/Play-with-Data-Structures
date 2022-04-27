/*
    TOPIC: Circular Linked List - Deletion

    It is a Linked list in which last node points to the head of linked list.

    Eg:
                  ___       ___       ___       ___       ___             
        head---> |1|_| --> |2|_| --> |3|_| --> |4|_| --> |5|_| -- 
                  ^                                              |        
                  '----------------------------------------------'
                                                                          

    Some real life application of circular linked list:-
    - CPU algorithms
    - Used to implement Queue data structure 

*/



#include <iostream>
using namespace std;

// Linked List
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


// Insertion in Circular linked list
void insertAtHead(Node *&head, int d)
{
    // step 1 (creating a new node)
    Node *n = new Node(d);
    n->next = head;

    // step 2 (creating a loop)
    if(head == NULL)
    {
        n->next = n;               // creating a self loop
    }
    else
    {
        // traverse towards the end of linked list
        Node *temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;            // creating a self loop
    }

    // step 3 (making head points towards new node)
    head = n;
    return;
}

// function to search node 
Node* getNode(Node *head, int data)
{
    Node *temp = head;
    // for all nodes except the last node
    while(temp->next != head)
    {
        if(temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    // Once loop is over, Check for last node
    if(temp->data ==data)
    {
        return temp;
    }
    return NULL;
}


// Deletion in Circular linked list
void deleteNode(Node *&head, int data)
{
    Node* del = getNode(head,data);          // del: node for deletion
    if(del == NULL)
    {
        return;
    }
    // otherwise
    
    // for deletion of first node (set the head pointer)
    if(head == del)
    {
        head = head->next;
    }
    // for deletion of other nodes
    Node *temp = head;
    while(temp->next != del)         // loop stops one step behind the node to be deleted
    {
        temp = temp->next;
    }

    temp->next = del->next;
    delete del;
}



// Display circular linked list
void print(Node *head)
{
    Node *temp = head;
    while(temp->next != head)  // printing values till 2nd last node
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data;        // to print the last node value
    cout << endl;
}


// function to drive code
int main()
{
    Node *head = NULL;

    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    cout << "Circular Linked List: ";
    print(head);

    deleteNode(head,30);
    cout << "Circular Linked List [delete at data=30]: ";
    print(head);

    deleteNode(head,10);
    cout << "Circular Linked List [delete at data=10]: ";
    print(head);

    return 0;
}


/* 
OUTPUT:

    Circular Linked List                     : 10 -> 20 -> 30 -> 40
    Circular Linked List [delete at data=30] : 10 -> 20 -> 40
    Circular Linked List [delete at data=10] : 20 -> 40

*/