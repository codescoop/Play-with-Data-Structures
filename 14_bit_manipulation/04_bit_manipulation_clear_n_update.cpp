/*
    Topic: Bit Manipulation - Clear & Update Bits

    Bitwise Operations
    - Clear the i-th bit
      (Given a number n, clear a particular bit in that number from the i-th position)
    - Update the i-th bit
*/

#include <iostream>
using namespace std;


// function to clear i-th bit of a given number
int clearBit(int n, int i)
{
    int mask = ~(1 << i);          // mask = ~(Left shift i bits)
    int ans = (n & mask);
    /* 
        Bitwise AND of n and mask, 
   
        Eg:   n = 5  (0101)
              i = 2
              mask = 1011      (i.e ~(0001 << 2) => ~(0100) => 1011) 

                0101     (5)
              & 1011    (mask)
              --------  
                0001     (1)
    */
    return ans;
}


// function to update i-th bit of a given number
int updateBit(int n, int i, int bit_val)
{
    int mask = ~(1 << i);         // mask = Left shift i bits
    int cleared_n = (n & mask);

    int val_mask = bit_val << i;
    int ans = cleared_n | val_mask;
    /* 
        - first clear the i-th bit
        - then  Bitwise OR of cleared_number and val_mask
   
        Eg:   n = 5  (0101)
              i = 2
              mask = 1011      (i.e ~(0001 << 2) => ~(0100) => 1011) 

                0101     (5)
              & 1011    (mask)
              --------  
                0001     (1)
        
        Now, cleared_n = 1  (0001)
             bit_val = 0
             val_mask = 0000       (i.e  (0000 << 2) => 0000) 

                0001     (cleared_n)
              | 0000    (bit_val << i)
              --------  
                0001       (1)
    */
    return ans;
}


// function to drive code
int main()
{
    int n, i;

    cout << "Enter number: ";
    cin >> n;


    // clear the i-th bit
    cout << "Clear Bit (Enter the i-th bit you want to clear): ";
    cin >> i;

    cout << "number " << n << " after clearing " << i <<"th-bit is: " << clearBit(n,i) << "\n\n";


    // Update the i-th bit
    cout << "Update Bit (Enter the i-th bit you want to update): ";
    cin >> i;
    
    int bit_val;
    cout << "Enter bit value for update: ";
    cin >> bit_val;

    cout << "number " << n << " after updating " << i <<"th-bit with " << bit_val << " is: " << updateBit(n,i, bit_val);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter number: 5

    Clear Bit (Enter the i-th bit you want to clear): 2
    number 5 after clearing 0th-bit is: 1

    Update Bit (Enter the i-th bit you want to update): 2
    Enter bit value for update: 0
    number 5 after updating 2th-bit with 0 is: 1

Case 2:
    Enter number: 5

    Clear Bit (Enter the i-th bit you want to clear): 0
    number 5 after clearing 2th-bit is: 4

    Update Bit (Enter the i-th bit you want to update): 2
    Enter bit value for update: 1
    number 5 after updating 2th-bit with 1 is: 5
*/