#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
//#define int           long long // change here

#define sfi(x)        scanf("%d", &x) // change here
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
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

const int mxn = 30010;

vector< pair<int,int> > adj[mxn];

bool vis1[mxn], vis2[mxn], inCycle[mxn];
int dist1[mxn], dist2[mxn], comp[mxn], components;

void dfs(int u, int wt, int dist[], bool vis[], bool cycle)
{
    dist[u] = wt;
    comp[u] = components;
    vis[u] = true;
    inCycle[u] = cycle;

    repit(it, adj[u]){
        int v = it->first, w = it->second;
        if(!vis[v]){
            dfs(v, wt+w, dist, vis, cycle);
        }
    }
}

void solve(int tc)
{
    int n, m, u, v, w;

    rep(i, 0, mxn){
        dist1[i] = dist2[i] = INF;
        vis1[i] = vis2[i] = false;
        comp[i] = -1;
        inCycle[i] = false;
        adj[i].clear();
    }

    sfi2(n, m);
    rep(i, 0, m){
        sfi3(u, v, w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    components = 0;
    for(int i=1; i<=n; i++){
        if(!vis1[i] && adj[i].size() < 2){
            components++;
            dfs(i, 0, dist1, vis1, false);
        }
    }

    for(int i=1; i<=n; i++) vis2[i] = vis1[i];

    for(int i=1; i<=n; i++){
        if(!vis1[i]){
            components++;
            dfs(i, 0, dist1, vis1, true);
            swap(adj[i][0], adj[i][1]);
            dfs(i, 0, dist2, vis2, true);
        }
    }

    pfs("Case "), pfi(tc), pfs(":\n");
    int q; sfi(q);
    while(q--){
        sfi2(u, v);
        int ans = -1;

        if(comp[u]!=-1 && comp[u]==comp[v]){
            ans = abs(dist1[u] - dist1[v]);
            if(inCycle[u] && inCycle[v]){
                int a = min(dist1[u] + dist2[v], dist1[v] + dist2[u]);
                ans = min(ans, a);
            }
        }

        pfin(ans);
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

