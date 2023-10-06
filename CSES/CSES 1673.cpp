#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define debug   if(0)

const int MXN = 2510, INF = 1e14;
int n = MXN, m = MXN;
bool vis1[MXN], vis2[MXN];
vector<int> adj1[MXN], adj2[MXN];
vector<pair<int,pair<int,int> > > edge;
int dist[MXN];

void dfs1(int u)
{
    vis1[u] = true;
    for(auto v : adj1[u]){
        if(!vis1[v]){
            dfs1(v);
        }
    }
}

void dfs2(int u)
{
    vis2[u] = true;
    for(auto v : adj2[u]){
        if(!vis2[v]){
            dfs2(v);
        }
    }
}

void init()
{
    for(int i=0; i<MXN; i++){
        adj1[i].clear();
        adj2[i].clear();
        vis1[i] = vis2[i] = false;
        dist[i] = -INF;
    }
    edge.clear();
}

int32_t main()
{
    cin >> n >> m;

    init();

    int u, v, w;

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
        edge.push_back({u, {v, w}});
    }

    dfs1(1);
    dfs2(n);

    dist[1] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            u = edge[j].first, v = edge[j].second.first, w = edge[j].second.second;
            if(dist[u]+w > dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    bool notPossible = false;

    for(int j=0; j<m; j++){
        u = edge[j].first, v = edge[j].second.first, w = edge[j].second.second;
        if(dist[u]+w > dist[v] && ((vis1[u] && vis2[u]) || (vis1[v] && vis2[v]))){
            notPossible = true;
            break;
        }
    }

    if(notPossible){
        cout << -1 << endl;
    }
    else{
        cout << dist[n] << endl;
    }

    return 0;
}
