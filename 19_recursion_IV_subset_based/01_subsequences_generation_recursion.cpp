/*
    Topic - Subsequences / Subsets Generation (Recursion)
            (Important Concept for Many Problems)
    
    Note: Subarray means continious part of array 
          Eg: abc
          Subsequences/Subsets means we can also combine not continious parts of array
          Eg: abc, ac, ab, ...

    Given a string containing N characters. find out the all subsets of that string.

    Eg: Input  : s: "abc"
        Output : subsets: " ", "a", "b", "c", "ab", "ac", "bc", "abc"

*/


#include <iostream>
using namespace std;


void generateSubsets(char input[], int i, char output[], int j)
{
    // base case
    if(input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    // rec case: we have 2 options
    // Option 1: when we include the current character
    output[j] = input[i];
    generateSubsets(input, i+1, output, j+1);
    // Option 2: when we exclude the current character
    // output[j] = '\0';
    generateSubsets(input, i+1, output, j);
    return;
}


// function to drive code
int main()
{
    char input[] = "abc";
    int len = sizeof(input)/sizeof(char);
    char output[len+1]; 

    cout << "Subsets of \"" << input << "\": \n";
    generateSubsets(input, 0, output, 0);

    return 0;
}

/*
OUTPUT:
    Subsets of "abc": 
    abc
    ab
    ac
    a
    
    bc
    b
    c



Explanation:

    When s = "abc"
                         _______
                         |a|b|c|
              ______________|___________
             | ___                     _|__
            a(|b|c|)                   |b|c|
     (Include current char)   (Exclude current char)
                                           
            a + " "                     " "
            a + "b"                     "b"
            a + "c"                     "c"
            a + "bc"                    "bc"

    Print:  a, ab, ac, abc, " ", b, c, bc



Code Dry Run:

      When:    Input:    |a|b|c|\0|
                          0 1 2  3
                                                   _______                                              
      Then:                               Output: |_|_|_|_|                                             
                                                    i=j=0                                               
                                 _____________________|________________________                         
                                |                                              |                        
                            i=1,j=1                                         i=1,j=0                     
                           |a|_|_|_|                                       |\0|_|_|_|                   
                         /            \                                  /            \                 
               i=2,j=2                 i=2,j=1                    i=2,j=1                 i=2,j=0       
              |a|b|_|_|              |a|\0|_|_|                  |b|_|_|_|              |\0|_|_|_|      
              /       \               /      \                  /       \               /      \        
        i=3,j=3     i=3,j=2     i=3,j=1     i=3,j=1        i=3,j=2     i=3,j=1     i=3,j=1     i=3,j=0  
       |a|b|c|_|   |a|b|_|_|   |a|c|_|_|   |a|_|_|_|      |b|c|_|_|   |b|_|_|_|   |c|_|_|_|   |_|_|_|_| 
           |            |          |           |              |            |          |           |     
        ________    ________    ________    ________       ________    ________    ________    ________ 
Print: |a|b|c|\0|  |a|b|\0|_|  |a|c|\0|_|  |a|\0|_|_|     |b|c|\0|_|  |b|\0|_|_|  |c|\0|_|_|  |\0|_|_|_|
*/