/*
    Problem Name: Person and Magical Park

    Ram is lost in a magical park which contains N rows and M columns.
    In order to get out of park safely and return home, he needs atleast K amount of strength.
    Given a N by M pattern, your task is to find weather Ram can ever escape the park.

    Ram enters the park with strength S. 
    The park is filled with some obstacles denoted by ‘.’ , some magical beans denoted by ‘*’ and some blockades denoted as ‘#’. 
    If he encounters an obstacle (.) , strength decreases by 2. 
    If he encounters a magic bean (' * ') , his strength increases by 5. 
    Ram can only walk row wise, so he starts from left of a row and moves towards right and he does this for every row. 
    However when he encounters a blockade (#) ,he cannot go any further in his current row and 
    simply jumps to the start of a new line without losing any strength. 
    Ram requires a strength of 1 for every step. 
    His strength should always be greater than K while traversing or else Ram will get lost. 
    Assume that Ram can shift immediately from last of one row to the start of next one without loss of any strength, 
    help out Ram to escape the park. 
    His escape is successful if he is able to return home with atleast K strength.
    
    Input Format: First line of input contains four integers – N,M,K and S. 
                  Next N lines contains M space separated characters which can be '.', '*' or '#'.

    Constraints: 1 <= N,M,K,S <= 100

    Output Format: Print "Yes" or "No" depending on whether Ram can escape or not. 
                   If the answer is "Yes", also print the amount of strength he escaped with.

    Sample Input: 4 4 5 20
                  . . * .
                  . # . .
                  * * . .
                  . # * *

    Sample Output:  Yes
                    13

    Explanation: 

    Ram starts with strength S=20.
    For first row, he encounters a obstacle ‘.’ and his strength reduces by 3 ( 2+1 ( 1 for taking the step) ). 
    Similarly after the second obstacle , his strength reduces by 3 again and becomes S=14. 
    Then he encounters a '*' , and his strength increases by 5 but decreases by 1 for taking the step. 
    Then his strength reduces by 2 (Not 3 as he will jump with no extra strength from here) after the last '.' . 
    At the end of the first row his strength is S=16.

    In the second row, he encounters a ‘.’ and his strength reduces by 3( 2+1 for the '.' ). 
    Then he encounters a '#' and without losing any extra strength simply jumps to the first cell of the next row.
    Similarly, his strength at the beginning of the third row is 13 and after completing it, his strength is 16.
    In the fourth row, he first encounters a '.' and his strength reduces to 13. 
    Then he encounters a '#' at the second position and jumps to the next row. 
    Since this is the last row, when he jumps he escapes from the park .
    His strength left is 13. Since this is clearly greater than K=5, his escape was successful.
    Ram escaped with final strength = 13.
*/

#include <iostream>
#include <string>
using namespace std;

void solvePuzzle(char **path, int rows, int cols, int strength, int power)
{
    for(int row=0; row<=rows-1; row++){
        if(power < strength){
            break;
        }
        for(int col=0; col<=cols-1; col++){
            int val = path[row][col];
            if(power < strength){
                break;
            }
            if(val == '.'){ 
                power -= 2;    // -2
            }else if( val == '*'){
                power += 5;    // +5
            }else if(val == '#'){
                break;         // take jump
            }
            // All cols except the last one
            if(col != cols-1){
                power--;           // -1 for taking every step
            }
            
        }
    }
    // Display result
if(power > strength){
        cout << "Yes" << endl << power; 
    }else{
        cout << "No";
    }
}

int main()
{
    int rows, cols , strength, power;
    cout << "Enter Row, Col, Strength & Power: ";
    cin >> rows >> cols >> strength >> power;

    // allocate memory
    char **path = new char*[rows];
    for(int row=0; row<=rows-1; row++){
        path[row] = new char[cols];
    }

    // taking path input
    cout << "Enter row & col values: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> path[row] [col];
        }
    }

    // find result
    solvePuzzle(path, rows, cols, strength, power);
    cout << endl;

    return 0;
}

/* 
Some Points to ponder before discussing the Solution :

    * Start from the 0-0 index of the 2 - D matrix 
      (No step would be count hence, strength remain intact).
    * Changing row won't take any strength.
    * If at any time, the Strength become smaller than K (threshold for piyush), 
      then no need to traverse rest of the array, you can say no nothing else.

Algorithm:

    * Take input N, M, K, S.
    * Take input 2 - D matrix of size N x M.
    * Put a loop on the array starting from 0 - 0 index to (N - 1) - (M - 1).
    * check if the Strength is lower than the threshold viz, K, print "No" and return.
    * otherwise,
        1. if character is '*', add 5 to the strength.
        2. else if, character is '.' , subtract 2 from the strength.
        3. else, if character is '#', break.
    * If you are not in the last column, decrement strength by 1.
    * After the loop, print 'Yes' and strength separated by a new line.
*/