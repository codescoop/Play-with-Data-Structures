/* 
    Pattern Inverted HourGlass

    Take N as input. For a value of N=5, we wish to draw the following pattern :

                5                   5 
                5 4               4 5 
                5 4 3           3 4 5 
                5 4 3 2       2 3 4 5 
                5 4 3 2 1   1 2 3 4 5 
                5 4 3 2 1 0 1 2 3 4 5 
                5 4 3 2 1   1 2 3 4 5 
                5 4 3 2       2 3 4 5 
                5 4 3           3 4 5 
                5 4               4 5 
                5                   5 

    Input Format: Take N as input.

    Output Format:  Pattern should be printed with a space between every two values.

    Sample Input:       5
 
    Sample Output:      5                   5 
                        5 4               4 5 
                        5 4 3           3 4 5 
                        5 4 3 2       2 3 4 5 
                        5 4 3 2 1   1 2 3 4 5 
                        5 4 3 2 1 0 1 2 3 4 5 
                        5 4 3 2 1   1 2 3 4 5 
                        5 4 3 2       2 3 4 5 
                        5 4 3           3 4 5 
                        5 4               4 5 
                        5                   5 
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int nop = 1;
	int nos = (total_rows*2)-1;                
	
	for(int row=1; row<=(total_rows*2)+1; row++){
		int val = total_rows;
		// for pattern
		for(int cop=1; cop<=nop; cop++){
			cout << val <<" ";
			val--;
		}
		// for space
		for(int cos=1; cos<=nos; cos++){
			cout << "  "; 
		}
		// for pattern
		for(int cop=1; cop<=nop; cop++){
			if(nop == total_rows+1 && cop == 1){
				cop++;
				val++;
			}
				val++;
				cout << val << " ";
		}

		// for next iteration
		if(row < total_rows+1){
			nop++;
			nos = nos-2;																											
		}else{
			nop--;
			nos = nos+2;
		}
		cout << endl;
	}
	return 0;
}