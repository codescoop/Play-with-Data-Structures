/*
    Topic: Generate Subsets using Bitmasking

    - Finding Subsequences/Subset of a Given String
      (Remember Subsequences are continious whereas Subset are not continious)

      Eg: Input : "abc"
          Output: " ",a,ab,abc,ac,b,bc,c

*/


#include <iostream>
#include <cstring>
using namespace std;


void filterChars(char c[], int n)
{
    int idx=0;

    while(n)
    {
        int last_bit = n&1;
        if(last_bit == 1)
        {
            cout << c[idx];
        }
        idx++;
        n = n>>1;     // Discard the last bit
    }
    cout << endl;
}


void printSubsets(char c[])
{
    int len = strlen(c);
    for(int i=0; i < (1<<len); i++)
    {
        filterChars(c, i);
    }
    return;
}


// function to drive code
int main()
{
    char c[100];

    cout << "Enter character: ";
    cin >> c;

    cout << "Output: \n";
    printSubsets(c);

    return 0;
}

/* 

OUTPUT:

    Enter character: abc

    Output: 

    a
    b
    ab
    c
    ac
    bc
    abc
*/