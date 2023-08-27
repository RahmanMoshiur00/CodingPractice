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
#define mem(a,v)     memset((a), v, sizeof(a))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000LL //1e9
#define mod           1000000007LL
#define MAX           2000005      //1e6

intl rep[MAX];

void MakeSet(intl n){
    for(intl i=0; i<n+2; i++) rep[i] = i;
}

intl FindRepresentative(intl x){
    if(x == rep[x]) return x;
    rep[x] = FindRepresentative(rep[x]);
    return rep[x];
}

void Union(intl x, intl y){
    intl RX = FindRepresentative(x);
    intl RY = FindRepresentative(y);

    if(RX != RY) rep[RX] = RY;
    return;

}

bool isSameComponent(intl x, intl y){
    if(FindRepresentative(x) == FindRepresentative(y)) return true;
    else return false;
}


int main()
{
    FasterIO
    while(false){}

    intl n, k; cin>>n>>k;
    intl arr[n], res[n];

    MakeSet(n+1);

    for(intl i=0; i<n; i++){ cin>>arr[i]; res[i] = 0; }

    intl x, y;
    for(intl i=0; i<k; i++){
        cin>>x>>y;
        Union(x-1, y-1);
    }

    for(intl i=0; i<n; i++){
        for(intl j=0; j<n; j++){
            if(arr[i]>arr[j] && isSameComponent(i, j)==false) res[i]++;
        }
    }
    cout<<res[0];
    for(intl i=1; i<n; i++){
        cout<<" "<<res[i];
    }
    cout<<endl;

    return 0;
}

