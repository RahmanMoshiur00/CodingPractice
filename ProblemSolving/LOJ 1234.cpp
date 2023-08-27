#include <bits/stdc++.h>
using namespace std;
#define mxn           10010
#define gamma         0.5772156649

double cum[mxn], ans=0.0;

void presum(){
    cum[0] = 0.0 , cum[1] = 1.0;
    for(int i=2; i<mxn; i++){
        cum[i] = cum[i-1] + (1.0 / (i*1.0));
    }
}

int main()
{

    int tc; cin>>tc;
    int n;

    presum();

    cout<<fixed<<setprecision(10);//this statement helps to print exactly 10 digits after decimal point
    for(int t=1; t<=tc; t++){
        cin>>n;
        if(n<mxn) cout<<"Case "<<t<<": "<<cum[n]<<endl;
        else{
            ans = log(2*n+1) - log(2) + gamma;
            cout<<"Case "<<t<<": "<<ans<<endl;
        }

    }

    return 0;
}
