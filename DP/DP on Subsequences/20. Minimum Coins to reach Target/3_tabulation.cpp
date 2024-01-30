// Array se minimum kitne elements ko pick kare taaki unka sum target ke barabar ho jaye
// TWIST : ek element ko infinite times use kr skte h
// TC ~ greater than O(target * N), bcoz one elem can be used infinite times;
// SC ~ O(target) + O(target * N) , bcoz it worst can go ---> choose 1 for target times;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> num = {1, 2};
    int x = 11;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    // Target Wala Base Case, T=0
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    // Index Wala Base Case
    for (int tar = 0; tar <= x; tar++)
    {
        if (tar % num[0] == 0)
        {
            dp[0][tar] = tar / num[0];
        }

        else
            dp[0][tar] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= x; tar++)
        {
            int notPick = dp[ind - 1][tar];
            int pick = 1e9;
            if (tar >= num[ind])
                pick = 1 + dp[ind][tar - num[ind]];

            dp[ind][tar] = min(pick, notPick);
        }
    }
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    cout << ans;
    return 0;
}