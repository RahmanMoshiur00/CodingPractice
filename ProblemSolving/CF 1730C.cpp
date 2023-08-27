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
    string s;
    cin >> s;

    int n = s.size();
    vector<int> adj[10];

    for(int i=0; i<n; i++){
        adj[s[i]-'0'].push_back(i);
    }

    for(int i=0; i<10; i++) sort(adj[i].begin(), adj[i].end());

    string ans = "";
    int li = INT_MIN;

    for(int i=0; i<10; i++){
        if(i==9){
            for(int j=0; j<adj[i].size(); j++) ans += '9';
        }
        else{
            for(int j=0; j<adj[i].size(); j++){
                if(adj[i][j] == ans.size() && ans.back()<=char(i+'0')){
                    ans += char(i+'0');
                }
                else if(adj[i][j]>li){
                    ans += char(i+'0');
                }
                else{
                    ans += char(i+1+'0');
                }
                li = max(li, adj[i][j]);
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

/*
1
13221
*/
