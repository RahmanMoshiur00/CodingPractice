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

    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    cout << "ans = ";
    if(n==1){
        cout << 0 << endl;
        return;
    }

    int ans = 0, x, y;
    for(int i=1; i<n; i++){
        x = a[i-1] - a[0];
        y = (i-1-0) * (a[i]-a[i-1]);
        if(x != y){
            cout << i << ' ';
            ans++;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

