// Kisi bhi Subsequences sum "K" ke barabar aajaye to 1 return krdo warna 0
// TC : O(N*K)
// SC :  O(N*K) ~ Auxiliary + 2D Dp size

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int fun(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return (k == arr[0]);
    if (dp[n][k] != -1)
        return dp[n][k];
    int take = 0;
    if (k >= arr[n])
        take = fun(n - 1, k - arr[n], arr, dp);
    int notTake = fun(n - 1, k, arr, dp);

    return dp[n][k] = (take + notTake);
}

int main()
{
    vector<int> arr = {1, 4, 4, 5};
    int n = arr.size();
    int k = 5;
    sort(arr.begin(), arr.end(), greater<int>()); // ~ for {0,0,1} case
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // BASE CASE ~ for target==0
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    // BASE CASE ~ for index ==0
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
            int notPick = dp[i - 1][target]; // fun(arr,ind-1,k,dp);
            int pick = 0;
            if (target >= arr[i])
                pick = dp[i - 1][target - arr[i]]; // fun(arr,ind-1,k-arr[ind],dp);

            dp[i][target] = (pick + notPick) % mod;
        }
    }
    cout<< dp[n - 1][k];

    return 0;
}