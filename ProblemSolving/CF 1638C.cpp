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

    set<int> st;
    int ans = 0, j;
    bool increase;
    for(int i=0; i<n; i++){
        increase = true;
        for(j=i+1; j<n; j++){
            if(arr[i]<arr[j]){
                break;
            }
            else{
                if(!st.empty()){
                    while(!st.empty() && *st.rbegin() > arr[j]){
                        st.erase(st.find(*st.rbegin()));
                    }
//                    auto itr = st.upper_bound(arr[j]);
//                    if(itr != st.end()){
//                        increase = false;
//                        ans = 1;
//                    }
                }
            }
        }
        st.insert(arr[i]);
//        if(increase) ans++;
        i = j-1;
    }

    cout << st.size() << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
4
6
4 2 5 3 6 1
6
6 5 4 3 2 1
6
1 2 3 4 5 6
1
1
*/
