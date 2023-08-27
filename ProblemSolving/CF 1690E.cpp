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
    int n, k, r, x;
    cin >> n >> k;

    int arr[n];
    vector<int> rem[k];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        r = arr[i] % k;
        rem[r].push_back(arr[i]);
    }

    for(int i=0; i<k; i++) sort(all(rem[i]));

    int ans = 0, sz;

    //for rem = 0
    while(rem[0].size() >= 2){
        x = *rem[0].rbegin();
        rem[0].pop_back();
        x += *rem[0].rbegin();
        rem[0].pop_back();
        ans += x/k;
    }

    // for remainder pairs
    for(int i=1, j=k-1; i<j; i++, j--){
        sz = min(rem[i].size(), rem[j].size());
        while(sz){
            ans += (*rem[i].rbegin() + *rem[j].rbegin() ) / k;
            rem[i].pop_back();
            rem[j].pop_back();
            sz--;
        }
    }

    if(k%2==0){ //i==j
        while(rem[k/2].size() >= 2){
            x = *rem[k/2].rbegin();
            rem[k/2].pop_back();
            x += *rem[k/2].rbegin();
            rem[k/2].pop_back();
            ans += x/k;
        }
    }

    vector<int> v;
    for(int i=0; i<k; i++){
        for(int j=0; j<rem[i].size(); j++) v.push_back(rem[i][j]);
    }


//    for(int i=0; i<k; i++){
//        if(rem[i].empty()) continue;
//        for(int j=i+1; j>k; j++){
//            if(rem[j].empty()) continue;
//            ans += (*rem[i].rbegin() + *rem[j].rbegin() ) / k;
//            rem[i].pop_back();
//            rem[j].pop_back();
//        }
//    }

    if(!v.empty()){
        sort(all(v));
        for(int i=0; i+1<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if((v[i]+v[j]) >= k){
                    ans += (v[i]+v[j]) / k;
                    v[j] = 0;
                }
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

