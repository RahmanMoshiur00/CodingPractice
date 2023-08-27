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
#define mxn           110

vector<string> str;
bool vis[mxn][mxn];
int r, c;
int EX[] = {1, 1, 2, 2,-1,-1,-2,-2};
int EY[] = {2,-2, 1,-1, 2,-2, 1,-1};
int KX[] = {0, 0, 1, 1,-1,-1,-1, 1};
int KY[] = {1,-1, 1,-1, 1,-1, 0, 0};


struct node{
    int x, y, l;
    node(int _x, int _y, int _l){ x = _x, y = _y, l = _l; }
};


bool enemy_valid(int x, int y){
    return !(x<0 or x>=r or y<0 or y>=c or vis[x][y] or str[x][y]=='A' or str[x][y]=='B');
}
bool king_valid(int x, int y){
    return !(x<0 or x>=r or y<0 or y>=c or vis[x][y]);
}

int bfs(int x, int y, int i, int j)
{
    vis[x][y] = true;
    queue<node> king;
    king.push({x, y, 0});

    int l;
    while(!king.empty()){
        x = king.front().x, y = king.front().y , l = king.front().l; king.pop();

        if(x==i and y==j) return l;

        rep(k, 0, 8){
            if(king_valid(x+KX[k], y+KY[k])){
                vis[x+KX[k]][y+KY[k]] = true;
                king.push({x+KX[k], y+KY[k], l+1});
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

    mem(vis, false);

    int ax, ay, bx, by;
    rep(i, 0, r){
        rep(j, 0, c){
            if(str[i][j] == 'A') ax = i, ay = j;
            else if(str[i][j] == 'B') bx = i, by = j;
            else if(str[i][j] == 'Z'){
                vis[i][j] = true;
                rep(k, 0, 8){
                    if(enemy_valid(i+EX[k], j+EY[k])) vis[i+EX[k]][j+EY[k]] = true;
                }
            }
        }
    }

    int ans = bfs(ax, ay, bx, by);

    if(ans == -1) cout<<"King Peter, you can't go now!"<<endl;
    else cout<<"Minimal possible length of a trip is "<<ans<<endl;
}

int main()
{

    int tc; cin>>tc;

    while(tc--) solve();

    return 0;
}


