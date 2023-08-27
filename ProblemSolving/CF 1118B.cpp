#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))

#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second

#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 0 )
#define mxn           200010

int odd_cum[mxn], even_cum[mxn], cum[mxn];

void solve(int tc)
{
    odd_cum[0] = even_cum[0] = cum[0] = 0;
    int n; cin>>n;
    int arr[n+5];

    rep(i, 1, n+1){
        cin>>arr[i];
        if(i%2) odd_cum[i] = arr[i] + odd_cum[i-1], even_cum[i] = even_cum[i-1];
        else even_cum[i] = arr[i] + even_cum[i-1], odd_cum[i] = odd_cum[i-1];
        cum[i] = arr[i] + cum[i-1];
    }

    int ans = 0, prev_odd, prev_even, next_odd, next_even;
    rep(i, 1, n+1){
        if(i%2){
            prev_odd = odd_cum[i] - arr[i];
            prev_even = even_cum[i];

            next_odd = even_cum[n] - even_cum[i];
            next_even = odd_cum[n] - odd_cum[i];
        }
        else{
            prev_odd = odd_cum[i];
            prev_even = even_cum[i] - arr[i];

            next_odd = even_cum[n] - even_cum[i];
            next_even = odd_cum[n] - odd_cum[i];
        }

        if(prev_odd+next_odd == prev_even+next_even) ans++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    //INPUT  //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

