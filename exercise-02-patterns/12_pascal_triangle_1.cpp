/* 
    Pascal Triangle 1

    Given an integer N, print Pascal Triangle upto N rows. 
    
    Input Format:   Single integer N.

    Constraints:    N <= 10

    Output Format:  Print pascal triangle.

    Sample Input:   4

    Sample Output:          1
                          1   1
                        1   2   1
                      1   3   3   1
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;
	
	int nos = total_rows;           // number of spaces in first row
	int nop = 1;                      // number of pattern in first row

	for(int row=1; row<=total_rows; row++){
		int cos;                      // counter of star
		int cop;                      // counter of pattern
		int num = 1;
		// print spaces
		for(cos=1; cos<=nos; cos++){
			cout << " ";
		}
		// print pattern - pascal number 
		for(cop=1; cop<=nop; cop++){
			if(cop==1 || cop==row){
				cout << 1 << " ";
			}else{
				num=num*(row-cop+1)/(cop-1);      // updating number
				cout << num <<" ";
			}
		}
		// for next iterations
		nos--;
		nop++;
		cout << endl;
	}
	return 0;
}


/* 
  Pascal's triangle is the triangular array of the binomial coefficients.The number of entries in a given line is equal to the line number.Every entry in the line is the value of a binomial coefficient. The value of ith entry in the number line is C(line,i)(i.e apply mathematical combination formula ).
  Where C(line,i)=line!/((line-i)!*i!).

  Given pattern can be seen as first spaces then numbers and can be formed using 3 approches:
  1.A simple method is to run two loops and calculate the value of binomial coefficient in inner loop. Complexity: O(N3).
  2.O(N2) time and O(n2) space complexity.In this method store the previously generated values in 2-D array. Use these values to generate value in a line.
  3.O(N2) time and O(1) space complexity. In this method calculate C(line,i) using C(line,i-1). It can be calculated in O(1) time as follows:

  C(line,i-1)=line!/((line-i+1)!*(i-1)!)
  C(line,i)=line!/((line-i)!*i!)
  C(line,i)=C(line,i-1)*(line-i+1)/i.

  Code:
  #include<iostream>
  using namespace std;

  int main() {
    int total_rows;
    cin >> total_rows;
    
    int row,col;
    //work for each row
    for(row=1;row<=total_rows;row++){
      int num=1;   //starting number

      //work for spaces
      for(int spaces=1; spaces<=(total_rows-row+1); spaces++){
        cout << " ";
      }

      // print pattern - pascal number 
      for(col=1; col<=row; col++){
        if(col==1)
          cout << col << " ";
        else
        {
          num=num*(row-col+1)/(col-1);      // updating number
          cout << num << " ";
        }
      }

      // for next iteration
      cout << endl;
    }
    return 0;
  }
*/