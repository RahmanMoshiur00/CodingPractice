#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define debug   if(0)

int const MAXN = 1e5 + 10;
int const INF = 1e16;

int n, m;
int dist1[MAXN], distN[MAXN];

struct Tuple{
    int first, second, third;
    Tuple(int _first, int _second, int _third){
        first = _first;
        second = _second;
        third = _third;
    }
};


void dijkstra(vector<pair<int,int>> adj[], int source, int dist[])
{
    bool vis[n+5];
    for(int i=0; i<=n; i++){
        vis[i] = false;
        dist[i] = INF;
    }

    dist[source] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(dist[source], source));

    int u, v, w;
    pair<int,int> p;

    while(!pq.empty()){
        p = pq.top();
        pq.pop();

        if(vis[p.second] == true) continue;

        vis[p.second] = true;
        for(auto x : adj[p.second]){
            u = p.second;
            v = x.first;
            w = x.second;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
}


void solve(int test_case)
{
    cin >> n >> m;

    vector<pair<int,int>> adj1[n+5], adjN[n+5];
    int dist1[n+5], distN[n+5];
    bool vis1[n+5], visN[n+5];
    vector<Tuple> vt;
    int u, v, w;

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj1[u].push_back({v, w});
        adjN[v].push_back({u, w});
        vt.push_back(Tuple(u, v, w));
    }

    dijkstra(adj1, 1LL, dist1);
    dijkstra(adjN, n, distN);

    int ans = LLONG_MAX;
    for(int i=0; i<m; i++){
        u = vt[i].first;
        v = vt[i].second;
        w = vt[i].third / 2;
        ans = min(ans, dist1[u] + w + distN[v]);
    }

    cout << ans << endl;
}

int32_t main()
{
    solve(1);
    return 0;
}
