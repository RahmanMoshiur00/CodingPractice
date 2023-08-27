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

    if(n==1 or *max_element(arr, arr+n) == *min_element(arr, arr+n)){
        cout << 0 << endl;
        return;
    }

    set<int> st;
    for(int i=1; i<n; i++){
        st.insert(arr[i]-arr[i-1]);
    }

    if(st.size() == 1){
        cout << 0 << endl;
    }
    else if(st.size()==2){
        auto it = st.begin();
        int sm = *it;
        it++;
        int bg = *it;
        if(sm<0 && bg>0){
            int sum = bg - sm;
            if(sum > *max_element(arr, arr+n)) cout << bg-sm << ' ' << abs(arr[0]-arr[1]) << endl;
            else cout << -1 << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
    else{
        cout << -1 << endl;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

