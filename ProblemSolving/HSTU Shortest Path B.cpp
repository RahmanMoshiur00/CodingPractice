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


vector<int> adj[mxn];
bool cat[mxn], vis[mxn];
int n, m, u, v, c, ans = 0;


void bfs(int s)
{
    vis[s] = true;
    queue< pair<int, int> > q;
    if(cat[s]) q.push({s, 1});
    else q.push({s, 0});

    while(!q.empty()){
        int u = q.front().first, c = q.front().second; q.pop();

        if(c > m) continue;

        bool restaurant = true;
        rep(i, 0, adj[u].size()){
            int v = adj[u][i];
            if(!vis[v]){
                restaurant = false;
                vis[v] = true;
                if(cat[v]) q.push({v, c+1});
                else q.push({v, 0});
            }

        }

        if(restaurant) ans++;
    }
}

int main()
{
    cin>>n>>m;

    rep(i, 1, n+1) cin>>cat[i];

    rep(i, 1, n){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    cout<<ans<<endl;

    return 0;
}


