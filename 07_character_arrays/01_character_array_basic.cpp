/*
    Character Array Basic
*/

#include <iostream>
using namespace std;


int main(){
    int a[] = {1,2,3};                          // Interger Array
    cout << "(int) a: " << a << endl;           
    /*  we get starting of address (Default behaviour of any array) */

    char b[] = {'m','o','n','d','a','y','\0'};      // Character Array
    cout << "(char) b: " << b << "\n\n";
    /* we get the content of array 'b'. It prints character unless it find '\0' (NULL) character. 
       This special behaviour is because of Operator Overloading. 
       "cout" when used with "<<" (left shift operator) & "charactr array" 
    */
    

    // Size of character array
    char s1[] = {'h','e','l','l','o'};       // doesn't  terminated with NULL. (So, it can return return Garbage after printing "hello")
    char s2[] = {'h','e','l','l','o','\0'};  
    char s3[] = "hello";                     // another way                    (Null character added automatically)

    cout << "s1: " << s1 << " | SIZE: " << sizeof(s1) << endl;       // 5 bytes
    cout << "s2: " << s2 << " | SIZE: " << sizeof(s2) << endl;       // 6 bytes
    cout << "s3: " << s3 << " | SIZE: " << sizeof(s3) << "\n\n";     // 6 bytes


    // User Input
    char s4[10];                             // atmost 10 characters (10 bytes)
    cout << "Enter your characters: ";
    cin >> s4;               // Instead of Loop we can directly use cin. Also, remember null character is automatically added.

    cout << "s4: " << s4 << endl;
    cout << "Size: " << sizeof(s4) << endl;   // 10 bytes  (because s4[10])

    return 0;
}

/* 
OUTPUT:

    (int) a: 0x7ffdebf80418
    (char) b: monday

    s1: hellohello | SIZE: 5
    s2: hello | SIZE: 6
    s3: hello | SIZE: 6

    Enter your characters: hello
    s4: hello
    Size: 10
*/