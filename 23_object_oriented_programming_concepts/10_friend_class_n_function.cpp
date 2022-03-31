/*
    TOPIC - Friend class and function in C++

   Friend Class:
   - A friend class can access private and protected members of other class in which it is declared as friend. 
   - It is sometimes useful to allow a particular class to access private members of other class.
   - For example: A LinkedList class may be allowed to access private members of Node.
       class Node
       {
       private:
           int key;
           Node *next;
           
           // Other members of Node Class
           friend class LinkedList;           // Now class LinkedList can access private members of Node
       };

   Friend Function:
   - Like friend class, a friend function can be given special grant to access private and protected members. 
   - A friend function can be:
      a) A method of another class
      b) A global function
   - For example:
       class Node
       {
       private:
           int key;
           Node *next;
    
           // Other members of Node Class
           friend int LinkedList::search();    // Only search() of linked List can access internal members
       };
*/
