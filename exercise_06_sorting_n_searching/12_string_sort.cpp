/* 
    Problem - String Sort

    Varun is a very naughty boy in C++ Batch. One day he was playing with strings, and
    randomly shuffled them all. Your task is to help Varun Sort all the strings ( lexicographically )
    but if a string is present completely as a prefix in another string, then string with longer length
    should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in 
    Batman - then sorted order should have - Batman, bat.

    Input Format:  N(integer) followed by N strings.

    Constraints:   N<=1000

    Output Format: N lines each containing one string.

    Sample Input:   3
                    bat
                    apple
                    batman

    Sample Output:  apple
                    batman
                    bat

    Explanation:   In mathematics, the lexicographic or lexicographical order (also known as lexical order,
                   dictionary order, alphabetical order or lexicographic(al) product) is a generalization
                   of the way words are alphabetically ordered based on the alphabetical order of their
                   component letters.

    
*/

#include <iostream>
#include <algorithm>
using namespace std;


bool compare(string s1, string s2)
{
    // if any string is prefix-substring of another-string, then sort in decending order
    if(s1.find(s2) == 0 || s2.find(s1) == 0)
    {
        return s1>s2;      // decending order
    }
    return s1<s2;          // asending order
}

// function to drive code
int main()
{
    int size;
    cout << "Enter string size: ";
    cin >> size;

    string str[size];
    cout << "Enter your strings: ";
    for(int idx=0; idx<=size-1; idx++)
    {
        cin >> str[idx];
    }

    // sorting stirng in lexicographical order
    sort(str, str+size, compare);

    cout << "Sorted Strings: \n";
    for(int idx=0; idx<=size-1; idx++)
    {
        cout << str[idx] << endl;
    }

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter string size  : 3

    Enter your strings : bat apple batman batm btw mango appy

    Sorted Strings:
    apple
    batman
    bat

Case 2:
    Enter string size  : 7

    Enter your strings : bat apple batman batm btw mango appy 

    Sorted Strings:
    apple
    appy
    batman
    batm
    bat
    btw
    mango



CODE:

    Program for lexographical order of strings is given below :


    #include <iostream>
    #include <algorithm>
    using namespace std;

    int compareTo(string s1, string s2) 
    {
            int i = 0;      

            while (i < s1.length() && i < s2.length()) 
            {
                if (s1[i] > s2[i]) 
                {
                    return 1;
                } 
                else if (s1[i] < s2[i]) 
                {
                    return -1;
                }
                i++;
            }

            if (s1.length() > s2.length()) 
            {
                return -1;
            } 
            else {
                return 1;
            }
        }

    void sortfunc(string str[], int n) 
    {
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n - i - 1; j++) 
                {
                    if (compareTo(str[j], str[j + 1]) > 0) 
                    {
                        // swap string
                        string temp = str[j];
                        str[j] = str[j + 1];
                        str[j + 1] = temp;
                    }
                }
            }
        }


    int main() 
    {
        int n;
        cin>>n;

        string* str = new string[n];
        cin.ignore();

        for(int i=0;i<n;i++)
        {   
            cin>>str[i];
        }

        sortfunc(str, n);

        for(int i=0;i<n;i++)
        {
            cout<<str[i]<<endl;
        }
    }


 */