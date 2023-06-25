#include<iostream>
#include<vector>
using namespace std;
const int n = 100;
vector <int> ar[n];
bool vis[n];
void dfs(int v){
       vis[v] = true;
     //  if(vis[v]) continue;
     cout<< v <<  " -> ";
     for(int child : ar[v]){
      if(vis[child]) continue;
      //cout<< "Parent :" << v << "-->" << "Child : "<< child <<endl;
      dfs(child);
     }
}
 void init_v(int v1,int v2){
   ar[v1].push_back(v2);
   ar[v2].push_back(v1);
 }

int main()
{
    int v,e;
    cout<< "enter vartices and edges: " ;
    cin >> v>> e;
    for(int i = 0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        init_v(v1,v2);
    }
    dfs(1);
    return 0 ;
}
