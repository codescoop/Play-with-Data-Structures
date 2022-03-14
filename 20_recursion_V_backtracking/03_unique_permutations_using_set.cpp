/*
    Topic - Unique Permutations (using set STL)

    Given a string s, task is to find all unique permutation of the string s.

    Input  : aba
    Output : aab, aba, baa

    Explaination: all permutaions: aab, aba, baa, baa, aba, aab,
                  unique         : aab, aba, baa,
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;


// function find all permutations
void uniquePermute(char *inp, int idx, set<string> &s)
{
    // Base Case
    if(inp[idx] == '\0')
    {
        // cout << inp << ", ";
        string str = inp;
        s.insert(str);
        return;
    }
    // Recursive Case
    for(int j=idx; inp[j] != '\0'; j++)
    {
        swap(inp[idx], inp[j]);
        uniquePermute(inp, idx+1, s);
        // backtracing: to restore the original array
        swap(inp[idx], inp[j]);
    }
}


// function to drive code
int main()
{
    char ch[100];
    cout << "Enter your string: ";
    cin >> ch;

    set<string> s;

    uniquePermute(ch, 0, s);

    // loop over the set s
    cout << "Unique Permutations: ";
    for(auto str:s)
    {
        cout << str << ", ";
    }

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter your string   : aba
    Unique Permutations : aab, aba, baa,

Case 2:
    Enter your string   : 121
    Unique Permutations : 112, 121, 211,
*/