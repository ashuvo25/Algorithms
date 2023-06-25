
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
#define ll long long
 int steps(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = steps(n-1) + steps(n-2) + steps(n-3);
    return dp[n];
 }
int main()
{
   memset(dp,-1,sizeof(dp));
 int n;cin>> n;
 
 cout<< steps(n);
    return 0;
}