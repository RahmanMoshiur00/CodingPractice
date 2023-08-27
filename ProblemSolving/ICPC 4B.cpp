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
    int n, m;
    cin >> n >> m;

    string s[n];
    for(int i=0; i<n; i++) cin >> s[i];

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j+1<m; j++){
            if(s[i][j]=='*' && s[i][j+1]=='*'){
                cnt++;
                break;
            }
        }
    }

    cout << "Case " << test_case << ": ";
    if(cnt == 3) cout << "Eight" << endl;
    else cout << "Zero" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

