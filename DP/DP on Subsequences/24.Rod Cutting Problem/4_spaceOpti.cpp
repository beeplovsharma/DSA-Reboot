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
    vector<int> prev(rS + 1, 0), cur(rS + 1, 0);
    // BASE CASE
    for (int rodSize = 0; rodSize <= rS; rodSize++)
        prev[rodSize] = rodSize * arr[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int rodSize = 0; rodSize <= rS; rodSize++)
        {
            int notPick = 0 + prev[rodSize];
            int pick = INT_MIN;
            int len = ind + 1;
            if (rodSize >= len)
                pick = arr[ind] + cur[rodSize - len];
            cur[rodSize] = max(notPick, pick);
        }
        prev = cur;
    }
    cout << prev[rS];
    return 0;
}