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
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int ans = 0, cnt = 0;
    for(int i=1; i<=n; i++){
        cnt = 0;
        for(int j=1; j<i; j++){
            if(i<=arr[j] && arr[i]<=arr[j]) cnt++;
        }
        ans += cnt;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

