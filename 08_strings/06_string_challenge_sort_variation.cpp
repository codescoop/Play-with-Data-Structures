/* 
    Solving a string challenge
    - Implement a variation of sort command.
      Given a list of 'n' strings s0,s1,s2 ... sn-1, each consisting of numbers & spaces for each entry.
      Numbers & Spaces are same for each entry.
      None  of the string contains consequetive spaces & space are to divide string in columns.
      The program has to support the required patterns:-
        key              : integer denoting the column used as a column. The left most column is denoted by 1.
        reversed         : boolean variable indicating whether to reverse the string
        comparision-type : lexicographic (eg: 122<13) or numeric (eg: 13<122)
    
    Sample Input: 3
                  92 022
                  82 12
                  77 13
                  2 false numeric
    
    Sample Output: 82 12
                   77 13
                   92 022
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string extractStringAtKey(string str, int key){
    char *c = strtok((char *)str.c_str(), " ");
    while(key>1){
        c = strtok(NULL, " ");
        key--;
    }
    return (string)c;
}

int convertToInt(string s){
    int ans = 0;
    int pow = 1;
    for(int idx=s.length()-1; idx>=0 ; idx--){
        ans += ((s[idx]-'0')*pow);              //Eg: char('5')-char('0') = Int(5)   // Ascii'5'(i.e 53) - Ascii'0'(i.e 48) = 53-48 =5
        pow *= 10;
    }
    return ans;
}

bool numericCompare(pair<string,string> s1,pair<string,string> s2){
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair<string,string> s1,pair<string,string> s2){
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return key1 < key2;
}

int main(){
    int totalStr;
    cout << "Enter total no of strings: ";
    cin >> totalStr;
    cin.get();          // to consume "\n"

    string str[100];
    cout << "Enter strings (Eg: 28 12 89): \n";
    for(int seq=0; seq<=totalStr-1; seq++){
        getline(cin,str[seq]);
    }

    int key;
    string reversal;
    string comparisonType;
    cout << "Enter column number for sorting: ";
    cin >> key;
    cout << "Want to Reverse string (true/false): ";
    cin >> reversal;
    cout << "Enter Comparision Type (numeric/lexicographic): ";
    cin >> comparisonType;
    
    // Pair Container
    pair<string,string> strPair[100]; 

    // first step - extract column by tokenization
    for(int seq=0; seq<=totalStr-1; seq++){
        strPair[seq].first = str[seq];
        strPair[seq].second = extractStringAtKey(str[seq],key);
    }

    // second step - sorting
    if(comparisonType == "numeric"){
        sort(strPair, strPair+totalStr, numericCompare);
    }else{
        sort(strPair, strPair+totalStr, lexicoCompare);
    }

    // third step - reversal
    if(reversal == "true"){
        for(int idx=0; idx<(totalStr/2); idx++){
            swap(strPair[idx], strPair[totalStr-1-idx]);
        }
    }

    // print final values
    cout << "\nAfter sorting: " << endl;
    for(int seq=0; seq<=totalStr-1; seq++){
        cout << strPair[seq].first << endl;;
    }
    
    return 0;
}

/* 
OUTPUT:
Case1:
    Enter total no of strings: 3

    Enter strings (Eg: 28 12 89): 
    28 12 899 44
    17 65 456 78
    56 71 598 12

    Enter column number for sorting: 3
    Want to Reverse string (true/false): false
    Enter Comparision Type (numeric/lexicographic): numeric

    After sorting: 
    17 65 456 78
    56 71 598 12
    28 12 899 44

Case2:
    Enter total no of strings: 4

    Enter strings (Eg: 28 12 89): 
    17 65
    44 56
    32 47
    88 05

    Enter column number for sorting: 1
    Want to Reverse string (true/false): true
    Enter Comparision Type (numeric/lexicographic): numeric

    After sorting: 
    88 05
    44 56
    32 47
    17 65

Case3:
    Enter total no of strings: 3

    Enter strings (Eg: 28 12 89): 
    121 45
    129 68
    120 48
    
    Enter column number for sorting: 1
    Want to Reverse string (true/false): false
    Enter Comparision Type (numeric/lexicographic): lexicographic

    After sorting: 
    120 48
    121 45
    129 68
*/