#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 1010;

vector<int> adj[mxn], adj_1[mxn];
bool vis[mxn];
int n, k, desc[mxn], child[mxn];

void init()
{
    for(int i=0; i<=n; i++){
        adj[i].clear();
        adj_1[i].clear();
        vis[i] = false;
        desc[i] = 0;
        child[i] = 0;
    }
}

void dfs_1(int u)
{
    vis[u] = true;
    child[u] = 0;
    for(auto &v : adj[u]){
        if(!vis[v]){
            dfs_1(v);
            child[u]++;
        }
    }
}

void dfs_build(int u)
{
    vis[u] = true;
    desc[u] = 1;
    if(child[u] < k) return;
    for(auto &v : adj[u]){
        if(!vis[v]){
            adj_1[u].push_back(v);
            adj_1[v].push_back(u);
            debug cout << u << " -- " << v << endl;
            dfs_build(v);
            desc[u] += desc[v];
        }
    }
}

void dfs_2(int u)
{
    vis[u] = true;
    child[u] = 0;
    for(auto &v : adj_1[u]){
        if(!vis[v]){
            dfs_2(v);
            child[u]++;
        }
    }
}


int bfs_ans(int u)
{
    queue<int> qu;
    qu.push(u);
    vis[u] = true;
    int ans = 1;

    set< pair<int,int> > st;
    while(!qu.empty()){
        u = qu.front(); qu.pop();
        st.clear();
//        debug cout << u << " = " << child[u] << " = " << desc[u] << endl;
//        if(child[u] > k){
//            for(auto &v : adj_1[u]) if(!vis[v]) st.insert(make_pair(desc[v], v));
//            int extra = child[u] - k;
//            while(extra--) st.erase(*st.rbegin());
//        }

        for(auto &v : adj_1[u]){
            if(!vis[v]){
                st.insert(make_pair(desc[v], v));
            }
        }
        int extra = max(0LL, child[u]-k);
        while(extra--) st.erase(st.begin());
        for(auto &x : st){
            qu.push(x.second);
            vis[x.second] = true;
            ans++;
            debug cout << u << " -> " << x.second << endl;
        }

//        for(auto &v : adj_1[u]){
//            if(!vis[v]){
//                if(st.find(make_pair(desc[v], v)) != st.end()){
//                    st.erase(make_pair(desc[v], v));
//                }
//                else{
//                    qu.push(v);
//                    vis[v] = true;
//                    ans++;
//                    debug cout << u << " -> " << v << endl;
//                }
//            }
//        }
    }

    return ans;
}

void solve(int test_case)
{
    init();

    cin >> n >> k;

    int u, v;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_1(1);
    ZERO(vis);
    dfs_build(1);
    ZERO(vis);
    dfs_2(1);
    ZERO(vis);
    int ans = bfs_ans(1);

    cout << "Case " << test_case << ": " << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
1
19 3
1 2
1 3
1 4
1 5
2 6
6 12
6 13
6 14
6 15
6 16
12 17
12 18
14 19
3 7
3 8
3 9
5 10
5 11
*/
