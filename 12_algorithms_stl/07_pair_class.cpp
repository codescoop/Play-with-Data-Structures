/* 
    Topic: Pair Class
    
    - A pair is a container which stores two values mapped to each other.
    - Pair is used to combine together two values which may be different in type. 
      Pair provides a way to store two heterogeneous objects as a single unit.
    - The first element is referenced as ‘first’ and the second element as ‘second’ 
      and the order is fixed (first, second).
    - To access the elements, we use variable name followed by dot operator 
      followed by the keyword first or second.

    Syntax: pair (data_type1, data_type2) Pair_name
*/

#include<iostream>
#include<vector>
using namespace std;

void print_array(int arr[], int size){
    for(int idx=0; idx<=size-1; ++idx){
        cout << arr[idx] << " ";
    }
    cout << endl;
}


int main()
{
    // create pair
    pair<int,char> p;           // declaring a pair object
    
    p.first = 121;              // update first value
    p.second = 'B';             // update second value

    
    // another way to create pair
    pair<int,char> p2(p);        // using existing pair to Initilize another pair
    
    cout << "p2.first: " << p2.first << endl;         // print first value
    cout << "p2.second: " << p2.second << "\n\n";     // print second value


    // pair default value
    pair<int,char> p5;                  // declaration

    cout << "p5.first: " << p5.first << endl;
    cout << "p5.second: " << p5.second << "\n\n";


    // create pair using make-pair() function
    pair<int,string> p3 = make_pair(232, "Audi");

    cout << "p3.first: " << p3.first << endl;
    cout << "p3.second: " << p3.second << "\n\n";


    // user input & make-pair()
    int num1, num2;
    cout << "Enter Two Numbers: ";
    cin >> num1 >> num2;

    pair<int,int> p4 = make_pair(num1, num2);

    cout << "p4.first: " << p4.first << endl;
    cout << "p4.second: " << p4.second << "\n\n";


    // Array of pairs
    pair<int,char> arr[3];              // declaration

    for(int idx=0; idx<3; idx++){
        // assign values
        arr[idx].first = idx+60;        // initilizing 1st element of pair
        arr[idx].second = 'a'+ idx;     // initilizing 2nd element of pair
        
        // print array
        cout << "arr[" << idx << "]: ";
        cout <<arr[idx].first << " " << arr[idx].second << endl;
    }


    // vector of pair
    vector< pair<int,string> > v1{{589,"Audi"}, {679,"Tesla"}};

    for(int idx=0; idx<v1.size(); idx++){
        cout << "\nv1[" << idx << "]: ";
        cout <<v1[idx].first << " " << v1[idx].second;
    }


    // pair of pair
    pair<int,pair<string,string>> car;      // declaration

    car.first = 101;                        // initilizing
    car.second.first = "Audi Q4";
    car.second.second = "Booked";

    cout << "\n\ncar.first: " << car.first << endl;
    cout << "car.second.first: " << car.second.first << endl;
    cout << "car.second.second: " << car.second.second << endl;

    /* NOTE: If you have complex data to store. It's better to create your own class */

    return 0;
}

/* 
OUTPUT: 
    p2.first: 121
    p2.second: B

    p5.first: 0
    p5.second: 

    p3.first: 232
    p3.second: Audi

    Enter Two Numbers: 785 101
    p4.first: 785
    p4.second: 101

    arr[0]: 60 a
    arr[1]: 61 b
    arr[2]: 62 c

    v1[0]: 589 Audi
    v1[1]: 679 Tesla

    car.first: 101
    car.second.first: Audi Q4
    car.second.second: Booked
*/