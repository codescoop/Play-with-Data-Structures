/*
    Topic - Time Complexity Binary Search

    Find the time complexity of below function:

    ----------------------------------------------------------------------------
    int binary_search(int arr[], int size, int key)
    {
        int start = 0;
        int end = size;

        while (start <= end)
        {
            int mid = (start + end) / 2;  // calculating the middle value

            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;                   
    }

    Assume, array size = n
    __ Steps___ |  ____Array Size______
        0       |   n    i.e = n/(2^0)   
        1       |   n/2  i.e = n/(2^1)   
        2       |   n/4  i.e = n/(2^2)   
        3       |   n/8  i.e = n/(2^3)   
        3       |   n/16 i.e = n/(2^4)   
       ...      |        ...
       ...      |        ...
    (Suppose at k steps array size reached at 1)
       k steps  |   1  i.e = n/(2^k)   

    Now, at k-steps,
           1 = n/(2^k)
         2^k = n
       Taking (log base2) both sides 
    log(2^k) = logn
           k = logn 

    Time Complexity = O(logn)

*/