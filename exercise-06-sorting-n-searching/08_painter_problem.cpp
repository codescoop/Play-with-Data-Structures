/* 
    Topic - Painter Problem

    You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. 
    There are K painters available and you are also given how much time a painter takes to paint 1 unit 
    of board. You have to get this job done as soon as possible under the constraints that any painter
    will only paint contiguous sections of board. Return the ans % 10000003

    Input Format: First line contains three space seperated integers N,K and T ,where
                  N = Size of array,
                  K = No of painters available ,
                  T = Time taken to print each board by one painter
                  Next line contains N space seperated positive integers denoting size of N boards.

    Constraints: 1<=N<=100000
                 1<=K<=100000
                 1<=T<=1000000
                 1<=Li<=100000

    Output Format: Return minimum time required to paint all boards % 10000003.

    Sample Input: 2 2 5
                  1 10

    Sample Output: 50

    Explanation: The first painter can paint the first board in 5 units of time and 
                 the second painter will take 50 units of time to paint the second board. 
                 Since both can paint simultaneously , the total time required to paint both 
                 the boards is 50.
*/

#include <iostream>
#include <climits>
#define ll long long int
using namespace  std;

// function to check if it is possible to paint all boards in the given time
bool isPossible(ll board[], ll totalBoard, ll totalPainter, ll given_time)
{
    ll painter_used = 1;
    ll time_taken_till_now = 0;

    for(ll idx=0; idx<= totalBoard-1; idx++)
    {
        time_taken_till_now = time_taken_till_now += board[idx];

        if(time_taken_till_now > given_time )
        {
            painter_used++;
            time_taken_till_now = board[idx];
            if(painter_used > totalPainter)
			{
                return false;
            }
        }
    }
    return true;
}


// function to find minimum time taken by painter's to paint all boards
ll getMinTime(ll *board, ll totalBoard, ll totalPainter, ll timePerUnit)
{
    /* 
	   Assuming the search space for Number of Minutes & 
       appling binary search on this time range 
	*/

    ll sum_boards_length = 0;
	ll max_length = INT_MIN;
    for(ll idx=0; idx<=totalBoard-1; idx++)
	{
        sum_boards_length += board[idx];
		max_length = max(max_length, board[idx]);
    }

    ll start = max_length;
    ll end = sum_boards_length;
    ll timeTaken = 0;

    while(start<=end)
    {
        ll mid = (start+end)/2;
        // check if it is possible to paint all boards in given time (i.e mid value)
        bool status = isPossible(board, totalBoard, totalPainter, mid);

        if(status)
		{
            // if it is possible to paint all boards in x minutes
            timeTaken = mid;     // store minimum value from the eligible time values
            end = mid-1;
        }
		else
		{
            // if it is not possible to paint all boards in x minutes
            start = mid+1;
        }
    }
    return (timeTaken*timePerUnit)%10000003;
}


// function to drive code
int main()
{
	ll totalPainter, totalBoard, timePerUnit;
	cout << "Enter Total [Board, Painter & Time]: ";
	cin >> totalBoard >> totalPainter >> timePerUnit;
	
	ll board[totalBoard];
	cout << "Enter length of boards: ";
	for(ll idx=0; idx<=totalBoard-1; idx++){
		cin >> board[idx] ;
	}

	// finding minimum time required to paint all boards
	ll timeTaken = getMinTime(board, totalBoard, totalPainter, timePerUnit);
	
	cout << "Minimum time to paint all boards: ";
	cout << timeTaken << endl;

    return 0;
}

       
/* 
OUTPUT:

Case 1:
    Enter Total [Board, Painter & Time]: 2 2 5
    Enter length of boards: 1 10
    Minimum time to paint all boards: 50

Case 2:
    Enter Total [Board, Painter & Time]: 2 3 1
    Enter length of boards: 10 11 10
    Minimum time to paint all boards: 11


Code:

    #include<iostream>
    #include<climits>
    #include<algorithm>
    #define ll long long int
    using namespace std;

    bool canPaint(ll boards[],ll n,ll k, ll time)
    {
        ll painting = 0;
        ll count = 1;
        for(ll i=0;i<n;i++)
        {
            painting+=boards[i];
            if(painting>time)
            {
                painting=boards[i];
                count++;
            }
        }
        if(count<=k)
        return true;
        else
        return false;
    }


    ll getMax(ll boards[],ll n)
    {
        ll max1 = INT_MIN;
        for(ll i = 0;i<n;i++)
        {
            if(boards[i]>max1)
            max1=boards[i];
        }
        return max1;
    }


    ll paintersPartitionProblem(ll boards[],ll n,ll k,ll t)
    {
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            // boards[i]*=t;
            sum+=boards[i];
        }

        ll s = getMax(boards,n);
        ll e = sum;
        ll ans = INT_MAX;

        while(s<=e)
        {
            ll mid = (s+e)/2;
            bool canDraw = canPaint(boards,n,k,mid);
            if(canDraw)
            {
                e = mid-1;
                ans = mid;
            }
            else
            s = mid+1;
        }
        return (ans*t)%10000003;
    }

    int main() 
    {
        ll n,k,t;
        cin>>n>>k>>t;
    
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
    
        cout<<paintersPartitionProblem(a,n,k,t)<<endl;

        return 0;
    }

*/