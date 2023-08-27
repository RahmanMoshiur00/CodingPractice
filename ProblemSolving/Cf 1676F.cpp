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
    int n, k;
    cin >> n >> k;

    map<int,int> mp;
    set<int> st;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
        st.insert(arr[i]);
    }

    vector<int> v;
    int val;
    for(auto &x : st){
        val = x;
        if(mp[val] >= k) v.push_back(val);
    }

    if(v.empty()){
        cout << -1 << endl;
        return;
    }

    int l = -1, r = -1, len = 0;
    for(int i=0; i<v.size(); i++){
        int j = i, k = 0;
        for(; j<v.size(); j++){
            if(v[i]+k != v[j]) break;
            k++;
        }
        if(j-i > len){
            l = v[i];
            r = v[j-1];
            len = j - i;
        }
        i = j - 1;
    }

    cout << l << ' ' << r << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

