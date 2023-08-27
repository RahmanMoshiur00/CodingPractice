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
    cin >> n;

    int alice[n];
    for(int i=0; i<n; i++) cin >> alice[i];

    cin >> m;
    int bob[m];
    for(int i=0; i<m; i++) cin >> bob[i];

    int mxa = *max_element(alice, alice+n);
    int mxb = *max_element(bob, bob+m);

    if(mxa >= mxb) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    if(mxa <= mxb) cout << "Bob" << endl;
    else cout << "Alice" << endl;

//    sort(alice, alice+n);
//    sort(bob, bob+m);

//    bool printed = false;
//    for(int i=n-1, j=m-1; i>=0 && j>=0; i--, j--){
//        if(alice[i] < bob[j]){
//            printed = true;
//            cout << "Bob" << endl;
//            break;
//        }
//        else if(alice[i] > bob[j]){
//            printed = true;
//            cout << "Alice" << endl;
//            break;
//        }
//    }
//    if(!printed){
//        if(n==m) cout << "Bob" << endl;
//        else if(n)
//    } cout << "Bob" << endl;
//
//
//    printed = false;
//    for(int i=n-1, j=m-1; i>=0 && j>=0; i--, j--){
//        if(alice[i] < bob[j]){
//            cout << "Bob" << endl;
//            printed = true;
//            break;
//        }
//        else if(alice[i] > bob[j]){
//            printed = true;
//            cout << "Alice" << endl;
//            break;
//        }
//    }
//    if(!printed) cout << "Alice" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

