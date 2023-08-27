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

    int st[n], en[n];
    for(int i=0; i<n; i++) cin >> st[i];
    for(int i=0; i<n; i++) cin >> en[i];

    int last_end = -1;
    for(int i=0; i<n; i++){
        if(last_end < st[i]){
            cout << en[i] - st[i] << ' ';
        }
        else{
            cout << en[i] - last_end << ' ';
        }
        last_end = en[i];
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

