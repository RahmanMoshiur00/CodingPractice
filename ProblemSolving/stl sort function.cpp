#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

bool cmp(PII a, PII b){
    return a.second/a.first > b.second/b.first;
}

int main()
{
    vector<PII> v;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int wt, pr;
        cin>>wt>>pr;
        v.push_back(PII(wt, pr));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++) cout<<v[i].first<<" "<<v[i].second<<endl;

    return 0;
}
