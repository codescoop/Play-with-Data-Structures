/*
    Topic: Divisible Subarray

    You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
    A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

    Input Format: The first line contains the number of test cases T. 
                  First line of each test case contains an integer N denoting the number of elements. 
                  Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes 
                  the ith element of the array.

    Constraints: 1<=T<=10
                 1<=N<=10^5
                 |ai|<=10^9          // i.e array elements can be negative

    Output Format: Output a single integer denoting the number of good sub-arrays.

    Sample Input: 2
                  5
                  1 1 1 1 1
                  5
                  5 5 5 5 5
    
    Sample Output: 1
                   15
    
    Explanation:  In first test case, there is only one sub-array [1, 1, 1, 1, 1], such that 1+1+1+1+1=5,
                  which is divisible by N=5
*/


#include <iostream>
#include <cstring>
using namespace std;

#define ll long

ll arr[1000005];
ll freq[1000005];                  // to store frequency of csum[]%N

// function to drive code
int main()
{
    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int size;
        cout << "Enter Total Elements: ";
        cin >> size;

        // initilize the arr with the sum of 0
        memset(freq,0,sizeof(freq));

        // frequecy of '0' is 1 bcz in the beginning if we don't consider any element then
        // sum of NULL sub-array is 0. So frequency of '0' is 1
        // So, 0 sum will come atleast onces because we have NULL sub array
        freq[0] = 1;

        // read the input
        cout << "Enter array elements: ";
        int csum = 0;
        for(int i=0; i<size; i++)
        {
            cin >> arr[i];
            csum += arr[i];
            csum = csum % size;  
            // in some case it can become negative  eg: (-5 + 3)%5 = -2
            csum = (csum+size)%size;
            // For any number x, x%N can N unique values.  eg: x%5  can be (0,1,2,3,4)
            freq[csum]++;      // increase the frequency for range 0 to N-1
        }
        
        for(int i=0; i<size; i++)
        {
            cout << freq[i] << ", ";
        }
        cout << endl;

        ll ans = 0;
        // iterate to all position & do nCr for r>2
        for(int i=0; i<size; i++)
        {
            ll m = freq[i];
            // NOTE: for m less than 2, the ans = 0
            ans += (m * (m-1)) / 2;     // nCr formula
            /* 
                 nCr = ____n!____
                        r!*(n-r)!
                when r = 2
                 nCr = ____n!____ = __n*(n-1)*(n-2)!____ = __n*(n-1)__
                        2!*(n-2)!       2! * (n-2)!            2
                       
             */
        }
        cout << "Total good sub-arrays: ";
        cout << ans << endl;
    }
    return 0;
}

/* 

OUTPUT:
    Enter testcases: 3

    Enter Total Elements: 5
    Enter array elements: 1 3 2 6 4
    Total good sub-arrays: 3

    Enter Total Elements: 5
    Enter array elements: 1 1 1 1 1
    Total good sub-arrays: 1

    Enter Total Elements: 5 
    Enter array elements: 5 5 5 5 5
    Total good sub-arrays: 15


Approach: 

    Pigeonhole Principle : The pigeonhole principle states that if n items are put into m containers, 
                           with n > m, then at least one container must contain more than one item.
    
    - Create Cumulative sub array for N given elements.
    - Take mod N with the Cumulative sub array and
    - create a frequency array 'f' having frequency of each sum
    - Now, sum all the Combination of frequency which are greater than 2
      i.e   ans += fC2  where f>2
      (Why for frequency > 2 bcz Atleast 2 boxes will have same values)


    Eg: Input  :  N   =    5  
                  Elements = 1,3,2,6,4
        Output :  3                       // Good Sub array: |3|2|, |6|4|, |3|2|6|4|
        
    Sol:
        arr[]      :   |1|3|2| 6| 4|
        cSum[]     : |0|1|4|6|12|16|      // 0 for NULL sub-arry 
                        |   |
                        a   b
        Now,  as per the definition of Good Sub array,
        we have to find those sub arrays where (cum[b]-cum[a]) % N is 0
                                           i.e (6-1)%5
                                              = 0
        If     (cum[b]-cum[a]) % N = 0
        then,   cum[b]%N = cum[a]%N 

        cSum[] % N   : |0|1|4|1|2|1|
        Now, we have total 6 values.

        But, we can have almost 5 unique values.
        (because any number x mod 5 can have only 5 unique values   i.e x%5 can be 0,1,2,3,4)
        (General case will be, any number x mod N can have output-value from N unique values)
        
        So, as per Pigeonhole Principle, Atleast 2 boxes will have same values.
        (why we are looking for same values bcz we are looking for positions where cum[b]%N = cum[a]%N. 
        So, If we pick any 2 positions and they are having same SUM then that sub-array is a good sub-array)
        
        Now, create frequeny array from cSum[] % N
        freqency[] = |1|3|1|0|1|
                      0 1 2 3 4

        Now, iterate over frequency array & do sum of combination(f,2) for all frequency which are greater than 2
        i.e        ans += fC2      (fC2 = combination(frequency,2))    
        where      f >= 2
*/