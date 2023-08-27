#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int x;
    for(int  i=0; i<5; i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    unique_copy(v.begin(), v.end());
    for( int i=0; i<v.size(); i++) cout<<v[i]<<" ";

}
