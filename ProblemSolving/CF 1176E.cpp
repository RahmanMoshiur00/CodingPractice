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
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 200010;

vector<int> adj[mxn];
bool vis[mxn];
int level[mxn];
vector<int> ans;
int cnt = 0;

void bfs(int s)
{   queue<int> qu;
    vis[s] = true;
    level[s] = 1;
    cnt = 1;
    qu.push(s);

    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        repit(it, adj[u]){
            int v = *it;
            if(!vis[v]){
                vis[v] = true;
                level[v] = level[u] + 1;
                if(level[v] % 2 == 1) cnt++;
                qu.push(v);
            }
        }
    }
}

void Clear(int n)
{
    rep(i, 0, n+1) vis[i] = false, adj[i].clear();
}

void solve(int tc)
{
    int n, m, u, v; sfi2(n, m);

    Clear(n);

    rep(i, 0, m){
        sfi2(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start_node = 0, max_degree = 0;
    rep(u, 1, n+1){
        if(adj[u].size() > max_degree){
            start_node = u;
            max_degree = adj[u].size();
        }
    }

    bfs(start_node);

    if(cnt <= (n/2)){
        pfin(cnt);
        rep(i, 1, n+1)
            if(level[i] & 1) pfis(i);
        nwl;
    }
    else{
        pfin(n-cnt);
        rep(i, 1, n+1)
            if(!(level[i] & 1)) pfis(i);
        nwl;
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
