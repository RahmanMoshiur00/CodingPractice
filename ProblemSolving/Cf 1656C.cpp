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

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    bool one = false, zero = false, two = false;
    for(int i=0; i<n; i++){
        if(arr[i] == 1) one = true;
        else if(arr[i] == 0) zero = true;
        else if(arr[i] == 2) two = true;
    }

    if(one){
        if(zero or two){
            cout << "NO" << endl;
        }
        else{
            map<int,int> mp;
            for(int i=0; i<n; i++){
                if(arr[i]!=1) mp[arr[i]] = 1;
            }

            for(int i=0; i<n; i++){
                if(arr[i]!=1 && mp[arr[i]+1]==1){
                    cout << "NO" << endl;
                    return;
                }
            }
            cout << "YES" << endl;
        }
    }
    else{
        cout << "YES" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

