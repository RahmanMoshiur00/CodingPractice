#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int w, h, n;
    cin >> w >> h >> n;

    set<int> w_point, h_point;
    multiset<int> w_seg, h_seg;

    w_point.insert(0); w_point.insert(w);
    h_point.insert(0); h_point.insert(h);

    w_seg.insert(w);
    h_seg.insert(h);

    int k;
    char ch;

    set<int>::iterator it, itr;
    while(n--){
        cin >> ch >> k;
        if(ch == 'H'){
            itr = h_point.lower_bound(k);
            it = itr;
            if(itr != h_point.end()) itr--;
            h_point.insert(k);
            h_seg.erase(h_seg.find(*it - *itr));
            h_seg.insert(*it - k);
            h_seg.insert(k - *itr);
        } else{
            itr = w_point.lower_bound(k);
            it = itr;
            if(itr != w_point.end()) itr--;
            w_point.insert(k);
            w_seg.erase(w_seg.find(*it - *itr));
            w_seg.insert(*it - k);
            w_seg.insert(k - *itr);
        }
        cout << (*h_seg.rbegin()) * (*w_seg.rbegin()) << endl;
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

