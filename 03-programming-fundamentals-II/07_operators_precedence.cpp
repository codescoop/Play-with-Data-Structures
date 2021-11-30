/*
    Write a program to calculate digits, whitespaces,alphabets & other characters terminated by $.
*/

#include <iostream>
using namespace std;

int main(){
    int digits=0;
    int alphabets=0;
    int spaces=0;
    int other=0;

    char ch;
    cout<<"Enter you characters :";
    ch = cin.get();         // Note: If you want to read spaces then use cin.get() 
    // cin>>ch;

    while(ch!='$'){
        if(ch>='0' and ch<='9'){
            digits++;
        }
        else if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z')){
            alphabets++;
        }
        else if(ch==' ' or ch=='\n' or ch=='\t'){
            spaces++;
        }
        else{
            other++;
        }
        ch = cin.get();         // Note: If you want to read spaces then use cin.get() 
        // cin>>ch;
    }
    
cout<<"Digits :"<<digits<<endl;
cout<<"Alphabets :"<<alphabets<<endl;
cout<<"Spaces :"<<spaces<<endl;
cout<<"Other :"<<other<<endl;

    return 0;
}