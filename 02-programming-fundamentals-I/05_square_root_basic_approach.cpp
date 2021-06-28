/*
    Find the square root of a number without using any predefined function
    
    Eg: Input    Output  
          10      3.162

    We will be trying Brute Force approach 
    (i.e We will be trying many possibilities until we get the best answer)
*/

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int number, precision;
    cout<<"Enter the number: ";
    cin>>number;
    cout<<"Enter the precision: ";
    cin>>precision;

    float ans = 0;
    float inc = 1.0;

    while(precision >=0){
        // Finalize the correct digit for correct place
        while(ans*ans <= number){
            ans = ans + inc;
        }
        ans = ans-inc;
        // Update the increment for the next precision position
        inc = inc/10;
        precision--; 
    }

    cout<<ans<<endl;
    return 0;
}