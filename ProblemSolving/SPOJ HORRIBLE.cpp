#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x) // changes
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x) // no changes
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

const int mxn    =    400010 ;

struct node{
    int sum;
    int prop;
    //node(){sum = prop = 0;}
};

node tree[mxn];

void update(int ind, int b, int e, int i, int  j, int value)
{
    if(e<i || b>j) return;
    if(b>=i && e<=j){
        tree[ind].sum += ( value * (e - b + 1) );
        tree[ind].prop += value;
        return;
    }

    int mid = (b + e) / 2;
    int left = ind * 2;
    int right = left + 1;

    update(left, b, mid, i, j, value);
    update(right, mid+1, e, i, j, value);

    tree[ind].sum = tree[left].sum + tree[right].sum + (tree[ind].prop * (e - b + 1));
}

int query(int ind, int b, int e, int i, int j, int carry = 0)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j){
        return tree[ind].sum + (carry * (e - b + 1));
    }

    int mid = (b + e) / 2;
    int left = ind * 2;
    int right = left + 1;

    int q1 = query(left, b, mid, i, j, carry+tree[ind].prop);
    int q2 = query(right, mid+1, e, i, j, carry+tree[ind].prop);

    return (q1 + q2);
}

void solve(int tc)
{
    int n, qu, p, q, v, qt;
    sfi2(n, qu);

    rep(i, 0, mxn) tree[i].sum = tree[i].prop = 0;

    rep(i, 0, qu){
        sfi(qt);
        if(!qt){
            sfi3(p, q, v);
            update(1, 1, n, p, q, v);
        }
        else{
            sfi2(p, q);
            int ans = query(1, 1, n, p, q, 0);
            pfin(ans);
        }
    }
}

int32_t main()
{
    //INPUT //OUTPUT

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

