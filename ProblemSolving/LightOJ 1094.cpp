#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          "\n"
#define sp            " "
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(i, x)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1073741820
#define mod           1000000007
#define mxn           30010

typedef pair<int,int> pii;
typedef vector< pii > vii;

bool vis[mxn];
int dist[mxn];

void dfs(vector< vii >& adj, int s){
    mem(vis, 0);
    mem(dist, 0);
    int u, v, w;
    dist[s] = 0;
    vis[s] = true;

    queue< pair<int, int> > q;
    q.push({s, 0});

    while(!q.empty()){
        u = q.front().ff; q.pop();
        rep(i, 0, adj[u].size()){
            v = adj[u][i].ff , w = adj[u][i].ss;
            if(!vis[v]){
                dist[v] = dist[u] + w;
                vis[v] = true;
                q.push({v,w});
            }
        }
    }
}

pii max_node_dist(int n){
    int mx_dist = -1, mx_node;
    rep(i, 0, n){
        if(dist[i]>mx_dist) mx_dist = dist[i] , mx_node = i;
    }
    return {mx_node, mx_dist};
}

int main()
{
    int tc, n, u, v, w; cin>>tc;

    rep(t, 1, tc+1){
        cin>>n;
        vector< vii > adj(n);
        rep(i, 1, n){
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        dfs(adj, 0);

        int far_node = max_node_dist(n).ff;

        dfs(adj, far_node);

        adj.clear();

        cout<<"Case "<<t<<": "<<max_node_dist(n).ss<<endl;
    }

    return 0;
}

