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

    if(n==1){
        cout << 1 << endl;
        return;
    }

    set<int> st[26];
    for(int i=0; i<n; i++){
        st[s[i]-'a'].insert(i);
    }


    int del = 0, fi, se;
    set<int>::iterator itf, its;

    for(int i=0; i<n; i++){
        fi = INT_MAX, se = INT_MAX;

        if(i==n-1){
            del++;
            continue;
        }
        if(i+1<n && s[i]==s[i+1]){
            i++;
            continue;
        }

        itf = st[s[i]-'a'].upper_bound(i);
        if(i+1<n){
            its = st[s[i+1]-'a'].upper_bound(i+1);
        }

        if(itf != st[s[i]-'a'].end()){
            fi = *itf - i - 1;
            debug cout << "at: " << i <<  "  itf: " << *itf << endl;
        }
        if(its != st[s[i+1]-'a'].end()){
            debug cout << "at: " << i <<  "   its: " << *its << endl;
            se = *its - (i+1) - 1;
        }

        debug cout << "Debug-> at: " << i << ' ' << fi << ' ' << se << endl;

        if(fi==se && fi==INT_MAX){ // no matches
            del++;
        }
        else if(fi <= se){
            del += fi;
            i += (fi+1);
        }
        else{ // fi > se
            del += se + 1;
            i += se + 2;
        }

    }

    cout << del << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

