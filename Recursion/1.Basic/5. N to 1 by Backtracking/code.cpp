#include <bits/stdc++.h>
using namespace std;
void fun(int n,int i)
{
   if(n==i) return;
   cout<<n<<" ";
   fun(n-1,i);
}
int main()
{
    int n=5;
    fun(n,0);
    return 0;
}