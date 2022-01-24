/* 
    Pattern Triangle

    Take N (number of rows), print the following pattern (for N = 4).
                        1 
                      2 3 2
                    3 4 5 4 3
                  4 5 6 7 6 5 4
    
    Constraints:    0 < N < 10

    Sample Input:   4
    
    Sample Output                   1
                                2	3	2
                            3	4	5	4	3
                        4	5	6	7	6	5	4
            
    Explanation: Each number is separated from other by a tab.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;
	
	for(int row=1; row <= total_rows; row++){
		int col;
		// printing spaces
		for(col= total_rows-row; col > 0; col--){
			cout << "\t";
		}
		// print number for first pattern
		int val = row;
		for(col=1; col<=row; col++){
			cout << val << "\t";
			val++;
		}
		// print number for second pattern
		val = val-2;
		for(col=1; col <= row-1; col++){
			cout << val << "\t";
			val--;
		}
		cout << endl;
	}
	return 0;
}

/* 
    In Pattern Question, there is a common method which we teach in course viz, taking nsp, nst, csp, cst and row variables.

    Pattern Hack: Always first Try to first print pattern by ignoring the value to be printed then accommodate your value in that pattern. For e.g.,
                    1 
                  2 3 2
                3 4 5 4 3
              4 5 6 7 6 5 4
    View it as:-
                    * 
                  * * *
                * * * * *
              * * * * * * * 

    Short Info about the variables:-
        1. nsp (number of spaces)-> Number of spaces in very First Line of the pattern.
        2. nst (number of stars)-> Number of stars in very first line of the pattern.
        3. csp (counter of spaces)-> counter of spaces that will print the required number of spaces and will be initialized with 1 and incremented upto nsp.
        4. cst (counter of stars)->  counter of spaces that will print the required number of stars and will be initialized with 1 and incremented upto nst.
        5. rows -> It will be initialized with 1 and will go upto the total number of rows in the pattern.

    Given pattern is seen as first spaces and then numbers.The numbers are first in increasing order then in decreasing order. Spaces are in decreasing order. So,first do the work for spaces and then for numbers .And then update variables accordingly for next iterations.

    Code:
    import java.util.Scanner;
    public class patterntriangle {

        public static void main(String[] args) {
            Scanner scn=new Scanner(System.in);

            int n=scn.nextInt();

            int nsp=n-1;
            int num=1;

            for(int i=1;i<=n;i++)
            {
                //work for spaces
            for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" \t");
            }

            // work for numbers

            for(int cst=1;cst<=(2*i-1);cst++)
            {
                System.out.print(num + "\t");

                if(cst<i)
                    num++;
                else
                    num--;

            }

            //preparation for next iteration

            nsp=nsp-1;
            num+=2;
            System.out.println();

            }
        }
    }
*/