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

void dfs(int u)
{
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
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

    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            ans.push_back(i);
        }
    }

    if(ans.empty()){
        cout << 0 << endl;
    }
    else{
        cout << ans.size() - 1 << endl;
        for(int i=1; i<ans.size(); i++){
            cout << ans[i-1] << ' ' << ans[i] << endl;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

