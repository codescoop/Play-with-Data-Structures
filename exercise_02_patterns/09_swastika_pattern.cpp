/* 
    卐 Swastika Pattern
    
    Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.
            *  ****
            *  *
            *  *
            *******
               *  *
               *  *
            ****  *
    
    Input Format:   Enter value of N ( >=5 )

    Constraints:    5 <= N <= 99

    Output Format:  Print the required pattern.

    Sample Input:   7
    
    Sample Output:  *  ****
                    *  *
                    *  *
                    *******
                       *  *
                       *  *
                    ****  *

    Explanation: Catch the pattern for the corresponding input and print it accordingly.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

    int total_cols = total_rows;
	int mid= (total_rows/2)+1;
	int last = total_rows;

	for(int row=1; row<=total_rows; row++){
		for(int col=1; col <= total_cols; col++){
			if((col==1 && row<mid) || (col==last && row>mid) || col==mid || row==mid || (row==1 && col>mid) || (row==last && col<mid) ) 
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}

/* 
    Divide the given pattern in two parts from middle .Now do the work of these parts separately and print the required pattern accordingly.

    Code:
    #include <iostream>
    using namespace std;
    int main (){
        int row, col;
        int total_rows;
        cin >> total_rows;

        // work for first row
        cout << "*";

        for (col = 1; col <= (total_rows+1)/2 - 2; col++)
            cout << " ";

        for (col = 1; col <= (total_rows+1)/2; col++)
            cout << "*";
        cout << endl;

        //work till middle row
        for (row = 1; row <= (total_rows+1)/2 - 2; row++)
        {
            cout << "*";

            for (col = 1; col <= (total_rows+1)/2 - 2; col++)
            cout << " ";

            cout << "*";

            cout << endl;
        }

        //work for middle row
        for (row = 1; row <= total_rows; row++)
            cout <<"*";
        cout << endl;

        //work till last row
        for (row = 1; row <= (total_rows+1)/2 - 2; row++)
        {
            for (col = 1; col <= (total_rows+1)/2 - 1; col++)
            cout << " ";

            cout << "*";

            for (col = 1; col <= (total_rows+1)/2 - 2; col++)
            cout << " ";

            cout << "*";

            cout << endl;
        }

        //work of last row
        for (row = 1; row <= (total_rows+1)/2; row++)
            cout << "*";

        for (row = 1; row <= (total_rows+1)/2 - 2; row++)
            cout << " ";

        cout <<"*";
        return 0;
    }

    Lang - Java

    Short Info about the variables:-
        1. nsp (number of spaces)-> Number of spaces in very First Line of the pattern.
        2. nst (number of stars)-> Number of stars in very first line of the pattern.
        3. csp (counter of spaces)-> counter of spaces that will print the required number of spaces and will be initialized with 1 and incremented upto nsp.
        4. cst (counter of stars)->  counter of spaces that will print the required number of stars and will be initialized with 1 and incremented upto nst.
        5. rows -> It will be initialized with 1 and will go upto the total number of rows in the pattern.
    
    Given pattern is seen as first we need to work for spaces and then for the numbers in each row.
    Numbers are first increasing till the mid element and then decreasing till end of the row.
    Thus, do the work of first spaces and then for numbers .
    And then change variables accordingly for next iterations.
    Always think of first row and then work for the next iteration and repeat the work total number of row times. That's how you can solve any problem related to pattern.

    import java.util.*;
    public class Main {
        public static void main(String args[]) {
            Scanner scn = new Scanner(System.in);

            int n = scn.nextInt();
            PattenG(n);
        }

        public static void PattenG(int n) {

            int nsp = n / 2 - 1;
            int rows = 1;
            int nst = n / 2;

            while (rows <= n) {

                if (rows <= n / 2 + 1) {

                    if (rows <= n / 2) {
                        System.out.print("*");

                        int csp = 1;
                        while (csp <= nsp) {
                            System.out.print(" ");
                            csp++;
                        }
                    } else {
                        int cst = 1;
                        while (cst <= nst) {
                            System.out.print("*");
                            cst++;
                        }
                    }

                    if (rows == 1 || rows == n / 2 + 1) {

                        int cst = 0;
                        while (cst <= nst) {
                            System.out.print("*");
                            cst++;
                        }
                    } else {
                        System.out.print("*");
                    }
                } else {

                    if (rows < n) {
                        int csp = 0;
                        while (csp <= nsp) {
                            System.out.print(" ");
                            csp++;
                        }
                    } else {
                        int cst = 1;
                        while (cst <= nst) {
                            System.out.print("*");
                            cst++;
                        }
                    }

                    System.out.print("*");

                    int csp = 1;
                    while (csp <= nsp) {
                        System.out.print(" ");
                        csp++;
                    }

                    System.out.print("*");

                }
                System.out.println();
                rows++;
            }
        }
    }
*/