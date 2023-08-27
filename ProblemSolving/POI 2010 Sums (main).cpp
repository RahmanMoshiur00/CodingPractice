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
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
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
#define INF           1000000007
#define mod           1000000007
#define mxn           50010
typedef pair<int, int> pii;

int a[mxn];
int dist[mxn];

void dijkstra(int s, int n){
    fill(dist, dist+mxn, INF);
    dist[s] = 0;
    priority_queue< pii > pq;
    pq.push(mp(0, s));
    int u, v, cost;
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        u = p.ss;
        for(int i=1; i<n; i++){
            v = (u+a[i]) % a[0];
            cost = a[i];
            if(dist[v] > dist[u] + cost){
                dist[v] = dist[u] + cost;
                pq.push(mp(-dist[v], v));
            }
        }
    }
}


int main()
{
    FasterIO

    int n; cin>>n;

    for(int i=0; i<n; i++) cin>>a[i];

    dijkstra(0, n);

    for(int i=0; i<mxn; i++){
        if(dist[i]!=INF) printf("dist[%d] = %d\n", i, dist[i]);
    }

    int q; cin>>q;
    while(q--){
        cin>>n;
        if(dist[n%a[0] ]>n) cout<<"NIE"<<endl;
        else cout<<"TAK"<<endl;
    }

    return 0;
}

