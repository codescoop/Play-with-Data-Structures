/*
    Problem Name: Find CSD Number

    Deepak and Gautam are having a discussion on a new type of number that they call Code Scoop Number or CSD Number. 

    They use following criteria to define a CSD Number.
    1.  0 and 1 are not a CSD number.
    2.  2,3,5,7,11,13,17,19,23,29 are CSD numbers.
    3.  Any number not divisible by the numbers in point 2( Given above) are also CSD numbers.
    
    Deepak said he loved CSD numbers. Hearing it, Gautam throws a challenge to him.
    Gautam will give Deepak a string of digits. 
    Deepak's task is to find the number of CSD numbers in the string.

    CSD number once detected should not be sub-string or super-string of any other CSD number.
    Ex- In 4991, both 499 and 991 are CSD numbers but you can choose either 499 or 991, not both.

    Further, the CSD number formed can only be a sub-string of the string.
    Ex - In 481, you can not take 41 as CSD number because 41 is not a sub-string of 481.

    As there can be multiple solutions, Gautam asks Deepak to find the maximum number of CSD numbers
    that can be formed from the given string. Now, help Deepak by solving Gautam's challenge.
        
    Input Format: First line contain size of the string.
                  Next line is A string of digits.

    Constraints: 1 <= Length of strings of digits <= 17

    Output Format: Maximum number of CSD numbers that can be formed.

    Sample Input: 5
                  81615

    Sample Output: 2

    Explanation: 61 and 5 are two CSD numbers.
*/

#include <iostream>
#include <algorithm>
#include <string>
#define MAX 2000
using namespace std;

// comparator function
bool sortOrder(int a, int b){
    return a>b;
}

// check if number is CSD number
bool isCSDNumber(int num){
    if(num == 0 || num==1){
        return false;
    }
    int i=2;
    while(i <= num-1){
        if(num%i == 0){
            return false;
        }
        i++;
    }
    return true;
}

// funtion to get all sub arrays
int getSubArrays(int arr[], int size, int subArray[]){
    int count=0;
    for(int i=0; i<=size-1; i++){
        for(int j=i; j<=size-1; j++){
            int num = 0;
            int pow = 10;   
            // number from sub-string
            for(int k=i; k<=j; k++){
                num = (num*pow) + (arr[k]); 
            }
            subArray[count++] = num;
        }
    }
    return count;
}

// convert number into array
int addNumToArr(int arr[], int inpNum){
    // calculate total digits;
    int num = inpNum;
    int size = 0;
    while(num){
        size++;
        num /= 10;
    }
    // add values in array
    for(int idx=size-1; idx>=0; idx--){
        arr[idx] = inpNum%10;
        inpNum /= 10;
    }
    return size;
}


// funtion to find total CSD Number
void maxCSD(string s, int size)
{   
    int numArr[MAX];
    int subArrays[MAX];
    int allPossibleCSD[MAX];
    int count = 0;
    
    // convert string int numberai array
    addNumToArr(numArr, stoi(s));


    // store all sub-string numeric values in a array
    size = getSubArrays(numArr, size, subArrays);
    
    // all possible csd & increment count
    for(int idx=0; idx<=size-1; idx++){
        if(isCSDNumber(subArrays[idx])){
            allPossibleCSD[count] = subArrays[idx];
            count++;
        }
    }

    // sort in descreasing order
    sort(allPossibleCSD, allPossibleCSD+count, sortOrder);

    int maxCSD = count;

    // check CSD should not be sub-string or super-string of any other CSD number.
    for(int i=0; i<=count-1; i++)
    {
        //convert possible CSD numeric values into array
        size = addNumToArr(numArr, allPossibleCSD[i]);
        // get sub-string for ever csd number
        size = getSubArrays(numArr, size, subArrays);
        // compare substring with other CSD numbers
        for(int j=0; j<=size-1; j++)
        {
            for(int k=i+1; k<=count-1; k++){
                int compare = subArrays[j];
                if(allPossibleCSD[j] == compare){
                    maxCSD--;
                }
            }
        }
    }
    cout << "Total CSD Numbers: ";
    cout << maxCSD;
}



// function to drive code
int main()
{
    int size;
    cout << "Enter string size: ";
    cin >> size;
    // cout << isCSDNumber(size);

    string str;
    cout << "Enter your string: ";
    cin >> str;

    // max csd numbers that can be formed
    maxCSD(str, size);
    cout << endl;

    return 0;
}

/*

Approach:

    According to the Problem the work is to find the Max CB numbers from the given number.

    As to work on substrings of the given number, we will capture the element into the String instead of integer .
    The number 'n' given is nothing to do with our approach(as we are working on String) but can be useful acoording to your approach.
    Intuition :
    Put loop on string that will give substring of every length.
    create a function that will return true if the passed number is a CB number otherwise return false.
    To put a check if the digit is already a part of the any other CB number, create an boolean array say, valid which store which digits till now has been a part of any other CB number.
    Take a counter and increment if a CB number is found.
    At the end print the count.

Code:

    #include <iostream>
    #include <bits/stdc++.h>

    using namespace std;

    long stoint(string s)
    {
        long i,j=0;
        i = 0;
        while(s[j] >= '0' && s[j] <= '9')
        {
            i = i * 10 + (s[j] - '0');
            j++;
        }
        return i;
    }

    bool is_cb_number(string s)
    {
        long long num = stoint(s);
        if (num == 0 || num == 1) {
            return false;
        }
        int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

            for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
                if (num == arr[i]) {
                    return true;
                }
            }

            for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
                if (num % arr[i] == 0) {
                    return false;
                }
            }

        return true;
    }

    bool is_valid(bool * visited, int l, int r)
    {
        for(int i=l;i<r;i++)
        {
            if(visited[i])
            {
                return false;
            }
        }
        return true;
    }

    int main()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        long count = 0;
        bool* visited = new bool[n];
    for(int i=0; i<s.length(); i++)
        {
            visited[i]=false;
        }
        for(int i=1; i <= s.length(); i++)
        {
            for(int j=0; j<=s.length()-i; j++)
            {   int e = j+i;
                string sub = s.substr(j, e-j);
                if(is_cb_number(sub) && is_valid(visited,j,e))
                {
                    count++;
                    for(int k=j;k<e;k++)
                    {
                        visited[k]=true;
                    }
                }
            }
        }
        cout<<count<<endl;
        return 0;
    }

*/