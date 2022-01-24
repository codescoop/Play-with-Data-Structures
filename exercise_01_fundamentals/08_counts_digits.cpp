/*
    Problem: Take the following as input.
             A number
             A digit
             Write a function that returns the number of times digit is found in the number. 
             Print the value returned.
    
    Input Format:  Integer (A number) Integer (A digit)

    Constraints:  0 <= N <= 1000000000 0 <= Digit <= 9
    
    Output Format: Integer (count of times digit occurs in the number)

    Sample Input:   5433231 
                    3
    
    Sample Output:  3

    Explanation: The digit can be from 0 to 9. Assume decimal numbers.In the given case digit 3 is occurring 3 times in the given number.

*/

#include<iostream>
using namespace std;

int main() {
	int number, digit, count=0;
    cout<<"Enter number & digit: ";
	cin>>number>>digit;

	while (number>0){
		int rem = number%10;
		if(digit == rem) count++;
		number = number/10;
	}
	cout<<"Total counts: "<<count<<endl;
	return 0;
}
/*
    Logic is pretty simple viz, to extract digit from the number one by one, till the number become zero and take a counter that will increment by one each time you extract a digit.

    To extract digit from a number, you need to know a mathematical operation viz, modulus ( % ) that's for finding the remainder of any number when divided by a number.
    If we perform modulus ( % ) of any number by 10, we get the last digit.
    If the extracted digit is similar to the item provided then increment your counter by 1.
    If we Divide ( / ) any number by 10, the last digit get removed form the number.
    So, that next digit will be extracted from the last.
*/