
// LightOJ 1300 - Odd Personality

#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin); i < (end); ++i)
#define per(i, end, begin) for(int i = (end)-1; i >= (begin); --i)
#define mem(a, v)     for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
#define memset(a, v)  memset((a), v, sizeof(a))
#define mxn           10010

vector<int> adj[mxn];
int dis[mxn], low[mxn], par[mxn], tym = 0;
set< pair<int, int> > bridge;


//=============================================== START ====================================================//
int biColNodes = 0;
bool vis[mxn], color[mxn];
//================================================ ENDS =====================================================//


//=============================================== START ====================================================//
bool isBicolorable(int u, int col) // checks if bi-colorable, because cycle with odd nodes cannot be bi-colored
{
    if(vis[u]) return (color[u] == col);

    vis[u] = true; // vis[] tracks if any node is visited
    color[u] = col; // col[] indicates color of nodes

    biColNodes++; // biColNodes this is a globally variable set to zero before calling this(isBicolorable) function;
           // biColNodes counts the number of nodes that can be bicolored if bicoloring is possible

    bool biCol = true;
    repit(it, adj[u]){
        int v = *it;

        // biCol &= isBicolorable(v, color[u]^1); // do that line and erase next if(!bridge.count({min(u, v), max(u, v)})) block

        if(!bridge.count({min(u, v), max(u, v)})){ // this if block is required because of the problem; eliminating edges, as we cannot pass an edge twice
            biCol &= isBicolorable(v, color[u]^1);
        }
    }

    return biCol;
}
//================================================ ENDS =====================================================//



void ArticulationBridge(int u) //finds articulation bridges
{
    vis[u] = true;
    low[u] = dis[u] = ++tym;

    repit(it, adj[u])
    {
        int v = *it;
        if(par[u] == v){
            continue;
        }
        if(vis[v]){ //back edge
            low[u] = min(low[u], dis[v]);
        }
        if(!vis[v]){
            par[v] = u;
            ArticulationBridge(v);
            low[u] = min(low[u], low[v]);

            if(dis[u]<low[v]){ //u-v is an articulation bridge
                bridge.insert({min(u, v), max(u, v)});
            }
        }
    }
}

void solve(int tc)
{
    int n, m, u, v;
    cin>>n>>m;

    rep(i, 0, m){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tym = 0;
    memset(vis, false); mem(par, -1);
    rep(i, 0, n) ArticulationBridge(i);


    //=============================================== START ====================================================//
    rep(i, 0, mxn) color[i] = vis[i] = false;
    int ans = 0; //total bicolorable nodes
    rep(i, 0, n){
        biColNodes = 0;
        if(!vis[i]){
            if(!isBicolorable(i, 0)) ans += biColNodes;
        }
    }
    //================================================ ENDS =====================================================//


    cout<<"Case "<<tc<<": "<<ans<<endl;

    rep(i, 0, n) adj[i].clear();
    bridge.clear();
}

int32_t main()
{
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

