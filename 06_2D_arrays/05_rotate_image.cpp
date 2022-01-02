/*
    Rotate Image
    - Given a 2D array of size NxN, Rotate the array 90 degrees anti-clockwise. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int arr[][1000], int rows, int cols){
    // reverse each row
    for(int row=0; row<=rows-1; row++){
        int start_col = 0;
        int end_col =  cols-1;
        while(start_col<end_col){
            swap(arr[row][start_col], arr[row][end_col]);
            start_col++;
            end_col--;
        }
    }
    // transpose
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            if(row<col){
                swap(arr[row][col],arr[col][row]);
            }
        }
        cout << " ";
    }
    
}

void rotate_stl(int arr[][1000],int rows,int cols){
    // reverse using STL (Standard Template Library) >> reverse(start_container,end_container)
    for(int row=0; row<=rows-1; row++){
        reverse(arr[row], arr[row]+cols);
    }
    // transpose
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            if(row<col){
                swap(arr[row][col],arr[col][row]);
            }
        }
        cout << " ";
    }
    cout << endl;
}



int main(){
    int arr[1000][1000] = {0};
    
    int rows, cols;
    cout << "Enter Rows & Cols: ";
    cin >> rows >> cols;
    
    int val = 1;
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            arr[row][col] = val++;
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    // rotate(arr, rows, cols);
    rotate_stl(arr, rows, cols);

    // display output
    cout << "After rotating 90 degree anticlockwise: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/* 
OUTPUT:

    Enter Rows & Cols: 4 4
     1  2  3  4 
     5  6  7  8 
     9 10 11 12 
    13 14 15 16 
        
    After rotating 90 degree anticlockwise: 
    4 8 12 16 
    3 7 11 15 
    2 6 10 14 
    1 5  9 13 
*/