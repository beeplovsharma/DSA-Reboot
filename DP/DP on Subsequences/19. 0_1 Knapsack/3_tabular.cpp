// Knapsack 0/1 ---> Chor ko is tarah samaan churaana hai ki value sbse high ho aur total weight bhi Bag ke capcity weight "W" ke barabar ya usse kam ho
// TC ~ O(N)
// SC ~ O(N*W) ~ DP Vector

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int n = weight.size();
    int maxWeight = 5;
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    for (int W = weight[0]; W <= maxWeight; W++)
    {
        dp[0][W] = value[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int notPick = dp[ind - 1][W]; // fun(wt,val,ind-1,W,dp);
            int pick = INT_MIN;
            if (weight[ind] <= W)
                pick = value[ind] + dp[ind - 1][W - weight[ind]]; //+ fun(wt,val,ind-1,W-wt[ind],dp);

            dp[ind][W] = max(pick, notPick);
        }
    }

    cout << dp[n - 1][maxWeight];

    return 0;
}