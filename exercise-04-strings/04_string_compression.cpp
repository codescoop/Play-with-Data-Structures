/*
    Problem Name: String Compression

    Take as input S, a string. 
    Write a function that does basic string compression. 
    Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

    Input Format: A single String S

    Constraints: 1 < = length of String < = 1000

    Output Format: The compressed String.

    Sample Input: aaabbccds

    Sample Output: a3b2c2d1s1

    Explanation: In the given sample test case 
                 'a' is repeated 3 times consecutively, 
                 'b' is repeated twice, 
                 'c' is repeated twice and 
                 'd and 's' occurred only once.
*/

#include <iostream>
#include <string>
using namespace std;

string stringCompression(string s1){
    string output = "";
    int count = 0;
    for(int i=0; i<=s1.length()-1; i++){
        count++;
        if(s1[i]!=s1[i+1]){
            output += s1[i];                    // append string
            output += to_string(count);         // convert to string
            count = 0;
        }
    }
    return output;
}

int main(){
    string s1;
    cout << "Enter string: ";
    cin >> s1;

    cout << stringCompression(s1);
    cout << endl;

	return 0;
}

/* 
Approach
    Take the first character of the present string and store it in say 'ch'. 
    Start iterating over the string and obtain the count of this character occurring consecutively from this point.
    Obtain the answer for remaining string recursively.
    Return ch+countOfCh+recursiveResult .

C++ Code

    #include <bits/stdc++.h>
    using namespace std;

    string compress(string s)
    {
        if (s.size() == 0)
        {
            return "";
        }

        char ch = s[0];
        int i = 1;
        while (i < s.size() && s[i] == ch)
        {
            i++;
        }

        string ros = s.substr(i);
        ros = compress(ros);

        string charCount = to_string(i);
        return ch + charCount + ros;
    }

    int main()
    {
        string s;
        cin >> s;

        cout << compress(s) << endl;

        return 0;
    }

Java Code

    import java.util.*;

    public class Main {

        static String compress(String s) {
            if (s.length() == 0) {
                return "";
            }

            char ch = s.charAt(0);
            int i = 1;
            while (i < s.length() && s.charAt(i) == ch) {
                i++;
            }

            String ros = s.substring(i);
            ros = compress(ros);

            String charCount = i + "";
            return ch + charCount + ros;
        }

        public static void main(String[] args) {

            Scanner sc = new Scanner(System.in);
            String s = sc.next();

            System.out.println(compress(s));
        }
    }
*/