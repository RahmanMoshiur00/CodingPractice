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
    int n, q;
    cin >> n >> q;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];


    if(n==1){
        cout << arr[0] << endl;
        return;
    } else if(n==2){
        cout << max(arr[0], arr[1]) << endl;
        return;
    }

    vector<int> add, sub;
    int peak = 0;
    for(int i=0; i<n; i++){
        if(i==0){
            if(arr[0] > arr[1] && peak==0){
                peak = 1;
                add.push_back(arr[i]);
            } else if(arr[i]<arr[i+1] && peak==1){
                peak = 0;
                sub.push_back(arr[i]);
            }
        } else if(i==n-1){
            if(arr[i]>arr[i-1] && peak==0){
                peak = 1;
                add.push_back(arr[i]);
            } else if(arr[i]<arr[i-1] && peak==1){
                peak = 0;
                sub.push_back(arr[i]);
            }
        } else{
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && peak==0){ // high_peak
                peak = 1;
                add.push_back(arr[i]);
            } else if(arr[i]<arr[i-1] && arr[i]<arr[i+1] && peak==1){
                peak = 0;
                sub.push_back(arr[i]);
            }
        }
    }

    int ans = 0;
    for(int v : add) ans += v;
    for(int i=0; i+1<add.size(); i++) ans -= sub[i];

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

