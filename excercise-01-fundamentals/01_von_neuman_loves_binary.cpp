/*
    Problem - Given a binary number ,help Von Neuman to find out its decimal representation. 
              For eg 000111 in binary is 7 in decimal.
    
    Input Format - The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

    Constraints - N<=1000 Digits in binary representation is <=16.

    Output Format - N lines,each containing a decimal equivalent of the binary number.

*/

#include<iostream>
using namespace std;

int main() {
	int total_inputs, bin_val;
	cin>>total_inputs;

	while(total_inputs>0){
		cin>>bin_val;
		int temp = bin_val;
		int base = 1;
        int dec_val = 0;
		while(temp>0){
			int last_digit = temp%10;                 // Extract rightmost digit
			dec_val = dec_val + (last_digit * base);  // add the digit to answer
			base = base * 2;                          // update the power of 2
			temp = temp / 10;                         // update the number
		}
		cout<<dec_val<<endl;
        total_inputs--;
	}

	return 0;
}

/*
    Sample Input:
    4
    101
    1111
    00110
    111111

    Sample Output:
    5
    15
    6
    63

*/