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
#define memset(a, v)  memset((a), v, sizeof(a))
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
#define mxn           100010

vector<int> adj[mxn];
bool vis[mxn];
vector<int> topsort;

void dfs1(int u)
{
    vis[u] = true;
    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs1(v);
    }
    topsort.push_back(u);
}

void dfs2(int u)
{
    vis[u] = true;
    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs2(v);
    }
}

void solve(int tc)
{
    int n, m, u, v;
    sfi2(n, m);

    rep(i, 0, m){
        sfi2(u, v);
        adj[u].push_back(v);
    }

    mem(vis, false);
    rep(i, 1, n+1){
        if(!vis[i]) dfs1(i);
    }

    int ans = 0;
    mem(vis, false);
    per(i, topsort.size(), 0){
        int v = topsort[i];
        if(!vis[v]){
            dfs2(v);
            ans++;
        }
    }
    pfs("Case "), pfi(tc), pfs(": "), pfi(ans), newl;

    rep(i, 1, n+1) adj[i].clear();
    topsort.clear();
}

int32_t main()
{
    //INPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
