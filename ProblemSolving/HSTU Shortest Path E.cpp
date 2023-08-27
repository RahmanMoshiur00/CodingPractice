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
#define INF           1e15
#define mod           1000000007
#define mxn           100010


vector< pair<intl,intl> > adj[mxn];
intl dist[mxn] , parent[mxn];
bool vis[mxn];

void dijkstra(intl s)
{
    rep(i, 0, mxn) dist[i] = INF;

    dist[s] = 0;
    priority_queue< pair<intl,intl> > pq;
    pq.push({0, s});

    while(!pq.empty())
    {
        pair<intl,intl> p = pq.top(); pq.pop();
        intl u = p.second , c = p.first;

        if(c > dist[u]) continue;

        rep(i, 0, adj[u].size())
        {
            intl v = adj[u][i].first , w = adj[u][i].second;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }
}

void print_path(int s)
{
    if(s == 0) return;
    print_path(parent[s]);
    cout<<s<<sp;
}

int main()
{
    intl n, m, u, v, w; cin>>n>>m;

    rep(i, 0, m){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1);

    if(dist[n] != INF) print_path(n);
    else cout<<-1<<endl;
    return 0;
}


