#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> dp(n + 1, -1);
    int prev = arr[0];
    int prev2 = 0;
    int curr = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = 0;
        if (i >= 2)
            pick = arr[i] + prev2;
        int notPick = prev;
        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    cout << curr;
    return 0;
}