#include<bits/stdc++.h>
using namespace std;
int fun(int ind,int arr[])
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + fun(ind - 2, arr);
    int notPick = fun(ind - 1, arr);

    return max(pick, notPick);
}
int main()
{
    int arr[] = {2,1,4,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<fun(n-1,arr)<<endl;
    return 0;
}