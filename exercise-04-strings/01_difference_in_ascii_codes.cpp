/*
    Problem Name: String - Difference in Ascii Codes

    Take as input S, a string. Write a program that inserts between each pair of 
    characters the difference between their ascii codes and print the ans.

    Input Format: String

    Constraints: Length of String should be between 2 to 1000.

    Output Format: String

    Sample Input:   acb

    Sample Output:  a2c-1b

    Explanation: For the sample case, the Ascii code of a=97 and c=99,
                 the difference between c and a is 2. Similarly,
                 the Ascii code of b=98 and c=99 and their difference is -1. 
                 So the ans is a2c-1b.
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter your string: ";
    getline(cin, s);

    cout << "Output: ";
    int end = s.length()*2;
    int idx = 0;
    for(int step=0; step<=end-2; step++){
        if(step%2 == 0){
            cout << s[idx];
            idx++;
        }else{
            cout << s[idx]-s[idx-1];
        }
    }
    cout << endl;
	return 0;
}

/* 

Approach: 

    All we need to do is just traverse the whole string and 
    for every two adjacent characters just calculate the ascii among them. 
    We will print the characters and the difference between with characters

Required Code is given below :

    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
        char str[1000];
        int nstr[2000];
        cin>>str;
        int i=1;
        cout<<str[0];
        while(str[i]!='\0'){
            nstr[i]=int(str[i])-int(str[i-1]);
            cout<<nstr[i]<<str[i];
            i++;
        }
        return 0;
    }
*/
