#include<bits/stdc++.h>
using namespace std;

void fun(int arr[],int n,int ind,vector<int>&ans){
    if(ind==n){
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;

        if(ans.size()==0) cout<<"{}"<<endl;
        return;
    }

    // Pick this element from the array
    ans.push_back(arr[ind]);
    fun(arr,n,ind+1,ans);
    ans.pop_back();
    // Not picking this element from the array
    fun(arr, n, ind + 1, ans);

}
int main()
{
    int arr[] = {1,2,3,4};
    vector<int>ans;
    int n = sizeof(arr)/sizeof(arr[0]);
    fun(arr,n,0,ans);
    return 0;
}

// Time Complexity ---> O(N * 2^N)
// {2^N : For all the possiblities,
// N : for printing all the possiblities}

// Space Complexity ---> O(N), not more than "N" recursions are waiting in the call stack