#include<bits/stdc++.h>
using namespace std;
typedef long long intt;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    intt tc, n, sz, rem;
    string num;
    cin>>tc;
    for(intt t=1; t<=tc; t++){
        cin>>num>>n;
        sz = num.length();
        rem = 0;
        for(intt i=0; i<sz; i++){
            if(num[i]=='-') continue;
            rem = ((rem*10) + (num[i]-'0'))%n;
        }
        if(rem==0) cout<<"Case "<<t<<": divisible"<<endl;
        else cout<<"Case "<<t<<": not divisible"<<endl;
    }
    return 0;
}
