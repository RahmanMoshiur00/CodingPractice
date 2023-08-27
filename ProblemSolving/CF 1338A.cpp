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

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int max_diff = 0, mx[n];
    mx[0] = arr[0];
    for(int i=1; i<n; i++){
        mx[i] = max(mx[i-1], arr[i]);
        max_diff = max(max_diff, mx[i] - arr[i]);
    }

    if(max_diff == 0){
        cout << 0 << endl;
        return;
    }

    int two[35];
    two[0] = 1;
    for(int i=1; i<35; i++) two[i] = two[i-1] * 2;

    int tot = 0;
    for(int i=0; i<35; i++){
        tot += two[i];
        if(tot >= max_diff){
            cout << i+1 << endl;
            return;
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

