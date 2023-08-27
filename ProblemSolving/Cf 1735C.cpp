#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010;


void solve(int test_case)
{
    int n; cin >> n;
    string tf, t;
    cin >> tf;

    t = "";
    int vis[26];
    ZERO(vis);
    for(int i=0; i<n; i++){
        if(!vis[tf[i]-'a']){
            t += tf[i];
        }
        vis[tf[i]-'a'] = 1;
    }

    map<char,char> mp;
    ZERO(vis);

    if(t.size() == 2){
        if(t[0]=='a'){
            mp['a'] = 'b';
            if(t[1]=='b') mp['b'] = 'c';
            else mp['b'] = 'a';
        }
        else{
            mp[t[0]] = 'a';
            if(t[1]=='a') mp['a'] = 'c';
            else mp[t[1]] = 'b';
        }

    }
    else{
            if(t[0]=='a'){
            for(int j=0; j<t.size(); j++){
                for(int i=t[j]-'a'+1; ;i++){
                    if(i==26) i = i%26;
                    if(!vis[i]){
                        vis[i] = 1;
                        mp[t[j]] = char('a' + i);
                        break;
                    }
                }
            }
        }
        else{
            for(int j=0; j<t.size(); j++){
                for(int i=0; ;i++){
                    if(i==26) i = i%26;
                    if(!vis[i]){
                        vis[i] = 1;
                        mp[t[j]] = char('a' + i);
                        break;
                    }
                }
            }
        }
    }





    for(int i=0; i<n; i++){
        cout << mp[tf[i]];
    } cout << endl;



}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

