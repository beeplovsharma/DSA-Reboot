#include<bits/stdc++.h>
using namespace std;

int fun(int i,int fact){
    if(i==1) return fact;

    return fun(i-1,fact*i);
}
int main()
{
    int n=5;
    cout<<fun(n,1);
    return 0;
}