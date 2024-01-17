#include<bits/stdc++.h>
using namespace std;
int fun(int i, int sum){
    if(i==0) return sum;
    return fun(i-1,sum+i);
}
int main()
{
    int n=5;
    cout<<fun(6,0);
    return 0;
}