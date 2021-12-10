/* 
    Designing String Tokeniser
*/

#include <iostream>
#include <cstring>
using namespace std;

// Function accepts string & single character act as delimiter
char *mystrtok(char *str, char delim)
{
    // state of static variable is initalize only once in a function call &
    // in every subsequent call it will the same state as in the previous call.
    static char*input = NULL;

    // we are making the first call
    if(str != NULL){
        input = str;
    }

    //checkhere - base case after the final token has been returned
    if(input == NULL){
        return NULL;
    }

    // start extracting tokens & store them in an array
    char *output = new char(strlen(input)+1);
    int i=0;
    for( ;input[i] != '\0'; i++){
        if(input[i] !=  delim){
            output[i] = input[i];
        }else{
            output[i] = '\0';
            input = input + i+1;
            return output;
        }
    }

    // corner case (i.e last entry)
    output[i] = '\0';
    input = NULL;
    return output;
}

int main(){
    char s1[100] = "Have a nice day" ;
    char *ptr = mystrtok(s1,' ');
    cout << ptr << endl;
    while(ptr != NULL){
        ptr = mystrtok(NULL,' ');
        cout << ptr << endl;
    }
    return 0;
}