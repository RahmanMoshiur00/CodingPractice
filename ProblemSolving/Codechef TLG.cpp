#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b, p1=0, p2=0, w, l=0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a>b) p1 += a-b;
        else p2 += b-a;
        if(p1-p2>l){
            w = 1;
            l = p1 - p2;
        }
        else if(p2-p1>l){
            w = 2;
            l = p2 - p1;
        }
    }
    cout<<w<<" "<<l<<endl;
    return 0;
}
