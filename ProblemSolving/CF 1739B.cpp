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
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int prev = v[0];
    for(int i=1; i<n; i++){
        if(prev+v[i]>=0 && prev-v[i]>=0 && prev+v[i]!=prev-v[i]){
            cout << -1 << endl;
            return;
        }
        else if(prev+v[i]>=0){
            prev += v[i];
        }
        else{
            prev -= v[i];
        }
    }

    int sum = 0;
    for(int i=0; i<n ;i++){
        sum += v[i];
        cout << sum << ' ';
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

