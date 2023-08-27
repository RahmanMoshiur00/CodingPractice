#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main()
{
    ull n, q, m, tp, c = 0, t, res;
    cin>>n>>q;

    ull arr[n];
    queue<ull> q1, q2;

    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr, arr+n);

    for(int i=n-1; i>=0; i--) q1.push(arr[i]);

    c = 0;
    for(int i=0; i<q; i++){
        cin>>m;
        t = m; m -= c;
        c = t; t = 1;
        while(m--){
            if((!q1.empty() && q2.empty()) || (!q1.empty() && q1.front()>=q2.front())){
                res = q1.front();
                q1.pop();
                q2.push(res/2);
            }
            else{
                res = q2.front();
                q2.pop();
                q2.push(res/2);
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
