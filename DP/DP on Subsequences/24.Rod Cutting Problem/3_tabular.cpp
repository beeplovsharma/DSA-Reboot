// It is quite similar to unbounded knapsack
// Ek array hai (1-based indexing) ---> array index : size of rod
// array ka value --->price denote krta hai
// kis tarah array se rods ko choose kre taaki value MAXIMUM ho + rodSize = size of array ho
// TWIST : 1 element ko value infinite baar use kar sakte

#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> arr = {2, 5, 7, 8, 10};
    int n = arr.size();
    int rodLength = n;
    int rS = n;
    vector<vector<int>> dp(n, vector<int>(rS + 1, 0));

    // BASE CASE
    for (int rodSize = 0; rodSize <= rS; rodSize++)
        dp[0][rodSize] = rodSize * arr[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int rodSize = 0; rodSize <= rS; rodSize++)
        {
            int notPick = 0 + dp[ind - 1][rodSize];
            int pick = INT_MIN;
            int len = ind + 1;
            if (rodSize >= len)
                pick = arr[ind] + dp[ind][rodSize - len];
            dp[ind][rodSize] = max(notPick, pick);
        }
    }
    cout << dp[n - 1][rS];
    return 0;
}