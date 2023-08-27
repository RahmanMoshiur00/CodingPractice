#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          "\n"
#define sp            " "
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(i, x)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1073741820
#define mod           1000000007
#define mxn           1010

vector<string> str;
bool vis[mxn][mxn];
int r, c;
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};


struct node{
    int x, y, l;
    node(int _x, int _y, int _l){ x = _x, y = _y, l = _l; }
};
queue<node> fire, joe;

bool valid(int x, int y){
    return !(x<0 or x>=r or y<0 or y>=c or vis[x][y]);
}

bool escapable(int x, int y){
    return (x<0 or x>=r or y<0 or y>=c);
}

int bfs(int x, int y)
{
    int l;
    vis[x][y] = true;
    joe.push({x, y, 0});

    int fire_level = 0, joe_level = 0;
    while(!joe.empty()){

        if(!fire.empty()) fire_level = fire.front().l;
        while(!fire.empty()){
            x = fire.front().x, y = fire.front().y, l = fire.front().l;
            if(l > fire_level) break;
            fire.pop();

            rep(i, 0, 4){
                if(valid(x+X[i], y+Y[i])) vis[x+X[i]][y+Y[i]] = true, fire.push({x+X[i], y+Y[i], l+1});
            }
        }

        joe_level = joe.front().l;

        while(!joe.empty()){
            x = joe.front().x, y = joe.front().y , l = joe.front().l;
            if(l > joe_level) break;
            joe.pop();

            rep(i, 0, 4){
                if(valid(x+X[i], y+Y[i])) vis[x+X[i]][y+Y[i]] = true, joe.push({x+X[i], y+Y[i], l+1});
                if(escapable(x+X[i], y+Y[i])) return l+1;
            }
        }
    }

    return -1;
}

void solve()
{
    cin>>r>>c;

    str.resize(r);
    rep(i, 0, r) cin>>str[i];

    fire = queue<node>();
    joe = queue<node>();
    mem(vis, false);

    int x, y;
    rep(i, 0, r){
        rep(j, 0, c){
            if(str[i][j] == '#') vis[i][j] = true;
            else if(str[i][j] == 'J') x = i, y = j;
            else if(str[i][j] == 'F') vis[i][j] = true , fire.push({i, j, 0});
        }
    }

    int ans = bfs(x, y);

    if(ans == -1) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
}

int main()
{
    int tc; cin>>tc;

    while(tc--) solve();

    return 0;
}


