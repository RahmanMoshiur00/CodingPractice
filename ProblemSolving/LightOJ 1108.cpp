#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))

#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           1010


struct node{
    int u, v, w;
    node(int _u, int _v, int _w){
        u = _u, v = _v, w = _w;
    }
};

vector<int> adj[mxn];
vector< node > edge;
set<int> cycle;
int dist[mxn], n, m;
bool vis[mxn];

void build_graph()
{
    sfi2(n, m);

    int u, v, w;
    rep(i, 0, m){
        sfi3(u, v, w);
        adj[v].push_back(u);
        edge.push_back({v, u, w});
    }
    rep(i, 0, n){
        edge.push_back({n, i, 0});
    }
}

void dfs(int u)
{
    vis[u] = true;
    cycle.insert(u);

    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs(v);
    }
}

void bellmanFord(int source)
{

    mem(dist, INF);
    dist[source] = 0;

    rep(i, 0, n){
        bool relaxed = false;
        repit(it, edge){
            int u = it->u, v = it->v, w = it->w;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                relaxed = true;
            }
        }
        if(!relaxed) return;
    }

    repit(it, edge){
        int u = it->u, v = it->v, w = it->w;
        if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;

            if(!vis[v]) dfs(v); // u and v nodes are both in negative cycle
            if(!vis[u]) dfs(u); //
        }
    }
}

void clear_memory()
{
    rep(i, 0, mxn) adj[i].clear();
    cycle.clear();
    edge.clear();
    setmem(vis, false);
}

void solve(int tc)
{
    clear_memory();

    build_graph();

    bellmanFord(n);

    pfs("Case "), pfi(tc), pfs(":");
    if(cycle.empty()) puts(" impossible");
    else{
        repit(it, cycle) space, pfi(*it); newl;
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
