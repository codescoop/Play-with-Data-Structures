/*
    ABCD Pattern Function
    
    Print the following pattern for given N=5
        ABCDE
        ABCD
        ABC
        AB
        A
*/

#include <iostream>
using namespace std;

void printABCDPattern(int total_rows)
{
    // int alphabet_count = total_rows;
    for (int row = 1; row <= total_rows; row++)
    {
        int alphabet_count = total_rows - row + 1;
        char alphabet = 'A';
        for (int col = 1; col <= alphabet_count; col++)
        {
            cout << alphabet;
            alphabet++;
        }
        // alphabet_count--;
        cout << endl;
    }
}

int main()
{
    int rows;
    cout << "Enter the number of rows for ABCD Pattern: ";
    cin >> rows;
    printABCDPattern(rows);
    return 0;
}
