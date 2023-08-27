#include<bits/stdc++.h>
using namespace std;
#define ICPCWF19        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define intt long long

int main()
{
    ICPCWF19
    intt tc; cin>>tc;
    for(intt t=1; t<=tc; t++){
        intt divider;
        string divident;
        cin>>divident>>divider;
        intt len = (intt)divident.size(), remainder = 0;
        vector<intt> result;
        if(divider<0) divider = -divider;
        for(intt i=0; i<len; i++){
            if(divident[i]=='-') continue;
            //if((((remainder*10) + (divident[i]-'0')) / divider) != 0) result.push_back((intt)((remainder*10) + (divident[i]-'0')) / divider);
            remainder = ((remainder*10) + (divident[i]&0x0f)) % divider;
        }
        if(remainder == 0) cout<<"Case "<<t<<": divisible"<<endl;
        else cout<<"Case "<<t<<": not divisible"<<endl;

        //cout<<"Division result: ";
        //for(intt i=0; i<result.size(); i++) cout<<result[i];
        //cout<<endl<<"Remainder: "<<remainder<<endl;
    }


    return 0;
}
