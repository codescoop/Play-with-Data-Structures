/* 
    Pattern Numbers & Stars - 1

    Take as input N, a number. Print the pattern as given in output section for corresponding input.

    Input Format:    Enter value of N

    Output Format:   All numbers and stars are Space separated

    Sample Input:   5
    
    Sample Output:  1 2 3 4 5
                    1 2 3 4 * 
                    1 2 3 * * *
                    1 2 * * * * *
                    1 * * * * * * *

    Explanation:    Catch the pattern for the corresponding input and print them accordingly.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;
	
	int nop = total_rows;              // number of pattern in first row
	int nos = -1;                      // number of star in first row

	for(int row=1; row<=total_rows; row++){
		int cop;                      // counter of pattern
		int cos;                      // counter of star
		// print number pattern
		for(cop=1; cop<=nop; cop++){
			cout << cop << " ";
		}
		// print stars
		for(cos=1; cos<=nos; cos++){
			cout << "*" << " ";
		}
		// for next iterations
		nop--;
		nos += 2;
		cout << endl;
	}

	return 0;
}
