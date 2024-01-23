// (0,0) se (m-1,n-1) tak jaane ko total ways kitna hoga???

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &arr,vector<vector<int>>&dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int left = fun(i, j - 1, arr,dp);
    int up = fun(i - 1, j, arr,dp);

    return dp[i][j] = left + up;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    int m = 3 , n=3;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout << fun(m-1,n-1, arr,dp);
    return 0;
}

// TC : O(n*m)
// SC : O((m-1)+(n-1)) + O(m*n) --> for auxiliary space + dp array