/*
    Problem Name: String - Max Frequency Character

    Take as input S, a string. Write a function that returns the character with maximum frequency. 
    Print the value returned.

    Input Format: String

    Constraints: A string of length between 1 to 1000.

    Output Format: Character

    Sample Input: aaabacb

    Sample Output: a

    Explanation: For the given input string, a appear 4 times. Hence, it is the most frequent character.
*/

#include <iostream>
using namespace std;

int main() {
    string s1;
    cout << "Enter string: ";
    cin >> s1;

    int len = s1.length();

    char ch[len];                      // character array to track character
    int freq[len] = {0};               // array to count frequency

    ch[0] = s1[0];
    freq[0] = 1;                    
    int index = 1;
    
    for(int i=1; i<=len-1; i++){
        bool isFound = false;
        for(int j=0; j<=index-1; j++){
            if(s1[i]==ch[j]){
                freq[j] += 1;         // counting charcter frequency
                isFound = true;
                break;
            }
        }
        if(!isFound){                  // update new charcter in ch[]
            ch[index] = s1[i];
            freq[index] += 1;
            index++;
        }
    }
    
    int max = -1;
    int pos = -1;
    for(int i=0; i<=index-1; i++){
        // cout << "Char: " << ch[i] << " | " << freq[i] << endl; 
        if(freq[i] > max){
            max = freq[i];
            pos = i;
        }
    }

    cout << "Output: " << ch[pos];
    cout << endl;
	return 0;
}


/* 

Algo
    1.Declare an Array of 26 size to store the Freq of each character.
    2.Each time any character is encountered increment its corresponding freq at that index. 
    3.Declare a max variable and put a loop on filled array. 
    4.Update the max and character accordingly.

Lang - Cpp
    
    #include <iostream>
    using namespace std;
    int main() {
        char str[1000];
        int freq[256] = {0};                  // character range is upto 256 

        cout << "Enter String: ";
        cin>>str;

        for(int x=0;str[x]!='\0';x++){
            freq[str[x]]++;            //Updating index of freq[] at its character ASCII value 
        }
        int ans=0;
        char ch;
        for(int x=0;x<256;x++){
            if(freq[x]>0){
                if(freq[x]>ans){
                    ans=freq[x];
                    ch=char(x);
                }
            }
        }
        cout<<ch;
    }

Lang - Java

    public static char maxFreq(String str){
            char[] charray = new char[26]; // To store freq of each character
            for(int i = 0;i < str.length();i++){  
                charray[str.charAt(i) - 'a']++; //Updating freq each time
            }
            int max = 0;
            char ch = 'a';
            for(int i = 0;i < 26;i++){
                if(max <= charray[i]){ //Choosing max Freq Character
                    max = charray[i];
                    ch = (char)(i + 'a');
                }
            }
            return ch; // return character
        }

*/