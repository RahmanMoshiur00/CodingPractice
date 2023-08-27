#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;

vector<int> adj[mxn];
int color[mxn];
bool isPossible = true;

void dfs(int u)
{
    for(int v : adj[u]){
        if(color[v] == 0){
            if(color[u] == 1) color[v] = 2;
            else color[v] = 1;
            dfs(v);
        }
        if(color[u] == color[v]){
            isPossible = false;
        }
    }

}

void solve(int test_case)
{
    int n, m, u, v;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(color[i] == 0){
            color[i] = 1;
            dfs(i);
        }
    }

    if(isPossible == false){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i=1; i<=n; i++){
        if(i!=1) cout << ' ';
        cout << color[i];
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

