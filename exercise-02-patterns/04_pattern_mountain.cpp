/* 
    Pattern Mountain

    Take N (number of rows), print the following pattern (for N = 4).
                        1           1
                        1 2       2 1  
                        1 2 3   3 2 1
                        1 2 3 4 3 2 1   

    Constraints:    0 < N < 10

    Sample Input:   4
    
    Sample Output:  1						1
                    1	2				2	1
                    1	2	3		3	2	1
                    1	2	3	4	3	2	1

    Explanation:    Each number is separated from other by a tab.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int total_cols = total_rows + (total_rows-1);
	int total_space = total_cols - 2;
	int row = 1;

	while (row <= total_rows){
		int col = 1;
		int val = 1;
		
		if (total_rows == 1){            // for first row only
			cout << val << "\t";
			break;
		}

		// printing first pattern
		while (col <= row){
			cout << val << "\t";
			val ++;
			col++;
		}

		// printing spaces
		col = 1;
		while (col <= total_space){
			cout << " " << "\t";
			col ++;
		}
		total_space -= 2;

		//printing second pattern
		col = 1;
		if (row == total_rows){          // for last row only
			val--;
			col ++;
		}
		while (col <= row){
			cout << --val << "\t";
			col++;
		}

		cout << endl;
		row++;
	}

	return 0;
}

/* 
    In Pattern Question, there is a common method which we teach in course viz, taking nsp, nst, csp, cst and row variables.

    Pattern Hack: Always first Try to first print pattern by ignoring the value to be printed then accommodate your value in that pattern. For e.g.,
                    1           1  
                    1 2       2 1    
                    1 2 3   3 2 1  
                    1 2 3 4 3 2 1    
    View it as:-
                    *           *
                    * *       * *  
                    * * *   * * *
                    * * * * * * *  

    Short Info about the variables:-
        1. nsp (number of spaces)-> Number of spaces in very First Line of the pattern.
        2. nst (number of stars)-> Number of stars in very first line of the pattern.
        3. csp (counter of spaces)-> counter of spaces that will print the required number of spaces and will be initialized with 1 and incremented upto nsp.
        4. cst (counter of stars)->  counter of spaces that will print the required number of stars and will be initialized with 1 and incremented upto nst.
        5. rows -> It will be initialized with 1 and will go upto the total number of rows in the pattern.

    Given pattern is seen as first work to print the numbers in increasing order then print the spaces accordingly and then the same pattern of numbers but in reverse order.
    So first do work for numbers then for spaces and then for numbers again.
    And then update variables accordingly for next iterations.
    Each number is separated from other by a tab ao use ' \t' for tab space.

    Code:

    import java.util.Scanner;
    public class patternMountain {
        public static void main(String[] args) {

            Scanner scn=new Scanner(System.in);

            int n=scn.nextInt();

            int nsp=2*n-3;     //initializing number of spaces
            int nst=1;         //initializing number of numbers

            for(int i=1;i<=n;i++)
            {
                int num=1;
                //work for numbers
                for(int cst=1;cst<=nst;cst++)
                {
                    if(cst!=n)
                    System.out.print(num+"\t");

                    num++;
                }

                //work for spaces
                for(int csp=1;csp<=nsp;csp++)
                {
                    System.out.print(" \t");
                }

                //work for numbers
                for(int cst=num-1;cst>=1;cst--)
                {
                    System.out.print(cst+"\t");
                }

                //preparation for next iteration

                nsp=nsp-2;
                nst++;
                System.out.println();
            }
        }
    }
*/