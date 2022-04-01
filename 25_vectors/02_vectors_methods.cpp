/* 
    TOPIC: Vectors - Methods

*/


#include<iostream>
#include<vector>
using namespace std;


int main()
{
    // create & initalise a vector
    vector<int> d{1,2,3,10,14};

    // Push Back | O(1) for most of the time. But takes longer when expanding the size.
    d.push_back(16);              // push_back(inp): Adds an element to the ends of vector
    d.push_back(20);

    // Push Back |  O(1)
    d.pop_back();                 // pop_back(): Removes the last element

    // Insert some elemenst in the middle | O(N) where N = elements_added + element_shifted
    d.insert(d.begin()+3, 98);      //insert(iterator, value)
    d.insert(d.begin()+4, 4, 55);   //insert(iterator,no_of_elements, value)

    // erase element from the middle
    d.erase(d.begin()+2);
    d.erase(d.begin()+2, d.begin()+5);  //erase the range

    cout << "d.size(): " << d.size() << endl;
    cout << "d.capacity(): " << d.capacity() << endl;

    // display 
    cout << "vector d: ";
    for(int x:d)
    {
        cout << x << " ";
    }
    cout << endl;

    // we avoid the shrink
    d.resize(18);       // resize(size): if size is changing then more memory will be allocated
    cout << "d.capacity(): " << d.capacity() << endl;

    // remove all elements of the vectors, it doesn't delete the memory occupied by the array
    d.clear();  

    // empty(): Its check if vector is empty or not.
    if(d.empty())
    {
      cout << "This is an empty vector." << endl;
    }

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    //front(): return the front most element of vector
    cout << "d.front(): " << d.front() << endl;

    //back(): return the last most element of vector
    cout << "d.back(): " << d.back() << endl;

    // display 
    cout << "vector d: ";
    for(int x:d)
    {
        cout << x << " ";
    }
    cout << endl;


    // Reserve(size): This method doesn't change the capacity until we reach size, then it doubles.
    vector<int> v;
    int n;
    cout << "Enter vector size: ";
    cin >> n;
    
    // To avoid doubling, we will use reserve function()
    v.reserve(1000);

    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
      int no;
      cin >> no;
      v.push_back(no);
      cout << "v.capacity(): " << v.capacity() << endl;
    }

    cout << "vector v: ";
    for(int x:v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


/* 
OUTPUT:

    d.size(): 7
    d.capacity(): 14
    vector d: 1 2 55 55 10 14 16 
    d.capacity(): 18

    This is an empty vector.

    d.front(): 10
    d.back(): 12
    vector d: 10 11 12 

    Enter vector size: 5
    Enter elements: 10 20 30 40 50
    v.capacity(): 1000
    v.capacity(): 1000
    v.capacity(): 1000
    v.capacity(): 1000
    v.capacity(): 1000
    
    vector v: 10 20 30 40 50 

*/