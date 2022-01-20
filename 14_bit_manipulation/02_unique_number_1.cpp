/*
    Topic: Unique Number - 1

    - Given a list of numbers (2N+1) where every number occurs twice except one, find that unique number
*/

#include <iostream>
using namespace std;

int main()
{
    int total_num, num, ans=0;

    cout << "Enter total numbers: ";
    cin >> total_num;

    cout << "Enter numbers: ";
    for(int step=0; step<total_num; step++)
    {
        cin >> num;
        // Using bitwise XOR Operator to solve, It helped to not use any storage
        ans = ans^num;
    }
    
    cout<<"Unique No. is : "<< ans << endl;

    return 0;
}

/* 
OUTPUT:

  Enter total numbers: 7
  Enter numbers: 5 6 5 6 1 2 1
  Unique No. is : 2
  
*/