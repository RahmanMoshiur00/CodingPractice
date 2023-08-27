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

#define mxn           100010


int arr[mxn], freq[mxn], start[mxn], End[mxn], n;
int tree[4*mxn];

void build(int idx, int l, int r)
{
    if(l == r){
        tree[idx] = freq[l];
        return;
    }

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    build(left, l, mid);
    build(right, mid+1, r);

    tree[idx] = max(tree[left], tree[right]);
}

int query(int idx, int l, int r, int i, int j)
{
    if(r<i || l>j) return 0;
    if(l>=i && r<=j) return tree[idx];

    int mid = (l+r) >> 1;
    int left = idx << 1;
    int right = left + 1;

    int q1 = query(left, l, mid, i, j);
    int q2 = query(right, mid+1, r, i, j);

    return max(q1, q2);
}

void solve(int tc)
{
    int q, ans, l, r;

    while(sfi(n) && n) {
        sfi(q);

        rep(i, 1, n+1) sfi(arr[i]);

        int cnt = 1, st = 1;
        rep(i, 2, n+1){
            if(arr[i] != arr[i-1]){
                rep(j, st, i){
                    freq[j] = cnt;
                    start[j] = st;
                    End[j] = i-1;
                }
                cnt = 1;
                st = i;
            }
            else{
                cnt++;
            }

            if(i == n){
                rep(j, st, n+1){
                    freq[j] = cnt;
                    start[j] = st;
                    End[j] = n;
                }
            }
        }

        build(1, 1, n);

        while(q--){
            sfi2(l, r);

            if(arr[l] == arr[r]) {
                ans = r - l + 1;
            }
            else{
                ans = max(End[l]-l+1, r-start[r]+1);
                if(End[l]+1 <= start[r]-1){
                    ans = max(ans, query(1, 1, n, End[l]+1, start[r]-1));
                }
            }

            pfin(ans);
        }
    }
}

int32_t main()
{
    //INPUT OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
