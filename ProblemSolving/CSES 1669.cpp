#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

vector<int> adj[mxn];
int color[mxn];
int parent[mxn], depth[mxn];
bool isCycle = false;
int min_depth = INT_MAX, cu = 0, cv = 0; // cycle back-edge

void dfs(int u)
{
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
        if(color[u] == color[v] && parent[u]!=v){
            isCycle = true;
            if(depth[u] - depth[v] + 1 < min_depth){
                min_depth = depth[u] - depth[v] + 1;
                cu = u;
                cv = v;
            }


            debug cout << "back-edge: " << cu << ' ' << cv << endl;
        }
    }
    color[u] = 2;
}

void print_path(int u, int v, int cnt)
{
    if(u == v){
        cout << cnt << endl;
        cout << u;
        return;
    }

    print_path(parent[u], v, cnt+1);
    cout << ' ' << u;

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
            depth[i] = 0;
            dfs(i);
        }
    }

    if(isCycle == true){
        print_path(cu, cv, 2);
        cout << ' ' << cv << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

