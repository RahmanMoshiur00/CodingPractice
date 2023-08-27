
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
    string s1, s2, s;
    cin >> s1 >> s2;

    multiset<string> st;
    for(int i=0; i<s1.size(); i++){
        s = "";
        for(int j=0; i+j<s1.size(); j++){
            s += s1[i+j];
            st.insert(s);
        }
    }

    int ans = 0;
    s2 += '*';

    for(int i=0; i+1<s2.size(); i++){
        s = "";
        for(int j=0; i+j<s2.size(); j++){
            s += s2[i+j];
            if(st.find(s) == st.end()){
                s.pop_back();
                st.erase(st.find(s));
                ans++;
                i = i + j - 1;
                break;
            }
        }
    }

    cout << "Case " << test_case << ": " << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

