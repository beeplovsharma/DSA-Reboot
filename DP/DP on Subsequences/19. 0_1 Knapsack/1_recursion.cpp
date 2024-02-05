// Knapsack 0/1 ---> Chor ko is tarah samaan churaana hai ki value sbse high ho aur total weight bhi Bag ke capcity weight "W" ke barabar ya usse kam ho
// TC ~ O(2^N)
// SC ~ O(N)

#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> wt, vector<int> val, int ind, int W)
{
    if (ind == 0)
    {
        if (W >= wt[0])
            return val[0];
        return INT_MIN;
    }

    int notPick = fun(wt, val, ind - 1, W);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + fun(wt, val, ind - 1, W - wt[ind]);

    return max(pick, notPick);
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int n = wt.size();
    int W = 5;
    cout << fun(wt, val, n - 1, W);
    return 0;
}