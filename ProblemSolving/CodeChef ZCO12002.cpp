#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff      first
#define ss      second
#define pb      push_back
#define mp      make_pair
#define all(x)  x.begin(),x.end()


int main()
{
    int n, x, y, s, e;
    cin>>n>>x>>y;

    vector<pii> contest;
    for(int i=0; i<n; i++){
        cin>>s>>e;
        contest.pb(mp(s,e));
    }

    vector<int> v(x), w(y);
    for(int i=0; i<x; i++) cin>>v[i];
    for(int i=0; i<y; i++) cin>>w[i];

    sort(all(v));
    sort(all(w));

    int res = INT_MAX, sti=0, edi=0, t1=0, t2=0;

    for(int i=0; i<n; i++){
        //finding the optimally valid starting and ending time of the journey through wormhole
        sti = lower_bound(all(v), contest[i].ff) - v.begin();
        if(sti!=x && v[sti]==contest[i].ff) t1 = v[sti];
        else if(sti!=0 && v[sti-1]<contest[i].ff) t1 = v[sti-1];
        else t1 = -1;

        edi = lower_bound(all(w), contest[i].ss) - w.begin();
        if(edi==y) t2 = -1;
        else t2 = w[edi];

        if(t1>=0 && t2>=0) res = min(res, t2 - t1 + 1);
    }

    cout<<res<<endl;

    return 0;
}
