#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x) // changes
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x) // no changes
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

#define mxn           10010

//pair<int,int> lpar[mxn][mxn], par[mxn][mxn];
//map< pair<int,int> , pair<int,int> > lpar, par;

pair<int,int> par[mxn][mxn];
bool vis[mxn][mxn], go[mxn][mxn][2];
int n;

bool valid(int x, int y)
{
    return !(x<1 or x>n or y<1 or y>n or vis[x][y]);
}
void bfs()
{
    queue< pair<int,int> > qu;
    qu.push({1, 1});
    vis[1][1] = true;

    pair<int,int> p;
    while(!qu.empty()){
        p = qu.front(); qu.pop();
        int x = p.first, y = p.second;

        if(x==n and y==n) return;

        if(valid(x, y+1) and !go[x][y][1]){
            vis[x][y+1] = true;
            par[x][y+1] = make_pair(x, y);
            qu.push({x, y+1});
        }
        if(valid(x+1, y) and !go[x][y][0]){
            vis[x+1][y] = true;
            par[x+1][y] = make_pair(x, y);
            qu.push({x+1, y});
        }
    }
}

void print_path(int x, int y)
{
    if(x==1 and y==1){
        return;
    }
    pair<int, int> p = par[x][y];
    print_path(p.first, p.second);

    if(p.first + 1 == x){
        pfc('S');
    }
    else if(p.second + 1 == y){
        pfc('E');
    }
}

void solve(int tc)
{
    sfi(n);

    string s;
    cin>>s;

    ZERO(vis);
    ZERO(go);

    int x=1, y=1, px = 1, py = 1;
    rep(i, 0, s.size()){
        if(s[i]=='E'){
            y = py + 1;
            go[px][py][1] = true;
        }
        else{
            x = px + 1;
            go[px][py][0] = true;
        }
        //lpar[{x,y}] = make_pair(px, py);
        //debug cout<<"lpar["<<x<<"]["<<y<<"] = "<<lpar[{x,y}].first<<sp<<lpar[{x,y}].second<<endl;
        px = x;
        py = y;
    }

    bfs();

    pfs("Case #"), pfi(tc), pfs(": ");
    print_path(n, n);
    pfs("\n");
}

int32_t main()
{
    //INPUT //OUTPUT

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

