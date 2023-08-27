#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

typedef pair<int, pair<int,int> > piii;

const int mxn = 1000010;

int t[4*mxn], o[4*mxn], c[4*mxn];
string s;

void build(int idx, int l, int r)
{
    if(l == r){
        t[idx] = o[idx] = c[idx] = 0;
        if(s[l-1] == '(') o[idx] = 1;
        else c[idx] = 1;
        return;
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    build(left, l, mid);
    build(right, mid+1, r);

    int valid = min(o[left], c[right]);
    t[idx] = t[left] + t[right] + valid;
    o[idx] = o[left] + o[right] - valid;
    c[idx] = c[left] + c[right] - valid;
}

piii query(int idx, int l, int r, int b, int e)
{
    if(r<b || l>e) return {0, {0, 0}};

    if(l>=b && r<=e){
        return {t[idx], {o[idx], c[idx]}};
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    piii q1 = query(left, l, mid, b, e);
    piii q2 = query(right, mid+1, r, b, e);

    piii q;
    int valid = min(q1.second.first, q2.second.second);
    q.first = q1.first + q2.first + valid;
    q.second.first = q1.second.first + q2.second.first - valid;
    q.second.second = q1.second.second + q2.second.second - valid;

    return q;
}

void solve(int tc)
{
    cin>>s;

    int n = s.size();

    build(1, 1, n);

    int a, b, q; sfi(q);

    while(q--){
        sfi2(a, b);
        piii p = query(1, 1, n, a, b);
        pfin(2 * p.first);
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

