// TWIST : Array Circular hai to, ek saath first aur last element nahi le sakte, yadi liye to wo adjacent hojayega
// Ek house chhor-chhor ke rob karna hai [ek se jyada bhi chhor skte hai], to kis tarah se robbing kiya jaaye ki Sabse Jyada Paisa Ho Apun Ke Paas !

// Ques 5 me do array bhejo 1>. Jisme Last Element Gayab Ho, 2>. Jisme First Element Gayab Ho
// Fir Unka Max Lelo

#include <bits/stdc++.h>
using namespace std;
int fun(int ind, vector<int> arr)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + fun(ind - 2, arr);
    int notPick = fun(ind - 1, arr);

    return max(pick, notPick);
}
int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> temp1,temp2;

    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1) temp2.push_back(arr[i]);
    }

    cout<<max(fun(n-1,temp1),fun(n-1,temp2));
    return 0;
}