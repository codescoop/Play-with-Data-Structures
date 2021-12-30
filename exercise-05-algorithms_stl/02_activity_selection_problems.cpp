/*
    Problem Name: Activity Selection Problem

    You are given n activities (from 0 to n-1) with their start and finish times. 
    Select the maximum number of activities that can be performed by a single person, 
    assuming that a person can only work on a single activity at a time.

    Input Format: The first line consists of an integer T, the number of test cases. 
                  For each test case, the first line consists of an integer N, 
                  the number of activities. Then the next N lines contain two integers
                  m and n, the start and end time of each activity.

    Constraints: 1 <= t <= 50
                 1 <= n <= 10000
                 1 <= A[i] <= 100

    Output Format: For each test case find the maximum number of activities that 
                   you can do.

    Sample Input:   1 
                    3
                    10 20
                    12 15
                    20 30

    Sample Output: 2

    Explanation: Person can only do 0th and 2nd activities.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// comparator function
bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

// function to drive code
int main() {
    int testcase;
    cout << "Enter total Testcases: ";
    cin >> testcase;

    while(testcase--){
        int activities;
        cout << "Enter Total Activities: ";
        cin >> activities;
        
        // array of pair to store start & end time
        pair<int,int> arr[activities];
        
        // taking input of activity time
        int start, end;
        for(int idx=0; idx<=activities-1; idx++){
            cout << "Enter Start & End time: ";
            cin >> start >> end;

            arr[idx] = make_pair(start, end);
        }

        // sorting activity in the increasing order of their finishing times.
        sort(arr, arr+activities, compare);

        int count = 1;       // counter of activities (value=1 for first activity)
        int chosen = 0;      // to store index of chosen activity (index=0 for first activity)

        for(int itr=1; itr <= activities-1; itr++){
            /* if the the starting time of current activity is greater than or equal to
               finish time of previous selected activity */
            if(arr[itr].first >= arr[chosen].second){
                count++;
                chosen = itr;
            }
        }
        cout << "Maximum activities done : " << count << endl;
    }
	return 0;
}

/* 

Approach
    A basic activity selection problem which uses Greedy approach. 
    The implementation mentioned here states to sort the activities in the increasing 
    order of their finishing times. Initially, we choose the first activity. 
    Now, starting from second activity, current activity can be selected if the 
    finish time of previous selected activity is less than or equal to the 
    starting time of current activity.

C++ Code

    #include <iostream>
    #include <algorithm>
    using namespace std;

    bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    int main(int argc, char const *argv[])
    {
        int t;
        cin>>t;
        while(t--) {
            int n, a, b;
            cin>>n;
            pair<int, int> arr[n];
            for(int i=0;i<n;i++) {
                cin>>a>>b;
                arr[i] = make_pair(a, b);
            }
            sort(arr, arr+n, cmp);
            // for(int i=0;i<n;i++) {
            //  cout<<arr[i].first<<" "<<arr[i].second<<endl;
            // }
            int ans = 1, chosen = 0;
            for(int i=1;i<n;i++) {
                if(arr[i].first>=arr[chosen].second) {
                    ans++;
                    chosen = i;
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }

*/
