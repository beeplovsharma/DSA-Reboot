#include <bits/stdc++.h>
using namespace std;

void fun(int arr[], int n, int ind, vector<int> &ans,int k,int sum)
{
    if (ind == n)
    {
        if(sum == k){

          for(auto x:ans) cout << x <<" ";
          cout<<endl;
        }
        return;
    }

    // Choose this element from the array
    ans.push_back(arr[ind]);
    sum+=arr[ind];
    fun(arr,n,ind+1,ans,k,sum);
    sum-=arr[ind];
    ans.pop_back();

    // Not to choose this element from the array
    fun(arr,n,ind+1,ans,k,sum);
}
int main()
{
    int arr[] = {1, 2, 3, 4,7};
    vector<int> ans;
    int k = 7,sum=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    fun(arr, n, 0, ans,k,sum);
    return 0;
}

// Time Complexity ---> O(N * 2^N)
// {2^N : For all the possiblities,
// N : for printing all the possiblities}

// Space Complexity ---> O(N), not more than "N" recursions are waiting in the call stack