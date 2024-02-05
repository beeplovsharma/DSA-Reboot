// Longest Common Subsequence [IMP]🚀
// adebc | dcadb -----> adb ----> length : 3
// TC : O(N1*N2)
// SC : O(N1*N2) + O(N1+N2) ~ DP + Auxiliary(N1 for S1 & N2 for S2)

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, string s, string t, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 1 + fun(i - 1, j - 1, s, t, dp);

    return dp[i][j] = max(fun(i - 1, j, s, t, dp), fun(i, j - 1, s, t, dp));
}

int main()
{
    string s = "adebc", t = "dcadb";
    int n1 = s.size(), n2 = t.size();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout << fun(n1 - 1, n2 - 1, s, t, dp);
    
    return 0;
}