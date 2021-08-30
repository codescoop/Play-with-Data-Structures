/* 
    Calculate the nCr.

    C(n,r) =  ____n!_____       where n = the set or population
                r!(n-r)!              r = subset or sample set
*/

#include<iostream>
using namespace std;

int factorial(int num){
    int ans = 1;
    for (int seq = 1; seq<=num; seq++){
        ans = ans*seq;
    }
    return ans;
}

int nCr(int n, int r){
    int ans = factorial(n) / (factorial(r)*factorial(n-r));
    return ans;
}

int main(){
    int n ,r;
    cout << "Enter values of n & r to calculate nCr: ";
    cin >> n >> r;
    
    cout << nCr(n,r) << endl;
    return 0;
}