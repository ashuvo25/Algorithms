 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[100] ;
int fibo(ll n){
    if(n == 1 || n ==0){
        return n;
    }
   if(dp[n] != -1) return dp[n];
    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
 int t;cin>>t;
   ll fib = fibo(t);
   cout<< fib;
   return 0;
}