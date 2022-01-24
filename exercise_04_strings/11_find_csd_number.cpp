/*
    Problem Name: Find CSD Number

    Deepak and Gautam are having a discussion on a new type of number that they call Code Scoop Number or CSD Number. 

    They use following criteria to define a CSD Number.
    1.  0 and 1 are not a CSD number.
    2.  2,3,5,7,11,13,17,19,23,29 are CSD numbers.
    3.  Any number not divisible by the numbers in point 2( Given above) are also CSD numbers.
    
    Deepak said he loved CSD numbers. Hearing it, Gautam throws a challenge to him.
    Gautam will give Deepak a string of digits. 
    Deepak's task is to find the number of CSD numbers in the string.

    CSD number once detected should not be sub-string or super-string of any other CSD number.
    Ex- In 4991, both 499 and 991 are CSD numbers but you can choose either 499 or 991, not both.

    Further, the CSD number formed can only be a sub-string of the string.
    Ex - In 481, you can not take 41 as CSD number because 41 is not a sub-string of 481.

    As there can be multiple solutions, Gautam asks Deepak to find the maximum number of CSD numbers
    that can be formed from the given string. Now, help Deepak by solving Gautam's challenge.
        
    Input Format: First line contain size of the string.
                  Next line is A string of digits.

    Constraints: 1 <= Length of strings of digits <= 17

    Output Format: Maximum number of CSD numbers that can be formed.

    Sample Input: 5
                  81615

    Sample Output: 2

    Explanation: 61 and 5 are two CSD numbers.
*/

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

// function to convert string to long
long stringtolong(string s)
{
    long idx = 0;
    long num = 0;
    while(s[idx] >= '0' && s[idx] <= '9')
    {
        num = num * 10 + (s[idx] - '0');
        idx++;
    }
    return num;
}


// function to check CSD Number
bool is_cb_number(string s)
{   
    // coverting string into long long using STL function
    long long num = stoll(s);

    // check first condtion of CSD number
    if (num == 0 || num == 1) {
        return false;
    }

    // check second condtion of CSD number
    int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        if (num == arr[i]) {
            return true;
        }
    }
    // check third condtion of CSD number
    for (int i = 0; i < size; i++) {
        if (num % arr[i] == 0) {
            return false;
        }
    }
    return true;
}


// function to check if digits of CSD number till now has been a part of any other CSD number
bool is_valid(bool* visited, int start, int end)
{
    for(int idx=start; idx<end; idx++)
    {
        // if digit of CSD number is visted, return false
        if(visited[idx])
        {
            return false;
        }
    }
    return true;
}


// function to drive code
int main()
{   
    int size;
    cout << "Enter String Length: ";
    cin>>size;
    
    string s;
    cout << "Enter String: ";
    cin>>s;

    long count = 0;

    // array to store status for CSD number digit
    bool* visited = new bool[size];
    
    // setting default values of visited array
    for(int i=0; i<s.length(); i++)
    {
        visited[i]=false;
    }

    // loop to maintain Length of substring
    for(int len=1; len <= s.length(); len++)
    {   
        // loop to maintain Start Position of substring
        for(int start=0; start<=s.length()-len; start++)
        {   
            int end = start+len;
            // find substring using STL funtion
            string sub = s.substr(start, len);

            // check for CSD number
            if(is_cb_number(sub) && is_valid(visited,start,end))
            {
                count++;

                // update status for CSD number digits
                for(int k=start; k<end; k++)
                {   
                    visited[k]=true;
                }
            }
        }
    }

    cout << "Maximum number of CB numbers that are formed: ";
    cout << count << endl;

    return 0;
}
/*

Approach:
    - According to the Problem the work is to find the Max CSD numbers from the given number.
    - As to work on substrings of the given number, we will capture the element into the String
      instead of integer .
    - The number 'n' given is nothing to do with our approach(as we are working on String) but 
      can be useful acoording to your approach.
    
Intuition :
    - Put loop on string that will give substring of every length.
    - create a function that will return true if the passed number is a CSD number otherwise return false.
    - To put a check if the digit is already a part of the any other CSD number, create an boolean array
      say, valid[] which store which digits till now has been a part of any other CSD number.
    - Take a counter and increment if a CSD number is found.
    - At the end print the count.

*/