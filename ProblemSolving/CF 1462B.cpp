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

    if(s[n-1]=='0' && s[n-2]=='2' && s[n-3]=='0' && s[n-4]=='2'){
        cout << "YES" << endl;
    }
    else if(s[0]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0'){
        cout << "YES" << endl;
    }
    else if(s[0]=='2' && s[1]=='0' && s[n-2]=='2' && s[n-1]=='0'){
        cout << "YES" << endl;
    }
    else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n-1]=='0'){
        cout << "YES" << endl;
    }
    else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0'){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

