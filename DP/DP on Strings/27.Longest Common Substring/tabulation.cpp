// Longest Common Substring [IMP]🚀
// adebc | dcadb -----> ad ----> length : 3
// TC : O(N1*N2)
// SC : O(N1*N2)  ~ DP 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "adbebc", t = "dcadb";
    int n1 = s.size(), n2 = t.size();
    // INDEX SHIFTING BY 1
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // NOW BASE CASE WOULD LOOK LIKE :
    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    int maxi = INT_MIN;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {

                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi = max(maxi, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << maxi;

    return 0;
}