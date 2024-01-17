// This is used for tough problems such as N Queen etc. in which two or more number of recursion calls are there

// Here is the example of fibo series:
#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n<=1) return n;
    // Two recursion call are there
    int last = fibo(n-1);
    int slast = fibo(n-2);

    return last+slast;
}
int main()
{
    cout<<fibo(4);
    return 0;
}