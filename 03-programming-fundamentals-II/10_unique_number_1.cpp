/*
    Problem - Unique Number
    Given a list of numbers where every number occurs twice except one, find that unique number

    Input: 3,2,3,5,6,5,2
    Output: 6
*/

#include <iostream>
using namespace std;

int main(){
    int total_num, num, ans=0;

    cout<<"Enter total numbers: ";
    cin>>total_num;
    cout<<"Enter you numbers: ";

    for(int step=0; step<total_num; step++){
        cin>>num;
        ans = ans^num;     //Bitwise XOR Operator to solve, It helped to not use any storage
    }
    
    cout<<"Unique No. is : "<<ans<<endl;

    return 0;
}