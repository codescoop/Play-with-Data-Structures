/*
    Take the following as input:
    A number
    Write a function which returns true if the number is an armstrong number and false otherwise, where Armstrong number is defined as follows.

    A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if.
    abcd… = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ….
    1634 is an Armstrong number as 1634 = 1^4 + 6^4 + 3^4 + 4^4
    371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3

    Input Format:  Single line input containing an integer

    Constraints:   0 < N < 1000000000

    Output Format: Print boolean output for each testcase.
                   "true" if the given number is an Armstrong Number, else print "false".

    Sample Input:  371

    Sample Output: true

    Explanation:   Use functions. Write a function to get check if the number is armstrong number or not. Numbers are armstrong if it is equal to sum of each digit raised to the power of number of digits.
*/

#include<iostream>
using namespace std;

int pow(int num,int power){
	if (num == 0)
		return 0;
	else if (power == 0)
		return 1;
	int res=1;
	while(power--){
		res *= num;
	}
	return res;
}

int check_armstrong(int num, int power){
	int sum = 0;
	int val = num;
	while(val){
		int rem = val%10;
		sum = sum + pow(rem,power);
		val /= 10;
	}
	return sum == num;
}

int main() {
	int num;
	cin >> num;

	int val = num;
	int no_of_digits = 0;
	while(val){
		no_of_digits++;
		val /= 10;
	}

	bool is_armstrong = check_armstrong(num, no_of_digits);
	if(is_armstrong)
		cout << "true";
	else
		cout << "false";
	return 0;
}

/* 
    Algorithm

    - Take input of number.
    - Calculate the number of digits of the number in a variable say , cnt.
    - Extract digit one by one from the number(using % 10).
    - Raise it to the power of number of digits and add it to sum.
    - After the loop check if the sum is equal to the original number.
        If yes, print true
        otherwise, print false.
  */