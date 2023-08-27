#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;

#define sfi(x)        scanf("%d", &x) // change here
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
#define debug         if( 1 )

#define ff            first.first
#define fs            first.second
#define ss            second

int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction

const int mxn = 202;

typedef pair<int,int> pii;

vector<string> str;
int n, m, dist1[mxn][mxn], dist2[mxn][mxn];
vector< pii > teleport;
bool vis[mxn][mxn];


void Clear()
{
    str.resize(n);
    teleport.clear();
    rep(i, 0, mxn)
        rep(j, 0, mxn) dist1[i][j] = dist2[i][j] = INF;
}

bool valid(int x, int y)
{
    return !(x<0 || x>=n || y<0 || y>=m || vis[x][y]==true || str[x][y]=='#');
}

int bfs(pii s, pii e)
{
    ZERO(vis);
    queue< pair<pii,int> > qu;
    qu.push({s, 0});
    vis[s.first][s.second] = true;

    pair<pii, int> u, v;
    while(!qu.empty()){
        u = qu.front(); qu.pop();
        if(u.first == e) return u.ss;
        rep(i, 0, 4){
            v.ff = dx[i] + u.ff;
            v.fs = dy[i] + u.fs;
            if(valid(v.ff, v.fs) && str[v.ff][v.fs]!='*'){
                vis[v.ff][v.fs] = true;
                v.ss = u.ss + 1;
                qu.push(v);
            }
        }
    }

    return INF;
}

void bfs_teleport1(pii s)
{
    ZERO(vis);
    queue< pair<pii,int> > qu;
    qu.push({s, 0});
    vis[s.first][s.second] = true;

    pair<pii, int> u, v;
    while(!qu.empty()){
        u = qu.front(); qu.pop();

        rep(i, 0, 4){
            v.ff = dx[i] + u.ff;
            v.fs = dy[i] + u.fs;
            if(valid(v.ff, v.fs)){
                if(str[v.ff][v.fs] == '*'){ // a teleport is found, it's distance needed to measured but should not be processed further
                    vis[v.ff][v.fs] = true; // this teleport will not be encountered again
                    dist1[v.ff][v.fs] = u.ss + 1;
                }
                else{
                    vis[v.ff][v.fs] = true;
                    v.ss = u.ss + 1;
                    qu.push(v);
                }
            }
        }
    }
}

void bfs_teleport2(pii s)
{
    ZERO(vis);
    queue< pair<pii,int> > qu;
    qu.push({s, 0});
    vis[s.first][s.second] = true;

    pair<pii, int> u, v;
    while(!qu.empty()){
        u = qu.front(); qu.pop();

        rep(i, 0, 4){
            v.ff = dx[i] + u.ff;
            v.fs = dy[i] + u.fs;
            if(valid(v.ff, v.fs)){
                if(str[v.ff][v.fs] == '*'){ // a teleport is found, it's distance needed to measured but should not be processed further
                    vis[v.ff][v.fs] = true; // this teleport will not be encountered again
                    dist2[v.ff][v.fs] = u.ss + 1;
                }
                else{
                    vis[v.ff][v.fs] = true;
                    v.ss = u.ss + 1;
                    qu.push(v);
                }
            }
        }
    }
}

void solve(int tc)
{
    cin>>n>>m;

    Clear();

    rep(i, 0, n) cin>>str[i];

    pii Start, End;

    rep(i, 0, n){
        rep(j, 0, m){
            if(str[i][j] == 'P') Start = {i, j};
            else if(str[i][j] == 'D') End = {i, j};
            else if(str[i][j] == '*') teleport.push_back({i, j});
        }
    }

    int ans1 = bfs(Start, End); // finding distance without using any teleports

    bfs_teleport1(Start); // finding distances of any teleport from Start in dist1[][] array

    bfs_teleport2(End); //finding distances of any teleport from End in dist2[][] array

    int ans2 = INF;
    rep(i, 0, teleport.size()){
        int x1 = teleport[i].first, y1 = teleport[i].second;
        rep(j, i+1, teleport.size()){
            int x2 = teleport[j].first, y2 = teleport[j].second;
            ans2 = min3(ans2, dist1[x1][y1]+dist2[x2][y2]+1, dist1[x2][y2]+dist2[x1][y1]+1); // let (x,y) and (i,j) be two teleports, then distance ( P->(x,y) + D->(i,j) ) or ( p->(i,j) + D->(x,y) )
            ans2 = min3(ans2, dist1[x1][y1]+dist2[x1][y1]+2, dist1[x2][y2]+dist2[x2][y2]+2); // if (x,y) is used twice teleporting i.e. (x,y) -> (i,j) -> (x,y) where (i,j) is another teleport
        }
    }

    int ans = min(ans1, ans2);

    pfs("Case "), pfi(tc), pfs(": ");
    if(ans == INF) puts("impossible");
    else pfin(ans);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

