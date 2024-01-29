#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> wt, vector<int> val, int ind, int W)
{
    if (ind == 0)
    {
        if (W >= wt[0])
            return val[0];
        return 0;
    }


    int notPick = fun(wt, val, ind - 1, W);
    int pick = -1e9;
    pick = val[ind] + fun(wt, val, ind - 1, W - wt[ind]);

    return max(pick, notPick);
}

int main()
{
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    int n = wt.size();
    int W =5;
    cout<< fun(wt,val,n-1,W);
    return 0;
}