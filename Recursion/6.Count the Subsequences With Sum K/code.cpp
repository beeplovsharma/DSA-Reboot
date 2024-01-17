#include<bits/stdc++.h>
using namespace std;
int fun(int arr[],int n,int ind,int k,int sum,vector<int>&ans){

    if(sum > k) return 0; // It is for reducing the Time Complexity

    if(ind==n){
        if(sum==k){
            return 1;
        }
        return 0;
    }

    ans.push_back(arr[ind]);
    sum += arr[ind];
    int left = fun(arr,n,ind+1,k,sum,ans);
    ans.pop_back();
    sum -= arr[ind];
    int right = fun(arr,n,ind+1,k,sum,ans);


    return left+right;

}
int main()
{
    int arr[] = {1,2,3,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    vector<int>ans;
    cout<<fun(arr,n,0,k,0,ans);
    return 0;
}

// Time Complexity : 2^n