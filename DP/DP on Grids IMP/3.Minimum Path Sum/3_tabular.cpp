// MICROSOFT QUESTION
// (0,0) se (m-1,n-1) tak jaane ko total ways kitna hoga???
// Jis Path me Sum sabse minimum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = arr[i][j];

            else
            {
                int left = arr[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left = 1e9;

                int up = arr[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up = 1e9;

                dp[i][j] = min(left, up);
            }
        }
    }
    cout << dp[m - 1][n - 1];
    return 0;
}

// TC : O(n*m)
// SC : O(n*m)