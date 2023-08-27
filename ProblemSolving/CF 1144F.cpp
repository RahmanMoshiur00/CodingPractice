#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x) // changes
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x) // no changes
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

#define mxn           200010

vector<int> adj[mxn];

int biColNodes = 0;
bool vis[mxn], color[mxn], edgcol[mxn];

map< pair<int,int>, int > edge;

bool isBicolorable(int u, int col) // checks if bi-colorable, because cycle with odd nodes cannot be bi-colored
{
    if(vis[u]) return (color[u] == col);

    vis[u] = true; // vis[] tracks if any node is visited
    color[u] = col; // col[] indicates color of nodes

    biColNodes++; // biColNodes this is a globally variable set to zero before calling this(isBicolorable) function;
           // biColNodes counts the number of nodes that can be bicolored if bicoloring is possible

    bool biCol = true;
    repit(it, adj[u]){
        int v = *it;
        biCol &= isBicolorable(v, color[u]^1);
    }

    return biCol;
}

void bfs(int s)
{
    rep(i, 0, mxn) vis[i] = false;

    queue< pair<int, int> > q;
    vis[s] = true;
    q.push({s, 0});

    while(!q.empty()){
        int u = q.front().first, l = q.front().second; q.pop();
        repit(it, adj[u]){
            int v = *it;
            if(!vis[v]){
                vis[v] = true;
                q.push({v, l+1});
            }

            if(l&1){
                if(edge.find({u, v}) != edge.end()){
                    edgcol[edge[{u, v}]] = 1;
                }
                else{
                    edgcol[edge[{v, u}]] = 0;
                }
            }
            else{
                if(edge.find({u, v}) != edge.end()){
                    edgcol[edge[{u, v}]] = 0;
                }
                else{
                    edgcol[edge[{v, u}]] = 1;
                }
            }
        }
    }
}

void solve(int tc)
{
    int n, m, u, v; sfi2(n, m);

    rep(i, 0, m){
        sfi2(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[make_pair(u, v)] = i;
    }

    rep(i, 0, mxn) color[i] = vis[i] = false;

    if(isBicolorable(1, 0)){
        bfs(1);
        cout<<"YES"<<endl;
        rep(i, 0, m){
            cout<<edgcol[i];
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int32_t main()
{
    solve(1);

    return 0;
}

