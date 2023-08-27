#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl, intl> pll;
typedef pair<int, int> pii;
typedef pair<intl, pair<intl,intl> > plll;
typedef pair<int, pair<int,int> > piii;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //e.g. ordered_set<int> s; s.insert(3); cout<<s.ook(3)<<*s.fbo(3);
#define ook           order_of_key
#define fbo           find_by_order //returns pointer
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          '\n'
#define sp            ' '
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define FOREACH(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b)    for(intl i=(intl)(a);i<=(intl)(b);++i)
#define ROF(i,a,b)    for(intl i=(intl)(a);i>=(intl)(b);--i)
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           1000010



int main()
{
    //INPUT

    int tc; sfi(tc);
    while(tc--){
        int n; sfi(n); n++;
        intl ar[n], formax[n], backmax[n], formin[n], backmin[n], cur_max, cur_min;
        n--;

        FOR(i, 1, n) sfl(ar[i]);

        cur_max = cur_min = formax[1] = formin[1] = ar[1];
        FOR(i, 2, n){
            cur_max = max(ar[i], ar[i]+cur_max);
            formax[i] = max(formax[i-1], cur_max);

            cur_min = min(ar[i], ar[i]+cur_min);
            formin[i] = min(formin[i-1], cur_min);
        }

        cur_max = cur_min = backmax[n] = backmin[n] = ar[n];
        ROF(i, n-1, 1){
            cur_max = max(ar[i], ar[i]+cur_max);
            backmax[i] = max(backmax[i+1], cur_max);

            cur_min = min(ar[i], ar[i]+cur_min);
            backmin[i] = min(backmin[i+1], cur_min);
        }

        intl ans = LLONG_MIN;
        FOR(i, 1, n-1) ans = max3(ans, ABS(formax[i]-backmin[i+1]), ABS(formin[i]-backmax[i+1]));
        pfl(ans);
    }

    return 0;
}

