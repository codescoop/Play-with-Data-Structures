/*
    Topic - 0-1 Knapsack (Recursion) | Popular Classical Problem

    Given weights and price of N items, put these items in a knapsack of capacity W to get the 
    maximum total price in the knapsack. In other words, given two integer arrays prices[0..n-1] and 
    wt[0..n-1] which represent prices and weights associated with N items respectively. 
    Also given an integer W which represents knapsack total capacity, 
    
    Find out the maximum price subset of prices[] such that sum of the weights of this subset is 
    smaller than or equal to W. 
    You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

    Eg: Input  : N = 3
                 prices   = { 60, 100, 120 }
                 weights  = { 10, 20, 30 }
                 capacity = 50

        Output : 220 
*/


#include <iostream>
using namespace std;

// function to find maximum profit such that sum of weight of all selected items are <= knapsack capacity
int profit(int total_items, char capacity, int prices[], int wt[])
{
    // base case
    if(total_items==0 || capacity==0)
    {
        return 0;
    }

    // rec case: we have 2 options
    int ans = 0;
    int inc, exc;
    inc = exc = 0;

    // Option 1: Including nth item (i.e last item)
    if(wt[total_items-1] <= capacity)
    {
        // price = selected item price + price of more item that can be added in knapsack 
        inc = prices[total_items-1] + profit(total_items-1, capacity - wt[total_items-1], prices, wt);
    }

    // Option 2: Excluding nth item
    exc = profit(total_items-1, capacity, prices, wt);  // no change in capacity
    
    // finding max
    ans = max(inc, exc);

    return ans;
}


// function to drive code
int main()
{
    int total_items;
    cout << "How many total items: ";
    cin >> total_items;

    int prices[total_items];
    cout << "Enter prices: ";
    for(int i=0; i<total_items; i++)
    {
        cin >> prices[i];
    }

    int weights[total_items];
    cout << "Enter weights: ";
    for(int i=0; i<total_items; i++)
    {
        cin >> weights[i];
    }

    int capacity;
    cout << "Enter Knapsack Capacity: ";
    cin >> capacity;
    
    // compute profit
    cout << "Profit: " << profit(total_items, capacity, prices, weights);

    cout << endl;
    return 0;
}



/*
OUTPUT:

Case 1:
    How many total items: 3
    Enter prices  : 60 100 120
    Enter weights : 10 20 30
    Enter Knapsack Capacity: 50
    Profit: 220

Case 2:
    How many total items: 4
    Enter prices: 40 20 30 100
    Enter weights: 1 2 3 5
    Enter Knapsack Capacity: 7
    Profit: 140



Explaination:

    Method: Recursion by Brute-Force algorithm OR Exhaustive Search.

    We need to take care of two conditions:
    - Include item
    - Exclude Item


Recursion Tree:

    In the following recursion tree, K() refers to knapSack(). The two parameters indicated in the
    following recursion tree are N and C.

    The recursion tree is for following sample inputs.
    N       = 3
    price[] = {10, 20, 30}
    wt[]    = {1, 1, 1}
    C       = 2 
                                K(N, C)
                                K(3, 2)  
                            /            \ 
                            /                \               
                    K(2, 2)                  K(2, 1)
                    /       \                  /    \ 
                /           \              /        \
                K(1, 2)      K(1, 1)        K(1, 1)     K(1, 0)
                /  \         /   \              /        \
                /      \     /       \          /            \
        K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)   K(0, 0)

    Recursion tree for Knapsack capacity 2 units and 3 items of 1 unit weight.
*/