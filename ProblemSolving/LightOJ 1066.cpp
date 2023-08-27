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
#define mxn           13

vector<string> s;
bool vis[mxn][mxn];
int n;

struct node{
    int x, y, l;
    node(int _x, int _y, int _l){
        x = _x , y = _y , l = _l;
    }
};

bool valid(int i, int j, char c){
    if(i<0 or i>=n or j<0 or j>=n or vis[i][j] or s[i][j]=='#') return false;
    else if(s[i][j] == '.' or (isupper(s[i][j]) and s[i][j] == c)) return true;
    else return false;
}

int bfs(int i, int j, char finish){
    mem(vis, 0);
    vis[i][j] = true;
    s[i][j] = '.';

    queue< node > q;
    q.push({i, j, 0});

    while(!q.empty()){
        int x = q.front().x , y = q.front().y , l = q.front().l;
        q.pop();

        if(s[x][y] == finish){
            s[x][y] = '.';
            return l;
        }

        if(valid(x, y+1, finish)) vis[x][y+1] = true , q.push(node(x, y+1, l+1));
        if(valid(x, y-1, finish)) vis[x][y-1] = true , q.push(node(x, y-1, l+1));
        if(valid(x+1, y, finish)) vis[x+1][y] = true , q.push(node(x+1, y, l+1));
        if(valid(x-1, y, finish)) vis[x-1][y] = true , q.push(node(x-1, y, l+1));

    }

    return -1;
}

void solve(int t)
{
    cin>>n;

    s.resize(n);
    rep(i, 0, n) cin>>s[i];

    vector<pair<char, pair<int, int> > > alpha;
    rep(i, 0, n){
        rep(j, 0, n){
            if(isupper(s[i][j])) alpha.pb({s[i][j] , {i,j}});
        }
    }

    sort(all(alpha));

    int ans = 0, res = 0;
    rep(i, 1, alpha.size()){
        char start = alpha[i-1].ff , finish = alpha[i].ff;
        int x = alpha[i-1].sf , y = alpha[i-1].sd;

        res = bfs(x, y, finish);

        if(res == -1){
            ans = -1;
            break;
        }
        else ans += res;
    }

    if(ans == -1) cout<<"Case "<<t<<": Impossible"<<endl;
    else cout<<"Case "<<t<<": "<<ans<<endl;

    s.clear();
    alpha.clear();
}

int main()
{
    //INPUT
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}
