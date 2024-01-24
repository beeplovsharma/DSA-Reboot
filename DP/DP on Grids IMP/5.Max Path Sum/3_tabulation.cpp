// DREAM11 Question
// starting pt ---> not fixed, and, ending pt ---> not fixed
// u,left digonal & right diagonal chalenge solve krne ke liye
// last row ke har ek column se pehle row tak jaao,
// Jis Path me Sum sabse maximum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // BASE CASE
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int ldiag = matrix[i][j];
            if (j >= 1)
                ldiag += dp[i - 1][j - 1];
            else
                ldiag += -1e8;

            int rdiag = matrix[i][j];
            if (j + 1 < m)
                rdiag += dp[i - 1][j + 1];
            else
                rdiag += -1e8;

            dp[i][j] = max(up, max(ldiag, rdiag));
        }
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }

    cout << maxi;

    return 0;
}

// TC : O(3^N) ~ Exponential
// SC : O(N) ~ Recursion Stack Space