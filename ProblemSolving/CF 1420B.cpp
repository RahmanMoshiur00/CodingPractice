#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;
int cnt[35];

int bin(int n)
{
    int bit_count = 0;
    while(n){
        n /= 2;
        bit_count++;
    }
    return bit_count;
}

void solve(int test_case)
{
    int n;
    cin >> n;

    ZERO(cnt);
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++){
        cnt[bin(arr[i])]++;
    }

    int tot = 0;
    for(int i=0; i<35; i++){
        tot += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    cout << tot << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

