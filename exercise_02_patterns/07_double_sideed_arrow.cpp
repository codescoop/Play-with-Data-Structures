/* 
    Pattern Double Sided Arrow

    Take N as input. For a value of N=7, we wish to draw the following pattern :
                                1 
                            2 1   1 2 
                        3 2 1       1 2 3 
                    4 3 2 1           1 2 3 4 
                        3 2 1       1 2 3 
                            2 1   1 2 
                                1 
   
    Input Format:    Take N as input.

    Constraints:     N is odd number.

    Output Format:   Pattern should be printed with a space between every two values.

    Sample Input:    7

    Sample Output:              1 
                            2 1   1 2 
                        3 2 1       1 2 3 
                    4 3 2 1           1 2 3 4 
                        3 2 1       1 2 3 
                            2 1   1 2 
                                1 

    Explanation:    Catch the pattern and print it accordingly.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int nos1 = total_rows-1;              // nos - number of space in first row  of pattern-1
	int nos2 = -1;                        // nos - number of space in first row of pattern-2
	int nop = 1;                          // nov - number of pattern in first row

	for(int row=1; row <= total_rows; row++){
		int val;
		if(row <= total_rows/2)               // till mid rows
			val = row;
		else                                  // after mid rows
			val = (total_rows-row)+1;

		// print spaces
		for(int cos=1; cos <= nos1; cos++){                       // cos - counter of spaces
			cout << "  "; 
		} 
		// print numbers - decreasing
		for(int cop=1; cop<=nop; cop++){                          // cop - counter of pattern
			cout << val << " ";
			val--;
		}
		// print spaces
		for(int cos=1; cos<=nos2; cos++){
			cout << "  "; 
		}
		// print number - increasing
		for(int cop=1; cop<=nop; cop++){
			if(row==1 || row==total_rows)
				continue;
			val++;
			cout << val << " ";
		}

		// for next iteration
		if(row <= total_rows/2){               // till mid rows
			nos1 -= 2;
			nop++;
			nos2 += 2;
		}else{                                 // after mid rows
			nos1 += 2;                      
			nop--;
			nos2 -= 2;
		}




		cout << endl; 
	}
	
	return 0;
}


/* 
    #include<iostream>
    using namespace std;

    int main() {
        int total_rows;
        cin >> total_rows;

        int nsp1 = total_rows-1;             // nsp - number of space in first
        int nst = 1;                         // nst - number of values in first 

        int nsp2 = 2;                        // nsp - number of space in first
        int nst2 = total_rows/2;

        int num = 1;

        for(int row=1; row <= total_rows; row++){
            int csp;
            int cst;
            if(row <= (total_rows/2)+1){             // till mid value 
                // print space-1
                for(csp=1; csp <= nsp1; csp++){
                    cout << " " << " ";
                }
                // print pattern-decreasing
                for(cst=1; cst<=nst; cst++){
                    cout << num << " ";
                    num--;
                }
                //print space-2
                for(csp=1; csp<=(2*(row-1)-1); csp++){
                    cout << " " << " ";
                }
                //print pattern-increasing
                for(cst=1; cst<=nst; cst++){
                    num++;
                    if(nst > 1){
                        cout << num << " ";
                    }
                }
                nsp1 = nsp1-2;
                nst++;
            }else{                            // after mid value 
                // print spaces-1
                for(csp=1; csp<=nsp2; csp++){
                    cout << " " << " ";
                }
                // print pattern-descreasing
                num = num-2;
                for(cst=1; cst<=nst2; cst++){
                    cout << num << " ";
                    num--;
                }
                // print spaces-2
                for(csp=1; csp<=((total_rows*2)-(row*2)-1); csp++){
                    cout << " " << " ";
                }
                //print patern-increasing
                for(cst=1; cst<=nst2; cst++){
                    if(row==total_rows)
                        break;
                    num++;
                    cout << num << " ";
                }
                nsp2 = nsp2+2;
                nst2--;
            }
            num++;
            cout << endl;
        }
        
        return 0;
    }
 */