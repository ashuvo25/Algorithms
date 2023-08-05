 /*******************বিসমিল্লাহির রাহমানির রাহিম **********************/
 /*__________________ MD ASADUZZAMAN SHUVO ______________________ */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9+10;
const int N = 1e5+10;

 vector<pair<int,int>> graph[N];
 vector<int>parent(N);

void path_print(vector<int> parent, int s, int d)
{
    if (s == d) cout << s;
    else {
        path_print(parent, s, parent[d]);
        cout << " -> " << d;
    }
}


void dijkstra(int source) {
    vector<int> visited(N,0);
    vector<int> distance(N,INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,source});
    distance[source] = 0;
    parent[source] = source;

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int v = node.second;
        int dist = node.first;
        if(visited[v] == 1) continue;
        visited[v] =  1;
        for(auto c  : graph[v]){
            int child_v = c.first;
            int wt = c.second;
            if(distance[v] + wt < distance[child_v]){
                distance[child_v] = distance[v] + wt;
                parent[child_v] = v;
                pq.push({distance[child_v],child_v});
            } 
        }
    }
}

void init(){
    int V,E ;cin>>V>>E;
   for (int i = 0; i < E; i++) {
   
    int u , v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
  int source,destination;
  cin>>source>>destination;
    dijkstra(source);
   path_print(parent,source,destination); 

}

int main()
{
   
   init();

    return 0;
}