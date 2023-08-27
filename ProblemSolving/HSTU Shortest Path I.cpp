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
#define mxn           35

int r, c, d, sx, sy, sz, ex, ey, ez;
string s[mxn][mxn];
bool vis[mxn][mxn][mxn];

int X[] = {1,-1, 0, 0, 0, 0};
int Y[] = {0, 0, 1,-1, 0, 0};
int Z[] = {0, 0, 0, 0, 1,-1};

struct node{
    int x, y, z, l;
    node(int i, int j, int k, int _l){
        x = i , y = j , z = k , l = _l;
    }
};

bool valid(int x, int y, int z)
{
    return !(x<0 or x>=r or y<0 or y>=c or z<0 or z>=d or vis[x][y][z]);
}

int bfs(int x, int y, int z, int i, int j, int k)
{
    vis[x][y][z] = true;
    queue<node> q;
    q.push({x, y, z, 0});

    int l;
    while(!q.empty()){
        x = q.front().x , y = q.front().y , z = q.front().z , l = q.front().l; q.pop();

        if(x==i and y==j and z==k) return l;

        rep(n, 0, 6)
            if(valid(x+X[n], y+Y[n], z+Z[n])) vis[x+X[n]][y+Y[n]][z+Z[n]] = true , q.push({x+X[n], y+Y[n], z+Z[n], l+1});
    }

    return -1;
}

int main()
{

    while(cin>>r>>c>>d){
        if(r==0 and c==0 and d==0) break;

        rep(i, 0, r)
            rep(j, 0, c) cin>>s[i][j];

        mem(vis, false);

        rep(i, 0, r)
            rep(j, 0, c)
                rep(k, 0, d){
                    if(s[i][j][k] == '#') vis[i][j][k] = true;
                    else if(s[i][j][k] == 'S') sx = i , sy = j , sz = k;
                    else if(s[i][j][k] == 'E') ex = i , ey = j , ez = k;
                }

        int ans = bfs(sx, sy, sz, ex, ey, ez);

        if(ans == -1) cout<<"Trapped!"<<endl;
        else cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
    }

    return 0;
}


