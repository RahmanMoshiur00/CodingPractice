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
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin); i < (end); ++i)
#define per(i, end, begin) for(int i = (end)-1; i >= (begin); --i)
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
#define debug         if( 1 )
#define mxn           205

vector< pair<int, int> > adj[mxn];
int key[mxn];
bool vis[mxn];


pair<int, int> prim(int s)
{
    mem(vis, false); mem(key, INF);
    key[s] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push({key[s], s});

    pair<int, int> ret = {0, 0};
    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        int c = -p.first, u = p.second;
        if(vis[u]) continue;
        vis[u] = true;
        ret.first += c;
        ret.second++;
        repit(it, adj[u]){
            int v = it->first, w = it->second;
            if(!vis[v] and key[v]>w){
                key[v] = w;
                pq.push({-key[v], v});
            }
        }
    }
    return ret;
}

void solve(int tc)
{
    int n, m, u, v, w;
    sfi2(n, m);

    printf("Case "), pfi(tc), pfs(":\n");
    rep(i, 0, m){
        sfi3(u, v, w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        pair<int, int> p = prim(1);

        if(p.second == n){
            pfi(p.first), newl;
        }
        else{
            pfs("-1\n");
        }
    }

    rep(i, 1, n+1) adj[i].clear();
}

int32_t main()
{
    INPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

