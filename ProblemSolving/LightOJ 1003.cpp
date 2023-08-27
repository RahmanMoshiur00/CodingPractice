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
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define mem(a, v)     memset((a), v, sizeof(a))
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
#define mxn           10010

vector<int> adj[mxn];
bool vis[mxn], inStack[mxn], isCycle = false;

void dfs(int u)
{
    vis[u] = inStack[u] = true;

    repit(it, adj[u]){
        int v = *it;
        if(!vis[v]) dfs(v);
        else if(inStack[v]) isCycle = true;
    }

    inStack[u] = false;
}

void solve(int tc)
{
    int m, n = 0; cin>>m;
    map<string, int> idx;

    string u, v;
    rep(i, 0, m){
        cin>>u>>v;
        if(idx.find(u) == idx.end()) idx[u] = n++;
        if(idx.find(v) == idx.end()) idx[v] = n++;
        adj[idx[u]].push_back(idx[v]);
    }

    cout<<"Case "<<tc<<": ";

    mem(vis, false);
    mem(inStack, false);

    rep(i, 0, n){
        isCycle = false;
        dfs(i);
        if(isCycle) break;
    }

    if(isCycle) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    rep(i, 0, n) adj[i].clear();
    idx.clear();
}

int32_t main()
{
    //INPUT
    FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

