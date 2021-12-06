/*
    Read a sentence/paragraph and store it
*/

#include <iostream>
using namespace std;

void readline(char arr[], int maxLen, char delim = '\n'){
    int itr = 0;
    char ch = cin.get();
    while(ch != delim){              // Terminating on "newline"     
        arr[itr] = ch;
        itr++;
        if(itr == maxLen-1){        // maxLen-1 because we need to add NULL character at last
            break;
        }
        ch = cin.get();
    }
    // once out of the loop
    arr[itr] = '\0';                // Adding null character at last
    return;
} 

int main(){
    char arr[1000];
    cout << "ENTER YOUR SENTENCE: ";
 
    /* reading sentence using cin */
    // cin >>  arr;                          // cin doesn't read "spaces" & "newline"


    /* reading sentence using cin.get() */
    readline(arr,1000,'\n');                // cin.get() reads single character at a time. 
                                             // So, put a loop to read charcters.


    /* reading sentence using cin.getline() */
    // cin.getline(arr,1000);  
    // cin.getline(arr,1000,'$');  

    cout << "OUTPUT: " << arr << endl;
    return 0;
}