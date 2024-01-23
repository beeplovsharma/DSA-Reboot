// MICROSOFT QUESTION
// (0,0) se (m-1,n-1) tak jaane ko total ways kitna hoga???
// Jis Path me Sum sabse minimum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return arr[0][0];
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int left = arr[i][j] + fun(i, j - 1, arr, dp);
    int up = arr[i][j] + fun(i - 1, j, arr, dp);

    return dp[i][j] = min(left, up);
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << fun(2, 2, arr, dp);
    return 0;
}

// TC : O(m*n)
// SC : O((m-1)+(n-1)) + O(m*n)