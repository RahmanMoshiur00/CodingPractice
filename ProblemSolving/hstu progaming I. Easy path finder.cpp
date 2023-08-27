#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           100010

typedef pair<int, int> pii;

bool vis[mxn];
int dist[mxn];
vector<pii> adj[mxn];

void Dijkstra(int s){
    fill(dist, dist+mxn, INF);
    fill(vis, vis+mxn, false);
    dist[s] = 0;
    priority_queue< pii > pq;
    pq.push({0,s});

    int u, v, cost;
    while(!pq.empty()){
        u = (pq.top()).ss;
        pq.pop();
        if(vis[u]) continue;
        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i].ss, cost = adj[u][i].ff;
            if(dist[v]>dist[u]+cost){
                dist[v] = dist[u] + cost;
                pq.push({-dist[v],v});
            }
        }
        vis[u] = true;
    }
}

int main()
{
    FasterIO

    int tc, u, v, c, n, m, gcost;; cin>>tc;

    while(tc--){
        cin>>n>>m>>gcost;
        for(int i=0; i<m; i++){
            cin>>u>>v>>c;
            adj[u].pb(mp(c,v));
        }
        Dijkstra(1);

        int ans = 0;
        for(int i=2; i<=n; i++) if(dist[i]<=gcost) ans++;
        cout<<ans<<endl;

        for(int i=0; i<mxn; i++) adj[i].clear();
    }


    return 0;
}

