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

vector< int > adj[mxn];
bool vis[mxn];

int bfs(int s, int t){
    int n, l;

    mem(vis, 0);
    vis[s] = true;
    queue< pair<int, int> > q;
    q.push({s, 0});

    while(!q.empty()){
        n = s = q.front().ff , l = q.front().ss; q.pop();

        if(s==t) return l;

        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0){
                while(n%i==0) n /= i;
                if(!vis[s+i] and t>=s+i){
                    vis[s+i] = true;
                    q.push({s+i, l+1});
                }
            }
        }

        if(n>1 and n!=s and !vis[s+n] and t>=s+n){
            vis[s+n] = true;
            q.push({s+n, l+1});
        }
    }

    return -1;
}

void solve(int c){
    int s, t; cin>>s>>t;

    int ans = bfs(s, t);
    cout<<"Case "<<c<<": "<<ans<<endl;

    rep(i, 0, mxn) adj[i].clear();
}


int main()
{
    int tc, s, t; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


