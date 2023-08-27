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
    set<int> st;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        st.insert(i+1);
    }

    if(n == 1){
        cout << -1 << endl;
        return;
    }

    int v, ans[n];
    set<int>::iterator it;
    for(int i=0; i<n; i++){
        if(arr[n-1] == n && i==n-2){
            ans[i] = n;
            st.erase(n);
            continue;
        }
        it = st.begin();
        v = *it;
        if(arr[i] == v){
            it++;
            v = *it;
        }
        st.erase(v);
        ans[i] = v;
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    } cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

