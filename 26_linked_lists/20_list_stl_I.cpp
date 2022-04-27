/*
    TOPIC: List STL - I

    List => Doubly Linked List
    Useful in insert & delete from front, middle & tail.
    (as it takes O(1) time in front & tail insertion)

    Unlike in vector, If we want to insert some element in the front & middle, we first have to shift 
    all the elements.

    Some useful Methods in List stl:-
    - push_back   :  insert at tail
    - push_front  :  insert at head
    - pop_back    :  remove at tail
    - pop_front   :  remove from front
    - insert      :  insert in the middle
    - erase(idx)  :  erase some of the elements
    - remove(val) :  remove all occurance of some value
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    // Init
    list<int> l1{1,2,3,10,8,5};
    list<string> l2{"apple","guava","mango","banana"};
    l2.push_back("pineapple");

    // Iterate over list and print the data
    for(auto s:l2)
    // for(string s:l2)
    {
        cout << s << "-->"; 
    }
    cout << endl;

    // sort
    l2.sort();                      // lexographic sorting of strings

    // reverse
    l2.reverse();

    // pop_front
    cout << l2.front() << endl;     // display front element
    l2.pop_front();

    // print the data
    for(auto s:l2)
    {
        cout << s << "-->"; 
    }
    cout << endl;

    // add to the front of the list
    l2.push_front("kiwi");

    cout << l2.back() << endl;     // display last element
    l2.pop_back();

    // print the data
    for(auto s:l2)
    {
        cout << s << "-->"; 
    }
    cout << endl;

    // Iterate over list using iterators
    for(auto it = l2.begin(); it != l2.end(); it++)
    {
        cout << (*it) << "-->"; 
    }
    cout << endl;

    return 0;
}

/* 
OUTPUT:

    apple-->guava-->mango-->banana-->pineapple

    pineapple
    mango-->guava-->banana-->apple

    apple
    kiwi-->mango-->guava-->banana

    kiwi-->mango-->guava-->banana
*/