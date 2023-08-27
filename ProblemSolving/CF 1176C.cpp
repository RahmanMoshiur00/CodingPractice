#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long intu;
typedef long long int intl;
//-----------------directions-----------------//
// int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
// int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
// int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//-------------------debug--------------------//
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define FastRead        ios::sync_with_stdio(0); cin.tie(0);
#define OUTPUT          freopen("output.txt","w",stdout);
#define INPUT           freopen("input.txt","r",stdin);
//------------------vivid--------------------//
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//------------------print--------------------//
#define int             long long
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld", (intl)a), printf("\n")
#define pfis(a)         printf("%lld", (intl)a), printf(" ")
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define pfsn(a)         printf("%s", a), printf("\n")
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '
//------------------input--------------------//
#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
//-------------------loop-------------------//
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
//--------------initialization--------------//
#define ZERO(a)         memset(a, 0, sizeof(a))
#define MINUS(a)        memset(a, 0xff, sizeof(a))
#define setval(a, v)    for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
//-------------------misc.------------------//
#define all(a)          a.begin(), a.end()
#define max3(a, b, c)   max(a,max(b,c))
#define min3(a, b, c)   min(a,min(b,c))
#define INF             1000000007
#define debug           if( 1 )

const int mxn = 500010;

int n, arr[mxn], nat = 0, mxind;
vector<int> adj[mxn];
vector<int> ind[50];

int put(int v)
{
    if(v == 4){
        nat++;
        if(nat > mxind) return 1;
        adj[nat].push_back(v);
        ind[4].push_back(nat);
    }
    else if(v == 8){
        if(ind[4].empty()) return 1;
        else{
            adj[ *ind[4].rbegin() ].push_back(8);
            ind[8].push_back(*ind[4].rbegin());
            ind[4].pop_back();
        }
    }
    else if(v == 15){
        if(ind[8].empty()) return 1;
        else{
            adj[ *ind[8].rbegin() ].push_back(15);
            ind[15].push_back(*ind[8].rbegin());
            ind[8].pop_back();
        }
    }
    else if(v == 16){
        if(ind[15].empty()) return 1;
        else{
            adj[ *ind[15].rbegin() ].push_back(16);
            ind[16].push_back(*ind[15].rbegin());
            ind[15].pop_back();
        }
    }
    else if(v == 23){
        if(ind[16].empty()) return 1;
        else{
            adj[ *ind[16].rbegin() ].push_back(23);
            ind[23].push_back(*ind[16].rbegin());
            ind[16].pop_back();
        }
    }
    else if(v == 42){
        if(ind[23].empty()) return 1;
        else{
            adj[ *ind[23].rbegin() ].push_back(42);
            ind[42].push_back(*ind[23].rbegin());
            ind[23].pop_back();
        }
    }

    return 0;
}

void solve(int tc)
{
    sfi(n);

    mxind = n / 6;

    rep(i, 0, n) sfi(arr[i]);

    int ans = 0;
    rep(i, 0, n){
        ans += put(arr[i]);
    }

    rep(i, 1, mxind+1){
        if(!adj[i].empty() && adj[i].size() != 6) ans += adj[i].size();
    }

    pfin(ans);
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

