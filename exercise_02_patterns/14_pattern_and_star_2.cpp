/* 
    Pattern Numbers & Stars - 2

    Take as input N, a number. Print the pattern as given in the input and output section.

    Input Format:   Enter value of N

    Constraints:    1 <= N < 10

    Output Format:  Print the pattern.

    Sample Input:   7

    Sample Output:  1******
                    12*****
                    123****
                    1234***
                    12345**
                    123456*
                    1234567

    Explanation:    There is no space between any two numbers. Catch the pattern for corresponding input and print them accordingly.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;
	
	int nop = 1;              // number of pattern in first row
	int nos = total_rows-1;                      // number of star in first row

	for(int row=1; row<=total_rows; row++){
		int cop;                      // counter of pattern
		int cos;                      // counter of star
		// print number pattern
		for(cop=1; cop<=nop; cop++){
			cout << cop;
		}
		// print stars
		for(cos=1; cos<=nos; cos++){
			cout << "*";
		}
		
		// for next iterations		
		nop++;
		nos--;
		cout << endl;
	}
	return 0;
}