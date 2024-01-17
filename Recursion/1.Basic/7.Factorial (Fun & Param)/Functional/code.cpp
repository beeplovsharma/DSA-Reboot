#include<bits/stdc++.h>
using namespace std;
int fun(int n){
    if(n==1) return 1;

    return n * fun(n-1);
}
int main()
{
    int n = 5;
    cout<<fun(5);
    return 0;
}