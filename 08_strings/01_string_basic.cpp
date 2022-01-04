/* 
    String Basic
*/

#include <iostream>
using namespace std;

int main(){

    // character array
    char c1[100] = "Hi";
    cout << "c1: " << c1 << endl;            // print value (not address)
    cout << "c1[0]: " << c1[0] << "\n";      // print character (at first index/column)
    cout << "c1[1]: " << c1[1] << "\n\n";    // print character (at second index/column)

    // string
    string s1 = "Hi";
    cout << "s1: " << s1 << endl;           // print value (not address)
    cout << "s1[0]: " << s1[0] << "\n";     // print character (at first index/column)
    cout << "s1[1]: " << s1[1] << "\n\n";   // print character (at second index/column)



    // 2D character array
    char c2[2][100] = {"Shyam","Ram Sharma"};
    cout << "c2: " << c2 << endl;              // print address
    cout << "c2[0]: " << c2[0] << endl;        // print first row
    cout << "c2[1]: " << c2[1] << endl;        // print second row
    cout << "c2[1][0]: " << c2[1][0] << endl;  // print character (at second row & first column)
    cout << "c2[1][1]: " << c2[1][1] << endl;  // print character (at second row & second column)
    cout << "c2[1][3]: " << c2[1][2] << "\n\n";  // print character (at second row & third column)

    // string
    string s2[2] = {"Shyam", "Ram Sharma"};
    cout << "s2: " << s2 << endl;              // print address
    cout << "s2[0]: " << s2[0] << endl;        // print first row
    cout << "s2[1]: " << s2[1] << endl;        // print second row
    cout << "s2[1][0]: " << s2[1][0] << endl;  // print character (at second row & first column)
    cout << "s2[1][1]: " << s2[1][1] << endl;  // print character (at second row & second column)
    cout << "s2[1][3]: " << s2[1][2] << "\n\n";  // print character (at second row & third column)


    string s3[2];                              // String declaration (2 rows)
    s3[0] = "first row";
    s3[1] = "second row";
    cout << "s3: " << s3 << endl;              // print address
    cout << "s3[0]: " << s3[0] << endl;
    cout << "s3[1]: " << s3[1] << "\n\n";


    /*  Taking User Input
    
        - cin                                  : It doesn't read spaces & newline
        - cin.get()                            : Read single character (including spaces & newline)
        - cin.getline(char* ch,int size)       : Read a line from an input stream (Syntax for Character Array)
        - getline(istream& cin, string& str)   : Read a line from an input stream (Syntax for String)
    */


    // character array
    char ch1[100];
    cout << "Enter elements for 1D character array: ";
    cin >> ch1;                                // cin doesn't read spaces & newline
    // cin.getline(ch1, 100);
    cout << ch1 << "\n\n";

    // string
    string str1;
    cout << "Enter elements for string: ";
    cin >> str1;                              // cin doesn't read spaces & newline
    // getline(cin, str1);
    cout << str1 << "\n\n";


    cin.get();                                 // to consume extra "\n"


    // 2D character array
    char ch2[10][100];                      // 2D character Array (10 Rows)
    cout << "Enter 2D character array (Row-1): ";
    cin.getline(ch2[0], 100);    
    cout << ch2[0] << endl;
    cout << "Enter 2D character array (Row-2): ";
    cin.getline(ch2[1], 100);    
    cout << ch2[1] << "\n\n";

    // string
    string str2[3];                           // string (3 Rows)
    cout << "Enter your string (Row-1): ";
    getline(cin, str2[0]);
    cout << str2[0] << endl;
    cout << "Enter your string (Row-2): ";
    getline(cin, str2[1]);
    cout << str2[1] << endl;

    return 0;
}

/* 
OUTPUT:

    c1: Hi
    c1[0]: H
    c1[1]: i

    s1: Hi
    s1[0]: H
    s1[1]: i

    c2: 0x7fff04666b20
    c2[0]: Shyam
    c2[1]: Ram Sharma
    c2[1][0]: R
    c2[1][1]: a
    c2[1][3]: m

    s2: 0x7fff04666a40
    s2[0]: Shyam
    s2[1]: Ram Sharma
    s2[1][0]: R
    s2[1][1]: a
    s2[1][3]: m

    s3: 0x7fff04666a80
    s3[0]: first row
    s3[1]: second row

    Enter elements for 1D character array: Hello
    Hello

    Enter elements for string: Hello
    Hello

    Enter 2D character array (Row-1): Ravi Sharma
    Ravi Sharma
    Enter 2D character array (Row-2): Aksh Verma
    Aksh Verma

    Enter your string (Row-1): Ravi Sharma 
    Ravi Sharma
    Enter your string (Row-2): Aksh Verma
    Aksh Verma
 */