/*
    Topic - Tower of Hanoi (Recursion) | Classical Recursion Problem

    Tower of Hanoi is a mathematical puzzle where we have three rods and N disks. The objective of the 
    puzzle is to move the entire stack to another rod, obeying the following simple rules: 

    1. Only one disk can be moved at a time.
    2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another
       stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    3. No disk may be placed on top of a smaller disk.
    
    Print all the steps for a given disk value N.


    Eg: Input  : 2
        Output : Disk 1 moved from A to B
                 Disk 2 moved from A to C
                 Disk 1 moved from B to C
        
        Input  : 3
        Output : Disk 1 moved from A to C
                 Disk 2 moved from A to B
                 Disk 1 moved from C to B
                 Disk 3 moved from A to C
                 Disk 1 moved from B to A
                 Disk 2 moved from B to C
                 Disk 1 moved from A to C

    Explaination: Take an example for 2 disks :
                  Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

                  Step 1 : Shift first disk from 'A' to 'B'.
                  Step 2 : Shift second disk from 'A' to 'C'.
                  Step 3 : Shift first disk from 'B' to 'C'.

    Approach    : Shift 'n-1' disks from 'A' to 'B'.
                  Shift last disk from 'A' to 'C'.
                  Shift 'n-1' disks from 'B' to 'C'.
*/


#include <iostream>
using namespace std;


// function to print all steps for moving N-disks from source-tower to destination-tower.
void move(int n, char src, char helper, char dest)
{
    // base case
    if(n == 0)
    {
        return;
    }
    // rec case
    move(n-1, src, dest, helper);
    cout << "Disk:" << n << " moved from " << src << " to " << dest << endl;
    move(n-1, helper, src, dest);
    return;
}


// function to drive code
int main()
{
    int total_disks;
    cout << "Enter disks: ";
    cin >> total_disks;

    cout << "Steps: \n";
    move(total_disks, 'A','B','C');

    return 0;
}

/*
OUTPUT:

Case 1:
    Enter disks: 2
    Steps: 
    Disk:1 moved from A to B
    Disk:2 moved from A to C
    Disk:1 moved from B to C

Case 2:
    Enter disks: 3
    Steps: 
    Disk:1 moved from A to C
    Disk:2 moved from A to B
    Disk:1 moved from C to B
    Disk:3 moved from A to C
    Disk:1 moved from B to A
    Disk:2 moved from B to C
    Disk:1 moved from A to C


APPROACH:

    When disk = N

          ___       |                  |                     |                 
           |       -|-                 |                     |                 
    n-1    |      --|--                |                     |                 
          _|_    ---|---               |                     |                 
    last  _|_  _----|----_        _____|_____           _____|_____            
                 source             helper              destination             
                   'A'                'B'                   'C'                

    1. Shift 'n-1' disks from 'A' to 'B'.

                    |                  |                     |                 
                    |                  |      ___            |                 
                    |                 -|-      |             |                 
           ___      |                --|--     | n-1         |                 
    last   _|_ _----|----_        __---|---__ _|_       _____|_____            
                  source             helper             destination            
                   'A'                'B'                   'C'                

    2. Shift last disk from 'A' to 'C'.

                    |                  |                     |                 
                    |                  |       ___           |                 
                    |                 -|-       |            |                 
                    |                --|--      | n-1        |        ___      
               _____|_____        __---|---__  _|_      _----|----_   _|_  last
                  source             helper             destination            
                   'A'                'B'                   'C'                

    3. Shift 'n-1' disks from 'B' to 'C'.

                    |                  |                     |        ___      
                    |                  |                    -|-        |       
                    |                  |                   --|--       |   n-1 
                    |                  |                  ---|---     _|_      
               _____|_____        _____|_____           _----|----_   _|_  last
                  source             helper             destination            
                   'A'                'B'                   'C'                


*/