/*
    - Given a binary number, help Von Neuman to find outits decimal representations.
      Eg: 000111 in binary is 7 in decimal

    - Also, the input will be provided from a file & we will be saving out out in file.
      Eg: file.exe < input_file.txt > output_file.txt
      
*/
#include <iostream>
using namespace std;

int main(){
    int total_values, binary_number, decimal_number, power;
    
    cin>>total_values;

    while(total_values > 0){
        decimal_number = 0;
        power = 1;
        cin>>binary_number;
        while(binary_number > 0){
            decimal_number = decimal_number +  (power * (binary_number%10));
            binary_number = binary_number/10;
            power = power * 2;
        }
        cout<<decimal_number<<endl;
        total_values--;
    }
    return 0;
}