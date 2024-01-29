// Knapsack 0/1 ---> Chor ko is tarah samaan churaana hai ki value sbse high ho aur total weight bhi Bag ke capcity weight "W" ke barabar ya usse kam ho
// TC ~ O(N)
// SC ~ O(N*W) + O(N) ~ DP Vector + Auxiliary Space

#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> wt, vector<int> val, int ind, int W, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (W >= wt[0])
            return val[0];
        return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = fun(wt, val, ind - 1, W, dp);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + fun(wt, val, ind - 1, W - wt[ind], dp);

    return dp[ind][W] = max(pick, notPick);
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int n = wt.size();
    int W = 5;
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << fun(wt, val, n - 1, W, dp);
    return 0;
}