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
#define mxn           20010

typedef vector<int> vi;

bool vis[mxn];
int res[2] , level[mxn];

int dfs(vector< vi >& adj, int s){
    queue<int> q;
    q.push(s);

    level[s] = 1 , vis[s] = true;
    res[0] = 0 , res[1] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(vis[v] == false){
                q.push(v);
                vis[v] = true;
                level[v] = level[u] + 1;
                int x = level[v] % 2;
                res[x]++;
            }
        }
    }

    return max(res[0], res[1]);
}

int main()
{
    FastRead;

    int tc, n, u, v; cin>>tc;

    rep(t, 1, tc+1){
        cin>>n;
        vector< vi > adj(mxn);
        set< int > st;

        rep(i, 0, n){
            cin>>u>>v;
            st.insert(u) , st.insert(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        mem(vis, 0);
        repeach(i , st){
            if(!vis[ *i ]) ans += dfs(adj, *i);
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }


    return 0;
}
