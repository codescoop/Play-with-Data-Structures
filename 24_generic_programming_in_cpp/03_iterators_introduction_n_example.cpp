/* 
    TOPIC: Iterators - Introduction & Example

    Iterators:
    - Iterators is an entity that helps us to access the data within a conatiner with certain restictions.
       1. Input Iterators:
       2. Output Iterators:
       3. Forward Iterators:
       4. Bidirectional Iterators:
       5. Random Access Iterators:

    Input Iterators:
    - A entity through which you can read data from conatiner and move ahead.
      For Example - A Keyboard

    Output Iterators:
    - A entity through which you can write into the conatiner and move ahead.
      For Example - Printer

    Forward Iterators:
    - Iterator with functionalities of input and output iterator in single direction.
      For Example - Single Linked List

    Bidirectional Iterators:
    - Forward Iterator that can move in both directions.
      For Example - Double Linked List

    Random Access Iterators:
    - Random Access Iterators is an Iterator that can read/write in both directions and also can take jumps.
      For Example - Array, Vector,...  (but, not a Linked List)



    Why Learn Iterators ?
    - Because we want to make generic algorithm with freedom from underlying data structure(i.e container)

    Example: 
    - We made "search() function" to work on all "data-types" using Templates
    - Now, we can make "search() function" to work on all types of "containers" using Iterators
*/


#include<iostream>
#include<list>
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


int main()
{
    /* 
    int arr[] = {1,2,3,5,17,20};                        // array of interger
    int n = sizeof(arr)/sizeof(int);
    int key = 17;
    cout << "Index: " << search(arr, n, key) << "\n\n"; 
    */

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(4);

    int key = 4;

    auto it = search(l.begin(), l.end(), key);

    if(it == l.end())
    {
        cout << "Element Not Found" << endl;
    }
    else{
        cout << *it << ": Element Found" << endl;
    }

    return 0;
}


/* 

When Key:7
OUTPUT: Element Not Found

When Key:4
OUTPUT: 4:Element Found

*/