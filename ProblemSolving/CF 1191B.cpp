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
#define space         printf(" ")
#define newline       printf("\n")
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

const int mxn = 100010;
vector<string> s(3);
int vis[10][3];

int idx(char c)
{
    if(c == 'm') return 0;
    if(c == 'p') return 1;
    if(c == 's') return 2;
}

bool koutsu()
{
    for(int i=1; i<=9; i++){
        for(int j=0; j<3; j++){
            if(vis[i][j] >= 3) return true;
        }
    }
    return false;
}

bool shuntsu()
{
    for(int i=1; i+2<=9; i++){
        for(int j=0; j<3; j++){
            if(vis[i][j] && vis[i+1][j] && vis[i+2][j]){
                return true;
            }
        }
    }
    return false;
}

void solve(int tc)
{
    rep(i, 0, 3){
        cin>>s[i];
        int x = idx(s[i][1]);
        vis[s[i][0] - '0'][x]++;
    }

    if(koutsu() || shuntsu()){
        cout<<0<<endl;
        return;
    }

    for(int i=1; i<=9; i++){
        for(int j=0; j<3; j++){
            vis[i][j]++;
            if(koutsu() || shuntsu()){
                cout<<1<<endl;
                return;
            }
            vis[i][j]--;
        }
    }

    cout<<2<<endl;
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

