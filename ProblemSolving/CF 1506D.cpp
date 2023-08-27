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

    map<int,int> mp;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    if(mp.size() < 2){
        cout << n << endl;
        return;
    }

    int mx = 0;
    for(auto &x : mp){
        mx = max(mx, x.second);
    }

    if(mx*2 > n){
        cout << n - (2 * (n-mx)) << endl;
    }
    else{
        if(n%2==1) cout << 1 << endl;
        else cout << 0 << endl;
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

