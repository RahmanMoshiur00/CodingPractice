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
#define debug         if( 0 )

const int mxn = 100010;

int n;
string s;

int fun(int i, int cnt)
{
    int res = 0;
    for(int j=i+1; j<i+cnt; j+=2){
        if(j+1==n){
            if(s[j-1]=='R' or s[j-1]=='B') s[j] = 'G';
            else if(s[j-1]=='R' or s[j-1]=='G') s[j] = 'B';
            else s[j] = 'R';
        }
        else{
            if(s[j-1]!='R' && 'R'!=s[j+1]) s[j] = 'R';
            else if(s[j-1]!='B' && 'B'!=s[j+1]) s[j] = 'B';
            else s[j] = 'G';
        }
        res++;
    }

    return res;
}

void solve(int tc)
{
    cin >> n >> s;

    int res = 0, cnt, j;
    for(int i=0; i<n; i++){
        cnt = 1;
        for(j=i+1; j<n; j++){
            if(s[i] != s[j]) break;
            cnt++;
        }
        if(cnt > 1) res += fun(i, cnt);
        i = j-1;
    }

    cout << res << '\n' << s << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

