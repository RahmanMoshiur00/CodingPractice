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
    string s;
    cin >> n >> s;

    int ans[n] = {0}, cnt = 1;
    stack<int> zero, one;
    if(s[0] == '0') zero.push(1);
    else one.push(1);
    ans[0] = 1;

    for(int i=1; i<n; i++){
        if(s[i] == '0'){
            if(one.empty()){
                cnt++;
                zero.push(cnt);
            } else{
                zero.push( one.top() );
                one.pop();
            }
            ans[i] = zero.top();
        } else{
            if(zero.empty()){
                cnt++;
                one.push(cnt);
            } else{
                one.push( zero.top() );
                zero.pop();
            }
            ans[i] = one.top();
        }
    }

    cout << cnt << endl;
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}
