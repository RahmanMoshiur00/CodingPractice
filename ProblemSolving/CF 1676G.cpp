#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 4005;

vector<int> adj[mxn];
char color[mxn];
bool vis[mxn];
int white[mxn], black[mxn];


int dfs_black(int u)
{
    vis[u] = true;
    if(color[u] == 'B') black[u] = 1;

    for(auto &v : adj[u]){
        if(!vis[v]){
            black[u] += dfs_black(v);
        }
    }
    return black[u];
}

int dfs_white(int u)
{
    vis[u] = true;
    if(color[u] == 'W') white[u] = 1;

    for(auto &v : adj[u]){
        if(!vis[v]){
            white[u] += dfs_white(v);
        }
    }
    return white[u];
}

void solve(int test_case)
{
    int n;
    cin >> n;

    for(int i=0; i<=n; i++){
        adj[i].clear();
        vis[i] = false;
        white[i] = black[i] = 0;
        color[i] = '-';
    }

    int u, v;
    for(int i=2; i<=n; i++){
        cin >> u;
        v = i;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++) cin >> color[i];

    black[1] = dfs_black(1);
    for(int i=0; i<=n; i++) vis[i] = false;
    white[1] = dfs_white(1);

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(black[i] == white[i]){
            ans++;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

