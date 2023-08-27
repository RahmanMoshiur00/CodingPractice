#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second.first
#define tt            second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           1010

typedef pair< int,pair<int,int> > piii;
typedef vector< piii > viii;

bool vis[mxn];
int dist[mxn];
queue<int> cycle;
vector<int> nodes;

int n , e; //no. of nodes & edges

bool BellmanFord(viii& edg){
    fill(dist, dist+mxn, INF);
    dist[n] = 0;
    int u, v, cost;

    bool upd = true;
    for(int i=1; i<=n && upd; i++){
        upd = false;
        for(int j=0; j<=e; j++){
            u = edg[j].ff; v = edg[j].ss; cost = edg[j].tt;
            if(dist[v]>dist[u]+cost){
                dist[v] = dist[u] + cost;
                upd = true;
            }
        }
    }

    for(int j=0; j<=e; j++){
        u = edg[j].ff; v = edg[j].ss; cost = edg[j].tt;
        if(dist[v]>dist[u]+cost){
            dist[v] = dist[u] + cost;
            cycle.push(v);
            cycle.push(u);
        }
    }
}

void BFS(vector<int> adj[]){
    fill(vis, vis+mxn, false);
    while(!cycle.empty()){
        int u = cycle.front(); cycle.pop();
        vis[u] = true;
        nodes.pb(u);
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]) cycle.push(v);
        }
    }
}

int main()
{
    FasterIO

    int t; cin>>t;
    for(int tc = 1; tc<=t; tc++){
        cin>>n>>e;

        int u , v , w;

        viii edg;
        vector<int> adj[n+1];

        for(int i=0; i<e; i++){
            cin>>u>>v>>w;
            edg.pb(mp(v, mp(u,w)));
            adj[v].pb(u);
        }
        for(int i=0; i<n; i++){
            edg.pb(mp(n, mp(i,0)));
            adj[n].pb(i);
        }

        BellmanFord(edg);

        BFS(adj);

        sort(all(nodes));

        cout<<"Case "<<tc<<":";
        if(nodes.empty()) cout<<" impossible\n";
        else{
            cout<<' '<<nodes[0];
            for(int i=1; i<nodes.size(); i++){
                if(nodes[i]!=nodes[i-1]) cout<<' '<<nodes[i];
            }
            cout<<endl;
        }
        nodes.clear();
    }

    return 0;
}
