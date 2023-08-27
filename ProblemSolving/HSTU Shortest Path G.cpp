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
#define INF           1000000007
#define mod           1000000007
#define mxn           25


vector<string> str;
int d[mxn][mxn];

int main()
{

    int n, m, u, v, w, cas = 1;
    while(cin>>n>>m and n){
        getchar();
        str.resize(n);
        rep(i, 0, n) getline(cin, str[i]);

        rep(i, 0, n){
            rep(j, 0, n){
                if(i==j) d[i][j] = 0;
                else d[i][j] = INF;
            }
        }

        rep(i, 0, m){
            cin>>u>>v>>w;
            u--, v--;
            d[u][v] = d[v][u] = min(d[u][v], w);
        }

        rep(k, 0, n)
            rep(i, 0, n)
                rep(j, 0, n)
                    if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];

        int idx = 0, cost = 0, cost_so_far = INF;
        rep(i, 0, n){
            cost = 0;
            rep(j, 0, n) cost += d[i][j];
            if(cost < cost_so_far) cost_so_far = cost, idx = i;
        }

        cout<<"Case #"<<cas++<<" : "<<str[idx]<<endl;
    }

    return 0;
}


