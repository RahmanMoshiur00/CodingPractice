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
#define mxn           100010 //maximum possible number of edges


typedef pair<int, pair<int, int> > piii;
vector< piii > edg;
int rep[mxn];

void setRep(){
    for(int i=0; i<mxn; i++) rep[i] = i;
}

int findRep(int n){
    //if(rep[n] != n) rep[n] = findRep(rep[n]);
    //return rep[n];
    while(rep[n] != n) //loop is faster
    {
        rep[n] = rep[rep[n]];
        n = rep[n];
    }
    return n;
}

void Union(int x, int y){
    int rx = findRep(x);
    int ry = findRep(y);
    rep[rx] = rep[ry];
}

bool connected(int x, int y){ //returns is x and y are in same component
    return (findRep(x) == findRep(y));
}

int Kruskal(){
    setRep();
    int mstCost = 0, sz = edg.size(), x, y, cost;
    for(int i=0; i<sz; i++){
        x = edg[i].sf , y = edg[i].ssd , cost = edg[i].ff;
        if(!connected(x,y)){
            mstCost += cost;
            Union(x , y);
        }
    }
    return mstCost;
}


int main()
{
    FasterIO

    int n, m, u, v, c;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v>>c;
        edg.pb(mp(c, mp(u,v)));
    }

    sort(all(edg));

    cout<<Kruskal()<<endl;

    return 0;
}
