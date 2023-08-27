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

    string s;
    cin >> s;

    if(n==1){
        if(s=="0") cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }

    int ans = 0, j, one = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            j = i+1, one = 0;
            for(; j<n; j++){
                if(s[j]=='1') one++;
                else{
                    if(one<2) ans += (2-one);
                    break;
                }
            }
            i = j - 1;
        }
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

