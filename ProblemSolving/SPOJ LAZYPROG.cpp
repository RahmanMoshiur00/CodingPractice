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

typedef pair<intl, pair<intl,intl> > plll;


int main()
{
    FasterIO

    int t, n;
    intl a,b,d;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++){
        scanf("%d", &n);
        priority_queue< plll > pq = priority_queue< plll >();
        for(int i=0; i<n; i++){
            scanf("%lld %lld %lld", &a, &b, &d);
            pq.push(mp(-d, mp(-b, -a)));
        }
        intl time = 0;
        double cost = 0.0;
        while(!pq.empty()){
            plll temp = pq.top(); pq.pop();
            d = -temp.ff; b = -temp.sf; a = -temp.ssd;
            if(t+b>d){
                cost += double(b-d+t)/double(a);
                t = d;
            }
            else t += b;
        }
        printf("%.2lf\n", cost);
    }

    return 0;
}
