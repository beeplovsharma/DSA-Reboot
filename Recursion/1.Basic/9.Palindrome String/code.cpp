#include<bits/stdc++.h>
using namespace std;

bool fun(string &str,int ind){
    if(ind>=str.size()) return true;

    if(str[ind]!=str[str.size()-ind-1]) return false;

    return fun(str,ind+1);
}
int main()
{
    string str = "COC";
    cout<<fun(str,0)<<endl;
    return 0;
}