// Longest Common Subsequence [IMP]🚀
// adebc | dcadb -----> adb ----> length : 3
// TC : O(2^(N1+N2))
// SC : O(N1+N2) ~ Auxiliary(N1 for S1 & N2 for S2)

#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, string s, string t)
{
    if (i < 0 || j < 0)
        return 0;

    if (s[i] == t[j])
        return 1 + fun(i - 1, j - 1, s, t);

    return max(fun(i - 1, j, s, t), fun(i, j - 1, s, t));
}

int main()
{
    string s = "adebc", t = "dcadb";
    int n1 = s.size(), n2 = t.size();
    cout << fun(n1 - 1, n2 - 1, s, t);

    return 0;
}