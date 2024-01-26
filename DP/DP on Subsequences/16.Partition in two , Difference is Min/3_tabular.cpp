// Ques : Array ko do bhaag me baato, s1 & s2 --> sum of elements in first & second array's elements
// (s1-s2) must be minimum.
// Soln : Saare Subsequences me kisi ek ka bhi sum "K" yahan [K = totSum of array elem] ke barabar aajaye to "True" return krdo
// Chuki 2D Grid me last row me alag alag target ke T/F value stored rehte hai.
// Isliye (target : 0--->k) dp[n-1][target] se minimum nikaal lenge
// TC : O(N*K)
// SC : O(N*K) ~ (dp size stack)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {8, 6, 5};
    int n = arr.size();

    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    int k = totSum; //---> Target

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;
            if (target >= arr[i])
                take = dp[i - 1][target - arr[i]];
            int notTake = dp[i - 1][target];

            dp[i][target] = (take | notTake);
        }
    }

    int mini = 1e9;

    for (int s1 = 0; s1 <= totSum; s1++)
    {
        if (dp[n - 1][s1])
        {
            int s2 = totSum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    cout << mini;
    return 0;
}