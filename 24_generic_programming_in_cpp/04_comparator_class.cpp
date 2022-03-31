/* 
    TOPIC: Comparator Class

    What we have learned till now:
    - If we want to make generic funtion we should use "templates".
      (because with the help of templates we get freedom from data types.)
    - we can also use "templates + Iterators" as with the help of iterators we get freedom from data structure.)

    Comparator
    - Comparators gives us freedom from different types of operations, operating on the data.
      Eg: If b1 & b2 are 2 books (i.e object). 
          Then,
          if b1 < b2, then we can define our own comparison. 
          OR
          if b1 == b2, then we can define our own comparison. 
          ... ...

    Now, with the help of "comparator" we can make our code more generic. 

*/


#include<iostream>
#include<list>
#include<vector>
using namespace std;

// [Templates] Linear Search
template<typename T>
int search(T arr[], int n, T key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    // return n, if element not found
    return n;
}

/* 
Steps:
- define search function with return type "ForwardIterator"
- this search function will accept 3 things: starting point & ending point of that conatiner & the element
  we want to search.
- we have to make it as a Template function<class A, classB> with 2 class: [One for container & Second for datatype]
- Now, write logic for the function.
 */

// [Templates + Iterators] Linear Search 
template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key)
{
    while(start != end)
    {
        if(*start == key)
        {
            return start;
        }
        start++;
    }
    // return end, if element not found
    return end;
}


// [Templates + Iterators + Comparators] Linear Search 
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while(start != end)
    {
        if(cmp(*start,key))
        {
            return start;
        }
        start++;
    }
    // return end, if element not found
    return end;
}

class Book
{
    public:
        string name;
        int price;

    Book()
    {
        //
    }

    Book(string name,int price)
    {
        this->name = name;
        this->price = price;
    }
};

// Comparator Class
class BookCompare
{
    public:
        bool operator()(Book A, Book B)                 // overloaded () operator
        {                        
            if(A.name == B.name)
            {
                return true; 
            }
            return false;
        }
};


int main()
{
    /* 
    int arr[] = {1,2,3,5,17,20};                        // array of interger
    int n = sizeof(arr)/sizeof(int);
    int key = 17;
    cout << "Index: " << search(arr, n, key) << "\n\n"; 
    */

    Book b1("C++", 100);          // old book edition
    Book b2("Python", 120);
    Book b3("Java", 130);
    Book b4(b1);


    vector<Book> l;
    // list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    // Search key (of datatype Book object)
    Book key("C++", 110);        // new book edition

    BookCompare cmp;           // "cmp" is an object of "BookCompare" class
    /* 
    if(cmp(b1,key))
    {
        cout << "True: same books!";
    } 
    */

    auto it = search(l.begin(), l.end(), key, cmp);
    // list<Book>::iterator  it = search(l.begin(), l.end(), key, cmp);
    // vector<Book>::iterator  it = search(l.begin(), l.end(), key, cmp);

    if(it == l.end())
    {
        cout << "Book Not Found" << endl;
    }
    else{
        cout << "Book found in the library" << endl;
    }

    return 0;
}


/* 
OUTPUT:

when key = ("C++", 110)
OUTPUT: Book found in the library

when key = ("C", 110)
OUTPUT: Book NOT found

*/