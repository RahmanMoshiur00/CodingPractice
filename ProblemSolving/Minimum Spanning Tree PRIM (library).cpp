#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           10001

typedef pair<int, int> pii;

vector< pii > adj[mxn];
bool vis[mxn];

int Prims(int s){
    priority_queue< pii, vector< pii >, greater< pii > > pq;
    int mstCost = 0;

    pq.push({0,s});

    pii u, v;
    while(!pq.empty()){
        u = pq.top(); pq.pop();
        if(vis[u.ss]==true) continue;
        vis[u.ss] = true;
        mstCost += u.ff;

        for(int i=0; i<adj[u.ss].size(); i++){
            v = adj[u.ss][i];
            if(!vis[v.ss]) pq.push(v);
        }
    }

    return mstCost;
}


int main()
{
    FasterIO

    //this code was accepted


    int n, m, u, v, c;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v>>c;
        adj[u].pb(mp(c,v)); //we have to put cost first in the pair because priority queue sorts first element and then the second in the PAIR
        adj[v].pb(mp(c,u));
    }

    cout<<Prims(1)<<endl; //we can start from any vertex

    //this code was accepted

    return 0;
}
