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
#define mxn           110

typedef pair<int,int> pii;

vector< pii > adj[mxn];
int dist[mxn];

void dijkstra(int s)
{
    rep(i, 0, mxn) dist[i] = INF;

    dist[s] = 0;
    priority_queue< pii > pq;
    pq.push({-dist[s], s});

    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        int u = p.second, c = -p.first;

        if(c > dist[u]) continue;

        rep(i, 0, adj[u].size()){
            int v = adj[u][i].first, w = adj[u][i].second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main()
{
    int tc; cin>>tc;

    int n, destination, time, e, u, v, w;
    rep(t, 0, tc){
        cin>>n>>destination>>time>>e;
        rep(i, 0, e){
            cin>>u>>v>>w;
            adj[v].push_back({u, w});
        }

        dijkstra(destination);

        sort(dist+1, dist+n+1);

        int ans = 0;
        rep(i, 1, n+1){
            if(dist[i] <= time) ans++;
            else break;
        }

        if(t) cout<<endl;
        cout<<ans<<endl;

        rep(i, 0, mxn) adj[i].clear();
    }

    return 0;
}


