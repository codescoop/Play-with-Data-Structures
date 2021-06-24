/*
    Program to check if Number is divisible by 2, divisible by 3 and both

    Concept we will learn: 
    - if, else if, else
*/

#include <iostream>
using namespace std;

int main(){
    int num; 

    cout<<"Enter the Number :";
    cin>>num;

    if(num%2 == 0 and num%3 ==0){
        cout<<"Number divisible by both 2 & 3"<<endl;
    }else if(num%2 == 0){
        cout<<"Number divisible by 2"<<endl;
    }else{
        cout<<"Number divisible by 3"<<endl;
    }

    return 0;
}