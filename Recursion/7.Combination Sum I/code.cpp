#include <bits/stdc++.h>
using namespace std;

void fun(int arr[], int n, int ind, vector<int> &ans, int k)
{
    if (ind == n)
    {
        if (k == 0)
        {
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
        }
        return;
    }

    if (arr[ind] <= k)
    {
        // Choose this element from the array
        ans.push_back(arr[ind]);
        fun(arr, n, ind, ans, k - arr[ind]);
        ans.pop_back();
    }
    // Not to choose this element from the array
    fun(arr, n, ind + 1, ans, k);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 7};
    vector<int> ans;
    int k = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    fun(arr, n, 0, ans, k);
    return 0;
}

// Time Complexity ---> O(k * 2^t)
// {2^N : For all the possiblities,
// N : for printing all the possiblities}

// Space Complexity ---> O(k*x), not sure about the space complexity, it depends upon the combinations