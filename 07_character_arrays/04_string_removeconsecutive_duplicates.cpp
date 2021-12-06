/*
    Remove consecutive duplicate characters from a string.
    eg: INPUT: cccooding 
        OUTPUT: coding
*/

#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicate(char arr[]){
    int len = strlen(arr);
    if(len <= 1){
        return;
    }
    int prev=0;
    for(int current=1; current<=len-1; current++){
        if(arr[prev] != arr[current]){
            prev++;
            arr[prev] = arr[current];
        }
    }
    arr[prev+1] = '\0';
    return;
}

int main(){
    char arr[1000];
    cout << "Enter your string: ";
    cin.getline(arr, 1000);

    removeDuplicate(arr);
    cout << arr << endl;
    return 0;
}