#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector< pair<int, pair<int, string> > >patro;

    int n; cin>>n;

    for(int i=0; i<n; i++){
        pair<int, pair<int, string> > p;
        cin>>p.second.second>>p.first>>p.second.first;
        patro.push_back(p);
    }
    sort(patro.begin(), patro.end(), greater< pair<int, pair<int, string> > >());
    for(int i = 0; i<n; i++){
        cout<<patro[i].first<<" "<<patro[i].second.first<<" "<<patro[i].second.second<<endl;
    }

    return 0;
}
