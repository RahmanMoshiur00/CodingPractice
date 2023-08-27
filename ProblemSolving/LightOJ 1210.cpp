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
#define mem(a, v)     for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
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
#define mxn           20010

int inDegree[mxn], outDegree[mxn], n, m;

vector<int> adj[mxn]; // actual graph
vector<int> trans[mxn]; // transpose graph
stack<int> stk; // holds greatest finishing time nodes in top and least in the bottom
int scc[mxn]; // scc[i] denotes the scc number of node i
int scc_count = 0; // counts total number of scc's
bool vis[mxn]; // visited checker

void dfs(int u)
{
    vis[u] = true;
    for(int i=0, sz = adj[u].size(); i<sz; i++){
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs_scc(int u)
{
    scc[u] = scc_count;
    vis[u] = true;
    for(int i=0, sz = trans[u].size(); i<sz; i++){
        int v = trans[u][i];
        if(!vis[v]) dfs_scc(v);
    }
}

void find_scc()
{
    memset(vis, false, sizeof vis);
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i);
    }

    scc_count = 0; // counts total number of scc's
    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        int u = stk.top(); stk.pop();
        if(!vis[u]){
            scc_count++;
            dfs_scc(u);
        }
    }
}

void solve(int tc)
{
    int u, v;
    sfi2(n, m);

    rep(i, 0, m){
        sfi2(u, v);
        u--; v--;
        adj[u].push_back(v);
        trans[v].push_back(u);
    }

    find_scc();

    int ans = 0;

    if(scc_count == 1) ans = 0;
    else{
        mem(inDegree, 0); mem(outDegree, 0);
        rep(u, 0, n){
            repit(it, adj[u]){
                int v = *it;
                if(scc[u] != scc[v]){
                    outDegree[ scc[u] ] ++;
                    inDegree[ scc[v] ]++;
                }
            }
        }

        int incnt = 0, outcnt = 0;
        rep(i, 1, scc_count+1){
            if(inDegree[i] == 0) incnt++;
            if(outDegree[i] == 0) outcnt++;
        }

        ans = max(incnt, outcnt);
    }

    pfs("Case "), pfi(tc), pfs(": "), pfi(ans), newl;

    rep(i, 0, n) adj[i].clear(), trans[i].clear();
}

int32_t main()
{
    //INPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

