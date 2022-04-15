/*
    TOPIC: Linked List - Taking Input

    - Taking input from user
    - Taking input from file
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



// function to delete data at start of linked list
void deleteAtHead(Node*&head)
{
    if(head == NULL)
    {
        return;
    }
    Node*temp = head->next;   // temp pointer is static. So it will be deleted at the end of function call 
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



int main()
{
    // since we don't have linked list class, we have to keep the track of head pointer
    Node *head = NULL;        // to store address of the first node

    /*     
    insertAtHead(head,3);
    insertAtHead(head,9);
    insertAtHead(head,74);
    insertAtMiddle(head,44,3);
    insertAtTail(head,88);
    */

    // take input of linked list from user
    cout << "Enter Elements [Press -1 to Exit]: ";
    head = take_input_2();

    // // take input from file "input.txt"
    // head = take_input_file();

    cout << "Linked List: ";
    print(head);

    return 0;
}


/* 
OUTPUT:

Case 1: [Input from USER]
    Enter Elements [Press -1 to Exit] : 6 5 10 9 7 3 -1
    Linked List                       : 3 -> 7 -> 9 -> 10 -> 5 -> 6

Case 2: [Input from FILE]  (i.e In Terminal: program_file.cpp < input.txt)
    Linked List                       : -1 -> 7 -> 19 -> 3 -> 10 -> 9 -> 5 -> 4

*/