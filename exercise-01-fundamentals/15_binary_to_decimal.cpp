/* 
    Take N (number in binary format). Write a function that converts it to decimal format and Print the value returned.
    Constraints:     0 < N <= 1000000000

    Sample Input:    101010
    Sample Output:   42
    
    Explanation:     For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.
 */

#include<iostream>
using namespace std;
int main() {
	int b_num;
	cin >> b_num;
	int pow = 1;
	int d_num = 0;
	while(b_num){
		int rem = b_num%10;
		d_num += (rem * pow);
		pow *= 2;
		b_num /= 10;
	}
	cout << d_num;
	return 0;
}

/* 
    For binary number fedcba , Decimal number = f.2^5 + e.2^4 + d.2^3 + …..+ a.2^0.

    The idea is to extract the digits of given binary number starting from right most digit and keep a variable decvalue.
    At the time of extracting digits from the binary number, multiply the digit with the proper base (Power of 2)
    and add it to the variable dec_value.
    At the end, the variable decvalue will store the required decimal number.
*/