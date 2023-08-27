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

    if(n==1){
        cout << 1 << endl;
        return;
    }

    sort(arr, arr+n);

    int cnt, j, twos = 0, ones = 0;
    for(int i=0; i<n; i++){
        cnt = 0;
        for(j=i; j<n; j++){
            if(arr[i]==arr[j]) cnt++;
            else break;
        }
        i = j-1;
        if(cnt > 1) twos++;
        else ones++;
    }

    int ans = twos + (ones/2);
    if(ones%2==1) ans++;

    cout << ans << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
3
1
1
2
1 2
2
2 1
*/
