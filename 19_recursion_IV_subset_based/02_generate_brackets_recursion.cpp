/*
    Topic - Generate Brackets (Recursion)

    Generate Balanced Brackets using N-Pairs of Round Brackets

    Eg: Input  : N = 2
        Output : 2 
        // The 2 Brackets are ()(), (())

        Input  : N = 3
        Output : 5 
        // The 5 Brackets are ()()(), (()) (), () (()), (()()), ((()))

*/


#include <iostream>
using namespace std;

// function to generate balanced brackets for N-Pairs
void generateBrackets(int n, char output[], int idx, int openCount, int closeCount)
{
    // base case
    if(idx == 2*n)
    {
        output[idx] = '\0';
        cout << output << endl;
        return;
    }

    // rec case: we have 2 options
    // Option 1: for open bracket
    if(openCount < n)
    {
        output[idx] = '(';
        generateBrackets(n, output, idx+1, openCount+1, closeCount);
    }
    // Option 2: for close bracket
    if(closeCount < openCount)
    {
        output[idx] = ')';
        generateBrackets(n, output, idx+1, openCount, closeCount+1);
    }
    return;
}


// function to drive code
int main()
{
    int total_pairs;
    cout << "How many Bracket Pairs: ";
    cin >> total_pairs;

    // For N pairs we need to store 2*N+1 elements in a array. +1  fors null character
    char output[(total_pairs*2)+1];

    cout << "Brackets: \n";
    generateBrackets(total_pairs, output, 0, 0, 0);

    return 0;
}



/*
OUTPUT:

Case 1:
    How many Bracket Pairs: 2
    Brackets: 
    (())
    ()()

Case 2:
    How many Bracket Pairs: 3
    Brackets: 
    ((()))
    (()())
    (())()
    ()(())
    ()()()


Explaination:

    We need to take care of two conditions:
    - At any index i,
      open-bracket-count should be less than N (i.e total pairs)
    - close-bracket-count must be less than open-bracket-count (i.e closeBracketCount < OpenBracketCount)

      Note: if closeBracketCount <= OpenBracketCount, then there are cases when close brackets will be 
            placed before open brackets. Thus, creating bracket imbalance.

Code Dry Run:

      When:                           N = 2
                                     _________                            
      Then:                         |_|_|_|_|_|                           Output[5], idx=0
                            ______/__           \                         
              (open < n)   |(|_|_|_|_|            X    (close = open)     idx = 1 
               _________ /             \__________                        
              |(|(|_|_|_|               |(|)|_|_| |                       idx = 2
              /   ____\____           ____/____   \                       
            X    |(|(|)|_|_|         |(|)|(|_|_|    X                     idx = 3
                  /    __\______       /    \ _________                   
                X     |(|(|)|)|_|    X       |(|)|(|)|_|                  idx = 4
                       _____|____             _____|____                  
      Print:          |(|(|)|)|\0|           |(|)|(|)|\0|                 
*/