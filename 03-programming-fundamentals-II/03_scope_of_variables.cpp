/*
    Scope -> defined for variable (accessibile)
    
    Two type of scope in c++:-
    - Local Scope (inside  curly brackets {})
    - Global Scope

*/

#include <iostream>
using namespace std;

// Global Scope
int var = 100;

int main(){
    // Local Scope
    int var = 10;
    cout<<var<<endl;

    for (int var=0; var<=5; var++){
        cout<<"Loop Scope - "<<var<<endl;
    }

    // both local and global value of var
    cout<<"Local var - "<<var<<endl;       // local var
    cout<<"Global var - "<< ::var<< endl;  // global var
    return 0;
}