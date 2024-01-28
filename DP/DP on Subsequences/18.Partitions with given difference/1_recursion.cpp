// how many subsets are available such that (s1-s2) = d, d is given, s1>s2
// Tip : s2 = (totSum - d)/2;
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
    vector<int> arr = {1,1,1,1};
    sort(arr.begin(), arr.end(), greater<int>()); // ~ for {0,0,1} case
    int n = arr.size();
    int d = 0;

    int totSum = 0;
    for(auto x:arr){
        totSum += x;
    }
    if(totSum-d < 0 || (totSum-d)%2) return false;
    cout << fun(n - 1, (totSum-d)/2, arr);
    return 0;
}