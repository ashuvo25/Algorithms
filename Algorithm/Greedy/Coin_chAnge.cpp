 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;

#define ll long long

/*
  you are given an array of Denomination and a value X,
  You need to fund the minimum number of coins required 
  to make value X.
*/


void coinChange(vector<int> &arr,int x){
    
       int count = 0;
       int coin  = 0;
      int total_coin = 0;
        sort(arr.begin(),arr.end(),greater<int>()); 
        for (int i = 0; i < arr.size(); i++)
        {
            if(arr[i] <= x){
                coin = x/arr[i];
                
                x = x - (coin*arr[i]);
                cout<<"\nCoins: " << arr[i] << " Needs:"<<coin<<" X Updated to :"<<x;
                total_coin+=coin;
            }
        }
        cout<< "\nTotal Coin: "<<total_coin <<endl;
        
          
}

int main()
{

     int X;cin>>X; 
     int t;cin>>t;
    vector<int> arr(t);
    for (int i = 0; i < t; i++)
    {
       cin>> arr[i];
    }
   coinChange(arr,X);
    return 0;
}