// Kisi bhi Subsequences sum "K" ke barabar aajaye to 1 return krdo warna 0
// TC : O(2^N)
// SC : O(N)

#include <bits/stdc++.h>
using namespace std;

int fun(int n, int k, vector<int> &arr)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return (k == arr[0]);
    int take = 0;
    if (k >= arr[n])
        take = fun(n - 1, k - arr[n], arr);
    int notTake = fun(n - 1, k, arr);

    return (take + notTake);
}

int main()
{
    vector<int> arr = {1,4,4,5};
    sort(arr.begin(), arr.end(), greater<int>()); // ~ for {0,0,1} case
    int n = arr.size();
    int target = 5;
    cout << fun(n - 1, target, arr);
    return 0;
}