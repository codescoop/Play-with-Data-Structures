/*
    Staircase Search
    Search row-wise & column-wise in sorted array.
*/

#include <iostream>
using namespace std;

void staircase_search(int arr[][100], int rowSize, int colSize, int key){
    int rowStart = 0;
    int colEnd = colSize-1;
    bool success  = false;
    // search value
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
    // print result
    if(success){
        cout << "Values found at Index: " << rowStart <<"," << colEnd << endl;
    }else{
        cout << "Values Not Found" << endl;
    }
}

void print_array(int arr[][100], int rowSize, int colSize){
    for(int row=0; row<=rowSize-1; row++){
        for(int col=0; col<=colSize-1; col++){
            cout << arr[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


int main(){
    int arr[100][100] ={{1,4,8,10},{2,5,9,15},{6,16,18,20},{11,17,19,23}};  
    int rowSize = 4;
    int colSize = 4;

    // Display error
    print_array(arr, rowSize, colSize);    

    int key;
    cout << "Enter the search value: ";
    cin >> key;

    // search value
    staircase_search(arr, rowSize, colSize, key);

    cout << "\n";
    return 0;
}