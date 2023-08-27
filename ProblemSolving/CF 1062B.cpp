#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl, intl> pll;
typedef pair<int, int> pii;
typedef pair<intl, pair<intl,intl> > plll;
typedef pair<int, pair<int,int> > piii;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //e.g. ordered_set<int> s; s.insert(3); cout<<s.ook(3)<<*s.fbo(3);
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          '\n'
#define sp            ' '
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
#define mxn           1000010

bool powtwo(intl n){
    return ((n != 0) && ((n &(n - 1)) == 0));
}

void solve(intl n){
    intl res = 1LL, cnt = 0, mx = 0, mn = INT_MAX, m = n;
    if(n%2==0){
        while(n%2==0) n/=2 , cnt++;
        mx = max(mx, cnt);
        mn = min(mn, cnt);
        res *= 2;
    }
    for(intl i=3; i<=sqrt(n+1.0); i+=2){
        if(n%i==0){
            cnt = 0;
            while(n%i==0) n/=i , cnt++;
            mx = max(mx, cnt);
            mn = min(mn, cnt);
            res *= i;
        }
    }
    if(n>1){
        mx = max(mx, 1LL);
        mn = min(mn, 1LL);
        res *= n;
    }

    if(res == m){
        cout<<res<<sp<<0<<endl;
        return;
    }

    intl step = 0;
    if(mx==mn and powtwo(mx)) step = 0;
    else step++;

    step += ceil(log2(mx*1.0));
    cout<<res<<sp<<step<<endl;
}


int main()
{
    intl num; cin>>num;

    solve(num);

    return 0;
}

