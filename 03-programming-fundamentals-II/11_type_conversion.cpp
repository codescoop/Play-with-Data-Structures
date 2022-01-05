/* 
    TOPIC - Type Conversion

    A type cast is basically a conversion from one type to another. 
    There are two types of type conversion:
    
    1. Implicit Type Conversion 
        - Also known as ‘automatic type conversion’.
        - Done by the compiler on its own, without any external trigger from the user.
        - Generally takes place when in an expression more than one data type is present. 
          In such condition type conversion (type promotion) takes place to avoid lose of data.
        - All the data types of the variables are upgraded to the data type of the variable with 
          largest data type.
                bool -> char -> short int -> int -> 
                unsigned int -> long -> unsigned -> 
                long long -> float -> double -> long double
        - It is possible for implicit conversions to lose information, signs can be lost 
          (when signed is implicitly converted to unsigned), and overflow can occur 
          (when long long is implicitly converted to float).
    
    2. Explicit Type Conversion: 
        - This process is also called type casting and it is user-defined. 
          Here the user can typecast the result to make it of a particular data type.
        
        - In C++, it can be done by two ways:
          a. Converting by assignment: This is done by explicitly defining the required type in front of the 
                                       expression in parenthesis. This can be also considered as forceful casting.
             Syntax:  (type) expression
          
          b. Conversion using Cast operator: A Cast operator is an unary operator which forces one data 
                                             type to be converted into another data type.
             C++ supports four types of casting:
             - Static Cast          Eg:   float f = 3.5;   int b = static_cast<int>(f);
             - Dynamic Cast
             - Const Cast
             - Reinterpret Cast


    - Parse into different datatype variables:-
    
    - INT to CHAR      :    Add single digit num with '0' character
    - CHAR t INT       :    Subtract single digit num with '0' character

    - INT to STRING    :    to_string(num)
    - STRING to INT    :    stoi(str)

    - CHAR to STRING   :    append(1,ch)   or   string class   or   '+=' operator   or  '=' operator
    - STRING to CHAR   :    c_str()
                            strcpy(char_array, str.c_str())
*/

#include <iostream>
#include <cstring>
using namespace std;


int main(){

    int num, num1;
    char ch, ch1;
    string str;

    // INT to CHAR
    num = 8;
    ch = num + '0';                   // Add with '0' character

    cout << "num: " << num <<  endl;
    cout << "ch: " << ch <<  endl;
    cout << "ch is of type: " << typeid(ch).name() << "\n\n";


    // CHAR to INT
    ch1 = '8';
    num1 = ch1 - '0';                 // Subtract with '0' character

    cout << "ch1: " << ch1 <<  endl;
    cout << "num1: " << num1 <<  endl;
    cout << "num1 is of type: " << typeid(num1).name() << "\n\n";


    // INT to STRING
    num = 1526;
    str = to_string(num);              // to_string()

    cout << "num: " << num <<  endl;
    cout << "str: " << str <<  endl;
    cout << "str is of type: " << typeid(str).name() << "\n\n";


    // STRING to INT
    str = "51689";
    num = stoi(str);                   // stoi()

    cout << "str: " << str <<  endl;
    cout << "num: " << num <<  endl;
    cout << "num is of type: " << typeid(num).name() << "\n\n";


    // CHAR to STRING
    ch = 'C';
    string s, s1, s2;

    s.append(4, ch);                    // append()      - we can append n copy at the end of string
    s1 += ch;                           // += operator   - append at the last of the string
    s2 = ch;                            // = operator    - overwrite the string
    string s3(3,ch);                    /* string class  - has a constructor that allow us to specify
                                                           size of string as a parameter */
    cout << "ch: " << ch <<  endl;
    cout << "s: " << s <<  endl;
    cout << "s1: " << s1 <<  endl;
    cout << "s2: " << s2 <<  endl;
    cout << "s is of type: " << typeid(s).name() << endl;
    cout << "s1 is of type: " << typeid(s1).name() << endl;
    cout << "s2 is of type: " << typeid(s2).name() << endl;
    cout << "s3 is of type: " << typeid(s3).name() << "\n\n";


    // STRING to CHAR
    str = "125ab";
    int len = str.length();
    char c[len+1];
    strcpy(c, str.c_str());            // c_str() function return a "const pointer"

    cout << "str: " << str <<  endl;
    cout << "c[]: " << c <<  endl;
    // cout << "c is of type: " << typeid(c).name() << "\n\n";            //ERROR

    return 0;
}

/* 
OUTPUT:

    num: 8
    ch: 8
    ch is of type: c

    ch1: 8
    num1: 8
    num1 is of type: i

    num: 1526
    str: 1526
    str is of type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE

    str: 51689
    num: 51689
    num is of type: i


    ch: C
    s: CCCC
    s1: C
    s2: C
    s is of type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    s1 is of type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    s2 is of type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    s3 is of type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE


    str: 125ab
    c[]: 125ab
*/