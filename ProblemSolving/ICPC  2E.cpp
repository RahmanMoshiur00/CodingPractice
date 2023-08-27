#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

set<int> st;

void primes(int n)
{
    if(n%2==0){
        st.insert(2);
        while(n%2==0) n /= 2;
    }

    for(int i=3; i<=sqrt(n)+1; i+=2){
        if(n%i==0){
            st.insert(i);
            while(n%i==0) n /= i;
        }
    }

    if(n != 1) st.insert(n);
}

void solve(int test_case)
{
    st.clear();
    int a, b;
    cin >> a >> b;

    primes(a);
    primes(b);

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

