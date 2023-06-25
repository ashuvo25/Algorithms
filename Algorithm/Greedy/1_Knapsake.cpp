 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll weight[100005]; ll price[100005];


ll knapsack(ll item, ll capa_city){
    ll profit = 0;
   for (ll outloop = 0;outloop <item-1;outloop++){
        for(ll i = 0 ;i<  item - outloop-1;i++){
            if(price[i]<price[i+1]){
                ll temp = price[i];
                price[i]  =  price[i+1];
                price[i+1]= temp;
                ll ttemp=weight[i];
                weight[i]   = weight[i+1];
                weight[i+1]=ttemp;
            }
        }
    }
    // for (ll i = 0; i < item; i++)
    // {
    //    cout << weight[i] << " " << price[i] <<endl;
    // }
    for (ll i = 0; i < item; i++)
    {
        if(weight[i] <= capa_city){
             capa_city -= weight[i];
             profit+=price[i];
        }
    }
    return profit;
}

int main()
{
 ll item;cin>>item;
 ll capa_city ;cin>> capa_city;
  for (ll i = 0; i < item; i++)
  {
    cin>> weight[i]>>price[i];
  }
 cout<< knapsack(item,capa_city);
    return 0;
}