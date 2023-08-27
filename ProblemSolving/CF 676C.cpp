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

#define FOR(i, begin, end)  for(__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
#define debug         if( 0 )

const int mxn = 100010;



void solve(int tc)
{
    int n, k;
    cin >> n >> k;

    char s[n+5];
    cin >> s + 1;

    debug{
        for(int i=1; i<=n; i++) cout << s[i]; cout << endl;
    }

    int cnt[n+1][2] = {0};
    for(int i=1; i<=n; i++){
        if(s[i]=='a'){
            cnt[i][0] = cnt[i-1][0] + 1;
            cnt[i][1] = cnt[i-1][1];
        }
        else{
            cnt[i][0] = cnt[i-1][0];
            cnt[i][1] = cnt[i-1][1] + 1;
        }
    }

    int cnta, cntb;
    for(int l=1, r=n; l<=r; ){
        cnta = cnt[r][0] - cnt[l-1][0];
        cntb = cnt[r][1] - cnt[l-1][1];

        if(min(cnta, cntb) <= k){
            cout << cnta + cntb << endl;
            return;
        }

        char ch;
        if(cnta > cntb) ch = 'b';
        else ch = 'a';

        int lft, rgt;
        for(int i=l; i<=r; i++){
            if(s[i]==ch){
                lft = i - l;
                break;
            }
        }
        for(int i=r; i>=l; i--){
            if(s[i]==ch){
                rgt = r - i;
                break;
            }
        }

        if(lft < rgt) l = l + lft + 1;
        else r = r - rgt - 1;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

