#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))

#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second

#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 0 )
#define mxn           1005


vector<int> adj[mxn]; // actual graph
vector<int> trans[mxn]; // transpose graph
stack<int> stk; // holds greatest finishing time nodes in top and least in the bottom
int scc[mxn]; // scc[i] denotes the scc number of node i
int scc_count = 0; // counts total number of scc's
bool vis[mxn]; // visited checker
bool node[mxn];

void dfs(int u)
{
    vis[u] = true;
    for(int i=0, sz = adj[u].size(); i<sz; i++){
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs_scc(int u)
{
    scc[u] = scc_count;
    vis[u] = true;
    for(int i=0, sz = trans[u].size(); i<sz; i++){
        int v = trans[u][i];
        if(!vis[v]) dfs_scc(v);
    }
}

void scc_calculation(int n)
{
    memset(vis, false, sizeof vis);
    for(int i=0; i<n; i++){
        if(node[i] && !vis[i]) dfs(i);
    }

    scc_count = 0; // counts total number of scc's
    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        int u = stk.top(); stk.pop();
        if(!vis[u]){
            scc_count++;
            dfs_scc(u);
        }
    }
}

bool find_result()
{
    vector<int> outDegree(scc_count+1, 0);
    vector<bool> root(scc_count+1, true);

    rep(u, 0, mxn){
        if(node[u]){
            repit(it, adj[u]){
                int v = *it;
                if(scc[u] != scc[v]){
                    outDegree[scc[u]]++;
                    if(outDegree[scc[u]] > 1) return false;
                    root[scc[v]] = false;
                }
            }
        }
    }

    int rooted = -1, root_count = 0;
    rep(i, 1, scc_count+1){
        if(root[i]){
            root_count++;
            rooted = i;
            if(root_count > 1) return false;
        }
    }

    return (rooted == scc[0]);
}

void solve(int tc)
{
    int n, k, u, v;
    sfi(n);

    rep(i, 0, n){
        sfi(k);
        while(k--){
            sfi2(u, v);
            adj[u].push_back(v);
            trans[v].push_back(u);
            node[u] = node[v] = true;
        }
    }

    scc_calculation(mxn);

    pfs("Case "), pfi(tc), pfs(": ");
    if(find_result()) puts("YES");
    else puts("NO");

    rep(i, 0, mxn) adj[i].clear(), trans[i].clear();
    memset(node, false, sizeof node);
    memset(scc, 0, sizeof scc);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

