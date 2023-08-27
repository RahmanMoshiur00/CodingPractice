#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 30010;

vector< pair<int,int> > adj[mxn];
bool vis[mxn];
int component[mxn], n , e, weight[mxn], component_weight[mxn];

void dfs(int u, int cmp)
{
    int v, w;
    component[u] = cmp;
    vis[u] = true;
    for(auto &x : adj[u]){
        v = x.first, w = x.second;
        if(!vis[v]){
            weight[v] = weight[u] + w;
            dfs(v, cmp);
        }
    }
}

void dfs_cycle(int u, int s, int cmp)
{
    int v, w;
    component[u] = cmp;
    vis[u] = true;
    for(auto &x : adj[u]){
        v = x.first, w = x.second;
        if(v == s){
            component_weight[cmp] += w;
        }
        if(!vis[v]){
            weight[v] = weight[u] + w;
            component_weight[cmp] += w;
            dfs_cycle(v, s, cmp);
        }
    }
}


void value_init()
{

    for(int i=0; i<=n; i++){
        adj[i].clear();
        vis[i] = false;
        weight[i] = 0;
        component_weight[i] = -1;
        component[i] = 0;
    }
}

void solve(int test_case)
{
    int u, v, w;
    cin >> n >> e;

    value_init();

    for(int i=0; i<e; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int comp_count = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 0 && !vis[i]){
            component[i] = comp_count++;
        }
        else if(adj[i].size() == 1 && !vis[i]){
            comp_count++;
            dfs(i, comp_count);
        }
    }
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 2 && !vis[i]){
            comp_count++;
            component_weight[comp_count] = 0;
            dfs_cycle(i, i, comp_count);
            component_weight[comp_count] -= adj[i][0].second;
        }
    }

    int q;
    cin >> q;

    cout << "Case " << test_case << ":" << endl;
    while(q--){
        cin >> u >> v;
        if(component[u] == component[v]){
            if(component_weight[component[v]] != -1){ //cycle
                debug cout << "check: " << u << " " << v << " " << component_weight[component[u]] << endl;
                cout << min(abs(weight[v]-weight[u]), component_weight[component[u]] - abs(weight[v]-weight[u])) << endl;
            }
            else{ // chain
                cout << abs(weight[v]-weight[u]) << endl;
            }
        }
        else{
            cout << -1 << endl;
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

