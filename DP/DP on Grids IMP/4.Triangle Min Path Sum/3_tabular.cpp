// starting pt ---> fixed, but, ending pt ---> not fixed
// down & diagonal chalenge solve krne ke liye
// (0,0) se last row tak jaane ko total ways kitna hoga???
// Jis Path me Sum sabse minimum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> triangle = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int i = 0, j = 0;
    // BASE CASE
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diag);
        }
    }

    cout<<dp[0][0];
}

// TC : O(n*n)
// SC : O(n*n)