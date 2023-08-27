#include <bits/stdc++.h>
using namespace std;
typedef int intt;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%d", &x)
#define sfi2(x, y)    scanf("%d %d", &x, &y)
#define sfi3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfl(x)        scanf("%lld", &x)
#define sfl2(x, y)    scanf("%lld %lld", &x, &y)
#define sfl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfs(x)        scanf("%s", x)
#define sfsn(x)       scanf("%[^\n]s", x)
#define pfi(x)        printf("%d", (intt)x)
#define pfi2(x, y)    printf("%d %d", (intt)x, (intt)y)
#define pfi3(x, y, z) printf("%d %d %d", (intt)x, (intt)y, (intt)z)
#define pfl(x)        printf("%lld", (intl)x)
#define pfl2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfl3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define watch(x)      cout<<">>   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<">>   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a)        a.begin(), a.end()
#define isfound(x, a) (x.find(a) != x.end())
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 0 )
#define mxn           100010

int len[mxn], cum[mxn], diff, shortage;

bool check(int x, int idx, int l) // idx is always greater than x
{
    diff = (idx==0) ? 0 : cum[idx-1] - cum[x-1]; //as, 0-1 == -1
    shortage = (l*(idx - x)) - diff; //finding the shortage length
    return (x >= shortage);  //returns if number of eaten snakes are greater than or equal to needed shortage length
}

void solve(int tc)
{
    int n, q, l;
    sfl2(n, q);

    rep(i, 0, n) sfl(len[i]);

    sort(len, len+n);

    cum[0] = len[0];
    rep(i, 1, n) cum[i] = cum[i-1] + len[i];

    while(q--){
        sfl(l);

        int idx = lower_bound(len, len + n, l) - len;
        int ans = n - idx;

        int lo = 0, hi = idx-1, x;

        debug cout<<"query:: "<<l<<endl;
        debug cout<<"first: "<<ans<<endl;

        while(hi-lo>1){
            x = (hi+lo) / 2;
            if(check(x, idx, l)){
                hi = x;
                debug cout<<"x: "<<x<<"  short: "<<shortage<<endl;
            }
            else lo = x;
        }

        for(int x=lo; x<hi+1; x++){
            if(check(x, idx, l)){
                ans += idx - x;
                debug cout<<"x: "<<x<<"  short: "<<shortage<<"  add: "<<idx-x<<endl;
                break;
            }
        }

        debug cout<<"Solution :: "<<ans<<endl<<endl;

        cout<<ans<<endl;
    }
}

int32_t main()
{
    //INPUT
    //solve(1);
    int tc; sfl(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}

