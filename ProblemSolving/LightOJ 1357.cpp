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
#define debug         if( 0 )
#define mxn           100010

int n;
vector<int> adj[mxn];
int inupper[mxn], inlower[mxn];
bool vis[mxn];

void init()
{
    rep(i, 0, mxn) adj[i].clear();
    setmem(inupper, 0);
    setmem(inlower, 0);
}

void bfs(int s)
{
    queue<int> qu;
    qu.push(s);

    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        vis[u] = true;
        repit(it, adj[u]){
            int v = *it;
            if(!vis[v]){
                inupper[v] = inupper[u] + 1;
                qu.push(v);
            }
        }
    }
}

int dfs(int u)
{
    vis[u] = true;

    int tot = 0;
    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]){
            tot += 1 + dfs(v);
        }
    }

    return inlower[u] = tot;
}

void build_graph()
{
    sfi(n);

    int u, v;
    rep(i, 0, n-1){
        sfi2(u, v);
        adj[u].push_back(v);
    }
}

void solve(int tc)
{
    init();

    build_graph();

    setmem(vis, false);
    bfs(1);

    setmem(vis, false);
    dfs(1);

    int ans = 0;
    rep(i, 1, n+1){
        ans += n - (inupper[i] + inlower[i] + 1);
    }

    ans /= 2;

    pfs("Case "), pfi(tc), pfs(": "), pfi(n-1), space, pfin(ans);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

