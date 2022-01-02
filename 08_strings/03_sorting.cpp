/* 
    Sorting
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string s1, string s2){
    if(s1.length() == s2.length()){         // if length is same, then compare lexicographic
        return s1<s2;
    }
    return s1.length()<s2.length();         // comparing string lengths
}

int main(){
    int totalStr;
    cout << "Enter total number of strings: ";
    cin >> totalStr;
    cin.get(); 

    string s[100];

    cout << "Enter Strings: \n";
    for(int seq=0; seq <= totalStr-1; seq++){
        getline(cin,s[seq]);
    }

    cout << "\nAfter Sorting: " << endl;
    sort(s, s+totalStr, compare);              // sorting

    for(int seq=0; seq <= totalStr-1; seq++){
        cout << s[seq] << endl;
    }
    return 0;
}

/* 
OUTPUT:

    Enter total number of strings: 6

    Enter Strings:
        Amandeep Verma
        deep  
        aman
        Govind
        Arvind
        Bhim Gupta

    After Sorting: 
        aman
        deep
        Arvind
        Govind
        Bhim Gupta
        Amandeep Verma
*/