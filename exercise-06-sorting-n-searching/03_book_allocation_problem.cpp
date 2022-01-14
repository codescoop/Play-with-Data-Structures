/* 
    Topic - Book Allocation
    
    You are given number of pages in n different books and m students. The books are arranged in ascending
    order of number of pages. Every student is assigned to read some consecutive books. The task is to 
    assign books in such a way that the maximum number of pages assigned to a student is minimum.

    Input Format: First line contains integer t as number of test cases. 
                  Next t lines contains two lines. For each test case, 
                  1st line contains two integers n and m which represents the number of books and students and 
                  2nd line contains n space separated integers which represents the number of pages of 
                  n books in ascending order.

    Constraints:  1 < t < 50
                  1< n < 100
                  1< m <= 50
                  1 <= Ai <= 1000

    Output Format: Print the maximum number of pages that can be assigned to students.

    Sample Input: 1
                  4 2
                  12 34 67 90

    Sample Output: 113 

    Explanation: 1st students : 12 , 34, 67 (total = 113)
                 2nd students : 90 (total = 90)
                 Print max(113, 90)
*/

#include <iostream>
#include <algorithm>
using namespace  std;


// function to check if it is possible to divide the books among students
bool isPossibleToAssignBooks(int books[], int totalBooks, int totalStudents, int curr_allocation)
{
    int studentCount = 1;                 // maintaining the count of no of students
    int pages_reading = 0;                // maintaining the no of page read by students

    for(int idx=0; idx<=totalBooks-1; idx++)
    {
        if(pages_reading + books[idx] > curr_allocation){
            studentCount++;
            pages_reading = books[idx];              // assigning current book to next student
            if(studentCount > totalStudents){
                return false;
            }
        }
        else{   
            pages_reading = pages_reading + books[idx];
        }
    }
    return true;
}




/* function to Minimize the Maximum pages for each student
   (As we have to assign books such that maximum number of pages assigned to a student is minimum)
*/
int getPages(int *books, int totalBooks, int totalStudents)
{
    /* assuming search space for Number Of Pages:
       - minimum pages that can be read by a student = pages of book_having_maximum_pages
         (The minimum_page_allocation_value should always be greater than books_with_maximum_pages because if
          books is having less pages than the minimum required pages.
          Then, we cannot assign the book to the student)
       - maximum pages that can be read by students (reading all books) = sum of pages for all books
       Now apply binary search on above search space.
    */


    // sum of all pages
    int book_max_pages = 0;
    int sum_of_all_pages = 0;
    for(int idx=0; idx<=totalBooks-1; idx++)
    {
        sum_of_all_pages += books[idx];
        book_max_pages = max(book_max_pages, books[idx]);
    }

    int start = book_max_pages;           // minimum value for pages allocation
    int end = sum_of_all_pages;           // maximum value for pages allocation

    int pages = 0;                        // variable to store final result

    while(start <= end)
    {
        int mid = (start+end)/2;

        // check for eligible page allocation values
        bool status = isPossibleToAssignBooks(books, totalBooks, totalStudents, mid);

        if(status){
            // if it is possible to divide at x pages
            // store the page value & decrease the number of pages
            pages = mid;          // store minimum value from all eligible page values
            end = mid-1;
        }
        else{
            // if it is not possible to divide at x pages
            // so, increase the number of pages
            start = mid+1;
        }
    }
    return pages;
 }


// function to drive code
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        int totalBooks, totalStudents;
        cout << "Enter number of Books & Students: ";
        cin >> totalBooks >> totalStudents;
        
        int books[totalBooks];
        cout << "Enter Pages for books [Sorted Order]: ";
        for(int idx=0; idx<=totalBooks-1; idx++){
            cin >> books[idx] ;
        }

        // finding maximum of minimum no of pages student can read
        int result = getPages(books, totalBooks, totalStudents);
        
        cout << "Maximum Pages student can read: ";
        cout << result << endl;

        testcases--;
    }

    return 0;
}
       

/* 
OUTPUT:

Case 1:
    Enter total testcases: 1
    Enter number of Books & Students: 4 2
    Enter Pages for books [Sorted Order]: 10 20 30 40
    Maximum Pages student can read: 60

Case 2:
    Enter total testcases: 1
    Enter number of Books & Students: 4 3
    Enter Pages for books [Sorted Order]: 10 20 30 40
    Maximum Pages student can read: 40

Case 3:
    Enter total testcases: 1
    Enter number of Books & Students: 4 2
    Enter Pages for books [Sorted Order]: 12 34 67 90
    Maximum Pages student can read: 113



APPROACH:

    The idea is to use Binary Search. We fix a value for the number of pages as mid of current minimum 
    and maximum. We initialize minimum and maximum as 0 and sum-of-all-pages respectively. If a 
    current mid can be a solution, then we search on the lower half, else we search in higher half.

    Now the question arises, how to check if a mid value is feasible or not? 
    Basically, we need to check if we can assign pages to all students in a way that the maximum 
    number doesn’t exceed current value. To do this, we sequentially assign pages to every student 
    while the current number of assigned pages doesn’t exceed the value. In this process, if the number
    of students becomes more than m, then the solution is not feasible. Else feasible.

Code

    public static long min(long[] arr, long n, long k) {
        long lo = arr[arr.length - 1];
        long totalpages = 0;
        long hi = 0;
        for (int i = 0; i < n; i++) {
            totalpages += arr[i];
        }
        hi = total_pages;
        long ans = 0;
        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            boolean isvalid = isValid(arr, k, mid);
            if (isvalid) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    private static boolean isValid(long[] arr, long k, long mid) {
        long sum = 0;
        int noOfstudents = 1;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum > mid) {
                noOfstudents++;
                sum = arr[i];
                if (noOfstudents > k) {
                    return false;
                }
            }
        }
        return true;
    }
*/