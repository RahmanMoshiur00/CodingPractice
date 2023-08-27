#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define sf            scanf
#define pf            printf
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000LL //1e9
#define mod           1000000007LL
#define mxn           100010      //1e5

typedef vector<int> vi;

bool vis[mxn];
int nov = 1;

void DFS(vector< vi >& adj, int s){
    vis[s] = true;
    int v, sz = adj[s].size();
    for(int i=0; i<sz; i++){
        v = adj[s][i];
        if(!vis[v]){
            nov++;
            DFS(adj, v);
        }
    }
}

int main()
{
    FasterIO

    int tc; cin>>tc;
    while(tc--){
        int n, m, cl, cr, u, v;
        cin>>n>>m>>cl>>cr;
        vector< vi > adj(n+1);
        for(int i=0; i<m; i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        intl res = 0LL;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                DFS(adj, i);
                res += cl + ((nov-1) * 1LL * min(cl, cr));
                nov = 1;
            }
        }

        cout<<res<<endl;

        mem(vis, false);
    }

    return 0;
}

