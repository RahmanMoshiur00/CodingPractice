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
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfs(x)        printf("%s", x)
#define pfnl          printf("\n")
#define pfsp          printf(" ")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(i, x)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setvalue(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 1 )

const int mxn = 200010;

typedef pair<int,int> pii;
typedef vector< pii > vii;

set< int > st;
bool vis[mxn];
int dist[mxn], par[mxn];

void bfs(vector< vii >& adj, int s){
    ZERO(vis);
    ZERO(dist);
    int u, v, w;
    dist[s] = 0;
    vis[s] = true;

    queue< pair<int, int> > q;
    q.push({s, 0});

    while(!q.empty()){
        u = q.front().first; q.pop();
        rep(i, 0, adj[u].size()){
            v = adj[u][i].first , w = adj[u][i].second;
            if(!vis[v]){
                dist[v] = dist[u] + w;
                vis[v] = true;
                par[v] = u;
                q.push({v,w});
            }
        }
    }
}

void bfs1(vector< vii >& adj, int s){

    int u, v, w;
    dist[s] = 0;
    vis[s] = true;

    queue< pair<int, int> > q;
    q.push({s, 0});

    while(!q.empty()){
        u = q.front().first; q.pop();
        rep(i, 0, adj[u].size()){
            v = adj[u][i].first , w = adj[u][i].second;
            if(!vis[v] && st.find(v)==st.end()){
                dist[v] = dist[u] + w;
                vis[v] = true;
                q.push({v,w});
            }
        }
    }
}

pii max_node_dist(int n){
    int mx_dist = -1, mx_node;
    rep(i, 1, n+1){
        if(dist[i]>=mx_dist){
            mx_dist = dist[i];
            mx_node = i;
        }
    }
    return {mx_node, mx_dist};
}

void find_path(int s, int d){
    st.insert(s);
    if(s == d) return;
    find_path(par[s], d);
}

void solve(int tc)
{
    int n, u, v, w;

    cin>>n;
    vector< vii > adj(n+1);
    for(int i=1; i<n; i++){
        cin>>u>>v;
        adj[u].push_back({v,1});
        adj[v].push_back({u,1});
    }

    bfs(adj, 1);

    int a_far_node = max_node_dist(n).first; //5

    bfs(adj, a_far_node);

    int b_far_node = max_node_dist(n).first; //1

    find_path(b_far_node, a_far_node);

    ZERO(vis);
    ZERO(dist);
    for(auto it : st) bfs1(adj, it);

    int mx_dist = -1, mx_node;
    for(int i=1; i<=n; i++){
        if(i==a_far_node || i==b_far_node) continue;
        if(dist[i] > mx_dist){
            mx_dist = dist[i];
            mx_node = i;
        }
    }

    cout << st.size() + mx_dist - 1 << endl;
    cout << a_far_node << sp << b_far_node << sp << mx_node << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
