/* 
    Topic - Winning Scholarship
    
    Management decided to give 100% scholarships to the needy students by taking an admission test. 
    However in order to avoid any losses at the institute, they came up with a solution. 
    Institute has N students and M discount coupons. 
    A student will get 100% waiver if he gets X discount coupons.
    However in order to get more discount coupons in addition to those M , Management decided that some 
    students who perform badly in the admission tests, need to pay additional amount equivalent to 
    Y discount coupons, 
    i.e. good students earn discount coupons and weak students need to pay coupons to get admission.
    
    Find out the maximum number of students who can get 100% waiver in their admission fees.
    Note : Management will try his best to give 100% discount to maximum students possible.

    Input Format:  The first line contains interger T (no of testcases)
                   Next T lines contains 4 integers N M X Y

    Constraints:  1 ≤ N,M,X,Y ≤ 10^9​​

    Output Format: The output should contain a single integer representing the maximum number of students 
                   who can get 100% discount.

    Sample Input:  2
                   5 10 2 1
                   3 10 4 2
    
    Sample Output: 5
                   2

    Explanation: Ex 1: Since there are 5 students, and 10 available coupons, and each student needs 
                       just 2 coupons to get 100% discount, so Management already has the needed number 
                       of coupons, so all 5 students will get 100% waiver on their fees.
                 Ex 2: There are 3 students. Management will give 100% discount to 2 students using the 
                       initial number of discounts, i.e 8 out of 10 will get used. We need atleast 
                       2 more coupons to give discount to the third student. 
                       Now if the third student pay additional amount equivalent to Y=2 coupons, 
                       we will get a total of 4 coupons in hand. However we can not use them for giving
                       discount as all 3 students have been considered (2 for getting discount and 
                       1 for paying additional amount).
*/

#include <iostream>
#include <climits>
using namespace  std;

// function to check if given students will get the scholarship
bool willGetScholarship(int totalStudents, int totalCoupons, int minReqCoupons, int couponAmountFromStudents, int givenStudents)
{
    int requiredCoupons = givenStudents*minReqCoupons;

    if(requiredCoupons <= totalCoupons)
    {
        return true;
    }
    else
    {
        int pendingStudents = totalStudents - givenStudents;
        int additionalCouponsFromStudents = pendingStudents*couponAmountFromStudents;

        int availableCoupons = totalCoupons + additionalCouponsFromStudents;

        if(requiredCoupons <= availableCoupons){
            return true;
        }else{
            return false;
        }
    }
}


// function to find maximun number of students who will get scholarship
int getMaxStudents(int totalStudents, int totalCoupons, int minReqCoupons, int couponAmountFromStudents)
{
    /* 
        Assuming a Search Space for number of students who can get scholarship
        appling binary search on above range 
    */
    
    // minimum no of students who can get scholarship
    int min = totalCoupons/minReqCoupons;

    int start = min;
    int end = totalStudents;
    int students = INT_MIN;

    while(start <= end){
        int mid = (start+end)/2;
        // check if it is possible to given scholarship to x students
        int status = willGetScholarship(totalStudents, totalCoupons, minReqCoupons, couponAmountFromStudents, mid);
        if(status){
            // if x students can get scholarship
            students = max(students, mid);          // store max value from all eligible values 
            start = mid+1;
        }else{
            // if x students can not get scholarship
            end = mid-1;
        }
        
    }
    return students;
}


// function to drive code
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        int totalStudents, totalCoupons, minReqCoupons, couponAmountFromStudents;

        cout << "Enter number of Students & Coupons: ";
        cin >> totalStudents >> totalCoupons;
        
        cout << "Enter no of coupons needed for scholarship: ";
        cin >> minReqCoupons;

        cout << "Enter Coupons Amount for students : ";
        cin >> couponAmountFromStudents;

        // finding maximun number of students who will get scholarship
        int students = getMaxStudents(totalStudents, totalCoupons, minReqCoupons,couponAmountFromStudents);
        
        cout << "No of Students who will get Scholarship : ";
        cout << students << endl;

        testcases--;
    }

    return 0;
}


/* 
OUTPUT:

    Enter total testcases: 3

    Enter number of Students & Coupons: 5 10
    Enter no of coupons needed for scholarship: 2 
    Enter Coupons Amount for students: 1
    No of Students who will get Scholarship : 5

    Enter number of Students & Coupons: 3 10
    Enter no of coupons needed for scholarship: 4 
    Enter Coupons Amount for students: 2
    No of Students who will get Scholarship : 2

    Enter number of Students & Coupons: 3 5
    Enter no of coupons needed for scholarship: 5
    Enter Coupons Amount for students: 6
    No of Students who will get Scholarship : 2
*/