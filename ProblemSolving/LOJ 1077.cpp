#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long tc, x1, x2, y1, y2;
    cin>>tc;
    for(int t=1; t<=tc; t++){
        cin>>x1>>y1>>x2>>y2;
        cout<<"Case "<<t<<": "<<1 + __gcd(abs(x1-x2), abs(y1-y2))<<endl;
    }
    return 0;
}
