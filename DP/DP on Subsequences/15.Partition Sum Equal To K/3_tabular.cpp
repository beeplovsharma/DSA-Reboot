// Saare Subsequences me kisi ek ka bhi sum "K" ke barabar aajaye to "True" return krdo
// TC : O(N*K)
// SC : O(N*K) ~ (dp size stack)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    int n = arr.size();
    // int k = 4;

    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    if (totSum % 2 != 0)
        return false;
    int k = totSum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if(arr[0]<=k) dp[0][arr[0]] = true; // arr[0] must be equal to or less than target itself, only then it is true.

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
    cout << dp[n - 1][k];
    return 0;
}