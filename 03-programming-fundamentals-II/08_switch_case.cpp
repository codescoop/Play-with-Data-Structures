/*
    Design a menu - where pressing a button gives you corresponding item
    B - Burger
    M - Maggi
    P - Pizza
    C - Coke
    D - Dosa
    .
    .
    and so on!
*/

#include <iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter you option: ";
    cin>>ch;

    switch(ch){
        case 'b':
        case 'B': cout<<"Burger"<<endl;
            break;

        case 'm':
        case 'M': cout<<"Maggi"<<endl;
            break;

        case 'p':
        case 'P': cout<<"Pizza"<<endl;
            break;

        default: cout<<"Item not available!"<<endl;
    }

    return 0;
}