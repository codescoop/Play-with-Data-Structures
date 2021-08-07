/* 
    Print number pyramid for N rows
            1
          2 3 2
        3 4 5 4 3
      4 5 6 7 6 5 4
    5 6 7 8 9 8 7 6 5
*/

#include <iostream>
using namespace std;

int main(){
    int total_rows, row=1, col, value=0;

    cout<<"Enter total number of rows: ";
    cin>>total_rows;

    while(row <= total_rows){
      //Print Spaces
      col = total_rows-row;
      while(col > 0){
          cout<<" ";
          col--;
      }

      //Print Increasing Values
      col = row;
      while(col>0){
        value++;
        cout<<value;
        col--;
      }
      
      //Print Descreasing Values
      col = row-1;
      while(col>0){
        value--;
        cout<<value;
        col--;
      }
      
      cout<<endl;
      row ++;
    }

    return 0;
}