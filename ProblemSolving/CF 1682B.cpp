#include <bits/stdc++.h>
using namespace std;
//#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;

void solve(int test_case)
{
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> v;
    for(int i=n-1; i>=0; i--){
        if(i != arr[i]){
            v.push_back(arr[i]);
        }
    }

    int ans = v[0];
    for(int i=1; i<v.size(); i++) ans &= v[i];

    cout << ans << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

