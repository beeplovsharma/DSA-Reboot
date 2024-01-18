#include <bits/stdc++.h>
using namespace std;
int fun(int arr[], int n)
{
    if (n == 0)
        return 0;

    int left = fun(arr, n - 1) + abs(arr[n] - arr[n - 1]);
    int right = INT_MAX;
    if (n > 1)
    {
        right = fun(arr, n - 2) + abs(arr[n] - arr[n - 2]);
    }
    return min(left, right);
}
int main()
{ 
    int arr[] = {30,10,60,10,60,50};
    int n = 6;
    cout << fun(arr, n - 1) << endl;
    return 0;
}