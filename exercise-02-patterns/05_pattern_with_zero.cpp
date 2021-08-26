/* 
    Pattern with Zeros
    
    Take N (number of rows), print the following pattern (for N = 5)
        1
        2 2
        3 0 3
        4 0 0 4
        5 0 0 0 5

    Input Format:    There will be an integer in input.

    Constraints:     0 < N < 100

    Output Format:   Print the pattern.

    Sample Input:       5

    Sample Output:      1  
                        2	2  
                        3	0	3    
                        4	0	0	4  
                        5	0	0	0	5

    Explanation:    Each number is separated from other by a tab.If row number is n (>1), total character is n. First and last character is n and rest are 0.
*/

#include<iostream>
using namespace std;

int main() {
	int total_rows;
	cin >> total_rows;

	int row = 1;
	while(row <= total_rows){                      // for rows
		int col = 1;
		while(col <= row){                         // for columns
			if (col==1 || col==row)
				cout << row << "\t";
			else
				cout << 0 << "\t";
			col++;
		}
		cout << endl;
		row++;
	}
	return 0;
}

/* 
    Lang - Cpp

    Each number is separated from other by a tab. For each row total characters is equal to row number itself where first and last character is i(i.e.row number) and rest are 0(i.e middle elements).

    Code:

    #include<iostream>
    using namespace std;

    int main() {
        int row, col;
        int total_rows;
        cin >> total_rows;
                                                    
        for (row = 1; row <= total_rows; row++)       //loop for each row
        {
            for (col = 1; col <= row; col++)          //loop for each col
            {
                if(col==1 || col==row)
                    cout << i<<"    ";               // for 1st and last element
                else
                    cout << "0"<<"  ";                // for in between elements
            }

            cout << endl;
        }
        return 0;
    }

    Lang - Java
    In Pattern Question, there is a common method which we teach in course viz, taking nsp, nst, csp, cst and row variables.
    Pattern Hack: Always first Try to first print pattern by ignoring the value to be printed then accommodate your value in that pattern. For e.g.,
    1
    2 2
    3 0 3
    4 0 0 4
    5 0 0 0 5

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

    int main() {
	int total_rows;
	cin >> total_rows;

	int nst=1;
	for (int row=1; row <= total_rows; row++){
		for (int cst=1; cst<=nst; cst++){
			if(cst == 1 || cst == nst)
				cout << row <<"\t";
			else
				cout << 0 << "\t";
		}
		cout << endl;
		nst++;
	}
	return 0;
}
*/