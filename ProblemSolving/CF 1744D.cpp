#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010;

int power_of_two(int n)
{
    if(n == 0) return 0;
    int cnt = 0;
    debug cout << n << " = ";
    while(n%2==0){
        n /= 2;
        cnt++;
    }
    debug cout << cnt << endl;
    return cnt;
}

void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> v;
    int prev = 0LL, need = 0LL, p2 = 0LL;
    for(int i=0; i<n; i++){
        prev += power_of_two(arr[i]);
        p2 = power_of_two(i+1);
        if(p2 > 0){
            v.push_back(p2);
        }
    }

    if(!v.empty()) sort(v.begin(), v.end(), greater<int>());

    int ans = 0;
    need = n - prev;
    if(need > 0){
        for(auto x : v){
            need -= x;
            ans++;
            if(need <= 0) break;
        }
    }

    if(need > 0) cout << -1 << endl;
    else cout << ans << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

