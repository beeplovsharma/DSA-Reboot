// starting pt ---> fixed, but, ending pt ---> not fixed
// down & diagonal chalenge solve krne ke liye
// (0,0) se last row tak jaane ko total ways kitna hoga???
// Jis Path me Sum sabse minimum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &mat, int n, vector<vector<int>> &dp)
{
    if (i == (n - 1))
        return mat[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = mat[i][j] + fun(i + 1, j, mat, n, dp);
    int diag = mat[i][j] + fun(i + 1, j + 1, mat, n, dp);

    return dp[i][j] = min(down, diag);
}
int main()
{
    vector<vector<int>> arr = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n, -1));
    cout << fun(0, 0, arr,n,dp );
    return 0;
}

// TC : O(n*n)
// SC : O(n) + O(n*n) --> Recursion Stack Space + DP Vector Space