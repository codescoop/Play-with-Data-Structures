/*
    Problem Name: Find all words in CamelCase string

    One of the important aspect of object oriented programming is readability of the code. 
    To enhance the readability of code, developers write function and variable names in Camel Case. 
    You are given a string, S, written in Camel Case. 
    Find all the words contained in it.

    Input Format: A single line contains the string.

    Constraints: |S|<=1000

    Output Format: Print words present in the string, in the order in which it appears in the string.

    Sample Input: IAmACompetitiveProgrammer

    Sample Output:  I
                    Am
                    A
                    Competitive
                    Programmer

    Explanation: There are 5 words in the string.
*/

#include <iostream>
#include <string>
using namespace std;

// function to print all words in camelcase string
void printWords(string s)
{
    for(int i=0; s[i] != '\0'; i++){
        // for first character
        if(i == 0){
            cout << s[i];
            continue;
        }
        // comparing with ascii values
        if (s[i] >= 'A' && s[i] <= 'Z'){
            cout << endl;
            cout << s[i];
        }else{
            cout << s[i];
        }
    }
}

int main()
{
    string s;
    cout << "Enter you String [in CamelCase]: ";
    cin >> s;

    // print all words in camelcase string
    printWords(s);
    cout << endl;

    return 0;
}

/*

Topic : Ad-hoc, string
Difficulty : Easy

EXPLANATION
Problem can be solved by dividing the input string at position, i, either if Si is the last letter, or
 Si+1 is a capital letter.

Time Complexity : O(N)

Code: 

    #include "bits/stdc++.h"
    #define mod 1000000007
    #define nn 100010
    
    using namespace std;
    ​
    int main()
    {
        int n;
        string s;
        cin>>s;
        n=s.length();
        string pr;
        for(int i=0;i<n;i++)
        {
            pr.push_back(s[i]);
            if(i==n-1) //last letter
                cout<<pr<<endl;
            else if(s[i+1]>='A' && s[i+1]<='Z') //s[i+1] is a capital letter.
            {
                cout<<pr<<endl;
                pr.clear();
            }
        }
        return 0;
    }

*/