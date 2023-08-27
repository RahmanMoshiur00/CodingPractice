#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int ar[3], a, b, c;

    int tc;
    cin>>tc;

    while(tc--){
        cin>>ar[0]>>ar[1]>>ar[2];

        sort(ar, ar+3);
        a = ar[0];
        b = ar[1];
        c = ar[2];

        double s, res , ans;

        if(a+b > c){
            s = (a+b+c) * 0.5;
            res = sqrt(s * (s-a) * (s-b) * (s-c));
            cout<<fixed<<setprecision(2)<<res<<endl;
        }
        else{
            cout<<"Oh, No!"<<endl;
        }
    }

    return 0;
}

