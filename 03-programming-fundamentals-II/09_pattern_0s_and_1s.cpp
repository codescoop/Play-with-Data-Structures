/*
    Print the below pattern upto N lines:
    0
    10
    010
    1010
    01010
    101010

    Observations:
    - For ith line print i numbers
    - odd line start with 0, and value alternates btw 0 and 1
    - even line start with 1, and value alternates btw 0 and 1
    - print n lines
*/

#include <iostream>
using namespace std;

int main(){
    int total_rows, row, col;
    
    cout<<"Enter total number of rows :";
    cin>>total_rows;

    for(row=1; row<=total_rows; row++){
        int value = row%2!=0?0:1;
        
        // Print i rows in ith line
        for(col=1; col<=row; col++){
            cout<<value;
            value = 1 - value;
            // cout<< (col%2!=0?value:!value);   
        }
        cout<<endl;
    }   
    return 0;
}