// Array se total kitne tareeke se elements ko pick kare taaki unka sum target ke barabar ho jaye
// Count all the possibilities
// TWIST : ek element ko infinite times use kr skte h
// TC ~ greater than O(2^n), bcoz one elem can be used infinite times;
// SC ~ O(target) , bcoz it worst can go ---> choose 1 for target times;

#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &num, int tar, int ind)
{

    if (tar == 0)
        return 1;
    if (ind == 0)
    {
        if (tar % num[0] == 0)
            return 1;
        return 0;
    }

    int notPick = fun(num, tar, ind - 1);
    int pick = 0;
    if (tar >= num[ind])
        pick = fun(num, tar - num[ind], ind);

    return (pick+ notPick);
}
int main()
{
    vector<int> num = {1, 2, 3};
    int x = 4;
    int n = num.size();
    int ans = fun(num, x, n - 1);
    cout << ans;
    return 0;
}