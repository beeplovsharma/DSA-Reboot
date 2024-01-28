// Kisi bhi Subsequences sum "K" ke barabar aajaye to 1 return krdo warna 0
// TC : O(N*K)
// SC : O(N) + O(N*K) ~ Auxiliary + 2D Dp size

#include <bits/stdc++.h>
using namespace std;

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
    sort(arr.begin(), arr.end(), greater<int>()); // ~ for {0,0,1} case
    int target = 5;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << fun(n - 1, target, arr, dp);
    return 0;
}