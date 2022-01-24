/*
    Problem Name - Playing With Bits

    Raman likes to play with bits. One day Raman decides to assign a task to his student Sanya. 
    You have to help Sanya to complete this task. 
    Task is as follows - Raman gives Q queries each query containing two integers a and b. 
    Your task is to count the no of set-bits in for all numbers between a and b (both inclusive)

    Input Format:  Read Q - No of Queries, Followed by Q lines containing 2 integers a and b.

    Constraints:   Q,a,b are integers.

    Output Format: Q lines, each containing an output for your query.

    Sample Input:  2
                   1 1
                   10 15

    Sample Output:  1
                    17

*/


#include <iostream>
using namespace std;

// function to count set bits
int countBits(int n)
{
    int count=0;
    while(n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

// function to count set bits between range I to J
int countSetBitIToJ(int start, int end)
{
    int count = 0;
    for(int i=start; i <= end; i++)
    {
        count += countBits(i);
    }
    return count;
}


// function to drive code
int main()
{
    int testcase;
    cout << "Enter total testcases: ";
    cin >> testcase;

    while(testcase--)
    {
        int i, j;
        cout << "Enter Range [i & j]: ";
        cin >> i >> j;

        cout << "Total Set Bits: ";
        cout << countSetBitIToJ(i,j) << endl;
    }

    return 0;
}

/* 

OUTPUT:
    Enter total testcases: 2

    Enter Range [i & j]: 1 1
    Total Set Bits: 1

    Enter Range [i & j]: 10 15
    Total Set Bits: 17


APPROACH:

    This is a quite simple problem to tackle. Just loop through all the numbers between a and b and 
    calculate the no of set bits using either brian kernighan algo or the inbuilt function for 
    counting set bits
*/