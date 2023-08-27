#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case, int n)
{
    string s[n];
    map<string, int> mp;
    for(int i=0; i<n; i++){
        cin >> s[i];
        mp[s[i]]++;
    }

    int i = 0, cnt[mp.size()] = {0};
    for(auto x : mp){
        cnt[i++] = x.second;
    }

    sort(cnt, cnt+mp.size());

    vector<int> ans;
    while(true){
        int present = 0;
        for(int j=0; j<mp.size(); j++){
            if(cnt[j]){
                cnt[j]--;
                present++;
            }
        }
        if(present == 0) break;
        else ans.push_back(present);
    }

    cout << "Case " << test_case << ": ";
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i];
    cout << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);

    int tc = 1, n;
    while(cin >> n && n) solve(tc++, n);

    return 0;
}

