#include <bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

//ordered_set declaration
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set;

const int mxn = 100010;



void solve(int test_case)
{
    int n, q;
    cin >> n >> q;

    ordered_set row_set, col_set;
    map<int, int> row_map, col_map;

    int t, r, c, x1, y1, x2, y2, cv, rv;
    while(q--){
        cin >> t;
        if(t == 1){ // put rook
            cin >> r >> c;
            row_set.insert(r);
            col_set.insert(c);
            row_map[r]++;
            col_map[c]++;
        }
        else if(t == 2){ // delete rook
            cin >> r >> c;
            row_map[r]--;
            col_map[c]--;
            if(row_map[r] < 1) row_set.erase(r);
            if(col_map[c] < 1) col_set.erase(c);
        }
        else{ // query
            cin >> x1 >> y1 >> x2 >> y2;

            rv = row_set.order_of_key(x2+1) - row_set.order_of_key(x1);

            cv = col_set.order_of_key(y2+1) - col_set.order_of_key(y1);

            debug cout << "rv = " << rv << "    cv = " << cv << endl;

            if((rv == (x2-x1+1)) || (cv == (y2-y1+1))) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
1 4
1 1 1
3 1 1 1 1
2 1 1
3 1 1 1 1
*/

