#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define pfs(x)        printf("%s", "x");
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           155

int cost[mxn][mxn];
int ranking[mxn];
int qsource[6010] , qdest[6010] , ans[6010];
vector< int > query[mxn];

int main()
{
    FasterIO

    int tc, n, c, r, s, d, p, q;
    sfi(tc);

    for(int t=1; t<=tc; t++){
        sfi(n);

        for(int i=1; i<=n; i++){
            cost[i][i] = 0;
            for(int j=i+1; j<=n; j++){
                sfi(c);
                if(c==-1) c = INF;
                cost[i][j] = cost[j][i] = c;
            }
        }

        sfi(p);
        for(int i=1; i<=p; i++) sfi(ranking[i]);

        sfi(q);
        for(int i=1; i<=q; i++){
            sfi(r) , sfi(qsource[i]) , sfi(qdest[i]);
            query[r].pb(i);
        }

        for(auto i : query[0]){
            if(cost[qsource[i]][qdest[i]] == INF) ans[i] = -1;
            else ans[i] = cost[qsource[i]][qdest[i]];
        }

        for(int sz=1; sz<=p; sz++){
            int k = ranking[sz];
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++) if(cost[i][k]+cost[k][j]<cost[i][j]) cost[i][j] = cost[i][k]+cost[k][j];
            }
            for(auto i : query[sz]){
                if(cost[qsource[i]][qdest[i]] == INF) ans[i] = -1;
                else ans[i] = cost[qsource[i]][qdest[i]];
            }
        }

        printf("Case %d:", t);
        for(int i=1; i<=q; i++) printf(" %d", ans[i]);
        printf("\n");

        for(int i=0; i<mxn; i++) query[i].clear();
    }

    return 0;
}
