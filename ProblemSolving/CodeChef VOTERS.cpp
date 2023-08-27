#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main()
{
    int a, b, c, n, id;
    cin>>a>>b>>c;
    n = a+b+c;
    vector<int> ans;
    while(n--){
        cin>>id;
        if(mp.find(id)==mp.end()) mp[id] = 1;
        else mp[id]++;
        if(mp[id]==2) ans.push_back(id);
    }
    sort(ans.begin(), ans.end());
    int sz = ans.size();
    cout<<sz<<endl;
    for(int i=0; i<sz; i++) cout<<ans[i]<<endl;

    return 0;
}
