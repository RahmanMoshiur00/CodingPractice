#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 32;

int cnt[mxn];

void f(int n)
{
    string s = "";
    while(n){
        s += char((n%2)+'0');
        n /= 2;
    }
    //reverse(all(s));
    for(int i=0; i<s.size(); i++){
        cnt[i] += (s[i] - '0');
    }
}

void solve(int test_case)
{
    int n;
    cin >> n;

    ZERO(cnt);
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++){
        f(arr[i]);
    }

    int last = -1;
    for(int i=0; i<32; i++){
        if(cnt[i]>0){
            last = i;
        }
    }

    int val = 1LL, sum = 0LL;
    for(int i=0; i<last; i++){
        if(cnt[i]>=1){
            sum += val;
        }
        val *= 2;
    }
    sum += val;

    cout << sum << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

