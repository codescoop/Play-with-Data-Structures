#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

// Function to print array elements
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

/* Function to reverse array element using auxiliary array */
void reverse_1(struct Array *arr)
{
    int i, j;
    int b[arr->length];

    for (i = 0, j = arr->length - 1; j >= 0; i++, j--)
        b[i] = arr->A[j];

    for (i = 0; i < arr->length; i++)
        arr->A[i] = b[i];
}

/* Function to reverse array element using swap */
void reverse_2(struct Array *arr)
{
    int i, j, temp;

    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main()
{
    struct Array arr;

    cout << "Enter the array size : ";
    cin >> arr.size;
    arr.A = new int[arr.size]{0};

    cout << "How many values do you want to enter : ";
    cin >> arr.length;

    cout << "Enter array values : ";
    for (int i = 0; i < arr.length; i++)
        cin >> arr.A[i];

    cout << "Array Elements : ";
    display(arr);

    reverse_1(&arr); //Method 1: Reverse using auxiliary array
    cout << "\n\nMethod 1: Reverse using auxiliary array \nReversed Array Element: ";
    display(arr);

    reverse_2(&arr); //Method 2: Reverse using swaping elements
    cout << "\n\nMethod 2: Reverse using swaping elements \nReversed Array Element: ";
    display(arr);

    return 0;
}

/*
Input : Enter the Array Size : 10
        How many values do you want to enter : 6
        Enter array values :10
        20
        30
        40
        50
        60
        Array Elements : 10 20 30 40 50 60

Output: Method 1: Reverse using auxiliary array
        Reversed Array Element: 60 50 40 30 20 10

        Method 2: Reverse using swaping elements
        Reversed Array Element: 10 20 30 40 50 60
*/