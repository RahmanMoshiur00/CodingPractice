#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 505, INF = 1e16;

int adj[MXN][MXN], dist[MXN][MXN];

void floyd_warshall(int n)
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(dist[k][i]+dist[i][j]<dist[k][j]){
                    dist[k][j] = dist[k][i]+dist[i][j];
                }
            }
        }
    }
}

void solve(int test_case)
{
    int n, m, q, u, v, w;
    cin >> n >> m >> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    floyd_warshall(n);

    for(int i=0; i<q; i++){
        cin >> u >> v;
        if(dist[u][v] == INF) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

