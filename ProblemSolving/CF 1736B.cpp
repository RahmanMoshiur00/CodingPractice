#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010;


void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    if(n <= 2){
        cout << "YES" << endl;
        return;
    }

    for(int i=2; i<n; i++){
        if(arr[i-2]==arr[i] && arr[i]!=1 && arr[i]%arr[i-1]==0){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

