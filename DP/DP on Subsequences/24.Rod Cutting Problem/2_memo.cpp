// It is quite similar to unbounded knapsack
// Ek array hai (1-based indexing) ---> array index : size of rod
// array ka value --->price denote krta hai
// kis tarah array se rods ko choose kre taaki value MAXIMUM ho + rodSize = size of array ho
// TWIST : 1 element ko value infinite baar use kar sakte

#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int ind, int rodSize, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (rodSize * arr[0]);
    }

    if (dp[ind][rodSize] != -1)
        return dp[ind][rodSize];

    int notPick = 0 + fun(arr, ind - 1, rodSize, dp);
    int pick = INT_MIN;
    int len = ind + 1;
    if (rodSize >= len)
        pick = arr[ind] + fun(arr, ind, rodSize - len, dp);

    return dp[ind][rodSize] = max(notPick, pick);
}
int main()
{
    vector<int> arr = {2, 5, 7, 8, 10};
    int n = arr.size();
    int rodLength = n;
    vector<vector<int>> dp(n, vector<int>(rodLength + 1, -1));
    cout << fun(arr, n - 1, rodLength,dp) << endl;
    return 0;
}