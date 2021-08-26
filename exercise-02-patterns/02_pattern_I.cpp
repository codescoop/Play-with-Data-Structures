/* 
    Pattern-I
    
    Given N, print pattern upto N lines. 
    For eg For N=6 , following pattern will be printed.
    1
    11
    111
    1001
    11111
    100001

    Input Format:   Single number N.

    Constraints:    N<=1000

    Output Format:  Pattern corresponding to N.

    Sample Input:   6
    
    Sample Output : 1 
                    11
                    111 
                    1001 
                    11111
                    100001
    Explanation:    For every odd number row print 1, odd number of times and for every even number row , print first and last character as 1 and rest of middle characters as 0.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int row = 1;

	while (row <= total_rows){               
		int col = row;
		if (row&1 == 1){                   // for even rows
			while(col > 0){
				cout << "1";
				col--;
			}
		}else{                            // for odd rows
			cout << "1" ;
			while(col-2 > 0){
				cout << "0";
				col--;
			}
			cout << "1" ;
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
            11
            111
            1001
            11111
            100001
    View it as:-
            *
            **
            ***
            ****
            *****
            ******
    Short Info about the variables:-
        1. nsp (number of spaces)-> Number of spaces in very First Line of the pattern.
        2. nst (number of stars)-> Number of stars in very first line of the pattern.
        3. csp (counter of spaces)-> counter of spaces that will print the required number of spaces and will be initialized with 1 and incremented upto nsp.
        4. cst (counter of stars)->  counter of spaces that will print the required number of stars and will be initialized with 1 and incremented upto nst.
        5. rows -> It will be initialized with 1 and will go upto the total number of rows in the pattern.

    In the given pattern,
    First build an intuition that u need to work for first row and at the end of the loop need to do work for the next row.
    For each row first you need to print your pattern in decreasing order then spaces and then the same pattern but in increasing order.
    To build the whole pattern just repeat this work according to total number of rows. With this approach, things seems to work out easily.

    public static void pattern1(int N) {

            int nst = 1;
            int rows = 1;

            while (rows <= N) {

                int cst = 1;
                while (cst <= nst) {

                    if (rows % 2 != 0 || cst == 1 || cst == nst) {
                        System.out.print(1);
                    } else {
                        System.out.print("0");
                    }

                    cst++;

                }

                rows++;
                System.out.println();
                nst++;
            }

        }
*/
