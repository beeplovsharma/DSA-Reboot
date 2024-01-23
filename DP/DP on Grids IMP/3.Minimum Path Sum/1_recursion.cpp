// MICROSOFT QUESTION
// (0,0) se (m-1,n-1) tak jaane ko total ways kitna hoga???
// Jis Path me Sum sabse minimum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &arr)
{
    if (i == 0 && j == 0)
        return arr[0][0];
    if (i < 0 || j < 0)
        return 1e9;

    int left = arr[i][j] + fun(i, j - 1, arr);
    int up = arr[i][j] + fun(i - 1, j, arr);

    return min(left, up);
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    // cout<<"ROW:"<<arr.size()<<endl;
    // cout<<"COL:"<<arr[0].size()<<endl;
    cout << fun(2, 2, arr);
    return 0;
}

// TC : O(2^(n*m))
// SC : O((m-1)+(n-1))