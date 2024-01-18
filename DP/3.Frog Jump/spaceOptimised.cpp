#include <bits/stdc++.h>
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
    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    int prev = 0;
    int prev2 = 0;
    int curr = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        // dp[i] = curr
        // dp[i-1] = prev
        // dp[i-2] = prev2

        int left = prev + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(arr[i] - arr[i - 2]);
        curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    cout << curr;
    return 0;
}