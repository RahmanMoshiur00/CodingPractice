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
#define debug         if( 1 )

const int mxn = 505;

int dp[mxn][mxn];
int n, m;

void solve(int tc)
{

    cin >> n >> m;

    string s[n];
    for(int i=0; i<n; i++) cin >> s[i];

    for(int i=1; i<n; i++){
        if(s[i][0]=='.' && s[i-1][0]=='.') dp[i][0] = dp[i-1][0] + 1;
        else dp[i][0] = dp[i-1][0];
    }

    for(int j=1; j<m; j++){
        if(s[0][j]=='.' && s[0][j-1]=='.') dp[0][j] = dp[0][j-1] + 1;
        else dp[0][j] = dp[0][j-1];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(s[i][j]=='.' && s[i-1][j]=='.') dp[i][j]++;
            if(s[i][j]=='.' && s[i][j-1]=='.') dp[i][j]++;
        }
    }

    int up_down[n][m] = {0}, left_right[n][m] = {0};
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            if(s[i][j]=='.' && s[i][j-1]=='.') left_right[i][j] = left_right[i][j-1] + 1;
            else left_right[i][j] = left_right[i][j-1];
        }
    }

    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++){
            if(s[i][j]=='.' && s[i-1][j]=='.') up_down[i][j] = up_down[i-1][j] + 1;
            else up_down[i][j] = up_down[i-1][j];
        }
    }

    int q, r1, c1, r2, c2, ans;
    cin >> q;
    while(q--){
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        ans = dp[r2][c2] - dp[r1][c2] - dp[r2][c1] + dp[r1][c1];
        ans += left_right[r1][c2] - left_right[r1][c1];
        ans += up_down[r2][c1] - up_down[r1][c1];
        cout << ans << endl;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin>>tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

