#include <bits/stdc++.h>
using namespace std;

int fun(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (W >= wt[0])
            return (W / wt[0] * val[0]);
        else
            return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = fun(ind - 1, W, val, wt, dp);
    int pick = INT_MIN;
    if (W >= wt[ind])
        pick = val[ind] + fun(ind, W - wt[ind], val, wt, dp);

    return dp[ind][W] = max(pick, notPick);
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int n = wt.size();
    int W = 10;
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << fun(n - 1, W, val, wt,dp);
    return 0;
}