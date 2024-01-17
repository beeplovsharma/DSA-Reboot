#include<bits/stdc++.h>
using namespace std;
void fun(int n,int i){
    if(i==n+1) return;
    cout<<i<<" ";
    fun(n,i+1);
}
int main()
{
    int n;
    fun(6,1);
    return 0;
}