/* 
    Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".

    Constraints:    2 < N <= 1000000000

    Sample Input:    3

    Sample Output:  Prime
    
    Explanation:  The output is case specific
 */

#include<iostream>
using namespace std;
int main() {
	int num;
	cin >> num;

	bool is_prime = true;
	int divisor = 2;
	while (divisor < num){
		if(num%divisor == 0){
			is_prime = false;
			break;
		}
		divisor++;
	}
	if(is_prime)
		cout << "Prime";
	else
		cout << "Not Prime";
	return 0;
}

/* 
    Any number which has only two divisors, one divisor is the number itself and other divisor is 1, is called as Prime number.

    Algorithmn:
    Take input of the number.
    put a loop from 2 to that number.
    If the number gets divided by any number in the loop, that means the number is not Prime.
    Othewise, Prime.
 */