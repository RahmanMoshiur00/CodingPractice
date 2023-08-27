#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //e.g. ordered_set<int> s; s.insert(3); cout<<s.ook(3)<<*s.fbo(3);
#define ook           order_of_key
#define fbo           find_by_order //returns pointer
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
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
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define fr(i,a,b)     for(int i=(a); i<=(b); i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second.first
#define ssd           second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           100010

#define GCD(a,b,c)    __gcd(a, __gcd(b,c))


vector< pair<int, pair<int, int> > > v;

bool check(int a, int b, int c){
    if(v.empty()) return true;

    for(int i=0; i<v.size(); i++){
        if((a==v[i].ff && b==v[i].ss && c==v[i].ssd) || (a==v[i].ff && c==v[i].ss && b==v[i].ssd) || (b==v[i].ff && a==v[i].ss && c==v[i].ssd) || (b==v[i].ff && c==v[i].ss && a==v[i].ssd) || (c==v[i].ff && a==v[i].ss && b==v[i].ssd) || (c==v[i].ff && b==v[i].ss && a==v[i].ssd)) return false;
    }
    return true;
}

int main()
{
    int tc, f, g; sfi(tc);

    for(int t=1; t<=tc; t++){

        sfi(f) , sfi(g);
        int res = 0;
        for(int i=1; i<=f; i++){
            for(int j=1; j<=f; j++){
                for(int k=1; k<=f; k++){
                    int gcd = GCD(i,j,k);
                    if(gcd==g && ((i*j*k/gcd) == f) && check(i, j, k)){
                        res++;
                        v.pb(mp(i, mp(j,k)));
                        //cout<<"dbg: "<<i<<sp<<j<<sp<<k<<endl;
                    }
                }
            }
        }
        printf("%d\n", res);
        v.clear();
    }



    return 0;
}

