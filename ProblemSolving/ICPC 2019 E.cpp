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
#define debug         if( 1 )

const int mxn = 20010;

struct node{
    int u, v, w;
};

vector<int> adj[mxn];
vector< node > edge;
int st[mxn], ed[mxn];
bool vis[mxn];
int n, tym;

void dfs(int u)
{
    vis[u] = true;
    st[u] = tym++;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    ed[u] = tym++;
}

void solve(int tc)
{
    sfi(n);

    edge.resize(n-1);
    for(int i=0; i<=n; i++) adj[i].clear(), vis[i] = false;

    int u, v, w;
    for(int i=0; i<n-1; i++){
        sfi3(u, v, w);
        edge[i].u = u, edge[i].v = v, edge[i].w = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tym = 0;
    dfs(1LL);

    vector<int> edt(n);
    for(int i=1; i<=n; i++) edt[i-1] = ed[i];
    sort(all(edt));

    int mt = LLONG_MIN, t, nu, nv, tot = 0LL, fr = 0LL;
    for(int i=0; i<n-1; i++){
        u = edge[i].u, v = edge[i].v, w = edge[i].w;
        nu = upper_bound(all(edt), ed[u]) - lower_bound(all(edt), st[u]);
        nv = upper_bound(all(edt), ed[v]) - lower_bound(all(edt), st[v]);
        t = min(nu, nv);
        t = t * (n - t);
        tot += (w * t);
        if(mt < (w * t)){
            mt = (w * t);
            fr = t;
        }
        else if(mt == (w*t) && (fr < t)) fr = t;
    }

    if(tot >= 0){
        printf("Case %lld: 0\n", tc);
        return;
    }

    tot = -tot;
    int ans = tot / fr;
    if(tot % fr != 0) ans++;

    printf("Case %lld: %lld\n", tc, ans);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

