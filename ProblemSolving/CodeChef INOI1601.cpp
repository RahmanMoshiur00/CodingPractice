#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl,intl> pii;
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
#define mxn           100010      //1e6

intl cost[mxn] , mx[mxn] , ans = INT_MIN;
vector<intl> adj[mxn];
bool visited[mxn];


void BFS(intl s){
    visited[s] = true;
    mx[s] = INT_MIN;
    queue<intl> q;
    q.push(s);
    intl u, v, sz;
    while(!q.empty()){
        u = q.front(); q.pop();
        sz = adj[u].size();
        for(intl i=0; i<sz; i++){
            v = adj[u][i];
            if(!visited[v]){
                mx[v] = max(mx[u], cost[u]);
                ans = max(ans, mx[v]-cost[v]);
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main()
{
    FasterIO
    while(false){}

    intl n, u , root; cin>>n;

    for(intl i=1; i<=n; i++) cin>>cost[i];
    for(intl i=1; i<=n; i++){
        cin>>u;
        if(u != -1) adj[u].pb(i);
        else root = i;
    }

    BFS(root);

    cout<<ans<<endl;

    return 0;
}

