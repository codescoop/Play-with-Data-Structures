/* 
    TOPIC: Generic Programming with Templates

    Basics:
    - The major advantage of C++ Standard Template Library(STL) is "all the containers" & "all the algorithms"
      provided by STL is generic.

    - Generic means they can work with different data types. 
      Eg: if you want to sort array of intergers, you can use the sort function.
          if you want to sort array of books (objects), then also you can use the sort function.
          So, underline datatype doesn't matter.

    - The only thing that it will need is, How do you compare 2 book object ? 
      For this, you  have to define a comparison using a Comparator function (that will make the sort function
      work for a array of books)

    Generic Programming can be done a 2 levels:-
    1. Algorithm
    2. Container (data structures Eg: vector)
    
    Let's make a Generic Function! (at Algorithm Level)
    - the way to do is using Templates.
      
      Eg: template <class T>     Or 
          template <typename T>
*/


#include<iostream>
using namespace std;

// Linear Search
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


int main()
{
    int arr[] = {1,2,3,5,17,20};                        // array of interger
    int n = sizeof(arr)/sizeof(int);
    int key = 17;
    cout << "Index: " << search(arr, n, key) << "\n\n";

    float b[] = {1.1, 1.6 , 2.3, 2.5};                  // array of float
    n = sizeof(b)/sizeof(int);
    float fkey = 1.6;
    cout << "Index: " << search(b, n, fkey) << "\n\n";

    char c[] = {'a', 'd' , 'e', '\0'};                   // array of char
    n = sizeof(c)/sizeof(int);
    char ckey = 'e';
    cout << "Index: " << search(c, n, ckey) << endl;


    // search(book, ....)                                // array of Objects

    return 0;
}


/* 
OUTPUT:

    Index: 4

    Index: 1

    Index: 0
 */