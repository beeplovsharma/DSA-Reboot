// (0,0) se (m-1,n-1) tak jaane ko total ways kitna hoga???
// TWIST/CONSTRAINT : yadi matrix ke kisi element me -1 hua to us path se nahi jana hai.

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &arr)
{
    if (i >= 0 && j >= 0 && arr[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    int left = fun(i, j - 1, arr);
    int up = fun(i - 1, j, arr);

    return left + up;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    cout << fun(2, 2, arr);
    return 0;
}

// TC : O(2^(n*m))
// SC : O((m-1)+(n-1))