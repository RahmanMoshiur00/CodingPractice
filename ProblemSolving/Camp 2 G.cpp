#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;

    int arr[1005], passed = 0, tp;
    stack<int> stk;

    while(true){
        cin >> n;
        if(n == 0) return;
        for (int i=0; i<n; i++) cin >> arr[i];

        passed = 0;
        stk = stack<int>();
        for(int i=0; i<n; i++){
            if(passed + 1 == arr[i]){
                passed++;
            } else{
                stk.push(arr[i]);
            }
            while(!stk.empty() && passed+1 == stk.top()){
                stk.pop();
                passed++;
            }
        }
        if(n == passed){
            cout << "yes\n";
        } else{
            cout << "no\n";
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

