#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;
int arr[mxn];

struct info
{
    int gcd;
} tree[mxn * 4];

void build(int ind, int b, int e)
{
    if(b==e){
        tree[ind].gcd = arr[b];
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[ind].gcd = __gcd(tree[left].gcd, tree[right].gcd);
}

int query(int ind, int b, int e, int l, int r)
{
    if(e<l || b>r) return 0;
    if(b>=l && e<=r){
        return tree[ind].gcd;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    int q1 = query(left, b, mid, l, r);
    int q2 = query(right, mid+1, e, l, r);

    int res = __gcd(q1, q2);
    return res;
}

void solve(int test_case)
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    sort(arr+1, arr+1+n);

    build(1, 1, n);

    int l, r, ans;
    for(int i=1; i<=n; i++){
        if(i%2==0){
            l = i/2;
            r = n - (i/2);
        }
        else{
            l = (i/2) + 1;
            r = n - (i/2);
        }
        ans = query(1, 1, n, l, r);
        if(i>1) cout << ' ';
        cout << ans;
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

