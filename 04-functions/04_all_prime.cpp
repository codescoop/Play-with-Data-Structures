/* 
    Print all prime numbers upto a number n
 */

#include <iostream>
using namespace std;

// check if number is prime
bool isPrime(int num)
{
    for (int index = 2; index < num; index++){
        if (num % index == 0){
            return false;
        }
    }
    return true;
}

// print all prime numbers
void printPrime(int range)
{
    for(int num = 2; num <= range; num++){
        if(isPrime(num))
            cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int num;
    cout << "Enter the range: ";
    cin >> num;

    printPrime(num);
}