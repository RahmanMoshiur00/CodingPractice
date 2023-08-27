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
    int n, k;
    cin >> n >> k;

    if(n==4 && k==3){
        cout << -1 << endl;
        return;
    }

    int l[n/2], r[n/2];
    for(int i=0; i<n/2; i++){
        l[i] = i;
        r[i] = n-1-i;
    }

    if(k == n-1){
        l[0] = n-2;
        r[1] = l[(n/2)-1];
        l[(n/2)-1] = 0;
    }
    else{
        for(int i=0; i<n/2; i++){
            if(l[i]==k){
                swap(l[i], l[0]);
                break;
            }
            else if(r[i]==k){
                swap(r[i], l[0]);
                break;
            }
        }
    }

    for(int i=0; i<n/2; i++){
        cout << l[i] << ' ' << r[i] << endl;
    }

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

/*
8
8 0
8 1
8 2
8 3
8 4
8 5
8 6
8 7
*/
