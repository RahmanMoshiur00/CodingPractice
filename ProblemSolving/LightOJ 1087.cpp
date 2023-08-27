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


#define mxn           150010 //n=10^5 + q=5*10^4

int arr[mxn], tree[4 * mxn];
int n, q;

void build(int ind, int b, int e)
{
    if(b==e){
        if(b<=n) tree[ind] = 1; // initially 1 to n'th army are able to attack
        else tree[ind] = 0; // not able to attack
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[ind] = tree[left] + tree[right];
}

void update(int ind, int b, int e, int i, int v)
{
    if(e<i || b>i) return;
    if(b>=i && e<=i){
        tree[ind] = v;
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    update(left, b, mid, i, v);
    update(right, mid+1, e, i, v);

    tree[ind] = tree[left] + tree[right];
}

int query(int ind, int b, int e, int l, int r)
{
    if(e<l || b>r) return 0;
    if(b>=l && e<=r){
        return tree[ind];
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    int q1 = query(left, b, mid, l, r);
    int q2 = query(right, mid+1, e, l, r);

    return q1 + q2;
}

void solve(int tc)
{
    sfi2(n, q);

    rep(i, 1, n+1){
        sfi(arr[i]);
    }

    int sz = n + q; // because, if q time "a p" query appears then segment tree must have n+q nodes overall

    build(1, 1, sz);

    pfs("Case "), pfi(tc), pfs(":\n");

    char str[3];
    int p, k;

    while(q--){
        sfs(str);
        if(str[0]=='c'){
            sfi(k);

            int lo = 1, hi = sz, mid, tot, pos = -1;
            while(lo<=hi){ // searching the index for which we can send k'th army using binary search
                mid = (lo+hi) / 2;
                tot = query(1, 1, sz, 1, mid);
                if(tot >= k){
                    pos = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }

            if(pos == -1){
                pfsn("none");
            }
            else{
                pfin(arr[pos]);
                update(1, 1, sz, pos, 0);
            }
        }
        else{
            sfi(p);
            arr[++n] = p;
            update(1, 1, sz, n, 1);
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

