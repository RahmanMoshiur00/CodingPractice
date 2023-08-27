#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;

vector<int> expand(int arr[], int n, int m)
{
    vector<int> v;
    for(int i=0; i<n; i++){
        while(arr[i]%m==0){
            arr[i] /= m;
            for(int j=0; j<m; j++) v.push_back(arr[i]);
        }
        v.push_back(arr[i]);
    }
    return v;
}

void solve(int test_case)
{
    int n, m;
    cin >> n >> m;
    int arr1[n];
    for(int i=0; i<n; i++) cin >> arr1[i];

    int k;
    cin >> k;
    int arr2[k];
    for(int i=0; i<k; i++) cin >> arr2[i];

    vector<int> v1, v2;
    v1 = expand(arr1, n, m);
    v2 = expand(arr2, k, m);

    debug{
        cout << "v1: "; for(int i=0; i<v1.size(); i++) cout << v1[i] << ' '; cout << endl;
        cout << "v2: "; for(int i=0; i<v2.size(); i++) cout << v2[i] << ' '; cout << endl;
    }

    if(v1.size() == v2.size()){
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i]){
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

