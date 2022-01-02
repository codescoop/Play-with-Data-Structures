// Spiral Pattern in 2D Array

#include <iostream>
using namespace std;

int main(){
    int arr[1000][1000];
    int rows, cols;
    cout << "Enter Rows & Cols: ";
    cin >> rows >> cols;

    int val=1;
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            arr[row][col] = val++;
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << "Spiral Pattern: ";
    int startRow=0;
    int startCol=0;
    int endRow=rows-1;
    int endCol=cols-1;

    while(startRow<=endRow && startCol <= endCol){
        // 1. First Row
        for(int i=startCol; i<=endCol; i++){
            cout << arr[startRow][i] << " ";
        }
        startRow++;
        cout << " ";
        
        // 2. Last Col
        for(int i=startRow; i<=endRow; i++){
            cout << arr[i][endCol] << " ";
        }
        endCol--;
        cout << " ";
        
        // 3. Last Row
        // to skip some rows in the ODD case.
        if(startRow<=endRow){
            for(int i=endCol; i>=startCol; i--){
                cout << arr[endRow][i] << " ";
            }
            endRow--;
            cout << " ";
        }
        
        // 4. First Col
        // to skip some cols in the ODD case.
        if(startCol<=endCol){
            for(int i=endRow; i>=startRow; i--){
                cout << arr[i][startCol] << " ";
            }
            startCol++;
            cout << " ";
        }
    }

    cout << "\n";
    return 0;
}

/*
OUTPUT:

Case1:
    Enter Rows & Cols: 4 4
     1  2  3  4 
     5  6  7  8 
     9 10 11 12 
    13 14 15 16 
    Spiral Pattern: 1 2 3 4   8 12 16   15 14 13   9 5   6 7   11   10 

Case2:
    Enter Rows & Cols: 3 6
     1  2  3  4  5  6 
     7  8  9 10 11 12 
    13 14 15 16 17 18 
    Spiral Pattern: 1 2 3 4 5 6   12 18   17 16 15 14 13   7   8 9 10 11
*/