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
    cout << "Spiral Pattern: \n";
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
        // Note: We are not using this condition in the beginning (i.e while loop) bcz it will skip some rows in the ODD case.
        if(startRow<endRow){                     
            for(int i=endCol; i>=startCol; i--){
                cout << arr[endRow][i] << " ";
            }
            endRow--;
            cout << " ";
        }
        
        // 4. First Col
        // Note: We are not using this condition in the beginning (i.e while loop) bcz it will skip some cols in the ODD case.
        if(startCol<endCol){
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
