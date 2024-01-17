#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
//  int fibo(int n){
//      if(n<=1) return n;
//      return fibo(n-1)+fibo(n-2);
//  }

// 2. Memoization Technique
//  int fibo(int n,vector<int>& dp){
//      if(n<=1) return n;

//     if(dp[n]!=-1) return dp[n];

//     return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
// }
// TC : O(N) SC : O(N) + O(N)

// 3.Tabulation Methods
// int fibo(int n,vector<int>& dp){
//     dp[0]=0, dp[1] = 1;
//     for(int i=2;i<=n;i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     return dp[n];
// }
// TC : O(N), SC : O(N)

// 4.Space Optimisation
int fibo(int n)
{
    int prev2 = 0, prev = 1, curr = -1;
    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
// TC : O(N), SC : O(1)
int main()
{
    int n = 7;

    // Array ke saare indices me -1 kaise put kare?
    // int dp[n+1];
    // memset(dp,-1,sizeof dp);

    // Vector ke saare indices me -1 kaise put kare?
    vector<int> dp(n + 1, -1);
    // cout<<fibo(n,dp)<<endl;
    cout << fibo(n);
    return 0;
}