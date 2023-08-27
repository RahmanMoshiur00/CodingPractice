#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010, INF = 1e13;
int n, m;
int dist[MXN];

struct tuples{
    int first = 0, second = 0, third = 0;
    tuples(){}
    tuples(int _first, int _second, int _third){
        first = _first;
        second = _second;
        third = _third;
    }
};

vector< tuples > edge;


bool bellman_ford(int s)
{
    for(int i=0; i<=n; i++){
        dist[i] = -INF;
    }

    dist[s] = 0;

    int u, v, w;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            u = edge[j].first, v = edge[j].second, w = edge[j].third;
            if(dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j=0; j<m; j++){
        u = edge[j].first, v = edge[j].second, w = edge[j].third;
        if(dist[u] + w > dist[v]){
            return false; //positive cycle
        }
    }

    return true;
}

void solve(int test_case)
{
    cin >> n >> m;

    int u, v, w;
    for(int i=0; i<m; i++){
       cin >> u >> v >> w;
       edge.push_back(tuples(u, v, w));
    }

    if(bellman_ford(1)){
        cout << dist[n] << endl;
    }
    else{
        cout << -1 << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

