/*
    Write a program to calculate simple interest.
    Formula: si = (principle*rate*time)/100   

    What we will learn ? 
    - Type Casting -> Implicit
      Eg:-  integer/integer = integer
            float/integer = float
            integer/float = float 

*/

#include <iostream>
using namespace std;

int main(){

    // Declare a variable
    int principle, rate, time;
    float si;

    cout<<"Enter Principle, Rate & Time : ";

    // Taking input from console & assigning value to a buckets (storage in memory)
    cin>>principle>>rate>>time; // 
    
    si = (principle*rate*time)/100.0;
    
    cout<<"Simple Interset = "<<si<<endl;
}