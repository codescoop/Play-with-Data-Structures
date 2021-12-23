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
#include <string>
using namespace std;

bool isCSDNumber(int num){
    if(num == 0 || num==1){
        return false;
    }
    int i=2;
    while(i <= num-1){
        if(num%i == 0){
            return false;
        }
        i++;
    }
    return true;
}

void maxCSD(string str, int size)
{
    int totalCSD = 0;
    // find all sub string
    for(int i=0; i<=size-1; i++){
        for(int j=1; j<=size-1; j++){
            // s[]
        }
        // convert string to int
        // check cb
    }
    cout << "Total CSD Numbers: ";
    cout << totalCSD;
}

int main()
{
    int size;
    cout << "Enter string size: ";
    cin >> size;
    // cout << isCSDNumber(size);

    string str;
    cout << "Enter your string: ";
    cin >> str;

    // max csd numbers that can be formed
    maxCSD(str, size);
    cout << endl;

    return 0;
}

/*

*/