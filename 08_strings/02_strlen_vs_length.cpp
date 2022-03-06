/* 
    Different methods to find length using sizeof() | strlen() | length() | size()

    - Using sizeof() Function
      sizeof(variable)/sizeof(datatype) : It's output will be total number of varaiable(int, char, string, etc)

    - Using strlen(const char *str) Function
      strlen(charArr) : This function returns length of character array. (#include <cstring>)
                        Remember It does not including the terminating null character.
    
    - Using string::length Method
      str.length() : This method returns length of string object (in terms of bytes)
    
    - Using string::size Method
      str.size()   : This method returns length of string object (& STL containers like vector, map, etc,) in terms of bytes.

    NOTE: Both string::size and string::length are synonyms and return the exact same value.
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int arr[] = {1,2,3};
    char ch1[] = {'h','i','\0'};
    char ch2[] = "hi";
    string s1(ch1);
    string s2(ch2);
    string s3("hi");


    cout << "arr: " ;
    for(auto i:arr){                       // for each loop
        cout << i;                         // 123
    }
    cout << endl;

    cout << "ch1: " << ch1 << endl;        // hi
    cout << "ch2: " << ch2 << endl;        // hi
    cout << "s1: " << s1 << endl;          // hi
    cout << "s2: " << s1 << endl;          // hi
    cout << "s3: " << s1 << endl;          // hi
    cout << endl;

    // sizeof(variable)/sizeof(datatype)
    cout << "sizeof(arr)/sizeof(int): " << sizeof(arr)/sizeof(arr[0]) << endl;   // 3 (for int)
    cout << "sizeof() ch1: " << sizeof(ch1)/sizeof(char) << endl;                // 3 (for character)
    cout << "sizeof() ch2: " << sizeof(ch2)/sizeof(ch2[0]) << endl;              // 3 (for character)

    // strlen(const char *str): It does not including the terminating null character
    cout << "strlen(ch2): " << strlen(ch2) << endl;                              // 2 (for character)
    cout << "strlen(ch1): " << strlen(ch1) << endl;                              // 2 (for character)
    cout << "strlen(s1.c_str()): " << strlen(s1.c_str()) << endl;                // 2 (for string.c_str())

    // str.length()
    cout << "s1.length(): " << s1.length() << endl;                              // 2 (for string)
    
    // str.size()
    cout << "s1.size(): " << s1.size() << endl;                                  // 2 (for string)

    return 0;
}

/* 
OUTPUT:
    arr: 123
    ch1: hi
    ch2: hi
    s1: hi
    s2: hi
    s3: hi

    sizeof(arr)/sizeof(int) : 3
    sizeof() ch1            : 3
    sizeof() ch2            : 3

    strlen(ch2)             : 2
    strlen(ch1)             : 2
    strlen(s1.c_str())      : 2

    s1.length()             : 2
    
    s1.size()               : 2
 */