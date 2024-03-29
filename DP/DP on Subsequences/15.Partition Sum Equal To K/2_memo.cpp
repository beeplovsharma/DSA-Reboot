// Saare Subsequences me kisi ek ka bhi sum "K" ke barabar aajaye to "True" return krdo
// TC : O(N*K)
// SC : O(N*K) + O(N) ~ (dp size stack + auxiliary stack)

#include <bits/stdc++.h>
using namespace std;

bool fun(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (n == 0)
        return (k == arr[0]);
    if (dp[n][k] != -1)
        return dp[n][k];

    bool take = false;
    if (k >= arr[n])
        take = fun(n - 1, k - arr[n], arr, dp);
    int notTake = fun(n - 1, k, arr, dp);

    return dp[n][k] = (take | notTake);
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    int n = arr.size();

    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    if (totSum % 2 != 0)
        return false;
    int target = totSum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    cout << fun(n - 1, target, arr, dp);
    return 0;
}