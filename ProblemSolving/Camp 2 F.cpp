#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define all(a)        a.begin(), a.end()
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 1010;

vector<int> adj[mxn], ind[mxn], val[mxn];
bool vis[mxn];
int arr[mxn];

void reset()
{
    for(int i=0; i<mxn; i++){
        adj[i].clear();
        ind[i].clear();
        val[i].clear();
        vis[i] = false;
    }
}

void dfs(int s, int component)
{
    vis[s] = true;
    ind[component].push_back(s);
    val[component].push_back(arr[s]);
    for(auto &v : adj[s]){
        if(!vis[v]) dfs(v, component);
    }
}

void solve(int test_case)
{
    reset();

    int n, k, u, v;
    cin >> n >> k;

    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<k; i++){
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, components);
            sort(all(val[components]));
            sort(all(ind[components]));
            for(int j=0, sz = val[components].size(); j<sz; j++){
                arr[ind[components][j]] = val[components][j];
            }
            components++;
        }
    }

    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << arr[i];
    } cout << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

