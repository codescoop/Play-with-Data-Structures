/* 
    Fibonacci Pattern (Pattern 4):
    Take N (number of rows), print the following pattern (for N = 4)
    0
    1 1
    2 3 5
    8 13 21 34

    Constraints:    0 < N < 100

    Sample Input:   4
    
    Sample Output:  0 
                    1    1 
                    2    3     5 
                    8   13    21    34

    Explanation:  Each number is separated from other by a tab. For given input n, You need to print n(n+1)/2 fibonacci numbers. Kth row contains , next k fibonacci numbers.
 */

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int row = 1;
	int first_fibo = 0;
	int second_fibo = 1;
	int counter=1;

	while (row <= total_rows){           // for rows
		int col = row;
		while (col > 0){                // for columns
			if (counter == 1)
				cout << first_fibo;
			else if (counter == 2)
				cout << second_fibo;
			else{
				int third_fibo = first_fibo + second_fibo;
				cout << third_fibo;
				first_fibo = second_fibo;
				second_fibo = third_fibo;
			}
			cout << "\t";
			counter ++;
			col --;
		}
		cout << endl;
		row ++;
	}

	return 0;
}

/* 
	Lang - Java

	In Pattern Question, there is a common method which we teach in course viz, taking nsp, nst, csp, cst and row variables.

	Pattern Hack: Always first Try to first print pattern by ignoring the value to be printed then accommodate your value in that pattern. For e.g.,
	0
	1 1
	2 3 5
	8 13 21 34

	View it as:-
	*
	* *
	* * *
	* * * *  

	Short Info about the variables:-
		1. nsp (number of spaces)-> Number of spaces in very First Line of the pattern.
		2. nst (number of stars)-> Number of stars in very first line of the pattern.
		3. csp (counter of spaces)-> counter of spaces that will print the required number of spaces and will be initialized with 1 and incremented upto nsp.
		4. cst (counter of stars)->  counter of spaces that will print the required number of stars and will be initialized with 1 and incremented upto nst.
		5. rows -> It will be initialized with 1 and will go upto the total number of rows in the pattern.

	In Given, pattern no spaces are there only stars are present.
	nst = 1, cst = 1, rows = 1, total rows = n;

	The Fibonacci numbers are the numbers in the following integer sequence. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
	In this sequence a fibonacci number is calculated as sum of the previous two fibonacci numbers.Here 0th fibonacci is 0 and 1stfibonacci is 1.
	In the given pattern each number is separated from other by a tab. For given input n, You need to print n(n+1)/2 fibonacci numbers i.e. Kth row contains , next k fibonacci numbers.

	Code:
		public static void pattern(int n){
			int nst = 1;
			int rows = 1;
			int firstFibo = 0;
			int secondFibo = 1;
			while(rows <= n){


				int cst = 1;
				while(cst <= nst){

					System.out.print((firstFibo)+"\t"); // Print the fibo number
					int thirdFibo = firstFibo + secondFibo; // Generate Third Fibo number
					firstFibo = secondFibo;  //Update first Fibo number
					secondFibo = thirdFibo; // Update third Fibo number
					cst++;
				}

				rows++;
				nst++;
				System.out.println();
			}
		}
		
	------------ ***** ----------
	Lang - CPP

		int main() {
			int total_rows;
			cin >> total_rows;

			int row = 1;
			int first_fibo = 0;
			int second_fibo = 1;
			
			while (row <= total_rows){                           // for rows
				int col = row;
				while (col > 0){                                 // for columns
					cout << first_fibo << "\t";
					int third_fibo = first_fibo + second_fibo;
					first_fibo = second_fibo;
					second_fibo = third_fibo;
					col --;
				}
				cout << endl;
				row ++;
			}

			return 0;
		}

*/
