#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

char round_up(char c)
{
    if(c=='9') return '0';
    if(c>='0' && c<'9') return c + 1;
    return c;
}

void solve(int test_case)
{
    string s;
    cin >> s;

    int d;
    cin >> d;

    string decimal, floating;

    int start = -1, point;
    for(int i=0; i<s.size(); i++){
        if(s[i]>'0' && s[i]<='9' && start == -1){
            start = i;
        }
        if(s[i]=='.'){
            point = i;
        }
    }


    if(start == -1){
        decimal += '0';
    }
    else{
        for(int i=start; i<point; i++) decimal += s[i];
    }

    if(point+d >= s.size()){
        for(int i=point+1; i<point+d+1; i++){
            if(i<s.size()) floating += s[i];
            else floating += '0';
        }
    }
    else{ // trouble is here -_-
        int carry = 0;
        for(int i=point+d; i>point; i--){
            floating += round_up(s[i+1]) + carry;
            if(floating[floating.size() - 1] == '0'){
                carry = 1;
            }
            else{
                carry = 0;
            }
        }

        if(carry == 1){
            for(int i=decimal.size() - 1; i>=0; i--){
                decimal[i] = round_up(decimal[i]) + carry;
                if(decimal[i]=='0'){
                    carry = 1;
                }
                else carry = 0;
            }

            string tmp = "";
            if(carry==1){
                tmp += '1';
                tmp += decimal;
                decimal = tmp;
            }
        }

        reverse(all(floating));
    }


    cout << decimal;
    if(d>0) cout << "." << floating;
    cout << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

