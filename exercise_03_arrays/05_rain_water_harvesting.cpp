/*
    Problem Name: Rain Water Harvesting

    Apoorvaa has created an elevated roof. 
    She wants to know how much water can she save during rain.
    Given n non negative integers representing the elevation map where width of every bar is 1, 
    Find the maximum water that she can save.

    Explanation for the Sample input Testcase:
    
            ___|__________      // "|" denotes roof building blocks
           | * | * * | * |      // "*" denotes water filled between building blocks
         __|_|_|_*_|_|_|_|_|_
         0 2 1 3 0 1 2 1 2 1
    So the total units of water she can save is 5 units

    Input Format: First line contains an integer n. 
                  Second line contains n space separated integers representing the elevation map.

    Constraints: 1 <= N <= 10^6

    Output Format: Print a single integer containing the maximum unit of waters she can save.

    Sample Input:   10
                    0 2 1 3 0 1 2 1 2 1

    Sample Output:  5

    Explanation: Refer to the image for explanation. 
                 Count the number of cells having water in them.

*/

#include <iostream>
using namespace std;

// Brute Force Approach - Time complexity O(n2).
int maxWater1(int arr[], int range){
    int res = 0;
    for(int idx=1; idx<=range-1; idx++){
        //Max value on left side of element
        int maxLeft =  arr[idx]; 
        for(int j=0; j<=idx; j++){
            maxLeft = max(arr[j], maxLeft);
        }
        //Max value on right side of element
        int maxRight =  arr[idx]; 
        for(int j=idx+1; j<=range-1; j++){
            maxRight = max(arr[j], maxRight);
        }
        // finding the unit of water on each element
        res += min(maxLeft, maxRight) - arr[idx];
    }
    return res;
}

// Pre-Computed values Approach - 
// Pre-compute highest bar on left and right of every bar in O(n) time.
int maxWater2(int arr[], int range){

    int leftMax[range], rightMax[range];
    leftMax[0] = arr[0];
    rightMax[range-1] = arr[range-1];

    for (int i = 1; i <= range-1; i++)
    {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }
    for (int i = range-2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i+1], arr[i]);
    }
    int res = 0;
    for (int i = 0; i <= range-1; i++)
    {
        res += (min(leftMax[i], rightMax[i]) - arr[i]);
    }
    return res;

}

//  Two Pointer Approach
int maxWater3(int arr[], int range){
    int res = 0;          // store final answer
    
    int leftMax = 0;      // Stores current max height on left side
    int rightMax = 0;     // Stores current max height on right side

    int lo=0;             // counter to traverse from left side
    int hi=range-1;       // counter to traverse from right side

    while(lo<hi){              
        if(arr[lo]<arr[hi]){       // Update the side which have lower value
            if(arr[lo]>leftMax){
                leftMax = arr[lo];           // update left max
            }else{
                res += (leftMax-arr[lo]);    // cal water units
            }
            lo++;
        }else{
            if(arr[hi]>rightMax){
                rightMax = arr[hi];           // update right max
            }else{
                res += (rightMax - arr[hi]);  // cal water units
            }
            hi--;
        }
    }
    return res;
}

int main() {
	int range;
    cout << "Total no. of values: ";
    cin >> range;

    int arr[range];
    cout << "Enter values: ";
    for(int idx=0; idx<=range-1; idx++){
        cin >> arr[idx];
    }

    cout << "Max unit of water stored : ";
    // cout << maxWater1(arr, range) << endl;
    // cout << maxWater2(arr, range) << endl;
    cout << maxWater3(arr, range) << endl;

	return 0;
}




