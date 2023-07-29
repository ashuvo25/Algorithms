 /*বিসমিল্লাহির রাহমানির রাহিম */
 /* MD ASADUZZAMAN SHUVO  */

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Disjointset {
  vector<int> parent;
  vector<int> rank;
public:
  Disjointset(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int find_parent(int value) {
    if (value == parent[value]) return value;
    return parent[value] = find_parent(parent[value]);
  }

  void Union(int u, int v) {
    int p_u = find_parent(u);
    int p_v = find_parent(v);
    if (p_u == p_v) return;
    if (rank[p_u] < rank[p_v]) {
      parent[p_u] = p_v;
    } else if (rank[p_u] > rank[p_v]) {
      parent[p_v] = p_u;
    } else {
      parent[p_v] = p_u;
      rank[p_u]++;
    }
  }

  void print() {
    for (int i = 0; i < rank.size(); i++) {
      cout << rank[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < parent.size(); i++) {
      cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < parent.size(); i++) {
      cout << parent[i] << " ";
    }
    cout << endl;
  }
};


int main()
{
 int t;cin>>t;
 while(t--){
    int nodes ;cin>>nodes;
    
    Disjointset ds (nodes);

    /// ...................Before making set ...................////
     cout<< "before Makeing Setes" <<endl;
          
    if(ds.find_parent(3) == ds.find_parent(7)){
        cout<< "Same" <<endl;
    }
    else cout<< "NOT Same" <<endl;

     ds.print();

    for(int i  = 1;i< nodes+1;i++){
        int a,b;cin>>a>>b;
        ds.Union(a, b );
    }
    // ds.Union(1,2);
    // ds.Union(2,3);
    // ds.Union(4,5);
    // ds.Union(6,7);
    // ds.Union(5,6);
    //ds.Union(3,7);
   

    
    // if(ds.find_parent(3) == ds.find_parent(7)){
    //     cout<< "Same" <<endl;
    // }
    // else cout<< "NOT Same" <<endl;


   // ds.Union(3,7);

      /// ...................after making set ...................////

cout<< "After making setes :" <<endl;
    if(ds.find_parent(3) == ds.find_parent(7)){
        cout<< "Same" <<endl;
    }
    else cout<< "NOT Same" <<endl;

    
      ds.print();
 }


    return 0;
}