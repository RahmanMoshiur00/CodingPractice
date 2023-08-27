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
    string s;
    cin >> s;

    string alpha = "";
    for(int i=0; i<26; i++) alpha += 'a' + i;

    char mx = 'a';
    for(int i=0; i<s.size(); i++){
        mx = max(mx, s[i]);
    }

    int lft = 0, rgt = s.size() - 1;
    for(int i=mx-'a'; i>=0; i--){
        if(alpha[i]==s[lft]){
            lft++;
        }
        else if(alpha[i]==s[rgt]){
            rgt--;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }

    if(lft > rgt) cout << "YES" << endl;
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

