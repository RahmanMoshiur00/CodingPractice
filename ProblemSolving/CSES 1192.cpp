#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 1010;

bool vis[mxn][mxn];

bool isPossible(int i, int j, int n, int m, string adj[])
{
    if(i>=0 && i<n && j>=0 && j<m && adj[i][j]=='.') return true;
    else return false;
}

void dfs(int i, int j, int n, int m, string adj[])
{
    vis[i][j] = true;
    if(isPossible(i+1, j, n, m, adj) && !vis[i+1][j]){
        dfs(i+1, j, n, m, adj);
    }
    if(isPossible(i-1, j, n, m, adj) && !vis[i-1][j]){
        dfs(i-1, j, n, m, adj);
    }
    if(isPossible(i, j+1, n, m, adj) && !vis[i][j+1]){
        dfs(i, j+1,n, m, adj);
    }
    if(isPossible(i, j-1, n, m, adj) && !vis[i][j-1]){
        dfs(i, j-1, n, m, adj);
    }
}

void solve(int test_case)
{
    int n, m;
    cin >> n >> m;

    string str[n];
    for(int i=0; i<n; i++) cin >> str[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = false;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && str[i][j]=='.'){
                dfs(i, j, n, m, str);
                ans++;
            }
        }
    }

    cout << ans << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

