/* 
    Program to find sum of number from 1 to N.

    What we will learned ? 
    - While loop

*/

#include <iostream>
using namespace std;

int main(){
    int num, sum=0;

    cout<<"Enter the number: ";
    cin>>num;

    while (num > 0){        // Stopping Criteria
        sum = sum + num;
        num --;             // Update Statement
    }
    
    cout<<"Sum of numbers = "<<sum<<endl;
    return 0;
}

/* 
    What we learned ? 
    - While loop
*/