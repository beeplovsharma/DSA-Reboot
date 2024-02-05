// String ko palindrome banane ke liye, minimum kitne letter ghusedne honge>>?
// string ko reverse karo ----> (LCS function ka use krke max length of common subseq nikaalo)
// ----> ans : (length of string - max length of common subseq nikaalo)
// adebc | dcadb -----> adb ----> length : 3
// TC : O(N1*N2)
// SC : O(N1*N2) ~ DP

#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
    int n1 = s.size(), n2 = t.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}
int main()
{
    string s = "abcdefg";
    string t = s;
    reverse(t.begin(), t.end());
    int longestSubseq = lcs(s, t);
    int n = s.size();
    cout << n - longestSubseq;
    return 0;
}