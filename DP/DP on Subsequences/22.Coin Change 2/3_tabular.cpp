// Array se total kitne tareeke se elements ko pick kare taaki unka sum target ke barabar ho jaye
// Count all the possibilities
// TWIST : ek element ko infinite times use kr skte h
// TC ~ greater than O(N*Target), bcoz one elem can be used infinite times;
// SC ~ O(N*target) , bcoz it worst can go ---> choose 1 for target times;

#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> arr = {1, 2, 3};
    int value = 4;
    int n = arr.size();
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    // return fun(denominations,n-1,value,dp);
    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = 1;

    for (int tar = 0; tar <= value; tar++)
    {
        if (tar % arr[0] == 0)
            dp[0][tar] = 1;
        else
            dp[0][tar] = 0;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= value; tar++)
        {
            long notPick = dp[ind - 1][tar];
            long pick = 0;
            if (tar >= arr[ind])
                pick = dp[ind][tar - arr[ind]];

            dp[ind][tar] = pick + notPick;
        }
    }

    cout << dp[n - 1][value];
    return 0;
}