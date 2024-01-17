#include <bits/stdc++.h>
using namespace std;
void fun(int n)
{
    if (n == 0)
        return;
    fun(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    fun(5);
    return 0;
}