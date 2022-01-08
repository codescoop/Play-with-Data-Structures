/* 
    Topic - Binary Search in Monotonic Search Space

    >> Square Root using Binary Search
       n = 10
       square_root(n) = 3    (int/floor)
    
    We actually has to think about search space. Also, no such search space is given in the above query.
    But, there exist a search space which is sorted & monotonic
    
    Eg: Suppose we are given a number N. 
        So, the square root of number N lies in the search space 0 to N.
        Now, we can apply binary search on this range.
*/

#include <iostream>
using namespace  std;

float get_square_root(int num, int precision)
{
    float ans = -1;
    // assuming a search space (0 to num) & appling binary search
    int start = 0;
    int end = num;
    while(start<=end){
        int mid = (start+end)/2;
        if(mid*mid == num){
            return mid;
        }
        if(mid*mid < num){
            ans = mid;              //  getting most potential value for answer
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    // finding the precision values using brute force
    float inc = 0.1; 
    for(int times=1; times<=precision; times++)
    {
        while(ans*ans <= num){
            ans = ans + inc;
        }
        // reducing the overshot value
        ans = ans - inc;
        // for next iteration
        inc = inc/10;
    }
    return ans;
}

// function to drive code
int main(){
    int num, precision;
    cout << "Enter number & precision: ";
    cin >> num >> precision;

    cout << "Square root: " << get_square_root(num, precision) << endl;

    return 0;
}


/* 
OUTPUT:

Case1:
    Enter number & precision: 10 3
    Square root: 3.162

Case2:
    Enter number & precision: 100 3
    Square root: 10

Case3:
    Enter number & precision: 2 4
    Square root: 1.4142
 */