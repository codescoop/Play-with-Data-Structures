/*
    Print the below pattern upto N lines:
    1
    11
    111
    1001
    11111
    100001
    1111111
    10000001
*/

#include <iostream>
using namespace std;

int main(){
    int rows, col, step = 1;

    cout<<"Enter the rows: ";
    cin>>rows;

    while (step <= rows){
        col = 1;
        if(step%2 != 0){
            while(col <= step){
                cout<<"1";
                col++;
            }
        }else{
            cout<<1;
            while(col <= step-2){
                cout<<"0";
                col++;
            }                        
            cout<<1;
        }
        step++;
        cout<<endl;
    }

    return 0;
}