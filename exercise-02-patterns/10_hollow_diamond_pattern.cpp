/* 
    Hollow Diamond Pattern

    Take N (number of rows), print the following pattern (for N = 5).
        * * * * *
        * *   * *
        *       *
        * *   * *
        * * * * *

    Constraints:    0 < N < 10 (where N is an odd number)

    Sample Input:   5

    Sample Output:  *	*	*    *   *		  
                    *	*	     *   *
                    * 	             *
                    * 	*        *   *
                    * 	*	*    *   *	
                
    Explanation:    Each '*' is separated from other by a tab.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int mid = (total_rows/2)+1;             // middle row
	int nop = (total_rows/2)+1;             // number of pattern in first row
	int nos = -1;                         // number of space in first row

	for(int row=1; row<=total_rows; row++){
		int cop;                          // counter of pattern
		int cos;                          // counter of spaces
		//printing pattern
		for(cop=1; cop<=nop; cop++){
			cout << "*" << "\t";
		}
		// printing spaces
		for(cos=1; cos<=nos; cos++){
			cout << " " << "\t";
		}
		// printing pattern
		for(cop=1; cop<=nop; cop++){
			if((cop==1 && row == 1) || (cop==1 && row == total_rows))  
					continue;                          // to handle extra star
			cout << "*" << "\t";
		}

		// for next iterations
		if(row < mid){
			nop--;
			nos += 2;
		}else{
			nop++;
			nos -= 2;
		}
		cout << endl;
	}
	return 0;
}