/* 
    Given coefficients of a quadratic equation , you need to print the nature of the roots (Real and Distinct , Real and Equal or Imaginary) and the roots.
    If Real and Distinct , print the roots in increasing order.
    If Real and Equal , print the same repeating root twice
    If Imaginary , no need to print the roots.

    Note : Print only the integer part of the roots.

    Input Format:   First line contains three integer coefficients a,b,c for the equation ax^2 + bx + c = 0.

    Constraints:   -100 <= a, b, c <= 100

    Output Format: Output contains one/two lines. 
                   First line contains nature of the roots .
                   The next line contains roots(in non-decreasing order) separated by a space if they exist. 
                   If roots are imaginary do not print the roots. Output the integer values for the roots.

    Sample Input:   1 -11 28
    
    Sample Output:  Real and Distinct
                    4 7
    
    Explanation: The input corresponds to equation ax^2 + bx + c = 0. Roots = (-b + sqrt(b^2 - 4ac))/2a , (-b - sqrt(b^2 - 4ac))/2a 
*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;

	int d = b*b-(4*a*c);
	int d_root = sqrt(d);

	if(d>0){
		cout<<"Real and Distinct";
	}else if(d==0){
		cout<<"Real and Equal";
	}else{
		cout<<"Imaginary";
	}
	cout << endl;
	if(d>=0){
		int root_1 = (-b - d_root)/(2*a);
		int root_2 = (-b + d_root)/(2*a);
		cout<<root_1<<" "<<root_2;
	}
	return 0;
}

/* 
    Formulas for Solving Quadratic Equations:
    1. The roots of the quadratic equation: x = (-b ± √D)/2a, where D = b2 – 4ac

    2. Nature of roots:
        D > 0, roots are real and distinct (unequal)
        D = 0, roots are real and equal (coincident)
        D < 0, roots are imaginary and unequal


    Algo:

    1 Calculate the D viz, sqrt(b * b - 4 * a * c).
    2 If D < 0,
        - print Imaginary
    3 if D == 0,
        - print Real and Equal
        - Calculate roots using formula ( - b + D) / (2 * a) and (- b - D)/ (2 * a)
        - Print the roots
    4 If D > 0,
        - print Real and Distinct
        - Calculate roots using formula ( - b + D) / (2 * a) and (- b - D)/ (2 * a)
        - print the roots (in non-decreasing order)
    5 End
*/