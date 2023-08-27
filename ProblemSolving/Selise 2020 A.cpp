#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

vector<int> adj[mxn], trans[mxn];
stack<int> stk;
int scc[mxn], scc_count = 0;
bool vis[mxn];

void dfs(int u)
{
    vis[u] = true;
    for(int i=0, sz = adj[u].size(); i<sz; i++){
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs_scc(int u)
{
    scc[u] = scc_count;
    vis[u] = true;
    for(int i=0, sz = trans[u].size(); i<sz; i++){
        int v = trans[u][i];
        if(!vis[v]) dfs_scc(v);
    }
}

void scc_calculation(int n)
{
    memset(vis, false, sizeof vis);
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i);
    }

    scc_count = 0; // counts total number of scc's
    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        int u = stk.top(); stk.pop();
        if(!vis[u]){
            scc_count++;
            dfs_scc(u);
        }
    }
}

void clear_all()
{
    for(int i=0; i<mxn; i++){
        adj[i].clear();
        trans[i].clear();
        vis[i] = false;
    }
    scc_count = 0;
}

void solve(int test_case)
{
    clear_all();
    int n, m, u, v;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        trans[v].push_back(u);
    }

    scc_calculation(n);

    cout << "Case " << test_case << ": " << min(0, scc_count-2)  << endl;
}


int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}
