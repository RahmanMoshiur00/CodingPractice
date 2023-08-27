#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;


bool isRegular(string &s)
{
    stack<char> stk;
    for(int i=0, sz = s.size(); i<sz; i++){
        if(s[i]=='(') stk.push('(');
        else{
            if(!stk.empty() && stk.top()=='(') stk.pop();
            else stk.push(')');
        }
    }
    return stk.empty();
}

bool ok(string s, string abc)
{
    for(int i=0, sz = s.size(); i<sz; i++){
        if(s[i]=='A') s[i] = abc[0];
        else if(s[i]=='B') s[i] = abc[1];
        else s[i] = abc[2];
    }

    return isRegular(s);
}

void solve(int test_case)
{
    string s;
    cin >> s;

    if(ok(s, "())") or ok(s, ")((") or ok(s, ")()") or ok(s, "()(") or ok(s, "))(") or ok(s, "(()")) cout << "YES" << endl;
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

