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

    int mx = *max_element(arr, arr+n);
    int mn = *min_element(arr, arr+n);

    if(mx == mn) cout << -1 << endl;
    else{
        for(int i=0; i<n; i++){
            if(arr[i] == mx && ((i+1<n && arr[i]>arr[i+1]) || (i-1>=0 && arr[i]>arr[i-1]))){
                cout << i + 1 << endl;
                return;
            }
        }
    }

//    int peak = -1, peak_id = -1;
//    if(arr[0]>arr[1]){
//        peak = arr[0];
//        peak_id = 1;
//    }
//    if(arr[n-1]>arr[n-2] && arr[n-1]>peak){
//        peak = arr[n-1];
//        peak_id = n;
//    }
//
//    for(int i=1; i+1<n; i++){
//        if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && arr[i]>peak){
//            peak = arr[i];
//            peak_id = i + 1;
//        }
//    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

