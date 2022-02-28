/*
    Topic - String Generation Acode (Recursion)

    We are given below mapping:
    Number      :  0 1 2 3 4 5 6 7 ... . . . 25 26
    Characters  :  A B C D E F G H ... . . . Y  Z

    We are also given a array of numbers. Now, we have to generate all possible strings that we can make 
    from this array.

    Eg: Input  : 1234
        Output : ABCD, LCD, AWD
        Explanation:  1234    (12)34  1(23)4
                     [ABCD]    [LCD]   [AWD]

        Input  : 1212
        Output : ABCD, LCD, AWD
        Explanation:  1212    (12)(12)  1(21)2
                     [ABAB]     [LL]     [AUB]
*/


#include <iostream>
using namespace std;


// function to generate all possible string mapped with the numbers
void generate_strings(char *in, int i, char *out, int j)
{
    // base case
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << ", ";
        return;
    }
    
    // rec case
    // case: One value at a time
    int firstDigit = in[i] - '0';
    char ch = firstDigit + 'A' - 1;
    out[j] = ch;
    generate_strings(in, i+1, out, j+1);

    // case: Two value at a time
    if(in[i+1] !=  '\0')
    {
        int secondDigit =  in[i+1] - '0';
        int no = firstDigit*10 + secondDigit;
        if(no <= 26)
        {
            ch = no + 'A' -1;
            out[j] = ch;
            generate_strings(in, i+2, out, j+1);
        }
    }
    return;
}


// function to drive code
int main()
{
    char in[100];
    cout << "Enter Numbers: ";
    cin >> in;

    char out[100];
    cout << "All String: ";
    generate_strings(in, 0, out, 0);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter Numbers: 1234
    All String: ABCD, AWD, LCD, 

Case 2:
    Enter Numbers: 1212
    All String: ABAB, ABL, AUB, LAB, LL,

Case 3:
    Enter Numbers: 123
    All String: ABC, AW, LC,

Case 4:
    Enter Numbers: 122212
    All String: ABBBAB, ABBBL, ABBUB, ABVAB, ABVL, AVBAB, AVBL, AVUB, LBBAB, LBBL, LBUB, LVAB, LVL,



Recursion Tree:

    When Number = 1234                        

                             1234             
                          /       \           
                      A234         L34        
                    /     \        /  \       
                AB34      AW4     LC4  X      
                /  \     /   \    /  \        
              ABC4  X   AWD   X  LCD  X       
              /  \                            
            ABCD  X                           

    PRINT:  ABCD\0      AWD\0    LCD\0        
*/