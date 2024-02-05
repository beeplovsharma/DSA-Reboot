#include <bits/stdc++.h>
using namespace std;

int fun(int ind, int W, vector<int> &val, vector<int> &wt)
{

    if (ind == 0)
    {
        if (W >= wt[0])
            return (int(W / wt[0]) * val[0]);
    }

    int notPick = fun(ind - 1, W, val, wt);
    int pick = INT_MIN;
    if (W >= wt[ind])
        pick = val[ind] + fun(ind, W - wt[ind], val, wt);

    return max(pick, notPick);
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int n = wt.size();
    int W = 10;
    cout << fun(n - 1, W, val, wt);
    return 0;
}