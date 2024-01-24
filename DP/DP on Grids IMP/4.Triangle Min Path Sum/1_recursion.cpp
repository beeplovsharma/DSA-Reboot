// starting pt ---> fixed, but, ending pt ---> not fixed
// down & diagonal chalenge solve krne ke liye 
// (0,0) se last row tak jaane ko total ways kitna hoga???
// Jis Path me Sum sabse minimum aaye, us SUM ko return karo.

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<vector<int>> &mat, int n)
{
    if (i == (n - 1))
        return mat[i][j];

    int down = mat[i][j] + fun(i + 1, j, mat, n);
    int diag = mat[i][j] + fun(i + 1, j + 1, mat, n);

    return min(down, diag);
}
int main()
{
    vector<vector<int>> arr = {{1}, {2,3}, {3,6,7},{8,9,6,10}};
    cout << fun(0,0, arr,arr.size());
    return 0;
}

// TC : O(2^(n*m))
// SC : O((m-1)+(n-1))