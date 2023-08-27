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
#define mxn           11

vector<string> str;
int r, c;
int dist[mxn][mxn] , cnt[mxn][mxn];

struct node{
    int i, j, k;
    node(int x, int y, int z){ i = x , j = y , k = z; }
};

void bfs(int i, int j, int k){
    queue< node > q;
    q.push({i, j, k});

    while(!q.empty()){
        int x = q.front().i , y = q.front().j , z = q.front().k; q.pop();
        cnt[x][y]++;

        if(str[x][y] != '.') k = str[x][y] - '0';


    }
}

void solve(int t){
    cin>>r>>c;
    str.resize(r);

    rep(i, 0, r) cin>>str[i];

    rep(i, 0, r){
        rep(j, 0, c){
            dist[i][j] = INF;
            cnt[i][j] = 0;
        }
    }

    int x, y, ans, riders = 0;
    rep(i, 0, r){
        rep(j, 0, c){
            if(str[i][j] != '.'){
                x = i , y = j , z = str[i][j] - '0';
                dist[i][j] = 0 , riders++;
            }
        }
    }

    bfs(x, y);

    x = y = -1 , ans = INF;
    rep(i, 0, r){
        rep(j, 0, c){
            if(cnt[i][j]>=riders and ans>dist[i][j]) ans = dist[i][j];
        }
    }

    if(ans == INF) cout<<"Case "<<": "<<-1<<endl;
    else cout<<"Case "<<": "<<ans<<endl;
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


