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
    vector<string> s;
    string tmp, str;

    for(int i=1; i<=9; i++){
        for(int j=0; j<4; j++){
            tmp = "";
            for(int k=0; k<=j; k++) tmp += i + '0';
            s.push_back(tmp);
        }

    }

    cin >> str;

    int ans = 0;
    for(int i=0; i<s.size(); i++){
        ans += s[i].size();
        if(s[i] == str) break;
    }

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

