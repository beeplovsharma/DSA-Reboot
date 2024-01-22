#include <bits/stdc++.h>
using namespace std;
int fun(int arr[], int n,int k)
{
    if (n == 0)
        return 0;
    
    int minSteps = INT_MAX;
    
    for(int i=1;i<=k;i++){
        int jumps=0;
        if(n-i>=0)
         jumps = fun(arr,n-i,k)+abs(arr[n]-arr[n-i]);
        minSteps = min(minSteps,jumps);
    }
    return minSteps;
}
int main()
{
    int arr[] = {30, 10, 60, 10, 60, 50};
    int n = 6;
    int k = 2;
    cout << fun(arr, n, k) << endl;
    return 0;
}