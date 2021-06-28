/*
    Problem Statement - Check is given number is prime.
*/

#include <iostream>
using namespace std;

int main(){
    int num, checker;
    cout<<"Enter the number: ";
    cin>>num;

    for(checker=2;checker<num;checker++){
        if(num%checker == 0){
            cout<<"Not Prime"<<endl;
            break;
        }
    }
    // Remember this check is important
    if(checker==num){
        cout<<"Number is Prime"<<endl;
    }
    return 0;
}
