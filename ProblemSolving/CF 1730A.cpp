#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n, c;
    cin >> n >> c;

    int x;
    int cnt[101];
    ZERO(cnt);

    for(int i=0; i<n; i++){
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for(int i=0; i<=100; i++){
        if(cnt[i]>0) ans+=min(cnt[i], c);
    }

    cout << min(n, ans) << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

