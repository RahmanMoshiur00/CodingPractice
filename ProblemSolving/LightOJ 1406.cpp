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
#define mxn           17


vector<int> adj[mxn], trans[mxn];
int scc[mxn], scc_count = 0;
bool vis[mxn];
stack<int> stk;

void dfs(int u)
{
    vis[u] = true;
    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs_scc(int u)
{
    vis[u] = true;
    scc[u] = scc_count;
    repit(it, trans[u]){
        int v = *it;
        if(!vis[v]) dfs_scc(v);
    }
}

void scc_calculation(int n)
{
    memset(vis, false, sizeof vis);
    rep(i, 1, n+1){
        if(!vis[i]) dfs(i);
    }

    scc_count = 0;
    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        debug cout<<stk.top()<<sp;
        int u = stk.top(); stk.pop();
        if(!vis[u]){
            scc_count++;
            dfs_scc(u);
        }
    }
}

int count_roots(int n)
{
    vector<bool> root(scc_count+1, true);
    rep(i, 1, n+1){
        repit(it, adj[i]){
            int v = *it;
            if(scc[i] != scc[v]){
                root[scc[v]] = false;
            }
        }
    }

    int roots = 0;
    rep(i, 1, scc_count+1){
        if(root[i]) roots++;
    }

    return roots;
}

void _init()
{
    rep(i, 0, mxn) adj[i].clear(), trans[i].clear();
    memset(scc, 0, sizeof scc);
}

void solve(int tc)
{
    _init();

    int n, m, u, v;
    sfi2(n, m);

    rep(i, 0, m){
        sfi2(u, v);
        adj[u].push_back(v);
        trans[v].push_back(u);
    }

    scc_calculation(n);

    int roots = count_roots(n);

    pfs("Case "), pfi(tc), pfs(": "), pfi(roots);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

//int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
