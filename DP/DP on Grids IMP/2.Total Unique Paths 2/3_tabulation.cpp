// (0,0) se (m-1,n-1) tak jaane ko total ways kitna hoga???
// TWIST/CONSTRAINT : yadi matrix ke kisi element me -1 hua to us path se nahi jana hai.
int mod = (1e9 + 7);
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, -1, 3}, {3, 4, 5}, {6, 7, 8}};
    int m = 3, n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (i >= 0 && j >= 0 && arr[i][j] == -1)
                dp[i][j] = 0;

            else if (i == 0 && j == 0)
                dp[i][j] = 1;

            else
            {
                int left = 0, up = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                if (i > 0)
                    up = dp[i - 1][j];

                dp[i][j] = (left + up) % mod;
            }
        }
    }

    cout << dp[m-1][n-1];
    return 0;
}

// TC : O(n*m)
// SC : O(m*n)