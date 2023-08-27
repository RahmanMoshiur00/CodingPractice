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

int idx(char ch)
{
    return (ch - 'a');
}

void solve(int tc)
{
    string s;
    cin >> s;

    int n = s.size();
    int fr[n+2][26], bck[n+2][26];
    ZERO(fr); ZERO(bck);

    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++){
            if(j != idx(s[i-1])) fr[i][j] = fr[i-1][j];
            else fr[i][j] = fr[i-1][j] + 1;
        }
    }

    for(int i=n; i>=1; i--){
        for(int j=0; j<26; j++){
            if(j != idx(s[i-1])) bck[i][j] = bck[i+1][j];
            else bck[i][j] = bck[i+1][j] + 1;
        }
    }

    int ans = 0;
    for(int i=0; i<26; i++){
        ans = max(ans, fr[n][i]);
        ans = max(ans, bck[1][i]);
    }

    int now;
    for(int j=0; j<26; j++){
        now = 0;
        for(int i=1; i<=n; i++){
            if(j != idx(s[i-1])) now += fr[i][idx(s[i-1])] * bck[i][j];
        }
        ans = max(ans, now);
    }

//    for(int i=1; i<=n; i++){
//        for(int j=0; j<26; j++){
//            if(j != idx(s[i-1])) ans = max(ans, fr[i][idx(s[i-1])] * bck[i][j]);
//        }
//    }

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
