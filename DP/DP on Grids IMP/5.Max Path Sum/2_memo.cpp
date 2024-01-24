// DREAM11 Question
// starting pt ---> not fixed, and, ending pt ---> not fixed
// u,left digonal & right diagonal chalenge solve krne ke liye
// last row ke har ek column se pehle row tak jaao,
// Jis Path me Sum sabse maximum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= matrix[0].size())
        return -1e8;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + fun(i - 1, j, matrix, dp);
    int ldiag = matrix[i][j] + fun(i - 1, j - 1, matrix, dp);
    int rdiag = matrix[i][j] + fun(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max(up, max(ldiag, rdiag));
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, fun(n - 1, j, arr,dp));
    }
    cout << maxi;
    return 0;
}

// TC : O(3^N) ~ Exponential
// SC : O(N) ~ Recursion Stack Space