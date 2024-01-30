// Array se minimum kitne elements ko pick kare taaki unka sum target ke barabar ho jaye
// TWIST : ek element ko infinite times use kr skte h
// TC ~ greater than O(2^n), bcoz one elem can be used infinite times;
// SC ~ O(target) , bcoz it worst can go ---> choose 1 for target times;

#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> &num, int tar, int ind)
{

    if (tar == 0)
        return 0;
    if (ind == 0)
    {
        if (tar % num[0] == 0)
            return tar / num[0];
        return 1e9;
    }

    int notPick = fun(num, tar, ind - 1);
    int pick = 1e9;
    if (tar >= num[ind])
        pick = 1 + fun(num, tar - num[ind], ind);

    return min(pick, notPick);
}
int main()
{
    vector<int> num = {1,2};
    int x = 11;
    int n = num.size();
    int ans = fun(num, x, n - 1);
    if (ans >= 1e9)
        return -1;
    cout<<ans;
    return 0;
}