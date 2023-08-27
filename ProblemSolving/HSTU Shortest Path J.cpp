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
#define mxn           10010

vector<int> adj[mxn];
map<string,int> mp;
int level[mxn], nodes = 1;

void bfs(int s)
{
    rep(i, 0, mxn) level[i] = -1;

    level[s] = 0;
    queue< int > q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();

        rep(i, 0, adj[u].size()){
            int v = adj[u][i];

            if(level[v] == -1){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

void make_graph()
{
    string str, tmp;
    getline(cin, str);

    vector<int> vn;
    int cnt = 0, brk = 0;

    stringstream ss(str);
    while(ss>>str){
        cnt++;
        if(cnt % 2) tmp = str;
        else{
            tmp += " "; tmp += str;

            if(*tmp.rbegin() == ':') brk = 1;
            tmp.erase(tmp.end()-1, tmp.end());

            if(mp.find(tmp) == mp.end()) mp[tmp] = nodes++;

            vn.push_back(mp[tmp]);
            if(brk) break;
        }
    }

    rep(i, 0, vn.size()){
        rep(j, 0, vn.size()){
            if(i != j){
                int u = vn[i] , v = vn[j];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
}

void solve(int tc)
{
    int p, q; cin>>p>>q; getchar();

    rep(i, 0, p) make_graph();

    bfs(mp["Erdos, P."]);

    string psycho;
    cout<<"Scenario "<<tc<<endl;
    rep(i, 0, q){
        getline(cin, psycho);
        cout<<psycho<<sp;

        int idx = mp[psycho];
        if(level[idx] == -1) cout<<"infinity"<<endl;
        else cout<<level[idx]<<endl;
    }

    rep(i, 0, mxn) adj[i].clear();
    mp.clear();
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


