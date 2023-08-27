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
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define sf            scanf
#define pf            printf
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
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
#define mod           1000000007
#define INF           1000000000
#define mxn           10005

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pii > vii;
bool vis[mxn];
int dist[mxn];


int dijkstra(vector< vii >& adj, int s, int e){
    dist[s] = 0;
    priority_queue< pii > pq;
    pq.push({0, s});

    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        int u = p.ss;

        if(vis[u]) continue; //already found the shortest path for vertex u

        int sz = adj[u].size();
        for(int i=0; i<sz; i++){
            int v = adj[u][i].ff;
            int cost = adj[u][i].ss;
            if(dist[v] > dist[u] + cost){
                dist[v] = dist[u] + cost;
                pq.push(mp(-dist[v], v));
            }
        }
        vis[u] = true;
        if(u==e) return dist[e];
    }
}


int main()
{
    FasterIO

    int tc; cin>>tc;

    while(tc--){
        for(int i=0; i<mxn; i++){ dist[i] = INF; vis[i] = false; }
        int n, ad;
        cin>>n;

        string city;
        map<string , int> mep;
        vector< vii > adj(n+1);

        for(int i=0; i<n; i++){
            cin>>city;
            mep[city] = i+1;
            cin>>ad;
            for(int j=0; j<ad; j++){
                int v, c; cin>>v>>c;
                adj[i+1].pb(mp(v, c));
            }
        }

        int q; cin>>q;
        string beg, en;
        for(int i=0; i<q; i++){
            cin>>beg>>en;
            cout<<dijkstra(adj, mep[beg], mep[en])<<endl;
            for(int i=0; i<mxn; i++){ dist[i] = INF; vis[i] = false; }
        }
    }

    return 0;
}
