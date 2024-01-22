#include<bits/stdc++.h>
using namespace std;
int fun(int arr[],int n,vector<int>&dp){
    if (n == 0)
        return 0;

    if(dp[n]!=-1) return dp[n];

    int left = fun(arr, n - 1,dp) + abs(arr[n] - arr[n - 1]);
    int right = INT_MAX;
    if (n > 1)
    {
        right = fun(arr, n - 2,dp) + abs(arr[n] - arr[n - 2]);
    }
    return dp[n] = min(left, right);
}
int main()
{
    int arr[] = {30, 10, 60, 10, 60, 50};
    int n = 6;
    vector<int>dp(n+1,-1);
    cout<<fun(arr, n - 1,dp);
    return 0;
}

// TC : O(N)
// SC : O(N) + O(N)