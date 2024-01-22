#include<bits/stdc++.h>
using namespace std;
// int fun(int arr[], int n)
// {
//     if (n == 0)
//         return 0;

//     int left = fun(arr, n - 1) + abs(arr[n] - arr[n - 1]);
//     int right = INT_MAX;
//     if (n > 1)
//     {
//         right = fun(arr, n - 2) + abs(arr[n] - arr[n - 2]);
//     }
//     return min(left, right);
// }
int main()
{
    int arr[] = {30, 10, 60, 10, 60, 50};
    int n = 6;
    // Take Reference from recursive function which is mentioned above
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i=1;i<=n-1;i++){
        // Yadi kahi par dp[i-1] aur dp[i-2] raha to waha --> space optimisation hoga !
        int left = dp[i-1]+abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2]+abs(arr[i] - arr[i-2]);
        dp[i] = min(left,right);
    }
    cout<<dp[n-1];
    return 0;
}