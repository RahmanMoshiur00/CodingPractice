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
    int n, q;
    cin >> n >> q;

    int arr[n], even = 0, odd = 0, total = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        total += arr[i];
        if(arr[i]%2==0) even++;
        else odd++;
    }

    int qu, x;
    while(q--){
        cin >> qu >> x;
        if(qu==0){
            total += (x*even);
            if(x%2==1){
                odd += even;
                even = 0;
            }
        }
        else{
            total += (x*odd);
            if(x%2==1){
                even += odd;
                odd = 0;
            }
        }
        cout << total << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

