#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(x, i)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define all(a)        a.begin(),a.end()
#define find(x, a)    x.find(a) != x.end()
#define endl          '\n'
#define sp            ' '
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define CEIL(x,y)     ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define mxn           300010


vector< pair<intl, intl> > adj[mxn];
intl dist[mxn];
bool vis[mxn];

void bfs(intl s)
{
    mem(vis, false);
    dist[s] = 0;
    vis[s] = true;

    queue< intl > q;
    q.push(s);

    while(!q.empty()){
        intl u = q.front(); q.pop();

        rep(i, 0, adj[u].size()){
            intl v = adj[u][i].first, w = adj[u][i].second;

            if(!vis[v]){
                vis[v] = true;
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main()
{
    intl n;
    cin>>n; n++;
    intl gas[n];

    intl mxg = 0;
    rep(i, 1, n) cin>>gas[i], mxg = max(mxg, gas[i]);

    intl u, v, w, c;
    rep(i, 1, n-1){
        cin>>u>>v>>c;
        w = gas[u] + gas[v] - c;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bfs(1LL);

    intl mxd = -1, idx = -1;
    rep(i, 1, n){
        if(dist[i] > mxd) mxd = dist[i] , idx = i;
    }

    bfs(intl(idx));

    mxd = -1, idx = -1;
    rep(i, 1, n){
        if(dist[i] > mxd) mxd = dist[i] , idx = i;
    }

    cout<<max(mxd, mxg)<<endl;

    return 0;
}


