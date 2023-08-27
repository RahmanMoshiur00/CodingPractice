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
#define INF           1e15
#define mod           1000000007
#define mxn           30


intl d[mxn][mxn], t[mxn][mxn];


int main()
{

    intl tc, n, m, u, v, tm, w, q; cin>>tc;

    rep(cas, 0, tc){
        cin>>n>>m;
        n++;

        rep(i, 1, n){
            rep(j, 1, n){
                if(i == j) d[i][j] = t[i][j] = 0LL;
                else d[i][j] = t[i][j] = INF;
            }
        }

        rep(i, 0, m){
            cin>>u>>v>>tm>>w;
            if(tm<t[u][v] or (tm==t[u][v] and w<=d[u][v])){
                t[u][v] = t[v][u] = tm;
                d[u][v] = d[v][u] = w;
            }
        }

        rep(k, 1, n){
            rep(i, 1, n){
                rep(j, 1, n){
                    if(t[i][j]>t[i][k]+t[k][j] or (t[i][j]==t[i][k]+t[k][j] and d[i][j]>d[i][k]+d[k][j])){
                        t[i][j] = t[i][k]+t[k][j];
                        d[i][j] = d[i][k]+d[k][j];
                    }
                }
            }
        }

        if(cas) cout<<endl;

        cin>>q;
        while(q--){
            cin>>u>>v;
            if(d[u][v] == INF) cout<<"No Path."<<endl;
            else cout<<"Distance and time to reach destination is "<<d[u][v]<<" "<<'&'<<" "<<t[u][v]<<"."<<endl;

        }
    }

    return 0;
}


