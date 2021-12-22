/*
    Problem Name: Ultra Fast Mathematicians

    Prateek is an extremely gifted student. He is great at everything including Combinatorics, Algebra, 
    Number Theory, Geometry, Calculus, etc. He is not only smart but extraordinarily fast!.

    One day Prateek was trying to find out if any one can possibly do calculations faster than him. 
    As a result he made a very great contest and asked every one to come and take part.

    In his contest he gave the contestants many different pairs of numbers. 
    Each number is made from digits 0 or 1. 
    The contestants should write a new number corresponding to the given pair of numbers. 
    The rule is simple: The i-th digit of the answer is 1 if and only if 
    the i-th digit of the two given numbers differ. 
    In the other case the i-th digit of the answer is 0.

    Prateek made many numbers and first tried his own speed. 
    He saw that he can perform these operations on numbers of length ∞ (length of a number 
    is number of digits in it) in a glance!
    He always gives correct answers so he expects the contestants to give correct answers, too. 
    He is a good fellow so he won't give anyone very big numbers and he always gives 
    one person numbers of same length.

    Now you are going to take part in Shapur's contest. See if you are faster and more accurate.


    Input Format: The first line contains an integer t , the no. of testcases. 
                  There are two inputs in each line. Each of them contains a single number. 
                  It is guaranteed that the numbers are made from 0 and 1 only and that their length is same. 
                  The numbers may start with 0.

    Constraints: The length of each number doesn't exceed 100.

    Output Format: Write t lines — the corresponding answer to the corresponding input. 
                   Do not omit the leading 0s.

    Sample Input:   1
                    10111 10000

    Sample Output:  00111

    Explanation: For the given example, Let str1 = "10111" and str2 = "10000", 
                 Value at first position of str1 is 1 and first position str2 is 1, 
                 hence according to the rule there will be 0 at the first position of the final ans.
                 Similarly, for second position the value at second position of both of the strings is 0,
                 so , there will be 0 at the second position of the final ans.
                 Similarly, for third position the value at third position of str1 is 1 and str2 is 0,so ,
                 there will be 1 at the third position of the final ans and So, on.
*/

#include <iostream>
using namespace std;

int main() {
    int testCases;
    cout << "Enter testcase: ";
    cin >> testCases;
    
    for(int i=0; i<=testCases-1; i++){
        string s1,s2;
        cout << "Enter you Input: ";
        cin >> s1 >> s2;
        
        cout << "Output: ";
        for(int idx=0; idx<s1.length(); idx++){
            if(s1[idx] == '-' || s2[idx] == '-'){            // for negative values
                continue;
            }else if(s1[idx] == s2[idx]){
                    cout << '0';
            }else{
                cout << '1';
            }
        }
    cout << endl;
    }
	return 0;
}


/* 

Approach:

    After taking the input, we enter a for loop with range from 0 to n-1 , 
    where n is the length of the input string(both strings have the same length). 
    We extract one character from each string and put them in two character variable a and b.

    We now check whether they are the same character or not. 
    If they are the same, we output 0. Otherwise, we print out 1 since a and b are not same characters.

    After the loop is finished, we get the desired output binary string.

C++ Code

    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        int t;
        cin>>t;
        while(t--){
            string s1, s2;
            cin >> s1 >> s2;
            for (size_t i = 0; i < s1.length(); ++i)               // using size_t datatype
            {
                if (s1[i] == s2[i])
                {
                    s1[i] = '0';
                }
                else
                {
                    s1[i] = '1';
                }
            }
            cout << s1 << endl;
        }
        return 0;
    }

    -----------------------------------------
    size_t Datatype:-

    size_t is an unsigned integral data type which is defined in various header files such as: 
    <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>, <wchar.h>
    
    1. It is guaranteed to be big enough to contain the size of the biggest object the host system can handle.
        Basically the maximum permissible size is dependent on the compiler; 
        if the compiler is 32 bit then it is simply a typedef(i.e., alias) for unsigned int but 
        if the compiler is 64 bit then it would be a typedef for unsigned long long.
    2.The size_t data type is never negative.
    
    Therefore many C library functions like malloc, memcpy and strlen declare their arguments and 
    return type as size_t.

    -----------------------------------------
    Java Code

    import java.util.*;
    public class Main {
        public static void main(String args[]) {

            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-- > 0){
                String str1 = sc.next();
                String str2 = sc.next();
                StringBuilder sb = new StringBuilder("");
                int i;
                for(i = 0; i < str1.length() && i< str2.length(); i++ ){
                    char c1 = str1.charAt(i);
                    char c2 = str2.charAt(i);
                    if(c1 != c2) sb.append("1");
                    else sb.append("0");
                }
                while(i < str1.length()){
                    sb.append(str1.charAt(i));
                    i++;
                }
                while(i < str2.length()){
                    sb.append(str2.charAt(i));
                    i++;
                }

                System.out.println(sb);


            }
        }
    }
*/