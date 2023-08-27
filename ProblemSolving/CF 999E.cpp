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
#define INF           1000000000
#define mod           1000000007
#define mxn           5010

vector<int> adj[mxn];
bool vis[mxn];
bool ok[mxn];
int nov = 0;

void DFS(int s){
    vis[s] = true;
    int v, sz = adj[s].size();
    for(int i=0; i<sz; i++){
        v = adj[s][i];
        if(!vis[v]){
            DFS(v);
        }
    }
}

void DFS1(int s){
    ok[s] = true; nov++;
    int v, sz = adj[s].size();
    for(int i=0; i<sz; i++){
        v = adj[s][i];
        if(!ok[v] && !vis[v]) DFS1(v);
    }
}

int main()
{
    FasterIO

    int n, m, s, u, v;
    cin>>n>>m>>s;

    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].pb(v);
    }

    DFS(s);

    vector< pair<int, int> > res;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            nov = 0;
            fill(ok, ok+mxn, false);
            DFS1(i);
            res.pb({nov,i});
        }
    }

    sort(all(res));

    int ans = 0;
    for(int i=res.size()-1; i>=0; i--){
        if(!vis[res[i].ss]){
            DFS(res[i].ss);
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}

