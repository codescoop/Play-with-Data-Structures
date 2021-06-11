/* 
    Program to find sum of digits of number.

    What we will learned ? 
    - Modulos (%) -> Remainder
*/

#include <iostream>
using namespace std;

int main(){
    int num, sum=0;

    cout<<"Enter the number: ";
    cin>>num;

    while(num > 0){
        sum = sum + (num%10);
        num = num/10;
    }

    cout<<"Sum of digits = "<<sum<<endl;

    return 0;
}