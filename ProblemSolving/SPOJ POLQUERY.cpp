#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;

#define int           long long // change here
#define sfi(x)        scanf("%lld", &x) // change here

#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfs(x)        printf("%s", x)
#define pfnl          printf("\n")
#define pfsp          printf(" ")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(i, x)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setvalue(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 100010;
int n, m;
vector<int> adj[mxn];
set< pair<int,int> > bridge;

bool isArtPoint[mxn];
bool vis[mxn];
int discovery[mxn], low[mxn], parent[mxn], tym = 0, root = -1;

void findArticulationPointAndBridge(int u)
{
    tym++;
    low[u] = discovery[u] = tym;
    vis[u] = true;
    int no_of_child = 0;

    repit(it, adj[u]){
        int v = *it;
        if(v == parent[u]) continue;
        if(vis[v]) low[u] = min(low[u], discovery[v]);
        if(!vis[v]){
            parent[v] = u;
            findArticulationPointAndBridge(v);
            low[u] = min(low[u], low[v]);
            if(discovery[u] <= low[v] && u!=root){ // u is an articulation point
                isArtPoint[u] = true;
            }
            if(discovery[u] < low[v] && u!=root){ // u->v is an articulation bridge
                bridge.insert({min(u, v), max(u, v)});
            }
            no_of_child++;
        }
        if(no_of_child>1 && u==root){ // u is and articulation point and u->v is an articulation bridge
            isArtPoint[u] = true;
            bridge.insert({min(u, v), max(u, v)});
        }
    }
}

void dfs(vector< vector<int> >& adj, bool vis[], int comp[], int u, int component){
    comp[u] = component;
    vis[u] = true;
    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs(adj, vis, comp, v, component);
    }
}

void solve(int tc)
{
    sfi2(n, m);

    int u, v;

    root = -1;
    rep(i, 0, m){
        sfi2(u, v);
        if(root == -1) root = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rep(i, 0, mxn){
        discovery[i] = low[i] = parent[i] = 0;
        vis[i] = isArtPoint[i] = false;
    }

    findArticulationPointAndBridge(root);

    vector< vector<int> > adj_bridge(mxn);
    vector< vector<int> > adj_point(mxn);

    for(int u=1, v; u<=n; u++){
        repit(it, adj[u]){
            v = *it;
            if(bridge.find({min(u, v), max(u, v)}) == bridge.end()){ // u-v is not arti bridge
                adj_bridge[u].push_back(v);
                adj_bridge[v].push_back(u);
            }
            if(isArtPoint[u]==false && isArtPoint[v]==false){ // u & v are not arti points
                adj_point[u].push_back(v);
                adj_point[v].push_back(u);
            }
        }
    }

    bool vis_bridge[mxn], vis_point[mxn];
    int point_comp[mxn], bridge_comp[mxn];
    rep(i, 0, mxn){
        point_comp[i] = bridge_comp[i] = 0;;
        vis_bridge[i] = vis_point[i] = false;
    }
    int comp_bridge = 0, comp_point = 0;
    for(int i=1; i<=n; ++i){
        if(!vis_bridge[i]){
            comp_bridge++;
            dfs(adj_bridge, vis_bridge, bridge_comp, i, comp_bridge);
        }
        if(!vis_point[i]){
            comp_point++;
            dfs(adj_point, vis_point, point_comp, i, comp_point);
        }
    }

    int q, typ, x, y; sfi(q);
    while(q--){
        sfi(typ);
        if(typ == 1){
            sfi2(u, v), sfi2(x, y);
            if(x>y) swap(x, y);
            if(bridge.find({x,y}) != bridge.end()){ // bridge
                if(bridge_comp[x] && bridge_comp[y] && bridge_comp[x] == bridge_comp[y]) puts("da");
                else puts("ne");
            }
            else puts("da");
        }
        else{
            sfi3(u, v, x);
            if(isArtPoint[x]){
                if(point_comp[u] == point_comp[v]) puts("da");
                else puts("ne");
            }
            else puts("da");
        }
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

