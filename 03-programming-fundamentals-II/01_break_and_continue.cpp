/*
    Problem Statement - Read & print a stream of number  until we get a multiple of 3 and
                        skip all numbers which are multiple of 2 and 3 

    Concept we will learn: 
    - break:    It leaves a loop completely and executes the statements after the loop.
    - continue: It skip the rest of loop and execute the next iteration.
*/

#include <iostream>
using namespace std;

int main(){
    int num;

    while(true){
        // No Stopping Condition as of now
        cout<<"Enter number: ";
        cin>>num;

        if(num%2 == 0){
            continue; // stops processing further & take you out to line 16 (i.e staring of loop)
        }
        if(num%3 == 0){
            break; // stops processing further & take you out to line 30 
        }
        cout<<"No: "<<num<<endl;
    }

    cout<<"Came out of loop!!"<<endl;
    return 0;
}