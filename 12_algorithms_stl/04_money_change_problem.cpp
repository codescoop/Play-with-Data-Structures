/* 
    Topic - Money Change Problem

    You are given Indian currency(i.e 1,2,5,10,20,50,100,200,500,2000) & an amount Rs X.
    You have to find to the change for amount X using minimum currency.

    Input = Rs 168
    
    Output = 100 50 10 5 2 1
    
    Explanation: [100+50+10+5+2+1 = Rs168]

*/

#include<iostream>
#include<algorithm>
using namespace std;

//comparator function (to overwrite lower bound)
bool compare(int a, int b){
    return a <= b;
}

// drive code
int main()
{
    int currency[] = {1,2,5,10,20,50,100,200,500,2000};
    int size = sizeof(currency)/sizeof(int);
    int amount;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Currency: ";
    while(amount){
        int idx = lower_bound(currency, currency+size, amount, compare) - currency -1;
        /* If search value is not present in array. Then lower bound will return 
           address of value, greater than the search value. So, we are reducing one index.
           Now, this will also increase one index for the case when the search values 
           is present in the array. So, we are using compare funtion to overwrite index.
        */
        int money = currency[idx];
        cout << money << " ";
        amount = amount - money;
    }

    cout << endl;
    return 0;
}

/* 
OUTPUT: 

    Enter amount : 182
    Currency     : 100 50 20 10 2
*/