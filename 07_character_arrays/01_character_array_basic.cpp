/*
    Character Array Basic
*/

#include <iostream>
using namespace std;


int main(){
    int a[] = {1,2,3};                          // Interger Array
    cout << "int 'a': " << a << endl;
    // we get starting of address (Default behaviour of any array)

    char b[] = {'a','b','c','d','e','\0'};      // Character Array
    cout << "char 'b': " << b << "\n\n";
    // we get the content's of the array. It prints character unless it find a '\0' (NULL) character. 
    // (Special behaviour) Because of Operator Overloading - "cout" when used with "<<" left shift operator with "charactr array"

    

    // Input
    char s1[] = {'h','e','l','l','o'};   // doesn't  terminated with NULL. (So, it can return return Garbage after printing "hello")
    char s2[] = "hello";                 // another way                    (Null character added automatically)

    cout << "s1: " << s1 << " | SIZE: " << sizeof(s1) << endl;       // 5 bytes
    cout << "s2: " << s2 << " | SIZE: " << sizeof(s2) << "\n\n";     // 6 bytes



    char s3[10] = "bye";       // atmost 10 characters
    cout << "s3: " << s3 << endl;

    char s4[10];
    cout << "Enter your characters: ";
    cin >> s4;               // Instead of Loop we can directly use cin. Also, remember null character is automatically added.
    cout << "s4: " << s4 << endl;

    return 0;
}