/*
    Problem - Read a list of characters (sentence)
    
    Concept we will learn:
    - cin vs cin.get() for input 
 
    - How the console & input buffer works:-
      "Input" in console   ->   Input Buffer    -> 
                                                    Loop 
      "Output" on console  <-   Output Buffer   <-
*/

#include <iostream>
using namespace std;

int main(){    
    char character;
    cout<<"**** Enter your Characters ****"<<endl;

    // read the first character
    character = cin.get(); // this method reads any single character including spaces/newlines from the input buffer
    // cin>>character;
    
    while(character != '.'){
        // Print the last character that we have read
        cout<<character;
        
        // Update "character" in the memory (i.e read the next character) 
        character = cin.get(); 
        // cin>>character;
    }

    return 0;
}