#include <bits/stdc++.h>
using namespace std;
typedef long long int intl; //
typedef unsigned long long intu; //
#define int             long long
#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfd(a)          scanf("%lf", &a)
#define sfd2(a,b)       scanf("%lf %lf", &a, &b)
#define sfd3(a, b, c)   scanf("%lf %lf %lf", &a, &b, &c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld\n", (intl)a)
#define pfis(a)         printf("%lld ", (intl)a)
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '
#define INPUT           freopen("input.txt","r",stdin);
#define OUTPUT          freopen("output.txt","w",stdout);
#define FastRead        ios::sync_with_stdio(0); cin.tie(0);
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define all(a)          a.begin(), a.end()
#define PB              push_back
#define mem(a, v)       for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
#define memset(a, v)    memset((a), v, sizeof(a))
#define min3(a, b, c)   min(a,min(b,c))
#define max3(a, b, c)   max(a,max(b,c))
#define ff              first
#define ss              second
#define CEIL(a, b)      ((a)%(b)==0 ? (a)/(b) : ((a)/(b))+1)
#define ABS(a)          ((a)<0?-(a):(a))
#define SQ(a)           ((a)*(a))
#define PI              acos(-1.00)
#define ERR             1e-9
#define INF             1000000007
#define mod             1000000007
#define debug           if( 0 )
#define mxn             100010


int arr[mxn], n, m, k;

bool check(int x)
{
    int lv = arr[0], need = 1;

    rep(i, 1, n){
        if(arr[i] - lv + 1 > x){
            need++;
            lv = arr[i];
        }
    }

    debug cout<<"for: "<<x<<" "<<need<<endl;

    return (need <= k);
}

int val(int x)
{
    int lv = arr[0], li = 0, tot = 0, now = arr[0];

    rep(i, 1, n){
        if(arr[i] - lv + 1 > x){
            tot += arr[i-1] - lv + 1;
            lv = arr[i];
            li = i;
        }
    }
    tot += arr[n-1] - lv + 1;

    return tot;
}

void solve(int tc)
{
    cin>>n>>m>>k;
    rep(i, 0, n) cin>>arr[i];


    if(n == 1){
        cout<<1<<endl;
        return;
    }

    int lo = 1, hi = arr[n-1] - arr[0] + 1, mid;

    while(hi - lo > 1){
        mid = (hi + lo + 1) / 2;

        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }


    int mx = 0, ans = 1;
    rep(i, lo, hi+1){
        if(check(i)){
            ans = max(1LL, val(i));
            break;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    //INPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
