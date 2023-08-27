#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld\n", (intl)x)
#define pfis(x)       printf("%lld ", (intl)x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
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
#define rep(i, begin, end) for(int i = (begin); i < (end); ++i)
#define per(i, end, begin) for(int i = (end)-1; i >= (begin); --i)
#define mem(a, v)     for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
#define setval(a, v)  memset((a), v, sizeof(a))
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
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

int cum[mxn];

void solve(int tc)
{
    int n, k, m, sum = 0;
    cin>>n>>k>>m;
    int arr[n+5];

    cum[0] = 0;
    rep(i, 1, n+1){
        cin>>arr[i];
        cum[i] = cum[i-1] + arr[i];
    }

    sort(arr+1, arr+1+n);

    int mx = arr[n], idx = -1, cnt = 0;
    per(i, n+1, 1){
        if(arr[i] != mx){
            idx = i;
            break;
        }
        cnt++;
    }

    double ans = 0.0;
    if(idx == -1){
        ans = double(cum[n] + min(n*k, m));
        ans = ans / (n*1.0);

        debug cout<<"if"<<endl;
    }
    else{
        int notcnt = n - cnt;
        if(m >= notcnt){
            m -= notcnt;
            ans = double((mx*cnt) + min(cnt*k, m));
            ans = ans / (cnt*1.0);

            debug cout<<"else -> if"<<endl;
        }
        else{ //m < notcnt
            ans = cum[n] - cum[m];
            ans = (ans*1.0) / (n-m);

            debug cout<<"else -> else"<<endl;
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}

int32_t main()
{
    //INPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
