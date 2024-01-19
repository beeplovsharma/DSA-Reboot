#include <bits/stdc++.h>
using namespace std;
int fun(int ind, int arr[],vector<int> &dp)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    if(dp[ind]!= -1) return dp[ind];

    int pick = arr[ind] + fun(ind - 2, arr,dp);
    int notPick = fun(ind - 1, arr,dp);

    return dp[ind]=max(pick, notPick);
}
int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> dp(n+1,-1);
    cout << fun(n - 1, arr,dp) << endl;
    return 0;
}