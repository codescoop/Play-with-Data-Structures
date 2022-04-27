/*
    TOPIC: Doubly Linked List - Introduction

    Each node in a linked list instead of storing a single pointer to the next node, stores two pointers.
    - one pointer points to the next node &
    - one pointer points to the previous node.
                       __________           
                      | |      | | --> next 
                      | | data | |          
             prev <-- |_|______|_|          
                                            
    Eg:
       
       head--     _______       _______  next _______       _______       _______             
            '--> | |   | | --> | |   | | --> | |   | | --> | |   | | --> | |   | | -->  NULL  
                 | | 1 | |     | | 3 | |     | | 6 | |     | | 7 | |     | | 8 | |            
       NULL <--- |_|___|_| <-- |_|___|_| <-- |_|___|_| <-- |_|___|_| <-- |_|___|_|            
                                                       prev                                   


    Advantages 
    - Traverse the linked list in both forward & backward directions

    Disadvantages
    - Needs extra space (4 bytes + 4 bytes)


                            C++ STL (Standard Template Library)
                      ____________________|____________________
                     |                                         |
               Forward List                                   List
           (Singly Linked List)                        (Doubly Linked List)


    Task:
    - Insertion
    - Deletion
    - User Input (Insertion)
    - Searching

*/



#include <iostream>
using namespace std;

// Doubly Linked List
class Node{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};


