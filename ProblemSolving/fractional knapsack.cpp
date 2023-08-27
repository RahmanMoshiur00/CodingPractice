#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int, int> PII;

vector<PII> v;

bool cmp(PII a, PII b){
    //return a.second/a.first > b.second/b.first; //counting on per unit price
    return a.second*b.first >= b.second*a.first;
}

int main()
{
    int n; cin>>n;
    int weight, price;
    for(int i=0; i<n; i++) cin>>weight>>price, v.pb(PII(weight, price));
    sort(v.begin(), v.end(), cmp);
    int wt, ans = 0; cin>>wt;
    for(int i=0; wt>0; i++){
        int m = min(wt, v[i].first);
        wt -= m;
        ans += m * (v[i].second / v[i].first);
    }

    cout<<"Maximum Cost = "<<ans<<endl;

    return 0;
}
