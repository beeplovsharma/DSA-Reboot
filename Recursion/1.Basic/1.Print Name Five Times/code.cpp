#include<bits/stdc++.h>
using namespace std;
void fun(int n){
    if(n==0) return;
    cout<<"Beeplov\n";
    fun(n-1);
}
int main()
{
    fun(5);
    return 0;
}