/*
    Staircase Search
    (Search element in a row-wise & column-wise sorted array)
*/

#include <iostream>
using namespace std;

// function to search element in row-wise  & col-wise sorted array
void staircase_search(int arr[][100], int rowSize, int colSize, int key){
    int rowStart = 0;
    int colEnd = colSize-1;
    bool success  = false;

    while(rowStart <= rowSize-1 && colEnd >= 0){
        if(key == arr[rowStart][colEnd]){
            success = true;
            break;
        }else if(key > arr[rowStart][colEnd]){
            rowStart++;
        }else{
            colEnd--;
        }
    }
    if(success){
        cout << "Values found at Index: " << rowStart <<"," << colEnd << endl;
    }else{
        cout << "Values Not Found" << endl;
    }
}

// function to print array
void print_array(int arr[][100], int rowSize, int colSize){
    for(int row=0; row<=rowSize-1; row++){
        for(int col=0; col<=colSize-1; col++){
            cout << arr[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// function to drive code
int main(){
    int arr[100][100] ={{1,4,8,10},{2,5,9,15},{6,16,18,20},{11,17,19,23}};  
    int rowSize = 4;
    int colSize = 4;

    // display array
    print_array(arr, rowSize, colSize);    

    int key;
    cout << "Enter the search value: ";
    cin >> key;

    // search value
    staircase_search(arr, rowSize, colSize, key);

    return 0;
}

/* 
OUTPUT:

Case1:
     1  4  8 10 
     2  5  9 15 
     6 16 18 20 
    11 17 19 23 

    Enter the search value: 16
    Values found at Index: 2,1

Case2:
     1  4  8 10 
     2  5  9 15 
     6 16 18 20 
    11 17 19 23 

    Enter the search value: 33
    Values Not Found
*/