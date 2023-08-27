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
    char c;
    cin >> n >> c;

    string s;
    cin >> s;


    int ans[n], last = -1, first = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='g'){
            first = i;
            break;
        }
    }

    int res = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='g') last = i;
        if(s[i]==c){
            if(last == -1){
                ans[i] = (n-i-1) + (first + 1);
            }
            else{
                ans[i] = last - i;
            }
            res = max(res, ans[i]);
        }
    }

    cout << res << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

