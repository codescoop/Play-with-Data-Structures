/* 
    Address of Operator (&)
    - It is used to find address of variable
    - C++ display address in HexaDecimal format (Base 16)
*/

#include <iostream>
using namespace  std;

int main(){
    int x=10;
    cout << "[Integer] Address of x [&x]: " << &x << endl;

    float y=9.5;
    cout << "[Float] Address of y [&y]: " << &y << "\n\n";

    // It doesn't work for character variables bcz of operator overloading
    char ch = 'A';
    cout << "[Character] Address of ch [&ch]: " << ch << endl;    

    // Explicit typecasting from char* to void*
    cout << "[Character] Address of ch [(void*)&ch]: " << (void*)&ch << endl;
    return 0;
}

/* 
OUTPUT: 

    [Integer]   Address of x [&x]:             0x7ffd67f494e0
    [Float]     Address of y [&y]:             0x7ffd67f494e4
    [Character] Address of ch [&ch]:           A
    [Character] Address of ch [(void*)&ch]:    0x7ffd67f494df
*/