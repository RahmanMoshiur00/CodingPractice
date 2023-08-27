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
#define mxn           100010


struct edge{
    int u, v, a, b;
};

edge edg[mxn];
int rep[mxn];
int n, m, mstA = 0, mstB = 0;


void setRep(){
    for(int i=0; i<mxn; i++) rep[i] = i;
}

int findRep(int n){
    if(rep[n]!=n) rep[n] = findRep(rep[n]);
    return rep[n];
}

bool connected(int x, int y){
    return (findRep(x)==findRep(y));
}

void Union(int x, int y){
    int rx = findRep(x);
    int ry = findRep(y);
    rep[rx] = rep[ry];
}

bool Kruskal(double x){
    setRep();
    double mst = 0.0;
    mstA = mstB = 0;
    sort(edg, edg+m, [x](edge &c, edge &d){ return (double(c.a - double(c.b*x)) > double(d.a - double(d.b*x))); } ); //sorting edges in decreasing order by value of (ai - bi*x)
    for(int i=0; i<m; i++){
        if(!connected(edg[i].u, edg[i].v)){
            mst += double(edg[i].a) - double(edg[i].b * x);
            mstA += edg[i].a;
            mstB += edg[i].b;
            Union(edg[i].u, edg[i].v);
        }
    }
    return (mst>=0.0);
}

int main()
{
    FasterIO

    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>edg[i].u>>edg[i].v>>edg[i].a>>edg[i].b;
    }

    double lo=0.0, hi = 10000000.0, mid; //predicates lies in between 0 to 10^5*100=10^7
    while(hi-lo>=0.0000001){
        mid = lo + (hi-lo)/2.0;
        if(Kruskal(mid)) lo = mid; //we're finding the maximum predicate value for which we get positive mstCost using (ai - bi*x)>=0 where x is a predicate value
        else hi = mid;
    }

    Kruskal(lo);

    int g = __gcd(mstA, mstB);
    cout<<mstA/g<<"/"<<mstB/g<<endl;

    return 0;
}
