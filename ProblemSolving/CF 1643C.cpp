#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;

#define int           long long // change here
#define sfi(x)        scanf("%lld", &x) // change here

#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfs(x)        printf("%s", x)
#define pfnl          printf("\n")
#define pfsp          printf(" ")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(i, x)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setvalue(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 1 )

const int mxn = 100010;

struct Pair{
    int ff, ss;
    Pair(int f, int s){
        ff = f;
        ss = s;
    }

    bool operator < (const Pair& a) const{
        if(ff != a.ff) return ff < a.ff;
        return ss < a.ss;
    }
};

void solve(int tc)
{
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=1; i<=n; i++) cin >> arr[i];

    int sum[n+2] = {0}, sub = 0;
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i=1; i<=n; i++){
        if(arr[i] == 0){
            int cnt = 1, j = i+1;
            for(; j<=n; j++){
                if(arr[j]==0) cnt++;
                else break;
            }
            i = j - 1;
            sub += (cnt * (cnt+1)) / 2;
        }
    }

    set < Pair > st;
    if(arr[n] != 0) st.insert(Pair(sum[n], n));
    for(int i=n; i>=1; i--){
        if(arr[i] == 0) continue;
        auto it = st.lower_bound(Pair(sum[i-1], LLONG_MIN));
        if(it!=st.end() && it->ff == sum[i-1]) sub += n - (it->ss) + 1;
        st.insert(Pair(sum[i], i));
    }

    int tot = (n*(n+1)) / 2;
    int ans = tot - sub;

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

