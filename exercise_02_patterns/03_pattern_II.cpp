/* 
    Patterns-II
    Print pattern of a given number. See the output pattern for given input n = 5.

    Input Format:   Single integer N denoting number of lines of the pattern.

    Constraints:    N<=1000

    Output Format:  Pattern.

    Sample Input:   5
    
    Sample Output:  1
                    11
                    202
                    3003
                    40004
    
    Explanation:    If row number is n (>1), total character is n. First and last character is n-1 and rest are 0. 
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int row = 1;

	while (row <= total_rows){
		if (row == 1)
			cout << 1;
		else{
			int col = row;
			cout << row-1;
			while (col-2 > 0){
				cout << 0;
				col--;
			}
			cout << row-1;
		}
		cout << endl;
		row++;
	}
	return 0;
}

/* 
    Lang - Java

    In Pattern Question, there is a common method which we teach in course viz, taking nsp, nst, csp, cst and row variables.

    Pattern Hack: Always first Try to first print pattern by ignoring the value to be printed then accommodate your value in that pattern. For e.g.,
    1
    1 1
    2 0 2
    3 0 0 3
    4 0 0 0 4

    View it as:-
    *
    * *
    * * *
    * * * *  
    * * * * *

    Short Info about the variables:-
        1. nsp (number of spaces)-> Number of spaces in very First Line of the pattern.
        2. nst (number of stars)-> Number of stars in very first line of the pattern.
        3. csp (counter of spaces)-> counter of spaces that will print the required number of spaces and will be initialized with 1 and incremented upto nsp.
        4. cst (counter of stars)->  counter of spaces that will print the required number of stars and will be initialized with 1 and incremented upto nst.
        5. rows -> It will be initialized with 1 and will go upto the total number of rows in the pattern.

    In Given, pattern no spaces are there only stars are present.
    Thinking about variables : nst = 1, cst = 1, rows = 1, total rows = n;
    Thinking about Value to be printed : row number is to be printed each time at the starting of the row and at the end of the row. So, starting of the row is when out cst is 1 and ending of the row when our cst is nst.

    public static void pattern2(int N) {

            int nst = 1;
            int rows = 1;

            while (rows <= N) {

                int val = 1;

                if (rows != 1) {
                    val = rows - 1;
                }
                int cst = 1;
                while (cst <= nst) {

                    if (cst == 1 || cst == nst)
                        System.out.print(val);
                    else
                        System.out.print(0);
                    cst++;

                }

                rows++;
                System.out.println();
                nst++;
            }

        }
*/