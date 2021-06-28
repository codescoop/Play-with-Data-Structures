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
    int total_rows, row=1, step, value;

    cout<<"Enter total number of rows: ";
    cin>>total_rows;

    while(row <= total_rows){
      //Print Spaces
      step = row;
      while(total_rows-step > 0){
          cout<<" ";
          step++;
      }

      //Print Increasing Values
      step = row;
      value = row;
      while(step>0){
        cout<<value;
        value++;
        step--;
      }
      
      //Print Descreasing Values
      step = row;
      value = value-2;
      while(step>1){
        cout<<value;
        value--;
        step--;
      }
      
      cout<<endl;
      row ++;
    }

    return 0;
}