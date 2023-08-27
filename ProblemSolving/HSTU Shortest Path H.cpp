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
#define mxn           100010

vector< int > adj[mxn];
bool vis[mxn];

int bfs(int source, int target)
{
    mem(vis, false);
    vis[source] = true;

    queue< pair<int,int> > q;
    q.push({source, 0});

    while(!q.empty()){
        int u = q.front().first , l = q.front().second; q.pop();

        if(u == target) return l;

        rep(i, 0, adj[u].size()){
            int v = adj[u][i];
            if(!vis[v]){
                vis[v] = true;
                q.push({v, l+1});
            }
        }
    }
}


int main()
{
    int tc; cin>>tc;

    rep(t, 0, tc){
        int n, u, v, c, nc; cin>>n;

        rep(i, 0, n){
            cin>>c>>nc;
            rep(j, 0, nc){
                cin>>v;
                adj[c].push_back(v);
                adj[v].push_back(c);
            }
        }

        cin>>u>>v;

        int ans = bfs(u, v);

        if(t) cout<<endl;
        cout<<u<<sp<<v<<sp<<ans-1<<endl;


        rep(i, 0, mxn) adj[i].clear();
    }

    return 0;
}


