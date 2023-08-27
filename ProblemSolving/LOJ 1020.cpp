#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;
    string str;
    cin>>tc;
    for(int t=1; t<=tc; t++){
        cin>>n>>str;
        if(n&1){
            if(str=="Alice") cout<<"Case "<<t<<": Bob"<<endl;
            else cout<<"Case "<<t<<": Alice"<<endl;
        }
        else{
            if(str=="Alice") cout<<"Case "<<t<<": Alice"<<endl;
            else cout<<"Case "<<t<<": Bob"<<endl;
        }
    }
    return 0;
}
