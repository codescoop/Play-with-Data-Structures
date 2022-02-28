/*
    Topic - Phone Keypad Problem (Recursion)

    Generate & print all possible string mapped with the phone keypad number.

    Phone Keypad :  0    1    2      3      4      5      6      7       8      9
    Characters   :  "",  "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"


    Eg: Input  : 2
        Output : A, B, C

        Input  : 23
        Output : AD, AE, AF, BD, BE, BF, CD, CE, CF

        Input  : 22
        Output : AA, AB, AC, BA, BB, BC, CA, CB, CC

        Input  : 234
        Output : ADG, ADH, ADI, AEG, AEH, AEI, AFG, AFH, AFI, BDG, BDH, BDI, BEG, BEH, BEI, BFG, 
                 BFH, BFI, CDG, CDH, CDI, CEG, CEH, CEI, CFG, CFH, CFI
*/


#include <iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

// function to generate all possible string mapped with the keypad number
void generate_names(char *in, int i, char *out, int j)
{
    // base case
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << ", ";
        return;
    }
    
    // rec case
    // extract current digit
    int digit = in[i] - '0';                  //Eg: '2'-'0' = 2

    // for phone keypad digit associated with NULL character
    if(digit==0 || digit==1)
    {
        generate_names(in, i+1, out, j);
    }

    // for all characters mapped with the phone keypad digit
    for(int k=0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        // fill the remaining part
        generate_names(in, i+1, out, j+1);
    }
}


// function to drive code
int main()
{
    char in[100];
    cout << "Enter phone keypad: ";
    cin >> in;

    char out[100];
    cout << "All String: ";
    generate_names(in, 0, out, 0);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter phone keypad: 01
    All String: , 

Case 2:
    Enter phone keypad: 02
    All String: A, B, C, 

Case 3:
    Enter phone keypad: 666
    All String: MMM, MMN, MMO, MNM, MNN, MNO, MOM, MON, MOO, NMM, NMN, NMO, NNM, NNN, NNO, NOM, NON,
                NOO, OMM, OMN, OMO, ONM, ONN, ONO, OOM, OON, OOO,

Case 4:
    Enter phone keypad: 23
    All String: AD, AE, AF, BD, BE, BF, CD, CE, CF,

Case 5:
    Enter phone keypad: 123
    All String: AD, AE, AF, BD, BE, BF, CD, CE, CF,
*/