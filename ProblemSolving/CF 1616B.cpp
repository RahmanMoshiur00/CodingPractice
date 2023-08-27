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

    int idx = -1;

    for(int i=1; i<n; i++){
        if(i==1){
            if(s[i-1]<=s[i]){
                idx = i;
                break;
            }
        }
        if(s[i-1]<s[i]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << s;
        for(int i=s.size()-1; i>=0; i--) cout << s[i];
        cout << endl;
    }
    else{
        for(int i=0; i<idx; i++) cout << s[i];
        for(int i=idx-1; i>=0; i--) cout << s[i];
        cout << endl;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

