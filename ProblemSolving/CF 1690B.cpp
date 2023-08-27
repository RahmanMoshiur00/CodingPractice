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

    int a[n], b[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    set<int> st;
    int max_diff_zero = 0;
    for(int i=0; i<n; i++){
        if(b[i]>a[i]){
            cout << "NO" << endl;
            return;
        }
        if(b[i]!=0 && a[i]!=0){
            st.insert(a[i]-b[i]);
        }
        if(b[i]==0){
            max_diff_zero = max(max_diff_zero, a[i]-b[i]);
        }
    }

    if(st.size() > 1){
        cout << "NO" << endl;
        return;
    }

    if(st.size() == 1 && max_diff_zero > *st.begin()){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

