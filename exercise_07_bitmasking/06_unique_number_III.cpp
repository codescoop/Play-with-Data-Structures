/*
    Problem Name: Unique Numbers - III

    We are given an array containg n numbers. 
    All the numbers are present thrice except for one number which is only present once. 
    Find the unique number. Only use - bitwise operators, and no extra space.

    Input Format:  First line contains the number n. Second line contains n space separated number.

    Constraints:  N < 10^5

    Output Format:  Output a single line containing the unique number

    Sample Input:   7
                    1 1 1 2 2 2 3

    Sample Output:  3

    Explanation:  3 is present only once
*/


#include <iostream>
using namespace std;

int main()
{
    int total_num, num;

    cout << "Enter total numbers: ";
    cin >> total_num;

    // Array of fixed size - O(1) space
    int bitCount[64] = {0};      // to maintain sum of bit-count at every bit position for input-numbers

    cout << "Enter numbers: ";
    for(int i=0; i<total_num; i++)
    {
        cin >> num;

        // update the bitCount array by extracting bits of each input number
        int idx = 0;
        while(num)
        {
            int lastBit = num&1;
            bitCount[idx] += lastBit;     // maintaing sum of each-bit-count
            idx++;
            num = num>>1;
        }
    }

    /*  
        As the numbers are repeated thrice. 
        So, sum of bit-count will be of form 3N or 3N+1 at every bit position.
        Thus to find the unique number, take modulus with 3 for sum-of-bit-count at every bit position
        (i.e eliminating the contribution of bits which are occuring 3N times) & converting 0s and 1s 
        into decimal number.
    */
    int power = 1;
    int ans = 0;
    for(int idx=0; idx<64; idx++)
    {
        bitCount[idx] = bitCount[idx]%3;  // reducing by a factor of 3
        ans += bitCount[idx]*power;
        power  = power<<1;                // power *= 2;
    }

    cout << "Unique Number: " << ans;
    cout << endl;

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter total numbers: 7
    Enter numbers: 1 1 1 3 2 2 2
    Unique Number: 3

Case 2:
    Enter total numbers: 7
    Enter numbers: 5 6 5 6 1 5 6
    Unique Number: 1
*/