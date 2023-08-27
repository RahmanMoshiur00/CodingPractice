#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 7

const int mxn = 100;

vector< pair<int,int> > adj[mxn];

int prim(int source)
{
    bool vis[mxn];
    int key[mxn];
    for(int i=0; i<mxn; i++) vis[i] = false, key[i] = INF;

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    key[source] = 0;
    pq.push({source, key[source]});

    int mst = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int u = p.first, c = p.second;

        if(vis[u]) continue;
        else vis[u] = true;

        mst += c;

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(!vis[v] && w < key[v]){
                key[v] = w;
                pq.push({v, key[v]});
            }
        }
    }

    return mst;
}

int main()
{
    int n, m;
    cin>>n>>m;

    int u, v, w;

    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mst = prim(1);

    cout<<"mst : "<<mst<<endl;
}
/*
4 6
1 1 -1
1 2 3
1 3 5
1 4 6
2 4 2
3 4 7
*/
