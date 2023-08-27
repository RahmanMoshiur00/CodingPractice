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
//------------------policy DS--------------------//
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
#define debug           if( 0 )

const int mxi = 12;

int pow_3[mxi];
set<int> v;

int f(int, int, int);

void init(){
    pow_3[0] = 1LL;
    for(int i=1; i<mxi; i++){
        pow_3[i] = pow_3[i-1] * 3LL;
    }
    f(0LL, mxi, 0LL);
}

int f(int i, int n, int sum){
    if(i == n) return 0LL;
    v.insert(sum);
    f(i+1, n, sum);
    f(i+1, n, sum+pow_3[i]);
}

void solve(int tc)
{
    int n;
    sfi(n);

    int ans = *v.lower_bound(n);
    pfin(ans);

//    bool taken[mxi];
//
//    int pos = -1;
//    if(n == 1){
//        pfin(1);
//        return;
//    }
//    for(int i=1; i<mxi; i++){
//        if(pow_3[i-1]<n && n<pow_3[i]) pos = i;
//        else if(pow_3[i] == n){
//            pos = i;
//            break;
//        }
//    }
//    if(pow_3[pos] == n){
//        pfin(n);
//        return;
//    }
//
//    int till_pos = 0;
//    for(int i=0; i<pos; i++) till_pos += pow_3[i];
//
//    if(till_pos < n){
//        pfin(pow_3[pos]);
//        return;
//    }
//    else if(till_pos > n){
//        int extra = till_pos - n;
//        bool performed = false, taken[mxi]; ZERO(taken);
//        while(true){
//            int last_i = -1;
//            for(int i=0; i<mxi; i++){
//                if(extra >= pow_3[i] && !taken[i]) last_i = i;
//            }
//            if(last_i == -1) break;
//            extra -= pow_3[last_i];
//            taken[last_i] = true;
//        }
//        if(extra == 0) pfin(till_pos);
//        else pfin(pow_3[pos]);
//        return;
//    }
//    else{
//        pfin(till_pos);
//        return;
//    }

//    int ans = 0LL;
//    while(n > 0){
//        int last = 0;
//        for(int i=0; i<mxi; i++){
//            if(pow_3[i]<=n && !taken[i]) last = pow_3[i];
//        }
//        ans += last;
//        taken[]
//        n -= last;
//    }
//    if(n > 0){
//        for(int i=0; i<39; i++){
//            if
//        }
//    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    init();
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);


    return 0;
}