// Insertion at head in Doubly Linked List (pass a pointer by reference)
void insertAtHead(Node *&head, int d)
{
    if(head == NULL)
    {
        head = new Node(d);
        return;
    }

    Node *n = new Node(d);
    n->next = head;
    head->prev = n;
    head = n;
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
    Node *n = new Node(data);
    tail->next = n;
    n->prev = tail;
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
    // take pos-1 jumps
    int i=1;
    Node *temp = head;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    // create a new node
    Node *n = new Node(data);
    n->next = temp->next;
    n->prev = temp;
    temp->next = n;
    n->next->prev = n;
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



void deleteAtHead(Node*&head)
{
    if(head == NULL)
    {
        return;
    }
    Node*temp = head->next;   // temp pointer is static. So it will be deleted at the end of function call 
    temp->prev = NULL;
    delete head;              // delete the Node whose address is stored in "head" pointer
    head = temp;
}



// function to delete data at end of linked list
void deleteAtTail(Node*&head)
{
    if(head == NULL)
    {
        return;
    }
    Node *tail = head;
    Node *prev;
    // moving towards the end of linked list
    while(tail->next != NULL)
    {
        prev = tail;
        tail = tail->next;
    }
    delete tail;                  // delete the Node whose address is stored in "tail" pointer
    // delete prev->next;         // prev->nex & tail are pointing towards same address
    prev->next = NULL;
}



// function to delete data at end of linked list
void deleteAtMiddle(Node*&head, int pos)
{
    if(head==NULL)
    {
        return;
    }
    else if(pos >= length(head))
    {
        return;
    }
    // jump towards pos
    Node *temp = head;
    Node *prev;
    int i = 1;
    while(i <= pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;              // delete the Node whose address is stored in "temp" pointer
}


// Search Operation
// Linear Search
bool search(Node*head, int key)
{
    Node*temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    // if key not found
    return false;
}


// Linear Search (recursively)
bool searchRecursive(Node*head, int key)
{
    //base case
    if(head == NULL)
    { 
        return false;
    }
    //rec case
    if(head->data == key)
    {
        return true;
    }
    return searchRecursive(head->next, key);
}


// Linked List User Input
void take_input(Node*&head)
{
    //
}

// Linked List User Input
Node* take_input_2()
{
    Node *head = NULL;

    int data;
    cin >> data;

    while(data != -1)
    {
        insertAtHead(head, data);
        // insertAtTail(head, data);
        cin >> data;
    }
    return head;
    /* NOTE: Since we are adding elements at "head" of linked list.
             So, we will be getting linked list in the reverse order.
    */
}


// Linked List User Input [When taking Input from a file]
Node* take_input_file()
{
    Node *head = NULL;

    int data;
    // cin >> data;

    while(cin >> data)
    // while(data != -1)
    {
        insertAtHead(head, data);
        // cin >> data;
    }
    return head;
    /* NOTE: Since we are adding elements at "head" of linked list.
             So, we will be getting linked list in the reverse order.
    */
}


/* 
    - Using "<<" for getting output
      Eg: cout << head;   
          This will print the address of head.
          But we want to print entire linked list uing "cout". 
          So, we will use operator overloading.
      
      NOTE:    cout << head;
               |         |
            ostream    Node
             object    object

         So, "<<" operator will take 2 parameter.
              One is Ostream object (for "cout")
              Second is Node object (for "head")
*/


// // Opertor Overloading (i.e for cases like: cout << head;)
// void operator<<(ostream &os, Node *head)
// {
//     print(head);
//     return;
// }


// Cascading of Operators (i.e for cases like: cout << head << head2;)
ostream& operator<<(ostream &os, Node *head)   // Both Return & Pass are by Reference
{
    print(head);
    return os;     // returning "cout" by reference

    /* 
        => cout << head << head2;
          |-----------|
           return cout

        =>        cout << head2;
                  |------------|
                    return cout

        =>               cout;  [OUTPUT]
        
        NOTE: We will get "cout; as output.
              "cout;" is a valid statement in C++ & writing it doesnot do anything.
    */
}


// Cascading of Operators (i.e for cases like: cin >> head >> head2;)
istream& operator>>(istream &is, Node *&head)
{
    head = take_input_2();
    return is;
}



int main()
{
    Node *head = NULL;

    // Insertion in Doubly Linked List
    cout << "Doubly Linked List [Insert at head]: ";
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    cout << "Doubly Linked List [Insert at tail]: ";
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    print(head);

    cout << "Doubly Linked List [Insert at kth pos]: ";
    insertAtMiddle(head, 9, 3);
    // print(head);
    cout << head; 

    // User Input in Doubly Linked List
    cout << "Enter DLL Elements [Press -1 to exit]: ";
    Node *head2 = take_input_2();
    cout << "Double Linked list [By user input]: " << head2;


    // Deletion in Doubly Linked List
    deleteAtHead(head2);
    cout << "Double Linked list [After Deletion at head]: " << head2;
    
    deleteAtTail(head2);
    cout << "Double Linked list [After Deletion at Tail]: " << head2;

    deleteAtMiddle(head2, 2);
    cout << "Double Linked list [After Deletion at 2nd pos]: " << head2;


    // Search in Doubly Linked List
    int key;
    cout << "Enter Search key: ";
    cin >> key;

    if(search(head2,key))
    {
        cout << "Element Found." << endl;
    }
    else
    {
        cout << "Element Not Found." << endl;;
    }

    return 0;
}


/* 
OUTPUT:

Case1:
    Doubly Linked List [Insert at head]    : 1 -> 2 -> 3
    Doubly Linked List [Insert at tail]    : 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Doubly Linked List [Insert at kth pos] : 1 -> 2 -> 3 -> 9 -> 4 -> 5 -> 6

    Enter DLL Elements [Press -1 to exit] : 16 15 14 13 12 11 -1
    Double Linked list [By user input]    : 11 -> 12 -> 13 -> 14 -> 15 -> 16 

    Double Linked list [After Deletion at head]    : 12 -> 13 -> 14 -> 15 -> 16
    Double Linked list [After Deletion at Tail]    : 12 -> 13 -> 14 -> 15
    Double Linked list [After Deletion at 2nd pos] : 12 -> 13 -> 15 

    Enter Search key: 13
    Element Found.

Case2:
    Doubly Linked List [Insert at head]    : 1 -> 2 -> 3
    Doubly Linked List [Insert at tail]    : 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Doubly Linked List [Insert at kth pos] : 1 -> 2 -> 3 -> 9 -> 4 -> 5 -> 6

    Enter DLL Elements [Press -1 to exit] : 16 15 14 13 12 11 -1
    Double Linked list [By user input]    : 11 -> 12 -> 13 -> 14 -> 15 -> 16 

    Double Linked list [After Deletion at head]    : 12 -> 13 -> 14 -> 15 -> 16
    Double Linked list [After Deletion at Tail]    : 12 -> 13 -> 14 -> 15
    Double Linked list [After Deletion at 2nd pos] : 12 -> 13 -> 15 

    Enter Search key: 20
    Element Not Found.

*/