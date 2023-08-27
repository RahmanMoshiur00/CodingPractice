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
#define mxn           27


bool vis[27][27][27];


char prev(char c){ return 'a' + (((c - 'a' - 1) + 26) % 26); }
char Next(char c){ return 'a' + (((c - 'a' + 1) + 26) % 26); }
int idx(char c){ return ((c - 'a') + 26) % 26; }

bool valid(string s){ return !vis[s[0]-'a'][s[1]-'a'][s[2]-'a']; }
void visited(string s){ vis[s[0]-'a'][s[1]-'a'][s[2]-'a'] = true; }

int bfs(string s, string d)
{
    queue< pair<string, int> > q;
    q.push({s, 0});

    if(!valid(s) or !valid(d)) return -1;

    while(!q.empty()){
        string u = q.front().ff;
        int l = q.front().ss;
        q.pop();

        if(u == d) return l;

        s = Next(u[0]) , s += u[1] , s += u[2];
        if(valid(s)) visited(s) , q.push({s, l+1});

        s = prev(u[0]) , s += u[1] , s += u[2];
        if(valid(s)) visited(s) , q.push({s, l+1});

        s = u[0] , s += Next(u[1]) , s += u[2];
        if(valid(s)) visited(s) , q.push({s, l+1});

        s = u[0] , s += prev(u[1]) , s += u[2];
        if(valid(s)) visited(s) , q.push({s, l+1});

        s = u[0] , s += u[1] , s += Next(u[2]);
        if(valid(s)) visited(s) , q.push({s, l+1});

        s = u[0] , s += u[1] , s += prev(u[2]);
        if(valid(s)) visited(s) , q.push({s, l+1});
    }

    return -1;
}

void solve(int t)
{
    string start, finish;
    cin>>start>>finish;

    int n; cin>>n; getchar();
    string a, b, c;

    mem(vis, 0);

    rep(i, 0, n){
        cin>>a>>b>>c;
        rep(i, 0, a.size()){
            rep(j, 0, b.size()){
                rep(k, 0, c.size()){
                    vis[a[i]-'a'][b[j]-'a'][c[k]-'a'] = true;
                }
            }
        }
    }

    int ans = bfs(start, finish);

    cout<<"Case "<<t<<": "<<ans<<endl;
}


int main()
{
    //INPUT

    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


