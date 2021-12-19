/*
    Problem Name: Chewbacca and Number

    Luke Skywalker gave Chewbacca an integer number x. 
    Chewbacca isn't good at numbers but he loves inverting digits in them. 
    Inverting digit t means replacing it with digit 9 - t.

    Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. 
    The decimal representation of the final number shouldn't start with a zero.
    
    Input Format: The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.

    Constraints: x <= 100000000000000000

    Output Format: Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

    Sample Input:   4545

    Sample Output:  4444

    Explanation: There are many numbers form after inverting the digit. For minimum number, check if inverting digit is less than or greater than the original digit. If it is less, then invert it otherwise leave it.
*/

#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ll num;
    cout << "Enter number: ";
    cin >> num;

    ll res = 0;
    ll pow=1;
    bool stop = false;

    while(num){
        int last_digit = num%10;
        int compare_digit = 9 - last_digit;
        if(num/10 == 0 && last_digit == 9){
            stop = true;
        }
        if(compare_digit < last_digit && !stop){
            last_digit = compare_digit;
        }
    res += last_digit*pow;
    pow *= 10;
    num /= 10;
    }
    cout << res << endl;
	return 0;
}

/* 
The logic behind this Problem was pretty simple as we can invert any digit ( 9 - digit) but we need to invert only such digits that will eventually end up giving the smallest number possible.
So, we should invert only digits greater then or equal to 5 as after inverting them, the result gives us smallest number.
For e.g.,
9 - 5 = 4 viz, smaller than the original number that was 5.
9 - 8 = 1 viz, smaller than the original number that was 8.
but 9 - 1 = 8 viz, greater than the original number that was 1.

Important point to consider is, After inverting any digits their should not be trailing zeros that means, if their is 9 at the starting of the number then it must remain the same
Also input can be quite big so, u need to capture the number in long long int in c++ and long in java.

Lang - Cpp

#include<iostream>
using namespace std;
int main() {
    long long int num, n;
    cin >> num;
    n = num;
    long long int ans = 0;
    long long int mult = 1;
    while(n != 0){

      long long int rem = n % 10;

      if(rem >= 5){

        if(rem == 9 && (n/10) == 0){
         //do nothing
        }else{
          rem = 9 - rem;
        }
      }
      ans += rem * mult;
      mult *= 10;
      n /= 10;
    }
    cout << ans;
    return 0;
}
*/