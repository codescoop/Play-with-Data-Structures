/*
    Problem - Given a list of numbers, stop processing input after the cumulative sum of all the input becomes negative.
    
    Input Format - A list of integers to be processed

    Constraints - All numbers input are integers between -1000 and 1000.
    
    Output Format - Print all the numbers before the cumulative sum become negative.

    Sample Input:   1
                    2
                    88
                    -100
                    49
    
    Sample Output:  1
                    2
                    88    

*/

#include<iostream>
using namespace std;
int main() {
	int num, cumulative_sum=0;
	cout<<"Enter values for cumulative sum: ";

	while (cumulative_sum>=0){
		cin>>num;
		cumulative_sum = cumulative_sum+num;
		if(cumulative_sum>=0){
			cout<<num<<endl;
		}
	}
	return 0;
}

/*

    Many of you are Wondering where is the N(No of inputs specified)?
    Till when we need to take input??
    Ans to the question is present in the question itself, as it said print the numbers till u get positive cumulative sum, so u need to take input till u got the positive cumulative irrespective of the number inputs.

    Algo:   Put a loop till the END OF INPUT.
            Add the new number to the previous sum.
            If the sum is positive print the current number.
            Otherwise, break the loop.
*/