// It is quite similar to unbounded knapsack
// Ek array hai (1-based indexing) ---> array index : size of rod
// array ka value --->price denote krta hai
// kis tarah array se rods ko choose kre taaki value MAXIMUM ho + rodSize = size of array ho
// TWIST : 1 element ko value infinite baar use kar sakte

#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr,int ind,int rodLength){
    int len = ind+1; // due to 1-based indexing

    if(ind==0){
        if(rodLength%len==0) return (rodLength/len)*arr[0];
    }

    int notPick = 0 + fun(arr,ind-1,rodLength);
    int pick = INT_MIN;
    if(rodLength>=len)
        pick = arr[ind] + fun(arr,ind-1,rodLength-len);

    return max(notPick,pick);
}
int main()
{
    vector<int> arr = {2,5,7,8,10};
    int n = arr.size();
    int rodLength=n;
    cout<<fun(arr,n-1,rodLength)<<endl;
    return 0;
}