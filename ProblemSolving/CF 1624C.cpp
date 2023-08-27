#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    vector< set<int> > v(n);
    for(int i=0; i<n; i++){
        while(arr[i]>0){
            v[i].insert(arr[i]);
            arr[i] /= 2;
        }
    }

    int taken[n];
    ZERO(taken);
    bool found = false;
    for(int j=n; j>=1; j--){
        found = false;
        for(int i=0; i<n; i++){
            if(!taken[i] && v[i].find(j) != v[i].end()){
                taken[i] = true;
                found = true;
                break;
            }
        }
        if(!found){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

