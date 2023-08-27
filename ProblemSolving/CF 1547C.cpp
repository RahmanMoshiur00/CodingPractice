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
    int lines, n, m;
    cin >> lines >> n >> m;

    int mono[n], poly[m];
    vector<int> ans;

    for(int i=0; i<n; i++) cin >> mono[i];
    for(int i=0; i<m; i++) cin >> poly[i];

    for(int i=0, j=0, k=0; i<n+m; i++){
        if(j<n && mono[j]!=0 && mono[j]<=lines){ //choose mono
            ans.push_back(mono[j++]);
        }
        else if(k<m && poly[k]!=0 && poly[k]<=lines){ //choose poly
            ans.push_back(poly[k++]);
        }
        else if(j>=n || mono[j]>=poly[k]){ //choose from poly
            if(poly[k]==0){
                lines++;
                ans.push_back(poly[k++]);
            }
            else{
                if(poly[k]<=lines) ans.push_back(poly[k++]);
                else{
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else{ //choose from mono
            if(mono[j]==0){
                lines++;
                ans.push_back(mono[j++]);
            }
            else{
                if(mono[j]<=lines) ans.push_back(mono[j++]);
                else{
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    for(int i=0; i<m+n; i++) cout << ans[i] << ' ';
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

