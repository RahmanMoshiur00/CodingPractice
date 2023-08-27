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

    stack<int> stk;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(i) cout << ' ';
        while(!stk.empty() && arr[stk.top()] >= arr[i]){
            stk.pop();
        }
        if(stk.empty()){
            cout << 0 ;
        }
        else{
            cout << stk.top() + 1;
        }
        stk.push(i);
    }
    cout << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

