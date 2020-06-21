#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

int linear_search(struct Array arg, int value)
{
    int index = -1; 
    for (int i = 0 ; i < arg.length; i++)
    {
        if (arg.A[i] == value)
        {
            index = i;
            return index;
        }    
    }
    return index;
}

// Function to display array
void display(struct Array arg)
{
    printf("Array : ");
    for (int i = 0; i < arg.length; i++)
        printf("%d ", arg.A[i]);
}

// Main Function
int main()
{
    int search_value, index;
    struct Array arr = {{5, 8, 7, 11, 18, 21, 9, 45, 38, 30}, 20, 10};
    display(arr);
    
    printf("\nEnter Search value : ");
    scanf("%d",&search_value);   //Taking input for search value

    index = linear_search(arr, search_value);
    if (index == -1)
        printf("Search value is not in array");
    else 
        printf("Search Value %d at index : %d",search_value,index);

    return 0;
}

/*
Input:
Array : 5 8 7 11 18 21 9 45 38 30
Enter Search value : 18

Output:
Search Value 18 at index : 4
*/