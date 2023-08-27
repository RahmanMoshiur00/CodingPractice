#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define all(a)        a.begin(), a.end()
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n, q, l, r, st, en;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int cnt[n];
    cnt[0] = arr[0];
    for(int i=1; i<n; i++) cnt[i] = cnt[i-1] + arr[i];

    cin >> q;
    while(q--){
        cin >> l >> r;
        st = lower_bound(arr, arr+n, l) - arr;
        en = upper_bound(arr, arr+n, r) - arr;
        if(en==0 || st==n){
            cout << 0 << endl;
        } else{
            cout << cnt[en-1] - cnt[st] + arr[st] << endl;
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

