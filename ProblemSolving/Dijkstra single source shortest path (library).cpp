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
#define mxn           3010 //maximum number of nodes

typedef pair<int,int> pii;

vector< pii > adj[mxn];
int dist[mxn];
bool vis[mxn];

//Dijkstra using priority_queue
void Dijkstra(int s){
    fill(dist, dist+mxn, INF);
    fill(vis, vis+mxn, false);
    dist[s] = 0;
    int u, v, cost, sz;
    priority_queue< pii > pq;
    pq.push({0,s});
    while(!pq.empty()){
        u = pq.top().ss; //taking the shortest node
        pq.pop();
        if(vis[u]) continue; //if u is visited, it means that u's shortest path is already found
        vis[u] = true;
        sz = adj[u].size();
        for(int i=0; i<sz; i++){
            v = adj[u][i].ss , cost = adj[u][i].ff; //extracting adjacent nodes and weights of the edges
            if(dist[v]>dist[u]+cost){
                dist[v] = dist[u] + cost;
                pq.push({-dist[v],v});
            }
        }

    }
}

//Dijkstra using multiset
/*
void Dijkstra(int s){
    fill(dist, dist+mxn, INF);
    fill(vis, vis+mxn, false);
    dist[s] = 0;
    int u, v, cost, sz;
    multiset< pii > pq;
    pq.insert({0,s});
    while(!pq.empty()){
        u = pq.begin()->ss;
        pq.erase(pq.begin());
        if(vis[u]) continue;
        vis[u] = true;
        sz = adj[u].size();
        for(int i=0; i<sz; i++){
            v = adj[u][i].ss , cost = adj[u][i].ff;
            if(dist[v]>dist[u]+cost){
                dist[v] = dist[u] + cost;
                pq.insert({dist[v],v});
            }
        }
    }
}
*/


int main()
{
    FasterIO
//this is an AC code; problem: https://www.hackerrank.com/challenges/dijkstrashortreach/problem
    int t; cin>>t;
    while(t--){
        int n, m, u, v, c;
        cin>>n>>m; //no of nodes and edges

        for(int i=0; i<m; i++){
            cin>>u>>v>>c;
            adj[u].pb({c,v});
            adj[v].pb({c,u});
        }

        int start; cin>>start;

        Dijkstra(start);

        bool first_print = true;
        for(int i=1; i<=n; i++){
            if(dist[i]==INF) dist[i] = -1; //to satisfy the problem statement

            if(i==start) continue;
            if(!first_print) cout<<' ';
            if(first_print) first_print=false;
            cout<<dist[i];
        }
        cout<<endl;

        for(int i=0; i<mxn; i++) adj[i].clear(); //clearing stored nodes and edges information
    }


    return 0;
}

