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
bool vis[mxn];
int path[mxn];

bool bfs(int beg, int dest)
{
    queue<int> qu;
    qu.push(beg);
    vis[beg] = true;

    int u, v;
    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        if(u == dest) return true;
        for(int v : adj[u]){
            if(!vis[v]){
                qu.push(v);
                vis[v] = true;
                path[v] = u;
            }
        }
    }

    return false;
}

void print_path(int u, int cnt)
{
    if(u == 1){
        cout << cnt+1 << endl;
        cout << 1;
        return;
    }
    print_path(path[u], cnt+1);
    cout << ' ' << u ;
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

    if(bfs(1, n) == true){
        print_path(n, 0);
        cout << endl;
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

