/*
    Program to print below Fahrenheit to Celsius table:
    F     C
    0    -17
    20   -6
    40    4
    60    15
    80    26
    100   37
    120   48  
    140   60
    160   71
    180   82
    200   93
    
    Formula: celsius = 5(fahrenheit - 32)
                       9
*/

#include <iostream>
using namespace std;

int main(){
    int fahren_value = 0, celsius_value;
    
    while(fahren_value <= 200){
        celsius_value = (5*(fahren_value - 32))/9;   
        // Catch:  don't do 5/9(fahren_value - 32)
        cout<<fahren_value<<"  "<<celsius_value<<endl;
        fahren_value = fahren_value + 20;
    }
    return 0;
}