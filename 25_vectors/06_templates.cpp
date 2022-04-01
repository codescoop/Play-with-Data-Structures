/* 
    TOPIC: Templates

    Converting a class into a Templated class

    Note: first view "vector2.h" file

*/


// Using user defined vector class

#include<iostream>                  // using <> for standard header files
#include "vector2.h"                 // using "" for user defined files
// #include "../25_vectors/vector2.h"
using namespace std;

int main()
{
    // Vector2<int> v;       // vector of int
    Vector2<char> v;      // vector of char

    v.push_back(71);
    v.push_back(72);
    v.push_back(73);
    v.push_back(74);
    v.pop_back();
    v.push_back(75);
    
    cout << "v.capacity: " << v.capacity() << endl;
    v.push_back(20);
    cout << "v.capacity: " << v.capacity() << endl;

    cout << "Vector v: ";
    for(int i=0; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "v.size: " << v.size() << endl;

    return 0;
}

/* 
OUTPUT: [when, using vector of int]

    v.capacity: 4
    v.capacity: 8

    Vector v: 11 12 13 15 20 
    v.size: 5


OUTPUT: [when, using vector of char]
    
    v.capacity: 4
    v.capacity: 8

    Vector v: G H I K  
    v.size: 5
*/