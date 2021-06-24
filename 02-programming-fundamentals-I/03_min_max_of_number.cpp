/*
    Find the minimum and maximum of N Numbers
*/

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int total_num, num, min_so_far, max_so_far;

    cout<<"Enter total numbers : ";
    cin>>total_num;

    max_so_far = INT_MIN;
    min_so_far = INT_MAX;

    while(total_num > 0){
        cin>>num;
        if(num < min_so_far){
            min_so_far = num;
        }
        if(num > max_so_far){
            max_so_far = num;
        }
        total_num--;
    }

    cout<<"Minimum Number: "<<min_so_far<<endl;
    cout<<"Maximum Number: "<<max_so_far<<endl;

    return 0;
}