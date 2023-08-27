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
    int n, v;
    cin >> n;

    set<int> st;
    int cnt[105] = {0};

    for(int i=0; i<n; i++){
        cin >> v;
        if(v<0) v = -v;
        cnt[v]++;
    }

    int ans = 0;
    for(int i=0; i<105; i++){
        if(i==0){
            if(cnt[i]>=1) ans++;
            continue;
        }
        if(cnt[i] <= 1) ans += cnt[i];
        else ans += 2;
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

