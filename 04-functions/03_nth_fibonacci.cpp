/* 
    Nth Fibonacci Function
    0, 1, 1, 2, 3, 5, 8, 13 ...
*/

#include <iostream>
using namespace std;

int fibonacci(int num)
{
    int first = 0;
    int second = 1;
    int curr = 0;
    
    for (int index = 1; index <= num; index++)
    {
        if (index == 1){
            curr = first;
        }
        else if (index == 2){
            curr = second;
        }
        else{
            curr = first + second;
            first = second;
            second = curr;
        }
    }
    return curr;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    cout << fibonacci(num) <<endl;
    return 0;
}