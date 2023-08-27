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
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 55;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1}; //4 Direction

int n, m;
vector<string> vs;
bool vis[mxn][mxn];

bool bounded(int x, int y)
{
    return !(x<0 or x>n+1 or y<0 or y>m+1);
}

void bfs(int x, int y, char ch)
{
    ZERO(vis);
    vis[x][y] = true;

    queue< pair<int,int> > qu;
    qu.push({x, y});

    pair<int,int> p;
    while(!qu.empty()){
        p = qu.front(); qu.pop();
        rep(i, 0, 4){
            x = dx[i] + p.first, y = dy[i] + p.second;
            if(bounded(x, y) && !vis[x][y]){
                vis[x][y] = true;
                if(vs[x][y] != ch) qu.push({x, y});
            }
        }
    }

    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if(!vis[i][j]) vs[i][j] = ch;
        }
    }
}

void solve(int tc)
{
    cin>>n>>m;
    vs.resize(n+2);

    rep(j, 0, m+2) vs[0] += '.', vs[n+1] += '.';

    string s;
    rep(i, 1, n+1){
        cin>>s;
        vs[i] = "."; vs[i] += s; vs[i] += ".";
    }

    rep(k, 0, 26){
        bfs(0, 0, k+'A');
    }

    pfs("Case "), pfi(tc), pfs(":\n");
    rep(i, 1, n+1){
        rep(j, 1, m+1) pfc(vs[i][j]); nwl;
    }
}

int32_t main()
{
    INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

