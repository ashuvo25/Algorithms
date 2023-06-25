/*Problem Statement
There are 
N sizs, numbered 
1,2,…,N. For each 
i (
1≤i≤N), siz 
i has a weight of 
wi
​and a value of 
vi
Taro has decided to choose some of the 
N sizs and carry them home in a knapsack. The capacity of the knapsack is 
W, which means that the sum of the weights of sizs taken must be at most 
W.
Find the maximum possible sum of the values of sizs that Taro takes home.
Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^9
 1≤wi≤W
1≤vi≤10^3 


input formate:
N W
w1 v1
​w2 v2
Output
Print the maximum possible sum of the values of sizs that Taro takes home.

*/


 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll weight[10005];ll value[1005];

int FinalTake(int siz,ll knap){
    ll profit = 0;
   for (ll outloop = 0;outloop <siz-1;outloop++){
        for(ll i = 0 ;i<  siz - outloop-1;i++){
            if(value[i]<value[i+1]){
                ll temp = value[i];
                value[i]  =  value[i+1];
                value[i+1]= temp;
                ll ttemp=weight[i];
                weight[i]   = weight[i+1];
                weight[i+1]=ttemp;
            }
        }
   }
     for (ll i = 0; i < siz; i++)
    {
        if(weight[i] <= knap){
             knap -= weight[i];
             profit+=value[i];
        }
    }
    return profit;
}

int main(){
 int t;cin>>t;
 ll w;cin>> w;

  for (int  i = 0; i < t; i++)
  {
    cin>> weight[i] >> value[i];
  }
  
  cout<< FinalTake(t,w);
  
    return 0;
}