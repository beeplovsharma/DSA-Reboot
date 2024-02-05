// Longest Common Subsequence [IMP]🚀
// adebc | dcadb -----> adb ----> length : 3
// TC : O(N1*N2)
// SC : O(N1+N2) ~ DP

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "adebc", t = "dcadb";
    int n1 = s.size(), n2 = t.size();
    vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);

    // for (int i = 0; i <= n1; i++)
    //     prev[0] = 0;
    // for (int j = 0; j <= n2; j++)
    //     dp[0][j] = 0;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    cout << cur[n2];
    return 0;
}