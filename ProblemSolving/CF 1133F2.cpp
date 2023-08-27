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
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a)) // int:0/-1, bool, char
#define mem(a, v)       for(int i=0, sz=(sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

#define mxn           200010


vector<pair<int, int> > adj[mxn];
bool vis[mxn];
int key[mxn];

set< pair<int,int> > edge;

void prim(int s) //prim algo finds mst of the component where s(source) node is in
{
    mem(vis, false);
    mem(key, INF);
    key[s] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push({key[s], s});

    int res = 0;
    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        int cost = -p.first, u = p.second;

        if(vis[u]) continue; // u is already taken in the MST
        vis[u] = true; // adding u to the mst
        res += cost;  // cost for adding node u to the mst

        repit(it, adj[u]){
            int v = it->first, w = it->second;
            if(!vis[v] and key[v]>w){
                edge.insert({min(u, v), max(u, v)});
                key[v] = w;
                pq.push({-key[v], v});
            }
        }
    }
}

void solve(int tc)
{
    int n, m, u, v, w, d;
    cin>>n>>m>>d;

    int deg[n+1];
    memset(deg, 0, sizeof deg);

    int node = 0;
    rep(i, 0, m){ // edge input
        cin>>u>>v;
        w = 1;

        deg[u]++;
        deg[v]++;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> start_node;
    rep(i, 1, n+1){
        if(deg[i] == d){
            start_node.push_back(i);
        }
    }

    repit(i, start_node){
        prim(*i); //finds mst of the component where 0 node is present
        if(edge.size() == n-1){
            cout<<"YES"<<endl;
            repit(it, edge){
                cout<<it->first<<sp<<it->second<<endl;
            }
            return;
        }
        edge.clear();
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);
    return 0;
}

