/*
    Problem Name - Unique Number - I

    We are given an array containg n numbers. All the numbers are present twice except for one number 
    which is only present once. Find the unique number without taking any extra spaces and in linear time.
    (Hint - Use Bitwise)

    Input Format: First line contains the number n. 
                  Second line contains n space separated number.

    Constraints:  n < 10^5

    Output Format: Output a single line containing the unique number

    Sample Input:  7
                   1 1 2 2 3 3 4 

    Sample Output: 4

    Explanation:   4 is present only once
*/


#include <iostream>
using namespace std;

int main()
{
    int total_num, num, ans=0;

    cout << "Enter total numbers: ";
    cin >> total_num;

    cout << "Enter numbers: ";
    for(int i=0; i<total_num; i++)
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
    Enter numbers: 1 1 2 2 3 3 4
    Unique No. is : 4


APPROACH:

    Use property of xor function to solve this problem. 

    Concept :
        If we take XOR of zero and some bit, it will return that bit: a^0 = a
        If we take XOR of two same bits, it will return 0: a^a=0
        a^b^a = (a^a)^b = 0^b = b
        So we can XOR all bits together to find the unique number.
*/