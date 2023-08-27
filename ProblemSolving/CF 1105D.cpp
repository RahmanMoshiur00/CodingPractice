#include <bits/stdc++.h>
using namespace std;
typedef int intt;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    scanf("%lld %lld", &x, &y)
#define sfi3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)
#define pfi(x)        printf("%lld", (intl)x)
#define pfi2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfi3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
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
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           1010

int r, c, n;
int speed[10], res[10];
bool vis[mxn][mxn];
pair<int, int> start[10];

int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

struct node{
    int row, col, per;
    node(int _r, int _c, int _p){
        row = _r, col = _c, per = _p;
    }
};

bool valid(int x, int y)
{
    return !(x<0 or x>=r or y<0 or y>=c or vis[x][y]);
}

void solve(int tc)
{
    sfi3(r, c, n);

    rep(i, 1, n+1){
        sfi(speed[i]);
    }

    char s[r][c+2];

    rep(i, 0, r){
        rep(j, 0, c){
            sfc(s[i][j]);
            if(s[i][j] == '#') vis[i][j] = true;
            else if(s[i][j] != '.'){
                rep(k, 1, 10){
                    if(s[i][j] == char(k+'0')){
                        start[k].first = i;
                        start[k].second = j;
                        vis[i][j] = true;
                        res[k]++;
                    }
                }
            }
        }
        s[i][c] = '\0';
        debug pfs(s[i]), newl;
    }

    queue<node> q;
    rep(i, 1, n+1){
        q.push(node(start[i].first, start[i].second, i));
    }

    while(!q.empty()){
        node nd = q.front();
        q.pop();

        debug cout<<"check: "<<nd.row<<sp<<nd.col<<sp<<nd.per<<endl;

        rep(i, 0, 4){
            int person = nd.per;
            int x = X[i] + nd.row, y = Y[i] + nd.col;

            rep(j, 0, speed[person]){
                x += j, y += j;
                if(valid(x, y)){
                    vis[x][y] = true;
                    res[person]++;
                    q.push({x, y, person});
                }
            }


        }
    }


    rep(i, 1, n+1) cout<<res[i]<<sp;
}

int32_t main()
{
    INPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

