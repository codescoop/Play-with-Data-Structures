/*
    Person with Magical Park:
    - Provided:  s - strength
                 k - minimum strength person should have
    - Rules:     .     - It reduces strength by 2
                 *     - It increase strength by 5
                 #     - Blocked. It move you to next row without lose of strength
                 move  - For every move strength reduce by 1 
    
    Print "Yes" or "No" depending on whether Ram can escape or not. 
    If the answer is "Yes", also print the amount of strength he escaped with.
*/

#include <iostream>
using namespace std;

int main(){
    char arr[1000][1000] = {0};
    
    int rows, cols;
    cout << "Enter Rows & Cols: ";
    cin >> rows >> cols;
    
    int k, s;
    cout << "Provide Minimum & Initial Strength: ";
    cin >> k >> s;
    
    cout << "Provide Magical Park path: ";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> arr[row][col];
        }
    }

    cout << "Magical Park: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    // Magical Park Problem
    for(int row=0; row<=rows-1; row++){
        if(s < k){
            break;
        }
        for(int col=0; col<=cols-1; col++){
            if(s < k){
               break;
            }
            char val = arr[row][col]; 
            if (val == '.'){
                s -= 2;
            }else if(val == '*'){
                s += 5;
            }else if (val == '#'){
                break;
            }
            // for next move we lose 1 point except the last column 
            if (col != cols-1){
                s--;
            }
        }
    }

    if(s>k){
        cout << "Yes \nStrenght: " << s << endl;
    }else{
        cout << "No \nStrenght: " << s << endl;
    }

    return 0;
}

/* 
OUTPUT:

Case1:
    Enter Rows & Cols: 4 4
    Provide Minimum & Initial Strength: 5 20
    Provide Magical Park path:  . . * . . # . . * * . . . # * *
    
    Magical Park: 
    . . * . 
    . # . . 
    * * . . 
    . # * * 
    Yes
    Strenght: 13

Case2: 
    Enter Rows & Cols: 4 4
    Provide Minimum & Initial Strength: 5 20
    Provide Magical Park path: . . . # . . . # . . . # . * . .
    
    Magical Park: 
    . . . # 
    . . . # 
    . . . # 
    . * . . 
    No 
    Strenght: 2
*/