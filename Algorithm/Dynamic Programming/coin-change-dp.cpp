 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<int>dp(10010,-1);
int amounts(int amount,vector<int>& coins){
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if(amount - coins[i]  >=0)
        mini =min(mini+0LL, amounts(amount - coins[i] ,coins)+1LL);
        
    }
   return dp[amount] = mini; 
}

int change(int amount, vector<int>& coins) {
    
     int mini = amounts(amount,coins);
    if(mini >= INT_MAX ) return -1;
    return mini;
    // return mini >= INT_MAX ? -1 : mini;
}

int main()
{
 int t;cin>>t;
 int amount ;cin>>amount;
    vector<int> coins(t);
    for(int i = 0 ;i<t;i++){
        cin >> coins[i];
    }
    cout<<change(amount,coins) <<endl;
    return 0;
}