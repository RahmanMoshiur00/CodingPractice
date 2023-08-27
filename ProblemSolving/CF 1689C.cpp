#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 300010;

vector<int> adj[mxn];
bool vis[mxn];
int sz[mxn], child[mxn], height[mxn];

void dfs(int u)
{
    vis[u] = true;
    sz[u] = 1;
    child[u] = 0;
    height[u] = 0;
    for(auto &v : adj[u]){
        if(!vis[v]){
            dfs(v);
            sz[u] += sz[v];
            child[u]++;
            height[u] = max(height[u], height[v]+1);
        }
    }
}

int bfs(int s, bool vis[])
{
    vis[s] = true;
    queue<int> qu;
    qu.push(s);
    int ans = 0, u, cnt = 0, lft, rgt;

    while(!qu.empty()){
        u = qu.front(); qu.pop();
        if(child[u] == 0) break;
        else if(child[u] == 1){
            for(auto &v : adj[u]){
                if(!vis[v]){
                    ans += sz[v] - 1;
                }
            }
            break;
        }
        else{
            cnt = 0;
            for(auto &v: adj[u]){
                if(!vis[v]){
                    if(cnt == 0){
                        lft = v;
                        cnt++;
                    }
                    else{
                        rgt = v;
                    }
                }
            }
            if(sz[lft] == sz[rgt]){ // the problem is here

                if(bfs(lft, vis) >= bfs(rgt, vis)){
                    vis[lft] = true;
                    qu.push(lft);
                    ans += sz[rgt] - 1;
                }
                else{
                    vis[rgt] = true;
                    qu.push(rgt);
                    ans += sz[lft] - 1;
                }
            }
            else if(sz[lft] > sz[rgt]){
                vis[rgt] = true;
                qu.push(rgt);
                ans += sz[lft] - 1;
            }
            else{
                vis[lft] = true;
                qu.push(lft);
                ans += sz[rgt] - 1;
            }
        }
    }

    return ans;
}

void solve(int test_case)
{
    int n;
    cin >> n;

    // initialization
    for(int i=0; i<=n; i++){
        adj[i].clear();
        vis[i] = false;
        sz[i] = 0;
        child[i] = 0;
        height[i] = 0;
    }

    int u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for(int i=0; i<=n; i++) vis[i] = false;

    debug{
        for(int i=1; i<=n; i++){
            cout << "for " << i << ": " << sz[i] << ' ' << height[i] << ' ' << child[i] << endl;
        }
    }

    int ans = bfs(1, vis);

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

