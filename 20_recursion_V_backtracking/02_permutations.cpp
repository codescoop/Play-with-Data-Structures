/*
    Topic - Permutations

    Given a string s, task is to find all permutation of the string s.

*/

#include <iostream>
using namespace std;


// function find all permutations
void permute(char *inp, int idx)
{
    // Base Case
    if(inp[idx] == '\0')
    {
        cout << inp << ", ";
        return;
    }
    // Recursive Case
    for(int j=idx; inp[j] != '\0'; j++)
    {
        swap(inp[idx], inp[j]);
        permute(inp, idx+1);
        // backtracing: to restore the original array
        swap(inp[idx], inp[j]);
    }
}


// function to drive code
int main()
{
    char ch[10];
    cout << "Enter your string: ";
    cin >> ch;

    cout << "Permutations: ";
    permute(ch, 0);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter your string : abc
    Permutations      : abc, acb, bac, bca, cba, cab, 

Case 2:
    Enter your string : aba
    Permutations      : aba, aab, baa, baa, aba, aab,

Case 3:
    Enter your string : 123
    Permutations      : 123, 132, 213, 231, 321, 312,
*/