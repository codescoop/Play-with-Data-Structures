/**
  * C++ Implement of Tower of Hanoi (n-disk) puzzle. 
  */

#include <iostream>
using namespace std;

//Tower of Hanoi function
int TOH(int n, int a, int b, int c)
{
    // a,b,c are names of Towers
    if (n==0)
        return 1; 
    TOH(n-1,a,c,b);
    cout<<"Move disk "<<a<<" to "<<c<<"\n";
    TOH(n-1,b,a,c);
    return 0;
}

int main()
{
    int n; // Number of disks
    
    cout<<"Enter number of Disks : ";
    cin>>n;
    
    // 1,2,3 are name of Towers
    TOH(n,1,2,3);
    return 0;
}