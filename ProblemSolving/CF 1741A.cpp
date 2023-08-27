#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010;


void solve(int test_case)
{
    string a, b;
    cin >> a >> b;

    char ab = a.back(), bb = b.back();

    if(ab != bb){
        if(ab > bb) cout << "<" << endl;
        else cout << ">" << endl;
        return;
    }

    for(int i = a.size() - 1 , j = b.size() - 1; i>=0 && j>=0; i--, j--){
        if(a[i]!=b[j]){
            if(a[i] > b[j]) cout << '<' << endl;
            else cout << '>' << endl;
            return;
        }
    }

    if(a.size() == b.size()){
        cout << "=" << endl;
    }
    else if(a.size() > b.size()){
        if(ab == 'S') cout << '<' << endl;
        else cout << '>' << endl;
    }
    else{
        if(ab == 'S') cout << '>' << endl;
        else cout << '<' << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

