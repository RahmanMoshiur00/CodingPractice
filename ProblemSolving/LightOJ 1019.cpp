#include <bits/stdc++.h>
using namespace std;
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INF           1000000007
#define mxn           110

vector< pair<int, int> > adj[mxn];
bool vis[mxn];
int dist[mxn];

void dijkstra(int s)
{
    rep(i, 0, mxn) vis[i] = false , dist[i] = INF;
    dist[s] = 0;
    priority_queue< pair<int,int> > pq;
    pq.push({0, s});

    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        rep(i, 0, adj[u].size()){
            int v = adj[u][i].first , w = adj[u][i].second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

void solve(int t){
    int n, m, u, v, w, s;
    cin>>n>>m;

    rep(i, 0, m){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1);

    if(dist[n] == INF) cout<<"Case "<<t<<": Impossible"<<endl;
    else cout<<"Case "<<t<<": "<<dist[n]<<endl;

    rep(i, 0, mxn) adj[i].clear();
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


