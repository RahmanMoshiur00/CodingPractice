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

    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    int neg = 0, pos = 0;
    for(int i=0; i<n; i++){
        if(a[i] < 0){
            neg = a[i];
            pos = max(0LL, pos+neg);
        }
        else if(a[i] > 0){
            pos += a[i];
        }
    }

    cout << pos << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

