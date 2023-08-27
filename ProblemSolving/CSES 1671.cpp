#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010, INF = 1e15;

vector< pair<int,int> > adj[mxn];
bool vis[mxn];
int dist[mxn];


void dijkstra(int s)
{
    dist[s] = 0;
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0, s));

    pair<int,int> p;
    int u, v, w;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        u = p.second;
        if(vis[u] == true) continue;
        vis[u] = true;
        for(auto x : adj[u]){
            v = x.first, w = x.second;
            if(!vis[v] && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
}


void solve(int test_case)
{
    int n, m, u, v, w;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    for(int i=1; i<=n; i++) dist[i] = INF;
    dijkstra(1);

    for(int i=1; i<=n; i++){
        if(i!=1) cout << ' ';
        cout << dist[i];
    } cout << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

