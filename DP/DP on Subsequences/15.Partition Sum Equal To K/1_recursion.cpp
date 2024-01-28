// Saare Subsequences me kisi ek ka bhi sum "K" ke barabar aajaye to "True" return krdo
// TC : O(2^N)
// SC : O(N)

#include<bits/stdc++.h>
using namespace std;

bool fun(int n, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (n == 0)
        return (k == arr[0]);
    bool take = false;
    if (k >= arr[n])
        take = fun(n - 1, k - arr[n], arr);
    int notTake = fun(n - 1, k, arr);

    return take || notTake;
}

int main()
{
    vector<int> arr = {4,3,2,1};
    int n = arr.size();
    // int k = 4;

    // Sabse pehle check karlo ki yadi, totSum even hai yadi nahi hai to false
    // yadi hai to iska matlab do bhaag me baata ja skta hai
    // target = totSum/2, yadi target mil gya to answer true h 

    int totSum = 0;
    for(int i=0;i<n;i++) totSum+=arr[i];
    if(totSum%2!=0) return false;
    int target = totSum / 2;

    cout<< fun(n-1, target, arr);
    return 0;
}