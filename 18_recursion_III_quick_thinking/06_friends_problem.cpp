/*
    Topic - Friends Problem (Recursion)

    # Friends Pairing Problem
    Given N friends who want to go to party on bikes. Each guy can go as single or duo.
    Find the number of ways in which N friends can go to the party.
    
    Eg: Input  : N = 3
        Output : Ways = 4
        Explanation: There are 3 Friends (f1, f2, f3). So, different ways they can go to party on bike:-
                    - Each go as single : (f1) as single & (f2) as single & (f3) as single 
                    - Duo & Single      : (f1,f2) as duo & (f3) as single
                    - Duo & Single      : (f1,f3) as duo & (f2) as single
                    - Duo & Single      : (f2,f3) as duo & (f1) as single
*/

#include <iostream>
using namespace std;

// funtion to compute combination of nCr when r=1
int getCombination(int n, int r)
{
    r = 1;
    /*  

        As,  C = ___n!___
                  (n-r)! 

        when r=1,    C = ___n!___  =  _n_*_(n-1)!__  =  n
                          (n-r)!         (n-r)!          
    */
    return n;
}


// function to get total number of ways to N friends pair up for party on bikes
int getNoOfWays(int totalFrineds)
{
    // base case
    if(totalFrineds == 0)
    {
        return 1;
    }
    if(totalFrineds < 0)
    {
        return 0;
    }
    // rec case:
    int single = 1 * getNoOfWays(totalFrineds-1);
    int duo = getCombination(totalFrineds-1, 1) * getNoOfWays(totalFrineds-2);

    return single + duo;
}


// function to drive code
int main()
{
    int n;
    cout << "Enter total friends: ";
    cin >> n;

    cout << "Number of ways: ";
    cout << getNoOfWays(n);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter total friends: 3
    Number of ways: 4

Case 2:
    Enter total friends: 2
    Number of ways: 2


APPROACH:

                                                                                    O   
                                                                                   `|`  
               ______ ______ ______ ______ ______ ______ .................______ __/ \__
     Friends:    0      1      2      3      4      5                      n-1      n

                1 is going single (one way) and left friends (n-1)
                i.e  1 and f(n-1)  
                                       O                                             O   
                                      `|`                                           `|`  
               ______ ______ ______ __/ \__ ______ ______ .................______ __/ \__
     Friends:    0      1      2       3      4      5                      n-1      n

                2 are going duo (i.e combination(n-1,2)) and left friends (n-2)
                i.e  C(n-1, 2) and f(n-2)
          
    So,  f(n) = 1 and f(n-1) or  c(n-1,1) and f(n-2)
              =     1*f(n-1)  +  c(n-1,1)*f(n-2)



    Example:   base case: N=0  ans=1
                          N=1  ans=1
                  
               rec case : N=2  ans=2       f(2) = 1*f(1) + C(1,1)*f(0)
                                                = 1 + 1*1
                                                = 2
                          N=3  ans=4       f(2) = 1*f(2) + c(2,1)*f(1)
                                                = 1*2 + 2*1
                                                = 4
*/