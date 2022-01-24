/*
    Problem:  Due to an immense rise in Pollution, transport minister is back with the Odd and Even Rule. 
              The scheme is as follows, each car will be allowed to run on Sunday 
              if the sum of digits which are even is divisible by 4 or sum of digits which are odd in that number is divisible by 3. 
              However to check every car for the above criteria can't be done by the Traffic Police. 
              You need to help Traffic Police by finding out if a car numbered N will be allowed to run on Sunday?

    Input Format: The first line contains N , then N integers follow each denoting the number of the car.

    Constraints: N<=1000 Car No >=0 && Car No <=1000000000
    
    Output Format: N lines each denoting "Yes" or "No" depending upon whether that car will be allowed on Sunday or Not !

    Sample Input:  2
                   12345
                   12134
    
    Sample Output: Yes
                   No

    Explanation: 1 + 3 + 5 = 9 which is divisible by 3
                 1 + 1 + 3 = 5 which is NOT divisible by 3 and 2+4 = 6 which is not divisble by 4.

*/

#include<iostream>
using namespace std;
int main() {
	int total_num, car_num, even_sum, odd_sum;
    cout<<"Enter total car's : ";
	cin>>total_num;
    cout<<"Enter car numbers : ";
	while(total_num!=0){
		cin>>car_num;
		even_sum = 0;
		odd_sum = 0;
		while(car_num>0){
			int rem = car_num%10;
			if(rem%2==0){
				even_sum += rem;
			}else{
				odd_sum += rem;
			}
			car_num /= 10;
		}

		if(even_sum%4==0 || odd_sum%3==0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	
		total_num--;
	}

	return 0;
}

/*

    Algorithm

    Take input of the Number.
    Declare two variables to store the sum of even numbers and odd numbers.
    Extract digit one by one ( by % 10).
        1. Check if the number is even or odd.
        2. If even add the number in the variable storing even sum.
        
        1. Othewise add it in the variable storing odd sum.
    
    After the loop, Check if the even sum is divisible by 4.
        1. If True, print Yes.
        2. otherwise print No.
    Check if the odd sum is divisible by 3.
        1. If True, print Yes.
        2. otherwise print No.


*/