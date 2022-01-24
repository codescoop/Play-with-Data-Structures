/*
    Problem Name: Broken Calculator

    Andrew was attempting a mathematics test where he needed to solve problems with factorials. 
    One such problem had an answer which equaled 100! ,
    He wondered what would this number look like. 
    He tried to calculate 100! On his scientific calculator but failed to get a correct answer. 
    Can you write a code to help Andrew calculate factorials of such large numbers?
    
    Input Format: a single lined integer N

    Constraints: 1 < = N < = 500

    Output Format: Print the factorial of N

    Sample Input:   5

    Sample Output:  120

    Explanation: for factorial of 5 we have 5 x 4 x 3 x 2 x 1 = 120
*/

#include <iostream>
#define MAX 2000               // When Max=2000, We can calculate upto 800! (factorial)
using namespace std;

// calculate factorial by storing result values in Array
int multiply(int resultArr[], int resultSize, int num){
    int carry = 0;
    for(int i=0; i<=resultSize-1; i++){
        int product = resultArr[i]*num + carry;
        resultArr[i] = product%10; 
        carry = product/10;
    }
    while(carry){
        resultSize++;      // increasing index to store carry
        resultArr[resultSize-1] = carry%10;
        carry /= 10;
    }
    return resultSize;
}

int main() {
    int inputNum;
    cout << "Enter number for calculating factorial: ";
    cin >> inputNum;

    int resultArr[MAX];        // using Array to store large factorial value
    resultArr[0] =  1;         // first value of result array
    int resultSize = 1;        // array lenght count

    // calculate factorial & returing the length of array
    for(int num=2; num<=inputNum; num++){
        resultSize = multiply(resultArr, resultSize, num);
    }
    // print the factorial value
    for(int i=resultSize-1; i>=0; i--){
        cout << resultArr[i];
    }
    // cout << "\nFactorial Length: " << resultSize;
    cout << endl;
	return 0;
}

/* 

Approach:

Algorithm for factorial:

factorial()
1. Create an array ‘res[]’ of MAX size where MAX is number of maximum digits in output.
2. Initialize value stored in ‘res[]’ as 1 and initialize ‘res_size’ (size of ‘res[]’) as 1.
3. Do following for all numbers from [int x=2 to n]
   … Multiply x with res[] and update res[] and res_size to store the multiplication result.
4. Print res[] from right to left.


Algorithm for multiplication:

multiply(res[], x)
1. Initialize carry as 0.
2. Do following for [int i=0 -> res_size–1]
   ….a) Find value of res[i] * x + carry. Let this value be prod.
   ….b) Update res[i] by storing last digit of prod in it.
   ….c) Update carry by storing remaining digits in carry.
3. Put all digits of carry in res[] and increase res_size by number of digits in carry.

--------------------------------------
Example:- 

So, let’s understand it with the help of an example:

Relate the approach with the way you perform multiplication in mathematics.

- Why are we using a matrix?
    The factorial results in a value greater than the range of long long.
    Example:
    Input :50
    Output : 30414093201713378043612608166064768844377641568960512000000000000

-----------------------------------

- Let’s understand the logic for multiplication using a small example:
    76*4

1.  In mathematics:

    76
    x4
    __
    304

    After multiplying 4 with 6 the result is 24
    adding carry to it i.e. 0 initially. So, the result is 24 only.
    So, write the last digit as it is i.e. 4
    Then, take 2 as carry over 7.

    Now multiplying 4 with 7, the result is 28
    Add carry to it 28+2=30
    Write the last digit as it is i.e. 0
    And take 3 as carry.

    As there are no more digits left to multiply with 4.
    So, write carry as it is in the answer i.e. 3.
    Hence, the answer is 304

- Now, the same approach has been followed in the code.
    The only difference is. The result here is stored from right to left.
    In the case of the array, it will be stored from left to right

----------------------------------
2. In Code (using array):

    - Create an array of size 1000: 
        int res[10000];
    
    - Initially res[] stores 76: 
        res[0] = 6    (the digit at one’s place is at index 0)
        res[1] = 7 
    
    - Set 
        res_size=2;
    
    - Initialize carry to zero
        carry=0;

    - Now multiply res[] with 4 :-
        for i=0 to res_size-1:
        when i=0:
            prod = res[i]*4 + carry;  (i.e 6*4 + 0 = 24)
            res[i] = res%10;          (i.e 24%10 = 4) (gives the digit at one’s place)
            carry = res/10;           (i.e 24/10 = 2) (rest goes to carry)
        when i=1:
            prod = res[i]*4 + carry;  (i.e 7*4 + 2 = 30)
            res[i] = res%10;          (i.e 30%10 = 0) (gives the digit at one’s place)
            carry= res/10;            (i.e 30/10 = 3) (rest goes to carry)
        End loop

        //insert carry to the res[]
        while(carry>0)
            res[res_size++] = carry%10;  (i.e res[2]= 3%10 =3)
            carry = carry/10;            (i.e 3/10 = 0)
        End loop
        
    This is how the multiplication is happening in the logic.

Note:
As result in array is stored from left to right in res[].
So, print res from right to left i.e. from index res_size-1 to 0.

*/