#include<iostream>
using namespace std;

int lcm(string a,string b,int i,int j){

    if(i == a.length())
        return 0;
    if(j == b.length())
        return 0;

    int res =0;

    if(a[i] == b[j])
        res = 1 + lcm(a,b,i+1,j+1);
    else
        res = max(lcm(a,b,i+1,j),lcm(a,b,i,j+1));
    return res;

}

int main()
{
    string s1;cin>>s1;
    string s2;cin>>s2;

    int ans = lcm(s1,s2,0,0);
    cout << ans <<endl;
    return 0;

}
