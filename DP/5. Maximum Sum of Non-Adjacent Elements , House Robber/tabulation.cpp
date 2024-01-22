#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>dp(n+1,-1);
    dp[0] = arr[0];

    for(int i=1;i<n;i++){
        int pick = arr[i];
        if(i>=2)
            pick = arr[i] + dp[i-2];
        int notPick = dp[i-1];
        dp[i] = max(pick,notPick);
    }
    cout << dp[n-1];
    return 0;
}