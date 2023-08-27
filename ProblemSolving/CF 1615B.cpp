#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 200010;

int cum[mxn][19];

string bin(int n)
{
    string s = "";
    while(n!=0){
        s += char('0' + (n%2));
        n /= 2;
    }
    while(s.size() < 19) s += '0';

    string temp = "";
    for(int i=18; i>=0; i--) temp += s[i];

    return temp;
}

void init()
{
    for(int i=0; i<19; i++) cum[0][i] = 0;
    string s;
    for(int i=1; i<mxn; i++){
        s = bin(i);
        for(int j=0; j<19; j++){
            cum[i][j] = cum[i-1][j] + (s[j] - '0');
        }
    }
}

void solve(int test_case)
{
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for(int i=0; i<19; i++){
        ans = max(ans, cum[r][i]-cum[l-1][i]);
    }

    cout << r-l+1 - ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //cout << "For 6 = " << bin(6) << endl;
    //cout << "For 16 = " << bin(16) << endl;

    init();

    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

