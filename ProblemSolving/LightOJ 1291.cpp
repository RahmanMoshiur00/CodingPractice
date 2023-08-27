#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define sfi(x)        scanf("%d", &x)
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
#define rep(i, begin, end) for(__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for(__typeof(end) i = (end)-1; i >= (begin); i -= 1)
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
#define mxn           10010

vector<int> adj[mxn];
set< pair<int, int> > bridge;
bool vis[mxn];
int dis[mxn], low[mxn], parent[mxn], tym = 0;

bool bfs(int s)
{
    int bridges = 0;
    queue<int> q;

    vis[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        repit(it, adj[u]){
            int v = *it;
            if(bridge.count({min(u, v), max(u, v)})){
                bridges++;
                continue;
            }
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }

    return (bridges == 1);
}

void ArticulationBridge(int u) //finds articulation bridges
{
    vis[u] = true;
    low[u] = dis[u] = ++tym;

    repit(it, adj[u])
    {
        int v = *it;
        if(parent[u] == v){
            continue;
        }
        if(vis[v]){ //back edge
            low[u] = min(low[u], dis[v]);
        }
        if(!vis[v]){
            parent[v] = u;
            ArticulationBridge(v);
            low[u] = min(low[u], low[v]);

            if(dis[u]<low[v]){ //u-v is an articulation bridge
                bridge.insert({min(u, v), max(u, v)});
            }
        }
    }
}


void solve(int tc)
{
    int n, m;
    sfi2(n, m);

    rep(i, 0, m){
        int u, v;
        sfi2(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rep(i, 0, n) parent[i] = -1, vis[i] = false;

    tym = 0;
    ArticulationBridge(0);

    int comp_count = 0;
    mem(vis, false);
    rep(i, 0, n){
        if(!vis[i]){
            if(bfs(i)) comp_count++;
        }
    }

    debug{
        cout<<"bridges::\n";
        repit(it, bridge) cout<<it->first<<sp<<it->second<<endl;
    }
    debug watch(comp_count);

    int ans = (comp_count + 1) / 2;

    pfs("Case "), pfi(tc), pfs(": "), pfi(ans), newl;

    rep(i, 0, n) adj[i].clear();
    bridge.clear();
}

int32_t main()
{
    //INPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