/* 
    Problem Name : Rain Water Harvesting

    EXPLANATION
    An element of the array can store water if there are higher bars on left and right. We can find the amount of water to be stored in every element by finding the heights of bars on left and right sides. The idea is to compute the amount of water that can be stored in every element of array. For example, consider the array {3, 0, 0, 2, 0, 4}, we can store three units of water at indexes 1 and 2, and one unit of water at index 3, and three units of water at index 4.
    A Simple Solution is to traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element. Time complexity of this solution is O(n2).

    Naive Approach
    int maxWater(int arr[], int n)
    {

    // To store the maximum water  
    // that can be stored 
    int res = 0; 

    // For every element of the array 
    for (int i = 1; i < n-1; i++) { 

        // Find the maximum element on its left 
        int left = arr[i]; 
        for (int j=0; j<i; j++) 
        left = max(left, arr[j]); 

        // Find the maximum element on its right    
        int right = arr[i]; 
        for (int j=i+1; j<n; j++) 
        right = max(right, arr[j]);  

    // Update the maximum water     
    res = res + (min(left, right) - arr[i]);    
    } 

    return res;  
    }
    --------------------------------------------------------------------
    Better Approach
    An element of an array can store water if there are higher bars on left and right. We can find the amount of water to be stored in every element by finding the heights of bars on the left and right sides. The idea is to compute the amount of water that can be stored in every element of the array. For example, consider the array {3, 0, 0, 2, 0, 4}, we can store two units of water at indexes 1 and 2, and one unit of water at index 2.
    Pre-compute highest bar on left and right of every bar in O(n) time. Then use these pre-computed values to find the amount of water in every array element.
    C++ Code

    #include <iostream>
    using namespace std;
    int a[1000000], l[1000000], r[1000000];
    int main()
    {
        int n, i, j;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        l[0] = a[0];
        r[n - 1] = a[n - 1];
        int leftmax = 0, rightmax = 0;
        for (i = 1; i < n; i++)
        {
            l[i] = max(l[i - 1], a[i]);
        }
        for (i = n - 2; i >= 0; i--)
        {
            r[i] = max(r[i + 1], a[i]);
        }
        int water = 0;
        for (i = 0; i < n; i++)
        {
            water += (min(l[i], r[i]) - a[i]);
        }
        cout << water;

        return 0;
    }
    Java Code

    import java.util.*;

    public class Practice {
        static int[] a = new int[1000000];
        static int[] r = new int[1000000];
        static int[] l = new int[1000000];

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            l[0] = a[0];
            r[n - 1] = a[n - 1];
            int leftmax = 0, rightmax = 0;
            for (int i = 1; i < n; i++) {
                l[i] = Math.max(l[i - 1], a[i]);
            }
            for (int i = n - 2; i >= 0; i--) {
                r[i] = Math.max(r[i + 1], a[i]);
            }
            int water = 0;
            for (int i = 0; i < n; i++) {
                water += (Math.min(l[i], r[i]) - a[i]);
            }
            System.out.println(water);
        }
    }
    --------------------------------------------------------------------
    Best Approach:

    Use the two pointer approach. Loop from index 0 to the end of the given array. If a wall greater than or equal to the previous wall is encountered then make note of the index of that wall in a var called previndex. Keep adding previous wall’s height minus the current (ith) wall to the variable water. Have a temporary variable that stores the same value as water. If no wall greater than or equal to the previous wall is found then quit. If previndex < size of the input array then subtract the temp variable from water, and loop from end of the input array to prev_index and find a wall greater than or equal to the previous wall (in this case, the last wall from backwards).
    C++ Code

    int maxWater_optimized(int arr[], int n)
    {
        int water = 0; // To store the final ans

        int left_max = 0;  // Which stores the current max height of the left side
        int right_max = 0; // Which stores the current max height of the right side

        int lo = 0;     // Counter to traverse from the left_side
        int hi = n - 1; // Counter to traverse from the right_side

        while (lo <= hi)
        {

            if (arr[lo] < arr[hi])
            {

                if (arr[lo] > left_max)
                {
                    left_max = arr[lo]; // Updating left_max
                }
                else
                {

                    water += left_max - arr[lo]; // Calculating the ans
                }
                lo++;
            }
            else
            {

                if (arr[hi] > right_max)
                {
                    right_max = arr[hi]; // Updating right_max
                }
                else
                {
                    water += right_max - arr[hi]; // Calculating the ans
                }
                hi--;
            }
        }

        return water;
    }
    Java Code

    public static int maxWater_optimized(int[] arr){

        int n = arr.length;
        int water = 0;  // To store the final ans

        int left_max = 0;     //Which stores the current max height of the left side
        int right_max = 0;   //Which stores the current max height of the right side

        int lo = 0;                //Counter to traverse from the left_side
        int hi = n - 1;           //Counter to traverse from the right_side

        while(lo <= hi){

        if(arr[lo] < arr[hi]){         

            if(arr[lo] > left_max){
            left_max = arr[lo];             //Updating left_max
            }else{ 

            water += left_max - arr[lo];  //Calculating the ans
            }
            lo++;
        }else{

            if(arr[hi] > right_max){
            right_max = arr[hi];               //Updating right_max
            }else{
            water += right_max - arr[hi];  //Calculating the ans
            }
            hi--;
        }

        }

        return water;  
    }
 */