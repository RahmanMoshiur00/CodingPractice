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
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 510;

int n, m;
vector<string> s;

bool valid(int i, int j)
{
    return (!(i<0 || i>=n || j<0 || j>=m) && (s[i][j] == '*'));
}

bool ok(int i, int j)
{
    if(valid(i, j) && valid(i-1, j) && valid(i+1, j) && valid(i, j+1) && valid(i, j-1)){
        s[i][j] = s[i-1][j] = s[i+1][j] = s[i][j+1] = s[i][j-1] = '.';
        return true;
    }
    return false;
}

void up(int i, int j)
{

}

void solve(int tc)
{
    cin>>n>>m;

    s.resize(n);

    rep(i, 0, n) cin>>s[i];

    bool found = false;
    rep(i, 0, n){
        bool br = false;
        rep(j, 0, m){
            if(ok(i, j)){
                per(k, i-1, 0){
                    if(s[k][j] == '*') s[k][j] = '.'; //up
                    else break;
                }
                rep(k, i+2, n){
                    if(s[k][j] == '*') s[k][j] = '.'; //down
                    else break;
                }
                per(k, j-1, 0){
                    if(s[i][k] == '*') s[i][k] = '.'; //left
                    else break;
                }
                rep(k, j+2, m){
                    if(s[i][k] == '*') s[i][k] = '.'; //right
                    else break;
                }
                br = true;
                found = true;
                break;
            }
        }
        if(br) break;
    }

    rep(i, 0, n){
        rep(j, 0, m){
            if(s[i][j] == '*'){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    if(found) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

