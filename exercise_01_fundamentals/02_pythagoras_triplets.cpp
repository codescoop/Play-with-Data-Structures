/*
    Problem - Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".
    
    Input Format - A single integer N

    Constraints - N <= 10^9

    Output Format - Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

*/

#include<iostream>
using namespace std;
#define ll long long int

int main() {
    ll num;
    cout<<"Enter the number: ";
    
    while(cin>>num){
        if(num<3){                            //No Pythagoras Triplet exists
            cout<<"-1"<<endl;
            continue;
        }
        if(num%2 == 0){                         // Calculating for even case
            cout<<((num*num)/4)-1<<" "<<((num*num)/4)+1<<endl;
        }
        else{                                  // Calculating for odd case
            cout<<((num*num)-1)/2<<" "<<((num*num)+1)/2<<endl;
        }
    }
    
   	return 0;
}

/*
    Formula for Triplets:

    - [Pythagoras Formula] - used for odd positive integers
       When n is ODD:   ((n*n)-1)/2   &  ((n*n)+1)/2 
    
    - [Plato's Formula] - used for even positive integers greater than 1
       When n is EVEN:   ((n*n)/4)-1   &  ((n*n)/4)+1 

*/