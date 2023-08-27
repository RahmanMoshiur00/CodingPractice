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
#define debug         if( 0 )
#define mxn           50010

vector<int> adj[mxn], trans[mxn], scc_graph[mxn];
stack<int> stk;
int scc[mxn], nodes_in_scc[mxn], dp[mxn], scc_count = 0, n;
bool vis[mxn];

void dfs(int u){
    vis[u] = true;
    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

int dfs_scc(int u)
{
    vis[u] = true;
    scc[u] = scc_count;

    int total_node = 1;

    repit(it, trans[u]){
        int v = *it;
        if(!vis[v]){
            total_node += dfs_scc(v);
        }
    }

    return total_node;
}

void scc_calculation()
{
    setmem(vis, false);
    rep(i, 1, n+1){
        if(!vis[i]){
            dfs(i);
        }
    }

    scc_count = 0;
    setmem(vis, false);
    while(!stk.empty()){
        int u = stk.top(); stk.pop();
        if(!vis[u]){
            scc_count++;
            nodes_in_scc[ scc_count ] = dfs_scc(u);
        }
    }
}

void build_scc_graph()
{
    rep(u, 1, n+1){
        repit(it, adj[u]){
            int v = *it;
            if(scc[u] != scc[v]){
                scc_graph[ scc[u] ].push_back(scc[v]);
            }
        }
    }
}

int dfs_dp(int u)
{
    if(dp[u] != -1) return dp[u];

    int total = nodes_in_scc[u];
    repit(it, scc_graph[u]){
        int v = *it;
        total += dfs_dp(v);
    }
    dp[u] = total;

    return dp[u];
}

void solve(int tc)
{
    sfi(n);

    int u, v;
    rep(i, 0, n){
        sfi2(u, v);
        adj[u].push_back(v);
        trans[v].push_back(u);
    }

    scc_calculation();

    build_scc_graph();


    setmem(dp, -1);
    rep(u, 1, scc_count+1){ // finding total number of reachable nodes from component u
        dp[u] = dfs_dp(u);
    }

    int res = 0, ans = 0;
    rep(i, 1, n+1){
        if(dp[ scc[i] ] > res){
            res = dp[ scc[i] ];
            ans = i;
        }
    }


    pfs("Case "), pfi(tc), pfs(": "), pfi(ans), newl;

    rep(i, 0, n+1){
        adj[i].clear();
        trans[i].clear();
        scc_graph[i].clear();
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
