#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010;

int calc(int n)
{
    if(n==1) return 1;
    if(n==2) return 3;
    return n * (n-1);
}

void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = 0LL, now = 0LL, j;
    for(int i=0; i<n; i++){
        now = 0, j = i;
        for(; j<n; j++){
            if(arr[j]>=now+1) now++;
            else{
                break;
            }
        }
        if(i!=0){
            now += arr[i]-1;
            ans -= calc(arr[i]-1);
        }
        i = j-1;
        ans += calc(now);
    }

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
4
3
1 2 3
3
1 1 1
4
2 1 4 3

6
2 4 5 4 3 4
*/
