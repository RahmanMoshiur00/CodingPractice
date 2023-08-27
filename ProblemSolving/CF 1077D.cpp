#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define mxn           1000010

intl cnt[mxn];

int main()
{

    intl n, k; cin>>n>>k;

    intl a[n], sum = 0LL;
    for(int i=0; i<n; i++) cin>>a[i] , cnt[a[i]]++;

    vector< pair<intl, intl> > vp;
    for(int i=0; i<mxn; i++){
        if(cnt[i]) vp.pb({cnt[i], i});
    }

    sort(all(vp), greater<pair<intl, intl> >());

    for(int i=0; i<vp.size(); i++) cout<<"debug: "<<vp[i].ss<<sp<<vp[i].ff<<endl;

    intl now = 0LL, last = 0LL;
    vector<pair<intl, intl> > res;
    for(intl i=0; i<n; i++){
        if(vp[i].ff < now/k) break;
        now += vp[i].ff;
        res.pb({vp[i].ss, vp[i].ff});
        last = vp[i].ff;
    }

    for(int i=0; i<res.size(); i++)
        for(int j=0; j<res[i].ss / last; j++) cout<<res[i].ff<<sp<<res[i].ss;

    return 0;
}


