#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld\n", (intl)x)
#define pfis(x)       printf("%lld ", (intl)x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
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
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           205


int busy[mxn];

vector< pair< pair<int, int> , int> > edge;
vector< int > adj[mxn];
int dist[mxn], parent[mxn];
bool vis[mxn];

void dfs_from_neg_cycle(int u)
{
    vis[u] = true;
    dist[u] = -INF;

    for(int i=0, sz = adj[u].size(); i<sz; i++){
        int v = adj[u][i];
        if(!vis[v]) dfs_from_neg_cycle(v);
    }
}

void bellmanFord(int n, int m, int source)
{
    for(int i=0; i<n; i++) dist[i] = INF;

    dist[source] = 0;
    for(int i=0; i<n-1; i++){
        bool relaxation = false;
        for(int j=0; j<m; j++){
            int u = edge[j].first.first, v = edge[j].first.second, w = edge[j].second;
            if(dist[u]!=INF && dist[v]>dist[u]+w){ // checking dist[u]!=INF is necessary; say u is not reachable from source and u->v has negative weight -w, then dist[v] will be updated as (INF-w); which is surely wrong
                parent[v] = u;
                dist[v] = dist[u] + w;
                relaxation = true;
            }
        }
        if(!relaxation) break; // no relaxation made in this iteration; so no relaxation will happen further
    }

    set<int> negCycle; // storing nodes of negative cycles

    bool isNegCycle = false;
    for(int j=0; j<m; j++){
        int u = edge[j].first.first, v = edge[j].first.second, w = edge[j].second;
        if(dist[u]!=INF && dist[v]>dist[u] + w){
            dist[v] = dist[u] + w;
            negCycle.insert(u); // u & v nodes are part of negative cycle
            negCycle.insert(v);
            isNegCycle = true;
        }
    }

    if(isNegCycle){
        memset(vis, false, sizeof vis);
        for(auto u : negCycle){
            if(!vis[u]) dfs_from_neg_cycle(u);
        }
    }
}

void solve(int tc)
{
    int n, m, u, v, b;
    sfi(n);
    rep(i, 0, n) sfi(busy[i]);

    sfi(m);

    rep(i, 0, m){
        sfi2(u, v);
        u--, v--;

        adj[u].push_back(v);
        b = busy[v] - busy[u];
        edge.push_back({{u, v} , b*b*b});
    }

    bellmanFord(n, m, 0);

    int query; sfi(query);
    pfs("Case "), pfi(tc), puts(":");
    while(query--){
        sfi(v);
        v--;
        if(dist[v]<3 or dist[v]==INF) puts("?");
        else pfin(dist[v]);
    }

    rep(i, 0, n) adj[i].clear();
    edge.clear();
}

int32_t main()
{
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

