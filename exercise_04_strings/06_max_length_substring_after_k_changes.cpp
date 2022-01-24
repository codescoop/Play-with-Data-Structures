/*
    Problem Name: Maximum length substring having all same characters after k changes

    Ram Bhaiya has a string consisting of only 'a' and 'b' as the characters.
    Ram Bhaiya describes perfectness of a string as the maximum length substring of equal characters.
    Ram Bhaiya is given a number k which denotes the maximum number of characters he can change.
    Find the maximum perfectness he can generate by changing no more than k characters.

    Input Format: The first line contains an integer denoting the value of K.
                  The next line contains a string having only ‘a’ and ‘b’ as the characters.

    Constraints: 2 ≤ N ≤ 10^6

    Output Format: A single integer denoting the maximum perfectness achievable.

    Sample Input: 2
                  abba

    Sample Output: 4

    Explanation: We can swap the a's to b using the 2 swaps and obtain the string "bbbb".
                 This would have all the b's and hence the answer 4.
                 Alternatively, we can also swap the b's to make "aaaa".
                 The final answer remains the same for both cases.
*/

#include <iostream>
#include <string>
using namespace std;

int findMaxLen(string s, char ch, int maxSwap)
{
    int range = s.size();
    int maxlen = 1;
    int swap = 0;
    int r = 0;      // right pointer
    int l = 0;      // left pointer
    while(r <= range-1){
        if(s[r] != ch){
            swap++;
        }
        // After maxSwap, Decrease the swap for unequal value & Increase the left index
        while(swap > maxSwap){
            if(s[l] != ch){
                swap--;
            }
            l++;
        }
        // Length of substring will be (rightIndex - leftIndex + 1)
        maxlen = max(maxlen, (r-l+1));
        r++;
    }
    return maxlen;
}

int findPerfectString(string s1, int maxSwap)
{
    int maxlen = max(findMaxLen(s1, 'a', maxSwap), findMaxLen(s1, 'b', maxSwap));
    return maxlen;
}

int main()
{
    int swap;
    cout << "Enter total swaps: ";
    cin >> swap;

    string s1;
    cout << "Enter string: ";
    cin >> s1;

    cout << findPerfectString(s1, swap);
    cout << endl;

    return 0;
}

/*
Algo - 
- We check for maximum length of sub-string that can be formed by every character in a set of 52 characters (From ‘A’ to ‘Z’ and from ‘a’ to ‘z’).
- For doing this we traverse whole string and whenever we find a different character, we increase the count.
- If count becomes greater than k (at right index), we again start from 0th index and if we found different character we will decrease the count.
- When count will be equal to k (at left index) then at that point the length will be rightIndex-leftIndex+1.
- We repeat this process until we reach at the end of string and at that point we will return the maximum length.
- We do this for all characters and finally return the maximum length.

// C++ program to find maximum length equal character string with k changes
#include <iostream>
using namespace std;

// function to find the maximum length of substring having character ch
int findLen(string& A, int n, int k, char ch)
{
	int maxlen = 1;
	int cnt = 0;
	int l = 0, r = 0;
	
	// traverse the whole string
	while (r < n) {
	
		// if character is not same as ch increase count
		if (A[r] != ch)
			++cnt;

		// While count > k, traverse the string again until count becomes less than k
		// and decrease the count when characters are not same
		while (cnt > k) {
			if (A[l] != ch)
				--cnt;
			++l;
		}

		// length of substring will be rightIndex -leftIndex + 1. 
        // Compare this with the maximum length and return maximum length
		maxlen = max(maxlen, r - l + 1);
		++r;
	}
	return maxlen;
}

// function which returns maximum length of substring
int answer(string& A, int n, int k)
{
	int maxlen = 1;
	for (int i = 0; i < 26; ++i) {
		maxlen = max(maxlen, findLen(A, n, k, i+'A'));
		maxlen = max(maxlen, findLen(A, n, k, i+'a'));
	}
	return maxlen;
}

// Driver code
int main()
{
	int n = 5, k = 2;
	string A = "ABABA";
	cout << "Maximum length = " << answer(A, n, k) << endl;

	n = 6, k = 4;
	string B = "HHHHHH";
	cout << "Maximum length = " << answer(B, n, k) << endl;
	return 0;
}

------------------------------------------------

Approach - Two pointer approach
      You can solve this problem in O(n) time using the two pointer approach.

    * Make two variabes , say i and j .
    * i defines the beginning of a window and j defines its end.
    * Start i from 0 and j from k.
    * Let’s talk about the singular case when we are considering the max window for only 'a’s and 
      consider only the swapping of b-> a. 
      If we are able to get the answer for max window of consecutive 'a’s , 
      we can simply implement the same algo for the max ‘b’ window as well.
    * So we started i from 0 and j from k.
    * Move j ahead freely as long as there are ‘a’ characters at s[ j ] position.
    * Maintain a count variable which counts the number of swaps made or the number of 'b’s in our A window.
    * If you encounter a ‘b’ char at s[ j ] position , increment the count variable. 
      Count should never exceed k.
    * Take the size of the window at every point using length = j - i + 1;
    * Compute the max size window this way and do the same for ‘b’ as well.
    * Output the maximum size window of ‘a’ and ‘b’.

C++ Code

    #include <iostream>
    #include <cstring>
    using namespace std;

    //Function to count the length of window which can be made of char ch with <= k swaps
    int countMaxWindowSize(const string &s, char ch, int k)
    {
        int i = 0; //Left pointer
        int j = 0; //Right pointer

        //First move the right pointer forward by k steps.
        //If the character is already ch , do not count a swap and move freely

        int c = 0; //Variable to count the swaps so far

        int ans = 0; //Variable to store the final answer

        for (j; c < k && j < s.size() - 1; j++)
        {
            if (s[j] != ch)
            {
                //If s[j] is not ch then count it as a swap and move forward
                c++;
            }
            if (c == k)
            {
                //If no of swaps has reached k, stop moving j any more forward
                break;
            }
        }

        while (i < j)
        {

            //Move j ahead if next element is ch as it doesn't count as a swap
            while (j < s.size() - 1 && s[j + 1] == ch)
            {
                j++;
            }

            //Store the maximum length of all windows
            int currentLength = j - i + 1;
            ans = max(ans, currentLength);

            //Move left pointer by one to slide the window
            i++;

            //If the char at previous position of left pointer was not ch, then that position must
            //have counted as a swap earlier. Now we have a free swap available.
            //Iterate right pointer forward to use that one free swap
            if (j < s.size() - 1 && s[i - 1] != ch)
            {
                j++;
            }
        }

        return ans;
    }

    int main()
    {
        int k;
        cin >> k;
        string s;
        cin >> s;

        if (k >= s.size())
        {
            //If k is larger than s.size() then we can swap all the elements to either A or B
            //and obtain the answer equal to length of string
            cout << s.size();
            return 0;
        }

        //First let us check for longest perfect string of A's then we will find the same for B's and compare
        int ansForA = countMaxWindowSize(s, 'a', k);

        //Now we do the same for B's
        int ansForB = countMaxWindowSize(s, 'b', k);

        //Final answer is max of the two answers obtained above
        cout << max(ansForA, ansForB);

        return 0;
    }

*/