#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define pfi(x)        printf("%lld", (intl)x)
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
#define rep(i, begin, end) for(int i = (begin); i < (end); i = i+1)
#define per(i, end, begin) for(int i = (end)-1; i >= (begin); i = i-1)
#define mem(a, v)     for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
#define setval(a, v)  memset((a), v, sizeof(a))
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
#define mxn           110

vector<pair<int, pair<int, int> > > edge;
int par[mxn];

void setRep() // set representative of i as i initially
{
    rep(i, 0, mxn) par[i] = i;
}

int findRep(int u) // finds representative of i
{
    if(par[u] == u) return u;
    par[u] = findRep(par[u]);
    return par[u];
}

int kruskal()
{
    int res = 0;

    setRep();

    rep(i, 0, edge.size()){ // processing all edges in non-decreasing order
        int w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        int ru = findRep(u);
        int rv = findRep(v);
        if(ru != rv){
            par[ru] = rv;
            res += w;
        }
    }

    return res;
}

int kruskal_max()
{
    int res = 0;

    setRep();

    per(i, edge.size(), 0){
        int w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;

        int ru = findRep(u);
        int rv = findRep(v);

        if(ru != rv){
            par[ru] = rv;
            res += w;
        }
    }

    return res;
}

void solve(int tc)
{
    int n; cin>>n;

    debug watch(n);

    int u, v, w;
    while(true){
        cin>>u>>v>>w;
        debug cout<<"check: "<<u<<sp<<v<<sp<<w<<endl;
        if(u==0 and v==0 and w==0) break;
        edge.push_back({w, {u, v}});
    }

    sort(all(edge));

    int mst = kruskal();

    debug watch(mst);

    int mxst = kruskal_max();

    debug watch(mxst);

    int res = mst + mxst;

    debug watch(res);

    cout<<"Case "<<tc<<": ";
    if(res % 2) cout<<res<<"/2"<<endl;
    else cout<<res/2<<endl;

    edge.clear();
}

int32_t main()
{
    //INPUT
    FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

