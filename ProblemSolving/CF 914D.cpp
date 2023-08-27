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
#define debug         if( 1 )

const int mxn = 500010;

int tr[4*mxn], arr[mxn];

void build(int idx, int l, int r)
{
    if(l == r){
        tr[idx] = arr[l];
        return;
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    build(left, l, mid);
    build(right, mid+1, r);

    tr[idx] = __gcd(tr[left], tr[right]);
}

int query(int idx, int l, int r, int ql, int qr, int x)
{
    if(r<ql || l>qr) return 0;

    if(l>=ql && r<=qr && tr[idx]%x==0) return 0;
    if(l>=ql && r<=qr && l==r) return 1; // t[idx]%x != 0

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    int q1 = 0, q2 = 0;

    q1 = query(left, l, mid, ql, qr, x);
    if(q1 <= 1) q2 = query(right, mid+1, r, ql, qr, x);

    return q1 + q2;
}

void update(int idx, int l, int r, int ul, int ur, int v)
{
    if(r<ul || l>ur) return;
    if(l>=ul && r<=ur){
        tr[idx] = v;
        return;
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    update(left, l, mid, ul, ur, v);
    update(right, mid+1, r, ul, ur, v);

    tr[idx] = __gcd(tr[left], tr[right]);
}

void solve(int tc)
{
    int n; sfi(n);

    rep(i, 1, n+1) sfi(arr[i]);

    build(1, 1, n);

    int q, l, r, x, v, type, ans;

    sfi(q);
    while(q--){
        sfi(type);
        if(type == 1){
            sfi3(l, r, x);
            ans = query(1, 1, n, l, r, x);
            if(ans <= 1) puts("YES");
            else puts("NO");
        }
        else{
            sfi2(l, v);
            update(1, 1, n, l, l, v);
        }
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

