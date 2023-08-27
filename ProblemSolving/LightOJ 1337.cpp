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
#define mxn           505

int n, m, q;
vector<string> s;
bool vis[mxn][mxn], vis1[mxn][mxn];
int crystal[mxn][mxn];

bool valid(int i, int j){
    return !(i<0 or i>=n or j<0 or j>=m or vis[i][j] or s[i][j]=='#');
}

bool valid1(int i, int j){
    return !(i<0 or i>=n or j<0 or j>=m or vis1[i][j] or s[i][j]=='#');
}

int bfs(int i, int j){
    int cry = 0;
    queue< pair<int,int> > q;
    q.push({i, j});
    vis[i][j] = true;

    while(!q.empty()){
        i = q.front().ff , j = q.front().ss; q.pop();

        if(s[i][j] == 'C') cry++;
        if(valid(i, j+1)) vis[i][j+1] = true , q.push({i, j+1});
        if(valid(i, j-1)) vis[i][j-1] = true , q.push({i, j-1});
        if(valid(i+1, j)) vis[i+1][j] = true , q.push({i+1, j});
        if(valid(i-1, j)) vis[i-1][j] = true , q.push({i-1, j});
    }

    return cry;
}

void bfs_setval(int i, int j, int val){
    queue< pair<int,int> > q;
    q.push({i, j});
    vis1[i][j] = true;

    while(!q.empty()){
        i = q.front().ff , j = q.front().ss; q.pop();
        crystal[i][j] = val;

        if(valid1(i, j+1)) vis1[i][j+1] = true , q.push({i, j+1});
        if(valid1(i, j-1)) vis1[i][j-1] = true , q.push({i, j-1});
        if(valid1(i+1, j)) vis1[i+1][j] = true , q.push({i+1, j});
        if(valid1(i-1, j)) vis1[i-1][j] = true , q.push({i-1, j});
    }
}


void solve(int t){
    cin>>n>>m>>q;
    string tmp;
    rep(i, 0, n) cin>>tmp , s.pb(tmp);

    mem(vis, 0);
    mem(vis1, 0);
    mem(crystal, 0);

    rep(i, 0, n){
        rep(j, 0, m){
            if(!vis[i][j] and s[i][j]!='#'){
                int val = bfs(i,j);
                bfs_setval(i,j,val);
            }
        }
    }

    cout<<"Case "<<t<<":"<<endl;
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<crystal[x-1][y-1]<<endl;
    }

    s.clear();
}

int main()
{

    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


