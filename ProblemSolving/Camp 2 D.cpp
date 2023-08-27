#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;



void solve(int test_case)
{
    int n, k, ind;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    multiset<int> st;
    st.insert(1e15);
    auto it = st.begin();

    for(int i=0, j=0; i<k; i++){
        cin >> ind;
        while(j<ind){
            st.insert(arr[j]);
            if(it!=st.end() && arr[j] < *it) it--;
            j++;
        }
        cout << *it << endl;
        it++;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

