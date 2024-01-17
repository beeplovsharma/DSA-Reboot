// 🚀 will solve this problem later on using matrix exponential

#include<bits/stdc++.h>
using namespace std;

int fun(int n){
    // Zero ya First Seedhi par raha to bas ek tarika hoga jump karne ka
    if(n==0 || n==1) return 1;

    int left = fun(n-1);
    int right = fun(n-2);

    return left+right;
}
int main()
{
    // No of stairs
    int n=4;
    cout<<fun(n);
    return 0;
}