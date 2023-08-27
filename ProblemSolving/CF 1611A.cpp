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

    string num = "2468";
    for(int i=0; i<num.size(); i++){
        if(s[s.size() - 1] == num[i]){
            cout << 0 << endl;
            return;
        }
    }

    for(int i=0; i<num.size(); i++){
        if(s[0] == num[i]){
            cout << 1 << endl;
            return;
        }
    }

    for(int i=0; i<num.size(); i++){
        for(int j=0; j<s.size(); j++){
            if(num[i]==s[j]){
                cout << 2 << endl;
                return;
            }
        }
    }

    cout << -1 << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

