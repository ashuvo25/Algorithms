 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(vector<int>&a,vector<int>&b){
    return a[1]<=b[1];
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> v;

    ///for input

    for(int i = 0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y}); 
    }
    ///for sorting basis of y
    sort(v.begin(),v.end() , comp);
    
    ///counting possible work
     int free_time = 0;
     int work = 0;
    for (int i = 0; i < n; i++)
    {
         if(free_time <= v[i][0]){  
              work++;
              free_time = v[i][1];
         }
    } 
     cout<< work << endl;
    return 0;
}