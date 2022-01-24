/* 
    Hollow Rhombus Pattern

    Given number of rows N, you have to print a Hollow Rhombus. See the output for corresponding given input.

    Input Format:   Single integer N.

    Constraints:    N <= 20

    Output Format:  Print pattern.

    Sample Input:   5

    Sample Output:      *****
                       *   *
                      *   *
                     *   *
                    *****

*/

#include<iostream>
using namespace std;

int main() {
	int total_row;
	cin >> total_row;

	int nos = total_row-1;                    // number of space in first row
	int nop = total_row;                      // number of pattern in first row
	for(int row=1; row<=total_row; row++){
		int cos;                             // counter of space
		int cop;                             // counter of pattern
		// print spaces
		for(cos=1; cos<=nos; cos++){
			cout << " ";
		}
		// print pattern
		if(row==1 || row==total_row){
			for(cop=1; cop<=nop; cop++){
				cout << "*";
			}
		}else{
			cout << "*";
		}
		// print spaces
		for(cos=1; cos<=total_row-2; cos++){
			cout << " ";
		}
		// print pattern
		if(row>1 && row<total_row)
				cout << "*";

		// for next iterations		
		nos--;
		cout<<endl;
	}
	return 0;
}

/* 
    Given pattern is seen as fist spaces and then stars for first and last row.And as first spaces then star then spaces and then star for in between rows.Thus, do the work for spaces and then for stars and then for spaces and stars.And do preparation accordingly for next iterations.

    Code:
    import java.util.Scanner;
    public class HollowRohmbusPattern {

        public static void main(String[] args) {

            Scanner scn = new Scanner(System.in);
            int n = scn.nextInt();

            int nst = n;            //initializing number of stars
            int nsp = n - 1;       // initializing number of spaces
            for (int i = 1; i <= n; i++) {

                // work for spaces
                for (int csp = 1; csp <= nsp; csp++) {
                    System.out.print(" ");
                }

                // work for stars

                for (int cst = 1; cst <= nst; cst++) {
                    System.out.print("*");
                }

                if (i > 1 && i < n) {
                    for (int csp = 1; csp <= n - 2; csp++) {
                        System.out.print(" ");
                    }
                    System.out.print("*");
                }

                // preparation for next iteration

                if (i >= 1 && i < n - 1) {
                    nst = 1;    // taking number of stars as 1 for in between rows

                } else {

                    nst = n;     //taking number of stars as n for last row
                }
                nsp = nsp - 1;
                System.out.println();
            }
        }
    }
*/