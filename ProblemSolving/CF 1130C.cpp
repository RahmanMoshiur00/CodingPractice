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
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))

#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second

#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 0 )
#define mxn           55

int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

int n, r1, c1, r2, c2;
vector<string> s;
vector< pair<int,int> > source, dest;
bool vis[mxn][mxn], found = false;

bool valid(int x, int y)
{
    return !(x<0 or x>=n or y<0 or y>=n or vis[x][y] or s[x][y]=='1');
}

bool bfs(int r, int c, int dr, int dc)
{
    setmem(vis, false);

    queue< pair<int, int> > qu;
    vis[r][c] = true;
    qu.push({r, c});

    while(!qu.empty()){
        int x = qu.front().first, y = qu.front().second; qu.pop();
        source.push_back({x+1, y+1});
        if(dr==x and dc==y) return true;
        rep(i, 0, 4){
            int ur = X[i] + x, uc = Y[i] + y;
            if(valid(ur, uc)){
                vis[ur][uc] = true;
                qu.push({ur, uc});
            }
        }
    }
    return false;
}

void bfs2(int r, int c, int dr, int dc)
{
    setmem(vis, false);

    queue< pair<int, int> > qu;
    vis[r][c] = true;
    qu.push({r, c});

    while(!qu.empty()){
        int x = qu.front().first, y = qu.front().second; qu.pop();
        dest.push_back({x+1, y+1});
        rep(i, 0, 4){
            int ur = X[i] + x, uc = Y[i] + y;
            if(valid(ur, uc)){
                vis[ur][uc] = true;
                qu.push({ur, uc});
            }
        }
    }
}

void solve(int tc)
{
    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    s.resize(n);
    rep(i, 0, n) cin>>s[i];

    r1--, c1--, r2--, c2--;
    bool ok = bfs(r1, c1, r2, c2);

    if(ok){
        cout<<0<<endl;
        return;
    }

    bfs2(r2, c2, r1, c1);

    debug{
        cout<<"------source-------"<<endl;
        repit(it, source){
            cout<<it->first<<sp<<it->second<<endl;
        }
        cout<<"======source========"<<endl;

        cout<<"------dest-------"<<endl;
        repit(it, dest){
            cout<<it->first<<sp<<it->second<<endl;
        }
        cout<<"======dest========"<<endl;
    }

    int ans = INT_MAX;
    rep(i, 0, source.size()){
        rep(j, 0, dest.size()){
            int sr = source[i].first, sc = source[i].second;
            int dr = dest[j].first, dc = dest[j].second;

            int v = ((sr - dr) * (sr - dr)) + ((sc - dc) * (sc - dc));

            ans = min(ans, v);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    //INPUT  //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

