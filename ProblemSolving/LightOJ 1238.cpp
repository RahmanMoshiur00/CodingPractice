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
#define mxn           1000010

typedef pair< int , pair<int, int> > piii;

int r, c;
vector< string > s;
bool vis[22][22];

bool valid(int i , int j){
    return !(i<0 or j<0 or i>r or j>c or vis[i][j]==true or s[i][j]=='#' or s[i][j]=='m');
}

int bfs(int i, int j){
    mem(vis, 0);
    queue< piii > q;
    q.push({i, {j, 0}});
    vis[i][j] = true;

    while(!q.empty()){
        piii v = q.front(); q.pop();
        int x = v.ff , y = v.sf , z = v.sd;

        if(s[x][y] == 'h') return z;

        if(valid(x, y+1)) vis[x][y+1] = true , q.push({x, {y+1, z+1}});
        if(valid(x, y-1)) vis[x][y-1] = true , q.push({x, {y-1, z+1}});
        if(valid(x+1, y)) vis[x+1][y] = true , q.push({x+1, {y, z+1}});
        if(valid(x-1, y)) vis[x-1][y] = true , q.push({x-1, {y, z+1}});
    }
}

int main()
{
    int tc, ax, ay, bx, by, cx, cy; cin>>tc;

    rep(t, 1, tc+1){
        cin>>r>>c;
        string tmp;

        rep(i, 0, r) cin>>tmp , s.push_back(tmp);

        rep(i, 0, r){
            rep(j, 0, c){
                if(s[i][j] == 'a') ax = i , ay = j;
                else if(s[i][j] == 'b') bx = i , by = j;
                else if(s[i][j] == 'c') cx = i , cy = j;
            }
        }

        r-- , c--;
        int ans = max3(bfs(ax, ay) , bfs(bx, by) , bfs(cx, cy));
        s.clear();

        cout<<"Case "<<t<<": "<<ans<<endl;
    }

    return 0;
}


