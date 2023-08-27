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
    int n, m, k;
    cin >> n >> m >> k;

    string a, b;
    cin >> a >> b;

    sort(all(a));
    sort(all(b));

    string c = "";
    int sz = min(a.size(), b.size()), fi = 0, se = 0;
    for(int i=0, j=0; i<a.size() && j<b.size(); ){
        if(a[i]<=b[j]){
           if(fi<k){
                c += a[i];
                fi++;
                se = 0;
                i++;
           }
           else{
                c += b[j];
                fi = 0;
                se++;
                j++;
           }
        }
        else{
            if(se<k){
                c += b[j];
                se++;
                fi = 0;
                j++;
            }
            else{
                c += a[i];
                fi++;
                se = 0;
                i++;
            }
        }
    }

    cout << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

