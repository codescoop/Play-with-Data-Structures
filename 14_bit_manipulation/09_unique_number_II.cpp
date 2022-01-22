/*
    Topic: Unique Numbers - II

    We are given an array containg n numbers. 
    All the numbers are present twice except for two numbers which are present only once. 
    Find the unique numbers in linear time without using any extra space. 
    (Hint - Use Bitwise)

    Input Format: First line contains the number n. 
                  Second line contains n space separated number.

    Constraints:  n < 10^5

    Output Format: Output a single line containing the unique numbers separated by space

    Sample Input:  4
                   3 1 2 1

    Sample Output: 2 3

    Explanation:  Smaller number comes before larger number
*/

#include <iostream>
using namespace std;


// function to find unique numbers
void getUniqueNumbers(int arr[], int size)
{
    int unique_xor_val = 0;         // to store xor value of both unique numbers
    int first_num = 0;
    int second_num = 0;
    
    // finding the xor of both unique numbers
    for(int i=0; i<=size-1; i++)
    {
        unique_xor_val = unique_xor_val^arr[i];
    }

    // finding the position of first set bit in unique_xor_val
    int temp = unique_xor_val;
    int pos = 0;
    while((temp&1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    // find those numbers which contains set bit at position 'pos'
    int mask = 1<<pos;
    for(int i=0; i<=size-1; i++)
    {
        if(arr[i]&mask)
        {
            first_num = first_num^arr[i];
        }
    }
    
    second_num = unique_xor_val ^ first_num;

    cout << "Unique Numbers are: ";
    cout << min(first_num, second_num) << " " << max(first_num, second_num);
}


// function to drive code
int main()
{
    int total_num;
    cout << "Enter total numbers: ";
    cin >> total_num;

    int arr[total_num];
    cout << "Enter numbers: ";
    for(int i=0; i<=total_num-1; i++)
    {
      cin >> arr[i];
    }

    // finding the unique numbers
    getUniqueNumbers(arr, total_num);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter total numbers: 4
    Enter numbers: 3 1 2 1
    Unique Numbers are: 2 3

Case 2:
    Enter total numbers: 8
    Enter numbers: 5 1 2 1 2 3 5 7
    Unique Numbers are: 3 7

*/