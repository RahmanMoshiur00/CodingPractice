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
#define mxn           30


struct node{
    int v, w, t;

    node(int _v, int _w, int _t){ v = _v, w = _w, t = _t; }
};

vector< node > adj[mxn];
int dist1[mxn], dist2[mxn];


void dijkstra(int source, int type, int dist[])
{
    rep(i, 0, mxn) dist[i] = INF;
    dist[source] = 0;

    priority_queue< pair<int,int> > pq;
    pq.push({0, source});

    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int u = p.second, c = -p.first;

        if(c > dist[u]) continue;

        rep(i, 0, adj[u].size()){
            int v = adj[u][i].v, w = adj[u][i].w, t = adj[u][i].t;

            if(t==type and dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main()
{
    int n, u, v, w, t;
    char a, b, c, d;

    while(cin>>n and n){
        rep(i, 0, n){
            cin>>a>>b>>c>>d>>w;

            u = c - 'A';
            v = d - 'A';

            if(a == 'Y') t = 1;
            else t = 2;

            adj[u].push_back({v, w, t});
            if(b == 'B') adj[v].push_back({u, w, t});
        }

        cin>>a>>b;


        int manz = a - 'A', migu = b - 'A';

        dijkstra(manz, 1, dist1);
        dijkstra(migu, 2, dist2);

        int cost = INF, place = -1;
        rep(i, 0, mxn){
            if(dist1[i]!=INF and dist2[i]!=INF){
                if(dist1[i]+dist2[i] < cost){
                    cost = dist1[i] + dist2[i];
                    place = i;
                }
            }
        }

        if(place == -1) cout<<"You will never meet."<<endl;
        else{
            cout<<cost;
            rep(i, 0, mxn){
                if(cost == dist1[i]+dist2[i]) cout<<sp<<char('A'+i);
            }
            cout<<endl;
        }

        rep(i, 0, mxn) adj[i].clear();
    }

    return 0;
}


